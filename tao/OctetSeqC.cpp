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

#include "OctetSeqC.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "OctetSeqC.i"
#endif /* !defined INLINE */

#include "Any.h"
#include "CDR.h"
#include "Typecode.h"
#include "ORB_Core.h"

#if !defined (_CORBA_OCTETSEQ_CS_)
#define _CORBA_OCTETSEQ_CS_

// *************************************************************
// CORBA::OctetSeq
// *************************************************************

CORBA_OctetSeq::CORBA_OctetSeq (void)
{}
CORBA_OctetSeq::CORBA_OctetSeq (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
CORBA_OctetSeq::CORBA_OctetSeq (CORBA::ULong max, CORBA::ULong length, CORBA::Octet *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
CORBA_OctetSeq::CORBA_OctetSeq (const CORBA_OctetSeq &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
CORBA_OctetSeq::~CORBA_OctetSeq (void) // dtor
{}
void CORBA_OctetSeq::_tao_any_destructor (void *x)
{
  CORBA_OctetSeq *tmp = ACE_static_cast (CORBA_OctetSeq*,x);
  delete tmp;
}


#endif /* end #if !defined */

static const CORBA::Long _oc_CORBA_OctetSeq[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  31, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x434f5242), ACE_NTOHL (0x412f4f63), ACE_NTOHL (0x74657453), ACE_NTOHL (0x65713a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
  9, ACE_NTOHL (0x4f637465), ACE_NTOHL (0x74536571), ACE_NTOHL (0x0),  // name = OctetSeq
  CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

    0U,

};
static CORBA::TypeCode _tc_TAO_tc_CORBA_OctetSeq (CORBA::tk_alias, sizeof (_oc_CORBA_OctetSeq), (char *) &_oc_CORBA_OctetSeq, 0, sizeof (CORBA_OctetSeq));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_OctetSeq, &_tc_TAO_tc_CORBA_OctetSeq)
TAO_NAMESPACE_END

void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA_OctetSeq &_tao_elem
  ) // copying
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
  {
    _tao_any._tao_replace (
        CORBA::_tc_OctetSeq,
        TAO_ENCAP_BYTE_ORDER,
        stream.begin ()
      );
  }
}

void operator<<= (CORBA::Any &_tao_any, CORBA_OctetSeq *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      CORBA::_tc_OctetSeq,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      CORBA_OctetSeq::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_OctetSeq *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const CORBA_OctetSeq*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const CORBA_OctetSeq *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    CORBA::Boolean result =
      type->equivalent (CORBA::_tc_OctetSeq, ACE_TRY_ENV);
    ACE_TRY_CHECK;

    if (!result)
      {
        return 0;
      }

    if (_tao_any.any_owns_data ())
    {
      _tao_elem = ACE_static_cast(
          const CORBA_OctetSeq*,
          _tao_any.value ()
        );
      return 1;
    }
    else
    {
      CORBA_OctetSeq *tmp;
      ACE_NEW_RETURN (tmp, CORBA_OctetSeq, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            CORBA::_tc_OctetSeq,
            1,
            ACE_static_cast (void *, tmp),
            CORBA_OctetSeq::_tao_any_destructor
          );
        _tao_elem = tmp;
        return 1;
      }
      else
      {
        delete tmp;
      }
    }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA_OctetSeq &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
    {
      TAO_Unbounded_Sequence<CORBA::Octet> *oseq =
        ACE_static_cast (TAO_Unbounded_Sequence<CORBA::Octet>*, (CORBA_OctetSeq *)&_tao_sequence);
      if (oseq->mb ())
        return strm.write_octet_array_mb (oseq->mb ());
      else
        return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }

#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());

#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA_OctetSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // If length is 0 we return true.
    if (0 >= _tao_seq_len)
      return 1;
    // retrieve all the elements

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
    if (ACE_BIT_DISABLED (strm.start ()->flags (),
                          ACE_Message_Block::DONT_DELETE))
      {
        TAO_ORB_Core* orb_core = strm.orb_core ();

        if (orb_core != 0 &&
            strm.orb_core ()->resource_factory ()->
            input_cdr_allocator_type_locked () == 1)
          {
            TAO_Unbounded_Sequence<CORBA::Octet> *oseq =
              ACE_static_cast(TAO_Unbounded_Sequence<CORBA::Octet>*, &_tao_sequence);
            oseq->replace (_tao_seq_len, strm.start ());
            oseq->mb ()->wr_ptr (oseq->mb()->rd_ptr () + _tao_seq_len);
            strm.skip_bytes (_tao_seq_len);
            return 1;
          }
      }

    return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_seq_len);

#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());

#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
  }
  return 0; // error
}
