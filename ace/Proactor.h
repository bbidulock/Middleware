/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    Proactor.h
//
// = AUTHOR
//    Irfan Pyarali (irfan@cs.wustl.edu),
//    Tim Harrison (harrison@cs.wustl.edu) and
//    Alexander Babu Arulanthu <alex@cs.wustl.edu>
//
// ============================================================================

#if !defined (ACE_PROACTOR_H)
#define ACE_PROACTOR_H

#include "ace/OS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if ((defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || (defined (ACE_HAS_AIO_CALLS)))
// This only works on Win32 platforms and on Unix platforms supporting
// POSIX aio calls.

#include "ace/Asynch_IO.h"
#include "ace/Asynch_IO_Impl.h"

// Forward declarations.
class ACE_Proactor_Impl;

class ACE_Export ACE_Proactor
{
  // = TITLE
  //     A manager for asynchronous event demultiplexing.
  //
  // = DESCRIPTION
  //     See the Proactor pattern description at
  //     http://www.cs.wustl.edu/~schmidt/proactor.ps.gz for more
  //     details.
public:
  ACE_Proactor (ACE_Proactor_Impl *implementation = 0,
                int delete_implementation = 0);
  // A do nothing constructor.
  
  virtual ~ACE_Proactor (void);
  // Virtual destruction.

  static ACE_Proactor *instance (size_t threads = 0);
  // Get pointer to a process-wide <ACE_Proactor>.  <threads> should
  // be part of another method.

  static ACE_Proactor *instance (ACE_Proactor *);
  // Set pointer to a process-wide <ACE_Proactor> and return existing
  // pointer.

  static void close_singleton (void);
  // Delete the dynamically allocated Singleton.

  // = Proactor event loop management methods.

  static int run_event_loop (void);
  // Run the event loop until the <ACE_Proactor::handle_events> method
  // returns -1 or the <end_event_loop> method is invoked.

  static int run_event_loop (ACE_Time_Value &tv);
  // Run the event loop until the <ACE_Proactor::handle_events> method
  // returns -1, the <end_event_loop> method is invoked, or the
  // <ACE_Time_Value> expires.

  static int end_event_loop (void);
  // Instruct the <ACE_Proactor::instance> to terminate its event
  // loop.

  static int event_loop_done (void);
  // Report if the <ACE_Proactor::instance> event loop is finished.

  virtual int close (void);
  // Close the IO completion port.

  virtual int register_handle (ACE_HANDLE handle,
			       const void *completion_key);
  // This method adds the <handle> to the I/O completion port. This
  // function is a no-op function for Unix systems.

  // = Timer management.
  virtual long schedule_timer (ACE_Handler &handler,
			       const void *act,
			       const ACE_Time_Value &time);
  // Schedule a <handler> that will expire after <time>.  If it
  // expires then <act> is passed in as the value to the <handler>'s
  // <handle_timeout> callback method.  This method returns a
  // <timer_id>. This <timer_id> can be used to cancel a timer before
  // it expires.  The cancellation ensures that <timer_ids> are unique
  // up to values of greater than 2 billion timers.  As long as timers
  // don't stay around longer than this there should be no problems
  // with accidentally deleting the wrong timer.  Returns -1 on
  // failure (which is guaranteed never to be a valid <timer_id>).

  virtual long schedule_repeating_timer (ACE_Handler &handler,
					 const void *act,
					 const ACE_Time_Value &interval);

  // Same as above except <interval> it is used to reschedule the
  // <handler> automatically.

  virtual long schedule_timer (ACE_Handler &handler,
			       const void *act,
			       const ACE_Time_Value &time,
			       const ACE_Time_Value &interval);
  // This combines the above two methods into one. Mostly for backward
  // compatibility.

  virtual int cancel_timer (ACE_Handler &handler,
			    int dont_call_handle_close = 1);
  // Cancel all timers associated with this <handler>.  Returns number
  // of timers cancelled.

  virtual int cancel_timer (long timer_id,
			    const void **act = 0,
			    int dont_call_handle_close = 1);
  // Cancel the single <ACE_Handler> that matches the <timer_id> value
  // (which was returned from the <schedule> method).  If <act> is
  // non-NULL then it will be set to point to the ``magic cookie''
  // argument passed in when the <Handler> was registered.  This makes
  // it possible to free up the memory and avoid memory leaks.
  // Returns 1 if cancellation succeeded and 0 if the <timer_id>
  // wasn't found.

  virtual int handle_events (ACE_Time_Value &wait_time);
  // Dispatch a single set of events.  If <wait_time> elapses before
  // any events occur, return.  Return 0 on success, non-zero (-1) on
  // timeouts/errors and errno is set accordingly.

  virtual int handle_events (void);
  // Block indefinitely until at least one event is dispatched.
  // Return 0 on success, non-zero (-1) on timeouts/errors and errno
  // is set accordingly.

#if 0
  virtual int post_completion (ACE_Asynch_Result *result);
  // Post a result to the completion port of the Proactor.  If errors
  // occur, the result will be deleted by this method.  If successful,
  // the result will be deleted by the Proactor when the result is
  // removed from the completion port.  Therefore, the result should
  // have been dynamically allocated and should be orphaned by the
  // user once this method is called.
#endif /* 0 */

  int wake_up_dispatch_threads (void);
  // Add wakeup dispatch threads (reinit).

  int close_dispatch_threads (int wait);
  // Close all dispatch threads.

  size_t number_of_threads (void) const;
  void number_of_threads (size_t threads);
  // Number of thread used as a parameter to CreatIoCompletionPort. 
  
  virtual ACE_HANDLE get_handle (void) const;
  // Get the event handle. 
  // It is a no-op in POSIX platforms and it returns
  // ACE_INVALID_HANDLE. 

  virtual ACE_Proactor_Impl *implementation (void) const;
  // Get the implementation class.

  //
  // = Factory methods for the operations
  //
  // Note that the user does not have to use or know about these
  // methods.
  
  virtual ACE_Asynch_Read_Stream_Impl *create_asynch_read_stream (void);
  // Create the correct implementation class for doing Asynch_Read_Stream. 
  
  virtual ACE_Asynch_Write_Stream_Impl *create_asynch_write_stream (void);
  // Create the correct implementation class for doing Asynch_Write_Stream. 

  virtual ACE_Asynch_Read_File_Impl *create_asynch_read_file (void);
  // Create the correct implementation class for doing Asynch_Read_File. 
  
  virtual ACE_Asynch_Write_File_Impl *create_asynch_write_file (void);
  // Create the correct implementation class for doing Asynch_Write_File. 
  
  virtual ACE_Asynch_Accept_Impl *create_asynch_accept (void);
  // Create the correct implementation class for doing Asynch_Accept. 
  
  virtual ACE_Asynch_Transmit_File_Impl *create_asynch_transmit_file (void);
  // Create the correct implementation class for doing Asynch_Transmit_File.
  
  //
  // = Factory methods for the results
  //
  // Note that the user does not have to use or know about these
  // methods unless they want to "fake" results.
  
  virtual ACE_Asynch_Read_Stream_Result_Impl *create_asynch_read_stream_result (ACE_Handler &handler,
                                                                                ACE_HANDLE handle,
                                                                                ACE_Message_Block &message_block,
                                                                                u_long bytes_to_read,
                                                                                const void* act,
                                                                                ACE_HANDLE event,
                                                                                int priority);
  // Create the correct implementation class for ACE_Asynch_Read_Stream::Result class. 
  
  virtual ACE_Asynch_Write_Stream_Result_Impl *create_asynch_write_stream_result (ACE_Handler &handler,
                                                                                  ACE_HANDLE handle,
                                                                                  ACE_Message_Block &message_block,
                                                                                  u_long bytes_to_write,
                                                                                  const void* act,
                                                                                  ACE_HANDLE event,
                                                                                  int priority);
  // Create the correct implementation class for ACE_Asynch_Write_Stream::Result.
  
