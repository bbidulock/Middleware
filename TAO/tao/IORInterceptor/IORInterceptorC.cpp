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
// be/be_codegen.cpp:301


#include "IORInterceptorC.h"
#include "tao/Stub.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Object_Argument_T.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include "tao/Var_Size_Argument_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "IORInterceptorC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:59

// Arg traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLICY__ARG_TRAITS_CS_)
#define _CORBA_POLICY__ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_IORInterceptor_Export Arg_Traits<CORBA::Policy>
    : public
        Object_Arg_Traits_T<
            CORBA::Policy_ptr,
            CORBA::Policy_var,
            CORBA::Policy_out,
            TAO::Objref_Traits<CORBA::Policy>
          >
  {
  };

#endif /* end #if !defined */

#if !defined (_CORBA_POLICY__ARG_TRAITS_CS_)
#define _CORBA_POLICY__ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_IORInterceptor_Export Arg_Traits<CORBA::Policy>
    : public
        Object_Arg_Traits_T<
            CORBA::Policy_ptr,
            CORBA::Policy_var,
            CORBA::Policy_out,
            TAO::Objref_Traits<CORBA::Policy>
          >
  {
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:428

#if !defined (_IOP_TAGGEDCOMPONENT__ARG_TRAITS_CS_)
#define _IOP_TAGGEDCOMPONENT__ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_IORInterceptor_Export Arg_Traits<IOP::TaggedComponent>
    : public
        Var_Size_Arg_Traits_T<
            IOP::TaggedComponent,
            IOP::TaggedComponent_var,
            IOP::TaggedComponent_out
          >
  {
  };

#endif /* end #if !defined */

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

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__ARG_TRAITS_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_IORInterceptor_Export Arg_Traits<PortableInterceptor::ObjectReferenceTemplate>
    : public
        Object_Arg_Traits_T<
            PortableInterceptor::ObjectReferenceTemplate *,
            PortableInterceptor::ObjectReferenceTemplate_var,
            PortableInterceptor::ObjectReferenceTemplate_out,
            TAO::Value_Traits<PortableInterceptor::ObjectReferenceTemplate>
          >
  {
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:262

#if !defined (__TAO_SEQ_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE___ARG_TRAITS_CS_)
#define __TAO_SEQ_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE___ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_IORInterceptor_Export Arg_Traits<PortableInterceptor::ObjectReferenceTemplateSeq>
    : public
        Var_Size_Arg_Traits_T<
            PortableInterceptor::ObjectReferenceTemplateSeq,
            PortableInterceptor::ObjectReferenceTemplateSeq_var,
            PortableInterceptor::ObjectReferenceTemplateSeq_out
          >
  {
  };

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_IORINFO__ARG_TRAITS_CS_)
#define _PORTABLEINTERCEPTOR_IORINFO__ARG_TRAITS_CS_
  
  ACE_TEMPLATE_SPECIALIZATION
  class TAO_IORInterceptor_Export Arg_Traits<PortableInterceptor::IORInfo>
    : public
        Object_Arg_Traits_T<
            PortableInterceptor::IORInfo_ptr,
            PortableInterceptor::IORInfo_var,
            PortableInterceptor::IORInfo_out,
            TAO::Objref_Traits<PortableInterceptor::IORInfo>
          >
  {
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableInterceptor::IORInfo.

PortableInterceptor::IORInfo_ptr
TAO::Objref_Traits<PortableInterceptor::IORInfo>::tao_duplicate (
    PortableInterceptor::IORInfo_ptr p
  )
{
  return PortableInterceptor::IORInfo::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::IORInfo>::tao_release (
    PortableInterceptor::IORInfo_ptr p
  )
{
  CORBA::release (p);
}

PortableInterceptor::IORInfo_ptr
TAO::Objref_Traits<PortableInterceptor::IORInfo>::tao_nil (void)
{
  return PortableInterceptor::IORInfo::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::IORInfo>::tao_marshal (
    PortableInterceptor::IORInfo_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*PortableInterceptor__TAO_IORInfo_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

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
  IORInfo_ptr proxy =
    dynamic_cast<IORInfo_ptr> (_tao_objref);
  proxy->_add_ref ();
  return proxy;
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
          (char *)value,
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
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableInterceptor::IORInterceptor.

PortableInterceptor::IORInterceptor_ptr
TAO::Objref_Traits<PortableInterceptor::IORInterceptor>::tao_duplicate (
    PortableInterceptor::IORInterceptor_ptr p
  )
{
  return PortableInterceptor::IORInterceptor::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::IORInterceptor>::tao_release (
    PortableInterceptor::IORInterceptor_ptr p
  )
{
  CORBA::release (p);
}

PortableInterceptor::IORInterceptor_ptr
TAO::Objref_Traits<PortableInterceptor::IORInterceptor>::tao_nil (void)
{
  return PortableInterceptor::IORInterceptor::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::IORInterceptor>::tao_marshal (
    PortableInterceptor::IORInterceptor_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*PortableInterceptor__TAO_IORInterceptor_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

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
  IORInterceptor_ptr proxy =
    dynamic_cast<IORInterceptor_ptr> (_tao_objref);
  proxy->_add_ref ();
  return proxy;
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

CORBA::Boolean
PortableInterceptor::IORInterceptor::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableInterceptor/Interceptor:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableInterceptor/IORInterceptor:1.0"
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

const char* PortableInterceptor::IORInterceptor::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/IORInterceptor:1.0";
}

CORBA::Boolean
PortableInterceptor::IORInterceptor::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1703

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (_CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<CORBA::Policy>;

  template class
    TAO::Object_Arg_Traits_T<
        CORBA::Policy_ptr,
        CORBA::Policy_var,
        CORBA::Policy_out
      >;

#endif /* end #if !defined */

#if !defined (_IOP_TAGGEDCOMPONENT__ARG_TRAITS_TMPLINST_CS_)
#define _IOP_TAGGEDCOMPONENT__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<IOP::TaggedComponent>;

  template class
    TAO::Var_Size_Arg_Traits<
        IOP::TaggedComponent,
        IOP::TaggedComponent_var,
        IOP::TaggedComponent_out
      >;

#endif /* end #if !defined */

  template class
    TAO::In_Object_Argument_T<
        PortableInterceptor::IORInfo_ptr
      >;

  template class
    TAO::In_Var_Size_Argument_T<
        PortableInterceptor::sequence
      >;

  template class
    TAO_Objref_Var_T<
        PortableInterceptor::IORInterceptor,
        TAO::Objref_Traits<PortableInterceptor::IORInterceptor>
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableInterceptor::IORInterceptor,
        TAO::Objref_Traits<PortableInterceptor::IORInterceptor>
      >;

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<PortableInterceptor::ObjectReferenceFactory>;

  template class
    TAO::Object_Arg_Traits_T<
        PortableInterceptor::ObjectReferenceFactory *,
        PortableInterceptor::ObjectReferenceFactory_var,
        PortableInterceptor::ObjectReferenceFactory_out
      >;

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<PortableInterceptor::ObjectReferenceTemplate>;

  template class
    TAO::Object_Arg_Traits_T<
        PortableInterceptor::ObjectReferenceTemplate *,
        PortableInterceptor::ObjectReferenceTemplate_var,
        PortableInterceptor::ObjectReferenceTemplate_out
      >;

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_SEQUENCE__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_SEQUENCE__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<PortableInterceptor::ObjectReferenceTemplateSeq>;

  template class
    TAO::Var_Size_Arg_Traits<
        PortableInterceptor::ObjectReferenceTemplateSeq,
        PortableInterceptor::ObjectReferenceTemplateSeq_var,
        PortableInterceptor::ObjectReferenceTemplateSeq_out
      >;

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_IORINFO__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_IORINFO__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<PortableInterceptor::IORInfo>;

  template class
    TAO::Object_Arg_Traits_T<
        PortableInterceptor::IORInfo_ptr,
        PortableInterceptor::IORInfo_var,
        PortableInterceptor::IORInfo_out
      >;

#endif /* end #if !defined */

  template class
    TAO::Ret_Object_Argument_T<
        CORBA::Policy_ptr,
        CORBA::Policy_var
      >;

  template class
    TAO::In_Var_Size_Argument_T<
        IOP::TaggedComponent
      >;

  template class
    TAO_Objref_Var_T<
        PortableInterceptor::IORInfo,
        TAO::Objref_Traits<PortableInterceptor::IORInfo>
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableInterceptor::IORInfo,
        TAO::Objref_Traits<PortableInterceptor::IORInfo>
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (_CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<CORBA::Policy>

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        CORBA::Policy_ptr, \
        CORBA::Policy_var, \
        CORBA::Policy_out \
      >

#endif /* end #if !defined */

#if !defined (_IOP_TAGGEDCOMPONENT__ARG_TRAITS_TMPLINST_CS_)
#define _IOP_TAGGEDCOMPONENT__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<IOP::TaggedComponent>

# pragma instantiate \
    TAO::Var_Size_Arg_Traits< \
        IOP::TaggedComponent, \
        IOP::TaggedComponent_var, \
        IOP::TaggedComponent_out \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::In_Object_Argument_T< \
        PortableInterceptor::IORInfo_ptr \
      >

# pragma instantiate \
    TAO::In_Var_Size_Argument_T< \
        PortableInterceptor::sequence \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableInterceptor::IORInterceptor, \
        TAO::Objref_Traits<PortableInterceptor::IORInterceptor> \
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableInterceptor::IORInterceptor, \
        TAO::Objref_Traits<PortableInterceptor::IORInterceptor> \
      >

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<PortableInterceptor::ObjectReferenceFactory>

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        PortableInterceptor::ObjectReferenceFactory *, \
        PortableInterceptor::ObjectReferenceFactory_var, \
        PortableInterceptor::ObjectReferenceFactory_out \
      >

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<PortableInterceptor::ObjectReferenceTemplate>

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        PortableInterceptor::ObjectReferenceTemplate *, \
        PortableInterceptor::ObjectReferenceTemplate_var, \
        PortableInterceptor::ObjectReferenceTemplate_out \
      >

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_SEQUENCE__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_SEQUENCE__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<PortableInterceptor::ObjectReferenceTemplateSeq>

# pragma instantiate \
    TAO::Var_Size_Arg_Traits< \
        PortableInterceptor::ObjectReferenceTemplateSeq, \
        PortableInterceptor::ObjectReferenceTemplateSeq_var, \
        PortableInterceptor::ObjectReferenceTemplateSeq_out \
      >

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_IORINFO__ARG_TRAITS_TMPLINST_CS_)
#define _PORTABLEINTERCEPTOR_IORINFO__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<PortableInterceptor::IORInfo>

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        PortableInterceptor::IORInfo_ptr, \
        PortableInterceptor::IORInfo_var, \
        PortableInterceptor::IORInfo_out \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::In_Var_Size_Argument_T< \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableInterceptor::IORInfo, \
        TAO::Objref_Traits<PortableInterceptor::IORInfo> \
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableInterceptor::IORInfo, \
        TAO::Objref_Traits<PortableInterceptor::IORInfo> \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

