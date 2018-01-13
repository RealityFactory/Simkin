# Microsoft Developer Studio Project File - Name="Simkin" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Simkin - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Simkin.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Simkin.mak" CFG="Simkin - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Simkin - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Simkin - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Simkin - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MD /W3 /O1 /Ob2 /I "f:\source\xerces-c1_3_0-win32\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x809
# ADD RSC /l 0x809
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Simkin - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /I "f:\source\xerces-c-src1_3_0\src" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "PLATFORM_WIN32" /YX /FD /c
# ADD BASE RSC /l 0x809
# ADD RSC /l 0x809
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "Simkin - Win32 Release"
# Name "Simkin - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\skAlist.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutable.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutableIterator.cpp
# End Source File
# Begin Source File

SOURCE=.\skHashTable.cpp
# End Source File
# Begin Source File

SOURCE=.\skInterpreter.cpp
# End Source File
# Begin Source File

SOURCE=.\skLang_tab.cpp
# End Source File
# Begin Source File

SOURCE=.\skParser.cpp
# End Source File
# Begin Source File

SOURCE=.\skRValue.cpp
# End Source File
# Begin Source File

SOURCE=.\skScriptedExecutable.cpp
# End Source File
# Begin Source File

SOURCE=.\skString.cpp
# End Source File
# Begin Source File

SOURCE=.\skStringTokenizer.cpp
# End Source File
# Begin Source File

SOURCE=.\skTracer.cpp
# End Source File
# Begin Source File

SOURCE=.\skTreeNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skTreeNodeObject.cpp
# End Source File
# Begin Source File

SOURCE=.\skTreeNodeObjectEnumerator.cpp
# End Source File
# Begin Source File

SOURCE=.\skXMLElementObject.cpp
# End Source File
# Begin Source File

SOURCE=.\skXMLElementObjectEnumerator.cpp
# End Source File
# Begin Source File

SOURCE=.\skXMLErrorHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\skXMLExecutable.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\skAlist.h
# End Source File
# Begin Source File

SOURCE=.\skAlist.inl
# End Source File
# Begin Source File

SOURCE=.\skExecutable.h
# End Source File
# Begin Source File

SOURCE=.\skGeneral.h
# End Source File
# Begin Source File

SOURCE=.\skHashTable.h
# End Source File
# Begin Source File

SOURCE=.\skHashTable.inl
# End Source File
# Begin Source File

SOURCE=.\skInterpreter.h
# End Source File
# Begin Source File

SOURCE=.\skInterpreterp.h
# End Source File
# Begin Source File

SOURCE=.\skLang_tab.h
# End Source File
# Begin Source File

SOURCE=.\skList.h
# End Source File
# Begin Source File

SOURCE=.\skList.inl
# End Source File
# Begin Source File

SOURCE=.\skosfcn.h
# End Source File
# Begin Source File

SOURCE=.\skRValue.h
# End Source File
# Begin Source File

SOURCE=.\skRValueArray.h
# End Source File
# Begin Source File

SOURCE=.\skScriptedExecutable.h
# End Source File
# Begin Source File

SOURCE=.\skString.h
# End Source File
# Begin Source File

SOURCE=.\skString.inl
# End Source File
# Begin Source File

SOURCE=.\skTreeNode.h
# End Source File
# Begin Source File

SOURCE=.\skTreeNodeObject.h
# End Source File
# Begin Source File

SOURCE=.\skTreeNodp.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
