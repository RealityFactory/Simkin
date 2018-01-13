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

#include "CommonFramework.h"
#include "skElementObject.h"
#include "skExpatParser.h"
#include "skString.h"
#include "skInterpreter.h"
#include "skRValueArray.h"
#include "skInputSource.h"
#include "skTraceCallback.h"

/**
* This class catches trace requests from the interpreter
* and outputs it to the console
*/
class ConsoleTracer : public skTraceCallback {
public:
  void trace(const skString& msg){
    console->Printf(msg.ptr());
    TPtrC16 cr((const TUint16 *)L"\n");
    console->Printf(cr);
  }
  void trace(const Char * msg){
    TPtrC16 p((const TUint16 *)msg);
    console->Printf(p);
    TPtrC16 cr((const TUint16 *)L"\n");
    console->Printf(cr);
  }
};

_LIT(KFileName,"c:\\test.xml");
_LIT(Kmain,"main");
// do the example
LOCAL_C void doExampleL()
{
// Create a tracer to output to the console
  ConsoleTracer * tracer=new (ELeave)ConsoleTracer;
  CleanupStack::PushL(tracer);
// Create an interpreter object
  skInterpreter * interp=new (ELeave) skInterpreter;
  CleanupStack::PushL(interp);
  interp->init();
// set the console tracer into the interpreter
  interp->setTraceCallback(tracer);
// Create an executable context
  skExecutableContext * ctxt=new (ELeave)skExecutableContext(interp);
  CleanupStack::PushL(ctxt);
// Create an object to read the script file in
  skInputFile * in=new (ELeave)skInputFile;
  CleanupStack::PushL(in);
  in->open(KFileName);
  if (in->eof()==false){
// Create a reader to read an XML document in
    skExpatParser * parser=new (ELeave)skExpatParser;
    CleanupStack::PushL(parser);
// Try to read in the script
    skElement * element=parser->parse(*in,*ctxt);
    if (element){
      CleanupStack::PushL(element);
      // Create an executable object to wrap the script
      skElementObject * obj=new (ELeave)skElementObject;
      CleanupStack::PushL(obj);
      skString location;
      SAVE_VARIABLE(location);
      obj->setElement(KFileName,element,false);
      // create the argument and return objects
      skRValueArray * args=new (ELeave)skRValueArray;
      CleanupStack::PushL(args);
      skRValue * ret=new (ELeave)skRValue;
      CleanupStack::PushL(ret);
      skString method_name;
      method_name=Kmain;
      // call the "main" method within the script
      obj->method(method_name,*args,*ret,*ctxt);
      // cleanup
      CleanupStack::PopAndDestroy(ret);
      CleanupStack::PopAndDestroy(args);
      RELEASE_VARIABLE(location);
      CleanupStack::PopAndDestroy(obj);
      CleanupStack::PopAndDestroy(element);
    }else{
      tracer->trace(L"Could not load file");
       tracer->trace(ctxt->getError().getException()->toString());
       }
    CleanupStack::PopAndDestroy(parser);
  }else{
    tracer->trace(L"Could not open file");
  }
  CleanupStack::PopAndDestroy(in);
  CleanupStack::PopAndDestroy(ctxt);
  CleanupStack::PopAndDestroy(interp);
  CleanupStack::PopAndDestroy(tracer);
}
