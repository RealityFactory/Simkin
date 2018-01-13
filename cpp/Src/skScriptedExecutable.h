/*
  Copyright 1996-2001
  Simon Whiteside

* $Id: skScriptedExecutable.h,v 1.12 2001/03/05 16:46:28 sdw Exp $
*/

#ifndef skSCRIPTEDEXECUTABLE_H
#define skSCRIPTEDEXECUTABLE_H

#include "skTreeNodeObject.h"

/**
 * This class provides an executable whose additional fields and methods are taken from a TreeNode file - most
 * of the behaviour is defined in the base class skTreeNodeObject
 */
class skScriptedExecutable : public skTreeNodeObject
{ 
 public:
  /**
   * Constructor - takes the name of the file from which the treenode will be loaded
   */
  skScriptedExecutable(const skString& filename);
  /**
   * Virtual destructor - so that derived class destructors will be called
   */
  virtual ~skScriptedExecutable();
 private:
  /**
   * Executables can't be copied
   */
  skScriptedExecutable(const skScriptedExecutable&);
  /**
   * Executables can't be copied
   */
  skScriptedExecutable& operator=(const skScriptedExecutable&);
};
#endif
