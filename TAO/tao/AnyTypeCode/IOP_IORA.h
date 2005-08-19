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

#ifndef _TAO_IDL_ANYTYPECODE_IOP_IORA_H_
#define _TAO_IDL_ANYTYPECODE_IOP_IORA_H_

#include /**/ "ace/pre.h"

#include "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/IOP_IORC.h"
#include "tao/AnyTypeCode/OctetSeqA.h"


// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:59

namespace IOP
{

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ProfileId;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_TaggedProfile;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_TaggedProfileSeq;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_IOR;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ComponentId;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_TaggedComponent;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_MultipleComponentProfile;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_TaggedComponentList;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_TaggedComponentSeq;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceId;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceContext;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ServiceContextList;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:86

} // module IOP

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::TaggedProfile &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::TaggedProfile*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedProfile *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedProfile *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::TaggedProfileSeq &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::TaggedProfileSeq*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedProfileSeq *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedProfileSeq *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::IOR &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::IOR*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::IOR *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::IOR *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::TaggedComponent &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::TaggedComponent*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedComponent *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedComponent *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::MultipleComponentProfile &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::MultipleComponentProfile*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::MultipleComponentProfile *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::MultipleComponentProfile *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::TaggedComponentList &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::TaggedComponentList*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedComponentList *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedComponentList *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::TaggedComponentSeq &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::TaggedComponentSeq*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedComponentSeq *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedComponentSeq *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::ServiceContext &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::ServiceContext*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::ServiceContext *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::ServiceContext *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const IOP::ServiceContextList &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, IOP::ServiceContextList*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::ServiceContextList *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::ServiceContextList *&);

#include /**/ "ace/post.h"

#endif /* ifndef */
