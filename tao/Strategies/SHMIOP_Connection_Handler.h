// This may look like C, but it's really -*- C++ -*-

// ===================================================================
/**
 *  @file   SHMIOP_Connection_Handler.h
 *
 *  $Id$
 *
 *  @author Originally by Nanbor Wang <nanbor@cs.wustl.edu> as UIOP_Connect.h
 *  @author modified by Balachandran Natarajan <bala@cs.wustl.edu>
 */
// ===================================================================

#ifndef TAO_SHMIOP_CONNECT_H
#define TAO_SHMIOP_CONNECT_H
#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (TAO_HAS_SHMIOP) && (TAO_HAS_SHMIOP != 0)

#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "tao/corbafwd.h"
#include "tao/Wait_Strategy.h"
#include "tao/Connection_Handler.h"
#include "SHMIOP_Transport.h"

// ****************************************************************
/**
 * @class TAO_SHMIOP_Connection_Handler
 *
 * @brief  Handles requests on a single connection.
 *
 * The Connection handler which is common for the Acceptor and
 * the Connector
 */


class TAO_Strategies_Export TAO_SHMIOP_Connection_Handler :
  public TAO_SHMIOP_SVC_HANDLER,
  public TAO_Connection_Handler
{

public:
  /// Constructor.
  TAO_SHMIOP_Connection_Handler (ACE_Thread_Manager* t = 0);

  /// Constructor. <arg> parameter is used by the Acceptor to pass the
  /// protocol configuration properties for this connection.
  TAO_SHMIOP_Connection_Handler (TAO_ORB_Core *orb_core,
                               CORBA::Boolean flag,
                               void *arg);


  /// Destructor.
  ~TAO_SHMIOP_Connection_Handler (void);

  /// Called by the <Strategy_Acceptor> when the handler is completely
  /// connected.  Argument is unused.
  virtual int open (void *);


  /// Active object activation method.
  virtual int activate (long flags = THR_NEW_LWP,
                        int n_threads = 1,
                        int force_active = 0,
                        long priority = ACE_DEFAULT_THREAD_PRIORITY,
                        int grp_id = -1,
                        ACE_Task_Base *task = 0,
                        ACE_hthread_t thread_handles[] = 0,
                        void *stack[] = 0,
                        size_t stack_size[] = 0,
                        ACE_thread_t  thread_names[] = 0);

  /// Only used when the handler is turned into an active object by
  /// calling <activate>.  This serves as the event loop in such cases.
  virtual int svc (void);

  //@{
  /** @name Event Handler overloads
   */
  virtual int resume_handler (void);
  virtual int close_connection (void);
  virtual int handle_input (ACE_HANDLE);
  virtual int handle_output (ACE_HANDLE);
  virtual int handle_close (ACE_HANDLE, ACE_Reactor_Mask);
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

private:
  /// Flag that we will be passing to the event handler to indicate
  /// whether the handle will be resumed by the method or not.
  int resume_flag_;

};



#if defined (__ACE_INLINE__)
#include "SHMIOP_Connection_Handler.inl"
#endif /* __ACE_INLINE__ */

#endif /* TAO_HAS_SHMIOP && TAO_HAS_SHMIOP != 0 */

#include "ace/post.h"
#endif /* TAO_SHMIOP_CONNECT_H */
