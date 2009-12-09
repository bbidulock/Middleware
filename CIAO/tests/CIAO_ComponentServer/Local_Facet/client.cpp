// $Id$

#include "ace/Get_Opt.h"
#include "ciao/ComponentServer/CIAO_CS_ClientS.h"
#include "ciao/ComponentServer/CIAO_ComponentServerC.h"
#include "ciao/ComponentServer/CIAO_ServerActivator_Impl.h"
#include "ciao/ComponentServer/CIAO_ComponentInstallation_Impl.h"
#include "ciao/ComponentServer/CIAO_PropertiesC.h"
#include "ciao/Valuetype_Factories/ConfigValue.h"
#include "ciao/Logger/Logger_Service.h"

#include "Local_FacetC.h"

const char *cs_path = "ciao_componentserver";
CORBA::ULong spawn_delay = 30;

int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("s:d:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 's':
        cs_path = ACE_TEXT_ALWAYS_CHAR (get_opts.opt_arg ());
        break;

      case 'd':
        spawn_delay = ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage: %s "
                           "-s <path> "
                           "-d <uint> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

int
ACE_TMAIN (int argc,  ACE_TCHAR **argv)
{
  using namespace CIAO::Deployment;

  CIAO::Logger_Service logger;

  logger.init (argc, argv);
  try
    {
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->resolve_initial_references ("RootPOA");

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (object.in ());

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager ();

      poa_manager->activate ();
      ACE_DEBUG ((LM_DEBUG, "foo\n"));

      CIAO::Deployment::ComponentInstallation_Impl *tmp_ci = 0;

      ACE_NEW_THROW_EX (tmp_ci,
                        CIAO::Deployment::ComponentInstallation_Impl (),
                        CORBA::NO_MEMORY ());

      PortableServer::ServantBase_var safe_servant = tmp_ci;

      root_poa->activate_object (tmp_ci);

      CIAO_ServerActivator_i *sa_tmp = new CIAO_ServerActivator_i (spawn_delay,
                                                                   cs_path,
                                                                   0,
                                                                   false,
                                                                   tmp_ci->_this (),
                                                                   orb.in (),
                                                                   root_poa.in ());

      PortableServer::ServantBase_var safe = sa_tmp;

      ServerActivator_var sa = sa_tmp->_this ();

      //ACE_DEBUG ((LM_DEBUG, "Attempting to create componentserver with no configvalues\n"));
      // Make a componentserver with no configvalues
      ComponentServer_var server1 (ComponentServer::_narrow (sa->create_component_server (0)));

      if (CORBA::is_nil (server1.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Nil componentserver references"), -1);
        }

      Components::Deployment::Container_var tmp = server1->create_container (0);
      Container_var cont1a = Container::_narrow (tmp.in ());

      if (CORBA::is_nil (cont1a.in ()))
        {
          ACE_ERROR ((LM_ERROR, "Error: Got nil object reference from first create op on server 1 %u %u\n",
                      tmp.in (), cont1a.in ()));
          return -1;
        }

      // Make our configvalues
      // ::Components::ConfigValues_var configs = new
      CORBA::Any val;
      ::Components::ConfigValues configs(3);
      configs.length (3);

      val <<= "create_Bar_Servant";
      configs[0] = new CIAO::ConfigValue_impl (CIAO::Deployment::SVNT_ENTRYPT,
                                               val);
      val <<= "Local_Facet_svnt";
      configs[1] = new CIAO::ConfigValue_impl (CIAO::Deployment::SVNT_ARTIFACT,
                                               val);
      tmp_ci->install ("Local_Facet_svnt", "Local_Facet_svnt");
      val <<= "Local_Facet_exec";
      configs[2] = new CIAO::ConfigValue_impl (CIAO::Deployment::EXEC_ARTIFACT,
                                               val);
      tmp_ci->install ("Local_Facet_exec", "Local_Facet_exec");

      // Install Components
      Components::CCMObject_var comp1 = cont1a->install_component ("User",
                                                                  "create_Bar_Impl",
                                                                  configs);
      Components::CCMObject_var comp2 = cont1a->install_component ("Provider",
                                                                   "create_Bar_Impl",
                                                                   configs);

      if (CORBA::is_nil (comp1) || CORBA::is_nil (comp2))
        {
          ACE_ERROR ((LM_ERROR, "Got back a nil component ref from install_component\n"));
          return -1;
        }

      ::Bar_var user = ::Bar::_narrow (comp1.in ());
      
      
      if (CORBA::is_nil (user))
        {
          ACE_ERROR ((LM_ERROR, "Narrow failed from CCMObject to Bar\n"));
          return -1;
        }


      cont1a->connect_local_facet (comp2, "foo_out", comp1, "foo_in");

      user->run_test ();
      
      cont1a->remove_component (comp1.in ());
      cont1a->remove_component (comp2.in ());

      server1->remove_container (cont1a.in ());

      //ACE_DEBUG ((LM_DEBUG, "Removing component server\n"));
      sa->remove_component_server (server1.in ());
      //ACE_DEBUG ((LM_DEBUG, "Componentserver removed\n"));

      orb->destroy ();
    }
  catch (::Components::CreateFailure &)
    {
      ACE_ERROR ((LM_ERROR, "Error: Caught CreateFailure exception.\n"));
    }
  catch (::Components::RemoveFailure &)
    {
      ACE_ERROR ((LM_ERROR, "Error: Caught RemoveFailure exception.\n"));
    }
  catch (...)
    {
      ACE_ERROR ((LM_ERROR, "Error: Caught unknown exception\n"));
    }
  return 0;
}
