// $Id$

#include "ace/Get_Opt.h"
#include "ace/Auto_Ptr.h"
#include "ace/Sched_Params.h"

#include "orbsvcs/Event_Utilities.h"
#include "orbsvcs/Event_Service_Constants.h"
#include "orbsvcs/Scheduler_Factory.h"
#include "orbsvcs/Time_Utilities.h"
#include "orbsvcs/RtecEventChannelAdminC.h"
#include "orbsvcs/Sched/Config_Scheduler.h"
#include "orbsvcs/Runtime_Scheduler.h"
#include "orbsvcs/Event/Event_Channel.h"
#include "orbsvcs/Event/Module_Factory.h"
#include "EC_Basic.h"

#if !defined (__ACE_INLINE__)
#include "EC_Basic.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(EC_Basic, EC_Basic, "$Id$")

ECB_Driver::ECB_Driver (void)
  : pid_filename_ (0)
{
}

int
ECB_Driver::run (int argc, char* argv[])
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
                  "EC_Basic: Execution parameters:\n"
                  "  pid file name = <%s>\n",
                  this->pid_filename_?this->pid_filename_:"nil") );

      if (this->pid_filename_ != 0)
        {
          FILE* pid = ACE_OS::fopen (this->pid_filename_, "w");
          if (pid != 0)
            {
              ACE_OS::fprintf (pid, "%d\n", ACE_OS::getpid ());
              ACE_OS::fclose (pid);
            }
        }

      ACE_Config_Scheduler scheduler_impl;
      RtecScheduler::Scheduler_var scheduler =
        scheduler_impl._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      CORBA::String_var str =
        this->orb_->object_to_string (scheduler.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;
      ACE_DEBUG ((LM_DEBUG,
                  "EC_Basic: The (local) scheduler IOR is <%s>\n",
                  str.in ()));

      if (ACE_Scheduler_Factory::server (scheduler.in ()) == -1)
        return -1;

      // Create the EventService implementation, but don't start its
      // internal threads.
      TAO_Reactive_Module_Factory module_factory;
      ACE_EventChannel ec_impl (0,
                                ACE_DEFAULT_EVENT_CHANNEL_TYPE,
                                &module_factory);

      // Register Event_Service with the Naming Service.
      RtecEventChannelAdmin::EventChannel_var ec =
        ec_impl._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      str = this->orb_->object_to_string (ec.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_DEBUG ((LM_DEBUG,
                  "EC_Basic: The (local) EC IOR is <%s>\n",
                  str.in ()));

      poa_manager->activate (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      RtecEventChannelAdmin::EventChannel_var local_ec =
        ec_impl._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ec_impl.activate ();

      ACE_DEBUG ((LM_DEBUG, "EC_Basic: local EC objref ready\n"));

      ACE_DEBUG ((LM_DEBUG, "EC_Basic: start supplier_id_test\n"));

      ECB_SupplierID_Test supplier_id_test;
      supplier_id_test.run (this->orb_,
                            local_ec,
                            scheduler,
                            TAO_TRY_ENV);
      TAO_CHECK_ENV;

      if (supplier_id_test.dump_results () != 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "EC_Basic: supplier_id test failed\n"),
                          -1);
      ACE_DEBUG ((LM_DEBUG, "EC_Basic: end supplier_id_test\n"));

      ACE_DEBUG ((LM_DEBUG, "EC_Basic: shutdown the EC\n"));
      ec_impl.shutdown ();
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

// ****************************************************************

int
ECB_Driver::parse_args (int argc, char *argv [])
{
  ACE_Get_Opt get_opt (argc, argv, "p:");
  int opt;

  while ((opt = get_opt ()) != EOF)
    {
      switch (opt)
        {
        case 'p':
          this->pid_filename_ = get_opt.optarg;
          break;


        case '?':
        default:
          ACE_DEBUG ((LM_DEBUG,
                      "Usage: %s "
                      "[ORB options] "
                      "-p <pid file name> "
                      "\n",
                      argv[0]));
          return -1;
        }
    }

  return 0;
}

// ****************************************************************

ECB_SupplierID_Test::ECB_SupplierID_Test (void)
  :  consumer0_ (this, 0),
     consumer1_ (this, 1),
     supplier0_ (this, ACE_ES_EVENT_UNDEFINED + 1),
     supplier1_ (this, ACE_ES_EVENT_UNDEFINED + 2)
{
}

void
ECB_SupplierID_Test::run (CORBA::ORB_ptr orb,
                          RtecEventChannelAdmin::EventChannel_ptr ec,
                          RtecScheduler::Scheduler_ptr scheduler,
                          CORBA::Environment& _env)
{
  int i;

  for (i = 0; i < ECB_SupplierID_Test::PHASE_END; ++i)
    {
      this->event_count_[i] = 0;
      this->error_count_[i] = 0;
    }

  // Startup
  this->consumer0_.open ("SupplierID/consumer0",
                         ec, scheduler, _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->consumer1_.open ("SupplierID/consumer1",
                         ec, scheduler, _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->supplier0_.open ("SupplierID/supplier0",
                         ec, scheduler, _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->supplier1_.open ("SupplierID/supplier1",
                         ec, scheduler, _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  // PHASE 0, test filtering by supplier ID in the presence of
  // multiple suppliers with the same ID...
  this->phase_ = ECB_SupplierID_Test::PHASE_0;

  this->consumer0_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->consumer1_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  this->supplier0_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->supplier1_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  for (i = 0; i < ECB_SupplierID_Test::EVENTS_SENT; ++i)
    {
      this->supplier0_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
      this->supplier1_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }

  // PHASE 1, test disconnection of a single supplier.
  this->phase_ = ECB_SupplierID_Test::PHASE_1;
  this->supplier1_.disconnect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  for (i = 0; i < ECB_SupplierID_Test::EVENTS_SENT; ++i)
    {
      this->supplier0_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }

  // PHASE 2, test reconnection of the supplier.
  this->phase_ = ECB_SupplierID_Test::PHASE_2;
  this->supplier1_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  for (i = 0; i < ECB_SupplierID_Test::EVENTS_SENT; ++i)
    {
      this->supplier0_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
      this->supplier1_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }

  // PHASE 3, test disconnect of one consumer
  this->phase_ = ECB_SupplierID_Test::PHASE_3;
  this->consumer1_.disconnect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  for (i = 0; i < ECB_SupplierID_Test::EVENTS_SENT; ++i)
    {
      this->supplier0_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
      this->supplier1_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }

  // PHASE 4, test reconnection of one consumer
  this->phase_ = ECB_SupplierID_Test::PHASE_4;
  this->consumer1_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  for (i = 0; i < ECB_SupplierID_Test::EVENTS_SENT; ++i)
    {
      this->supplier0_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
      this->supplier1_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }

  // PHASE 5, test disconnection of two consumers.
  this->phase_ = ECB_SupplierID_Test::PHASE_5;
  this->consumer0_.disconnect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->consumer1_.disconnect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  for (i = 0; i < ECB_SupplierID_Test::EVENTS_SENT; ++i)
    {
      this->supplier0_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
      this->supplier1_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }

  // PHASE 6, test reconnection of two consumers.
  this->phase_ = ECB_SupplierID_Test::PHASE_6;
  this->consumer0_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->consumer1_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  for (i = 0; i < ECB_SupplierID_Test::EVENTS_SENT; ++i)
    {
      this->supplier0_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
      this->supplier1_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }

  // PHASE 7, test disconnect/reconnect of both suppliers.
  this->phase_ = ECB_SupplierID_Test::PHASE_7;
  this->supplier0_.disconnect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->supplier1_.disconnect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->supplier0_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->supplier1_.connect (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  for (i = 0; i < ECB_SupplierID_Test::EVENTS_SENT; ++i)
    {
      this->supplier0_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
      this->supplier1_.send_event (_env);
      TAO_CHECK_ENV_RETURN_VOID (_env);
    }

  // PHASE END, any events received after this are errors.
  this->phase_ = ECB_SupplierID_Test::PHASE_END;

  // Finish
  this->supplier1_.close (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->supplier0_.close (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->consumer1_.close (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->consumer0_.close (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
}

int
ECB_SupplierID_Test::dump_results (void)
{
  static int expected_count[PHASE_END]={
    4 * ECB_SupplierID_Test::EVENTS_SENT,
    2 * ECB_SupplierID_Test::EVENTS_SENT,
    4 * ECB_SupplierID_Test::EVENTS_SENT,
    2 * ECB_SupplierID_Test::EVENTS_SENT,
    4 * ECB_SupplierID_Test::EVENTS_SENT,
    0,
    4 * ECB_SupplierID_Test::EVENTS_SENT,
    4 * ECB_SupplierID_Test::EVENTS_SENT
  };

  int result = 0;
  for (int i = 0; i < ECB_SupplierID_Test::PHASE_END; ++i)
    {
      if (this->error_count_[i] != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "SupplierID_Test: Error count for phase %d "
                      "is not zero\n", i));
          result = -1;
        }
      if (this->event_count_[i] != expected_count[i])
        {
          ACE_ERROR ((LM_ERROR,
                      "SupplierID_Test: Mismatched event count in phase %d, "
                      "expected %d, count is %d\n",
                      i,
                      expected_count[i],
                      this->event_count_[i]));
          result = -1;
        }
    }
  if (this->error_count_[ECB_SupplierID_Test::PHASE_END] != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "SupplierID_Test: Events received after final phase\n"));
      result = -1;
    }
  if (result == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "SupplierID_Test: All phases successful\n"));
    }

  return result;
}

void
ECB_SupplierID_Test::push (int consumer_id,
                           const RtecEventComm::EventSet& events,
                           CORBA::Environment &_env)
{
  switch (this->phase_)
    {
    case ECB_SupplierID_Test::PHASE_END:
    default:
      this->error_count_[ECB_SupplierID_Test::PHASE_END]++;
      break;

    case ECB_SupplierID_Test::PHASE_0:
      this->event_count_[ECB_SupplierID_Test::PHASE_0]++;
      break;

    case ECB_SupplierID_Test::PHASE_1:
      this->event_count_[ECB_SupplierID_Test::PHASE_1]++;
      break;

    case ECB_SupplierID_Test::PHASE_2:
      this->event_count_[ECB_SupplierID_Test::PHASE_2]++;
      break;

    case ECB_SupplierID_Test::PHASE_3:
      if (consumer_id == 0)
        this->event_count_[ECB_SupplierID_Test::PHASE_3]++;
      else
        this->error_count_[ECB_SupplierID_Test::PHASE_3]++;
      break;

    case ECB_SupplierID_Test::PHASE_4:
      this->event_count_[ECB_SupplierID_Test::PHASE_4]++;
      break;

    case ECB_SupplierID_Test::PHASE_5:
      this->error_count_[ECB_SupplierID_Test::PHASE_5]++;
      break;

    case ECB_SupplierID_Test::PHASE_6:
      this->event_count_[ECB_SupplierID_Test::PHASE_6]++;
      break;

    case ECB_SupplierID_Test::PHASE_7:
      this->event_count_[ECB_SupplierID_Test::PHASE_7]++;
      break;

    }
}

// ****************************************************************

ECB_SupplierID_Test::Consumer::Consumer (ECB_SupplierID_Test *test,
                                         int consumer_id)
  :  test_ (test),
     consumer_id_ (consumer_id)
{
}

void
ECB_SupplierID_Test::Consumer::open (const char* name,
                                     RtecEventChannelAdmin::EventChannel_ptr ec,
                                     RtecScheduler::Scheduler_ptr scheduler,
                                     CORBA::Environment& _env)
{
  this->rt_info_ =
    scheduler->create (name, _env);
  TAO_CHECK_ENV_RETURN_VOID(_env);

  // The worst case execution time is far less than 2
  // milliseconds, but that is a safe estimate....
  ACE_Time_Value tv (0, 2000);
  TimeBase::TimeT time;
  ORBSVCS_Time::Time_Value_to_TimeT (time, tv);
  scheduler->set (this->rt_info_,
                  RtecScheduler::VERY_HIGH_CRITICALITY,
                  time, time, time,
                  0,
                  RtecScheduler::VERY_LOW_IMPORTANCE,
                  time,
                  0,
                  RtecScheduler::OPERATION,
                  _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  // = Connect as a consumer.
  this->consumer_admin_ = ec->for_consumers (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
}

void
ECB_SupplierID_Test::Consumer::connect (CORBA::Environment& _env)
{
  if (CORBA::is_nil (this->consumer_admin_.in ()))
    return;

  this->supplier_proxy_ =
    this->consumer_admin_->obtain_push_supplier (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  ACE_ConsumerQOS_Factory qos;
  qos.start_disjunction_group ();
  qos.insert_source (ECB_SupplierID_Test::SUPPLIER_ID,
                     this->rt_info_);

  RtecEventComm::PushConsumer_var objref = this->_this (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  this->supplier_proxy_->connect_push_consumer (objref.in (),
                                                qos.get_ConsumerQOS (),
                                                _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
}

void
ECB_SupplierID_Test::Consumer::disconnect (CORBA::Environment& _env)
{
  if (CORBA::is_nil (this->supplier_proxy_.in ())
      || CORBA::is_nil (this->consumer_admin_.in ()))
    return;

  this->supplier_proxy_->disconnect_push_supplier (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->supplier_proxy_ =
    RtecEventChannelAdmin::ProxyPushSupplier::_nil ();
}

void
ECB_SupplierID_Test::Consumer::close (CORBA::Environment &_env)
{
  this->disconnect (_env);
  this->consumer_admin_ =
    RtecEventChannelAdmin::ConsumerAdmin::_nil ();
}

void
ECB_SupplierID_Test::Consumer::push (const RtecEventComm::EventSet& events,
                                     CORBA::Environment &_env)
{
  this->test_->push (this->consumer_id_,
                     events,
                     _env);
}

void
ECB_SupplierID_Test::Consumer::disconnect_push_consumer (CORBA::Environment &)
{
}

// ****************************************************************

ECB_SupplierID_Test::Supplier::Supplier (ECB_SupplierID_Test *test,
                                         int supplier_id)
  :  test_ (test),
     supplier_id_ (supplier_id)
{
}

void
ECB_SupplierID_Test::Supplier::open (const char* name,
                                     RtecEventChannelAdmin::EventChannel_ptr ec,
                                     RtecScheduler::Scheduler_ptr scheduler,
                                     CORBA::Environment &_env)
{
  RtecScheduler::handle_t rt_info =
    scheduler->create (name, _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  // The execution times are set to reasonable values, but
  // actually they are changed on the real execution, i.e. we
  // lie to the scheduler to obtain right priorities; but we
  // don't care if the set is schedulable.
  ACE_Time_Value tv (0, 2000);
  TimeBase::TimeT time;
  ORBSVCS_Time::Time_Value_to_TimeT (time, tv);

  scheduler->set (rt_info,
                  RtecScheduler::VERY_HIGH_CRITICALITY,
                  time, time, time,
                  0,
                  RtecScheduler::VERY_LOW_IMPORTANCE,
                  time,
                  1,
                  RtecScheduler::OPERATION,
                  _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  // = Connect as a consumer.
  this->supplier_admin_ = ec->for_suppliers (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
}

void
ECB_SupplierID_Test::Supplier::connect (CORBA::Environment& _env)
{
  if (CORBA::is_nil (this->supplier_admin_.in ()))
    return;

  this->consumer_proxy_ =
    this->supplier_admin_->obtain_push_consumer (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  ACE_SupplierQOS_Factory qos;
  qos.insert (ECB_SupplierID_Test::SUPPLIER_ID,
              this->supplier_id_,
              this->rt_info_,
              1);

  RtecEventComm::PushSupplier_var objref = this->_this (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);

  this->consumer_proxy_->connect_push_supplier (objref.in (),
                                                qos.get_SupplierQOS (),
                                                _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
}

void
ECB_SupplierID_Test::Supplier::disconnect (CORBA::Environment& _env)
{
  if (CORBA::is_nil (this->consumer_proxy_.in ())
      || CORBA::is_nil (this->supplier_admin_.in ()))
    return;

  this->consumer_proxy_->disconnect_push_consumer (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  this->consumer_proxy_ =
    RtecEventChannelAdmin::ProxyPushConsumer::_nil ();
}

void
ECB_SupplierID_Test::Supplier::close (CORBA::Environment &_env)
{
  this->disconnect (_env);
  this->supplier_admin_ =
    RtecEventChannelAdmin::SupplierAdmin::_nil ();
}

void
ECB_SupplierID_Test::Supplier::send_event (CORBA::Environment& _env)
{
  RtecEventComm::EventSet events (1);
  events.length (1);

  RtecEventComm::Event& e = events[0];
  e.header.source = ECB_SupplierID_Test::SUPPLIER_ID;
  e.header.ttl = 1;
  e.header.type = this->supplier_id_;

  ACE_hrtime_t t = ACE_OS::gethrtime ();
  ORBSVCS_Time::hrtime_to_TimeT (e.header.creation_time, t);
  e.header.ec_recv_time = ORBSVCS_Time::zero;
  e.header.ec_send_time = ORBSVCS_Time::zero;

  e.data.x = 0;
  e.data.y = 0;

  this->consumer_proxy_->push (events, _env);
}

void
ECB_SupplierID_Test::Supplier::disconnect_push_supplier (CORBA::Environment& _env)
{
  // this->supplier_proxy_->disconnect_push_supplier (_env);
}

// ****************************************************************

int
main (int argc, char *argv [])
{
  ECB_Driver driver;
  return driver.run (argc, argv);
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
