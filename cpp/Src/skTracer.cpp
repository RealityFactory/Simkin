/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skTracer.cpp,v 1.2 2001/03/05 16:46:28 sdw Exp $
*/
#include "skTracer.h"
#include <stdarg.h>
#include <stdio.h>

//------------------------------------------
void skTracer::trace(const char * buffer,...)
//------------------------------------------
{
    va_list marker;
    va_start( marker, buffer);
    vprintf(buffer,marker);
}
