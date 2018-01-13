/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skGeneral.h,v 1.4 2001/03/05 16:46:28 sdw Exp $
*/
#ifndef GENERAL_H
#define GENERAL_H

#include <iostream.h>
#include <stdlib.h>
#include "assert.h"

typedef unsigned int USize;
 
#ifndef max
#define max(a,b) (((a)>(b))?(a):(b))
#endif
#ifndef min
#define min(a,b) (((a)<(b))?(a):(b))
#endif
#endif
