# $Id: Makefile,v 1.2 2001/11/05 18:09:55 sdw Exp $

CFLAGS = -c 
CPPFLAGS = -c -g -ggdb -Dlinux -fimplicit-templates -I/usr/share/xerces-c-src1_4_0/src -I../../ -D_REENTRANT 
CPP = g++ -fpic
CC = gcc
.SUFFIXES: .cpp

.cpp.o:	
	${CPP} ${CPPFLAGS}  $<

.c.o:	
	${CPP} ${CPPFLAGS}  $<

LIBS = ../../Simkin_Xerces.a /usr/share/xerces-c-src1_4_0/lib/libxerces-c1_4.so /usr/lib/libpthread.so
OBJS = HelloWorld.o 


HelloWorld: $(OBJS) $(LIBS)
	${CPP} $(OBJS) $(LIBS) -o HelloWorld

clean:
	rm *.o *.a

depend:
	makedepend -I/usr/share/xerces-c-src1_4_0/src -I../../ *.cpp

# DO NOT DELETE


HelloWorld.c.o: ../../skBoundsException.h ../../skExecutable.h
HelloWorld.c.o: ../../skGeneral.h ../../skiExecutable.h ../../skInterpreter.h
HelloWorld.c.o: ../../skNull.h ../../skRValueArray.h ../../skRValue.h
HelloWorld.c.o: ../../skRValue.inl ../../skString.h ../../skString.inl
HelloWorld.c.o: ../../skValist.h ../../skXMLElementObject.h
HelloWorld.c.o: ../../skXMLExecutable.h /usr/include/alloca.h
HelloWorld.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
HelloWorld.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
HelloWorld.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
HelloWorld.c.o: /usr/include/endian.h /usr/include/features.h
HelloWorld.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/streambuf.h
HelloWorld.c.o: /usr/include/_G_config.h /usr/include/gconv.h
HelloWorld.c.o: /usr/include/libio.h /usr/include/stdio.h
HelloWorld.c.o: /usr/include/stdlib.h /usr/include/string.h
HelloWorld.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
HelloWorld.c.o: /usr/include/time.h /usr/include/wchar.h
HelloWorld.c.o: /usr/include/xlocale.h
HelloWorld.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
HelloWorld.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
