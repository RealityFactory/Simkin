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

  PURPOSE.

  Demo_Main.cpp

  This function provides an entry point for the demo.

  $Id: Demo_Main.cpp,v 1.1 2003/01/23 14:22:09 simkin_cvs Exp $
*/

//	these functions are implemented in Demo_xxx.cpp where xxx is the platform
//	either Windows, Mac or X

extern void InitializeEventLoop();
extern void TerminateEventLoop();
extern int ProcessEventLoop();

#include "skXMLParseException.h"

#include <comdef.h>

// Load the COM libraries
struct StartOle
{
    StartOle( ) { CoInitialize( NULL ); };
    ~StartOle( ) { CoUninitialize(); };
} _inst_StartOle;

#include "Demo_Controller.h"
#include "skInterpreter.h"

//-----------------------------------------------------------------
int main(int argc,char * argv[])
  //-----------------------------------------------------------------
{
  //	create an interpreter
  skInterpreter interp;
  try{
    InitializeEventLoop();
    //	create a controller
    Controller controller("Demo.xml",&interp);
    if (controller.getElement()!=0){
      //	go into event processing
      int r=ProcessEventLoop();
    }
  }catch(skXMLParseException e){
    cerr << "There was an error in parsing the XML file.\n";
  }
  TerminateEventLoop();
  return 0;
}
