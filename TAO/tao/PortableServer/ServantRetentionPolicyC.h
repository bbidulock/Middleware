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
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_SERVANTRETENTIONPOLICYC_H_
#define _TAO_IDL_ORIG_SERVANTRETENTIONPOLICYC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "portableserver_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_PortableServer_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// be\be_visitor_root/root_ch.cpp:63

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  class Collocation_Proxy_Broker;
  
  template<typename T> class Narrow_Utils;
  template<typename T> class AbstractBase_Narrow_Utils;
}

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace PortableServer
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_enum/enum_ch.cpp:57
  
  enum ServantRetentionPolicyValue
  {
    RETAIN,
    NON_RETAIN
  };
  
  typedef ServantRetentionPolicyValue &ServantRetentionPolicyValue_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServantRetentionPolicyValue;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:603

#if !defined (_PORTABLESERVER_SERVANTRETENTIONPOLICY__VAR_OUT_CH_)
#define _PORTABLESERVER_SERVANTRETENTIONPOLICY__VAR_OUT_CH_
  
  class ServantRetentionPolicy;
  typedef ServantRetentionPolicy *ServantRetentionPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ServantRetentionPolicy
      >
    ServantRetentionPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        ServantRetentionPolicy
      >
    ServantRetentionPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_SERVANTRETENTIONPOLICY_CH_)
#define _PORTABLESERVER_SERVANTRETENTIONPOLICY_CH_
  
  class TAO_PortableServer_Export ServantRetentionPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef ServantRetentionPolicy_ptr _ptr_type;
    typedef ServantRetentionPolicy_var _var_type;
    
    // The static operations.
    static ServantRetentionPolicy_ptr _duplicate (ServantRetentionPolicy_ptr obj);
    
    static ServantRetentionPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ServantRetentionPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ServantRetentionPolicy_ptr _nil (void)
    {
      return (ServantRetentionPolicy_ptr)0;
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableServer::ServantRetentionPolicyValue value (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr copy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:208
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ServantRetentionPolicy (void);
    
    virtual ~ServantRetentionPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ServantRetentionPolicy (const ServantRetentionPolicy &);
    
    void operator= (const ServantRetentionPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServantRetentionPolicy;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_SERVANTRETENTIONPOLICY__TRAITS_CH_)
#define _PORTABLESERVER_SERVANTRETENTIONPOLICY__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::ServantRetentionPolicy>
  {
    static ::PortableServer::ServantRetentionPolicy_ptr duplicate (
        ::PortableServer::ServantRetentionPolicy_ptr
      );
    static void release (
        ::PortableServer::ServantRetentionPolicy_ptr
      );
    static ::PortableServer::ServantRetentionPolicy_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableServer::ServantRetentionPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_ch.cpp:51

TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::ServantRetentionPolicyValue);
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableServer::ServantRetentionPolicyValue &);

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::ServantRetentionPolicy_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::ServantRetentionPolicy_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableServer::ServantRetentionPolicy_ptr &);

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_ch.cpp:50

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableServer::ServantRetentionPolicyValue &);
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableServer::ServantRetentionPolicyValue &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:958

#if defined (__ACE_INLINE__)
#include "ServantRetentionPolicyC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


