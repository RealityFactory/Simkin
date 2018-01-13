/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skXMLExecutable.cpp,v 1.8 2001/03/05 16:46:29 sdw Exp $
*/

#include "skXMLErrorHandler.h"
#include <fstream.h>
#include "parsers/DOMParser.hpp"
#include "framework/LocalFileInputSource.hpp"
#include "framework/MemBufInputSource.hpp"

#include "skXMLExecutable.h"

//------------------------------------------
skXMLExecutable::skXMLExecutable() 
//------------------------------------------
{
}
//------------------------------------------
skXMLExecutable::skXMLExecutable(const skString& scriptLocation,InputSource& in)
//------------------------------------------
{
  load(scriptLocation,in);
}
//------------------------------------------
skXMLExecutable::skXMLExecutable(const skString& scriptLocation,const skString& in)
//------------------------------------------
{
  load(scriptLocation,in);
}
//------------------------------------------
skXMLExecutable::skXMLExecutable(const skString& fileName)
//------------------------------------------
{
  load(fileName);
}
//------------------------------------------
void skXMLExecutable::load(const skString& scriptLocation,const skString& in) 
//------------------------------------------
{
  DOMString domStr=fromString(in);
  DOMString domLocation=fromString(scriptLocation);
  MemBufInputSource inputSource((const XMLByte *)domStr.transcode(),domStr.length(),domLocation.rawBuffer(),true);
  load(scriptLocation,inputSource);
}
//------------------------------------------
void skXMLExecutable::load(const skString& scriptLocation,InputSource& in) 
//------------------------------------------
{
  m_ScriptLocation=scriptLocation;
  DOMParser * parser = new DOMParser;
  skXMLErrorHandler handler;
  parser->setErrorHandler(&handler);
  parser->parse(in);
  DOM_Element elem=parser->getDocument().getDocumentElement();
  delete parser;
  setElement(elem);
}
//------------------------------------------
void skXMLExecutable::load(const skString& fileName) 
//------------------------------------------
{
  DOMString sFileName((const char *)fileName);
  const XMLCh * buffer=sFileName.rawBuffer();
  LocalFileInputSource in(buffer);
  load(fileName,in);
}
//------------------------------------------
void skXMLExecutable::save(ostream& out) 
//------------------------------------------
{
  DOM_Element elem=getElement();
  out << elem;
}
//------------------------------------------
void skXMLExecutable::save(const skString& fileName) 
//------------------------------------------
{
  ofstream out(fileName);
  save(out);
}
//------------------------------------------
skXMLExecutable::skXMLExecutable(const skXMLExecutable& other)
//------------------------------------------
{
}
//------------------------------------------
skXMLExecutable& skXMLExecutable::operator=(const skXMLExecutable& other)
//------------------------------------------
{
  return *this;
}
