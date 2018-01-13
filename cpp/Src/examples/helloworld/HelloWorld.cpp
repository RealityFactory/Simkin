/*
  Copyright 1996-2002
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
*/
#include "skInterpreter.h"
#include "skElementExecutable.h"
#include "skRValueArray.h"
#include "skInputSource.h"

/**
 * This example shows the simplest possible application which just prints "Hello World"
 */

// A simple piece of XML, that just shows "Hello World" on the console
const char * g_XML="<object><function name=\"main\"> trace(\"Hello World\"); </function></object>";

skLITERAL(main);

void main(){

  // Set up global interpreter
  skInterpreter i;
  // And an executable context
  skExecutableContext ctxt(&i);

  // create an XMLExecutable object with the xml string
  skInputString in(g_XML);
  skElementExecutable executable("Hello World",in,ctxt);

  // call the "main" method
  skRValueArray args;
  skRValue return_value;
  executable.method(s_main,args,return_value,ctxt);

}
