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

#ifndef _TAO_IDL_ORIG_ULONGLONGSEQA_H_
#define _TAO_IDL_ORIG_ULONGLONGSEQA_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/ULongLongSeqC.h"

#if defined (TAO_AnyTypeCode_Export_MACRO)
#undef TAO_AnyTypeCode_Export_MACRO
#endif
#define TAO_AnyTypeCode_Export_MACRO TAO_AnyTypeCode_Export

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
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_ULongLongSeq;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const CORBA::ULongLongSeq &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, CORBA::ULongLongSeq*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::ULongLongSeq *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::ULongLongSeq *&);

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


