// -*- C++ -*-
//
// $Id$

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Condition_Attributes::ACE_Condition_Attributes (int type)
{
  (void) ACE_OS::condattr_init (this->attributes_, type);
}

ACE_INLINE
ACE_Condition_Attributes::~ACE_Condition_Attributes (void)
{
  ACE_OS::condattr_destroy (this->attributes_);
}

ACE_INLINE
const ACE_condattr_t&
ACE_Condition_Attributes::attributes (void) const
{
  return this->attributes_;
}

ACE_INLINE
ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy>::ACE_Condition_Attributes_T (int type)
 : ACE_Condition_Attributes (type)
{
#if !defined (ACE_LACKS_CLOCK_MONOTONIC)
  (void) ACE_OS::condattr_setclock (this->attributes_, CLOCK_MONOTONIC);
#endif
}

ACE_INLINE
ACE_Condition_Attributes_T<ACE_Monotonic_Time_Policy>::~ACE_Condition_Attributes_T (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
