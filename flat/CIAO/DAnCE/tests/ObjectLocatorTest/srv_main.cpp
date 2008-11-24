
#include "ace/OS_NS_stdio.h"

#include "DummyC.h"
#include "DummyImpl.h"
#include "RedirectionService/CCMObjectLocator.h"
#include "RegistrationPath.h"
#include "DAnCE/Logger/Log_Macros.h"

using namespace ObjectLocatorTest;


int main (int argc, char * argv[])
{
  try
    {
      char * argvm[argc+3];
      for (int i = 0; i < argc; ++i)
        {
          argvm[i] = argv[i];
        }
      char buf1[32];
      ACE_OS::sprintf (buf1, "-ORBListenEndpoints");
      argvm[argcm-2] = buf1;
      char buf2[32];
      ACE_OS::sprintf (buf2, "iiop://:12345");
      argvm[argcm-1] = buf2;
      argvm[argcm] = 0;
      CORBA::ORB_var orb = CORBA::ORB_init (argcm, argvm);

      CORBA::Object_var obj = orb->resolve_initial_references ("RootPOA");
      PortableServer::POA_var root_poa = PortableServer::POA::_narrow (obj.in ());

      PortableServer::POAManager_var poa_manager = root_poa->the_POAManager();
      poa_manager->activate();

      DAnCE::CCMObjectLocator locator (orb.in(), root_poa.in(), "Dummy");

      DummyImpl servant;

      PortableServer::ObjectId_var id = root_poa->activate_object (&servant);
      Dummy_var dummy_obj = Dummy::_narrow (root_poa->id_to_reference (id));//servant._this();

      locator.register_object (app_name, inst_name, port_name, dummy_obj);

      orb->run();
    }
  catch (...)
    {
      DANCE_ERROR((LM_ERROR, "[%M] An error has occured."));
    }
}

