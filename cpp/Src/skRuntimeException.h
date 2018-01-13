/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skRuntimeException.h,v 1.5 2001/06/19 14:02:47 sdw Exp $
*/
#ifndef SKRUNTIMEEXCEPTION_H
#define SKRUNTIMEEXCEPTION_H

#include "skString.h"

/**
 * This exception is thrown when there are execution errors in a Simkin script
 */
class skRuntimeException {
 public:
  /**
   * Constructor - receives information about the exception
   */
  skRuntimeException(const skString& location,int line_num,const skString& msg) 
      : m_Location(location),m_Msg(msg),m_LineNum(line_num){
  }
  /**
   * this method returns a description of the exception
   */
  skString toString() const {
    return m_Location+skSTR(":")+skString::from(m_LineNum)+skSTR("-")+m_Msg;
  }
   /**
   * returns the location of the script
   */
  skString location() const{
    return m_Location;
  }
  /**
   * shows the line number where the runtime error occurred
   */
  int lineNum() const{
    return m_LineNum;
  }
private:
  int m_LineNum;
  skString m_Msg;
  skString m_Location;
};
#endif
