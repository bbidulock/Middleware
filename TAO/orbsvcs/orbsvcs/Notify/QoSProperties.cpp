// $Id$

#include "QoSProperties.h"

#if ! defined (__ACE_INLINE__)
#include "QoSProperties.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Notify, TAO_Notify_QoSProperties, "$Id$")

#include "Property.h"



TAO_Notify_QoSProperties::TAO_Notify_QoSProperties (void)
  :  event_reliability_(CosNotification::EventReliability)
    , connection_reliability_(CosNotification::ConnectionReliability)
    , priority_ (CosNotification::Priority)
    , timeout_ (CosNotification::Timeout)
    , stop_time_supported_ (CosNotification::StopTimeSupported)
    , maximum_batch_size_ (CosNotification::MaximumBatchSize)
    , max_events_per_consumer_ (CosNotification::MaxEventsPerConsumer)
    , pacing_interval_ (CosNotification::PacingInterval)
    , thread_pool_ (NotifyExt::ThreadPool)
    , thread_pool_lane_ (NotifyExt::ThreadPoolLanes)
{
  unsupported_[0] = CosNotification::StartTimeSupported;
}

TAO_Notify_QoSProperties::~TAO_Notify_QoSProperties ()
{
}

int
TAO_Notify_QoSProperties::unsupported (ACE_CString& name)
{
  for (int i = 0; i < UNSUPPORTED_PROPERTY_COUNT; ++i)
    {
      if (this->unsupported_[i] == name)
        return 1;
    }

  return 0;
}
void
TAO_Notify_QoSProperties::init ()
{
  if (this->event_reliability_.is_valid())
  {
    CORBA::Any a;
    a <<= this->event_reliability_.value();
    this->add(this->event_reliability_.name(), a);
  }
  if (this->connection_reliability_.is_valid())
  {
    CORBA::Any a;
    a <<= this->connection_reliability_.value();
    this->add(this->connection_reliability_.name(), a);
  }
  if (this->priority_.is_valid())
  {
    CORBA::Any a;
    a <<= this->priority_.value();
    this->add(this->priority_.name(), a);
  }
  if (this->timeout_.is_valid())
  {
    CORBA::Any a;
    a <<= this->timeout_.value();
    this->add(this->timeout_.name(), a);
  }
  if (this->stop_time_supported_.is_valid())
  {
    CORBA::Any a;
    a <<= CORBA::Any::from_boolean (this->stop_time_supported_.value());
    this->add(this->stop_time_supported_.name(), a);
  }
  if (this->maximum_batch_size_.is_valid())
  {
    CORBA::Any a;
    a <<= this->maximum_batch_size_.value();
    this->add(this->maximum_batch_size_.name(), a);
  }
  if (this->pacing_interval_.is_valid())
  {
    CORBA::Any a;
    a <<= this->pacing_interval_.value();
    this->add(this->pacing_interval_.name(), a);
  }
  if (this->max_events_per_consumer_.is_valid())
  {
    CORBA::Any a;
    a <<= this->max_events_per_consumer_.value();
    this->add(this->max_events_per_consumer_.name(), a);
  }
  if (this->thread_pool_.is_valid())
  {
    CORBA::Any a;
    a <<= this->thread_pool_.value();
    this->add(this->thread_pool_.name(), a);
  }
  if (this->thread_pool_lane_.is_valid())
  {
    CORBA::Any a;
    a <<= this->thread_pool_lane_.value();
    this->add(this->thread_pool_lane_.name(), a);
  }
}

int
TAO_Notify_QoSProperties::init (const CosNotification::PropertySeq& prop_seq, CosNotification::PropertyErrorSeq& err_seq)
{
  int err_index = -1;

  ACE_CString name;
  for (CORBA::ULong i = 0; i < prop_seq.length (); ++i)
    {
      name = prop_seq[i].name.in();

      if (this->unsupported (name))
        {
          err_index =  err_seq.length ();
          err_seq.length (err_seq.length () + 1);

          err_seq[err_index].code = CosNotification::UNSUPPORTED_PROPERTY;
          err_seq[err_index].name = CORBA::string_dup (prop_seq[i].name);
        }
      else if (this->property_map_.rebind (prop_seq[i].name.in (), prop_seq[i].value) == -1)
        return -1;
      // Note call to rebind. This allows to call <init> to set updates.
    }

  if (prop_seq.length () > 0)
    {
        // Now, init the supported properties
        this->event_reliability_.set (*this);
        this->connection_reliability_.set (*this);
        this->priority_.set (*this);
        this->timeout_.set (*this);
        this->stop_time_supported_.set (*this);
        this->maximum_batch_size_.set (*this);
        this->pacing_interval_.set (*this);
        this->thread_pool_.set (*this);
        this->thread_pool_lane_.set (*this);
  }

  return err_index == -1 ? 0 : 1;
}

int
TAO_Notify_QoSProperties::copy (TAO_Notify_QoSProperties& qos_properties)
{
  qos_properties.event_reliability_ = this->event_reliability_;
  qos_properties.connection_reliability_ = this->connection_reliability_;
  qos_properties.priority_ = this->priority_;
  qos_properties.timeout_ = this->timeout_;
  qos_properties.stop_time_supported_ = this->stop_time_supported_;
  qos_properties.maximum_batch_size_ = this->maximum_batch_size_;
  qos_properties.pacing_interval_ = this->pacing_interval_;

  PROPERTY_MAP::ITERATOR iter (this->property_map_);
  PROPERTY_MAP::ENTRY *entry;

  for (; iter.next (entry); iter.advance ())
    {
      if (qos_properties.property_map_.rebind (entry->ext_id_, entry->int_id_) == -1)
        return -1;
    }

  return 0;
}

int
TAO_Notify_QoSProperties::transfer (TAO_Notify_QoSProperties& qos_properties)
{
  if (this->copy (qos_properties) == -1)
    return -1;

  // unbind the properties that we don't want to transfer.
  qos_properties.property_map_.unbind (NotifyExt::ThreadPool);
  qos_properties.property_map_.unbind (NotifyExt::ThreadPoolLanes);

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO_Notify_PropertyBase_T<CORBA::Long>;
template class TAO_Notify_PropertyBase_T<CORBA::Short>;
template class TAO_Notify_PropertyBase_T<TimeBase::TimeT>;

template class TAO_Notify_Property_T<CORBA::Long>;
template class TAO_Notify_Property_T<CORBA::Short>;
template class TAO_Notify_Property_T<TimeBase::TimeT>;

template class TAO_Notify_StructProperty_T<NotifyExt::ThreadPoolParams>;
template class TAO_Notify_StructProperty_T<NotifyExt::ThreadPoolLanesParams>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate TAO_Notify_PropertyBase_T<CORBA::Long>
#pragma instantiate TAO_Notify_PropertyBase_T<CORBA::Short>
#pragma instantiate TAO_Notify_PropertyBase_T<TimeBase::TimeT>

#pragma instantiate TAO_Notify_Property_T<CORBA::Long>
#pragma instantiate TAO_Notify_Property_T<CORBA::Short>
#pragma instantiate TAO_Notify_Property_T<TimeBase::TimeT>

#pragma instantiate TAO_Notify_StructProperty_T<NotifyExt::ThreadPoolParams>
#pragma instantiate TAO_Notify_StructProperty_T<NotifyExt::ThreadPoolLanesParams>

#endif /*ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
