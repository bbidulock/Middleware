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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_MESSAGING_POLICYVALUEC_H_
#define _TAO_IDL_ORIG_MESSAGING_POLICYVALUEC_H_

#include /**/ "ace/pre.h"
#include "IOP_IORC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#include "tao/Policy_ForwardC.h"

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  Messaging
{

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:231

  struct PolicyValue;

  typedef
    TAO_Var_Var_T<
        PolicyValue
      >
    PolicyValue_var;

  typedef
    TAO_Out_T<
        PolicyValue,
        PolicyValue_var
      >
    PolicyValue_out;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export PolicyValue
  {
    typedef PolicyValue_var _var_type;

    static void _tao_any_destructor (void *);
    CORBA::PolicyType ptype;


    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:75

    class TAO_Export _tao_seq_Octet
      : public
          TAO_Unbounded_Sequence<
              CORBA::Octet
            >
    {
    public:
      _tao_seq_Octet (void);
      _tao_seq_Octet (CORBA::ULong max);
      _tao_seq_Octet (
          CORBA::ULong max,
          CORBA::ULong length,
          CORBA::Octet *buffer,
          CORBA::Boolean release = 0
        );
      _tao_seq_Octet (const _tao_seq_Octet &);
      ~_tao_seq_Octet (void);

      static void _tao_any_destructor (void *);



#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      _tao_seq_Octet (
          CORBA::ULong length,
          const ACE_Message_Block* mb
        )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
    };

    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_field/field_ch.cpp:447

    typedef _tao_seq_Octet _pvalue_seq;
    _tao_seq_Octet pvalue;
  };

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_PolicyValue;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:75

  class PolicyValueSeq;

  typedef
    TAO_VarSeq_Var_T<
        PolicyValueSeq,
        Messaging::PolicyValue
      >
    PolicyValueSeq_var;

  typedef
    TAO_Seq_Out_T<
        PolicyValueSeq,
        PolicyValueSeq_var,
        Messaging::PolicyValue
      >
    PolicyValueSeq_out;

  class TAO_Export PolicyValueSeq
    : public
        TAO_Unbounded_Sequence<
            Messaging::PolicyValue
          >
  {
  public:
    PolicyValueSeq (void);
    PolicyValueSeq (CORBA::ULong max);
    PolicyValueSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        PolicyValue *buffer,
        CORBA::Boolean release = 0
      );
    PolicyValueSeq (const PolicyValueSeq &);
    ~PolicyValueSeq (void);

    static void _tao_any_destructor (void *);

    typedef PolicyValueSeq_var _var_type;
  };

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_PolicyValueSeq;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_POLICIES = 2U;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId INVOCATION_POLICIES = 2U;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module Messaging

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Messaging::PolicyValue &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Messaging::PolicyValue*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::PolicyValue *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Messaging::PolicyValue *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Messaging::PolicyValueSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Messaging::PolicyValueSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::PolicyValueSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Messaging::PolicyValueSeq *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Messaging::PolicyValue &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, Messaging::PolicyValue &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:57

#if !defined _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_H_
#define _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValue::_tao_seq_Octet &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValue::_tao_seq_Octet &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:57

#if !defined _TAO_CDR_OP_Messaging_PolicyValueSeq_H_
#define _TAO_CDR_OP_Messaging_PolicyValueSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValueSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValueSeq &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValueSeq_H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "Messaging_PolicyValueC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */
