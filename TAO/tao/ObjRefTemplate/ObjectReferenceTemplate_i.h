// -*- C++ -*-

//=============================================================================
/**
 * @file ObjectReferenceTemplate_i.h
 *
 * $Id$
 *
 * This is the implementation of the
 * PortableInterceptor::ObjectReferenceTemplate ValueType.
 *
 * @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_OBJECT_REFERENCE_TEMPLATE_I_H
#define TAO_OBJECT_REFERENCE_TEMPLATE_I_H

#include /**/ "ace/pre.h"

#include "tao/ObjRefTemplate/ort_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Default_ORTC.h"
#include "tao/SystemException.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

namespace PortableServer
{
  class POA;

  typedef POA *POA_ptr;
  typedef TAO_Objref_Var_T<POA> POA_var;
}

namespace TAO
{
  /**
   * @class TAO_ObjectReferenceTemplate
   *
   * @brief Implementation of the PortableInterceptor::ObjectReferenceTemplate
   *        interface. This is a default implementation created to be returned
   *        by the IORInfo when the user requests the ORT or ORF.
   */
  class TAO_ORT_Export ObjectReferenceTemplate
    : public virtual OBV_TAO_Default_ORT::ObjectReferenceTemplate,
      public virtual CORBA::DefaultValueRefCountBase
  {
  public:
    /// Constructor
    ObjectReferenceTemplate (const char *server_id,
                             const char *orb_id,
                             PortableInterceptor::AdapterName *adapter_name,
                             PortableServer::POA_ptr poa);

    /**
     * @name PortableInterceptor::ObjectReferenceTemplate Methods
     *
     * Methods required by the
     * PortableInterceptor::ObjectReferenceTemplate ValueType.
     */
    //@{
    virtual char * server_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual char * orb_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual PortableInterceptor::AdapterName * adapter_name (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
    //@}

    /**
     * @name PortableInterceptor::ObjectReferenceFactory Methods
     *
     * Methods required by the
     * PortableInterceptor::ObjectReferenceFactory ValueType.
     */
    //@{
    virtual CORBA::Object_ptr make_object (
      const char * repository_id,
      const PortableInterceptor::ObjectId & id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
                       CORBA::SystemException
                       ));
    //@}

  protected:

    /// Destructor
    /**
     * Protected destructor to enforce proper memory management via
     * reference counting.
     */
    ~ObjectReferenceTemplate (void);

  private:
    const char *server_id_;
    const char *orb_id_;
    PortableInterceptor::AdapterName_var adapter_name_;
    PortableServer::POA_var poa_;
  };
}

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif /* TAO_OBJECT_REFERENCE_TEMPLATE_I_H */
