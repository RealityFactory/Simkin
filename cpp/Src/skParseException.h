/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skParseException.h,v 1.4 2001/03/05 16:46:28 sdw Exp $
*/
#ifndef SKPARSEEXCEPTION_H
#define SKPARSEEXCEPTION_H

#include "skString.h"
#include "skValist.h"

/**
  This class encapsulates an error message from the parser, representing a syntax error in the script
*/
class skCompileError
{
 public:
  /** 
   * Default constructor
   */
  skCompileError() 
    : m_LineNum(0){
  }
  /**
   * Constructor which is passed information about the error
   */
  skCompileError(skString location,int line_num,const skString& msg)
    : m_Location(location),m_LineNum(line_num),m_Msg(msg){
  }
  /**
   * returns the location of the script, as passed into the parse() function
   */
  skString location() const{
    return m_Location;
  }
  /**
   * shows the line number where the syntax error occurred
   */
  int lineNum() const{
    return m_LineNum;
  }
  /**
   * gives a message about the error
   */
  skString msg() const{
    return m_Msg;
  }
  /**
   * this method returns a string representation of the whole error
   */
  skString toString() const {
    return m_Location+":"+skString::from(m_LineNum)+":"+m_Msg;
  }
 private:
  int m_LineNum;
  skString m_Location;
  skString m_Msg;
};
/**
 * This is a list of compile errors
 */
class skCompileErrorList : public skTVAList<skCompileError> 
{
};
/**
 * This exception is thrown when there are parse errors in some Simkin script
 */
class skParseException {
 public:
  /**
   * Constructor - the exception is passed a list of errors
   */
  skParseException(const skCompileErrorList& errors) : m_Errors(errors) {
  }
  /**
   * this method returns a list of errors encountered in parsing the script
   */
  const skCompileErrorList& getErrors() const{
    return m_Errors;
  }
  /**
   * this method returns a string representation of the exception - concatenating all the error messages onto different lines
   */
  skString toString() const {
    skString ret;
    for (unsigned int i=0;i<m_Errors.entries();i++)
      ret+=m_Errors[i].toString()+"\n";
    return ret;
  }
 private:
  skCompileErrorList m_Errors;
};

#endif
