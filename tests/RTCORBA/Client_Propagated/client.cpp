// $Id$

#if (TAO_HAS_RT_CORBA == 1)

#include "testC.h"
#include "ace/Get_Opt.h"

const char *ior = "file://test.ior";

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        ior = get_opts.optarg;
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k <ior> "
                           "\n",
                           argv [0]),
                          -1);
      }

  return 0;
}

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      // Initialize and obtain reference to the Test object.
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object (ior, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      Test_var server =
        Test::_narrow (object.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (server.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "ERROR: Object reference <%s> is nil\n",
                             ior),
                            1);
        }

      // Check that the object is configured with CLIENT_PROPAGATED
      // PriorityModelPolicy.
      CORBA::Policy_var policy =
        server->_get_policy (RTCORBA::PRIORITY_MODEL_POLICY_TYPE,
                             ACE_TRY_ENV);
      ACE_TRY_CHECK;

      RTCORBA::PriorityModelPolicy_var priority_policy =
        RTCORBA::PriorityModelPolicy::_narrow (policy, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (priority_policy.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "ERROR: Priority Model Policy not exposed!\n"),
                          1);

      RTCORBA::PriorityModel priority_model =
        priority_policy->priority_model (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (priority_model != RTCORBA::CLIENT_PROPAGATED)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "ERROR: priority_model != "
                           "RTCORBA::CLIENT_PROPAGATED!\n"),
                          1);

      // Make several invocation, changing the priority of this thread
      // for each.
      object =
        orb->resolve_initial_references ("RTCurrent", ACE_TRY_ENV);
      ACE_TRY_CHECK;
      RTCORBA::Current_var current =
        RTCORBA::Current::_narrow (object.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;

      CORBA::Short desired_priority = 0;
      current->the_priority (desired_priority, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      for (int i = 0; i < 3; ++i)
        {
          CORBA::Short priority =
            current->the_priority (ACE_TRY_ENV);
          ACE_TRY_CHECK;

          if (desired_priority != priority)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "ERROR: Unable to set thread "
                               "priority to %d\n", desired_priority),
                              1);


          server->test_method (priority, ACE_TRY_ENV);
          ACE_TRY_CHECK;

          desired_priority++;

          current->the_priority (desired_priority, ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }

      // Shut down Server ORB.
      server->shutdown (ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Catched exception:");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}

#endif /* TAO_HAS_RT_CORBA == 1 */
