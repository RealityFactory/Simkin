/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skTracer.h,v 1.3 2001/03/05 16:46:28 sdw Exp $
*/

#ifndef skTRACER_H
#define skTRACER_H

/**
 * This class is used to provide output to a trace
 */
class skTracer {
 public:
  /** 
   * this function outputs its arguments to stdout
   */
  static void trace(const char * buffer,...);
};
#endif
