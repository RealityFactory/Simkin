# $Id: Makefile,v 1.8 2001/05/03 16:01:30 sdw Exp $

CFLAGS = -c 
CPPFLAGS = -c -g -ggdb -Dlinux -fimplicit-templates -I/usr/share/xerces-c-src1_4_0/src -D_REENTRANT 
#-instances=static
CPP = g++ -fpic
CC = gcc
.SUFFIXES: .cpp

.cpp.o:	
	${CPP} ${CPPFLAGS}  $<

.c.o:	
	${CPP} ${CPPFLAGS}  $<

lib_proj=Interpreter

objects = skAlist.o skTreeNodeObject.o skTreeNodeObjectEnumerator.o skHashTable.o skString.o skTreeNode.o  skLang_tab.o skExecutable.o skInterpreter.o skRValue.o skScriptedExecutable.o skTracer.o skXMLElementObject.o skXMLElementObjectEnumerator.o  skXMLExecutable.o skStringTokenizer.o skXMLErrorHandler.o

skInterpreter.a: skLang_tab.cpp $(objects) 
	ar -r skInterpreter.a  $(objects)
	ranlib skInterpreter.a

skLang_tab.cpp: skLang.y
	byacc -bskLang -d -v skLang.y
	mv skLang.tab.c skLang_tab.cpp
	mv skLang.tab.h skLang_tab.h

clean:
	rm *.o *.a

depend:
	makedepend -I/usr/share/xerces-c-src1_4_0/src *.cpp

# DO NOT DELETE


