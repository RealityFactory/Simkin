/*
  Copyright 1996-2001
  Simon Whiteside

  $Id: skStringList.h,v 1.5 2001/03/05 16:46:28 sdw Exp $
*/
#ifndef STRINGLIST_H
#define STRINGLIST_H

#include "skString.h"
#include "skValist.h"

/**
 * This class is a list of Strings, held by value
 */
class skStringList : public  skTVAList<skString> {
};
#endif
