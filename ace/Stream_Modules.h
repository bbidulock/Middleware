/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Stream_Modules.h
//
// = AUTHOR
//    Doug Schmidt 
// 
// ============================================================================

// This needs to go outside of the #if !defined() block.  Don't ask...
#include "ace/Task.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_STREAM_MODULES)
#define ACE_STREAM_MODULES

template <ACE_SYNCH_DECL>
class ACE_Stream_Head : public ACE_Task<ACE_SYNCH_USE>
{
  // = TITLE
  //    Standard module that acts as the head of a ustream.
public:
  ACE_Stream_Head (void);
  // Construction 

  ~ACE_Stream_Head (void);
  // Destruction

  // = ACE_Task hooks
  virtual int open (void *a = 0);
  virtual int close (u_long flags = 0);
  virtual int put (ACE_Message_Block *msg, ACE_Time_Value * = 0);
  virtual int svc (void);

  // = Dynamic linking hooks 
  virtual int init (int argc, ASYS_TCHAR *argv[]);
  virtual int info (ASYS_TCHAR **info_string, size_t length) const;
  virtual int fini (void);

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  int control (ACE_Message_Block *);
  int canonical_flush (ACE_Message_Block *);
  // Performs canonical flushing at the ACE_Stream Head.
};

template <ACE_SYNCH_DECL>
class ACE_Stream_Tail : public ACE_Task<ACE_SYNCH_USE>
{
  // = TITLE
  //    Standard module that acts as the head of a ustream.
public:
  ACE_Stream_Tail (void);
  // Construction 

  ~ACE_Stream_Tail (void);
  // Destruction

  // = ACE_Task hooks
  virtual int open (void *a = 0);
  virtual int close (u_long flags = 0);
  virtual int put (ACE_Message_Block *msg, ACE_Time_Value * = 0);
  virtual int svc (void);

  // = Dynamic linking hooks 
  virtual int init (int argc, ASYS_TCHAR *argv[]);
  virtual int info (ASYS_TCHAR **info_string, size_t length) const;
  virtual int fini (void);

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  int control (ACE_Message_Block *);
  int canonical_flush (ACE_Message_Block *);
  // Performs canonical flushing at the ACE_Stream tail.
};

template <ACE_SYNCH_DECL>
class ACE_Thru_Task : public ACE_Task<ACE_SYNCH_USE>
{
  // = TITLE
  //    Standard module that acts as a "no op", simply passing on all
  //    data to its adjacent neighbor.
public:
  ACE_Thru_Task (void);
  // Construction 

  ~ACE_Thru_Task (void);
  // Destruction

  // = ACE_Task hooks
  virtual int open (void *a = 0);
  virtual int close (u_long flags = 0);
  virtual int put (ACE_Message_Block *msg, ACE_Time_Value * = 0);
  virtual int svc (void);

  // = Dynamic linking hooks
  virtual int init (int argc, ASYS_TCHAR *argv[]);
  virtual int info (ASYS_TCHAR **info_string, size_t length) const;
  virtual int fini (void);

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.
};

#if defined (__ACE_INLINE__)
#include "ace/Stream_Modules.i"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Stream_Modules.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Stream_Modules.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_STREAM_MODULES */
