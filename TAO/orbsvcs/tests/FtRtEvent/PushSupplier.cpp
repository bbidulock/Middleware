// $Id$

#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/Event_Utilities.h"
#include "PushSupplier.h"
#include "ace/Reactor.h"
#include "ace/Select_Reactor.h"
#include "tao/MProfile.h"
#include "tao/Stub.h"
#include "orbsvcs/FtRtEvent/Utils/resolve_init.h"
#include "orbsvcs/FtRtEvent/Utils/Log.h"
#include "FtRtEvent_Test.h"
#include "tao/ORB.h"
#include "tao/ORB_Core.h"

ACE_RCSID (FtRtEvent,
           PushSupplier,
           "$Id$")

int
PushSupplier_impl::ReactorTask::svc (void)
{
  ACE_DEBUG((LM_DEBUG, "Reactor Thread started\n"));
  ACE_Reactor reactor (new ACE_Select_Reactor) ;
  reactor_ = &reactor;

  if (reactor_->schedule_timer(handler_, 0, ACE_Time_Value::zero, timer_interval_)== -1)
    ACE_ERROR_RETURN((LM_ERROR,"Cannot schedule timer\n"),-1);

  reactor_->run_reactor_event_loop();

  return 0;
}



PushSupplier_impl::PushSupplier_impl()
: supplier_servant_(this)
, seq_no_(0)
, reactor_task_(this)
, in_timeout_handler_(0)
{
}

PushSupplier_impl::~PushSupplier_impl()
{
  reactor_task_.wait();
}

int PushSupplier_impl::init(CORBA::ORB_ptr orb,
                            RtecEventChannelAdmin::EventChannel_ptr channel, 
                            const Options& options
                            ACE_ENV_ARG_DECL)
{
  ACE_DEBUG((LM_DEBUG, "PushSupplier_impl::init\n"));
  orb_ = orb;
  num_iterations_ = options.num_iterations;
  reactor_task_.timer_interval_ = options.timer_interval;
  proxy_consumer_file_ = options.proxy_consumer_file;

  RtecEventChannelAdmin::SupplierQOS qos;
  qos.publications.length (1);
  RtecEventComm::EventHeader& h0 =
    qos.publications[0].event.header;
  h0.type   = ACE_ES_EVENT_UNDEFINED; // first free event type
  h0.source = 1;                      // first free event source

  ACE_TRY {
    RtecEventComm::PushSupplier_var supplier = supplier_servant_._this();

    ACE_Time_Value time_val = ACE_OS::gettimeofday ();

    RtecEventChannelAdmin::SupplierAdmin_var supplier_admin =
      channel->for_suppliers(ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;

    consumer_ =
      supplier_admin->obtain_push_consumer(ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;

    consumer_->connect_push_supplier(supplier.in(), qos   ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;


    time_val = ACE_OS::gettimeofday () - time_val;

    ACE_DEBUG((LM_DEBUG, "connected to proxy_push_consumer, subscription latency = %d\n", time_val.sec () * 10000000 + time_val.usec ()* 10));
  }
  ACE_CATCHANY 
  {
    ACE_PRINT_EXCEPTION(ex, "PushSupplier_impl::init ");
    exit(1);
  }
  ACE_ENDTRY;
  ACE_CHECK;

  /*
  if (!reactor_task_.thr_count() &&
    reactor_task_.activate (THR_NEW_LWP | THR_JOINABLE, 1) != 0)
    ACE_ERROR_RETURN ((LM_ERROR, "Cannot activate reactor thread\n"), -1);
  */

  ACE_Reactor* reactor = orb->orb_core()->reactor();
  if (reactor->schedule_timer(this, 0, ACE_Time_Value::zero, options.timer_interval)== -1) {
    ACE_DEBUG((LM_ERROR,"Cannot schedule timer\n"));
    exit(1);
  }

  return 0;
}



void  PushSupplier_impl::disconnect_push_supplier (
        ACE_ENV_SINGLE_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ))
{

  reactor_task_.reactor_->end_reactor_event_loop();

  PortableServer::Current_var current =
    resolve_init<PortableServer::Current>(orb_.in(), "POACurrent" ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  PortableServer::POA_var poa = current->get_POA(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  PortableServer::ObjectId_var oid = current->get_object_id(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  poa->deactivate_object(oid ACE_ENV_ARG_PARAMETER);
}

int PushSupplier_impl::handle_timeout (const ACE_Time_Value &current_time,
                     const void *act)
{
  ACE_UNUSED_ARG(act);
  ACE_UNUSED_ARG(current_time);

  if (in_timeout_handler_) return 0;
  in_timeout_handler_ = 1;

  FTRTEC_TRACE("PushSupplier_impl::handle_timeout");

  RtecEventComm::EventSet event (1);
  event.length (1);
  event[0].header.type   = ACE_ES_EVENT_UNDEFINED;
  event[0].header.source = 1;
  event[0].header.ttl    = 1;

  ACE_Time_Value time_val = ACE_OS::gettimeofday ();
  TAO_FTRTEC::Log(1, "sending data %d\n", seq_no_);

  event[0].header.ec_send_time = time_val.sec () * 10000000 + time_val.usec ()* 10;
  event[0].data.any_value <<= seq_no_;
  bool final = (num_iterations_ == (int) seq_no_++);

  ACE_TRY_NEW_ENV {
    if (!final) {
      consumer_->push(event ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
    else {
      ACE_CString ior("file://");
      ior += proxy_consumer_file_;
      CORBA::Object_var obj = orb_->string_to_object(ior.c_str() ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      RtecEventComm::PushConsumer_var consumer = 
        RtecEventComm::PushConsumer::_narrow(obj.in());
      ACE_OS::sleep(1);
      consumer->push(event ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  }
  ACE_CATCHANY
  {
    ACE_PRINT_EXCEPTION(ACE_ANY_EXCEPTION, "A CORBA Exception occurred.");
  }
  ACE_ENDTRY;

  if (final) {
    ACE_DEBUG((LM_DEBUG, "shutdown orb\n"));
    this->reactor()->cancel_timer(this);
    this->reactor()->end_reactor_event_loop();
    this->reactor(0);
    orb_->shutdown();
  }
  in_timeout_handler_ = 0;
  return 0;
}
