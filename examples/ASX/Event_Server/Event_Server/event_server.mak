# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=Event_Server - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Event_Server - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Event_Server - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Event_Server.mak" CFG="Event_Server - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Event_Server - Win32 Debug" (based on\
 "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Event_Server - Win32 Debug"
RSC=rc.exe
CPP=cl.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\.
INTDIR=.\Debug

ALL : "$(OUTDIR)\Event_Server.exe"

CLEAN : 
	-@erase "$(INTDIR)\Consumer_Router.obj"
	-@erase "$(INTDIR)\Event_Analyzer.obj"
	-@erase "$(INTDIR)\event_server.obj"
	-@erase "$(INTDIR)\Options.obj"
	-@erase "$(INTDIR)\Peer_Router.obj"
	-@erase "$(INTDIR)\Supplier_Router.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Event_Server.exe"
	-@erase "$(OUTDIR)\Event_Server.ilk"
	-@erase "$(OUTDIR)\Event_Server.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Event_Server.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 ace.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=ace.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib\
 odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/Event_Server.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/Event_Server.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Consumer_Router.obj" \
	"$(INTDIR)\Event_Analyzer.obj" \
	"$(INTDIR)\event_server.obj" \
	"$(INTDIR)\Options.obj" \
	"$(INTDIR)\Peer_Router.obj" \
	"$(INTDIR)\Supplier_Router.obj"

"$(OUTDIR)\Event_Server.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /Fp"$(INTDIR)/Event_Server.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Event_Server - Win32 Debug"
################################################################################
# Begin Source File

