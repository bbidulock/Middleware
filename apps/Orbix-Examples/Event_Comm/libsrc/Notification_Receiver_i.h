/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    EventComm
// 
// = FILENAME
//    Notification_Receiver__i.h
//
// = DESCRIPTION 
//    Class interface for the implementation of the <Notification_Receiver>
//
// = AUTHOR
//    Douglas C. Schmidt (schmidt@cs.wustl.edu)
// 
// ============================================================================

#if !defined (_Notification_Receiver_i_H)
#define _Notification_Receiver_i_H

#if defined (ACE_HAS_ORBIX) && (ACE_HAS_ORBIX != 0)
#include "Event_Comm.hh"

class Notification_Receiver_i
{
  // = TITLE
  //   Defines the implementation class for event <Notification_Receivers>.
public:
  // = Initialization and termination methods.
  Notification_Receiver_i (void);
  // Constructor.

  ~Notification_Receiver_i (void);
  // Destructor.

  virtual void receive_notification (const Event_Comm::Notification &notification,
				     CORBA::Environment &IT_env);
  // Pass the <Notification> to the <Notification_Receiver>.

  virtual void disconnect (const char *reason,
			   CORBA::Environment &IT_env);
  // Disconnect the <Notification_Receiver> from the <Notifier>,
  // giving it the <reason>.
};

#endif /* ACE_HAS_ORBIX */
#endif /* _Notification_Receiver_i_H */
