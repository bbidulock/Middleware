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

#ifndef _TAO_IDL_EXCEPTIONHOLDERC_H_
#define _TAO_IDL_EXCEPTIONHOLDERC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "messaging_export.h"
#include "tao/Valuetype/ValueBase.h"
#include "tao/Valuetype/Valuetype_Adapter_Impl.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Valuetype/Value_VarOut_T.h"

#include "tao/OctetSeqC.h"
#include "tao/AnyTypeCode/DynamicC.h"

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
  // be\be_valuetype.cpp:524



#if !defined (_MESSAGING_EXCEPTIONHOLDER__VAR_OUT_CH_)
#define _MESSAGING_EXCEPTIONHOLDER__VAR_OUT_CH_

  class ExceptionHolder;
  typedef
    TAO_Value_Var_T<
        ExceptionHolder
      >
    ExceptionHolder_var;

  typedef
    TAO_Value_Out_T<
        ExceptionHolder
      >
    ExceptionHolder_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_valuetype/valuetype_ch.cpp:61

#if !defined (_MESSAGING_EXCEPTIONHOLDER_CH_)
#define _MESSAGING_EXCEPTIONHOLDER_CH_

  class TAO_Messaging_Export ExceptionHolder
    : public virtual ::CORBA::ValueBase
  {
  public:
    typedef ExceptionHolder_var _var_type;

    static ExceptionHolder* _downcast ( ::CORBA::ValueBase *);

    // (TAO extensions or internals)
    static ::CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        ExceptionHolder *&
      );

    virtual const char* _tao_obv_repository_id (void) const;

    static const char* _tao_obv_static_repository_id (void);

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:400

  public:
    virtual void raise_exception (
         ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      ) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:400

  public:
    virtual void raise_exception_with_list (
        const ::Dynamic::ExceptionList & ACE_ENV_ARG_DECL_WITH_DEFAULTS
      ) = 0;

  protected:

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/field_ch.cpp:469

    virtual void is_system_exception (::CORBA::Boolean) = 0;
    virtual ::CORBA::Boolean is_system_exception (void) const = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/field_ch.cpp:469

    virtual void byte_order (::CORBA::Boolean) = 0;
    virtual ::CORBA::Boolean byte_order (void) const = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/field_ch.cpp:542

    virtual void marshaled_exception (const CORBA::OctetSeq &) = 0;
    virtual const CORBA::OctetSeq &marshaled_exception (void) const = 0;
    virtual CORBA::OctetSeq &marshaled_exception (void) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:251

  protected:
    ExceptionHolder (void);

    virtual ~ExceptionHolder (void);

    virtual ::CORBA::Boolean _tao_marshal_v (TAO_OutputCDR &) const;
    virtual ::CORBA::Boolean _tao_unmarshal_v (TAO_InputCDR &);

  private:
    ExceptionHolder (const ExceptionHolder &);
    void operator= (const ExceptionHolder &);

  protected:
    virtual ::CORBA::Boolean
    _tao_marshal__Messaging_ExceptionHolder (TAO_OutputCDR &) const = 0;

    virtual ::CORBA::Boolean
    _tao_unmarshal__Messaging_ExceptionHolder (TAO_InputCDR &) = 0;
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module Messaging

// TAO_IDL - Generated from
// be\be_visitor_valuetype/obv_module.cpp:55

namespace OBV_Messaging
{

  // TAO_IDL - Generated from
  // be\be_visitor_valuetype/valuetype_obv_ch.cpp:58

#if !defined (_MESSAGING_EXCEPTIONHOLDER___OBV_CH_)
#define _MESSAGING_EXCEPTIONHOLDER___OBV_CH_

  // OBV_ class
  class TAO_Messaging_Export ExceptionHolder
    : public virtual Messaging::ExceptionHolder
  {
  public:

  protected:

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/field_ch.cpp:469

    virtual void is_system_exception (::CORBA::Boolean);
    virtual ::CORBA::Boolean is_system_exception (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/field_ch.cpp:469

    virtual void byte_order (::CORBA::Boolean);
    virtual ::CORBA::Boolean byte_order (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/field_ch.cpp:542

    virtual void marshaled_exception (const CORBA::OctetSeq &);
    virtual const CORBA::OctetSeq &marshaled_exception (void) const;
    virtual CORBA::OctetSeq &marshaled_exception (void);

  protected:
    ExceptionHolder (void);
    virtual ~ExceptionHolder (void);

  protected:
    virtual ::CORBA::Boolean
    _tao_marshal__Messaging_ExceptionHolder (TAO_OutputCDR &) const;

    virtual ::CORBA::Boolean
    _tao_unmarshal__Messaging_ExceptionHolder (TAO_InputCDR &);

    ::CORBA::Boolean _tao_marshal_state (TAO_OutputCDR &) const;
    ::CORBA::Boolean _tao_unmarshal_state (TAO_InputCDR &);

  private:
    ::CORBA::Boolean _pd_is_system_exception;
    ::CORBA::Boolean _pd_byte_order;
    CORBA::OctetSeq _pd_marshaled_exception;
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_MESSAGING_EXCEPTIONHOLDER__TRAITS_)
#define _MESSAGING_EXCEPTIONHOLDER__TRAITS_

  template<>
  struct TAO_Messaging_Export Value_Traits<Messaging::ExceptionHolder>
  {
    static void add_ref (Messaging::ExceptionHolder *);
    static void remove_ref (Messaging::ExceptionHolder *);
    static void release (Messaging::ExceptionHolder *);
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_valuetype.cpp:431

namespace CORBA
{
  extern TAO_Messaging_Export void add_ref (Messaging::ExceptionHolder *);
  extern TAO_Messaging_Export void remove_ref (Messaging::ExceptionHolder *);
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/cdr_op_ch.cpp:61

TAO_Messaging_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Messaging::ExceptionHolder *);
TAO_Messaging_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, Messaging::ExceptionHolder *&);

// TAO_IDL - Generated from
// be\be_codegen.cpp:1040

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ExceptionHolderC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */


