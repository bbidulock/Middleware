// $Id$

#include "ace/Get_Opt.h"
#include "test_i.h"
#include "tao/BiDir_GIOP/BiDirGIOP.h"
#include "tao/AnyTypeCode/Any.h"

ACE_RCSID(BiDirectional, client, "$Id$")

const char *ior = "file://test.ior";

void do_nothing (void)
{
}

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
  CORBA::ORB_var orb = CORBA::ORB::_nil();
  PortableServer::POA_var root_poa = PortableServer::POA::_nil();
  Callback_i *servant = 0;

  try
    {
      orb = CORBA::ORB_init (argc, argv, "");

      CORBA::Object_var poa_object =
        orb->resolve_initial_references ("RootPOA");

      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in ());

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager ();

      // Policies for the childPOA to be created.
      CORBA::PolicyList policies (1);
      policies.length (1);

      CORBA::Any pol;
      pol <<= BiDirPolicy::BOTH;
      policies[0] =
        orb->create_policy (BiDirPolicy::BIDIRECTIONAL_POLICY_TYPE,
                            pol);

      // Create POA as child of RootPOA with the above policies.  This POA
      // will receive request in the same connection in which it sent
      // the request
      PortableServer::POA_var child_poa =
        root_poa->create_POA ("childPOA",
                              poa_manager.in (),
                              policies);

      // Creation of childPOA is over. Destroy the Policy objects.
      for (CORBA::ULong i = 0;
           i < policies.length ();
           ++i)
        {
          policies[i]->destroy ();
        }

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


      servant = new Callback_i (orb.in ());

      Callback_var callback =
        servant->_this ();

      // Send the calback object to the server
      server->callback_object (callback.in ());

      // A  method to kickstart callbacks from the server
      CORBA::Long r =
        server->test_method (1);

      if (r != 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "(%P|%t) unexpected result = %d ",
                      r));
        }

      orb->run ();

      root_poa->destroy (1, 1);

    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Caught exception:");
      return 1;
    }

  if (!CORBA::is_nil(root_poa.in()))
    root_poa->destroy (1,1);
  delete servant;

  return 0;
}
