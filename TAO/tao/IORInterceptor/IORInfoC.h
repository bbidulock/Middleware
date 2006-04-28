// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:154

#ifndef _TAO_IDL_IORINFOC_H_
#define _TAO_IDL_IORINFOC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/IORInterceptor/iorinterceptor_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/PortableInterceptorC.h"
#include "tao/Policy_ForwardC.h"
#include "tao/IOP_IORC.h"
#include "tao/ObjRefTemplate/ObjectReferenceTemplate_includeC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IORInterceptor_Export

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:646

#if !defined (_PORTABLEINTERCEPTOR_IORINFO__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_IORINFO__VAR_OUT_CH_
  
  class IORInfo;
  typedef IORInfo *IORInfo_ptr;
  
  typedef
    TAO_Objref_Var_T<
        IORInfo
      >
    IORInfo_var;
  
  typedef
    TAO_Objref_Out_T<
        IORInfo
      >
    IORInfo_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_IORINFO_CH_)
#define _PORTABLEINTERCEPTOR_IORINFO_CH_
  
  class TAO_IORInterceptor_Export IORInfo
    : public virtual ::CORBA::Object
  {
  public:
    typedef IORInfo_ptr _ptr_type;
    typedef IORInfo_var _var_type;
    
    // The static operations.
    static IORInfo_ptr _duplicate (IORInfo_ptr obj);
    
    static void _tao_release (IORInfo_ptr obj);
    
    static IORInfo_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IORInfo_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IORInfo_ptr _nil (void)
    {
      return static_cast<IORInfo_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr get_effective_policy (
        ::CORBA::PolicyType type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void add_ior_component (
        const ::IOP::TaggedComponent & a_component
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void add_ior_component_to_profile (
        const ::IOP::TaggedComponent & a_component,
        ::IOP::ProfileId profile_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * manager_id (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableInterceptor::AdapterState state (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableInterceptor::ObjectReferenceTemplate * adapter_template (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableInterceptor::ObjectReferenceFactory * current_factory (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void current_factory (
        ::PortableInterceptor::ObjectReferenceFactory * current_factory
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual ::CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    IORInfo (void);
    
    virtual ~IORInfo (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    IORInfo (const IORInfo &);
    
    void operator= (const IORInfo &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module PortableInterceptor

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLEINTERCEPTOR_IORINFO__TRAITS_)
#define _PORTABLEINTERCEPTOR_IORINFO__TRAITS_
  
  template<>
  struct TAO_IORInterceptor_Export Objref_Traits< ::PortableInterceptor::IORInfo>
  {
    static ::PortableInterceptor::IORInfo_ptr duplicate (
        ::PortableInterceptor::IORInfo_ptr
      );
    static void release (
        ::PortableInterceptor::IORInfo_ptr
      );
    static ::PortableInterceptor::IORInfo_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::PortableInterceptor::IORInfo_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_codegen.cpp:1040

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


