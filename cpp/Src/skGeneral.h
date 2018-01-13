/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skGeneral.h,v 1.6 2001/05/22 11:57:57 sdw Exp $
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

// Windows Specific Thread Control...
// We use this for skInterpreter::getInterpreter()
// What we should do is have a method whereby the curent interpreter is set into each executable
// object, so that it can be reused when that object spawns a new one.
// At present, this only occurs in skTreeNodeObject and skXMLElementObject
// TODO: Define thread control for other platforms!!!
#if defined(_MSC_VER) && (_MSC_VER >= 1200 )
#define THREAD __declspec(thread)
#else
#define THREAD
#endif

#endif
