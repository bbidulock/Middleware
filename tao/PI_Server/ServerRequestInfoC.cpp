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


#include "tao/PI_Server/ServerRequestInfoC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
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

// Traits specializations for PortableInterceptor::ServerRequestInfo.

PortableInterceptor::ServerRequestInfo_ptr
TAO::Objref_Traits<PortableInterceptor::ServerRequestInfo>::duplicate (
    PortableInterceptor::ServerRequestInfo_ptr p
  )
{
  return PortableInterceptor::ServerRequestInfo::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::ServerRequestInfo>::release (
    PortableInterceptor::ServerRequestInfo_ptr p
  )
{
  ::CORBA::release (p);
}

PortableInterceptor::ServerRequestInfo_ptr
TAO::Objref_Traits<PortableInterceptor::ServerRequestInfo>::nil (void)
{
  return PortableInterceptor::ServerRequestInfo::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::ServerRequestInfo>::marshal (
    PortableInterceptor::ServerRequestInfo_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::ServerRequestInfo::ServerRequestInfo (void)
{}

PortableInterceptor::ServerRequestInfo::~ServerRequestInfo (void)
{}

PortableInterceptor::ServerRequestInfo_ptr
PortableInterceptor::ServerRequestInfo::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ServerRequestInfo::_duplicate (
      dynamic_cast<ServerRequestInfo_ptr> (_tao_objref)
    );
}

PortableInterceptor::ServerRequestInfo_ptr
PortableInterceptor::ServerRequestInfo::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ServerRequestInfo::_duplicate (
      dynamic_cast<ServerRequestInfo_ptr> (_tao_objref)
    );
}

PortableInterceptor::ServerRequestInfo_ptr
PortableInterceptor::ServerRequestInfo::_duplicate (ServerRequestInfo_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
PortableInterceptor::ServerRequestInfo::_tao_release (ServerRequestInfo_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
PortableInterceptor::ServerRequestInfo::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/RequestInfo:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/ServerRequestInfo:1.0"
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

const char* PortableInterceptor::ServerRequestInfo::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/ServerRequestInfo:1.0";
}

::CORBA::Boolean
PortableInterceptor::ServerRequestInfo::marshal (TAO_OutputCDR &)
{
  return false;
}

TAO_END_VERSIONED_NAMESPACE_DECL
