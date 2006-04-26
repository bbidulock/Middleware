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

#ifndef _TAO_IDL_MESSAGING_RT_POLICYC_H_
#define _TAO_IDL_MESSAGING_RT_POLICYC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Messaging/messaging_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/TimeBaseC.h"
#include "tao/PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Messaging_Export

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace Messaging
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef TimeBase::TimeT Timeout;
  typedef TimeBase::TimeT_out Timeout_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType RELATIVE_RT_TIMEOUT_POLICY_TYPE = 32U;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:646

#if !defined (_MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY__VAR_OUT_CH_)
#define _MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY__VAR_OUT_CH_
  
  class RelativeRoundtripTimeoutPolicy;
  typedef RelativeRoundtripTimeoutPolicy *RelativeRoundtripTimeoutPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        RelativeRoundtripTimeoutPolicy
      >
    RelativeRoundtripTimeoutPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        RelativeRoundtripTimeoutPolicy
      >
    RelativeRoundtripTimeoutPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY_CH_)
#define _MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY_CH_
  
  class TAO_Messaging_Export RelativeRoundtripTimeoutPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef RelativeRoundtripTimeoutPolicy_ptr _ptr_type;
    typedef RelativeRoundtripTimeoutPolicy_var _var_type;
    
    // The static operations.
    static RelativeRoundtripTimeoutPolicy_ptr _duplicate (RelativeRoundtripTimeoutPolicy_ptr obj);
    
    static void _tao_release (RelativeRoundtripTimeoutPolicy_ptr obj);
    
    static RelativeRoundtripTimeoutPolicy_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static RelativeRoundtripTimeoutPolicy_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static RelativeRoundtripTimeoutPolicy_ptr _nil (void)
    {
      return static_cast<RelativeRoundtripTimeoutPolicy_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::TimeBase::TimeT relative_expiry (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr copy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
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
    RelativeRoundtripTimeoutPolicy (void);
    
    virtual ~RelativeRoundtripTimeoutPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    RelativeRoundtripTimeoutPolicy (const RelativeRoundtripTimeoutPolicy &);
    
    void operator= (const RelativeRoundtripTimeoutPolicy &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module Messaging

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY__TRAITS_)
#define _MESSAGING_RELATIVEROUNDTRIPTIMEOUTPOLICY__TRAITS_
  
  template<>
  struct TAO_Messaging_Export Objref_Traits< ::Messaging::RelativeRoundtripTimeoutPolicy>
  {
    static ::Messaging::RelativeRoundtripTimeoutPolicy_ptr duplicate (
        ::Messaging::RelativeRoundtripTimeoutPolicy_ptr
      );
    static void release (
        ::Messaging::RelativeRoundtripTimeoutPolicy_ptr
      );
    static ::Messaging::RelativeRoundtripTimeoutPolicy_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::Messaging::RelativeRoundtripTimeoutPolicy_ptr p,
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


