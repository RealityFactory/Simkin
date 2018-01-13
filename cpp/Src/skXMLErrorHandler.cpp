/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skXMLErrorHandler.cpp,v 1.3 2001/06/13 16:48:21 sdw Exp $
*/
#include "skXMLErrorHandler.h"
#include "dom/DOMString.hpp"
#include <sax/SAXParseException.hpp>
#include "skXMLElementObject.h"

//------------------------------------------
void  skXMLErrorHandler::warning (const SAXParseException& exception)
//------------------------------------------
{
}
//------------------------------------------
void  skXMLErrorHandler::error (const SAXParseException& toCatch)
//------------------------------------------
{
  cerr << "Error at file \"" << DOMString(toCatch.getSystemId())
       << "\", line " << toCatch.getLineNumber()
       << ", column " << toCatch.getColumnNumber()
       << "\n   Message: " << DOMString(toCatch.getMessage()) << endl;
  throw SAXParseException(toCatch);  // Copy the 'toCatch' object before throwing - 
  //   otherwise we would be throwing a reference to
  //   a local object that gets destroyed before
  //   the catch.
}
//------------------------------------------
void  skXMLErrorHandler::fatalError (const SAXParseException& toCatch)
//------------------------------------------
{
  cerr << "Fatal Error at file \"" << DOMString(toCatch.getSystemId())
       << "\", line " << toCatch.getLineNumber()
       << ", column " << toCatch.getColumnNumber()
       << "\n   Message: " << DOMString(toCatch.getMessage()) << endl;
  throw SAXParseException(toCatch);
}
//------------------------------------------
void  skXMLErrorHandler::resetErrors ()
//------------------------------------------
{
}
