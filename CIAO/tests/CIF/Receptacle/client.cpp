// $Id$

#include "Common/CIF_Common.h"
#include "ReceptacleEC.h"


const char * artifact_name = "Receptacle";

const char * entrypoint_name1 = "Receptacle";
const char * entrypoint_name2 = "Provider";

int
run_test (Receptacle_ptr rec,
          Provider_ptr ,
          ::CORBA::Object_ptr facet)
{
  try
    {
      //CONNECT
      ::Components::Cookie_var ck;
      try
        {
          ck = rec->connect ("rec_foo", facet);
          ACE_DEBUG ((LM_DEBUG, "Receptacle run_test - "
                                "connect test passed !\n"));
        }
      catch (const ::Components::InvalidName &)
        {
          ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                "Error: InvalidName "
                                "exception during connect\n"));
        }
      catch (const ::Components::InvalidConnection &)
        {
          ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                "Error: InvalidConnection "
                                "exception during connect\n"));
        }
      catch (const ::Components::AlreadyConnected &)
        {
          ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                "Error: AlreadyConnected "
                                "exception during connect\n"));
        }
      catch (const ::Components::ExceededConnectionLimit &)
        {
          ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                "Error: ExceededConnectionLimit "
                                "exception during connect\n"));
        }
      // DISCONNECT
      try
        {
          ::CORBA::Object_var obj = rec->disconnect ("rec_foo", ck);
          if (obj->_is_equivalent(facet))
            {
              ACE_DEBUG ((LM_DEBUG, "Receptacle run_test - "
                                    "disconnect test passed !\n"));
            }
          else
            {
              ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                    "Error : Returned object unequal to "
                                    "original object: "
                                    "expected <%@> - received <%@>\n",
                                    facet, obj.in ()));
            }
        }
      catch (const ::Components::InvalidName &)
        {
          ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                "Error: InvalidName "
                                "exception during connect\n"));
        }
      catch (const ::Components::InvalidConnection &)
        {
          ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                "Error: InvalidConnection "
                                "exception during connect\n"));
        }
      catch (const ::Components::CookieRequired &)
        {
          ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                "Error: CookieRequired "
                                "exception during connect\n"));
        }
      catch (const ::Components::NoConnection &)
        {
          ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                                "Error: NoConnection "
                                "exception during connect\n"));
        }
//       TODO:
//       Exception tests for connect/disconnect
//       #if !defined (CCM_LW)
//           ConnectionDescriptions get_connections (in FeatureName name)
//             raises (InvalidName);
//       #endif
//       #if !defined (CCM_LW)
//           ReceptacleDescriptions get_all_receptacles ();
//       #endif
//       #if !defined (CCM_LW)
//           ReceptacleDescriptions get_named_receptacles (in NameList names)
//             raises (InvalidName);
//       #endif
    }

  catch (...)
    {
      ACE_ERROR ((LM_ERROR, "Receptacle run_test - "
                            "Error: Unknown "
                            "exception during run_test\n"));
    }


  return 0;
}

int
ACE_TMAIN (int argc,  ACE_TCHAR **argv)
{
  using namespace ::CIAO::Deployment;

  CIF_Common cmd;
  try
    {
      if (cmd.init (argc, argv, artifact_name) != 0)
        return 1;

      ComponentServer_var server1 = cmd.create_componentserver ();

      ComponentServer_var server2 = cmd.create_componentserver ();
      if (CORBA::is_nil (server1.in ()) ||
          CORBA::is_nil (server2.in ()))
        {
          ACE_ERROR ((LM_ERROR, "Error: Got nil object references from create_component_server "
                                "operation\n"));
          return 1;
        }

      Container_var cont1 = cmd.create_container (server1.in ());
      Container_var cont2 = cmd.create_container (server2.in ());
      if (CORBA::is_nil (cont1.in ()) ||
          CORBA::is_nil (cont2.in ()))
        {
          ACE_ERROR ((LM_ERROR, "Error: Got nil object references from create_container "
                                "operation on server\n"));
          return 1;
        }

      Components::CCMObject_var comp1 = cmd.install_component (cont1.in (),
                                                               entrypoint_name1);
      Components::CCMObject_var comp2 = cmd.install_component (cont2.in (),
                                                               entrypoint_name2);
      if (CORBA::is_nil (comp1.in ()) ||
          CORBA::is_nil (comp2.in ()))
        {
          ACE_ERROR ((LM_ERROR, "Error: Installing components failed.\n"));
          return 1;
        }
      Receptacle_var rec = Receptacle::_narrow (comp1.in ());
      Provider_var prov = Provider::_narrow (comp2.in ());

      if (CORBA::is_nil (rec.in ()) ||
          CORBA::is_nil (prov.in ()))
        {
          ACE_ERROR ((LM_ERROR, "Narrow failed from CCMObjects to Receptacles\n"));
          return 1;
        }

      ::CORBA::Object_var facet;
      try
        {
          facet = prov->provide_facet ("prov_foo");
        }
      catch (const ::Components::InvalidName &e)
        {
          ACE_ERROR ((LM_ERROR, "Error: Unexpected InvalidName exception caught "
                                "while providing facet\n"));
        }

      run_test (rec.in (), prov.in (), facet.in ());

      cmd.shutdown (server1.in (), cont1.in (), comp1.in (), false);
      cmd.shutdown (server2.in (), cont2.in (), comp2.in ());
    }
  catch (const ::Components::CreateFailure &)
    {
      ACE_ERROR ((LM_ERROR, "Error: Caught CreateFailure exception.\n"));
      return  1;
    }
  catch (const ::Components::RemoveFailure &)
    {
      ACE_ERROR ((LM_ERROR, "Error: Caught RemoveFailure exception.\n"));
      return  1;
    }
  catch (...)
    {
      ACE_ERROR ((LM_ERROR, "Error: Caught unknown exception\n"));
      return  1;
    }
  return 0;
}
