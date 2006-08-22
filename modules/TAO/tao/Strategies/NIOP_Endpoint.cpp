// This may look like C, but it's really -*- C++ -*-
// $Id$


#include "tao/Strategies/NIOP_Endpoint.h"

#if defined (TAO_HAS_NIOP) && (TAO_HAS_NIOP != 0)

#include "tao/Strategies/NIOP_Connection_Handler.h"
#include "tao/debug.h"
#include "tao/ORB_Constants.h"

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"


ACE_RCSID (Strategies,
           NIOP_Endpoint,
           "$Id$")


#if !defined (__ACE_INLINE__)
# include "tao/Strategies/NIOP_Endpoint.inl"
#endif /* __ACE_INLINE__ */

#include "ace/os_include/os_netdb.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_NIOP_Endpoint::TAO_NIOP_Endpoint (const ACE_Utils::UUID& uuid)
  : TAO_Endpoint (TAO_TAG_NIOP_PROFILE
                  )//priority)
    , uuid_ ()
    , next_ (0)
{
  const ACE_CString * to_string = (const_cast <ACE_Utils::UUID&>(uuid)).to_string ();
  uuid_.from_string (*to_string);
}

TAO_NIOP_Endpoint::TAO_NIOP_Endpoint (void)
  : TAO_Endpoint (TAO_TAG_NIOP_PROFILE),
    uuid_ (),
//    object_addr_ (),
  //  object_addr_set_ (0),
    next_ (0)
{
}
              /*
TAO_NIOP_Endpoint::TAO_NIOP_Endpoint (const char *host,
                                      CORBA::UShort port,
                                      CORBA::Short priority)
  : TAO_Endpoint (TAO_TAG_NIOP_PROFILE),
    host_ (),
    port_ (port),
    object_addr_ (),
    object_addr_set_ (0),
    next_ (0)
{
  if (host != 0)
    this->host_ = host;

  this->priority (priority);
}
                */
TAO_NIOP_Endpoint::~TAO_NIOP_Endpoint (void)
{

}

/*int
TAO_NIOP_Endpoint::set (const ACE_INET_Addr &addr,
                        int use_dotted_decimal_addresses)
{
  char tmp_host[MAXHOSTNAMELEN + 1];

  if (use_dotted_decimal_addresses
      || addr.get_host_name (tmp_host, sizeof (tmp_host)) != 0)
    {
      const char *tmp = addr.get_host_addr ();
      if (tmp == 0)
        {
          if (TAO_debug_level > 0)
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("\n\nTAO (%P|%t) ")
                        ACE_TEXT ("NIOP_Endpoint::set ")
                        ACE_TEXT ("- %p\n\n"),
                        ACE_TEXT ("cannot determine hostname")));
          return -1;
        }
      else
        this->host_ = tmp;
    }
  else
    this->host_ = CORBA::string_dup (tmp_host);

  this->port_ = addr.get_port_number();

  return 0;
} */

int
TAO_NIOP_Endpoint::addr_to_string (char *buffer, size_t length)
{
  const ACE_CString *str = uuid_.to_string ();
  size_t const actual_len =
    str->length ();

  if (length < actual_len)
    return -1;

  ACE_OS::sprintf (buffer, "%s",
                   str->c_str());

  return 0;
}

TAO_Endpoint *
TAO_NIOP_Endpoint::next (void)
{
  return 0;
}

TAO_Endpoint *
TAO_NIOP_Endpoint::duplicate (void)
{
  TAO_NIOP_Endpoint *endpoint = 0;

  ACE_NEW_RETURN (endpoint,
                  TAO_NIOP_Endpoint (this->uuid_),
                  0);

  return endpoint;
}

CORBA::Boolean
TAO_NIOP_Endpoint::is_equivalent (const TAO_Endpoint *other_endpoint)
{
  TAO_Endpoint *endpt = const_cast<TAO_Endpoint *> (other_endpoint);

  TAO_NIOP_Endpoint *endpoint = dynamic_cast<TAO_NIOP_Endpoint *> (endpt);
  if (endpoint == 0)
    return false;

  return (this->uuid_ == endpoint->uuid_);
}

CORBA::ULong
TAO_NIOP_Endpoint::hash (void)
{
  if (this->hash_val_ != 0)
    return this->hash_val_;

  {
    ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                      guard,
                      this->addr_lookup_lock_,
                      this->hash_val_);
    // .. DCL
    if (this->hash_val_ != 0)
      return this->hash_val_;

    const ACE_CString *stringval = this->uuid_.to_string ();
    this->hash_val_ =
      stringval->hash ();
  }

  return this->hash_val_;
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_HAS_NIOP && TAO_HAS_NIOP != 0 */
