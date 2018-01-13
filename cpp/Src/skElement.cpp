/*
  Copyright 1996-2001
  Simon Whiteside

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

* $Id: skElement.cpp,v 1.4 2001/11/22 11:13:21 sdw Exp $
*/
#include "skElement.h"

//------------------------------------------
skElement::skElement(const skString& tagname)
//------------------------------------------
:m_TagName(tagname)
{
}
//------------------------------------------
void skElement::appendChild(skNode * child)
//------------------------------------------
{
  m_ChildNodes.append(child);
}
//------------------------------------------
void skElement::removeAndDestroyChild(skNode * child)
//------------------------------------------
{
  m_ChildNodes.removeAndDestroy(child);
}
//------------------------------------------
void skElement::setAttribute(const skString& name,const skString& value)
//------------------------------------------
{
  skAttribute * attr=findAttribute(name);
  if (attr)
    attr->setValue(value);
  else
    m_Attributes.append(new skAttribute(name,value));
}
//------------------------------------------
skAttribute * skElement::findAttribute(const skString& name) const
//------------------------------------------
{
  skAttribute * ret=0;
  for (USize i=0;i<m_Attributes.entries();i++){
    skAttribute * attr=m_Attributes[i];
    if (attr->getName()==name){
      ret=attr;
      break;
    }
  }
  return ret;
}
//------------------------------------------
skString skElement::getAttribute(const skString& name) const
//------------------------------------------
{
  skString value;
  skAttribute * attr=findAttribute(name);
  if (attr)
    value=attr->getValue();
  return value;
}
//------------------------------------------
skNodeList& skElement::getChildNodes()
//------------------------------------------
{
  return m_ChildNodes;
}
//------------------------------------------
skString skElement::getTagName() const
//------------------------------------------
{
  return m_TagName;
}
//------------------------------------------
 skNode::NodeType skElement::getNodeType() const
//------------------------------------------
{
  return ELEMENT_NODE;
}
//------------------------------------------
 skNode * skElement::clone()
//------------------------------------------
{
  skElement * element=new skElement(m_TagName);
  for (USize i=0;i<m_Attributes.entries();i++){
    skAttribute * attr=m_Attributes[i];
    element->setAttribute(attr->getName(),attr->getValue());
  }
  for (USize j=0;j<m_ChildNodes.entries();j++){
    skNode * node=m_ChildNodes[j];
    element->appendChild(node->clone());
  }
  return element;
}
//------------------------------------------
void skElement::write(ostream& out) const
//------------------------------------------
{
  out << "<" << m_TagName;
  for (USize i=0;i<m_Attributes.entries();i++)
    out << " " << *m_Attributes[i];
  out << ">";
  for (USize j=0;j<m_ChildNodes.entries();j++)
    out << *m_ChildNodes[j];
  out << "</" << m_TagName << ">";
}
//------------------------------------------
ostream& operator<<(ostream& out,const skAttribute& a)
//------------------------------------------
{
  out << a.getName() << "=\"" << skNode::escapeXMLDelimiters(a.getValue()) << "\"";
  return out;
}
