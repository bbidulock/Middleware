// $Id$

#include "EC_MT_Dispatching.h"

ACE_RCSID(Event, EC_MT_Dispatching, "$Id$")

TAO_EC_MT_Dispatching::TAO_EC_MT_Dispatching (int nthreads,
                                              int thread_creation_flags,
                                              int thread_priority,
                                              int force_activate)
  :  nthreads_ (nthreads),
     thread_creation_flags_ (thread_creation_flags),
     thread_priority_ (thread_priority),
     force_activate_ (force_activate),
     task_ (&this->thread_manager_),
     active_ (0)
{
}

void
TAO_EC_MT_Dispatching::activate (void)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);

  if (this->active_ != 0)
    return;

  this->active_ = 1;

  if (this->task_.activate (this->thread_creation_flags_,
                            this->nthreads_,
                            1,
                            this->thread_priority_) == -1)
    {
      if (this->force_activate_ != 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "EC (%P|%t) activating dispatching queue at"
                      " default priority\n"));
          if (this->task_.activate (THR_BOUND, this->nthreads_) == -1)
            ACE_ERROR ((LM_ERROR,
                        "EC (%P|%t) cannot activate dispatching queue.\n"));
        }
    }
}

void
TAO_EC_MT_Dispatching::shutdown (void)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);

  if (this->active_ == 0)
    return;

  for (int i = 0; i < this->nthreads_; ++i)
    {
      this->task_.putq (new TAO_EC_Shutdown_Task_Command);
    }
  this->thread_manager_.wait ();
}

void
TAO_EC_MT_Dispatching::push (TAO_EC_ProxyPushSupplier* proxy,
                             RtecEventComm::PushConsumer_ptr consumer,
                             const RtecEventComm::EventSet& event,
                             TAO_EC_QOS_Info& qos_info
                             ACE_ENV_ARG_DECL)
{
  RtecEventComm::EventSet event_copy = event;
  this->push_nocopy (proxy, consumer, event_copy, qos_info ACE_ENV_ARG_PARAMETER);
}

void
TAO_EC_MT_Dispatching::push_nocopy (TAO_EC_ProxyPushSupplier* proxy,
                                    RtecEventComm::PushConsumer_ptr consumer,
                                    RtecEventComm::EventSet& event,
                                    TAO_EC_QOS_Info&
                                    ACE_ENV_ARG_DECL)
{
  // Double checked locking....
  if (this->active_ == 0)
    this->activate ();

  this->task_.push (proxy, consumer, event ACE_ENV_ARG_PARAMETER);
}
