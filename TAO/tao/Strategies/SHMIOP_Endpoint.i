// -*- C++ -*-
// $Id$

ACE_INLINE const char *
TAO_SHMIOP_Endpoint::host (void) const
{
  return this->host_.in ();
}

ACE_INLINE CORBA::UShort
TAO_SHMIOP_Endpoint::port (void) const
{
  return this->port_;
}

ACE_INLINE CORBA::UShort
TAO_SHMIOP_Endpoint::port (CORBA::UShort p)
{
  return this->port_ = p;
}
