/* -*- C++ -*- */
// $Id$

#include "ace/Reactor.h"



ACE_INLINE
ACE_Select_Reactor_Impl::ACE_Select_Reactor_Impl ()
    : handler_rep_ (*this),
      timer_queue_ (0),
      delete_timer_queue_ (0),
      delete_signal_handler_ (0),
      delete_notify_handler_ (0),
      requeue_position_ (-1), // Requeue at end of waiters by default.
      initialized_ (0),
      state_changed_ (0),
      supress_renew_ (0)
{
}

ACE_INLINE int
ACE_Select_Reactor_Impl::purge_pending_notifications (ACE_Event_Handler *eh,
                                                      ACE_Reactor_Mask mask)
{
  if (this->notify_handler_ == 0)
    return 0;
  else
    return this->notify_handler_->purge_pending_notifications (eh, mask);
}

ACE_INLINE int
ACE_Select_Reactor_Impl::supress_notify_renew (void)
{
  return this->supress_renew_;
}

ACE_INLINE void
ACE_Select_Reactor_Impl::supress_notify_renew (int sr)
{
  this->supress_renew_ = sr;
}
