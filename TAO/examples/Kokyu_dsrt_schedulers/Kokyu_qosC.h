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
// .\be\be_codegen.cpp:186

#ifndef _TAO_IDL_KOKYU_QOSC_H_
#define _TAO_IDL_KOKYU_QOSC_H_

#include /**/ "ace/pre.h"

#include "tao/ORB.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Kokyu_dsrt_schedulers_export.h"
#include "tao/CDR.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#include "TimeBaseC.h"
#include "tao/RTCORBA/RTCORBA_includeC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO Kokyu_DSRT_Schedulers_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO Kokyu_DSRT_Schedulers_Export
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
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:48

namespace Kokyu
{
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_KOKYU_GUIDTYPE_CH_)
#define _KOKYU_GUIDTYPE_CH_
  
  class GuidType;
  
  typedef
    TAO_FixedSeq_Var_T<
        GuidType,
        CORBA::Octet
      >
    GuidType_var;
  
  typedef
    TAO_Seq_Out_T<
        GuidType,
        GuidType_var,
        CORBA::Octet
      >
    GuidType_out;
  
  class Kokyu_DSRT_Schedulers_Export GuidType
    : public
        TAO_Unbounded_Sequence<
            CORBA::Octet
          >
  {
  public:
    GuidType (void);
    GuidType (CORBA::ULong max);
    GuidType (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::Octet* buffer, 
        CORBA::Boolean release = 0
      );
    GuidType (const GuidType &);
    ~GuidType (void);
    
    static void _tao_any_destructor (void *);
    
    typedef GuidType_var _var_type;

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
    GuidType (
        CORBA::ULong length,
        const ACE_Message_Block* mb
      )
      : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_GuidType;
  
  // TAO_IDL - Generated from
  // .\be\be_type.cpp:258
  
  struct Svc_Ctxt_DSRT_QoS;
  
  typedef
    TAO_Var_Var_T<
        Svc_Ctxt_DSRT_QoS
      >
    Svc_Ctxt_DSRT_QoS_var;
  
  typedef
    TAO_Out_T<
        Svc_Ctxt_DSRT_QoS,
        Svc_Ctxt_DSRT_QoS_var
      >
    Svc_Ctxt_DSRT_QoS_out;
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:52
  
  struct Kokyu_DSRT_Schedulers_Export Svc_Ctxt_DSRT_QoS
  {
    typedef Svc_Ctxt_DSRT_QoS_var _var_type;
    
    static void _tao_any_destructor (void *);
    Kokyu::GuidType guid;
    CORBA::Long importance;
    CORBA::Long criticality;
    RTCORBA::Priority desired_priority;
    TimeBase::TimeT deadline;
    TimeBase::TimeT estimated_initial_execution_time;
  };
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Svc_Ctxt_DSRT_QoS;

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:66

} // module Kokyu

// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:50

// Traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_ch.cpp:52

Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, const Kokyu::GuidType &); // copying version
Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, Kokyu::GuidType*); // noncopying version
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>>= (const CORBA::Any &, Kokyu::GuidType *&); // deprecated
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Kokyu::GuidType *&);

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:52

Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, const Kokyu::Svc_Ctxt_DSRT_QoS &); // copying version
Kokyu_DSRT_Schedulers_Export void operator<<= (CORBA::Any &, Kokyu::Svc_Ctxt_DSRT_QoS*); // noncopying version
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>>= (const CORBA::Any &, Kokyu::Svc_Ctxt_DSRT_QoS *&); // deprecated
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Kokyu::Svc_Ctxt_DSRT_QoS *&);

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_Kokyu_GuidType_H_
#define _TAO_CDR_OP_Kokyu_GuidType_H_

Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Kokyu::GuidType &
  );
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Kokyu::GuidType &
  );

#endif /* _TAO_CDR_OP_Kokyu_GuidType_H_ */

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:53

Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Kokyu::Svc_Ctxt_DSRT_QoS &);
Kokyu_DSRT_Schedulers_Export CORBA::Boolean operator>> (TAO_InputCDR &, Kokyu::Svc_Ctxt_DSRT_QoS &);

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1050

#if defined (__ACE_INLINE__)
#include "Kokyu_qosC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */

