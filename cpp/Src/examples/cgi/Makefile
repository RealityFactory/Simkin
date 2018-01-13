# $Id: Makefile,v 1.1 2003/03/13 12:01:13 sdw Exp $

CFLAGS = -c 
CPPFLAGS = -c -g -ggdb -Dlinux -fimplicit-templates -I/usr/share/xerces-c-src2_1_0/src -I../../ -D_REENTRANT 
#-instances=static
CPP = g++ -fpic 
CC = gcc
LINKFLAGS = -lm -L/usr/lib -L/usr/local/lib -lc
.SUFFIXES: .cpp

.cpp.o:	
	${CPP} ${CPPFLAGS}  $<

.c.o:	
	${CPP} ${CPPFLAGS}  $<

TREENODE_LIBS = ../../Simkin_TreeNode.a

SimkinCGI: $(TREENODE_LIBS) SimkinCGI.cpp
	${CPP} ${CPPFLAGS} SimkinCGI.cpp 
	${CPP} SimkinCGI.o $(TREENODE_LIBS) ${LINKFLAGS} -o SimkinCGI

clean:
	rm *.o *.a SimkinCGI

