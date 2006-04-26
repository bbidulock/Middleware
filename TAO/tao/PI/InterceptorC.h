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

#ifndef _TAO_IDL_INTERCEPTORC_H_
#define _TAO_IDL_INTERCEPTORC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PI/pi_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PI_Export

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:646

#if !defined (_PORTABLEINTERCEPTOR_INTERCEPTOR__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_INTERCEPTOR__VAR_OUT_CH_
  
  class Interceptor;
  typedef Interceptor *Interceptor_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Interceptor
      >
    Interceptor_var;
  
  typedef
    TAO_Objref_Out_T<
        Interceptor
      >
    Interceptor_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_INTERCEPTOR_CH_)
#define _PORTABLEINTERCEPTOR_INTERCEPTOR_CH_
  
  class TAO_PI_Export Interceptor
    : public virtual ::CORBA::Object
  {
  public:
    typedef Interceptor_ptr _ptr_type;
    typedef Interceptor_var _var_type;
    
    // The static operations.
    static Interceptor_ptr _duplicate (Interceptor_ptr obj);
    
    static void _tao_release (Interceptor_ptr obj);
    
    static Interceptor_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Interceptor_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Interceptor_ptr _nil (void)
    {
      return static_cast<Interceptor_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * name (
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
    Interceptor (void);
    
    virtual ~Interceptor (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Interceptor (const Interceptor &);
    
    void operator= (const Interceptor &);
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

#if !defined (_PORTABLEINTERCEPTOR_INTERCEPTOR__TRAITS_)
#define _PORTABLEINTERCEPTOR_INTERCEPTOR__TRAITS_
  
  template<>
  struct TAO_PI_Export Objref_Traits< ::PortableInterceptor::Interceptor>
  {
    static ::PortableInterceptor::Interceptor_ptr duplicate (
        ::PortableInterceptor::Interceptor_ptr
      );
    static void release (
        ::PortableInterceptor::Interceptor_ptr
      );
    static ::PortableInterceptor::Interceptor_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::PortableInterceptor::Interceptor_ptr p,
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


