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

  $Id: skElementObjectEnumerator.cpp,v 1.2 2001/11/22 11:13:21 sdw Exp $
*/

#include "skElementObjectEnumerator.h"
#include "skElementObject.h"
#include "skRValue.h"
#include "skInterpreter.h"

//-----------------------------------------------------------------
skElementObjectEnumerator::skElementObjectEnumerator(skElement * element,bool add_if_not_present,const skString& location)
//-----------------------------------------------------------------
  : m_Element(element),m_NodeNum(0),m_AddIfNotPresent(add_if_not_present),m_Location(location)
{
  // first wind forward to the first occurrence of the tag
  findNextNode();
}
//-----------------------------------------------------------------
skElementObjectEnumerator::skElementObjectEnumerator(skElement * element,bool add_if_not_present,const skString& location,const skString& tag)
//-----------------------------------------------------------------
    : m_Element(element),m_NodeNum(0),m_Tag(tag),m_AddIfNotPresent(add_if_not_present),m_Location(location)
{
  // first wind forward to the first occurrence of the tag
  findNextNode();
}
//------------------------------------------
bool skElementObjectEnumerator::method(const skString& s,skRValueArray& args,skRValue& r)
  //------------------------------------------
{
  bool bRet=false;
  if (s=="next"){
    if (next(r)==false)
      r=skRValue(&skInterpreter::g_Null);
    bRet=true;
  }else if (s=="reset"){
    m_NodeNum=0;
    findNextNode();
    bRet=true;
  }else
    bRet=skExecutable::method(s,args,r);
  return bRet;
}
/**
 * this method winds m_NodeNum onto the next matching element - or beyond the end of the list for the end of enumeration
 */ 
//------------------------------------------
void skElementObjectEnumerator::findNextNode()
//------------------------------------------
{
  skNodeList& nodes=m_Element->getChildNodes();
  for (;m_NodeNum<nodes.entries();m_NodeNum++){
    skNode * node=nodes[m_NodeNum];
    if (node->getNodeType()==skNode::ELEMENT_NODE && (m_Tag.length()==0 || ((skElement *)node)->getTagName()==m_Tag)){
      break;
    }
  }
}
//------------------------------------------
bool skElementObjectEnumerator::next(skRValue& r)
  //------------------------------------------
{
  bool ret=false;
  skNodeList& nodes=m_Element->getChildNodes();
  if (m_NodeNum<nodes.entries()){
    skElementObject * obj=new skElementObject(m_Location,(skElement * )nodes[m_NodeNum],false);
    r=skRValue(obj,true);
    obj->setAddIfNotPresent(m_AddIfNotPresent);
    m_NodeNum++;
    findNextNode();
    ret=true;
  }
  return ret;
}

