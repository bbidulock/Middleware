//
// $Id$
//

ACE_INLINE ACE_Task_Manager::ReactorTask*
ACE_Task_Manager::GetReactorTask(RtecScheduler::OS_Priority priority)
{
  if (reactorTasks[priority] == 0)
    {
      initialize();
      //ACE_ERROR_RETURN ((LM_ERROR,
      //"%p no reactor task for priority %d.\n", 
      //"ACE_Task_Manager::GetReactor",
      //priority), 0);
   }
   
  return reactorTasks[priority];
}

ACE_INLINE ACE_RT_Thread_Manager* ACE_Task_Manager::ThrMgr()
{
  return &thr_mgr;
}

ACE_INLINE ACE_Task_Manager* ACE_Task_Manager::instance()
{
  return ACE_Singleton<ACE_Task_Manager,ACE_SYNCH_MUTEX>::instance();
}


