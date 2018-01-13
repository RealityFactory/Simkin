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
#include "skRValueArray.h"
#include "skParseException.h"
#include "skRuntimeException.h"
#include "skExecutableIterator.h"

#include "skXMLExecutable.h"
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax/SAXException.hpp>
#include "skTracer.h"
#include "Test.h"


// define some string constants

skLITERAL(Test);
skLITERAL(main);

/*
 *This program loads XML or TreeNode files containing Simkin script.
 *<p>The program calls the "main" method on each script it loads.
 *<p>The script names are passed on the command line.
*/
/*
 * Entry point for the ScriptLoader application. It expects to have an argument giving the filename of an XML or TreeNode file to be loaded.
 * <p>An {@link skXMLExecutable skXMLExecutable} or {@link skScriptedExecutable skScriptedExecutable} object is created, passed the file, and then the method "main" is called
 */
int main(int argc,Char * argv[]){
  if (argc>1){
    // Initialize the Xerces-C library
    XMLPlatformUtils::Initialize();
    
    // Set up global interpreter
    skInterpreter interpreter;
    // set up an executable context
    skExecutableContext ctxt(&interpreter);
    // create global variable of class "Test" - we can use this in scripts to create instances of test,
    // using the "createObject" method
    interpreter.addGlobalVariable(s_Test,new skTest());
    for (int i=1;i<argc;i++){
      try{
        // if the file is prefixed ".xml"  create an XML Executable
        skString file_name=argv[i];
        int name_len=file_name.length();
        if (name_len>4){
	        skString extension=file_name.substr(name_len-4,4);
          if (extension==skSTR(".xml") || extension==skSTR(".XML")){
            skXMLExecutable executable(file_name);
            // and call the "main" method
            skRValueArray args;
            skRValue return_value;
            executable.method(s_main,args,return_value,ctxt);
          }
        }
      }catch(SAXException e){
        skTracer::trace(skSTR("XML Parse Error"));
      }catch(skParseException e){
        skTracer::trace(e.toString());
      }catch(skRuntimeException e){
        skTracer::trace(e.toString());
      }catch(...){
        skTracer::trace(skSTR("unknown exception"));
      }
    }
  }else
    skTracer::trace(skSTR("Syntax: ScriptLoader <xml file>\n"));
  return 0;
}
