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
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:303


#include "ObjectReferenceTemplateC.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Valuetype/ValueFactory.h"
#include "tao/ORB_Core.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include "tao/Var_Size_Argument_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ObjectReferenceTemplateC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_arg_traits.cpp:379

#if !defined (_CORBA_STRINGSEQ__ARG_TRAITS_CS_)
#define _CORBA_STRINGSEQ__ARG_TRAITS_CS_

  ACE_TEMPLATE_SPECIALIZATION
  class TAO_ORT_Export Arg_Traits<CORBA::StringSeq>
    : public
        Var_Size_Arg_Traits_T<
            CORBA::StringSeq,
            CORBA::StringSeq_var,
            CORBA::StringSeq_out
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:290

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
    sizeof (PortableInterceptor::ObjectReferenceFactory)
  );

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr _tc_ObjectReferenceFactory =
    &_tc_TAO_tc_PortableInterceptor_ObjectReferenceFactory;
}

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_cs.cpp:66

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceFactory>::add_ref (
    PortableInterceptor::ObjectReferenceFactory * p
  )
{
  CORBA::add_ref (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceFactory>::remove_ref (
    PortableInterceptor::ObjectReferenceFactory * p
  )
{
  CORBA::remove_ref (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceFactory>::release (
    PortableInterceptor::ObjectReferenceFactory * p
  )
{
  CORBA::remove_ref (p);
}

PortableInterceptor::ObjectReferenceFactory *
PortableInterceptor::ObjectReferenceFactory::_downcast (CORBA::ValueBase *v)
{
  if (v == 0)
    {
      return 0;
    }

  return dynamic_cast< ::PortableInterceptor::ObjectReferenceFactory * > (v);
}

const char *
PortableInterceptor::ObjectReferenceFactory::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

void
PortableInterceptor::ObjectReferenceFactory::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceFactory *_tao_tmp_pointer =
    static_cast<
        ObjectReferenceFactory *> (
        _tao_void_pointer
      );
  CORBA::remove_ref (_tao_tmp_pointer);
}

CORBA::Boolean PortableInterceptor::ObjectReferenceFactory::_tao_unmarshal (
    TAO_InputCDR &strm,
    ObjectReferenceFactory *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory.out (),
        base,
        ObjectReferenceFactory::_tao_obv_static_repository_id ()
      );

  if (retval == 0)
    {
      return 0;
    }

  if (factory.in () != 0)
    {
      base = factory->create_for_unmarshal ();

      if (base == 0)
        {
          return 0;  // %! except.?
        }

      retval = base->_tao_unmarshal_v (strm);

      if (retval == 0)
        {
          return 0;
        }
    }

  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ObjectReferenceFactory::_downcast (base);
  return retval;
}

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:290

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
    sizeof (PortableInterceptor::ObjectReferenceTemplate)
  );

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplate =
    &_tc_TAO_tc_PortableInterceptor_ObjectReferenceTemplate;
}

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_cs.cpp:66

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceTemplate>::add_ref (
    PortableInterceptor::ObjectReferenceTemplate * p
  )
{
  CORBA::add_ref (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceTemplate>::remove_ref (
    PortableInterceptor::ObjectReferenceTemplate * p
  )
{
  CORBA::remove_ref (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceTemplate>::release (
    PortableInterceptor::ObjectReferenceTemplate * p
  )
{
  CORBA::remove_ref (p);
}

PortableInterceptor::ObjectReferenceTemplate *
PortableInterceptor::ObjectReferenceTemplate::_downcast (CORBA::ValueBase *v)
{
  if (v == 0)
    {
      return 0;
    }

  return dynamic_cast< ::PortableInterceptor::ObjectReferenceTemplate * > (v);
}

const char *
PortableInterceptor::ObjectReferenceTemplate::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

void
PortableInterceptor::ObjectReferenceTemplate::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceTemplate *_tao_tmp_pointer =
    static_cast<
        ObjectReferenceTemplate *> (
        _tao_void_pointer
      );
  CORBA::remove_ref (_tao_tmp_pointer);
}

CORBA::Boolean PortableInterceptor::ObjectReferenceTemplate::_tao_unmarshal (
    TAO_InputCDR &strm,
    ObjectReferenceTemplate *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory.out (),
        base,
        ObjectReferenceTemplate::_tao_obv_static_repository_id ()
      );

  if (retval == 0)
    {
      return 0;
    }

  if (factory.in () != 0)
    {
      base = factory->create_for_unmarshal ();

      if (base == 0)
        {
          return 0;  // %! except.?
        }

      retval = base->_tao_unmarshal_v (strm);

      if (retval == 0)
        {
          return 0;
        }
    }

  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ObjectReferenceTemplate::_downcast (base);
  return retval;
}

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CS_

PortableInterceptor::ObjectReferenceTemplateSeq::ObjectReferenceTemplateSeq (void)
{}

PortableInterceptor::ObjectReferenceTemplateSeq::ObjectReferenceTemplateSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Valuetype_Sequence<
        PortableInterceptor::ObjectReferenceTemplate,
        PortableInterceptor::ObjectReferenceTemplate_var
      >
    (max)
{}

PortableInterceptor::ObjectReferenceTemplateSeq::ObjectReferenceTemplateSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    PortableInterceptor::ObjectReferenceTemplate * * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Valuetype_Sequence<
        PortableInterceptor::ObjectReferenceTemplate,
        PortableInterceptor::ObjectReferenceTemplate_var
      >
    (max, length, buffer, release)
{}

PortableInterceptor::ObjectReferenceTemplateSeq::ObjectReferenceTemplateSeq (
    const ObjectReferenceTemplateSeq &seq
  )
  : TAO_Unbounded_Valuetype_Sequence<
        PortableInterceptor::ObjectReferenceTemplate,
        PortableInterceptor::ObjectReferenceTemplate_var
      >
    (seq)
{}

PortableInterceptor::ObjectReferenceTemplateSeq::~ObjectReferenceTemplateSeq (void)
{}

void PortableInterceptor::ObjectReferenceTemplateSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ObjectReferenceTemplateSeq * _tao_tmp_pointer =
    static_cast<ObjectReferenceTemplateSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:290

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
    sizeof (PortableInterceptor::ObjectReferenceTemplateSeq)
  );

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplateSeq =
    &_tc_TAO_tc_PortableInterceptor_ObjectReferenceTemplateSeq;
}

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/any_op_cs.cpp:57

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
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/any_op_cs.cpp:57

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
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

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

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:490

