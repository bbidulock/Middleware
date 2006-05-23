
/* -*- C++ -*- */

//======================================================================
/**
 * @file RepositoryManager.cpp
 *
 * $Id$
 *
 * Description:
 *  Main driver program for the CIAO RepositoryManager
 *  Please run as follows:
 *       RepositoryManagerDeamon [int:nthreads]
 *
 * @author Stoyan Paunov
 */
//======================================================================

#include "RepositoryManager_Impl.h"
#include "ace/OS_NS_stdio.h"
#include "ace/streams.h"
#include "ace/Auto_Ptr.h"
#include "ace/Task.h"
#include "ace/Get_Opt.h"
#include "ace/SString.h"

#include "orbsvcs/CosNamingC.h"

namespace CIAO
{
  namespace RepositoryManager
  {
    /// Name of the file holding the IOR of the RM
    const char * RMior = "RepositoryManagerDeamon.ior";

    // Name of Naming service
    char * repoman_name_;

    //Name service of the RM
    char * RMname_service = "RepositoryManager";

    /// Default number of worker threads to run in the multi-threaded RM
    static unsigned int nthreads = 3;
    static ACE_CString HTTPserver = "127.0.0.1:5432";

    static bool register_with_ns_ = false;
    static bool write_to_ior_ = true;
  }
}

//forward declaration
bool parse_args (int argc, char *argv[]);

/**
 * @class Worker
 *
 * Class that implements the service routine of the worker threads
 * of the repository manager
 */
class Worker : public ACE_Task_Base
{
public:
  /// ctor
  Worker (CORBA::ORB_ptr orb);

  /// The thread entry point.
  virtual int svc (void);

private:
  /// The orb
  CORBA::ORB_var orb_;
};

bool
write_ior_file (CORBA::ORB_ptr orb,
                CIAO::RepositoryManagerDaemon_ptr obj
                ACE_ENV_ARG_DECL)
{
  CORBA::String_var ior =
    orb->object_to_string (obj
    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (false);

  FILE* RMior_file =
    ACE_OS::fopen (CIAO::RepositoryManager::RMior, "w");

  if (RMior_file)
  {
    ACE_OS::fprintf (RMior_file,
      "%s",
      ior.in ());
    ACE_OS::fclose (RMior_file);
  }
  else
    return false;

  return true;
}

bool
register_with_ns (CORBA::ORB_ptr orb,
                  CIAO::RepositoryManagerDaemon_ptr obj
                  ACE_ENV_ARG_DECL)
{
  if (CIAO::RepositoryManager::repoman_name_ != "")
    CIAO::RepositoryManager::RMname_service = 
      CIAO::RepositoryManager::repoman_name_;

  // Naming Service related operations
  CORBA::Object_var naming_context_object =
    orb->resolve_initial_references ("NameService"
    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (false);

  CosNaming::NamingContext_var naming_context =
    CosNaming::NamingContext::_narrow (naming_context_object.in ());

  // Initialize the Naming Sequence
  CosNaming::Name name (1);
  name.length (1);

  // String dup required for MSVC6
  name[0].id = CORBA::string_dup (CIAO::RepositoryManager::RMname_service);

  // Register the servant with the Naming Service
  naming_context->rebind (name, obj);
 
  return true;
}

///Main function

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  try
  {
    //init the ORB
    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

    if (!parse_args (argc, argv))
       return -1;

    //Get the root POA object
    CORBA::Object_var obj = orb->resolve_initial_references ("RootPOA");

    //downcast to POA type
    PortableServer::POA_var root_poa = PortableServer::POA::_narrow (obj.in ());

    //activate the POA manager
    PortableServer::POAManager_var mgr = root_poa->the_POAManager ();
    mgr->activate ();

    //create a servant
    CIAO_RepositoryManagerDaemon_i* repo;
    ACE_NEW_RETURN (repo,
                    CIAO_RepositoryManagerDaemon_i (
                          orb.in (),
                          CIAO::RepositoryManager::HTTPserver.c_str ()),
                    1);

    //trasfer ownership to the POA
    PortableServer::ServantBase_var owner_transfer(repo);

    //register and implicitly activate servant
    CIAO::RepositoryManagerDaemon_var RepositoryManagerDeamon = repo->_this ();

    bool retval = false;

    if (CIAO::RepositoryManager::write_to_ior_)
    {
      retval =
        write_ior_file (orb.in (),
        RepositoryManagerDeamon.in ()
        ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
    else if (CIAO::RepositoryManager::register_with_ns_)
    {
      retval =
        register_with_ns (orb.in (),
        RepositoryManagerDeamon.in ()
        ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }

    if (!retval)
      return -1;


    Worker worker (orb.in ());
    if (worker.activate (THR_NEW_LWP | THR_JOINABLE,
                         CIAO::RepositoryManager::nthreads) != 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot activate worker threads\n"),
                           1);

    worker.thr_mgr ()->wait ();

    ACE_DEBUG ((LM_DEBUG, "event loop finished\n"));

    //done
    return 0;

    //Start accepting requests
    orb->run ();

    //allow objects registered with the POA ot get cleaned-up
    root_poa->destroy (1, 1);

    //shutdown the orb
    orb->shutdown (1);

    return 0;
  }
  catch (CORBA::Exception &ex) {
    cerr << "CORBA Exception: " << ex << endl;

    return 1;
  }


  return 0;
}


// ****************************************************************

///Code to parse the arguments

    bool
    parse_args (int argc, char *argv[])
    {
      ACE_Get_Opt get_opts (argc, argv, "ov:s:n:");
      int c;
      while ((c = get_opts ()) != -1)
        switch (c)
          {
          case 'o':
            CIAO::RepositoryManager::write_to_ior_ = true;
            CIAO::RepositoryManager::register_with_ns_ = false;
            break;
          case 'v':
            CIAO::RepositoryManager::write_to_ior_ = false;
            CIAO::RepositoryManager::register_with_ns_ = true;
            CIAO::RepositoryManager::repoman_name_ = get_opts.opt_arg ();
            break;
          case 's':
            CIAO::RepositoryManager::HTTPserver = get_opts.opt_arg ();
            break;
          case 'n':
            CIAO::RepositoryManager::nthreads = ACE_OS::atoi (get_opts.opt_arg ());
            break;
          case '?':  // display help for use of the server.
            ACE_DEBUG ((LM_INFO,
                        "usage:  %s\n"
                        "-o <using ior file>\n"
                        "-v <name of naming service>\n"
                        "-s <IP:PORT for HTTP server>\n"
                        "-n <number of threads>\n",
                        argv [0]));
            return false;
            break;
          default:
            ;
          }

      return true;
    }



// ****************************************************************

///Constuctor for the worker class
Worker::Worker (CORBA::ORB_ptr orb)
  :  orb_ (CORBA::ORB::_duplicate (orb))
{
}

///implementation of the service routine inherited from ACE::Task_Base

int Worker::svc (void)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      this->orb_->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;
  return 0;
}


