/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    ReactorEx.h
//
// = AUTHOR
//    Tim Harrison and Doug Schmidt
// 
// ============================================================================

#if !defined (ACE_ReactorEx_H)
#define ACE_ReactorEx_H

#include "ace/Time_Value.h"
#include "ace/Event_Handler.h"
#include "ace/Message_Queue.h"
#include "ace/Token.h"

#if defined (ACE_MT_SAFE)

#if defined (ACE_REACTOREX_HAS_DEADLOCK_DETECTION)
#include "ace/Local_Tokens.h"
typedef ACE_Local_Mutex ACE_REACTOREX_MUTEX;
#else 
typedef ACE_Token ACE_REACTOREX_MUTEX;
#endif /* ACE_REACTOR_HAS_DEADLOCK_DETECTION */

// Forward decl.
class ACE_ReactorEx;
 
class ACE_Export ACE_ReactorEx_Token : public ACE_REACTOREX_MUTEX
{
public:
  ACE_ReactorEx_Token (ACE_ReactorEx &r);

  virtual void sleep_hook (void);
  // Called just before the ACE_Event_Handler goes to sleep.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_ReactorEx &reactorEx_;
};

#endif /* ACE_MT_SAFE */

#if defined (ACE_WIN32)
// ************************************************************

class ACE_Export ACE_ReactorEx_Notify : public ACE_Event_Handler
// = TITLE
//    ReactorEx Notify
//
// = DESCRIPTION
//    A "do-nothing" class that is called when ReactorEx::notify is
//    called.
{
public:
  ACE_ReactorEx_Notify (void);
  // Creates a handle.

  ~ACE_ReactorEx_Notify (void);
  // Destroys a handle.

  int notify (ACE_Event_Handler *eh = 0,
	      ACE_Reactor_Mask mask = ACE_Event_Handler::EXCEPT_MASK);
  // Special trick to unblock WaitForMultipleObjects() when updates
  // occur in somewhere other than the main <ACE_ReactorEx> thread.
  // All we do is enqueue <eh> and <mask> onto the <ACE_Message_Queue>
  // and wakeup the ReactorEx by signaling its <ACE_Event> handle.

private:
  struct 
  {
    ACE_Event_Handler *eh_;
    ACE_Reactor_Mask mask_;
  };

  virtual ACE_HANDLE get_handle (void) const;
  // Returns a handle.

  virtual int handle_signal (int signum, siginfo_t * = 0, ucontext_t * = 0);
  // Does with a handle.

  ACE_Auto_Event notify_event_;
  // A handle.

  ACE_Message_Queue<ACE_MT_SYNCH> message_queue_;
  // Message queue that keeps track of pending <ACE_Event_Handlers>.
  // This queue must be thread-safe because it can be called by
  // multiple threads of control.
};