void
CORBA::add_ref (PortableInterceptor::ObjectReferenceFactory * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (PortableInterceptor::ObjectReferenceFactory * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_cs.cpp:73

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const PortableInterceptor::ObjectReferenceFactory *_tao_valuetype
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        const_cast<
            PortableInterceptor::ObjectReferenceFactory *> (
            _tao_valuetype
          ),
        (ptrdiff_t) &PortableInterceptor::ObjectReferenceFactory::_downcast
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    PortableInterceptor::ObjectReferenceFactory *&_tao_valuetype
  )
{
  return PortableInterceptor::ObjectReferenceFactory::_tao_unmarshal (strm, _tao_valuetype);
}



// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:490

void
CORBA::add_ref (PortableInterceptor::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (PortableInterceptor::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_cs.cpp:73

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const PortableInterceptor::ObjectReferenceTemplate *_tao_valuetype
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        const_cast<
            PortableInterceptor::ObjectReferenceTemplate *> (
            _tao_valuetype
          ),
        (ptrdiff_t) &PortableInterceptor::ObjectReferenceTemplate::_downcast
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    PortableInterceptor::ObjectReferenceTemplate *&_tao_valuetype
  )
{
  return PortableInterceptor::ObjectReferenceTemplate::_tao_unmarshal (strm, _tao_valuetype);
}



// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_CPP_
#define _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const PortableInterceptor::ObjectReferenceTemplateSeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();

  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = 1;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i].in ());
        }

      return _tao_marshal_flag;
    }

  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    PortableInterceptor::ObjectReferenceTemplateSeq &_tao_sequence
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
          _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
        }

      return _tao_marshal_flag;

    }

  return 0;
}

#endif /* _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_CPP_ */

