// $Id$

#ifndef ACE_LOCK_SOCK_ACCEPTOR_CPP
#define ACE_LOCK_SOCK_ACCEPTOR_CPP

#include /**/ "ace/Synch.h"
#include /**/ "ace/LOCK_SOCK_Acceptor.h"

ACE_RCSID(ace, LOCK_SOCK_Acceptor, "$Id$")

template <class ACE_LOCK> int
ACE_LOCK_SOCK_Acceptor<ACE_LOCK>::accept (ACE_SOCK_Stream &stream,
                                          ACE_Addr *remote_address,
                                          ACE_Time_Value *timeout,
                                          int restart,
                                          int reset_new_handle) const
{
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, (ACE_LOCK &) this->lock_, -1);

  return ACE_SOCK_Acceptor::accept (stream,
                                    remote_address,
                                    timeout,
                                    restart,
                                    reset_new_handle);
}

template <class ACE_LOCK> ACE_LOCK &
ACE_LOCK_SOCK_Acceptor<ACE_LOCK>::lock (void)
{
  return this->lock_;
}

#endif /* ACE_LOCK_SOCK_ACCEPTOR_CPP */
