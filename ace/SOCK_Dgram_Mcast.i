/* -*- C++ -*- */
// $Id$

// SOCK_Dgram_Mcast.i

ASYS_INLINE
ACE_SOCK_Dgram_Mcast::~ACE_SOCK_Dgram_Mcast (void)
{
}

ASYS_INLINE int
ACE_SOCK_Dgram_Mcast::set_option (int option, 
				  char optval) 
{ 
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::set_option");
  return this->ACE_SOCK::set_option (IPPROTO_IP, option, 
				     &optval, sizeof (char));
}

ASYS_INLINE ssize_t
ACE_SOCK_Dgram_Mcast::send (const void *buf, 
			    size_t n, int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::send");
  return this->ACE_SOCK_Dgram::send (buf, n, 
				     this->mcast_addr_, flags);
}

ASYS_INLINE ssize_t
ACE_SOCK_Dgram_Mcast::send (const ACE_IO_Vector_Base iov[], 
			    size_t n, int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::send");
  return this->ACE_SOCK_Dgram::send (iov, n, 
				     this->mcast_addr_, flags);
}
