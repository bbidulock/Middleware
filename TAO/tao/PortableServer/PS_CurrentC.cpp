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
// be\be_codegen.cpp:303


#include "PS_CurrentC.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "PS_CurrentC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::Current.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::Current_ptr
TAO::Objref_Traits<PortableServer::Current>::duplicate (
    PortableServer::Current_ptr p
  )
{
  return PortableServer::Current::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<PortableServer::Current>::release (
    PortableServer::Current_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::Current_ptr
TAO::Objref_Traits<PortableServer::Current>::nil (void)
{
  return PortableServer::Current::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<PortableServer::Current>::marshal (
    PortableServer::Current_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*PortableServer__TAO_Current_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::Current::NoContext::NoContext (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/Current/NoContext:2.3",
        "NoContext"
      )
{
}

PortableServer::Current::NoContext::~NoContext (void)
{
}

PortableServer::Current::NoContext::NoContext (const ::PortableServer::Current::NoContext &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::Current::NoContext&
PortableServer::Current::NoContext::operator= (const ::PortableServer::Current::NoContext &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::Current::NoContext::_tao_any_destructor (void *_tao_void_pointer)
{
  NoContext *_tao_tmp_pointer =
    static_cast<NoContext*> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::Current::NoContext *
PortableServer::Current::NoContext::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/PortableServer/Current/NoContext:2.3", _tao_excp->_rep_id ()))
    {
      return dynamic_cast<NoContext *> (_tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *PortableServer::Current::NoContext::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::Current::NoContext, 0);
  return retval;
}

CORBA::Exception *
PortableServer::Current::NoContext::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::Current::NoContext (*this),
      0
    );
  return result;
}

void PortableServer::Current::NoContext::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::Current::NoContext::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::Current::NoContext::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::Current::NoContext::_type (void) const
{
  return ::PortableServer::Current::_tc_NoContext;
}

PortableServer::Current::Current (void)
{}

PortableServer::Current::~Current (void)
{}

void 
PortableServer::Current::_tao_any_destructor (void *_tao_void_pointer)
{
  Current *_tao_tmp_pointer =
    static_cast<Current *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::Current_ptr
PortableServer::Current::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Current::_nil ();
    }
  
  Current_ptr proxy =
    dynamic_cast<Current_ptr> (_tao_objref);
  
  return Current::_duplicate (proxy);
}

PortableServer::Current_ptr
PortableServer::Current::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Current::_nil ();
    }
  
  Current_ptr proxy =
    dynamic_cast<Current_ptr> (_tao_objref);
  
  return Current::_duplicate (proxy);
}

PortableServer::Current_ptr
PortableServer::Current::_duplicate (Current_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
PortableServer::Current::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Current:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableServer/Current:2.3"
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

const char* PortableServer::Current::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/Current:2.3";
}

CORBA::Boolean
PortableServer::Current::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::Current
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::Current
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::Current
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::Current \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::Current
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::Current
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
