// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    IIOP_Acceptor.h
//
// = DESCRIPTION
//    IIOP specific acceptor processing
//
// = AUTHOR
//    Fred Kuhns
//
// ============================================================================

#ifndef TAO_IIOP_ACCEPTOR_H
#define TAO_IIOP_ACCEPTOR_H

#include "tao/Pluggable.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/IIOP_Connect.h"
#include "tao/Acceptor_Impl.h"

#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"

//Forward Declaration.
class TAO_IIOP_Connector;

// TAO IIOP_Acceptor concrete call defination

class TAO_Export TAO_IIOP_Acceptor : public TAO_Acceptor
{
  // = TITLE
  //   TAO_IIOP_Acceptor
  //
  // = DESCRIPTION
  //   The IIOP-specific bridge class for the concrete acceptor.
  //
public:
 
  TAO_IIOP_Acceptor (void);
  // Create Acceptor object using addr.

  ~TAO_IIOP_Acceptor (void);
  // Destructor.

  virtual int open (TAO_ORB_Core *orb_core,
                    int version_major,
                    int version_minor,
                    ACE_CString &address);
  // initialize acceptor for this address.

  virtual int open_default (TAO_ORB_Core *orb_core);
  // Open an acceptor on the default endpoint for this protocol

  int create_mprofile (const TAO_ObjectKey &object_key,
                       TAO_MProfile &mprofile);
  // create profile objects for this Acceptor using the SAP
  // (service access point, Host and Port) and object_key.

  // = See TAO_Acceptor
  virtual int is_collocated (const TAO_Profile*);

  ACE_Event_Handler *acceptor (void);
  // Return the underlying acceptor object, ACE_Acceptor

  virtual int close (void);
  // Closes the acceptor

  CORBA::ULong endpoint_count (void);
  // return the number of profiles this will generate

  const ACE_INET_Addr& address (void) const;
  // @@ Helper method for the implementation repository, should go
  //    away

  typedef ACE_Strategy_Acceptor<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR> TAO_IIOP_BASE_ACCEPTOR;
  typedef TAO_Creation_Strategy<TAO_IIOP_Server_Connection_Handler> TAO_IIOP_CREATION_STRATEGY;
  typedef TAO_Concurrency_Strategy<TAO_IIOP_Server_Connection_Handler> TAO_IIOP_CONCURRENCY_STRATEGY;
  typedef TAO_Accept_Strategy<TAO_IIOP_Server_Connection_Handler, ACE_SOCK_ACCEPTOR, TAO_IIOP_Connector> TAO_IIOP_ACCEPT_STRATEGY;

private:
  int open_i (TAO_ORB_Core* orb_core,
              const ACE_INET_Addr& addr);
  // Implement the common part of the open*() methods

private:
  TAO_IIOP_BASE_ACCEPTOR base_acceptor_;
  // the concrete acceptor, as a pointer to it's base class.

  TAO_IIOP_CREATION_STRATEGY *creation_strategy_;
  TAO_IIOP_CONCURRENCY_STRATEGY *concurrency_strategy_;
  TAO_IIOP_ACCEPT_STRATEGY *accept_strategy_;
  // Acceptor strategies.

  ACE_INET_Addr address_;
  ACE_CString host_;
  // Cache the information about the endpoint serviced by this
  // acceptor.
  // @@ TODO there may in fact be multiple hostnames for this
  //    endpoint. For example it the IP address is INADDR_ANY
  //    (0.0.0.0) then there will be possibly a different hostname for
  //    each interface.

  TAO_GIOP_Version version_;
  // The GIOP version for this endpoint

  TAO_ORB_Core *orb_core_;
  // ORB Core.
};

#if defined(__ACE_INLINE__)
#include "tao/IIOP_Acceptor.i"
#endif /* __ACE_INLINE__ */

#endif  /* TAO_IIOP_ACCEPTOR_H */
