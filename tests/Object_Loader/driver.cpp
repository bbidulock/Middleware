//
// $Id$
//

#include "TestC.h"
#include "tao/PortableServer/PortableServer.h"

#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdio.h"

int
main (int, char *[])
{
  int niterations = 10;
  int norbs = 10;

  ACE_TRY_NEW_ENV
    {
      for (int i = 0; i != niterations; ++i)
        {
          for (int j = 0; j != norbs; ++j)
            {
              char buf[16];
              ACE_OS::sprintf (buf, "ORB_%4.4d", j);

              int argc = 0;
              CORBA::ORB_var orb =
                CORBA::ORB_init (argc, 0, buf ACE_ENV_ARG_PARAMETER);

              CORBA::Object_var object =
                orb->string_to_object ("DLL:Test_Object"
                                       ACE_ENV_ARG_PARAMETER);

              Test_var test =
                Test::_narrow (object.in () ACE_ENV_ARG_PARAMETER);

              CORBA::Long count =
                test->instance_count ();

              if (count != norbs*i + j + 1)
                {
                  ACE_DEBUG ((LM_DEBUG,
                              "Incorrect number of objects "
                              "(%d != %d)\n",
                              count, norbs * i + j + 1));
                }
              test->destroy ();
            }
        }

      for (int j = 0; j != norbs; ++j)
        {
          char buf[16];
          ACE_OS::sprintf (buf, "ORB_%4.4d", j);

          int argc = 0;
          CORBA::ORB_var orb =
            CORBA::ORB_init (argc, 0, buf ACE_ENV_ARG_PARAMETER);

          CORBA::Object_var obj =
            orb->resolve_initial_references ("RootPOA"
                                             ACE_ENV_ARG_PARAMETER);

          PortableServer::POA_var poa =
            PortableServer::POA::_narrow (obj.in () ACE_ENV_ARG_PARAMETER);

          poa->destroy (1, 1 ACE_ENV_ARG_PARAMETER);

          orb->destroy ();
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "main()");
      return 1;
    }
  ACE_ENDTRY;
  return 0;
}
