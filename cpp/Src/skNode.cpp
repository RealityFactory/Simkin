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

* $Id: skNode.cpp,v 1.11 2003/03/24 15:51:32 simkin_cvs Exp $
*/
#include "skNode.h"
#include "skStringBuffer.h"

//------------------------------------------
skNode::skNode()
//------------------------------------------
:m_Parent(0)
{
}
//------------------------------------------
skNode::skNode(const skNode& other)
//------------------------------------------
:m_Parent(0)
{
}
//------------------------------------------
skNode::~skNode()
//------------------------------------------
{
}
//------------------------------------------
skNode& skNode::operator=(const skNode& other)
//------------------------------------------
{
  return *this;
}
//------------------------------------------
skString skNode::getNodeValue() const
//------------------------------------------
{
  return skString();
}
//------------------------------------------
void skNode::setNodeValue(const skString& )
//------------------------------------------
{
}
static Char g_SpecialChars[]={'&','<','>','"'};
static Char * g_SpecialCharEscapes[]={skSTR("&amp;"),skSTR("&lt;"),skSTR("&gt;"),skSTR("&quot;")};
static USize g_NumSpecialChars=sizeof(g_SpecialChars)/sizeof(Char);
//------------------------------------------
skString skNode::escapeXMLDelimiters(const skString& text)
//------------------------------------------
{
  skString out=text;
  bool need_to_scan=false;
  // first check if the text has any special characters in it
  for (USize i=0;i<g_NumSpecialChars;i++)
    if (text.indexOf(g_SpecialChars[i])!=-1){
      need_to_scan=true;
      break;
    }
  // if it does, need to scan and replace them
  if (need_to_scan){
    skStringBuffer buffer(text.length());
    for (USize i=0;i<text.length();i++){
      Char c=out[i];
      bool char_replaced=false;
      for (USize i=0;i<g_NumSpecialChars;i++)
        if (c==g_SpecialChars[i]){
          char_replaced=true;
          buffer.append(g_SpecialCharEscapes[i]);
          break;
        }
      if (char_replaced==false)
        buffer.append(c);
    }
    out=buffer.toString();
  }
  return out;
}
//------------------------------------------
void skNode::setParent(skElement * parent)
//------------------------------------------
{
  m_Parent=parent;
}
//------------------------------------------
skElement * skNode::getParent()
//------------------------------------------
{
  return m_Parent;
}

