/*
  Copyright 1996-2000
  Simon Whiteside

*/
#include "skInterpreter.h"
#include "InheritsExecutable.h"
#include "skRValueArray.h"
#include "skParseException.h"
#include "skRuntimeException.h"
#include "skExecutable.h"
#include <util/PlatformUtils.hpp>
#include <sax/SAXException.hpp>
#include "skTracer.h"

/**
/**
 * This program loads XML files containing Simkin script.
 *<p>The program calls the "main" method on each script it loads.
 *<p>The script names are passed on the command line.
*/
/**
 * Entry point for the Inherits application. It expects to have an argument giving the filename of an XML file to be loaded.
 * <p>An {@link InheritsExecutable InheritsExecutable} object is created, passed the file, and then the method "main" is called
 */
void main(int argc,char * argv[]){
  if (argc>1){
    // Initialize the Xerces-C library
    XMLPlatformUtils::Initialize();
    
    // Set up global interpreter
    skInterpreter interpreter;
    skInterpreter::setInterpreter(&interpreter);
    for (int i=1;i<argc;i++){
      try{
	// if the file is prefixed ".xml"  create an XML Executable
	skString file_name=argv[i];
	skTracer::trace("Loading %s\n",(const char *)file_name);
	InheritsExecutable executable(file_name);
	// and call the "main" method
	skRValueArray args;
	skRValue return_value;

	executable.method("main",args,return_value);
      }catch(SAXException e){
	cout << e.getMessage();
      }catch(skParseException e){
	cout << e.toString();
      }catch(skRuntimeException e){
	cout << e.toString();
      }catch(...){
      }
    }
  }else
    cout << ("Syntax: Inherits <xml file>\n");
}
