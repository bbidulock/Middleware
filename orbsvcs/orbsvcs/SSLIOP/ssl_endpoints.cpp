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
// be/be_codegen.cpp:302


#include "ssl_endpoints.h"
#include "tao/Typecode.h"
#include "tao/Any_Dual_Impl_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:60

// TAO_IDL - Generated from
// be/be_visitor_sequence/sequence_cs.cpp:66

#if !defined (_TAO_SSLENDPOINTSEQUENCE_CS_)
#define _TAO_SSLENDPOINTSEQUENCE_CS_

TAO_SSLEndpointSequence::TAO_SSLEndpointSequence (void)
{}

TAO_SSLEndpointSequence::TAO_SSLEndpointSequence (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        SSLIOP::SSL
      >
    (max)
{}

TAO_SSLEndpointSequence::TAO_SSLEndpointSequence (
    CORBA::ULong max,
    CORBA::ULong length,
    SSLIOP::SSL * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        SSLIOP::SSL
      >
    (max, length, buffer, release)
{}

TAO_SSLEndpointSequence::TAO_SSLEndpointSequence (
    const TAO_SSLEndpointSequence &seq
  )
  : TAO_Unbounded_Sequence<
        SSLIOP::SSL
      >
    (seq)
{}

TAO_SSLEndpointSequence::~TAO_SSLEndpointSequence (void)
{}

void TAO_SSLEndpointSequence::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  TAO_SSLEndpointSequence * _tao_tmp_pointer =
    ACE_static_cast (TAO_SSLEndpointSequence *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_TAO_SSLEndpointSequence[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  32,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x53534c45),
  ACE_NTOHL (0x6e64706f),
  ACE_NTOHL (0x696e7453),
  ACE_NTOHL (0x65717565),
  ACE_NTOHL (0x6e63653a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:TAO_SSLEndpointSequence:1.0
    24,
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x53534c45),
  ACE_NTOHL (0x6e64706f),
  ACE_NTOHL (0x696e7453),
  ACE_NTOHL (0x65717565),
  ACE_NTOHL (0x6e636500),  // name = TAO_SSLEndpointSequence
    CORBA::tk_sequence, // typecode kind
  296, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
    280, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      27,
      ACE_NTOHL (0x49444c3a),
      ACE_NTOHL (0x6f6d672e),
      ACE_NTOHL (0x6f72672f),
      ACE_NTOHL (0x53534c49),
      ACE_NTOHL (0x4f502f53),
      ACE_NTOHL (0x534c3a31),
      ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/SSLIOP/SSL:1.0
            4,
      ACE_NTOHL (0x53534c00),  // name = SSL
      3, // member count
            16,
      ACE_NTOHL (0x74617267),
      ACE_NTOHL (0x65745f73),
      ACE_NTOHL (0x7570706f),
      ACE_NTOHL (0x72747300),  // name = target_supports
            CORBA::tk_alias, // typecode kind for typedefs
      80, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        44,
        ACE_NTOHL (0x49444c3a),
        ACE_NTOHL (0x6f6d672e),
        ACE_NTOHL (0x6f72672f),
        ACE_NTOHL (0x53656375),
        ACE_NTOHL (0x72697479),
        ACE_NTOHL (0x2f417373),
        ACE_NTOHL (0x6f636961),
        ACE_NTOHL (0x74696f6e),
        ACE_NTOHL (0x4f707469),
        ACE_NTOHL (0x6f6e733a),
        ACE_NTOHL (0x312e3800),  // repository ID = IDL:omg.org/Security/AssociationOptions:1.8
                19,
        ACE_NTOHL (0x4173736f),
        ACE_NTOHL (0x63696174),
        ACE_NTOHL (0x696f6e4f),
        ACE_NTOHL (0x7074696f),
        ACE_NTOHL (0x6e730000),  // name = AssociationOptions
                CORBA::tk_ushort,


      16,
      ACE_NTOHL (0x74617267),
      ACE_NTOHL (0x65745f72),
      ACE_NTOHL (0x65717569),
      ACE_NTOHL (0x72657300),  // name = target_requires
            CORBA::tk_alias, // typecode kind for typedefs
      80, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        44,
        ACE_NTOHL (0x49444c3a),
        ACE_NTOHL (0x6f6d672e),
        ACE_NTOHL (0x6f72672f),
        ACE_NTOHL (0x53656375),
        ACE_NTOHL (0x72697479),
        ACE_NTOHL (0x2f417373),
        ACE_NTOHL (0x6f636961),
        ACE_NTOHL (0x74696f6e),
        ACE_NTOHL (0x4f707469),
        ACE_NTOHL (0x6f6e733a),
        ACE_NTOHL (0x312e3800),  // repository ID = IDL:omg.org/Security/AssociationOptions:1.8
                19,
        ACE_NTOHL (0x4173736f),
        ACE_NTOHL (0x63696174),
        ACE_NTOHL (0x696f6e4f),
        ACE_NTOHL (0x7074696f),
        ACE_NTOHL (0x6e730000),  // name = AssociationOptions
                CORBA::tk_ushort,


      5,
      ACE_NTOHL (0x706f7274),
      ACE_NTOHL (0x0),  // name = port
            CORBA::tk_ushort,


    0U,

};

static CORBA::TypeCode _tc_TAO_tc_TAO_SSLEndpointSequence (
    CORBA::tk_alias,
    sizeof (_oc_TAO_SSLEndpointSequence),
    (char *) &_oc_TAO_SSLEndpointSequence,
    0,
    sizeof (TAO_SSLEndpointSequence)
  );

::CORBA::TypeCode_ptr _tc_TAO_SSLEndpointSequence =
  &_tc_TAO_tc_TAO_SSLEndpointSequence;

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_SSLEndpointSequence &_tao_sequence
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
    TAO_SSLEndpointSequence &_tao_sequence
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
