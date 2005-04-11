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
// be\be_codegen.cpp:291


#include "PortableServer.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
#include "tao/Object_Argument_T.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
#if !defined (_PORTABLESERVER_ADAPTERACTIVATOR__ARG_TRAITS_CS_)
#define _PORTABLESERVER_ADAPTERACTIVATOR__ARG_TRAITS_CS_
  
  template<>
  class  Arg_Traits<PortableServer::AdapterActivator>
    : public
        Object_Arg_Traits_T<
            PortableServer::AdapterActivator_ptr,
            PortableServer::AdapterActivator_var,
            PortableServer::AdapterActivator_out,
            TAO::Objref_Traits<PortableServer::AdapterActivator>
          >
  {
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_PORTABLESERVER_POALIST_CS_)
#define _PORTABLESERVER_POALIST_CS_

PortableServer::POAList::POAList (void)
{}

PortableServer::POAList::POAList (
    CORBA::ULong max
  )
  : TAO_Unbounded_Object_Sequence<
        PortableServer::POA,
        PortableServer::POA_var
      >
    (max)
{}

PortableServer::POAList::POAList (
    CORBA::ULong max,
    CORBA::ULong length,
    PortableServer::POA_ptr * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Object_Sequence<
        PortableServer::POA,
        PortableServer::POA_var
      >
    (max, length, buffer, release)
{}

PortableServer::POAList::POAList (
    const POAList &seq
  )
  : TAO_Unbounded_Object_Sequence<
        PortableServer::POA,
        PortableServer::POA_var
      >
    (seq)
{}

PortableServer::POAList::~POAList (void)
{}

void PortableServer::POAList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  POAList * _tao_tmp_pointer =
    static_cast<POAList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::POA.

PortableServer::POA_ptr
TAO::Objref_Traits<PortableServer::POA>::duplicate (
    PortableServer::POA_ptr p
  )
{
  return PortableServer::POA::_duplicate (p);
}

void
TAO::Objref_Traits<PortableServer::POA>::release (
    PortableServer::POA_ptr p
  )
{
  CORBA::release (p);
}

PortableServer::POA_ptr
TAO::Objref_Traits<PortableServer::POA>::nil (void)
{
  return PortableServer::POA::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableServer::POA>::marshal (
    PortableServer::POA_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::AdapterAlreadyExists::AdapterAlreadyExists (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/AdapterAlreadyExists:2.3",
        "AdapterAlreadyExists"
      )
{
}

PortableServer::POA::AdapterAlreadyExists::~AdapterAlreadyExists (void)
{
}

PortableServer::POA::AdapterAlreadyExists::AdapterAlreadyExists (const ::PortableServer::POA::AdapterAlreadyExists &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::AdapterAlreadyExists&
PortableServer::POA::AdapterAlreadyExists::operator= (const ::PortableServer::POA::AdapterAlreadyExists &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::AdapterAlreadyExists::_tao_any_destructor (void *_tao_void_pointer)
{
  AdapterAlreadyExists *_tao_tmp_pointer =
    static_cast<AdapterAlreadyExists *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::AdapterAlreadyExists *
PortableServer::POA::AdapterAlreadyExists::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<AdapterAlreadyExists *> (_tao_excp);
}

const PortableServer::POA::AdapterAlreadyExists *
PortableServer::POA::AdapterAlreadyExists::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const AdapterAlreadyExists *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::AdapterAlreadyExists::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::AdapterAlreadyExists, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::AdapterAlreadyExists::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::AdapterAlreadyExists (*this),
      0
    );
  return result;
}

void PortableServer::POA::AdapterAlreadyExists::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::AdapterAlreadyExists::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::AdapterAlreadyExists::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::AdapterAlreadyExists::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_AdapterAlreadyExists;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::AdapterNonExistent::AdapterNonExistent (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/AdapterNonExistent:2.3",
        "AdapterNonExistent"
      )
{
}

PortableServer::POA::AdapterNonExistent::~AdapterNonExistent (void)
{
}

PortableServer::POA::AdapterNonExistent::AdapterNonExistent (const ::PortableServer::POA::AdapterNonExistent &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::AdapterNonExistent&
PortableServer::POA::AdapterNonExistent::operator= (const ::PortableServer::POA::AdapterNonExistent &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::AdapterNonExistent::_tao_any_destructor (void *_tao_void_pointer)
{
  AdapterNonExistent *_tao_tmp_pointer =
    static_cast<AdapterNonExistent *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::AdapterNonExistent *
PortableServer::POA::AdapterNonExistent::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<AdapterNonExistent *> (_tao_excp);
}

const PortableServer::POA::AdapterNonExistent *
PortableServer::POA::AdapterNonExistent::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const AdapterNonExistent *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::AdapterNonExistent::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::AdapterNonExistent, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::AdapterNonExistent::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::AdapterNonExistent (*this),
      0
    );
  return result;
}

void PortableServer::POA::AdapterNonExistent::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::AdapterNonExistent::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::AdapterNonExistent::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::AdapterNonExistent::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_AdapterNonExistent;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::InvalidPolicy::InvalidPolicy (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/InvalidPolicy:2.3",
        "InvalidPolicy"
      )
{
}

PortableServer::POA::InvalidPolicy::~InvalidPolicy (void)
{
}

PortableServer::POA::InvalidPolicy::InvalidPolicy (const ::PortableServer::POA::InvalidPolicy &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
  this->index = _tao_excp.index;
}

PortableServer::POA::InvalidPolicy&
PortableServer::POA::InvalidPolicy::operator= (const ::PortableServer::POA::InvalidPolicy &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  this->index = _tao_excp.index;
  return *this;
}

void PortableServer::POA::InvalidPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  InvalidPolicy *_tao_tmp_pointer =
    static_cast<InvalidPolicy *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::InvalidPolicy *
PortableServer::POA::InvalidPolicy::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<InvalidPolicy *> (_tao_excp);
}

const PortableServer::POA::InvalidPolicy *
PortableServer::POA::InvalidPolicy::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const InvalidPolicy *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::InvalidPolicy::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::InvalidPolicy, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::InvalidPolicy::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::InvalidPolicy (*this),
      0
    );
  return result;
}

