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
// be/be_codegen.cpp:302


#include "Messaging.h"
#include "tao/Object_T.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "MessagingC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:60

// Arg traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Messaging_ExceptionHolder[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  42,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x4d657373),
  ACE_NTOHL (0x6167696e),
  ACE_NTOHL (0x672f4578),
  ACE_NTOHL (0x63657074),
  ACE_NTOHL (0x696f6e48),
  ACE_NTOHL (0x6f6c6465),
  ACE_NTOHL (0x723a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/Messaging/ExceptionHolder:1.0
    16,
  ACE_NTOHL (0x45786365),
  ACE_NTOHL (0x7074696f),
  ACE_NTOHL (0x6e486f6c),
  ACE_NTOHL (0x64657200),  // name = ExceptionHolder
    0, // value modifier
  CORBA::tk_null, // no stateful base valuetype

3, // member count
    20,
  ACE_NTOHL (0x69735f73),
  ACE_NTOHL (0x79737465),
  ACE_NTOHL (0x6d5f6578),
  ACE_NTOHL (0x63657074),
  ACE_NTOHL (0x696f6e00),  // name = is_system_exception
    CORBA::tk_boolean,

  1, // data member visibility marker

  11,
  ACE_NTOHL (0x62797465),
  ACE_NTOHL (0x5f6f7264),
  ACE_NTOHL (0x65720000),  // name = byte_order
    CORBA::tk_boolean,

  1, // data member visibility marker

  20,
  ACE_NTOHL (0x6d617273),
  ACE_NTOHL (0x68616c65),
  ACE_NTOHL (0x645f6578),
  ACE_NTOHL (0x63657074),
  ACE_NTOHL (0x696f6e00),  // name = marshaled_exception
    CORBA::tk_alias, // typecode kind for typedefs
  76, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    31,
    ACE_NTOHL (0x49444c3a),
    ACE_NTOHL (0x6f6d672e),
    ACE_NTOHL (0x6f72672f),
    ACE_NTOHL (0x434f5242),
    ACE_NTOHL (0x412f4f63),
    ACE_NTOHL (0x74657453),
    ACE_NTOHL (0x65713a31),
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
        9,
    ACE_NTOHL (0x4f637465),
    ACE_NTOHL (0x74536571),
    ACE_NTOHL (0x0),  // name = OctetSeq
        CORBA::tk_sequence, // typecode kind
    12, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_octet,

      0U,


  1, // data member visibility marker

};

static CORBA::TypeCode _tc_TAO_tc_Messaging_ExceptionHolder (
    CORBA::tk_value,
    sizeof (_oc_Messaging_ExceptionHolder),
    (char *) &_oc_Messaging_ExceptionHolder,
    0,
    sizeof (Messaging::ExceptionHolder)
  );

namespace Messaging
{
  ::CORBA::TypeCode_ptr _tc_ExceptionHolder =
    &_tc_TAO_tc_Messaging_ExceptionHolder;
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/valuetype_cs.cpp:66

void
TAO::Value_Traits<Messaging::ExceptionHolder>::tao_add_ref (
    Messaging::ExceptionHolder * p
  )
{
  CORBA::add_ref (p);
}

void
TAO::Value_Traits<Messaging::ExceptionHolder>::tao_remove_ref (
    Messaging::ExceptionHolder * p
  )
{
  CORBA::remove_ref (p);
}

Messaging::ExceptionHolder *
Messaging::ExceptionHolder::_downcast (CORBA::ValueBase *v)
{
  if (v == 0)
    {
      return 0;
    }

  return dynamic_cast<Messaging::ExceptionHolder *> (v);
}

const char *
Messaging::ExceptionHolder::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}
void
Messaging::ExceptionHolder::_tao_any_destructor (void *_tao_void_pointer)
{
  ExceptionHolder *_tao_tmp_pointer =
    ACE_static_cast (
        ExceptionHolder *,
        _tao_void_pointer
      );
  CORBA::remove_ref (_tao_tmp_pointer);
}

CORBA::Boolean Messaging::ExceptionHolder::_tao_marshal_v (TAO_OutputCDR & strm)
{
  return this->_tao_marshal__Messaging_ExceptionHolder (strm);
}

CORBA::Boolean Messaging::ExceptionHolder::_tao_unmarshal_v (TAO_InputCDR & strm)
{
  return this->_tao_unmarshal__Messaging_ExceptionHolder (strm);
}

CORBA::Boolean Messaging::ExceptionHolder::_tao_unmarshal (
    TAO_InputCDR &strm,
    ExceptionHolder *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory.out (),
        base,
        ExceptionHolder::_tao_obv_static_repository_id ()
      );

  if (retval == 0)
    {
      return 0;
    }

  if (factory.in () != 0)
    {
      base = factory->create_for_unmarshal ();

      if (base == 0)
        {
          return 0;  // %! except.?
        }

      retval = base->_tao_unmarshal_v (strm);

      if (retval == 0)
        {
          return 0;
        }
    }

  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ExceptionHolder::_downcast (base);
  return retval;
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/valuetype_init_cs.cpp:85

