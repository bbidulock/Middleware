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
// be/be_codegen.cpp:301


#include "TAO_ExtC.h"
#include "tao/Stub.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"
#include "tao/Basic_Arguments.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "TAO_ExtC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:59

// Arg traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for TAO::ConnectionTimeoutPolicy.

TAO::ConnectionTimeoutPolicy_ptr
TAO::Objref_Traits<TAO::ConnectionTimeoutPolicy>::tao_duplicate (
    TAO::ConnectionTimeoutPolicy_ptr p
  )
{
  return TAO::ConnectionTimeoutPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<TAO::ConnectionTimeoutPolicy>::tao_release (
    TAO::ConnectionTimeoutPolicy_ptr p
  )
{
  CORBA::release (p);
}

TAO::ConnectionTimeoutPolicy_ptr
TAO::Objref_Traits<TAO::ConnectionTimeoutPolicy>::tao_nil (void)
{
  return TAO::ConnectionTimeoutPolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<TAO::ConnectionTimeoutPolicy>::tao_marshal (
    TAO::ConnectionTimeoutPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*TAO__TAO_ConnectionTimeoutPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

TAO::ConnectionTimeoutPolicy::ConnectionTimeoutPolicy (void)
{}

TAO::ConnectionTimeoutPolicy::~ConnectionTimeoutPolicy (void)
{}

void 
TAO::ConnectionTimeoutPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  ConnectionTimeoutPolicy *_tao_tmp_pointer =
    ACE_static_cast (ConnectionTimeoutPolicy *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  ConnectionTimeoutPolicy_ptr proxy =
    dynamic_cast<ConnectionTimeoutPolicy_ptr> (_tao_objref);
  proxy->_add_ref ();
  return proxy;
}

TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy::_duplicate (ConnectionTimeoutPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
TAO::ConnectionTimeoutPolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:tao/TAO/ConnectionTimeoutPolicy:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* TAO::ConnectionTimeoutPolicy::_interface_repository_id (void) const
{
  return "IDL:tao/TAO/ConnectionTimeoutPolicy:1.0";
}

CORBA::Boolean
TAO::ConnectionTimeoutPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_TAO_ConnectionTimeoutPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  40,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x74616f2f), 
  ACE_NTOHL (0x54414f2f), 
  ACE_NTOHL (0x436f6e6e), 
  ACE_NTOHL (0x65637469), 
  ACE_NTOHL (0x6f6e5469), 
  ACE_NTOHL (0x6d656f75), 
  ACE_NTOHL (0x74506f6c), 
  ACE_NTOHL (0x6963793a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:tao/TAO/ConnectionTimeoutPolicy:1.0
    24,
  ACE_NTOHL (0x436f6e6e), 
  ACE_NTOHL (0x65637469), 
  ACE_NTOHL (0x6f6e5469), 
  ACE_NTOHL (0x6d656f75), 
  ACE_NTOHL (0x74506f6c), 
  ACE_NTOHL (0x69637900),  // name = ConnectionTimeoutPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_TAO_ConnectionTimeoutPolicy (
    CORBA::tk_objref,
    sizeof (_oc_TAO_ConnectionTimeoutPolicy),
    (char *) &_oc_TAO_ConnectionTimeoutPolicy,
    0,
    sizeof (TAO::ConnectionTimeoutPolicy)
  );

namespace TAO
{
  ::CORBA::TypeCode_ptr _tc_ConnectionTimeoutPolicy =
    &_tc_TAO_tc_TAO_ConnectionTimeoutPolicy;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO::ConnectionTimeoutPolicy_ptr _tao_elem
  )
{
  TAO::ConnectionTimeoutPolicy_ptr _tao_objptr =
    TAO::ConnectionTimeoutPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO::ConnectionTimeoutPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>::insert (
      _tao_any,
      TAO::ConnectionTimeoutPolicy::_tao_any_destructor,
      TAO::_tc_ConnectionTimeoutPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    TAO::ConnectionTimeoutPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>::extract (
        _tao_any,
        TAO::ConnectionTimeoutPolicy::_tao_any_destructor,
        TAO::_tc_ConnectionTimeoutPolicy,
        _tao_elem
      );
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1703

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Basic_Impl_T<
        CORBA::SetOverrideType
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::PolicyError
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::InvalidPolicies
      >;

  template class
    TAO_Objref_Var_T<
        TAO::ConnectionTimeoutPolicy,
        TAO::Objref_Traits<TAO::ConnectionTimeoutPolicy>
      >;
  
  template class
    TAO_Objref_Out_T<
        TAO::ConnectionTimeoutPolicy,
        TAO::Objref_Traits<TAO::ConnectionTimeoutPolicy>
      >;

  template class
    TAO::Any_Impl_T<
        TAO::ConnectionTimeoutPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        CORBA::SetOverrideType \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::PolicyError \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::InvalidPolicies \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        TAO::ConnectionTimeoutPolicy, \
        TAO::Objref_Traits<TAO::ConnectionTimeoutPolicy> \
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        TAO::ConnectionTimeoutPolicy, \
        TAO::Objref_Traits<TAO::ConnectionTimeoutPolicy> \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        TAO::ConnectionTimeoutPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

