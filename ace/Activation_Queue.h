/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Activation_Queue.h
//
// = AUTHOR
//    Andres Kruse <Andres.Kruse@cern.ch> and Douglas C. Schmidt
//    <schmidt@cs.wustl.edu> 
// 
// ============================================================================

#if !defined (ACE_ACTIVATION_QUEUE_H)
#define ACE_ACTIVATION_QUEUE_H

#include "ace/Synch_T.h"
#include "ace/Message_Queue.h"
#include "ace/Method_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ACE_Export ACE_Activation_Queue
{
  // = TITLE
  //     Reifies a method into an object.  Subclasses typically
  //     represent necessary state and behavior.
  //
  // = DESCRIPTION
  //     A <Method_Object> is inserted in the <Activation_Queue>, where
  //     it is subsequently removed by the <Scheduler> and invoked.
public:
  // = Initialization and termination methods.
  ACE_Activation_Queue (ACE_Message_Queue<ACE_SYNCH> *new_queue = 0);
  virtual ~ACE_Activation_Queue (void);

  // = Queue operations.

  // For the following two methods if <timeout> == 0, the caller will
  // block until action is possible, else will wait until the absolute
  // time specified in *<timeout> elapses).  These calls will return,
  // however, when queue is closed, deactivated, when a signal occurs,
  // or if the time specified in timeout elapses, (in which case errno
  // = EWOULDBLOCK).

  ACE_Method_Object *dequeue (ACE_Time_Value *tv = 0);
  // Dequeue the next available <Method_Object>.

  int enqueue (ACE_Method_Object *new_method_object, 
	       ACE_Time_Value *tv = 0);
  // Enqueue the <Method_Object>.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  ACE_Message_Queue<ACE_SYNCH> *queue_;
  // Stores the <Method_Objects>.
  
  int delete_queue_;
  // Keeps track of whether we need to delete the queue.
};

#if defined (__ACE_INLINE__)
#include "ace/Activation_Queue.i"
#endif /* __ACE_INLINE__ */

#endif /* ACE_ACTIVATION_QUEUE_H */

