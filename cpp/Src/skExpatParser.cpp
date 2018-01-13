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

* $Id: skExpatParser.cpp,v 1.13 2003/03/14 16:39:44 simkin_cvs Exp $
*/
#include "skExpatParser.h"
#include "skXMLParseException.h"
#include "skCDataNode.h"
#include "skInputSource.h"
#include <stdio.h>
//-----------------------------------------------------------------
skExpatParser::skExpatParser()
//-----------------------------------------------------------------
  : m_InCData(false),m_RootElement(0)
{
}
//-----------------------------------------------------------------
skExpatParser::~skExpatParser()
//-----------------------------------------------------------------
{
  delete m_RootElement;
}
//-----------------------------------------------------------------
skExpatParser::skExpatParser(const skExpatParser&)
//-----------------------------------------------------------------
{
}
//-----------------------------------------------------------------
skExpatParser& skExpatParser::operator=(const skExpatParser&)
//-----------------------------------------------------------------
{
  return *this;
}
//-----------------------------------------------------------------
void skExpatParser::startElementHandler(void *userData, const Char *name, const Char **atts)
//-----------------------------------------------------------------
{
  ((skExpatParser *)userData)->startElement(name,atts);
}
//-----------------------------------------------------------------
void skExpatParser::startElement(const Char *name, const Char **attr)
//-----------------------------------------------------------------
{
  skElement * elem=new skElement(name);
  if (m_RootElement==0)
    m_RootElement=elem;
  for (int i = 0; attr[i]; i += 2) {
    elem->setAttribute(attr[i],attr[i+1]);
  }
  if (m_ElementStack.entries())
    ((skElement *)m_ElementStack[m_ElementStack.entries()-1])->appendChild(elem);
  m_ElementStack.append(elem);
}
//-----------------------------------------------------------------
void skExpatParser::endElementHandler(void *userData, const Char *name)
//-----------------------------------------------------------------
{
  ((skExpatParser *)userData)->endElement(name);
}
//-----------------------------------------------------------------
void skExpatParser::endElement(const Char *name)
//-----------------------------------------------------------------
{
  // pop latest off the stack
  if (m_ElementStack.entries())
    m_ElementStack.remove(m_ElementStack[m_ElementStack.entries()-1]);
}
//-----------------------------------------------------------------
void skExpatParser::characterDataHandler(void *userData, const XML_Char *s,int len)
//-----------------------------------------------------------------
{
  ((skExpatParser *)userData)->characterData(s,len);
}
//-----------------------------------------------------------------
void skExpatParser::characterData(const XML_Char *s,int len)
//-----------------------------------------------------------------
{
  if (m_ElementStack.entries()){
    skElement * element=(skElement * )m_ElementStack[m_ElementStack.entries()-1];
    if (m_InCData)
      element->appendChild(new skCDataNode(skString(s,(USize)len)));
    else
      element->appendChild(new skTextNode(skString(s,(USize)len)));
  }
}
//-----------------------------------------------------------------
void skExpatParser::startCDataHandler(void *userData)
//-----------------------------------------------------------------
{
  ((skExpatParser *)userData)->startCData();
}
//-----------------------------------------------------------------
void skExpatParser::startCData()
//-----------------------------------------------------------------
{
  m_InCData=true;
}
//-----------------------------------------------------------------
void skExpatParser::endCDataHandler(void *userData)
//-----------------------------------------------------------------
{
  ((skExpatParser *)userData)->endCData();
}
//-----------------------------------------------------------------
void skExpatParser::endCData ()
//-----------------------------------------------------------------
{
  m_InCData=false;
}
//-----------------------------------------------------------------
skElement * skExpatParser::parse(skInputSource& in,skExecutableContext& context)
//-----------------------------------------------------------------
{
  m_InCData=false;
  m_RootElement=0;
  skElement * elem=0;
  XML_Parser parser = XML_ParserCreate(NULL);
  XML_SetUserData(parser,this);
  XML_SetElementHandler(parser, startElementHandler, endElementHandler);
  XML_SetCharacterDataHandler(parser, characterDataHandler);
  XML_SetCdataSectionHandler(parser, startCDataHandler, endCDataHandler);
  skString in_string=in.readAllToString();
  unsigned int buf_len=in_string.length()*sizeof(Char);
  if (!XML_Parse(parser, (const char *)(const Char *)in_string, buf_len, true)) {
#ifdef EXCEPTIONS_DEFINED
    m_ElementStack.clearAndDestroy();
    m_RootElement=0;
    skXMLParseException e(XML_ErrorString(XML_GetErrorCode(parser)),XML_GetCurrentLineNumber(parser));
    XML_ParserFree(parser);
    throw (e,skXMLParseException_Code);
#else
    m_ElementStack.clearAndDestroy();
    m_RootElement=0;
    context.getError().setError(skScriptError::XMLPARSE_ERROR,new skXMLParseException(XML_ErrorString(XML_GetErrorCode(parser)),XML_GetCurrentLineNumber(parser)));
#endif
  }
  XML_ParserFree(parser);
  elem=m_RootElement;
  m_RootElement=0;
  m_ElementStack.clear();
  return elem;
}
