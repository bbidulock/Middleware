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

#include "IORManip_Loader.h"
#include "tao/Typecode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Property[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  33,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x494f502f),
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x494f525f),
  ACE_NTOHL (0x50726f70),
  ACE_NTOHL (0x65727479),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/TAO_IOR_Property:1.0
    17,
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x494f525f),
  ACE_NTOHL (0x50726f70),
  ACE_NTOHL (0x65727479),
  ACE_NTOHL (0x0),  // name = TAO_IOR_Property
  };

static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Property (
    CORBA::tk_objref,
    sizeof (_oc_TAO_IOP_TAO_IOR_Property),
    (char *) &_oc_TAO_IOP_TAO_IOR_Property,
    0,
    0
  );

namespace TAO_IOP
{
  ::CORBA::TypeCode_ptr _tc_TAO_IOR_Property =
    &_tc_TAO_tc_TAO_IOP_TAO_IOR_Property;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Manipulation_IORList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  45,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x494f502f),
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x494f525f),
  ACE_NTOHL (0x4d616e69),
  ACE_NTOHL (0x70756c61),
  ACE_NTOHL (0x74696f6e),
  ACE_NTOHL (0x2f494f52),
  ACE_NTOHL (0x4c697374),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/TAO_IOR_Manipulation/IORList:1.0
    8,
  ACE_NTOHL (0x494f524c),
  ACE_NTOHL (0x69737400),  // name = IORList
    CORBA::tk_sequence, // typecode kind
  68, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_objref,
    52, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      29,
      ACE_NTOHL (0x49444c3a),
      ACE_NTOHL (0x6f6d672e),
      ACE_NTOHL (0x6f72672f),
      ACE_NTOHL (0x434f5242),
      ACE_NTOHL (0x412f4f62),
      ACE_NTOHL (0x6a656374),
      ACE_NTOHL (0x3a312e30),
      ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/Object:1.0
            7,
      ACE_NTOHL (0x4f626a65),
      ACE_NTOHL (0x63740000),  // name = Object

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_IORList (
    CORBA::tk_alias,
    sizeof (_oc_TAO_IOP_TAO_IOR_Manipulation_IORList),
    (char *) &_oc_TAO_IOP_TAO_IOR_Manipulation_IORList,
    0,
    0
  );

::CORBA::TypeCode_ptr TAO_IOP::TAO_IOR_Manipulation::_tc_IORList =
  &_tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_IORList;

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Manipulation[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  37,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x494f502f),
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x494f525f),
  ACE_NTOHL (0x4d616e69),
  ACE_NTOHL (0x70756c61),
  ACE_NTOHL (0x74696f6e),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/TAO_IOR_Manipulation:1.0
    21,
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x494f525f),
  ACE_NTOHL (0x4d616e69),
  ACE_NTOHL (0x70756c61),
  ACE_NTOHL (0x74696f6e),
  ACE_NTOHL (0x0),  // name = TAO_IOR_Manipulation
  };

static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation (
    CORBA::tk_objref,
    sizeof (_oc_TAO_IOP_TAO_IOR_Manipulation),
    (char *) &_oc_TAO_IOP_TAO_IOR_Manipulation,
    0,
    0
  );

