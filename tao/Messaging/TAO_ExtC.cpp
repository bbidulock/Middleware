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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "TAO_ExtC.h"
#include "tao/Stub.h"
#include "tao/Invocation.h"
#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/ClientRequestInfo_i.h"
#include "tao/ClientInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */



#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "TAO_ExtC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:61

int TAO::ConnectionTimeoutPolicy::_tao_class_id = 0;

TAO::ConnectionTimeoutPolicy_ptr
tao_TAO_ConnectionTimeoutPolicy_duplicate (
    TAO::ConnectionTimeoutPolicy_ptr p
  )
{
  return TAO::ConnectionTimeoutPolicy::_duplicate (p);
}

void
tao_TAO_ConnectionTimeoutPolicy_release (
    TAO::ConnectionTimeoutPolicy_ptr p
  )
{
  CORBA::release (p);
}

TAO::ConnectionTimeoutPolicy_ptr
tao_TAO_ConnectionTimeoutPolicy_nil (
    void
  )
{
  return TAO::ConnectionTimeoutPolicy::_nil ();
}

TAO::ConnectionTimeoutPolicy_ptr
tao_TAO_ConnectionTimeoutPolicy_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return TAO::ConnectionTimeoutPolicy::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
tao_TAO_ConnectionTimeoutPolicy_upcast (
    void *src
  )
{
  TAO::ConnectionTimeoutPolicy **tmp =
    ACE_static_cast (TAO::ConnectionTimeoutPolicy **, src);
  return *tmp;
}

CORBA::Boolean
tao_TAO_ConnectionTimeoutPolicy_marshal (
    TAO::ConnectionTimeoutPolicy_ptr p,
    TAO_OutputCDR &strm
  )
{
  return p->marshal (strm);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:721

// *************************************************************
// TAO::ConnectionTimeoutPolicy_var
// *************************************************************

TAO::ConnectionTimeoutPolicy_var::ConnectionTimeoutPolicy_var (void)
  : ptr_ (ConnectionTimeoutPolicy::_nil ())
{}

::TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy_var::ptr (void) const
{
  return this->ptr_;
}

TAO::ConnectionTimeoutPolicy_var::ConnectionTimeoutPolicy_var (const ::TAO::ConnectionTimeoutPolicy_var &p)
  : TAO_Base_var (),
    ptr_ (ConnectionTimeoutPolicy::_duplicate (p.ptr ()))
{}

TAO::ConnectionTimeoutPolicy_var::~ConnectionTimeoutPolicy_var (void)
{
  CORBA::release (this->ptr_);
}

TAO::ConnectionTimeoutPolicy_var &
TAO::ConnectionTimeoutPolicy_var::operator= (ConnectionTimeoutPolicy_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

TAO::ConnectionTimeoutPolicy_var &
TAO::ConnectionTimeoutPolicy_var::operator= (const ::TAO::ConnectionTimeoutPolicy_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::TAO::ConnectionTimeoutPolicy::_duplicate (p.ptr ());
  }
  return *this;
}

TAO::ConnectionTimeoutPolicy_var::operator const ::TAO::ConnectionTimeoutPolicy_ptr &() const // cast
{
  return this->ptr_;
}

TAO::ConnectionTimeoutPolicy_var::operator ::TAO::ConnectionTimeoutPolicy_ptr &() // cast 
{
  return this->ptr_;
}

::TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy_var::operator-> (void) const
{
  return this->ptr_;
}

::TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy_var::in (void) const
{
  return this->ptr_;
}

::TAO::ConnectionTimeoutPolicy_ptr &
TAO::ConnectionTimeoutPolicy_var::inout (void)
{
  return this->ptr_;
}

::TAO::ConnectionTimeoutPolicy_ptr &
TAO::ConnectionTimeoutPolicy_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO::ConnectionTimeoutPolicy::_nil ();
  return this->ptr_;
}

::TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::TAO::ConnectionTimeoutPolicy_ptr val = this->ptr_;
  this->ptr_ = ::TAO::ConnectionTimeoutPolicy::_nil ();
  return val;
}

::TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy_var::tao_duplicate (ConnectionTimeoutPolicy_ptr p)
{
  return ::TAO::ConnectionTimeoutPolicy::_duplicate (p);
}

void
TAO::ConnectionTimeoutPolicy_var::tao_release (ConnectionTimeoutPolicy_ptr p)
{
  CORBA::release (p);
}

::TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy_var::tao_nil (void)
{
  return ::TAO::ConnectionTimeoutPolicy::_nil ();
}

::TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy_var::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return ::TAO::ConnectionTimeoutPolicy::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
TAO::ConnectionTimeoutPolicy_var::tao_upcast (void *src)
{
  ConnectionTimeoutPolicy **tmp =
    ACE_static_cast (ConnectionTimeoutPolicy **, src);
  return *tmp;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:1030

// *************************************************************
// TAO::ConnectionTimeoutPolicy_out
// *************************************************************

TAO::ConnectionTimeoutPolicy_out::ConnectionTimeoutPolicy_out (ConnectionTimeoutPolicy_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::TAO::ConnectionTimeoutPolicy::_nil ();
}

TAO::ConnectionTimeoutPolicy_out::ConnectionTimeoutPolicy_out (ConnectionTimeoutPolicy_var &p)
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO::ConnectionTimeoutPolicy::_nil ();
}

TAO::ConnectionTimeoutPolicy_out::ConnectionTimeoutPolicy_out (const ::TAO::ConnectionTimeoutPolicy_out &p)
  : ptr_ (ACE_const_cast (ConnectionTimeoutPolicy_out &, p).ptr_)
{}

::TAO::ConnectionTimeoutPolicy_out &
TAO::ConnectionTimeoutPolicy_out::operator= (const ::TAO::ConnectionTimeoutPolicy_out &p)
{
  this->ptr_ = ACE_const_cast (ConnectionTimeoutPolicy_out&, p).ptr_;
  return *this;
}

TAO::ConnectionTimeoutPolicy_out &
TAO::ConnectionTimeoutPolicy_out::operator= (const ::TAO::ConnectionTimeoutPolicy_var &p)
{
  this->ptr_ = ::TAO::ConnectionTimeoutPolicy::_duplicate (p.ptr ());
  return *this;
}

TAO::ConnectionTimeoutPolicy_out &
TAO::ConnectionTimeoutPolicy_out::operator= (ConnectionTimeoutPolicy_ptr p)
{
  this->ptr_ = p;
  return *this;
}

TAO::ConnectionTimeoutPolicy_out::operator ::TAO::ConnectionTimeoutPolicy_ptr &() // cast
{
  return this->ptr_;
}

::TAO::ConnectionTimeoutPolicy_ptr &
TAO::ConnectionTimeoutPolicy_out::ptr (void)
{
  return this->ptr_;
}

::TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:235

TAO::ConnectionTimeoutPolicy::ConnectionTimeoutPolicy (void)
{}

TAO::ConnectionTimeoutPolicy::~ConnectionTimeoutPolicy (void)
{}

void 
TAO::ConnectionTimeoutPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  ConnectionTimeoutPolicy *tmp = ACE_static_cast (ConnectionTimeoutPolicy *, _tao_void_pointer);
  CORBA::release (tmp);
}

TAO::ConnectionTimeoutPolicy_ptr
TAO::ConnectionTimeoutPolicy::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return ConnectionTimeoutPolicy::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

TAO::ConnectionTimeoutPolicy_ptr 
TAO::ConnectionTimeoutPolicy::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return ConnectionTimeoutPolicy::_nil ();
    }
  
  return
      ACE_reinterpret_cast (
          ConnectionTimeoutPolicy_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptr_arith_t,
                  &ConnectionTimeoutPolicy::_tao_class_id
                )
            )
        );
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

void *TAO::ConnectionTimeoutPolicy::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  
  if (type == ACE_reinterpret_cast (
              ptr_arith_t,
              &ACE_NESTED_CLASS (::TAO, ConnectionTimeoutPolicy)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
              ptr_arith_t,
              &::CORBA::Policy::_tao_class_id)
            )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (
                CORBA::Policy_ptr,
                this
              )
          );
    }
  else if (type == ACE_reinterpret_cast (
               ptr_arith_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }
  
  if (retv != 0)
    {
      this->_add_ref ();
    }
  
  return retv;
}

const char* TAO::ConnectionTimeoutPolicy::_interface_repository_id (void) const
{
  return "IDL:tao/TAO/ConnectionTimeoutPolicy:1.0";
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ConnectionTimeoutPolicy,
    &_tc_TAO_tc_TAO_ConnectionTimeoutPolicy
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_cs.cpp:52

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

template<>
CORBA::Boolean
TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO_Object_Manager<TAO::ConnectionTimeoutPolicy,TAO::ConnectionTimeoutPolicy_var>;
  template class TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Object_Manager<TAO::ConnectionTimeoutPolicy, TAO::ConnectionTimeoutPolicy_var>
# pragma instantiate TAO::Any_Impl_T<TAO::ConnectionTimeoutPolicy>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

