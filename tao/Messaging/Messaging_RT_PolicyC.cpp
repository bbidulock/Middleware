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
// be\be_codegen.cpp:302


#include "Messaging_RT_PolicyC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Messaging_RT_PolicyC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::RelativeRoundtripTimeoutPolicy.

Messaging::RelativeRoundtripTimeoutPolicy_ptr
TAO::Objref_Traits<Messaging::RelativeRoundtripTimeoutPolicy>::duplicate (
    Messaging::RelativeRoundtripTimeoutPolicy_ptr p
  )
{
  return Messaging::RelativeRoundtripTimeoutPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::RelativeRoundtripTimeoutPolicy>::release (
    Messaging::RelativeRoundtripTimeoutPolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
TAO::Objref_Traits<Messaging::RelativeRoundtripTimeoutPolicy>::nil (void)
{
  return Messaging::RelativeRoundtripTimeoutPolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<Messaging::RelativeRoundtripTimeoutPolicy>::marshal (
    Messaging::RelativeRoundtripTimeoutPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

Messaging::RelativeRoundtripTimeoutPolicy::RelativeRoundtripTimeoutPolicy (void)
{}

Messaging::RelativeRoundtripTimeoutPolicy::~RelativeRoundtripTimeoutPolicy (void)
{}

void 
Messaging::RelativeRoundtripTimeoutPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  RelativeRoundtripTimeoutPolicy *_tao_tmp_pointer =
    static_cast<RelativeRoundtripTimeoutPolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
Messaging::RelativeRoundtripTimeoutPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return RelativeRoundtripTimeoutPolicy::_nil ();
    }
  
  RelativeRoundtripTimeoutPolicy_ptr proxy =
    dynamic_cast<RelativeRoundtripTimeoutPolicy_ptr> (_tao_objref);
  
  return RelativeRoundtripTimeoutPolicy::_duplicate (proxy);
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
Messaging::RelativeRoundtripTimeoutPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return RelativeRoundtripTimeoutPolicy::_nil ();
    }
  
  RelativeRoundtripTimeoutPolicy_ptr proxy =
    dynamic_cast<RelativeRoundtripTimeoutPolicy_ptr> (_tao_objref);
  
  return RelativeRoundtripTimeoutPolicy::_duplicate (proxy);
}

Messaging::RelativeRoundtripTimeoutPolicy_ptr
Messaging::RelativeRoundtripTimeoutPolicy::_duplicate (RelativeRoundtripTimeoutPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::RelativeRoundtripTimeoutPolicy::_tao_release (RelativeRoundtripTimeoutPolicy_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
Messaging::RelativeRoundtripTimeoutPolicy::_is_a (
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
          "IDL:omg.org/Messaging/RelativeRoundtripTimeoutPolicy:1.0"
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

const char* Messaging::RelativeRoundtripTimeoutPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/RelativeRoundtripTimeoutPolicy:1.0";
}

CORBA::Boolean
Messaging::RelativeRoundtripTimeoutPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1528

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        Messaging::RelativeRoundtripTimeoutPolicy
      >;

  template class
    TAO_Objref_Var_T<
        Messaging::RelativeRoundtripTimeoutPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        Messaging::RelativeRoundtripTimeoutPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        Messaging::RelativeRoundtripTimeoutPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        Messaging::RelativeRoundtripTimeoutPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        Messaging::RelativeRoundtripTimeoutPolicy
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
