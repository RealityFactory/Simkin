/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skTracer.h,v 1.4 2001/06/13 16:48:21 sdw Exp $
*/

#ifndef skTRACER_H
#define skTRACER_H

#include "skString.h"

/**
 * This class is used to provide output to a trace
 */
class skTracer {
 public:
  /** 
   * this function outputs its arguments to stdout
   */
  static void trace(const skString& s);
};
#endif