  virtual ACE_Asynch_Read_File_Result_Impl *create_asynch_read_file_result (ACE_Handler &handler,
                                                                            ACE_HANDLE handle,
                                                                            ACE_Message_Block &message_block,
                                                                            u_long bytes_to_read,
                                                                            const void* act,
                                                                            u_long offset,
                                                                            u_long offset_high,
                                                                            ACE_HANDLE event,
                                                                            int priority);
  // Create the correct implementation class for ACE_Asynch_Read_File::Result.
  
  virtual ACE_Asynch_Write_File_Result_Impl *create_asynch_write_file_result (ACE_Handler &handler,
                                                                              ACE_HANDLE handle,
                                                                              ACE_Message_Block &message_block,
                                                                              u_long bytes_to_write,
                                                                              const void* act,
                                                                              u_long offset,
                                                                              u_long offset_high,
                                                                              ACE_HANDLE event,
                                                                              int priority);
  // Create the correct implementation class for ACE_Asynch_Write_File::Result.
  
  virtual ACE_Asynch_Accept_Result_Impl *create_asynch_accept_result (ACE_Handler &handler,
                                                                      ACE_HANDLE listen_handle,
                                                                      ACE_HANDLE accept_handle,
                                                                      ACE_Message_Block &message_block,
                                                                      u_long bytes_to_read,
                                                                      const void* act,
                                                                      ACE_HANDLE event,
                                                                      int priority);
  // Create the correct implementation class for ACE_Asynch_Accept::Result.
  
  virtual ACE_Asynch_Transmit_File_Result_Impl *create_asynch_transmit_file_result (ACE_Handler &handler,
                                                                                    ACE_HANDLE socket,
                                                                                    ACE_HANDLE file,
                                                                                    ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer,
                                                                                    u_long bytes_to_write,
                                                                                    u_long offset,
                                                                                    u_long offset_high,
                                                                                    u_long bytes_per_send,
                                                                                    u_long flags,
                                                                                    const void *act,
                                                                                    ACE_HANDLE event,
                                                                                    int priority);
  // Create the correct implementation class for ACE_Asynch_Transmit_File::Result.
  
protected:
  virtual void implementation (ACE_Proactor_Impl *implementation);
  // Set the implementation class.
  
  ACE_Proactor_Impl *implementation_;
  // Delegation/implementation class that all methods will be
  // forwarded to.

  int delete_implementation_;
  // Flag used to indicate whether we are responsible for cleaning up 
  // the implementation instance.

  static ACE_Proactor *proactor_;
  // Pointer to a process-wide <ACE_Proactor>.
  
  static int delete_proactor_;
  // Must delete the <proactor_> if non-0.

  static sig_atomic_t end_event_loop_;
  // Terminate the proactor event loop.
  
private:
  ACE_Proactor (const ACE_Proactor &);
  ACE_Proactor &operator= (const ACE_Proactor &);
  // Deny access since member-wise won't work...
};

#if defined (__ACE_INLINE__)
#include "ace/Proactor.i"
#endif /* __ACE_INLINE__ */

#else /* NOT WIN32 or POSIX with AIO features. */
class ACE_Export ACE_Proactor
{
public:
  class Timer_Queue {};
  ACE_Proactor (size_t /* number_of_threads */ = 0,
		Timer_Queue * /* tq */ = 0) {}
  virtual int handle_events (void) { return -1; }
  virtual int handle_events (ACE_Time_Value &) { return -1; }

  static ACE_Proactor *instance (size_t threads = 0);
  // Placeholder to enable compilation on non-Win32 platforms

  static ACE_Proactor *instance (ACE_Proactor *);
  // Placeholder to enable compilation on non-Win32 platforms

  static void close_singleton (void);
  // Placeholder to enable compilation on non-Win32 platforms

  static int run_event_loop (void);
  // Placeholder to enable compilation on non-Win32 platforms

  static int run_event_loop (ACE_Time_Value &tv);
  // Placeholder to enable compilation on non-Win32 platforms

  static int end_event_loop (void);
  // Placeholder to enable compilation on non-Win32 platforms

  static sig_atomic_t event_loop_done (void);
  // Placeholder to enable compilation on non-Win32 platforms
};
#endif /* ACE_WIN32 && !ACE_HAS_WINCE || ACE_HAS_AIO_CALLS*/
#endif /* ACE_PROACTOR_H */