void PortableServer::POA::InvalidPolicy::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::InvalidPolicy::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::InvalidPolicy::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// be\be_visitor_exception/exception_ctor.cpp:66

PortableServer::POA::InvalidPolicy::InvalidPolicy (
    CORBA::UShort _tao_index
  )
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/InvalidPolicy:2.3",
        "InvalidPolicy"
      )
{
  this->index = _tao_index;
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::InvalidPolicy::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_InvalidPolicy;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

#if (TAO_HAS_MINIMUM_POA == 0)

PortableServer::POA::NoServant::NoServant (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/NoServant:2.3",
        "NoServant"
      )
{
}

PortableServer::POA::NoServant::~NoServant (void)
{
}

PortableServer::POA::NoServant::NoServant (const ::PortableServer::POA::NoServant &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::NoServant&
PortableServer::POA::NoServant::operator= (const ::PortableServer::POA::NoServant &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::NoServant::_tao_any_destructor (void *_tao_void_pointer)
{
  NoServant *_tao_tmp_pointer =
    static_cast<NoServant *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::NoServant *
PortableServer::POA::NoServant::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<NoServant *> (_tao_excp);
}

const PortableServer::POA::NoServant *
PortableServer::POA::NoServant::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const NoServant *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::NoServant::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::NoServant, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::NoServant::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::NoServant (*this),
      0
    );
  return result;
}

void PortableServer::POA::NoServant::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::NoServant::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::NoServant::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::NoServant::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_NoServant;
}

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::ObjectAlreadyActive::ObjectAlreadyActive (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/ObjectAlreadyActive:2.3",
        "ObjectAlreadyActive"
      )
{
}

PortableServer::POA::ObjectAlreadyActive::~ObjectAlreadyActive (void)
{
}

