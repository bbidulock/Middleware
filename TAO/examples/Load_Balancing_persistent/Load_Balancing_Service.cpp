// $Id$
// ============================================================================
//
// = LIBRARY
//    TAO/examples/Load_Balancing
//
// = FILENAME
//    Load_Balancing_Service.cpp
//
// = AUTHOR
//    Marina Spivak <marina@cs.wustl.edu>
//
// ============================================================================

#include "Load_Balancing_Service.h"
#include "Load_Balancer_i.h"
#include "tao/debug.h"
#include "ace/Get_Opt.h"

Load_Balancing_Service::Load_Balancing_Service (void)
  : ior_output_file_ (0)
{
}

int
Load_Balancing_Service::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "do:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag.
        TAO_debug_level++;
        break;
      case 'o': // outputs object ior to the specified file.
        this->ior_output_file_ =
          ACE_OS::fopen (get_opts.opt_arg (), "w");

        if (this->ior_output_file_ == 0)
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to open %s for writing: %p\n",
                             get_opts.opt_arg ()), -1);
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-d]"
                           " [-o] <ior_output_file>"
                           "\n",
                           argv [0]),
                          -1);
      }

  // Indicates successful parsing of command line.
  return 0;
}

int
Load_Balancing_Service::init (int argc,
                    char* argv[])
{
  int result;
  CORBA::String_var ior;

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      result = this->orb_manager_.init (argc,
                                        argv
                                        ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      if (result == -1)
        return result;

      // Check the non-ORB arguments.
      result = this->parse_args (argc, argv);
      if (result < 0)
        return result;


      CORBA::PolicyList policies (2);
      policies.length (2);

      // Lifespan policy
      policies[0] =
        this->orb_manager_.root_poa()->create_lifespan_policy (PortableServer::PERSISTENT
                                                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      policies[1] =
        this->orb_manager_.root_poa()->create_implicit_activation_policy (PortableServer::IMPLICIT_ACTIVATION
                                                                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POA_var persistent_POA =
        this->orb_manager_.root_poa()->create_POA ("persistent",
                                                   this->orb_manager_.poa_manager (),
                                                   policies
                                                   ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;


      // Destroy policy objects
      for (CORBA::ULong i = 0;
           i < policies.length ();
           ++i)
        {
          policies[i]->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }

      // Create, ref. count, and activate the servant.
      Object_Group_Factory_i * factory_servant;
      ACE_NEW_RETURN (factory_servant,
                      Object_Group_Factory_i (this->orb_manager_.orb (),
                                              persistent_POA.in ()),
                      -1);

      // Activate the POA manager
      //PortableServer::ServantBase_var s = factory_servant;
      this->orb_manager_.activate_poa_manager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var objref = factory_servant->_this ();

      ior = this->orb_manager_.orb ()->object_to_string (objref.in ()
                                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (ior.in () == 0)
        return -1;
      else if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG,
                    "Object Group Factory ior: %s\n",
                    ior.in ()));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Load_Balancing_Service::init");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  if (this->ior_output_file_ != 0)
    {
      ACE_OS::fprintf (this->ior_output_file_,
                       "%s",
                       ior.in ());
      ACE_OS::fclose (this->ior_output_file_);
    }
  return 0;
}



int
Load_Balancing_Service::run (ACE_ENV_SINGLE_ARG_DECL)
{
  int result;

  result = this->orb_manager_.run (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  return result;
}

Load_Balancing_Service::~Load_Balancing_Service (void)
{
}

int
main (int argc, char *argv[])
{
  int result = 0;
  Load_Balancing_Service factory;

  if (factory.init (argc, argv) == -1)
    return 1;

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      result = factory.run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Load_Balancing_Service");
      return 1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (1);

  if (result == -1)
    return 1;
  else
    return 0;
}
