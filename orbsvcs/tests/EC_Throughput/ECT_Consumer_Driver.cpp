// $Id$

#include "ace/Get_Opt.h"
#include "ace/Auto_Ptr.h"
#include "ace/Sched_Params.h"

#include "tao/Timeprobe.h"
#include "orbsvcs/Event_Utilities.h"
#include "orbsvcs/Event_Service_Constants.h"
#include "orbsvcs/Scheduler_Factory.h"
#include "orbsvcs/Time_Utilities.h"
#include "ECT_Consumer_Driver.h"

ACE_RCSID(EC_Throughput, ECT_Consumer_Driver, "$Id$")

int
main (int argc, char *argv [])
{
  ECT_Consumer_Driver driver;
  return driver.run (argc, argv);
}

// ****************************************************************

ECT_Consumer_Driver::ECT_Consumer_Driver (void)
  : n_consumers_ (1),
    n_suppliers_ (1),
    event_a_ (ACE_ES_EVENT_UNDEFINED),
    event_b_ (ACE_ES_EVENT_UNDEFINED + 1),
    pid_file_name_ (0),
    active_count_ (0)
{
}

ECT_Consumer_Driver::~ECT_Consumer_Driver (void)
{
}

int
ECT_Consumer_Driver::run (int argc, char* argv[])
{
  TAO_TRY
    {
      this->orb_ =
        CORBA::ORB_init (argc, argv, "", TAO_TRY_ENV);
      TAO_CHECK_ENV;

      CORBA::Object_var poa_object =
        this->orb_->resolve_initial_references("RootPOA");
      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      if (this->parse_args (argc, argv))
        return 1;

      ACE_DEBUG ((LM_DEBUG,
                  "Execution parameters:\n"
                  "  consumers = <%d>\n"
                  "  suppliers = <%d>\n"
                  "  supplier Event A = <%d>\n"
                  "  supplier Event B = <%d>\n"
                  "  pid file name = <%s>\n",

                  this->n_consumers_,
                  this->n_suppliers_,
                  this->event_a_,
                  this->event_b_,

                  this->pid_file_name_?this->pid_file_name_:"nil") );

      if (this->pid_file_name_ != 0)
        {
          FILE* pid = ACE_OS::fopen (this->pid_file_name_, "w");
          if (pid != 0)
            {
              ACE_OS::fprintf (pid, "%d\n", ACE_OS::getpid ());
              ACE_OS::fclose (pid);
            }
        }

      int min_priority =
        ACE_Sched_Params::priority_min (ACE_SCHED_FIFO);
        // Enable FIFO scheduling, e.g., RT scheduling class on Solaris.

      if (ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                                  min_priority,
                                                  ACE_SCOPE_PROCESS)) != 0)
        {
          if (ACE_OS::last_error () == EPERM)
            ACE_DEBUG ((LM_DEBUG,
                        "%s: user is not superuser, "
                        "so remain in time-sharing class\n", argv[0]));
          else
            ACE_ERROR ((LM_ERROR,
                        "%s: ACE_OS::sched_params failed\n", argv[0]));
        }

      if (ACE_OS::thr_setprio (min_priority) == -1)
        {
          ACE_ERROR ((LM_ERROR, "(%P|%t) main thr_setprio failed,"
                      "no real-time features\n"));
        }

      CORBA::Object_var naming_obj =
        this->orb_->resolve_initial_references ("NameService");
      if (CORBA::is_nil (naming_obj.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to get the Naming Service.\n"),
                          1);

      CosNaming::NamingContext_var naming_context =
        CosNaming::NamingContext::_narrow (naming_obj.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;

      if (ACE_Scheduler_Factory::use_config (naming_context.in ()) == -1)
        return -1;

      CosNaming::Name name (1);
      name.length (1);
      name[0].id = CORBA::string_dup ("EventService");

      CORBA::Object_var ec_obj =
        naming_context->resolve (name, TAO_TRY_ENV);
      TAO_CHECK_ENV;

      RtecEventChannelAdmin::EventChannel_var channel;
      if (CORBA::is_nil (ec_obj.in ()))
        channel = RtecEventChannelAdmin::EventChannel::_nil ();
      else
        channel = RtecEventChannelAdmin::EventChannel::_narrow (ec_obj.in (),
                                                                TAO_TRY_ENV);
      TAO_CHECK_ENV;

      poa_manager->activate (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      this->connect_consumers (channel.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_DEBUG ((LM_DEBUG, "connected consumer(s)\n"));

      ACE_DEBUG ((LM_DEBUG, "running the test\n"));
      if (this->orb_->run () == -1)
        ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "orb->run"), -1);
      ACE_DEBUG ((LM_DEBUG, "event loop finished\n"));

      this->dump_results ();

      this->disconnect_consumers (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      channel->destroy (TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCH (CORBA::SystemException, sys_ex)
    {
      TAO_TRY_ENV.print_exception ("SYS_EX");
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("NON SYS EX");
    }
  TAO_ENDTRY;
  return 0;
}

void
ECT_Consumer_Driver::shutdown_consumer (void*,
                                        CORBA::Environment &)
{
  // int ID =
  //   (ACE_reinterpret_cast(Test_Consumer**,consumer_cookie)
  //    - this->consumers_);
  //
  // ACE_DEBUG ((LM_DEBUG, "(%t) events received by consumer %d\n", ID));

  ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock_);
  this->active_count_--;
  if (this->active_count_ <= 0)
    this->orb_->shutdown ();
}

void
ECT_Consumer_Driver::connect_consumers (RtecEventChannelAdmin::EventChannel_ptr channel,
                           CORBA::Environment &_env)
{
  {
    ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock_);
    this->active_count_ = this->n_consumers_;
  }
  for (int i = 0; i < this->n_consumers_; ++i)
    {
      char buf[BUFSIZ];
      ACE_OS::sprintf (buf, "consumer_%02.2d", i);

      ACE_NEW (this->consumers_[i],
               Test_Consumer (this,
                              this->consumers_ + i,
                              this->n_suppliers_));

      this->consumers_[i]->connect (buf,
                                    this->event_a_,
                                    this->event_b_,
                                    channel,
                                    _env);
      if (_env.exception () != 0) return;
    }
}

void
ECT_Consumer_Driver::dump_results (void)
{
  for (int i = 0; i < this->n_consumers_; ++i)
    {
      char buf[BUFSIZ];
      ACE_OS::sprintf (buf, "consumer_%02.2d", i);

      this->consumers_[i]->dump_results (buf);
    }
}

void
ECT_Consumer_Driver::disconnect_consumers (CORBA::Environment &_env)
{
  for (int i = 0; i < this->n_consumers_; ++i)
    {
      this->consumers_[i]->disconnect (_env);
      if (_env.exception () != 0) return;
    }
}

int
ECT_Consumer_Driver::parse_args (int argc, char *argv [])
{
  ACE_Get_Opt get_opt (argc, argv, "dc:s:h:p:");
  int opt;

  while ((opt = get_opt ()) != EOF)
    {
      switch (opt)
        {
        case 'c':
          this->n_consumers_ = ACE_OS::atoi (get_opt.optarg);
          break;

        case 's':
          this->n_suppliers_ = ACE_OS::atoi (get_opt.optarg);
          break;

        case 'h':
          {
            char* aux;
                char* arg = ACE_OS::strtok_r (get_opt.optarg, ",", &aux);

            this->event_a_ = ACE_ES_EVENT_UNDEFINED + ACE_OS::atoi (arg);
                arg = ACE_OS::strtok_r (0, ",", &aux);
            this->event_b_ = ACE_ES_EVENT_UNDEFINED + ACE_OS::atoi (arg);
          }
          break;

        case 'p':
          this->pid_file_name_ = get_opt.optarg;
          break;

        case '?':
        default:
          ACE_DEBUG ((LM_DEBUG,
                      "Usage: %s "
                      "[ORB options] "
                      "-c <n_consumers> "
                      "-s <n_suppliers> "
                      "-h <event_a,event_b> "
                      "-p <pid file name> "
                      "\n",
                      argv[0]));
          return -1;
        }
    }

  if (this->n_suppliers_ <= 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s: number of suppliers (%d) is out of range, "
                  "reset to default (%d)\n",
                  argv[0], this->n_suppliers_,
                  1));
      this->n_suppliers_ = 1;
    }

  if (this->n_consumers_ <= 0)
    {
      ACE_ERROR_RETURN ((LM_DEBUG,
                         "%s: number of consumers or "
                         "suppliers out of range\n", argv[0]), -1);
    }

  return 0;
}
