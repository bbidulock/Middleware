// $Id$
// This is a simple test of an ImR using the corba interfaces
// It uses multicast to find the ImplRepoService

#include "testS.h"

#include "tao/IORTable/IORTable.h"

#include "ace/streams.h"
#include "ace/ARGV.h"

class test_i : public virtual POA_test {
  int n_;
public:
  test_i (void) : n_(0)
  {
  }
  virtual ~test_i (void) {
  }
  virtual CORBA::Long get (ACE_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC ((CORBA::SystemException)) {
    ACE_DEBUG((LM_DEBUG, "dynserver: get() %d\n", ++n_));
    return n_;
  }
};

PortableServer::POA_ptr createPersistPOA(const char* name, PortableServer::POA_ptr root_poa, PortableServer::POAManager_ptr poaman) {
  CORBA::PolicyList policies (2);
  policies.length (2);
  policies[0] = root_poa->create_id_assignment_policy(PortableServer::USER_ID);
  policies[1] = root_poa->create_lifespan_policy(PortableServer::PERSISTENT);
  PortableServer::POA_var poa = root_poa->create_POA(name, poaman, policies);
  policies[0]->destroy();
  policies[1]->destroy();
  return poa._retn();
}

int main(int argc, char* argv[]) {

  try {

    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

    CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
    PortableServer::POA_var root_poa = PortableServer::POA::_narrow(obj.in());
    PortableServer::POAManager_var poaman = root_poa->the_POAManager();
    obj = orb->resolve_initial_references ("IORTable");
    IORTable::Table_var ior_table = IORTable::Table::_narrow (obj.in());
    ACE_ASSERT(! is_nil(ior_table.in()));

    ACE_DEBUG((LM_DEBUG, "test_server: creating poas. (Registers with ImR)\n"));

    PortableServer::POA_var poa1 = createPersistPOA("TestObject1", root_poa.in(), poaman.in());
    PortableServer::POA_var poa2 = createPersistPOA("TestObject2", root_poa.in(), poaman.in());

    ACE_DEBUG((LM_DEBUG, "test_server: activating objects.\n"));

    test_i svt1, svt2;

    PortableServer::ObjectId_var id = PortableServer::string_to_ObjectId("myobject");

    poa1->activate_object_with_id(id.in(), &svt1);
    poa2->activate_object_with_id(id.in(), &svt2);

    obj = poa1->id_to_reference(id.in());
    CORBA::String_var ior = orb->object_to_string(obj.in());
    ior_table->bind ("TestObject1", ior.in());
    obj = poa2->id_to_reference(id.in());
    ior = orb->object_to_string(obj.in());
    ior_table->bind ("TestObject2", ior.in());

    poaman->activate();

    ACE_DEBUG((LM_DEBUG, "test_server: Running...\n"));

    orb->run();

    ACE_DEBUG((LM_DEBUG, "test_server: Shutting down...\n"));

    root_poa->destroy(1, 1);
    orb->destroy();

  } catch (CORBA::Exception& e) {
    ACE_PRINT_EXCEPTION(e, "TestServer::init()");
  }
  return 0;
}
