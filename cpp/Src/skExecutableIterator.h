/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skExecutableIterator.h,v 1.1 2001/06/13 16:48:54 sdw Exp $
*/

#ifndef skEXECUTABLEITERATOR_H
#define skEXECUTABLEITERATOR_H


#include "skGeneral.h"

class skRValue;

/**
 * This class is used to iterate over a set of values whilst in the foreach statement
 */
class skExecutableIterator {
 public:
  virtual ~skExecutableIterator();
  virtual bool next(skRValue&)=0;
};

#endif

