// -*- C++ -*-

//=============================================================================
/**
 *  @file    ComponentServer_Impl.h
 *
 *  $Id$
 *
 *  This file contains implementation for the servant of
 *  Components::Deployment::ComponentServer interface.
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================


#ifndef CIAO_COMPONENTSERVER_IMPL_H
#define CIAO_COMPONENTSERVER_IMPL_H
#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "CCM_DeploymentS.h"

namespace CIAO
{
  /**
   * @class ComponentServer_Impl
   *
   * @brief Servant implementation for Components::Deployment::ComponentServer
   *
   * This class implements the Components::Deployment::ComponentServer
   * interface as defined by the CCM spcification.  As the interface
   * implies, this is actually part of the deployment interface and is
   * used to manage the lifecycle of containers running on the server.
   */
  class CIAO_SERVER_Export ComponentServer_Impl
    : public virtual POA_Components::Deployment::ComponentServer,
      public virtual PortableServer::RefCountServantBase
  {
  public:
    /// Constructor
    ComponentServer_Impl (CORBA::ORB_ptr o);

    /// Destructor
    virtual ~ComponentServer_Impl (void);

    /// Get the containing POA.  This operation does *not*
    /// increase the reference count of the POA.
    virtual PortableServer::POA_ptr _default_POA (void);

    /// Initialize the container with a name.
    int init (::Components::ConfigValues &options
              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Components::Deployment::ComponentServer defined attributes/operations.

    virtual ::Components::ConfigValues *
    configuration (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::Deployment::ServerActivator_ptr
    get_server_activator (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::Deployment::Container_ptr
    create_container (const Components::ConfigValues & config
                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CreateFailure,
                       Components::InvalidConfiguration));

    virtual void remove_container (Components::Deployment::Container_ptr cref
                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::RemoveFailure));

    virtual ::Components::Deployment::Containers *
    get_containers (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::RemoveFailure));

protected:
    /// Keep a pointer to the managing ORB serving this servant.
    CORBA::ORB_var orb_;

    /// Keep a pointer to the managing POA.
    PortableServer::POA_var poa_;

    /// Keep a list of managed Container objects.
    Object_Set<::Components::Deployment::Container> container_set_;
  };
}

#if defined (__ACE_INLINE__)
# include "ComponentServer_Impl.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* CIAO_COMPONENTSERVER_IMPL_H */
