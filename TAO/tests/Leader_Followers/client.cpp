// $Id$

// ================================================================
//
// = FILENAME
//     client.cpp
//
// = DESCRIPTION
//     See README.
//
// = AUTHOR
//     Irfan Pyarali
//
// ================================================================

#include "ace/Get_Opt.h"
#include "ace/Read_Buffer.h"
#include "ace/Task.h"
#include "testC.h"

ACE_RCSID(Leader_Followers, client, "$Id$")

  // Name of file contains ior.
  static const char *IOR = "file://ior";

// Number of client threads.
static int number_of_client_threads = 5;

// Number of event loop threads.
static int number_of_event_loop_threads = 1;

// Amount of remote work (in milli seconds).
static u_long remote_work = 5000;

// Run event loop for this much time (in milli seconds).
static u_long event_loop_timeout = 7000;

// Flag indicates whether to shutdown remote server or not upon client
// shutdown.
static int shutdown_server = 0;

static int
parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "k:c:e:w:t:x");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        IOR = get_opts.optarg;
        break;

      case 'c':
        number_of_client_threads = ::atoi (get_opts.optarg);
        break;

      case 'e':
        number_of_event_loop_threads = ::atoi (get_opts.optarg);
        break;

      case 't':
        event_loop_timeout = ::atoi (get_opts.optarg);
        break;

      case 'w':
        remote_work = ::atoi (get_opts.optarg);
        break;

      case 'x':
        shutdown_server = 1;
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k IOR "
                           "-c number of client threads "
                           "-e number of event loop threads "
                           "-t event loop timeout "
                           "-w remote work "
                           "-x shutdown server "
                           "\n",
                           argv [0]),
                          -1);
      }

  if (IOR == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Please specify the IOR for the servant\n"), -1);

  // Indicates successful parsing of command line.
  return 0;
}

class Client_Task : public ACE_Task_Base
{
public:
  Client_Task (test_ptr t)
    : test_ (test::_duplicate (t)),
      work_so_far_ (0),
      sleep_ (0)
    {
    }

  int svc (void)
    {
      ACE_DECLARE_NEW_CORBA_ENV;

      ACE_TRY
        {
          u_long work_from_this_thread = 0;
          ACE_Time_Value sleep_for_this_thread;

          {
            ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);

            this->work_so_far_ += remote_work / number_of_client_threads;
            work_from_this_thread = this->work_so_far_;

            sleep_for_this_thread.msec (this->sleep_);
            this->sleep_ += 1000 / number_of_client_threads;
          }

          // Small pause to avoid overrunning the server.
          ACE_OS::sleep (sleep_for_this_thread);

          // Invoke the method.
          ACE_DEBUG ((LM_DEBUG,
                      "Client: Invoking server from thread %t for time %d @ %T\n",
                      work_from_this_thread));

          CORBA::ULong result = this->test_->method (work_from_this_thread,
                                                     ACE_TRY_ENV);
          ACE_TRY_CHECK;

          if (work_from_this_thread != result)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "Client: result is %d\n", result));
              ACE_ASSERT (work_from_this_thread == result);
            }

          ACE_DEBUG ((LM_DEBUG, "Client: client loop finished for thread %t @ %T\n"));
        }
      ACE_CATCHANY
        {
          ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                               "Exception caught in thread:");
          return -1;
        }
      ACE_ENDTRY;

      ACE_CHECK_RETURN (-1);

      return 0;
    }

private:
  test_var test_;
  // server reference.

  u_long work_so_far_;
  // Work counter.

  ACE_SYNCH_MUTEX lock_;
  // Lock for work counter.

  u_long sleep_;
  // Small pause to avoid overrunning the server.
};

class Event_Loop_Task : public ACE_Task_Base
{
public:
  Event_Loop_Task (CORBA::ORB_ptr orb)
    :  orb_ (CORBA::ORB::_duplicate (orb)),
       event_loop_timeout_so_far_ (0)
    {
    }

  int svc (void)
    {
      ACE_DECLARE_NEW_CORBA_ENV;

      ACE_TRY
        {
          u_long event_loop_timeout_for_this_thread = 0;

          {
            ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, -1);

            this->event_loop_timeout_so_far_ += event_loop_timeout / number_of_event_loop_threads;
            event_loop_timeout_for_this_thread = this->event_loop_timeout_so_far_;
          }

          ACE_DEBUG ((LM_DEBUG,
                      "Client: Event loop thread %t starting event loop for %d milli seconds @ %T\n",
                      event_loop_timeout_for_this_thread));

          ACE_Time_Value timeout (0,
                                  event_loop_timeout_for_this_thread * 1000);

          if (this->orb_->run (timeout,
                               ACE_TRY_ENV) == -1)
            ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "orb->run"), -1);
          ACE_TRY_CHECK;

          ACE_DEBUG ((LM_DEBUG, "Client: Event loop finished for thread %t @ %T\n"));
        }
      ACE_CATCHANY
        {
          ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                               "Exception caught in thread:");
          return -1;
        }
      ACE_ENDTRY;

      ACE_CHECK_RETURN (-1);

      return 0;
    }

private:
  CORBA::ORB_var orb_;
  // ORB reference.

  u_long event_loop_timeout_so_far_;
  // Event loop timeout counter.

  ACE_SYNCH_MUTEX lock_;
  // Lock for event loop timeout counter.
};

int
main (int argc, char **argv)
{
  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      // Initialize the ORB.
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc,
                         argv,
                         0,
                         ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Initialize options based on command-line arguments.
      int parse_args_result = parse_args (argc, argv);
      if (parse_args_result != 0)
        return parse_args_result;

      CORBA::Object_var object =
        orb->resolve_initial_references ("RootPOA",
                                         ACE_TRY_ENV);
      ACE_TRY_CHECK;

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (object.in (),
                                      ACE_TRY_ENV);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      poa_manager->activate (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Get an object reference from the argument string.
      object = orb->string_to_object (IOR,
                                      ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Try to narrow the object reference to a <server> reference.
      test_var server = test::_narrow (object.in (),
                                       ACE_TRY_ENV);
      ACE_TRY_CHECK;

      Client_Task client_task (server.in ());

      if (client_task.activate (THR_NEW_LWP | THR_JOINABLE,
                                number_of_client_threads) != 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot activate client threads\n"),
                          -1);

      // Make sure to give the client threads enough time to become
      // leaders.
      ACE_OS::sleep (4);

      Event_Loop_Task event_loop_task (orb.in ());

      if (event_loop_task.activate (THR_NEW_LWP | THR_JOINABLE,
                                    number_of_event_loop_threads) != 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot activate event_loop threads\n"),
                          -1);

      event_loop_task.thr_mgr ()->wait ();
      client_task.thr_mgr ()->wait ();

      ACE_DEBUG ((LM_DEBUG, "Client: All threads finished @ %T\n"));

      // Shutdown server.
      if (shutdown_server)
        {
          server->shutdown (ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }

      root_poa->destroy (1,
                         1,
                         ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception caught:");
      return -1;
    }
  ACE_ENDTRY;

  ACE_CHECK_RETURN (-1);

  return 0;
}
