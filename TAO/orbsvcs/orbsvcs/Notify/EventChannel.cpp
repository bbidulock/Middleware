// $Id$

#include "EventChannel.h"

#if ! defined (__ACE_INLINE__)
#include "EventChannel.inl"
#endif /* __ACE_INLINE__ */

#include "Container_T.h"
#include "EventChannelFactory.h"
#include "ConsumerAdmin.h"
#include "SupplierAdmin.h"
#include "Event_Manager.h"
#include "Properties.h"
#include "Factory.h"
#include "Builder.h"
#include "Find_Worker_T.h"
#include "Seq_Worker_T.h"
#include "Topology_Saver.h"
#include "Save_Persist_Worker_T.h"
#include "Reconnect_Worker_T.h"

#include "tao/debug.h"
//#define DEBUG_LEVEL 9
#define DEBUG_LEVEL TAO_debug_level

ACE_RCSID(Notify, TAO_Notify_EventChannel, "$Id$")

typedef TAO_Notify_Find_Worker_T<TAO_Notify_ConsumerAdmin
                             , CosNotifyChannelAdmin::ConsumerAdmin
                             , CosNotifyChannelAdmin::ConsumerAdmin_ptr
                             , CosNotifyChannelAdmin::AdminNotFound>
TAO_Notify_ConsumerAdmin_Find_Worker;

typedef TAO_Notify_Find_Worker_T<TAO_Notify_SupplierAdmin
                             , CosNotifyChannelAdmin::SupplierAdmin
                             , CosNotifyChannelAdmin::SupplierAdmin_ptr
                             , CosNotifyChannelAdmin::AdminNotFound>
TAO_Notify_SupplierAdmin_Find_Worker;

typedef TAO_Notify_Seq_Worker_T<TAO_Notify_ConsumerAdmin> TAO_Notify_ConsumerAdmin_Seq_Worker;
typedef TAO_Notify_Seq_Worker_T<TAO_Notify_SupplierAdmin> TAO_Notify_SupplierAdmin_Seq_Worker;

TAO_Notify_EventChannel::TAO_Notify_EventChannel (void)
  : ecf_ (0)
  , ca_container_ (0)
  , sa_container_ (0)
{
}

TAO_Notify_EventChannel::~TAO_Notify_EventChannel ()
{
  delete this->event_manager_; // The EventChannel always owns the EventManager.

  this->ecf_->_decr_refcnt ();
}

