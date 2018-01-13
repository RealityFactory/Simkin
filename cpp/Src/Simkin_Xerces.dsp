# Microsoft Developer Studio Project File - Name="Simkin_Xerces" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Simkin_Xerces - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Simkin_Xerces.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Simkin_Xerces.mak" CFG="Simkin_Xerces - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Simkin_Xerces - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Simkin_Xerces - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Simkin_Xerces - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Simkin_Xerces_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Simkin_Xerces_Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "f:\source\xerces-c-src2_1_0\src" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Simkin_Xerces - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Simkin_Xerces_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Simkin_Xerces_Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "f:\source\xerces-c-src2_1_0\src" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
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

# Name "Simkin_Xerces - Win32 Release"
# Name "Simkin_Xerces - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\skAlist.cpp
# End Source File
# Begin Source File

SOURCE=.\skConstants.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutable.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutableContext.cpp
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

SOURCE=.\skInterpreterByte.cpp
# End Source File
# Begin Source File

SOURCE=.\skInterpreterNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skParseNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skParser.cpp

!IF  "$(CFG)" == "Simkin_Xerces - Win32 Release"

# ADD CPP /Od

!ELSEIF  "$(CFG)" == "Simkin_Xerces - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\skRValue.cpp
# End Source File
# Begin Source File

SOURCE=.\skSHashTable.cpp
# End Source File
# Begin Source File

SOURCE=.\skStackFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\skString.cpp
# End Source File
# Begin Source File

SOURCE=.\skStringBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\skStringTokenizer.cpp
# End Source File
# Begin Source File

SOURCE=.\skTracer.cpp
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

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
