// $Id$

#include "EC_RTCORBA_Factory.h"
#include "EC_RTCORBA_Dispatching.h"

#include "tao/RTCORBA/Priority_Mapping_Manager.h"

#if ! defined (__ACE_INLINE__)
#include "EC_RTCORBA_Factory.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Event, EC_RTCORBA_Factory, "$Id$")

TAO_EC_RTCORBA_Factory::
    TAO_EC_RTCORBA_Factory (TAO_EC_Factory *body,
                            const RTCORBA::ThreadpoolLanes &lanes)
  : body_ (body)
  , lanes_ (lanes)
{
}

TAO_EC_RTCORBA_Factory::~TAO_EC_RTCORBA_Factory (void)
{
}


int
TAO_EC_RTCORBA_Factory::init (int argc, char* argv[])
{
  return this->body_->init (argc, argv);
}

int
TAO_EC_RTCORBA_Factory::fini (void)
{
  return this->body_->fini ();
}

// ****************************************************************

TAO_EC_Dispatching*
TAO_EC_RTCORBA_Factory::create_dispatching (TAO_EC_Event_Channel *)
{
  TAO_EC_Dispatching *dispatching = 0;
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // @@ The ORBId could be important!!!
      int argc = 0;
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, 0, ""
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::Object_var obj =
        orb->resolve_initial_references ("PriorityMappingManager"
                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      RTCORBA::PriorityMappingManager_var priority_mapping_manager =
        RTCORBA::PriorityMappingManager::_narrow (obj.in ()
                                                  ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      RTCORBA::PriorityMapping *priority_mapping =
        priority_mapping_manager->mapping ();

      obj =
        orb->resolve_initial_references ("RTCurrent"
                                         ACE_ENV_ARG_PARAMETER);
      RTCORBA::Current_var current =
        RTCORBA::Current::_narrow (obj.in ()
                                   ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_NEW_RETURN (dispatching,
                      TAO_EC_RTCORBA_Dispatching (this->lanes_,
                                                  priority_mapping,
                                                  current.in ()),
                      0);
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;

  return dispatching;
}

void
TAO_EC_RTCORBA_Factory::destroy_dispatching (TAO_EC_Dispatching *x)
{
  return this->body_->destroy_dispatching (x);
}

TAO_EC_Filter_Builder*
TAO_EC_RTCORBA_Factory::create_filter_builder (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_filter_builder (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_filter_builder (TAO_EC_Filter_Builder *x)
{
  return this->body_->destroy_filter_builder (x);
}

TAO_EC_Supplier_Filter_Builder*
TAO_EC_RTCORBA_Factory::create_supplier_filter_builder (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_supplier_filter_builder (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_supplier_filter_builder (TAO_EC_Supplier_Filter_Builder *x)
{
  return this->body_->destroy_supplier_filter_builder (x);
}

TAO_EC_ConsumerAdmin*
TAO_EC_RTCORBA_Factory::create_consumer_admin (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_consumer_admin (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_consumer_admin (TAO_EC_ConsumerAdmin *x)
{
  return this->body_->destroy_consumer_admin (x);
}

TAO_EC_SupplierAdmin*
TAO_EC_RTCORBA_Factory::create_supplier_admin (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_supplier_admin (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_supplier_admin (TAO_EC_SupplierAdmin *x)
{
  return this->body_->destroy_supplier_admin (x);
}

TAO_EC_ProxyPushSupplier*
TAO_EC_RTCORBA_Factory::create_proxy_push_supplier (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_proxy_push_supplier (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_proxy_push_supplier (TAO_EC_ProxyPushSupplier *x)
{
  return this->body_->destroy_proxy_push_supplier (x);
}

TAO_EC_ProxyPushConsumer*
TAO_EC_RTCORBA_Factory::create_proxy_push_consumer (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_proxy_push_consumer (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_proxy_push_consumer (TAO_EC_ProxyPushConsumer *x)
{
  return this->body_->destroy_proxy_push_consumer (x);
}

TAO_EC_Timeout_Generator*
TAO_EC_RTCORBA_Factory::create_timeout_generator (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_timeout_generator (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_timeout_generator (TAO_EC_Timeout_Generator *x)
{
  return this->body_->destroy_timeout_generator (x);
}

TAO_EC_ObserverStrategy*
TAO_EC_RTCORBA_Factory::create_observer_strategy (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_observer_strategy (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_observer_strategy (TAO_EC_ObserverStrategy *x)
{
  return this->body_->destroy_observer_strategy (x);
}

TAO_EC_Scheduling_Strategy*
TAO_EC_RTCORBA_Factory::create_scheduling_strategy (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_scheduling_strategy (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_scheduling_strategy (TAO_EC_Scheduling_Strategy* x)
{
  return this->body_->destroy_scheduling_strategy (x);
}

TAO_EC_ProxyPushConsumer_Collection*
TAO_EC_RTCORBA_Factory::create_proxy_push_consumer_collection (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_proxy_push_consumer_collection (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_proxy_push_consumer_collection (TAO_EC_ProxyPushConsumer_Collection *x)
{
  return this->body_->destroy_proxy_push_consumer_collection (x);
}

TAO_EC_ProxyPushSupplier_Collection*
TAO_EC_RTCORBA_Factory::create_proxy_push_supplier_collection (TAO_EC_Event_Channel *ec)
{
  return this->body_->create_proxy_push_supplier_collection (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_proxy_push_supplier_collection (TAO_EC_ProxyPushSupplier_Collection *x)
{
  return this->body_->destroy_proxy_push_supplier_collection (x);
}

ACE_Lock*
TAO_EC_RTCORBA_Factory::create_consumer_lock (void)
{
  return this->body_->create_consumer_lock ();
}

void
TAO_EC_RTCORBA_Factory::destroy_consumer_lock (ACE_Lock* x)
{
  return this->body_->destroy_consumer_lock (x);
}

ACE_Lock*
TAO_EC_RTCORBA_Factory::create_supplier_lock (void)
{
  return this->body_->create_supplier_lock ();
}

void
TAO_EC_RTCORBA_Factory::destroy_supplier_lock (ACE_Lock* x)
{
  return this->body_->destroy_supplier_lock (x);
}

TAO_EC_ConsumerControl*
TAO_EC_RTCORBA_Factory::create_consumer_control (TAO_EC_Event_Channel* ec)
{
  return this->body_->create_consumer_control (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_consumer_control (TAO_EC_ConsumerControl* x)
{
  return this->body_->destroy_consumer_control (x);
}

TAO_EC_SupplierControl*
TAO_EC_RTCORBA_Factory::create_supplier_control (TAO_EC_Event_Channel* ec)
{
  return this->body_->create_supplier_control (ec);
}

void
TAO_EC_RTCORBA_Factory::destroy_supplier_control (TAO_EC_SupplierControl* x)
{
  return this->body_->destroy_supplier_control (x);
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
