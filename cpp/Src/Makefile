# $Id: Makefile,v 1.17 2003/03/13 12:00:54 sdw Exp $

CFLAGS = -c 
CPPFLAGS = -c -g -ggdb -Dlinux -fimplicit-templates -I/usr/share/xerces-c-src2_1_0/src -D_REENTRANT 
#-instances=static
CPP = g++ -fpic
CC = gcc
.SUFFIXES: .cpp

.cpp.o:	
	${CPP} ${CPPFLAGS}  $<

.c.o:	
	${CPP} ${CPPFLAGS}  $<

lib_proj=Interpreter

treenode_objects = skAlist.o skTreeNodeObject.o skTreeNodeObjectEnumerator.o skHashTable.o skString.o skTreeNode.o  skLang_tab.o skExecutable.o skInterpreter.o skRValue.o skScriptedExecutable.o skTracer.o skParser.o skExecutableIterator.o skStringBuffer.o skOutputDestination.o skInputSource.o skStackFrame.o skExecutableContext.o skEncodingUtils.o skStringTokenizer.o

xerces_objects = skAlist.o skHashTable.o skString.o  skLang_tab.o skExecutable.o skInterpreter.o skRValue.o skScriptedExecutable.o skTracer.o skXMLElementObject.o skXMLElementObjectEnumerator.o  skXMLExecutable.o skStringTokenizer.o skXMLErrorHandler.o skParser.o skExecutableIterator.o skStringBuffer.o skOutputDestination.o skInputSource.o skStackFrame.o skExecutableContext.o

expat_objects = skAlist.o skHashTable.o skString.o skTreeNode.o  skLang_tab.o skExecutable.o skInterpreter.o skRValue.o skTracer.o skParser.o skExecutableIterator.o skElement.o skElementExecutable.o skElementObject.o skElementObjectEnumerator.o skExpatParser.o skNode.o skStringTokenizer.o skStringBuffer.o skOutputDestination.o skInputSource.o skStackFrame.o skExecutableContext.o skTextNode.o skCDataNode.o

Simkin_Xerces.a: skLang_tab.cpp $(xerces_objects) 
	ar -r Simkin_Xerces.a  $(xerces_objects)
	ranlib Simkin_Xerces.a

Simkin_Expat.a: skLang_tab.cpp $(expat_objects) 
	ar -r Simkin_Expat.a  $(expat_objects)
	ranlib Simkin_Expat.a

Simkin_TreeNode.a: skLang_tab.cpp $(treenode_objects) 
	ar -r Simkin_TreeNode.a  $(treenode_objects)
	ranlib Simkin_TreeNode.a

clean:
	rm *.o *.a

