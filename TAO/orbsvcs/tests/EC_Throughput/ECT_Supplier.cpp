// $Id$

#include "ace/Get_Opt.h"
#include "ace/Auto_Ptr.h"
#include "ace/Sched_Params.h"

#include "tao/Timeprobe.h"
#include "orbsvcs/Event_Utilities.h"
#include "orbsvcs/Event_Service_Constants.h"
#include "orbsvcs/Scheduler_Factory.h"
#include "orbsvcs/Time_Utilities.h"
#include "orbsvcs/Sched/Config_Scheduler.h"
#include "orbsvcs/Event/Event_Channel.h"
#include "ECT_Supplier.h"
#include "ECT_Data.h"

int
main (int argc, char *argv [])
{
  ECTS_Driver driver;
  return driver.run (argc, argv);
}

// ****************************************************************

ECTS_Driver::ECTS_Driver (void)
  : n_suppliers_ (1),
    event_count_ (100),
    event_period_ (100),
    event_a_ (ACE_ES_EVENT_UNDEFINED),
    event_b_ (ACE_ES_EVENT_UNDEFINED + 1),
    pid_file_name_ (0)
{
}



int
ECTS_Driver::run (int argc, char* argv[])
{
  TAO_TRY
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "", TAO_TRY_ENV);
      TAO_CHECK_ENV;

      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA");
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
                  "  suppliers = <%d>\n"
                  "  event count = <%d>\n"
                  "  event period = <%d>\n"
                  "  supplier Event A = <%d>\n"
                  "  supplier Event B = <%d>\n"
                  "  pid file name = <%s>\n",

                  this->n_suppliers_,
                  this->event_count_,
                  this->event_period_,
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
        orb->resolve_initial_references ("NameService");
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

      this->connect_suppliers (channel.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_DEBUG ((LM_DEBUG, "connected supplier(s)\n"));

      this->activate_suppliers (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_DEBUG ((LM_DEBUG, "suppliers are active\n"));

      // Wait for the supplier threads...
      if (ACE_Thread_Manager::instance ()->wait () == -1)
	{
	  ACE_ERROR ((LM_ERROR, "Thread_Manager wait failed\n"));
	  return 1;
	}

      ACE_DEBUG ((LM_DEBUG, "suppliers finished\n"));

      this->disconnect_suppliers (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      
      // @@ Deactivate the suppliers (as CORBA Objects?)
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

int
ECTS_Driver::supplier_task (Test_Supplier *supplier,
		       void* cookie)
{
  TAO_TRY
    {
      ACE_Time_Value tv (0, this->event_period_);

      CORBA::ULong n = this->event_count_;

      ECT_IDLData::Info info;
      info.mobile_name = CORBA::string_copy ("test");
      info.mobile_speed = 1;
      info.trajectory.length (n);

      ECT_Data other;
      other.description = CORBA::string_copy ("some data");

      for (CORBA::ULong j = 0; j < n; ++j)
	{
	  info.trajectory[j].x = j;
	  info.trajectory[j].y = j*j;
	  other.inventory.bind (j, j + 1);
	}

      // We have to make it big enough so we get a contiguous block,
      // otherwise the octet sequence will not work correctly.
      TAO_OutputCDR cdr (n * 16 + CDR::DEFAULT_BUFSIZE);

      CORBA::Boolean byte_order = TAO_ENCAP_BYTE_ORDER;
      cdr << byte_order;

      // The typecode name standard, the encode method is not (in
      // general the CDR interface is not specified).
      // @@ TODO once the compiled marshalling approach is in place
      // this will read: cdr << info;
      cdr.encode (ECT_IDLData::_tc_Info, &info, 0, TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Here we marshall a non-IDL type.
      cdr << other;

      const ACE_Message_Block* mb = cdr.begin ();
      CORBA::ULong mblen = cdr.length ();

      for (CORBA::ULong i = 0; i < n; ++i)
	{
	  RtecEventComm::EventSet event (1);
	  event.length (1);
	  event[0].source_ = supplier->supplier_id ();
	  event[0].ttl_ = 1;

	  ACE_hrtime_t t = ACE_OS::gethrtime ();
	  ORBSVCS_Time::hrtime_to_TimeT (event[0].creation_time_, t);
	  event[0].ec_recv_time_ = ORBSVCS_Time::zero;
	  event[0].ec_send_time_ = ORBSVCS_Time::zero;

	  if (i == this->event_count_ - 1)
	    event[0].type_ = ACE_ES_EVENT_SHUTDOWN;
	  else if (i % 2 == 0)
	    event[0].type_ = this->event_a_;
	  else
	    event[0].type_ = this->event_b_;

	  event[0].data_.x = 0;
	  event[0].data_.y = 0;

	  // We use replace to minimize the copies, this should result
	  // in just one memory allocation; 
	  event[0].data_.payload.replace (mblen, mb);

	  supplier->consumer_proxy ()->push(event, TAO_TRY_ENV);
	  TAO_CHECK_ENV;

	  // ACE_DEBUG ((LM_DEBUG, "(%t) supplier push event\n"));
	  
	  ACE_OS::sleep (tv);
	}
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
ECTS_Driver::connect_suppliers (RtecEventChannelAdmin::EventChannel_ptr channel,
			   CORBA::Environment &_env)
{
  for (int i = 0; i < this->n_suppliers_; ++i)
    {
      char buf[BUFSIZ];
      ACE_OS::sprintf (buf, "supplier_%02.2d", i);

      ACE_NEW (this->suppliers_[i], Test_Supplier (this));

      this->suppliers_[i]->connect (buf,
				    this->event_a_,
				    this->event_b_,
				    this->event_period_,
				    channel,
				    _env);
      if (_env.exception () != 0) return;
    }
}

void
ECTS_Driver::activate_suppliers (CORBA::Environment &)
{
  for (int i = 0; i < this->n_suppliers_; ++i)
    {
      this->suppliers_[i]->activate ();
    }
}

void
ECTS_Driver::disconnect_suppliers (CORBA::Environment &_env)
{
  for (int i = 0; i < this->n_suppliers_; ++i)
    {
      this->suppliers_[i]->disconnect (_env);
      if (_env.exception () != 0) return;
    }
}

int
ECTS_Driver::parse_args (int argc, char *argv [])
{
  ACE_Get_Opt get_opt (argc, argv, "ds:n:t:h:p:");
  int opt;

  while ((opt = get_opt ()) != EOF)
    {
      switch (opt)
        {
	case 's':
	  this->n_suppliers_ = ACE_OS::atoi (get_opt.optarg);
	  break;

	case 'n':
	  this->event_count_ = ACE_OS::atoi (get_opt.optarg);
	  break;

	case 't':
	  this->event_period_ = ACE_OS::atoi (get_opt.optarg);
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
                      "-s <nsuppliers> "
		      "-n <event count> "
		      "-t <event period (usecs)> "
                      "-h <eventa,eventb> "
                      "-p <pid file name> "
                      "\n",
                      argv[0]));
          return -1;
        }
    }

  if (this->event_count_ <= 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s: event count (%d) is out of range, "
                  "reset to default (%d)\n",
                  argv[0], this->event_count_,
                  100));
      this->event_count_ = 100;
    }

  if (this->n_suppliers_ <= 0)
    {
      ACE_ERROR_RETURN ((LM_DEBUG,
                         "%s: number of suppliers out of range, "
			 "reset to default (%d)\n",
			 argv[0], 1), -1);
      this->n_suppliers_ = 1;
    }

  return 0;
}

// ****************************************************************

Test_Supplier::Test_Supplier (ECTS_Driver *driver)
  :  driver_ (driver),
     supplier_ (this)
{
}

void
Test_Supplier::connect (const char* name,
			int event_a,
			int event_b,
			int event_period,
			RtecEventChannelAdmin::EventChannel_ptr ec,
			CORBA::Environment &_env)
{
  TAO_TRY
    {
      RtecScheduler::Scheduler_ptr server =
        ACE_Scheduler_Factory::server ();

      RtecScheduler::handle_t rt_info =
        server->create (name, TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_Time_Value tv (0, event_period);
      RtecScheduler::Period rate = tv.usec () * 10;

      // The execution times are set to reasonable values, but
      // actually they are changed on the real execution, i.e. we
      // lie to the scheduler to obtain right priorities; but we
      // don't care if the set is schedulable.
      tv.set (0, 2000);
      TimeBase::TimeT time;
      ORBSVCS_Time::Time_Value_to_TimeT (time, tv);
      server->set (rt_info,
                   RtecScheduler::VERY_HIGH_CRITICALITY,
                   time, time, time,
                   rate,
                   RtecScheduler::VERY_LOW_IMPORTANCE,
                   time,
                   1,
                   RtecScheduler::OPERATION,
                   TAO_TRY_ENV);
      TAO_CHECK_ENV;

      this->supplier_id_ = ACE::crc32 (name);
      ACE_DEBUG ((LM_DEBUG, "ID for <%s> is %04.4x\n", name,
                  this->supplier_id_));

      ACE_SupplierQOS_Factory qos;
      qos.insert (this->supplier_id_,
                  event_a,
                  rt_info, 1);
      qos.insert (this->supplier_id_,
                  event_b,
                  rt_info, 1);
      qos.insert (this->supplier_id_,
                  ACE_ES_EVENT_SHUTDOWN,
                  rt_info, 1);

      RtecEventChannelAdmin::SupplierAdmin_var supplier_admin =
        ec->for_suppliers (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      this->consumer_proxy_ =
        supplier_admin->obtain_push_consumer (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      RtecEventComm::PushSupplier_var objref =
	this->supplier_._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      this->consumer_proxy_->connect_push_supplier (objref.in (),
                                                    qos.get_SupplierQOS (),
                                                    TAO_TRY_ENV);
      TAO_CHECK_ENV;

    }
  TAO_CATCHANY
    {
      TAO_RETHROW;
    }
  TAO_ENDTRY;
}

void
Test_Supplier::disconnect (CORBA::Environment &_env)
{
  if (CORBA::is_nil (this->consumer_proxy_.in ()))
    return;

  this->consumer_proxy_->disconnect_push_consumer (_env);
  if (_env.exception () != 0) return;

  this->consumer_proxy_ = 0;
}

int
Test_Supplier::svc ()
{
  return this->driver_->supplier_task (this, this->cookie_);
}

void
Test_Supplier::disconnect_push_supplier (CORBA::Environment& _env)
{
}

int Test_Supplier::supplier_id (void) const
{
  return this->supplier_id_;
}

RtecEventChannelAdmin::ProxyPushConsumer_ptr
Test_Supplier::consumer_proxy (void)
{
  return this->consumer_proxy_;
}

// ****************************************************************

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_PushSupplier_Adapter<Test_Supplier>;
#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_PushSupplier_Adapter<Test_Supplier>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
