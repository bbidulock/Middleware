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


#include "AdapterActivatorC.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "AdapterActivatorC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

#if (TAO_HAS_MINIMUM_POA == 0)

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::AdapterActivator.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::AdapterActivator_ptr
TAO::Objref_Traits<PortableServer::AdapterActivator>::duplicate (
    PortableServer::AdapterActivator_ptr p
  )
{
  return PortableServer::AdapterActivator::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<PortableServer::AdapterActivator>::release (
    PortableServer::AdapterActivator_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::AdapterActivator_ptr
TAO::Objref_Traits<PortableServer::AdapterActivator>::nil (void)
{
  return PortableServer::AdapterActivator::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<PortableServer::AdapterActivator>::marshal (
    PortableServer::AdapterActivator_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*PortableServer__TAO_AdapterActivator_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

PortableServer::AdapterActivator::AdapterActivator (void)
{}

PortableServer::AdapterActivator::~AdapterActivator (void)
{}

void
PortableServer::AdapterActivator::_tao_any_destructor (void *_tao_void_pointer)
{
  AdapterActivator *_tao_tmp_pointer =
    static_cast<AdapterActivator *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::AdapterActivator_ptr
PortableServer::AdapterActivator::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return AdapterActivator::_nil ();
    }

  AdapterActivator_ptr proxy =
    dynamic_cast<AdapterActivator_ptr> (_tao_objref);

  return AdapterActivator::_duplicate (proxy);
}

PortableServer::AdapterActivator_ptr
PortableServer::AdapterActivator::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return AdapterActivator::_nil ();
    }

  AdapterActivator_ptr proxy =
    dynamic_cast<AdapterActivator_ptr> (_tao_objref);

  return AdapterActivator::_duplicate (proxy);
}

PortableServer::AdapterActivator_ptr
PortableServer::AdapterActivator::_duplicate (AdapterActivator_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
PortableServer::AdapterActivator::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableServer/AdapterActivator:2.3"
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

const char* PortableServer::AdapterActivator::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/AdapterActivator:2.3";
}

CORBA::Boolean
PortableServer::AdapterActivator::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::AdapterActivator
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::AdapterActivator
      >;

  template class
    TAO_Objref_Out_T<
        PortableServer::AdapterActivator
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::AdapterActivator \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::AdapterActivator
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::AdapterActivator
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
