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

#include "Default_ORTC.h"

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
#include "Default_ORTC.i"
#endif /* !defined INLINE */

static const CORBA::Long _oc_TAO_Default_ORT_ObjectReferenceFactory[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  47,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x54414f5f), 
  ACE_NTOHL (0x44656661), 
  ACE_NTOHL (0x756c745f), 
  ACE_NTOHL (0x4f52542f), 
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636546), 
  ACE_NTOHL (0x6163746f), 
  ACE_NTOHL (0x72793a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:TAO_Default_ORT/ObjectReferenceFactory:1.0
  23,
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636546), 
  ACE_NTOHL (0x6163746f), 
  ACE_NTOHL (0x72790000),  // name = ObjectReferenceFactory
  0, // value modifier
  CORBA::tk_null, // no stateful base valuetype

  0, // member count
};

static CORBA::TypeCode _tc_TAO_tc_TAO_Default_ORT_ObjectReferenceFactory (
    CORBA::tk_value,
    sizeof (_oc_TAO_Default_ORT_ObjectReferenceFactory),
    (char *) &_oc_TAO_Default_ORT_ObjectReferenceFactory,
    0,
    sizeof (TAO_Default_ORT::ObjectReferenceFactory)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_Default_ORT)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_ObjectReferenceFactory, &_tc_TAO_tc_TAO_Default_ORT_ObjectReferenceFactory)
TAO_NAMESPACE_END

// *************************************************************
// Operations for class TAO_Default_ORT::ObjectReferenceFactory_var
// *************************************************************

TAO_Default_ORT::ObjectReferenceFactory_var::ObjectReferenceFactory_var (void) // default constructor
  : ptr_ (0)
{}

TAO_Default_ORT::ObjectReferenceFactory_var::ObjectReferenceFactory_var (ObjectReferenceFactory* p)
  : ptr_ (p)
{}

TAO_Default_ORT::ObjectReferenceFactory_var::ObjectReferenceFactory_var (const ObjectReferenceFactory* p)
  : ptr_ (ACE_const_cast(ObjectReferenceFactory*, p))
{}

TAO_Default_ORT::ObjectReferenceFactory* 
TAO_Default_ORT::ObjectReferenceFactory_var::ptr (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory_var::ObjectReferenceFactory_var (const ObjectReferenceFactory_var &p) // copy constructor
{
  CORBA::add_ref (p.ptr ());
  this->ptr_ = p.ptr ();
}

TAO_Default_ORT::ObjectReferenceFactory_var::~ObjectReferenceFactory_var (void) // destructor
{
  CORBA::remove_ref (this->ptr_);
}

TAO_Default_ORT::ObjectReferenceFactory_var &
TAO_Default_ORT::ObjectReferenceFactory_var::operator= (ObjectReferenceFactory* p)
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = p;
  return *this;
}

TAO_Default_ORT::ObjectReferenceFactory_var &
TAO_Default_ORT::ObjectReferenceFactory_var::operator= (const ObjectReferenceFactory_var &p)
{
  if (this != &p)
  {
    CORBA::remove_ref (this->ptr_);
    ObjectReferenceFactory* tmp = p.ptr ();
    CORBA::add_ref (tmp);
    this->ptr_ = tmp;
  }
  return *this;
}

