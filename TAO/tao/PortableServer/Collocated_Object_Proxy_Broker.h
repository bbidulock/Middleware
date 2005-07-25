// -*- C++ -*-

//=============================================================================
/**
 *  @file    Collocated_Object_Proxy_Broker.h
 *
 *  $Id$
 *
 *  This files contains the Collocated Proxy Broker implementation
 *  for the CORBA Object.
 *
 *  @author  Angelo Corsaro <corsaro@cs.wustl.edu>
 *  @author  Balachandran Natarajan (modified the implementation)
 */
//=============================================================================

#ifndef TAO_COLLOCATED_OBJECT_PROXY_BROKER_H
#define TAO_COLLOCATED_OBJECT_PROXY_BROKER_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Object_Proxy_Broker.h"

namespace TAO
{
  /**
   * @class Collocated_Object_Proxy_Broker
   *
   * @brief Collocated_Object_Proxy_Broker
   *
   * A broker for standard CORBA::Object calls that needs to be made
   * on remote objects.
   */
  class TAO_PortableServer_Export Collocated_Object_Proxy_Broker
    : public Object_Proxy_Broker
  {
  public:
    /// Please see the documentation in Object_Proxy_Broker.h for
    /// details.
    virtual CORBA::Boolean _is_a (CORBA::Object_ptr target,
                                  const char *logical_type_id
                                  ACE_ENV_ARG_DECL);

#if (TAO_HAS_MINIMUM_CORBA == 0)

  virtual CORBA::Boolean _non_existent (CORBA::Object_ptr target
                                        ACE_ENV_ARG_DECL);

  virtual CORBA::InterfaceDef * _get_interface (
      CORBA::Object_ptr target
      ACE_ENV_ARG_DECL
    );

  virtual CORBA::Object_ptr _get_component (CORBA::Object_ptr target
                                            ACE_ENV_ARG_DECL);

  virtual char * _repository_id (CORBA::Object_ptr target
                                 ACE_ENV_ARG_DECL);

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

  };
}

// -----------------------------------------------------

/// This function is used to access the unique instance of strategized
/// proxy broker. All the CORBA::Object share the proxy broker.
TAO::Collocated_Object_Proxy_Broker *the_tao_collocated_object_proxy_broker (void);

#include /**/ "ace/post.h"

#endif /* TAO_COLLOCATED_OBJECT_PROXY_BROKER_H*/
