/* -*- C++ -*- */
// $Id$

// ===========================================================
//
//
// = LIBRARY
//    TAO/examples/Callback_Quoter
//
// = FILENAME
//    Consumer_Input_Handler.h
//
// = DESCRIPTION
//    Definition of the Supplier_Timer_Handler class.
//
// = AUTHOR
//    Kirthika Parameswaran <kirthika@cs.wustl.edu>
//
// ===========================================================

#ifndef SUPPLIER_TIMER_HANDLER_H
#define SUPPLIER_TIMER_HANDLER_H
#include "ace/Reactor.h"
#include "ace/Timer_Queue.h"
#include "ace/Event_Handler.h"
#include "Supplier_i.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Creating a class to handle timer  events.
// Since only timer events need to be handled, only the handle_timeout
// method is overlaoded.

class Supplier;
class Supplier_Timer_Handler : public ACE_Event_Handler
{
  // = TITLE
  //    Callback Quoter Supplier Timer Handler  class.
  //
  // = Description
  //    Feeds stock information to the Callback Quoter notifier
  //    periodically.

public:

  Supplier_Timer_Handler (Supplier *supplier,ACE_Reactor *reactor);
  // initilization.

  ~Supplier_Timer_Handler (void);
  // destructor
 
  virtual int handle_timeout (const ACE_Time_Value &tv,
                              const void *arg = 0);
  // Method which will be called by the Reactor when timeout
  // occurs.

private:

  Supplier *supplier_obj_;
  // the supplier instance.

  ACE_Reactor *reactor_;
  // reactor used by the supplier.
};

#endif /* SUPPLIER_TIMER_HANDLER_H */
