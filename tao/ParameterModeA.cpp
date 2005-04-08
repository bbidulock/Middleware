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

#include "ParameterModeC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Enum_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/enum_typecode.cpp:34

static char const * const _tao_enumerators_CORBA_ParameterMode[] =
  {
    "PARAM_IN",
    "PARAM_OUT",
    "PARAM_INOUT"
    
  };

static TAO::TypeCode::Enum<char const *,
                           char const * const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ParameterMode (
    "IDL:omg.org/CORBA/ParameterMode:1.0",
    "ParameterMode",
    _tao_enumerators_CORBA_ParameterMode,
    3);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ParameterMode =
    &_tao_tc_CORBA_ParameterMode;
}



// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ParameterMode _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<CORBA::ParameterMode>::insert (
      _tao_any,
      CORBA::_tc_ParameterMode,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ParameterMode &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<CORBA::ParameterMode>::extract (
        _tao_any,
        CORBA::_tc_ParameterMode,
        _tao_elem 
      );
}
