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

#ifndef _TAO_IDL_ORIG_LIFESPANPOLICYC_H_
#define _TAO_IDL_ORIG_LIFESPANPOLICYC_H_

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
#include "tao/PortableServer/PortableServerC.h"

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
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// be\be_visitor_root/root_ch.cpp:63

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
  // be\be_interface.cpp:601

#if !defined (_PORTABLESERVER_LIFESPANPOLICY__VAR_OUT_CH_)
#define _PORTABLESERVER_LIFESPANPOLICY__VAR_OUT_CH_
  
  class LifespanPolicy;
  typedef LifespanPolicy *LifespanPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        LifespanPolicy
      >
    LifespanPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        LifespanPolicy
      >
    LifespanPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_LIFESPANPOLICY_CH_)
#define _PORTABLESERVER_LIFESPANPOLICY_CH_
  
  class TAO_PortableServer_Export LifespanPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef LifespanPolicy_ptr _ptr_type;
    typedef LifespanPolicy_var _var_type;
    
    // The static operations.
    static LifespanPolicy_ptr _duplicate (LifespanPolicy_ptr obj);
    
    static LifespanPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static LifespanPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static LifespanPolicy_ptr _nil (void)
    {
      return (LifespanPolicy_ptr)0;
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableServer::LifespanPolicyValue value (
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
    LifespanPolicy (void);
    
    virtual ~LifespanPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    LifespanPolicy (const LifespanPolicy &);
    
    void operator= (const LifespanPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_LifespanPolicy;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_LIFESPANPOLICY__TRAITS_CH_)
#define _PORTABLESERVER_LIFESPANPOLICY__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::LifespanPolicy>
  {
    static ::PortableServer::LifespanPolicy_ptr duplicate (
        ::PortableServer::LifespanPolicy_ptr
      );
    static void release (
        ::PortableServer::LifespanPolicy_ptr
      );
    static ::PortableServer::LifespanPolicy_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableServer::LifespanPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::LifespanPolicy_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::LifespanPolicy_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableServer::LifespanPolicy_ptr &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:964

#if defined (__ACE_INLINE__)
#include "LifespanPolicyC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


