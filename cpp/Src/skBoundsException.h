/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skBoundsException.h,v 1.3 2001/03/05 16:46:28 sdw Exp $
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
    return skString(m_File)+":"+skString::from(m_LineNum)+m_Msg;
  }
 private:
  skString m_Msg;
  const char * m_File;
  int m_LineNum;

};
#endif
