/*
  Copyright 1996-2003
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

* $Id: skAsciiString.h,v 1.3 2003/04/04 17:04:25 simkin_cvs Exp $
*/


#ifndef skASCIISTRING_H
#define skASCIISTRING_H

#include "skGeneral.h"

#ifdef STREAMS_ENABLED
#include <iostream.h>
#endif



class P_AsciiString;

/**
 * This class encapsulates a null-terminated 8-bit c-string
 * It uses a pointer to a string plus a reference count to save copying when passed by value
*/
class CLASSEXPORT skAsciiString 
{
 public:
  /**
   * Default Constructor - constructs a blank string
   */
  skAsciiString();
  /**
   * Constructor - from a null-terminated c-string
   */
  skAsciiString(const char *);
  /**
   * Copy Constructor
   */
  skAsciiString(const skAsciiString&);
  /**
   * Constructor - from a non null-terminated buffer
   * @param buffer - the buffer to be copied from
   * @param len - the length of the data to be copied
   */
  skAsciiString(const char * buffer, USize len);
  /**
   * Constructor - a repeated list of characters
   * @param repeatchar - the character to be repeated
   * @param len - the number of times the character is repeated
   */
  skAsciiString(const char repeatchar, USize len);
  /**
   * Destructor
   */
  virtual ~skAsciiString();
  /**
   * Assignment operator - increments reference count of underlying P_String object
   */
  skAsciiString& operator=(const skAsciiString&);
  /**
   * Assignment operator - dereferences the P_String object and makes a new one by copying the given buffer
   */
  skAsciiString& operator=(const char *);
  /**
   * Comparison operator
   * @return true if the current string is alphabetically before the other string
   */
  bool operator<(const skAsciiString&) const;
  /**
   * Equality operator
   * @return true if the other string is the same as the current one
   */
  bool operator==(const skAsciiString&) const;
  /**
   * Equality operator 
   * @return true if the other c-string is the same as the current one
   */
  bool operator==(const char *) const;
  /**
   * Inequality operator
   * @return true if the other string is different to the current one
   */
  bool operator!=(const skAsciiString&) const;
  /**
   * Inequality operator
   * @return true if the other c-string is different to the current one
   */
  bool operator!=(const char *) const;
  /**
   * Conversion operator
   * @return a pointer to the buffer contained within the P_String object
   */
  operator const char * () const;
  /**
   * Case-insensitive equality
   * @return true if the other string is the same as the current one, ignoring case
   */
  bool equalsIgnoreCase(const skAsciiString&) const;
  /**
   * Returns a hash value for this string
   */
  USize hash() const;
  /**
   * Returns a character within the string
   * @param index - the index of the character, starting at 0
   * @return the character, or 0 if the index does not lie within the length of the string
   */
  char at(USize index) const;
  /**
   * Returns a substring of this string
   * @param start - the 0-based start of the substring
   * @param length - the length of the substring
   * @return a new String for the substring, or a blank string if the start and length do not lie within the current string
   */
  skAsciiString substr(USize start,USize length) const;
  /**
   * Returns the substring from the start up to the end of the current string
   * @param start - the 0-based start of the substring
   * @return a new String for the substring, or a blank string if the start does not lie within the current string
   */
  skAsciiString substr(USize start) const;
  /**
   * Addition operator
   * @return a String that contains this string followed by the other string
   */
  skAsciiString operator+(const skAsciiString&) const ;
  /**
   * Increment operator - dereferences the P_String object, and replaces it with the concatenation of this string and the other one
   * @return this string
   */
  skAsciiString& operator+=(const skAsciiString&);
  /**
   * Length of the string
   * @return the length of the buffer in the P_String object
   */
  USize length() const;
  /**
   * returns the index of the first occurrence of the given string within the string
   * @return an index, or -1 if not found
   */
  int indexOf(const skAsciiString& s) const;
  /**
   * returns the index of the first occurrence of the given character within the string
   * @return an index, or -1 if not found
   */
  int indexOf(char c) const;
  /**
   * returns the index of the last occurrence of the given character within the string
   * @return an index, or -1 if not found
   */
  int indexOfLast(char c) const;
  /**
   * Converts the string to an integer
   */
  int to() const;
#ifdef USE_FLOATING_POINT
  /**
   * Converts the string to a float
   */
  float toFloat() const;
#endif
  /**
   * Constructs a string from static string - the static string is *not* copied
   */
  static skAsciiString literal(const char *);
  /**
   * Constructs a string from a signed integer
   */
  static skAsciiString from(int);
  /**
   * Constructs a string from an unsigned integer
   */
  static skAsciiString from(USize);
#ifdef USE_FLOATING_POINT
  /**
   * Constructs a string from a float
   */
  static skAsciiString from(float);
#endif
  /**
   * Constructs a string from a character
   */
  static skAsciiString from(char ch);
  /**
   * Constructs a string from a buffer, which is *not* copied. The string will delete the buffer when the reference count reaches zero
   */
  static skAsciiString fromBuffer(char * buffer);
  /**
   * returns a version of this string with leading blanks removed
   */
  skAsciiString ltrim() const;
 protected:
  /**
   * Constructor - internal taking a P_String and not copying it
   */
  skAsciiString(P_AsciiString *);
  /**
   * Constructor - internal, taking a buffer and not copying it
   */
  skAsciiString(const char * s,int);
  /**
   * Assigns another buffer to this one, and copies it
   */
  void assign(const char *,int len=0);				
  /**
   * Dereferences the P_String object, deleting it if the reference count is zero
   */
  void deRef();
  /**
   * The underlying string object
   */
  P_AsciiString * pimp;
};
/*
 * A hashKey function for HashTables
 */
inline USize hashKey(const skAsciiString * s)
{
    return s->hash();
}
/*
 * An operator to add strings
 */
CLASSEXPORT skAsciiString operator+(const char * s1,const skAsciiString& s2);

#ifdef STREAMS_ENABLED
/*
 * A streaming operator to write a string to an output stream
 */
CLASSEXPORT ostream& operator<<(ostream&,const skAsciiString&s);
#endif

#include "skAsciiString.inl"

#endif



