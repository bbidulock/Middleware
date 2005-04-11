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
// be\be_codegen.cpp:291


#include "POAManagerC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::POAManager.

PortableServer::POAManager_ptr
TAO::Objref_Traits<PortableServer::POAManager>::duplicate (
    PortableServer::POAManager_ptr p
  )
{
  return PortableServer::POAManager::_duplicate (p);
}

void
TAO::Objref_Traits<PortableServer::POAManager>::release (
    PortableServer::POAManager_ptr p
  )
{
  CORBA::release (p);
}

PortableServer::POAManager_ptr
TAO::Objref_Traits<PortableServer::POAManager>::nil (void)
{
  return PortableServer::POAManager::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableServer::POAManager>::marshal (
    PortableServer::POAManager_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

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
    static_cast<AdapterInactive *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POAManager::AdapterInactive *
PortableServer::POAManager::AdapterInactive::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<AdapterInactive *> (_tao_excp);
}

const PortableServer::POAManager::AdapterInactive *
PortableServer::POAManager::AdapterInactive::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const AdapterInactive *> (_tao_excp);
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
  CORBA::Exception *result = 0;
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
CORBA::TypeCode_ptr PortableServer::POAManager::AdapterInactive::_tao_type (void) const
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

void
PortableServer::POAManager::_tao_release (POAManager_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
PortableServer::POAManager::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableServer/POAManager:2.3"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* PortableServer::POAManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/POAManager:2.3";
}

CORBA::Boolean
PortableServer::POAManager::marshal (TAO_OutputCDR &)
{
  return false;
}
