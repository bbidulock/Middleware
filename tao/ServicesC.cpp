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
// be/be_codegen.cpp:338


#include "ServicesC.h"
#include "tao/Typecode.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ServicesC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:62

// Arg traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

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

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceType =
    &_tc_TAO_tc_CORBA_ServiceType;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

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

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceOption =
    &_tc_TAO_tc_CORBA_ServiceOption;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

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

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceDetailType =
    &_tc_TAO_tc_CORBA_ServiceDetailType;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

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

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceDetail =
    &_tc_TAO_tc_CORBA_ServiceDetail;
}

// TAO_IDL - Generated from 
// be/be_visitor_structure/structure_cs.cpp:66

void 
CORBA::ServiceDetail::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  ServiceDetail *_tao_tmp_pointer =
    ACE_static_cast (ServiceDetail *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

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

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceInformation =
    &_tc_TAO_tc_CORBA_ServiceInformation;
}

// TAO_IDL - Generated from 
// be/be_visitor_structure/structure_cs.cpp:66

void 
CORBA::ServiceInformation::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  ServiceInformation *_tao_tmp_pointer =
    ACE_static_cast (ServiceInformation *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_CORBA_SERVICEOPTION__CS_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_CORBA_SERVICEOPTION__CS_

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_::_tao_seq_CORBA_ServiceOption_ (void)
{}

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_::_tao_seq_CORBA_ServiceOption_ (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceOption
      >
    (max)
{}

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_::_tao_seq_CORBA_ServiceOption_ (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ULong * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceOption
      >
    (max, length, buffer, release)
{}

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_::_tao_seq_CORBA_ServiceOption_ (
    const _tao_seq_CORBA_ServiceOption_ &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceOption
      >
    (seq)
{}

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_::~_tao_seq_CORBA_ServiceOption_ (void)
{}

void CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  _tao_seq_CORBA_ServiceOption_ * _tao_tmp_pointer =
    ACE_static_cast (_tao_seq_CORBA_ServiceOption_ *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_CORBA_SERVICEDETAIL__CS_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_CORBA_SERVICEDETAIL__CS_

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_::_tao_seq_CORBA_ServiceDetail_ (void)
{}

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_::_tao_seq_CORBA_ServiceDetail_ (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceDetail
      >
    (max)
{}

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_::_tao_seq_CORBA_ServiceDetail_ (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ServiceDetail * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceDetail
      >
    (max, length, buffer, release)
{}

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_::_tao_seq_CORBA_ServiceDetail_ (
    const _tao_seq_CORBA_ServiceDetail_ &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceDetail
      >
    (seq)
{}

CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_::~_tao_seq_CORBA_ServiceDetail_ (void)
{}

void CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  _tao_seq_CORBA_ServiceDetail_ * _tao_tmp_pointer =
    ACE_static_cast (_tao_seq_CORBA_ServiceDetail_ *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_cs.cpp:95

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__CPP_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_ &_tao_sequence
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
    CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_ &_tao_sequence
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

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__CPP_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_cs.cpp:95

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__CPP_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_ &_tao_sequence
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
    CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_ &_tao_sequence
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

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__CPP_ */

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1725

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Var_Var_T<
        CORBA::ServiceDetail
      >;

  template class
    TAO_Var_Base_T<
        CORBA::ServiceDetail
      >;

  template class
    TAO_Out_T<
        CORBA::ServiceDetail,
        CORBA::ServiceDetail_var
      >;

#if !defined (_CORBA_ULONG__EXPLICIT_CS_)
#define _CORBA_ULONG__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        CORBA::ServiceOption
      >;

#endif /* end #if !defined */

#if !defined (_CORBA_SERVICEDETAIL__EXPLICIT_CS_)
#define _CORBA_SERVICEDETAIL__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        CORBA::ServiceDetail
      >;

#endif /* end #if !defined */

  template class
    TAO_Var_Var_T<
        CORBA::ServiceInformation
      >;

  template class
    TAO_Var_Base_T<
        CORBA::ServiceInformation
      >;

  template class
    TAO_Out_T<
        CORBA::ServiceInformation,
        CORBA::ServiceInformation_var
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_Var_Var_T< \
        CORBA::ServiceDetail \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        CORBA::ServiceDetail \
      >

# pragma instantiate \
    TAO_Out_T< \
        CORBA::ServiceDetail, \
        CORBA::ServiceDetail_var \
      >

#if !defined (_CORBA_ULONG__EXPLICIT_CS_)
#define _CORBA_ULONG__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        CORBA::ServiceOption \
      >

#endif /* end #if !defined */

#if !defined (_CORBA_SERVICEDETAIL__EXPLICIT_CS_)
#define _CORBA_SERVICEDETAIL__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        CORBA::ServiceDetail \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_Var_Var_T< \
        CORBA::ServiceInformation \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        CORBA::ServiceInformation \
      >

# pragma instantiate \
    TAO_Out_T< \
        CORBA::ServiceInformation, \
        CORBA::ServiceInformation_var \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

