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

#include "skScriptedExecutable.h"
#include "skTracer.h"
#include "Test.h"


// define some string constants

skLITERAL(Test);
skLITERAL(main);

/*
 *This program loads TreeNode files containing Simkin script.
 *<p>The program calls the "main" method on each script it loads.
 *<p>The script names are passed on the command line.
*/
/*
 * Entry point for the ScriptLoader application. It expects to have an argument giving the filename of an XML or TreeNode file to be loaded.
 * <p>An {@link skXMLExecutable skXMLExecutable} or {@link skScriptedExecutable skScriptedExecutable} object is created, passed the file, and then the method "main" is called
 */
int 
#ifdef _WIN32_WCE
__cdecl
#endif
main(int argc,Char * argv[]){
  if (argc>1){
    
    // Set up global interpreter
    skInterpreter interpreter;
    // set up an executable context
    skExecutableContext ctxt(&interpreter);
    // create global variable of class "Test" - we can use this in scripts to create instances of test,
    // using the "createObject" method
    interpreter.addGlobalVariable(s_Test,new skTest());
    for (int i=1;i<argc;i++){
#ifdef EXCEPTIONS_DEFINED
      try{
#endif
        // if the file is prefixed ".xml"  create an XML Executable
        skString file_name=argv[i];
        int name_len=file_name.length();
        if (name_len>4){
	        skString extension=file_name.substr(name_len-4,4);
          skScriptedExecutable executable(file_name,ctxt);
          // and call the "main" method
          skRValueArray args;
          skRValue return_value;
          executable.method(s_main,args,return_value,ctxt);
        }
#ifdef EXCEPTIONS_DEFINED
      }catch(skParseException e){
        skTracer::trace(e.toString());
      }catch(skRuntimeException e){
        skTracer::trace(e.toString());
      }catch(...){
        skTracer::trace(skSTR("unknown exception"));
      }
#else
      // if exceptions are not being used - examine the error code in the 
      // skExecutableContext object to spot any errors
      if (ctxt.m_Error.getErrorCode()!=skScriptError::NONE)
        skTracer::trace(ctxt.m_Error.getException()->toString());
#endif
    }
  }else
    skTracer::trace(skSTR("Syntax: ScriptLoader <treenode file>\n"));
  return 0;
}
// Entry point for Windows CE applications
#ifdef _WIN32_WCE
int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd)
{
	main(1,&lpCmdLine);
	return 0;
}
#endif