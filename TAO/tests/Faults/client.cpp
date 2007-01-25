// $Id$

#include "ace/Get_Opt.h"
#include "test_i.h"

ACE_RCSID(Failure, client, "$Id$")

const char *ior = "file://test.ior";
int niterations = 10;
int do_shutdown = 0;
int do_suicide = 0;
int do_self_shutdown = 0;
int do_abort = 0;
int do_crash = 0;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "acszxk:i:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'a':
        do_abort = 1;
        break;

      case 'c':
        do_crash = 1;
        break;

      case 'x':
        do_shutdown = 1;
        break;

      case 's':
        do_suicide = 1;
        break;

      case 'z':
        do_self_shutdown = 1;
        break;

      case 'k':
        ior = get_opts.opt_arg ();
        break;

      case 'i':
        niterations = ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "[-a] [-c] [-x] [-s] [-z] "
                           "-k <ior> "
                           "-i <niterations> "
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
  try
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "");

      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA");

      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in ());

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager ();

      poa_manager->activate ();

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object (ior);

      Simple_Server_var server =
        Simple_Server::_narrow (object.in ());

      if (CORBA::is_nil (server.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Object reference <%s> is nil\n",
                             ior),
                            1);
        }

      Callback_i callback_impl (orb.in ());

      Callback_var callback =
        callback_impl._this ();

      for (int i = 0; i != niterations; ++i)
        {
          CORBA::Long r =
            server->test_method (0, 0, callback.in ());

          if (r != 0)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "(%P|%t) unexpected result = %d for %d",
                          r, i));
            }
        }

      if (do_abort)
        {
          try
            {
              server->shutdown_now (0);
            }
          catch (const CORBA::COMM_FAILURE& comm_failure)
            {
              ACE_UNUSED_ARG (comm_failure);
              // Expected exception, continue....
            }
        }
      else if (do_crash)
        {
          try
            {
              server->shutdown_now (1);
            }
          catch (const CORBA::COMM_FAILURE& comm_failure)
            {
              ACE_UNUSED_ARG (comm_failure);
              // Expected exception, continue....
            }
        }
      else if (do_suicide)
        {
          (void) server->test_method (1, 0, callback.in ());
          ACE_DEBUG ((LM_DEBUG, "ERROR: client should have aborted\n"));
        }
      else if (do_self_shutdown)
        {
          (void) server->test_method (1, 1, callback.in ());
        }

      if (do_shutdown)
        {
          server->shutdown ();
        }

      root_poa->destroy (1, 1);

    }
  catch (const CORBA::COMM_FAILURE& x)
    {
      // For other case this is expected.
      if (do_self_shutdown == 0)
        {
          x._tao_print_exception ("ERROR: Unexpected exception \n");
        }
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught in client:");
      return 1;
    }

  return 0;
}
