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
// be\be_codegen.cpp:277


#include "tao/PortableServer/IdAssignmentPolicyC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::IdAssignmentPolicy.

PortableServer::IdAssignmentPolicy_ptr
TAO::Objref_Traits<PortableServer::IdAssignmentPolicy>::duplicate (
    PortableServer::IdAssignmentPolicy_ptr p
  )
{
  return PortableServer::IdAssignmentPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<PortableServer::IdAssignmentPolicy>::release (
    PortableServer::IdAssignmentPolicy_ptr p
  )
{
  CORBA::release (p);
}

PortableServer::IdAssignmentPolicy_ptr
TAO::Objref_Traits<PortableServer::IdAssignmentPolicy>::nil (void)
{
  return PortableServer::IdAssignmentPolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableServer::IdAssignmentPolicy>::marshal (
    PortableServer::IdAssignmentPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

PortableServer::IdAssignmentPolicy::IdAssignmentPolicy (void)
{}

PortableServer::IdAssignmentPolicy::~IdAssignmentPolicy (void)
{}

PortableServer::IdAssignmentPolicy_ptr
PortableServer::IdAssignmentPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return IdAssignmentPolicy::_duplicate (
      dynamic_cast<IdAssignmentPolicy_ptr> (_tao_objref)
    );
}

PortableServer::IdAssignmentPolicy_ptr
PortableServer::IdAssignmentPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return IdAssignmentPolicy::_duplicate (
      dynamic_cast<IdAssignmentPolicy_ptr> (_tao_objref)
    );
}

PortableServer::IdAssignmentPolicy_ptr
PortableServer::IdAssignmentPolicy::_duplicate (IdAssignmentPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableServer::IdAssignmentPolicy::_tao_release (IdAssignmentPolicy_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
PortableServer::IdAssignmentPolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableServer/IdAssignmentPolicy:2.3"
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

const char* PortableServer::IdAssignmentPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/IdAssignmentPolicy:2.3";
}

CORBA::Boolean
PortableServer::IdAssignmentPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_cs.cpp:51

CORBA::Boolean operator<< (TAO_OutputCDR & strm, PortableServer::IdAssignmentPolicyValue _tao_enumerator)
{
  return strm << static_cast<CORBA::ULong> (_tao_enumerator);
}

CORBA::Boolean operator>> (TAO_InputCDR & strm, PortableServer::IdAssignmentPolicyValue & _tao_enumerator)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean const _tao_success = strm >> _tao_temp;
  
  if (_tao_success)
    {
      _tao_enumerator = static_cast<PortableServer::IdAssignmentPolicyValue> (_tao_temp);
    }
  
  return _tao_success;
}

TAO_END_VERSIONED_NAMESPACE_DECL
