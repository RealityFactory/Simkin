/*
  copyright 1996-2001
  Simon Whiteside

* $Id: skScriptedExecutable.cpp,v 1.10 2001/03/05 16:46:28 sdw Exp $
*/
#include "skScriptedExecutable.h"
#include "skTreeNode.h"

//------------------------------------------
skScriptedExecutable::skScriptedExecutable(const skString& filename)
//------------------------------------------
  : skTreeNodeObject(filename,skTreeNode::read(filename),true)
{
}
//------------------------------------------
skScriptedExecutable::~skScriptedExecutable()
//------------------------------------------
{
}
//------------------------------------------
skScriptedExecutable::skScriptedExecutable(const skScriptedExecutable& other)
//------------------------------------------
{
}
//------------------------------------------
skScriptedExecutable& skScriptedExecutable::operator=(const skScriptedExecutable& other)
//------------------------------------------
{
  return *this;
}