SOURCE=.\Supplier_Router.cpp
DEP_CPP_SUPPL=\
	".\Options.h"\
	".\Options.i"\
	".\Peer_Router.h"\
	".\Supplier_Router.h"\
	{$(INCLUDE)}"\ace\Acceptor.cpp"\
	{$(INCLUDE)}"\ace\Acceptor.h"\
	{$(INCLUDE)}"\ace\Acceptor.i"\
	{$(INCLUDE)}"\ace\ACE.h"\
	{$(INCLUDE)}"\ace\ACE.i"\
	{$(INCLUDE)}"\ace\Addr.h"\
	{$(INCLUDE)}"\ace\Addr.i"\
	{$(INCLUDE)}"\ace\Asynch_IO.h"\
	{$(INCLUDE)}"\ace\Asynch_IO.i"\
	{$(INCLUDE)}"\ace\config-win32-common.h"\
	{$(INCLUDE)}"\ace\config.h"\
	{$(INCLUDE)}"\ace\Containers.cpp"\
	{$(INCLUDE)}"\ace\Containers.h"\
	{$(INCLUDE)}"\ace\Containers.i"\
	{$(INCLUDE)}"\ace\Dynamic.h"\
	{$(INCLUDE)}"\ace\Dynamic.i"\
	{$(INCLUDE)}"\ace\Event_Handler.h"\
	{$(INCLUDE)}"\ace\Event_Handler.i"\
	{$(INCLUDE)}"\ace\Handle_Set.h"\
	{$(INCLUDE)}"\ace\Handle_Set.i"\
	{$(INCLUDE)}"\ace\Hash_Map_Manager.cpp"\
	{$(INCLUDE)}"\ace\Hash_Map_Manager.h"\
	{$(INCLUDE)}"\ace\High_Res_Timer.h"\
	{$(INCLUDE)}"\ace\High_Res_Timer.i"\
	{$(INCLUDE)}"\ace\INET_Addr.h"\
	{$(INCLUDE)}"\ace\INET_Addr.i"\
	{$(INCLUDE)}"\ace\IO_Cntl_Msg.h"\
	{$(INCLUDE)}"\ace\IPC_SAP.h"\
	{$(INCLUDE)}"\ace\IPC_SAP.i"\
	{$(INCLUDE)}"\ace\Local_Tokens.h"\
	{$(INCLUDE)}"\ace\Local_Tokens.i"\
	{$(INCLUDE)}"\ace\Log_Msg.h"\
	{$(INCLUDE)}"\ace\Log_Priority.h"\
	{$(INCLUDE)}"\ace\Log_Record.h"\
	{$(INCLUDE)}"\ace\Log_Record.i"\
	{$(INCLUDE)}"\ace\Malloc.h"\
	{$(INCLUDE)}"\ace\Malloc.i"\
	{$(INCLUDE)}"\ace\Malloc_T.cpp"\
	{$(INCLUDE)}"\ace\Malloc_T.h"\
	{$(INCLUDE)}"\ace\Malloc_T.i"\
	{$(INCLUDE)}"\ace\Map_Manager.cpp"\
	{$(INCLUDE)}"\ace\Map_Manager.h"\
	{$(INCLUDE)}"\ace\Map_Manager.i"\
	{$(INCLUDE)}"\ace\Mem_Map.h"\
	{$(INCLUDE)}"\ace\Mem_Map.i"\
	{$(INCLUDE)}"\ace\Memory_Pool.h"\
	{$(INCLUDE)}"\ace\Memory_Pool.i"\
	{$(INCLUDE)}"\ace\Message_Block.h"\
	{$(INCLUDE)}"\ace\Message_Block.i"\
	{$(INCLUDE)}"\ace\Message_Queue.cpp"\
	{$(INCLUDE)}"\ace\Message_Queue.h"\
	{$(INCLUDE)}"\ace\Message_Queue.i"\
	{$(INCLUDE)}"\ace\Module.cpp"\
	{$(INCLUDE)}"\ace\Module.h"\
	{$(INCLUDE)}"\ace\Module.i"\
	{$(INCLUDE)}"\ace\OS.h"\
	{$(INCLUDE)}"\ace\OS.i"\
	{$(INCLUDE)}"\ace\Pipe.h"\
	{$(INCLUDE)}"\ace\Pipe.i"\
	{$(INCLUDE)}"\ace\Proactor.h"\
	{$(INCLUDE)}"\ace\Proactor.i"\
	{$(INCLUDE)}"\ace\Profile_Timer.h"\
	{$(INCLUDE)}"\ace\Profile_Timer.i"\
	{$(INCLUDE)}"\ace\Reactor.h"\
	{$(INCLUDE)}"\ace\Reactor.i"\
	{$(INCLUDE)}"\ace\ReactorEx.h"\
	{$(INCLUDE)}"\ace\ReactorEx.i"\
	{$(INCLUDE)}"\ace\Service_Config.h"\
	{$(INCLUDE)}"\ace\Service_Config.i"\
	{$(INCLUDE)}"\ace\Service_Object.h"\
	{$(INCLUDE)}"\ace\Service_Object.i"\
	{$(INCLUDE)}"\ace\Shared_Object.h"\
	{$(INCLUDE)}"\ace\Shared_Object.i"\
	{$(INCLUDE)}"\ace\Signal.h"\
	{$(INCLUDE)}"\ace\Signal.i"\
	{$(INCLUDE)}"\ace\SOCK.h"\
	{$(INCLUDE)}"\ace\SOCK.i"\
	{$(INCLUDE)}"\ace\SOCK_Acceptor.h"\
	{$(INCLUDE)}"\ace\SOCK_Acceptor.i"\
	{$(INCLUDE)}"\ace\SOCK_IO.h"\
	{$(INCLUDE)}"\ace\SOCK_IO.i"\
	{$(INCLUDE)}"\ace\SOCK_Stream.h"\
	{$(INCLUDE)}"\ace\SOCK_Stream.i"\
	{$(INCLUDE)}"\ace\SString.h"\
	{$(INCLUDE)}"\ace\SString.i"\
	{$(INCLUDE)}"\ace\stdcpp.h"\
	{$(INCLUDE)}"\ace\Strategies.h"\
	{$(INCLUDE)}"\ace\Strategies_T.cpp"\
	{$(INCLUDE)}"\ace\Strategies_T.h"\
	{$(INCLUDE)}"\ace\Stream_Modules.cpp"\
	{$(INCLUDE)}"\ace\Stream_Modules.h"\
	{$(INCLUDE)}"\ace\Stream_Modules.i"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Complex.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Complex.i"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Simple.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Simple.i"\
	{$(INCLUDE)}"\ace\Svc_Conf_Tokens.h"\
	{$(INCLUDE)}"\ace\Svc_Handler.cpp"\
	{$(INCLUDE)}"\ace\Svc_Handler.h"\
	{$(INCLUDE)}"\ace\Svc_Handler.i"\
	{$(INCLUDE)}"\ace\Synch.h"\
	{$(INCLUDE)}"\ace\Synch.i"\
	{$(INCLUDE)}"\ace\Synch_Options.h"\
	{$(INCLUDE)}"\ace\Synch_T.cpp"\
	{$(INCLUDE)}"\ace\Synch_T.h"\
	{$(INCLUDE)}"\ace\Synch_T.i"\
	{$(INCLUDE)}"\ace\Task.h"\
	{$(INCLUDE)}"\ace\Task.i"\
	{$(INCLUDE)}"\ace\Task_T.cpp"\
	{$(INCLUDE)}"\ace\Task_T.h"\
	{$(INCLUDE)}"\ace\Task_T.i"\
	{$(INCLUDE)}"\ace\Thread.h"\
	{$(INCLUDE)}"\ace\Thread.i"\
	{$(INCLUDE)}"\ace\Thread_Manager.h"\
	{$(INCLUDE)}"\ace\Thread_Manager.i"\
	{$(INCLUDE)}"\ace\Time_Value.h"\
	{$(INCLUDE)}"\ace\Timer_Heap.h"\
	{$(INCLUDE)}"\ace\Timer_Heap_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Heap_T.h"\
	{$(INCLUDE)}"\ace\Timer_List.h"\
	{$(INCLUDE)}"\ace\Timer_List_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_List_T.h"\
	{$(INCLUDE)}"\ace\Timer_Queue.h"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.h"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.i"\
	{$(INCLUDE)}"\ace\Timer_Wheel.h"\
	{$(INCLUDE)}"\ace\Timer_Wheel_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Wheel_T.h"\
	{$(INCLUDE)}"\ace\Token.h"\
	{$(INCLUDE)}"\ace\Token.i"\
	{$(INCLUDE)}"\ace\Trace.h"\
	{$(INCLUDE)}"\ace\ws2tcpip.h"\
	

