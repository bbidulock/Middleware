// $Id$

#include "CounterC.h"

ACE_RCSID(tao, client, "$Id$")

int
main (int argc, char *argv[])
{
  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      // ORB Initialization
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
      // @@ Angelo, remember error checking, i.e., ACE_TRY_ENV

      CORBA::Object_var object;

      // Get the IOR from a file.
      object = orb->string_to_object ("file://ec.ior", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      Counter_var counter = Counter::_narrow (object.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (counter))
        {
          ACE_DEBUG ((LM_DEBUG,
                      "Unable to convert the IOR to the proper object reference.\n"));
          return 1;
        }

      CORBA::ULong i;

      for (i = 0; i < 10; i++)
        {
          counter->increment (ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }
      // @@ Angelo, above isn't strictly needed for the test...

      // @@ Angelo, make sure to always use ACE_TRY & friends to
      // detect exception conditions, especially on idl method invocations.

      // Marina DONE.
      // @@ Angelo, not done at all!! The next two lines contain
      // remote invocations, and each is missing ACE_TRY_ENV!

       ACE_DEBUG ((LM_DEBUG,
                   "The Counter Value is: %d\n", counter->get_count()));
       // @@ Angelo, never ever use result of expression that might
       // throw exception in another expression.

       counter->shutdown ();

       // @@ Angelo, the code below is misindented.
      CORBA::Policy *policy_ptr;
      // @@ Angelo, please use Policy_ptr, not Policy *.
      policy_ptr = counter->_get_policy (RTCORBA::PRIORITY_MODEL_POLICY_TYPE,
                                         ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // @@ Angelo, use is_nil ()...
      if (policy_ptr == 0)
        {
          ACE_DEBUG ((LM_DEBUG, "Unable to get Priority Policy.\n"));
          return 1;
        }

      RTCORBA::PriorityModelPolicy *priority_policy =
        RTCORBA::PriorityModelPolicy::_narrow (policy_ptr);

      ACE_DEBUG ((LM_DEBUG, "Priority Model: %d\nCORBA Priority: %d",
                  priority_policy->priority_model (ACE_TRY_ENV),
                  priority_policy->server_priority (ACE_TRY_ENV)));

      // @@ Angelo, again, don't use methods that may throw exceptions
      // inside other expressions.  By the time you get to
      // ACE_TRY_CHECK, you program would have fallen to the evil
      // spirits of the seg daemon...

      ACE_TRY_CHECK;

      // @@ Angelo, you have a memory leaks - never deallocating
      // policies.  Make sure you read section on parameter passing
      // considerations in CORBA 2.3 as well as description of narrow method.
    }

  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "CORBA Excaption Raised");
      return 1;
    }

  ACE_ENDTRY;

  return 0;
}
