/**
 * @file client.cpp
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 *
 */
#include "TestC.h"

#include "ace/Get_Opt.h"

ACE_RCSID(Bug_1568_Regression, client, "$Id$")

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
        ior = get_opts.opt_arg ();
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
  // Indicates sucessful parsing of the command line
  return 0;
}

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object (ior ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      Baz::C_var cobject =
        Baz::C::_narrow (object.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (cobject.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                                "Cannot narrow Baz::C object <%s>\n",
                                ior),
                            1);
        }

      cobject->op1 (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      cobject->op2 (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      cobject->op3 (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      cobject->op4 (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}
