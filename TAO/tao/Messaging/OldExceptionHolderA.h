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
// be\be_codegen.cpp:754

#ifndef _TAO_IDL_OLDEXCEPTIONHOLDERA_H_
#define _TAO_IDL_OLDEXCEPTIONHOLDERA_H_

#include /**/ "ace/pre.h"

#include "tao/Messaging/messaging_export.h"
#include "tao/Messaging/OldExceptionHolderC.h"
#include "tao/AnyTypeCode/OctetSeqA.h"

#if defined (TAO_HAS_DEPRECATED_EXCEPTION_HOLDER)

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:59

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace Messaging
{

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_Messaging_Export ::CORBA::TypeCode_ptr const _tc_ExceptionHolder;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:86

} // module Messaging

// TAO_IDL - Generated from
// be\be_visitor_valuetype/any_op_ch.cpp:55



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Messaging
{
  TAO_Messaging_Export void operator<<= ( ::CORBA::Any &, ExceptionHolder *); // copying
  TAO_Messaging_Export void operator<<= ( ::CORBA::Any &, ExceptionHolder **); // non-copying
  TAO_Messaging_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ExceptionHolder *&);
}

#else

TAO_Messaging_Export void operator<<= (::CORBA::Any &, Messaging::ExceptionHolder *); // copying
TAO_Messaging_Export void operator<<= (::CORBA::Any &, Messaging::ExceptionHolder **); // non-copying
TAO_Messaging_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Messaging::ExceptionHolder *&);

#endif

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* */

#include /**/ "ace/post.h"

#endif /* ifndef */
