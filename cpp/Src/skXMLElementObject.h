/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skXMLElementObject.h,v 1.16 2001/03/05 16:46:28 sdw Exp $
*/


#ifndef skXMLELEMENTOBJECT_H
#define skXMLELEMENTOBJECT_H

#include "skExecutable.h"
#include "dom/DOM_Element.hpp"
#include <iostream.h>

class skMethodTable;

// this is the value returned by executableType

#define XMLELEMENT_TYPE 2

/*
 * A stream operator for DOM_Nodes
 */
extern ostream& operator<<(ostream& target, DOM_Node& toWrite);
/*
 * A stream operator for DOM_Strings
 */
extern ostream& operator<< (ostream& target, const DOMString& s);

/**
 * This object is a container for an XML element, and exposes an interface to it to Simkin
 * The class implements methods from the Executable interface.
 * The methods getValue, setValue and method all search for matching element tags within the XML document. Only the first matching tag is used.  
 * The class uses the Xerces library to access XML documents
 * <p>The class supports the following fields:<ul>
 * <li>"nodename" - returns the tag name of this element</li></ul>
 * The class supports the following methods:<ul>
 * <li>dump - writes the whole XML Object out to the tracer (useful for debugging)</li>
 * <li>enumerate([name]) - returns an skXMLElementObjectEnumerator which enumerates over the child elements of this element. If no tag name is passed the enumerator lists all the children. A tag name can be passed to show only children with the matching tag name.</li>
 * </ul>
 */
class skXMLElementObject : public skExecutable {
 public:
  /**
   * Default Constructor
   */
  skXMLElementObject();
  /**
   * Constructor which takes an Element
   * @param location - used to identify the source of the document in error messages
   * @param elem - the element to be stored
   */
  skXMLElementObject(const skString& location,DOM_Element elem);
  /**
   * Destructor
   */
  ~skXMLElementObject();
  /**
   * Returns XMLELEMENT_TYPE indicating the element is an XMLElementObject
   * @return the type as XML element
   */
  int executableType() const;			
  /**
   * @return the value of the element text data as an integer
   */
  int intValue() const;
  /**
   * @return the value of the element text data as a float
   */
  float floatValue() const;
  /**
   * @return the value of the element text data as a boolean
   */
  bool boolValue() const;
  /**
   * @return the first character of the element text data 
   */
  char charValue() const;
  /**
   * @return the value of the element text data as a string
   */
  skString strValue() const;
  /**
   * sets the value of an item in the element. The first sub-element matching the tag is found. If the value passed is an element, it is first copied. 
   * @param name - the name of the element tag to set (null if it's the overall element)
   * @param attribute - the name of the attribute to set (null to set text for the element)
   * @param return_value - the RValue to receive the value
   * @return true if the field was found, false otherwise
   */
  bool setValue(const skString& s,const skString& attribute,const skRValue& return_value);
  /**
   * Retrieves a field from the XML. The first sub-element matching the tag is found. The value returned is an XMLElementObject, unless the attrib value is specified. It also supports the following built-in field:
   * <P> "nodename" - returns the tag name of this element
   * @param name - the tag name containing the data
   * @param attrib - the attribute name to retrieve
   * @param return_value -  the RValue to containing the value to be set
   * @return true if the method was found, false otherwise
   */
  bool getValue(const skString& s,const skString& attribute,skRValue& return_value);
  /**
   * this method attempts to execute a method stored in the XML. It searches for an element whose tag matches the method name and if found passes the text for the tag through to the interpeter. 
   * <p>The method also supports the following methods to Simkin scripts: <ul>
   * <li>dump - writes the whole XML Object out to the tracer (useful for debugging)</li>
   * <li>enumerate([name]) - returns an skXMLElementObjectEnumerator which enumerates over the child elements of this element. If no tag name is passed the enumerator lists all the children. A tag name can be passed to show only children with the matching tag name.</li>
   * </ul>
   * @param name the name of the method
   * @param args an array of arguments to the method
   * @param ret the object to receive the result of the method call
   * @return true if the method was found, false otherwise
   */
  bool method(const skString& name,skRValueArray& args,skRValue& ret);
  /**
   * tests for equality with another object, using the string value
   * @return true if the data in both elements is the same
   */
  //  bool equals(skExecutable * o) const;
  /**
   * Clears the other element and does a deep copy of the children of this node into that one
   * @param child - the element into which our children will be copied
   */
  void copyItemsInto(DOM_Element other);
  /**
   * This method returns the XML Element being held by the object.
   * @return the underlying Element
   */
  DOM_Element getElement();
  /**
   * retrieves the text data from an element
   * @param element
   * @return the text from a child node of type CDATA or TEXT
   */
  static skString getData(DOM_Element element);
  /**
   * sets the text data for a node by looking for the first CDATA and TEXT child node
   * @param element the element to be changed
   * @param data the data to be set
   */
  static void setData(DOM_Element element,const skString& data);
  /**
   * returns a child element
   * @param parent the parent element
   * @param tagname the tag name of the element
   * @return the first element child of the parent with the matching tag name, or null if not found
   */
  static DOM_Element findChild(DOM_Element parent,const skString& tagname);
  /**
   * returns a child element with the given attribute set to the given value
   * @param parent the parent element
   * @param tagname the tag name of the element
   * @param attribute name of the attribute
   * @param value value of the named attribute
   * @return the first element child of the parent with the matching tag name and attribute value, or null if not found
   */
  static DOM_Element findChild(DOM_Element parent,const skString& tagname,const skString& attribute,const skString& value);
  /**
   * Sets an attribute on this node
   */
  void setAttribute(skString name,const skString& value);
  /**
   * This method returns the value of an attribute attached to this element.
   * @return the value of the given attribute
   */
  skString getAttribute(const skString& name);
  /**
   * Converts a Xerces DOMString to a Simkin skString
   */
  static skString toString(DOMString str);
  /**
   * Converts a Simkin skString to a Xerces DOMString
   */
  static DOMString fromString(const skString& str);
  /**
   * This function returns the location associated with this object (typically a file name)
   */
  skString getLocation() const;
 protected:
  /**
   * This method updates the associated element and clears the parse tree cache
   * @param elem - the new Element
   */
  void setElement(DOM_Element element);
 protected:
  /**
   * the location that the XML document came from
   */
  skString m_ScriptLocation;
 private:
  /**
   * the underlying document
   */
  DOM_Element m_Element;
  /**
   * a cache used to hold onto parse trees for methods that have already been executed
   */
  skMethodTable * m_MethodCache;
  /**
   * Executables can't be copied
   */
  skXMLElementObject(const skXMLElementObject&);
  /**
   * Executables can't be copied
   */
  skXMLElementObject& operator=(const skXMLElementObject&);
};

#endif
