/*
  Copyright 1996-2003
  Simon Whiteside

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  $Id: DynamicTreeNode.cpp,v 1.3 2003/02/24 19:59:48 simkin_cvs Exp $

*/
#include "skInterpreter.h"
#include "skScriptedExecutable.h"
#include "skTreeNode.h"
#include "skRValueArray.h"

/**
 * This programs shows how to use dynamic treenodes.
 * It loads a script called dynamic.dat which adds data to a global treenode object called "Data"
*/
void main(int argc,char * argv[])
{
  // create an interpreter and a context
  skInterpreter interp;
  skExecutableContext ctxt(&interp);
  
  // create a blank treenode object
  skTreeNodeObject obj("Data",new skTreeNode,true);
  
  // set the "AddIfNotPresent" flag
  obj.setAddIfNotPresent(true);
  
  // set this object as a global variable called "Data"
  interp.addGlobalVariable("Data",&obj);
  
  // call the script which will manipulate the Data object
  skScriptedExecutable s("dynamic.dat",ctxt);
  skRValueArray args;
  skRValue ret;
  s.method("main",args,ret,ctxt);
}
