/* -*- C++ -*- */

// $Id$

// ============================================================================
//
// = LIBRARY
//    examples
// 
// = FILENAME
//    Driver.h
//
// = DESCRIPTION
//    This code builds an abstraction to factor out common code for 
//    the different implementations of the Timer_Queue.
//
// = AUTHORS
//    Sergio Flores-Gaitan <sergio@cs.wustl.edu>
// 
// ============================================================================

#if !defined (_DRIVER_H_)
#define _DRIVER_H_

#include "ace/Task.h"
#include "ace/Timer_Heap_T.h"
#include "ace/Timer_Queue_Adapters.h"

typedef ACE_Event_Handler_Handle_Timeout_Upcall<ACE_Null_Mutex> 
	Upcall;
typedef ACE_Timer_Heap_T<ACE_Event_Handler *,
	                 ACE_Event_Handler_Handle_Timeout_Upcall<ACE_Null_Mutex>,
			 ACE_Null_Mutex>
	Timer_Heap;
typedef ACE_Timer_Heap_Iterator_T<ACE_Event_Handler *,
                                  ACE_Event_Handler_Handle_Timeout_Upcall<ACE_Null_Mutex>,
				  ACE_Null_Mutex> 
        Timer_Heap_Iterator;
typedef ACE_Thread_Timer_Queue_Adapter<Timer_Heap>
        Thread_Timer_Queue;

template <class RECEIVER, class ACTION>
class Command 
  // = TITLE
  // @@ Please add a more descriptive title here...
  //    Command
  //
  // = DESCRIPTION
  //    This class declares an interface to execute operations,
  //    binding a RECEIVER object with an ACTION.  The RECEIVER knows
  //    how to implement the operation.  A class can invoke operations
  //    without knowing anything about it, or how it was implemented.
{
public:
  Command (RECEIVER &recvr, ACTION action);
  // @@ Please add a comment.

  virtual int execute (void *arg);
  // @@ Please add a comment.

private:
  RECEIVER &receiver_;
  // object where the method resides.

  ACTION action_;
  // method that is going to be invoked.
};

template <class TQ, class RECEIVER, class ACTION>
class Timer_Queue_Test_Driver
  // = TITLE 
  // @@ Please add a more descriptive title here...
  //    Timer_Queue_Test_Driver
  //
  // = DESCRIPTION
  //    This class implements a test driver for timer queues.  This is
  //    the place where the common code to test the different
  //    implementations of the timer queue resides.  This class has
  //    the logic for the parse_commands() method, the run_test(),
  //    read_input() and the get_next_request().  Subclasses can
  //    override these methods if there is some logic that is specific
  //    to that implementation.
{
public:
  // @@ Please comment all of these methods.
  virtual int parse_commands (const char *buf);

  virtual int run_test (void);
  
  virtual int get_next_request (void);

  virtual ssize_t read_input (char *buf, size_t bufsiz);

  // = Template Methods.
    
  virtual int display_menu (void)=0;
  
  virtual int init (void)=0;
  
protected:
  TQ timer_queue_;
  // timer queue

  // = Set of <Command>s to be executed.

  Command<RECEIVER, ACTION> *schedule_cmd_;
  // schedule timer command

  Command<RECEIVER, ACTION> *cancel_cmd_;
  // cancel timer command.

  Command<RECEIVER, ACTION> *list_cmd_;
  // list timers command.

  Command<RECEIVER, ACTION> *shutdown_cmd_;
  // shutdown the driver.
};

#endif /* _DRIVER_H_ */
