# $Id$

# The following three lines let this script run without specifying the
# full path to perl, as long as it is in the user's PATH.
# Taken from perlrun man page.

eval '(exit $?0)' && eval 'exec perl -pi -S $0 ${1+"$@"}'
    & eval 'exec perl -pi -S $0 $argv:q'
    if 0;

s/\bAcceptor\b/ACE_Acceptor/g;
s/\bAddr\b/ACE_Addr/g;
s/\bArgument_Vector\b/ACE_ARGV/g;
s/\bAtomic_Op\b/ACE_Atomic_Op/g;
s/\bCORBA_Handler\b/ACE_CORBA_Handler/g;
s/\bCondition\b/ACE_Condition/g;
s/\bConnector\b/ACE_Connector/g;
s/\bControl_Block\b/ACE_Control_Block/g;
s/\bControl_Mode\b/ACE_Control_Mode/g;
s/\bData_Block\b/ACE_Data_Block/g;
s/\bDummy_Node\b/ACE_Dummy_Node/g;
s/\bDynamic_Node\b/ACE_Dynamic_Node/g;
s/\bElapsed_Time\b/ACE_Elapsed_Time/g;
s/\bEvent_Handler\b/ACE_Event_Handler/g;
s/\bEvent_Handler_T\b/ACE_Event_Handler_T/g;
s/\bFIFO\b/ACE_FIFO/g;
s/\bFIFO_Recv\b/ACE_FIFO_Recv/g;
s/\bFIFO_Recv_Msg\b/ACE_FIFO_Recv_Msg/g;
s/\bFIFO_Send\b/ACE_FIFO_Send/g;
s/\bFIFO_Send_Msg\b/ACE_FIFO_Send_Msg/g;
s/\bFunction_Node\b/ACE_Function_Node/g;
s/\bGet_Opt\b/ACE_Get_Opt/g;
s/\bGuard\b/ACE_Guard/g;
s/\bHANDLE\b/ACE_HANDLE/g;
s/\bHandle_Set_Iterator\b/ACE_Handle_Set_Iterator/g;
s/\bHandle_Set\b/ACE_Handle_Set/g;
s/\bHigh_Res_Timer\b/ACE_High_Res_Timer/g;
s/\bINET_Addr\b/ACE_INET_Addr/g;
s/\bIO_Cntl_Cmds\b/ACE_IO_Cntl_Cmds/g;
s/\bIO_Cntl_Msg\b/ACE_IO_Cntl_Msg/g;
s/\bIO_Vector\b/ACE_IO_Vector/g;
s/\bIPC_SAP\b/ACE_IPC_SAP/g;
s/\bLSOCK\b/ACE_LSOCK/g;
s/\bLSOCK_Acceptor\b/ACE_LSOCK_Acceptor/g;
s/\bLSOCK_Aceeptor\b/ACE_LSOCK_Aceeptor/g;
s/\bLSOCK_CODgram\b/ACE_LSOCK_CODgram/g;
s/\bLSOCK_Connector\b/ACE_LSOCK_Connector/g;
s/\bLSOCK_Dgram\b/ACE_LSOCK_Dgram/g;
s/\bLSOCK_Stream\b/ACE_LSOCK_Stream/g;
s/\bLocal_Memory_Pool\b/ACE_Local_Memory_Pool/g;
s/\bLocation_Node\b/ACE_Location_Node/g;
s/\bLog_Msg\b/ACE_Log_Msg/g;
s/\bLog_Priority\b/ACE_Log_Priority/g;
s/\bLog_Record\b/ACE_Log_Record/g;
s/\bMalloc\b/ACE_Malloc/g;
s/\bMalloc_Align\b/ACE_Malloc_Align/g;
s/\bMalloc_Header\b/ACE_Malloc_Header/g;
s/\bMalloc_Stats\b/ACE_Malloc_Stats/g;
s/\bMap_Entry\b/ACE_Map_Entry/g;
s/\bMap_Iterator\b/ACE_Map_Iterator/g;
s/\bMap_Manager\b/ACE_Map_Manager/g;
s/\bMem_Map\b/ACE_Mem_Map/g;
s/\bMMAP_Memory_Pool\b/ACE_MMAP_Memory_Pool/g;
s/\bMT_SYNCH\b/ACE_MT_SYNCH/g;
s/\bMemory_Pool\b/ACE_Memory_Pool/g;
s/\bMessage_Block\b/ACE_Message_Block/g;
s/\bMessage_Queue\b/ACE_Message_Queue/g;
s/\bMessage_Type\b/ACE_Message_Type/g;
s/\bModule\b/ACE_Module/g;
s/\bModule_Link\b/ACE_Module_Link/g;
s/\bModule_Type\b/ACE_Module_Type/g;
s/\bMultiplexor\b/ACE_Multiplexor/g;
s/\bMutex\b/ACE_Mutex/g;
s/\bNull_Condition\b/ACE_Null_Condition/g;
s/\bNull_Mutex\b/ACE_Null_Mutex/g;
s/\bNULL_SYNCH\b/ACE_NULL_SYNCH/g;
s/\bObchunk\b/ACE_Obchunk/g;
s/\bObject_Node\b/ACE_Object_Node/g;
s/\bObstack\b/ACE_Obstack/g;
s/\bOneshot_Acceptor\b/ACE_Oneshot_Acceptor/g;
s/\bParse_Node\b/ACE_Parse_Node/g;
s/\bProcess_Mutex\b/ACE_Process_Mutex/g;
s/\bProfile_Timer\b/ACE_Profile_Timer/g;
s/\bQ_Entry\b/ACE_Q_Entry/g;
s/\bQueue\b/ACE_Queue/g;
s/\bRW_Mutex\b/ACE_RW_Mutex/g;
s/\bRaw_Data_Block\b/ACE_Raw_Data_Block/g;
s/\bReactor\b/ACE_Reactor/g;
s/\bReactor_Mask\b/ACE_Reactor_Mask/g;
s/\bReactor_Token\b/ACE_Reactor_Token/g;
s/\bRead_Guard\b/ACE_Read_Guard/g;
s/\bRecursive_Lock\b/ACE_Recursive_Lock/g;
s/\bRemove_Node\b/ACE_Remove_Node/g;
s/\bRequest_Queue\b/ACE_Request_Queue/g;
s/\bResume_Node\b/ACE_Resume_Node/g;
s/\bSOCK\b/ACE_SOCK/g;
s/\bSOCK_Acceptor\b/ACE_SOCK_Acceptor/g;
s/\bSOCK_CODgram\b/ACE_SOCK_CODgram/g;
s/\bSOCK_Connector\b/ACE_SOCK_Connector/g;
s/\bSOCK_DGRAM\b/ACE_SOCK_DGRAM/g;
s/\bSOCK_Dgram\b/ACE_SOCK_Dgram/g;
s/\bSOCK_Dgram_Bcast\b/ACE_SOCK_Dgram_Bcast/g;
s/\bSOCK_Dgram_Mcast\b/ACE_SOCK_Dgram_Mcast/g;
s/\bSOCK_IO\b/ACE_SOCK_IO/g;
s/\bSOCK_Stream\b/ACE_SOCK_Stream/g;
s/\bSPIPE\b/ACE_SPIPE/g;
s/\bSPIPE_Acceptor\b/ACE_SPIPE_Acceptor/g;
s/\bSPIPE_Addr\b/ACE_SPIPE_Addr/g;
s/\bSPIPE_Connector\b/ACE_SPIPE_Connector/g;
s/\bSPIPE_IO\b/ACE_SPIPE_Stream/g;
s/\bSPIPE_Msg\b/ACE_SPIPE_Msg/g;
s/\bSString\b/ACE_SString/g;
s/\bSV_Message\b/ACE_SV_Message/g;
s/\bSV_Message_Queue\b/ACE_SV_Message_Queue/g;
s/\bSV_Semaphore\b/ACE_SV_Semaphore/g;
s/\bSV_Semaphore_Complex\b/ACE_SV_Semaphore_Complex/g;
s/\bSV_Semaphore_Simple\b/ACE_SV_Semaphore_Simple/g;
s/\bSV_Shared_Memory\b/ACE_SV_Shared_Memory/g;
s/\bSemaphore\b/ACE_Semaphore/g;
s/\bService_Config\b/ACE_Service_Config/g;
s/\bService_Manager\b/ACE_Service_Manager/g;
s/\bService_Object\b/ACE_Service_Object/g;
s/\bService_Object_Type\b/ACE_Service_Object_Type/g;
s/\bService_Record\b/ACE_Service_Record/g;
s/\bService_Repository\b/ACE_Service_Repository/g;
s/\bService_Repository_Iterator\b/ACE_Service_Repository_Iterator/g;
s/\bService_Type\b/ACE_Service_Type/g;
s/\bShared_Malloc\b/ACE_Shared_Malloc/g;
s/\bShared_Malloc_MM\b/ACE_Shared_Malloc_MM/g;
s/\bShared_Malloc_SV\b/ACE_Shared_Malloc_SV/g;
s/\bShared_Memory\b/ACE_Shared_Memory/g;
s/\bShared_Memory_Pool\b/ACE_Shared_Memory_Pool/g;
s/\bShared_Object\b/ACE_Shared_Object/g;
s/\bSig_Action\b/ACE_Sig_Action/g;
s/\bSig_Handler\b/ACE_Sig_Handler/g;
s/\bSig_Set\b/ACE_Sig_Set/g;
s/\bSignalHandler\b/ACE_SignalHandler/g;
s/\bSignalHandlerV\b/ACE_SignalHandlerV/g;
s/\bSignal_Guard\b/ACE_Signal_Guard/g;
s/\bSignal_Handler\b/ACE_Signal_Handler/g;
s/\bStatic_Node\b/ACE_Static_Node/g;
s/\bStr_Buf\b/ACE_Str_Buf/g;
s/\bStream\b/ACE_Stream/g;
s/\bStream_Head\b/ACE_Stream_Head/g;
s/\bStream_Iterator\b/ACE_Stream_Iterator/g;
s/\bStream_Modules\b/ACE_Stream_Modules/g;
s/\bStream_Node\b/ACE_Stream_Node/g;
s/\bStream_Tail\b/ACE_Stream_Tail/g;
s/\bSTREAM_Type\b/ACE_STREAM_Type/g;
s/\bSuspend_Node\b/ACE_Suspend_Node/g;
s/\bSvc_Handler\b/ACE_Svc_Handler/g;
s/\bSvc_Manager\b/ACE_Svc_Manager/g;
s/\bSvc_Tuple\b/ACE_Svc_Tuple/g;
s/\bSynch\b/ACE_Synch/g;
s/\bSynch_Options\b/ACE_Synch_Options/g;
s/\bTHR_FUNC\b/ACE_THR_FUNC/g;
s/\bTLI\b/ACE_TLI/g;
s/\bTLI_Acceptor\b/ACE_TLI_Acceptor/g;
s/\bTLI_Connector\b/ACE_TLI_Connector/g;
s/\bTLI_Stream\b/ACE_TLI_Stream/g;
s/\bTask\b/ACE_Task/g;
s/\bThread\b/ACE_Thread/g;
s/\bThread_Control\b/ACE_Thread_Control/g;
s/\bThread_Manager\b/ACE_Thread_Manager/g;
s/\bThread_Mutex\b/ACE_Thread_Mutex/g;
s/\bThread_Spawn\b/ACE_Thread_Spawn/g;
s/\bThread_Specific\b/ACE_Thread_Specific/g;
s/\bThru_Task\b/ACE_Thru_Task/g;
s/\bTime_Value\b/ACE_Time_Value/g;
s/\bTimer_Handle\b/ACE_Timer_Handle/g;
s/\bTimer_Queue\b/ACE_Timer_Queue/g;
s/\bToken\b/ACE_Token/g;
s/\bTrace\b/ACE_Trace/g;
s/\bTry_Guard\b/ACE_Try_Guard/g;
s/\bTyped_SV_Message\b/ACE_Typed_SV_Message/g;
s/\bTyped_SV_Message_Queue\b/ACE_Typed_SV_Message_Queue/g;
s/\bUNIX_Addr\b/ACE_UNIX_Addr/g;
s/\bUPIPE\b/ACE_UPIPE/g;
s/\bUPIPE_Addr\b/ACE_UPIPE_Addr/g;
s/\bUPIPE_Stream\b/ACE_UPIPE_Stream/g;
s/\bUPIPE_Acceptor\b/ACE_UPIPE_Acceptor/g;
s/\bUPIPE_Connector\b/ACE_UPIPE_Connector/g;
s/\bWrite_Guard\b/ACE_Write_Guard/g;
s@ace/ACE_@ace/@g;
