/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Timer_Queue_T.h
//
// = AUTHOR
//    Doug Schmidt and Irfan Pyarali
// 
// ============================================================================

#if !defined (ACE_TIMER_QUEUE_T_H)
#define ACE_TIMER_QUEUE_T_H

#include "ace/Time_Value.h"

// Forward declarations.
template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_Queue_T;

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_List_T;

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_List_Iterator_T;

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_Heap_T;

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_Heap_Iterator_T;

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_Wheel_T;

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_Wheel_Iterator_T;

// This should be nested within the ACE_Timer_Queue class but some C++
// compilers still don't like this...

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_Node_T
  // = TITLE
  //     Maintains the state associated with a Timer entry.
{
  // = The use of friends should be replaced with accessors...
  friend class ACE_Timer_Queue_T<TYPE, FUNCTOR, LOCK>;
  friend class ACE_Timer_List_T<TYPE, FUNCTOR, LOCK>;
  friend class ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, LOCK>;
  friend class ACE_Timer_Heap_T<TYPE, FUNCTOR, LOCK>;
  friend class ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, LOCK>;
  friend class ACE_Timer_Wheel_T<TYPE, FUNCTOR, LOCK>;
  friend class ACE_Timer_Wheel_Iterator_T<TYPE, FUNCTOR, LOCK>;

  // = Initialization methods.
  ACE_Timer_Node_T (const TYPE &type, 
		    const void *a, 
		    const ACE_Time_Value &t, 
		    const ACE_Time_Value &i, 
		    ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *n, 
		    long timer_id);
  // Constructor.

  ACE_Timer_Node_T (const TYPE &type, 
		    const void *a, 
		    const ACE_Time_Value &t, 
		    const ACE_Time_Value &i, 
		    ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *p,
                    ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *n, 
		    long timer_id);
  // Constructor for the doubly linked list version.


  ACE_Timer_Node_T (void);
  // Default constructor.
  
  TYPE type_;
  // Type of object stored in the Queue
  
  const void *act_;
  // Act associated with the timer.
  
  ACE_Time_Value timer_value_;
  // Time until the timer expires.
  
  ACE_Time_Value interval_;
  // If this is a periodic timer this holds the time until the next
  // timeout.

  ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *prev_;
  // Pointer to previous timer.

  ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *next_;
  // Pointer to next timer.
  
  long timer_id_;
  // Id of this timer (used to cancel timers before they expire).

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

  void dump (void) const;
  // Dump the state of an TYPE.
};

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_Queue_Iterator_T
  // = TITLE
  //     Generic interfae for iterating over a subclass of
  //     <ACE_Timer_Queue>.
  //
  // = DESCRIPTION
  //     This is a special type of iterator that "advances" by moving
  //     the head of the timer queue up by one every time.
{
public:
  // = Initialization and termination methods.
  ACE_Timer_Queue_Iterator_T (void);
  // Constructor.

  virtual ~ACE_Timer_Queue_Iterator_T (void);
  // Destructor.

  virtual int next (ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *&timer_node,
		    const ACE_Time_Value &cur_time) = 0;
  // Pass back the next <timer_node> that hasn't been seen yet, if its
  // <time_value_> <= <cur_time>.  In addition, moves the timer queue
  // forward by one node.  Returns 0 when all <timer_nodes> have been
  // seen, else 1.
};

