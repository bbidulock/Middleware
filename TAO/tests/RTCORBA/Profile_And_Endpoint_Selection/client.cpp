// $Id$

// ================================================================
//
//
// = FILENAME
//     client.cpp
//
// = DESCRIPTION
//     This is a client implementation.
//
// = AUTHOR
//     Irfan Pyarali
//
// ================================================================

#include "ace/Get_Opt.h"
#include "ace/Task.h"
#include "tao/RTCORBA/RTCORBA.h"
#include "tao/Strategies/advanced_resource.h"
#include "../common_args.cpp"
#include "testC.h"

ACE_RCSID(Profile_And_Endpoint_Selection, client, "$Id$")

static int iterations = 1;
static int debug = 1;
static int shutdown_server = 0;
static const char *ior = "file://ior";
static const char *invocation_priorities_file = "empty_file";
static const char *protocols_file = "empty_file";
static const char *bands_file = "empty_file";

static int
parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "b:d:i:k:p:t:x");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'b':
        bands_file = get_opts.opt_arg ();
        break;

      case 'd':
        debug = ::atoi (get_opts.opt_arg ());
        break;

      case 'i':
        iterations = ::atoi (get_opts.opt_arg ());
        break;

      case 'k':
        ior = get_opts.opt_arg ();
        break;

      case 'p':
        protocols_file = get_opts.opt_arg ();
        break;

      case 't':
        invocation_priorities_file = get_opts.opt_arg ();
        break;

      case 'x':
        shutdown_server = 1;
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%s usage: \n"
                           "\t-b <bands file> (defaults to %s)\n"
                           "\t-i <iterations> (defaults to %d)\n"
                           "\t-k <ior> (defaults to %s)\n"
                           "\t-p <protocol file> (defaults to %s)\n"
                           "\t-t <invocation priorities file> (defaults to %s)\n"
                           "\t-x <shutdown server> (defaults to %d)\n"
                           "\n",
                           argv[0],
                           bands_file,
                           iterations,
                           ior,
                           protocols_file,
                           invocation_priorities_file,
                           shutdown_server),
                          -1);
      }

  return 0;
}

void
vanilla_invocations (test_ptr test
                     ACE_ENV_ARG_DECL);

class Worker_Thread : public ACE_Task_Base
{
public:
  Worker_Thread (test_ptr test,
                 RTCORBA::Current_ptr current,
                 CORBA::Short priority);

  int svc (void);

  void validate_connection (ACE_ENV_SINGLE_ARG_DECL);

private:
  test_var test_;
  RTCORBA::Current_var current_;
  CORBA::Short priority_;
};

Worker_Thread::Worker_Thread (test_ptr test,
                              RTCORBA::Current_ptr current,
                              CORBA::Short priority)
  : test_ (test::_duplicate (test)),
    current_ (RTCORBA::Current::_duplicate (current)),
    priority_ (priority)
{
}

void
Worker_Thread::validate_connection (ACE_ENV_SINGLE_ARG_DECL)
{
  // Try to validate the connection several times, ignoring transient
  // exceptions.  If the connection can still not be setup, return
  // failure.
  CORBA::PolicyList_var inconsistent_policies;
  int max_attempts = 10;
  int current_attempt = 0;
  for (;;)
    {
      ACE_TRY
        {
          ++current_attempt;
          this->test_->_validate_connection (inconsistent_policies.out ()
                                             ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          // If successful, we are done.
          return;
        }
      ACE_CATCH (CORBA::TRANSIENT, exception)
        {
          // If we have reach our maximum number of tries, throw exception.
          if (current_attempt == max_attempts)
            ACE_RE_THROW;
          // Otherwise, ignore...
        }
      ACE_CATCHANY
        {
          // Rethrow any other exceptions.
          ACE_RE_THROW;
        }
      ACE_ENDTRY;
      ACE_CHECK;
    }
}

int
Worker_Thread::svc (void)
{
  ACE_TRY_NEW_ENV
    {
      this->current_->the_priority (this->priority_
                                    ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      this->validate_connection (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      vanilla_invocations (this->test_.in ()
                           ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Worker Thread exception:");
    }
  ACE_ENDTRY;
  return 0;
}

void
vanilla_invocations (test_ptr test
                     ACE_ENV_ARG_DECL)
{
  for (int i = 0; i < iterations; i++)
    {
      test->method (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }
}

void
priority_invocations (RTCORBA::RTORB_ptr rt_orb,
                      CORBA::ORB_ptr orb,
                      CORBA::PolicyManager_ptr policy_manager,
                      RTCORBA::Current_ptr current,
                      test_ptr test,
                      int debug
                      ACE_ENV_ARG_DECL)
{
  ULong_Array priorities;
  int result =
    get_values ("client",
                invocation_priorities_file,
                "invocation priorities",
                priorities,
                debug);
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "Error in parsing invocation priorities data file: %s\n",
                  invocation_priorities_file));
      return;
    }

  u_long i = 0;

  Worker_Thread **workers = 0;

  ACE_NEW (workers,
           Worker_Thread *[priorities.size ()]);

  for (i = 0;
       i < priorities.size ();
       ++i)
    {
      ACE_NEW (workers[i],
               Worker_Thread (test,
                              current,
                              priorities[i]));

      long flags =
        THR_NEW_LWP |
        THR_JOINABLE |
        orb->orb_core ()->orb_params ()->scope_policy () |
        orb->orb_core ()->orb_params ()->sched_policy ();

      result =
        workers[i]->activate (flags);
      if (result != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "Cannot activate thread\n"));
          return;
        }
    }

  ACE_Thread_Manager::instance ()->wait ();

  for (i = 0;
       i < priorities.size ();
       ++i)
    {
      delete workers[i];
    }
  delete[] workers;
}

