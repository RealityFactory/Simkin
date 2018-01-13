/*
  Copyright 1996-2001
  Simon Whiteside
  
* $Id: skXMLExecutable.h,v 1.8 2001/03/05 16:46:29 sdw Exp $
*/

#ifndef skXMLEXECUTABLE_H
#define skXMLEXECUTABLE_H

#include "skXMLElementObject.h"
#include "sax/InputSource.hpp"
#include <iostream.h>

/**
 * This class is a base class for objects which store their data and methods in an XML document
 * Each instance is associated with an XML document which is loaded on construction. 
 */
class skXMLExecutable : public skXMLElementObject {
 public:
  /**
   * Default Constructor.
   */ 
  skXMLExecutable();
  /**
   * Constructor - passed the name of a file to load an XML document from
   */
  skXMLExecutable(const skString& fileName);
  /**
   * Constructor taking an input stream containing an XML document
   */
  skXMLExecutable(const skString& scriptLocation,InputSource& in);
  /**
   * Constructor taking a String containing an XML document
   */
  skXMLExecutable(const skString& scriptLocation,const skString& in);
  /**
   * This method causes the XML to be reloaded
   * @param in - stream containing the XML
   */
  void load(const skString& scriptLocation,InputSource& in);
  /**
   * This method causes the XML to be reloaded
   * @param in - string containing the XML
   */
  void load(const skString& scriptLocation,const skString& in);
  /**
   * This method causes the XML to be loaded from a file
   */
  void load(const skString& fileName);
  /**
   * Call this method to save the state of the object back to a stream
   * @exception IOException if there was an error writing to the stream
   */
  void save(ostream& out);
  /**
   * This method saves the current state as an XML document out to the given file
   */
  void save(const skString& fileName);
 private:
  /**
   * Executables can't be copied
   */
  skXMLExecutable(const skXMLExecutable&);
  /**
   * Executables can't be copied
   */
  skXMLExecutable& operator=(const skXMLExecutable&);
};
#endif
