# Microsoft Developer Studio Project File - Name="TAO_IDL Compiler" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=TAO_IDL Compiler - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "tao_idl.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tao_idl.mak" CFG="TAO_IDL Compiler - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TAO_IDL Compiler - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "TAO_IDL Compiler - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TAO_IDL Compiler - Win32 Release"

# PROP Ignore_Export_Lib 0
BSC32=bscmake.exe
LINK32=link.exe

!ELSEIF  "$(CFG)" == "TAO_IDL Compiler - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_DEBUG" /YX /FD  /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "include" /I "be_include" /I "../../" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_DEBUG" /YX /FD  /c
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_DEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 TAO_IDL_BE_DLLd.lib TAO_IDL_FE_DLLd.lib aced.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\ace"

!ENDIF 

# Begin Target

# Name "TAO_IDL Compiler - Win32 Release"
# Name "TAO_IDL Compiler - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\driver\drv_args.cpp

!IF  "$(CFG)" == "TAO_IDL Compiler - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO_IDL Compiler - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\driver\drv_init.cpp

!IF  "$(CFG)" == "TAO_IDL Compiler - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO_IDL Compiler - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\driver\drv_preproc.cpp

!IF  "$(CFG)" == "TAO_IDL Compiler - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO_IDL Compiler - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\driver\drv_private.cpp

!IF  "$(CFG)" == "TAO_IDL Compiler - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO_IDL Compiler - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\tao_idl.cpp

!IF  "$(CFG)" == "TAO_IDL Compiler - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO_IDL Compiler - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\include\drv_extern.h
# End Source File
# Begin Source File

SOURCE=.\include\drv_private.h
# End Source File
# End Group
# End Target
# End Project
