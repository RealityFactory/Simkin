Simkin for C++
(c)1996-2004 Simon Whiteside

Simkin version 2.23
-------------------
Date: 17/12/2004

* allowed for compound statements to contain no statements at all, allowing for blank methods
* added a "break" statement for loops

Simkin version 2.22
Date: 18/11/2004
-------------------
* fix to bug in TreeNode lexer "\\" would be interpreted as "\" by the parser. (thanks to Henry Kropf!)
* fix to char-to-float and char-to-int conversions in skRValue.cpp (thanks to James Larcombe!)

Simkin version 2.21
Date: 20/11/2003
-------------------
* added support for "return" statement with no return expression
* added support for compiling with Visual Studio .NET
* added type coercion functions and documentation on built-in functions

Simkin Version 2.20
Date: 27/5/2003
-------------------

* fixed a bug where the skExpatParser would double-delete the elements in the case of an XML syntax error. Bug was introduced in Simkin version 2.18
* added removeElement script method to skElementObject
* added reset() method to skStringBuffer
* fixed nasty bug in skString::operator+ if the current string is blank, the add returns a blank whatever is being added to it
* added another "getAttribute" function to skElement - which returns a default value if an attribute is not present
* fixed bug stopping multiple line comments from working (thanks to "Cool" on the discussion board!!)

Simkin Version 2.19
Date: 19/4/2003
-------------------

* added some extra functions to skAttributeList
* fixed some bugs in the new byte code representation
* ported Simkin DOM classes to Symbian, along with the Expat parser

Simkin Version 2.18
Date: 14/4/2003
-------------------

* brought identifiers in line with Java version - $ and @ can now be embedded within an identifier name
* added some static methods to efficiently add strings to skString
* added some virtual destructors to the DOM classes. Many thanks IvanK
* added function c_str() to skString() to be similar to stdlib
* improved keyword search - now use a perfect hash version
* made various changes to support a Symbian version, including some new Symbian examples
* optimization of core classes to make them smaller
* added compressed representation of parse tree. This is smaller, but slightly slower than the current version. The two implementations can be
  selected via a #ifdef EXECUTE_PARSENODES in skGeneral.h. The compressed representation is stored in a skCompiledCode object.
* added a #ifdef to include/exclude floating point support. This is called USE_FLOATING_POINT and is defined in skGeneral.h
* introduced new hashtable class, skSHashTable, which maps skString values to templated pointers
* made equality operator do value-based comparisons for TreeNode and XMLElements.
* modified setNode function in skTreeNodeObject to specify location and created parameters
* added some documentation on preprocessor directives which control the build

Simkin Version 2.17
Date: 19/3/2003
-------------------

* fixed bug in quoting "\" "[" "]" in TreeNode writing
* added getAttributes function to skiExecutable - to help debugger support
  added this function to the XML base classes
* removed P_Interpeter class - put private functionality back into skInterpreter
* removed P_TreeNodeReader class - put private functionality back into skTreeNodeReader
* skTreeNodeObject now parses the parameters to methods rather than relying on the Simkin parser to do it - this improves line number mapping for TreeNode scripts when viewed in the debugger
* added a new example, showing how Simkin can be used with CGI
* fixed bug in skInputString::eof - was returning the wrong value

Simkin Version 2.16
Date: 24/2/2003
-------------------

* fixed bugs in parsing unicode TreeNode files containing errors (on Windows CE)
* fixed bugs in file handling for Windows CE (in skInputFile)
* added "AddIfNotPresent" flag to skTreeNodeObject for dynamically adding fields if they are not already present
* fixed some bugs in "AddIfNotPresent" support in base classes
* updated Linux makefiles
* added more data type conversion information to the documentation (including values of "true") - see the page entitled "Simkin Script Syntax"/"Data Types"
* added a new example called DynamicTreeNode showing how new fields can be added to a TreeNode object by scripts. This can be used to store dynamic data in arbitrary structures.
* added an overview of the classes in the Simkin library to the documentation
* moved to MSXML2 namespace for Microsoft XML classes

Simkin Version 2.15
Date: 23/1/2003
-------------------

* renamed skContext to skStackFrame and modified the usage for use in debugging
* showed IM in Windows CE demo
* added skInputSource to manage reading skTreeNode's and Expat XML documents from different data sources such as sockets
* added some functions to skiExecutable to aid debugging
* added evaluateExpression functionality to the Interpreter
* added support for Microsoft XML parser (thanks Marlin!) (look for classes called skMSXML... )
* Windows CE InputFile classes can now translate from ANSI documents to Unicode on the fly.

