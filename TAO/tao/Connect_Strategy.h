// -*- C++ -*-

//=============================================================================
/**
 *  @file Connect_Strategy.h
 *
 *  $Id$
 *
 *  @author Balachandran Natarajan <bala@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_CONNECT_STRATEGY_H
#define TAO_CONNECT_STRATEGY_H
#include "ace/pre.h"

#include "TAO_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_ORB_Core;
class TAO_Connector;
class TAO_Connection_Handler;
class ACE_Synch_Options;
class ACE_Time_Value;

/**
 * @class TAO_Connect_Strategy
 *
 * @brief Define the interface for the connect strategy, i.e. the
 *  algorithm that controls how does the ORB establishes remote
 *  connections.
 *
 * The thread that establishes remote connections can either make a
 * blocking or a non-blocking connect. The strategy to wait for the
 * connection completion can also be different.
 *
 * This strategy controls how does the ORB schedules and waits for
 * connection completion.
 */

class TAO_Export TAO_Connect_Strategy
{
public:

  /// Constructor
  TAO_Connect_Strategy (TAO_ORB_Core *orb);

  /// Destructor
  virtual ~TAO_Connect_Strategy (void);

  /* Return the synch option for the connector, based on the timeout
   * and the strategy in place. ACE_Connectors behavior can be altered
   * by passing the right ACE_Synch_Options to the connect () call.
   */
  virtual void synch_options (ACE_Time_Value *val,
                              ACE_Synch_Options &opt) = 0;

  /* Wait for the connection to be completed and return a transport
   * whose reference count has been incremented. If the connection
   * establishment fails this method returns a null transport
   * indicating the failure of connection.
   */
  virtual int wait (TAO_Connection_Handler *ch,
                    ACE_Time_Value *val) = 0;

  /// Cleanup in case of failed connect.
  /*
   * Do any left over memory management or related things after
   * the connect failed. The argument @c is_successful indicates
   * whether the connection handler had undergone a sucessful state
   * transitions or not.
   */
  virtual int post_failed_connect (TAO_Connection_Handler *ch,
                                   int is_successful = 1);

protected:

  /// Cached copy of the ORB core pointer
  TAO_ORB_Core *orb_core_;
};


#include "ace/post.h"
#endif /*TAO_CONNECT_STRATEGY_H*/
