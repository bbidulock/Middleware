/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Handle_Set.h
//
// = AUTHOR
//    Doug Schmidt 
// 
// ============================================================================

#if !defined (ACE_HANDLE_SET_H)
#define ACE_HANDLE_SET_H

#include "ace/ACE.h"

class ACE_Export ACE_Handle_Set 
{
  // = TITLE
  //     C++ wrapper for the socket <FD_SET> abstraction.
friend class ACE_Handle_Set_Iterator;
public:
  // = Initialization and termination. 

  enum 
  {
    MAXSIZE = ACE_DEFAULT_REACTOR_SIZE
  };

  // = Initialization methods.
  ACE_Handle_Set (void);
  // Constructor, initializes the bitmask to all 0s.

  ACE_Handle_Set (const ACE_FD_SET_TYPE &mask);

  // = Methods for manipulating bitsets.
  void reset (void);
  // Initialize the bitmask to all 0s and reset the associated fields.

  int is_set (ACE_HANDLE) const;
  // Checks whether handle is enabled.

  void set_bit (ACE_HANDLE);
  // Enables the handle.

  void clr_bit (ACE_HANDLE);
  // Disables the handle.

  int num_set (void) const;
  // Returns a count of the number of enabled bits.

  ACE_HANDLE max_set (void) const;
  // Returns the number of the large bit.

  void sync (ACE_HANDLE max);
  // Synchronize the underlying FD_SET with the MAX_FD and the SIZE.

  operator fd_set *();
  // Returns a pointer to the underlying fd_set.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  int size_;
  // Size of the set, i.e., a count of the number of enabled bits.

  ACE_HANDLE max_handle_;
  // Current max handle.

  fd_set mask_;
  // Bitmask.

  enum
  {
    WORDSIZE = NFDBITS,
#if !defined (ACE_WIN32)
    NUM_WORDS = howmany (MAXSIZE, NFDBITS),
#endif /* ACE_WIN32 */
    NBITS = 256
  };

  int count_bits (u_long n) const;
  // Counts the number of bits enabled in N.  Uses a table lookup to
  // speed up the count.

  void set_max (ACE_HANDLE max);
  // Resets the MAX_FD after a clear of the original MAX_FD.

  static const char nbits_[NBITS];
  // Table that maps bytes to counts of the enabled bits.
};

class ACE_Export ACE_Handle_Set_Iterator
  // = TITLE
  //     Iterator for the <ACE_Handle_Set> abstraction. 
{
public:
  ACE_Handle_Set_Iterator (const ACE_Handle_Set &hs);
  // Constructor.

  ACE_HANDLE operator () (void);
  // "Next" operator.  Returns the next unseen <ACE_HANDLE> in the
  // <Handle_Set> up to <handle_set_.max_handle_>).  When all the
  // handles have been seen returns <ACE_INVALID_HANDLE>.  Advances
  // the iterator automatically, so you need not call <operator++>
  // (which is now obsolete).

  void operator++ (void);
  // This is a no-op and no longer does anything.  It's only here for
  // backwards compatibility.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  const ACE_Handle_Set &handles_;
  // The <Handle_Set> we are iterating through.

#if defined (ACE_WIN32)
  u_int handle_index_; 
#else
  int handle_index_; 
#endif /* ACE_WIN32 */
  // Index of the bit we're examining in the current <word_num_> word.

  int word_num_;
  // Number of the word we're iterating over (typically between 0..7).

#if !defined (ACE_WIN32)
  fd_mask word_val_;
  // Value of the bits in the word we're iterating on.
#endif /* ACE_WIN32 */
};

#if defined (__ACE_INLINE__)
#include "ace/Handle_Set.i"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HANDLE_SET */
