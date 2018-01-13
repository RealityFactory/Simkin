/**
   $Id: skRValueTable.h,v 1.1 2001/06/29 09:18:21 sdw Exp $
   Copyright 1996-2001
   Simon Whiteside
*/
#ifndef skRVALUETABLE_H
#define skRVALUETABLE_H

#include "skHashTable.h"
#include "skRValue.h"

/** This class is used to hold a hash table of skRValue's based on name. It is used to store local or global variables in the interpreter
 */
class skRValueTable: public skTHashTable<skString,skRValue>
{
 public:
  skRValueTable(unsigned short  size)
    : skTHashTable<skString,skRValue>(size){
  }
  skRValueTable(){
  }
  ~skRValueTable(){
  }

};

#endif
