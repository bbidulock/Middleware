// $Id$

#include "JAWS/Concurrency.h"

JAWS_Dispatcher_Singleton jaws_dispatcher;
JAWS_Thread_Pool_Singleton jaws_thread_pool;
JAWS_Thread_Per_Singleton jaws_thread_per;

JAWS_Concurrency_Base::JAWS_Concurrency_Base (void)
{
}

int
JAWS_Concurrency_Base::put (ACE_Message_Block *mb, ACE_Time_Value *tv)
{
  return this->putq (mb, tv);
}

int
JAWS_Concurrency_Base::svc (void)
{
  int result = 0;

  for (;;)
    {
      ACE_Message_Block *mb;

      // At this point we could set a timeout value so that the
      // threading strategy can delete a thread if there is nothing to
      // do.  Carefully think how to implement it so you don't leave
      // yourself with 0 threads.

      result = this->getq (mb);
      if (result == -1 || mb == 0)
        break;

      this->put_next (mb);
    }
  return 0;
}

JAWS_Dispatch_Policy::JAWS_Dispatch_Policy (void)
{
}

JAWS_Dispatch_Policy::~JAWS_Dispatch_Policy (void)
{
}

JAWS_Dispatcher::JAWS_Dispatcher (JAWS_Dispatch_Policy *policy)
  : policy_(policy)
{
}

JAWS_Thread_Pool_Task::JAWS_Thread_Pool_Task (long flags,
                                              int nthreads,
                                              int maxthreads)
  : nthreads_ (nthreads),
    maxthreads_ (maxthreads)
{
  if (this->activate (flags, nthreads) == -1)
    ACE_ERROR ((LM_ERROR, "%p\n", "JAWS_Thread_Pool_Task::activate"));
}

int
JAWS_Thread_Pool_Task::open (long flags, int nthreads, int maxthreads)
{
  this->nthreads_ = nthreads;
  this->maxthreads_ = maxthreads;

  if (this->activate (flags, nthreads) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "JAWS_Thread_Pool_Task::activate"),
                      -1);
}

JAWS_Thread_Per_Task::JAWS_Thread_Per_Task (long flags, int maxthreads)
  : flags_ (flags),
    maxthreads_ (maxthreads)
{
}

int
JAWS_Thread_Per_Task::open (long flags, int maxthreads)
{
  this->flags_ = flags;
  this->maxthreads_ = maxthreads;
  return 0;
}

int
JAWS_Thread_Per_Task::put (ACE_Message_Block *mb, ACE_Time_Value *tv)
{
  const int force_active = 1;
  const int nthreads = 1;

  if (this->activate (this->flags_, nthreads, force_active) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "JAWS_Thread_Pool_Task::activate"),
                      -1);

  this->putq (mb, tv);

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Singleton<JAWS_Dispatcher, ACE_MT_SYNCH>;
template class ACE_Singleton<JAWS_Thread_Pool_Task, ACE_MT_SYNCH>;
template class ACE_Singleton<JAWS_Thread_Per_Task, ACE_MT_SYNCH>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate  ACE_Singleton<JAWS_Dispatcher, ACE_MT_SYNCH>
#pragma instantiate  ACE_Singleton<JAWS_Thread_Pool_Task, ACE_MT_SYNCH>
#pragma instantiate  ACE_Singleton<JAWS_Thread_Per_Task, ACE_MT_SYNCH>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