depend:
	makedepend -I/usr/share/xerces-c-src1_5_2/src *.cpp

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
skElement.c.o: skAlist.h skAlist.inl skAttribute.h skBoundsException.h
skElement.c.o: skElement.h skGeneral.h skNode.h skString.h skString.inl
skElement.c.o: /usr/include/alloca.h /usr/include/assert.h
skElement.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skElement.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skElement.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skElement.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skElement.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skElement.c.o: /usr/include/gconv.h /usr/include/libio.h /usr/include/stdlib.h
skElement.c.o: /usr/include/string.h /usr/include/sys/select.h
skElement.c.o: /usr/include/sys/types.h /usr/include/time.h
skElement.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skElement.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skElement.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skElementExecutable.c.o: skAlist.h skAlist.inl skAttribute.h
skElementExecutable.c.o: skBoundsException.h skElementExecutable.h skElement.h
skElementExecutable.c.o: skElementObject.h skExecutable.h skExpatParser.h
skElementExecutable.c.o: skGeneral.h skiExecutable.h skNode.h skString.h
skElementExecutable.c.o: skString.inl /usr/include/alloca.h
skElementExecutable.c.o: /usr/include/assert.h
skElementExecutable.c.o: /usr/include/bits/pthreadtypes.h
skElementExecutable.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skElementExecutable.c.o: /usr/include/bits/types.h
skElementExecutable.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skElementExecutable.c.o: /usr/include/expat.h /usr/include/features.h
skElementExecutable.c.o: /usr/include/g++-3/fstream.h
skElementExecutable.c.o: /usr/include/g++-3/iostream.h
skElementExecutable.c.o: /usr/include/g++-3/streambuf.h
skElementExecutable.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skElementExecutable.c.o: /usr/include/libio.h /usr/include/stdlib.h
skElementExecutable.c.o: /usr/include/string.h /usr/include/sys/select.h
skElementExecutable.c.o: /usr/include/sys/types.h /usr/include/time.h
skElementExecutable.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skElementExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skElementExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skElementObject.c.o: skAlist.h skAlist.inl skAttribute.h skBoundsException.h
skElementObject.c.o: skElement.h skElementObjectEnumerator.h skElementObject.h
skElementObject.c.o: skExecutable.h skExecutableIterator.h skGeneral.h
skElementObject.c.o: skHashTable.h skHashTable.inl skiExecutable.h
skElementObject.c.o: skInterpreter.h skMethodTable.h skNode.h skNull.h
skElementObject.c.o: skParseNode.h skRValueArray.h skRValue.h skRValue.inl
skElementObject.c.o: skString.h skString.inl skStringList.h
skElementObject.c.o: skStringTokenizer.h skValist.h /usr/include/alloca.h
skElementObject.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skElementObject.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skElementObject.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skElementObject.c.o: /usr/include/endian.h /usr/include/features.h
skElementObject.c.o: /usr/include/g++-3/iostream.h
skElementObject.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skElementObject.c.o: /usr/include/gconv.h /usr/include/libio.h
skElementObject.c.o: /usr/include/stdio.h /usr/include/stdlib.h
skElementObject.c.o: /usr/include/string.h /usr/include/sys/select.h
skElementObject.c.o: /usr/include/sys/types.h /usr/include/time.h
skElementObject.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skElementObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skElementObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skElementObjectEnumerator.c.o: skAlist.h skAlist.inl skAttribute.h
skElementObjectEnumerator.c.o: skBoundsException.h skElement.h
skElementObjectEnumerator.c.o: skElementObjectEnumerator.h skElementObject.h
skElementObjectEnumerator.c.o: skExecutable.h skExecutableIterator.h
skElementObjectEnumerator.c.o: skGeneral.h skiExecutable.h skInterpreter.h
skElementObjectEnumerator.c.o: skNode.h skNull.h skRValue.h skRValue.inl
skElementObjectEnumerator.c.o: skString.h skString.inl /usr/include/alloca.h
skElementObjectEnumerator.c.o: /usr/include/assert.h
skElementObjectEnumerator.c.o: /usr/include/bits/pthreadtypes.h
skElementObjectEnumerator.c.o: /usr/include/bits/sched.h
skElementObjectEnumerator.c.o: /usr/include/bits/sigset.h
skElementObjectEnumerator.c.o: /usr/include/bits/types.h
skElementObjectEnumerator.c.o: /usr/include/bits/waitstatus.h
skElementObjectEnumerator.c.o: /usr/include/endian.h /usr/include/features.h
skElementObjectEnumerator.c.o: /usr/include/g++-3/iostream.h
skElementObjectEnumerator.c.o: /usr/include/g++-3/streambuf.h
skElementObjectEnumerator.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skElementObjectEnumerator.c.o: /usr/include/libio.h /usr/include/stdio.h
skElementObjectEnumerator.c.o: /usr/include/stdlib.h /usr/include/string.h
skElementObjectEnumerator.c.o: /usr/include/sys/select.h
skElementObjectEnumerator.c.o: /usr/include/sys/types.h /usr/include/time.h
skElementObjectEnumerator.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skElementObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skElementObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skExecutable.c.o: skBoundsException.h skExecutable.h skGeneral.h
skExecutable.c.o: skiExecutable.h skInterpreter.h skNull.h skRValueArray.h
skExecutable.c.o: skRValue.h skRValue.inl skString.h skString.inl skTracer.h
skExecutable.c.o: skValist.h /usr/include/alloca.h /usr/include/assert.h
skExecutable.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skExecutable.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skExecutable.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skExecutable.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skExecutable.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skExecutable.c.o: /usr/include/gconv.h /usr/include/libio.h
skExecutable.c.o: /usr/include/stdio.h /usr/include/stdlib.h
skExecutable.c.o: /usr/include/string.h /usr/include/sys/select.h
skExecutable.c.o: /usr/include/sys/types.h /usr/include/time.h
skExecutable.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skExecutableIterator.c.o: skExecutableIterator.h skGeneral.h
skExecutableIterator.c.o: /usr/include/alloca.h /usr/include/assert.h
skExecutableIterator.c.o: /usr/include/bits/pthreadtypes.h
skExecutableIterator.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skExecutableIterator.c.o: /usr/include/bits/types.h
skExecutableIterator.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skExecutableIterator.c.o: /usr/include/features.h /usr/include/stdlib.h
skExecutableIterator.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skExecutableIterator.c.o: /usr/include/time.h /usr/include/xlocale.h
skExecutableIterator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skExpatParser.c.o: skAlist.h skAlist.inl skAttribute.h skBoundsException.h
skExpatParser.c.o: skElement.h skExpatParser.h skGeneral.h skNode.h skString.h
skExpatParser.c.o: skString.inl skXMLParseException.h /usr/include/alloca.h
skExpatParser.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skExpatParser.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skExpatParser.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skExpatParser.c.o: /usr/include/endian.h /usr/include/expat.h
skExpatParser.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skExpatParser.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skExpatParser.c.o: /usr/include/gconv.h /usr/include/libio.h
skExpatParser.c.o: /usr/include/stdio.h /usr/include/stdlib.h
skExpatParser.c.o: /usr/include/string.h /usr/include/sys/select.h
skExpatParser.c.o: /usr/include/sys/types.h /usr/include/time.h
skExpatParser.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skExpatParser.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skExpatParser.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
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
skInterpreter.c.o: skExecutableIterator.h skGeneral.h skHashTable.h
skInterpreter.c.o: skHashTable.inl skiExecutable.h skInterpreter.h
skInterpreter.c.o: skInterpreterp.h skNull.h skParseException.h skParseNode.h
skInterpreter.c.o: skParser.h skRuntimeException.h skRValueArray.h skRValue.h
skInterpreter.c.o: skRValue.inl skRValueTable.h skStatementStepper.h
skInterpreter.c.o: skString.h skString.inl skStringList.h skTraceCallback.h
skInterpreter.c.o: skTracer.h skValist.h /usr/include/alloca.h
skInterpreter.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skInterpreter.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skInterpreter.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skInterpreter.c.o: /usr/include/endian.h /usr/include/features.h
skInterpreter.c.o: /usr/include/g++-3/iostream.h
skInterpreter.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skInterpreter.c.o: /usr/include/gconv.h /usr/include/libio.h
skInterpreter.c.o: /usr/include/stdio.h /usr/include/stdlib.h
skInterpreter.c.o: /usr/include/string.h /usr/include/sys/select.h
skInterpreter.c.o: /usr/include/sys/types.h /usr/include/time.h
skInterpreter.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skInterpreter.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skInterpreter.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skLang_tab.c.o: skAlist.h skAlist.inl skBoundsException.h skGeneral.h sklang.y
skLang_tab.c.o: skParseException.h skParseNode.h skParser.h skString.h
skLang_tab.c.o: skString.inl skStringList.h skValist.h /usr/include/alloca.h
skLang_tab.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skLang_tab.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skLang_tab.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skLang_tab.c.o: /usr/include/endian.h /usr/include/features.h
skLang_tab.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/streambuf.h
skLang_tab.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skLang_tab.c.o: /usr/include/libio.h /usr/include/stdio.h
skLang_tab.c.o: /usr/include/stdlib.h /usr/include/string.h
skLang_tab.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skLang_tab.c.o: /usr/include/time.h /usr/include/wchar.h
skLang_tab.c.o: /usr/include/xlocale.h
skLang_tab.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skLang_tab.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skLang_tab.c.o: /usr/local/share/bison.simple
skNode.c.o: skAlist.h skAlist.inl skBoundsException.h skGeneral.h skNode.h
skNode.c.o: skString.h skString.inl /usr/include/alloca.h
skNode.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skNode.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skNode.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skNode.c.o: /usr/include/endian.h /usr/include/features.h
skNode.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/streambuf.h
skNode.c.o: /usr/include/_G_config.h /usr/include/gconv.h /usr/include/libio.h
skNode.c.o: /usr/include/stdlib.h /usr/include/string.h
skNode.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skNode.c.o: /usr/include/time.h /usr/include/wchar.h /usr/include/xlocale.h
skNode.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skNode.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skParser.c.o: skAlist.h skAlist.inl skBoundsException.h skGeneral.h
skParser.c.o: skLang_tab.h skParseException.h skParseNode.h skParser.h
skParser.c.o: skString.h skString.inl skStringList.h skTracer.h skValist.h
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
skRValue.c.o: skExecutable.h skGeneral.h skiExecutable.h skRValue.h
skRValue.c.o: skRValue.inl skString.h skString.inl /usr/include/alloca.h
skRValue.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skRValue.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skRValue.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skRValue.c.o: /usr/include/endian.h /usr/include/features.h
skRValue.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/ostream.h
skRValue.c.o: /usr/include/g++-3/streambuf.h /usr/include/g++-3/stream.h
skRValue.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skRValue.c.o: /usr/include/libio.h /usr/include/stdio.h /usr/include/stdlib.h
skRValue.c.o: /usr/include/string.h /usr/include/sys/select.h
skRValue.c.o: /usr/include/sys/types.h /usr/include/time.h
skRValue.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skRValue.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skRValue.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skScriptedExecutable.c.o: skExecutable.h skGeneral.h skiExecutable.h
skScriptedExecutable.c.o: skScriptedExecutable.h skString.h skString.inl
skScriptedExecutable.c.o: skTreeNode.h skTreeNodeObject.h
skScriptedExecutable.c.o: /usr/include/alloca.h /usr/include/assert.h
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
skTracer.c.o: skGeneral.h skString.h skString.inl skTracer.h
skTracer.c.o: /usr/include/alloca.h /usr/include/assert.h
skTracer.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
skTracer.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
skTracer.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skTracer.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skTracer.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skTracer.c.o: /usr/include/gconv.h /usr/include/libio.h /usr/include/stdlib.h
skTracer.c.o: /usr/include/string.h /usr/include/sys/select.h
skTracer.c.o: /usr/include/sys/types.h /usr/include/time.h
skTracer.c.o: /usr/include/wchar.h /usr/include/xlocale.h
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
skTreeNodeObject.c.o: skAlist.h skAlist.inl skBoundsException.h skExecutable.h
skTreeNodeObject.c.o: skExecutableIterator.h skGeneral.h skHashTable.h
skTreeNodeObject.c.o: skHashTable.inl skiExecutable.h skInterpreter.h
skTreeNodeObject.c.o: skMethodTable.h skNull.h skParseNode.h skRValueArray.h
skTreeNodeObject.c.o: skRValue.h skRValue.inl skString.h skString.inl
skTreeNodeObject.c.o: skStringList.h skTreeNode.h skTreeNodeObjectEnumerator.h
skTreeNodeObject.c.o: skTreeNodeObject.h skValist.h /usr/include/alloca.h
skTreeNodeObject.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
skTreeNodeObject.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skTreeNodeObject.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
skTreeNodeObject.c.o: /usr/include/endian.h /usr/include/features.h
skTreeNodeObject.c.o: /usr/include/g++-3/iostream.h
skTreeNodeObject.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
skTreeNodeObject.c.o: /usr/include/gconv.h /usr/include/libio.h
skTreeNodeObject.c.o: /usr/include/stdio.h /usr/include/stdlib.h
skTreeNodeObject.c.o: /usr/include/string.h /usr/include/sys/select.h
skTreeNodeObject.c.o: /usr/include/sys/types.h /usr/include/time.h
skTreeNodeObject.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skTreeNodeObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skTreeNodeObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skTreeNodeObjectEnumerator.c.o: skExecutable.h skExecutableIterator.h
skTreeNodeObjectEnumerator.c.o: skGeneral.h skiExecutable.h skInterpreter.h
skTreeNodeObjectEnumerator.c.o: skNull.h skRValue.h skRValue.inl skString.h
skTreeNodeObjectEnumerator.c.o: skString.inl skTreeNode.h
skTreeNodeObjectEnumerator.c.o: skTreeNodeObjectEnumerator.h
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
skTreeNodeObjectEnumerator.c.o: /usr/include/libio.h /usr/include/stdio.h
skTreeNodeObjectEnumerator.c.o: /usr/include/stdlib.h /usr/include/string.h
skTreeNodeObjectEnumerator.c.o: /usr/include/sys/select.h
skTreeNodeObjectEnumerator.c.o: /usr/include/sys/types.h /usr/include/time.h
skTreeNodeObjectEnumerator.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skTreeNodeObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skTreeNodeObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skXMLElementObject.c.o: skAlist.h skAlist.inl skBoundsException.h
skXMLElementObject.c.o: skExecutable.h skExecutableIterator.h skGeneral.h
skXMLElementObject.c.o: skHashTable.h skHashTable.inl skiExecutable.h
skXMLElementObject.c.o: skInterpreter.h skMethodTable.h skNull.h skParseNode.h
skXMLElementObject.c.o: skRValueArray.h skRValue.h skRValue.inl skString.h
skXMLElementObject.c.o: skString.inl skStringList.h skStringTokenizer.h
skXMLElementObject.c.o: skValist.h skXMLElement.h
skXMLElementObject.c.o: skXMLElementObjectEnumerator.h skXMLElementObject.h
skXMLElementObject.c.o: /usr/include/alloca.h /usr/include/assert.h
skXMLElementObject.c.o: /usr/include/bits/pthreadtypes.h
skXMLElementObject.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
skXMLElementObject.c.o: /usr/include/bits/types.h
skXMLElementObject.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
skXMLElementObject.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
skXMLElementObject.c.o: /usr/include/g++-3/streambuf.h
skXMLElementObject.c.o: /usr/include/_G_config.h /usr/include/gconv.h
skXMLElementObject.c.o: /usr/include/libio.h /usr/include/stdio.h
skXMLElementObject.c.o: /usr/include/stdlib.h /usr/include/string.h
skXMLElementObject.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
skXMLElementObject.c.o: /usr/include/time.h /usr/include/wchar.h
skXMLElementObject.c.o: /usr/include/xlocale.h
skXMLElementObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skXMLElementObject.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Attr.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_CDATASection.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_CharacterData.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Comment.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_DocumentFragment.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Document.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_DocumentType.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_DOMImplementation.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Element.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Entity.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_EntityReference.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_NamedNodeMap.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_NodeFilter.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Node.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_NodeIterator.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_NodeList.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Notation.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_ProcessingInstruction.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Range.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOMString.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Text.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_TreeWalker.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_XMLDecl.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLAttDef.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLAttDefList.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLAttr.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLContentModel.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLDocumentHandler.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLElementDecl.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLEntityDecl.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLEntityHandler.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLErrorReporter.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLFormatter.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLNotationDecl.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/parsers/DOMParser.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/ArrayIndexOutOfBoundsException.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/Compilers/GCCDefs.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/EmptyStackException.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/HashBase.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/HashXMLCh.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/IllegalArgumentException.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/KeyValuePair.c
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/KeyValuePair.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/NoSuchElementException.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/NullPointerException.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/Platforms/Linux/LinuxDefs.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/QName.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefHashTableOf.c
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefHashTableOf.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefVectorOf.c
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefVectorOf.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/RuntimeException.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/ValueStackOf.c
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/ValueStackOf.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/ValueVectorOf.c
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/ValueVectorOf.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/XercesDefs.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLEnumerator.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLException.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLExceptMsgs.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLMsgLoader.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLString.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLUniDefs.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLUni.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/validators/DTD/DocTypeHandler.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/validators/DTD/DTDAttDef.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/validators/DTD/DTDElementDecl.hpp
skXMLElementObject.c.o: /usr/share/xerces-c-src1_5_2/src/validators/DTD/DTDEntityDecl.hpp
skXMLElementObjectEnumerator.c.o: skExecutable.h skExecutableIterator.h
skXMLElementObjectEnumerator.c.o: skGeneral.h skiExecutable.h skInterpreter.h
skXMLElementObjectEnumerator.c.o: skNull.h skRValue.h skRValue.inl skString.h
skXMLElementObjectEnumerator.c.o: skString.inl skXMLElementObjectEnumerator.h
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
skXMLElementObjectEnumerator.c.o: /usr/include/stdio.h /usr/include/stdlib.h
skXMLElementObjectEnumerator.c.o: /usr/include/string.h
skXMLElementObjectEnumerator.c.o: /usr/include/sys/select.h
skXMLElementObjectEnumerator.c.o: /usr/include/sys/types.h /usr/include/time.h
skXMLElementObjectEnumerator.c.o: /usr/include/wchar.h /usr/include/xlocale.h
skXMLElementObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
skXMLElementObjectEnumerator.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Element.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Node.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_NodeList.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOMString.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLFormatter.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_5_2/src/util/Compilers/GCCDefs.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_5_2/src/util/Platforms/Linux/LinuxDefs.hpp
skXMLElementObjectEnumerator.c.o: /usr/share/xerces-c-src1_5_2/src/util/XercesDefs.hpp
skXMLErrorHandler.c.o: skExecutable.h skGeneral.h skiExecutable.h skString.h
skXMLErrorHandler.c.o: skString.inl skXMLElementObject.h skXMLErrorHandler.h
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
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Element.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Node.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOMString.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLFormatter.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/sax/ErrorHandler.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/sax/SAXException.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/sax/SAXParseException.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/ArrayIndexOutOfBoundsException.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/Compilers/GCCDefs.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/Platforms/Linux/LinuxDefs.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefVectorOf.c
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefVectorOf.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/XercesDefs.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLEnumerator.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLException.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLExceptMsgs.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLString.hpp
skXMLErrorHandler.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLUni.hpp
skXMLExecutable.c.o: skExecutable.h skGeneral.h skiExecutable.h skString.h
skXMLExecutable.c.o: skString.inl skXMLElementObject.h skXMLErrorHandler.h
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
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Attr.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_CDATASection.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_CharacterData.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Comment.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_DocumentFragment.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Document.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_DocumentType.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_DOMImplementation.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Element.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Entity.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_EntityReference.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_NodeFilter.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Node.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_NodeIterator.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_NodeList.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Notation.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_ProcessingInstruction.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Range.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOMString.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_Text.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_TreeWalker.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/dom/DOM_XMLDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/LocalFileInputSource.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/MemBufInputSource.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLAttDef.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLAttDefList.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLAttr.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLContentModel.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLDocumentHandler.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLElementDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLEntityDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLEntityHandler.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLErrorReporter.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLFormatter.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/framework/XMLNotationDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/parsers/DOMParser.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/sax/ErrorHandler.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/sax/InputSource.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/ArrayIndexOutOfBoundsException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/Compilers/GCCDefs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/EmptyStackException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/HashBase.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/HashXMLCh.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/IllegalArgumentException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/KeyValuePair.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/KeyValuePair.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/NoSuchElementException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/NullPointerException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/Platforms/Linux/LinuxDefs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/QName.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefHashTableOf.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefHashTableOf.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefVectorOf.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/RefVectorOf.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/RuntimeException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/ValueStackOf.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/ValueStackOf.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/ValueVectorOf.c
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/ValueVectorOf.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/XercesDefs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLEnumerator.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLException.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLExceptMsgs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLMsgLoader.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLString.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLUniDefs.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/util/XMLUni.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/validators/DTD/DocTypeHandler.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/validators/DTD/DTDAttDef.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/validators/DTD/DTDElementDecl.hpp
skXMLExecutable.c.o: /usr/share/xerces-c-src1_5_2/src/validators/DTD/DTDEntityDecl.hpp
