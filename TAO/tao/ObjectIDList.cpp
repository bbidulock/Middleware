/* -*- C++ -*- */
// $Id$
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html
//
// Hand Modified by Vishal Kachroo <vishal@cs.wustl.edu>
//

#include "tao/ObjectIDList.h"
#include "tao/Typecode.h"
#include "tao/ORB.h"
#include "tao/Any.h"

#if !defined (__ACE_INLINE__)
#include "tao/ObjectIDList.i"
#endif /* !defined INLINE */

#if !defined (_CORBA_ORB_OBJECTIDLIST_CS_)
#define _CORBA_ORB_OBJECTIDLIST_CS_

// *************************************************************
// CORBA::ORB_ObjectIdList
// *************************************************************

CORBA::ORB_ObjectIdList::ORB_ObjectIdList (void)
{}
CORBA::ORB_ObjectIdList::ORB_ObjectIdList (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_String_Sequence
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_String_Sequence
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
CORBA::ORB_ObjectIdList::ORB_ObjectIdList (CORBA::ULong max, CORBA::ULong length, char * *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_String_Sequence
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_String_Sequence
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
CORBA::ORB_ObjectIdList::ORB_ObjectIdList (const CORBA::ORB_ObjectIdList &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_String_Sequence
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_String_Sequence
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
CORBA::ORB_ObjectIdList::~ORB_ObjectIdList (void) // dtor
{}


#endif /* end #if !defined */

static const CORBA::Long _oc_CORBA_ORB_ObjectIdList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  39, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x434f5242), ACE_NTOHL (0x412f4f52), ACE_NTOHL (0x422f4f62), ACE_NTOHL (0x6a656374), ACE_NTOHL (0x49644c69), ACE_NTOHL (0x73743a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/ORB/ObjectIdList:1.0
  13, ACE_NTOHL (0x4f626a65), ACE_NTOHL (0x63744964), ACE_NTOHL (0x4c697374), ACE_NTOHL (0x0),  // name = ObjectIdList
  CORBA::tk_sequence, // typecode kind
  84, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_alias, // typecode kind for typedefs
    68, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      35, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x434f5242), ACE_NTOHL (0x412f4f52), ACE_NTOHL (0x422f4f62), ACE_NTOHL (0x6a656374), ACE_NTOHL (0x49643a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/ORB/ObjectId:1.0
      9, ACE_NTOHL (0x4f626a65), ACE_NTOHL (0x63744964), ACE_NTOHL (0x0),  // name = ObjectId
      CORBA::tk_string,
      0, // string length
  0,
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_ORB_ObjectIdList (CORBA::tk_alias, sizeof (_oc_CORBA_ORB_ObjectIdList), (char *) &_oc_CORBA_ORB_ObjectIdList, 0, sizeof (CORBA::ORB_ObjectIdList));
CORBA::TypeCode_ptr CORBA::ORB::_tc_ObjectIdList = &_tc_TAO_tc_CORBA_ORB_ObjectIdList;

void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ORB_ObjectIdList &_tao_elem
  ) // copying
{
    TAO_OutputCDR stream;
    stream << _tao_elem;

    _tao_any._tao_replace (CORBA::ORB::_tc_ObjectIdList,
                           TAO_ENCAP_BYTE_ORDER,
                           stream.begin ());
}

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ORB_ObjectIdList &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm << _tao_sequence[i].in ());
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean
operator>> (TAO_InputCDR &strm, CORBA::ORB_ObjectIdList &_tao_sequence)
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
    return _tao_marshal_flag;
  }
  return 0; // error
}

void CORBA::ORB_ObjectIdList::_tao_any_destructor (void *x)
{
  CORBA::ORB_ObjectIdList *tmp = ACE_static_cast (CORBA::ORB_ObjectIdList*, x);
  delete tmp;
}

void operator<<= (CORBA::Any &_tao_any, CORBA::ORB_ObjectIdList *_tao_elem)
{
    TAO_OutputCDR stream;
    stream << *_tao_elem;

    _tao_any._tao_replace (CORBA::ORB::_tc_ObjectIdList,
                           TAO_ENCAP_BYTE_ORDER,
                           stream.begin (),
                           1,
                           _tao_elem,
                           CORBA::ORB_ObjectIdList::_tao_any_destructor);
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::ORB_ObjectIdList *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::ORB::_tc_ObjectIdList ACE_ENV_ARG_PARAMETER)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA::ORB_ObjectIdList *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA::ORB_ObjectIdList, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr (),
                           _tao_any._tao_byte_order ());
      if (stream >> *_tao_elem)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            CORBA::ORB::_tc_ObjectIdList,
            1,
            _tao_elem,
            CORBA::ORB_ObjectIdList::_tao_any_destructor);
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
