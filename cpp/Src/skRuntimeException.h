/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skRuntimeException.h,v 1.3 2001/03/05 16:46:28 sdw Exp $
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
  skRuntimeException(const skString& location,const skString& msg) 
      : m_Location(location),m_Msg(msg){
  }
  /**
   * this method returns a description of the exception
   */
  skString toString() const {
    return m_Location+":"+m_Msg;
  }
 private:
  skString m_Msg;
  skString m_Location;
};
#endif
