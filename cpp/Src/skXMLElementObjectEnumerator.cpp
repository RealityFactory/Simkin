/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skXMLElementObjectEnumerator.cpp,v 1.4 2001/06/22 10:07:57 sdw Exp $
*/

#include "skXMLElementObjectEnumerator.h"
#include "skXMLElementObject.h"
#include "skRValue.h"
#include "skInterpreter.h"
#include "dom/DOM_NodeList.hpp"

//-----------------------------------------------------------------
skXMLElementObjectEnumerator::skXMLElementObjectEnumerator(skXMLElementObject * element)
//-----------------------------------------------------------------
    : m_Element(element),m_NodeNum(0)
{
  // first wind forward to the first occurrence of the tag
  findNextNode();
}
//-----------------------------------------------------------------
skXMLElementObjectEnumerator::skXMLElementObjectEnumerator(skXMLElementObject * element,const skString& tag)
//-----------------------------------------------------------------
    : m_Element(element),m_NodeNum(0),m_Tag(tag)
{
  // first wind forward to the first occurrence of the tag
  findNextNode();
}
//------------------------------------------
bool skXMLElementObjectEnumerator::method(const skString& s,skRValueArray& args,skRValue& r)
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
void skXMLElementObjectEnumerator::findNextNode()
//------------------------------------------
{
  DOM_NodeList nodes=m_Element->getElement().getChildNodes();
  DOMString sTagName;
  if (m_Tag.length()>0)
    sTagName=skXMLElementObject::fromString(m_Tag);
  for (;m_NodeNum<nodes.getLength();m_NodeNum++){
    DOM_Node node=nodes.item(m_NodeNum);
    if (node.getNodeType()==DOM_Node::ELEMENT_NODE && (m_Tag.length()==0 || node.getNodeName().equals(sTagName))){
      break;
    }
  }
}
//------------------------------------------
bool skXMLElementObjectEnumerator::next(skRValue& r)
  //------------------------------------------
{
  bool ret=false;
  DOM_NodeList nodes=m_Element->getElement().getChildNodes();
  if (m_NodeNum<nodes.getLength()){
    r=skRValue(new skXMLElementObject(m_Element->getLocation(),*(DOM_Element *)&(nodes.item(m_NodeNum))),true);
    m_NodeNum++;
    findNextNode();
    ret=true;
  }
  return ret;
}

