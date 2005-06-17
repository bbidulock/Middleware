// file      : ace/RMCast/Socket.h
// author    : Boris Kolpackov <boris@kolpackov.net>
// cvs-id    : $Id$

#ifndef ACE_RMCAST_SOCKET_H
#define ACE_RMCAST_SOCKET_H

#include "ace/config-lite.h" // ACE_HANDLE

#include "ace/Auto_Ptr.h"
#include "ace/INET_Addr.h"
#include "ace/Time_Value.h"

#include "RMCast_Export.h"


namespace ACE_RMCast
{
  class Socket_Impl;

  class ACE_RMCast_Export Socket
  {
  public:
    virtual
    ~Socket ();

    // If 'simulator' is 'true' then internal message loss and
    // reordering simulator (on IPv4 level) is turned on.
    //
    Socket (ACE_INET_Addr const& a, bool loop = true, bool simulator = false);

  public:
    virtual void
    send (void const* buf, size_t s);


    // Block if message is not available. Upon successful completion
    // return the next message. Otherwise return -1 and errno set to
    // indicate the error. ENOENT indicates that the sender does not
    // retain the data for this message anymore.
    //
    virtual ssize_t
    recv (void* buf, size_t s);


    // Block for up to <timeout> until message is available. Upon
    // successful completion return the next message. Otherwise
    // return -1 and errno set to indicate the error. ETIME indicates
    // that the operation timed out. ENOENT indicates that the sender
    // does not retain the data for this message anymore.
    //
    virtual ssize_t
    recv (void* buf, size_t s, ACE_Time_Value const& timeout);


    // Block if message is not available. Upon successful completion
    // return the size of the next message. Otherwise return -1 and
    // errno set to indicate the error. ENOENT indicates that the
    // sender does not retain the data for this message anymore.
    //
    virtual ssize_t
    size ();


    // Block for up to <timeout> until message is available. Upon
    // successful completion return the size of the next message.
    // Otherwise return -1 and errno set to indicate the error.
    // ETIME indicates that the operation timed out. ENOENT indicates
    // that the sender does not retain the data for this message anymore.
    //
    virtual ssize_t
    size (ACE_Time_Value const& timeout);

  public:
    // Reactor interface. Note that the handle returned by get_handle()
    // is for signalling purposes only.
    //
    ACE_HANDLE
    get_handle () const;

  private:
    ACE_Auto_Ptr<Socket_Impl> impl_;
  };
}


#endif  // ACE_RMCAST_SOCKET_H
