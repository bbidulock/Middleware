// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    CDR.h
//
// = DESCRIPTION
//     Common Data Representation (CDR) marshaling streams.
//
//     This implementation assumes that the native numeric
//     representation is two's complement for integers, IEEE
//     single/double for floats.  Also that characters are in ISO
//     Latin/1.
//
//     Note that CDR itself makes no such assumptions, but this
//     implementation makes such assumptions for reasons of
//     efficiency.  Careful enhancements could preserve that
//     efficiency where the assumptions are true, yet still allow the
//     code to work when they aren't true.
//
//     The implementation expects that buffers are aligned according
//     to the strongest CDR alignment restriction.
//
//     NOTE: this does everything "CDR 1.1" does ... that is, it
//     supports the five extended OMG-IDL data types in UNO Appendix
//     A, which provide richer arithmetic types (64 bit integers,
//     "quad precision" FP) and UNICODE-based characters and strings.
//     Those types are not standard parts of OMG-IDL at this time.
//
//     THREADING NOTE: CDR data structures must be protected against
//     concurrent access by their owning thread.
//
// = AUTHOR
//     Copyright 1994-1995 by Sun Microsystems, Inc.
//     Many enhancements added by Aniruddha Gokhale and Carlos O'Ryan.
//
// ============================================================================

#ifndef TAO_CDR_H
#define TAO_CDR_H

#include "tao/corbafwd.h"
#include "tao/Typecode.h"

class TAO_ORB_Core;

class TAO_Export TAO_OutputCDR : public ACE_OutputCDR
{
  //
  // = TITLE
  //   A CDR stream for writing, i.e. for marshalling.
  //
  // = DESCRIPTION
  //   This class is based on the the CORBA spec for Java (98-02-29),
  //   java class omg.org.CORBA.portable.OutputStream.
  //   It diverts in a few ways:
  //     + Operations taking arrays don't have offsets, because in C++
  //     it is easier to describe an array starting from x+offset.
  //     + Operations return an error status, because exceptions are
  //     not widely available in C++ (yet).
  //
  //   A particularly useful static member function for this buffer is
  //   an interpretive encoding routine, usable as a typecode
  //   interpreter callback.  Ditto for decoding.  These are used to
  //   support all OMG-IDL datatypes, even those not supported
  //   directly by put/get primitives.
  //
public:
  friend class TAO_InputCDR;
  // For reading from a output CDR stream.

  // The default values for the allocators and memcpy_tradeoff
  // in these constructors are not 0, but are generated by the
  // ORB. Refer to the constructor bodies in CDR.cpp for the
  // code that supplies these values to the base class constructor.

  TAO_OutputCDR (size_t size = 0,
                 int byte_order = ACE_CDR_BYTE_ORDER,
                 ACE_Allocator* buffer_allocator = 0,
                 ACE_Allocator* data_block_allocator = 0,
                 size_t memcpy_tradeoff = 0,
                 ACE_Char_Codeset_Translator *char_translator = 0,
                 ACE_WChar_Codeset_Translator *wchar_translator = 0);
  // Default constructor, allocates <size> bytes in the internal
  // buffer, if <size> == 0 it allocates the default size.

  TAO_OutputCDR (char *data,
                 size_t size,
                 int byte_order = ACE_CDR_BYTE_ORDER,
                 ACE_Allocator* buffer_allocator = 0,
                 ACE_Allocator* data_block_allocator = 0,
                 size_t memcpy_tradeoff = 0,
                 ACE_Char_Codeset_Translator *char_translator = 0,
                 ACE_WChar_Codeset_Translator *wchar_translator = 0);
  // Build a CDR stream with an initial buffer, it will *not* remove
  // <data>, since it did not allocated it.

  TAO_OutputCDR (ACE_Message_Block *data,
                 int byte_order = ACE_CDR_BYTE_ORDER,
                 size_t memcpy_tradeoff = 0,
                 ACE_Char_Codeset_Translator *char_translator = 0,
                 ACE_WChar_Codeset_Translator *wchar_translator = 0);
  // Build a CDR stream with an initial Message_Block chain, it will *not*
  // remove <data>, since it did not allocate it.

  ~TAO_OutputCDR (void);
  // Destructor.

  CORBA::TypeCode::traverse_status append (CORBA::TypeCode_ptr tc,
                                           TAO_InputCDR *src,
                                           CORBA_Environment &ACE_TRY_ENV =
                                           TAO_default_environment ());
  // Append the contents of the CDR stream based on information
  // described by <tc>; returning any errors in <TAO_IN_ENV>.

  // @@ TODO: do we want a special method to write an array of
  // strings and wstrings?

  // = TAO specific methods.

  CORBA::TypeCode::traverse_status encode (CORBA::TypeCode_ptr tc,
                                           const void *data,
                                           const void *,
                                           CORBA_Environment &ACE_TRY_ENV =
                                           TAO_default_environment ());
  // Marshalls the contents of <data> as described by the TypeCode in
  // <tc>. Any errors are reported though the <TAO_IN_ENV> parameter.

private:
  TAO_OutputCDR (const TAO_OutputCDR& rhs);
  TAO_OutputCDR& operator= (const TAO_OutputCDR& rhs);
  // disallow copying...
};

