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

#include "TypeCodeFactory_Loader.h"
#include "tao/Sequence_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "TypeCodeFactoryC.inl"
#endif /* !defined INLINE */

int CORBA_TypeCodeFactory::_tao_class_id = 0;

// *************************************************************
// Operations for class CORBA_TypeCodeFactory_var
// *************************************************************

CORBA_TypeCodeFactory_var::CORBA_TypeCodeFactory_var (void) // default constructor
  : ptr_ (CORBA_TypeCodeFactory::_nil ())
{}

::CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory_var::ptr (void) const
{
  return this->ptr_;
}

CORBA_TypeCodeFactory_var::CORBA_TypeCodeFactory_var (const ::CORBA_TypeCodeFactory_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (CORBA_TypeCodeFactory::_duplicate (p.ptr ()))
{}

CORBA_TypeCodeFactory_var::~CORBA_TypeCodeFactory_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

CORBA_TypeCodeFactory_var &
CORBA_TypeCodeFactory_var::operator= (CORBA_TypeCodeFactory_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

CORBA_TypeCodeFactory_var &
CORBA_TypeCodeFactory_var::operator= (const ::CORBA_TypeCodeFactory_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::CORBA_TypeCodeFactory::_duplicate (p.ptr ());
  }
  return *this;
}

CORBA_TypeCodeFactory_var::operator const ::CORBA_TypeCodeFactory_ptr &() const // cast
{
  return this->ptr_;
}

CORBA_TypeCodeFactory_var::operator ::CORBA_TypeCodeFactory_ptr &() // cast
{
  return this->ptr_;
}

::CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory_var::operator-> (void) const
{
  return this->ptr_;
}

::CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory_var::in (void) const
{
  return this->ptr_;
}

::CORBA_TypeCodeFactory_ptr &
CORBA_TypeCodeFactory_var::inout (void)
{
  return this->ptr_;
}

::CORBA_TypeCodeFactory_ptr &
CORBA_TypeCodeFactory_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA_TypeCodeFactory::_nil ();
  return this->ptr_;
}

::CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::CORBA_TypeCodeFactory_ptr val = this->ptr_;
  this->ptr_ = ::CORBA_TypeCodeFactory::_nil ();
  return val;
}

::CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory_var::tao_duplicate (CORBA_TypeCodeFactory_ptr p)
{
  return ::CORBA_TypeCodeFactory::_duplicate (p);
}

void
CORBA_TypeCodeFactory_var::tao_release (CORBA_TypeCodeFactory_ptr p)
{
  CORBA::release (p);
}

::CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory_var::tao_nil (void)
{
  return ::CORBA_TypeCodeFactory::_nil ();
}

::CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory_var::tao_narrow (
    CORBA::Object *p
    TAO_ENV_ARG_DECL
  )
{
  return ::CORBA_TypeCodeFactory::_narrow (p TAO_ENV_ARG_PARAMETER);
}

CORBA::Object *
CORBA_TypeCodeFactory_var::tao_upcast (void *src)
{
  CORBA_TypeCodeFactory **tmp =
    ACE_static_cast (CORBA_TypeCodeFactory **, src);
  return *tmp;
}

// *************************************************************
// Inline operations for class CORBA_TypeCodeFactory_out
// *************************************************************

CORBA_TypeCodeFactory_out::CORBA_TypeCodeFactory_out (CORBA_TypeCodeFactory_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::CORBA_TypeCodeFactory::_nil ();
}

CORBA_TypeCodeFactory_out::CORBA_TypeCodeFactory_out (CORBA_TypeCodeFactory_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::CORBA_TypeCodeFactory::_nil ();
}

CORBA_TypeCodeFactory_out::CORBA_TypeCodeFactory_out (const ::CORBA_TypeCodeFactory_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_TypeCodeFactory_out &, p).ptr_)
{}

::CORBA_TypeCodeFactory_out &
CORBA_TypeCodeFactory_out::operator= (const ::CORBA_TypeCodeFactory_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_TypeCodeFactory_out&, p).ptr_;
  return *this;
}

CORBA_TypeCodeFactory_out &
CORBA_TypeCodeFactory_out::operator= (const ::CORBA_TypeCodeFactory_var &p)
{
  this->ptr_ = ::CORBA_TypeCodeFactory::_duplicate (p.ptr ());
  return *this;
}

CORBA_TypeCodeFactory_out &
CORBA_TypeCodeFactory_out::operator= (CORBA_TypeCodeFactory_ptr p)
{
  this->ptr_ = p;
  return *this;
}

CORBA_TypeCodeFactory_out::operator ::CORBA_TypeCodeFactory_ptr &() // cast
{
  return this->ptr_;
}

::CORBA_TypeCodeFactory_ptr &
CORBA_TypeCodeFactory_out::ptr (void) // ptr
{
  return this->ptr_;
}

::CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory_out::operator-> (void)
{
  return this->ptr_;
}


// default constructor
CORBA_TypeCodeFactory::CORBA_TypeCodeFactory ()
{
  }

// destructor
CORBA_TypeCodeFactory::~CORBA_TypeCodeFactory (void)
{}

CORBA_TypeCodeFactory_ptr CORBA_TypeCodeFactory::_narrow (
    CORBA::Object_ptr obj
    TAO_ENV_ARG_DECL
  )
{
  return CORBA_TypeCodeFactory::_unchecked_narrow (obj TAO_ENV_ARG_PARAMETER);
}

CORBA_TypeCodeFactory_ptr CORBA_TypeCodeFactory::_unchecked_narrow (
    CORBA::Object_ptr obj
    TAO_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_TypeCodeFactory::_nil ();
  return
      ACE_reinterpret_cast
        (
          CORBA_TypeCodeFactory_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &CORBA_TypeCodeFactory::_tao_class_id
                  )
              )
        );
}

CORBA_TypeCodeFactory_ptr
CORBA_TypeCodeFactory::_duplicate (CORBA_TypeCodeFactory_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *CORBA_TypeCodeFactory::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &CORBA_TypeCodeFactory::_tao_class_id))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_tao_class_id))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* CORBA_TypeCodeFactory::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/TypeCodeFactory:1.0";
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
    template class TAO_Object_Manager<CORBA_TypeCodeFactory,CORBA_TypeCodeFactory_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Object_Manager<CORBA_TypeCodeFactory,CORBA_TypeCodeFactory_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

