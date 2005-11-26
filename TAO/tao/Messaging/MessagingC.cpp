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


#include "Messaging.h"
#include "tao/CDR.h"
#include "tao/Object_T.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "MessagingC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::ReplyHandler.

Messaging::ReplyHandler_ptr
TAO::Objref_Traits<Messaging::ReplyHandler>::duplicate (
    Messaging::ReplyHandler_ptr p
  )
{
  return Messaging::ReplyHandler::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::ReplyHandler>::release (
    Messaging::ReplyHandler_ptr p
  )
{
  CORBA::release (p);
}

Messaging::ReplyHandler_ptr
TAO::Objref_Traits<Messaging::ReplyHandler>::nil (void)
{
  return Messaging::ReplyHandler::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Messaging::ReplyHandler>::marshal (
    Messaging::ReplyHandler_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  ) = 0;

Messaging::ReplyHandler::ReplyHandler (void)
 : the_TAO_ReplyHandler_Proxy_Broker_ (0)
{
  this->Messaging_ReplyHandler_setup_collocation ();
}

void
Messaging::ReplyHandler::Messaging_ReplyHandler_setup_collocation ()
{
  if (::Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_ReplyHandler_Proxy_Broker_ =
        ::Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer (this);
    }
}

Messaging::ReplyHandler::~ReplyHandler (void)
{}

void 
Messaging::ReplyHandler::_tao_any_destructor (void *_tao_void_pointer)
{
  ReplyHandler *_tao_tmp_pointer =
    static_cast<ReplyHandler *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

Messaging::ReplyHandler_ptr
Messaging::ReplyHandler::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<ReplyHandler>::narrow (
        _tao_objref,
        "IDL:omg.org/Messaging/ReplyHandler:1.0",
        Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

Messaging::ReplyHandler_ptr
Messaging::ReplyHandler::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<ReplyHandler>::unchecked_narrow (
        _tao_objref,
        "IDL:omg.org/Messaging/ReplyHandler:1.0",
        Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

Messaging::ReplyHandler_ptr
Messaging::ReplyHandler::_duplicate (ReplyHandler_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::ReplyHandler::_tao_release (ReplyHandler_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
Messaging::ReplyHandler::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/Messaging/ReplyHandler:1.0"
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
      return this->ACE_NESTED_CLASS ( ::CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

const char* Messaging::ReplyHandler::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/ReplyHandler:1.0";
}

::CORBA::Boolean
Messaging::ReplyHandler::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be\be_visitor_interface/cdr_op_cs.cpp:63

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::ReplyHandler_ptr _tao_objref
  )
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::ReplyHandler_ptr &_tao_objref
  )
{
  ::CORBA::Object_var obj;
  
  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::Messaging::ReplyHandler RHS_SCOPED_NAME;
  
  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer
      );
    
  return 1;
}

TAO_END_VERSIONED_NAMESPACE_DECL