Simkin Version 2.14
Date: 14/12/2002
-------------------

* fixed bug in skStringBuffer::append(char) (thanks Gabriel Bouvigne)
* fixed bug in skTreeNodeObject when the node is changed, the method cache is invalid (thanks Enzo Petrelli)
* fixes to bugs in Expat XML DOM. 
* fixes to memory leaks in Expat parser (thanks Rich Goldstein)
* fixed missing <= >= operators for floats (thanks Dave Zarlengo)
* added new class skScriptError to propagate exceptions when C++ exceptions are not available (such as in Windows CE)
* added skExecutableContext parameter to calls in skiExecutable - this is to remove the need for a global interpreter object and to allow for compilers where C++ exceptions are not available
* removed the global interpreter objects from skInterpreter
* further unicode changes to support Windows CE
* updated to work with Xerces 2.1.0 (with deprecated DOM) and Expat 1.95.5

Simkin Version 2.13
Date: 13/2/2002
-------------------

* fixed bug in skElementObject where it would crash if load() hadn't been called
* fixed memory leak of a parse tree if executeString() caused a runtime exception
* fixed precedence problems with the "!=" operator
* fixed crash if trace() called with no arguments

Simkin Version 2.12
Date: 18/1/2002
-------------------

* added ltrim() method to skString
* some improvements in method placement within skRValue and skString (thanks Rich Goldstein!)
* improvements in skString and skParser memory allocation (thanks Pavel Savara!)
* fixed some precendence and associativity bugs in the parser (thanks Pavel!)
* fixed memory leak in parsing of array indices (thanks Pavel!)

Simkin Version 2.11
Date: 21/11/2001
-------------------

* added skStringBuffer class to give a more efficient "growable" string
* added skContext class to improve re-entrancy of interpreter
* integrated latest version of Xerces: 1.5.2
* added better support for streaming out XML documents from skXMLExecutable
* added new classes to support Expat XML parser: skElementObject, skElementExecutable etc..
* strings now use const Char * rather than const unsigned char *. Char is typedefed to char or w_char depending on whether unicode is used
* removed copy constructor and assignment operator from skTAList - causes problems for classes which don't want to be copied that way
* part-way through a Windows CE port - so support for unicode under CE is there 
* added Windows declarations so that Simkin can be put into a DLL
* added a new abstract base class called skiExecutable so that people can use COMish objects with Simkin
* fix to bug in skXMLElementObject::copyItems into (thanks to Rich Goldstein, MD <rich@wima-nj.com>!)
* fix to bug in skXMLElementObjectEnumerator and skTreeNodeObjectEnumerator (thanks to Rich Goldstein, MD <rich@wima-nj.com>!)

Simkin Version 2.10
Date: 5/7/2001
-------------------

* removed local variable cache - could cause problems if exceptions are thrown
* added skTraceCallback to capture all tracing output
* added skStatementStepper to be called for each statement executed
* added new operators "less than or equal", le and '<=' and "more than or equal", ge and '>='
* added a new "for" statement, e.g. "for x=1 to 10 step 5"

Simkin Version 2.09
Date: 22nd June 2001
-------------------

* added "label" field to TreeNodes
* minor change in assignment code e.g. field:attribute=value;
* added "for each in " statement. This is supported in the skTreeNodeObject and skXMLElementObject classes.
* inlined skRValue methods
* reinstated ">" and "<" as symbols for greater than and less than. These cannot be used in XML files, but can be in other sources, also "&" can be used in place of "#"
* introduced typedef'ed Char type, to allow for unicode builds
* added line numbers to RuntimeExceptions

Simkin Version 2.08
Date: 1st June 2001
-------------------

* bug fix in array index operator for cases a=foo[0] and foo[0]=a
* bug fix in methods plus attributes, foo():attr will now behave correctly
* bug fix in skXMLElementObject - nodes from other documents are now *imported* rather than *cloned*
* added AddIfNotPresent feature to skXMLElementObject: this means that elements that are references but do not exist can be added on the fly (by default the feature is disabled)

Simkin Version 2.07
Date: 22nd May 2001
-------------------

* added a new example called Inherits, which shows how you can support inheritance within Simkin scripts
* made the interpreter re-entrant by using the pure_parser option in bison - added a new class called skParser to help with this
* on Windows, one interpreter is now created per thread (Any advice on non-Windows equivalents??)
  (many thanks to Rich Goldstein, MD <rich@wima-nj.com> for help on this)

Simkin Version 2.06
Date: 14th May 2001
-------------------

* bug fix in skXMLElementObject - now adds a text node to an element if there isn't already one
* bug fix in Interpreter - wasn't coping with "field:attribute=value" properly

