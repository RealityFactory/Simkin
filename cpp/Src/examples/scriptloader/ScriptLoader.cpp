/*
  Copyright 1996-2000
  Simon Whiteside

*/
#include "skInterpreter.h"
#include "skXMLExecutable.h"
#include "skRValueArray.h"
#include "skParseException.h"
#include "skRuntimeException.h"
#include <util/PlatformUtils.hpp>

/**
 *This program loads XML files containing Simkin script.
 *<p>The program calls the "main" method on each script it loads.
 *<p>The script names are passed on the command line.
*/
/**
 * Entry point for the ScripLoader application. It expects to have an argument giving the filename of an XML file to be loaded.
 * <p>An {@link skXMLExecutable skXMLExecutable} object is created, passed the file, and then the method "main" is called
 */
void main(int argc,char * argv[]){
  if (argc>1){
    // Initialize the Xerces-C library
    XMLPlatformUtils::Initialize();
    
    // Set up global interpreter
    skInterpreter interpreter;
    skInterpreter::setInterpreter(&interpreter);
    for (int i=1;i<argc;i++){
      // create an XML Executable
      skXMLExecutable executable(argv[i]);
      // and call the "main" method
      skRValueArray args;
      skRValue return_value;
      try{
	executable.method("main",args,return_value);
      }catch(skParseException e){
	cout << e.toString();
      }catch(skRuntimeException e){
	cout << e.toString();
      }
    }
  }else
    cout << ("Syntax: ScriptLoader <xml file>\n");
}
