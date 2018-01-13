# $Id: Makefile,v 1.7 2001/03/05 16:00:33 sdw Exp $

CFLAGS = -c 
CPPFLAGS = -c -g -ggdb -Dlinux -fimplicit-templates -I/home/sdw/source/xerces-c-src1_3_0/include -D_REENTRANT -instances=static
CPP = g++ -fpic
CC = gcc
.SUFFIXES: .cpp

.cpp.o:	
	${CPP} ${CPPFLAGS}  $<

.c.o:	
	${CPP} ${CPPFLAGS}  $<

lib_proj=Interpreter

objects = skAlist.o skTreeNodeObject.o skTreeNodeObjectEnumerator.o skHashTable.o skString.o skTreeNode.o  skLang_tab.o skExecutable.o skInterpreter.o skRValue.o skScriptedExecutable.o skTracer.o skXMLElementObject.o skXMLElementObjectEnumerator.o  skXMLExecutable.o skStringTokenizer.o skXMLErrorHandler.o

skInterpreter.a: $(objects)
	ar -r skInterpreter.a  $(objects)
	ranlib skInterpreter.a

skLang_tab.cpp: skLang.y
	byacc -bskLang -d -v skLang.y
	mv skLang.tab.c skLang_tab.cpp
	mv skLang.tab.h skLang_tab.h

clean:
	rm *.o *.a

depend:
	makedepend -I/home/sdw/source/xerces-c-src1_3_0/include *.cpp

# DO NOT DELETE

