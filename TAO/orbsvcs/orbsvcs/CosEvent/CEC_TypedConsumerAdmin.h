// $Id$
/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   CEC_TypedConsumerAdmin.h
 *
 *  @author Jon Astle (jon@astle45.fsnet.co.uk)
 *
 *  Based on the untyped version by Carlos O'Ryan (coryan@cs.wustl.edu)
 */
//=============================================================================


#ifndef TAO_CEC_TYPEDCONSUMERADMIN_H_
#define TAO_CEC_TYPEDCONSUMERADMIN_H_

#include "ace/pre.h"

#include "orbsvcs/CosTypedEventChannelAdminS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/ESF/ESF_Proxy_Admin.h"

#include "CEC_ProxyPushSupplier.h"
#include "CEC_TypedEvent.h"

class TAO_CEC_TypedEventChannel;

//Class TAO_CEC_TypedConsumerAdmin
class TAO_Event_Export TAO_CEC_TypedConsumerAdmin 
  : public POA_CosTypedEventChannelAdmin::TypedConsumerAdmin
{
public:

  // Constructor 
  TAO_CEC_TypedConsumerAdmin (TAO_CEC_TypedEventChannel* typed_event_channel);
  
  // Destructor 
  virtual ~TAO_CEC_TypedConsumerAdmin (void);

  /// For each elements call <worker->work()>.
  void for_each (TAO_ESF_Worker<TAO_CEC_ProxyPushSupplier> *worker
                 ACE_ENV_ARG_DECL);

  /// Invoke the typed event on all the consumers
  virtual void invoke (const TAO_CEC_TypedEvent& typed_event
                       ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException));

  /// Used to inform the EC that a Supplier has connected or
  /// disconnected from it.
  virtual void connected (TAO_CEC_ProxyPushSupplier*
                          ACE_ENV_ARG_DECL_NOT_USED);
  virtual void reconnected (TAO_CEC_ProxyPushSupplier*
                            ACE_ENV_ARG_DECL_NOT_USED);
  virtual void disconnected (TAO_CEC_ProxyPushSupplier*
                             ACE_ENV_ARG_DECL_NOT_USED);

  /// The typed event channel is shutting down, inform all the consumers of
  /// this
  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL_NOT_USED);

  // = The CosTypedEventChannelAdmin::TypedConsumerAdmin methods...
  virtual CosEventChannelAdmin::ProxyPushSupplier_ptr
    obtain_typed_push_supplier (const char * uses_interface)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       CosTypedEventChannelAdmin::NoSuchImplementation));
  virtual CosTypedEventChannelAdmin::TypedProxyPullSupplier_ptr 
    obtain_typed_pull_supplier (const char * supported_interface)
      ACE_THROW_SPEC ((CORBA::SystemException, 
                       CosTypedEventChannelAdmin::InterfaceNotSupported));

  // = The CosEventChannelAdmin::ConsumerAdmin methods...
  virtual CosEventChannelAdmin::ProxyPushSupplier_ptr
    obtain_push_supplier (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CosEventChannelAdmin::ProxyPullSupplier_ptr
    obtain_pull_supplier (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException));

  // = The PortableServer::ServantBase methods
  virtual PortableServer::POA_ptr _default_POA (ACE_ENV_SINGLE_ARG_DECL);

private:
  /// The Event Channel we belong to
  TAO_CEC_TypedEventChannel *typed_event_channel_;

  /// Store the default POA.
  PortableServer::POA_var default_POA_;

  /// Implement the push side of this class
  TAO_ESF_Proxy_Admin<TAO_CEC_TypedEventChannel,TAO_CEC_ProxyPushSupplier,CosEventChannelAdmin::ProxyPushSupplier> typed_push_admin_;
};

// ****************************************************************

class TAO_CEC_Propagate_Typed_Event : public TAO_ESF_Worker<TAO_CEC_ProxyPushSupplier>
{
public:
  TAO_CEC_Propagate_Typed_Event (const TAO_CEC_TypedEvent& typed_event,
                                 TAO_CEC_TypedEventChannel* typed_event_channel);

  void work (TAO_CEC_ProxyPushSupplier *supplier
             ACE_ENV_ARG_DECL);

private:
  /// The typed event
  const TAO_CEC_TypedEvent typed_event_;

  /// The typed EC
  TAO_CEC_TypedEventChannel* typed_event_channel_;
};

#if defined (__ACE_INLINE__)
#include "CEC_TypedConsumerAdmin.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"

#endif /* TAO_CEC_TYPEDCONSUMERADMIN_H_ */
