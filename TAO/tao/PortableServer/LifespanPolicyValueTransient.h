// -*- C++ -*-

//=============================================================================
/**
 *  @file LifespanPolicyValueTransient.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_LIFESPAN_POLICY_VALUE_TRANSIENT_H
#define TAO_LIFESPAN_POLICY_VALUE_TRANSIENT_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "LifespanPolicyValue.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export LifespanPolicyValueTransient
      : public virtual LifespanPolicyValue
    {
      public:
        virtual ~LifespanPolicyValueTransient (void);

        virtual ::PortableServer::LifespanPolicyValue policy_type (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, LifespanPolicyValueTransient)
    ACE_FACTORY_DECLARE (TAO_PortableServer, LifespanPolicyValueTransient)
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_LIFESPAN_POLICY_VALUE_TRANSIENT_H */

