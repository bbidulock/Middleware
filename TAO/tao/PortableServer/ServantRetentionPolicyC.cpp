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


#include "ServantRetentionPolicyC.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ServantRetentionPolicyC.inl"
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

// Traits specializations for PortableServer::ServantRetentionPolicy.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::ServantRetentionPolicy_ptr
TAO::Objref_Traits<PortableServer::ServantRetentionPolicy>::duplicate (
    PortableServer::ServantRetentionPolicy_ptr p
  )
{
  return PortableServer::ServantRetentionPolicy::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<PortableServer::ServantRetentionPolicy>::release (
    PortableServer::ServantRetentionPolicy_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::ServantRetentionPolicy_ptr
TAO::Objref_Traits<PortableServer::ServantRetentionPolicy>::nil (void)
{
  return PortableServer::ServantRetentionPolicy::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<PortableServer::ServantRetentionPolicy>::marshal (
    PortableServer::ServantRetentionPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*PortableServer__TAO_ServantRetentionPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

PortableServer::ServantRetentionPolicy::ServantRetentionPolicy (void)
{}

PortableServer::ServantRetentionPolicy::~ServantRetentionPolicy (void)
{}

void 
PortableServer::ServantRetentionPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  ServantRetentionPolicy *_tao_tmp_pointer =
    static_cast<ServantRetentionPolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::ServantRetentionPolicy_ptr
PortableServer::ServantRetentionPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ServantRetentionPolicy::_nil ();
    }
  
  ServantRetentionPolicy_ptr proxy =
    dynamic_cast<ServantRetentionPolicy_ptr> (_tao_objref);
  
  return ServantRetentionPolicy::_duplicate (proxy);
}

PortableServer::ServantRetentionPolicy_ptr
PortableServer::ServantRetentionPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ServantRetentionPolicy::_nil ();
    }
  
  ServantRetentionPolicy_ptr proxy =
    dynamic_cast<ServantRetentionPolicy_ptr> (_tao_objref);
  
  return ServantRetentionPolicy::_duplicate (proxy);
}

PortableServer::ServantRetentionPolicy_ptr
PortableServer::ServantRetentionPolicy::_duplicate (ServantRetentionPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
PortableServer::ServantRetentionPolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableServer/ServantRetentionPolicy:1.0"
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

const char* PortableServer::ServantRetentionPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/ServantRetentionPolicy:1.0";
}

CORBA::Boolean
PortableServer::ServantRetentionPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::ServantRetentionPolicy
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::ServantRetentionPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::ServantRetentionPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::ServantRetentionPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::ServantRetentionPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::ServantRetentionPolicy
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
