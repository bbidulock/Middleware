// This may look like C, but it's really -*- C++ -*-
// $Id$

#include "ace/config-all.h"

#if defined (ACE_HAS_SSL) && ACE_HAS_SSL == 1

#include "SSLIOP_Endpoint.h"
#include "SSLIOP_Connect.h"
#include "tao/IIOP_Endpoint.h"
#include "tao/debug.h"

ACE_RCSID(tao, SSLIOP_Endpoint, "$Id$")

#if !defined (__ACE_INLINE__)
# include "SSLIOP_Endpoint.i"
#endif /* __ACE_INLINE__ */

TAO_SSLIOP_Endpoint::TAO_SSLIOP_Endpoint (const SSLIOP::SSL *ssl_component,
                                          TAO_IIOP_Endpoint *iiop_endp)
  : TAO_Endpoint (TAO_TAG_IIOP_PROFILE),
    ssl_hint_ (0),
    next_ (0),
    iiop_endpoint_ (iiop_endp)
{
  if (ssl_component != 0)
    {
      this->ssl_component_.target_supports = ssl_component->target_supports;
      this->ssl_component_.target_requires = ssl_component->target_requires;
      this->ssl_component_.port = ssl_component->port;
    }
  else
    {
      // Clear all bits in the SSLIOP::SSL association option fields.
      this->ssl_component_.target_supports = 0;
      this->ssl_component_.target_requires = 0;

      // SSLIOP requires these Security::AssociationOptions by default.
      ACE_SET_BITS (this->ssl_component_.target_requires,
                    Security::Integrity
                    | Security::Confidentiality
                    | Security::DetectReplay
                    | Security::DetectMisordering
                    | Security::NoDelegation);

      // SSLIOP supports these Security::AssociationOptions by default.
      ACE_SET_BITS (this->ssl_component_.target_supports,
                    Security::Integrity
                    | Security::Confidentiality
                    | Security::DetectReplay
                    | Security::DetectMisordering
                    | Security::EstablishTrustInTarget
                    | Security::NoDelegation);

      // Initialize the default SSL port to the IANA assigned IIOP
      // over SSL port.  We usually only get here if we're creating a
      // profile on the client side.
      this->ssl_component_.port = 684;
    }
}

TAO_SSLIOP_Endpoint::~TAO_SSLIOP_Endpoint (void)
{
}

int
TAO_SSLIOP_Endpoint::addr_to_string (char *buffer, size_t length)
{
  // @@ Marina, this is broken.  You're returning the IIOP address,
  //    not the SSLIOP one, meaning that the port will be incorrect.
  return
    this->iiop_endpoint_->addr_to_string (buffer, length);
}

void
TAO_SSLIOP_Endpoint::reset_hint (void)
{
  this->iiop_endpoint_->reset_hint ();

  // @@ Who is doing the locking here!
  if (this->ssl_hint_)
    {
      this->ssl_hint_->cleanup_hint ();
      this->ssl_hint_ = 0;
    }
}

TAO_Endpoint *
TAO_SSLIOP_Endpoint::next (void)
{
  return this->next_;
}

CORBA::Boolean
TAO_SSLIOP_Endpoint::is_equivalent (const TAO_Endpoint *other_endpoint)
{
  TAO_Endpoint *endpt = ACE_const_cast (TAO_Endpoint *,
                                        other_endpoint);

  TAO_SSLIOP_Endpoint *endpoint = ACE_dynamic_cast (TAO_SSLIOP_Endpoint *,
                                                    endpt);

  if (this->ssl_component_.port != 0
      && endpoint->ssl_component_.port != 0
      && this->ssl_component_.port != endpoint->ssl_component_.port)
    return 0;

  return
    this->iiop_endpoint_->is_equivalent (endpoint->iiop_endpoint_);
}

TAO_Endpoint *
TAO_SSLIOP_Endpoint::duplicate (void)
{
  TAO_SSLIOP_Endpoint *endpoint = 0;

  ACE_NEW_RETURN (endpoint,
                  TAO_SSLIOP_Endpoint (&this->ssl_component_,
                                       this->iiop_endpoint_),
                  0);

  return endpoint;
}

CORBA::ULong
TAO_SSLIOP_Endpoint::hash (void)
{
  return this->iiop_endpoint_->hash ();
}

#endif  /* ACE_HAS_SSL */
