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

* $Id: skAttribute.h,v 1.3 2001/11/22 11:13:21 sdw Exp $
*/
#ifndef skATTRIBUTE_H
#define skATTRIBUTE_H

#include "skAlist.h"
#include "skString.h"

/**
 * This class represents an attribute of an element in an XML document. The class forms part of the Simkin DOM class library.
 */
class CLASSEXPORT skAttribute 
{
 public:
  /** Constructs a new attribute with the given name and value
   * @param name - the name of the attribute
   * @param value - the value of the attribute
   */
  skAttribute(const skString& name,const skString& value)
    : m_Name(name),m_Value(value){
  }
  /** this returns the name of the attribute
   * @return the name of the attribute
   */
  skString getName() const {
    return m_Name;
  }
  /** this returns the value of the attribute
   * @return the value of the attribute
   */
  skString getValue() const {
    return m_Value;
  }
  /** this method sets the value of the attribute */
  void setValue(const skString& name){
    m_Name=name;
  }
 private:
  skString m_Name;
  skString m_Value;
};

EXTERN_TEMPLATE template class CLASSEXPORT skTAList<skAttribute>;

/**
 * This class holds a list of attributes - it is used by the Element class.
 */
class CLASSEXPORT skAttributeList : public skTAList<skAttribute>{
};
CLASSEXPORT ostream& operator<<(ostream& out,const skAttribute& a);
#endif
