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
// .\be\be_codegen.cpp:277


#include "CSD_FrameworkC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"


// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// c:\csd\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CSD_Framework::Strategy.

CSD_Framework::Strategy_ptr
TAO::Objref_Traits<CSD_Framework::Strategy>::duplicate (
    CSD_Framework::Strategy_ptr p
  )
{
  return CSD_Framework::Strategy::_duplicate (p);
}

void
TAO::Objref_Traits<CSD_Framework::Strategy>::release (
    CSD_Framework::Strategy_ptr p
  )
{
  CORBA::release (p);
}

CSD_Framework::Strategy_ptr
TAO::Objref_Traits<CSD_Framework::Strategy>::nil (void)
{
  return CSD_Framework::Strategy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<CSD_Framework::Strategy>::marshal (
    CSD_Framework::Strategy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

CSD_Framework::Strategy::Strategy (void)
{}

CSD_Framework::Strategy::~Strategy (void)
{}

CSD_Framework::Strategy_ptr
CSD_Framework::Strategy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return Strategy::_duplicate (
      dynamic_cast<Strategy_ptr> (_tao_objref)
    );
}

CSD_Framework::Strategy_ptr
CSD_Framework::Strategy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return Strategy::_duplicate (
      dynamic_cast<Strategy_ptr> (_tao_objref)
    );
}

CSD_Framework::Strategy_ptr
CSD_Framework::Strategy::_duplicate (Strategy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
CSD_Framework::Strategy::_tao_release (Strategy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
CSD_Framework::Strategy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:CSD_Framework/Strategy:2.3"
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

const char* CSD_Framework::Strategy::_interface_repository_id (void) const
{
  return "IDL:CSD_Framework/Strategy:2.3";
}

::CORBA::Boolean
CSD_Framework::Strategy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// c:\csd\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CSD_Framework::POA.

CSD_Framework::POA_ptr
TAO::Objref_Traits<CSD_Framework::POA>::duplicate (
    CSD_Framework::POA_ptr p
  )
{
  return CSD_Framework::POA::_duplicate (p);
}

void
TAO::Objref_Traits<CSD_Framework::POA>::release (
    CSD_Framework::POA_ptr p
  )
{
  CORBA::release (p);
}

CSD_Framework::POA_ptr
TAO::Objref_Traits<CSD_Framework::POA>::nil (void)
{
  return CSD_Framework::POA::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<CSD_Framework::POA>::marshal (
    CSD_Framework::POA_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

CSD_Framework::POA::POA (void)
{}

CSD_Framework::POA::~POA (void)
{}

CSD_Framework::POA_ptr
CSD_Framework::POA::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return POA::_duplicate (
      dynamic_cast<POA_ptr> (_tao_objref)
    );
}

CSD_Framework::POA_ptr
CSD_Framework::POA::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return POA::_duplicate (
      dynamic_cast<POA_ptr> (_tao_objref)
    );
}

CSD_Framework::POA_ptr
CSD_Framework::POA::_duplicate (POA_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
CSD_Framework::POA::_tao_release (POA_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
CSD_Framework::POA::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableServer/POA:2.3"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:CSD_Framework/POA:2.3"
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

const char* CSD_Framework::POA::_interface_repository_id (void) const
{
  return "IDL:CSD_Framework/POA:2.3";
}

::CORBA::Boolean
CSD_Framework::POA::marshal (TAO_OutputCDR &)
{
  return false;
}
