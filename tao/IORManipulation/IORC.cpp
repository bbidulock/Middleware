/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "IORC.h"
#include "tao/Typecode.h"
#include "tao/Any.h"
#include  "tao/ORB.h"

#if !defined (__ACE_INLINE__)
#include "IORC.i"
#endif /* !defined INLINE */

// default constructor
TAO_IOP::EmptyProfileList::EmptyProfileList (void)
  : CORBA_UserException ("IDL:TAO_IOP/EmptyProfileList:1.0")
{
}

// destructor - all members are of self managing types
TAO_IOP::EmptyProfileList::~EmptyProfileList (void)
{
}

void TAO_IOP::EmptyProfileList::_tao_any_destructor (void *x)
{
  EmptyProfileList *tmp = ACE_static_cast (EmptyProfileList*,x);
  delete tmp;
}

// copy constructor
TAO_IOP::EmptyProfileList::EmptyProfileList (const ::TAO_IOP::EmptyProfileList &_tao_excp)
  : CORBA_UserException (_tao_excp._id ())
{
}

// assignment operator
TAO_IOP::EmptyProfileList&
TAO_IOP::EmptyProfileList::operator= (const ::TAO_IOP::EmptyProfileList &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::EmptyProfileList *
TAO_IOP::EmptyProfileList::_downcast (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/EmptyProfileList:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (EmptyProfileList *, exc);
  else
    return 0;
}


void TAO_IOP::EmptyProfileList::_raise ()
{
  TAO_RAISE(*this);
}


void TAO_IOP::EmptyProfileList::_tao_encode (
    TAO_OutputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  ) const
{
  if (cdr << *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}


void TAO_IOP::EmptyProfileList::_tao_decode (
    TAO_InputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (cdr >> *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::EmptyProfileList::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::TAO_IOP::EmptyProfileList, 0);
  return retval;
}

static const CORBA::Long _oc_TAO_IOP_EmptyProfileList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  33, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x456d7074), ACE_NTOHL (0x7950726f), ACE_NTOHL (0x66696c65), ACE_NTOHL (0x4c697374), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/EmptyProfileList:1.0
  17, ACE_NTOHL (0x456d7074), ACE_NTOHL (0x7950726f), ACE_NTOHL (0x66696c65), ACE_NTOHL (0x4c697374), ACE_NTOHL (0x0),  // name = EmptyProfileList
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_EmptyProfileList (CORBA::tk_except, sizeof (_oc_TAO_IOP_EmptyProfileList), (char *) &_oc_TAO_IOP_EmptyProfileList, 0, sizeof (TAO_IOP::EmptyProfileList));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_IOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_EmptyProfileList, &_tc_TAO_tc_TAO_IOP_EmptyProfileList)
TAO_NAMESPACE_END

// TAO extension - the virtual _type method
CORBA::TypeCode_ptr TAO_IOP::EmptyProfileList::_type (void) const
{
  return ::TAO_IOP::_tc_EmptyProfileList;
}

// default constructor
TAO_IOP::NotFound::NotFound (void)
  : CORBA_UserException ("IDL:TAO_IOP/NotFound:1.0")
{
}

// destructor - all members are of self managing types
TAO_IOP::NotFound::~NotFound (void)
{
}

void TAO_IOP::NotFound::_tao_any_destructor (void *x)
{
  NotFound *tmp = ACE_static_cast (NotFound*,x);
  delete tmp;
}

// copy constructor
TAO_IOP::NotFound::NotFound (const ::TAO_IOP::NotFound &_tao_excp)
  : CORBA_UserException (_tao_excp._id ())
{
}