namespace TAO_IOP
{
  ::CORBA::TypeCode_ptr _tc_TAO_IOR_Manipulation =
    &_tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation;
}

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<TAO_IOP::EmptyProfileList>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;

  if (!(cdr >> id.out ()))
    {
      return false;
    }

  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;

  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO_IOP::EmptyProfileList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::EmptyProfileList>::insert_copy (
      _tao_any,
      TAO_IOP::EmptyProfileList::_tao_any_destructor,
      TAO_IOP::_tc_EmptyProfileList,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::EmptyProfileList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::EmptyProfileList>::insert (
      _tao_any,
      TAO_IOP::EmptyProfileList::_tao_any_destructor,
      TAO_IOP::_tc_EmptyProfileList,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO_IOP::EmptyProfileList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TAO_IOP::EmptyProfileList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO_IOP::EmptyProfileList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO_IOP::EmptyProfileList>::extract (
        _tao_any,
        TAO_IOP::EmptyProfileList::_tao_any_destructor,
        TAO_IOP::_tc_EmptyProfileList,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<TAO_IOP::NotFound>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;

  if (!(cdr >> id.out ()))
    {
      return false;
    }

  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;

  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO_IOP::NotFound &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::NotFound>::insert_copy (
      _tao_any,
      TAO_IOP::NotFound::_tao_any_destructor,
      TAO_IOP::_tc_NotFound,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::NotFound *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::NotFound>::insert (
      _tao_any,
      TAO_IOP::NotFound::_tao_any_destructor,
      TAO_IOP::_tc_NotFound,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO_IOP::NotFound *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TAO_IOP::NotFound *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO_IOP::NotFound *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO_IOP::NotFound>::extract (
        _tao_any,
        TAO_IOP::NotFound::_tao_any_destructor,
        TAO_IOP::_tc_NotFound,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<TAO_IOP::Duplicate>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;

  if (!(cdr >> id.out ()))
    {
      return false;
    }

  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;

  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO_IOP::Duplicate &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::Duplicate>::insert_copy (
      _tao_any,
      TAO_IOP::Duplicate::_tao_any_destructor,
      TAO_IOP::_tc_Duplicate,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::Duplicate *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::Duplicate>::insert (
      _tao_any,
      TAO_IOP::Duplicate::_tao_any_destructor,
      TAO_IOP::_tc_Duplicate,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO_IOP::Duplicate *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TAO_IOP::Duplicate *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO_IOP::Duplicate *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO_IOP::Duplicate>::extract (
        _tao_any,
        TAO_IOP::Duplicate::_tao_any_destructor,
        TAO_IOP::_tc_Duplicate,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<TAO_IOP::Invalid_IOR>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;

  if (!(cdr >> id.out ()))
    {
      return false;
    }

  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;

  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO_IOP::Invalid_IOR &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::Invalid_IOR>::insert_copy (
      _tao_any,
      TAO_IOP::Invalid_IOR::_tao_any_destructor,
      TAO_IOP::_tc_Invalid_IOR,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::Invalid_IOR *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::Invalid_IOR>::insert (
      _tao_any,
      TAO_IOP::Invalid_IOR::_tao_any_destructor,
      TAO_IOP::_tc_Invalid_IOR,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO_IOP::Invalid_IOR *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TAO_IOP::Invalid_IOR *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO_IOP::Invalid_IOR *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO_IOP::Invalid_IOR>::extract (
        _tao_any,
        TAO_IOP::Invalid_IOR::_tao_any_destructor,
        TAO_IOP::_tc_Invalid_IOR,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<TAO_IOP::MultiProfileList>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if (!(cdr >> id.out ()))
    {
      return false;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;
  
  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO_IOP::MultiProfileList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::MultiProfileList>::insert_copy (
      _tao_any,
      TAO_IOP::MultiProfileList::_tao_any_destructor,
      TAO_IOP::_tc_MultiProfileList,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::MultiProfileList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::MultiProfileList>::insert (
      _tao_any,
      TAO_IOP::MultiProfileList::_tao_any_destructor,
      TAO_IOP::_tc_MultiProfileList,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO_IOP::MultiProfileList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TAO_IOP::MultiProfileList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO_IOP::MultiProfileList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO_IOP::MultiProfileList>::extract (
        _tao_any,
        TAO_IOP::MultiProfileList::_tao_any_destructor,
        TAO_IOP::_tc_MultiProfileList,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Property>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Property>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Property>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::TAO_IOR_Property_ptr _tao_elem
  )
{
  TAO_IOP::TAO_IOR_Property_ptr _tao_objptr =
    TAO_IOP::TAO_IOR_Property::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::TAO_IOR_Property_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Property>::insert (
      _tao_any,
      TAO_IOP::TAO_IOR_Property::_tao_any_destructor,
      TAO_IOP::_tc_TAO_IOR_Property,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    TAO_IOP::TAO_IOR_Property_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Property>::extract (
        _tao_any,
        TAO_IOP::TAO_IOR_Property::_tao_any_destructor,
        TAO_IOP::_tc_TAO_IOR_Property,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Manipulation>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Manipulation>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Manipulation>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::TAO_IOR_Manipulation_ptr _tao_elem
  )
{
  TAO_IOP::TAO_IOR_Manipulation_ptr _tao_objptr =
    TAO_IOP::TAO_IOR_Manipulation::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::TAO_IOR_Manipulation_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Manipulation>::insert (
      _tao_any,
      TAO_IOP::TAO_IOR_Manipulation::_tao_any_destructor,
      TAO_IOP::_tc_TAO_IOR_Manipulation,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    TAO_IOP::TAO_IOR_Manipulation_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Manipulation>::extract (
        _tao_any,
        TAO_IOP::TAO_IOR_Manipulation::_tao_any_destructor,
        TAO_IOP::_tc_TAO_IOR_Manipulation,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54



ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<TAO_IOP::TAO_IOR_Manipulation::IORList>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<TAO_IOP::TAO_IOR_Manipulation::IORList>::demarshal_value (TAO_InputCDR &)
{
  return false;
}// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO_IOP::TAO_IOR_Manipulation::IORList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::TAO_IOR_Manipulation::IORList>::insert_copy (
      _tao_any,
      TAO_IOP::TAO_IOR_Manipulation::IORList::_tao_any_destructor,
      TAO_IOP::TAO_IOR_Manipulation::_tc_IORList,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO_IOP::TAO_IOR_Manipulation::IORList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO_IOP::TAO_IOR_Manipulation::IORList>::insert (
      _tao_any,
      TAO_IOP::TAO_IOR_Manipulation::IORList::_tao_any_destructor,
      TAO_IOP::TAO_IOR_Manipulation::_tc_IORList,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO_IOP::TAO_IOR_Manipulation::IORList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TAO_IOP::TAO_IOR_Manipulation::IORList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO_IOP::TAO_IOR_Manipulation::IORList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO_IOP::TAO_IOR_Manipulation::IORList>::extract (
        _tao_any,
        TAO_IOP::TAO_IOR_Manipulation::IORList::_tao_any_destructor,
        TAO_IOP::TAO_IOR_Manipulation::_tc_IORList,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        TAO_IOP::EmptyProfileList
      >;

  template class
    TAO::Any_Dual_Impl_T<
        TAO_IOP::NotFound
      >;

  template class
    TAO::Any_Dual_Impl_T<
        TAO_IOP::Duplicate
      >;

  template class
    TAO::Any_Dual_Impl_T<
        TAO_IOP::Invalid_IOR
      >;

  template class
    TAO::Any_Dual_Impl_T<
        TAO_IOP::MultiProfileList
      >;

  template class
    TAO::Any_Impl_T<
        TAO_IOP::TAO_IOR_Property
      >;

  template class
    TAO::Any_Dual_Impl_T<
        TAO_IOP::TAO_IOR_Manipulation::IORList
      >;

  template class
    TAO::Any_Impl_T<
        TAO_IOP::TAO_IOR_Manipulation
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TAO_IOP::EmptyProfileList \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TAO_IOP::NotFound \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TAO_IOP::Duplicate \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TAO_IOP::Invalid_IOR \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TAO_IOP::MultiProfileList \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        TAO_IOP::TAO_IOR_Property \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TAO_IOP::TAO_IOR_Manipulation::IORList \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        TAO_IOP::TAO_IOR_Manipulation \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
