// $Id$

#include "Property_Boolean.h"

#if ! defined (__ACE_INLINE__)
#include "Property_Boolean.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Notify, TAO_NS_Property_Boolean, "$Id$")

#include "PropertySeq.h"

TAO_NS_Property_Boolean::TAO_NS_Property_Boolean (const ACE_CString& name)
  :name_ (name), valid_(0)
{
}

TAO_NS_Property_Boolean::TAO_NS_Property_Boolean (const ACE_CString& name, CORBA::Boolean initial)
  :name_ (name), value_ (initial), valid_ (1)
{
}

int
TAO_NS_Property_Boolean::set (const TAO_NS_PropertySeq& property_seq)
{
  CosNotification::PropertyValue value;

  if (property_seq.find (this->name_, value) == -1)
    return -1;

  value >>= CORBA::Any::to_boolean (this->value_);

  return 0;
}

void
TAO_NS_Property_Boolean::get (CosNotification::PropertySeq& prop_seq)
{
  /// Make space
  prop_seq.length (prop_seq.length () + 1);

  prop_seq[prop_seq.length () - 1].value <<= CORBA::Any::from_boolean (this->value_);
}
