// -*- C++ -*-

//=============================================================================
/**
 * @file ObjectReferenceFactory.h
 *
 * $Id$
 *
 * This is the implementation of the
 * PortableInterceptor::ObjectReferenceFactory interface.
 *
 * @author Priyanka Gontla <gontla_p@ociweb.com>
 */
//=============================================================================

#ifndef TAO_OBJECT_REFERENCE_FACTORY_H
#define TAO_OBJECT_REFERENCE_FACTORY_H

#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_INTERCEPTORS == 1)

#include "tao/PortableInterceptorC.h"
#include "tao/PortableServer/PortableServerC.h"


#include "tao/PortableServer/portableserver_export.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class TAO_POA;

/**
 * @class TAO_ObjectReferenceFactory
 *
 * @brief Implementation of the PortableInterceptor::ObjectReferenceFactory
 *        interface.
 */
class TAO_PortableServer_Export TAO_ObjectReferenceFactory
  : public CORBA::DefaultValueRefCountBase,
    public virtual PortableInterceptor::ObjectReferenceFactory
{
 public:

  /// Constructor
  TAO_ObjectReferenceFactory (TAO_POA *poa);

  virtual CORBA::Object_ptr make_object (
      const char * repository_id,
      const PortableInterceptor::ObjectId & id
      TAO_ENV_ARG_DECL_WITH_DEFAULTS);

  void set_servant (PortableServer::Servant servant);

  void make_object_invoker (CORBA::ULong identifier);

 private:

  TAO_POA *poa_;

  PortableServer::Servant servant_;

  CORBA::ULong make_object_invoker_;
};

#endif /* TAO_HAS_INTERCEPTORS == 1 */

#include "ace/post.h"

#endif /* TAO_OBJECT_REFERENCE_FACTORY_H */