PortableServer::POA::ObjectAlreadyActive::ObjectAlreadyActive (const ::PortableServer::POA::ObjectAlreadyActive &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::ObjectAlreadyActive&
PortableServer::POA::ObjectAlreadyActive::operator= (const ::PortableServer::POA::ObjectAlreadyActive &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::ObjectAlreadyActive::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectAlreadyActive *_tao_tmp_pointer =
    static_cast<ObjectAlreadyActive *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::ObjectAlreadyActive *
PortableServer::POA::ObjectAlreadyActive::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<ObjectAlreadyActive *> (_tao_excp);
}

const PortableServer::POA::ObjectAlreadyActive *
PortableServer::POA::ObjectAlreadyActive::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const ObjectAlreadyActive *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::ObjectAlreadyActive::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::ObjectAlreadyActive, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::ObjectAlreadyActive::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::ObjectAlreadyActive (*this),
      0
    );
  return result;
}

void PortableServer::POA::ObjectAlreadyActive::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::ObjectAlreadyActive::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::ObjectAlreadyActive::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::ObjectAlreadyActive::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_ObjectAlreadyActive;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::ObjectNotActive::ObjectNotActive (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/ObjectNotActive:2.3",
        "ObjectNotActive"
      )
{
}

PortableServer::POA::ObjectNotActive::~ObjectNotActive (void)
{
}

PortableServer::POA::ObjectNotActive::ObjectNotActive (const ::PortableServer::POA::ObjectNotActive &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::ObjectNotActive&
PortableServer::POA::ObjectNotActive::operator= (const ::PortableServer::POA::ObjectNotActive &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::ObjectNotActive::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectNotActive *_tao_tmp_pointer =
    static_cast<ObjectNotActive *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::ObjectNotActive *
PortableServer::POA::ObjectNotActive::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<ObjectNotActive *> (_tao_excp);
}

const PortableServer::POA::ObjectNotActive *
PortableServer::POA::ObjectNotActive::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const ObjectNotActive *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::ObjectNotActive::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::ObjectNotActive, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::ObjectNotActive::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::ObjectNotActive (*this),
      0
    );
  return result;
}

void PortableServer::POA::ObjectNotActive::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::ObjectNotActive::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::ObjectNotActive::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::ObjectNotActive::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_ObjectNotActive;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::ServantAlreadyActive::ServantAlreadyActive (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/ServantAlreadyActive:2.3",
        "ServantAlreadyActive"
      )
{
}

PortableServer::POA::ServantAlreadyActive::~ServantAlreadyActive (void)
{
}

PortableServer::POA::ServantAlreadyActive::ServantAlreadyActive (const ::PortableServer::POA::ServantAlreadyActive &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::ServantAlreadyActive&
PortableServer::POA::ServantAlreadyActive::operator= (const ::PortableServer::POA::ServantAlreadyActive &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::ServantAlreadyActive::_tao_any_destructor (void *_tao_void_pointer)
{
  ServantAlreadyActive *_tao_tmp_pointer =
    static_cast<ServantAlreadyActive *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::ServantAlreadyActive *
PortableServer::POA::ServantAlreadyActive::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<ServantAlreadyActive *> (_tao_excp);
}

const PortableServer::POA::ServantAlreadyActive *
PortableServer::POA::ServantAlreadyActive::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const ServantAlreadyActive *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::ServantAlreadyActive::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::ServantAlreadyActive, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::ServantAlreadyActive::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::ServantAlreadyActive (*this),
      0
    );
  return result;
}

void PortableServer::POA::ServantAlreadyActive::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::ServantAlreadyActive::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::ServantAlreadyActive::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::ServantAlreadyActive::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_ServantAlreadyActive;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::ServantNotActive::ServantNotActive (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/ServantNotActive:2.3",
        "ServantNotActive"
      )
{
}

PortableServer::POA::ServantNotActive::~ServantNotActive (void)
{
}

PortableServer::POA::ServantNotActive::ServantNotActive (const ::PortableServer::POA::ServantNotActive &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::ServantNotActive&
PortableServer::POA::ServantNotActive::operator= (const ::PortableServer::POA::ServantNotActive &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::ServantNotActive::_tao_any_destructor (void *_tao_void_pointer)
{
  ServantNotActive *_tao_tmp_pointer =
    static_cast<ServantNotActive *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::ServantNotActive *
PortableServer::POA::ServantNotActive::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<ServantNotActive *> (_tao_excp);
}

const PortableServer::POA::ServantNotActive *
PortableServer::POA::ServantNotActive::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const ServantNotActive *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::ServantNotActive::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::ServantNotActive, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::ServantNotActive::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::ServantNotActive (*this),
      0
    );
  return result;
}

