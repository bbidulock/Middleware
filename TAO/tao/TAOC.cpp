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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#include "TAOC.h"


#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

#if !defined (__ACE_INLINE__)
#include "TAOC.i"
#endif /* !defined INLINE */

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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_BufferingConstraintMode, &_tc_TAO_tc_TAO_BufferingConstraintMode)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (const CORBA::UShort)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (const CORBA::UShort, BUFFER_FLUSH, 0U)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::UShort)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (const CORBA::UShort, BUFFER_TIMEOUT, 1U)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::UShort)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (const CORBA::UShort, BUFFER_MESSAGE_COUNT, 2U)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::UShort)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (const CORBA::UShort, BUFFER_MESSAGE_BYTES, 4U)
TAO_NAMESPACE_END
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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_BufferingConstraint, &_tc_TAO_tc_TAO_BufferingConstraint)
TAO_NAMESPACE_END

void TAO::BufferingConstraint::_tao_any_destructor (void *_tao_void_pointer)
{
  BufferingConstraint *tmp = ACE_static_cast (BufferingConstraint*, _tao_void_pointer);
  delete tmp;
}

TAO_NAMESPACE_TYPE (const CORBA::ULong)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (const CORBA::ULong, BUFFERING_CONSTRAINT_POLICY_TYPE, 1413545985U)
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:67

int TAO::BufferingConstraintPolicy::_tao_class_id = 0;

TAO::BufferingConstraintPolicy_ptr
tao_TAO_BufferingConstraintPolicy_duplicate (
    TAO::BufferingConstraintPolicy_ptr p
  )
{
  return TAO::BufferingConstraintPolicy::_duplicate (p);
}

void
tao_TAO_BufferingConstraintPolicy_release (
    TAO::BufferingConstraintPolicy_ptr p
  )
{
  CORBA::release (p);
}

TAO::BufferingConstraintPolicy_ptr
tao_TAO_BufferingConstraintPolicy_nil (
    void
  )
{
  return TAO::BufferingConstraintPolicy::_nil ();
}

TAO::BufferingConstraintPolicy_ptr
tao_TAO_BufferingConstraintPolicy_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return TAO::BufferingConstraintPolicy::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
tao_TAO_BufferingConstraintPolicy_upcast (
    void *src
  )
{
  TAO::BufferingConstraintPolicy **tmp =
    ACE_static_cast (TAO::BufferingConstraintPolicy **, src);
  return *tmp;
}

// *************************************************************
// TAO::BufferingConstraintPolicy_var
// TAO_IDL - Generated from
// be/be_interface.cpp:654
// *************************************************************

TAO::BufferingConstraintPolicy_var::BufferingConstraintPolicy_var (void) // default constructor
  : ptr_ (BufferingConstraintPolicy::_nil ())
{}

::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::ptr (void) const
{
  return this->ptr_;
}

TAO::BufferingConstraintPolicy_var::BufferingConstraintPolicy_var (const ::TAO::BufferingConstraintPolicy_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (BufferingConstraintPolicy::_duplicate (p.ptr ()))
{}

TAO::BufferingConstraintPolicy_var::~BufferingConstraintPolicy_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

TAO::BufferingConstraintPolicy_var &
TAO::BufferingConstraintPolicy_var::operator= (BufferingConstraintPolicy_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

TAO::BufferingConstraintPolicy_var &
TAO::BufferingConstraintPolicy_var::operator= (const ::TAO::BufferingConstraintPolicy_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::TAO::BufferingConstraintPolicy::_duplicate (p.ptr ());
  }
  return *this;
}

TAO::BufferingConstraintPolicy_var::operator const ::TAO::BufferingConstraintPolicy_ptr &() const // cast
{
  return this->ptr_;
}

TAO::BufferingConstraintPolicy_var::operator ::TAO::BufferingConstraintPolicy_ptr &() // cast
{
  return this->ptr_;
}

::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::operator-> (void) const
{
  return this->ptr_;
}

::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::in (void) const
{
  return this->ptr_;
}

::TAO::BufferingConstraintPolicy_ptr &
TAO::BufferingConstraintPolicy_var::inout (void)
{
  return this->ptr_;
}

::TAO::BufferingConstraintPolicy_ptr &
TAO::BufferingConstraintPolicy_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_nil ();
  return this->ptr_;
}

