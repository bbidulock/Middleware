// $Id$
#include "ServerApp.h"
#include "AppHelper.h"
#include "OrbRunner.h"
#include "AppShutdown.h"
#include "TestAppExceptionC.h"
#include "Foo_B_SimpleClientEngine.h"
#include "Callback_i.h"
#include "ace/OS.h"
#include "ace/Get_Opt.h"
// To force static load the service.
#include "tao/PI/PI.h"
#include "tao/CSD_ThreadPool/CSD_ThreadPool.h"


ServerApp::ServerApp()
  : TestAppBase("TP_Test_3_Server"),
    ior_filename_prefix_("foo"),
    num_servants_(1),
    num_csd_threads_(1),
    num_orb_threads_(1),
    num_remote_clients_(1),
    num_collocated_clients_(0),
    collocated_client_kind_(0)
{
}


ServerApp::~ServerApp()
{
}


int
ServerApp::run_i(int argc, char* argv[] ACE_ENV_ARG_DECL)
{
  int result = this->init(argc, argv ACE_ENV_ARG_PARAMETER);
  if (result != 0)   
    {
      return result;
    }
  ACE_CHECK_RETURN (-1);

  this->poa_setup(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  this->csd_setup(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  this->servant_setup(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  this->collocated_setup(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  this->poa_activate(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  this->run_collocated_clients(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  this->run_orb_event_loop(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  this->cleanup();
  return this->check_validity () ? 0 : -1;
}


int
ServerApp::init(int argc, char* argv[] ACE_ENV_ARG_DECL)
{
  this->orb_ = CORBA::ORB_init(argc, argv, "" ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  // Parse the command-line args for this application.
  // * Raises -1 if problems are encountered.
  // * Returns 1 if the usage statement was explicitly requested.
  // * Returns 0 otherwise.
  int result = this->parse_args(argc, argv);
  if (result != 0)
    {
      return result;
    }

  unsigned num_clients = this->num_remote_clients_ +
                         this->num_collocated_clients_;

  TheAppShutdown->init(this->orb_.in(), num_clients ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  return 0;
}


void
ServerApp::poa_setup(ACE_ENV_SINGLE_ARG_DECL)
{
  this->poa_ = this->create_poa(this->orb_.in(), 
                                "ChildPoa" 
                                ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  
  if (this->num_collocated_clients_ > 0)
    {
      this->cb_poa_ = this->create_poa(this->orb_.in(), 
                                       "CallbackPoa" 
                                       ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
}

void
ServerApp::csd_setup(ACE_ENV_SINGLE_ARG_DECL)
{
  this->tp_strategy_ = new TAO::CSD::TP_Strategy(this->num_csd_threads_);

// We don't apply the strategy for this test to show that the bug isn't
// part of the CSD ThreadPool Strategy code.
#if 0
  if (!this->tp_strategy_->apply_to(this->poa_.in() ACE_ENV_ARG_PARAMETER))
    {
      ACE_ERROR((LM_ERROR,
                 "Failed to apply CSD strategy to poa.\n"));
      ACE_THROW(TestAppException());
    }
  ACE_CHECK;
#endif

  // Use another poa and strategy for callbacks. This would resolve
  // the deadlock situation that happens when having number of csd 
  // threads less than number of collocated clients.
  if (this->num_collocated_clients_ > 0)
    {
      this->cb_tp_strategy_ = new TAO::CSD::TP_Strategy();
// We don't apply the strategy for this test to show that the bug isn't
// part of the CSD ThreadPool Strategy code.
#if 0
      if (!this->cb_tp_strategy_->apply_to(this->cb_poa_.in() ACE_ENV_ARG_PARAMETER))
        {
          ACE_ERROR((LM_ERROR,
            "Failed to apply CSD strategy to callback poa.\n"));
          ACE_THROW(TestAppException());
        } 
  ACE_CHECK;
#endif
    }
}


void
ServerApp::servant_setup(ACE_ENV_SINGLE_ARG_DECL)
{
  this->foo_servants_.create_and_activate(this->num_servants_,
                                      this->orb_.in (),
                                      this->poa_.in (),
                                      this->ior_filename_prefix_.c_str()
                                      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}


void
ServerApp::collocated_setup(ACE_ENV_SINGLE_ARG_DECL)
{
  if (this->num_collocated_clients_ == 0)
    return;

  this->cb_servants_.create_and_activate(1, // number of callback servants
                                         this->cb_poa_.in()
                                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CallbackServantListType::T_stub_var cb = this->cb_servants_.objref(0);
  
  unsigned client_id = this->num_remote_clients_;

  for (unsigned i = 0; i < this->num_collocated_clients_; i++)
    {
      client_id ++;
      // Dole out the servant object references in a round-robin fashion.
      unsigned servant_index = i % this->num_servants_;

      FooServantListType::T_stub_var foo 
        = this->foo_servants_.objref(servant_index);
      ClientEngine_Handle engine 
        = new Foo_B_SimpleClientEngine(foo.in(), cb.in (), client_id, true);
      this->collocated_client_task_.add_engine(engine.in());
    }
}


void
ServerApp::poa_activate(ACE_ENV_SINGLE_ARG_DECL)
{
  PortableServer::POAManager_var poa_manager 
    = this->poa_->the_POAManager(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  poa_manager->activate(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}


void
ServerApp::run_collocated_clients(ACE_ENV_SINGLE_ARG_DECL)
{
  if (this->num_collocated_clients_ > 0)
    {
      if (this->collocated_client_task_.open() == -1)
        {
          ACE_THROW (TestAppException ());
        }
    }
}


void
ServerApp::run_orb_event_loop(ACE_ENV_SINGLE_ARG_DECL)
{
  OrbRunner orb_runner(this->orb_.in(), this->num_orb_threads_);
  orb_runner.run(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  TheAppShutdown->wait ();
}


void
ServerApp::cleanup()
{
}


int
ServerApp::parse_args(int argc, char* argv[])
{
  this->exe_name_ = argv[0];

  ACE_Get_Opt get_opts(argc, argv, "p:s:n:t:r:c:k:");

  int c;

  while ((c = get_opts()) != -1)
    {
      int result = 0;
      switch (c)
      {
        case 'p':
          this->ior_filename_prefix_ = get_opts.opt_arg();
          break;

        case 's':
          result = set_arg(this->num_servants_,
                  get_opts.opt_arg(),
                  c,
                  "num_servants",
                  1);
          break;

        case 'n':
          result = set_arg(this->num_csd_threads_,
                  get_opts.opt_arg(),
                  c,
                  "num_servants",
                  1);
          break;

        case 't':
          result = set_arg(this->num_orb_threads_,
                  get_opts.opt_arg(),
                  c,
                  "num_orb_threads",
                  1);
          break;

        case 'r':
          result = set_arg(this->num_remote_clients_,
                  get_opts.opt_arg(),
                  c,
                  "num_remote_clients");
          break;

        case 'c':
          result = set_arg(this->num_collocated_clients_,
                  get_opts.opt_arg(),
                  c,
                  "num_collocated_clients");
          break;

        case 'k':
          result = set_arg(this->collocated_client_kind_,
                  get_opts.opt_arg(),
                  c,
                  "collocated_client_kind");
          break;

        case '?':
          this->usage_statement();
          return 1;

        default:
          this->usage_statement();
          return -1;
      }

      if (result != 0)
        {
          return result;
        }
    }

  return this->arg_dependency_checks();
}

void
ServerApp::usage_statement()
{
  ACE_ERROR((LM_ERROR,
             "Usage:  %s [options]\n\n"
             "OPTIONS:\n\n"
             "\t[-p <ior_filename_prefix>]\n"
             "\t[-s <num_servants>]\n"
             "\t[-n <num_csd_threads>]\n"
             "\t[-t <num_orb_threads>]\n"
             "\t[-r <num_remote_clients>]\n"
             "\t[-c <num_collocated_clients>]\n"
             "\t[-k <collocated_client_kind>]\n"
             "\t[-?]\n\n",
             this->exe_name_.c_str()));
}


int
ServerApp::arg_dependency_checks()
{
  return (this->num_remote_clients_ 
          + this->num_collocated_clients_) > 0 ? 0 : -1;
}


int
ServerApp::set_arg(unsigned&   value,
                   const char* arg,
                   char        opt,
                   const char* name,
                   int         min)
{
  int tmp = ACE_OS::atoi(arg);

  if (tmp < min)
    {
      ACE_ERROR((LM_ERROR,
                 "Error: -%c <%s> must be integer type with a value of, "
                 "at least, %d.\n", opt, name, min));
      this->usage_statement();
      return -1;
    }

  value = tmp;
  return 0;
}


PortableServer::POA_ptr
ServerApp::create_poa(CORBA::ORB_ptr orb, 
                      const char* poa_name 
                      ACE_ENV_ARG_DECL)
{
  // Get the Root POA.
  PortableServer::POA_var root_poa
    = RefHelper<PortableServer::POA>::resolve_initial_ref(orb, 
                                                          "RootPOA" 
                                                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (PortableServer::POA::_nil ());

  // Get the POAManager from the Root POA.
  PortableServer::POAManager_var poa_manager 
    = root_poa->the_POAManager(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (PortableServer::POA::_nil ());

  // Create the child POA Policies.
  CORBA::PolicyList policies(0);
  policies.length(0);

  // Create the child POA
  PortableServer::POA_var poa = AppHelper::create_poa(poa_name,
                                                      root_poa.in(),
                                                      poa_manager.in(),
                                                      policies
                                                      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (PortableServer::POA::_nil ());

  // Give away the child POA_ptr from the POA_var variable.
  return poa._retn();
}


bool
ServerApp::check_validity ()
{
  return true;
#if 0
  // Check whether the clients return any errors.
  if (this->num_collocated_clients_ > 0 
    && this->collocated_client_task_.failure_count () > 0)
    {
      return false;
    }

  Foo_B_Statistics stats (this->num_remote_clients_,
                          this->num_collocated_clients_);
  
  Foo_B_SimpleClientEngine::expected_results (stats);

  for (unsigned i = 0; i < this->num_servants_; i++)
    {
      this->foo_servants_.servant(i)->gather_stats (stats);
    }

  if (this->num_collocated_clients_ > 0)
    {
      this->cb_servants_.servant (0)->gather_stats (stats);
    }

  return stats.actual_vs_expected ();
#endif
}

