/*
  Copyright 1996-2000
  Simon Whiteside
  $Id: InheritsExecutable.h,v 1.3 2001/05/22 12:38:06 sdw Exp $
*/
#ifndef INHERITSEXECUTABLE_H
#define INHERITSEXECUTABLE_H

#include "InheritsElement.h"
#include "sax/InputSource.hpp"

/**
 * This class loads an XML file and makes sure any <inherits> tags are resolved.
 */
class InheritsExecutable : public InheritsElement {
 public:
  /**
   * Constructor - passed the name of a file to load an XML document from
   */
  InheritsExecutable(const skString& fileName);
  /**
   * This method causes the XML to be reloaded
   * @param in - stream containing the XML
   */
  void load(const skString& scriptLocation,InputSource& in);
  /**
   * This method causes the XML to be loaded from a file
   */
  void load(const skString& fileName);
 private:
  /**
   * Executables can't be copied
   */
  InheritsExecutable(const InheritsExecutable&);
  /**
   * Executables can't be copied
   */
  InheritsExecutable& operator=(const InheritsExecutable&);
};

#endif
