# Microsoft Developer Studio Project File - Name="NavDisplay_svnt DLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=NavDisplay_svnt DLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "NavDisplay_svnt.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "NavDisplay_svnt.mak" CFG="NavDisplay_svnt DLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NavDisplay_svnt DLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NavDisplay_svnt DLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NavDisplay_svnt DLL - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "."
# PROP Intermediate_Dir "Release\NavDisplay_svnt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GR /GX /Zi /O2 /I "..\..\..\..\..\orbsvcs\orbsvcs" /I "..\..\..\.." /I "..\..\..\..\ciao" /I "..\..\..\..\.." /I "..\..\..\..\..\tao" /I "..\..\..\..\..\.." /D NDEBUG=1 /D WIN32=1 /D _WINDOWS=1 /D NAVDISPLAY_SVNT_BUILD_DLL=1 /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "..\..\..\..\..\orbsvcs\orbsvcs" /i "..\..\..\.." /i "..\..\..\..\ciao" /i "..\..\..\..\.." /i "..\..\..\..\..\tao" /i "..\..\..\..\..\.." /d NDEBUG=1
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 advapi32.lib user32.lib NavDisplay_stub.lib HUDisplay_stub.lib HUDisplay_svnt.lib CIAO_Server.lib TAO_PortableServer.lib TAO_IORInterceptor.lib TAO_ObjRefTemplate.lib TAO_Security.lib CIAO_Container.lib TAO.lib TAO_IFR_Client.lib TAO_Valuetype.lib CIAO_Client.lib ACE.lib /nologo /subsystem:windows /dll /pdb:"..\..\..\..\..\..\bin\NavDisplay_svnt.pdb" /machine:I386 /out:"..\..\..\..\..\..\bin\NavDisplay_svnt.dll" /libpath:".." /libpath:"..\..\..\..\..\tao\PortableServer" /libpath:"..\..\..\..\..\tao\IORInterceptor" /libpath:"..\..\..\..\..\tao\ObjRefTemplate" /libpath:"..\..\..\..\..\orbsvcs\orbsvcs" /libpath:"..\..\..\..\..\tao\IFR_Client" /libpath:"..\..\..\..\..\tao\Valuetype" /libpath:"..\..\..\..\ciao" /libpath:"..\..\..\..\..\tao" /libpath:"..\..\..\..\..\..\ace" /version:1.3.1
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NavDisplay_svnt DLL - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "Debug\NavDisplay_svnt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /Gy /I "..\..\..\..\..\orbsvcs\orbsvcs" /I "..\..\..\.." /I "..\..\..\..\ciao" /I "..\..\..\..\.." /I "..\..\..\..\..\tao" /I "..\..\..\..\..\.." /D _DEBUG=1 /D WIN32=1 /D _WINDOWS=1 /D NAVDISPLAY_SVNT_BUILD_DLL=1 /FD /c
# SUBTRACT CPP /Fr /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "..\..\..\..\..\orbsvcs\orbsvcs" /i "..\..\..\.." /i "..\..\..\..\ciao" /i "..\..\..\..\.." /i "..\..\..\..\..\tao" /i "..\..\..\..\..\.." /d _DEBUG=1
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 advapi32.lib user32.lib NavDisplay_stubd.lib HUDisplay_stubd.lib HUDisplay_svntd.lib CIAO_Serverd.lib TAO_PortableServerd.lib TAO_IORInterceptord.lib TAO_ObjRefTemplated.lib TAO_Securityd.lib CIAO_Containerd.lib TAOd.lib TAO_IFR_Clientd.lib TAO_Valuetyped.lib CIAO_Clientd.lib ACEd.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"..\..\..\..\..\..\bin\NavDisplay_svntd.pdb" /debug /machine:I386 /out:"..\..\..\..\..\..\bin\NavDisplay_svntd.dll" /libpath:".." /libpath:"..\..\..\..\..\tao\PortableServer" /libpath:"..\..\..\..\..\tao\IORInterceptor" /libpath:"..\..\..\..\..\tao\ObjRefTemplate" /libpath:"..\..\..\..\..\orbsvcs\orbsvcs" /libpath:"..\..\..\..\..\tao\IFR_Client" /libpath:"..\..\..\..\..\tao\Valuetype" /libpath:"..\..\..\..\ciao" /libpath:"..\..\..\..\..\tao" /libpath:"..\..\..\..\..\..\ace" /version:1.3.1
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "NavDisplay_svnt DLL - Win32 Release"
# Name "NavDisplay_svnt DLL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE=.\NavDisplay_svnt.cpp
# End Source File
# Begin Source File

SOURCE=.\NavDisplayEC.cpp
# End Source File
# Begin Source File

SOURCE=.\NavDisplayS.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE=.\NavDisplay_svnt.h
# End Source File
# Begin Source File

SOURCE=.\NavDisplayEC.h
# End Source File
# Begin Source File

SOURCE=.\NavDisplayS.h
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "i;inl"
# Begin Source File

SOURCE=.\NavDisplayEC.i
# End Source File
# Begin Source File

SOURCE=.\NavDisplayS.i
# End Source File
# End Group
# Begin Group "IDL Files"

# PROP Default_Filter "idl"
# Begin Source File

SOURCE=.\NavDisplay.cidl

!IF  "$(CFG)" == "NavDisplay_svnt DLL - Win32 Release"

!ELSEIF  "$(CFG)" == "NavDisplay_svnt DLL - Win32 Debug"

USERDEP__NAVDI="..\..\..\..\..\..\bin\cidlc.exe"	
# Begin Custom Build - Invoking CIAO CIDL Compiler on $(InputPath)
InputPath=.\NavDisplay.cidl
InputName=NavDisplay

BuildCmds= \
	..\..\..\..\..\..\bin\cidlc --lem-file-suffix "E.idl" -- $(InputName).cidl

"$(InputName)E.idl" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputName)_svnt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputName)_svnt.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NavDisplayE.idl

!IF  "$(CFG)" == "NavDisplay_svnt DLL - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Invoking IDL Compiler on $(InputPath)
InputPath=.\NavDisplayE.idl
InputName=NavDisplayE

BuildCmds= \
	..\..\..\..\..\..\bin\tao_idl -o . -Wb,export_macro=NAVDISPLAY_SVNT_Export -Wb,export_include=NavDisplay_svnt_export.h -I..\..\..\..\.. -I..\..\..\..\..\CIAO\ciao -Wb,pre_include="ace\pre.h" -Wb,post_include="ace\post.h" -I ..\..\..\.. -I ..\..\..\..\.. -I ..\..\..\..\..\orbsvcs\orbsvcs -Ge 1 -Sc $(InputPath)

".\$(InputName)C.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "NavDisplay_svnt DLL - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Invoking IDL Compiler on $(InputPath)
InputPath=.\NavDisplayE.idl
InputName=NavDisplayE

BuildCmds= \
	..\..\..\..\..\..\bin\tao_idl -o . -Wb,export_macro=NAVDISPLAY_SVNT_Export -Wb,export_include=NavDisplay_svnt_export.h -I..\..\..\..\.. -I..\..\..\..\..\CIAO\ciao -Wb,pre_include="ace\pre.h" -Wb,post_include="ace\post.h" -I ..\..\..\.. -I ..\..\..\..\.. -I ..\..\..\..\..\orbsvcs\orbsvcs -Ge 1 -Sc $(InputPath)

".\$(InputName)C.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
