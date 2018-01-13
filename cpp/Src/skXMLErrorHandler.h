/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skXMLErrorHandler.h,v 1.3 2001/03/05 16:46:29 sdw Exp $
*/

#ifndef skXMLERRORHANDLER_H
#define skXMLERRORHANDLER_H

#include "sax/ErrorHandler.hpp"

/**
 * This class picks up errors encountered while parsing an XML document and throws SAXParseExceptions
 */
class skXMLErrorHandler : public ErrorHandler {
 public:
  /**
   * This function is called when there is a warning - it does nothing
   */
  void  warning (const SAXParseException& exception);
  /**
   * This function is called when there is an error - it throws the exception
   * @exception SAXParseException - the exception received is thrown
   */
  void  error (const SAXParseException& exception);
  /**
   * This function is called when there is a fatal error - it throws the exception
   * @exception SAXParseException - the exception received is thrown
   */
  void  fatalError (const SAXParseException& exception);
  /**
   * this function does nothing
   */
  void  resetErrors ();
};

#endif
