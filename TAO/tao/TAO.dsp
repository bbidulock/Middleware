# Microsoft Developer Studio Project File - Name="TAO" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (ALPHA) Dynamic-Link Library" 0x0602

CFG=TAO - Win32 Alpha Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TAO.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TAO.mak" CFG="TAO - Win32 Alpha Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TAO - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TAO - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TAO - Win32 Alpha Debug" (based on\
 "Win32 (ALPHA) Dynamic-Link Library")
!MESSAGE "TAO - Win32 Alpha Release" (based on\
 "Win32 (ALPHA) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "TAO - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\\" /I "..\\" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "TAO_BUILD_DLL" /FD /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 ace.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\..\bin\TAO.dll" /libpath:"..\..\ace"
# SUBTRACT LINK32 /incremental:yes

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /Gy /I "..\..\\" /I "..\\" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "TAO_BUILD_DLL" /FD /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 aced.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"..\..\bin\TAOd.dll" /libpath:"..\..\ace"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "TAO___Wi"
# PROP BASE Intermediate_Dir "TAO___Wi"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /Zi /Od /I "..\..\\ /I" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "TAO_BUILD_DLL" /FD /MTd ..\\ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /Gt0 /W3 /GX /Zi /Od /I "..\..\\ /I" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "TAO_BUILD_DLL" /FD /MDd ..\\ /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 aced.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:ALPHA /out:"TAOd.dll" /libpath:"..\..\ace"
# ADD LINK32 aced.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:ALPHA /out:"TAOd.dll" /libpath:"..\..\ace"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "TAO___W0"
# PROP BASE Intermediate_Dir "TAO___W0"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
CPP=cl.exe
# ADD BASE CPP /nologo /MT /Gt0 /W3 /GX /O2 /I "..\..\\ /I" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "TAO_BUILD_DLL" /FD ..\\ /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /Gt0 /W3 /GX /O2 /I "..\..\\ /I" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "TAO_BUILD_DLL" /FD ..\\ /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ace.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:ALPHA /libpath:"..\..\ace"
# ADD LINK32 ace.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:ALPHA /libpath:"..\..\ace"

!ENDIF 

# Begin Target

# Name "TAO - Win32 Release"
# Name "TAO - Win32 Debug"
# Name "TAO - Win32 Alpha Debug"
# Name "TAO - Win32 Alpha Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Any.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_ANY_C=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_ANY_C=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\append.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_APPEN=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_APPEN=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CDR.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_CDR_C=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_CDR_C=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Client_Strategy_Factory.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_CLIEN=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_CLIEN=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Connect.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_CONNE=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\Timeprobe.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_CONNE=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CurrentC.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_CURRE=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_CURRE=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CurrentS.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_CURREN=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_CURREN=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\debug.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_DEBUG=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_DEBUG=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\decode.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_DECOD=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_DECOD=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\deep_free.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_DEEP_=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_DEEP_=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\default_client.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_DEFAU=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_DEFAU=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\default_server.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_DEFAUL=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_DEFAUL=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DynAny_i.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DynAnyC.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DynAnyS.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DynArray_i.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DynEnum_i.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DynSequence_i.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DynStruct_i.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DynUnion_i.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\encode.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_ENCOD=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_ENCOD=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Environment.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_ENVIR=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_ENVIR=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Exception.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_EXCEP=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_EXCEP=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Forwarding_Servant.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_FORWA=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\Forwarding_Servant.h"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_FORWA=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\GIOP.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_GIOP_=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\Timeprobe.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_GIOP_=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\IIOP_Interpreter.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_IIOP_=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_IIOP_=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\IIOP_Object.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_IIOP_O=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\Timeprobe.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_IIOP_O=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\IIOP_ORB.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_IIOP_OR=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_IIOP_OR=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\InconsistentTypeCodeC.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Invocation.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_INVOC=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\Timeprobe.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_INVOC=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Marshal.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_MARSH=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_MARSH=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NVList.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_NVLIS=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_NVLIS=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Object.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_OBJEC=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_OBJEC=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Object_KeyC.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_OBJECT=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_OBJECT=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Object_Table.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_OBJECT_=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_OBJECT_=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Operation_Table.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_OPERA=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_OPERA=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ORB.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_ORB_C=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_Dgram.h"\
	"..\..\ace\SOCK_Dgram.i"\
	"..\..\ace\SOCK_Dgram_Mcast.h"\
	"..\..\ace\SOCK_Dgram_Mcast.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\TAO_Internal.h"\
	".\Timeprobe.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_ORB_C=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ORB_Core.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_ORB_CO=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Arg_Shifter.h"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Env_Value_T.cpp"\
	"..\..\ace\Env_Value_T.h"\
	"..\..\ace\Env_Value_T.i"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Local_Tokens.h"\
	"..\..\ace\Local_Tokens.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Pipe.h"\
	"..\..\ace\Pipe.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Select_Reactor.h"\
	"..\..\ace\Select_Reactor.i"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Token.h"\
	"..\..\ace\Token.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\TAO_Internal.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_ORB_CO=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\params.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_PARAM=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_PARAM=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\POA.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_POA_C=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\Forwarding_Servant.h"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\Timeprobe.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_POA_C=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\POAC.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_POAC_=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_POAC_=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\POAS.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_POAS_=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_POAS_=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\PolicyC.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_POLIC=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_POLIC=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\PolicyS.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_POLICY=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_POLICY=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Principal.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_PRINC=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_PRINC=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Request.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_REQUE=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_REQUE=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Sequence.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_SEQUE=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_SEQUE=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Servant_Base.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_SERVA=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\Timeprobe.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_SERVA=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Server_Request.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_SERVE=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\High_Res_Timer.h"\
	"..\..\ace\High_Res_Timer.i"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timeprobe.h"\
	"..\..\ace\Timeprobe.i"\
	"..\..\ace\Timeprobe_T.cpp"\
	"..\..\ace\Timeprobe_T.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\Timeprobe.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_SERVE=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Server_Strategy_Factory.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_SERVER=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_SERVER=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\skip.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_SKIP_=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_SKIP_=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Stub.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_STUB_=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_STUB_=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TAO.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_TAO_C=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\TAO.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_TAO_C=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TAO_Internal.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_TAO_I=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\TAO_Internal.h"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_TAO_I=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Typecode.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_TYPEC=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_TYPEC=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Typecode_Constants.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_TYPECO=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_TYPECO=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Union.cpp

!IF  "$(CFG)" == "TAO - Win32 Release"

!ELSEIF  "$(CFG)" == "TAO - Win32 Debug"

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Debug"

DEP_CPP_UNION=\
	"..\..\ace\Acceptor.cpp"\
	"..\..\ace\Acceptor.h"\
	"..\..\ace\Acceptor.i"\
	"..\..\ace\ACE.h"\
	"..\..\ace\ACE.i"\
	"..\..\ace\Addr.h"\
	"..\..\ace\Addr.i"\
	"..\..\ace\Atomic_Op.i"\
	"..\..\ace\Auto_Ptr.cpp"\
	"..\..\ace\Auto_Ptr.h"\
	"..\..\ace\Auto_Ptr.i"\
	"..\..\ace\Basic_Types.h"\
	"..\..\ace\Basic_Types.i"\
	"..\..\ace\config-win32-borland.h"\
	"..\..\ace\config-win32-common.h"\
	"..\..\ace\config-win32.h"\
	"..\..\ace\config-WinCE.h"\
	"..\..\ace\config.h"\
	"..\..\ace\Connector.cpp"\
	"..\..\ace\Connector.h"\
	"..\..\ace\Connector.i"\
	"..\..\ace\Containers.cpp"\
	"..\..\ace\Containers.h"\
	"..\..\ace\Containers.i"\
	"..\..\ace\Dynamic.h"\
	"..\..\ace\Dynamic.i"\
	"..\..\ace\Dynamic_Service.cpp"\
	"..\..\ace\Dynamic_Service.h"\
	"..\..\ace\Event_Handler.h"\
	"..\..\ace\Event_Handler.i"\
	"..\..\ace\Free_List.cpp"\
	"..\..\ace\Free_List.h"\
	"..\..\ace\Free_List.i"\
	"..\..\ace\Get_Opt.h"\
	"..\..\ace\Get_Opt.i"\
	"..\..\ace\Handle_Set.h"\
	"..\..\ace\Handle_Set.i"\
	"..\..\ace\Hash_Map_Manager.cpp"\
	"..\..\ace\Hash_Map_Manager.h"\
	"..\..\ace\inc_user_config.h"\
	"..\..\ace\INET_Addr.h"\
	"..\..\ace\INET_Addr.i"\
	"..\..\ace\IO_Cntl_Msg.h"\
	"..\..\ace\iosfwd.h"\
	"..\..\ace\IPC_SAP.h"\
	"..\..\ace\IPC_SAP.i"\
	"..\..\ace\Log_Msg.h"\
	"..\..\ace\Log_Priority.h"\
	"..\..\ace\Log_Record.h"\
	"..\..\ace\Log_Record.i"\
	"..\..\ace\Malloc.h"\
	"..\..\ace\Malloc.i"\
	"..\..\ace\Malloc_Base.h"\
	"..\..\ace\Malloc_T.cpp"\
	"..\..\ace\Malloc_T.h"\
	"..\..\ace\Malloc_T.i"\
	"..\..\ace\Managed_Object.cpp"\
	"..\..\ace\Managed_Object.h"\
	"..\..\ace\Managed_Object.i"\
	"..\..\ace\Map_Manager.cpp"\
	"..\..\ace\Map_Manager.h"\
	"..\..\ace\Map_Manager.i"\
	"..\..\ace\Mem_Map.h"\
	"..\..\ace\Mem_Map.i"\
	"..\..\ace\Memory_Pool.h"\
	"..\..\ace\Memory_Pool.i"\
	"..\..\ace\Message_Block.h"\
	"..\..\ace\Message_Block.i"\
	"..\..\ace\Message_Queue.h"\
	"..\..\ace\Message_Queue.i"\
	"..\..\ace\Message_Queue_T.cpp"\
	"..\..\ace\Message_Queue_T.h"\
	"..\..\ace\Message_Queue_T.i"\
	"..\..\ace\Module.cpp"\
	"..\..\ace\Module.h"\
	"..\..\ace\Module.i"\
	"..\..\ace\Object_Manager.h"\
	"..\..\ace\Object_Manager.i"\
	"..\..\ace\OS.h"\
	"..\..\ace\OS.i"\
	"..\..\ace\Reactor.h"\
	"..\..\ace\Reactor.i"\
	"..\..\ace\Reactor_Impl.h"\
	"..\..\ace\Service_Config.h"\
	"..\..\ace\Service_Config.i"\
	"..\..\ace\Service_Object.h"\
	"..\..\ace\Service_Object.i"\
	"..\..\ace\Service_Repository.h"\
	"..\..\ace\Service_Repository.i"\
	"..\..\ace\Service_Types.h"\
	"..\..\ace\Service_Types.i"\
	"..\..\ace\Shared_Object.h"\
	"..\..\ace\Shared_Object.i"\
	"..\..\ace\Signal.h"\
	"..\..\ace\Signal.i"\
	"..\..\ace\Singleton.cpp"\
	"..\..\ace\Singleton.h"\
	"..\..\ace\Singleton.i"\
	"..\..\ace\SOCK.h"\
	"..\..\ace\SOCK.i"\
	"..\..\ace\SOCK_Acceptor.h"\
	"..\..\ace\SOCK_Acceptor.i"\
	"..\..\ace\SOCK_Connector.h"\
	"..\..\ace\SOCK_Connector.i"\
	"..\..\ace\SOCK_IO.h"\
	"..\..\ace\SOCK_IO.i"\
	"..\..\ace\SOCK_Stream.h"\
	"..\..\ace\SOCK_Stream.i"\
	"..\..\ace\SString.h"\
	"..\..\ace\SString.i"\
	"..\..\ace\Strategies.h"\
	"..\..\ace\Strategies.i"\
	"..\..\ace\Strategies_T.cpp"\
	"..\..\ace\Strategies_T.h"\
	"..\..\ace\Strategies_T.i"\
	"..\..\ace\Stream_Modules.cpp"\
	"..\..\ace\Stream_Modules.h"\
	"..\..\ace\Stream_Modules.i"\
	"..\..\ace\streams.h"\
	"..\..\ace\SV_Semaphore_Complex.h"\
	"..\..\ace\SV_Semaphore_Complex.i"\
	"..\..\ace\SV_Semaphore_Simple.h"\
	"..\..\ace\SV_Semaphore_Simple.i"\
	"..\..\ace\Svc_Conf_Tokens.h"\
	"..\..\ace\Svc_Handler.cpp"\
	"..\..\ace\Svc_Handler.h"\
	"..\..\ace\Svc_Handler.i"\
	"..\..\ace\Synch.h"\
	"..\..\ace\Synch.i"\
	"..\..\ace\Synch_Options.h"\
	"..\..\ace\Synch_Options.i"\
	"..\..\ace\Synch_T.cpp"\
	"..\..\ace\Synch_T.h"\
	"..\..\ace\Synch_T.i"\
	"..\..\ace\Task.h"\
	"..\..\ace\Task.i"\
	"..\..\ace\Task_T.cpp"\
	"..\..\ace\Task_T.h"\
	"..\..\ace\Task_T.i"\
	"..\..\ace\Thread.h"\
	"..\..\ace\Thread.i"\
	"..\..\ace\Thread_Manager.h"\
	"..\..\ace\Thread_Manager.i"\
	"..\..\ace\Time_Value.h"\
	"..\..\ace\Timer_Queue.h"\
	"..\..\ace\Timer_Queue_T.cpp"\
	"..\..\ace\Timer_Queue_T.h"\
	"..\..\ace\Timer_Queue_T.i"\
	"..\..\ace\Trace.h"\
	"..\..\ace\WFMO_Reactor.h"\
	"..\..\ace\WFMO_Reactor.i"\
	"..\..\ace\ws2tcpip.h"\
	".\align.h"\
	".\any.h"\
	".\any.i"\
	".\cdr.h"\
	".\cdr.i"\
	".\Client_Strategy_Factory.h"\
	".\connect.h"\
	".\connect.i"\
	".\corba.h"\
	".\CurrentC.h"\
	".\CurrentC.i"\
	".\debug.h"\
	".\default_client.h"\
	".\default_client.i"\
	".\default_server.h"\
	".\default_server.i"\
	".\Environment.h"\
	".\Environment.i"\
	".\Exception.h"\
	".\Exception.i"\
	".\giop.h"\
	".\giop.i"\
	".\IIOP_Interpreter.h"\
	".\IIOP_Object.h"\
	".\IIOP_Object.i"\
	".\IIOP_ORB.h"\
	".\IIOP_ORB.i"\
	".\Invocation.h"\
	".\Invocation.i"\
	".\marshal.h"\
	".\marshal.i"\
	".\nvlist.h"\
	".\NVList.i"\
	".\object.h"\
	".\object.i"\
	".\Object_KeyC.h"\
	".\Object_KeyC.i"\
	".\Object_Table.h"\
	".\Operation_Table.h"\
	".\orb.h"\
	".\ORB.i"\
	".\orb_core.h"\
	".\orb_core.i"\
	".\ORB_Strategies_T.cpp"\
	".\ORB_Strategies_T.h"\
	".\ORB_Strategies_T.i"\
	".\orbconf.h"\
	".\params.h"\
	".\params.i"\
	".\poa.h"\
	".\POA.i"\
	".\POA_CORBA.h"\
	".\poa_macros.h"\
	".\poaC.h"\
	".\poaC.i"\
	".\poaS.h"\
	".\poaS.i"\
	".\PolicyC.h"\
	".\PolicyC.i"\
	".\Principal.h"\
	".\Principal.i"\
	".\request.h"\
	".\Request.i"\
	".\sequence.h"\
	".\sequence.i"\
	".\Sequence_T.cpp"\
	".\Sequence_T.h"\
	".\Sequence_T.i"\
	".\servant_base.h"\
	".\Server_Request.h"\
	".\Server_Request.i"\
	".\Server_Strategy_Factory.h"\
	".\singletons.h"\
	".\stub.h"\
	".\stub.i"\
	".\typecode.h"\
	".\typecode.i"\
	".\Union.h"\
	".\varout.cpp"\
	".\varout.h"\
	".\varout.i"\
	
NODEP_CPP_UNION=\
	"..\..\ace\sys_conf.h"\
	

!ELSEIF  "$(CFG)" == "TAO - Win32 Alpha Release"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\align.h
# End Source File
# Begin Source File

SOURCE=.\any.h
# End Source File
# Begin Source File

SOURCE=.\arg_shifter.h
# End Source File
# Begin Source File

SOURCE=.\cdr.h
# End Source File
# Begin Source File

SOURCE=.\Client_Strategy_Factory.h
# End Source File
# Begin Source File

SOURCE=.\connect.h
# End Source File
# Begin Source File

SOURCE=.\corba.h
# End Source File
# Begin Source File

SOURCE=.\CurrentC.h
# End Source File
# Begin Source File

SOURCE=.\debug.h
# End Source File
# Begin Source File

SOURCE=.\default_client.h
# End Source File
# Begin Source File

SOURCE=.\default_server.h
# End Source File
# Begin Source File

SOURCE=.\DynAny_i.h
# End Source File
# Begin Source File

SOURCE=.\DynAnyC.h
# End Source File
# Begin Source File

SOURCE=.\DynArray_i.h
# End Source File
# Begin Source File

SOURCE=.\DynEnum_i.h
# End Source File
# Begin Source File

SOURCE=.\DynSequence_i.h
# End Source File
# Begin Source File

SOURCE=.\DynStruct_i.h
# End Source File
# Begin Source File

SOURCE=.\DynUnion_i.h
# End Source File
# Begin Source File

SOURCE=.\Environment.h
# End Source File
# Begin Source File

SOURCE=.\Exception.h
# End Source File
# Begin Source File

SOURCE=.\Forwarding_Servant.h
# End Source File
# Begin Source File

SOURCE=.\giop.h
# End Source File
# Begin Source File

SOURCE=.\IIOP_Interpreter.h
# End Source File
# Begin Source File

SOURCE=.\IIOP_Object.h
# End Source File
# Begin Source File

SOURCE=.\IIOP_ORB.h
# End Source File
# Begin Source File

SOURCE=.\InconsistentTypeCodeC.h
# End Source File
# Begin Source File

SOURCE=.\marshal.h
# End Source File
# Begin Source File

SOURCE=.\nvlist.h
# End Source File
# Begin Source File

SOURCE=.\object.h
# End Source File
# Begin Source File

SOURCE=.\Object_KeyC.h
# End Source File
# Begin Source File

SOURCE=.\Object_Table.h
# End Source File
# Begin Source File

SOURCE=.\Operation_Table.h
# End Source File
# Begin Source File

SOURCE=.\orb.h
# End Source File
# Begin Source File

SOURCE=.\orb_core.h
# End Source File
# Begin Source File

SOURCE=.\ORB_Strategies_T.h
# End Source File
# Begin Source File

SOURCE=.\orbconf.h
# End Source File
# Begin Source File

SOURCE=.\params.h
# End Source File
# Begin Source File

SOURCE=.\poa.h
# End Source File
# Begin Source File

SOURCE=.\POA_CORBA.h
# End Source File
# Begin Source File

SOURCE=.\poa_macros.h
# End Source File
# Begin Source File

SOURCE=.\poa_T.h
# End Source File
# Begin Source File

SOURCE=.\poaC.h
# End Source File
# Begin Source File

SOURCE=.\poaS.h
# End Source File
# Begin Source File

SOURCE=.\PolicyC.h
# End Source File
# Begin Source File

SOURCE=.\PolicyS.h
# End Source File
# Begin Source File

SOURCE=.\Principal.h
# End Source File
# Begin Source File

SOURCE=.\request.h
# End Source File
# Begin Source File

SOURCE=.\sequence.h
# End Source File
# Begin Source File

SOURCE=.\Sequence_T.h
# End Source File
# Begin Source File

SOURCE=.\servant_base.h
# End Source File
# Begin Source File

SOURCE=.\Server_Request.h
# End Source File
# Begin Source File

SOURCE=.\Server_Strategy_Factory.h
# End Source File
# Begin Source File

SOURCE=.\singletons.h
# End Source File
# Begin Source File

SOURCE=.\stub.h
# End Source File
# Begin Source File

SOURCE=.\TAO.h
# End Source File
# Begin Source File

SOURCE=.\TAO_Internal.h
# End Source File
# Begin Source File

SOURCE=.\Timeprobe.h
# End Source File
# Begin Source File

SOURCE=.\typecode.h
# End Source File
# Begin Source File

SOURCE=.\varout.h
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "*.i"
# Begin Source File

SOURCE=.\any.i
# End Source File
# Begin Source File

SOURCE=.\cdr.i
# End Source File
# Begin Source File

SOURCE=.\connect.i
# End Source File
# Begin Source File

SOURCE=.\default_client.i
# End Source File
# Begin Source File

SOURCE=.\default_server.i
# End Source File
# Begin Source File

SOURCE=.\DynAnyC.i
# End Source File
# Begin Source File

SOURCE=.\Environment.i
# End Source File
# Begin Source File

SOURCE=.\Exception.i
# End Source File
# Begin Source File

SOURCE=.\giop.i
# End Source File
# Begin Source File

SOURCE=.\IIOP_Object.i
# End Source File
# Begin Source File

SOURCE=.\IIOP_ORB.i
# End Source File
# Begin Source File

SOURCE=.\marshal.i
# End Source File
# Begin Source File

SOURCE=.\NVList.i
# End Source File
# Begin Source File

SOURCE=.\object.i
# End Source File
# Begin Source File

SOURCE=.\Object_KeyC.i
# End Source File
# Begin Source File

SOURCE=.\ORB.i
# End Source File
# Begin Source File

SOURCE=.\orb_core.i
# End Source File
# Begin Source File

SOURCE=.\ORB_Strategies_T.i
# End Source File
# Begin Source File

SOURCE=.\params.i
# End Source File
# Begin Source File

SOURCE=.\poaC.i
# End Source File
# Begin Source File

SOURCE=.\poaS.i
# End Source File
# Begin Source File

SOURCE=.\PolicyC.i
# End Source File
# Begin Source File

SOURCE=.\Request.i
# End Source File
# Begin Source File

SOURCE=.\sequence.i
# End Source File
# Begin Source File

SOURCE=.\Sequence_T.i
# End Source File
# Begin Source File

SOURCE=.\Server_Request.i
# End Source File
# Begin Source File

SOURCE=.\stub.i
# End Source File
# Begin Source File

SOURCE=.\TAO_Internal.i
# End Source File
# Begin Source File

SOURCE=.\Timeprobe.i
# End Source File
# Begin Source File

SOURCE=.\typecode.i
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
