// -*- C++ -*-

//=============================================================================
/**
 *  @file ServantRetentionPolicyValueNonRetain.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_SERVANT_RETENTION_POLICY_VALUE_NON_RETAIN_H
#define TAO_SERVANT_RETENTION_POLICY_VALUE_NON_RETAIN_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ServantRetentionPolicyValue.h"
#include "ace/Service_Config.h"

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export ServantRetentionPolicyValueNonRetain
      : public virtual ServantRetentionPolicyValue
    {
      public:
        virtual ~ServantRetentionPolicyValueNonRetain  (void);

        virtual ::PortableServer::ServantRetentionPolicyValue policy_type (void);
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, ServantRetentionPolicyValueNonRetain)
    ACE_FACTORY_DECLARE (TAO_PortableServer, ServantRetentionPolicyValueNonRetain)
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_SERVANT_RETENTION_POLICY_VALUE_NON_RETAIN_H */

