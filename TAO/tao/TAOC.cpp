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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:301


#include "TAOC.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Typecode.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "TAOC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_arg_traits.cpp:59

// Arg traits specializations.
namespace TAO
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_arg_traits.cpp:428

#if !defined (_TAO_BUFFERINGCONSTRAINT__ARG_TRAITS_CS_)
#define _TAO_BUFFERINGCONSTRAINT__ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_Export Arg_Traits<TAO::BufferingConstraint>
    : public
        Fixed_Size_Arg_Traits_T<
            TAO::BufferingConstraint
          >
  {
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_TAO_BufferingConstraintMode[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  40,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x74616f2f), 
  ACE_NTOHL (0x54414f2f), 
  ACE_NTOHL (0x42756666), 
  ACE_NTOHL (0x6572696e), 
  ACE_NTOHL (0x67436f6e), 
  ACE_NTOHL (0x73747261), 
  ACE_NTOHL (0x696e744d), 
  ACE_NTOHL (0x6f64653a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:tao/TAO/BufferingConstraintMode:1.0
    24,
  ACE_NTOHL (0x42756666), 
  ACE_NTOHL (0x6572696e), 
  ACE_NTOHL (0x67436f6e), 
  ACE_NTOHL (0x73747261), 
  ACE_NTOHL (0x696e744d), 
  ACE_NTOHL (0x6f646500),  // name = BufferingConstraintMode
    CORBA::tk_ushort,

};

static CORBA::TypeCode _tc_TAO_tc_TAO_BufferingConstraintMode (
    CORBA::tk_alias,
    sizeof (_oc_TAO_BufferingConstraintMode),
    (char *) &_oc_TAO_BufferingConstraintMode,
    0,
    sizeof (TAO::BufferingConstraintMode)
  );

namespace TAO
{
  ::CORBA::TypeCode_ptr _tc_BufferingConstraintMode =
    &_tc_TAO_tc_TAO_BufferingConstraintMode;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_TAO_BufferingConstraint[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x74616f2f), 
  ACE_NTOHL (0x54414f2f), 
  ACE_NTOHL (0x42756666), 
  ACE_NTOHL (0x6572696e), 
  ACE_NTOHL (0x67436f6e), 
  ACE_NTOHL (0x73747261), 
  ACE_NTOHL (0x696e743a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:tao/TAO/BufferingConstraint:1.0
    20,
  ACE_NTOHL (0x42756666), 
  ACE_NTOHL (0x6572696e), 
  ACE_NTOHL (0x67436f6e), 
  ACE_NTOHL (0x73747261), 
  ACE_NTOHL (0x696e7400),  // name = BufferingConstraint
  4, // member count
    5,
  ACE_NTOHL (0x6d6f6465), 
  ACE_NTOHL (0x0),  // name = mode
    CORBA::tk_alias, // typecode kind for typedefs
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    40,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x74616f2f), 
    ACE_NTOHL (0x54414f2f), 
    ACE_NTOHL (0x42756666), 
    ACE_NTOHL (0x6572696e), 
    ACE_NTOHL (0x67436f6e), 
    ACE_NTOHL (0x73747261), 
    ACE_NTOHL (0x696e744d), 
    ACE_NTOHL (0x6f64653a), 
    ACE_NTOHL (0x312e3000),  // repository ID = IDL:tao/TAO/BufferingConstraintMode:1.0
        24,
    ACE_NTOHL (0x42756666), 
    ACE_NTOHL (0x6572696e), 
    ACE_NTOHL (0x67436f6e), 
    ACE_NTOHL (0x73747261), 
    ACE_NTOHL (0x696e744d), 
    ACE_NTOHL (0x6f646500),  // name = BufferingConstraintMode
        CORBA::tk_ushort,


  8,
  ACE_NTOHL (0x74696d65), 
  ACE_NTOHL (0x6f757400),  // name = timeout
    CORBA::tk_alias, // typecode kind for typedefs
  56, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    31,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x54696d65), 
    ACE_NTOHL (0x42617365), 
    ACE_NTOHL (0x2f54696d), 
    ACE_NTOHL (0x65543a31), 
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/TimeBase/TimeT:1.0
        6,
    ACE_NTOHL (0x54696d65), 
    ACE_NTOHL (0x54000000),  // name = TimeT
        CORBA::tk_ulonglong,


  14,
  ACE_NTOHL (0x6d657373), 
  ACE_NTOHL (0x6167655f), 
  ACE_NTOHL (0x636f756e), 
  ACE_NTOHL (0x74000000),  // name = message_count
    CORBA::tk_ulong,

  14,
  ACE_NTOHL (0x6d657373), 
  ACE_NTOHL (0x6167655f), 
  ACE_NTOHL (0x62797465), 
  ACE_NTOHL (0x73000000),  // name = message_bytes
    CORBA::tk_ulong,

};

