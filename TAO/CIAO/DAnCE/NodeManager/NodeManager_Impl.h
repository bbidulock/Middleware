// -*- C++ -*-
//=============================================================================
/**
 *  @file NodeManager_Impl.h
 *
 *  $Id$
 *
 *  This file contains servant implementation for Deployment:NodeManager
 *  interface. In the current design of the NodeManager, as with the
 *  legacy  implementation of CIAO, Each NodeManager corresponds to
 *  ONE NodeApplication Manager. Though, the name intuitively suggests
 *  that there be one NodeManager  for every node, our design, allows
 *  the end-user to have multiple components run on the same node.
 *
 *  @author Arvind S. Krishna <arvindk@dre.vanderbilt.edu>
 */
//=============================================================================


#ifndef CIAO_NODEMANAGER_IMPL_H
#define CIAO_NODEMANAGER_IMPL_H
#include /**/ "ace/pre.h"

#include "NodeManagerS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

#include "NAM_Map.h"

namespace CIAO
{
  /**
   * @class NodeManager_Impl
   *
   * @brief Servant implementation CIAO's daemon process control
   * interface
   *
   * This class implements the CIAO:NodeManager interface.
   *
   */
  class NodeManager_Impl
    : public virtual POA_CIAO::NodeManager
  {
  public:

    /// Constructor
    NodeManager_Impl (const char *name,
                      CORBA::ORB_ptr orb,
                      PortableServer::POA_ptr p,
                      const char * nodeapp_loc,
                      const char* nodeapp_options,
                      int spawn_delay)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Initializes the NodeManager.
    virtual void init (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// POA operation..
    virtual PortableServer::POA_ptr _default_POA (void);

    /// CIAO::Daemon defined attributes/operations.
    virtual char * name (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void joinDomain (const Deployment::Domain & domain,
                             Deployment::TargetManager_ptr manager,
                             Deployment::Logger_ptr log
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS
                             )
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void leaveDomain (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Deployment::NodeApplicationManager_ptr
    preparePlan (const Deployment::DeploymentPlan &plan
                 ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::StartError,
                       Deployment::PlanError));

    virtual void
    destroyManager (Deployment::NodeApplicationManager_ptr appManager
                    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::StopError,
                       Deployment::InvalidReference));

  private:
    /// Validate the child deployment plan. In particular, we are
    /// trying to verify that all the component instances within this
    /// child deployment plan have the same "server_resource_id"
    /// assigned.
    bool validate_plan (const Deployment::DeploymentPlan &plan);

  protected:
    /// Since this class is reference counted, making this
    /// destructor protected to enforce proper memory managment
    /// through the reference counting mechanism (i.e. to
    /// disallow calling operator delete() on an instance of
    /// this class.
    virtual ~NodeManager_Impl (void);

    /// Keep a pointer to the managing ORB serving this servant.
    CORBA::ORB_var orb_;

    /// Keep a pointer to the managing POA.
    PortableServer::POA_var poa_;

    /// My Canonical name.
    CORBA::String_var name_;

    /// NodeApplication location
    CORBA::String_var nodeapp_location_;
    
    /// NodeApplication options
    CORBA::String_var nodeapp_options_;
    
    /// Cached callback POA.
    PortableServer::POA_var callback_poa_;

    /// Spawn delay for the NodeAppMgr
    int spawn_delay_;

    // Cache reference of last NodeAppManager
    // Deployment::NodeApplicationManager_var manager_;

    NAM_Map map_;
  };
}

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__ACE_INLINE__)
# include "NodeManager_Impl.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* CIAO_NODEMANAGER_IMPL_H */