void
TAO_Notify_EventChannel::init (TAO_Notify_EventChannelFactory* ecf
                           , const CosNotification::QoSProperties & initial_qos
                           , const CosNotification::AdminProperties & initial_admin
                           ACE_ENV_ARG_DECL)
{
  this->TAO_NOTIFY::Topology_Object::init (ecf);

  this->ecf_ = ecf;

  this->ecf_->_incr_refcnt ();

  // Init ca_container_
  ACE_NEW_THROW_EX (this->ca_container_,
                    TAO_Notify_ConsumerAdmin_Container (),
                    CORBA::INTERNAL ());
  ACE_CHECK;

  this->ca_container_->init (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Init ca_container_
  ACE_NEW_THROW_EX (this->sa_container_,
                    TAO_Notify_SupplierAdmin_Container (),
                    CORBA::INTERNAL ());
  ACE_CHECK;

  this->sa_container_->init (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  TAO_Notify_AdminProperties* admin_properties = 0;

  // Set the admin properties.
  ACE_NEW_THROW_EX (admin_properties,
                    TAO_Notify_AdminProperties (),
                    CORBA::NO_MEMORY ());
  ACE_CHECK;

  this->admin_properties_ = admin_properties;

  // create the event manager. @@ use factory
  ACE_NEW_THROW_EX (this->event_manager_,
                    TAO_Notify_Event_Manager (),
                    CORBA::INTERNAL ());
  ACE_CHECK;

  this->event_manager_->init (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  const CosNotification::QoSProperties &default_ec_qos =
    TAO_Notify_PROPERTIES::instance ()->default_event_channel_qos_properties ();

  this->set_qos (default_ec_qos ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->set_qos (initial_qos ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->set_admin (initial_admin ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Note originally default admins were allocated here, bt this caused problems
  // attempting to save the topology changes before the Event Channel was completely
  // constructed and linked to the ECF.
  // Lazy evaluation also avoids creating unneded admins.
}


void
TAO_Notify_EventChannel::init (TAO_Notify_EventChannelFactory* ecf
                           ACE_ENV_ARG_DECL)
{
  this->TAO_NOTIFY::Topology_Object::init (ecf);

  this->ecf_ = ecf;

  this->ecf_->_incr_refcnt ();

  // Init ca_container_
  ACE_NEW_THROW_EX (this->ca_container_,
                    TAO_Notify_ConsumerAdmin_Container (),
                    CORBA::INTERNAL ());
  ACE_CHECK;

  this->ca_container_->init (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Init ca_container_
  ACE_NEW_THROW_EX (this->sa_container_,
                    TAO_Notify_SupplierAdmin_Container (),
                    CORBA::INTERNAL ());
  ACE_CHECK;

  this->sa_container_->init (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  TAO_Notify_AdminProperties* admin_properties = 0;

  // Set the admin properties.
  ACE_NEW_THROW_EX (admin_properties,
                    TAO_Notify_AdminProperties (),
                    CORBA::NO_MEMORY ());
  ACE_CHECK;

  this->admin_properties_ = admin_properties;

  // create the event manager. @@ use factory
  ACE_NEW_THROW_EX (this->event_manager_,
                    TAO_Notify_Event_Manager (),
                    CORBA::INTERNAL ());
  ACE_CHECK;

  this->event_manager_->init (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  const CosNotification::QoSProperties &default_ec_qos =
    TAO_Notify_PROPERTIES::instance ()->default_event_channel_qos_properties ();

  this->set_qos (default_ec_qos ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}


void
TAO_Notify_EventChannel::_add_ref (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  this->_incr_refcnt ();
}

void
TAO_Notify_EventChannel::_remove_ref (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  this->_decr_refcnt ();
}

void
TAO_Notify_EventChannel::release (void)
{
  delete this;
  //@@ inform factory
}

int
TAO_Notify_EventChannel::shutdown (ACE_ENV_SINGLE_ARG_DECL)
{
  if (TAO_Notify_Object::shutdown (ACE_ENV_SINGLE_ARG_PARAMETER) == 1)
    return 1;

  this->ca_container_->shutdown (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (1);

  this->sa_container_->shutdown (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (1);

  delete this->ca_container_;
  delete this->sa_container_;

  this->event_manager_->shutdown ();

  return 0;
}

void
TAO_Notify_EventChannel::destroy (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  if (this->shutdown (ACE_ENV_SINGLE_ARG_PARAMETER) == 1)
    return;

  ACE_CHECK;

  this->ecf_->remove (this ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_Notify_EventChannel::remove (TAO_Notify_ConsumerAdmin* consumer_admin ACE_ENV_ARG_DECL)
{
  this->ca_container_->remove (consumer_admin ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_EventChannel::remove (TAO_Notify_SupplierAdmin* supplier_admin ACE_ENV_ARG_DECL)
{
  this->sa_container_->remove (supplier_admin ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_EventChannel::set_qos (const CosNotification::QoSProperties & qos ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosNotification::UnsupportedQoS
                   ))
{
  this->TAO_Notify_Object::set_qos (qos ACE_ENV_ARG_PARAMETER);
}

CosNotification::QoSProperties*
TAO_Notify_EventChannel::get_qos (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->TAO_Notify_Object::get_qos (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CosNotifyChannelAdmin::EventChannelFactory_ptr
TAO_Notify_EventChannel::MyFactory (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->ecf_->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CosNotifyChannelAdmin::ConsumerAdmin_ptr
TAO_Notify_EventChannel::default_consumer_admin (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  if (CORBA::is_nil (default_consumer_admin_.in ()))
    {
      ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, guard, this->default_admin_mutex_, CosNotifyChannelAdmin::ConsumerAdmin::_nil());
      if (CORBA::is_nil (default_consumer_admin_.in ()))
        {
          CosNotifyChannelAdmin::AdminID id;
          this->default_consumer_admin_ = this->new_for_consumers (CosNotifyChannelAdmin::OR_OP, id ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (CosNotifyChannelAdmin::ConsumerAdmin::_nil());
          // Wish there was a better way to do this!
          PortableServer::ServantBase * admin_servant =
            this->poa_->reference_to_servant (
              this->default_consumer_admin_.in ()
              ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (CosNotifyChannelAdmin::ConsumerAdmin::_nil());
          TAO_Notify_Admin * pAdmin = dynamic_cast <TAO_Notify_Admin *> (admin_servant);
          ACE_ASSERT (pAdmin != 0); // if this assert triggers, we have mixed implementations?
          if (pAdmin != 0)
            {
              pAdmin->set_default (true);
            }
        }
    }
  return CosNotifyChannelAdmin::ConsumerAdmin::_duplicate (this->default_consumer_admin_.in ());
}

CosNotifyChannelAdmin::SupplierAdmin_ptr
TAO_Notify_EventChannel::default_supplier_admin (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  if (CORBA::is_nil (default_supplier_admin_.in ()))
    {
      ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, guard, this->default_admin_mutex_, CosNotifyChannelAdmin::SupplierAdmin::_nil());
      if (CORBA::is_nil (default_supplier_admin_.in ()))
        {
          CosNotifyChannelAdmin::AdminID id;
          this->default_supplier_admin_ = this->new_for_suppliers (CosNotifyChannelAdmin::OR_OP, id ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (CosNotifyChannelAdmin::SupplierAdmin::_nil());
          PortableServer::ServantBase * admin_servant =
            this->poa_->poa()->reference_to_servant (
              this->default_supplier_admin_.in ()
              ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);
          TAO_Notify_Admin * pAdmin = dynamic_cast <TAO_Notify_Admin *> (admin_servant);
          ACE_ASSERT (pAdmin != 0); // if this assert triggers, we have mixed implementations?
          if (pAdmin != 0)
            {
              pAdmin->set_default (true);
            }
        }
    }
  return CosNotifyChannelAdmin::SupplierAdmin::_duplicate (this->default_supplier_admin_.in ());
}

::CosNotifyFilter::FilterFactory_ptr TAO_Notify_EventChannel::default_filter_factory (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->ecf_->get_default_filter_factory (ACE_ENV_SINGLE_ARG_PARAMETER);
}

::CosNotifyChannelAdmin::ConsumerAdmin_ptr
TAO_Notify_EventChannel::new_for_consumers (CosNotifyChannelAdmin::InterFilterGroupOperator op,
                                        CosNotifyChannelAdmin::AdminID_out id ACE_ENV_ARG_DECL
                                        )
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))

{
  ::CosNotifyChannelAdmin::ConsumerAdmin_var ca =
    TAO_Notify_PROPERTIES::instance()->builder()->build_consumer_admin (this, op, id ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (ca._retn ());
  this->self_change (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (ca._retn ());
  return ca._retn ();
}

::CosNotifyChannelAdmin::SupplierAdmin_ptr
TAO_Notify_EventChannel::new_for_suppliers (CosNotifyChannelAdmin::InterFilterGroupOperator op,
                                        CosNotifyChannelAdmin::AdminID_out id
                                        ACE_ENV_ARG_DECL
                                        )
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  ::CosNotifyChannelAdmin::SupplierAdmin_var sa =
    TAO_Notify_PROPERTIES::instance()->builder()->build_supplier_admin (this, op, id ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (sa._retn ());
  this->self_change (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (sa._retn ());
  return sa._retn ();
}

CosNotifyChannelAdmin::ConsumerAdmin_ptr
TAO_Notify_EventChannel::get_consumeradmin (CosNotifyChannelAdmin::AdminID id ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosNotifyChannelAdmin::AdminNotFound
                   ))
{
  TAO_Notify_ConsumerAdmin_Find_Worker find_worker;

  return find_worker.resolve (id, *this->ca_container_ ACE_ENV_ARG_PARAMETER);
}

CosNotifyChannelAdmin::SupplierAdmin_ptr
TAO_Notify_EventChannel::get_supplieradmin (CosNotifyChannelAdmin::AdminID id ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosNotifyChannelAdmin::AdminNotFound
                   ))
{
  TAO_Notify_SupplierAdmin_Find_Worker find_worker;

  return find_worker.resolve (id, *this->sa_container_ ACE_ENV_ARG_PARAMETER);
}

CosNotifyChannelAdmin::AdminIDSeq*
TAO_Notify_EventChannel::get_all_consumeradmins (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  TAO_Notify_ConsumerAdmin_Seq_Worker seq_worker;

  return seq_worker.create (*this->ca_container_ ACE_ENV_ARG_PARAMETER);
}

CosNotifyChannelAdmin::AdminIDSeq*
TAO_Notify_EventChannel::get_all_supplieradmins (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  TAO_Notify_SupplierAdmin_Seq_Worker seq_worker;

  return seq_worker.create (*this->sa_container_ ACE_ENV_ARG_PARAMETER);
}

void
TAO_Notify_EventChannel::set_admin (const CosNotification::AdminProperties & admin ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosNotification::UnsupportedAdmin
                   ))
{
  this->admin_properties_->init (admin);
}

CosNotification::AdminProperties*
TAO_Notify_EventChannel::get_admin (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  CosNotification::AdminProperties_var properties;

  ACE_NEW_THROW_EX (properties,
                    CosNotification::AdminProperties (),
                    CORBA::NO_MEMORY ());

  this->admin_properties_->populate (properties);

  return properties._retn ();
}

CosEventChannelAdmin::ConsumerAdmin_ptr
TAO_Notify_EventChannel::for_consumers (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->default_consumer_admin(ACE_ENV_SINGLE_ARG_PARAMETER);
}

CosEventChannelAdmin::SupplierAdmin_ptr
TAO_Notify_EventChannel::for_suppliers (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->default_supplier_admin (ACE_ENV_SINGLE_ARG_PARAMETER);
}

void
TAO_Notify_EventChannel::validate_qos (const CosNotification::QoSProperties & /*required_qos*/,
                                   CosNotification::NamedPropertyRangeSeq_out /*available_qos*/
                                   ACE_ENV_ARG_DECL
                                   )
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosNotification::UnsupportedQoS
                   ))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

void
TAO_Notify_EventChannel::save_persistent (TAO_NOTIFY::Topology_Saver& saver ACE_ENV_ARG_DECL)
{
  bool changed = this->self_changed_;
  this->self_changed_ = false;
  this->children_changed_ = false;

  if (is_persistent ())
  {
    TAO_NOTIFY::NVPList attrs;
    this->save_attrs(attrs);

    bool want_all_children = saver.begin_object(
      this->id(), "channel", attrs, changed ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    TAO_NOTIFY::Save_Persist_Worker<TAO_Notify_ConsumerAdmin> ca_wrk(saver, want_all_children);

    ACE_ASSERT(this->ca_container_ != 0);
    this->ca_container_->collection()->for_each(&ca_wrk ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    TAO_NOTIFY::Save_Persist_Worker<TAO_Notify_SupplierAdmin> sa_wrk(saver, want_all_children);
    ACE_ASSERT(this->sa_container_ != 0);
    this->sa_container_->collection()->for_each(&sa_wrk ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    saver.end_object(this->id(), "channel" ACE_ENV_ARG_PARAMETER);
  }
}

namespace {
  template<class T>
    void add_attr(TAO_NOTIFY::NVPList& attrs, const T& prop) {
      if (prop.is_valid())
      {
        attrs.push_back(TAO_NOTIFY::NVP (prop));
      }
    }
#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template void add_attr<TAO_NS_Property_Boolean>(TAO_NOTIFY::NVPList&,
  const TAO_NS_Property_Boolean&);
template void add_attr<TAO_NS_Property_T<int> >(TAO_NOTIFY::NVPList&,
  const TAO_NS_Property_T<int>&);
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate void add_attr<TAO_NS_Property_Boolean>(\
  TAO_NOTIFY::NVPList&, const TAO_NS_Property_Boolean&)
#pragma instantiate void add_attr<TAO_NS_Property_T<int> >(\
  TAO_NOTIFY::NVPList&, const TAO_NS_Property_T<int>&)
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
}

void
TAO_Notify_EventChannel::save_attrs(TAO_NOTIFY::NVPList& attrs)
{
  TAO_Notify_Object::save_attrs(attrs);
  add_attr(attrs, this->admin_properties_->max_global_queue_length());
  add_attr(attrs, this->admin_properties_->max_consumers());
  add_attr(attrs, this->admin_properties_->max_suppliers());
  add_attr(attrs, this->admin_properties_->reject_new_events());
}

void
TAO_Notify_EventChannel::load_attrs(const TAO_NOTIFY::NVPList& attrs)
{
  TAO_Notify_Object::load_attrs(attrs);
  attrs.load(this->admin_properties_->max_global_queue_length());
  attrs.load(this->admin_properties_->max_consumers());
  attrs.load(this->admin_properties_->max_suppliers());
  attrs.load(this->admin_properties_->reject_new_events());
  this->admin_properties_->init();
}

TAO_NOTIFY::Topology_Object *
TAO_Notify_EventChannel::load_child (const ACE_CString &type,
                                                  CORBA::Long id,
                                                  const TAO_NOTIFY::NVPList& attrs
                                                  ACE_ENV_ARG_DECL)
{
  TAO_NOTIFY::Topology_Object* result = this;
  if (type == "consumer_admin")
  {
    if (DEBUG_LEVEL) ACE_DEBUG ((LM_DEBUG,
      ACE_TEXT ("(%P|%t) EventChannel reload consumer_admin %d\n")
      , ACE_static_cast (int, id)
      ));

    // call special builder method to reload
    TAO_Notify_Builder* bld = TAO_Notify_PROPERTIES::instance()->builder();
    TAO_Notify_ConsumerAdmin * ca = bld->build_consumer_admin (
      this,
      id
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN(0);
    ca->load_attrs (attrs);
    if (ca->is_default ())
      {
        CORBA::Object_var caob = this->poa_->servant_to_reference (ca ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN(0);
        this->default_consumer_admin_ =
          CosNotifyChannelAdmin::ConsumerAdmin::_narrow (
          caob.in () ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN(0);
      }
    result = ca;
  }
  else if (type == "supplier_admin")
  {
    if (DEBUG_LEVEL) ACE_DEBUG ((LM_DEBUG,
      ACE_TEXT ("(%P|%t) EventChannel reload supplier_admin %d\n")
      , ACE_static_cast (int, id)
      ));
    TAO_Notify_Builder* bld = TAO_Notify_PROPERTIES::instance()->builder();

    TAO_Notify_SupplierAdmin * sa = bld->build_supplier_admin (
      this,
      id
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN(0);
    sa->load_attrs (attrs);
    if (sa->is_default ())
      {
        CORBA::Object_var saob = this->poa_->servant_to_reference (sa ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN(0);
        this->default_supplier_admin_ =
          CosNotifyChannelAdmin::SupplierAdmin::_narrow (
          saob.in () ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN(0);
      }
    result = sa;
  }
  return result;
}

void
TAO_Notify_EventChannel::reconnect (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_NOTIFY::Reconnect_Worker<TAO_Notify_ConsumerAdmin> ca_wrk;
  ACE_ASSERT(this->ca_container_ != 0);
  this->ca_container_->collection()->for_each(&ca_wrk ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  TAO_NOTIFY::Reconnect_Worker<TAO_Notify_SupplierAdmin> sa_wrk;
  ACE_ASSERT(this->sa_container_ != 0);
  this->sa_container_->collection()->for_each(&sa_wrk ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO_Notify_Find_Worker_T<TAO_Notify_ConsumerAdmin
                                    , CosNotifyChannelAdmin::ConsumerAdmin
                                    , CosNotifyChannelAdmin::ConsumerAdmin_ptr
                                    , CosNotifyChannelAdmin::AdminNotFound>;
template class TAO_Notify_Find_Worker_T<TAO_Notify_SupplierAdmin
                                    , CosNotifyChannelAdmin::SupplierAdmin
                                    , CosNotifyChannelAdmin::SupplierAdmin_ptr
                                    , CosNotifyChannelAdmin::AdminNotFound>;

template class TAO_Notify_Seq_Worker_T<TAO_Notify_ConsumerAdmin>;
template class TAO_Notify_Seq_Worker_T<TAO_Notify_SupplierAdmin>;

template class TAO_Notify_Container_T <TAO_Notify_ConsumerAdmin>;
template class TAO_Notify_Container_T <TAO_Notify_SupplierAdmin>;

template class TAO_ESF_Shutdown_Proxy<TAO_Notify_ConsumerAdmin>;
template class TAO_ESF_Shutdown_Proxy<TAO_Notify_SupplierAdmin>;

template class Save_Persist_Worker<TAO_Notify_ConsumerAdmin>;
template class Save_Persist_Worker<TAO_Notify_SupplierAdmin>;
template class TAO_NOTIFY::Reconnect_Worker<TAO_Notify_ConsumerAdmin>;
template class TAO_NOTIFY::Reconnect_Worker<TAO_Notify_SupplierAdmin>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate TAO_Notify_Find_Worker_T<TAO_Notify_ConsumerAdmin
                                    , CosNotifyChannelAdmin::ConsumerAdmin
                                    , CosNotifyChannelAdmin::ConsumerAdmin_ptr
                                    , CosNotifyChannelAdmin::AdminNotFound>
#pragma instantiate TAO_Notify_Find_Worker_T<TAO_Notify_SupplierAdmin
                                    , CosNotifyChannelAdmin::SupplierAdmin
                                    , CosNotifyChannelAdmin::SupplierAdmin_ptr
                                    , CosNotifyChannelAdmin::AdminNotFound>

#pragma instantiate TAO_Notify_Seq_Worker_T<TAO_Notify_ConsumerAdmin>
#pragma instantiate TAO_Notify_Seq_Worker_T<TAO_Notify_SupplierAdmin>

#pragma instantiate TAO_Notify_Container_T <TAO_Notify_ConsumerAdmin>
#pragma instantiate TAO_Notify_Container_T <TAO_Notify_SupplierAdmin>

#pragma instantiate TAO_ESF_Shutdown_Proxy<TAO_Notify_ConsumerAdmin>
#pragma instantiate TAO_ESF_Shutdown_Proxy<TAO_Notify_SupplierAdmin>

#pragma instantiate Save_Persist_Worker<TAO_Notify_ConsumerAdmin>
#pragma instantiate Save_Persist_Worker<TAO_Notify_SupplierAdmin>
#pragma instantiate TAO_NOTIFY::Reconnect_Worker<TAO_Notify_ConsumerAdmin>
#pragma instantiate TAO_NOTIFY::Reconnect_Worker<TAO_Notify_SupplierAdmin>

#endif /*ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