void
set_client_protocols_policies (RTCORBA::RTORB_ptr rt_orb,
                               CORBA::PolicyManager_ptr policy_manager,
                               int debug
                               ACE_ENV_ARG_DECL)
{
  CORBA::PolicyList policies;

  int result =
    get_protocols ("client",
                   protocols_file,
                   rt_orb,
                   policies,
                   debug
                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "Error in parsing protocols data file: %s\n",
                  protocols_file));
      return;
    }

  policy_manager->set_policy_overrides (policies,
                                        CORBA::ADD_OVERRIDE
                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
set_priority_bands (RTCORBA::RTORB_ptr rt_orb,
                    CORBA::PolicyManager_ptr policy_manager,
                    int debug
                    ACE_ENV_ARG_DECL)
{
  CORBA::PolicyList policies;

  int result =
    get_priority_bands ("client",
                        bands_file,
                        rt_orb,
                        policies,
                        debug
                        ACE_ENV_ARG_PARAMETER);
  ACE_TRY_CHECK;
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "Error in parsing bands data file: %s\n",
                  bands_file));
      return;
    }

  policy_manager->set_policy_overrides (policies,
                                        CORBA::ADD_OVERRIDE
                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
set_private_connection_policies (RTCORBA::RTORB_ptr rt_orb,
                                 CORBA::PolicyManager_ptr policy_manager
                                 ACE_ENV_ARG_DECL)
{
  CORBA::PolicyList policies;
  policies.length (1);

  policies[0] =
    rt_orb->create_private_connection_policy (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  policy_manager->set_policy_overrides (policies,
                                        CORBA::ADD_OVERRIDE
                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
reset_policies (CORBA::PolicyManager_ptr policy_manager
                ACE_ENV_ARG_DECL)
{
  CORBA::PolicyList empty_policies;

  policy_manager->set_policy_overrides (empty_policies,
                                        CORBA::SET_OVERRIDE
                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

int
main (int argc, char **argv)
{
  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc,
                         argv,
                         0
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var object =
        orb->resolve_initial_references ("RTORB"
                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      RTCORBA::RTORB_var rt_orb =
        RTCORBA::RTORB::_narrow (object.in ()
                                 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      object =
        orb->resolve_initial_references ("ORBPolicyManager"
                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::PolicyManager_var policy_manager =
        CORBA::PolicyManager::_narrow (object.in ()
                                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      object =
        orb->resolve_initial_references ("RTCurrent"
                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      RTCORBA::Current_var current =
        RTCORBA::Current::_narrow (object.in ()
                                   ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      current->the_priority (0
                             ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      int parse_args_result =
        parse_args (argc, argv);
      if (parse_args_result != 0)
        return parse_args_result;

      object =
        orb->string_to_object (ior
                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      test_var test =
        test::_narrow (object.in ()
                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      vanilla_invocations (test.in ()
                           ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      set_private_connection_policies (rt_orb.in (),
                                       policy_manager.in ()
                                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      vanilla_invocations (test.in ()
                           ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      reset_policies (policy_manager.in ()
                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      set_client_protocols_policies (rt_orb.in (),
                                     policy_manager.in (),
                                     debug
                                     ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      vanilla_invocations (test.in ()
                           ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      set_private_connection_policies (rt_orb.in (),
                                       policy_manager.in ()
                                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      vanilla_invocations (test.in ()
                           ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      reset_policies (policy_manager.in ()
                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      set_priority_bands (rt_orb.in (),
                          policy_manager.in (),
                          debug
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      priority_invocations (rt_orb.in (),
                            orb.in (),
                            policy_manager.in (),
                            current.in (),
                            test.in (),
                            debug
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      set_private_connection_policies (rt_orb.in (),
                                       policy_manager.in ()
                                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      priority_invocations (rt_orb.in (),
                            orb.in (),
                            policy_manager.in (),
                            current.in (),
                            test.in (),
                            debug
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      reset_policies (policy_manager.in ()
                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      set_priority_bands (rt_orb.in (),
                          policy_manager.in (),
                          debug
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      set_client_protocols_policies (rt_orb.in (),
                                     policy_manager.in (),
                                     0
                                     ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      priority_invocations (rt_orb.in (),
                            orb.in (),
                            policy_manager.in (),
                            current.in (),
                            test.in (),
                            0
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      set_private_connection_policies (rt_orb.in (),
                                       policy_manager.in ()
                                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      priority_invocations (rt_orb.in (),
                            orb.in (),
                            policy_manager.in (),
                            current.in (),
                            test.in (),
                            debug
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      reset_policies (policy_manager.in ()
                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (shutdown_server)
        {
          test->shutdown (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Error!");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}