class ACE_Export ACE_ReactorEx
  // = TITLE
  //     An object oriented event demultiplexor and event handler
  //     ReactorEx for Win32 WaitForMultipleObjects
  //     
  // = DESCRIPTION

  //     The ACE_ReactorEx is an object-oriented event demultiplexor
  //     and event handler ReactorEx.  The sources of events that the
  //     ACE_ReactorEx waits for and dispatches includes I/O events,
  //     general Win32 synchronization events (such as mutexes,
  //     semaphores, threads, etc.) and timer events.
{
public:
  enum 
  {
    MAX_SIZE = MAXIMUM_WAIT_OBJECTS,
    // Default size of the ReactorEx's handle table.
  };

  // = Initialization and termination methods.

  ACE_ReactorEx (void);
  // Initialize the new ACE_ReactorEx with the default size.

  virtual ~ACE_ReactorEx (void);
  // Close down the ReactorEx and release all of its resources.
  
  // = Event loop drivers. 
  // Main event loop driver that blocks for -how_long- before
  // returning (will return earlier if I/O or signal events occur).
  // Note that -how_long- can be 0, in which case this method blocks
  // until I/O events or signals occur.  Returns 0 if timed out, 1 if
  // an event occurred, and -1 if an error occured.
  virtual int handle_events (ACE_Time_Value *how_long = 0,
			     int wait_all = 0);
  virtual int handle_events (ACE_Time_Value &how_long,
			     int wait_all = 0);


  // = Register and remove Handlers. 
  virtual int register_handler (ACE_Event_Handler *eh, 
				ACE_HANDLE handle = ACE_INVALID_HANDLE);
  // Register an Event_Handler -eh-.  If handle == ACE_INVALID_HANDLE
  // the ReactorEx will call eh->get_handle() to extract the
  // underlying I/O handle).
 
  virtual int remove_handler (ACE_Event_Handler *eh,
			      ACE_Reactor_Mask mask = 0);
  // Removes -eh- from the ReactorEx.  Note that the ReactorEx will
  // call eh->get_handle() to extract the underlying I/O handle.  If
  // -mask- == ACE_Event_Handler::DONT_CALL then the -handle_close-
  // method of the -eh- is not invoked.

  int notify (ACE_Event_Handler * = 0, 
	      ACE_Reactor_Mask = ACE_Event_Handler::EXCEPT_MASK);
  // Wakeup <ACE_ReactorEx> if currently blocked in
  // WaitForMultipleObjects().

  // = Timer management. 
  virtual int schedule_timer (ACE_Event_Handler *eh,
			      const void *arg,
			      const ACE_Time_Value &delta,
			      const ACE_Time_Value &interval = ACE_Time_Value::zero);  
  // Schedule an Event Handler -eh- that will expire after -delta-
  // amount of time.  If it expires then -arg- is passed in as the
  // value to eh->handle_timeout.  If -interval- is != to
  // ACE_Time_Value::zero then it is used to reschedule -eh-
  // automatically.  This method returns a timer handle that uniquely
  // identifies the -eh- in an internal list.  This timer handle can
  // be used to cancel an Event_Handler before it expires.  The
  // cancellation ensures that timer_ids are unique up to values of
  // greater than 2 billion timers.  As long as timers don't stay
  // around longer than this there should be no problems with
  // accidentally deleting the wrong timer.

  virtual int cancel_timer (ACE_Event_Handler *event_handler);
  // Cancel all Event_Handlers that match the address of
  // -event_handler-.

  virtual int cancel_timer (int timer_id, const void **arg = 0);
  // Cancel the single Event_Handler that matches the -timer_id- value
  // (which was returned from the schedule method).  If arg is
  // non-NULL then it will be set to point to the ``magic cookie''
  // argument passed in when the Event_Handler was registered.  This
  // makes it possible to free up the memory and avoid memory leaks.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  int handle_notification (void);
  // Handle the case where some thread has awakened us via our
  // notification event.

  ACE_Timer_Queue timer_queue_; 
  // Defined as a pointer to allow overriding by derived classes...

  ACE_Time_Value timer_skew_;
  // Adjusts for timer skew in various clocks.

  ACE_HANDLE handles_[MAX_SIZE];
  // Array of handles passed to WaitForMultipleObjects.

  ACE_Event_Handler *handlers_[MAX_SIZE];
  // Array of Event_Handler pointers that store the handlers to
  // dispatch when the corresponding handles_ entry becomes signaled.

  size_t active_handles_;
  // Number of handles that are currently active (ranges between 0 and
  // MAX_SIZE).

  ACE_ReactorEx_Token token_;
  // Synchronization token for the MT_SAFE ACE_Reactor.

private:

  // Deny access since member-wise won't work...
  ACE_ReactorEx (const ACE_ReactorEx &);
  ACE_ReactorEx &operator = (const ACE_ReactorEx &);

  ACE_ReactorEx_Notify notify_handler_;
  // Called when notify is called.
};

#else /* NOT win32 */
class ACE_Export ACE_ReactorEx
{
public:
  virtual int handle_events (void) { return -1; }
  virtual int handle_events (ACE_Time_Value &) { return -1; }
  int notify (ACE_Event_Handler * = 0,
	      ACE_Reactor_Mask = ACE_Event_Handler::EXCEPT_MASK)
  { return 0; }
};

#endif /* ACE_WIN32 */

#if defined (__ACE_INLINE__)
#include "ace/ReactorEx.i"
#endif /* __ACE_INLINE__ */
#endif /* ACE_ReactorEx_H */
