// -*- C++ -*-
// $Id$

ACE_INLINE CORBA::ULong
TAO_Profile::tag (void) const
{
  return this->tag_;
}

ACE_INLINE const TAO_GIOP_Message_Version &
TAO_Profile::version (void) const
{
  return this->version_;
}

ACE_INLINE TAO_ORB_Core *
TAO_Profile::orb_core (void) const
{
  return this->orb_core_;
}

ACE_INLINE void
TAO_Profile::forward_to (TAO_MProfile *mprofiles)
{
  this->forward_to_ = mprofiles;
}

ACE_INLINE TAO_MProfile *
TAO_Profile::forward_to (void)
{
  return this->forward_to_;
}

ACE_INLINE TAO_MProfile *
TAO_Profile::forward_to_i (void)
{
  return this->forward_to_;
}

ACE_INLINE const TAO_Tagged_Components&
TAO_Profile::tagged_components (void) const
{
  return this->tagged_components_;
}

ACE_INLINE TAO_Tagged_Components&
TAO_Profile::tagged_components (void)
{
  return this->tagged_components_;
}

ACE_INLINE CORBA::Short
TAO_Profile::addressing_mode (void) const
{
  return this->addressing_mode_;
}
