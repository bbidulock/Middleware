// $Id$

#include "Leader_Follower.h"
#include "Resource_Factory.h"

#include "ace/Reactor.h"

#if !defined (__ACE_INLINE__)
# include "Leader_Follower.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(tao, Leader_Follower, "$Id$")

TAO_Leader_Follower::~TAO_Leader_Follower (void)
{
  // Hand the reactor back to the resource factory.
  this->orb_core_->resource_factory ()->reclaim_reactor (this->reactor_);
  this->reactor_ = 0;
}

ACE_SYNCH_CONDITION*
TAO_Leader_Follower::get_next_follower (void)
{
  ACE_Unbounded_Set_Iterator<ACE_SYNCH_CONDITION *> iterator (
    this->follower_set_);

  if (iterator.first () == 0)
    // means set is empty
    return 0;

  ACE_SYNCH_CONDITION *cond = *iterator;

#if defined (TAO_DEBUG_LEADER_FOLLOWER)
  ACE_DEBUG ((LM_DEBUG,
              "TAO (%P|%t) LF::get_next_follower - "
              "follower is %x\n",
              cond));
#endif /* TAO_DEBUG_LEADER_FOLLOWER */

  // We *must* remove it when we signal it so the same condition is
  // not signalled for both wake up as a follower and as the next
  // leader.
  // The follower may not be there if the reply is received while the
  // consumer is not yet waiting for it (i.e. it send the request but
  // has not blocked to receive the reply yet)
  (void) this->remove_follower (cond); // Ignore errors..

  return cond;
}

int
TAO_Leader_Follower::wait_for_client_leader_to_complete (ACE_Time_Value *max_wait_time)
{
  int result = 0;
  ACE_Countdown_Time countdown (max_wait_time);

  // Note that we are waiting.
  ++this->event_loop_threads_waiting_;

  while (this->client_thread_is_leader_ &&
         result != -1)
    {
      if (max_wait_time == 0)
        {
          if (this->event_loop_threads_condition_.wait () == -1)
            {
              ACE_ERROR ((LM_ERROR,
                          ACE_TEXT ("TAO (%P|%t): TAO_Leader_Follower::wait_for_client_leader_to_complete - ")
                          ACE_TEXT ("Condition variable wait failed\n")));

              result = -1;
            }
        }
      else
        {
          countdown.update ();
          ACE_Time_Value tv = ACE_OS::gettimeofday ();
          tv += *max_wait_time;
          if (this->event_loop_threads_condition_.wait (&tv) == -1)
            {
              if (errno != ETIME)
                ACE_ERROR ((LM_ERROR,
                            ACE_TEXT ("TAO (%P|%t): TAO_Leader_Follower::wait_for_client_leader_to_complete - ")
                            ACE_TEXT ("Condition variable wait failed\n")));

              result = -1;
            }
        }
    }

  // Reset waiting state.
  --this->event_loop_threads_waiting_;

  return result;
}

ACE_Reactor *
TAO_Leader_Follower::reactor (void)
{
  if (this->reactor_ == 0)
    {
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock (), 0);
      if (this->reactor_ == 0)
        {
          this->reactor_ =
            this->orb_core_->resource_factory ()->get_reactor ();
        }
    }
  return this->reactor_;
}

void
TAO_Leader_Follower::set_client_thread (void)
{
  // If we were a leader thread or an event loop thread, give up
  // leadership.
  TAO_ORB_Core_TSS_Resources *tss = this->get_tss_resources ();
  if (tss->event_loop_thread_ ||
      tss->client_leader_thread_)
    {
      --this->leaders_;
    }

  if (this->clients_ == 0 &&
      this->orb_core_->has_shutdown ())
    {
      // The ORB has shutdown and we are the first client after
      // that. This means that the reactor is disabled, we must
      // re-enable it if we want to receive any replys...
      this->orb_core_->reactor ()->reset_reactor_event_loop ();
    }
  this->clients_++;
}

void
TAO_Leader_Follower::reset_client_thread (void)
{
  // If we were a leader thread or an event loop thread, take back
  // leadership.
  TAO_ORB_Core_TSS_Resources *tss = this->get_tss_resources ();
  if (tss->event_loop_thread_ ||
      tss->client_leader_thread_)
    {
      ++this->leaders_;
    }

  this->clients_--;
  if (this->clients_ == 0 && this->orb_core_->has_shutdown ())
    {
      // The ORB has shutdown and we are the last client thread, we
      // must stop the reactor to ensure that any server threads go
      // away.
      this->orb_core_->reactor ()->end_reactor_event_loop ();
    }
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Node<ACE_SYNCH_CONDITION*>;
template class ACE_Unbounded_Set<ACE_SYNCH_CONDITION*>;
template class ACE_Unbounded_Set_Iterator<ACE_SYNCH_CONDITION*>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Node<ACE_SYNCH_CONDITION*>
#pragma instantiate ACE_Unbounded_Set<ACE_SYNCH_CONDITION*>
#pragma instantiate ACE_Unbounded_Set_Iterator<ACE_SYNCH_CONDITION*>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
