// $Id$

#include "StructuredEvent.h"

#if ! defined (__ACE_INLINE__)
#include "StructuredEvent.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(RT_Notify, TAO_NS_StructuredEvent, "$id$")

TAO_NS_StructuredEvent::TAO_NS_StructuredEvent (void)
{
}

TAO_NS_StructuredEvent::~TAO_NS_StructuredEvent ()
{
}

TAO_NS_StructuredEvent::TAO_NS_StructuredEvent (const char* name)
{
  event_.header.fixed_header.event_name = CORBA::string_dup(name);
}

TAO_NS_StructuredEvent::TAO_NS_StructuredEvent (const char* domain, const char* type)
{
  event_.header.fixed_header.event_type.domain_name = CORBA::string_dup(domain);
  event_.header.fixed_header.event_type.type_name = CORBA::string_dup(type);
}

TAO_NS_StructuredEvent::TAO_NS_StructuredEvent (const char* name, const char* domain, const char* type)
{
  event_.header.fixed_header.event_name = CORBA::string_dup(name);
  event_.header.fixed_header.event_type.domain_name = CORBA::string_dup(domain);
  event_.header.fixed_header.event_type.type_name = CORBA::string_dup(type);
}

void
TAO_NS_StructuredEvent::name (const char* name)
{
  event_.header.fixed_header.event_name = CORBA::string_dup(name);
}

void
TAO_NS_StructuredEvent::type (const char* domain, const char* type)
{
  event_.header.fixed_header.event_type.domain_name = CORBA::string_dup(domain);
  event_.header.fixed_header.event_type.type_name = CORBA::string_dup(type);
}

const char*
TAO_NS_StructuredEvent::type (void)
{
  return event_.header.fixed_header.event_type.type_name;
}

void
TAO_NS_StructuredEvent::opt_header (const char* name, CORBA::Any& value)
{
  CosNotification::PropertySeq& opt =  event_.header.variable_header;
  opt.length (opt.length () + 1);

  opt[opt.length () - 1].name = CORBA::string_dup (name);
  opt[opt.length () - 1].value = value;
}

void
TAO_NS_StructuredEvent::filter (const char* name, CORBA::Any& value)
{
  CosNotification::PropertySeq& filter = event_.filterable_data;
  filter.length (filter.length () + 1);

  filter[filter.length () - 1].name = CORBA::string_dup (name);
  filter[filter.length () - 1].value = value;
}

void
TAO_NS_StructuredEvent::qos (const char* name, CORBA::Any& value)
{
  this->opt_header (name, value);
}

void
TAO_NS_StructuredEvent::payload (CORBA::Any& value)
{
  event_.remainder_of_body = value;
}

CosNotification::StructuredEvent&
TAO_NS_StructuredEvent::event (void)
{
  return this->event_;
}
