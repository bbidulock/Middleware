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


#include "IORTableC.h"
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
#include "IORTableC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_cs.cpp:63

IORTable::AlreadyBound::AlreadyBound (void)
  : CORBA::UserException (
        "IDL:IORTable/AlreadyBound:1.0",
        "AlreadyBound"
      )
{
}

IORTable::AlreadyBound::~AlreadyBound (void)
{
}

IORTable::AlreadyBound::AlreadyBound (const ::IORTable::AlreadyBound &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IORTable::AlreadyBound&
IORTable::AlreadyBound::operator= (const ::IORTable::AlreadyBound &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

IORTable::AlreadyBound *
IORTable::AlreadyBound::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:IORTable/AlreadyBound:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (AlreadyBound *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *IORTable::AlreadyBound::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IORTable::AlreadyBound, 0);
  return retval;
}

CORBA::Exception *
IORTable::AlreadyBound::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::IORTable::AlreadyBound (*this),
      0
    );
  return result;
}

void IORTable::AlreadyBound::_raise (void)
{
  TAO_RAISE (*this);
}

void IORTable::AlreadyBound::_tao_encode (
    TAO_OutputCDR &cdr
    ACE_ENV_ARG_DECL
  ) const
{
  if (cdr << *this)
    {
      return;
    }

  ACE_THROW (CORBA::MARSHAL ());
}

void IORTable::AlreadyBound::_tao_decode (
    TAO_InputCDR &cdr
    ACE_ENV_ARG_DECL
  )
{
  if (cdr >> *this)
    {
      return;
    }

  ACE_THROW (CORBA::MARSHAL ());
}



// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_cs.cpp:63

IORTable::NotFound::NotFound (void)
  : CORBA::UserException (
        "IDL:IORTable/NotFound:1.0",
        "NotFound"
      )
{
}

IORTable::NotFound::~NotFound (void)
{
}

IORTable::NotFound::NotFound (const ::IORTable::NotFound &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IORTable::NotFound&
IORTable::NotFound::operator= (const ::IORTable::NotFound &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

IORTable::NotFound *
IORTable::NotFound::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:IORTable/NotFound:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (NotFound *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *IORTable::NotFound::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IORTable::NotFound, 0);
  return retval;
}

CORBA::Exception *
IORTable::NotFound::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::IORTable::NotFound (*this),
      0
    );
  return result;
}

void IORTable::NotFound::_raise (void)
{
  TAO_RAISE (*this);
}

void IORTable::NotFound::_tao_encode (
    TAO_OutputCDR &cdr
    ACE_ENV_ARG_DECL
  ) const
{
  if (cdr << *this)
    {
      return;
    }

  ACE_THROW (CORBA::MARSHAL ());
}

