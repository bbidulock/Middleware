/* -*- C++ -*- $Id$ */

// ================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   GIOPC.h
//
// = DESCRIPTION
//   Generated from GIOP1_2.pidl, that contains a part of the new data
//   type definitions for GIOP1.2 module.
//   The code was generated by the IDL compiler and then hand-crafted
//   to reduce the includes interdependencies.
//   hand crafted by Balachandran Natarajan <bala@cs.wustl.edu>
// ================================================================


#include "tao/GIOPC.h"
#include "tao/Environment.h"
#include "tao/Any.h"


#if !defined (__ACE_INLINE__)
#include "GIOPC.i"
#endif /* !defined INLINE */


static const CORBA::Long _oc_GIOP_AddressingDisposition[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  43, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x47494f50), ACE_NTOHL (0x2f416464), ACE_NTOHL (0x72657373), ACE_NTOHL (0x696e6744), ACE_NTOHL (0x6973706f), ACE_NTOHL (0x73697469), ACE_NTOHL (0x6f6e3a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/GIOP/AddressingDisposition:1.0
  22, ACE_NTOHL (0x41646472), ACE_NTOHL (0x65737369), ACE_NTOHL (0x6e674469), ACE_NTOHL (0x73706f73), ACE_NTOHL (0x6974696f), ACE_NTOHL (0x6e000000),  // name = AddressingDisposition
  CORBA::tk_short,

};
static CORBA::TypeCode _tc_TAO_tc_GIOP_AddressingDisposition (CORBA::tk_alias, sizeof (_oc_GIOP_AddressingDisposition), (char *) &_oc_GIOP_AddressingDisposition, 0, sizeof (GIOP::AddressingDisposition));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (GIOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_AddressingDisposition, &_tc_TAO_tc_GIOP_AddressingDisposition)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (GIOP)
TAO_NAMESPACE_DEFINE (const CORBA::Short, KeyAddr, 0)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (GIOP)
TAO_NAMESPACE_DEFINE (const CORBA::Short, ProfileAddr, 1)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (GIOP)
TAO_NAMESPACE_DEFINE (const CORBA::Short, ReferenceAddr, 2)
TAO_NAMESPACE_END
static const CORBA::Long _oc_GIOP_IORAddressingInfo[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  39, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x47494f50), ACE_NTOHL (0x2f494f52), ACE_NTOHL (0x41646472), ACE_NTOHL (0x65737369), ACE_NTOHL (0x6e67496e), ACE_NTOHL (0x666f3a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/GIOP/IORAddressingInfo:1.0
  18, ACE_NTOHL (0x494f5241), ACE_NTOHL (0x64647265), ACE_NTOHL (0x7373696e), ACE_NTOHL (0x67496e66), ACE_NTOHL (0x6f000000),  // name = IORAddressingInfo
  2, // member count
  23, ACE_NTOHL (0x73656c65), ACE_NTOHL (0x63746564), ACE_NTOHL (0x5f70726f), ACE_NTOHL (0x66696c65), ACE_NTOHL (0x5f696e64), ACE_NTOHL (0x65780000),  // name = selected_profile_index
  CORBA::tk_ulong,

  4, ACE_NTOHL (0x696f7200),  // name = ior
  CORBA::tk_struct, // typecode kind
  288, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    24, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x494f523a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/IOP/IOR:1.0
    4, ACE_NTOHL (0x494f5200),  // name = IOR
    2, // member count
    8, ACE_NTOHL (0x74797065), ACE_NTOHL (0x5f696400),  // name = type_id
    CORBA::tk_string,
    0U, // string length
    9, ACE_NTOHL (0x70726f66), ACE_NTOHL (0x696c6573), ACE_NTOHL (0x0),  // name = profiles
    CORBA::tk_sequence, // typecode kind
    200, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_struct, // typecode kind
      184, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        34, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54616767), ACE_NTOHL (0x65645072), ACE_NTOHL (0x6f66696c), ACE_NTOHL (0x653a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/TaggedProfile:1.0
        14, ACE_NTOHL (0x54616767), ACE_NTOHL (0x65645072), ACE_NTOHL (0x6f66696c), ACE_NTOHL (0x65000000),  // name = TaggedProfile
        2, // member count
        4, ACE_NTOHL (0x74616700),  // name = tag
        CORBA::tk_alias, // typecode kind for typedefs
        60, // encapsulation length
          TAO_ENCAP_BYTE_ORDER, // byte order
          30, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x50726f66), ACE_NTOHL (0x696c6549), ACE_NTOHL (0x643a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/ProfileId:1.0
          10, ACE_NTOHL (0x50726f66), ACE_NTOHL (0x696c6549), ACE_NTOHL (0x64000000),  // name = ProfileId
          CORBA::tk_ulong,


        13, ACE_NTOHL (0x70726f66), ACE_NTOHL (0x696c655f), ACE_NTOHL (0x64617461), ACE_NTOHL (0x0),  // name = profile_data
        CORBA::tk_sequence, // typecode kind
        12, // encapsulation length
          TAO_ENCAP_BYTE_ORDER, // byte order
          CORBA::tk_octet,

          0U,


      0U,


};
static CORBA::TypeCode _tc_TAO_tc_GIOP_IORAddressingInfo (CORBA::tk_struct, sizeof (_oc_GIOP_IORAddressingInfo), (char *) &_oc_GIOP_IORAddressingInfo, 0, sizeof (GIOP::IORAddressingInfo));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (GIOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_IORAddressingInfo, &_tc_TAO_tc_GIOP_IORAddressingInfo)
TAO_NAMESPACE_END

