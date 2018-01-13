/*
  Copyright 1996-2000
  Simon Whiteside

*/
#include "skInterpreter.h"
#include "skXMLExecutable.h"
#include "skScriptedExecutable.h"
#include "skRValueArray.h"
#include "skParseException.h"
#include "skRuntimeException.h"
#include "skExecutable.h"
#include <util/PlatformUtils.hpp>
#include <sax/SAXException.hpp>

/**
 * You can use this small class to trace calls into a C++ object from a script. The class supports the method "createObject" and an instance is put as a global variable called "Test". This means you can do the following in Simkin script:
 * <pre>
 * a=Test.createObject();
 * b=a:name;
 * </pre>
 * And watch a trace of the "getValue" function being called
 */

class skTest : public skExecutable {
public:
  skTest(){
  }
  bool getValue(const skString& field_name,const skString& attribute,skRValue& value){
    cout << "skTest::getValue field_name=" << field_name << " attribute=" << attribute << "\n";
    return skExecutable::getValue(field_name,attribute,value);
  }
  bool setValue(const skString& field_name,const skString& attribute,const skRValue& value){
    cout << "skTest::setValue field_name=" << field_name << " attribute=" << attribute << "\n";
    return skExecutable::setValue(field_name,attribute,value);
  }
  bool method(const skString& method_name,skRValueArray& arguments,skRValue& return_value){
    cout << "skTest::method method_name=" << method_name << "\n";
    bool bRet=false;
    if (method_name=="createObject"){
      return_value=skRValue(new skTest(),true);
      bRet=true;
    }else{
      bRet=skExecutable::method(method_name,arguments,return_value);
    }
    return bRet;
  }
};

/**
 *This program loads XML or TreeNode files containing Simkin script.
 *<p>The program calls the "main" method on each script it loads.
 *<p>The script names are passed on the command line.
*/
/**
 * Entry point for the ScripLoader application. It expects to have an argument giving the filename of an XML or TreeNode file to be loaded.
 * <p>An {@link skXMLExecutable skXMLExecutable} or {@link skScriptedExecutable skScriptedExecutable} object is created, passed the file, and then the method "main" is called
 */
void main(int argc,char * argv[]){
  if (argc>1){
    // Initialize the Xerces-C library
    XMLPlatformUtils::Initialize();
    
    // Set up global interpreter
    skInterpreter interpreter;
    skInterpreter::setInterpreter(&interpreter);
    interpreter.addGlobalVariable("Test",new skTest());
    for (int i=1;i<argc;i++){
      try{
	// if the file is prefixed ".xml"  create an XML Executable
	skString file_name=argv[i];
	int name_len=file_name.length();
	if (name_len>4){
	  skString extension=file_name.substr(name_len-4,4);
	  if (extension==".xml" || extension==".XML"){
	    skXMLExecutable executable(file_name);
	    // and call the "main" method
	    skRValueArray args;
	    skRValue return_value;
	    executable.method("main",args,return_value);
	  }else{
	    skScriptedExecutable executable(file_name);
	    // and call the "main" method
	    skRValueArray args;
	    skRValue return_value;
	    executable.method("main",args,return_value);
	  }
	}
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
    cout << ("Syntax: ScriptLoader <xml file>\n");
}
