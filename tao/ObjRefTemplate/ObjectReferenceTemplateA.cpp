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

#include "ObjectReferenceTemplate.h"
#include "tao/Typecode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_PortableInterceptor_ObjectReferenceFactory[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  59,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x496e7465), 
  ACE_NTOHL (0x72636570), 
  ACE_NTOHL (0x746f722f), 
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636546), 
  ACE_NTOHL (0x6163746f), 
  ACE_NTOHL (0x72793a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/PortableInterceptor/ObjectReferenceFactory:1.0
    23,
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636546), 
  ACE_NTOHL (0x6163746f), 
  ACE_NTOHL (0x72790000),  // name = ObjectReferenceFactory
    2, // value modifier
  CORBA::tk_null, // no stateful base valuetype

0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableInterceptor_ObjectReferenceFactory (
    CORBA::tk_value,
    sizeof (_oc_PortableInterceptor_ObjectReferenceFactory),
    (char *) &_oc_PortableInterceptor_ObjectReferenceFactory,
    0,
    0
  );

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr _tc_ObjectReferenceFactory =
    &_tc_TAO_tc_PortableInterceptor_ObjectReferenceFactory;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_PortableInterceptor_ObjectReferenceTemplate[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  60,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x496e7465), 
  ACE_NTOHL (0x72636570), 
  ACE_NTOHL (0x746f722f), 
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636554), 
  ACE_NTOHL (0x656d706c), 
  ACE_NTOHL (0x6174653a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/PortableInterceptor/ObjectReferenceTemplate:1.0
    24,
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636554), 
  ACE_NTOHL (0x656d706c), 
  ACE_NTOHL (0x61746500),  // name = ObjectReferenceTemplate
    2, // value modifier
  CORBA::tk_null, // no stateful base valuetype

3, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableInterceptor_ObjectReferenceTemplate (
    CORBA::tk_value,
    sizeof (_oc_PortableInterceptor_ObjectReferenceTemplate),
    (char *) &_oc_PortableInterceptor_ObjectReferenceTemplate,
    0,
    0
  );

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplate =
    &_tc_TAO_tc_PortableInterceptor_ObjectReferenceTemplate;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_PortableInterceptor_ObjectReferenceTemplateSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  63,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x496e7465), 
  ACE_NTOHL (0x72636570), 
  ACE_NTOHL (0x746f722f), 
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636554), 
  ACE_NTOHL (0x656d706c), 
  ACE_NTOHL (0x61746553), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/PortableInterceptor/ObjectReferenceTemplateSeq:1.0
    27,
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63745265), 
  ACE_NTOHL (0x66657265), 
  ACE_NTOHL (0x6e636554), 
  ACE_NTOHL (0x656d706c), 
  ACE_NTOHL (0x61746553), 
  ACE_NTOHL (0x65710000),  // name = ObjectReferenceTemplateSeq
    CORBA::tk_sequence, // typecode kind
  124, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_value, // typecode kind
    480, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      60,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x506f7274), 
      ACE_NTOHL (0x61626c65), 
      ACE_NTOHL (0x496e7465), 
      ACE_NTOHL (0x72636570), 
      ACE_NTOHL (0x746f722f), 
      ACE_NTOHL (0x4f626a65), 
      ACE_NTOHL (0x63745265), 
      ACE_NTOHL (0x66657265), 
      ACE_NTOHL (0x6e636554), 
      ACE_NTOHL (0x656d706c), 
      ACE_NTOHL (0x6174653a), 
      ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/PortableInterceptor/ObjectReferenceTemplate:1.0
            24,
      ACE_NTOHL (0x4f626a65), 
      ACE_NTOHL (0x63745265), 
      ACE_NTOHL (0x66657265), 
      ACE_NTOHL (0x6e636554), 
      ACE_NTOHL (0x656d706c), 
      ACE_NTOHL (0x61746500),  // name = ObjectReferenceTemplate
            2, // value modifier
      CORBA::tk_null, // no stateful base valuetype

3, // member count
      
    0U,

};

static CORBA::TypeCode _tc_TAO_tc_PortableInterceptor_ObjectReferenceTemplateSeq (
    CORBA::tk_alias,
    sizeof (_oc_PortableInterceptor_ObjectReferenceTemplateSeq),
    (char *) &_oc_PortableInterceptor_ObjectReferenceTemplateSeq,
    0,
    0
  );

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplateSeq =
    &_tc_TAO_tc_PortableInterceptor_ObjectReferenceTemplateSeq;
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/any_op_cs.cpp:57

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ObjectReferenceFactory>::to_value (
    CORBA::ValueBase *&_tao_elem
  ) const
{
  CORBA::add_ref (this->value_);
  _tao_elem = this->value_;
  return 1;
}
// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ObjectReferenceFactory *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ObjectReferenceFactory **_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ObjectReferenceFactory>::insert (
      _tao_any,
      PortableInterceptor::ObjectReferenceFactory::_tao_any_destructor,
      PortableInterceptor::_tc_ObjectReferenceFactory,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ObjectReferenceFactory *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ObjectReferenceFactory>::extract (
        _tao_any,
        PortableInterceptor::ObjectReferenceFactory::_tao_any_destructor,
        PortableInterceptor::_tc_ObjectReferenceFactory,
        _tao_elem
      );
}



// TAO_IDL - Generated from
// be\be_visitor_valuetype/any_op_cs.cpp:57

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ObjectReferenceTemplate>::to_value (
    CORBA::ValueBase *&_tao_elem
  ) const
{
  CORBA::add_ref (this->value_);
  _tao_elem = this->value_;
  return 1;
}
// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ObjectReferenceTemplate *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ObjectReferenceTemplate **_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ObjectReferenceTemplate>::insert (
      _tao_any,
      PortableInterceptor::ObjectReferenceTemplate::_tao_any_destructor,
      PortableInterceptor::_tc_ObjectReferenceTemplate,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ObjectReferenceTemplate *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ObjectReferenceTemplate>::extract (
        _tao_any,
        PortableInterceptor::ObjectReferenceTemplate::_tao_any_destructor,
        PortableInterceptor::_tc_ObjectReferenceTemplate,
        _tao_elem
      );
}



// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableInterceptor::ObjectReferenceTemplateSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ObjectReferenceTemplateSeq>::insert_copy (
      _tao_any,
      PortableInterceptor::ObjectReferenceTemplateSeq::_tao_any_destructor,
      PortableInterceptor::_tc_ObjectReferenceTemplateSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ObjectReferenceTemplateSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ObjectReferenceTemplateSeq>::insert (
      _tao_any,
      PortableInterceptor::ObjectReferenceTemplateSeq::_tao_any_destructor,
      PortableInterceptor::_tc_ObjectReferenceTemplateSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ObjectReferenceTemplateSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableInterceptor::ObjectReferenceTemplateSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableInterceptor::ObjectReferenceTemplateSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableInterceptor::ObjectReferenceTemplateSeq>::extract (
        _tao_any,
        PortableInterceptor::ObjectReferenceTemplateSeq::_tao_any_destructor,
        PortableInterceptor::_tc_ObjectReferenceTemplateSeq,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ObjectReferenceFactory
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ObjectReferenceTemplate
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableInterceptor::ObjectReferenceTemplateSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ObjectReferenceFactory \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ObjectReferenceTemplate \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableInterceptor::ObjectReferenceTemplateSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
