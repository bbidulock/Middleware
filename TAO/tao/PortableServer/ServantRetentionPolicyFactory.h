// -*- C++ -*-

//=============================================================================
/**
 *  @file ServantRetentionPolicyFactory.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_LOADABLE_SERVANT_RETENTION_POLICY_H
#define TAO_LOADABLE_SERVANT_RETENTION_POLICY_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "PolicyFactory.h"
#include "PortableServerC.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_MINIMUM_POA == 0)

namespace CORBA
{
  class PolicyError;
}

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export ServantRetentionPolicyFactory :
       public virtual PolicyFactory
    {
    public:
      virtual ~ServantRetentionPolicyFactory (void);

      /// Create a new servant retention policy
      /**
       * @note If all the compilers supported covariant return types we could
       * change this to a CORBA::Policy_ptr create() call, which is defined
       * as pure virtual in the base. This is something for the future.
       */
      ::PortableServer::ServantRetentionPolicy_ptr create (
        ::PortableServer::ServantRetentionPolicyValue value);

      /// Create a new servant retention policy
      ::PortableServer::ServantRetentionPolicy_ptr create (
        const CORBA::Any &value ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::PolicyError));
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, ServantRetentionPolicyFactory)
    ACE_FACTORY_DECLARE (TAO_PortableServer, ServantRetentionPolicyFactory)
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_LOADABLE_SERVANT_RETENTION_POLICY_H */
