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

#include "BoundsC.h"
#include "tao/Typecode.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_CORBA_Bounds[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  29,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f426f),
  ACE_NTOHL (0x756e6473),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/Bounds:1.0
    7,
  ACE_NTOHL (0x426f756e),
  ACE_NTOHL (0x64730000),  // name = Bounds
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_Bounds (
    CORBA::tk_except,
    sizeof (_oc_CORBA_Bounds),
    (char *) &_oc_CORBA_Bounds,
    0,
    sizeof (CORBA::Bounds)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_Bounds =
    &_tc_TAO_tc_CORBA_Bounds;
}

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<CORBA::Bounds>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;

  if ((cdr >> id.out ()) == 0)
    {
      return 0;
    }

  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return 0;
    }
  ACE_ENDTRY;

  return 1;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::Bounds &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::Bounds>::insert_copy (
      _tao_any,
      CORBA::Bounds::_tao_any_destructor,
      CORBA::_tc_Bounds,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Bounds *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::Bounds>::insert (
      _tao_any,
      CORBA::Bounds::_tao_any_destructor,
      CORBA::_tc_Bounds,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::Bounds *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::Bounds *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::Bounds *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::Bounds>::extract (
        _tao_any,
        CORBA::Bounds::_tao_any_destructor,
        CORBA::_tc_Bounds,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::Bounds
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::Bounds \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

