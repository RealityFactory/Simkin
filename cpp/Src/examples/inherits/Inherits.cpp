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
#include "InheritsExecutable.h"
#include "skRValueArray.h"
#include "skParseException.h"
#include "skRuntimeException.h"
#include "skExecutable.h"
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax/SAXException.hpp>
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
    for (int i=1;i<argc;i++){
      try{
        // if the file is prefixed ".xml"  create an XML Executable
        skString file_name=argv[i];
        skTracer::trace(skString("Loading ")+file_name+"\n");
        InheritsExecutable executable(file_name);
        // and call the "main" method
        skRValueArray args;
        skRValue return_value;
        skExecutableContext ctxt(&interpreter);
        executable.method("main",args,return_value,ctxt);
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
