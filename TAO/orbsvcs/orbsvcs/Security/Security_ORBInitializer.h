// -*- C++ -*-
//
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     Security_ORBInitializer.h
//
// = AUTHOR
//     Ossama Othman <ossama@uci.edu>
//
// ============================================================================

#ifndef TAO_SECURITY_ORB_INITIALIZER_H
#define TAO_SECURITY_ORB_INITIALIZER_H

#include /**/ "ace/pre.h"

#include "security_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableInterceptorC.h"
#include "tao/LocalObject.h"

#include "Security_PolicyFactory.h"

// This is to remove "inherits via dominance" warnings from MSVC.
// MSVC is being a little too paranoid.
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

/// Security ORB initializer.
namespace TAO
{
  namespace Security
  {

    /**
     * @class ORBInitializer
     *
     * @brief ORBInitializer that configures CORBA Security features
     *        into an ORB.
     *
     * This ORBInitializer configures CORBA Security features into an
     * ORB, such as CSIv2, security objects, security policy
     * factories, etc, into an ORB.
     */
    class TAO_Security_Export ORBInitializer
      : public virtual PortableInterceptor::ORBInitializer,
        public virtual TAO_Local_RefCounted_Object
    {
    public:

      /**
       * @name PortableInterceptor::ORBInitializer Methods.
       *
       * Methods required by the PortableInterceptor::ORBInitializer
       * interface.
       */
      //@{
      virtual void pre_init (PortableInterceptor::ORBInitInfo_ptr info
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void post_init (PortableInterceptor::ORBInitInfo_ptr info
                              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));
      //@}

    private:

      /// Register Security policy factories.
      void register_policy_factories (PortableInterceptor::ORBInitInfo_ptr info
                                      ACE_ENV_ARG_DECL);

    private:

      /// PolicyFactory that is used to create all security related
      /// policies capable of being created via ORB::create_policy().
      TAO::Security::PolicyFactory policy_factory_;

    };

  } // End Security namespace
}  // End TAO namespace

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif /* TAO_SECURITY_ORB_INITIALIZER_H */
