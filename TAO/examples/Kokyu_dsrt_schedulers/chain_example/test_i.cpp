//$Id$

#include "test_i.h"
#include "ace/High_Res_Timer.h"
#include "ace/Task.h"
#include "ace/ACE.h"
#include "tao/debug.h"
#include "EDF_Scheduler.h"
#include "orbsvcs/orbsvcs/Time_Utilities.h"
#include "Task_Stats.h"
#include "cpuload.h"

#if defined (ACE_HAS_DSUI)
#include <ace/Counter.h>
#include "chain_config.h"
#include "chain_dsui_families.h"
#include <dsui.h>
#endif // ACE_HAS_DSUI

#if !defined(__ACE_INLINE__)
#include "test_i.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(MT_Server, test_i, "test_i.cpp,v 1.2 2003/10/08 13:26:32 venkita Exp")

void
Simple_Server_i::test_method (CORBA::Long exec_duration ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Policy_ptr sched_policy =
    this->current_->scheduling_parameter(ACE_ENV_SINGLE_ARG_PARAMETER);

  EDF_Scheduling::SchedulingParameterPolicy_var sched_param_policy =
  EDF_Scheduling::SchedulingParameterPolicy::_narrow (sched_policy);

  EDF_Scheduling::SchedulingParameter_var sched_param = sched_param_policy->value ();

  ACE_hthread_t thr_handle;
  ACE_Thread::self (thr_handle);
  int prio;
  int guid;

  ACE_OS::
    memcpy (&guid,
            this->current_->id (ACE_ENV_SINGLE_ARG_PARAMETER)->get_buffer (),
            sizeof (this->current_->id (ACE_ENV_SINGLE_ARG_PARAMETER)->length ()));

  Object_ID oid;
  oid.id=sched_param->id;
  oid.pid=sched_param->pid;
  oid.tid=sched_param->tid;
  oid.task_id=sched_param->task_id;
  oid.guid=guid;
  DSTRM_EVENT (TEST_ONE_FAM, START_SERVICE, 0, sizeof(Object_ID), (char*)&oid);

  ACE_High_Res_Timer timer;
  ACE_Time_Value elapsed_time;

  ACE_DEBUG ((LM_DEBUG, "Request in thread %t\n"));

  if (ACE_Thread::getprio (thr_handle, prio) == -1)
    {
      if (errno == ENOTSUP)
	{
	  ACE_DEBUG((LM_DEBUG,
		     ACE_TEXT ("getprio not supported on this platform\n")
		     ));
	  return; 
	}
      ACE_ERROR ((LM_ERROR,
			 ACE_TEXT ("%p\n"),
			 ACE_TEXT ("getprio failed")));
      return;
    }

  ACE_DEBUG ((LM_DEBUG, 
              "Request in thread %t, prio = %d,"
              "exec duration = %u\n", prio, exec_duration));


  //Applicable only for CV based implementations
  //yield every 1 sec

timer.start();
timeval tv;

tv.tv_sec = exec_duration/1000;
tv.tv_usec = (exec_duration%1000)*1000;

CPULoad::run(tv);
 
  timer.stop ();
  timer.elapsed_time (elapsed_time);
  
  ACE_DEBUG ((LM_DEBUG, 
	      "Request processing in thread %t done, "
	      "prio = %d, load = %d, elapsed time = %umsec\n", 
	      prio, exec_duration, elapsed_time.msec () ));
  DSTRM_EVENT (TEST_ONE_FAM, STOP_SERVICE, 0, sizeof(Object_ID), (char*)&oid);

  const char * name = 0;
  EDF_Scheduling::SchedulingParameterPolicy_var implicit_sched_param;
  //If we do not define implicit_sched_param, the new spawned DT will have the default lowest prio.
  implicit_sched_param = sched_param_policy;

  DSTRM_EVENT (WORKER_GROUP_FAM, BEGIN_SCHED_SEGMENT, 0, sizeof(Object_ID), (char*)&oid);
  this->current_->begin_scheduling_segment (name,
                                                    sched_param_policy.in (),
                                                    implicit_sched_param.in ()
                                                    ACE_ENV_ARG_PARAMETER);
  DSTRM_EVENT (WORKER_GROUP_FAM, END_SCHED_SEGMENT, 0, sizeof(Object_ID), (char*)&oid);
    
  DSTRM_EVENT (WORKER_GROUP_FAM, ONE_WAY_CALL_START, 0, sizeof(Object_ID), (char*)&oid);
  this->server_->test_method2(exec_duration);
  DSTRM_EVENT (WORKER_GROUP_FAM, ONE_WAY_CALL_DONE, 0, sizeof(Object_ID), (char*)&oid);
  this->current_->end_scheduling_segment (name);
}

void
Simple_Server_i::shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG, "shutdown request from client\n"));
  this->server_->shutdown();
  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
}
