/*=======================================================================
 *
 * @file RepositoryManager_Impl.h
 *
 * $Id$
 *
 * @brief This file contains implementation for
 * Deployment::RepositoryManager interface.
 *
 * @author Jaiganesh Balasubramanian <jai@dre.vanderbilt.edu>
 *
 *======================================================================*/

#ifndef REPOSITORYMANAGER_IMPL_H
#define REPOSITORYMANAGER_IMPL_H

#include "DeploymentS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Synch.h"
#include "ace/Hash_Map_Manager.h"

/**
 *
 * @class ReposityManager_Impl
 *
 * @brief This class implements the RepositoryManager. RepositoryManager
 * assists the execution process after the planning stage.
 *
 */
namespace CIAO
{
  class RepositoryManager_Impl
    : public virtual PortableServer::RefCountServantBase
    {

    public:
      // Default constructor.
      RepositoryManager_Impl (CORBA::ORB_ptr orb,
                            PortableServer::POA_ptr poa
                            ACE_ENV_ARG_DECL);

      // Default destructor.
      ~RepositoryManager_Impl ();

      virtual void installPackage (const char* installation_name,
                                   const char* location
                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Deployment::NameExists,
                         Deployment::PackageError));

      virtual void createPackage (const char* installation_name,
                                  const Deployment::PackageConfiguration& pc,
                                  const char* base_location,
                                  CORBA::Boolean replace
                                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         Deployment::NameExists,
                         Deployment::PackageError));

      virtual Deployment::PackageConfiguration*
        findPackageByName (const char* name
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException,
                           Deployment::NoSuchName));

      virtual Deployment::PackageConfiguration*
        findPackageByUUID (const char* name
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException,
                           Deployment::NoSuchName));

      virtual CORBA::StringSeq*
        findNamesByType (const char* type
                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CORBA::StringSeq*
        getAllNames (ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CORBA::StringSeq*
        getAllTypes (ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
        deletePackage (const char* name
                       ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException,
                           Deployment::NoSuchName));
    };

};

#include /**/ "ace/post.h"
#endif /* REPOSITORYMANAGER_IMPL_H */
