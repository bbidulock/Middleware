// $Id$

// ============================================================================
//
// = LIBRARY
//    examples
// 
// = FILENAME
//    main_async.cpp             
//
// = DESCRIPTION
//      Implements an asynchronous timer queue.
//      This code exercises the Timer_Queue_Test_Driver class using
//      signals as an asynchronous mechanism to dispatch events.
//
// = AUTHORS
//    Douglas Schmidt      <schmidt@cs.wustl.edu> &&
//    Sergio Flores-Gaitan <sergio@cs.wustl.edu>  
// 
// ============================================================================

#include "ace/Auto_Ptr.h"
#include "Driver.h"
#include "Async_Timer_Queue_Test.h"

typedef Timer_Queue_Test_Driver<Async_Timer_Queue *,
                                Async_Timer_Queue,
                                Async_Timer_Queue::ACTION>
        ASYNC_TIMER_QUEUE_TEST_DRIVER;

int
main (int, char *[])
{
  // Auto ptr ensures that the driver memory is released
  // automatically.
  auto_ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER> driver;
  ASYNC_TIMER_QUEUE_TEST_DRIVER *tqtd;
  
  ACE_NEW_RETURN (tqtd, Async_Timer_Queue_Test_Driver, -1);
  driver = tqtd;
  
  return driver->run_test ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class auto_ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER>;
template class ACE_Auto_Basic_Ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate auto_ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER>
#pragma instantiate ACE_Auto_Basic_Ptr <ASYNC_TIMER_QUEUE_TEST_DRIVER>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


