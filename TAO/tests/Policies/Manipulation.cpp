// $Id$

#include "testC.h"

#include "tao/Messaging.h"
#include "tao/TAOC.h"
#include "ace/Get_Opt.h"
#include "ace/Task.h"

ACE_RCSID(Policies, Manipulation, "$Id$")

int nthreads = 5;
int niterations = 100;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "n:i:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'n':
        nthreads = ACE_OS::atoi (get_opts.optarg);
        break;
      case 'i':
        niterations = ACE_OS::atoi (get_opts.optarg);
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-n <nthreads> "
                           "-i <niterations> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

class Manipulation : public ACE_Task_Base
{
  // = TITLE
  //   Run the client thread
  //
  // = DESCRIPTION
  //   Use the ACE_Task_Base class to run the client threads.
  //
public:
  Manipulation (CORBA::ORB_ptr orb,
                Test_ptr test,
                int niterations);
  // ctor

  virtual int svc (void);
  // The thread entry point.

private:
  void perform_iteration (ACE_RANDR_TYPE &seed,
                          CORBA::PolicyList_var &policies,
                          CORBA::PolicyManager_ptr policy_manager,
                          CORBA::PolicyCurrent_ptr policy_current
                          TAO_ENV_ARG_DECL);

private:
  CORBA::ORB_var orb_;
  // The ORB pointer

  Test_var test_;
  // The test object reference

