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

#include "ServantRetentionPolicyC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Enum_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Basic_Impl_T.h"

#if (TAO_HAS_MINIMUM_POA == 0)

// TAO_IDL - Generated from
// be\be_visitor_typecode/enum_typecode.cpp:34

static char const * const _tao_enumerators_PortableServer_ServantRetentionPolicyValue[] =
  {
    "RETAIN",
    "NON_RETAIN"

  };

static TAO::TypeCode::Enum<char const *,
                           char const * const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_ServantRetentionPolicyValue (
    "IDL:omg.org/PortableServer/ServantRetentionPolicyValue:2.3",
    "ServantRetentionPolicyValue",
    _tao_enumerators_PortableServer_ServantRetentionPolicyValue,
    2);

namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_ServantRetentionPolicyValue =
    &_tao_tc_PortableServer_ServantRetentionPolicyValue;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_ServantRetentionPolicy (
    CORBA::tk_local_interface,
    "IDL:omg.org/PortableServer/ServantRetentionPolicy:2.3",
    "ServantRetentionPolicy");

namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_ServantRetentionPolicy =
    &_tao_tc_PortableServer_ServantRetentionPolicy;
}



// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantRetentionPolicyValue _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<PortableServer::ServantRetentionPolicyValue>::insert (
      _tao_any,
      PortableServer::_tc_ServantRetentionPolicyValue,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::ServantRetentionPolicyValue &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<PortableServer::ServantRetentionPolicyValue>::extract (
        _tao_any,
        PortableServer::_tc_ServantRetentionPolicyValue,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableServer::ServantRetentionPolicy>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableServer::ServantRetentionPolicy>::marshal_value (TAO_OutputCDR &)
  {
    return false;
  }

  template<>
  CORBA::Boolean
  Any_Impl_T<PortableServer::ServantRetentionPolicy>::demarshal_value (TAO_InputCDR &)
  {
    return false;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantRetentionPolicy_ptr _tao_elem
  )
{
  PortableServer::ServantRetentionPolicy_ptr _tao_objptr =
    PortableServer::ServantRetentionPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantRetentionPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::ServantRetentionPolicy>::insert (
      _tao_any,
      PortableServer::ServantRetentionPolicy::_tao_any_destructor,
      PortableServer::_tc_ServantRetentionPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::ServantRetentionPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::ServantRetentionPolicy>::extract (
        _tao_any,
        PortableServer::ServantRetentionPolicy::_tao_any_destructor,
        PortableServer::_tc_ServantRetentionPolicy,
        _tao_elem
      );
}

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