::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::TAO::BufferingConstraintPolicy_ptr val = this->ptr_;
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_nil ();
  return val;
}

::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::tao_duplicate (BufferingConstraintPolicy_ptr p)
{
  return ::TAO::BufferingConstraintPolicy::_duplicate (p);
}

void
TAO::BufferingConstraintPolicy_var::tao_release (BufferingConstraintPolicy_ptr p)
{
  CORBA::release (p);
}

::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::tao_nil (void)
{
  return ::TAO::BufferingConstraintPolicy::_nil ();
}

::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return ::TAO::BufferingConstraintPolicy::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
TAO::BufferingConstraintPolicy_var::tao_upcast (void *src)
{
  BufferingConstraintPolicy **tmp =
    ACE_static_cast (BufferingConstraintPolicy **, src);
  return *tmp;
}

// *************************************************************
// TAO::BufferingConstraintPolicy_out
// TAO_IDL - Generated from
// be/be_interface.cpp:932
// *************************************************************

TAO::BufferingConstraintPolicy_out::BufferingConstraintPolicy_out (BufferingConstraintPolicy_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_nil ();
}

TAO::BufferingConstraintPolicy_out::BufferingConstraintPolicy_out (BufferingConstraintPolicy_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_nil ();
}

TAO::BufferingConstraintPolicy_out::BufferingConstraintPolicy_out (const ::TAO::BufferingConstraintPolicy_out &p) // copy constructor
  : ptr_ (ACE_const_cast (BufferingConstraintPolicy_out &, p).ptr_)
{}

::TAO::BufferingConstraintPolicy_out &
TAO::BufferingConstraintPolicy_out::operator= (const ::TAO::BufferingConstraintPolicy_out &p)
{
  this->ptr_ = ACE_const_cast (BufferingConstraintPolicy_out&, p).ptr_;
  return *this;
}

TAO::BufferingConstraintPolicy_out &
TAO::BufferingConstraintPolicy_out::operator= (const ::TAO::BufferingConstraintPolicy_var &p)
{
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_duplicate (p.ptr ());
  return *this;
}

TAO::BufferingConstraintPolicy_out &
TAO::BufferingConstraintPolicy_out::operator= (BufferingConstraintPolicy_ptr p)
{
  this->ptr_ = p;
  return *this;
}

TAO::BufferingConstraintPolicy_out::operator ::TAO::BufferingConstraintPolicy_ptr &() // cast
{
  return this->ptr_;
}

::TAO::BufferingConstraintPolicy_ptr &
TAO::BufferingConstraintPolicy_out::ptr (void) // ptr
{
  return this->ptr_;
}

::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_out::operator-> (void)
{
  return this->ptr_;
}


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:198

TAO::BufferingConstraintPolicy::BufferingConstraintPolicy (void)
{}

TAO::BufferingConstraintPolicy::~BufferingConstraintPolicy (void)
{}

void TAO::BufferingConstraintPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  BufferingConstraintPolicy *tmp = ACE_static_cast (BufferingConstraintPolicy*, _tao_void_pointer);
  CORBA::release (tmp);
}

TAO::BufferingConstraintPolicy_ptr TAO::BufferingConstraintPolicy::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return BufferingConstraintPolicy::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    return BufferingConstraintPolicy::_nil ();
  return
      ACE_reinterpret_cast
        (
          BufferingConstraintPolicy_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &BufferingConstraintPolicy::_tao_class_id
                  )
              )
        );
}

TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy::_duplicate (BufferingConstraintPolicy_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *TAO::BufferingConstraintPolicy::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &ACE_NESTED_CLASS (::TAO, BufferingConstraintPolicy)::_tao_class_id))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &::CORBA::Policy::_tao_class_id))
    retv = ACE_reinterpret_cast
      (
        void *,
        ACE_static_cast
          (
            CORBA::Policy_ptr,
            this
          )
      );
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_tao_class_id))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* TAO::BufferingConstraintPolicy::_interface_repository_id (void) const
{
  return "IDL:tao/TAO/BufferingConstraintPolicy:1.0";
}

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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_BufferingConstraintPolicy, &_tc_TAO_tc_TAO_BufferingConstraintPolicy)
TAO_NAMESPACE_END

#endif (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (const CORBA::Short, SYNC_EAGER_BUFFERING, 0)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (const CORBA::Short, SYNC_DELAYED_BUFFERING, -2)
TAO_NAMESPACE_END

#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_cs.cpp:58

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO::BufferingConstraint &_tao_elem
  )
{
  TAO_OutputCDR stream;

  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          TAO::_tc_BufferingConstraint,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraint *_tao_elem
  )
{
  TAO_OutputCDR stream;

  if (stream << *_tao_elem)
    {
      _tao_any._tao_replace (
          TAO::_tc_BufferingConstraint,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin (),
          1,
          _tao_elem,
          TAO::BufferingConstraint::_tao_any_destructor
        );
    }
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
  _tao_elem = 0;

  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();

    CORBA::Boolean result =
      type->equivalent (
          TAO::_tc_BufferingConstraint
          ACE_ENV_ARG_PARAMETER
        );
    ACE_TRY_CHECK;

    if (result == 0)
      {
        return 0; // not equivalent
      }

    if (_tao_any.any_owns_data ())
      {
        _tao_elem = ACE_static_cast (
            const TAO::BufferingConstraint*,
            _tao_any.value ()
          );

        return 1;
      }
    else
      {
        TAO::BufferingConstraint *tmp;
        ACE_NEW_RETURN (
            tmp,
            TAO::BufferingConstraint,
            0
          );

        TAO_InputCDR stream (
            _tao_any._tao_get_cdr (),
            _tao_any._tao_byte_order ()
          );

        if (stream >> *tmp)
          {
            ((CORBA::Any *)&_tao_any)->_tao_replace (
                TAO::_tc_BufferingConstraint,
                1,
                ACE_static_cast (void *, tmp),
                TAO::BufferingConstraint::_tao_any_destructor
              );

            _tao_elem = tmp;
            return 1;
          }
        else
          {
            delete tmp;
          }
      }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;

  return 0;
}


// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:60

void operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr _tao_elem
  )
{
  _tao_any._tao_replace (
      TAO::_tc_BufferingConstraintPolicy,
      1,
      TAO::BufferingConstraintPolicy::_duplicate (_tao_elem),
      TAO::BufferingConstraintPolicy::_tao_any_destructor
    );

  _tao_any.contains_local (1);
}

void operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr *_tao_elem
  )
{
  _tao_any._tao_replace (
      TAO::_tc_BufferingConstraintPolicy,
      1,
      *_tao_elem,
      TAO::BufferingConstraintPolicy::_tao_any_destructor
    );

  _tao_any.contains_local (1);
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr &_tao_elem
  )
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = TAO::BufferingConstraintPolicy::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();

    CORBA::Boolean result =
      type->equivalent (
          TAO::_tc_BufferingConstraintPolicy
          ACE_ENV_ARG_PARAMETER
        );
    ACE_TRY_CHECK;

    if (!result)
      {
        return 0; // not equivalent
      }

    _tao_elem =
      ACE_reinterpret_cast (
          TAO::BufferingConstraintPolicy_ptr,
          ACE_const_cast (void *, _tao_any.value ())
        );

    return 1;
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;

  _tao_elem = TAO::BufferingConstraintPolicy::_nil ();
  return 0;
}

#endif  /* TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1 */
