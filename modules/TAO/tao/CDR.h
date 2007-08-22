// -*- C++ -*-

//=============================================================================
/**
 *  @file    CDR.h
 *
 *  $Id$
 *
 *   Common Data Representation (CDR) marshaling streams.
 *
 *   This implementation assumes that the native numeric
 *   representation is two's complement for integers, IEEE
 *   single/double for floats.  Also that characters are in ISO
 *   Latin/1.
 *
 *   Note that CDR itself makes no such assumptions, but this
 *   implementation makes such assumptions for reasons of
 *   efficiency.  Careful enhancements could preserve that
 *   efficiency where the assumptions are true, yet still allow the
 *   code to work when they aren't true.
 *
 *   The implementation expects that buffers are aligned according
 *   to the strongest CDR alignment restriction.
 *
 *   NOTE: this does everything "CDR 1.1" does ... that is, it
 *   supports the five extended OMG-IDL data types in UNO Appendix
 *   A, which provide richer arithmetic types (64 bit integers,
 *   "quad precision" FP) and UNICODE-based characters and strings.
 *   Those types are not standard parts of OMG-IDL at this time.
 *
 *   THREADING NOTE: CDR data structures must be protected against
 *   concurrent access by their owning thread.
 *
 *
 *  @author  Copyright 1994-1995 by Sun Microsystems Inc.
 *  @author  Aniruddha Gokhale
 *  @author  Carlos O'Ryan
 */
//=============================================================================


#ifndef TAO_CDR_H
#define TAO_CDR_H

#include /**/ "ace/pre.h"

#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "tao/TAO_Export.h"
#include "tao/Basic_Types.h"
#include "tao/GIOP_Message_Version.h"

#include "ace/CDR_Stream.h"


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_ORB_Core;
class TAO_GIOP_Fragmentation_Strategy;
class TAO_Stub;

/**
 * @class TAO_OutputCDR
 *
 * @brief A CDR stream for writing, i.e. for marshalling.
 *
 * This class is based on the the CORBA spec for Java (98-02-29),
 * java class omg.org.CORBA.portable.OutputStream.
 * It diverts in a few ways:
 * + Operations taking arrays don't have offsets, because in C++
 * it is easier to describe an array starting from x+offset.
 * + Operations return an error status, because exceptions are
 * not widely available in C++ (yet).
 * A particularly useful static member function for this buffer is
 * an interpretive encoding routine, usable as a typecode
 * interpreter callback.  Ditto for decoding.  These are used to
 * support all OMG-IDL datatypes, even those not supported
 * directly by put/get primitives.
 */
class TAO_Export TAO_OutputCDR : public ACE_OutputCDR
{
public:
  /// For reading from a output CDR stream.
  friend class TAO_InputCDR;

  // The default values for the allocators and memcpy_tradeoff
  // in these constructors are not 0, but are generated by the
  // ORB. Refer to the constructor bodies in CDR.cpp for the
  // code that supplies these values to the base class constructor.

  /// Default constructor, allocates <size> bytes in the internal
  /// buffer, if <size> == 0 it allocates the default size.
  TAO_OutputCDR (size_t size = 0,
                 int byte_order = ACE_CDR_BYTE_ORDER,
                 ACE_Allocator* buffer_allocator = 0,
                 ACE_Allocator* data_block_allocator = 0,
                 ACE_Allocator* message_block_allocator = 0,
                 size_t memcpy_tradeoff = 0,
                 ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                 ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR);

  /// Build a CDR stream with an initial buffer, it will *not* remove
  /// <data>, since it did not allocated it.
  TAO_OutputCDR (char *data,
                 size_t size,
                 int byte_order = ACE_CDR_BYTE_ORDER,
                 ACE_Allocator* buffer_allocator = 0,
                 ACE_Allocator* data_block_allocator = 0,
                 ACE_Allocator* message_block_allocator = 0,
                 size_t memcpy_tradeoff = 0,
                 ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                 ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR);

  /// Build a CDR stream with an initial buffer, it will *not* remove
  /// @a data since it did not allocated it, and enable fragmentation
  /// support.
  TAO_OutputCDR (char *data,
                 size_t size,
                 int byte_order,
                 ACE_Allocator* buffer_allocator,
                 ACE_Allocator* data_block_allocator,
                 ACE_Allocator* message_block_allocator,
                 size_t memcpy_tradeoff,
                 TAO_GIOP_Fragmentation_Strategy * fs,
                 ACE_CDR::Octet major_version,
                 ACE_CDR::Octet minor_version);