class TAO_Export TAO_InputCDR : public ACE_InputCDR
{
  //
  // = TITLE
  //   A CDR stream for reading, i.e. for demarshalling.
  //
  // = DESCRIPTION
  //   This class is based on the the CORBA spec for Java (98-02-29),
  //   java class omg.org.CORBA.portable.InputStream.
  //   It diverts in a few ways:
  //     + Operations to retrieve basic types take parameters by
  //     reference.
  //     + Operations taking arrays don't have offsets, because in C++
  //     it is easier to describe an array starting from x+offset.
  //     + Operations return an error status, because exceptions are
  //     not widely available in C++ (yet).
  //
  //   A particularly useful static member function for this buffer is
  //   an interpretive encoding routine, usable as a typecode
  //   interpreter callback.  Ditto for decoding.  These are used to
  //   support all OMG-IDL datatypes, even those not supported
  //   directly by put/get primitives.
public:
  TAO_InputCDR (const char* buf,
                size_t bufsiz,
                int byte_order = ACE_CDR_BYTE_ORDER,
                TAO_ORB_Core* orb_core = 0);
  // Create an input stream from an arbitrary buffer, care must be
  // exercised wrt alignment, because this contructor will *not* work
  // if the buffer is unproperly aligned.

  TAO_InputCDR (size_t bufsiz,
                int byte_order = ACE_CDR_BYTE_ORDER,
                TAO_ORB_Core* orb_core = 0);
  // Create an empty input stream. The caller is responsible for
  // putting the right data and providing the right alignment.

  TAO_InputCDR (const ACE_Message_Block *data,
                int byte_order = ACE_CDR_BYTE_ORDER,
                TAO_ORB_Core* orb_core = 0);
  // Create an input stream from an ACE_Message_Block

  TAO_InputCDR (ACE_Data_Block *data,
                int byte_order = ACE_CDR_BYTE_ORDER,
                TAO_ORB_Core* orb_core = 0);
  // Create an input stream from an ACE_Data_Block

  TAO_InputCDR (const TAO_InputCDR& rhs);
  // Make a copy of the current stream state, but does not copy the
  // internal buffer; so the same stream can be read multiple times
  // efficiently.

  TAO_InputCDR (const TAO_InputCDR& rhs,
                size_t size,
                ACE_CDR::Long offset);
  // When interpreting indirected TypeCodes it is useful to make a
  // "copy" of the stream starting in the new position.

  TAO_InputCDR (const TAO_InputCDR& rhs,
                size_t size);
  // This creates an encapsulated stream, the first byte must be (per
  // the spec) the byte order of the encapsulation.  The default
  // values for the allocators in this constructor are not 0, but are
  // generated by the ORB. Refer to the constructor body in CDR.cpp
  // for the code that supplies these values to the base class
  // constructor.

  TAO_InputCDR (const TAO_OutputCDR& rhs,
                ACE_Allocator* buffer_allocator = 0,
                ACE_Allocator* data_block_allocator = 0,
                TAO_ORB_Core* orb_core = 0);
  // Create an input CDR from an output CDR.

  ~TAO_InputCDR (void);
  // destructor

  // = TAO specific methods.

  CORBA::TypeCode::traverse_status decode (CORBA::TypeCode_ptr tc,
                                           const void *data,
                                           const void *,
                                           CORBA_Environment &ACE_TRY_ENV =
                                           TAO_default_environment ());
  // Demarshall the contents of the CDR stream into <data> as
  // described by <tc>; returning any errors in <TAO_IN_ENV>.

  CORBA::TypeCode::traverse_status skip (CORBA::TypeCode_ptr tc,
                                         CORBA_Environment &ACE_TRY_ENV =
                                         TAO_default_environment ());
  // Skip the contents of the CDR stream based on information
  // described by <tc>; returning any errors in <TAO_IN_ENV>.

  TAO_ORB_Core *orb_core (void) const;
  // Accessor

private:
  void init_translators (void);

private:
  TAO_ORB_Core* orb_core_;
  // The ORB_Core, required to extract object references.
};

// This operators are too complex to be inline....
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR& cdr,
                                             const CORBA::Any &x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR& cdr,
                                             const CORBA::TypeCode *x);

extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR& cdr,
                                             CORBA::Any &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR& cdr,
                                             CORBA::TypeCode *&x);

#if defined(__ACE_INLINE__)
# include "tao/CDR.i"
#else

// CDR output operators for CORBA types

extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             CORBA::Short x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             CORBA::UShort x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             CORBA::Long x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             CORBA::ULong x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             CORBA::LongLong x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             CORBA::ULongLong x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR& os,
                                             CORBA::LongDouble x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             CORBA::Float x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             CORBA::Double x);
extern TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                             const CORBA::Char* x);

// CDR input operators for CORBA types

extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::Short &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::UShort &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::Long &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::ULong &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::LongLong &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::ULongLong &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::LongDouble &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::Float &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::Double &x);
extern TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                             CORBA::Char* &x);

#endif /* __ACE_INLINE */

#endif /* TAO_CDR_H */
