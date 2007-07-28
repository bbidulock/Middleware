// -*- C++ -*-

//==========================================================================
/**
 *  @file    SOCK_SCTP_SEQPACK.h
 *
 *  $Id$
 *
 *  @author Andrew J. Stafford <ajstafford@gmail.com>
 */
//==========================================================================

#ifndef ACE_SOCK_SCTP_SEQPACK_H
#define ACE_SOCK_SCTP_SEQPACK_H

#include /**/ "ace/pre.h"

#include "ace/SOCK.h"
#include "ace/INET_Addr.h"
#include "ace/Multihomed_INET_Addr.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/ACE.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_SOCK_SCTP_SEQPACK
 *
 * @brief Defines the methods for the ACE one-to-many style SCTP socket. 
 *
 */
class ACE_Export ACE_SOCK_SCTP_SEQPACK : public ACE_SOCK
{
  
public:

  /// Constructor.
  ACE_SOCK_SCTP_SEQPACK (void);

  /// Destructor.
  ~ACE_SOCK_SCTP_SEQPACK (void);

  int open (const ACE_Multihomed_INET_Addr &local_sap,
            int reuse_addr = 0,
            int protocol_family = PF_UNSPEC,
            int backlog = ACE_DEFAULT_BACKLOG);

  ssize_t recvmsg(void* msg,
                  size_t msgsz,
                  ACE_INET_Addr& from_addr,
                  struct sctp_sndrcvinfo* sinfo,
                  int* msg_flags);

  ssize_t sendmsg(const void* msg,
                  size_t msgsz,
                  ACE_INET_Addr& to_addr,
                  uint32_t ppid,
                  uint32_t flags,
                  uint16_t stream,
                  uint32_t timetolive,
                  uint32_t context);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_SOCK_SCTP_SEQPACK_H */