skAlist.o: skAlist.h skGeneral.h /usr/include/stdlib.h
skAlist.o: /usr/include/features.h /usr/include/sys/cdefs.h
skAlist.o: /usr/include/gnu/stubs.h
skAlist.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skAlist.o: /usr/include/sys/types.h /usr/include/bits/types.h
skAlist.o: /usr/include/time.h /usr/include/endian.h
skAlist.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skAlist.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skAlist.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skAlist.o: /usr/include/assert.h skAlist.inl skBoundsException.h skString.h
skAlist.o: skString.inl /usr/include/string.h
skExecutable.o: skExecutable.h skString.h skGeneral.h /usr/include/stdlib.h
skExecutable.o: /usr/include/features.h /usr/include/sys/cdefs.h
skExecutable.o: /usr/include/gnu/stubs.h
skExecutable.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skExecutable.o: /usr/include/sys/types.h /usr/include/bits/types.h
skExecutable.o: /usr/include/time.h /usr/include/endian.h
skExecutable.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skExecutable.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skExecutable.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skExecutable.o: /usr/include/assert.h skString.inl /usr/include/string.h
skExecutable.o: skRValue.h skRValueArray.h skValist.h skBoundsException.h
skExecutable.o: skTracer.h
skHashTable.o: skHashTable.h skGeneral.h /usr/include/stdlib.h
skHashTable.o: /usr/include/features.h /usr/include/sys/cdefs.h
skHashTable.o: /usr/include/gnu/stubs.h
skHashTable.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skHashTable.o: /usr/include/sys/types.h /usr/include/bits/types.h
skHashTable.o: /usr/include/time.h /usr/include/endian.h
skHashTable.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skHashTable.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skHashTable.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skHashTable.o: /usr/include/assert.h skAlist.h skAlist.inl
skHashTable.o: skBoundsException.h skString.h skString.inl
skHashTable.o: /usr/include/string.h skHashTable.inl
skInterpreter.o: skInterpreter.h skRValue.h skString.h skGeneral.h
skInterpreter.o: /usr/include/stdlib.h /usr/include/features.h
skInterpreter.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skInterpreter.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skInterpreter.o: /usr/include/sys/types.h /usr/include/bits/types.h
skInterpreter.o: /usr/include/time.h /usr/include/endian.h
skInterpreter.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skInterpreter.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skInterpreter.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skInterpreter.o: /usr/include/assert.h skString.inl /usr/include/string.h
skInterpreter.o: skExecutable.h skInterpreterp.h skHashTable.h skAlist.h
skInterpreter.o: skAlist.inl skBoundsException.h skHashTable.inl
skInterpreter.o: skParseNode.h skStringList.h skValist.h /usr/include/ctype.h
skInterpreter.o: skLang_tab.h /usr/include/stdio.h
skInterpreter.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stdarg.h
skInterpreter.o: /usr/include/libio.h /usr/include/_G_config.h
skInterpreter.o: /usr/include/bits/stdio_lim.h skRValueArray.h
skInterpreter.o: skParseException.h skRuntimeException.h skTracer.h
skLang_tab.o: skParseNode.h skStringList.h skString.h skGeneral.h
skLang_tab.o: /usr/include/stdlib.h /usr/include/features.h
skLang_tab.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skLang_tab.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skLang_tab.o: /usr/include/sys/types.h /usr/include/bits/types.h
skLang_tab.o: /usr/include/time.h /usr/include/endian.h
skLang_tab.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skLang_tab.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skLang_tab.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skLang_tab.o: /usr/include/assert.h skString.inl /usr/include/string.h
skLang_tab.o: skValist.h skBoundsException.h skAlist.h skAlist.inl skosfcn.h
skRValue.o: skRValue.h skString.h skGeneral.h /usr/include/stdlib.h
skRValue.o: /usr/include/features.h /usr/include/sys/cdefs.h
skRValue.o: /usr/include/gnu/stubs.h
skRValue.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skRValue.o: /usr/include/sys/types.h /usr/include/bits/types.h
skRValue.o: /usr/include/time.h /usr/include/endian.h
skRValue.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skRValue.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skRValue.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skRValue.o: /usr/include/assert.h skString.inl /usr/include/string.h
skRValue.o: skExecutable.h /usr/include/stdio.h
skRValue.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stdarg.h
skRValue.o: /usr/include/libio.h /usr/include/_G_config.h
skRValue.o: /usr/include/bits/stdio_lim.h
skScriptedExecutable.o: skScriptedExecutable.h skTreeNodeObject.h
skScriptedExecutable.o: skExecutable.h skString.h skGeneral.h
skScriptedExecutable.o: /usr/include/stdlib.h /usr/include/features.h
skScriptedExecutable.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skScriptedExecutable.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skScriptedExecutable.o: /usr/include/sys/types.h /usr/include/bits/types.h
skScriptedExecutable.o: /usr/include/time.h /usr/include/endian.h
skScriptedExecutable.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skScriptedExecutable.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skScriptedExecutable.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skScriptedExecutable.o: /usr/include/assert.h skString.inl
skScriptedExecutable.o: /usr/include/string.h skTreeNode.h
skString.o: /usr/include/string.h /usr/include/features.h
skString.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skString.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skString.o: /usr/include/stdlib.h /usr/include/sys/types.h
skString.o: /usr/include/bits/types.h /usr/include/time.h
skString.o: /usr/include/endian.h /usr/include/bits/endian.h
skString.o: /usr/include/sys/select.h /usr/include/bits/select.h
skString.o: /usr/include/bits/sigset.h /usr/include/sys/sysmacros.h
skString.o: /usr/include/alloca.h /usr/include/stdio.h
skString.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stdarg.h
skString.o: /usr/include/libio.h /usr/include/_G_config.h
skString.o: /usr/include/bits/stdio_lim.h skString.h skGeneral.h
skString.o: /usr/include/assert.h skString.inl
skStringTokenizer.o: skStringTokenizer.h skString.h skGeneral.h
skStringTokenizer.o: /usr/include/stdlib.h /usr/include/features.h
skStringTokenizer.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skStringTokenizer.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skStringTokenizer.o: /usr/include/sys/types.h /usr/include/bits/types.h
skStringTokenizer.o: /usr/include/time.h /usr/include/endian.h
skStringTokenizer.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skStringTokenizer.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skStringTokenizer.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skStringTokenizer.o: /usr/include/assert.h skString.inl /usr/include/string.h
skTracer.o: skTracer.h
skTracer.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stdarg.h
skTracer.o: /usr/include/stdio.h /usr/include/features.h
skTracer.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skTracer.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skTracer.o: /usr/include/bits/types.h /usr/include/libio.h
skTracer.o: /usr/include/_G_config.h /usr/include/bits/stdio_lim.h
skTreeNode.o: /usr/include/string.h /usr/include/features.h
skTreeNode.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skTreeNode.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skTreeNode.o: skTreeNode.h skString.h skGeneral.h /usr/include/stdlib.h
skTreeNode.o: /usr/include/sys/types.h /usr/include/bits/types.h
skTreeNode.o: /usr/include/time.h /usr/include/endian.h
skTreeNode.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skTreeNode.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skTreeNode.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skTreeNode.o: /usr/include/assert.h skString.inl skTreeNodp.h skAlist.h
skTreeNode.o: skAlist.inl skBoundsException.h /usr/include/stdio.h
skTreeNode.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stdarg.h
skTreeNode.o: /usr/include/libio.h /usr/include/_G_config.h
skTreeNode.o: /usr/include/bits/stdio_lim.h /usr/include/ctype.h
skTreeNodeObject.o: skTreeNodeObject.h skExecutable.h skString.h skGeneral.h
skTreeNodeObject.o: /usr/include/stdlib.h /usr/include/features.h
skTreeNodeObject.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skTreeNodeObject.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skTreeNodeObject.o: /usr/include/sys/types.h /usr/include/bits/types.h
skTreeNodeObject.o: /usr/include/time.h /usr/include/endian.h
skTreeNodeObject.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skTreeNodeObject.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skTreeNodeObject.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skTreeNodeObject.o: /usr/include/assert.h skString.inl /usr/include/string.h
skTreeNodeObject.o: skTreeNode.h skRValue.h skInterpreter.h skMethodTable.h
skTreeNodeObject.o: skHashTable.h skAlist.h skAlist.inl skBoundsException.h
skTreeNodeObject.o: skHashTable.inl skParseNode.h skStringList.h skValist.h
skXMLElementObject.o: skStringTokenizer.h skString.h skGeneral.h
skXMLElementObject.o: /usr/include/stdlib.h /usr/include/features.h
skXMLElementObject.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skXMLElementObject.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skXMLElementObject.o: /usr/include/sys/types.h /usr/include/bits/types.h
skXMLElementObject.o: /usr/include/time.h /usr/include/endian.h
skXMLElementObject.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skXMLElementObject.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skXMLElementObject.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skXMLElementObject.o: /usr/include/assert.h skString.inl
skXMLElementObject.o: /usr/include/string.h skXMLElementObject.h
skXMLElementObject.o: skExecutable.h
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Element.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XercesDefs.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/util/AutoSense.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Node.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOMString.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_NodeList.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_CharacterData.hpp
skXMLElementObject.o: skRValue.h skXMLElement.h
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Document.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_DocumentType.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_DOMImplementation.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_DocumentFragment.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Comment.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_CDATASection.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Text.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_ProcessingInstruction.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Attr.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Entity.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_EntityReference.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Notation.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_NodeIterator.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_NodeFilter.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Node.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_TreeWalker.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_XMLDecl.hpp
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Range.hpp
skXMLElementObject.o: skMethodTable.h skHashTable.h skAlist.h skAlist.inl
skXMLElementObject.o: skBoundsException.h skHashTable.inl skParseNode.h
skXMLElementObject.o: skStringList.h skValist.h skInterpreter.h
skXMLElementObject.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_NamedNodeMap.hpp
skXMLErrorHandler.o: skXMLErrorHandler.h
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/sax/ErrorHandler.hpp
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XercesDefs.hpp
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/util/AutoSense.hpp
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOMString.hpp
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/sax/SAXParseException.hpp
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/sax/SAXException.hpp
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLString.hpp
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLUni.hpp
skXMLErrorHandler.o: skXMLElementObject.h skExecutable.h skString.h
skXMLErrorHandler.o: skGeneral.h /usr/include/stdlib.h
skXMLErrorHandler.o: /usr/include/features.h /usr/include/sys/cdefs.h
skXMLErrorHandler.o: /usr/include/gnu/stubs.h
skXMLErrorHandler.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skXMLErrorHandler.o: /usr/include/sys/types.h /usr/include/bits/types.h
skXMLErrorHandler.o: /usr/include/time.h /usr/include/endian.h
skXMLErrorHandler.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skXMLErrorHandler.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skXMLErrorHandler.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skXMLErrorHandler.o: /usr/include/assert.h skString.inl /usr/include/string.h
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Element.hpp
skXMLErrorHandler.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Node.hpp
skXMLExecutable.o: skXMLErrorHandler.h
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/sax/ErrorHandler.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XercesDefs.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/AutoSense.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/parsers/DOMParser.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Document.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_DocumentType.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Node.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOMString.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_DOMImplementation.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Element.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_DocumentFragment.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Comment.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_CharacterData.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_CDATASection.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Text.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_ProcessingInstruction.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Attr.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Entity.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_EntityReference.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_NodeList.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Notation.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_NodeIterator.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_NodeFilter.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Node.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_TreeWalker.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_XMLDecl.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Range.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLDocumentHandler.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/RefVectorOf.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/ArrayIndexOutOfBoundsException.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLException.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLExceptMsgs.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLUni.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLEnumerator.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/RefVectorOf.c
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLAttr.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLString.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLAttDef.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLErrorReporter.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLMsgLoader.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLEntityHandler.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/ValueStackOf.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/EmptyStackException.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/ValueVectorOf.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/ValueVectorOf.c
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/ValueStackOf.c
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/validators/DTD/DocTypeHandler.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLNotationDecl.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/validators/DTD/DTDAttDef.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/validators/DTD/DTDElementDecl.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/RefHashTableOf.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/KeyValuePair.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/KeyValuePair.c
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/HashBase.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/IllegalArgumentException.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/NoSuchElementException.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/RuntimeException.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/HashXMLCh.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/RefHashTableOf.c
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLElementDecl.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLAttDefList.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLContentModel.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/validators/DTD/DTDEntityDecl.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLEntityDecl.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/validators/DTD/DTDValidator.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/NameIdPool.hpp
skXMLExecutable.o: /usr/include/string.h /usr/include/features.h
skXMLExecutable.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
skXMLExecutable.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/NameIdPool.c
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/util/StringPool.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLValidator.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLValidityCodes.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/XMLRefInfo.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/LocalFileInputSource.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/sax/InputSource.hpp
skXMLExecutable.o: /home/sdw/source/xerces-c-src1_3_0/include/framework/MemBufInputSource.hpp
skXMLExecutable.o: skXMLExecutable.h skXMLElementObject.h skExecutable.h
skXMLExecutable.o: skString.h skGeneral.h /usr/include/stdlib.h
skXMLExecutable.o: /usr/include/sys/types.h /usr/include/bits/types.h
skXMLExecutable.o: /usr/include/time.h /usr/include/endian.h
skXMLExecutable.o: /usr/include/bits/endian.h /usr/include/sys/select.h
skXMLExecutable.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
skXMLExecutable.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
skXMLExecutable.o: /usr/include/assert.h skString.inl
