// $Id$

// ============================================================================
//
// = LIBRARY
//    PortableServer
//
// = FILENAME
//    Strategized_Object_Proxy_Broker.h
//
// = DESCRIPTION
//    This files contains the strategized proxy broker implementation.
//
// = AUTHOR
//     Angelo Corsaro <corsaro@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_STRATEGIZED_OBJECT_PROXY_BROKER_H_
#define TAO_STRATEGIZED_OBJECT_PROXY_BROKER_H_

// -- PortableServer Include --
#include "portableserver_export.h"

// -- ACE Include --
#include "ace/pre.h"

// -- TAO Include --
#include "tao/corba.h"
#include "tao/Object_Proxy_Broker.h"
#include "tao/ORB_Core.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


class TAO_PortableServer_Export TAO_Strategized_Object_Proxy_Broker : public TAO_Object_Proxy_Broker
{
public:

  // -- Ctor/Dtor --
  TAO_Strategized_Object_Proxy_Broker (void);
  ~TAO_Strategized_Object_Proxy_Broker (void);

  virtual TAO_Object_Proxy_Impl &select_proxy (CORBA::Object_ptr object,
                                               CORBA::Environment &ACE_TRY_ENV);

private:

  void create_proxy (TAO_ORB_Core::TAO_Collocation_Strategies strategy,
                     CORBA::Environment &ACE_TRY_ENV);

private:

  TAO_Object_Proxy_Impl
  *proxy_cache_[TAO_ORB_Core::COLLOCATION_STRATEGIES_NUM];

  ACE_SYNCH_MUTEX mutex_;
};

TAO_Strategized_Object_Proxy_Broker *the_tao_strategized_object_proxy_broker (void);
// This function is used to access the unique instance of strategized
// proxy broker. All the CORBA::Object share the proxy broker.

#include "ace/post.h"
#endif /* TAO_STRATEGIZED_OBJECT_PROXY_BROKER_H_ */
