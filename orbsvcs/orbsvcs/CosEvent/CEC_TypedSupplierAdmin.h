// $Id$

/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   CEC_TypedSupplierAdmin.h
 *
 *  $Id:
 *
 *  @author Jon Astle (jon@astle45.fsnet.co.uk)
 *
 *  Based on the untyped version by Carlos O'Ryan (coryan@cs.wustl.edu)
 */
//=============================================================================


#ifndef TAO_CEC_TYPEDSUPPLIERADMIN_H_
#define TAO_CEC_TYPEDSUPPLIERADMIN_H_

#include /**/ "ace/pre.h"

#include "orbsvcs/CosTypedEventChannelAdminS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/ESF/ESF_Proxy_Admin.h"

#include "CEC_TypedProxyPushConsumer.h"

class TAO_CEC_TypedEventChannel;

//Class TAO_CEC_TypedSupplierAdmin
class  TAO_Event_Serv_Export TAO_CEC_TypedSupplierAdmin
  : public POA_CosTypedEventChannelAdmin::TypedSupplierAdmin
{
public:
  //Constructor
   TAO_CEC_TypedSupplierAdmin (TAO_CEC_TypedEventChannel* event_channel);

  //Destructor
  virtual ~TAO_CEC_TypedSupplierAdmin (void);

  /// For each elements call <worker->work()>.
  void for_each (TAO_ESF_Worker<TAO_CEC_TypedProxyPushConsumer> *worker
                 ACE_ENV_ARG_DECL);

  /// Keep track of connected consumers.
  virtual void connected (TAO_CEC_TypedProxyPushConsumer*
                          ACE_ENV_ARG_DECL_NOT_USED);
  virtual void reconnected (TAO_CEC_TypedProxyPushConsumer*
                            ACE_ENV_ARG_DECL_NOT_USED);
  virtual void disconnected (TAO_CEC_TypedProxyPushConsumer*
                             ACE_ENV_ARG_DECL_NOT_USED);

  /// The typed event channel is shutting down, inform all the consumers of
  /// this
  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL_NOT_USED);

  // = The CosTypedEventChannelAdmin::TypedSupplierAdmin methods...
  virtual CosTypedEventChannelAdmin::TypedProxyPushConsumer_ptr
    obtain_typed_push_consumer (const char * supported_interface
                                ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       CosTypedEventChannelAdmin::InterfaceNotSupported));

  virtual CosEventChannelAdmin::ProxyPullConsumer_ptr
    obtain_typed_pull_consumer (const char * uses_interface
                                ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       CosTypedEventChannelAdmin::NoSuchImplementation));

  // = The CosEventChannelAdmin::SupplierAdmin methods...
  virtual CosEventChannelAdmin::ProxyPushConsumer_ptr
    obtain_push_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CosEventChannelAdmin::ProxyPullConsumer_ptr
    obtain_pull_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException));

  // = The PortableServer::ServantBase methods
  virtual PortableServer::POA_ptr _default_POA (ACE_ENV_SINGLE_ARG_DECL);

private:
  /// The Event Channel we belong to
  TAO_CEC_TypedEventChannel *typed_event_channel_;

  /// Store the default POA.
  PortableServer::POA_var default_POA_;

  /// The push and pull aspects are implemented using these classes
  TAO_ESF_Proxy_Admin<TAO_CEC_TypedEventChannel,
                      TAO_CEC_TypedProxyPushConsumer,
                      CosTypedEventChannelAdmin::TypedProxyPushConsumer>
    typed_push_admin_;
};

#if defined (__ACE_INLINE__)
#include "CEC_TypedSupplierAdmin.i"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_CEC_TYPEDSUPPLIERADMIN_H_ */