template <class TYPE, class FUNCTOR, class LOCK>
class ACE_Timer_Queue_T
  // = TITLE 
  //      Provides an interface to timers.
  //
  // = DESCRIPTION
  //      This is an abstract base class that provides hook for
  //      implementing specialized policies such as <ACE_Timer_List>
  //      and <ACE_Timer_Heap>.
{
public: 
  typedef ACE_Timer_Queue_Iterator_T<TYPE, FUNCTOR, LOCK> ITERATOR;
  // Type of Iterator

  // = Initialization and termination methods.
  ACE_Timer_Queue_T (FUNCTOR *upcall_functor = 0);
  // Default constructor. <upcall_functor> is the instance of the
  // FUNCTOR to be used by the queue. If <upcall_functor> is 0, Timer
  // Queue will create a default FUNCTOR.

  virtual ~ACE_Timer_Queue_T (void);
  // Destructor - make virtual for proper destruction of inherited
  // classes.

  virtual int is_empty (void) const = 0;
  // True if queue is empty, else false.

  virtual const ACE_Time_Value &earliest_time (void) const = 0;
  // Returns the time of the earlier node in the Timer_Queue.

  virtual long schedule (const TYPE &type, 
			 const void *act, 
			 const ACE_Time_Value &delay,
			 const ACE_Time_Value &interval = ACE_Time_Value::zero) = 0;
  // Schedule <type> that will expire after <delay> amount of time.
  // If it expires then <act> is passed in as the value to the
  // <functor>.  If <interval> is != to <ACE_Time_Value::zero> then it
  // is used to reschedule the <type> automatically.  This method
  // returns a <timer_id> that uniquely identifies the the <type>
  // entry in an internal list.  This <timer_id> can be used to cancel
  // the timer before it expires.  The cancellation ensures that
  // <timer_ids> are unique up to values of greater than 2 billion
  // timers.  As long as timers don't stay around longer than this
  // there should be no problems with accidentally deleting the wrong
  // timer.  Returns -1 on failure (which is guaranteed never to be a
  // valid <timer_id>).

  virtual int cancel (const TYPE &type,
		      int dont_call_handle_close = 1) = 0;
  // Cancel all timer associated with <type>.  If <dont_call> is 0
  // then the <functor> will be invoked.  Returns number of timers
  // cancelled.

  virtual int cancel (long timer_id, 
		      const void **act = 0,
		      int dont_call_handle_close = 1) = 0;
  // Cancel the single timer that matches the <timer_id> value (which
  // was returned from the <schedule> method).  If act is non-NULL
  // then it will be set to point to the ``magic cookie'' argument
  // passed in when the timer was registered.  This makes it possible
  // to free up the memory and avoid memory leaks.  If <dont_call> is
  // 0 then the <functor> will be invoked.  Returns 1 if cancellation
  // succeeded and 0 if the <timer_id> wasn't found.

  virtual int expire (const ACE_Time_Value &current_time);
  // Run the <functor> for all timers whose values are <= <cur_time>.
  // This does not account for <timer_skew>.  Returns the number of
  // timers canceled.

  virtual int expire (void);
  // Run the <functor> for all timers whose values are <=
  // <ACE_OS::gettimeofday>.  Also accounts for <timer_skew>.  Returns
  // the number of timers canceled.

  virtual ACE_Time_Value gettimeofday (void);
  // Returns the current time of day.  This allows different
  // implementations of the timer queue to use special high resolution
  // timers.

  void gettimeofday (ACE_Time_Value (*gettimeofday)(void));
  // Allows applications to control how the timer queue gets the time
  // of day.

  virtual ACE_Time_Value *calculate_timeout (ACE_Time_Value *max);
  // Determine the next event to timeout.  Returns <max> if there are
  // no pending timers or if all pending timers are longer than max.

  // = Set/get the timer skew for the Timer_Queue.
  void timer_skew (const ACE_Time_Value &skew);
  const ACE_Time_Value &timer_skew (void) const;

  LOCK &mutex (void); 
  // Synchronization variable used by the queue

  FUNCTOR &upcall_functor (void);
  // Accessor to the upcall functor

  virtual void dump (void) const;
  // Dump the state of a object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:

  virtual void upcall (TYPE &type,
		       const void *act,
		       const ACE_Time_Value &cur_time);
  // This method will call the <functor> with the <type>, <act> and
  // <time>

  virtual void reschedule (ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *) = 0;
  // Reschedule an "interval" <ACE_Timer_Node>.

  virtual ITERATOR &iter (void) = 0;
  // Returns a pointer to this <ACE_Timer_Queue>'s iterator.

  virtual ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *alloc_node (void) = 0;
  // Factory method that allocates a new node.

  virtual void free_node (ACE_Timer_Node_T<TYPE, FUNCTOR, LOCK> *) = 0;
  // Factory method that frees a previously allocated node.

  LOCK mutex_; 
  // Synchronization variable for <ACE_Timer_Queue>.

  ACE_Time_Value (*gettimeofday_)(void);
  // Pointer to function that returns the current time of day.

  FUNCTOR &upcall_functor_;
  // Upcall functor

  int delete_upcall_functor_;
  // To delete or not to delete is the question?

private:
  ACE_Time_Value timeout_;
  // Returned by <calculate_timeout>.

  ACE_Time_Value timer_skew_;
  // Adjusts for timer skew in various clocks.

  // = Don't allow these operations for now.
  ACE_Timer_Queue_T (const ACE_Timer_Queue_T<TYPE, FUNCTOR, LOCK> &);
  void operator= (const ACE_Timer_Queue_T<TYPE, FUNCTOR, LOCK> &);
};

#if defined (__ACE_INLINE__)
#include "ace/Timer_Queue_T.i"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Timer_Queue_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Timer_Queue_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_TIMER_QUEUE_T_H */
