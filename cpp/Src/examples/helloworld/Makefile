# $Id: Makefile,v 1.1 2000/12/21 15:37:19 sdw Exp $

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
OBJS = HelloWorld.o 


HelloWorld: $(OBJS) $(LIBS)
	${CPP} $(OBJS) $(LIBS) -o HelloWorld

clean:
	rm *.o *.a

depend:
	makedepend -I/home/sdw/source/xerces-c-src1_3_0/include -I../../ *.cpp

# DO NOT DELETE

HelloWorld.o: ../../skInterpreter.h ../../skRValue.h ../../skString.h
HelloWorld.o: ../../skGeneral.h /usr/include/stdlib.h /usr/include/features.h
HelloWorld.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
HelloWorld.o: /usr/lib/gcc-lib/i386-redhat-linux/egcs-2.91.66/include/stddef.h
HelloWorld.o: /usr/include/sys/types.h /usr/include/bits/types.h
HelloWorld.o: /usr/include/time.h /usr/include/endian.h
HelloWorld.o: /usr/include/bits/endian.h /usr/include/sys/select.h
HelloWorld.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
HelloWorld.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
HelloWorld.o: /usr/include/assert.h ../../skString.inl /usr/include/string.h
HelloWorld.o: ../../skExecutable.h ../../skXMLExecutable.h
HelloWorld.o: ../../skXMLElementObject.h
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Element.hpp
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XercesDefs.hpp
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/util/AutoSense.hpp
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOM_Node.hpp
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/dom/DOMString.hpp
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/sax/InputSource.hpp
HelloWorld.o: ../../skRValueArray.h ../../skValist.h
HelloWorld.o: ../../skBoundsException.h
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/util/PlatformUtils.hpp
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLException.hpp
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLExceptMsgs.hpp
HelloWorld.o: /home/sdw/source/xerces-c-src1_3_0/include/util/XMLUni.hpp
