// -*- C++ -*-

// ===================================================================
/**
 *  @file   NIOP_Connection_Handler.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen <jwillemsen@remedy.nl>
 */
// ===================================================================

#ifndef TAO_NIOP_CONNECTION_HANDLER_H
#define TAO_NIOP_CONNECTION_HANDLER_H

#include /**/ "ace/pre.h"

#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (TAO_HAS_NIOP) && (TAO_HAS_NIOP != 0)

#include "tao/Strategies/strategies_export.h"
#include "tao/Wait_Strategy.h"
#include "tao/Connection_Handler.h"
#include "tao/Strategies/NIOP_Transport.h"
#include "ace/Reactor.h"
#include "ace/Acceptor.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward Decls
class TAO_Pluggable_Messaging;

// ****************************************************************

/**
 * @class TAO_NIOP_Connection_Handler
 *
 * @brief  Handles requests on a single connection.
 *
 * The Connection handler which is common for the Acceptor and
 * the Connector
 */
class TAO_Strategies_Export TAO_NIOP_Connection_Handler
  : public TAO_NIOP_SVC_HANDLER
  , public TAO_Connection_Handler
{

public:

  TAO_NIOP_Connection_Handler (ACE_Thread_Manager* t = 0);

  /// Constructor.
  TAO_NIOP_Connection_Handler (TAO_ORB_Core *orb_core,
                               CORBA::Boolean flag);

  /// Destructor.
  ~TAO_NIOP_Connection_Handler (void);

  /// Called by the <Strategy_Acceptor> when the handler is completely
  /// connected.  Argument is unused.
  virtual int open (void *);

  //@{
  /**
   * Connection_Handler overloads
   */
  virtual int open_handler (void *);
  //@}

  /// Close called by the Acceptor or Connector when connection
  /// establishment fails.
  int close (u_long = 0);

  //@{
  /** @name Event Handler overloads
   */
  virtual int resume_handler (void);
  virtual int close_connection (void);
  virtual int handle_input (ACE_HANDLE);
  virtual int handle_output (ACE_HANDLE);
  virtual int handle_close (ACE_HANDLE, ACE_Reactor_Mask);
  virtual int handle_timeout (const ACE_Time_Value &current_time,
                              const void *act = 0);
  //@}

  /// Add ourselves to Cache.
  int add_transport_to_cache (void);

protected:

  //@{
  /**
   * @name TAO_Connection Handler overloads
   */
  virtual int release_os_resources (void);
  //@}
};

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_HAS_NIOP && TAO_HAS_NIOP != 0 */

#include /**/ "ace/post.h"

#endif /* TAO_NIOP_CONNECTION_HANDLER_H */
