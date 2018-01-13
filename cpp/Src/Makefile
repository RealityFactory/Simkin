# $Id: Makefile,v 1.9 2001/05/22 10:22:53 sdw Exp $

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

objects = skAlist.o skTreeNodeObject.o skTreeNodeObjectEnumerator.o skHashTable.o skString.o skTreeNode.o  skLang_tab.o skExecutable.o skInterpreter.o skRValue.o skScriptedExecutable.o skTracer.o skXMLElementObject.o skXMLElementObjectEnumerator.o  skXMLExecutable.o skStringTokenizer.o skXMLErrorHandler.o skParser.o

skInterpreter.a: skLang_tab.cpp $(objects) 
	ar -r skInterpreter.a  $(objects)
	ranlib skInterpreter.a

skLang_tab.cpp: skLang.y
	bison -bskLang -d -v skLang.y
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
skInterpreter.c.o: skInterpreterp.h skNull.h skParseException.h skParseNode.h
skInterpreter.c.o: skParser.h skRuntimeException.h skRValueArray.h skRValue.h
skInterpreter.c.o: skString.h skString.inl skStringList.h skTracer.h
skInterpreter.c.o: skValist.h /usr/include/alloca.h /usr/include/assert.h
skInterpreter.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skInterpreter.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skInterpreter.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skInterpreter.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skInterpreter.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skInterpreter.c.o: /usr/include/gconv.h /usr/include/libio.h
skInterpreter.c.o: /usr/include/stdio.h /usr/include/stdlib.h
skInterpreter.c.o: /usr/include/string.h /usr/include/sys/select.h
skInterpreter.c.o: /usr/include/sys/types.h /usr/include/time.h
skInterpreter.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skInterpreter.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skInterpreter.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skLang_tab.c.o: skLang.y /usr/include/bits/pthreadtypes.h
skLang_tab.c.o: /usr/include/bits/sched.h /usr/include/bits/types.h
skLang_tab.c.o: /usr/include/features.h /usr/include/_G_config.h
skLang_tab.c.o: /usr/include/gconv.h /usr/include/libio.h /usr/include/stdio.h
skLang_tab.c.o: /usr/include/wchar.h /usr/lib/bison.simple
skLang_tab.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skLang_tab.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skParser.c.o: skAlist.h skAlist.inl skBoundsException.h skGeneral.h
skParser.c.o: skLang_tab.h skParseException.h skParseNode.h skParser.h
skParser.c.o: skString.h skString.inl skStringList.h skValist.h
skParser.c.o: /usr/include/alloca.h /usr/include/assert.h
skParser.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skParser.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skParser.c.o: /usr/include/bits/waitstatus.h /usr/include/ctype.h
skParser.c.o: /usr/include/endian.h /usr/include/features.h
skParser.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/streambuf.h
skParser.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skParser.c.o: /usr/include/libio.h /usr/include/stdlib.h /usr/include/string.h
skParser.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skParser.c.o: /usr/include/time.h /usr/include/wchar.h /usr/include/xlocale.h
skParser.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skParser.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
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
