/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skTreeNodeObjectEnumerator.cpp,v 1.2 2001/03/05 16:46:28 sdw Exp $
*/

#include "skTreeNodeObjectEnumerator.h"
#include "skTreeNodeObject.h"
#include "skRValue.h"
#include "skInterpreter.h"

//-----------------------------------------------------------------
skTreeNodeObjectEnumerator::skTreeNodeObjectEnumerator(skTreeNodeObject * element)
//-----------------------------------------------------------------
  : m_Iter(*(element->getNode())),m_Object(element)
{
  m_CurrentNode=m_Iter();
}
//-----------------------------------------------------------------
skTreeNodeObjectEnumerator::skTreeNodeObjectEnumerator(skTreeNodeObject * element,const skString& tag)
//-----------------------------------------------------------------
  : m_Iter(*(element->getNode())),m_Tag(tag),m_Object(element)
{
  // first wind forward to the first occurrence of the tag
  findNextNode();
}
//------------------------------------------
bool skTreeNodeObjectEnumerator::method(const skString& s,skRValueArray& args,skRValue& r)
  //------------------------------------------
{
  bool bRet=false;
  if (s=="next"){
    if (m_CurrentNode){
      r=skRValue(new skTreeNodeObject(m_Object->getLocation(),m_CurrentNode,false),true);
      if (m_Tag.length())
	findNextNode();
      else
	m_CurrentNode=m_Iter();
    }else
      r=skRValue(&skInterpreter::g_Null);
    bRet=true;
  }else if (s=="reset"){
    m_Iter.reset();
    if (m_Tag.length())
	findNextNode();
    else
      m_CurrentNode=m_Iter();
    bRet=true;
  }else
    bRet=skExecutable::method(s,args,r);
  return bRet;
}
/**
 * this method winds m_NodeNum onto the next matching element - or beyond the end of the list for the end of enumeration
 */ 
//------------------------------------------
void skTreeNodeObjectEnumerator::findNextNode()
//------------------------------------------
{
  m_CurrentNode=0;
  while ((m_CurrentNode=m_Iter())!=0){
    if (m_CurrentNode->label()==m_Tag)
      break;
  }
}