void PortableServer::POA::ServantNotActive::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::ServantNotActive::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::ServantNotActive::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::ServantNotActive::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_ServantNotActive;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::WrongAdapter::WrongAdapter (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/WrongAdapter:2.3",
        "WrongAdapter"
      )
{
}

PortableServer::POA::WrongAdapter::~WrongAdapter (void)
{
}

PortableServer::POA::WrongAdapter::WrongAdapter (const ::PortableServer::POA::WrongAdapter &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::WrongAdapter&
PortableServer::POA::WrongAdapter::operator= (const ::PortableServer::POA::WrongAdapter &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::WrongAdapter::_tao_any_destructor (void *_tao_void_pointer)
{
  WrongAdapter *_tao_tmp_pointer =
    static_cast<WrongAdapter *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::WrongAdapter *
PortableServer::POA::WrongAdapter::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<WrongAdapter *> (_tao_excp);
}

const PortableServer::POA::WrongAdapter *
PortableServer::POA::WrongAdapter::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const WrongAdapter *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::WrongAdapter::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::WrongAdapter, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::WrongAdapter::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::WrongAdapter (*this),
      0
    );
  return result;
}

void PortableServer::POA::WrongAdapter::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::WrongAdapter::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::WrongAdapter::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::WrongAdapter::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_WrongAdapter;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::POA::WrongPolicy::WrongPolicy (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/POA/WrongPolicy:2.3",
        "WrongPolicy"
      )
{
}

PortableServer::POA::WrongPolicy::~WrongPolicy (void)
{
}

PortableServer::POA::WrongPolicy::WrongPolicy (const ::PortableServer::POA::WrongPolicy &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::POA::WrongPolicy&
PortableServer::POA::WrongPolicy::operator= (const ::PortableServer::POA::WrongPolicy &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::POA::WrongPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  WrongPolicy *_tao_tmp_pointer =
    static_cast<WrongPolicy *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::POA::WrongPolicy *
PortableServer::POA::WrongPolicy::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<WrongPolicy *> (_tao_excp);
}

const PortableServer::POA::WrongPolicy *
PortableServer::POA::WrongPolicy::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const WrongPolicy *> (_tao_excp);
}

CORBA::Exception *PortableServer::POA::WrongPolicy::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::POA::WrongPolicy, 0);
  return retval;
}

CORBA::Exception *
PortableServer::POA::WrongPolicy::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::POA::WrongPolicy (*this),
      0
    );
  return result;
}

void PortableServer::POA::WrongPolicy::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::POA::WrongPolicy::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::POA::WrongPolicy::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::POA::WrongPolicy::_tao_type (void) const
{
  return ::PortableServer::POA::_tc_WrongPolicy;
}

PortableServer::POA::POA (void)
{}

PortableServer::POA::~POA (void)
{}

void 
PortableServer::POA::_tao_any_destructor (void *_tao_void_pointer)
{
  POA *_tao_tmp_pointer =
    static_cast<POA *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::POA_ptr
PortableServer::POA::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return POA::_nil ();
    }
  
  POA_ptr proxy =
    dynamic_cast<POA_ptr> (_tao_objref);
  
  return POA::_duplicate (proxy);
}

PortableServer::POA_ptr
PortableServer::POA::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return POA::_nil ();
    }
  
  POA_ptr proxy =
    dynamic_cast<POA_ptr> (_tao_objref);
  
  return POA::_duplicate (proxy);
}

PortableServer::POA_ptr
PortableServer::POA::_duplicate (POA_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableServer::POA::_tao_release (POA_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
PortableServer::POA::_is_a (
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

const char* PortableServer::POA::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/POA:2.3";
}

CORBA::Boolean
PortableServer::POA::marshal (TAO_OutputCDR &)
{
  return false;
}
