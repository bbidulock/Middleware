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

#ifndef _TAO_IDL_ORIG_THREADPOLICYC_H_
#define _TAO_IDL_ORIG_THREADPOLICYC_H_

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

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace PortableServer
{

  // TAO_IDL - Generated from
  // be\be_visitor_enum/enum_ch.cpp:57

  enum ThreadPolicyValue
  {
    ORB_CTRL_MODEL,
    SINGLE_THREAD_MODEL
  };

#if (TAO_HAS_MINIMUM_POA == 0)
  typedef ThreadPolicyValue &ThreadPolicyValue_out;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_PortableServer_Export ::CORBA::TypeCode_ptr const _tc_ThreadPolicyValue;

  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLESERVER_THREADPOLICY__VAR_OUT_CH_)
#define _PORTABLESERVER_THREADPOLICY__VAR_OUT_CH_

  class ThreadPolicy;
  typedef ThreadPolicy *ThreadPolicy_ptr;

  typedef
    TAO_Objref_Var_T<
        ThreadPolicy
      >
    ThreadPolicy_var;

  typedef
    TAO_Objref_Out_T<
        ThreadPolicy
      >
    ThreadPolicy_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_THREADPOLICY_CH_)
#define _PORTABLESERVER_THREADPOLICY_CH_

  class TAO_PortableServer_Export ThreadPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef ThreadPolicy_ptr _ptr_type;
    typedef ThreadPolicy_var _var_type;

    // The static operations.
    static ThreadPolicy_ptr _duplicate (ThreadPolicy_ptr obj);

    static void _tao_release (ThreadPolicy_ptr obj);

    static ThreadPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static ThreadPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static ThreadPolicy_ptr _nil (void)
    {
      return static_cast<ThreadPolicy_ptr> (0);
    }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual ::PortableServer::ThreadPolicyValue value (
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
    ThreadPolicy (void);

    virtual ~ThreadPolicy (void);

  private:
    // Private and unimplemented for concrete interfaces.
    ThreadPolicy (const ThreadPolicy &);

    void operator= (const ThreadPolicy &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_PortableServer_Export ::CORBA::TypeCode_ptr const _tc_ThreadPolicy;

#endif /* TAO_HAS_MINIMUM_POA == 0 */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if (TAO_HAS_MINIMUM_POA == 0)

#if !defined (_PORTABLESERVER_THREADPOLICY__TRAITS_CH_)
#define _PORTABLESERVER_THREADPOLICY__TRAITS_CH_

  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::ThreadPolicy>
  {
    static ::PortableServer::ThreadPolicy_ptr duplicate (
        ::PortableServer::ThreadPolicy_ptr
      );
    static void release (
        ::PortableServer::ThreadPolicy_ptr
      );
    static ::PortableServer::ThreadPolicy_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableServer::ThreadPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#endif /* TAO_HAS_MINIMUM_POA == 0 */

}

// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_ch.cpp:51

#if (TAO_HAS_MINIMUM_POA == 0)

TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::ThreadPolicyValue);
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableServer::ThreadPolicyValue &);

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::ThreadPolicy_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::ThreadPolicy_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableServer::ThreadPolicy_ptr &);

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_ch.cpp:50

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, PortableServer::ThreadPolicyValue);
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableServer::ThreadPolicyValue &);

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


