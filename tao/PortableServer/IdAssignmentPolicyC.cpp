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


#include "IdAssignmentPolicyC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "IdAssignmentPolicyC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:66

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::IdAssignmentPolicy.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::IdAssignmentPolicy_ptr
TAO::Objref_Traits<PortableServer::IdAssignmentPolicy>::duplicate (
    PortableServer::IdAssignmentPolicy_ptr p
  )
{
  return PortableServer::IdAssignmentPolicy::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<PortableServer::IdAssignmentPolicy>::release (
    PortableServer::IdAssignmentPolicy_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::IdAssignmentPolicy_ptr
TAO::Objref_Traits<PortableServer::IdAssignmentPolicy>::nil (void)
{
  return PortableServer::IdAssignmentPolicy::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
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

void 
PortableServer::IdAssignmentPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  IdAssignmentPolicy *_tao_tmp_pointer =
    static_cast<IdAssignmentPolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::IdAssignmentPolicy_ptr
PortableServer::IdAssignmentPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return IdAssignmentPolicy::_nil ();
    }
  
  IdAssignmentPolicy_ptr proxy =
    dynamic_cast<IdAssignmentPolicy_ptr> (_tao_objref);
  
  return IdAssignmentPolicy::_duplicate (proxy);
}

PortableServer::IdAssignmentPolicy_ptr
PortableServer::IdAssignmentPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return IdAssignmentPolicy::_nil ();
    }
  
  IdAssignmentPolicy_ptr proxy =
    dynamic_cast<IdAssignmentPolicy_ptr> (_tao_objref);
  
  return IdAssignmentPolicy::_duplicate (proxy);
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
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* PortableServer::IdAssignmentPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/IdAssignmentPolicy:2.3";
}

CORBA::Boolean
PortableServer::IdAssignmentPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_cs.cpp:51

CORBA::Boolean operator<< (TAO_OutputCDR &strm, const PortableServer::IdAssignmentPolicyValue &_tao_enumval)
{
  CORBA::ULong _tao_temp = _tao_enumval;
  return strm << _tao_temp;
}

CORBA::Boolean operator>> (TAO_InputCDR &strm, PortableServer::IdAssignmentPolicyValue &_tao_enumval)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean _tao_result = strm >> _tao_temp;
  
  if (_tao_result == 1)
    {
      _tao_enumval = static_cast<PortableServer::IdAssignmentPolicyValue> (_tao_temp);
    }
  
  return _tao_result;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::IdAssignmentPolicy
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::IdAssignmentPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::IdAssignmentPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::IdAssignmentPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::IdAssignmentPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::IdAssignmentPolicy
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
