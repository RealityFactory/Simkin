# Microsoft Developer Studio Project File - Name="Simkin_Expat_DLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Simkin_Expat_DLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Simkin_Expat_DLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Simkin_Expat_DLL.mak" CFG="Simkin_Expat_DLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Simkin_Expat_DLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Simkin_Expat_DLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Simkin_Expat_DLL - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Simkin_Expat_DLL___Win32_Release"
# PROP BASE Intermediate_Dir "Simkin_Expat_DLL___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Simkin_Expat_DLL___Win32_Release"
# PROP Intermediate_Dir "Simkin_Expat_DLL___Win32_Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SIMKIN_EXPAT_DLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "\source\expat-1.95.5\lib" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SIMKIN_EXPAT_DLL_EXPORTS" /D "ENABLE_WINDOWS_DLL_SUPPORT" /D "BUILDING_DLL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"Release/Simkin_Expat_DLL.dll"

!ELSEIF  "$(CFG)" == "Simkin_Expat_DLL - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Simkin_Expat_DLL___Win32_Debug"
# PROP BASE Intermediate_Dir "Simkin_Expat_DLL___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Simkin_Expat_DLL___Win32_Debug"
# PROP Intermediate_Dir "Simkin_Expat_DLL___Win32_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SIMKIN_EXPAT_DLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "\source\expat-1.95.5\lib" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "SIMKIN_EXPAT_DLL_EXPORTS" /D "ENABLE_WINDOWS_DLL_SUPPORT" /D "BUILDING_DLL" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"Debug/Simkin_Expat_DLL.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Simkin_Expat_DLL - Win32 Release"
# Name "Simkin_Expat_DLL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\skAlist.cpp
# End Source File
# Begin Source File

SOURCE=.\skCDataNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skElement.cpp
# End Source File
# Begin Source File

SOURCE=.\skElementExecutable.cpp
# End Source File
# Begin Source File

SOURCE=.\skElementObject.cpp
# End Source File
# Begin Source File

SOURCE=.\skElementObjectEnumerator.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutable.cpp
# End Source File
# Begin Source File

SOURCE=.\skExecutableIterator.cpp
# End Source File
# Begin Source File

SOURCE=.\skExpatParser.cpp
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

SOURCE=.\skNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skParser.cpp
# End Source File
# Begin Source File

SOURCE=.\skRValue.cpp
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

SOURCE=.\skTextNode.cpp
# End Source File
# Begin Source File

SOURCE=.\skTracer.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
