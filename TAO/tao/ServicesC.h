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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_SERVICESC_H_
#define _TAO_IDL_ORIG_SERVICESC_H_

#include /**/ "ace/pre.h"

#include "tao/OctetSeqC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/CDR.h"
#include "tao/VarOut_T.h"

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

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:333
  
  typedef CORBA::UShort ServiceType;
  typedef CORBA::UShort_out ServiceType_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceType;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:333
  
  typedef CORBA::ULong ServiceOption;
  typedef CORBA::ULong_out ServiceOption_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceOption;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:333
  
  typedef CORBA::ULong ServiceDetailType;
  typedef CORBA::ULong_out ServiceDetailType_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceDetailType;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::ServiceType Security = 1U;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:258
  
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
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export ServiceDetail
  {
    typedef ServiceDetail_var _var_type;
    
    static void _tao_any_destructor (void *);
    CORBA::ServiceDetailType service_detail_type;
    CORBA::OctetSeq service_detail;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceDetail;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:258
  
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
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export ServiceInformation
  {
    typedef ServiceInformation_var _var_type;
    
    static void _tao_any_destructor (void *);
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_CORBA_SERVICEOPTION__CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_CORBA_SERVICEOPTION__CH_
    
    class TAO_Export _tao_seq_CORBA_ServiceOption_
      : public
          TAO_Unbounded_Sequence<
              ACE_NESTED_CLASS (CORBA, ServiceOption)
            >
    {
    public:
      _tao_seq_CORBA_ServiceOption_ (void);
      _tao_seq_CORBA_ServiceOption_ (CORBA::ULong max);
      _tao_seq_CORBA_ServiceOption_ (
          CORBA::ULong max,
          CORBA::ULong length,
          CORBA::ULong* buffer, 
          CORBA::Boolean release = 0
        );
      _tao_seq_CORBA_ServiceOption_ (const _tao_seq_CORBA_ServiceOption_ &);
      ~_tao_seq_CORBA_ServiceOption_ (void);
      
      static void _tao_any_destructor (void *);
      
      
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_field/field_ch.cpp:453
    
    typedef _tao_seq_CORBA_ServiceOption_ _service_options_seq;
    _tao_seq_CORBA_ServiceOption_ service_options;
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_CORBA_SERVICEDETAIL__CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_CORBA_SERVICEDETAIL__CH_
    
    class TAO_Export _tao_seq_CORBA_ServiceDetail_
      : public
          TAO_Unbounded_Sequence<
              ACE_NESTED_CLASS (CORBA, ServiceDetail)
            >
    {
    public:
      _tao_seq_CORBA_ServiceDetail_ (void);
      _tao_seq_CORBA_ServiceDetail_ (CORBA::ULong max);
      _tao_seq_CORBA_ServiceDetail_ (
          CORBA::ULong max,
          CORBA::ULong length,
          ACE_NESTED_CLASS (CORBA, ServiceDetail)* buffer, 
          CORBA::Boolean release = 0
        );
      _tao_seq_CORBA_ServiceDetail_ (const _tao_seq_CORBA_ServiceDetail_ &);
      ~_tao_seq_CORBA_ServiceDetail_ (void);
      
      static void _tao_any_destructor (void *);
      
      
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_field/field_ch.cpp:453
    
    typedef _tao_seq_CORBA_ServiceDetail_ _service_details_seq;
    _tao_seq_CORBA_ServiceDetail_ service_details;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceInformation;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::ServiceDetail &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::ServiceDetail*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceDetail *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceDetail *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::ServiceInformation &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::ServiceInformation*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceInformation *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceInformation *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ServiceDetail &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ServiceDetail &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ServiceInformation &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ServiceInformation &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__H_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_ &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_ &
  );

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__H_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_ &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_ &
  );

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:969

#if defined (__ACE_INLINE__)
#include "ServicesC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */

