/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skBoundsException.h,v 1.4 2001/06/13 16:48:21 sdw Exp $
*/
#ifndef SKBOUNDSEXCEPTION_H
#define SKBOUNDSEXCEPTION_H

#include "skString.h"

/**
 * this class represents an exception thrown by the collection classes
 */

class skBoundsException {
 public:
  /**
   * Constructor
   */
  skBoundsException(const skString& msg,const char * file,int linenum)
    : m_Msg(msg),m_File(file),m_LineNum(linenum){
  }
  /**
   * produces a string describing the exception
   */
  skString toString() const{
	  return skString::literal(m_File)+skSTR(":")+skString::from(m_LineNum)+m_Msg;
  }
 private:
  skString m_Msg;
  const char * m_File;
  int m_LineNum;

};
#endif