skAlist.c.o: skAlist.h skAlist.inl skBoundsException.h skGeneral.h skString.h
skAlist.c.o: skString.inl /usr/include/alloca.h /usr/include/assert.h
skAlist.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skAlist.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skAlist.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skAlist.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skAlist.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skAlist.c.o: /usr/include/gconv.h /usr/include/libio.h /usr/include/stdlib.h
skAlist.c.o: /usr/include/string.h /usr/include/sys/select.h
skAlist.c.o: /usr/include/sys/types.h /usr/include/time.h /usr/include/wchar.h
skAlist.c.o: /usr/include/xlocale.h
skAlist.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skAlist.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skExecutable.c.o: skBoundsException.h skExecutable.h skGeneral.h
skExecutable.c.o: skRValueArray.h skRValue.h skString.h skString.inl
skExecutable.c.o: skTracer.h skValist.h /usr/include/alloca.h
skExecutable.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skExecutable.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skExecutable.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skExecutable.c.o: /usr/include/endian.h /usr/include/features.h
skExecutable.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/streambuf.h
skExecutable.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skExecutable.c.o: /usr/include/libio.h /usr/include/stdlib.h
skExecutable.c.o: /usr/include/string.h /usr/include/sys/select.h
skExecutable.c.o: /usr/include/sys/types.h /usr/include/time.h
skExecutable.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skHashTable.c.o: skAlist.h skAlist.inl skBoundsException.h skGeneral.h
skHashTable.c.o: skHashTable.h skHashTable.inl skString.h skString.inl
skHashTable.c.o: /usr/include/alloca.h /usr/include/assert.h
skHashTable.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skHashTable.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skHashTable.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skHashTable.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skHashTable.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skHashTable.c.o: /usr/include/gconv.h /usr/include/libio.h
skHashTable.c.o: /usr/include/stdlib.h /usr/include/string.h
skHashTable.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skHashTable.c.o: /usr/include/time.h /usr/include/wchar.h
skHashTable.c.o: /usr/include/xlocale.h
skHashTable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skHashTable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skInterpreter.c.o: skAlist.h skAlist.inl skBoundsException.h skExecutable.h
skInterpreter.c.o: skGeneral.h skHashTable.h skHashTable.inl skInterpreter.h
skInterpreter.c.o: skInterpreterp.h skLang_tab.h skNull.h skParseException.h
skInterpreter.c.o: skParseNode.h skRuntimeException.h skRValueArray.h
skInterpreter.c.o: skRValue.h skString.h skString.inl skStringList.h
skInterpreter.c.o: skTracer.h skValist.h /usr/include/alloca.h
skInterpreter.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skInterpreter.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skInterpreter.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skInterpreter.c.o: /usr/include/ctype.h /usr/include/endian.h
skInterpreter.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skInterpreter.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skInterpreter.c.o: /usr/include/gconv.h /usr/include/libio.h
skInterpreter.c.o: /usr/include/stdio.h /usr/include/stdlib.h
skInterpreter.c.o: /usr/include/string.h /usr/include/sys/select.h
skInterpreter.c.o: /usr/include/sys/types.h /usr/include/time.h
skInterpreter.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skInterpreter.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skInterpreter.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skLang_tab.c.o: skAlist.h skAlist.inl skBoundsException.h skGeneral.h
skLang_tab.c.o:  skLang.y skosfcn.h skParseNode.h skString.h
skLang_tab.c.o: skString.inl skStringList.h skValist.h /usr/include/alloca.h
skLang_tab.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skLang_tab.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skLang_tab.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skLang_tab.c.o: /usr/include/endian.h /usr/include/features.h
skLang_tab.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/streambuf.h
skLang_tab.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skLang_tab.c.o: /usr/include/libio.h /usr/include/stdlib.h
skLang_tab.c.o: /usr/include/string.h /usr/include/sys/select.h
skLang_tab.c.o: /usr/include/sys/types.h /usr/include/time.h
skLang_tab.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skLang_tab.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skLang_tab.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skRValue.c.o: skExecutable.h skGeneral.h skRValue.h skString.h skString.inl
skRValue.c.o: /usr/include/alloca.h /usr/include/assert.h
skRValue.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skRValue.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skRValue.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skRValue.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skRValue.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skRValue.c.o: /usr/include/gconv.h /usr/include/libio.h /usr/include/stdio.h
skRValue.c.o: /usr/include/stdlib.h /usr/include/string.h
skRValue.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skRValue.c.o: /usr/include/time.h /usr/include/wchar.h /usr/include/xlocale.h
skRValue.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skRValue.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skScriptedExecutable.c.o: skExecutable.h skGeneral.h skScriptedExecutable.h
skScriptedExecutable.c.o: skString.h skString.inl skTreeNode.h
skScriptedExecutable.c.o: skTreeNodeObject.h /usr/include/alloca.h
skScriptedExecutable.c.o: /usr/include/assert.h
skScriptedExecutable.c.o: /usr/include/bits/pthreadtypes.h
skScriptedExecutable.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skScriptedExecutable.c.o: /usr/include/bits/types.h
skScriptedExecutable.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skScriptedExecutable.c.o: /usr/include/features.h
skScriptedExecutable.c.o: /usr/include/g++-3/iostream.h
skScriptedExecutable.c.o: /usr/include/g++-3/streambuf.h
skScriptedExecutable.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skScriptedExecutable.c.o: /usr/include/libio.h /usr/include/stdlib.h
skScriptedExecutable.c.o: /usr/include/string.h /usr/include/sys/select.h
skScriptedExecutable.c.o: /usr/include/sys/types.h /usr/include/time.h
skScriptedExecutable.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skScriptedExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skScriptedExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skString.c.o: skGeneral.h skString.h skString.inl /usr/include/alloca.h
skString.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skString.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skString.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skString.c.o: /usr/include/endian.h /usr/include/features.h
skString.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/streambuf.h
skString.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skString.c.o: /usr/include/libio.h /usr/include/stdio.h /usr/include/stdlib.h
skString.c.o: /usr/include/string.h /usr/include/sys/select.h
skString.c.o: /usr/include/sys/types.h /usr/include/time.h
skString.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skString.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skString.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skStringTokenizer.c.o: skGeneral.h skString.h skString.inl skStringTokenizer.h
skStringTokenizer.c.o: /usr/include/alloca.h /usr/include/assert.h
skStringTokenizer.c.o: /usr/include/bits/pthreadtypes.h
skStringTokenizer.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skStringTokenizer.c.o: /usr/include/bits/types.h
skStringTokenizer.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skStringTokenizer.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skStringTokenizer.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skStringTokenizer.c.o: /usr/include/gconv.h /usr/include/libio.h
skStringTokenizer.c.o: /usr/include/stdlib.h /usr/include/string.h
skStringTokenizer.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skStringTokenizer.c.o: /usr/include/time.h /usr/include/wchar.h
skStringTokenizer.c.o: /usr/include/xlocale.h
skStringTokenizer.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skStringTokenizer.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skTracer.c.o: skTracer.h /usr/include/bits/pthreadtypes.h
skTracer.c.o: /usr/include/bits/sched.h /usr/include/bits/types.h
skTracer.c.o: /usr/include/features.h /usr/include/_G_config.h
skTracer.c.o: /usr/include/gconv.h /usr/include/libio.h /usr/include/stdio.h
skTracer.c.o: /usr/include/wchar.h
skTracer.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skTracer.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skTreeNode.c.o: skAlist.h skAlist.inl skBoundsException.h skGeneral.h
skTreeNode.c.o: skString.h skString.inl skTreeNode.h skTreeNodp.h
skTreeNode.c.o: /usr/include/alloca.h /usr/include/assert.h
skTreeNode.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skTreeNode.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skTreeNode.c.o: /usr/include/bits/waitstatus.h /usr/include/ctype.h
skTreeNode.c.o: /usr/include/endian.h /usr/include/features.h
skTreeNode.c.o: /usr/include/g++-3/fstream.h /usr/include/g++-3/iostream.h
skTreeNode.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skTreeNode.c.o: /usr/include/gconv.h /usr/include/libio.h /usr/include/stdio.h
skTreeNode.c.o: /usr/include/stdlib.h /usr/include/string.h
skTreeNode.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skTreeNode.c.o: /usr/include/time.h /usr/include/wchar.h
skTreeNode.c.o: /usr/include/xlocale.h
skTreeNode.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skTreeNode.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skTreeNodeEnumerator.c.o: skExecutable.h skGeneral.h skString.h skString.inl
skTreeNodeEnumerator.c.o: skTreeNode.h skTreeNodeObjectEnumerator.h
skTreeNodeEnumerator.c.o: /usr/include/alloca.h /usr/include/assert.h
skTreeNodeEnumerator.c.o: /usr/include/bits/pthreadtypes.h
skTreeNodeEnumerator.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skTreeNodeEnumerator.c.o: /usr/include/bits/types.h
skTreeNodeEnumerator.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skTreeNodeEnumerator.c.o: /usr/include/features.h
skTreeNodeEnumerator.c.o: /usr/include/g++-3/iostream.h
skTreeNodeEnumerator.c.o: /usr/include/g++-3/streambuf.h
skTreeNodeEnumerator.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skTreeNodeEnumerator.c.o: /usr/include/libio.h /usr/include/stdlib.h
skTreeNodeEnumerator.c.o: /usr/include/string.h /usr/include/sys/select.h
skTreeNodeEnumerator.c.o: /usr/include/sys/types.h /usr/include/time.h
skTreeNodeEnumerator.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skTreeNodeEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skTreeNodeEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skTreeNodeObject.c.o: skAlist.h skAlist.inl skBoundsException.h skExecutable.h
skTreeNodeObject.c.o: skGeneral.h skHashTable.h skHashTable.inl
skTreeNodeObject.c.o: skInterpreter.h skMethodTable.h skNull.h skParseNode.h
skTreeNodeObject.c.o: skRValueArray.h skRValue.h skString.h skString.inl
skTreeNodeObject.c.o: skStringList.h skTreeNode.h skTreeNodeObjectEnumerator.h
skTreeNodeObject.c.o: skTreeNodeObject.h skValist.h /usr/include/alloca.h
skTreeNodeObject.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skTreeNodeObject.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skTreeNodeObject.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skTreeNodeObject.c.o: /usr/include/endian.h /usr/include/features.h
skTreeNodeObject.c.o: /usr/include/g++-3/iostream.h
skTreeNodeObject.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skTreeNodeObject.c.o: /usr/include/gconv.h /usr/include/libio.h
skTreeNodeObject.c.o: /usr/include/stdlib.h /usr/include/string.h
skTreeNodeObject.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skTreeNodeObject.c.o: /usr/include/time.h /usr/include/wchar.h
skTreeNodeObject.c.o: /usr/include/xlocale.h
skTreeNodeObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skTreeNodeObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skTreeNodeObjectEnumerator.c.o: skExecutable.h skGeneral.h skInterpreter.h
skTreeNodeObjectEnumerator.c.o: skNull.h skRValue.h skString.h skString.inl
skTreeNodeObjectEnumerator.c.o: skTreeNode.h skTreeNodeObjectEnumerator.h
skTreeNodeObjectEnumerator.c.o: skTreeNodeObject.h /usr/include/alloca.h
skTreeNodeObjectEnumerator.c.o: /usr/include/assert.h
skTreeNodeObjectEnumerator.c.o: /usr/include/bits/pthreadtypes.h
skTreeNodeObjectEnumerator.c.o: /usr/include/bits/sched.h
skTreeNodeObjectEnumerator.c.o: /usr/include/bits/sigset.h
skTreeNodeObjectEnumerator.c.o: /usr/include/bits/types.h
skTreeNodeObjectEnumerator.c.o: /usr/include/bits/waitstatus.h
skTreeNodeObjectEnumerator.c.o: /usr/include/endian.h /usr/include/features.h
skTreeNodeObjectEnumerator.c.o: /usr/include/g++-3/iostream.h
skTreeNodeObjectEnumerator.c.o: /usr/include/g++-3/streambuf.h
skTreeNodeObjectEnumerator.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skTreeNodeObjectEnumerator.c.o: /usr/include/libio.h /usr/include/stdlib.h
skTreeNodeObjectEnumerator.c.o: /usr/include/string.h
skTreeNodeObjectEnumerator.c.o: /usr/include/sys/select.h
skTreeNodeObjectEnumerator.c.o: /usr/include/sys/types.h /usr/include/time.h
skTreeNodeObjectEnumerator.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skTreeNodeObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skTreeNodeObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skXMLElementObject.c.o: skAlist.h skAlist.inl skBoundsException.h
skXMLElementObject.c.o: skExecutable.h skGeneral.h skHashTable.h
skXMLElementObject.c.o: skHashTable.inl skInterpreter.h skMethodTable.h
skXMLElementObject.c.o: skNull.h skParseNode.h skRValueArray.h skRValue.h
skXMLElementObject.c.o: skString.h skString.inl skStringList.h
skXMLElementObject.c.o: skStringTokenizer.h skValist.h skXMLElement.h
skXMLElementObject.c.o: skXMLElementObjectEnumerator.h skXMLElementObject.h
skXMLElementObject.c.o: /usr/include/alloca.h /usr/include/assert.h
skXMLElementObject.c.o: /usr/include/bits/pthreadtypes.h
skXMLElementObject.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skXMLElementObject.c.o: /usr/include/bits/types.h
skXMLElementObject.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skXMLElementObject.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skXMLElementObject.c.o: /usr/include/g++-3/streambuf.h
skXMLElementObject.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skXMLElementObject.c.o: /usr/include/libio.h /usr/include/stdlib.h
skXMLElementObject.c.o: /usr/include/string.h /usr/include/sys/select.h
skXMLElementObject.c.o: /usr/include/sys/types.h /usr/include/time.h
skXMLElementObject.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skXMLElementObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skXMLElementObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Attr.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_CDATASection.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_CharacterData.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Comment.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_DocumentFragment.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Document.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_DocumentType.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_DOMImplementation.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Element.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Entity.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_EntityReference.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_NamedNodeMap.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_NodeFilter.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Node.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_NodeIterator.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_NodeList.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Notation.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_ProcessingInstruction.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Range.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOMString.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Text.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_TreeWalker.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_XMLDecl.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/util/Compilers/GCCDefs.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/util/Platforms/Linux/LinuxDefs.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_4_0/src/util/XercesDefs.hpp
skXMLElementObjectEnumerator.c.o: skExecutable.h skGeneral.h skInterpreter.h
skXMLElementObjectEnumerator.c.o: skNull.h skRValue.h skString.h skString.inl
skXMLElementObjectEnumerator.c.o: skXMLElementObjectEnumerator.h
skXMLElementObjectEnumerator.c.o: skXMLElementObject.h /usr/include/alloca.h
skXMLElementObjectEnumerator.c.o: /usr/include/assert.h
skXMLElementObjectEnumerator.c.o: /usr/include/bits/pthreadtypes.h
skXMLElementObjectEnumerator.c.o: /usr/include/bits/sched.h
skXMLElementObjectEnumerator.c.o: /usr/include/bits/sigset.h
skXMLElementObjectEnumerator.c.o: /usr/include/bits/types.h
skXMLElementObjectEnumerator.c.o: /usr/include/bits/waitstatus.h
skXMLElementObjectEnumerator.c.o: /usr/include/endian.h
skXMLElementObjectEnumerator.c.o: /usr/include/features.h
skXMLElementObjectEnumerator.c.o: /usr/include/g++-3/iostream.h
skXMLElementObjectEnumerator.c.o: /usr/include/g++-3/streambuf.h
skXMLElementObjectEnumerator.c.o: /usr/include/_G_config.h
skXMLElementObjectEnumerator.c.o: /usr/include/gconv.h /usr/include/libio.h
skXMLElementObjectEnumerator.c.o: /usr/include/stdlib.h /usr/include/string.h
skXMLElementObjectEnumerator.c.o: /usr/include/sys/select.h
skXMLElementObjectEnumerator.c.o: /usr/include/sys/types.h /usr/include/time.h
skXMLElementObjectEnumerator.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skXMLElementObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skXMLElementObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Element.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Node.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_NodeList.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOMString.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_4_0/src/util/Compilers/GCCDefs.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_4_0/src/util/Platforms/Linux/LinuxDefs.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_4_0/src/util/XercesDefs.hpp
skXMLErrorHandler.c.o: skExecutable.h skGeneral.h skString.h skString.inl
skXMLErrorHandler.c.o: skXMLElementObject.h skXMLErrorHandler.h
skXMLErrorHandler.c.o: /usr/include/alloca.h /usr/include/assert.h
skXMLErrorHandler.c.o: /usr/include/bits/pthreadtypes.h
skXMLErrorHandler.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skXMLErrorHandler.c.o: /usr/include/bits/types.h
skXMLErrorHandler.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skXMLErrorHandler.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skXMLErrorHandler.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skXMLErrorHandler.c.o: /usr/include/gconv.h /usr/include/libio.h
skXMLErrorHandler.c.o: /usr/include/stdlib.h /usr/include/string.h
skXMLErrorHandler.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skXMLErrorHandler.c.o: /usr/include/time.h /usr/include/wchar.h
skXMLErrorHandler.c.o: /usr/include/xlocale.h
skXMLErrorHandler.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skXMLErrorHandler.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Element.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Node.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOMString.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/sax/ErrorHandler.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/sax/SAXException.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/sax/SAXParseException.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/util/Compilers/GCCDefs.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/util/Platforms/Linux/LinuxDefs.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/util/XercesDefs.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLString.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLUni.hpp
skXMLExecutable.c.o: skExecutable.h skGeneral.h skString.h skString.inl
skXMLExecutable.c.o: skXMLElementObject.h skXMLErrorHandler.h
skXMLExecutable.c.o: skXMLExecutable.h /usr/include/alloca.h
skXMLExecutable.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skXMLExecutable.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skXMLExecutable.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skXMLExecutable.c.o: /usr/include/endian.h /usr/include/features.h
skXMLExecutable.c.o: /usr/include/g++-3/fstream.h
skXMLExecutable.c.o: /usr/include/g++-3/iostream.h
skXMLExecutable.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skXMLExecutable.c.o: /usr/include/gconv.h /usr/include/libio.h
skXMLExecutable.c.o: /usr/include/stdlib.h /usr/include/string.h
skXMLExecutable.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skXMLExecutable.c.o: /usr/include/time.h /usr/include/wchar.h
skXMLExecutable.c.o: /usr/include/xlocale.h
skXMLExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skXMLExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Attr.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_CDATASection.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_CharacterData.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Comment.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_DocumentFragment.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Document.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_DocumentType.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_DOMImplementation.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Element.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Entity.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_EntityReference.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_NodeFilter.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Node.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_NodeIterator.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_NodeList.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Notation.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_ProcessingInstruction.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Range.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOMString.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Text.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_TreeWalker.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_XMLDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/LocalFileInputSource.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/MemBufInputSource.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLAttDef.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLAttDefList.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLAttr.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLContentModel.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLDocumentHandler.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLElementDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLEntityDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLEntityHandler.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLErrorReporter.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLNotationDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLRefInfo.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLValidator.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/framework/XMLValidityCodes.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/parsers/DOMParser.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/sax/ErrorHandler.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/sax/InputSource.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/ArrayIndexOutOfBoundsException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/Compilers/GCCDefs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/EmptyStackException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/HashBase.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/HashXMLCh.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/IllegalArgumentException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/KeyValuePair.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/KeyValuePair.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/NameIdPool.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/NameIdPool.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/NoSuchElementException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/Platforms/Linux/LinuxDefs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/RefHashTableOf.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/RefHashTableOf.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/RefVectorOf.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/RefVectorOf.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/RuntimeException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/StringPool.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/ValueStackOf.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/ValueStackOf.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/ValueVectorOf.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/ValueVectorOf.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/XercesDefs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLEnumerator.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLExceptMsgs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLMsgLoader.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLString.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLUni.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/validators/DTD/DocTypeHandler.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/validators/DTD/DTDAttDef.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/validators/DTD/DTDElementDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/validators/DTD/DTDEntityDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_4_0/src/validators/DTD/DTDValidator.hpp