  /// Build a CDR stream with an initial Message_Block chain, it will *not*
  /// remove <data>, since it did not allocate it.
  TAO_OutputCDR (ACE_Message_Block *data,
                 int byte_order = ACE_CDR_BYTE_ORDER,
                 size_t memcpy_tradeoff = 0,
                 ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                 ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR);

  /// Build a CDR stream with an initial data block, it will *not* remove
  /// <data_block>, since it did not allocated it.
  TAO_OutputCDR (ACE_Data_Block *data,
                 int byte_order = ACE_CDR_BYTE_ORDER,
                 ACE_Allocator* message_block_allocator = 0,
                 size_t memcpy_tradeoff = 0,
                 TAO_GIOP_Fragmentation_Strategy * fs = 0,
                 ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                 ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR);

  /// Destructor.
  ~TAO_OutputCDR (void);

  // @todo do we want a special method to write an array of
  // strings and wstrings?

  // = TAO specific methods.
  static void throw_stub_exception (int error_num);
  static void throw_skel_exception (int error_num);

  void get_version (TAO_GIOP_Message_Version& giop_version);

  /**
   * @name Outgoing GIOP Fragment Related Methods
   *
   * These methods are only used when fragmenting outgoing GIOP
   * requests and replies.
   */
  //@{
  /// Fragment this output CDR stream if necessary.
  /**
   * Fragmentation will done through GIOP fragments when the length of
   * the CDR stream length will exceed the configured threshold.
   */
  bool fragment_stream (ACE_CDR::ULong pending_alignment,
                        ACE_CDR::ULong pending_length);

  /// Are there more data fragments to come?
  bool more_fragments (void) const;

  /// Specify whether there are more data fragments to come.
  void more_fragments (bool more);

  /// Are we containing compressed data?
  bool compressed (void) const;

  /// Specify whether we have compressed data.
  void compressed (bool compressed);

  /// Set fragmented message attributes.
  void message_attributes (CORBA::ULong request_id,
                           TAO_Stub * stub,
                           int message_semantics,
                           ACE_Time_Value * timeout);

  /// Fragmented message request ID.
  CORBA::ULong request_id (void) const;

  /// Stub object associated with the request.
  TAO_Stub * stub (void) const;

  /// Message semantics (twoway, oneway, reply)
  int message_semantics (void) const;

  /// Maximum time to wait for outgoing message to be sent.
  ACE_Time_Value * timeout (void) const;
  //@}

private:

  // disallow copying...
  TAO_OutputCDR (const TAO_OutputCDR& rhs);
  TAO_OutputCDR& operator= (const TAO_OutputCDR& rhs);

private:

  /**
   * @name Outgoing GIOP Fragment Related Attributes
   *
   * These attributes are only used when fragmenting outgoing GIOP
   * requests and replies.
   */
  //@{
  /// Strategy that sends data currently marshaled into this
  /// TAO_OutputCDR stream if necessary.
  TAO_GIOP_Fragmentation_Strategy * const fragmentation_strategy_;

  /// Are there more data fragments to come?
  bool more_fragments_;

  /// Request ID for the request currently being marshaled.
  CORBA::ULong request_id_;

  /// Stub object associated with the request.
  TAO_Stub * stub_;

  /// Twoway, oneway, reply?
  /**
   * @see TAO_Transport
   */
  int message_semantics_;

  /// Request/reply send timeout.
  ACE_Time_Value * timeout_;

  /// Do we contain compressed data
  bool compressed_;
  //@}

};

/**
 * @class TAO_InputCDR
 *
 * @brief A CDR stream for reading, i.e. for demarshalling.
 *
 * This class is based on the the CORBA spec for Java (98-02-29),
 * java class omg.org.CORBA.portable.InputStream.
 * It diverts in a few ways:
 * + Operations to retrieve basic types take parameters by
 * reference.
 * + Operations taking arrays don't have offsets, because in C++
 * it is easier to describe an array starting from x+offset.
 * + Operations return an error status, because exceptions are
 * not widely available in C++ (yet).
 * A particularly useful static member function for this buffer is
 * an interpretive encoding routine, usable as a typecode
 * interpreter callback.  Ditto for decoding.  These are used to
 * support all OMG-IDL datatypes, even those not supported
 * directly by put/get primitives.
 */
class TAO_Export TAO_InputCDR : public ACE_InputCDR
{
public:
  CORBA::Boolean compressed_;
  /**
   * Create an input stream from an arbitrary buffer, care must be
   * exercised wrt alignment, because this contructor will *not* work
   * if the buffer is unproperly aligned.
   */
  TAO_InputCDR (const char* buf,
                size_t bufsiz,
                int byte_order = ACE_CDR_BYTE_ORDER,
                ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR,
                TAO_ORB_Core* orb_core = 0);

