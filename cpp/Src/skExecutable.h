/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skExecutable.h,v 1.16 2001/05/03 16:01:31 sdw Exp $
*/

#ifndef skEXECUTABLE_H
#define skEXECUTABLE_H

#include "skString.h"

class skRValueArray;
class skRValue;



/*
 * this constant is for undefined type primitive objects
 */
const int UNDEFINED_TYPE=0;
/*
 * this constant is should be used for the type of any user-defined primitive objects
 */
const int START_USER_TYPES=10;

/**
 * This class gives an interface for the Interpreter to call into
 */
class skExecutable
{ 
 public:
  /**
   * Default Constructor
   */
  skExecutable();
  /**
   * Destructor
   */
  virtual ~skExecutable();
  
  /**
   * this method returns the type of the object. By default this is UNDEFINED_TYPE.
   * Define your own value if you want to check the type of your object at run-time
   */
  virtual int executableType() const;			
  /**
   * returns an integer equivalent of this object
   */
  virtual int intValue() const;
  /**
   * returns a boolean equivalent of this object
   */
  virtual bool boolValue() const;
  /**
   * returns a character equivalent of this object
   */
  virtual char charValue() const;
  /**
   * returns a String equivalent of this object
   */
  virtual skString strValue() const; 
  /**
   * returns a float equivalent of this object
   */
  virtual float floatValue() const;
  /**
   * requests the object to set a field to the given value
   * @param field_name - the name of the field name to set
   * @param attribute - the attribute name to set (may be blank)
   * @param value - the value to be set
   * @return true if the field was changed, false if the field could not be set or found
   */
  virtual bool setValue(const skString& field_name,const skString& attribute,const skRValue& value); 
  /**
   * requests the object to set an item in its collection to a certain value
   * @param array_index - the identifier of the item - this might be a string, integer or any other legal value
   * @param attribute - the attribute name to set (may be blank)
   * @param value - the value to be set
   * @return true if the field was changed, false if the field could not be set or found
   */
  virtual bool setValueAt(const skRValue& array_index,const skString& attribute,const skRValue& value); 
  /**
   * requests the object to return a field's  value
   * @param field_name - the name of the field name to get
   * @param attribute - the attribute name to get (may be blank)
   * @param value - the value to receive the value of the field
   * @return true if the field was changed, false if the field could not be get or found
   */
  virtual bool getValue(const skString& field_name,const skString& attribute,skRValue& value);
  /**
   * requests the object to return an object from its collection
   * @param array_index - the identifier of the item - this might be a string, integer or any other legal value
   * @param attribute - the attribute name to get (may be blank)
   * @param value - the value to receive the value of the field
   * @return true if the field was changed, false if the field could not be get or found
   */
  virtual bool getValueAt(const skRValue& array_index,const skString& attribute,skRValue& value);
  /**
   * Requests that the object execute the given method
   * @param method_name - the name of the method to execute
   * @param arguments - an array of RValue objects, which are the arguments to the method
   * @param return_value - an object to receive the return value of the method
   * @param return true if the method could be executed, or false if the method is not supported
   */
  virtual bool method(const skString& method_name,skRValueArray& arguments,skRValue& return_value);
  /**
   * This method compares this object with another object. The default implementation checks object pointers.
   */
  virtual bool equals(skExecutable * other_object) const;
 private:
  /**
   * Executables can't be copied
   */
  skExecutable(const skExecutable& other);
  /**
   * Executables can't be copied
   */
  skExecutable& operator=(const skExecutable& other);
};

// Some help-defines for method, getValue and setValue

#define IS_METHOD(s,m)		(s==m)
#define IS_GETVALUE(s,v)	(s==v)
#define IS_SETVALUE(s,v)	(s==v)


#endif
