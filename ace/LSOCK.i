/* -*- C++ -*- */
// $Id$

// LSOCK.i

// Simple-minded constructor. 

ASYS_INLINE
ACE_LSOCK::ACE_LSOCK (void)
{
  ACE_TRACE ("ACE_LSOCK::ACE_LSOCK");
}

// Sets the underlying file descriptor.

ASYS_INLINE void
ACE_LSOCK::set_handle (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_LSOCK::set_handle");
  this->aux_handle_ = handle;
}

// Gets the underlying file descriptor.

ASYS_INLINE ACE_HANDLE
ACE_LSOCK::get_handle (void) const
{
  ACE_TRACE ("ACE_LSOCK::get_handle");
  return this->aux_handle_;
}

// Sets the underlying file descriptor. 

ASYS_INLINE
ACE_LSOCK::ACE_LSOCK (ACE_HANDLE handle)
  : aux_handle_ (handle)
{
  ACE_TRACE ("ACE_LSOCK::ACE_LSOCK");
}
