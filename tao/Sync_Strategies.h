// -*- C++ -*-

//=============================================================================
/**
 *  @file    Sync_Strategies.h
 *
 *  $Id$
 *
 *   Sync Strategies for the ORB Messaging layer.
 *
 *
 *  @author  Irfan Pyarali
 */
//=============================================================================


#ifndef TAO_SYNC_STRATEGIES_H
#define TAO_SYNC_STRATEGIES_H
#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Pluggable.h"
#include "tao/TAOC.h"

class TAO_Export TAO_Sync_Strategy
{
public:
  virtual ~TAO_Sync_Strategy (void);

  virtual ssize_t send (TAO_Transport &transport,
                        TAO_Stub &stub,
                        const ACE_Message_Block *message_block,
                        const ACE_Time_Value *max_wait_time) = 0;
};

class TAO_Export TAO_Transport_Sync_Strategy : public TAO_Sync_Strategy
{
public:
  ssize_t send (TAO_Transport &transport,
                TAO_Stub &stub,
                const ACE_Message_Block *message_block,
                const ACE_Time_Value *max_wait_time);
};

#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

class TAO_Export TAO_Eager_Buffering_Sync_Strategy : public TAO_Sync_Strategy
{
public:
  ssize_t send (TAO_Transport &transport,
                TAO_Stub &stub,
                const ACE_Message_Block *message_block,
                const ACE_Time_Value *max_wait_time);

  virtual int buffering_constraints_reached (TAO_Transport &transport,
                                             TAO_Stub &stub,
                                             TAO_Transport_Buffering_Queue &buffering_queue);

  void timer_check (TAO_Transport &transport,
                    const TAO::BufferingConstraint &buffering_constraint);

  ACE_Time_Value time_conversion (const TimeBase::TimeT &time);
};

class TAO_Export TAO_Delayed_Buffering_Sync_Strategy : public TAO_Eager_Buffering_Sync_Strategy
{
public:
  ssize_t send (TAO_Transport &transport,
                TAO_Stub &stub,
                const ACE_Message_Block *message_block,
                const ACE_Time_Value *max_wait_time);
};

#endif /* TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1 */

#if defined (__ACE_INLINE__)
# include "tao/Sync_Strategies.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_SYNC_STRATEGIES_H */
