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

#include "IdUniquenessPolicyC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/TypeCode_Enumerator.h"
#include "tao/Enum_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/enum_typecode.cpp:34

static TAO::TypeCode::Enumerator<char const *> const _tao_enumerators_PortableServer_IdUniquenessPolicyValue[] =
  {
    { "UNIQUE_ID" },
    { "MULTIPLE_ID" }
    
  };

static TAO::TypeCode::Enum<char const *,
                           TAO::TypeCode::Enumerator<char const *> const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_IdUniquenessPolicyValue (
    "IDL:omg.org/PortableServer/IdUniquenessPolicyValue:2.3",
    "IdUniquenessPolicyValue",
    _tao_enumerators_PortableServer_IdUniquenessPolicyValue,
    2);
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_IdUniquenessPolicyValue =
    &_tao_tc_PortableServer_IdUniquenessPolicyValue;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_IdUniquenessPolicy (
    "IDL:omg.org/PortableServer/IdUniquenessPolicy:2.3",
    "IdUniquenessPolicy");
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_IdUniquenessPolicy =
    &_tao_tc_PortableServer_IdUniquenessPolicy;
}



// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdUniquenessPolicyValue _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<PortableServer::IdUniquenessPolicyValue>::insert (
      _tao_any,
      PortableServer::_tc_IdUniquenessPolicyValue,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::IdUniquenessPolicyValue &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<PortableServer::IdUniquenessPolicyValue>::extract (
        _tao_any,
        PortableServer::_tc_IdUniquenessPolicyValue,
        _tao_elem 
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdUniquenessPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdUniquenessPolicy>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdUniquenessPolicy>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdUniquenessPolicy_ptr _tao_elem
  )
{
  PortableServer::IdUniquenessPolicy_ptr _tao_objptr =
    PortableServer::IdUniquenessPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdUniquenessPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::IdUniquenessPolicy>::insert (
      _tao_any,
      PortableServer::IdUniquenessPolicy::_tao_any_destructor,
      PortableServer::_tc_IdUniquenessPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::IdUniquenessPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::IdUniquenessPolicy>::extract (
        _tao_any,
        PortableServer::IdUniquenessPolicy::_tao_any_destructor,
        PortableServer::_tc_IdUniquenessPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Basic_Impl_T<
        PortableServer::IdUniquenessPolicyValue
      >;

  template class
    TAO::Any_Impl_T<
        PortableServer::IdUniquenessPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        PortableServer::IdUniquenessPolicyValue \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::IdUniquenessPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
