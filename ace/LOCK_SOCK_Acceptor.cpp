// $Id$

#if !defined (LOCK_SOCK_ACCEPTOR_CPP)
#define LOCK_SOCK_ACCEPTOR_CPP

template <class ACE_LOCK> int
ACE_LOCK_SOCK_Acceptor<ACE_LOCK>::accept (ACE_SOCK_Stream &stream,
                                          ACE_Addr *remote_address,
                                          ACE_Time_Value *timeout,
                                          int restart,
                                          int reset_new_handle) const
{
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, (ACE_LOCK &) this->lock_, -1);
  
  return SUPER::accept (stream, 
                        remote_address, 
                        timeout, 
                        restart, 
                        reset_new_handle);
}

#endif /* LOCK_SOCK_ACCEPTOR_CPP */
