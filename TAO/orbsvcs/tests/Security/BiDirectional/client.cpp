// $Id$

#include "ace/Get_Opt.h"
#include "ace/Argv_Type_Converter.h"
#include "test_i.h"
#include "tao/BiDir_GIOP/BiDirGIOP.h"
#include "tao/AnyTypeCode/Any.h"

#include "tao/ORB_Core.h"
#include "tao/Transport_Cache_Manager.h"
#include "tao/Thread_Lane_Resources.h"

ACE_RCSID(BiDirectional, client, "$Id$")

const char *ior = "file://test.ior";

void do_nothing (void)
{
}

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Arg_Opt<char> get_opts (argc, argv, "k:");
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
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Argv_Type_Converter convert (argc, argv);

  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (convert.get_argc(), convert.get_ASCII_argv(), "" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var poa_object =
        orb->resolve_initial_references ("RootPOA" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Policies for the childPOA to be created.
      CORBA::PolicyList policies (1);
      policies.length (1);

      CORBA::Any pol;
      pol <<= BiDirPolicy::BOTH;
      policies[0] =
        orb->create_policy (BiDirPolicy::BIDIRECTIONAL_POLICY_TYPE,
                            pol
                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Create POA as child of RootPOA with the above policies.  This POA
      // will receive request in the same connection in which it sent
      // the request
      PortableServer::POA_var child_poa =
        root_poa->create_POA ("childPOA",
                              poa_manager.in (),
                              policies
                              ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Creation of childPOA is over. Destroy the Policy objects.
      for (CORBA::ULong i = 0;
           i < policies.length ();
           ++i)
        {
          policies[i]->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }

      poa_manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object (ior ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      Simple_Server_var server =
        Simple_Server::_narrow (object.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (server.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Object reference <%s> is nil\n",
                             ior),
                            1);
        }


      Callback_i callback_impl (orb.in ());

      PortableServer::ObjectId_var id =
        PortableServer::string_to_ObjectId ("client_callback");

      child_poa->activate_object_with_id (id.in (),
                                          &callback_impl
                                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var callback_object =
        child_poa->id_to_reference (id.in ()
                                    ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      Callback_var callback =
        Callback::_narrow (callback_object.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;


      CORBA::String_var ior =
        orb->object_to_string (callback.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_DEBUG ((LM_DEBUG, "(%P|%t) Client callback activated as <%s>\n", ior.in ()));

      // Send the calback object to the server
      server->callback_object (callback.in ()
                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // This is a non-portable, but the only currently available way of
      // determining the number of currently open connections.
      int pre_call_connections =
        orb->orb_core ()->lane_resources ().transport_cache ().current_size ();

      // A  method to kickstart callbacks from the server
      CORBA::Long r =
        server->test_method (1 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (r != 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "(%P|%t) unexpected result = %d ",
                      r));
        }

      orb->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // This is a non-portable, but the only currently available way of
      // determining the number of currently open connections.
      int cur_connections =
        orb->orb_core()->lane_resources().transport_cache().current_size ();

      if (cur_connections > pre_call_connections)
        {
          ACE_ERROR ((LM_ERROR,
                      "(%P|%t) Expected %d "
                      "connections in the transport cache, but found "
                      "%d instead.  Aborting.\n",
                      pre_call_connections,
                      cur_connections));

          ACE_OS::abort ();
        }

      root_poa->destroy (1, 1 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

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
