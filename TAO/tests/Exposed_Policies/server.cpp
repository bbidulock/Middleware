//$Id$

////////////////////////////////////////////////////////////////////////
// This files tests the Client exposed policies:
//     - PriorityModelPolicy
//     - PriorityBandedConnectionPolicy
//     - ClientProtocolPolicy
//
// This policies are embedded in the object reference, by writem
// them into the IOR.
//
//
// -- App. Specific Include --
#include "Policy_Tester.h"

#include "tao/Strategies/advanced_resource.h"
#include "ace/Argv_Type_Converter.h"

ACE_RCSID(tao, server, "$Id$")


int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Argv_Type_Converter convert (argc, argv);

  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      Policy_Tester policy_tester;

      int result = policy_tester.init (convert.get_argc(), convert.get_ASCII_argv() ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (result != 0)
        return result;

      policy_tester.run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }

  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           ACE_TEXT ("CORBA Exception Raised."));
      return 1;
    }

  ACE_ENDTRY;

  return 0;
}
