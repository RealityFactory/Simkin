# $Id: Makefile,v 1.1 2000/12/21 15:37:20 sdw Exp $

CFLAGS = -c 
CPPFLAGS = -c -g -ggdb -Dlinux -fimplicit-templates -I/home/sdw/source/xerces-c-src1_3_0/include -I../../ -D_REENTRANT -instances=static
CPP = g++ -fpic
CC = gcc
.SUFFIXES: .cpp

.cpp.o:	
	${CPP} ${CPPFLAGS}  $<

.c.o:	
	${CPP} ${CPPFLAGS}  $<

LIBS = ../../skInterpreter.a /home/sdw/source/xerces-c-src1_3_0/lib/libxerces-c1_3.so
OBJS = ScriptLoader.o 


ScriptLoader: $(OBJS) $(LIBS)
	${CPP} $(OBJS) $(LIBS) -o ScriptLoader

clean:
	rm *.o *.a

depend:
	makedepend -I/home/sdw/source/xerces-c-src1_3_0/include -I../../ *.cpp

# DO NOT DELETE

ScriptLoader.o: ../../skInterpreter.h ../../skRValue.h ../../skString.h
ScriptLoader.o: ../../skGeneral.h /usr/include/stdlib.h
ScriptLoader.o: /usr/include/features.h /usr/include/sys/cdefs.h
ScriptLoader.o: /usr/include/gnu/stubs.h
ScriptLoader.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
ScriptLoader.o: /usr/include/sys/types.h /usr/include/bits/types.h
ScriptLoader.o: /usr/include/time.h /usr/include/endian.h
ScriptLoader.o: /usr/include/bits/endian.h /usr/include/sys/select.h
ScriptLoader.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
ScriptLoader.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
ScriptLoader.o: /usr/include/assert.h ../../skString.inl
ScriptLoader.o: /usr/include/string.h ../../skExecutable.h
ScriptLoader.o: ../../skXMLExecutable.h ../../skXMLElementObject.h
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Element.hpp
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XercesDefs.hpp
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/util/AutoSense.hpp
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Node.hpp
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOMString.hpp
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/sax/InputSource.hpp
ScriptLoader.o: ../../skRValueArray.h ../../skValist.h
ScriptLoader.o: ../../skBoundsException.h
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/util/PlatformUtils.hpp
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLException.hpp
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLExceptMsgs.hpp
ScriptLoader.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLUni.hpp
