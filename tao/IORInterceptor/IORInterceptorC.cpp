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


#include "IORInterceptor.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "IORInterceptorC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableInterceptor::IORInterceptor.

PortableInterceptor::IORInterceptor_ptr
TAO::Objref_Traits<PortableInterceptor::IORInterceptor>::duplicate (
    PortableInterceptor::IORInterceptor_ptr p
  )
{
  return PortableInterceptor::IORInterceptor::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::IORInterceptor>::release (
    PortableInterceptor::IORInterceptor_ptr p
  )
{
  CORBA::release (p);
}

PortableInterceptor::IORInterceptor_ptr
TAO::Objref_Traits<PortableInterceptor::IORInterceptor>::nil (void)
{
  return PortableInterceptor::IORInterceptor::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::IORInterceptor>::marshal (
    PortableInterceptor::IORInterceptor_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::IORInterceptor::IORInterceptor (void)
{}

PortableInterceptor::IORInterceptor::~IORInterceptor (void)
{}

PortableInterceptor::IORInterceptor_ptr
PortableInterceptor::IORInterceptor::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return IORInterceptor::_nil ();
    }
  
  IORInterceptor_ptr proxy =
    dynamic_cast<IORInterceptor_ptr> (_tao_objref);
  
  return IORInterceptor::_duplicate (proxy);
}

PortableInterceptor::IORInterceptor_ptr
PortableInterceptor::IORInterceptor::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return IORInterceptor::_nil ();
    }
  
  IORInterceptor_ptr proxy =
    dynamic_cast<IORInterceptor_ptr> (_tao_objref);
  
  return IORInterceptor::_duplicate (proxy);
}

PortableInterceptor::IORInterceptor_ptr
PortableInterceptor::IORInterceptor::_duplicate (IORInterceptor_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableInterceptor::IORInterceptor::_tao_release (IORInterceptor_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
PortableInterceptor::IORInterceptor::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/Interceptor:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/IORInterceptor:1.0"
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

const char* PortableInterceptor::IORInterceptor::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/IORInterceptor:1.0";
}

CORBA::Boolean
PortableInterceptor::IORInterceptor::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1619

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableInterceptor::IORInterceptor
      >;

  template class
    TAO_Objref_Var_T<
        PortableInterceptor::IORInterceptor
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableInterceptor::IORInterceptor
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableInterceptor::IORInterceptor \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableInterceptor::IORInterceptor
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableInterceptor::IORInterceptor
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
