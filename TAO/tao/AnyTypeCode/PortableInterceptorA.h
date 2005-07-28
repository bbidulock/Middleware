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

#ifndef _TAO_IDL_ORIG_PORTABLEINTERCEPTORA_H_
#define _TAO_IDL_ORIG_PORTABLEINTERCEPTORA_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"

#include "tao/PI_ForwardC.h"
#include "tao/Messaging_SyncScopeC.h"
#include "tao/InvalidSlotC.h"
#include "tao/PICurrentC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_AnyTypeCode_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace PortableInterceptor
{

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::AdapterState HOLDING = 0;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::AdapterState ACTIVE = 1;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::AdapterState DISCARDING = 2;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::AdapterState INACTIVE = 3;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::AdapterState NON_EXISTENT = 4;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::ReplyStatus SUCCESSFUL = 0;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::ReplyStatus SYSTEM_EXCEPTION = 1;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::ReplyStatus USER_EXCEPTION = 2;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::ReplyStatus LOCATION_FORWARD = 3;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::ReplyStatus TRANSPORT_RETRY = 4;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const PortableInterceptor::ReplyStatus UNKNOWN = 5;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableInterceptor

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

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