"$(INTDIR)\Supplier_Router.obj" : $(SOURCE) $(DEP_CPP_SUPPL) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Event_Analyzer.cpp
DEP_CPP_EVENT=\
	".\Event_Analyzer.h"\
	".\Options.h"\
	".\Options.i"\
	{$(INCLUDE)}"\ace\ACE.h"\
	{$(INCLUDE)}"\ace\ACE.i"\
	{$(INCLUDE)}"\ace\Addr.h"\
	{$(INCLUDE)}"\ace\Addr.i"\
	{$(INCLUDE)}"\ace\Asynch_IO.h"\
	{$(INCLUDE)}"\ace\Asynch_IO.i"\
	{$(INCLUDE)}"\ace\config-win32-common.h"\
	{$(INCLUDE)}"\ace\config.h"\
	{$(INCLUDE)}"\ace\Containers.cpp"\
	{$(INCLUDE)}"\ace\Containers.h"\
	{$(INCLUDE)}"\ace\Containers.i"\
	{$(INCLUDE)}"\ace\Event_Handler.h"\
	{$(INCLUDE)}"\ace\Event_Handler.i"\
	{$(INCLUDE)}"\ace\Handle_Set.h"\
	{$(INCLUDE)}"\ace\Handle_Set.i"\
	{$(INCLUDE)}"\ace\Hash_Map_Manager.cpp"\
	{$(INCLUDE)}"\ace\Hash_Map_Manager.h"\
	{$(INCLUDE)}"\ace\High_Res_Timer.h"\
	{$(INCLUDE)}"\ace\High_Res_Timer.i"\
	{$(INCLUDE)}"\ace\INET_Addr.h"\
	{$(INCLUDE)}"\ace\INET_Addr.i"\
	{$(INCLUDE)}"\ace\IO_Cntl_Msg.h"\
	{$(INCLUDE)}"\ace\IPC_SAP.h"\
	{$(INCLUDE)}"\ace\IPC_SAP.i"\
	{$(INCLUDE)}"\ace\Local_Tokens.h"\
	{$(INCLUDE)}"\ace\Local_Tokens.i"\
	{$(INCLUDE)}"\ace\Log_Msg.h"\
	{$(INCLUDE)}"\ace\Log_Priority.h"\
	{$(INCLUDE)}"\ace\Log_Record.h"\
	{$(INCLUDE)}"\ace\Log_Record.i"\
	{$(INCLUDE)}"\ace\Malloc.h"\
	{$(INCLUDE)}"\ace\Malloc.i"\
	{$(INCLUDE)}"\ace\Malloc_T.cpp"\
	{$(INCLUDE)}"\ace\Malloc_T.h"\
	{$(INCLUDE)}"\ace\Malloc_T.i"\
	{$(INCLUDE)}"\ace\Map_Manager.cpp"\
	{$(INCLUDE)}"\ace\Map_Manager.h"\
	{$(INCLUDE)}"\ace\Map_Manager.i"\
	{$(INCLUDE)}"\ace\Mem_Map.h"\
	{$(INCLUDE)}"\ace\Mem_Map.i"\
	{$(INCLUDE)}"\ace\Memory_Pool.h"\
	{$(INCLUDE)}"\ace\Memory_Pool.i"\
	{$(INCLUDE)}"\ace\Message_Block.h"\
	{$(INCLUDE)}"\ace\Message_Block.i"\
	{$(INCLUDE)}"\ace\Message_Queue.cpp"\
	{$(INCLUDE)}"\ace\Message_Queue.h"\
	{$(INCLUDE)}"\ace\Message_Queue.i"\
	{$(INCLUDE)}"\ace\Module.cpp"\
	{$(INCLUDE)}"\ace\Module.h"\
	{$(INCLUDE)}"\ace\Module.i"\
	{$(INCLUDE)}"\ace\OS.h"\
	{$(INCLUDE)}"\ace\OS.i"\
	{$(INCLUDE)}"\ace\Pipe.h"\
	{$(INCLUDE)}"\ace\Pipe.i"\
	{$(INCLUDE)}"\ace\Proactor.h"\
	{$(INCLUDE)}"\ace\Proactor.i"\
	{$(INCLUDE)}"\ace\Profile_Timer.h"\
	{$(INCLUDE)}"\ace\Profile_Timer.i"\
	{$(INCLUDE)}"\ace\Reactor.h"\
	{$(INCLUDE)}"\ace\Reactor.i"\
	{$(INCLUDE)}"\ace\ReactorEx.h"\
	{$(INCLUDE)}"\ace\ReactorEx.i"\
	{$(INCLUDE)}"\ace\Service_Config.h"\
	{$(INCLUDE)}"\ace\Service_Config.i"\
	{$(INCLUDE)}"\ace\Service_Object.h"\
	{$(INCLUDE)}"\ace\Service_Object.i"\
	{$(INCLUDE)}"\ace\Shared_Object.h"\
	{$(INCLUDE)}"\ace\Shared_Object.i"\
	{$(INCLUDE)}"\ace\Signal.h"\
	{$(INCLUDE)}"\ace\Signal.i"\
	{$(INCLUDE)}"\ace\SOCK.h"\
	{$(INCLUDE)}"\ace\SOCK.i"\
	{$(INCLUDE)}"\ace\SOCK_IO.h"\
	{$(INCLUDE)}"\ace\SOCK_IO.i"\
	{$(INCLUDE)}"\ace\SOCK_Stream.h"\
	{$(INCLUDE)}"\ace\SOCK_Stream.i"\
	{$(INCLUDE)}"\ace\SString.h"\
	{$(INCLUDE)}"\ace\SString.i"\
	{$(INCLUDE)}"\ace\stdcpp.h"\
	{$(INCLUDE)}"\ace\Strategies.h"\
	{$(INCLUDE)}"\ace\Strategies_T.cpp"\
	{$(INCLUDE)}"\ace\Strategies_T.h"\
	{$(INCLUDE)}"\ace\Stream.cpp"\
	{$(INCLUDE)}"\ace\Stream.h"\
	{$(INCLUDE)}"\ace\Stream.i"\
	{$(INCLUDE)}"\ace\Stream_Modules.cpp"\
	{$(INCLUDE)}"\ace\Stream_Modules.h"\
	{$(INCLUDE)}"\ace\Stream_Modules.i"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Complex.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Complex.i"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Simple.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Simple.i"\
	{$(INCLUDE)}"\ace\Svc_Conf_Tokens.h"\
	{$(INCLUDE)}"\ace\Synch.h"\
	{$(INCLUDE)}"\ace\Synch.i"\
	{$(INCLUDE)}"\ace\Synch_Options.h"\
	{$(INCLUDE)}"\ace\Synch_T.cpp"\
	{$(INCLUDE)}"\ace\Synch_T.h"\
	{$(INCLUDE)}"\ace\Synch_T.i"\
	{$(INCLUDE)}"\ace\Task.h"\
	{$(INCLUDE)}"\ace\Task.i"\
	{$(INCLUDE)}"\ace\Task_T.cpp"\
	{$(INCLUDE)}"\ace\Task_T.h"\
	{$(INCLUDE)}"\ace\Task_T.i"\
	{$(INCLUDE)}"\ace\Thread.h"\
	{$(INCLUDE)}"\ace\Thread.i"\
	{$(INCLUDE)}"\ace\Thread_Manager.h"\
	{$(INCLUDE)}"\ace\Thread_Manager.i"\
	{$(INCLUDE)}"\ace\Time_Value.h"\
	{$(INCLUDE)}"\ace\Timer_Heap.h"\
	{$(INCLUDE)}"\ace\Timer_Heap_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Heap_T.h"\
	{$(INCLUDE)}"\ace\Timer_List.h"\
	{$(INCLUDE)}"\ace\Timer_List_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_List_T.h"\
	{$(INCLUDE)}"\ace\Timer_Queue.h"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.h"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.i"\
	{$(INCLUDE)}"\ace\Timer_Wheel.h"\
	{$(INCLUDE)}"\ace\Timer_Wheel_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Wheel_T.h"\
	{$(INCLUDE)}"\ace\Token.h"\
	{$(INCLUDE)}"\ace\Token.i"\
	{$(INCLUDE)}"\ace\Trace.h"\
	{$(INCLUDE)}"\ace\ws2tcpip.h"\
	

