/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skTraceCallback.h,v 1.1 2001/06/29 09:18:21 sdw Exp $
*/
#ifndef skTRACECALLBACK_H
#define skTRACECALLBACK_H
#include "skString.h"

/**
 * This abstract class is used to provide an interface for the Interpreter to pass
 * trace messages to
 */

class skTraceCallback {
 public:
  /** This method receives trace messages from the interpreter and Simkin scripts
   * @param msg  the trace message
   */
  virtual void trace(const skString& msg)=0;
};
#endif