// assignment operator
TAO_IOP::NotFound&
TAO_IOP::NotFound::operator= (const ::TAO_IOP::NotFound &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::NotFound *
TAO_IOP::NotFound::_downcast (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/NotFound:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (NotFound *, exc);
  else
    return 0;
}


void TAO_IOP::NotFound::_raise ()
{
  TAO_RAISE(*this);
}


void TAO_IOP::NotFound::_tao_encode (
    TAO_OutputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  ) const
{
  if (cdr << *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}


void TAO_IOP::NotFound::_tao_decode (
    TAO_InputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (cdr >> *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::NotFound::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::TAO_IOP::NotFound, 0);
  return retval;
}

static const CORBA::Long _oc_TAO_IOP_NotFound[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  25, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x4e6f7446), ACE_NTOHL (0x6f756e64), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/NotFound:1.0
  9, ACE_NTOHL (0x4e6f7446), ACE_NTOHL (0x6f756e64), ACE_NTOHL (0x0),  // name = NotFound
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_NotFound (CORBA::tk_except, sizeof (_oc_TAO_IOP_NotFound), (char *) &_oc_TAO_IOP_NotFound, 0, sizeof (TAO_IOP::NotFound));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_IOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_NotFound, &_tc_TAO_tc_TAO_IOP_NotFound)
TAO_NAMESPACE_END

// TAO extension - the virtual _type method
CORBA::TypeCode_ptr TAO_IOP::NotFound::_type (void) const
{
  return ::TAO_IOP::_tc_NotFound;
}

// default constructor
TAO_IOP::Duplicate::Duplicate (void)
  : CORBA_UserException ("IDL:TAO_IOP/Duplicate:1.0")
{
}

// destructor - all members are of self managing types
TAO_IOP::Duplicate::~Duplicate (void)
{
}

void TAO_IOP::Duplicate::_tao_any_destructor (void *x)
{
  Duplicate *tmp = ACE_static_cast (Duplicate*,x);
  delete tmp;
}

// copy constructor
TAO_IOP::Duplicate::Duplicate (const ::TAO_IOP::Duplicate &_tao_excp)
  : CORBA_UserException (_tao_excp._id ())
{
}

// assignment operator
TAO_IOP::Duplicate&
TAO_IOP::Duplicate::operator= (const ::TAO_IOP::Duplicate &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::Duplicate *
TAO_IOP::Duplicate::_downcast (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/Duplicate:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (Duplicate *, exc);
  else
    return 0;
}


void TAO_IOP::Duplicate::_raise ()
{
  TAO_RAISE(*this);
}


void TAO_IOP::Duplicate::_tao_encode (
    TAO_OutputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  ) const
{
  if (cdr << *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}


void TAO_IOP::Duplicate::_tao_decode (
    TAO_InputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (cdr >> *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::Duplicate::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::TAO_IOP::Duplicate, 0);
  return retval;
}

static const CORBA::Long _oc_TAO_IOP_Duplicate[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  26, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x4475706c), ACE_NTOHL (0x69636174), ACE_NTOHL (0x653a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:TAO_IOP/Duplicate:1.0
  10, ACE_NTOHL (0x4475706c), ACE_NTOHL (0x69636174), ACE_NTOHL (0x65000000),  // name = Duplicate
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_Duplicate (CORBA::tk_except, sizeof (_oc_TAO_IOP_Duplicate), (char *) &_oc_TAO_IOP_Duplicate, 0, sizeof (TAO_IOP::Duplicate));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_IOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Duplicate, &_tc_TAO_tc_TAO_IOP_Duplicate)
TAO_NAMESPACE_END

// TAO extension - the virtual _type method
CORBA::TypeCode_ptr TAO_IOP::Duplicate::_type (void) const
{
  return ::TAO_IOP::_tc_Duplicate;
}

// default constructor
TAO_IOP::Invalid_IOR::Invalid_IOR (void)
  : CORBA_UserException ("IDL:TAO_IOP/Invalid_IOR:1.0")
{
}

// destructor - all members are of self managing types
TAO_IOP::Invalid_IOR::~Invalid_IOR (void)
{
}

void TAO_IOP::Invalid_IOR::_tao_any_destructor (void *x)
{
  Invalid_IOR *tmp = ACE_static_cast (Invalid_IOR*,x);
  delete tmp;
}

// copy constructor
TAO_IOP::Invalid_IOR::Invalid_IOR (const ::TAO_IOP::Invalid_IOR &_tao_excp)
  : CORBA_UserException (_tao_excp._id ())
{
}

// assignment operator
TAO_IOP::Invalid_IOR&
TAO_IOP::Invalid_IOR::operator= (const ::TAO_IOP::Invalid_IOR &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::Invalid_IOR *
TAO_IOP::Invalid_IOR::_downcast (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/Invalid_IOR:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (Invalid_IOR *, exc);
  else
    return 0;
}


void TAO_IOP::Invalid_IOR::_raise ()
{
  TAO_RAISE(*this);
}


void TAO_IOP::Invalid_IOR::_tao_encode (
    TAO_OutputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  ) const
{
  if (cdr << *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}


void TAO_IOP::Invalid_IOR::_tao_decode (
    TAO_InputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (cdr >> *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::Invalid_IOR::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::TAO_IOP::Invalid_IOR, 0);
  return retval;
}

static const CORBA::Long _oc_TAO_IOP_Invalid_IOR[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  28, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x496e7661), ACE_NTOHL (0x6c69645f), ACE_NTOHL (0x494f523a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:TAO_IOP/Invalid_IOR:1.0
  12, ACE_NTOHL (0x496e7661), ACE_NTOHL (0x6c69645f), ACE_NTOHL (0x494f5200),  // name = Invalid_IOR
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_Invalid_IOR (CORBA::tk_except, sizeof (_oc_TAO_IOP_Invalid_IOR), (char *) &_oc_TAO_IOP_Invalid_IOR, 0, sizeof (TAO_IOP::Invalid_IOR));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_IOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Invalid_IOR, &_tc_TAO_tc_TAO_IOP_Invalid_IOR)
TAO_NAMESPACE_END

// TAO extension - the virtual _type method
CORBA::TypeCode_ptr TAO_IOP::Invalid_IOR::_type (void) const
{
  return ::TAO_IOP::_tc_Invalid_IOR;
}

// default constructor
TAO_IOP::MultiProfileList::MultiProfileList (void)
  : CORBA_UserException ("IDL:TAO_IOP/MultiProfileList:1.0")
{
}

// destructor - all members are of self managing types
TAO_IOP::MultiProfileList::~MultiProfileList (void)
{
}

void TAO_IOP::MultiProfileList::_tao_any_destructor (void *x)
{
  MultiProfileList *tmp = ACE_static_cast (MultiProfileList*,x);
  delete tmp;
}

// copy constructor
TAO_IOP::MultiProfileList::MultiProfileList (const ::TAO_IOP::MultiProfileList &_tao_excp)
  : CORBA_UserException (_tao_excp._id ())
{
}

// assignment operator
TAO_IOP::MultiProfileList&
TAO_IOP::MultiProfileList::operator= (const ::TAO_IOP::MultiProfileList &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::MultiProfileList *
TAO_IOP::MultiProfileList::_downcast (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/MultiProfileList:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (MultiProfileList *, exc);
  else
    return 0;
}


void TAO_IOP::MultiProfileList::_raise ()
{
  TAO_RAISE(*this);
}


void TAO_IOP::MultiProfileList::_tao_encode (
    TAO_OutputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  ) const
{
  if (cdr << *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}


void TAO_IOP::MultiProfileList::_tao_decode (
    TAO_InputCDR &cdr,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (cdr >> *this)
    return;
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::MultiProfileList::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::TAO_IOP::MultiProfileList, 0);
  return retval;
}

static const CORBA::Long _oc_TAO_IOP_MultiProfileList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  33, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x4d756c74), ACE_NTOHL (0x6950726f), ACE_NTOHL (0x66696c65), ACE_NTOHL (0x4c697374), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/MultiProfileList:1.0
  17, ACE_NTOHL (0x4d756c74), ACE_NTOHL (0x6950726f), ACE_NTOHL (0x66696c65), ACE_NTOHL (0x4c697374), ACE_NTOHL (0x0),  // name = MultiProfileList
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_MultiProfileList (CORBA::tk_except, sizeof (_oc_TAO_IOP_MultiProfileList), (char *) &_oc_TAO_IOP_MultiProfileList, 0, sizeof (TAO_IOP::MultiProfileList));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_IOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_MultiProfileList, &_tc_TAO_tc_TAO_IOP_MultiProfileList)
TAO_NAMESPACE_END

// TAO extension - the virtual _type method
CORBA::TypeCode_ptr TAO_IOP::MultiProfileList::_type (void) const
{
  return ::TAO_IOP::_tc_MultiProfileList;
}


// default constructor
TAO_IOP::TAO_IOR_Property::TAO_IOR_Property (void)
{}

// destructor
TAO_IOP::TAO_IOR_Property::~TAO_IOR_Property (void)
{}

TAO_IOP::TAO_IOR_Property_ptr TAO_IOP::TAO_IOR_Property::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return TAO_IOR_Property::_unchecked_narrow (obj, ACE_TRY_ENV);
}

TAO_IOP::TAO_IOR_Property_ptr TAO_IOP::TAO_IOR_Property::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return TAO_IOR_Property::_nil ();
  return
      ACE_reinterpret_cast
        (
          TAO_IOR_Property_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &TAO_IOR_Property::_narrow
                  )
              )
        );
}

