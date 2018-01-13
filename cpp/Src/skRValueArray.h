/*
* $Id: skRValueArray.h,v 1.6 2000/12/19 13:19:25 sdw Exp $
*/
#ifndef skRVALUEARRAY_H
#define skRVALUEARRAY_H

#include "skRValue.h"
#include "skValist.h"


/**
 * This class provides an array of RValues
 */
class skRValueArray	: public skTVAList<skRValue>
{ 
 public:
  /**
   * Default Constructor: creates an array of zero size
   */
  skRValueArray() {}
  /**
   * Constructor: creates an array of the given size
   */
  skRValueArray(unsigned short size)
    : skTVAList<skRValue>(size,size) {}
};
#endif



