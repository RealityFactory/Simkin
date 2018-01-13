/*
  Copyright 1996-2001
  Simon Whiteside

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

* $Id: skElementObject.h,v 1.3 2001/11/22 11:13:21 sdw Exp $
*/


#ifndef skELEMENTOBJECT_H
#define skELEMENTOBJECT_H

#include "skExecutable.h"
#include "skElement.h"
#include <iostream.h>

class skMethodTable;

// this is the value returned by executableType

#define ELEMENT_TYPE 4


/**
 * This object is a container for an  element, and exposes an interface to it to Simkin
 * The class implements methods from the Executable interface.
 * The methods getValue, setValue and method all search for matching element tags within the  document. Only the first matching tag is used.  
 * The class uses the Simkin XML DOM classes.
 * <p>The class supports the following fields:<ul>
 * <li>"nodename" - returns the tag name of this element</li>
 * <li>"numChildren" - returns the number of children of this element</li></ul>
 * The class supports the following methods:<ul>
 * <li>dump - writes the whole  Object out to the tracer (useful for debugging)</li>
 * <li>enumerate([name]) - returns an skElementObjectEnumerator which enumerates over the child elements of this element. If no tag name is passed the enumerator lists all the children. A tag name can be passed to show only children with the matching tag name.</li>
 * <li>addElement([tag name]) - adds a new empty element with the given tag name to this element</li>
 * <li>containsElement([tag name]) - returns true if the  element contains an element with the given tag</li>
 * <li>tagName - returns the tag name of this element</li>
 * </ul>
 */
