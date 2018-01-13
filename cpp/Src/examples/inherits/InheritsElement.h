/*
  Copyright 1996-2000
  Simon Whiteside
  $Id: InheritsElement.h,v 1.4 2001/05/22 12:38:06 sdw Exp $
*/
#ifndef INHERITSELEMENT_H
#define INHERITSELEMENT_H

#include "skXMLElementObject.h"
#include "dom/DOM_Element.hpp"

/** 
 * this class extends the skXMLElementObject class with understanding of the <inherits> tag. It overrides the createXMLElementObject method to make sure that any sub-elements are also checked.
 */
class InheritsElement : public skXMLElementObject {
 public:
    /**
     * Default constructor - does nothing
     */
  InheritsElement();
  /**
   * passes parameters up to parent, and then calls replaceInherits to look for inherits tags
   * @param location location of the script
   * @param elem the element associated with this object
   */
  InheritsElement(const skString& location,DOM_Element elem);
 protected:
  /**
   * This method overrides the parent method and ensures that replaceInherits is called on the element associated with this object
   */
  virtual void setElement(DOM_Element elem);
  /**
   * This method overrides the parent method, it makes sure that if an object is created to associated with a sub-element, an InheritsElement type is used
   */
  virtual skXMLElementObject * createXMLElementObject(const skString& location,DOM_Element element);
  /**
   * This method walks through the given element, replacing any instances of <inherits> with the contents of the XML file given as the value of the inherits tag
   */
  static void replaceInherits(DOM_Element elem);
};

#endif