TAO_IOP::TAO_IOR_Property_ptr
TAO_IOP::TAO_IOR_Property::_duplicate (TAO_IOR_Property_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *TAO_IOP::TAO_IOR_Property::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &ACE_NESTED_CLASS (::TAO_IOP, TAO_IOR_Property)::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* TAO_IOP::TAO_IOR_Property::_interface_repository_id (void) const
{
  return "IDL:TAO_IOP/TAO_IOR_Property:1.0";
}




// default constructor
TAO_IOP::TAO_IOR_Manipulation::TAO_IOR_Manipulation (void)
{}

// destructor
TAO_IOP::TAO_IOR_Manipulation::~TAO_IOR_Manipulation (void)
{}

TAO_IOP::TAO_IOR_Manipulation_ptr TAO_IOP::TAO_IOR_Manipulation::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return TAO_IOR_Manipulation::_unchecked_narrow (obj, ACE_TRY_ENV);
}

TAO_IOP::TAO_IOR_Manipulation_ptr TAO_IOP::TAO_IOR_Manipulation::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return TAO_IOR_Manipulation::_nil ();
  return
      ACE_reinterpret_cast
        (
          TAO_IOR_Manipulation_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &TAO_IOR_Manipulation::_narrow
                  )
              )
        );
}

TAO_IOP::TAO_IOR_Manipulation_ptr
TAO_IOP::TAO_IOR_Manipulation::_duplicate (TAO_IOR_Manipulation_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CS_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CS_

  // The Base_Sequence functions, please see tao/Sequence.h
  void
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_allocate_buffer (CORBA::ULong length)
  {
    CORBA::Object **tmp = 0;
    tmp = _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (length);

    if (this->buffer_ != 0)
    {
      CORBA::Object **old = ACE_reinterpret_cast (CORBA::Object**, this->buffer_);
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        if (!this->release_)
          tmp[i] = CORBA::Object::_duplicate (old[i]);
        else
          tmp[i] = old[i];

      if (this->release_)
        delete[] old;

    }
    this->buffer_ = tmp;
  }

  void
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_deallocate_buffer (void)
  {
    if (this->buffer_ == 0 || this->release_ == 0)
      return;
    CORBA::Object **tmp = ACE_reinterpret_cast (CORBA::Object**, this->buffer_);
    for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = CORBA::Object::_nil ();
    }
    _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::freebuf (tmp);
    this->buffer_ = 0;
  }

  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::~_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (void)
  {
    this->_deallocate_buffer ();
  }

  void
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_shrink_buffer (CORBA::ULong nl, CORBA::ULong ol)
  {
    CORBA::Object **tmp = ACE_reinterpret_cast (CORBA::Object**, this->buffer_);

    for (CORBA::ULong i = nl; i < ol; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = CORBA::Object::_nil ();
    }
  }
  void
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_downcast (
      void* target,
      CORBA_Object *src,
      CORBA_Environment &ACE_TRY_ENV
    )
  {
    CORBA::Object **tmp = ACE_static_cast (CORBA::Object**, target);
    *tmp = CORBA::Object::_narrow (src, ACE_TRY_ENV);
  }

  CORBA_Object*
  TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_upcast (void *src) const
  {
    CORBA::Object **tmp = ACE_static_cast (CORBA::Object**, src);
    return *tmp;
  }

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CS_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CS_