void IORTable::NotFound::_tao_decode (
    TAO_InputCDR &cdr
    ACE_ENV_ARG_DECL
  )
{
  if (cdr >> *this)
    {
      return;
    }

  ACE_THROW (CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:61

int IORTable::Table::_tao_class_id = 0;

IORTable::Table_ptr
tao_IORTable_Table_duplicate (
    IORTable::Table_ptr p
  )
{
  return IORTable::Table::_duplicate (p);
}

void
tao_IORTable_Table_release (
    IORTable::Table_ptr p
  )
{
  CORBA::release (p);
}

IORTable::Table_ptr
tao_IORTable_Table_nil (
    void
  )
{
  return IORTable::Table::_nil ();
}

IORTable::Table_ptr
tao_IORTable_Table_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return IORTable::Table::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
tao_IORTable_Table_upcast (
    void *src
  )
{
  IORTable::Table **tmp =
    ACE_static_cast (IORTable::Table **, src);
  return *tmp;
}

CORBA::Boolean
tao_IORTable_Table_marshal (
    IORTable::Table_ptr p,
    TAO_OutputCDR &strm
  )
{
  return p->marshal (strm);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:721

// *************************************************************
// IORTable::Table_var
// *************************************************************

IORTable::Table_var::Table_var (void)
  : ptr_ (Table::_nil ())
{}

::IORTable::Table_ptr
IORTable::Table_var::ptr (void) const
{
  return this->ptr_;
}

IORTable::Table_var::Table_var (const ::IORTable::Table_var &p)
  : TAO_Base_var (),
    ptr_ (Table::_duplicate (p.ptr ()))
{}

IORTable::Table_var::~Table_var (void)
{
  CORBA::release (this->ptr_);
}

IORTable::Table_var &
IORTable::Table_var::operator= (Table_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

IORTable::Table_var &
IORTable::Table_var::operator= (const ::IORTable::Table_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::IORTable::Table::_duplicate (p.ptr ());
  }
  return *this;
}

IORTable::Table_var::operator const ::IORTable::Table_ptr &() const // cast
{
  return this->ptr_;
}

IORTable::Table_var::operator ::IORTable::Table_ptr &() // cast
{
  return this->ptr_;
}

::IORTable::Table_ptr
IORTable::Table_var::operator-> (void) const
{
  return this->ptr_;
}

::IORTable::Table_ptr
IORTable::Table_var::in (void) const
{
  return this->ptr_;
}

::IORTable::Table_ptr &
IORTable::Table_var::inout (void)
{
  return this->ptr_;
}

::IORTable::Table_ptr &
IORTable::Table_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::IORTable::Table::_nil ();
  return this->ptr_;
}

::IORTable::Table_ptr
IORTable::Table_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::IORTable::Table_ptr val = this->ptr_;
  this->ptr_ = ::IORTable::Table::_nil ();
  return val;
}

::IORTable::Table_ptr
IORTable::Table_var::tao_duplicate (Table_ptr p)
{
  return ::IORTable::Table::_duplicate (p);
}

void
IORTable::Table_var::tao_release (Table_ptr p)
{
  CORBA::release (p);
}

::IORTable::Table_ptr
IORTable::Table_var::tao_nil (void)
{
  return ::IORTable::Table::_nil ();
}

::IORTable::Table_ptr
IORTable::Table_var::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return ::IORTable::Table::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
IORTable::Table_var::tao_upcast (void *src)
{
  Table **tmp =
    ACE_static_cast (Table **, src);
  return *tmp;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:1030

// *************************************************************
// IORTable::Table_out
// *************************************************************

IORTable::Table_out::Table_out (Table_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::IORTable::Table::_nil ();
}

IORTable::Table_out::Table_out (Table_var &p)
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::IORTable::Table::_nil ();
}

IORTable::Table_out::Table_out (const ::IORTable::Table_out &p)
  : ptr_ (ACE_const_cast (Table_out &, p).ptr_)
{}

::IORTable::Table_out &
IORTable::Table_out::operator= (const ::IORTable::Table_out &p)
{
  this->ptr_ = ACE_const_cast (Table_out&, p).ptr_;
  return *this;
}

IORTable::Table_out &
IORTable::Table_out::operator= (const ::IORTable::Table_var &p)
{
  this->ptr_ = ::IORTable::Table::_duplicate (p.ptr ());
  return *this;
}

IORTable::Table_out &
IORTable::Table_out::operator= (Table_ptr p)
{
  this->ptr_ = p;
  return *this;
}

IORTable::Table_out::operator ::IORTable::Table_ptr &() // cast
{
  return this->ptr_;
}

::IORTable::Table_ptr &
IORTable::Table_out::ptr (void)
{
  return this->ptr_;
}

::IORTable::Table_ptr
IORTable::Table_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:235

IORTable::Table::Table (void)
{}

IORTable::Table::~Table (void)
{}

IORTable::Table_ptr
IORTable::Table::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return Table::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

IORTable::Table_ptr
IORTable::Table::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return Table::_nil ();
    }
  
  return
      ACE_reinterpret_cast (
          Table_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptr_arith_t,
                  &Table::_tao_class_id
                )
            )
        );
}

