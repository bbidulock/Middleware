// $Id$

//=============================================================================
/**
 *  @file    SOCK_Netlink.cpp
 *
 *  SOCK_Netlink.cpp,v 5.4.2 2004/10/10 
 * 
 *  @author Raz Ben Yehuda <raziebe@013.net.il>
 */
//=============================================================================


#include /* */ "ace/OS.h"
#if defined (ACE_HAS_LINUX_NETLINK)

#include /* */  "ace/Log_Msg.h"
#include /* */  "ace/ACE.h"
#include /* */  "ace/OS_NS_string.h"
#include /* */  "ace/OS_NS_unistd.h"
#include /* */  "ace/SOCK_Netlink.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
     # pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#  include "ace/SOCK_Netlink.inl"
#endif /* __ACE_INLINE__ */
  
ACE_ALLOC_HOOK_DEFINE (ACE_SOCK_Netlink)

//
//    I use the netlink sockets as  a conneted sockets ( very much the 
//     same as udp connected sockets).
//    I believe that it is easier instead of sending the address every time i send a message.
//    
int ACE_SOCK_Netlink::open (ACE_Netlink_Addr &local,
                      int protocol_family,
                      int protocol) //! protocol of your choosing                       
{
  ACE_TRACE ("ACE_SOCK_Netlink::open");
  

  if ( ACE_SOCK::open (SOCK_RAW,
                       protocol_family, //! RAW or DGRAM valid
                       protocol,0) < 0 ) {
                ACE_TRACE ("ACE_SOCK_Netlink::open failed to open");		
		return -1;	      
    }

  if (ACE_OS::bind(this->get_handle(),
                        (sockaddr*)local.get_addr(),
                        local.get_addr_size())  == -1 ) { 
                ACE_TRACE ("ACE_SOCK_Netlink::open failed to bind socket"); 
		return -1;	      	
  }
  return 0; 
}

// Here's the general-purpose constructor used by a connectionless
// datagram ``server''...

ACE_SOCK_Netlink::ACE_SOCK_Netlink (ACE_Netlink_Addr &local,
                                int protocol_family,
                                int protocol)                                
{
  ACE_TRACE ("ACE_SOCK_Netlink::ACE_SOCK_Netlink");

  if (this->open (local,
                  protocol_family,
                  protocol)  == -1)                  
    ACE_ERROR ((LM_ERROR,
                ACE_LIB_TEXT ("%p\n"),
                ACE_LIB_TEXT ("ACE_SOCK_Netlink")));
}

ssize_t
ACE_SOCK_Netlink::send (const iovec iov[],
                      int n,
                      const ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Netlink::send");
  msghdr send_msg;

  send_msg.msg_iov = (iovec *) iov;
  send_msg.msg_iovlen = n;
  send_msg.msg_name = (char *) addr.get_addr ();
  send_msg.msg_namelen = addr.get_size ();
  send_msg.msg_control = 0;
  send_msg.msg_controllen = 0;
  send_msg.msg_flags = 0;

  return ACE_OS::sendmsg (this->get_handle (),
                          &send_msg,
                          flags);
}

ssize_t
ACE_SOCK_Netlink::recv (iovec iov[],
                      int n,
                      ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Netlink::recv");
  msghdr recv_msg;

  recv_msg.msg_iov = (iovec *) iov;
  recv_msg.msg_iovlen = n;
  recv_msg.msg_name = (char *) addr.get_addr ();
  recv_msg.msg_namelen = addr.get_size ();
  recv_msg.msg_control = 0;
  recv_msg.msg_controllen = 0;
  recv_msg.msg_flags = 0;

  ssize_t status = ACE_OS::recvmsg (this->get_handle (),
                                    &recv_msg,
                                    flags);

  if (recv_msg.msg_flags & MSG_TRUNC)
      return -1;

  addr.set_size (recv_msg.msg_namelen);
  addr.set_type (((sockaddr_in *) addr.get_addr())->sin_family);

  return status;
}

#endif // #if defined (ACE_HAS_LINUX_NETLINK)

