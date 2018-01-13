/*
  Copyright 1996-2000
  Simon Whiteside
  $Id: InheritsExecutable.cpp,v 1.2 2001/05/22 12:24:10 sdw Exp $
*/
#include "InheritsExecutable.h"
#include "parsers/DOMParser.hpp"
#include "framework/LocalFileInputSource.hpp"
#include "skXMLErrorHandler.h"

//------------------------------------------
InheritsExecutable::InheritsExecutable(const skString& fileName)
//------------------------------------------
{
  load(fileName);
}
//------------------------------------------
void InheritsExecutable::load(const skString& scriptLocation,InputSource& in) 
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
void InheritsExecutable::load(const skString& fileName) 
//------------------------------------------
{
  DOMString sFileName((const char *)fileName);
  const XMLCh * buffer=sFileName.rawBuffer();
  LocalFileInputSource in(buffer);
  load(fileName,in);
}
