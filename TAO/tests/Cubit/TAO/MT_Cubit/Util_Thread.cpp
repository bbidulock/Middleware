// $Id$

#include "Util_Thread.h"

Util_Thread::Util_Thread (Task_State *ts,
                          ACE_Thread_Manager *thr_mgr)
  : ACE_MT (ACE_Task<ACE_MT_SYNCH> (thr_mgr)),
    done_ (0),
    number_of_computations_ (0),
    ts_ (ts)
{
}

int
Util_Thread::svc (void)
{
  // On Solaris 2.5.x, the LWP priority needs to be set.  This is the
  // ACE way to do that . . .
  ACE_hthread_t thr_handle;
  ACE_Thread::self (thr_handle);
  int prio;

  if (ACE_Thread::getprio (thr_handle, prio) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "getprio failed"), -1);

  ACE_DEBUG ((LM_DEBUG, "(%P|%t): Util_Thread::svc; set my priority to %d\n",
              prio));
  ACE_OS::thr_setprio (prio);

  ACE_DEBUG ((LM_DEBUG,
              "(%t) Utilization Thread created, "
              "waiting for threads to finish binding\n"));

  // this barrier synchronizes the utilization thread with 
  // the client threads
  // i.e., the Util_thread should wait until all the 
  // clients have finished binding, and only then
  // start measuring the utilization. 
  this->ts_->barrier_->wait ();

  ACE_DEBUG ((LM_DEBUG,
              "(%t) Threads have bound, "
              "utilization test started\n"));

  this->run_computations ();

  return 0;
}

double
Util_Thread::get_number_of_computations (void)
{
  return this->number_of_computations_;
}

// computation performed by the Utilization thread.  We need this in a
// separate function to get it's execution time.
//inline
void
Util_Thread::computation (void)
{
  // See if this number is prime. 2 and CUBIT_ARBIT_NUMBER / 2 are
  // the recommended values for min_factor and max_factor, as
  // explained in ACE.h (is_prime).
  ACE::is_prime (CUBIT_ARBIT_NUMBER,
		 2,
		 CUBIT_ARBIT_NUMBER / 2);
}

// Perform repeated prime factor computations on an arbitrary number.
// And you thought your life was boring... :-)
int
Util_Thread::run_computations (void)
{
  while (this->done_ == 0)
    {
      this->computation ();
      this->number_of_computations_ ++;
      ACE_OS::thr_yield (); // Shouldn't need this.  And I'm not sure
                            // if it really helps.
    }

  return 0;
}
