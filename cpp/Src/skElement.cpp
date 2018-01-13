/*
  Copyright 1996-2003
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

* $Id: skElement.cpp,v 1.15 2003/04/04 17:13:13 simkin_cvs Exp $
*/
#include "skElement.h"
#include "skStringBuffer.h"
#include "skOutputDestination.h"
//------------------------------------------
skElement::skElement(const skString& tagname)
//------------------------------------------
:m_TagName(tagname)
{
}
//------------------------------------------
skElement::~skElement()
//------------------------------------------
{
}
//------------------------------------------
void skElement::appendChild(skNode * child)
//------------------------------------------
{
  m_ChildNodes.append(child);
  child->setParent(this);
}
//------------------------------------------
void skElement::removeAndDestroyChild(skNode * child)
//------------------------------------------
{
  child->setParent(0);
  m_ChildNodes.removeAndDestroy(child);
}
//------------------------------------------
void skElement::removeChild(skNode * child)
//------------------------------------------
{
  child->setParent(0);
  m_ChildNodes.remove(child);
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
skAttributeList& skElement::getAttributes()
//------------------------------------------
{
  return m_Attributes;
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
void skElement::write(skOutputDestination& out) const
//------------------------------------------
{
  out.write(skSTR("<"));
  out.write(m_TagName);
  for (USize i=0;i<m_Attributes.entries();i++){
    out.write(skSTR(" ")); 
    m_Attributes[i]->write(out);
  }
  out.write(skSTR(">"));
  for (USize j=0;j<m_ChildNodes.entries();j++)
    m_ChildNodes[j]->write(out);
  out.write(skSTR("</"));
  out.write(m_TagName);
  out.write(skSTR(">"));
}
//------------------------------------------
skString skElement::toString() const
//------------------------------------------
{
  skStringBuffer buffer(100);
  buffer.append(skSTR("<"));
  buffer.append(m_TagName);
  for (USize i=0;i<m_Attributes.entries();i++){
    buffer.append(skSTR(" "));
    buffer.append(m_Attributes[i]->toString());
  }
  buffer.append(skSTR(">"));
  for (USize j=0;j<m_ChildNodes.entries();j++)
    buffer.append(m_ChildNodes[j]->toString());
  buffer.append(skSTR("</"));
  buffer.append(m_TagName);
  buffer.append(skSTR(">"));
  return buffer.toString();
}
//------------------------------------------
bool skElement::equals(const skNode& other) const
//------------------------------------------
{
  bool equals=false;
  if (getNodeType()==other.getNodeType())
    equals=deepCompare(*(skElement*)&other,true);
  return equals;
}
//------------------------------------------
bool skElement::operator==(const skElement& other) const
//------------------------------------------
{
  // at this level, *do not* check tag name
  return deepCompare(other,false);
}
//------------------------------------------
bool skElement::deepCompare(const skElement& other,bool check_tagname) const
//------------------------------------------
{
  bool equals=false;
  // check tag name
  if (check_tagname==false || m_TagName==other.m_TagName){
    // check attributes
    if (m_Attributes.entries()==other.m_Attributes.entries()){
      equals=true;
      for (USize i=0;i<m_Attributes.entries();i++){
              skAttribute * attr=m_Attributes[i];
              if (other.getAttribute(attr->getName())!=attr->getValue()){
                equals=false;
                break;
              }
            }
            if (equals){
              // check children match
              if (m_ChildNodes.entries()==other.m_ChildNodes.entries()){
                for (USize i=0;i<m_ChildNodes.entries();i++){
                  skNode * this_node=m_ChildNodes[i];
                  skNode * other_node=other.m_ChildNodes[i];
                  if (this_node->getNodeType()==other_node->getNodeType()){
                    if (this_node->equals(*other_node)==false){
                      equals=false;
                      break;
                    }
                  }else{
                    equals=false;
                    break;
                  }
                }
              }
      }
    }
  }
  return equals;
}
//------------------------------------------
skString skAttribute::toString() const
//------------------------------------------
{
  skStringBuffer buffer(100);
  buffer.append(getName());
  buffer.append(skSTR("=\""));
  buffer.append(skNode::escapeXMLDelimiters(getValue()));
  buffer.append(skSTR("\""));
  return buffer.toString();
}
//------------------------------------------
void skAttribute::write(skOutputDestination& out)
//------------------------------------------
{
  out.write(m_Name);
  out.write(skSTR("=\""));
  out.write(skNode::escapeXMLDelimiters(m_Value));
  out.write(skSTR("\""));
}