Messaging::ExceptionHolder_init::ExceptionHolder_init (void)
{
}

Messaging::ExceptionHolder_init::~ExceptionHolder_init (void)
{
}

const char*
Messaging::ExceptionHolder_init::tao_repository_id (void)
{
  return Messaging::ExceptionHolder::_tao_obv_static_repository_id ();
}

CORBA::ValueBase *
Messaging::ExceptionHolder_init::create_for_unmarshal (void)
{
  CORBA::ValueBase *ret_val = 0;
  ACE_NEW_RETURN (
      ret_val,
      OBV_Messaging::ExceptionHolder,
      0
    );
  return ret_val;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::ReplyHandler.

Messaging::ReplyHandler_ptr
TAO::Objref_Traits<Messaging::ReplyHandler>::tao_duplicate (
    Messaging::ReplyHandler_ptr p
  )
{
  return Messaging::ReplyHandler::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::ReplyHandler>::tao_release (
    Messaging::ReplyHandler_ptr p
  )
{
  CORBA::release (p);
}

Messaging::ReplyHandler_ptr
TAO::Objref_Traits<Messaging::ReplyHandler>::tao_nil (void)
{
  return Messaging::ReplyHandler::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<Messaging::ReplyHandler>::tao_marshal (
    Messaging::ReplyHandler_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

Messaging::ReplyHandler::ReplyHandler (int collocated)
 : the_TAO_ReplyHandler_Proxy_Broker_ (0)
{
  this->Messaging_ReplyHandler_setup_collocation (collocated);
}

void
Messaging::ReplyHandler::Messaging_ReplyHandler_setup_collocation (int collocated)
{
  if (collocated)
    {
      this->the_TAO_ReplyHandler_Proxy_Broker_ =
        ::Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer (this);
    }
}

Messaging::ReplyHandler::~ReplyHandler (void)
{}

void
Messaging::ReplyHandler::_tao_any_destructor (void *_tao_void_pointer)
{
  ReplyHandler *_tao_tmp_pointer =
    ACE_static_cast (ReplyHandler *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

Messaging::ReplyHandler_ptr
Messaging::ReplyHandler::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<ReplyHandler>::narrow (
        _tao_objref,
        "IDL:omg.org/Messaging/ReplyHandler:1.0",
        Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

Messaging::ReplyHandler_ptr
Messaging::ReplyHandler::_duplicate (ReplyHandler_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
Messaging::ReplyHandler::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/Messaging/ReplyHandler:1.0"
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
      return this->ACE_NESTED_CLASS (CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

const char* Messaging::ReplyHandler::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/ReplyHandler:1.0";
}

CORBA::Boolean
Messaging::ReplyHandler::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Messaging_ReplyHandler[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  39,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x4d657373),
  ACE_NTOHL (0x6167696e),
  ACE_NTOHL (0x672f5265),
  ACE_NTOHL (0x706c7948),
  ACE_NTOHL (0x616e646c),
  ACE_NTOHL (0x65723a31),
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/Messaging/ReplyHandler:1.0
    13,
  ACE_NTOHL (0x5265706c),
  ACE_NTOHL (0x7948616e),
  ACE_NTOHL (0x646c6572),
  ACE_NTOHL (0x0),  // name = ReplyHandler
  };

static CORBA::TypeCode _tc_TAO_tc_Messaging_ReplyHandler (
    CORBA::tk_objref,
    sizeof (_oc_Messaging_ReplyHandler),
    (char *) &_oc_Messaging_ReplyHandler,
    0,
    sizeof (Messaging::ReplyHandler)
  );

namespace Messaging
{
  ::CORBA::TypeCode_ptr _tc_ReplyHandler =
    &_tc_TAO_tc_Messaging_ReplyHandler;
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/valuetype_obv_cs.cpp:58

OBV_Messaging::ExceptionHolder::ExceptionHolder (void)
{}

OBV_Messaging::ExceptionHolder::~ExceptionHolder (void)
{}

CORBA::Boolean
OBV_Messaging::ExceptionHolder::_tao_marshal__Messaging_ExceptionHolder (TAO_OutputCDR &strm)
{
  return _tao_marshal_state (strm);
}

CORBA::Boolean
OBV_Messaging::ExceptionHolder::_tao_unmarshal__Messaging_ExceptionHolder (TAO_InputCDR &strm)
{
  return _tao_unmarshal_state (strm);
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/field_cs.cpp:567

// Accessor to set the member.
void
OBV_Messaging::ExceptionHolder::is_system_exception (CORBA::Boolean val)
{
  // Set the value.
  this->_pd_is_system_exception = val;
}

// Retrieve the member
CORBA::Boolean
OBV_Messaging::ExceptionHolder::is_system_exception (void) const
{
  return this->_pd_is_system_exception;
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/field_cs.cpp:567

// Accessor to set the member.
void
OBV_Messaging::ExceptionHolder::byte_order (CORBA::Boolean val)
{
  // Set the value.
  this->_pd_byte_order = val;
}

// Retrieve the member
CORBA::Boolean
OBV_Messaging::ExceptionHolder::byte_order (void) const
{
  return this->_pd_byte_order;
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/field_cs.cpp:742

// Accessor to set the member.
void
OBV_Messaging::ExceptionHolder::marshaled_exception (const CORBA::OctetSeq &val)
{
  this->_pd_marshaled_exception = val;
}

// Readonly get method.
const CORBA::OctetSeq &
OBV_Messaging::ExceptionHolder::marshaled_exception (void) const
{
  return this->_pd_marshaled_exception;
}

// Read/write get method.
CORBA::OctetSeq &
OBV_Messaging::ExceptionHolder::marshaled_exception (void)
{
  return this->_pd_marshaled_exception;
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/any_op_cs.cpp:57



template<>
CORBA::Boolean
TAO::Any_Impl_T<Messaging::ExceptionHolder>::to_value (
    CORBA::ValueBase *&_tao_elem
  ) const
{
  CORBA::add_ref (this->value_);
  _tao_elem = this->value_;
  return 1;
}// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ExceptionHolder *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ExceptionHolder **_tao_elem
  )
{
  TAO::Any_Impl_T<Messaging::ExceptionHolder>::insert (
      _tao_any,
      Messaging::ExceptionHolder::_tao_any_destructor,
      Messaging::_tc_ExceptionHolder,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::ExceptionHolder *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<Messaging::ExceptionHolder>::extract (
        _tao_any,
        Messaging::ExceptionHolder::_tao_any_destructor,
        Messaging::_tc_ExceptionHolder,
        _tao_elem
      );
}



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<Messaging::ReplyHandler>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr _tao_elem
  )
{
  Messaging::ReplyHandler_ptr _tao_objptr =
    Messaging::ReplyHandler::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<Messaging::ReplyHandler>::insert (
      _tao_any,
      Messaging::ReplyHandler::_tao_any_destructor,
      Messaging::_tc_ReplyHandler,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::ReplyHandler_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<Messaging::ReplyHandler>::extract (
        _tao_any,
        Messaging::ReplyHandler::_tao_any_destructor,
        Messaging::_tc_ReplyHandler,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_valuetype.cpp:490

void
CORBA::add_ref (Messaging::ExceptionHolder * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (Messaging::ExceptionHolder * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/cdr_op_cs.cpp:73

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const Messaging::ExceptionHolder *_tao_valuetype
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        ACE_const_cast (
            Messaging::ExceptionHolder *,
            _tao_valuetype
          ),
        (ptrdiff_t) &Messaging::ExceptionHolder::_downcast
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    Messaging::ExceptionHolder *&_tao_valuetype
  )
{
  return Messaging::ExceptionHolder::_tao_unmarshal (strm, _tao_valuetype);
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/marshal_cs.cpp:44

CORBA::Boolean
OBV_Messaging::ExceptionHolder::_tao_marshal_state (TAO_OutputCDR &strm)
{
  if (
    (strm << CORBA::Any::from_boolean (_pd_is_system_exception)) &&
    (strm << CORBA::Any::from_boolean (_pd_byte_order)) &&
    (strm << _pd_marshaled_exception)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

CORBA::Boolean
OBV_Messaging::ExceptionHolder::_tao_unmarshal_state (TAO_InputCDR &strm)
{
  if (
    (strm >> CORBA::Any::to_boolean (_pd_is_system_exception)) &&
    (strm >> CORBA::Any::to_boolean (_pd_byte_order)) &&
    (strm >> _pd_marshaled_exception)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:63

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::ReplyHandler_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::ReplyHandler_ptr &_tao_objref
  )
{
  CORBA::Object_var obj;

  if ((strm >> obj.inout ()) == 0)
    {
      return 0;
    }

  typedef ::Messaging::ReplyHandler RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer
      );

  return 1;
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1702

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Value_Var_T<
        Messaging::ExceptionHolder

      >;

  template class
    TAO_Value_Out_T<
        Messaging::ExceptionHolder

      >;

  template class
    TAO::Any_Impl_T<
        Messaging::ExceptionHolder
      >;

  template class TAO::Objref_Traits<Messaging::ReplyHandler>;

  template class
    TAO_Objref_Var_T<
        Messaging::ReplyHandler

      >;

  template class
    TAO_Objref_Out_T<
        Messaging::ReplyHandler

      >;

  template class
    TAO::Narrow_Utils<Messaging::ReplyHandler>;

  template class
    TAO::Any_Impl_T<
        Messaging::ReplyHandler
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_Value_Var_T< \
        Messaging::ExceptionHolder \

      >

# pragma instantiate \
    TAO_Value_Out_T< \
        Messaging::ExceptionHolder \

      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        Messaging::ExceptionHolder \
      >

# pragma instantiate TAO::Objref_Traits<Messaging::ReplyHandler>

# pragma instantiate \
    TAO_Objref_Var_T< \
        Messaging::ReplyHandler

      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        Messaging::ReplyHandler

      >

# pragma instantiate \
    TAO::Narrow_Utils<Messaging::ReplyHandler>

# pragma instantiate \
    TAO::Any_Impl_T< \
        Messaging::ReplyHandler \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
