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


#include "IORInfoC.h"
#include "tao/CDR.h"
#include "tao/Object_Argument_T.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "IORInfoC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:65

// Arg traits specializations.
namespace TAO
{

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_IORInterceptor_Export Arg_Traits<PortableInterceptor::ObjectReferenceFactory>
    : public
        Object_Arg_Traits_T<
            PortableInterceptor::ObjectReferenceFactory *,
            PortableInterceptor::ObjectReferenceFactory_var,
            PortableInterceptor::ObjectReferenceFactory_out,
            TAO::Value_Traits<PortableInterceptor::ObjectReferenceFactory>
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableInterceptor::IORInfo.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableInterceptor::IORInfo_ptr
TAO::Objref_Traits<PortableInterceptor::IORInfo>::duplicate (
    PortableInterceptor::IORInfo_ptr p
  )
{
  return PortableInterceptor::IORInfo::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<PortableInterceptor::IORInfo>::release (
    PortableInterceptor::IORInfo_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableInterceptor::IORInfo_ptr
TAO::Objref_Traits<PortableInterceptor::IORInfo>::nil (void)
{
  return PortableInterceptor::IORInfo::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::IORInfo>::marshal (
    PortableInterceptor::IORInfo_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::IORInfo::IORInfo (void)
{}

PortableInterceptor::IORInfo::~IORInfo (void)
{}

PortableInterceptor::IORInfo_ptr
PortableInterceptor::IORInfo::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return IORInfo::_nil ();
    }
  
  IORInfo_ptr proxy =
    dynamic_cast<IORInfo_ptr> (_tao_objref);
  
  return IORInfo::_duplicate (proxy);
}

PortableInterceptor::IORInfo_ptr
PortableInterceptor::IORInfo::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return IORInfo::_nil ();
    }
  
  IORInfo_ptr proxy =
    dynamic_cast<IORInfo_ptr> (_tao_objref);
  
  return IORInfo::_duplicate (proxy);
}

PortableInterceptor::IORInfo_ptr
PortableInterceptor::IORInfo::_duplicate (IORInfo_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
PortableInterceptor::IORInfo::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/IORInfo:1.0"
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

const char* PortableInterceptor::IORInfo::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/IORInfo:1.0";
}

CORBA::Boolean
PortableInterceptor::IORInfo::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_TMPLINST_CS_

  template class
     TAO::Arg_Traits<
        PortableInterceptor::ObjectReferenceFactory
      >;

  template class
    TAO::Object_Arg_Traits_T<
        PortableInterceptor::ObjectReferenceFactory *,
        PortableInterceptor::ObjectReferenceFactory_var,
        PortableInterceptor::ObjectReferenceFactory_out,
        TAO::Objref_Traits<PortableInterceptor::ObjectReferenceFactory> 
      >;

#endif /* end #if !defined */

  template class
    TAO::Objref_Traits<
        PortableInterceptor::IORInfo
      >;

  template class
    TAO_Objref_Var_T<
        PortableInterceptor::IORInfo
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableInterceptor::IORInfo
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate \
     TAO::Arg_Traits< \
        PortableInterceptor::ObjectReferenceFactory \
      >

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        PortableInterceptor::ObjectReferenceFactory *, \
        PortableInterceptor::ObjectReferenceFactory_var, \
        PortableInterceptor::ObjectReferenceFactory_out, \
        TAO::Objref_Traits<PortableInterceptor::ObjectReferenceFactory>  \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableInterceptor::IORInfo \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableInterceptor::IORInfo
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableInterceptor::IORInfo
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
