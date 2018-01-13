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

* $Id: skTextNode.h,v 1.2 2001/11/22 11:13:21 sdw Exp $
*/
#ifndef skTEXTNODE_H
#define skTEXTNODE_H

#include "skNode.h"

/**
 * This class represents a text node. This holds the text within or between two elements in an XML document
 */
class CLASSEXPORT skTextNode : public skNode
{
 public:
  /** Contructs a new text node with the given text 
   * @param text - the text to use as the node's value
   */
  skTextNode(const skString& text);
  /**
   * returns the text within the text node
   *@return the text for this node 
   */
  virtual skString getNodeValue() const;
  /**
   * sets the text in this node
   *@param s - the new text for this node
   */
  virtual void setNodeValue(const skString& s);
  /**
   * this returns the type of this node
   * @return returns TEXT_NODE
   */
  virtual NodeType getNodeType() const;
  /**
   * this method returns a new skTextNode that has the same text value as this one
   * @return a new copy of this node
   */
  virtual skNode * clone();
  /**
   * writes the text in this node to the given stream
   * @param out - the stream to write to
   */
  virtual void write(ostream& out) const;
 protected:
  /** this member variable holds the text for this node */
  skString m_Text;
};
#endif
