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


#include "WrongTransactionC.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "tao/SystemException.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "WrongTransactionC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:66

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

CORBA::WrongTransaction::WrongTransaction (void)
  : CORBA::UserException (
        "IDL:omg.org/CORBA/WrongTransaction:1.0",
        "WrongTransaction"
      )
{
}

CORBA::WrongTransaction::~WrongTransaction (void)
{
}

CORBA::WrongTransaction::WrongTransaction (const ::CORBA::WrongTransaction &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

CORBA::WrongTransaction&
CORBA::WrongTransaction::operator= (const ::CORBA::WrongTransaction &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void CORBA::WrongTransaction::_tao_any_destructor (void *_tao_void_pointer)
{
  WrongTransaction *_tao_tmp_pointer =
    static_cast<WrongTransaction *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

CORBA::WrongTransaction *
CORBA::WrongTransaction::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<WrongTransaction *> (_tao_excp);
}

const CORBA::WrongTransaction *
CORBA::WrongTransaction::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const WrongTransaction *> (_tao_excp);
}

CORBA::Exception *CORBA::WrongTransaction::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::WrongTransaction, 0);
  return retval;
}

CORBA::Exception *
CORBA::WrongTransaction::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::CORBA::WrongTransaction (*this),
      0
    );
  return result;
}

void CORBA::WrongTransaction::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::WrongTransaction::_tao_encode (
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

void CORBA::WrongTransaction::_tao_decode (
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
CORBA::TypeCode_ptr CORBA::WrongTransaction::_type (void) const
{
  return ::CORBA::_tc_WrongTransaction;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_WrongTransaction[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  39,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5772), 
  ACE_NTOHL (0x6f6e6754), 
  ACE_NTOHL (0x72616e73), 
  ACE_NTOHL (0x61637469), 
  ACE_NTOHL (0x6f6e3a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/WrongTransaction:1.0
    17,
  ACE_NTOHL (0x57726f6e), 
  ACE_NTOHL (0x67547261), 
  ACE_NTOHL (0x6e736163), 
  ACE_NTOHL (0x74696f6e), 
  ACE_NTOHL (0x0),  // name = WrongTransaction
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_WrongTransaction (
    CORBA::tk_except,
    sizeof (_oc_CORBA_WrongTransaction),
    (char *) &_oc_CORBA_WrongTransaction,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_WrongTransaction =
    &_tc_TAO_tc_CORBA_WrongTransaction;
}

// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_cs.cpp:60

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::WrongTransaction &_tao_aggregate
  )
{
  // Marshal the repository ID.
  return (strm << _tao_aggregate._rep_id ());
}

CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::WrongTransaction&
  )
{
  return true;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1509

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
