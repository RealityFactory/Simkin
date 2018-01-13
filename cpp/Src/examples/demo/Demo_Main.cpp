/*
  Copyright 1996-2002
  Simon Whiteside, All Rights Reserved


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

  Demo_Main.cpp

  This function provides an entry point for the demo.

  $Id: Demo_Main.cpp,v 1.4 2002/12/20 15:06:32 sdw Exp $
*/

//	these functions are implemented in Demo_xxx.cpp where xxx is the platform
//	either Windows, Mac or X

extern void InitializeEventLoop();
extern void TerminateEventLoop();
extern int ProcessEventLoop();

#include "Demo_Controller.h"
#include "skInterpreter.h"

//-----------------------------------------------------------------
int 
#ifdef _WIN32_WCE
__cdecl
#endif
main(int argc,char * argv[])
  //-----------------------------------------------------------------
{
  //	create an interpreter
  skInterpreter interp;
  InitializeEventLoop();
  // creata an executable context
  skExecutableContext context(&interp);
  //	create a controller
#ifdef _WIN32_WCE
  Controller controller(skSTR("\\My Documents\\Demo.s"),context);
#else
  Controller controller(skSTR("Demo.s"),context);
#endif
  if (controller.getNode()){
    //	go into event processing
    int r=ProcessEventLoop();
  }
  TerminateEventLoop();
  return 0;
}
