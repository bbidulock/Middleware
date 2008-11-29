// -*- C++ -*-

//=============================================================================
/**
 * @file LWFT_Client_Init.h
 *
 * $Id$
 *
 * A concrete implementation of a service callback
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_LWFT_CLIENT_INIT_H
#define TAO_LWFT_CLIENT_INIT_H

#include /**/ "ace/pre.h"

#include "lwft_client_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Versioned_Namespace.h"

#include "ForwardingAgent_Thread.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class LWFT_Client_Init
 *
 * @brief A class that encapsulates the special initialization
 *        requirements of LWFT clients.
 *
 */
namespace CORBA
{
  class ORB;
  typedef ORB *ORB_ptr;
}

class LWFT_Client_Export LWFT_Client_Init
{
public:
  LWFT_Client_Init (void);
  ~LWFT_Client_Init (void);
  
  CORBA::ORB_ptr init (int &argc, char *argv[]);
  
private:
  ForwardingAgent_Thread fa_thread_;
};

#include /**/ "ace/post.h"

#endif /*TAO_LWFT_CLIENT_INIT_H  */