"$(INTDIR)\Event_Analyzer.obj" : $(SOURCE) $(DEP_CPP_EVENT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\event_server.cpp
DEP_CPP_EVENT_=\
	".\Consumer_Router.h"\
	".\Event_Analyzer.h"\
	".\Options.h"\
	".\Options.i"\
	".\Peer_Router.h"\
	".\Supplier_Router.h"\
	{$(INCLUDE)}"\ace\Acceptor.cpp"\
	{$(INCLUDE)}"\ace\Acceptor.h"\
	{$(INCLUDE)}"\ace\Acceptor.i"\
	{$(INCLUDE)}"\ace\ACE.h"\
	{$(INCLUDE)}"\ace\ACE.i"\
	{$(INCLUDE)}"\ace\Addr.h"\
	{$(INCLUDE)}"\ace\Addr.i"\
	{$(INCLUDE)}"\ace\Asynch_IO.h"\
	{$(INCLUDE)}"\ace\Asynch_IO.i"\
	{$(INCLUDE)}"\ace\config-win32-common.h"\
	{$(INCLUDE)}"\ace\config.h"\
	{$(INCLUDE)}"\ace\Containers.cpp"\
	{$(INCLUDE)}"\ace\Containers.h"\
	{$(INCLUDE)}"\ace\Containers.i"\
	{$(INCLUDE)}"\ace\Dynamic.h"\
	{$(INCLUDE)}"\ace\Dynamic.i"\
	{$(INCLUDE)}"\ace\Event_Handler.h"\
	{$(INCLUDE)}"\ace\Event_Handler.i"\
	{$(INCLUDE)}"\ace\Handle_Set.h"\
	{$(INCLUDE)}"\ace\Handle_Set.i"\
	{$(INCLUDE)}"\ace\Hash_Map_Manager.cpp"\
	{$(INCLUDE)}"\ace\Hash_Map_Manager.h"\
	{$(INCLUDE)}"\ace\High_Res_Timer.h"\
	{$(INCLUDE)}"\ace\High_Res_Timer.i"\
	{$(INCLUDE)}"\ace\INET_Addr.h"\
	{$(INCLUDE)}"\ace\INET_Addr.i"\
	{$(INCLUDE)}"\ace\IO_Cntl_Msg.h"\
	{$(INCLUDE)}"\ace\IPC_SAP.h"\
	{$(INCLUDE)}"\ace\IPC_SAP.i"\
	{$(INCLUDE)}"\ace\Local_Tokens.h"\
	{$(INCLUDE)}"\ace\Local_Tokens.i"\
	{$(INCLUDE)}"\ace\Log_Msg.h"\
	{$(INCLUDE)}"\ace\Log_Priority.h"\
	{$(INCLUDE)}"\ace\Log_Record.h"\
	{$(INCLUDE)}"\ace\Log_Record.i"\
	{$(INCLUDE)}"\ace\Malloc.h"\
	{$(INCLUDE)}"\ace\Malloc.i"\
	{$(INCLUDE)}"\ace\Malloc_T.cpp"\
	{$(INCLUDE)}"\ace\Malloc_T.h"\
	{$(INCLUDE)}"\ace\Malloc_T.i"\
	{$(INCLUDE)}"\ace\Map_Manager.cpp"\
	{$(INCLUDE)}"\ace\Map_Manager.h"\
	{$(INCLUDE)}"\ace\Map_Manager.i"\
	{$(INCLUDE)}"\ace\Mem_Map.h"\
	{$(INCLUDE)}"\ace\Mem_Map.i"\
	{$(INCLUDE)}"\ace\Memory_Pool.h"\
	{$(INCLUDE)}"\ace\Memory_Pool.i"\
	{$(INCLUDE)}"\ace\Message_Block.h"\
	{$(INCLUDE)}"\ace\Message_Block.i"\
	{$(INCLUDE)}"\ace\Message_Queue.cpp"\
	{$(INCLUDE)}"\ace\Message_Queue.h"\
	{$(INCLUDE)}"\ace\Message_Queue.i"\
	{$(INCLUDE)}"\ace\Module.cpp"\
	{$(INCLUDE)}"\ace\Module.h"\
	{$(INCLUDE)}"\ace\Module.i"\
	{$(INCLUDE)}"\ace\OS.h"\
	{$(INCLUDE)}"\ace\OS.i"\
	{$(INCLUDE)}"\ace\Pipe.h"\
	{$(INCLUDE)}"\ace\Pipe.i"\
	{$(INCLUDE)}"\ace\Proactor.h"\
	{$(INCLUDE)}"\ace\Proactor.i"\
	{$(INCLUDE)}"\ace\Profile_Timer.h"\
	{$(INCLUDE)}"\ace\Profile_Timer.i"\
	{$(INCLUDE)}"\ace\Reactor.h"\
	{$(INCLUDE)}"\ace\Reactor.i"\
	{$(INCLUDE)}"\ace\ReactorEx.h"\
	{$(INCLUDE)}"\ace\ReactorEx.i"\
	{$(INCLUDE)}"\ace\Service_Config.h"\
	{$(INCLUDE)}"\ace\Service_Config.i"\
	{$(INCLUDE)}"\ace\Service_Object.h"\
	{$(INCLUDE)}"\ace\Service_Object.i"\
	{$(INCLUDE)}"\ace\Shared_Object.h"\
	{$(INCLUDE)}"\ace\Shared_Object.i"\
	{$(INCLUDE)}"\ace\Signal.h"\
	{$(INCLUDE)}"\ace\Signal.i"\
	{$(INCLUDE)}"\ace\SOCK.h"\
	{$(INCLUDE)}"\ace\SOCK.i"\
	{$(INCLUDE)}"\ace\SOCK_Acceptor.h"\
	{$(INCLUDE)}"\ace\SOCK_Acceptor.i"\
	{$(INCLUDE)}"\ace\SOCK_IO.h"\
	{$(INCLUDE)}"\ace\SOCK_IO.i"\
	{$(INCLUDE)}"\ace\SOCK_Stream.h"\
	{$(INCLUDE)}"\ace\SOCK_Stream.i"\
	{$(INCLUDE)}"\ace\SPIPE.h"\
	{$(INCLUDE)}"\ace\SPIPE.i"\
	{$(INCLUDE)}"\ace\SPIPE_Acceptor.h"\
	{$(INCLUDE)}"\ace\SPIPE_Addr.h"\
	{$(INCLUDE)}"\ace\SPIPE_Addr.i"\
	{$(INCLUDE)}"\ace\SPIPE_Stream.h"\
	{$(INCLUDE)}"\ace\SPIPE_Stream.i"\
	{$(INCLUDE)}"\ace\SString.h"\
	{$(INCLUDE)}"\ace\SString.i"\
	{$(INCLUDE)}"\ace\stdcpp.h"\
	{$(INCLUDE)}"\ace\Strategies.h"\
	{$(INCLUDE)}"\ace\Strategies_T.cpp"\
	{$(INCLUDE)}"\ace\Strategies_T.h"\
	{$(INCLUDE)}"\ace\Stream.cpp"\
	{$(INCLUDE)}"\ace\Stream.h"\
	{$(INCLUDE)}"\ace\Stream.i"\
	{$(INCLUDE)}"\ace\Stream_Modules.cpp"\
	{$(INCLUDE)}"\ace\Stream_Modules.h"\
	{$(INCLUDE)}"\ace\Stream_Modules.i"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Complex.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Complex.i"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Simple.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Simple.i"\
	{$(INCLUDE)}"\ace\Svc_Conf_Tokens.h"\
	{$(INCLUDE)}"\ace\Svc_Handler.cpp"\
	{$(INCLUDE)}"\ace\Svc_Handler.h"\
	{$(INCLUDE)}"\ace\Svc_Handler.i"\
	{$(INCLUDE)}"\ace\Synch.h"\
	{$(INCLUDE)}"\ace\Synch.i"\
	{$(INCLUDE)}"\ace\Synch_Options.h"\
	{$(INCLUDE)}"\ace\Synch_T.cpp"\
	{$(INCLUDE)}"\ace\Synch_T.h"\
	{$(INCLUDE)}"\ace\Synch_T.i"\
	{$(INCLUDE)}"\ace\Task.h"\
	{$(INCLUDE)}"\ace\Task.i"\
	{$(INCLUDE)}"\ace\Task_T.cpp"\
	{$(INCLUDE)}"\ace\Task_T.h"\
	{$(INCLUDE)}"\ace\Task_T.i"\
	{$(INCLUDE)}"\ace\Thread.h"\
	{$(INCLUDE)}"\ace\Thread.i"\
	{$(INCLUDE)}"\ace\Thread_Manager.h"\
	{$(INCLUDE)}"\ace\Thread_Manager.i"\
	{$(INCLUDE)}"\ace\Time_Value.h"\
	{$(INCLUDE)}"\ace\Timer_Heap.h"\
	{$(INCLUDE)}"\ace\Timer_Heap_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Heap_T.h"\
	{$(INCLUDE)}"\ace\Timer_List.h"\
	{$(INCLUDE)}"\ace\Timer_List_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_List_T.h"\
	{$(INCLUDE)}"\ace\Timer_Queue.h"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.h"\
	{$(INCLUDE)}"\ace\Timer_Queue_T.i"\
	{$(INCLUDE)}"\ace\Timer_Wheel.h"\
	{$(INCLUDE)}"\ace\Timer_Wheel_T.cpp"\
	{$(INCLUDE)}"\ace\Timer_Wheel_T.h"\
	{$(INCLUDE)}"\ace\Token.h"\
	{$(INCLUDE)}"\ace\Token.i"\
	{$(INCLUDE)}"\ace\Trace.h"\
	{$(INCLUDE)}"\ace\UPIPE_Acceptor.h"\
	{$(INCLUDE)}"\ace\UPIPE_Acceptor.i"\
	{$(INCLUDE)}"\ace\UPIPE_Addr.h"\
	{$(INCLUDE)}"\ace\UPIPE_Stream.h"\
	{$(INCLUDE)}"\ace\UPIPE_Stream.i"\
	{$(INCLUDE)}"\ace\ws2tcpip.h"\
	

"$(INTDIR)\event_server.obj" : $(SOURCE) $(DEP_CPP_EVENT_) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Options.cpp
DEP_CPP_OPTIO=\
	".\Options.h"\
	".\Options.i"\
	{$(INCLUDE)}"\ace\ACE.h"\
	{$(INCLUDE)}"\ace\ACE.i"\
	{$(INCLUDE)}"\ace\config-win32-common.h"\
	{$(INCLUDE)}"\ace\config.h"\
	{$(INCLUDE)}"\ace\Event_Handler.h"\
	{$(INCLUDE)}"\ace\Event_Handler.i"\
	{$(INCLUDE)}"\ace\Get_Opt.h"\
	{$(INCLUDE)}"\ace\Get_Opt.i"\
	{$(INCLUDE)}"\ace\High_Res_Timer.h"\
	{$(INCLUDE)}"\ace\High_Res_Timer.i"\
	{$(INCLUDE)}"\ace\Log_Msg.h"\
	{$(INCLUDE)}"\ace\Log_Priority.h"\
	{$(INCLUDE)}"\ace\Log_Record.h"\
	{$(INCLUDE)}"\ace\Log_Record.i"\
	{$(INCLUDE)}"\ace\OS.h"\
	{$(INCLUDE)}"\ace\OS.i"\
	{$(INCLUDE)}"\ace\Profile_Timer.h"\
	{$(INCLUDE)}"\ace\Profile_Timer.i"\
	{$(INCLUDE)}"\ace\SString.h"\
	{$(INCLUDE)}"\ace\SString.i"\
	{$(INCLUDE)}"\ace\stdcpp.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Complex.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Complex.i"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Simple.h"\
	{$(INCLUDE)}"\ace\SV_Semaphore_Simple.i"\
	{$(INCLUDE)}"\ace\Synch.h"\
	{$(INCLUDE)}"\ace\Synch.i"\
	{$(INCLUDE)}"\ace\Synch_T.cpp"\
	{$(INCLUDE)}"\ace\Synch_T.h"\
	{$(INCLUDE)}"\ace\Synch_T.i"\
	{$(INCLUDE)}"\ace\Thread.h"\
	{$(INCLUDE)}"\ace\Thread.i"\
	{$(INCLUDE)}"\ace\Time_Value.h"\
	{$(INCLUDE)}"\ace\Trace.h"\
	{$(INCLUDE)}"\ace\ws2tcpip.h"\
	

"$(INTDIR)\Options.obj" : $(SOURCE) $(DEP_CPP_OPTIO) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Peer_Router.cpp
DEP_CPP_PEER_=\
	".\Options.h"\
	".\Peer_Router.h"\
	{$(INCLUDE)}"\ace\Acceptor.h"\
	{$(INCLUDE)}"\ace\ACE.h"\
	{$(INCLUDE)}"\ace\config-win32-common.h"\
	{$(INCLUDE)}"\ace\config.h"\
	{$(INCLUDE)}"\ace\Get_Opt.h"\
	{$(INCLUDE)}"\ace\Get_Opt.i"\
	{$(INCLUDE)}"\ace\Log_Msg.h"\
	{$(INCLUDE)}"\ace\Log_Record.h"\
	{$(INCLUDE)}"\ace\OS.h"\
	{$(INCLUDE)}"\ace\OS.i"\
	{$(INCLUDE)}"\ace\Profile_Timer.h"\
	{$(INCLUDE)}"\ace\Service_Config.h"\
	{$(INCLUDE)}"\ace\stdcpp.h"\
	{$(INCLUDE)}"\ace\Trace.h"\
	{$(INCLUDE)}"\ace\ws2tcpip.h"\
	

"$(INTDIR)\Peer_Router.obj" : $(SOURCE) $(DEP_CPP_PEER_) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Consumer_Router.cpp
DEP_CPP_CONSU=\
	".\Consumer_Router.h"\
	".\Options.h"\
	{$(INCLUDE)}"\ace\config-win32-common.h"\
	{$(INCLUDE)}"\ace\config.h"\
	{$(INCLUDE)}"\ace\Log_Msg.h"\
	{$(INCLUDE)}"\ace\Log_Record.h"\
	{$(INCLUDE)}"\ace\OS.h"\
	{$(INCLUDE)}"\ace\OS.i"\
	{$(INCLUDE)}"\ace\Profile_Timer.h"\
	{$(INCLUDE)}"\ace\SOCK_Acceptor.h"\
	{$(INCLUDE)}"\ace\SOCK_Stream.h"\
	{$(INCLUDE)}"\ace\stdcpp.h"\
	{$(INCLUDE)}"\ace\Trace.h"\
	{$(INCLUDE)}"\ace\ws2tcpip.h"\
	

"$(INTDIR)\Consumer_Router.obj" : $(SOURCE) $(DEP_CPP_CONSU) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
