// -*- C++ -*-

//=============================================================================
/**
 * @file SL3_SecurityManager.h
 *
 * $Id$
 *
 * @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================


#ifndef TAO_SL3_SECURITY_MANAGER_H
#define TAO_SL3_SECURITY_MANAGER_H

#include /**/ "ace/pre.h"
#include "orbsvcs/orbsvcs/Security/security_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/orbsvcs/SecurityLevel3C.h"

#include "tao/LocalObject.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

namespace TAO
{
  namespace SL3
  {
    /**
     * @class SecurityManager
     *
     * @brief
     *
     *
     */
    class TAO_Security_Export SecurityManager
      : public virtual SecurityLevel3::SecurityManager,
        public virtual TAO_Local_RefCounted_Object
    {
    public:

      /// Constructor
      SecurityManager (SecurityLevel3::CredentialsCurator_ptr cc);

      /**
       * @name SecurityLevel3::SecurityManager Methods
       *
       * Methods required by the SecurityLevel3::SecurityManager
       * interface.
       */
      //@{
      virtual SecurityLevel3::CredentialsCurator_ptr credentials_curator (
          ACE_ENV_SINGLE_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException));

      virtual SecurityLevel3::TargetCredentials_ptr get_target_credentials (
          CORBA::Object_ptr the_object
          ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException));

      virtual SecurityLevel3::ContextEstablishmentPolicy_ptr
      create_context_estab_policy (
          SecurityLevel3::CredsDirective creds_directive,
          const SecurityLevel3::OwnCredentialsList & creds_list,
          SecurityLevel3::FeatureDirective use_client_auth,
          SecurityLevel3::FeatureDirective use_target_auth,
          SecurityLevel3::FeatureDirective use_confidentiality,
          SecurityLevel3::FeatureDirective use_integrity
          ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException));

      virtual SecurityLevel3::ObjectCredentialsPolicy_ptr
      create_object_creds_policy (
          const SecurityLevel3::OwnCredentialsList & cred_list
          ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException));
      //@}

    protected:

      /// Destructor
      /**
       * Protected destructor to enforce proper memory management
       * through the reference counting mechanism.
       */
      ~SecurityManager (void);

    private:

      /// The ORB-specific SecurityLevel3::CredentialsCurator
      /// reference.
      SecurityLevel3::CredentialsCurator_var credentials_curator_;

    };

  } // End SL3 namespace

}  // End TAO namespace


#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif  /* TAO_SL3_SECURITY_MANAGER_H */
