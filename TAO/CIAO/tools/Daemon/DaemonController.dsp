# Microsoft Developer Studio Project File - Name="DaemonController EXE" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=DaemonController EXE - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DaemonController.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DaemonController.mak" CFG="DaemonController EXE - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DaemonController EXE - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "DaemonController EXE - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DaemonController EXE - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\.." /I "..\..\.." /I "..\..\ciao" /I "..\..\..\orbsvcs\orbsvcs" /D NDEBUG=1 /D WIN32=1 /D _CONSOLE=1 /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "..\..\..\..\orbsvcs\orbsvcs" /i "..\..\..\..\CIAO" /i "..\..\..\..\CIAO\ciao" /i "..\..\..\.." /i "..\..\..\..\tao" /i "..\..\..\..\.." /d NDEBUG=1
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 advapi32.lib user32.lib CIAO_Server.lib TAO_PortableServer.lib TAO_Security.lib CIAO_Container.lib TAO.lib TAO_IFR_Client.lib CIAO_Client.lib ACE.lib ACEXML.lib ACEXML_Parser.lib /nologo /version:1.3 /subsystem:console /machine:I386 /out:"DaemonController.exe" /libpath:"..\..\..\..\ace" /libpath:"..\..\..\tao" /libpath:"..\..\..\tao\PortableServer" /libpath:"..\..\..\tao\IFR_Client" /libpath:"..\..\ciao" /libpath:"..\..\..\orbsvcs\orbsvcs" /libpath:"..\..\..\..\ACEXML\Common" /libpath:"..\..\..\..\ACEXML\parser\parser"

!ELSEIF  "$(CFG)" == "DaemonController EXE - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /Gy /I "..\..\..\.." /I "..\..\.." /I "..\..\ciao" /I "..\..\..\orbsvcs\orbsvcs" /D _DEBUG=1 /D WIN32=1 /D _CONSOLE=1 /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "..\..\..\..\orbsvcs\orbsvcs" /i "..\..\..\..\CIAO" /i "..\..\..\..\CIAO\ciao" /i "..\..\..\.." /i "..\..\..\..\tao" /i "..\..\..\..\.." /d _DEBUG=1
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 advapi32.lib user32.lib CIAO_Serverd.lib TAO_PortableServerd.lib TAO_Securityd.lib CIAO_Containerd.lib TAOd.lib TAO_IFR_Clientd.lib CIAO_Clientd.lib ACEd.lib ACEXMLd.lib ACEXML_Parserd.lib /nologo /version:1.3 /subsystem:console /incremental:no /debug /machine:I386 /libpath:"..\..\..\..\ace" /libpath:"..\..\..\tao" /libpath:"..\..\..\tao\PortableServer" /libpath:"..\..\..\tao\IFR_Client" /libpath:"..\..\ciao" /libpath:"..\..\..\orbsvcs\orbsvcs" /libpath:"..\..\..\..\ACEXML\Common" /libpath:"..\..\..\..\ACEXML\parser\parser"

!ENDIF 

# Begin Target

# Name "DaemonController EXE - Win32 Release"
# Name "DaemonController EXE - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE=..\XML_Helpers\Assembly_Handlers.cpp
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\Assembly_Spec.cpp
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\Cascadable_DocHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\controller_i.cpp
# End Source File
# Begin Source File

SOURCE=.\Daemon_Commands.cpp
# End Source File
# Begin Source File

SOURCE=.\DaemonC.cpp
# End Source File
# Begin Source File

SOURCE=.\DaemonController.cpp
# End Source File
# Begin Source File

SOURCE=.\Softpkg_Commands.cpp
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\Softpkg_Handlers.cpp
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\XML_Utils.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE=..\XML_Helpers\Assembly_Handlers.h
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\Assembly_Spec.h
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\Cascadable_DocHandler.h
# End Source File
# Begin Source File

SOURCE=.\controller_i.h
# End Source File
# Begin Source File

SOURCE=.\Daemon_Commands.h
# End Source File
# Begin Source File

SOURCE=.\Softpkg_Commands.h
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\Softpkg_Handlers.h
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\XML_Utils.h
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "i;inl"
# Begin Source File

SOURCE=..\XML_Helpers\Assembly_Handlers.inl
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\Assembly_Spec.inl
# End Source File
# Begin Source File

SOURCE=.\controller_i.inl
# End Source File
# Begin Source File

SOURCE=.\Daemon_Commands.inl
# End Source File
# Begin Source File

SOURCE=.\DaemonC.i
# End Source File
# Begin Source File

SOURCE=.\Softpkg_Commands.inl
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\Softpkg_Handlers.inl
# End Source File
# Begin Source File

SOURCE=..\XML_Helpers\XML_Utils.inl
# End Source File
# End Group
# Begin Group "IDL FIles"

# PROP Default_Filter "idl"
# Begin Source File

SOURCE=.\Daemon.idl

!IF  "$(CFG)" == "DaemonController EXE - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Invoking TAO_IDL Compiler on $(InputPath)
OutDir=.\Release
InputPath=.\Daemon.idl
InputName=Daemon

BuildCmds= \
	..\..\..\..\bin\tao_idl -o $(OutDir) -I..\..\.. -I..\..\..\CIAO\ciao -Wb,pre_include="ace\pre.h" -Wb,post_include="ace\post.h" -I ..\.. -I ..\..\.. -I ..\..\..\orbsvcs\orbsvcs -Ge 1 -Sc $(InputPath)

"$(OutDir)\$(InputName)C.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)C.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)C.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)S.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)S.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)S.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "DaemonController EXE - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Invoking TAO_IDL Compiler on $(InputPath)
OutDir=.
InputPath=.\Daemon.idl
InputName=Daemon

BuildCmds= \
	..\..\..\..\bin\tao_idl -o $(OutDir) -I..\..\.. -I..\..\..\CIAO\ciao -Wb,pre_include="ace\pre.h" -Wb,post_include="ace\post.h" -I ..\.. -I ..\..\.. -I ..\..\..\orbsvcs\orbsvcs -Ge 1 -Sc $(InputPath)

"$(OutDir)\$(InputName)C.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)C.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)C.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)S.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)S.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(InputName)S.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
