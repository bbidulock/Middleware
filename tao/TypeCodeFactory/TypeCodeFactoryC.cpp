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


#include "TypeCodeFactoryC.h"
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
#include "TypeCodeFactoryC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:61

int CORBA::TypeCodeFactory::_tao_class_id = 0;

CORBA::TypeCodeFactory_ptr
CORBA::tao_TypeCodeFactory_life::tao_duplicate (
    CORBA::TypeCodeFactory_ptr p
  )
{
  return CORBA::TypeCodeFactory::_duplicate (p);
}

void
CORBA::tao_TypeCodeFactory_life::tao_release (
    CORBA::TypeCodeFactory_ptr p
  )
{
  CORBA::release (p);
}

CORBA::TypeCodeFactory_ptr
CORBA::tao_TypeCodeFactory_life::tao_nil (
    void
  )
{
  return CORBA::TypeCodeFactory::_nil ();
}

CORBA::Boolean
CORBA::tao_TypeCodeFactory_life::tao_marshal (
    CORBA::TypeCodeFactory_ptr p,
    TAO_OutputCDR &cdr
  )
{
  return p->marshal (cdr);
}

CORBA::TypeCodeFactory_ptr
CORBA::tao_TypeCodeFactory_cast::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return CORBA::TypeCodeFactory::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
CORBA::tao_TypeCodeFactory_cast::tao_upcast (
    void *src
  )
{
  CORBA::TypeCodeFactory **tmp =
    ACE_static_cast (CORBA::TypeCodeFactory **, src);
  return *tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class
    TAO_Objref_Var_T<
        CORBA::TypeCodeFactory,
        CORBA::tao_TypeCodeFactory_life
      >;
  template class
    TAO_Objref_Out_T<
        CORBA::TypeCodeFactory,
        CORBA::tao_TypeCodeFactory_life
      >;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::TypeCodeFactory, \
        CORBA::tao_TypeCodeFactory_life \
      >
# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::TypeCodeFactory, \
        CORBA::tao_TypeCodeFactory_life \
      >
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:232

CORBA::TypeCodeFactory::TypeCodeFactory (void)
{}

CORBA::TypeCodeFactory::~TypeCodeFactory (void)
{}

void
CORBA::TypeCodeFactory::_tao_any_destructor (void *_tao_void_pointer)
{
  TypeCodeFactory *tmp = ACE_static_cast (TypeCodeFactory *, _tao_void_pointer);
  CORBA::release (tmp);
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return TypeCodeFactory::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return TypeCodeFactory::_nil ();
    }

  return
      ACE_reinterpret_cast (
          TypeCodeFactory_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptr_arith_t,
                  &TypeCodeFactory::_tao_class_id
                )
            )
        );
}

CORBA::TypeCodeFactory_ptr
CORBA::TypeCodeFactory::_duplicate (TypeCodeFactory_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void *CORBA::TypeCodeFactory::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;

  if (type == ACE_reinterpret_cast (
              ptr_arith_t,
              &ACE_NESTED_CLASS (::CORBA, TypeCodeFactory)::_tao_class_id)
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

const char* CORBA::TypeCodeFactory::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/TypeCodeFactory:1.0";
}

CORBA::Boolean
CORBA::TypeCodeFactory::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_TypeCodeFactory[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  38,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f5479),
  ACE_NTOHL (0x7065436f),
  ACE_NTOHL (0x64654661),
  ACE_NTOHL (0x63746f72),
  ACE_NTOHL (0x793a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/TypeCodeFactory:1.0
    16,
  ACE_NTOHL (0x54797065),
  ACE_NTOHL (0x436f6465),
  ACE_NTOHL (0x46616374),
  ACE_NTOHL (0x6f727900),  // name = TypeCodeFactory
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_TypeCodeFactory (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_TypeCodeFactory),
    (char *) &_oc_CORBA_TypeCodeFactory,
    0,
    sizeof (CORBA::TypeCodeFactory)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_TypeCodeFactory,
    &_tc_TAO_tc_CORBA_TypeCodeFactory
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_cs.cpp:52

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::TypeCodeFactory_ptr _tao_elem
  )
{
  CORBA::TypeCodeFactory_ptr _tao_objptr =
    CORBA::TypeCodeFactory::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::TypeCodeFactory_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::TypeCodeFactory>::insert (
      _tao_any,
      CORBA::TypeCodeFactory::_tao_any_destructor,
      CORBA::_tc_TypeCodeFactory,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::TypeCodeFactory_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::TypeCodeFactory>::extract (
        _tao_any,
        CORBA::TypeCodeFactory::_tao_any_destructor,
        CORBA::_tc_TypeCodeFactory,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO_Object_Manager<CORBA::TypeCodeFactory,CORBA::TypeCodeFactory_var>;
  template class TAO::Any_Impl_T<CORBA::TypeCodeFactory>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Object_Manager<CORBA::TypeCodeFactory, CORBA::TypeCodeFactory_var>
# pragma instantiate TAO::Any_Impl_T<CORBA::TypeCodeFactory>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