// *************************************************************
// TAO_IOP::TAO_IOR_Manipulation::IORList
// *************************************************************

TAO_IOP::TAO_IOR_Manipulation::IORList::IORList (void)
{}
TAO_IOP::TAO_IOR_Manipulation::IORList::IORList (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA::Object,CORBA::Object_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
TAO_IOP::TAO_IOR_Manipulation::IORList::IORList (CORBA::ULong max, CORBA::ULong length, CORBA::Object_ptr *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA::Object,CORBA::Object_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
TAO_IOP::TAO_IOR_Manipulation::IORList::IORList (const IORList &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA::Object,CORBA::Object_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
TAO_IOP::TAO_IOR_Manipulation::IORList::~IORList (void) // dtor
{}
void TAO_IOP::TAO_IOR_Manipulation::IORList::_tao_any_destructor (void *x)
{
  IORList *tmp = ACE_static_cast (IORList*,x);
  delete tmp;
}


#endif /* end #if !defined */

void *TAO_IOP::TAO_IOR_Manipulation::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &ACE_NESTED_CLASS (::TAO_IOP, TAO_IOR_Manipulation)::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* TAO_IOP::TAO_IOR_Manipulation::_interface_repository_id (void) const
{
  return "IDL:TAO_IOP/TAO_IOR_Manipulation:1.0";
}



void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::EmptyProfileList &_tao_elem) // copying
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_EmptyProfileList,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin ()
    );
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::EmptyProfileList *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_EmptyProfileList,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      TAO_IOP::EmptyProfileList::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::EmptyProfileList *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const TAO_IOP::EmptyProfileList*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const TAO_IOP::EmptyProfileList *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (TAO_IOP::_tc_EmptyProfileList, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::EmptyProfileList *)_tao_any.value ();
      return 1;
    }
    else
    {
      TAO_IOP::EmptyProfileList *tmp;
      ACE_NEW_RETURN (tmp, TAO_IOP::EmptyProfileList, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      CORBA::String_var interface_repository_id;
      if (!(stream >> interface_repository_id.out ()))
        return 0;
      if (ACE_OS::strcmp (
          interface_repository_id.in (),
          "IDL:TAO_IOP/EmptyProfileList:1.0"))
        return 0;
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            TAO_IOP::_tc_EmptyProfileList,
            1,
            tmp,
            TAO_IOP::EmptyProfileList::_tao_any_destructor
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

void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::NotFound &_tao_elem) // copying
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_NotFound,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin ()
    );
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::NotFound *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_NotFound,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      TAO_IOP::NotFound::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::NotFound *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const TAO_IOP::NotFound*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const TAO_IOP::NotFound *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (TAO_IOP::_tc_NotFound, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::NotFound *)_tao_any.value ();
      return 1;
    }
    else
    {
      TAO_IOP::NotFound *tmp;
      ACE_NEW_RETURN (tmp, TAO_IOP::NotFound, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      CORBA::String_var interface_repository_id;
      if (!(stream >> interface_repository_id.out ()))
        return 0;
      if (ACE_OS::strcmp (
          interface_repository_id.in (),
          "IDL:TAO_IOP/NotFound:1.0"))
        return 0;
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            TAO_IOP::_tc_NotFound,
            1,
            tmp,
            TAO_IOP::NotFound::_tao_any_destructor
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

void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::Duplicate &_tao_elem) // copying
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_Duplicate,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin ()
    );
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::Duplicate *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_Duplicate,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      TAO_IOP::Duplicate::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::Duplicate *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const TAO_IOP::Duplicate*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const TAO_IOP::Duplicate *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (TAO_IOP::_tc_Duplicate, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::Duplicate *)_tao_any.value ();
      return 1;
    }
    else
    {
      TAO_IOP::Duplicate *tmp;
      ACE_NEW_RETURN (tmp, TAO_IOP::Duplicate, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      CORBA::String_var interface_repository_id;
      if (!(stream >> interface_repository_id.out ()))
        return 0;
      if (ACE_OS::strcmp (
          interface_repository_id.in (),
          "IDL:TAO_IOP/Duplicate:1.0"))
        return 0;
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            TAO_IOP::_tc_Duplicate,
            1,
            tmp,
            TAO_IOP::Duplicate::_tao_any_destructor
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

void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::Invalid_IOR &_tao_elem) // copying
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_Invalid_IOR,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin ()
    );
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::Invalid_IOR *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_Invalid_IOR,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      TAO_IOP::Invalid_IOR::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::Invalid_IOR *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const TAO_IOP::Invalid_IOR*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const TAO_IOP::Invalid_IOR *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (TAO_IOP::_tc_Invalid_IOR, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::Invalid_IOR *)_tao_any.value ();
      return 1;
    }
    else
    {
      TAO_IOP::Invalid_IOR *tmp;
      ACE_NEW_RETURN (tmp, TAO_IOP::Invalid_IOR, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      CORBA::String_var interface_repository_id;
      if (!(stream >> interface_repository_id.out ()))
        return 0;
      if (ACE_OS::strcmp (
          interface_repository_id.in (),
          "IDL:TAO_IOP/Invalid_IOR:1.0"))
        return 0;
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            TAO_IOP::_tc_Invalid_IOR,
            1,
            tmp,
            TAO_IOP::Invalid_IOR::_tao_any_destructor
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

void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::MultiProfileList &_tao_elem) // copying
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_MultiProfileList,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin ()
    );
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::MultiProfileList *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      TAO_IOP::_tc_MultiProfileList,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      TAO_IOP::MultiProfileList::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::MultiProfileList *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const TAO_IOP::MultiProfileList*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const TAO_IOP::MultiProfileList *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (TAO_IOP::_tc_MultiProfileList, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::MultiProfileList *)_tao_any.value ();
      return 1;
    }
    else
    {
      TAO_IOP::MultiProfileList *tmp;
      ACE_NEW_RETURN (tmp, TAO_IOP::MultiProfileList, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      CORBA::String_var interface_repository_id;
      if (!(stream >> interface_repository_id.out ()))
        return 0;
      if (ACE_OS::strcmp (
          interface_repository_id.in (),
          "IDL:TAO_IOP/MultiProfileList:1.0"))
        return 0;
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            TAO_IOP::_tc_MultiProfileList,
            1,
            tmp,
            TAO_IOP::MultiProfileList::_tao_any_destructor
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

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
    template class TAO_Object_Manager<TAO_IOP::TAO_IOR_Property,TAO_IOP::TAO_IOR_Property_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Object_Manager<TAO_IOP::TAO_IOR_Property,TAO_IOP::TAO_IOR_Property_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
    template class TAO_Object_Manager<TAO_IOP::TAO_IOR_Manipulation,TAO_IOP::TAO_IOR_Manipulation_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Object_Manager<TAO_IOP::TAO_IOR_Manipulation,TAO_IOP::TAO_IOR_Manipulation_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