static CORBA::TypeCode _tc_TAO_tc_TAO_BufferingConstraint (
    CORBA::tk_struct,
    sizeof (_oc_TAO_BufferingConstraint),
    (char *) &_oc_TAO_BufferingConstraint,
    0,
    sizeof (TAO::BufferingConstraint)
  );

namespace TAO
{
  ::CORBA::TypeCode_ptr _tc_BufferingConstraint =
    &_tc_TAO_tc_TAO_BufferingConstraint;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_cs.cpp:66

void 
TAO::BufferingConstraint::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  BufferingConstraint *_tao_tmp_pointer =
    ACE_static_cast (BufferingConstraint *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for TAO::BufferingConstraintPolicy.

TAO::BufferingConstraintPolicy_ptr
TAO::Objref_Traits<TAO::BufferingConstraintPolicy>::tao_duplicate (
    TAO::BufferingConstraintPolicy_ptr p
  )
{
  return TAO::BufferingConstraintPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<TAO::BufferingConstraintPolicy>::tao_release (
    TAO::BufferingConstraintPolicy_ptr p
  )
{
  CORBA::release (p);
}

TAO::BufferingConstraintPolicy_ptr
TAO::Objref_Traits<TAO::BufferingConstraintPolicy>::tao_nil (void)
{
  return TAO::BufferingConstraintPolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<TAO::BufferingConstraintPolicy>::tao_marshal (
    TAO::BufferingConstraintPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*TAO__TAO_BufferingConstraintPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

TAO::BufferingConstraintPolicy::BufferingConstraintPolicy (void)
{}

TAO::BufferingConstraintPolicy::~BufferingConstraintPolicy (void)
{}

void 
TAO::BufferingConstraintPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  BufferingConstraintPolicy *_tao_tmp_pointer =
    ACE_static_cast (BufferingConstraintPolicy *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return BufferingConstraintPolicy::_nil ();
    }
  
  BufferingConstraintPolicy_ptr proxy =
    dynamic_cast<BufferingConstraintPolicy_ptr> (_tao_objref);

  return BufferingConstraintPolicy::_duplicate (proxy);
}

TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy::_duplicate (BufferingConstraintPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
TAO::BufferingConstraintPolicy::_is_a (
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
          "IDL:tao/TAO/BufferingConstraintPolicy:1.0"
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

const char* TAO::BufferingConstraintPolicy::_interface_repository_id (void) const
{
  return "IDL:tao/TAO/BufferingConstraintPolicy:1.0";
}

CORBA::Boolean
TAO::BufferingConstraintPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_TAO_BufferingConstraintPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  42,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x74616f2f), 
  ACE_NTOHL (0x54414f2f), 
  ACE_NTOHL (0x42756666), 
  ACE_NTOHL (0x6572696e), 
  ACE_NTOHL (0x67436f6e), 
  ACE_NTOHL (0x73747261), 
  ACE_NTOHL (0x696e7450), 
  ACE_NTOHL (0x6f6c6963), 
  ACE_NTOHL (0x793a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:tao/TAO/BufferingConstraintPolicy:1.0
    26,
  ACE_NTOHL (0x42756666), 
  ACE_NTOHL (0x6572696e), 
  ACE_NTOHL (0x67436f6e), 
  ACE_NTOHL (0x73747261), 
  ACE_NTOHL (0x696e7450), 
  ACE_NTOHL (0x6f6c6963), 
  ACE_NTOHL (0x79000000),  // name = BufferingConstraintPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_TAO_BufferingConstraintPolicy (
    CORBA::tk_objref,
    sizeof (_oc_TAO_BufferingConstraintPolicy),
    (char *) &_oc_TAO_BufferingConstraintPolicy,
    0,
    sizeof (TAO::BufferingConstraintPolicy)
  );

namespace TAO
{
  ::CORBA::TypeCode_ptr _tc_BufferingConstraintPolicy =
    &_tc_TAO_tc_TAO_BufferingConstraintPolicy;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO::BufferingConstraint &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::BufferingConstraint>::insert_copy (
      _tao_any,
      TAO::BufferingConstraint::_tao_any_destructor,
      TAO::_tc_BufferingConstraint,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraint *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::BufferingConstraint>::insert (
      _tao_any,
      TAO::BufferingConstraint::_tao_any_destructor,
      TAO::_tc_BufferingConstraint,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO::BufferingConstraint *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const TAO::BufferingConstraint *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO::BufferingConstraint *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO::BufferingConstraint>::extract (
        _tao_any,
        TAO::BufferingConstraint::_tao_any_destructor,
        TAO::_tc_BufferingConstraint,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr _tao_elem
  )
{
  TAO::BufferingConstraintPolicy_ptr _tao_objptr =
    TAO::BufferingConstraintPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::insert (
      _tao_any,
      TAO::BufferingConstraintPolicy::_tao_any_destructor,
      TAO::_tc_BufferingConstraintPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::extract (
        _tao_any,
        TAO::BufferingConstraintPolicy::_tao_any_destructor,
        TAO::_tc_BufferingConstraintPolicy,
        _tao_elem
      );
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:1703

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

#if !defined (_TAO_BUFFERINGCONSTRAINT__ARG_TRAITS_TMPLINST_CS_)
#define _TAO_BUFFERINGCONSTRAINT__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<TAO::BufferingConstraint>;

  template class
    TAO::Fixed_Size_Arg_Traits<
        TAO::BufferingConstraint
      >;

#endif /* end #if !defined */

  template class
    TAO_Fixed_Var_T<
        TAO::BufferingConstraint
      >;

  template class
    TAO_Var_Base_T<
        TAO::BufferingConstraint
      >;

  template class
    TAO::Any_Dual_Impl_T<
        TAO::BufferingConstraint
      >;

  template class
    TAO_Objref_Var_T<
        TAO::BufferingConstraintPolicy,
        TAO::Objref_Traits<TAO::BufferingConstraintPolicy>
      >;
  
  template class
    TAO_Objref_Out_T<
        TAO::BufferingConstraintPolicy,
        TAO::Objref_Traits<TAO::BufferingConstraintPolicy>
      >;

  template class
    TAO::Any_Impl_T<
        TAO::BufferingConstraintPolicy
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

#if !defined (_TAO_BUFFERINGCONSTRAINT__ARG_TRAITS_TMPLINST_CS_)
#define _TAO_BUFFERINGCONSTRAINT__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<TAO::BufferingConstraint>

# pragma instantiate \
    TAO::Fixed_Size_Arg_Traits< \
        TAO::BufferingConstraint \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_Fixed_Var_T< \
        TAO::BufferingConstraint \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        TAO::BufferingConstraint \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TAO::BufferingConstraint \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        TAO::BufferingConstraintPolicy, \
        TAO::Objref_Traits<TAO::BufferingConstraintPolicy> \
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        TAO::BufferingConstraintPolicy, \
        TAO::Objref_Traits<TAO::BufferingConstraintPolicy> \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        TAO::BufferingConstraintPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

