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

#include "TimeBaseC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Struct_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_TimeBase_TimeT (
    "IDL:omg.org/TimeBase/TimeT:1.0",
    "TimeT",
    &CORBA::_tc_ulonglong);
  
namespace TimeBase
{
  ::CORBA::TypeCode_ptr const _tc_TimeT =
    &_tao_tc_TimeBase_TimeT;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_TimeBase_InaccuracyT (
    "IDL:omg.org/TimeBase/InaccuracyT:1.0",
    "InaccuracyT",
    &TimeBase::_tc_TimeT);
  
namespace TimeBase
{
  ::CORBA::TypeCode_ptr const _tc_InaccuracyT =
    &_tao_tc_TimeBase_InaccuracyT;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_TimeBase_TdfT (
    "IDL:omg.org/TimeBase/TdfT:1.0",
    "TdfT",
    &CORBA::_tc_short);
  
namespace TimeBase
{
  ::CORBA::TypeCode_ptr const _tc_TdfT =
    &_tao_tc_TimeBase_TdfT;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *> _tao_fields_TimeBase_UtcT[] =
  {
    { "time", &TimeBase::_tc_TimeT },
    { "inacclo", &CORBA::_tc_ulong },
    { "inacchi", &CORBA::_tc_ushort },
    { "tdf", &TimeBase::_tc_TdfT }
    
  };
static TAO::TypeCode::Struct<char const *,
                             TAO::TypeCode::Struct_Field<char const *> const *,
                             CORBA::tk_struct,
                             TAO::Null_RefCount_Policy>
  _tao_tc_TimeBase_UtcT (
    "IDL:omg.org/TimeBase/UtcT:1.0",
    "UtcT",
    _tao_fields_TimeBase_UtcT,
    4);
  
namespace TimeBase
{
  ::CORBA::TypeCode_ptr const _tc_UtcT =
    &_tao_tc_TimeBase_UtcT;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *> _tao_fields_TimeBase_IntervalT[] =
  {
    { "lower_bound", &TimeBase::_tc_TimeT },
    { "upper_bound", &TimeBase::_tc_TimeT }
    
  };
static TAO::TypeCode::Struct<char const *,
                             TAO::TypeCode::Struct_Field<char const *> const *,
                             CORBA::tk_struct,
                             TAO::Null_RefCount_Policy>
  _tao_tc_TimeBase_IntervalT (
    "IDL:omg.org/TimeBase/IntervalT:1.0",
    "IntervalT",
    _tao_fields_TimeBase_IntervalT,
    2);
  
namespace TimeBase
{
  ::CORBA::TypeCode_ptr const _tc_IntervalT =
    &_tao_tc_TimeBase_IntervalT;
}



// TAO_IDL - Generated from 
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TimeBase::UtcT &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TimeBase::UtcT>::insert_copy (
      _tao_any,
      TimeBase::UtcT::_tao_any_destructor,
      TimeBase::_tc_UtcT,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TimeBase::UtcT *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TimeBase::UtcT>::insert (
      _tao_any,
      TimeBase::UtcT::_tao_any_destructor,
      TimeBase::_tc_UtcT,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TimeBase::UtcT *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TimeBase::UtcT *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TimeBase::UtcT *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TimeBase::UtcT>::extract (
        _tao_any,
        TimeBase::UtcT::_tao_any_destructor,
        TimeBase::_tc_UtcT,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TimeBase::IntervalT &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TimeBase::IntervalT>::insert_copy (
      _tao_any,
      TimeBase::IntervalT::_tao_any_destructor,
      TimeBase::_tc_IntervalT,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TimeBase::IntervalT *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TimeBase::IntervalT>::insert (
      _tao_any,
      TimeBase::IntervalT::_tao_any_destructor,
      TimeBase::_tc_IntervalT,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TimeBase::IntervalT *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TimeBase::IntervalT *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TimeBase::IntervalT *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TimeBase::IntervalT>::extract (
        _tao_any,
        TimeBase::IntervalT::_tao_any_destructor,
        TimeBase::_tc_IntervalT,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        TimeBase::UtcT
      >;

  template class
    TAO::Any_Dual_Impl_T<
        TimeBase::IntervalT
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TimeBase::UtcT \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TimeBase::IntervalT \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