TAO_Default_ORT::ObjectReferenceFactory_var::operator const TAO_Default_ORT::ObjectReferenceFactory* () const // cast
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory_var::operator TAO_Default_ORT::ObjectReferenceFactory* () // cast 
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory* 
TAO_Default_ORT::ObjectReferenceFactory_var::operator-> (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory*
TAO_Default_ORT::ObjectReferenceFactory_var::in (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory* &
TAO_Default_ORT::ObjectReferenceFactory_var::inout (void)
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory* &
TAO_Default_ORT::ObjectReferenceFactory_var::out (void)
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = 0;
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory* 
TAO_Default_ORT::ObjectReferenceFactory_var::_retn (void)
{
  // yield ownership of managed obj reference
  ObjectReferenceFactory* tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

// *************************************************************
// Operations for class TAO_Default_ORT::ObjectReferenceFactory_out
// *************************************************************

TAO_Default_ORT::ObjectReferenceFactory_out::ObjectReferenceFactory_out (ObjectReferenceFactory* &p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

TAO_Default_ORT::ObjectReferenceFactory_out::ObjectReferenceFactory_out (ObjectReferenceFactory_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = 0;
}

TAO_Default_ORT::ObjectReferenceFactory_out::ObjectReferenceFactory_out (const ObjectReferenceFactory_out &p) // copy constructor
  : ptr_ (ACE_const_cast (ObjectReferenceFactory_out&,p).ptr_)
{}

TAO_Default_ORT::ObjectReferenceFactory_out &
TAO_Default_ORT::ObjectReferenceFactory_out::operator= (const ObjectReferenceFactory_out &p)
{
  this->ptr_ = ACE_const_cast (ObjectReferenceFactory_out&,p).ptr_;
  return *this;
}

TAO_Default_ORT::ObjectReferenceFactory_out &
TAO_Default_ORT::ObjectReferenceFactory_out::operator= (const ObjectReferenceFactory_var &p)
{
  ObjectReferenceFactory* tmp = p.ptr ();
  CORBA::add_ref (tmp);
  this->ptr_ = tmp;
  return *this;
}

TAO_Default_ORT::ObjectReferenceFactory_out &
TAO_Default_ORT::ObjectReferenceFactory_out::operator= (ObjectReferenceFactory* p)
{
  this->ptr_ = p;
  return *this;
}

TAO_Default_ORT::ObjectReferenceFactory_out::operator TAO_Default_ORT::ObjectReferenceFactory* &() // cast
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory* &
TAO_Default_ORT::ObjectReferenceFactory_out::ptr (void) // ptr
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory* 
TAO_Default_ORT::ObjectReferenceFactory_out::operator-> (void)
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceFactory* TAO_Default_ORT::ObjectReferenceFactory::_downcast (CORBA::ValueBase* v)
{
  if (v == 0) return 0;
  return (ObjectReferenceFactory* ) v->_tao_obv_narrow ((ptr_arith_t) &_downcast);
}

const char* TAO_Default_ORT::ObjectReferenceFactory::_tao_obv_repository_id () const
{
  return this->_tao_obv_static_repository_id ();
}

void* TAO_Default_ORT::ObjectReferenceFactory::_tao_obv_narrow (ptr_arith_t type_id)
{
  if (type_id == (ptr_arith_t) &_downcast)
    return this;
  void *rval = 0;
  if (rval == 0)
    rval = ACE_NESTED_CLASS (PortableInterceptor,ObjectReferenceFactory)::_tao_obv_narrow (type_id);
  return rval;
}

void
TAO_Default_ORT::ObjectReferenceFactory::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceFactory *tmp = ACE_static_cast (ObjectReferenceFactory*, _tao_void_pointer);
  delete tmp;
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceFactory::_tao_marshal_v (TAO_OutputCDR & strm)
{
  return this->_tao_marshal__TAO_Default_ORT_ObjectReferenceFactory (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceFactory::_tao_unmarshal_v (TAO_InputCDR & strm)
{
  return this->_tao_unmarshal__TAO_Default_ORT_ObjectReferenceFactory (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceFactory::_tao_unmarshal (TAO_InputCDR &strm, ObjectReferenceFactory *&new_object)
{
  CORBA::Boolean retval = 1;
  CORBA::ValueBase *base;   // %! should be a _var
  CORBA::ValueFactory_ptr factory;   // %! should be a _var
  if (!CORBA::ValueBase::_tao_unmarshal_pre (strm, factory, base,
          ObjectReferenceFactory::_tao_obv_static_repository_id ()) )
    {
      return 0;
    }
  if (factory != 0)
    {
      base = factory->create_for_unmarshal ();
      factory->_remove_ref ();
      if (base == 0)  return 0;  // %! except.?
      //%! ACE_DEBUG ((LM_DEBUG, "TAO_Default_ORT::ObjectReferenceFactory::_tao_unmarshal %s\n", base->_tao_obv_repository_id () ));
      retval = base->_tao_unmarshal_v (strm);
      //%! ACE_DEBUG ((LM_DEBUG, "TAO_Default_ORT::ObjectReferenceFactory::_tao_unmarshal retval unmarshal_v is %d\n", retval));
      if (!retval) return 0;
    }
  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ObjectReferenceFactory::_downcast (base);
  // %! unmarshal_post
  return 1;
}

static const CORBA::Long _oc_TAO_Default_ORT_ObjectReferenceTemplate[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  48,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x54414f5f), 
  ACE_NTOHL (0x44656661), 
  ACE_NTOHL (0x756c745f), 
  ACE_NTOHL (0x4f52542f), 
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636554), 
  ACE_NTOHL (0x656d706c), 
  ACE_NTOHL (0x6174653a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:TAO_Default_ORT/ObjectReferenceTemplate:1.0
  24,
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636554), 
  ACE_NTOHL (0x656d706c), 
  ACE_NTOHL (0x61746500),  // name = ObjectReferenceTemplate
  0, // value modifier
  CORBA::tk_null, // no stateful base valuetype

  0, // member count
};

static CORBA::TypeCode _tc_TAO_tc_TAO_Default_ORT_ObjectReferenceTemplate (
    CORBA::tk_value,
    sizeof (_oc_TAO_Default_ORT_ObjectReferenceTemplate),
    (char *) &_oc_TAO_Default_ORT_ObjectReferenceTemplate,
    0,
    sizeof (TAO_Default_ORT::ObjectReferenceTemplate)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_Default_ORT)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_ObjectReferenceTemplate, &_tc_TAO_tc_TAO_Default_ORT_ObjectReferenceTemplate)
TAO_NAMESPACE_END

// *************************************************************
// Operations for class TAO_Default_ORT::ObjectReferenceTemplate_var
// *************************************************************

TAO_Default_ORT::ObjectReferenceTemplate_var::ObjectReferenceTemplate_var (void) // default constructor
  : ptr_ (0)
{}

TAO_Default_ORT::ObjectReferenceTemplate_var::ObjectReferenceTemplate_var (ObjectReferenceTemplate* p)
  : ptr_ (p)
{}

TAO_Default_ORT::ObjectReferenceTemplate_var::ObjectReferenceTemplate_var (const ObjectReferenceTemplate* p)
  : ptr_ (ACE_const_cast(ObjectReferenceTemplate*, p))
{}

TAO_Default_ORT::ObjectReferenceTemplate* 
TAO_Default_ORT::ObjectReferenceTemplate_var::ptr (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate_var::ObjectReferenceTemplate_var (const ObjectReferenceTemplate_var &p) // copy constructor
{
  CORBA::add_ref (p.ptr ());
  this->ptr_ = p.ptr ();
}

TAO_Default_ORT::ObjectReferenceTemplate_var::~ObjectReferenceTemplate_var (void) // destructor
{
  CORBA::remove_ref (this->ptr_);
}

TAO_Default_ORT::ObjectReferenceTemplate_var &
TAO_Default_ORT::ObjectReferenceTemplate_var::operator= (ObjectReferenceTemplate* p)
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = p;
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_var &
TAO_Default_ORT::ObjectReferenceTemplate_var::operator= (const ObjectReferenceTemplate_var &p)
{
  if (this != &p)
  {
    CORBA::remove_ref (this->ptr_);
    ObjectReferenceTemplate* tmp = p.ptr ();
    CORBA::add_ref (tmp);
    this->ptr_ = tmp;
  }
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_var::operator const TAO_Default_ORT::ObjectReferenceTemplate* () const // cast
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate_var::operator TAO_Default_ORT::ObjectReferenceTemplate* () // cast 
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate* 
TAO_Default_ORT::ObjectReferenceTemplate_var::operator-> (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate*
TAO_Default_ORT::ObjectReferenceTemplate_var::in (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate* &
TAO_Default_ORT::ObjectReferenceTemplate_var::inout (void)
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate* &
TAO_Default_ORT::ObjectReferenceTemplate_var::out (void)
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = 0;
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate* 
TAO_Default_ORT::ObjectReferenceTemplate_var::_retn (void)
{
  // yield ownership of managed obj reference
  ObjectReferenceTemplate* tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

// *************************************************************
// Operations for class TAO_Default_ORT::ObjectReferenceTemplate_out
// *************************************************************

TAO_Default_ORT::ObjectReferenceTemplate_out::ObjectReferenceTemplate_out (ObjectReferenceTemplate* &p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

TAO_Default_ORT::ObjectReferenceTemplate_out::ObjectReferenceTemplate_out (ObjectReferenceTemplate_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = 0;
}

TAO_Default_ORT::ObjectReferenceTemplate_out::ObjectReferenceTemplate_out (const ObjectReferenceTemplate_out &p) // copy constructor
  : ptr_ (ACE_const_cast (ObjectReferenceTemplate_out&,p).ptr_)
{}

TAO_Default_ORT::ObjectReferenceTemplate_out &
TAO_Default_ORT::ObjectReferenceTemplate_out::operator= (const ObjectReferenceTemplate_out &p)
{
  this->ptr_ = ACE_const_cast (ObjectReferenceTemplate_out&,p).ptr_;
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_out &
TAO_Default_ORT::ObjectReferenceTemplate_out::operator= (const ObjectReferenceTemplate_var &p)
{
  ObjectReferenceTemplate* tmp = p.ptr ();
  CORBA::add_ref (tmp);
  this->ptr_ = tmp;
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_out &
TAO_Default_ORT::ObjectReferenceTemplate_out::operator= (ObjectReferenceTemplate* p)
{
  this->ptr_ = p;
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_out::operator TAO_Default_ORT::ObjectReferenceTemplate* &() // cast
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate* &
TAO_Default_ORT::ObjectReferenceTemplate_out::ptr (void) // ptr
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate* 
TAO_Default_ORT::ObjectReferenceTemplate_out::operator-> (void)
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate* TAO_Default_ORT::ObjectReferenceTemplate::_downcast (CORBA::ValueBase* v)
{
  if (v == 0) return 0;
  return (ObjectReferenceTemplate* ) v->_tao_obv_narrow ((ptr_arith_t) &_downcast);
}

const char* TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_repository_id () const
{
  return this->_tao_obv_static_repository_id ();
}

void* TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_narrow (ptr_arith_t type_id)
{
  if (type_id == (ptr_arith_t) &_downcast)
    return this;
  void *rval = 0;
  if (rval == 0)
    rval = ACE_NESTED_CLASS (PortableInterceptor,ObjectReferenceTemplate)::_tao_obv_narrow (type_id);
  return rval;
}

void
TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceTemplate *tmp = ACE_static_cast (ObjectReferenceTemplate*, _tao_void_pointer);
  delete tmp;
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal_v (TAO_OutputCDR & strm)
{
  return this->_tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal_v (TAO_InputCDR & strm)
{
  return this->_tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal (TAO_InputCDR &strm, ObjectReferenceTemplate *&new_object)
{
  CORBA::Boolean retval = 1;
  CORBA::ValueBase *base;   // %! should be a _var
  CORBA::ValueFactory_ptr factory;   // %! should be a _var
  if (!CORBA::ValueBase::_tao_unmarshal_pre (strm, factory, base,
          ObjectReferenceTemplate::_tao_obv_static_repository_id ()) )
    {
      return 0;
    }
  if (factory != 0)
    {
      base = factory->create_for_unmarshal ();
      factory->_remove_ref ();
      if (base == 0)  return 0;  // %! except.?
      //%! ACE_DEBUG ((LM_DEBUG, "TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal %s\n", base->_tao_obv_repository_id () ));
      retval = base->_tao_unmarshal_v (strm);
      //%! ACE_DEBUG ((LM_DEBUG, "TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal retval unmarshal_v is %d\n", retval));
      if (!retval) return 0;
    }
  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ObjectReferenceTemplate::_downcast (base);
  // %! unmarshal_post
  return 1;
}

CORBA::Boolean 
OBV_TAO_Default_ORT::ObjectReferenceFactory::_tao_marshal__TAO_Default_ORT_ObjectReferenceFactory (TAO_OutputCDR &strm){
  return _tao_marshal_state (strm);
  
}
CORBA::Boolean OBV_TAO_Default_ORT::ObjectReferenceFactory::_tao_unmarshal__TAO_Default_ORT_ObjectReferenceFactory (TAO_InputCDR &strm){
  return _tao_unmarshal_state (strm);
  
}
CORBA::Boolean 
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_OutputCDR &strm){
  return _tao_marshal_state (strm);
  
}
CORBA::Boolean OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_InputCDR &strm){
  return _tao_unmarshal_state (strm);
  
}
TAO_PortableServer_Export void
operator<<= (CORBA::Any &any, TAO_Default_ORT::ObjectReferenceFactory *value) // copying
{
  TAO_OutputCDR stream;
  if (stream << value)
  {
    any._tao_replace (
        TAO_Default_ORT::_tc_ObjectReferenceFactory, 
        TAO_ENCAP_BYTE_ORDER,
        stream.begin ());
  }
}

TAO_PortableServer_Export void
operator<<= (CORBA::Any &any, TAO_Default_ORT::ObjectReferenceFactory **value) // non-copying
{
  TAO_OutputCDR stream;
  if (stream << *value)
  {
    any._tao_replace (
        TAO_Default_ORT::_tc_ObjectReferenceFactory, 
        TAO_ENCAP_BYTE_ORDER,
        stream.begin (),
        1,
        *value,
        TAO_Default_ORT::ObjectReferenceFactory::_tao_any_destructor);
  }
}

TAO_PortableServer_Export CORBA::Boolean
operator>>= (const CORBA::Any &any, TAO_Default_ORT::ObjectReferenceFactory *&value)
{
  ACE_TRY_NEW_ENV
  {
    value = 0;
    CORBA::TypeCode_var type = any.type ();
    
    CORBA::Boolean result = type->equivalent (TAO_Default_ORT::_tc_ObjectReferenceFactory ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;
    
    if (!result)
    {
      return 0; // not equivalent
    }
    if (any.any_owns_data ())
    {
      const TAO_Default_ORT::ObjectReferenceFactory *const_holder = ACE_static_cast (
          const TAO_Default_ORT::ObjectReferenceFactory*,
          any.value ());
      value = ACE_const_cast (
          TAO_Default_ORT::ObjectReferenceFactory*,
          const_holder);
      return 1;
    }
    else
    {
      TAO_Default_ORT::ObjectReferenceFactory *tmp;
      TAO_InputCDR stream (
          any._tao_get_cdr (),
          any._tao_byte_order ());
      if (stream >> tmp)
      {
        ((CORBA::Any *)&any)->_tao_replace (
            TAO_Default_ORT::_tc_ObjectReferenceFactory,
            1,
            ACE_static_cast (void *, tmp),
            TAO_Default_ORT::ObjectReferenceFactory::_tao_any_destructor);
        value = tmp;
        return 1;
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
    template class TAO_Valuetype_Manager<TAO_Default_ORT::ObjectReferenceFactory, TAO_Default_ORT::ObjectReferenceFactory_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Valuetype_Manager<TAO_Default_ORT::ObjectReferenceFactory, TAO_Default_ORT::ObjectReferenceFactory_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

TAO_PortableServer_Export void
operator<<= (CORBA::Any &any, TAO_Default_ORT::ObjectReferenceTemplate *value) // copying
{
  TAO_OutputCDR stream;
  if (stream << value)
  {
    any._tao_replace (
        TAO_Default_ORT::_tc_ObjectReferenceTemplate, 
        TAO_ENCAP_BYTE_ORDER,
        stream.begin ());
  }
}

TAO_PortableServer_Export void
operator<<= (CORBA::Any &any, TAO_Default_ORT::ObjectReferenceTemplate **value) // non-copying
{
  TAO_OutputCDR stream;
  if (stream << *value)
  {
    any._tao_replace (
        TAO_Default_ORT::_tc_ObjectReferenceTemplate, 
        TAO_ENCAP_BYTE_ORDER,
        stream.begin (),
        1,
        *value,
        TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor);
  }
}

TAO_PortableServer_Export CORBA::Boolean
operator>>= (const CORBA::Any &any, TAO_Default_ORT::ObjectReferenceTemplate *&value)
{
  ACE_TRY_NEW_ENV
  {
    value = 0;
    CORBA::TypeCode_var type = any.type ();
    
    CORBA::Boolean result = type->equivalent (TAO_Default_ORT::_tc_ObjectReferenceTemplate ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;
    
    if (!result)
    {
      return 0; // not equivalent
    }
    if (any.any_owns_data ())
    {
      const TAO_Default_ORT::ObjectReferenceTemplate *const_holder = ACE_static_cast (
          const TAO_Default_ORT::ObjectReferenceTemplate*,
          any.value ());
      value = ACE_const_cast (
          TAO_Default_ORT::ObjectReferenceTemplate*,
          const_holder);
      return 1;
    }
    else
    {
      TAO_Default_ORT::ObjectReferenceTemplate *tmp;
      TAO_InputCDR stream (
          any._tao_get_cdr (),
          any._tao_byte_order ());
      if (stream >> tmp)
      {
        ((CORBA::Any *)&any)->_tao_replace (
            TAO_Default_ORT::_tc_ObjectReferenceTemplate,
            1,
            ACE_static_cast (void *, tmp),
            TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor);
        value = tmp;
        return 1;
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
    template class TAO_Valuetype_Manager<TAO_Default_ORT::ObjectReferenceTemplate, TAO_Default_ORT::ObjectReferenceTemplate_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Valuetype_Manager<TAO_Default_ORT::ObjectReferenceTemplate, TAO_Default_ORT::ObjectReferenceTemplate_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

//@@ Boris: begin experimental
void
CORBA::add_ref (TAO_Default_ORT::ObjectReferenceFactory * vt)
{
  if (vt != 0)
  {
    vt->_add_ref ();
  }
}

void
CORBA::remove_ref (TAO_Default_ORT::ObjectReferenceFactory * vt)
{
  if (vt != 0)
  {
    vt->_remove_ref ();
  }
}

//@@ Boris: end experimental
CORBA::Boolean
operator<< (TAO_OutputCDR &strm, const TAO_Default_ORT::ObjectReferenceFactory *_tao_valuetype)
{
  return CORBA_ValueBase::_tao_marshal (strm,
    ACE_const_cast (TAO_Default_ORT::ObjectReferenceFactory*, _tao_valuetype),
    (ptr_arith_t) &TAO_Default_ORT::ObjectReferenceFactory::_downcast);
}

CORBA::Boolean
operator>> (TAO_InputCDR &strm, TAO_Default_ORT::ObjectReferenceFactory *&_tao_valuetype)
{
  return TAO_Default_ORT::ObjectReferenceFactory::_tao_unmarshal (strm, _tao_valuetype);
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceFactory::_tao_marshal_state (TAO_OutputCDR &)
{
  if (
    1
  )
    return 1;
  else
    return 0;
  
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceFactory::_tao_unmarshal_state (TAO_InputCDR &)
{
  if (
    1
  )
    return 1;
  else
    return 0;
  
}

//@@ Boris: begin experimental
void
CORBA::add_ref (TAO_Default_ORT::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
  {
    vt->_add_ref ();
  }
}

void
CORBA::remove_ref (TAO_Default_ORT::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
  {
    vt->_remove_ref ();
  }
}

//@@ Boris: end experimental
CORBA::Boolean
operator<< (TAO_OutputCDR &strm, const TAO_Default_ORT::ObjectReferenceTemplate *_tao_valuetype)
{
  return CORBA_ValueBase::_tao_marshal (strm,
    ACE_const_cast (TAO_Default_ORT::ObjectReferenceTemplate*, _tao_valuetype),
    (ptr_arith_t) &TAO_Default_ORT::ObjectReferenceTemplate::_downcast);
}

CORBA::Boolean
operator>> (TAO_InputCDR &strm, TAO_Default_ORT::ObjectReferenceTemplate *&_tao_valuetype)
{
  return TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal (strm, _tao_valuetype);
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal_state (TAO_OutputCDR &)
{
  if (
    1
  )
    return 1;
  else
    return 0;
  
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal_state (TAO_InputCDR &)
{
  if (
    1
  )
    return 1;
  else
    return 0;
  
}

