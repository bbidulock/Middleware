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
// be\be_codegen.cpp:788

#ifndef _TAO_IDL_ANYTYPECODE_SERVICESA_H_
#define _TAO_IDL_ANYTYPECODE_SERVICESA_H_

#include /**/ "ace/pre.h"

#include "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/ServicesC.h"
#include "tao/AnyTypeCode/OctetSeqA.h"


// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:59

namespace CORBA
{

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceType;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceOption;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceDetailType;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceDetailData;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceOptionSeq;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceDetail;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceDetailSeq;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceInformation;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:86

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const CORBA::ServiceOptionSeq &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, CORBA::ServiceOptionSeq*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceOptionSeq *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceOptionSeq *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const CORBA::ServiceDetail &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, CORBA::ServiceDetail*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceDetail *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceDetail *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const CORBA::ServiceDetailSeq &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, CORBA::ServiceDetailSeq*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceDetailSeq *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceDetailSeq *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const CORBA::ServiceInformation &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, CORBA::ServiceInformation*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ServiceInformation *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ServiceInformation *&);

#include /**/ "ace/post.h"

#endif /* ifndef */
