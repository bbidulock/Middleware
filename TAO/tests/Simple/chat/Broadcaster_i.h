/* -*- C++ -*- */
// $Id$

// ===========================================================
//
// = LIBRARY
//    TAO/tests/Simple/chat
//
// = FILENAME
//    Broadcaster_i.h
//
// = DESCRIPTION
//    Defines the implementation header for the Broadcaster interface.
//
// = AUTHOR
//    Pradeep Gore <pradeep@cs.wustl.edu>
//
// ===========================================================

#if !defined (BROADCASTER_I_H)
#define BROADCASTER_I_H

#include "BroadcasterS.h"
#include "ReceiverC.h"
#include "tao/TAO.h"
#include "ace/Containers.h"
#include "ace/SString.h"

class Broadcaster_i : public POA_Broadcaster
{
  // = TITLE
  //    The implementation of the Broadcaster class, which is the
  //    servant object for the chat server.
public:
  // = Initialization and termination methods.
  Broadcaster_i (void);
  // Constructor

  ~Broadcaster_i (void);
  // Destructor

  virtual void add (Receiver_ptr receiver,
		    const char *nickname,
		    CORBA::Environment &_tao_environment);
  // Saves receiver references in a list.

  virtual void remove (Receiver_ptr receiver,
		       CORBA::Environment &_tao_environment);
  // Removes receiver references from the list.

  virtual void say (Receiver_ptr receiver,
		    const char *text,
		    CORBA::Environment &_tao_environment);
  // Called by Broadcaster clients to send messages.

private:
  TAO_ORB_Manager orb_manager_;
  // The ORB manager.

  void broadcast (const char* text,
		  CORBA::Environment &_tao_environment);
  // Broadcasts the text to all registered clients.

  class Receiver_Data
  {
    // = TITLE
    //   Per-client info.
    //
    // = DESCRIPTION
    //   Saves the Receiver_var and user nickname.
  public:
    int operator == (const Receiver_Data &receiver_data) const;
    // The == op required by the ACE_Unbounded set.

    Receiver_var receiver_;
    // Stores the receiver reference.

    ACE_CString nickname_;
    // Stores the client nickname.
  };

  typedef ACE_Unbounded_Set<Receiver_Data>
          RECEIVER_SET;
  typedef ACE_Unbounded_Set_Iterator<Receiver_Data>
	  RECEIVER_SET_ITERATOR;

  RECEIVER_SET receiver_set_;
  // Set of registered clients.
};

#endif /* BROADCASTER_I_H */