IORTable::Table_ptr
IORTable::Table::_duplicate (Table_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void *IORTable::Table::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  
  if (type == ACE_reinterpret_cast (
              ptr_arith_t,
              &ACE_NESTED_CLASS (::IORTable, Table)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
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

const char* IORTable::Table::_interface_repository_id (void) const
{
  return "IDL:IORTable/Table:1.0";
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:61

int IORTable::Locator::_tao_class_id = 0;

IORTable::Locator_ptr
tao_IORTable_Locator_duplicate (
    IORTable::Locator_ptr p
  )
{
  return IORTable::Locator::_duplicate (p);
}

void
tao_IORTable_Locator_release (
    IORTable::Locator_ptr p
  )
{
  CORBA::release (p);
}

IORTable::Locator_ptr
tao_IORTable_Locator_nil (
    void
  )
{
  return IORTable::Locator::_nil ();
}

IORTable::Locator_ptr
tao_IORTable_Locator_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return IORTable::Locator::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
tao_IORTable_Locator_upcast (
    void *src
  )
{
  IORTable::Locator **tmp =
    ACE_static_cast (IORTable::Locator **, src);
  return *tmp;
}

CORBA::Boolean
tao_IORTable_Locator_marshal (
    IORTable::Locator_ptr p,
    TAO_OutputCDR &strm
  )
{
  return p->marshal (strm);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:721

// *************************************************************
// IORTable::Locator_var
// *************************************************************

IORTable::Locator_var::Locator_var (void)
  : ptr_ (Locator::_nil ())
{}

::IORTable::Locator_ptr
IORTable::Locator_var::ptr (void) const
{
  return this->ptr_;
}

IORTable::Locator_var::Locator_var (const ::IORTable::Locator_var &p)
  : TAO_Base_var (),
    ptr_ (Locator::_duplicate (p.ptr ()))
{}

IORTable::Locator_var::~Locator_var (void)
{
  CORBA::release (this->ptr_);
}

IORTable::Locator_var &
IORTable::Locator_var::operator= (Locator_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

IORTable::Locator_var &
IORTable::Locator_var::operator= (const ::IORTable::Locator_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::IORTable::Locator::_duplicate (p.ptr ());
  }
  return *this;
}

IORTable::Locator_var::operator const ::IORTable::Locator_ptr &() const // cast
{
  return this->ptr_;
}

IORTable::Locator_var::operator ::IORTable::Locator_ptr &() // cast
{
  return this->ptr_;
}

::IORTable::Locator_ptr
IORTable::Locator_var::operator-> (void) const
{
  return this->ptr_;
}

::IORTable::Locator_ptr
IORTable::Locator_var::in (void) const
{
  return this->ptr_;
}

::IORTable::Locator_ptr &
IORTable::Locator_var::inout (void)
{
  return this->ptr_;
}

::IORTable::Locator_ptr &
IORTable::Locator_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::IORTable::Locator::_nil ();
  return this->ptr_;
}

::IORTable::Locator_ptr
IORTable::Locator_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::IORTable::Locator_ptr val = this->ptr_;
  this->ptr_ = ::IORTable::Locator::_nil ();
  return val;
}

::IORTable::Locator_ptr
IORTable::Locator_var::tao_duplicate (Locator_ptr p)
{
  return ::IORTable::Locator::_duplicate (p);
}

void
IORTable::Locator_var::tao_release (Locator_ptr p)
{
  CORBA::release (p);
}

::IORTable::Locator_ptr
IORTable::Locator_var::tao_nil (void)
{
  return ::IORTable::Locator::_nil ();
}

::IORTable::Locator_ptr
IORTable::Locator_var::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return ::IORTable::Locator::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
IORTable::Locator_var::tao_upcast (void *src)
{
  Locator **tmp =
    ACE_static_cast (Locator **, src);
  return *tmp;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:1030

// *************************************************************
// IORTable::Locator_out
// *************************************************************

IORTable::Locator_out::Locator_out (Locator_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::IORTable::Locator::_nil ();
}

IORTable::Locator_out::Locator_out (Locator_var &p)
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::IORTable::Locator::_nil ();
}

IORTable::Locator_out::Locator_out (const ::IORTable::Locator_out &p)
  : ptr_ (ACE_const_cast (Locator_out &, p).ptr_)
{}

::IORTable::Locator_out &
IORTable::Locator_out::operator= (const ::IORTable::Locator_out &p)
{
  this->ptr_ = ACE_const_cast (Locator_out&, p).ptr_;
  return *this;
}

IORTable::Locator_out &
IORTable::Locator_out::operator= (const ::IORTable::Locator_var &p)
{
  this->ptr_ = ::IORTable::Locator::_duplicate (p.ptr ());
  return *this;
}

IORTable::Locator_out &
IORTable::Locator_out::operator= (Locator_ptr p)
{
  this->ptr_ = p;
  return *this;
}

IORTable::Locator_out::operator ::IORTable::Locator_ptr &() // cast
{
  return this->ptr_;
}

::IORTable::Locator_ptr &
IORTable::Locator_out::ptr (void)
{
  return this->ptr_;
}

::IORTable::Locator_ptr
IORTable::Locator_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:235
IORTable::Locator::Locator (void)
{}

IORTable::Locator::~Locator (void)
{}

IORTable::Locator_ptr
IORTable::Locator::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return Locator::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

IORTable::Locator_ptr
IORTable::Locator::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return Locator::_nil ();
    }
  
  return
      ACE_reinterpret_cast (
          Locator_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptr_arith_t,
                  &Locator::_tao_class_id
                )
            )
        );
}

IORTable::Locator_ptr
IORTable::Locator::_duplicate (Locator_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void *IORTable::Locator::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  
  if (type == ACE_reinterpret_cast (
              ptr_arith_t,
              &ACE_NESTED_CLASS (::IORTable, Locator)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
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

const char* IORTable::Locator::_interface_repository_id (void) const
{
  return "IDL:IORTable/Locator:1.0";
}
