// $Id$

#include "NamingTask.h"
#include "Hello.h"
#include "NsShutdown.h"
#include "orbsvcs/CosNamingC.h"
#include "ace/OS.h"
#include "ace/Get_Opt.h"

const char *ior_output_file = "shutdown.ior";

class TestTask : public ACE_Task_Base
{
public:
  TestTask(int argc, char **argv);
  virtual int svc();

  int parse_args (int argc, char **argv);

  void end();
private:
  NamingTask namingServiceA_;
  NamingTask namingServiceB_;
  CORBA::ORB_var orb_;
  CORBA::Boolean shutdown_ns_;
};

TestTask::TestTask(int argc, char **argv)
 : namingServiceA_("NamingORBA", argc, argv, 9931),
   namingServiceB_("NamingORBB", argc, argv, 9932)
{
  orb_ = CORBA::ORB_init(argc, argv, "ServerORB");
  shutdown_ns_ = false;
  parse_args(argc, argv);
}

void TestTask::end()
{
  orb_->shutdown(0);
  wait();
}

int
TestTask::parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "s");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 's':
        shutdown_ns_ = true;
        break;
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

int TestTask::svc()
{

  try {
    // Start the Naming Service tasks
    namingServiceA_.activate();
    // Wait for the Naming Service initialized.
    namingServiceA_.waitInit();

    namingServiceB_.activate();
    // Wait for the Naming Service initialized.
    namingServiceB_.waitInit();

    FILE *output_file= ACE_OS::fopen ("ns.ior", "w");
    if (output_file == 0)
      ACE_ERROR_RETURN ((LM_ERROR,
                          "Cannot open output file for writing IOR: ns.ior\n"),
                          1);
    ACE_OS::fprintf (output_file, "%s", namingServiceA_.ior ());
    ACE_OS::fclose (output_file);

    // Get reference to Root POA
    CORBA::Object_var obj = orb_->resolve_initial_references("RootPOA");
    PortableServer::POA_var poa = PortableServer::POA::_narrow(obj.in());

    // Activate POA Manager
    PortableServer::POAManager_var mgr = poa->the_POAManager();
    mgr->activate();

    // Find the Naming Service
    obj = orb_->string_to_object (namingServiceB_.ior ());
    CosNaming::NamingContext_var root =
      CosNaming::NamingContext::_narrow(obj.in());

    if (CORBA::is_nil(root.in())) {
      ACE_ERROR ((LM_ERROR, "Error, Nil Naming Context reference\n"));
      return 1;
    }
    // Bind the example Naming Context, if necessary
    CosNaming::NamingContext_var example_nc;
    CosNaming::Name name;
    name.length(1);
    name[0].id = CORBA::string_dup("example");
    try
    {
      obj = root->resolve(name);
      example_nc = CosNaming::NamingContext::_narrow(obj.in());
    }
    catch (const CosNaming::NamingContext::NotFound&)
    {
      example_nc = root->bind_new_context(name);
    }

    // Bind the Test object
    name.length(2);
    name[1].id = CORBA::string_dup("Hello");

    // Create an object
    Hello servant(orb_.in ());
    PortableServer::ObjectId_var oid = poa->activate_object(&servant);
    obj = poa->id_to_reference(oid.in());
    root->rebind(name, obj.in());

    ACE_DEBUG ((LM_INFO, "Hello object bound in Naming Service B\n"));

    name.length(1);
    obj = orb_->string_to_object (namingServiceA_.ior ());
    root = CosNaming::NamingContext::_narrow(obj.in());
    root->bind_context (name, example_nc.in ());

    ACE_DEBUG ((LM_INFO, "'example' context of NS B bound in Naming Service A\n"));

    if (shutdown_ns_)
    {
      namingServiceB_.end();

      ACE_DEBUG ((LM_INFO, "Naming Service B shut down\n"));
    }

    // Create shutdown server
    NsShutdown shutdown_servant(orb_.in ());
    PortableServer::ObjectId_var shutdown_oid = poa->activate_object(&shutdown_servant);
    obj = poa->id_to_reference(shutdown_oid.in());
    CORBA::String_var ior = orb_->object_to_string (obj.in ());

    output_file= ACE_OS::fopen (ior_output_file, "w");
    if (output_file == 0)
      ACE_ERROR_RETURN ((LM_ERROR,
                          "Cannot open output file for writing IOR: %s\n",
                          ior_output_file),
                          1);
    ACE_OS::fprintf (output_file, "%s", ior.in ());
    ACE_OS::fclose (output_file);

    // Normally we run the orb and the orb is shutdown by
    // calling TestTask::end().
    // Accept requests
    orb_->run();
    orb_->destroy();

    // Shutdown the Naming Services.
    namingServiceA_.end();
    if (!shutdown_ns_)
      {
        namingServiceB_.end();
      }

    return 0;
  }
  catch (CORBA::Exception& ex)
  {
    ex._tao_print_exception ("CORBA exception: ");
  }

  return -1;
}

int main(int argc, char* argv[])
{
  // Start the Test task
  TestTask test_(argc, argv);
  if (test_.activate() == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR, "Unable to start test task.\n"), -1);
    }

  // Wait the Test task finish.
  test_.wait();

  return 0;
}
