/*
  Copyright 1996-2000
  Simon Whiteside, All Rights Reserved

  THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
  PURPOSE.

  Demo_Main.cpp

  This function provides an entry point for the demo.

  $Id: Demo_Main.cpp,v 1.1 2000/12/21 13:32:59 sdw Exp $
*/

//	these functions are implemented in Demo_xxx.cpp where xxx is the platform
//	either Windows, Mac or X

extern void InitializeEventLoop();
extern void TerminateEventLoop();
extern int ProcessEventLoop();

#include "Demo_Controller.h"
#include "skInterpreter.h"

//-----------------------------------------------------------------
int main(int argc,char * argv[])
  //-----------------------------------------------------------------
{
  //	create an interpreter
  skInterpreter interp;
  //	make it the "global" interpreter
  skInterpreter::setInterpreter(&interp);
  InitializeEventLoop();
  //	create a controller
  Controller controller("Demo.s");
  if (controller.getNode()){
    //	go into event processing
    int r=ProcessEventLoop();
  }
  TerminateEventLoop();
  return 0;
}
