// -*- C++ -*-

//=============================================================================
/**
 *  @file IdUniquenessPolicyFactory.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_IDUNIQUENESSPOLICYFACTORY_H
#define TAO_PORTABLESERVER_IDUNIQUENESSPOLICYFACTORY_H
#include /**/ "ace/pre.h"

#include "tao/PortableServer/portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PolicyFactory.h"
#include "tao/PortableServer/IdUniquenessPolicyC.h"

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export IdUniquenessPolicyFactory
      : public virtual PolicyFactory
    {
    public:
      /// Create a new id uniqueness policy
      /**
       * @note If all the compilers supported covariant return types we could
       * change this to a CORBA::Policy_ptr create() call, which is defined
       * as pure virtual in the base. This is something for the future.
       */
      virtual ::PortableServer::IdUniquenessPolicy_ptr create (
        ::PortableServer::IdUniquenessPolicyValue value) = 0;

      /// Create a new id uniqueness policy
      virtual ::PortableServer::IdUniquenessPolicy_ptr create (
        const CORBA::Any &value ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::PolicyError)) = 0;
    };
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_IDUNIQUENESSPOLICYFACTORY_H */
