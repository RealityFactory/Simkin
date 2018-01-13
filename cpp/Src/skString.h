/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skString.h,v 1.11 2001/06/13 16:48:21 sdw Exp $
*/


#ifndef skSTRING_H
#define skSTRING_H

#include <iostream.h>
#include "skGeneral.h"

class P_String;

/**
 * This class encapsulates a null-terminated 8-bit c-string
 * It uses a pointer to a string plus a reference count to save copying when passed by value
*/
class skString 
{
 public:
  /**
   * Default Constructor - constructs a blank string
   */
  skString();
  /**
   * Constructor - from a null-terminated c-string
   */
  skString(const char *);
  /**
   * Constructor - from a null-terminated c-string
   */
  skString(const unsigned char *);
  /**
   * Copy Constructor
   */
  skString(const skString&);
  /**
   * Constructor - from a non null-terminated buffer
   * @param buffer - the buffer to be copied from
   * @param len - the length of the data to be copied
   */
  skString(const unsigned char * buffer, USize len);
  /**
   * Constructor - a repeated list of characters
   * @param repeatChar - the character to be repeated
   * @param len - the number of times the character is repeated
   */
  skString(const unsigned char repeatChar, USize len);
  /**
   * Destructor
   */
  virtual ~skString();
  /**
   * Assignment operator - increments reference count of underlying P_String object
   */
  skString& operator=(const skString&);
  /**
   * Assignment operator - dereferences the P_String object and makes a new one by copying the given buffer
   */
  skString& operator=(const unsigned char *);
  /**
   * Assignment operator - dereferences the P_String object and makes a new one by copying the given buffer
   */
  skString& operator=(const char *);
  /**
   * Comparison operator
   * @return true if the current string is alphabetically before the other string
   */
  bool operator<(const skString&) const;
  /**
   * Equality operator
   * @return true if the other string is the same as the current one
   */
  bool operator==(const skString&) const;
  /**
   * Equality operator 
   * @return true if the other c-string is the same as the current one
   */
  bool operator==(const unsigned char *) const;
  /**
   * Equality operator 
   * @return true if the other c-string is the same as the current one
   */
  bool operator==(const char *) const;
  /**
   * Inequality operator
   * @return true if the other string is different to the current one
   */
  bool operator!=(const skString&) const;
  /**
   * Inequality operator
   * @return true if the other c-string is different to the current one
   */
  bool operator!=(const char *) const;
  /**
   * Inequality operator
   * @return true if the other c-string is different to the current one
   */
  bool operator!=(const unsigned char *) const;
  /**
   * Conversion operator
   * @return a pointer to the buffer contained within the P_String object
   */
  operator const unsigned char * () const;
  /**
   * Conversion operator
   * @return a pointer to the buffer contained within the P_String object
   */
  operator const char * () const;
  /**
   * Returns a hash value for this string
   */
  USize hash() const;
  /**
   * Returns a character within the string
   * @param index - the index of the character, starting at 0
   * @return the character, or 0 if the index does not lie within the length of the string
   */
  unsigned char at(USize index) const;
  /**
   * Returns a substring of this string
   * @param start - the 0-based start of the substring
   * @param length - the length of the substring
   * @return a new String for the substring, or a blank string if the start and length do not lie within the current string
   */
  skString substr(USize start,USize length) const;
  /**
   * Returns the substring from the start up to the end of the current string
   * @param start - the 0-based start of the substring
   * @return a new String for the substring, or a blank string if the start does not lie within the current string
   */
  skString substr(USize start) const;
  /**
   * Addition operator
   * @return a String that contains this string followed by the other string
   */
  skString operator+(const skString&) const ;
  /**
   * Increment operator - dereferences the P_String object, and replaces it with the concatenation of this string and the other one
   * @return this string
   */
  skString& operator+=(const skString&);
  /**
   * Length of the string
   * @return the length of the buffer in the P_String object
   */
  USize length() const;
  /**
   * returns the index of the first occurrence of the given character within the string
   * @return an index, or -1 if not found
   */
  int indexOf(char c);
  /**
   * Converts the string to an integer
   */
  int to() const;
  /**
   * Converts the string to a float
   */
  float toFloat() const;
  /**
   * Constructs a string from static string - the static string is *not* copied
   */
  static skString literal(const char *);
  /**
   * Constructs a string from a signed integer
   */
  static skString from(int);
  /**
   * Constructs a string from an unsigned integer
   */
  static skString from(USize);
  /**
   * Constructs a string from a float
   */
  static skString from(float);
  /**
   * Constructs a string from a character
   */
  static skString from(unsigned char ch);
  /**
   * Constructs a string from a buffer, which is *not* copied. The string will delete the buffer when the reference count reaches zero
   */
  static skString fromBuffer(unsigned char * buffer);
 protected:
  /**
   * Constructor - internal taking a P_String and not copying it
   */
  skString(P_String *);
  /**
   * Constructor - internal, taking a buffer and not copying it
   */
  skString(const unsigned char * s,int);
  /**
   * Assigns another buffer to this one, and copies it
   */
  void assign(const unsigned char *,int len=0);				
  /**
   * Dereferences the P_String object, deleting it if the reference count is zero
   */
  void deRef();
  /**
   * The underlying string object
   */
  P_String * pimp;
};
/*
 * A hashKey function for HashTables
 */
inline USize hashKey(skString * s)
{
    return s->hash();
}
/*
 * A streaming operator to write a string to an output stream
 */
ostream& operator<<(ostream&,const skString&s);

/*
 * Some helper macros for declaring literal strings, and references to literal strings
 */
#define skLITERAL(s) skString s_##s=skString::literal(#s)
#define xskLITERAL(s) extern skString s_##s
#define skSTR(s) skString(s)
typedef char Char;
inline float ATOF(const Char * c){
  return (float) atof(c);
}
inline int ATOI(const Char * c){
  return atoi(c);
}

#include "skString.inl"

#endif



