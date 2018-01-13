/*
  Copyright 1996-2002
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

* $Id: skElement.h,v 1.7 2002/12/13 17:21:54 sdw Exp $
*/
#ifndef skELEMENT_H
#define skELEMENT_H

#include "skNode.h"
#include "skAttribute.h"

/**
 * This class represents an Element within an XML document. The class forms part of the Simkin DOM class library.
 */
class CLASSEXPORT skElement : public skNode
{
 public:
  /** This constructs a new element with the given tag
   * @param tagname - the tag name to use for the element
   */
  skElement(const skString& tagname);
  /**
   * This adds a child to the list of children owned by this element. The node's "parent" field is set to this element
   * @param child - the child to be added. Note: the child is not copied, and will be deleted by the destructor for this class.
   */
  void appendChild(skNode * child);
  /**
   * This removes a child from the list of children owned by this element. The child is deleted by this function.
   * @param child - the child to be removed and destroyed.
   */
  void removeAndDestroyChild(skNode * child);
  /**
   * This removes a child from the list of children owned by this element. The child is *not* deleted by this function. The child's "parent" field is set to zero.
   * @param child - the child to be removed .
   */
  void removeChild(skNode * child);
  /**
   * This sets an attribute of this element. The attribute is added, if not already present.
   * @param name - the name of the attribute. If one already exists with this name, its value is overwritten.
   * @param value - the value for the attribute
   */
  void setAttribute(const skString& name,const skString& value);
  /**
   * This returns the value of an attribute. If the attribute does not exist, a blank string is returned.
   * @param name - the name of the attribute being accessed
   * @return the value associated with the name, or a blank string.
   */
  skString getAttribute(const skString& name) const;
  /**
   * This method returns the list of child nodes owned by this element
   * @return the list of child nodes owned by this element
   */
  skNodeList& getChildNodes();
  /**
   * This returns the tag name for the element
   * @return the tag name of the element 
   */
  skString getTagName() const;
  /**
   * this returns the type of this node
   * @return ELEMENT_NODE
   */
  virtual NodeType getNodeType() const;
  /**
   * This method returns a new element with the same tag name, attributes and child list. A deep copy is made.
   * @return a deep copy of this element
   */
  virtual skNode * clone();
  /**
   * Copies this element, its attributes and children to a string.
   * @return a string containing this element
   */
  virtual skString toString() const;
#ifdef STREAMS_ENABLED
  /**
   * Writes this element, its attributes and children to the given stream.
   * @param out - the stream to write to
   */
  virtual void write(ostream& out) const;
#endif
 protected:
  /** this method finds a named attribute */
  skAttribute * findAttribute(const skString& name) const;
  /** this variable stores the tag name for this element */
  skString m_TagName;
  /** this holds the list of attributes for this element */
  skAttributeList m_Attributes;
  /** this holds the list of child nodes owned by this element */
  skNodeList m_ChildNodes;
};
#endif


