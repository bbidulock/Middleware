// $Id$

#include "EC_RTCORBA_Dispatching.h"
#include "tao/RTCORBA/Priority_Mapping.h"

#if ! defined (__ACE_INLINE__)
#include "EC_RTCORBA_Dispatching.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Event, EC_RTCORBA_Dispatching, "$Id$")

TAO_EC_RTCORBA_Dispatching::
  TAO_EC_RTCORBA_Dispatching (const RTCORBA::ThreadpoolLanes &lanes,
                              RTCORBA::PriorityMapping *mapping,
                              RTCORBA::Current_ptr current)
    :  lanes_ (lanes)
    , priority_mapping_ (mapping)
    , current_ (RTCORBA::Current::_duplicate (current))
{
  ACE_NEW (this->tasks_, TAO_EC_Dispatching_Task[this->lanes_.length ()]);
  for (CORBA::ULong i = 0; i != this->lanes_.length (); ++i)
    this->tasks_->thr_mgr (&this->thread_manager_);
}

TAO_EC_RTCORBA_Dispatching::~TAO_EC_RTCORBA_Dispatching (void)
{
  delete[] this->tasks_;
}

void
TAO_EC_RTCORBA_Dispatching::activate (void)
{
  for (CORBA::ULong i = 0; i != this->lanes_.length (); ++i)
    {
      CORBA::ULong nthreads = this->lanes_[i].static_threads;
      if (nthreads == 0)
        {
          nthreads = 1;
        }
      RTCORBA::Priority corba_priority = this->lanes_[i].lane_priority;
      RTCORBA::NativePriority native_priority;
      if (this->priority_mapping_->to_native (corba_priority,
                                              native_priority) != 0)
        {
          this->tasks_[i].activate (THR_NEW_LWP | THR_JOINABLE,
                                    nthreads,
                                    0,
                                    native_priority);
        }
    }
}

void
TAO_EC_RTCORBA_Dispatching::shutdown (void)
{
  for (CORBA::ULong i = 0; i != this->lanes_.length (); ++i)
    {
      int nthreads =
        this->thread_manager_.num_threads_in_task (&this->tasks_[i]);
      if (nthreads <= 0)
        continue;
      for (int j = 0; j != nthreads; ++j)
        {
          this->tasks_[i].putq (new TAO_EC_Shutdown_Task_Command);
        }
    }
  this->thread_manager_.wait ();
}

void
TAO_EC_RTCORBA_Dispatching::push (TAO_EC_ProxyPushSupplier* proxy,
                             RtecEventComm::PushConsumer_ptr consumer,
                             const RtecEventComm::EventSet& event,
                             TAO_EC_QOS_Info& qos_info
                             ACE_ENV_ARG_DECL)
{
  RtecEventComm::EventSet event_copy = event;
  this->push_nocopy (proxy, consumer, event_copy, qos_info ACE_ENV_ARG_PARAMETER);
}

void
TAO_EC_RTCORBA_Dispatching::push_nocopy (TAO_EC_ProxyPushSupplier* proxy,
                                         RtecEventComm::PushConsumer_ptr consumer,
                                         RtecEventComm::EventSet& event,
                                         TAO_EC_QOS_Info&
                                         ACE_ENV_ARG_DECL)
{
  RTCORBA::Priority current_priority =
    this->current_->the_priority (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  for (CORBA::ULong i = 0; i != this->lanes_.length (); ++i)
    {
      if (this->lanes_[i].lane_priority != current_priority)
        continue;

      // @@ If there were no threads available we may need to create
      // some...

      this->tasks_[i].push (proxy, consumer, event
                            ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
      break;
    }
}
