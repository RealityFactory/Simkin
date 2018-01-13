# $Id: Makefile,v 1.3 2003/06/04 08:11:31 sdw Exp $

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

LIBS = ../../Simkin_Xerces.a /usr/share/xerces-c-src2_1_0/lib/libxerces-c.so.21.0 /usr/lib/libpthread.so
OBJS = Inherits.o InheritsExecutable.o InheritsElement.o


Inherits: $(OBJS) $(LIBS)
	${CPP} $(OBJS) $(LIBS) ${LINKFLAGS} -o Inherits

clean:
	rm *.o *.a

depend:
	makedepend -I/usr/share/xerces-c-src2_1_0/src -I../../ *.cpp

# DO NOT DELETE


Inherits.c.o: InheritsElement.h InheritsExecutable.h ../../skAlist.h
Inherits.c.o: ../../skAlist.inl ../../skBoundsException.h ../../skConstants.h
Inherits.c.o: ../../skException.h ../../skExecutableContext.h
Inherits.c.o: ../../skExecutable.h ../../skExecutableIterator.h
Inherits.c.o: ../../skGeneral.h ../../skiExecutable.h ../../skInterpreter.h
Inherits.c.o: ../../skNull.h ../../skParseException.h ../../skParseNode.h
Inherits.c.o: ../../skParseNode.inl ../../skRuntimeException.h
Inherits.c.o: ../../skRValueArray.h ../../skRValue.h ../../skRValue.inl
Inherits.c.o: ../../skRValueTable.h ../../skSHashTable.h
Inherits.c.o: ../../skSHashTable.inl ../../skStringBuffer.h ../../skString.h
Inherits.c.o: ../../skString.inl ../../skStringList.h ../../skTracer.h
Inherits.c.o: ../../skValist.h ../../skXMLElementObject.h
Inherits.c.o: /usr/include/alloca.h /usr/include/assert.h
Inherits.c.o: /usr/include/bits/local_lim.h /usr/include/bits/posix1_lim.h
Inherits.c.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sched.h
Inherits.c.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Inherits.c.o: /usr/include/bits/types.h /usr/include/bits/waitstatus.h
Inherits.c.o: /usr/include/bits/xopen_lim.h /usr/include/ctype.h
Inherits.c.o: /usr/include/endian.h /usr/include/features.h
Inherits.c.o: /usr/include/g++-3/iostream.h /usr/include/g++-3/streambuf.h
Inherits.c.o: /usr/include/_G_config.h /usr/include/gconv.h
Inherits.c.o: /usr/include/libio.h /usr/include/limits.h /usr/include/stdlib.h
Inherits.c.o: /usr/include/string.h /usr/include/sys/select.h
Inherits.c.o: /usr/include/sys/types.h /usr/include/time.h
Inherits.c.o: /usr/include/wchar.h /usr/include/xlocale.h
Inherits.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/limits.h
Inherits.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
Inherits.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
Inherits.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/syslimits.h
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Element.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Node.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOMString.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLErrorReporter.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLFormatter.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/sax/InputSource.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/sax/SAXException.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ArrayIndexOutOfBoundsException.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/Compilers/GCCDefs.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/Platforms/Linux/LinuxDefs.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/PlatformUtils.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefVectorOf.c
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefVectorOf.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XercesDefs.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XercesVersion.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLEnumerator.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLException.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLExceptMsgs.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLMsgLoader.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLString.hpp
Inherits.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLUni.hpp
InheritsElement.c.o: InheritsElement.h ../../skExecutableContext.h
InheritsElement.c.o: ../../skExecutable.h ../../skGeneral.h
InheritsElement.c.o: ../../skiExecutable.h ../../skString.h ../../skString.inl
InheritsElement.c.o: ../../skXMLElementObject.h ../../skXMLErrorHandler.h
InheritsElement.c.o: /usr/include/alloca.h /usr/include/assert.h
InheritsElement.c.o: /usr/include/bits/local_lim.h
InheritsElement.c.o: /usr/include/bits/posix1_lim.h
InheritsElement.c.o: /usr/include/bits/pthreadtypes.h
InheritsElement.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
InheritsElement.c.o: /usr/include/bits/time.h /usr/include/bits/types.h
InheritsElement.c.o: /usr/include/bits/waitstatus.h
InheritsElement.c.o: /usr/include/bits/xopen_lim.h /usr/include/ctype.h
InheritsElement.c.o: /usr/include/endian.h /usr/include/features.h
InheritsElement.c.o: /usr/include/g++-3/iostream.h
InheritsElement.c.o: /usr/include/g++-3/streambuf.h /usr/include/_G_config.h
InheritsElement.c.o: /usr/include/gconv.h /usr/include/libio.h
InheritsElement.c.o: /usr/include/limits.h /usr/include/stdlib.h
InheritsElement.c.o: /usr/include/string.h /usr/include/sys/select.h
InheritsElement.c.o: /usr/include/sys/types.h /usr/include/time.h
InheritsElement.c.o: /usr/include/wchar.h /usr/include/xlocale.h
InheritsElement.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/limits.h
InheritsElement.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
InheritsElement.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
InheritsElement.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/syslimits.h
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Attr.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_CDATASection.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_CharacterData.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Comment.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_DocumentFragment.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Document.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_DocumentType.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_DOMImplementation.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Element.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Entity.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_EntityReference.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_NodeFilter.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Node.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_NodeIterator.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_NodeList.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Notation.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOMParser.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_ProcessingInstruction.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Range.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOMString.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Text.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_TreeWalker.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_XMLDecl.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/LocalFileInputSource.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLAttDef.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLAttDefList.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLAttr.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLContentModel.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLDocumentHandler.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLElementDecl.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLEntityDecl.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLEntityHandler.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLErrorReporter.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLFormatter.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLNotationDecl.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/sax/ErrorHandler.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/sax/InputSource.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ArrayIndexOutOfBoundsException.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/Compilers/GCCDefs.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/EmptyStackException.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/HashBase.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/HashXMLCh.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/IllegalArgumentException.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/NoSuchElementException.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/NullPointerException.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/Platforms/Linux/LinuxDefs.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/QName.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefHashTableOf.c
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefHashTableOf.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefVectorOf.c
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefVectorOf.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RuntimeException.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ValueStackOf.c
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ValueStackOf.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ValueVectorOf.c
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ValueVectorOf.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XercesDefs.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XercesVersion.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLEnumerator.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLException.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLExceptMsgs.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLMsgLoader.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLString.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLUniDefs.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLUni.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/validators/DTD/DocTypeHandler.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/validators/DTD/DTDAttDef.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/validators/DTD/DTDElementDecl.hpp
InheritsElement.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/validators/DTD/DTDEntityDecl.hpp
InheritsExecutable.c.o: InheritsElement.h InheritsExecutable.h
InheritsExecutable.c.o: ../../skExecutableContext.h ../../skExecutable.h
InheritsExecutable.c.o: ../../skGeneral.h ../../skiExecutable.h
InheritsExecutable.c.o: ../../skString.h ../../skString.inl
InheritsExecutable.c.o: ../../skXMLElementObject.h ../../skXMLErrorHandler.h
InheritsExecutable.c.o: /usr/include/alloca.h /usr/include/assert.h
InheritsExecutable.c.o: /usr/include/bits/local_lim.h
InheritsExecutable.c.o: /usr/include/bits/posix1_lim.h
InheritsExecutable.c.o: /usr/include/bits/pthreadtypes.h
InheritsExecutable.c.o: /usr/include/bits/sched.h /usr/include/bits/sigset.h
InheritsExecutable.c.o: /usr/include/bits/time.h /usr/include/bits/types.h
InheritsExecutable.c.o: /usr/include/bits/waitstatus.h
InheritsExecutable.c.o: /usr/include/bits/xopen_lim.h /usr/include/ctype.h
InheritsExecutable.c.o: /usr/include/endian.h /usr/include/features.h
InheritsExecutable.c.o: /usr/include/g++-3/iostream.h
InheritsExecutable.c.o: /usr/include/g++-3/streambuf.h
InheritsExecutable.c.o: /usr/include/_G_config.h /usr/include/gconv.h
InheritsExecutable.c.o: /usr/include/libio.h /usr/include/limits.h
InheritsExecutable.c.o: /usr/include/stdlib.h /usr/include/string.h
InheritsExecutable.c.o: /usr/include/sys/select.h /usr/include/sys/types.h
InheritsExecutable.c.o: /usr/include/time.h /usr/include/wchar.h
InheritsExecutable.c.o: /usr/include/xlocale.h
InheritsExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/limits.h
InheritsExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stdarg.h
InheritsExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/stddef.h
InheritsExecutable.c.o: /usr/lib/gcc-lib/i386-redhat-linux/2.96/include/syslimits.h
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Attr.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_CDATASection.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_CharacterData.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Comment.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_DocumentFragment.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Document.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_DocumentType.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_DOMImplementation.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Element.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Entity.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_EntityReference.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_NodeFilter.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Node.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_NodeIterator.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_NodeList.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Notation.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOMParser.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_ProcessingInstruction.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Range.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOMString.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_Text.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_TreeWalker.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/dom/deprecated/DOM_XMLDecl.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/LocalFileInputSource.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLAttDef.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLAttDefList.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLAttr.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLContentModel.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLDocumentHandler.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLElementDecl.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLEntityDecl.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLEntityHandler.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLErrorReporter.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLFormatter.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/framework/XMLNotationDecl.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/sax/ErrorHandler.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/sax/InputSource.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ArrayIndexOutOfBoundsException.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/Compilers/GCCDefs.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/EmptyStackException.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/HashBase.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/HashXMLCh.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/IllegalArgumentException.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/NoSuchElementException.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/NullPointerException.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/Platforms/Linux/LinuxDefs.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/QName.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefHashTableOf.c
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefHashTableOf.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefVectorOf.c
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RefVectorOf.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/RuntimeException.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ValueStackOf.c
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ValueStackOf.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ValueVectorOf.c
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/ValueVectorOf.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XercesDefs.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XercesVersion.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLEnumerator.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLException.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLExceptMsgs.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLMsgLoader.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLString.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLUniDefs.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/util/XMLUni.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/validators/DTD/DocTypeHandler.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/validators/DTD/DTDAttDef.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/validators/DTD/DTDElementDecl.hpp
InheritsExecutable.c.o: /usr/share/xerces-c-src2_1_0/src/xercesc/validators/DTD/DTDEntityDecl.hpp
