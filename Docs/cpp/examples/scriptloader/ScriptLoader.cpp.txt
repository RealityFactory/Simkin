/*
  Copyright 1996-2001
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
#ifdef USE_XERCES
#define USE_XML
#include "skXMLExecutable.h"
#include <util/PlatformUtils.hpp>
#include <sax/SAXException.hpp>
#endif
#ifdef USE_EXPAT
#define USE_XML
#include "skXMLParseException.h"
#include "skElementExecutable.h"
#endif
#ifdef USE_TREENODE
#include "skScriptedExecutable.h"
#endif

/*
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
/*
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

/*
 *This program loads XML or TreeNode files containing Simkin script.
 *<p>The program calls the "main" method on each script it loads.
 *<p>The script names are passed on the command line.
*/
/*
 * Entry point for the ScriptLoader application. It expects to have an argument giving the filename of an XML or TreeNode file to be loaded.
 * <p>An {@link skXMLExecutable skXMLExecutable} or {@link skScriptedExecutable skScriptedExecutable} object is created, passed the file, and then the method "main" is called
 */
int main(int argc,char * argv[]){
  if (argc>1){
#ifdef USE_XERCES
    // Initialize the Xerces-C library
    XMLPlatformUtils::Initialize();
#endif
    
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
#ifdef USE_XML
	  if (extension==".xml" || extension==".XML"){
#ifdef USE_XERCES
	    skXMLExecutable executable(file_name);
#endif
#ifdef USE_EXPAT
	    skElementExecutable executable(file_name);
#endif
	    // and call the "main" method
	    skRValueArray args;
	    skRValue return_value;
	    executable.method("main",args,return_value);
	    
	    cout.flush();
	  }
#endif
#ifdef USE_TREENODE
	  skScriptedExecutable executable(file_name);
	  // and call the "main" method
	  skRValueArray args;
	  skRValue return_value;
	  executable.method("main",args,return_value);
#endif
	}
#ifdef USE_XERCES
      }catch(SAXException e){
	cout << e.getMessage();
#endif
#ifdef USE_EXPAT
      }catch(skXMLParseException e){
	cout << e.getErrorMessage()<< " at line "<< e.getLineNum();
#endif
      }catch(skParseException e){
	cout << e.toString();
      }catch(skRuntimeException e){
	cout << e.toString();
      }catch(...){
	cout << "unknown exception";
      }
    }
  }else
#ifdef USE_XML
    cout << ("Syntax: ScriptLoader <xml file>\n");
#endif
#ifdef USE_TREENODE
    cout << ("Syntax: ScriptLoader <treenode file>\n");
#endif
  return 0;
}