#if !defined (_GIOP_TARGETADDRESS__TAO_SEQ_OCTET_CS_)
#define _GIOP_TARGETADDRESS__TAO_SEQ_OCTET_CS_

// *************************************************************
// GIOP::TargetAddress::_tao_seq_Octet
// *************************************************************

GIOP::TargetAddress::_tao_seq_Octet::_tao_seq_Octet (void)
{}
GIOP::TargetAddress::_tao_seq_Octet::_tao_seq_Octet (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
GIOP::TargetAddress::_tao_seq_Octet::_tao_seq_Octet (CORBA::ULong max, CORBA::ULong length, CORBA::Octet *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
GIOP::TargetAddress::_tao_seq_Octet::_tao_seq_Octet (const _tao_seq_Octet &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
GIOP::TargetAddress::_tao_seq_Octet::~_tao_seq_Octet (void) // dtor
{}


#endif /* end #if !defined */

// *************************************************************
// Operations for union GIOP::TargetAddress
// *************************************************************

// default constructor
GIOP::TargetAddress::TargetAddress (void)
  : TAO_Base_Union ()
{
  ACE_OS::memset (&this->disc_, 0, sizeof (this->disc_));
  ACE_OS::memset (&this->u_, 0, sizeof (this->u_));
}

// copy constructor
GIOP::TargetAddress::TargetAddress (const GIOP::TargetAddress &u)
  : TAO_Base_Union ()
{
  this->disc_ = u.disc_;
  switch (this->disc_)
  {
    case 0:
    {
      ACE_NEW (
          this->u_.object_key_,
          GIOP::TargetAddress::_tao_seq_Octet (*u.u_.object_key_)
        );
    }
    break;
    case 1:
    {
      ACE_NEW (
          this->u_.profile_,
          IOP::TaggedProfile (*u.u_.profile_)
        );
    }
    break;
    case 2:
    {
      ACE_NEW (
          this->u_.ior_,
          GIOP::IORAddressingInfo (*u.u_.ior_)
        );
    }
    break;
    default:
    break;
  }
}

// assignment operator
GIOP::TargetAddress &
GIOP::TargetAddress::operator= (const GIOP::TargetAddress &u)
{
  this->_reset (u.disc_, 0);
  this->disc_ = u.disc_;
  switch (this->disc_)
  {
    case 0:
    {
      ACE_NEW_RETURN (
          this->u_.object_key_,
          GIOP::TargetAddress::_tao_seq_Octet (*u.u_.object_key_),
          *this
        );
    }
    break;
    case 1:
    {
      ACE_NEW_RETURN (
          this->u_.profile_,
          IOP::TaggedProfile (*u.u_.profile_),
          *this
        );
    }
    break;
    case 2:
    {
      ACE_NEW_RETURN (
          this->u_.ior_,
          GIOP::IORAddressingInfo (*u.u_.ior_),
          *this
        );
    }
    break;
    default:
    break;
  }
return *this;
}

// reset method to reset old values of a union
void GIOP::TargetAddress::_reset (CORBA::Short, CORBA::Boolean /*finalize*/)
{
  switch (this->disc_)
  {
    case 0:
      delete this->u_.object_key_;
      this->u_.object_key_ = 0;
      break;
    case 1:
      delete this->u_.profile_;
      this->u_.profile_ = 0;
      break;
    case 2:
      delete this->u_.ior_;
      this->u_.ior_ = 0;
      break;
    default:
      break;
  }
}

// the virtual overloaded access method
void *GIOP::TargetAddress::_access (CORBA::Boolean alloc_flag)
{
  switch (this->disc_)
  {
    case 0:
      if (alloc_flag)
        ACE_NEW_RETURN (this->u_.object_key_, GIOP::TargetAddress::_tao_seq_Octet, 0);
      return this->u_.object_key_;
    case 1:
      if (alloc_flag)
        ACE_NEW_RETURN (this->u_.profile_, IOP::TaggedProfile, 0);
      return this->u_.profile_;
    case 2:
      if (alloc_flag)
        ACE_NEW_RETURN (this->u_.ior_, GIOP::IORAddressingInfo, 0);
      return this->u_.ior_;
    default:
      return 0;
  }
}

static const CORBA::Long _oc_GIOP_TargetAddress[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  35, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x47494f50), ACE_NTOHL (0x2f546172), ACE_NTOHL (0x67657441), ACE_NTOHL (0x64647265), ACE_NTOHL (0x73733a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/GIOP/TargetAddress:1.0
  14, ACE_NTOHL (0x54617267), ACE_NTOHL (0x65744164), ACE_NTOHL (0x64726573), ACE_NTOHL (0x73000000),  // name = TargetAddress
  CORBA::tk_short,

  -1, // default used index
  3, // member count
  ACE_IDL_NSTOHL (0x0000), // union case label (evaluated value)
  11, ACE_NTOHL (0x6f626a65), ACE_NTOHL (0x63745f6b), ACE_NTOHL (0x65790000),  // name = object_key
  CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

    0U,

  ACE_IDL_NSTOHL (0x0001), // union case label (evaluated value)
  8, ACE_NTOHL (0x70726f66), ACE_NTOHL (0x696c6500),  // name = profile
  CORBA::tk_struct, // typecode kind
  184, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    34, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54616767), ACE_NTOHL (0x65645072), ACE_NTOHL (0x6f66696c), ACE_NTOHL (0x653a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/TaggedProfile:1.0
    14, ACE_NTOHL (0x54616767), ACE_NTOHL (0x65645072), ACE_NTOHL (0x6f66696c), ACE_NTOHL (0x65000000),  // name = TaggedProfile
    2, // member count
    4, ACE_NTOHL (0x74616700),  // name = tag
    CORBA::tk_alias, // typecode kind for typedefs
    60, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      30, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x50726f66), ACE_NTOHL (0x696c6549), ACE_NTOHL (0x643a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/ProfileId:1.0
      10, ACE_NTOHL (0x50726f66), ACE_NTOHL (0x696c6549), ACE_NTOHL (0x64000000),  // name = ProfileId
      CORBA::tk_ulong,


    13, ACE_NTOHL (0x70726f66), ACE_NTOHL (0x696c655f), ACE_NTOHL (0x64617461), ACE_NTOHL (0x0),  // name = profile_data
    CORBA::tk_sequence, // typecode kind
    12, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_octet,

      0U,


  ACE_IDL_NSTOHL (0x0002), // union case label (evaluated value)
  4, ACE_NTOHL (0x696f7200),  // name = ior
  CORBA::tk_struct, // typecode kind
  412, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    39, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x47494f50), ACE_NTOHL (0x2f494f52), ACE_NTOHL (0x41646472), ACE_NTOHL (0x65737369), ACE_NTOHL (0x6e67496e), ACE_NTOHL (0x666f3a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/GIOP/IORAddressingInfo:1.0
    18, ACE_NTOHL (0x494f5241), ACE_NTOHL (0x64647265), ACE_NTOHL (0x7373696e), ACE_NTOHL (0x67496e66), ACE_NTOHL (0x6f000000),  // name = IORAddressingInfo
    2, // member count
    23, ACE_NTOHL (0x73656c65), ACE_NTOHL (0x63746564), ACE_NTOHL (0x5f70726f), ACE_NTOHL (0x66696c65), ACE_NTOHL (0x5f696e64), ACE_NTOHL (0x65780000),  // name = selected_profile_index
    CORBA::tk_ulong,

    4, ACE_NTOHL (0x696f7200),  // name = ior
    CORBA::tk_struct, // typecode kind
    288, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      24, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x494f523a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/IOP/IOR:1.0
      4, ACE_NTOHL (0x494f5200),  // name = IOR
      2, // member count
      8, ACE_NTOHL (0x74797065), ACE_NTOHL (0x5f696400),  // name = type_id
      CORBA::tk_string,
      0U, // string length
      9, ACE_NTOHL (0x70726f66), ACE_NTOHL (0x696c6573), ACE_NTOHL (0x0),  // name = profiles
      CORBA::tk_sequence, // typecode kind
      200, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        CORBA::tk_struct, // typecode kind
        184, // encapsulation length
          TAO_ENCAP_BYTE_ORDER, // byte order
          34, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54616767), ACE_NTOHL (0x65645072), ACE_NTOHL (0x6f66696c), ACE_NTOHL (0x653a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/TaggedProfile:1.0
          14, ACE_NTOHL (0x54616767), ACE_NTOHL (0x65645072), ACE_NTOHL (0x6f66696c), ACE_NTOHL (0x65000000),  // name = TaggedProfile
          2, // member count
          4, ACE_NTOHL (0x74616700),  // name = tag
          CORBA::tk_alias, // typecode kind for typedefs
          60, // encapsulation length
            TAO_ENCAP_BYTE_ORDER, // byte order
            30, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x50726f66), ACE_NTOHL (0x696c6549), ACE_NTOHL (0x643a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/ProfileId:1.0
            10, ACE_NTOHL (0x50726f66), ACE_NTOHL (0x696c6549), ACE_NTOHL (0x64000000),  // name = ProfileId
            CORBA::tk_ulong,


          13, ACE_NTOHL (0x70726f66), ACE_NTOHL (0x696c655f), ACE_NTOHL (0x64617461), ACE_NTOHL (0x0),  // name = profile_data
          CORBA::tk_sequence, // typecode kind
          12, // encapsulation length
            TAO_ENCAP_BYTE_ORDER, // byte order
            CORBA::tk_octet,

            0U,


        0U,



};
static CORBA::TypeCode _tc_TAO_tc_GIOP_TargetAddress (CORBA::tk_union, sizeof (_oc_GIOP_TargetAddress), (char *) &_oc_GIOP_TargetAddress, 0, sizeof (GIOP::TargetAddress));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (GIOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_TargetAddress, &_tc_TAO_tc_GIOP_TargetAddress)
TAO_NAMESPACE_END

void operator<<= (CORBA::Any &_tao_any, const GIOP::IORAddressingInfo &_tao_elem) // copying
{
  GIOP::IORAddressingInfo *_any_val;
  ACE_NEW (_any_val, GIOP::IORAddressingInfo (_tao_elem));
  if (!_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (GIOP::_tc_IORAddressingInfo, _any_val, 1, ACE_TRY_ENV); // copy the value
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, GIOP::IORAddressingInfo *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (GIOP::_tc_IORAddressingInfo, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, GIOP::IORAddressingInfo *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (GIOP::_tc_IORAddressingInfo, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (GIOP::IORAddressingInfo *)_tao_any.value ();
      return 1;
      }
    else
    {
      ACE_NEW_RETURN (_tao_elem, GIOP::IORAddressingInfo, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr (),
                           _tao_any._tao_byte_order ());
      if (stream.decode (GIOP::_tc_IORAddressingInfo, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (GIOP::_tc_IORAddressingInfo, _tao_elem, 1, ACE_TRY_ENV);
        ACE_TRY_CHECK;
        return 1;
      }
      else
      {
        delete _tao_elem;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

void operator<<= (
    CORBA::Any &_tao_any,
    const GIOP::TargetAddress &_tao_elem
  )
{
  GIOP::TargetAddress *_any_val;
  ACE_NEW (_any_val, GIOP::TargetAddress (_tao_elem));
  ACE_TRY_NEW_ENV
  {
    TAO_OutputCDR stream;
    stream << *_any_val;
    _tao_any._tao_replace (
        GIOP::_tc_TargetAddress,
        TAO_ENCAP_BYTE_ORDER,
        stream.begin (),
        1,
        _any_val,
        ACE_TRY_ENV
      );
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (
    CORBA::Any &_tao_any,
    GIOP::TargetAddress *_tao_elem
  )
{
  ACE_TRY_NEW_ENV
  {
    TAO_OutputCDR stream;
    stream << *_tao_elem;
    _tao_any._tao_replace (
        GIOP::_tc_TargetAddress,
        TAO_ENCAP_BYTE_ORDER,
        stream.begin (),
        1,
        _tao_elem,
        ACE_TRY_ENV
      );
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    GIOP::TargetAddress *&_tao_elem
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (GIOP::_tc_TargetAddress, ACE_TRY_ENV))
      return 0;
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (GIOP::TargetAddress *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, GIOP::TargetAddress, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr (),
                           _tao_any._tao_byte_order ());
      stream >> *_tao_elem;
      ((CORBA::Any *)&_tao_any)->_tao_replace (
          GIOP::_tc_TargetAddress,
          1,
          ACE_reinterpret_cast(void*,_tao_elem),
          ACE_TRY_ENV
        );
      ACE_TRY_CHECK;

      return 1;
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
  }
  ACE_ENDTRY;
  return 0;
}

#if !defined _TAO_CDR_OP_GIOP_TargetAddress__tao_seq_Octet_CPP_
#define _TAO_CDR_OP_GIOP_TargetAddress__tao_seq_Octet_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const GIOP::TargetAddress::_tao_seq_Octet &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements

#if defined (TAO_NO_COPY_OCTET_SEQUENCES)
    {
      TAO_Unbounded_Sequence<CORBA::Octet> *oseq =
        ACE_static_cast (TAO_Unbounded_Sequence<CORBA::Octet>*, (GIOP::TargetAddress::_tao_seq_Octet *)&_tao_sequence);
      if (oseq->mb ())
        return strm.write_octet_array_mb (oseq->mb ());
      else
        return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }

#else /* TAO_NO_COPY_OCTET_SEQUENCES */
    return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());

#endif /* TAO_NO_COPY_OCTET_SEQUENCES */
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    GIOP::TargetAddress::_tao_seq_Octet &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements

#if defined (TAO_NO_COPY_OCTET_SEQUENCES)
    if (ACE_BIT_DISABLED (strm.start ()->flags (),ACE_Message_Block::DONT_DELETE))
    {
      TAO_Unbounded_Sequence<CORBA::Octet> *oseq =
        ACE_static_cast(TAO_Unbounded_Sequence<CORBA::Octet>*, &_tao_sequence);
      oseq->replace (_tao_seq_len, strm.start ());
      oseq->mb ()->wr_ptr (oseq->mb()->rd_ptr () + _tao_seq_len);
      strm.skip_bytes (_tao_seq_len);
      return 1;
    }
    else
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_seq_len);

#else /* TAO_NO_COPY_OCTET_SEQUENCES */
    return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());

#endif /* TAO_NO_COPY_OCTET_SEQUENCES */
  }
  return 0; // error
}

#endif /* _TAO_CDR_OP_GIOP_TargetAddress__tao_seq_Octet_CPP_ */
