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

#ifndef _TAO_IDL_IDASSIGNMENTPOLICYC_H_
#define _TAO_IDL_IDASSIGNMENTPOLICYC_H_

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

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

namespace PortableServer
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_enum/enum_ch.cpp:57
  
  enum IdAssignmentPolicyValue
  {
    USER_ID,
    SYSTEM_ID
  };
  
  typedef IdAssignmentPolicyValue &IdAssignmentPolicyValue_out;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLESERVER_IDASSIGNMENTPOLICY__VAR_OUT_CH_)
#define _PORTABLESERVER_IDASSIGNMENTPOLICY__VAR_OUT_CH_
  
  class IdAssignmentPolicy;
  typedef IdAssignmentPolicy *IdAssignmentPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        IdAssignmentPolicy
      >
    IdAssignmentPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        IdAssignmentPolicy
      >
    IdAssignmentPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_IDASSIGNMENTPOLICY_CH_)
#define _PORTABLESERVER_IDASSIGNMENTPOLICY_CH_
  
  class TAO_PortableServer_Export IdAssignmentPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef IdAssignmentPolicy_ptr _ptr_type;
    typedef IdAssignmentPolicy_var _var_type;
    
    // The static operations.
    static IdAssignmentPolicy_ptr _duplicate (IdAssignmentPolicy_ptr obj);
    
    static void _tao_release (IdAssignmentPolicy_ptr obj);
    
    static IdAssignmentPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IdAssignmentPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static IdAssignmentPolicy_ptr _nil (void)
    {
      return static_cast<IdAssignmentPolicy_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableServer::IdAssignmentPolicyValue value (
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
    IdAssignmentPolicy (void);
    
    virtual ~IdAssignmentPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    IdAssignmentPolicy (const IdAssignmentPolicy &);
    
    void operator= (const IdAssignmentPolicy &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_IDASSIGNMENTPOLICY__TRAITS_)
#define _PORTABLESERVER_IDASSIGNMENTPOLICY__TRAITS_
  
  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::IdAssignmentPolicy>
  {
    static ::PortableServer::IdAssignmentPolicy_ptr duplicate (
        ::PortableServer::IdAssignmentPolicy_ptr
      );
    static void release (
        ::PortableServer::IdAssignmentPolicy_ptr
      );
    static ::PortableServer::IdAssignmentPolicy_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableServer::IdAssignmentPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_ch.cpp:50

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, PortableServer::IdAssignmentPolicyValue);
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableServer::IdAssignmentPolicyValue &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:1028

#include /**/ "ace/post.h"

#endif /* ifndef */


