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
// be\be_codegen.cpp:301


#include "POAManagerC.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "POAManagerC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::POAManager.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::POAManager_ptr
TAO::Objref_Traits<PortableServer::POAManager>::duplicate (
    PortableServer::POAManager_ptr p
  )
{
  return PortableServer::POAManager::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<PortableServer::POAManager>::release (
    PortableServer::POAManager_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::POAManager_ptr
TAO::Objref_Traits<PortableServer::POAManager>::nil (void)
{
  return PortableServer::POAManager::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<PortableServer::POAManager>::marshal (
    PortableServer::POAManager_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*PortableServer__TAO_POAManager_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POAManager::AdapterInactive::AdapterInactive (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POAManager/AdapterInactive:2.3",
        "AdapterInactive"
      )
{
}

PortableServer::POAManager::AdapterInactive::~AdapterInactive (void)
{
}

PortableServer::POAManager::AdapterInactive::AdapterInactive (const ::PortableServer::POAManager::AdapterInactive &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POAManager::AdapterInactive&
PortableServer::POAManager::AdapterInactive::operator= (const ::PortableServer::POAManager::AdapterInactive &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POAManager::AdapterInactive::_tao_any_destructor (void *_tao_void_pointer)
{
  AdapterInactive *_tao_tmp_pointer =
    static_cast<AdapterInactive*> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POAManager::AdapterInactive *
PortableServer::POAManager::AdapterInactive::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/PortableServer/POAManager/AdapterInactive:2.3", _tao_excp->_rep_id ()))
    {
      return dynamic_cast<AdapterInactive *> (_tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *PortableServer::POAManager::AdapterInactive::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POAManager::AdapterInactive, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POAManager::AdapterInactive::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POAManager::AdapterInactive (*this),
      0
    );
  return result;
}

void PortableServer::POAManager::AdapterInactive::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POAManager::AdapterInactive::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POAManager::AdapterInactive::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POAManager::AdapterInactive::_type (void) const
{
  return ::PortableServer::POAManager::_tc_AdapterInactive;
}

PortableServer::POAManager::POAManager (void)
{}

PortableServer::POAManager::~POAManager (void)
{}

void 
PortableServer::POAManager::_tao_any_destructor (void *_tao_void_pointer)
{
  POAManager *_tao_tmp_pointer =
    static_cast<POAManager *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::POAManager_ptr
PortableServer::POAManager::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return POAManager::_nil ();
    }
  
  POAManager_ptr proxy =
    dynamic_cast<POAManager_ptr> (_tao_objref);
  
  return POAManager::_duplicate (proxy);
}

PortableServer::POAManager_ptr
PortableServer::POAManager::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return POAManager::_nil ();
    }
  
  POAManager_ptr proxy =
    dynamic_cast<POAManager_ptr> (_tao_objref);
  
  return POAManager::_duplicate (proxy);
}

PortableServer::POAManager_ptr
PortableServer::POAManager::_duplicate (POAManager_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
PortableServer::POAManager::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableServer/POAManager:2.3"
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

const char* PortableServer::POAManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/POAManager:2.3";
}

CORBA::Boolean
PortableServer::POAManager::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::POAManager
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::POAManager
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::POAManager
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::POAManager \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::POAManager
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::POAManager
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
