//$Id$
#include "Thread_Task.h"

#include "ace/High_Res_Timer.h"
#include "tao/debug.h"

#include "Activity.h"
#include "Task_Stats.h"

Thread_Task::Thread_Task (void)
{
}

int
Thread_Task::activate_task (ACE_Barrier* barrier)
{
  barrier_ = barrier;

  long flags = THR_NEW_LWP | THR_JOINABLE;

  flags |=
    ACTIVITY::instance()->scope_policy () |
    ACTIVITY::instance()->sched_policy ();

  // Become an active object.
  if (this->ACE_Task <ACE_SYNCH>::activate (flags,
                                            1,
                                            0,
                                            this->task_priority_) == -1)
       {
         if (ACE_OS::last_error () == EPERM)
           ACE_ERROR_RETURN ((LM_ERROR,
                              ACE_TEXT ("Insufficient privilege to run this test.\n")),
                             -1);
         else
           ACE_DEBUG ((LM_ERROR,
                       ACE_TEXT ("(%t) task activation at priority %d failed, ")
                        ACE_TEXT ("exiting!\n%a"),
                       this->task_priority_,
                       -1));
       }
  return 0;
}

int
Thread_Task::svc (void)
{
  // if debugging, dump the priority that we're actually at.
  if (TAO_debug_level > 0)
    {
      TAO_ENV_DECLARE_NEW_ENV;
      // Get the priority of the current thread.
      RTCORBA::Priority prio =
        ACTIVITY::instance()->current ()->the_priority (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (-1);

      if (prio == this->task_priority_)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("(%t) actual prio of %d equals desired priority\n"),
                    prio));
      else
        {
          ACE_DEBUG ((LM_ERROR,
                      ACE_TEXT ("(%t) actual prio = %d, desired priority_ = %d!\n"),
                      prio,
                      this->task_priority_));
        }
    }

  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG, "Thread_Task (%t) - wait\n"));

  // First, wait for other threads.
  this->barrier_->wait ();

  // first thread here inits the Base_Time.
  task_stats_->base_time (BASE_TIME::instance ()->base_time_);

  // now wait till the phase_ period expires.
  ACE_OS::sleep (ACE_Time_Value (0, phase_));

  ACE_UINT32 gsf = ACE_High_Res_Timer::global_scale_factor ();

  ACE_hrtime_t before, after;

  for (int i = 0; i < iter_ ; ++i)
    {
      before = ACE_OS::gethrtime ();

      job_->work (load_);

      after = ACE_OS::gethrtime ();

      task_stats_->sample (before, after);

      if (period_ != 0) // blast mode, no sleep.
        {
          // convert to microseconds
#if !defined ACE_LACKS_LONGLONG_T

          ACE_UINT32 elapsed_microseconds = ACE_UINT32((after - before) / gsf);

#else  /* ! ACE_LACKS_LONGLONG_T */

          ACE_UINT32 elapsed_microseconds = (after - before) / gsf;

#endif /* ! ACE_LACKS_LONGLONG_T */

#if defined (ACE_WIN32)
          elapsed_microseconds*=1000; // convert to uSec on Win32
#endif /* ACE_WIN32 */

      // did we miss any deadlines?

          int missed =
            elapsed_microseconds > period_ ? elapsed_microseconds/period_ : 0;

          long sleep_time = (missed + 1)*period_ ;
          sleep_time -= elapsed_microseconds;

          if (TAO_debug_level > 0)
            ACE_DEBUG ((LM_DEBUG, "(%t) sleep time = %d\n", sleep_time));

          ACE_Time_Value t_sleep (0, sleep_time);
          ACE_OS::sleep (t_sleep);
        } /* period != 0 */
    } /* for */

  task_stats_->end_time (ACE_OS::gethrtime ());

  job_->shutdown (); // tell the job that we're done.

  ACTIVITY::instance ()->task_ended (this);

  return 0;
}
