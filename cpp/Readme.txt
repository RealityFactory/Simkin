Simkin for C++
(c)2000-2001 Simon Whiteside

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



