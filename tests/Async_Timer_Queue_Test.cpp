// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
// 
// = FILENAME
//    Async_Timer_Queue_Test.cpp
//
// = DESCRIPTION
//      This test exercises the <ACE_Asynch_Timer_Queue_Adapter> 
//      using an <ACE_Timer_List>.
//
// = AUTHORS
//    Douglas C. Schmidt
// 
// ============================================================================

#include "ace/Signal.h"
#include "ace/Timer_List.h"
#include "test_config.h"

class Timer_Handler : public ACE_Event_Handler
  // = TITLE
  //     Target of the asynchronous timeout operation.
{
public:
  virtual int handle_timeout (const ACE_Time_Value &tv,
			      const void *arg);
  // Callback hook invoked by the <Timer_Queue>.
};

int 
Timer_Handler::handle_timeout (const ACE_Time_Value &tv,
			       const void *arg)
{
  ACE_DEBUG ((LM_DEBUG,
	      "handle_timeout() = (%d, %d) %d\n",
	      tv.sec (),
	      tv.usec (),
	      arg));
  delete this;
  return 0;
}

// Create a helpful typedef.
class Async_Timer_Queue : public ACE_Async_Timer_Queue_Adapter<ACE_Timer_List>
  // = TITLE
  //     Asynchronous Timer Queue Singleton, instantiated by an <ACE_Timer_List>.
{
public:
  static Async_Timer_Queue *instance (void);
  // Singleton access point.

  void dump (void);
  // Dump the contents of the queue.

private:
  Async_Timer_Queue (void);
  // Private constructor enforces the Singleton.

  static Async_Timer_Queue *instance_;
  // Pointer to the timer queue.
};

// Initialize the Singleton pointer.
Async_Timer_Queue *Async_Timer_Queue::instance_ = 0;

// Implement the Singleton logic.
Async_Timer_Queue *
Async_Timer_Queue::instance (void)
{
  if (Async_Timer_Queue::instance_ == 0)
    {
      // Initialize with all signals enabled.
      ACE_Sig_Set ss (1);

      // Don't block out SIGQUIT.
      ss.sig_del (SIGQUIT);

      ACE_NEW_RETURN (Async_Timer_Queue::instance_,
		      ACE_Async_Timer_Queue_Adapter<ACE_Timer_List> (&ss),
		      0);
    }
  return Async_Timer_Queue::instance_;
}

// Dump the contents of the queue.
void
Async_Timer_Queue::dump (void)
{
  ACE_DEBUG ((LM_DEBUG, "begin dumping timer queue\n"));

  for (ACE_Timer_List_Iterator iter (Async_Timer_Queue::instance ()->timer_queue ());
       iter.item () != 0;
       iter.next ())
    iter.item ()->dump ();

  ACE_DEBUG ((LM_DEBUG, "end dumping timer queue\n"));
}

// Command-line API.

static int
parse_commands (char *buf)
{
  u_int choice;
  long value;

  if (sscanf (buf, "%u %ld", &choice, &value) != 2)
    ACE_ERROR_RETURN ((LM_ERROR, "invalid input %s", buf), -1);

  switch (choice)
    {
    case 1: // Schedule a timer.
      {
	ACE_Time_Value tv (0, value);
	ACE_Event_Handler *eh;
	ACE_NEW_RETURN (eh, Timer_Handler, -1);

	long tid = Async_Timer_Queue::instance ()->schedule 
	  (eh, 0, ACE_OS::gettimeofday () + tv);

	if (tid == -1)
	  ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "schedule_timer"), -1);
	
	break;
	/* NOTREACHED */
      }
    case 2: // Cancel a timer.
      {
	const void *act;

	if (Async_Timer_Queue::instance ()->cancel (value, &act) == -1)
	  ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "cancel_timer"), -1);

	// In this case, the act will be 0, but it might be a real
	// pointer.
	delete (ACE_Event_Handler *) act;

	ACE_DEBUG ((LM_DEBUG, "canceling %d\n", value));
	break;
	/* NOTREACHED */
      }
    }

  return 0;
}

static void 
signal_handler (int signum)
{
  ACE_DEBUG ((LM_DEBUG, "handling signal %S\n", signum));

  switch (signum)
    {
    /* NOTREACHED */
    case SIGINT:
      {
        Async_Timer_Queue::instance ()->dump ();
	break;
	/* NOTREACHED */
      }
    case SIGQUIT:
      ACE_DEBUG ((LM_DEBUG, "shutting down on SIGQUIT%a\n", 1));
      /* NOTREACHED */
      break;
    }
}

static void
register_signal_handlers (void)
{
  // Register SIGQUIT (never blocked).
  ACE_Sig_Action sigquit ((ACE_SignalHandler) signal_handler,
			  SIGQUIT);
  ACE_UNUSED_ARG (sigquit);

  // Don't let the SIGALRM interrupt the SIGINT handler!
  ACE_Sig_Set ss;
  ss.sig_add (SIGALRM);

  ACE_Sig_Action sigint ((ACE_SignalHandler) handler,
			 SIGINT,
			 ss,
			 SA_RESTART);
  ACE_UNUSED_ARG (sigint);
}

static char menu[] = 
"****\n"
"1) schedule_timer <usecs> \n"
"2) cancel_timer <timer_id>\n"
"^C list_timers\n"
"please enter your choice: ";

int
main (int, char *[])
{
  // ACE_START_TEST ("Timer_Queue_Test");

  register_signal_handlers ();

  for (;;)
    {
      ACE_DEBUG ((LM_DEBUG, "%s", menu));

      char buf[BUFSIZ];

      if (ACE_OS::read (ACE_STDIN, buf, sizeof buf) <= 0)
	break;

      parse_commands (buf);
    }

  // ACE_END_TEST;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Async_Timer_Queue_Adapter<ACE_Timer_List>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Async_Timer_Queue_Adapter<ACE_Timer_List>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
