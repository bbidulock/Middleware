// $Id$

#ifndef TAO_EC_CONCRETE_PROXY_SET_CPP
#define TAO_EC_CONCRETE_PROXY_SET_CPP

#include "EC_Concrete_Proxy_Set.h"

#if ! defined (__ACE_INLINE__)
#include "EC_Concrete_Proxy_Set.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Event, EC_Concrete_Proxy_Set, "$Id$")

template<class PROXY>
TAO_EC_List_Based_Proxy_Set<PROXY>::
      TAO_EC_List_Based_Proxy_Set (void)
{
}

template<class PROXY> void
TAO_EC_List_Based_Proxy_Set<PROXY>::connected (PROXY *proxy,
                                               CORBA::Environment &)
{
  int r = this->impl_.insert (proxy);
  if (r == 0)
    return;

  if (r == 1)
    {
      // @@ Already there, throw some user exception..
      proxy->_decr_refcnt ();
    }
  if (r == -1)
    {
      // @@ Cannot insert, running out of memory? throw some other
      // user exception
      proxy->_decr_refcnt ();
    }
}

template<class PROXY> void
TAO_EC_List_Based_Proxy_Set<PROXY>::reconnected (PROXY *proxy,
                                                 CORBA::Environment &)
{
  int r = this->impl_.insert (proxy);
  if (r == 0 || r == 1)
    {
      // Reference count is incremented by the callers to [re]connected.
      // @@ Find out if the protocol could be simplified, and decoupling
      //    increased.
      proxy->_decr_refcnt ();
      return;
    }

  if (r == -1)
    {
      // @@ Cannot insert, running out of memory? throw some other
      // user exception
      proxy->_decr_refcnt ();
    }
}

template<class PROXY> void
TAO_EC_List_Based_Proxy_Set<PROXY>::disconnected (PROXY *proxy,
                                                  CORBA::Environment &)
{
  int r = this->impl_.remove (proxy);
  if (r != 0)
    {
      // @@ Cannot remove, throw some other
      // user exception
      return;
    }
  proxy->_decr_refcnt ();
}

template<class PROXY> void
TAO_EC_List_Based_Proxy_Set<PROXY>::shutdown (CORBA::Environment &)
{
  Iterator end = this->impl_.end ();
  for (Iterator i = this->impl_.begin (); i != end; ++i)
    {
      // Decrement reference count
      (*i)->_decr_refcnt ();
    }
  this->impl_.reset ();
}

// ****************************************************************

template<class PROXY>
TAO_EC_RB_Tree_Based_Proxy_Set<PROXY>::
      TAO_EC_RB_Tree_Based_Proxy_Set (void)
{
}

template<class PROXY> void
TAO_EC_RB_Tree_Based_Proxy_Set<PROXY>::connected (PROXY *proxy,
                                                  CORBA::Environment &)
{
  int r = this->impl_.bind (proxy, 1);
  if (r == 0)
    return;

  if (r == 1)
    {
      // @@ Already there, throw some user exception..
      proxy->_decr_refcnt ();
    }
  if (r == -1)
    {
      // @@ Cannot insert, running out of memory? throw some other
      // user exception
      proxy->_decr_refcnt ();
    }
}

template<class PROXY> void
TAO_EC_RB_Tree_Based_Proxy_Set<PROXY>::reconnected (PROXY *proxy,
                                                 CORBA::Environment &)
{
  int r = this->impl_.rebind (proxy, 1);
  if (r != 0)
    {
      // Reference count is incremented by the callers to [re]connected.
      // @@ Find out if the protocol could be simplified, and decoupling
      //    increased.
      proxy->_decr_refcnt ();
      return;
    }
}

template<class PROXY> void
TAO_EC_RB_Tree_Based_Proxy_Set<PROXY>::disconnected (PROXY *proxy,
                                                  CORBA::Environment &)
{
  int r = this->impl_.unbind (proxy);
  if (r != 0)
    {
      // @@ Cannot remove, throw some other
      // user exception
      return;
    }
  proxy->_decr_refcnt ();
}

template<class PROXY> void
TAO_EC_RB_Tree_Based_Proxy_Set<PROXY>::shutdown (CORBA::Environment &)
{
  Iterator end = this->impl_.end ();
  for (Iterator i = this->impl_.begin (); i != end; ++i)
    {
      // Decrement reference count
      (*i)->_decr_refcnt ();
    }
  this->impl_.clear ();
}

#endif /* TAO_EC_CONCRETE_PROXY_SET_CPP */
