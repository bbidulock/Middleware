// $Id$

#include "Hello.h"
#include "Server_Task.h"
#include "tao/Utils/Servant_Var.h"
#include "ace/Get_Opt.h"

ACE_RCSID (Bug_1XXX_Regression, server, "$Id$")

const char *ior_output_file = "test.ior";

bool simulate_crashes = true;

int nthreads = 1;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "xn:o:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'o':
        ior_output_file = get_opts.opt_arg ();
        break;

      case 'x':
        simulate_crashes = false;
        break;

      case 'n':
        nthreads = ACE_OS::atoi(get_opts.opt_arg());
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                              "usage:  %s"
                              " -o <iorfile>"
                              " -x (do not simulate crashes)"
                              " -n <nthreads>"
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

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in ());

      if (CORBA::is_nil (root_poa.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Panic: nil RootPOA\n"),
                          1);

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager ();

      if (parse_args (argc, argv) != 0)
        return 1;

      TAO::Utils::Servant_Var<Hello> hello_impl(
          new Hello(orb.in(), simulate_crashes));

      Test::Hello_var hello =
        hello_impl->_this ();

      CORBA::String_var ior =
        orb->object_to_string (hello.in ());

      // Output the IOR to the <ior_output_file>
      FILE *output_file= ACE_OS::fopen (ior_output_file, "w");
      if (output_file == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot open output file for writing IOR: %s",
                           ior_output_file),
                              1);
      ACE_OS::fprintf (output_file, "%s", ior.in ());
      ACE_OS::fclose (output_file);

      poa_manager->activate ();


      Server_Task st (orb.in (),
                      ACE_Thread_Manager::instance ());

      if (st.activate (THR_NEW_LWP | THR_JOINABLE, nthreads, 1) == -1)
        {
          ACE_ERROR ((LM_ERROR,
                      "Error activating server task\n"));

          return -1;
        }

      ACE_Thread_Manager::instance()->wait();

      ACE_DEBUG ((LM_DEBUG, "(%P|%t) server - event loop finished\n"));

      root_poa->destroy (1, 1);

      orb->destroy ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return 1;
    }

  return 0;
}
