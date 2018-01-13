# $Id: Makefile,v 1.3 2003/06/02 09:15:19 sdw Exp $

CFLAGS = -c 
CPPFLAGS = -c -g -ggdb -Dlinux -fimplicit-templates  -I../../ -D_REENTRANT 
CPP = g++ -fpic
CC = gcc
.SUFFIXES: .cpp

.cpp.o:	
	${CPP} ${CPPFLAGS}  $<

.c.o:	
	${CPP} ${CPPFLAGS}  $<

LIBS = ../../Simkin_Expat.a  /usr/lib/libexpat.a
OBJS = HelloWorld.o 


HelloWorld: $(OBJS) $(LIBS)
	${CPP} $(OBJS) $(LIBS) -o HelloWorld

clean:
	rm *.o *.a

depend:
	makedepend -I../../ *.cpp

# DO NOT DELETE


HelloWorld.c.o: ../../skAlist.h ../../skAlist.inl ../../skAttribute.h
HelloWorld.c.o: ../../skBoundsException.h ../../skConstants.h
HelloWorld.c.o: ../../skElementExecutable.h ../../skElement.h
HelloWorld.c.o: ../../skElementObject.h ../../skExecutableContext.h
HelloWorld.c.o: ../../skExecutable.h ../../skExecutableIterator.h
HelloWorld.c.o: ../../skGeneral.h ../../skiExecutable.h ../../skInputSource.h
HelloWorld.c.o: ../../skInterpreter.h ../../skNode.h ../../skNull.h
HelloWorld.c.o: ../../skParseNode.h ../../skParseNode.inl
HelloWorld.c.o: ../../skRValueArray.h ../../skRValue.h ../../skRValue.inl
HelloWorld.c.o: ../../skRValueTable.h ../../skSHashTable.h
HelloWorld.c.o: ../../skSHashTable.inl ../../skString.h ../../skString.inl
HelloWorld.c.o: ../../skStringList.h ../../skValist.h /usr/include/alloca.h
HelloWorld.c.o: /usr/include/assert.h /usr/include/bits/pthreadtypes.h
HelloWorld.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
HelloWorld.c.o: /usr/include/bits/time.h /usr/include/bits/types.h
HelloWorld.c.o: /usr/include/bits/waitstatus.h /usr/include/ctype.h
HelloWorld.c.o: /usr/include/endian.h /usr/include/features.h
HelloWorld.c.o: /usr/include/g++-3/fstream.h /usr/include/g++-3/iostream.h
HelloWorld.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
HelloWorld.c.o: /usr/include/gconv.h /usr/include/libio.h /usr/include/stdio.h
HelloWorld.c.o: /usr/include/stdlib.h /usr/include/string.h
HelloWorld.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
HelloWorld.c.o: /usr/include/time.h /usr/include/wchar.h
HelloWorld.c.o: /usr/include/xlocale.h
HelloWorld.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
HelloWorld.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
