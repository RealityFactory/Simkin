/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skMethodTable.h,v 1.3 2001/03/05 16:46:28 sdw Exp $
*/
#ifndef skMETHODTABLE_H
#define skMETHODTABLE_H

#include "skHashTable.h"
#include "skParseNode.h"

/**
 * This class can be used to cache parse trees. It is a hashtable mapping method name to parse tree
 */
class skMethodTable : public skTHashTable<skString,skMethodDefNode>
{
};

#endif

