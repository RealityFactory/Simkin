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
#include "skExecutableIterator.h"
#include <util/PlatformUtils.hpp>
#include <sax/SAXException.hpp>

/**
 * This small class can be used to trace calls into an iterator from a foreach statement in a script
 */
class skTestIterator : public skExecutableIterator {
  int m_Count;
public:
  skTestIterator() : m_Count(0){
  }
  bool next(skRValue& v){
    bool ret=false;
    if (m_Count<10){
      v=m_Count;
      cout << "skTestIterator::next\n";
      cout.flush();
      m_Count++;
      ret=true;
    }
    return ret;
  }
};
/**
 * You can use this small class to trace calls into a C++ object from a script. The class supports the method "createObject" and an instance is put as a global variable called "Test". This means you can do the following in Simkin script:
 * <pre>
 * a=Test.createObject();
 * b=a:name;
 * </pre>
 * And watch a trace of the "getValue" function being called
 */

class skTest : public skExecutable{
public:
  skTest(){
  }
  skExecutableIterator * createIterator(const skString& qualifier){
    cout << "skTest::createIterator qualified by " << qualifier <<"\n";
    cout.flush();
    return new skTestIterator();
  }
  skExecutableIterator * createIterator(){
    cout << "skTest::createIterator\n";
    cout.flush();
    return new skTestIterator();
  }
  bool getValue(const skString& field_name,const skString& attribute,skRValue& value){
    cout << "skTest::getValue field_name=" << field_name << " attribute=" << attribute << "\n";
    cout.flush();
    return true;
  }
  bool setValue(const skString& field_name,const skString& attribute,const skRValue& value){
    cout << "skTest::setValue field_name=" << field_name << " attribute=" << attribute << "\n";
    cout.flush();
    return true;
  }
  bool setValueAt(const skRValue& array_index, const skString& attribute,const skRValue& value)
  {
    cout << "skTest::setValueAt array_index=" << array_index.str() << " attribute=" << attribute << " value=" << value.str() << "\n";
    cout.flush();
    return true;
  }

  bool getValueAt(const skRValue& array_index, const skString& attribute, skRValue& value)
  {
    cout << "skTest::getValueAt array_index=" << array_index.str() << " attribute=" << attribute << "\n";
    cout.flush();
    return true;
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
	cout << "unknown exception";
      }
    }
  }else
    cout << ("Syntax: ScriptLoader <xml file>\n");
}