// TAO_IDL - Generated from
// C:\ACE\develop\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:1628

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (_CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<CORBA::StringSeq>;

  template class
    TAO::Var_Size_Arg_Traits_T<
        CORBA::StringSeq,
        CORBA::StringSeq_var,
        CORBA::StringSeq_out
      >;

#endif /* end #if !defined */

  template class
    TAO::Value_Traits<
        PortableInterceptor::ObjectReferenceFactory
      >;

  template class
    TAO_Value_Var_T<
        PortableInterceptor::ObjectReferenceFactory

      >;

  template class
    TAO_Value_Out_T<
        PortableInterceptor::ObjectReferenceFactory

      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ObjectReferenceFactory
      >;

  template class
    TAO::Ret_Var_Size_Argument_T<
        PortableInterceptor::AdapterName,
        PortableInterceptor::AdapterName_var
      >;

  template class
    TAO::Value_Traits<
        PortableInterceptor::ObjectReferenceTemplate
      >;

  template class
    TAO_Value_Var_T<
        PortableInterceptor::ObjectReferenceTemplate

      >;

  template class
    TAO_Value_Out_T<
        PortableInterceptor::ObjectReferenceTemplate

      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ObjectReferenceTemplate
      >;

  template class
    TAO_Valuetype_Manager<
        PortableInterceptor::ObjectReferenceTemplate,
        PortableInterceptor::ObjectReferenceTemplate_var
      >;

  template class
    TAO_MngSeq_Var_T<
        PortableInterceptor::ObjectReferenceTemplateSeq,
        TAO_Valuetype_Manager<
            PortableInterceptor::ObjectReferenceTemplate,
            PortableInterceptor::ObjectReferenceTemplate_var
          >
      >;

  template class
    TAO_Seq_Var_Base_T<
        PortableInterceptor::ObjectReferenceTemplateSeq,
        TAO_Valuetype_Manager<
            PortableInterceptor::ObjectReferenceTemplate,
            PortableInterceptor::ObjectReferenceTemplate_var
          >
      >;

  template class
    TAO_MngSeq_Out_T<
        PortableInterceptor::ObjectReferenceTemplateSeq,
        PortableInterceptor::ObjectReferenceTemplateSeq_var,
        TAO_Valuetype_Manager<
            PortableInterceptor::ObjectReferenceTemplate,
            PortableInterceptor::ObjectReferenceTemplate_var
          >
      >;

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__EXPLICIT_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__EXPLICIT_CS_

  template class
    TAO_Unbounded_Valuetype_Sequence<
        PortableInterceptor::ObjectReferenceTemplate,
        PortableInterceptor::ObjectReferenceTemplate_var
      >;

#endif /* end #if !defined */

  template class
    TAO::Any_Dual_Impl_T<
        PortableInterceptor::ObjectReferenceTemplateSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (_CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<CORBA::StringSeq>

# pragma instantiate \
    TAO::Var_Size_Arg_Traits_T< \
        CORBA::StringSeq, \
        CORBA::StringSeq_var, \
        CORBA::StringSeq_out \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::Value_Traits< \
        PortableInterceptor::ObjectReferenceFactory \
      >

# pragma instantiate \
    TAO_Value_Var_T< \
        PortableInterceptor::ObjectReferenceFactory \

      >

# pragma instantiate \
    TAO_Value_Out_T< \
        PortableInterceptor::ObjectReferenceFactory \

      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ObjectReferenceFactory \
      >

# pragma instantiate \
    TAO::Ret_Var_Size_Argument_T< \
        PortableInterceptor::AdapterName, \
        PortableInterceptor::AdapterName_var \
      >

# pragma instantiate \
    TAO::Value_Traits< \
        PortableInterceptor::ObjectReferenceTemplate \
      >

# pragma instantiate \
    TAO_Value_Var_T< \
        PortableInterceptor::ObjectReferenceTemplate \

      >

# pragma instantiate \
    TAO_Value_Out_T< \
        PortableInterceptor::ObjectReferenceTemplate \

      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ObjectReferenceTemplate \
      >

# pragma instantiate \
    TAO_MngSeq_Var_T< \
        PortableInterceptor::ObjectReferenceTemplateSeq, \
        TAO_Valuetype_Manager< \
            PortableInterceptor::ObjectReferenceTemplate, \
            PortableInterceptor::ObjectReferenceTemplate_var \
          > \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        PortableInterceptor::ObjectReferenceTemplateSeq, \
        TAO_Valuetype_Manager< \
            PortableInterceptor::ObjectReferenceTemplate, \
            PortableInterceptor::ObjectReferenceTemplate_var \
          > \
      >

# pragma instantiate \
    TAO_MngSeq_Out_T< \
        PortableInterceptor::ObjectReferenceTemplateSeq, \
        PortableInterceptor::ObjectReferenceTemplateSeq_var, \
        TAO_Valuetype_Manager< \
            PortableInterceptor::ObjectReferenceTemplate, \
            PortableInterceptor::ObjectReferenceTemplate_var \
          > \
      >

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__EXPLICIT_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Valuetype_Sequence< \
        PortableInterceptor::ObjectReferenceTemplate, \
        PortableInterceptor::ObjectReferenceTemplate_var \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableInterceptor::ObjectReferenceTemplateSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