  /// Create an empty input stream. The caller is responsible for
  /// putting the right data and providing the right alignment.
  TAO_InputCDR (size_t bufsiz,
                int byte_order = ACE_CDR_BYTE_ORDER,
                ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR,
                TAO_ORB_Core* orb_core = 0);

  /// Create an input stream from an ACE_Message_Block
  TAO_InputCDR (const ACE_Message_Block *data,
                int byte_order = ACE_CDR_BYTE_ORDER,
                ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR,
                TAO_ORB_Core* orb_core = 0);

  /// Create an input stream from an ACE_Message_Block with an optional lock
  /// used to protect the data.
  TAO_InputCDR (const ACE_Message_Block *data,
                ACE_Lock* lock,
                int byte_order = ACE_CDR_BYTE_ORDER,
                ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR,
                TAO_ORB_Core* orb_core = 0);


  /// Create an input stream from an ACE_Data_Block
  TAO_InputCDR (ACE_Data_Block *data,
                ACE_Message_Block::Message_Flags flag = 0,
                int byte_order = ACE_CDR_BYTE_ORDER,
                ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR,
                TAO_ORB_Core* orb_core = 0);

  /// Create an input stream from an ACE_Data_Block
  TAO_InputCDR (ACE_Data_Block *data,
                ACE_Message_Block::Message_Flags flag,
                size_t read_pointer_position,
                size_t write_pointer_position,
                int byte_order = ACE_CDR_BYTE_ORDER,
                ACE_CDR::Octet major_version = TAO_DEF_GIOP_MAJOR,
                ACE_CDR::Octet minor_version = TAO_DEF_GIOP_MINOR,
                TAO_ORB_Core* orb_core = 0);

  /**
   * Make a copy of the current stream state, but does not copy the
   * internal buffer; so the same stream can be read multiple times
   * efficiently.
   */
  TAO_InputCDR (const TAO_InputCDR& rhs);

  /// When interpreting indirected TypeCodes it is useful to make a
  /// "copy" of the stream starting in the new position.
  TAO_InputCDR (const TAO_InputCDR& rhs,
                size_t size,
                ACE_CDR::Long offset);
  /**
   * This creates an encapsulated stream, the first byte must be (per
   * the spec) the byte order of the encapsulation.  The default
   * values for the allocators in this constructor are not 0, but are
   * generated by the ORB. Refer to the constructor body in CDR.cpp
   * for the code that supplies these values to the base class
   * constructor.
   */
  TAO_InputCDR (const TAO_InputCDR& rhs,
                size_t size);

  /// Create an input CDR from an output CDR.
  TAO_InputCDR (const TAO_OutputCDR& rhs,
                ACE_Allocator* buffer_allocator = 0,
                ACE_Allocator* data_block_allocator = 0,
                ACE_Allocator* message_block_allocator = 0,
                TAO_ORB_Core* orb_core = 0);

  /// Initialize the contents of one CDR from another, without data
  /// copying and with minimimum locking overhead.
  TAO_InputCDR (ACE_InputCDR::Transfer_Contents rhs,
                TAO_ORB_Core* orb_core = 0);

  /// destructor
  ~TAO_InputCDR (void);

  // = TAO specific methods.

  /// Accessor
  TAO_ORB_Core *orb_core (void) const;

  ACE_Message_Block::Message_Flags
    clr_mb_flags( ACE_Message_Block::Message_Flags less_flags );

  // = TAO specific methods.
  static void throw_stub_exception (int error_num);
  static void throw_skel_exception (int error_num);

private:
  /// The ORB_Core, required to extract object references.
  TAO_ORB_Core* orb_core_;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(__ACE_INLINE__)
# include "tao/CDR.inl"
#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// CDR output operators for CORBA types

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      CORBA::Short x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      CORBA::UShort x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      CORBA::Long x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      CORBA::ULong x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      CORBA::LongLong x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      CORBA::ULongLong x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR& os,
                                      CORBA::LongDouble x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      CORBA::Float x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      CORBA::Double x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      const CORBA::Char* x);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &os,
                                      const CORBA::WChar* x);

// CDR input operators for CORBA types

TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::Short &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::UShort &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::Long &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::ULong &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::LongLong &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::ULongLong &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::LongDouble &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::Float &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::Double &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::Char* &x);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &is,
                                      CORBA::WChar* &x);

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* __ACE_INLINE */

#include /**/ "ace/post.h"
#endif /* TAO_CDR_H */
