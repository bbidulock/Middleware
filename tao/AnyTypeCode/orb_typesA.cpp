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

#include "tao/AnyTypeCode/orb_typesA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ORBid (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ORBid:1.0",
    "ORBid",
    &CORBA::_tc_string);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ORBid =
    &_tao_tc_CORBA_ORBid;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_Flags (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/Flags:1.0",
    "Flags",
    &CORBA::_tc_ulong);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_Flags =
    &_tao_tc_CORBA_Flags;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_Identifier (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/Identifier:1.0",
    "Identifier",
    &CORBA::_tc_string);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_Identifier =
    &_tao_tc_CORBA_Identifier;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_RepositoryId (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/RepositoryId:1.0",
    "RepositoryId",
    &CORBA::_tc_string);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_RepositoryId =
    &_tao_tc_CORBA_RepositoryId;
}


TAO_END_VERSIONED_NAMESPACE_DECL
