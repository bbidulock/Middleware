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

#ifndef _TAO_IDL_ORIG_TAO_EXTC_H_
#define _TAO_IDL_ORIG_TAO_EXTC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "messaging_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/PolicyC.h"
#include "tao/TimeBaseC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Messaging_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Messaging_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// be\be_visitor_root/root_ch.cpp:62

namespace TAO
{
  class Collocation_Proxy_Broker;
  
  template<typename T> class Narrow_Utils;
  template<typename T> class AbstractBase_Narrow_Utils;
}

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace TAO
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType CONNECTION_TIMEOUT_POLICY_TYPE = 1413545992U;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_TAO_CONNECTIONTIMEOUTPOLICY__VAR_OUT_CH_)
#define _TAO_CONNECTIONTIMEOUTPOLICY__VAR_OUT_CH_
  
  class ConnectionTimeoutPolicy;
  typedef ConnectionTimeoutPolicy *ConnectionTimeoutPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ConnectionTimeoutPolicy
      >
    ConnectionTimeoutPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        ConnectionTimeoutPolicy
      >
    ConnectionTimeoutPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_TAO_CONNECTIONTIMEOUTPOLICY_CH_)
#define _TAO_CONNECTIONTIMEOUTPOLICY_CH_
  
  class TAO_Messaging_Export ConnectionTimeoutPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef ConnectionTimeoutPolicy_ptr _ptr_type;
    typedef ConnectionTimeoutPolicy_var _var_type;
    
    // The static operations.
    static ConnectionTimeoutPolicy_ptr _duplicate (ConnectionTimeoutPolicy_ptr obj);
    
    static void _tao_release (ConnectionTimeoutPolicy_ptr obj);
    
    static ConnectionTimeoutPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ConnectionTimeoutPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ConnectionTimeoutPolicy_ptr _nil (void)
    {
      return static_cast<ConnectionTimeoutPolicy_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual TimeBase::TimeT relative_expiry (
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
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ConnectionTimeoutPolicy (void);
    
    virtual ~ConnectionTimeoutPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ConnectionTimeoutPolicy (const ConnectionTimeoutPolicy &);
    
    void operator= (const ConnectionTimeoutPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr const _tc_ConnectionTimeoutPolicy;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module TAO

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_TAO_CONNECTIONTIMEOUTPOLICY__TRAITS_CH_)
#define _TAO_CONNECTIONTIMEOUTPOLICY__TRAITS_CH_
  
  template<>
  struct TAO_Messaging_Export Objref_Traits< ::TAO::ConnectionTimeoutPolicy>
  {
    static ::TAO::ConnectionTimeoutPolicy_ptr duplicate (
        ::TAO::ConnectionTimeoutPolicy_ptr
      );
    static void release (
        ::TAO::ConnectionTimeoutPolicy_ptr
      );
    static ::TAO::ConnectionTimeoutPolicy_ptr nil (void);
    static CORBA::Boolean marshal (
        ::TAO::ConnectionTimeoutPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_Messaging_Export void operator<<= (CORBA::Any &, TAO::ConnectionTimeoutPolicy_ptr); // copying
TAO_Messaging_Export void operator<<= (CORBA::Any &, TAO::ConnectionTimeoutPolicy_ptr *); // non-copying
TAO_Messaging_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO::ConnectionTimeoutPolicy_ptr &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:969

#if defined (__ACE_INLINE__)
#include "TAO_ExtC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


