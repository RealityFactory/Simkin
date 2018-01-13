# Microsoft Developer Studio Project File - Name="Simkin_TreeNode" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Simkin_TreeNode - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Simkin_TreeNode.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Simkin_TreeNode.mak" CFG="Simkin_TreeNode - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Simkin_TreeNode - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Simkin_TreeNode - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Simkin_TreeNode - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Simkin_TreeNode_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Simkin_TreeNode_Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "\source\simkin\cpp\src" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Simkin_TreeNode - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Simkin_TreeNode_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Simkin_TreeNode_Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "Simkin_TreeNode - Win32 Release"
# Name "Simkin_TreeNode - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=skAlist.cpp
# End Source File
# Begin Source File

SOURCE=.\skAlist.h
# End Source File
# Begin Source File

SOURCE=.\skAlist.inl
# End Source File
# Begin Source File

SOURCE=.\skBoundsException.h
# End Source File
# Begin Source File

SOURCE=.\skConstants.cpp
# End Source File
# Begin Source File

SOURCE=.\skConstants.h
# End Source File
# Begin Source File

SOURCE=.\skException.h
# End Source File
# Begin Source File

SOURCE=skExecutable.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutable.h
# End Source File
# Begin Source File

SOURCE=.\skExecutableContext.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutableContext.h
# End Source File
# Begin Source File

SOURCE=skExecutableIterator.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutableIterator.h
# End Source File
# Begin Source File

SOURCE=.\skGeneral.h
# End Source File
# Begin Source File

SOURCE=skHashTable.cpp
# End Source File
# Begin Source File

SOURCE=.\skHashTable.h
# End Source File
# Begin Source File

SOURCE=.\skHashTable.inl
# End Source File
# Begin Source File

SOURCE=.\skiExecutable.h
# End Source File
# Begin Source File

SOURCE=.\skInputSource.cpp
# End Source File
# Begin Source File

SOURCE=.\skInputSource.h
# End Source File
# Begin Source File

SOURCE=skInterpreter.cpp
# End Source File
# Begin Source File

SOURCE=.\skInterpreter.h
# End Source File
# Begin Source File

SOURCE=.\skInterpreterByte.cpp
# End Source File
# Begin Source File

SOURCE=.\skInterpreterNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skInterpreterp.h
# End Source File
# Begin Source File

SOURCE=.\skLang_tab.h
# End Source File
# Begin Source File

SOURCE=.\skMethodTable.h
# End Source File
# Begin Source File

SOURCE=.\skNull.h
# End Source File
# Begin Source File

SOURCE=.\skOutputDestination.cpp
# End Source File
# Begin Source File

SOURCE=.\skOutputDestination.h
# End Source File
# Begin Source File

SOURCE=.\skParseException.h
# End Source File
# Begin Source File

SOURCE=.\skParseNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skParseNode.h
# End Source File
# Begin Source File

SOURCE=skParser.cpp

!IF  "$(CFG)" == "Simkin_TreeNode - Win32 Release"

# ADD CPP /O1

!ELSEIF  "$(CFG)" == "Simkin_TreeNode - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\skParser.h
# End Source File
# Begin Source File

SOURCE=.\skRuntimeException.h
# End Source File
# Begin Source File

SOURCE=skRValue.cpp
# End Source File
# Begin Source File

SOURCE=.\skRValue.h
# End Source File
# Begin Source File

SOURCE=.\skRValue.inl
# End Source File
# Begin Source File

SOURCE=.\skRValueArray.h
# End Source File
# Begin Source File

SOURCE=.\skRValueTable.h
# End Source File
# Begin Source File

SOURCE=skScriptedExecutable.cpp
# End Source File
# Begin Source File

SOURCE=.\skScriptedExecutable.h
# End Source File
# Begin Source File

SOURCE=.\skScriptError.h
# End Source File
# Begin Source File

SOURCE=.\skSHashTable.cpp
# End Source File
# Begin Source File

SOURCE=.\skSHashTable.h
# End Source File
# Begin Source File

SOURCE=.\skSHashTable.inl
# End Source File
# Begin Source File

SOURCE=.\skStackFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\skStackFrame.h
# End Source File
# Begin Source File

SOURCE=.\skStatementStepper.h
# End Source File
# Begin Source File

SOURCE=skString.cpp
# End Source File
# Begin Source File

SOURCE=.\skString.h
# End Source File
# Begin Source File

SOURCE=.\skString.inl
# End Source File
# Begin Source File

SOURCE=.\skStringBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\skStringBuffer.h
# End Source File
# Begin Source File

SOURCE=.\skStringList.h
# End Source File
# Begin Source File

SOURCE=skStringTokenizer.cpp
# End Source File
# Begin Source File

SOURCE=.\skStringTokenizer.h
# End Source File
# Begin Source File

SOURCE=.\skTraceCallback.h
# End Source File
# Begin Source File

SOURCE=skTracer.cpp
# End Source File
# Begin Source File

SOURCE=.\skTracer.h
# End Source File
# Begin Source File

SOURCE=skTreeNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skTreeNode.h
# End Source File
# Begin Source File

SOURCE=skTreeNodeObject.cpp
# End Source File
# Begin Source File

SOURCE=.\skTreeNodeObject.h
# End Source File
# Begin Source File

SOURCE=skTreeNodeObjectEnumerator.cpp
# End Source File
# Begin Source File

SOURCE=.\skTreeNodeObjectEnumerator.h
# End Source File
# Begin Source File

SOURCE=.\skTreeNodp.h
# End Source File
# Begin Source File

SOURCE=.\skValist.h
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
