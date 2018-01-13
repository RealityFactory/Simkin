/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skXMLElementObjectEnumerator.h,v 1.6 2001/03/05 16:46:29 sdw Exp $
*/
#ifndef XMLELEMENTOBJECTENUMERATOR_H
#define XMLELEMENTOBJECTENUMERATOR_H

#include "skExecutable.h"

class skXMLElementObject;

/**
 * This class enumerates the element children of an skXMLElementObject
 */
class skXMLElementObjectEnumerator : public skExecutable{
 public:
  skXMLElementObjectEnumerator(skXMLElementObject * element);
  skXMLElementObjectEnumerator(skXMLElementObject * element,const skString& tag);
  /**
   * This method exposes the following methods to Simkin scripts:
   * returns the next element in the enumeration - or null if there are no more
     */
  bool method(const skString& s,skRValueArray& args,skRValue& r);
 private:
  void findNextNode();

  skXMLElementObject * m_Element;
  int m_NodeNum;
  skString m_Tag;
};
#endif
