// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Sync_Strategies.h
//
// = DESCRIPTION
//     Sync Strategies for the ORB Messaging layer.
//
// = AUTHOR
//     Irfan Pyarali
//
// ============================================================================

#ifndef TAO_SYNC_STRATEGIES_H
#define TAO_SYNC_STRATEGIES_H

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Pluggable.h"

class TAO_Export TAO_Sync_Strategy
{
public:
  virtual ~TAO_Sync_Strategy (void);

  virtual ssize_t send (TAO_Transport &transport,
                        TAO_Stub &stub,
                        const ACE_Message_Block *message_block,
                        ACE_Time_Value *max_wait_time) = 0;
};

class TAO_Export TAO_Transport_Sync_Strategy : public TAO_Sync_Strategy
{
public:
  ssize_t send (TAO_Transport &transport,
                TAO_Stub &stub,
                const ACE_Message_Block *message_block,
                ACE_Time_Value *max_wait_time);
};

#if defined (TAO_HAS_CORBA_MESSAGING)

class TAO_Export TAO_None_Sync_Strategy : public TAO_Sync_Strategy
{
public:
  ssize_t send (TAO_Transport &transport,
                TAO_Stub &stub,
                const ACE_Message_Block *message_block,
                ACE_Time_Value *max_wait_time);

  virtual int buffering_constraints_reached (TAO_Stub &stub,
                                             TAO_Transport_Buffering_Queue &buffering_queue);

  void dequeue_head (TAO_Transport_Buffering_Queue &buffering_queue);

  void dequeue_all (TAO_Transport_Buffering_Queue &buffering_queue);

  void reset_queued_message (TAO_Transport_Buffering_Queue &buffering_queue,
                             ACE_Message_Block *message_block,
                             size_t bytes_delivered);
};

class TAO_Export TAO_Flush_Sync_Strategy : public TAO_None_Sync_Strategy
{
public:
  int buffering_constraints_reached (TAO_Stub &stub,
                                     TAO_Transport_Buffering_Queue &buffering_queue);
};

#endif /* TAO_HAS_CORBA_MESSAGING */

#if defined (__ACE_INLINE__)
# include "tao/Sync_Strategies.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_SYNC_STRATEGIES_H */