Simkin Version 2.05
-------------------

* added various functions to skXMLElementObject for adding elements
* fixed bug where compile errors might be reported for the wrong method

Simkin Version 2.04
Date: 8th May 2001
--------------------

* added support for the array index operator. This works by calling into two new functions in the skExecutable class: setValueAt and getValueAt

* The skXMLElementObject and skTreeNodeObject both support the new array index operator, so you can step through XML or TreeNode children using code like:

while (i lt count){
      value=variable[i];
}

* skXMLElementObject and skTreeNodeObject also support a field called "numChildren" which returns the number of children of a given node or element

* slight modifications of the Linux makefiles to accomodate the latest versions of Xerces and g++

Simkin Version 2.03
Date: 5th March 2001
--------------------


* added support for a "null" object
* added new enumerate() method to enumerate over XML and TreeNode elements, 
  please see new Enumerate example and classes skXMLElementObjectEnumerator 
  and skTreeNodeObjectEnumerator
* expression syntax is more flexible - you can now write a=b.c().d(), or
  b.c().d=e;
* a new "!=" (not equal to) operator has been added

Bugs fixed:

* fixed some errors where attributes could not be accessed

Simkin Version 2.02
Date: 25th January 2001
-----------------------

Features:

i) Added new switch statement

Bug fixes:

i) m_MethodCache not zeroed after delete in skXMLElementObject:setElement
 (spotted by Pratip Mukherjee <pratip.mukherjee@fmr.com>)

Simkin Version 2.01

Date: 3rd January 2001
-----------------------

Some work to bring this version into line with Java version 1.1

i) new character type has been added - specified by ' in Simkin
ii) charAt in skExecutable now returns a char object
iii) skRValue now supports char and bool values
iv) skExecutable now has a boolValue() method
v) try..catch statements have been added to the ScriptLoader example

Bug fixes:

i) wrong code in equality operator handling in the skIntepreter
ii) missing break statements in the operator== of skRValue

Simkin Version 2
Date: 21st December 2000
------------------------

There's been an extensive re-write to bring this in line with the Java version:

i) new syntax added to support lists of id's, as in a.b.c.d=4;
ii) new syntax added to support attributes: a:b
iii) now use skParseNode hierachy to store the parsetree, rather than skTreeNode objects
iv) now throw Exceptions when encountering parse or runtime errors
v)  support 2 syntaxes for method declaration, "normal" and "external". External was added to support XML where
the parameters are declared within an attribute, and there are no enclosing braces around the statements
vi) added the skXML... classes so that Simkin can be embedded within XML
vii) changed some of the operators which clash with XML syntax, "<" has become "lt", ">" has become "gt" and "&" has become "#"
viii) method names have been re-spelt in the Java style
ix) JavaDoc-style comments have been added to the header files
x) floating point numbers have been added
xi) Examples are now found beneath the Src directory.

Last, but not least, Simkin for C++ has become Open Source!!


Simkin Version 1
Date: 1st January 2000
---------------------------------------

Welcome to version 1 of Simkin

Directory Structure:

Demo		-	code for the demo
Doc		-	html documentation
Examples	-	examples
Src		-	C++ source code for language interpreter

This release includes some makefiles. You make need to modify them to suit your requirements.

These build the Mac and Windows demonstrations:

Demo/Demo.mak  -	 MSVC version 4 make file for Windows
Demo/Demo.mcp  -	 Code Warrior version 4 project file for PPC/68k Mac

These build static libraries:

Src/Makefile   -	 gnu c++ makefile for Linux
Src/Simkin.mak -	 MSVC version 4 make file for Windows
Src/Simkin.mcp  -	 Code Warrior version 4 project file for PPC/68k Mac


Simkin Beta Release 2

Date: 14th October 1999

---------------------------------------

Welcome to this beta release.

This release contains some fixes to the documentation and two extra pages:

Simkin_Quoting.html - about quoting special characters in Simkin files
Simkin_Names.html - about rules for method and field naming.

There have also been a couple of code changes:

a bug was fixed where return'ing a value from within a while statement didn't work correctly

method and field names can now also contain the ':' character


Simkin Beta Release 1

Date: 14th September 1999

---------------------------------------

Welcome to this beta release.

This beta contains the following directories:

Demo		-	code for the demo
Doc		-	html documentation
Examples	-	examples
Src		-	C++ source code for language interpreter

Note: this release does *not* contain any make files. 
Please create them appropriately for your platform and compiler.

I usually build Simkin into a separate library and link it 
into the final application.



