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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "ServicesC.h"
#include "tao/Any_T.h"
#include "tao/Environment.h"
#include "tao/ORB_Core.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ServicesC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_ServiceType[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  34,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65547970), 
  ACE_NTOHL (0x653a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/ServiceType:1.0
    12,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636554), 
  ACE_NTOHL (0x79706500),  // name = ServiceType
    CORBA::tk_ushort,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceType (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ServiceType),
    (char *) &_oc_CORBA_ServiceType,
    0,
    sizeof (CORBA::ServiceType)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ServiceType,
    &_tc_TAO_tc_CORBA_ServiceType
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_ServiceOption[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x654f7074), 
  ACE_NTOHL (0x696f6e3a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceOption:1.0
    14,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x6963654f), 
  ACE_NTOHL (0x7074696f), 
  ACE_NTOHL (0x6e000000),  // name = ServiceOption
    CORBA::tk_ulong,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceOption (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ServiceOption),
    (char *) &_oc_CORBA_ServiceOption,
    0,
    sizeof (CORBA::ServiceOption)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ServiceOption,
    &_tc_TAO_tc_CORBA_ServiceOption
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_ServiceDetailType[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  40,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65446574), 
  ACE_NTOHL (0x61696c54), 
  ACE_NTOHL (0x7970653a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailType:1.0
    18,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636544), 
  ACE_NTOHL (0x65746169), 
  ACE_NTOHL (0x6c547970), 
  ACE_NTOHL (0x65000000),  // name = ServiceDetailType
    CORBA::tk_ulong,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceDetailType (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ServiceDetailType),
    (char *) &_oc_CORBA_ServiceDetailType,
    0,
    sizeof (CORBA::ServiceDetailType)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ServiceDetailType,
    &_tc_TAO_tc_CORBA_ServiceDetailType
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_ServiceDetail[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65446574), 
  ACE_NTOHL (0x61696c3a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetail:1.0
    14,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636544), 
  ACE_NTOHL (0x65746169), 
  ACE_NTOHL (0x6c000000),  // name = ServiceDetail
  2, // member count
    20,
  ACE_NTOHL (0x73657276), 
  ACE_NTOHL (0x6963655f), 
  ACE_NTOHL (0x64657461), 
  ACE_NTOHL (0x696c5f74), 
  ACE_NTOHL (0x79706500),  // name = service_detail_type
    CORBA::tk_alias, // typecode kind for typedefs
  76, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    40,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f5365), 
    ACE_NTOHL (0x72766963), 
    ACE_NTOHL (0x65446574), 
    ACE_NTOHL (0x61696c54), 
    ACE_NTOHL (0x7970653a), 
    ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailType:1.0
        18,
    ACE_NTOHL (0x53657276), 
    ACE_NTOHL (0x69636544), 
    ACE_NTOHL (0x65746169), 
    ACE_NTOHL (0x6c547970), 
    ACE_NTOHL (0x65000000),  // name = ServiceDetailType
        CORBA::tk_ulong,


  15,
  ACE_NTOHL (0x73657276), 
  ACE_NTOHL (0x6963655f), 
  ACE_NTOHL (0x64657461), 
  ACE_NTOHL (0x696c0000),  // name = service_detail
    CORBA::tk_alias, // typecode kind for typedefs
  76, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    31,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f4f63), 
    ACE_NTOHL (0x74657453), 
    ACE_NTOHL (0x65713a31), 
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
        9,
    ACE_NTOHL (0x4f637465), 
    ACE_NTOHL (0x74536571), 
    ACE_NTOHL (0x0),  // name = OctetSeq
        CORBA::tk_sequence, // typecode kind
    12, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_octet,

      0U,


};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceDetail (
    CORBA::tk_struct,
    sizeof (_oc_CORBA_ServiceDetail),
    (char *) &_oc_CORBA_ServiceDetail,
    0,
    sizeof (CORBA::ServiceDetail)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ServiceDetail,
    &_tc_TAO_tc_CORBA_ServiceDetail
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_cs.cpp:67

void CORBA::ServiceDetail::_tao_any_destructor (void *_tao_void_pointer)
{
  ServiceDetail *tmp = ACE_static_cast (ServiceDetail*, _tao_void_pointer);
  delete tmp;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_ServiceInformation[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  41,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65496e66), 
  ACE_NTOHL (0x6f726d61), 
  ACE_NTOHL (0x74696f6e), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/ServiceInformation:1.0
    19,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636549), 
  ACE_NTOHL (0x6e666f72), 
  ACE_NTOHL (0x6d617469), 
  ACE_NTOHL (0x6f6e0000),  // name = ServiceInformation
  2, // member count
    16,
  ACE_NTOHL (0x73657276), 
  ACE_NTOHL (0x6963655f), 
  ACE_NTOHL (0x6f707469), 
  ACE_NTOHL (0x6f6e7300),  // name = service_options
    CORBA::tk_sequence, // typecode kind
  84, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_alias, // typecode kind for typedefs
    68, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      36,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x434f5242), 
      ACE_NTOHL (0x412f5365), 
      ACE_NTOHL (0x72766963), 
      ACE_NTOHL (0x654f7074), 
      ACE_NTOHL (0x696f6e3a), 
      ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceOption:1.0
            14,
      ACE_NTOHL (0x53657276), 
      ACE_NTOHL (0x6963654f), 
      ACE_NTOHL (0x7074696f), 
      ACE_NTOHL (0x6e000000),  // name = ServiceOption
            CORBA::tk_ulong,


    0U,

  16,
  ACE_NTOHL (0x73657276), 
  ACE_NTOHL (0x6963655f), 
  ACE_NTOHL (0x64657461), 
  ACE_NTOHL (0x696c7300),  // name = service_details
    CORBA::tk_sequence, // typecode kind
  296, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
    280, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      36,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x434f5242), 
      ACE_NTOHL (0x412f5365), 
      ACE_NTOHL (0x72766963), 
      ACE_NTOHL (0x65446574), 
      ACE_NTOHL (0x61696c3a), 
      ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetail:1.0
            14,
      ACE_NTOHL (0x53657276), 
      ACE_NTOHL (0x69636544), 
      ACE_NTOHL (0x65746169), 
      ACE_NTOHL (0x6c000000),  // name = ServiceDetail
      2, // member count
            20,
      ACE_NTOHL (0x73657276), 
      ACE_NTOHL (0x6963655f), 
      ACE_NTOHL (0x64657461), 
      ACE_NTOHL (0x696c5f74), 
      ACE_NTOHL (0x79706500),  // name = service_detail_type
            CORBA::tk_alias, // typecode kind for typedefs
      76, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        40,
        ACE_NTOHL (0x49444c3a), 
        ACE_NTOHL (0x6f6d672e), 
        ACE_NTOHL (0x6f72672f), 
        ACE_NTOHL (0x434f5242), 
        ACE_NTOHL (0x412f5365), 
        ACE_NTOHL (0x72766963), 
        ACE_NTOHL (0x65446574), 
        ACE_NTOHL (0x61696c54), 
        ACE_NTOHL (0x7970653a), 
        ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailType:1.0
                18,
        ACE_NTOHL (0x53657276), 
        ACE_NTOHL (0x69636544), 
        ACE_NTOHL (0x65746169), 
        ACE_NTOHL (0x6c547970), 
        ACE_NTOHL (0x65000000),  // name = ServiceDetailType
                CORBA::tk_ulong,


      15,
      ACE_NTOHL (0x73657276), 
      ACE_NTOHL (0x6963655f), 
      ACE_NTOHL (0x64657461), 
      ACE_NTOHL (0x696c0000),  // name = service_detail
            CORBA::tk_alias, // typecode kind for typedefs
      76, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        31,
        ACE_NTOHL (0x49444c3a), 
        ACE_NTOHL (0x6f6d672e), 
        ACE_NTOHL (0x6f72672f), 
        ACE_NTOHL (0x434f5242), 
        ACE_NTOHL (0x412f4f63), 
        ACE_NTOHL (0x74657453), 
        ACE_NTOHL (0x65713a31), 
        ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
                9,
        ACE_NTOHL (0x4f637465), 
        ACE_NTOHL (0x74536571), 
        ACE_NTOHL (0x0),  // name = OctetSeq
                CORBA::tk_sequence, // typecode kind
        12, // encapsulation length
          TAO_ENCAP_BYTE_ORDER, // byte order
          CORBA::tk_octet,

          0U,



    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceInformation (
    CORBA::tk_struct,
    sizeof (_oc_CORBA_ServiceInformation),
    (char *) &_oc_CORBA_ServiceInformation,
    0,
    sizeof (CORBA::ServiceInformation)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ServiceInformation,
    &_tc_TAO_tc_CORBA_ServiceInformation
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_cs.cpp:67

void CORBA::ServiceInformation::_tao_any_destructor (void *_tao_void_pointer)
{
  ServiceInformation *tmp = ACE_static_cast (ServiceInformation*, _tao_void_pointer);
  delete tmp;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_cs.cpp:101

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CS_

void
CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::_allocate_buffer (CORBA::ULong length)
{
  CORBA::ULong* tmp = 0;
  tmp = _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::allocbuf (length);
  
  if (this->buffer_ != 0)
    {
      CORBA::ULong *old =
        ACE_reinterpret_cast (CORBA::ULong *, this->buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        {
          tmp[i] = old[i];
        }
      
      if (this->release_)
        {
          _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::freebuf (old);
        }
    }
  
  this->buffer_ = tmp;
}

void
CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::_deallocate_buffer (void)
{
  if (this->buffer_ == 0 || this->release_ == 0)
    {
      return;
    }
  
  CORBA::ULong *tmp =
    ACE_reinterpret_cast (CORBA::ULong *, this->buffer_);
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::freebuf (tmp);
  this->buffer_ = 0;
} 

CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption::~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (void)
{
  this->_deallocate_buffer ();
}

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CS_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CS_

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:250

// *************************************************************
// CORBA::ServiceInformation::_tao_seq_ServiceOption
// *************************************************************

CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_seq_ServiceOption (void)
{}

CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_seq_ServiceOption (CORBA::ULong max)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ULong>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max)
{}

CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_seq_ServiceOption (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ULong *buffer,
    CORBA::Boolean release
  )
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ULong>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max, length, buffer, release)
{}

CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_seq_ServiceOption (const _tao_seq_ServiceOption &seq)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ULong>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (seq)
{}

CORBA::ServiceInformation::_tao_seq_ServiceOption::~_tao_seq_ServiceOption (void) // dtor
{}

void CORBA::ServiceInformation::_tao_seq_ServiceOption::_tao_any_destructor (void *_tao_void_pointer)
{
  _tao_seq_ServiceOption *tmp = ACE_static_cast (_tao_seq_ServiceOption*, _tao_void_pointer);
  delete tmp;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_cs.cpp:101

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CS_

void
CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::_allocate_buffer (CORBA::ULong length)
{
  CORBA::ServiceDetail* tmp = 0;
  tmp = _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::allocbuf (length);
  
  if (this->buffer_ != 0)
    {
      CORBA::ServiceDetail *old =
        ACE_reinterpret_cast (CORBA::ServiceDetail *, this->buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        {
          tmp[i] = old[i];
        }
      
      if (this->release_)
        {
          _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::freebuf (old);
        }
    }
  
  this->buffer_ = tmp;
}

void
CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::_deallocate_buffer (void)
{
  if (this->buffer_ == 0 || this->release_ == 0)
    {
      return;
    }
  
  CORBA::ServiceDetail *tmp =
    ACE_reinterpret_cast (CORBA::ServiceDetail *, this->buffer_);
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::freebuf (tmp);
  this->buffer_ = 0;
} 

CORBA::ServiceInformation::_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail::~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (void)
{
  this->_deallocate_buffer ();
}

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CS_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CS_

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:250

// *************************************************************
// CORBA::ServiceInformation::_tao_seq_ServiceDetail
// *************************************************************

CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_seq_ServiceDetail (void)
{}

CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_seq_ServiceDetail (CORBA::ULong max)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ServiceDetail>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max)
{}

CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_seq_ServiceDetail (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ServiceDetail *buffer,
    CORBA::Boolean release
  )
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ServiceDetail>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max, length, buffer, release)
{}

CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_seq_ServiceDetail (const _tao_seq_ServiceDetail &seq)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ServiceDetail>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (seq)
{}

CORBA::ServiceInformation::_tao_seq_ServiceDetail::~_tao_seq_ServiceDetail (void) // dtor
{}

void CORBA::ServiceInformation::_tao_seq_ServiceDetail::_tao_any_destructor (void *_tao_void_pointer)
{
  _tao_seq_ServiceDetail *tmp = ACE_static_cast (_tao_seq_ServiceDetail*, _tao_void_pointer);
  delete tmp;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceDetail &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::insert_copy (
      _tao_any,
      CORBA::ServiceDetail::_tao_any_destructor,
      CORBA::_tc_ServiceDetail,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceDetail *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::insert (
      _tao_any,
      CORBA::ServiceDetail::_tao_any_destructor,
      CORBA::_tc_ServiceDetail,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceDetail *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::ServiceDetail *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceDetail *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::extract (
        _tao_any,
        CORBA::ServiceDetail::_tao_any_destructor,
        CORBA::_tc_ServiceDetail,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceInformation &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::insert_copy (
      _tao_any,
      CORBA::ServiceInformation::_tao_any_destructor,
      CORBA::_tc_ServiceInformation,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceInformation *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::insert (
      _tao_any,
      CORBA::ServiceInformation::_tao_any_destructor,
      CORBA::_tc_ServiceInformation,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceInformation *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::ServiceInformation *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceInformation *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::extract (
        _tao_any,
        CORBA::ServiceInformation::_tao_any_destructor,
        CORBA::_tc_ServiceInformation,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:125

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceOption_CPP_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceOption_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceInformation::_tao_seq_ServiceOption &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      return strm.write_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceInformation::_tao_seq_ServiceOption &_tao_sequence
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
      return strm.read_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return 0;
}

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceOption_CPP_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:125

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceDetail_CPP_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceDetail_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceInformation::_tao_seq_ServiceDetail &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
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
    CORBA::ServiceInformation::_tao_seq_ServiceDetail &_tao_sequence
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

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_ServiceDetail_CPP_ */

