// -*- C++ -*-

//=============================================================================
/**
 *  @file ThreadPolicyValue.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_THREADPOLICYVALUE_H
#define TAO_PORTABLESERVER_THREADPOLICYVALUE_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "ThreadPolicyC.h"
#include "ace/Service_Object.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace PortableServer
  {
    class TAO_PortableServer_Export ThreadPolicyValue
      : public virtual ACE_Service_Object
    {
      public:
        virtual ~ThreadPolicyValue (void);

        virtual ::PortableServer::ThreadPolicyValue policy_type (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException)) = 0;
    };

    class TAO_PortableServer_Export ORB_CTRL_Thread_Policy
      : public virtual ThreadPolicyValue
    {
      public:
        virtual ~ORB_CTRL_Thread_Policy (void);

        virtual ::PortableServer::ThreadPolicyValue policy_type (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));
    };

    class TAO_PortableServer_Export SINGLE_THREAD_Thread_Policy
      : public virtual ThreadPolicyValue
    {
      public:
        virtual ~SINGLE_THREAD_Thread_Policy  (void);

        virtual ::PortableServer::ThreadPolicyValue policy_type (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));
    };

    ACE_STATIC_SVC_DECLARE (ORB_CTRL_Thread_Policy)
    ACE_FACTORY_DECLARE (TAO_PortableServer, ORB_CTRL_Thread_Policy)

    ACE_STATIC_SVC_DECLARE (SINGLE_THREAD_Thread_Policy)
    ACE_FACTORY_DECLARE (TAO_PortableServer, SINGLE_THREAD_Thread_Policy)
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_THREADPOLICYVALUE_H */

