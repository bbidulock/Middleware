# Microsoft Developer Studio Project File - Name="ACEXML_XML_Svc_Conf_Parser DLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ACEXML_XML_Svc_Conf_Parser DLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE run the tool that generated this project file and specify the
!MESSAGE nmake output type.  You can then use the following command:
!MESSAGE
!MESSAGE NMAKE /f "ACEXML_XML_Svc_Conf_Parser.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "ACEXML_XML_Svc_Conf_Parser.mak" CFG="ACEXML_XML_Svc_Conf_Parser DLL - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "ACEXML_XML_Svc_Conf_Parser DLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ACEXML_XML_Svc_Conf_Parser DLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ACEXML_XML_Svc_Conf_Parser DLL - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "."
# PROP Intermediate_Dir "Release\ACEXML_XML_Svc_Conf_Parser"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /W3 /GX /O2 /MD /Zi /GR /I "..\..\.." /D NDEBUG=1 /D WIN32=1 /D _WINDOWS=1 /FD /c
# SUBTRACT CPP /YX
# ADD RSC /l 0x409 /d NDEBUG=1 /i "..\..\.."
BSC32=bscmake.exe
# ADD BSC32 /nologo /o".\ACEXML_XML_Svc_Conf_Parser.bsc"
LINK32=link.exe
# ADD LINK32 advapi32.lib user32.lib /INCREMENTAL:NO ACEXML_Parser.lib ACEXML.lib ACE.lib /libpath:"..\..\..\ACEXML\common" /libpath:"..\..\..\ACEXML\parser\parser" /libpath:"..\..\..\ace" /nologo /version:5.3.1 /subsystem:windows /pdb:"..\..\..\bin\ACEXML_XML_Svc_Conf_Parser.pdb" /dll  /machine:I386 /out:"..\..\..\bin\ACEXML_XML_Svc_Conf_Parser.dll"

!ELSEIF  "$(CFG)" == "ACEXML_XML_Svc_Conf_Parser DLL - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "Debug\ACEXML_XML_Svc_Conf_Parser"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /MDd /GR /Gy /I "..\..\.." /D _DEBUG=1 /D WIN32=1 /D _WINDOWS=1 /FD /c
# SUBTRACT CPP /Fr /YX
# ADD RSC /l 0x409 /d _DEBUG=1 /i "..\..\.."
BSC32=bscmake.exe
# ADD BSC32 /nologo /o".\ACEXML_XML_Svc_Conf_Parser.bsc"
LINK32=link.exe
# ADD LINK32 advapi32.lib user32.lib /INCREMENTAL:NO ACEXML_Parserd.lib ACEXMLd.lib ACEd.lib /libpath:"..\..\..\ACEXML\common" /libpath:"..\..\..\ACEXML\parser\parser" /libpath:"..\..\..\ace" /nologo /version:5.3.1 /subsystem:windows /pdb:"..\..\..\bin\ACEXML_XML_Svc_Conf_Parserd.pdb" /dll /debug /machine:I386 /out:"..\..\..\bin\ACEXML_XML_Svc_Conf_Parserd.dll"

!ENDIF

# Begin Target

# Name "ACEXML_XML_Svc_Conf_Parser DLL - Win32 Release"
# Name "ACEXML_XML_Svc_Conf_Parser DLL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE=.\Svcconf.cpp
# End Source File
# Begin Source File

SOURCE=.\Svcconf_Handler.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE=.\Svcconf.h
# End Source File
# Begin Source File

SOURCE=.\Svcconf_Handler.h
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "i;inl"
# Begin Source File

SOURCE=.\Svcconf_Handler.i
# End Source File
# End Group
# Begin Group "Documentation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\README
# End Source File
# End Group
# End Target
# End Project
