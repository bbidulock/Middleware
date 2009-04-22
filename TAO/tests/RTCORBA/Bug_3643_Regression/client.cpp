// $Id$

#include "ace/Get_Opt.h"
#include "testC.h"
#include "tao/RTCORBA/RTCORBA.h"
#include "tao/ORB_Core.h"
#include "ace/Task.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_time.h"

ACE_RCSID(Thread_Pool, client, "$Id$")

const ACE_TCHAR *ior = "file://ior_1";
int iterations = 1000;
int shutdown_server = 0;
bool decreased = false;

const char *
sched_policy_name (int sched_policy)
{
  const char *name = 0;

  switch (sched_policy)
    {
    case ACE_SCHED_OTHER:
      name = "SCHED_OTHER";
      break;
    case ACE_SCHED_RR:
      name = "SCHED_RR";
      break;
    case ACE_SCHED_FIFO:
      name = "SCHED_FIFO";
      break;
    }

  return name;
}

int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "xk:i:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'x':
        shutdown_server = 1;
        break;

      case 'k':
        ior = get_opts.opt_arg ();
        break;

      case 'i':
        iterations = ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k <ior> "
                           "-i <iterations> "
                           "-x [shutdown server] "
                           "\n",
                           argv [0]),
                          -1);
      }

  // Indicates sucessful parsing of the command line
  return 0;
}

class Task : public ACE_Task_Base
{
public:

  Task (ACE_Thread_Manager &thread_manager,
        CORBA::ORB_ptr orb);

  int svc (void);

  CORBA::ORB_var orb_;

};

Task::Task (ACE_Thread_Manager &thread_manager,
            CORBA::ORB_ptr orb)
  : ACE_Task_Base (&thread_manager),
    orb_ (CORBA::ORB::_duplicate (orb))
{
}

int
Task::svc (void)
{
  try
    {
      CORBA::Object_var object =
        this->orb_->string_to_object (ior);

      test_var test =
        test::_narrow (object.in ());

      pid_t pid =
        ACE_OS::getpid ();

      CORBA::Long tc = 0;

      struct timespec millis;
      millis.tv_sec  = 0L;
      millis.tv_nsec = 50 * 1000000L; // 1e6 nanos per milli

      ACE_hrtime_t start = ACE_OS::gethrtime();

      for (int i = 0; i != iterations; ++i)
        {
          // ~20 req/sec means to sleep 50 millis between each
          ACE_OS::nanosleep(&millis); // ignore signals

          CORBA::Long mtc = 0;
          CORBA::Long r =
            test->method (pid,
                          i,
                          mtc);

          ACE_ASSERT (r == i);
          // Assert disappears on with optimizations on.
          ACE_UNUSED_ARG (r);

          if (mtc > tc)
            {
              // Number of threads increased, so store this.
              ACE_DEBUG ((LM_DEBUG, "Thread count increased to %d\n", mtc));
              tc = mtc;
            }
          else if (mtc < tc)
            {
              // Number of threads decreased!
              ACE_DEBUG ((LM_DEBUG, "Thread count decreased to %d\n", mtc));
              decreased = true;
              tc = mtc;
            }
        }
      ACE_hrtime_t duration = ACE_OS::gethrtime() - start;
      double tp = ((double) iterations) / (duration / 1000000);
      tp *= 1000.0;
      ACE_DEBUG ((LM_DEBUG, "Throughput: %d\n", tp));

      ACE_OS::sleep (10);

      CORBA::Long end = 0;
      CORBA::Long re =
        test->method (pid,
                      0,
                      end);

      ACE_ASSERT (re == 0);
      // Assert disappears on with optimizations on.
      ACE_UNUSED_ARG (re);

      if (end != 0)
        {
          ACE_ERROR ((LM_ERROR, "Dynamic thread count should be 0, not %d\n", end));
        }

      if (shutdown_server)
        {
          test->shutdown ();
        }
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return -1;
    }

  return 0;
}

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  try
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv);

      int result =
        parse_args (argc, argv);
      if (result != 0)
        return result;

      // Thread Manager for managing task.
      ACE_Thread_Manager thread_manager;

      // Create task.
      Task task (thread_manager,
                 orb.in ());

      // Task activation flags.
      long flags =
        THR_NEW_LWP |
        THR_JOINABLE |
        orb->orb_core ()->orb_params ()->thread_creation_flags ();

      // Activate task.
      result = task.activate (flags);

      if (result == -1)
        {
          if (errno == EPERM)
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Cannot create thread with scheduling policy %s\n"
                                 "because the user does not have the appropriate privileges, terminating program....\n"
                                 "Check svc.conf options and/or run as root\n",
                                 sched_policy_name (orb->orb_core ()->orb_params ()->ace_sched_policy ())),
                                2);
            }
          else
            // Unexpected error.
            ACE_ASSERT (0);
        }

      // Wait for task to exit.
      result =
        thread_manager.wait ();
      ACE_ASSERT (result != -1);

      if (decreased == false)
        {
          ACE_ERROR_RETURN ((LM_ERROR, "ERROR: Number of threads didn't decrease\n"), -1);
        }
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught");
      return -1;
    }

  return 0;
}
