# $Id: Makefile,v 1.1 2001/05/22 12:38:06 sdw Exp $

CFLAGS = -c 
CPPFLAGS = -c -g -ggdb -Dlinux -fimplicit-templates -I/usr/share/xerces-c-src1_4_0/src -I../../ -D_REENTRANT 
#-instances=static
CPP = g++ -fpic 
CC = gcc
LINKFLAGS = -lm -L/usr/lib -L/usr/local/lib -lc
.SUFFIXES: .cpp

.cpp.o:	
	${CPP} ${CPPFLAGS}  $<

.c.o:	
	${CPP} ${CPPFLAGS}  $<

LIBS = ../../skInterpreter.a /usr/share/xerces-c-src1_4_0/lib/libxerces-c1_4.so /usr/lib/libpthread.so
OBJS = Inherits.o InheritsExecutable.o InheritsElement.o


Inherits: $(OBJS) $(LIBS)
	${CPP} $(OBJS) $(LIBS) ${LINKFLAGS} -o Inherits

clean:
	rm *.o *.a

depend:
	makedepend -I/usr/share/xerces-c-src1_4_0/src -I../../ *.cpp

# DO NOT DELETE


ScriptLoader.c.o: ../../skBoundsException.h ../../skExecutable.h
ScriptLoader.c.o: ../../skGeneral.h ../../skInterpreter.h ../../skNull.h
ScriptLoader.c.o: ../../skParseException.h ../../skRuntimeException.h
ScriptLoader.c.o: ../../skRValueArray.h ../../skRValue.h ../../skString.h
ScriptLoader.c.o: ../../skString.inl ../../skValist.h
ScriptLoader.c.o: ../../skXMLElementObject.h ../../skXMLExecutable.h
ScriptLoader.c.o: /usr/include/alloca.h /usr/include/assert.h
ScriptLoader.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
ScriptLoader.c.o: /usr/include/bits/sigset.h /usr/include/bits/types.h
ScriptLoader.c.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
ScriptLoader.c.o: /usr/include/features.h /usr/include/g++-3/iostream.h
ScriptLoader.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
ScriptLoader.c.o: /usr/include/gconv.h /usr/include/libio.h
ScriptLoader.c.o: /usr/include/stdlib.h /usr/include/string.h
ScriptLoader.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
ScriptLoader.c.o: /usr/include/time.h /usr/include/wchar.h
ScriptLoader.c.o: /usr/include/xlocale.h
ScriptLoader.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
ScriptLoader.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Element.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOM_Node.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/dom/DOMString.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/sax/InputSource.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/util/Compilers/GCCDefs.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/util/Platforms/Linux/LinuxDefs.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/util/PlatformUtils.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/util/XercesDefs.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLException.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLExceptMsgs.hpp
ScriptLoader.c.o: /usr/share/xerces-c-src1_4_0/src/util/XMLUni.hpp
