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


#include "GOAC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "GOAC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableServer::NotAGroupObject::NotAGroupObject (void)
  : CORBA::UserException (
        "IDL:omg.org/PortableServer/NotAGroupObject:1.0",
        "NotAGroupObject"
      )
{
}

PortableServer::NotAGroupObject::~NotAGroupObject (void)
{
}

PortableServer::NotAGroupObject::NotAGroupObject (const ::PortableServer::NotAGroupObject &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableServer::NotAGroupObject&
PortableServer::NotAGroupObject::operator= (const ::PortableServer::NotAGroupObject &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void PortableServer::NotAGroupObject::_tao_any_destructor (void *_tao_void_pointer)
{
  NotAGroupObject *_tao_tmp_pointer =
    static_cast<NotAGroupObject*> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableServer::NotAGroupObject *
PortableServer::NotAGroupObject::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/PortableServer/NotAGroupObject:1.0", _tao_excp->_rep_id ()))
    {
      return dynamic_cast<NotAGroupObject *> (_tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *PortableServer::NotAGroupObject::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableServer::NotAGroupObject, 0);
  return retval;
}

CORBA::Exception *
PortableServer::NotAGroupObject::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::PortableServer::NotAGroupObject (*this),
      0
    );
  return result;
}

void PortableServer::NotAGroupObject::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableServer::NotAGroupObject::_tao_encode (
    TAO_OutputCDR &cdr
    ACE_ENV_ARG_DECL
  ) const
{
  if (cdr << *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}

void PortableServer::NotAGroupObject::_tao_decode (
    TAO_InputCDR &cdr
    ACE_ENV_ARG_DECL
  )
{
  if (cdr >> *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr PortableServer::NotAGroupObject::_type (void) const
{
  return ::PortableServer::_tc_NotAGroupObject;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_PORTABLESERVER_IDS_CS_)
#define _PORTABLESERVER_IDS_CS_

PortableServer::IDs::IDs (void)
{}

PortableServer::IDs::IDs (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        PortableServer::ObjectId
      >
    (max)
{}

PortableServer::IDs::IDs (
    CORBA::ULong max,
    CORBA::ULong length,
    PortableServer::ObjectId * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        PortableServer::ObjectId
      >
    (max, length, buffer, release)
{}

PortableServer::IDs::IDs (
    const IDs &seq
  )
  : TAO_Unbounded_Sequence<
        PortableServer::ObjectId
      >
    (seq)
{}

PortableServer::IDs::~IDs (void)
{}

void PortableServer::IDs::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  IDs * _tao_tmp_pointer =
    static_cast<IDs *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::GOA.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::GOA_ptr
TAO::Objref_Traits<PortableServer::GOA>::duplicate (
    PortableServer::GOA_ptr p
  )
{
  return PortableServer::GOA::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<PortableServer::GOA>::release (
    PortableServer::GOA_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::GOA_ptr
TAO::Objref_Traits<PortableServer::GOA>::nil (void)
{
  return PortableServer::GOA::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<PortableServer::GOA>::marshal (
    PortableServer::GOA_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*PortableServer__TAO_GOA_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

PortableServer::GOA::GOA (void)
{}

PortableServer::GOA::~GOA (void)
{}

void 
PortableServer::GOA::_tao_any_destructor (void *_tao_void_pointer)
{
  GOA *_tao_tmp_pointer =
    static_cast<GOA *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::GOA_ptr
PortableServer::GOA::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return GOA::_nil ();
    }
  
  GOA_ptr proxy =
    dynamic_cast<GOA_ptr> (_tao_objref);
  
  return GOA::_duplicate (proxy);
}

PortableServer::GOA_ptr
PortableServer::GOA::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return GOA::_nil ();
    }
  
  GOA_ptr proxy =
    dynamic_cast<GOA_ptr> (_tao_objref);
  
  return GOA::_duplicate (proxy);
}

PortableServer::GOA_ptr
PortableServer::GOA::_duplicate (GOA_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
PortableServer::GOA::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableServer/POA:2.3"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/PortableServer/GOA:1.0"
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

const char* PortableServer::GOA::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/GOA:1.0";
}

CORBA::Boolean
PortableServer::GOA::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_cs.cpp:60

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const PortableServer::NotAGroupObject &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

CORBA::Boolean operator>> (
    TAO_InputCDR &,
    PortableServer::NotAGroupObject&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_PortableServer_IDs_CPP_
#define _TAO_CDR_OP_PortableServer_IDs_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const PortableServer::IDs &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = 1;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    PortableServer::IDs &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return 0;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = 1;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return 0;
}

#endif /* _TAO_CDR_OP_PortableServer_IDs_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_VarSeq_Var_T<
        PortableServer::IDs,
        PortableServer::ObjectId
      >;

  template class
    TAO_Seq_Var_Base_T<
        PortableServer::IDs,
        PortableServer::ObjectId
      >;

  template class
    TAO_Seq_Out_T<
        PortableServer::IDs,
        PortableServer::IDs_var,
        PortableServer::ObjectId
      >;

#if !defined (_CORBA_SEQUENCE__EXPLICIT_CS_)
#define _CORBA_SEQUENCE__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        PortableServer::ObjectId
      >;

#endif /* end #if !defined */

  template class
    TAO::Objref_Traits<
        PortableServer::GOA
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::GOA
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::GOA
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_VarSeq_Var_T< \
        PortableServer::IDs, \
        PortableServer::ObjectId \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        PortableServer::IDs, \
        PortableServer::ObjectId \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        PortableServer::IDs, \
        PortableServer::IDs_var, \
        PortableServer::ObjectId \
      >

#if !defined (_CORBA_SEQUENCE__EXPLICIT_CS_)
#define _CORBA_SEQUENCE__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        PortableServer::ObjectId \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::GOA \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::GOA
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::GOA
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
