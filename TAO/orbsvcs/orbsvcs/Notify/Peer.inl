// $Id$

#include "Peer.h"
#include "Proxy.h"

CORBA::ULong
TAO_NS_Peer::_incr_refcnt (void)
{
  return this->proxy ()->_incr_refcnt ();
}

CORBA::ULong
TAO_NS_Peer::_decr_refcnt (void)
{
  return this->proxy ()->_decr_refcnt ();
}


void
TAO_NS_Peer::updates_dispatch_observer (TAO_NS_Updates_Dispatch_Observer* updates_dispatch_observer)
{
  this->updates_dispatch_observer_ = updates_dispatch_observer;
}
