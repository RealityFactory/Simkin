/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skXMLElement.h,v 1.3 2001/03/05 16:46:28 sdw Exp $
*/
#ifndef skXMLELEMENT_H
#define skXMLELEMENT_H

#include "skString.h"
#include "dom/DOM_Element.hpp"
#include "dom/DOM_Document.hpp"

/**
 * This class is used to create additional XML elements that are added to an XML document, it overrides DOM_Element from the Xerces library
 */
class skXMLElement : public DOM_Element {
 public:
  /**
   * Constructor - passes an owner and a tagname
   */
    inline skXMLElement(DOM_Element owner,const skString& tagname)
  : DOM_Element(owner.getOwnerDocument().createElement(DOMString((const char *)tagname))){
    }
};

#endif
