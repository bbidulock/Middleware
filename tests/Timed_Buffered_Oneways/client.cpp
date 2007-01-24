// $Id$

// ================================================================
//
// = FILENAME
//     client.cpp
//
// = DESCRIPTION
//     This is a client that uses oneways with buffering constraints
//     and roundtrip timeout constraints.
//
// = AUTHOR
//     Irfan Pyarali
//
// ================================================================

#include "testC.h"

#include "tao/Messaging/Messaging.h"
#include "tao/AnyTypeCode/TAOA.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/TAOC.h"
#include "ace/Get_Opt.h"
#include "ace/Read_Buffer.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_time.h"

ACE_RCSID(Timed_Buffered_Oneways, client, "$Id$")

// Eager buffering option.
static int eager_buffering = 0;

// Name of file contains ior.
static const char *IOR = "file://ior";

// Default iterations.
static u_long iterations = 20;

// Default number of bytes to send as data.
static CORBA::ULong data_bytes = 100000;

// Default roundtrip timeout (in milli seconds).
static long timeout = 500;

// Default amount of work.
static CORBA::ULong work = 3000;

// Time interval between invocation (in milli seconds).
static u_long interval = 500;

// Flag indicates whether to shutdown remote server or not upon client
// shutdown.
static int shutdown_server = 0;

static int
parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "ek:i:d:t:w:z:x");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'e':
        eager_buffering = 1;
        break;

      case 'k':
        IOR = get_opts.opt_arg ();
        break;

      case 'i':
        iterations = ::atoi (get_opts.opt_arg ());
        break;

      case 'd':
        data_bytes = ::atoi (get_opts.opt_arg ());
        break;

      case 't':
        timeout = ::atoi (get_opts.opt_arg ());
        break;

      case 'w':
        work = ::atoi (get_opts.opt_arg ());
        break;

      case 'z':
        interval = ::atoi (get_opts.opt_arg ());
        break;

      case 'x':
        shutdown_server = 1;
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-e eager buffering [default is delayed] "
                           "-k IOR "
                           "-i iterations "
                           "-d data bytes "
                           "-t roundtrip timeout "
                           "-w remote work "
                           "-z interval between calls "
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

test_ptr
setup_policies (CORBA::ORB_ptr orb, test_ptr object ACE_ENV_ARG_DECL)
{

  test_var object_with_policy;
  CORBA::PolicyList policy_list (1);
  if (timeout == -1)
    {
      object_with_policy = test::_duplicate (object);
    }
  else
    {
      policy_list.length (1);
      TimeBase::TimeT rt_timeout = 10 * 1000 * timeout;

      CORBA::Any rt_timeout_any;
      rt_timeout_any <<= rt_timeout;
      policy_list[0] =
        orb->create_policy (Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE,
                            rt_timeout_any
                            ACE_ENV_ARG_PARAMETER);

      CORBA::Object_var object_temp =
        object->_set_policy_overrides (policy_list,
                                       CORBA::ADD_OVERRIDE
                                       ACE_ENV_ARG_PARAMETER);

      object_with_policy = test::_narrow (object_temp.in ()
                                          ACE_ENV_ARG_PARAMETER);

      policy_list[0]->destroy ();
    }

  Messaging::SyncScope sync =
    eager_buffering ? TAO::SYNC_EAGER_BUFFERING : TAO::SYNC_DELAYED_BUFFERING;

  CORBA::Any sync_any;
  sync_any <<= sync;

  policy_list.length (1);
  policy_list[0] =
    orb->create_policy (Messaging::SYNC_SCOPE_POLICY_TYPE,
                        sync_any
                        ACE_ENV_ARG_PARAMETER);

  CORBA::Object_var object_temp =
    object_with_policy->_set_policy_overrides (policy_list,
                                               CORBA::ADD_OVERRIDE
                                               ACE_ENV_ARG_PARAMETER);

  test_var object_with_two_policies = test::_narrow (object_temp.in ()
                                                     ACE_ENV_ARG_PARAMETER);

  policy_list[0]->destroy ();

  return object_with_two_policies._retn ();
}

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
                         0
                         ACE_ENV_ARG_PARAMETER);

      // Initialize options based on command-line arguments.
      int parse_args_result = parse_args (argc, argv);
      if (parse_args_result != 0)
        return parse_args_result;

      // Get an object reference from the argument string.
      CORBA::Object_var object =
        orb->string_to_object (IOR
                               ACE_ENV_ARG_PARAMETER);

      // Try to narrow the object reference to a <test> reference.
      test_var test_object_no_policy = test::_narrow (object.in ()
                                                      ACE_ENV_ARG_PARAMETER);

      // Setup buffering and timeout
      test_var test_object = setup_policies (orb.in (),
                                             test_object_no_policy.in ()
                                             ACE_ENV_ARG_PARAMETER);

      test::data the_data (data_bytes);
      the_data.length (data_bytes);

      for (CORBA::ULong i = 1; i <= iterations; ++i)
        {
          ACE_Time_Value start = ACE_OS::gettimeofday ();
          // Invoke the oneway method.
          test_object->method (i,
                               start.msec (),
                               the_data,
                               work
                               ACE_ENV_ARG_PARAMETER);

          ACE_Time_Value end = ACE_OS::gettimeofday ();

          ACE_DEBUG ((LM_DEBUG,
                      "client:\t%d took\t%dms\n",
                      i, (end - start).msec ()));

          // Interval between successive calls.
          ACE_Time_Value sleep_interval (0, interval * 1000);

          // If we don't run the orb, then no data will be sent, and no
          // connection will be made initially.
          orb->run (sleep_interval ACE_ENV_ARG_PARAMETER);
        }

      ACE_DEBUG ((LM_DEBUG, "client: flushing\n"));
      test_object_no_policy->flush ();

      ACE_DEBUG ((LM_DEBUG, "client: Shutting down...\n"));
      if (shutdown_server)
        {
          ACE_DEBUG ((LM_DEBUG,"client killing server\n"));
          long now = ACE_OS::gettimeofday ().msec ();
          test_object_no_policy->shutdown (now ACE_ENV_ARG_PARAMETER);
        }

      orb->shutdown (1 ACE_ENV_ARG_PARAMETER);

      // Destroy the ORB.  On some platforms, e.g., Win32, the socket
      // library is closed at the end of main().  This means that any
      // socket calls made after main() fail. Hence if we wait for
      // static destructors to flush the queues, it will be too late.
      // Therefore, we use explicit destruction here and flush the
      // queues before main() ends.
      orb->destroy ();
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Client side exception caught:");
      return -1;
    }
  ACE_ENDTRY;


  return 0;
}
