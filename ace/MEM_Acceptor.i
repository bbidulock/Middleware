/* -*- C++ -*- */
// $Id$

// MEM_Acceptor.i

ASYS_INLINE int
ACE_MEM_Acceptor::open (const ACE_Addr &local_sap,
                        int reuse_addr,
                        int protocol_family,
                        int backlog,
                        int protocol)
{
  return this->ACE_SOCK_Acceptor:: open
    (local_sap, reuse_addr, protocol_family, backlog, protocol);
}

ASYS_INLINE int
ACE_MEM_Acceptor::open (const ACE_Addr &local_sap,
                        ACE_Protocol_Info *protocolinfo,
                        ACE_SOCK_GROUP g,
                        u_long flags,
                        int reuse_addr,
                        int protocol_family,
                        int backlog,
                        int protocol)
{
  return this->ACE_SOCK_Acceptor::open
    (local_sap, protocolinfo, g, flags, reuse_addr, protocol_family,
     backlog, protocol);
}

ASYS_INLINE int
ACE_MEM_Acceptor::accept (ACE_SOCK_Stream &new_stream,
                          ACE_Addr *remote_addr,
                          ACE_Time_Value *timeout,
                          int restart,
                          int reset_new_handle) const
{
  return this->ACE_SOCK_Acceptor::accept
    (new_stream, remote_addr, timeout, restart, reset_new_handle);
}

ASYS_INLINE int
ACE_MEM_Acceptor::accept (ACE_SOCK_Stream &new_stream,
                          ACE_Accept_QoS_Params qos_params,
                          ACE_Addr *remote_addr,
                          ACE_Time_Value *timeout,
                          int restart,
                          int reset_new_handle) const
{
  return this->ACE_SOCK_Acceptor::accept
    (new_stream, qos_params, remote_addr, timeout, restart, reset_new_handle);
}
