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


#include "testC.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "testC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:59

// Arg traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for test.

test_ptr
TAO::Objref_Traits<test>::tao_duplicate (
    test_ptr p
  )
{
  return test::_duplicate (p);
}

void
TAO::Objref_Traits<test>::tao_release (
    test_ptr p
  )
{
  CORBA::release (p);
}

test_ptr
TAO::Objref_Traits<test>::tao_nil (void)
{
  return test::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<test>::tao_marshal (
    test_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*_TAO_test_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

test::test (void)
{}

test::~test (void)
{}

void 
test::_tao_any_destructor (void *_tao_void_pointer)
{
  test *_tao_tmp_pointer =
    ACE_static_cast (test *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

test_ptr
test::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return test::_nil ();
    }
  
  test_ptr proxy =
    dynamic_cast<test_ptr> (_tao_objref);
  
  return test::_duplicate (proxy);
}

test_ptr
test::_duplicate (test_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
test::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:test:1.0"
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

const char* test::_interface_repository_id (void) const
{
  return "IDL:test:1.0";
}

CORBA::Boolean
test::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_test[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  13,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x74657374), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:test:1.0
    5,
  ACE_NTOHL (0x74657374), 
  ACE_NTOHL (0x0),  // name = test
  };

static CORBA::TypeCode _tc_TAO_tc_test (
    CORBA::tk_objref,
    sizeof (_oc_test),
    (char *) &_oc_test,
    0,
    sizeof (test)
  );

::CORBA::TypeCode_ptr _tc_test =
  &_tc_TAO_tc_test;

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    test_ptr _tao_elem
  )
{
  test_ptr _tao_objptr =
    test::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    test_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<test>::insert (
      _tao_any,
      test::_tao_any_destructor,
      _tc_test,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    test_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<test>::extract (
        _tao_any,
        test::_tao_any_destructor,
        _tc_test,
        _tao_elem
      );
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<test>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<test>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<test>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

