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

#ifndef _TAO_IDL_ORIG_SERVICESC_H_
#define _TAO_IDL_ORIG_SERVICESC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#include "tao/OctetSeqC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef CORBA::UShort ServiceType;
  typedef CORBA::UShort_out ServiceType_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceType;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef CORBA::ULong ServiceOption;
  typedef CORBA::ULong_out ServiceOption_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceOption;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef CORBA::ULong ServiceDetailType;
  typedef CORBA::ULong_out ServiceDetailType_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceDetailType;
  
  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::ServiceType Security = 1U;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:258
  
  struct ServiceDetail;
  
  typedef
    TAO_Var_Var_T<
        ServiceDetail
      >
    ServiceDetail_var;
  
  typedef
    TAO_Out_T<
        ServiceDetail,
        ServiceDetail_var
      >
    ServiceDetail_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export ServiceDetail
  {
    typedef ServiceDetail_var _var_type;
    
    static void _tao_any_destructor (void *);
    CORBA::ServiceDetailType service_detail_type;
    CORBA::OctetSeq service_detail;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceDetail;
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_SERVICEOPTIONSEQ_CH_)
#define _CORBA_SERVICEOPTIONSEQ_CH_
  
  class ServiceOptionSeq;
  
  typedef
    TAO_FixedSeq_Var_T<
        ServiceOptionSeq,
        ServiceOption
      >
    ServiceOptionSeq_var;
  
  typedef
    TAO_Seq_Out_T<
        ServiceOptionSeq,
        ServiceOptionSeq_var,
        ServiceOption
      >
    ServiceOptionSeq_out;
  
  class TAO_Export ServiceOptionSeq
    : public
        TAO_Unbounded_Sequence<
            ServiceOption
          >
  {
  public:
    ServiceOptionSeq (void);
    ServiceOptionSeq (CORBA::ULong max);
    ServiceOptionSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::ULong* buffer, 
        CORBA::Boolean release = 0
      );
    ServiceOptionSeq (const ServiceOptionSeq &);
    ~ServiceOptionSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ServiceOptionSeq_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceOptionSeq;
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_SERVICEDETAILSEQ_CH_)
#define _CORBA_SERVICEDETAILSEQ_CH_
  
  class ServiceDetailSeq;
  
  typedef
    TAO_VarSeq_Var_T<
        ServiceDetailSeq,
        ServiceDetail
      >
    ServiceDetailSeq_var;
  
  typedef
    TAO_Seq_Out_T<
        ServiceDetailSeq,
        ServiceDetailSeq_var,
        ServiceDetail
      >
    ServiceDetailSeq_out;
  
  class TAO_Export ServiceDetailSeq
    : public
        TAO_Unbounded_Sequence<
            ServiceDetail
          >
  {
  public:
    ServiceDetailSeq (void);
    ServiceDetailSeq (CORBA::ULong max);
    ServiceDetailSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        ServiceDetail* buffer, 
        CORBA::Boolean release = 0
      );
    ServiceDetailSeq (const ServiceDetailSeq &);
    ~ServiceDetailSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ServiceDetailSeq_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceDetailSeq;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:258
  
  struct ServiceInformation;
  
  typedef
    TAO_Var_Var_T<
        ServiceInformation
      >
    ServiceInformation_var;
  
  typedef
    TAO_Out_T<
        ServiceInformation,
        ServiceInformation_var
      >
    ServiceInformation_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export ServiceInformation
  {
    typedef ServiceInformation_var _var_type;
    
    static void _tao_any_destructor (void *);
    CORBA::ServiceOptionSeq service_options;
    CORBA::ServiceDetailSeq service_details;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceInformation;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::ServiceDetail &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::ServiceDetail*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceDetail *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceDetail *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::ServiceOptionSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::ServiceOptionSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceOptionSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceOptionSeq *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::ServiceDetailSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::ServiceDetailSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceDetailSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceDetailSeq *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::ServiceInformation &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::ServiceInformation*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceInformation *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceInformation *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ServiceDetail &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ServiceDetail &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_ServiceOptionSeq_H_
#define _TAO_CDR_OP_CORBA_ServiceOptionSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ServiceOptionSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ServiceOptionSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ServiceOptionSeq_H_ */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_ServiceDetailSeq_H_
#define _TAO_CDR_OP_CORBA_ServiceDetailSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ServiceDetailSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ServiceDetailSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ServiceDetailSeq_H_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ServiceInformation &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ServiceInformation &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:961

#if defined (__ACE_INLINE__)
#include "ServicesC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


