// $Id$

#include "Sender_i.h"
#include "Server_Task.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Get_Opt.h"

ACE_RCSID(Oneways_Invoking_Twoways, server, "$Id$")

const char *ior_output_file = "test.ior";
int number_of_oneways = 10;

int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("o:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'o':
        ior_output_file = get_opts.opt_arg ();
        break;
      case 'n' :
        number_of_oneways = ACE_OS::atoi (get_opts.opt_arg ());
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-o <iorfile>"
                           "-n <number of oneways>"
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  try
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv);

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

      if (parse_args (argc, argv) != 0)
        return 1;

      Sender_i *sender_impl;
      ACE_NEW_RETURN (sender_impl,
                      Sender_i (orb.in ()),
                      1);
      PortableServer::ServantBase_var receiver_owner_transfer(sender_impl);

      PortableServer::ObjectId_var id =
        root_poa->activate_object (sender_impl);

      CORBA::Object_var object = root_poa->id_to_reference (id.in ());

      Test::Sender_var sender =
        Test::Sender::_narrow (object.in ());

      CORBA::String_var ior =
        orb->object_to_string (sender.in ());

      // If the ior_output_file exists, output the ior to it
      FILE *output_file= ACE_OS::fopen (ior_output_file, "w");
      if (output_file == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot open output file for writing IOR: %s",
                           ior_output_file),
                              1);
      ACE_OS::fprintf (output_file, "%s", ior.in ());
      ACE_OS::fclose (output_file);

      poa_manager->activate ();

      Server_Task server_task (orb.in (),
                               ACE_Thread_Manager::instance ());

      if (server_task.activate (THR_NEW_LWP | THR_JOINABLE, 4, 1) == -1)
        {
          ACE_ERROR ((LM_ERROR, "Error activating server task\n"));
        }
      ACE_Thread_Manager::instance ()->wait ();

      ACE_DEBUG ((LM_DEBUG, "Now terminating test\n"));

      CORBA::ULong activeobjects = sender_impl->get_active_objects ();
      if (((number_of_oneways * activeobjects) !=
            sender_impl->get_number_received ()) && activeobjects != 0)
        {
          ACE_ERROR ((LM_ERROR, "Error, expected %d oneways, received %d\n",
                      number_of_oneways,
                      sender_impl->get_number_received()));
        }
      else
        {
          if (sender_impl->get_number_received () == 0)
            {
              ACE_ERROR ((LM_ERROR, "Error: Received no calls\n"));
            }
          else
            {
              ACE_DEBUG ((LM_DEBUG, "Corrected amount received\n"));
            }
        }

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