  int niterations_;
  // The number of iterations on this thread
};

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "" TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object ("corbaloc:iiop:localhost:12345/FakeIOR"
                               TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      Test_var test =
        Test::_unchecked_narrow (object.in () TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (test.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Object reference is nil\n"),
                            1);
        }

      Manipulation manipulation (orb.in (),
                     test.in (),
                     niterations);
      if (manipulation.activate (THR_NEW_LWP | THR_JOINABLE,
                           nthreads) != 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot activate manipulation threads\n"),
                          1);

      manipulation.thr_mgr ()->wait ();

      ACE_DEBUG ((LM_DEBUG, "threads finished\n"));

    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Caught exception:");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}

// ****************************************************************

Manipulation::Manipulation (CORBA::ORB_ptr orb,
                Test_ptr test,
                int niterations)
  :  orb_ (CORBA::ORB::_duplicate (orb)),
     test_ (Test::_duplicate (test)),
     niterations_ (niterations)
{
}

void
Manipulation::perform_iteration (ACE_RANDR_TYPE &seed,
                                 CORBA::PolicyList_var &policies,
                                 CORBA::PolicyManager_ptr policy_manager,
                                 CORBA::PolicyCurrent_ptr policy_current
                                 TAO_ENV_ARG_DECL)
{
  ACE_TRY
    {
      int r = ACE_OS::rand_r (seed);

      const int ADD_OBJECT_POLICY  = 0;
      const int ADD_CURRENT_POLICY = 1;
      const int ADD_MANAGER_POLICY = 2;

      const int SET_OBJECT_POLICY  = 3;
      const int SET_CURRENT_POLICY = 4;
      const int SET_MANAGER_POLICY = 5;

      const int SAVE_CURRENT_POLICIES    = 6;
      const int RESTORE_CURRENT_POLICIES = 7;
      const int SAVE_MANAGER_POLICIES    = 8;
      // const int RESTORE_MANAGER_POLICIES = 9;
      const int LAST_OPERATION   = 10;
      int operation = r % LAST_OPERATION;

      if (operation == ADD_OBJECT_POLICY
          || operation == ADD_CURRENT_POLICY
          || operation == ADD_MANAGER_POLICY
          || operation ==  SET_OBJECT_POLICY
          || operation ==  SET_CURRENT_POLICY
          || operation ==  SET_MANAGER_POLICY)
        {
          CORBA::Policy_var policy;

          CORBA::Any any;
          CORBA::ULong policy_type = 0;

          int type = ACE_OS::rand_r (seed) % 3;
          if (type == 0)
            {
              TimeBase::TimeT value = 0;
              any <<= value;

              policy_type =
                Messaging::RELATIVE_RT_TIMEOUT_POLICY_TYPE;
            }
          else if (type == 1)
            {
              TAO::BufferingConstraint value;
              any <<= value;

              policy_type =
                TAO::BUFFERING_CONSTRAINT_POLICY_TYPE;
            }
          else // type == 2 (or something else)
            {
              Messaging::SyncScope value = 0;
              any <<= value;

              policy_type =
                Messaging::SYNC_SCOPE_POLICY_TYPE;
            }

          policy = this->orb_->create_policy (policy_type,
                                              any
                                              TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          CORBA::SetOverrideType override_type = CORBA::SET_OVERRIDE;
          if (operation == ADD_OBJECT_POLICY
              || operation == ADD_CURRENT_POLICY
              || operation == ADD_MANAGER_POLICY)
            {
              override_type = CORBA::ADD_OVERRIDE;
            }

          CORBA::PolicyList policy_list (1);
          policy_list.length (1);
          policy_list[0] = CORBA::Policy::_duplicate (policy.in ());

          if (operation == ADD_OBJECT_POLICY
              || operation == SET_OBJECT_POLICY)
            {
              CORBA::Object_var tmp =
                this->test_->_set_policy_overrides (policy_list,
                                                    override_type
                                                    TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;
            }
          else if (operation == ADD_CURRENT_POLICY
                   || operation == SET_CURRENT_POLICY)
            {
              policy_current->set_policy_overrides (policy_list,
                                                    override_type
                                                    TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;
            }
          else
            {
              // operation == ADD_CURRENT_POLICY
              // || operation == SET_CURRENT_POLICY)
              policy_manager->set_policy_overrides (policy_list,
                                                    override_type
                                                    TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;
            }
          policy_list[0]->destroy (TAO_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      else if (operation == SAVE_CURRENT_POLICIES)
        {
          CORBA::PolicyTypeSeq types;
          policies =
            policy_current->get_policy_overrides (types TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      else if (operation == SAVE_MANAGER_POLICIES)
        {
          CORBA::PolicyTypeSeq types;
          policies =
            policy_manager->get_policy_overrides (types TAO_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      else if (operation == RESTORE_CURRENT_POLICIES)
        {
          if (policies.ptr () != 0)
            {
              policy_current->set_policy_overrides (policies.in (),
                                                    CORBA::SET_OVERRIDE
                                                    TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;
            }
        }
      else // operation == RESTORE_MANAGER_POLICIES)
        {
          if (policies.ptr () != 0)
            {
              policy_manager->set_policy_overrides (policies.in (),
                                                    CORBA::SET_OVERRIDE
                                                    TAO_ENV_ARG_PARAMETER);
              ACE_TRY_CHECK;
            }
        }
    }
  ACE_CATCHANY
    {
      // Ignore all exceptions
    }
  ACE_ENDTRY;
}


int
Manipulation::svc (void)
{
  ACE_TRY_NEW_ENV
    {
#ifndef ACE_LACKS_LONGLONG_T
      ACE_RANDR_TYPE seed =
        ACE_static_cast (ACE_RANDR_TYPE, ACE_OS::gethrtime ());
#else
      ACE_RANDR_TYPE seed =
        ACE_static_cast (ACE_RANDR_TYPE, ACE_OS::gethrtime().lo());
#endif
      CORBA::Object_var object =
        this->orb_->resolve_initial_references ("ORBPolicyManager"
                                                TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::PolicyManager_var policy_manager =
        CORBA::PolicyManager::_narrow (object.in () TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      object =
        this->orb_->resolve_initial_references ("PolicyCurrent"
                                                TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::PolicyCurrent_var policy_current =
        CORBA::PolicyCurrent::_narrow (object.in () TAO_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;


      for (int i = 0; i != this->niterations_; ++i)
        {
          CORBA::PolicyList_var policies;
          this->perform_iteration (seed,
                                   policies,
                                   policy_manager.in (),
                                   policy_current.in ()
                                   TAO_ENV_ARG_PARAMETER);
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Manipulation: exception raised");
    }
  ACE_ENDTRY;
  return 0;
}
