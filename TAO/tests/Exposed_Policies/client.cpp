// $Id$

#include "CounterC.h"

ACE_RCSID(tao, client, "$Id$")


  CORBA::Boolean check_reference (CORBA::Object_ptr object,
                                  const char *msg = 0)
{
  if (CORBA::is_nil (object))
    {
      if (msg == 0)
        ACE_DEBUG ((LM_DEBUG, 
                    ACE_TEXT ("The Object reference is nil.\n")));
      else
        ACE_DEBUG ((LM_DEBUG, 
                    ACE_TEXT (msg)));
      return 0;
    }
  return 1;
}


int
main (int argc, char *argv[])
{
  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      // ORB Initialization
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv, "TAO", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      CORBA::Object_var object;

      // Get the IOR from a file.
      object = orb->string_to_object ("file://s.ior", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (!check_reference (object, "Invalid IOR file!\n"))
        return 1;
      
      Counter_var counter = Counter::_narrow (object.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      if (!check_reference (object, 
                            "Unable to convert the IOR to the proper object reference.\n"))
        return 1;
      
      CORBA::Policy_var policy_ptr;
      policy_ptr = counter->_get_policy (RTCORBA::PRIORITY_MODEL_POLICY_TYPE,
                                         ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      if (!check_reference (policy_ptr, "Unable to get Priority Policy.\n"))
        return 1;

      RTCORBA::PriorityModelPolicy_var priority_policy =
        RTCORBA::PriorityModelPolicy::_narrow (policy_ptr);
        
      RTCORBA::PriorityModel priority_model = 
        priority_policy->priority_model (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      RTCORBA::Priority priority = 
        priority_policy->server_priority (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (priority_model == RTCORBA::SERVER_DECLARED)
        ACE_DEBUG ((LM_DEBUG, 
                    ACE_TEXT ("\n\nPriority Model: RTCORBA::SERVER_DECLARED\n")
                    ));

      ACE_DEBUG ((LM_DEBUG, 
                  ACE_TEXT ("\nPriority Model: %d\nCORBA Priority: %d\n"),
                  priority_model,
                  priority
                  ));
      
      policy_ptr = object->_get_policy (RTCORBA::PRIORITY_BANDED_CONNECTION_POLICY_TYPE,
                                        ACE_TRY_ENV);
      if (!check_reference (policy_ptr, "Unable to get Priority Banded Policy\n"))
        return 1;
      
      RTCORBA::PriorityBandedConnectionPolicy_var priority_banded_policy = 
        RTCORBA::PriorityBandedConnectionPolicy::_narrow (policy_ptr,
                                                          ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (!check_reference (priority_banded_policy, "Unable to get Priority Banded Policy\n"))
        return 1;
      
      // Here we have a priority banded connection policy.

      RTCORBA::PriorityBands_var pb = priority_banded_policy->priority_bands ();
      unsigned int band_num = pb->length ();
      for (unsigned int i = 0; i < band_num; ++i)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("Priority Band <%d>: (%d, %d)\n"), 
                      i,
                      pb[i].low,
                      pb[i].high
                      ));
        }

      policy_ptr = object->_get_policy (RTCORBA::CLIENT_PROTOCOL_POLICY_TYPE,
                                        ACE_TRY_ENV);
      if (!check_reference (policy_ptr, "Unable to get Priority Banded Policy\n"))
        return 1;

      RTCORBA::ClientProtocolPolicy_var client_protocol_policy = 
        RTCORBA::ClientProtocolPolicy::_narrow (policy_ptr, ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      RTCORBA::ProtocolList_var protocol_list = 
        client_protocol_policy->protocols (ACE_TRY_ENV);
      ACE_TRY_CHECK;
 
      for (i = 0; i < protocol_list->length (); i++)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("The Client Protocol Type: %d\n"), 
                    protocol_list[i].protocol_type));
                            
    }

  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "CORBA Excaption Raised");
      return 1;
    }

  ACE_ENDTRY;

  return 0;
}