class CLASSEXPORT skElementObject : public skExecutable {
 public:
  /**
   * Default Constructor
   */
  skElementObject();
  /**
   * Constructor which takes an Element
   * @param location - used to identify the source of the document in error messages
   * @param elem - the element to be stored
   */
  skElementObject(const skString& location,skElement * elem,bool created);
  /**
   * Destructor
   */
  ~skElementObject();
  /**
   * Returns ELEMENT_TYPE indicating the element is an ElementObject
   * @return the type as  element
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
  Char charValue() const;
  /**
   * @return the value of the element text data as a string
   */
  skString strValue() const;
  /**
   * sets the value of an item in the element. The first sub-element matching the tag is found. If the value passed is an element, it is first copied. If the m_AddIfNotPresent flag is true, a new item will be added if one is not already present
   * @param name - the name of the element tag to set (null if it's the overall element)
   * @param attribute - the name of the attribute to set (null to set text for the element)
   * @param return_value - the RValue to receive the value
   * @return true if the field was found, false otherwise
   */
  bool setValue(const skString& s,const skString& attribute,const skRValue& return_value);
  /**
   * Sets a value within the nth element of the  element. If the m_AddIfNotPresent flag is true, a new item with the tag name "array_item" will be added if one is not already present.
   * @param array_index - the identifier of the item - this might be a string, integer or any other legal value
   * @param attribute - the attribute name to set (may be blank)
   * @param value - the value to be set
   * @return true if the field was changed, false if the field could not be set or found
   */
  bool setValueAt(const skRValue& array_index,const skString& attribute,const skRValue& value); 
  /**
   * Retrieves a field from the . The first sub-element matching the tag is found. The value returned is an ElementObject, unless the attrib value is specified. It also supports the following built-in field:
   * <P> "nodename" - returns the tag name of this element
   * <p>If the m_AddIfNotPresent flag is true, a new item will be added if one is not already present.
   * @param name - the tag name containing the data
   * @param attrib - the attribute name to retrieve
   * @param return_value -  the RValue to containing the value to be set
   * @return true if the method was found, false otherwise
   */
  bool getValue(const skString& s,const skString& attribute,skRValue& return_value);
  /**
   * Retrieves the nth value from within the element. If the array index falls within the range of the number of children of this element, 
   * a new ElementObject encapsulating the child is returned. If the m_AddIfNotPresent flag is true, a new item with the tag name "array_item" will be added if one is not already present
   */
  bool getValueAt(const skRValue& array_index,const skString& attribute,skRValue& value);
  /**
   * this method attempts to execute a method stored in the . It searches for an element whose tag matches the method name and if found passes the text for the tag through to the interpeter. 
   * <p>The method also supports the following methods to Simkin scripts: <ul>
   * <li>dump - writes the whole  Object out to the tracer (useful for debugging)</li>
   * <li>enumerate([name]) - returns an skElementObjectEnumerator which enumerates over the child elements of this element. If no tag name is passed the enumerator lists all the children. A tag name can be passed to show only children with the matching tag name.</li>
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
  void copyItemsInto(skElement * other);
  /** sets the flag controlling whether new elements are created as they are accessed
   * @param enable enables this feature (which by default is disabled)
   */
  virtual void setAddIfNotPresent(bool enable);
  /** this returns the value of the flag controlling whether new elements are created as they are accessed 
   * @return true if the feature is enabled, otherwise false (the default)
   */
  virtual bool getAddIfNotPresent();
  /**
   * This method returns the  Element being held by the object.
   * @return the underlying Element
   */
  skElement * getElement();
  /**
   * retrieves the text data from an element
   * @param element
   * @return the text from a child node of type CDATA or TEXT
   */
  static skString getData(skElement * element);
  /**
   * sets the text data for a node by looking for the first CDATA and TEXT child node
   * @param element the element to be changed
   * @param data the data to be set
   */
  static void setData(skElement * element,const skString& data);
  /**
   * returns a child element
   * @param parent the parent element
   * @param tagname the tag name of the element
   * @return the first element child of the parent with the matching tag name, or null if not found
   */
  static skElement * findChild(skElement * parent,const skString& tagname);
  /**
   * returns the nth child element
   * @param parent the parent element
   * @param index the index of the element
   * @return the matching element or null if outside the current list ot items
   */
  static skElement * findChild(skElement * parent,int index);
  /**
   * returns a child element with the given attribute set to the given value
   * @param parent the parent element
   * @param tagname the tag name of the element
   * @param attribute name of the attribute
   * @param value value of the named attribute
   * @return the first element child of the parent with the matching tag name and attribute value, or null if not found
   */
  static skElement * findChild(skElement * parent,const skString& tagname,const skString& attribute,const skString& value);
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
   * This function returns the location associated with this object (typically a file name)
   */
  skString getLocation() const;
  /** this method returns the number of element children of the given element */
  static int countChildren(skElement * parent);
 protected:
  /**
   * This method updates the associated element and clears the parse tree cache
   * @param elem - the new Element
   */
  virtual void setElement(skElement * element);
  /**
   * This method creates a new  Element object to wrap an element. Override this for special behaviour in derived classes. In this method, the newly created object inherits this object's m_AddIfNotPresent flag
   * @param location the location of this element
   * @param element the DOM element to associate with the object
   */
  virtual skElementObject * createElementObject(const skString& location,skElement * element,bool created);
  /**
   * the location that the  document came from
   */
  skString m_ScriptLocation;
  /**
   * This function returns an skExecutableIterator object which is used in the for each statement. It will iterate over elements with the given tag.
   * @param qualifier tag - only elements with this tag will appear in the iteration
   */
  skExecutableIterator * createIterator(const skString& qualifier);
  /**
   * This function returns an skExecutableIterator object which is used in the for each statement. It will iterate over *all* children of this element
   */
  skExecutableIterator * createIterator();
 private:
  /**
   * the underlying document
   */
  skElement * m_Element;
  /**
   * a cache used to hold onto parse trees for methods that have already been executed
   */
  skMethodTable * m_MethodCache;
  /**
   * Executables can't be copied
   */
  skElementObject(const skElementObject&);
  /**
   * Executables can't be copied
   */
  skElementObject& operator=(const skElementObject&);
  /**
   * this variable controls whether new items are added to this element if they are not found, by default it is false,
   but can be modified using the setAddIfNotPresent() method
  */
  bool m_AddIfNotPresent;
  /**
   * if this flag is true, the ElementObject will delete the underlying element in its destructor
   */
  bool m_Created;


};

#endif