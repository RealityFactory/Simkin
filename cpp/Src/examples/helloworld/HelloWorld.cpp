/*
  Copyright 1996-2000
  Simon Whiteside

*/
#include "skInterpreter.h"
#include "skXMLExecutable.h"
#include "skRValueArray.h"
#include <util/PlatformUtils.hpp>

/**
 * This example shows the simplest possible application which just prints "Hello World"
 */

// A simple piece of XML, that just shows "Hello World" on the console
const char * g_XML="<object><function name=\"main\"> trace(\"Hello World\"); </function></object>";

void main(){
  // Initialize the Xerces-C library
  XMLPlatformUtils::Initialize();

  // Set up global interpreter
  skInterpreter i;
  skInterpreter::setInterpreter(&i);

  // create an XMLExecutable object with the xml string
  skXMLExecutable executable("Hello World",g_XML);

  // call the "main" method
  skRValueArray args;
  skRValue return_value;
  executable.method("main",args,return_value);

  // Terminate the Xerces-C library
  XMLPlatformUtils::Terminate();
}
