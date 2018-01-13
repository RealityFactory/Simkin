/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skRValue.h,v 1.9 2001/03/05 16:46:28 sdw Exp $
*/
#ifndef skRVALUE_H
#define skRVALUE_H

#include "skString.h"

class skExecutable;
class skObjectRef;

/**
 * This class is used to hold the value of a variable in Simkin. It can hold reference counts for objects and delete them when these reach zero.
 */
class skRValue	
{ 
 public:
  /**
   * An RValue has a value of one of these types: Executable object, String, integer, float or character
   */
  enum RType { T_Object,T_String,T_Int,T_Float,T_Char,T_Bool };
   
  /**
   * Default Constructor - creates a blank string object
   */ 
  skRValue();
  /**
   * Copy Constructor - copies type and value from the other object
   */ 
  skRValue(const skRValue&);
  /**
   * Constructor with an executable object
   * @param object - the object to be associated with the RValue
   * @param created - set this to true if you want the object to be deleted once all references have reached zero
   */
  skRValue(skExecutable * obj,bool created=false);
  /**
   * Constructor with a string
   */
  skRValue(skString s);
  /**
   * Constructor with a character
   */
  skRValue(char c);
  /**
   * Constructor with an integer
   */
  skRValue(int n);
  /**
   * Constructor with an unsigned integer
   */
  skRValue(unsigned int n);
  /**
   * Constructor with a float
   */
  skRValue(float f);
  /**
   * Constructor with a boolean value
   */
  skRValue(bool b);
  /**
   * Destructor - will delete an associated object if the created flag is set in constructor
   */
  ~skRValue();
  /**
   * Assigment operator - clears this value, and then assigns type and value
   */
  skRValue& operator=(const skRValue& v);
  /**
   * returns true if the other value is equal to this one. Comparison depends on the types held in each value.
   */
  bool operator==(const skRValue&);
  /**
   * returns a character representation of the value, converting if necessary
   */
  char	charValue()  const;		
  /**
   * returns a boolean representation of the value, converting if necessary
   */
  bool	boolValue()  const;		
  /**
   * returns an integer representation of the value, converting if necessary
   */
  int intValue()  const;		
  /**
   * returns a float representation of the value, converting if necessary
   */
  float floatValue()  const;		
  /**
   * returns a string representation of the value, converting if necessary
   */
  skString str() const;
  /**
   * returns the object associated with this RValue, or 0 if there is none
   */
  skExecutable * obj()  const;
  /**
   * returns the type of the value held in this RValue - one of the enumerated RType
   */
  RType	type()  const;
 private:	                         
  /**
   * The type of the value
   */
  unsigned char m_Type;
  /**
   * The string value
   */
  skString m_String;
  
  /**
   * A union of object reference or numeric type
   */
  union {
    skObjectRef * m_ObjectRef;	
    char m_Char;
    int	m_Int;
    float m_Float;
    bool m_Bool;
  }m_Value;
};                              

#endif


