// -*- C++ -*-
// $Id$

// ****************************************************************

ACE_INLINE
TAO_Leader_Follower::TAO_Leader_Follower (TAO_ORB_Core* orb_core)
  : orb_core_ (orb_core),
    reverse_lock_ (lock_),
    leaders_ (0),
    clients_ (0),
    reactor_ (0),
    client_thread_is_leader_ (0),
    event_loop_threads_waiting_ (0),
    event_loop_threads_condition_ (lock_)
{
}

ACE_INLINE TAO_ORB_Core_TSS_Resources *
TAO_Leader_Follower::get_tss_resources (void) const
{
  return this->orb_core_->get_tss_resources ();
}

ACE_INLINE int
TAO_Leader_Follower::follower_available (void) const
{
  return !this->follower_set_.is_empty ();
}

ACE_INLINE int
TAO_Leader_Follower::elect_new_leader (void)
{
  if (this->leaders_ == 0)
    {
      if (this->event_loop_threads_waiting_)
        {
          return this->event_loop_threads_condition_.broadcast ();
        }
      else if (this->follower_available ())
        {
          ACE_SYNCH_CONDITION* condition_ptr = this->get_next_follower ();
          if (condition_ptr == 0 || condition_ptr->signal () == -1)
            return -1;
        }
    }
  return 0;
}

ACE_INLINE int
TAO_Leader_Follower::set_event_loop_thread (ACE_Time_Value *max_wait_time)
{
  TAO_ORB_Core_TSS_Resources *tss = this->get_tss_resources ();

  // Make sure that there is no other client thread run the show.  If
  // we are the client thread running the show, then it is ok.
  if (this->client_thread_is_leader_ &&
      tss->client_leader_thread_ == 0)
    {
      int result =
        this->wait_for_client_leader_to_complete (max_wait_time);

      if (result != 0)
        return result;
    }

  // If <event_loop_thread_> == 0 and <client_leader_thread_> == 0, we
  // are running the event loop for the first time.  Therefore,
  // increment the leaders.  Otherwise, simply increment
  // <event_loop_thread_> since either (a) if <event_loop_thread_> !=
  // 0 this is a nested call to the event loop, or (b)
  // <client_leader_thread_> != 0 this is a call to the event loop
  // while we are a client leader.
  if (tss->event_loop_thread_ == 0 &&
      tss->client_leader_thread_ == 0)
    ++this->leaders_;

  ++tss->event_loop_thread_;

  return 0;
}

ACE_INLINE void
TAO_Leader_Follower::reset_event_loop_thread_i (TAO_ORB_Core_TSS_Resources *tss)
{
  // Always decrement <event_loop_thread_>. If <event_loop_thread_>
  // reaches 0 and we are not a client leader, we are done with our
  // duties of running the event loop. Therefore, decrement the
  // leaders.  Otherwise, we just got done with a nested call to the
  // event loop or a call to the event loop when we were the client
  // leader.
  --tss->event_loop_thread_;

  if (tss->event_loop_thread_ == 0 &&
      tss->client_leader_thread_ == 0)
    --this->leaders_;
}

ACE_INLINE void
TAO_Leader_Follower::reset_event_loop_thread (void)
{
  TAO_ORB_Core_TSS_Resources *tss = this->get_tss_resources ();
  if (tss->event_loop_thread_ > 0)
    this->reset_event_loop_thread_i (tss);
}

ACE_INLINE ACE_SYNCH_MUTEX &
TAO_Leader_Follower::lock (void)
{
  return this->lock_;
}

ACE_INLINE void
TAO_Leader_Follower::set_upcall_thread (void)
{
  TAO_ORB_Core_TSS_Resources *tss = this->get_tss_resources ();

  if (tss->event_loop_thread_ > 0)
    {
      ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock ());
      this->reset_event_loop_thread_i (tss);

      this->elect_new_leader ();
    }
}

ACE_INLINE int
TAO_Leader_Follower::leader_available (void) const
{
  return this->leaders_ != 0;
}

ACE_INLINE void
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

ACE_INLINE void
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

ACE_INLINE void
TAO_Leader_Follower::set_client_leader_thread (void)
{
  TAO_ORB_Core_TSS_Resources *tss = this->get_tss_resources ();
  ++this->leaders_;
  this->client_thread_is_leader_ = 1;
  ++tss->client_leader_thread_;
}

ACE_INLINE void
TAO_Leader_Follower::reset_client_leader_thread (void)
{
  TAO_ORB_Core_TSS_Resources *tss = this->get_tss_resources ();
  --tss->client_leader_thread_;
  --this->leaders_;
  this->client_thread_is_leader_ = 0;
}

ACE_INLINE int
TAO_Leader_Follower::is_client_leader_thread (void) const
{
  TAO_ORB_Core_TSS_Resources *tss = this->get_tss_resources ();
  return tss->client_leader_thread_ != 0;
}

ACE_INLINE int
TAO_Leader_Follower::add_follower (ACE_SYNCH_CONDITION *follower_ptr)
{
  return this->follower_set_.insert (follower_ptr);
}

ACE_INLINE int
TAO_Leader_Follower::remove_follower (ACE_SYNCH_CONDITION *follower_ptr)
{
  return this->follower_set_.remove (follower_ptr);
}

ACE_INLINE ACE_Reverse_Lock<ACE_SYNCH_MUTEX> &
TAO_Leader_Follower::reverse_lock (void)
{
  return this->reverse_lock_;
}

ACE_INLINE int
TAO_Leader_Follower::has_clients (void) const
{
  return this->clients_;
}

ACE_INLINE
TAO_LF_Client_Thread_Helper::TAO_LF_Client_Thread_Helper (TAO_Leader_Follower &leader_follower)
  : leader_follower_ (leader_follower)
{
  this->leader_follower_.set_client_thread ();
}

ACE_INLINE
TAO_LF_Client_Thread_Helper::~TAO_LF_Client_Thread_Helper (void)
{
  this->leader_follower_.reset_client_thread ();
}

ACE_INLINE
TAO_LF_Client_Leader_Thread_Helper::TAO_LF_Client_Leader_Thread_Helper (TAO_Leader_Follower &leader_follower)
  : leader_follower_ (leader_follower)
{
  this->leader_follower_.set_client_leader_thread ();
}

ACE_INLINE
TAO_LF_Client_Leader_Thread_Helper::~TAO_LF_Client_Leader_Thread_Helper (void)
{
  this->leader_follower_.reset_client_leader_thread ();
}

ACE_INLINE int
TAO_LF_Event_Loop_Thread_Helper::set_event_loop_thread (ACE_Time_Value *max_wait_time)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->leader_follower_.lock (), -1);

  int result =
    this->leader_follower_.set_event_loop_thread (max_wait_time);

  // If successful, reset has to be called.
  if (result == 0)
    this->call_reset_ = 1;

  return result;
}

ACE_INLINE
TAO_LF_Event_Loop_Thread_Helper::TAO_LF_Event_Loop_Thread_Helper (TAO_Leader_Follower &leader_follower)
  : leader_follower_ (leader_follower),
    call_reset_ (0)
{
}

ACE_INLINE
TAO_LF_Event_Loop_Thread_Helper::~TAO_LF_Event_Loop_Thread_Helper (void)
{
  ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->leader_follower_.lock ());

  if (this->call_reset_)
    this->leader_follower_.reset_event_loop_thread ();

  int result = this->leader_follower_.elect_new_leader ();

  if (result == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("TAO (%P|%t) Failed to wake up ")
                ACE_TEXT ("a follower thread\n")));
}
