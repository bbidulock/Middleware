/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    LSOCK_Stream.h
//
// = AUTHOR
//    Doug Schmidt 
// 
// ============================================================================

#if !defined (ACE_LOCAL_SOCK_STREAM_H)
#define ACE_LOCAL_SOCK_STREAM_H

#include "ace/SOCK_Stream.h"
#include "ace/UNIX_Addr.h"
#include "ace/LSOCK.h"

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

class ACE_Export ACE_LSOCK_Stream : public ACE_SOCK_Stream, public ACE_LSOCK
{
  // = TITLE
  //     Create a Local ACE_SOCK stream. 
public:
  // = Send/recv methods.
  ssize_t send_msg (const ACE_IO_Vector_Base iov[],
                    size_t n,
                    ACE_HANDLE handle);
  // Send iovecs via <::writev>.

  ssize_t recv_msg (ACE_IO_Vector_Base iov[],
                    size_t n,
                    ACE_HANDLE &handle);
  // Send iovecs via <::writev>.

  ACE_HANDLE get_handle (void) const;
  // Get handle.

  void set_handle (ACE_HANDLE fd); 
  // Overrides set_handle from the base classes.

  // = Meta-type info
  typedef ACE_UNIX_Addr PEER_ADDR;

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

  int get_local_addr (ACE_Addr &) const; 
  // This method simply returns the "local" addr.

  int get_remote_addr (ACE_Addr &) const; 
  // This method returns the "local" addr since it's the same value
  // for UNIX domain sockets.
};

#if !defined (ACE_LACKS_INLINE_FUNCTIONS)
#include "ace/LSOCK_Stream.i"
#endif

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
#endif /* ACE_LOCAL_SOCK_STREAM_H */
