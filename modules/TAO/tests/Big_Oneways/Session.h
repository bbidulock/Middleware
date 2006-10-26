// -*- C++ -*-
//
// $Id$

#ifndef BIG_ONEWAYS_SESSION_H
#define BIG_ONEWAYS_SESSION_H

#include /**/ "ace/pre.h"

#include "TestS.h"
#include "Session_Task.h"

#if defined(ACE_HAS_THREADS)
# include "ace/Barrier.h"
#else
# include "ace/Null_Barrier.h"
#endif  /* ACE_HAS_THREADS */

/// Implement the Test::Session interface
class Session
  : public virtual POA_Test::Session
{
public:
  /// Constructor
  Session (Test::Session_Control_ptr control,
           CORBA::ULong payload_size,
           CORBA::ULong thread_count,
           CORBA::ULong message_count,
           CORBA::ULong peer_count);

  /// Destructor
  virtual ~Session (void);

  /// Run one of the experiment threads
  int svc (void);

  // = The skeleton methods
  virtual void start (const Test::Session_List &other_sessions
                      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Test::Already_Running,
                     Test::No_Peers));

  virtual void ping (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void receive_payload (const Test::Payload &the_payload
                                ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void destroy (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  /// Helper function used to report any problems and destroy local
  /// resources
  void terminate (CORBA::Boolean success
                  ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC (());

  /// Return 1 if all the work in this session has been completed
  int more_work (void) const;

  /// Make sure that all threads have connections avaiable to the
  /// other sessions.
  void validate_connections (ACE_ENV_SINGLE_ARG_DECL);

private:
  /// Synchronize the internal state
  ACE_SYNCH_MUTEX mutex_;

  /// Keep a reference to the Session_Control, this is used to report
  /// when the test finishes.
  Test::Session_Control_var control_;

  /// Keep track of wether the test is running.
  int running_;

  /// The other session objects participating in the test
  Test::Session_List other_sessions_;

  /// Size of each message
  CORBA::ULong payload_size_;

  /// Number of threads
  CORBA::ULong thread_count_;

  /// Number of messages to send
  CORBA::ULong message_count_;

  /// The number of threads currently running, when this reaches 0 the
  /// session destroys itself.
  CORBA::ULong active_thread_count_;

  /// Number of messages expected
  CORBA::ULong expected_messages_;

  /// Helper class to run svc() in a separate thread
  Session_Task task_;

  /// Barrier to start all threads simultaenously
#if defined(ACE_HAS_THREADS)
  typedef ACE_Thread_Barrier Barrier;
#else
  typedef ACE_Null_Barrier Barrier;
#endif /* ACE_HAS_THREADS */
  Barrier barrier_;
};

#include /**/ "ace/post.h"

#endif /* BIG_ONEWAYS_SESSION_H */
