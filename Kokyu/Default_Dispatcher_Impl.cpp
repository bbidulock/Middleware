// $Id$

#include "Default_Dispatcher_Impl.h"
#include "ace/Sched_Params.h"

#if ! defined (__ACE_INLINE__)
#include "Default_Dispatcher_Impl.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Kokyu, Default_Dispatcher_Impl, "$Id$")

namespace Kokyu
{

Default_Dispatcher_Impl::Default_Dispatcher_Impl ()
  : activated_ (0)
{
}

int
Default_Dispatcher_Impl::init_i (const Dispatcher_Attributes& attrs)
{
  //create and init the dispatcher tasks here

  //ACE_DEBUG ((LM_DEBUG, "entering init_t\n" ));
  int size;
  size = attrs.config_info_set_.size ();

  if (size == 0)
    return -1;

  this->ntasks_ = size;

  Dispatcher_Task_Auto_Ptr * tasks_array=0;
  ACE_NEW_RETURN (tasks_array, Dispatcher_Task_Auto_Ptr[ntasks_], -1);

  //ACE_DEBUG ((LM_DEBUG, "after new on task array\n" ));
  tasks_.reset(tasks_array);

  //ACE_DEBUG ((LM_DEBUG, "task array auto_ptr set\n" ));

  ConfigInfoSet& config_set = 
    const_cast<ConfigInfoSet&> (attrs.config_info_set_);
  ConfigInfoSet::ITERATOR iter(config_set);
  int i=0;

  ConfigInfo* config;
  for (;i<size && iter.next (config);iter.advance ())
    {
      //ACE_DEBUG ((LM_DEBUG, "iter = %d\n", i));
      Dispatcher_Task* task=0;
      ACE_NEW_RETURN (task, Dispatcher_Task (*config, ACE_Thread_Manager::instance ()), -1);
      auto_ptr<Dispatcher_Task> tmp_task_auto_ptr (task);
      tasks_[i++] = tmp_task_auto_ptr;
      //I couldn't use reset because MSVC++ auto_ptr does not have reset method.
      //So in configurations where the auto_ptr maps to the std::auto_ptr instead
      //of ACE auto_ptr, this would be a problem.
      //tasks_[i++].reset (task);
    }

  if (attrs.immediate_activation_ && !this->activated_)
    {
      this->activate_i ();
    }

  curr_config_info_ = attrs.config_info_set_;
  return 0;
}

int
Default_Dispatcher_Impl::activate_i ()
{
  int i;

  if (this->activated_)
    return 0;

  for(i=0; i<ntasks_; ++i)
    {
      long flags = THR_NEW_LWP | THR_BOUND | THR_SCHED_FIFO | THR_JOINABLE;

      Priority_t priority =
        tasks_[i]->get_curr_config_info ().thread_priority_;

      if (this->tasks_[i]->activate (flags, 1, 1, priority) == -1)
        {
          flags = THR_BOUND | THR_JOINABLE;
          priority = ACE_Sched_Params::priority_min (ACE_SCHED_OTHER,
                                                     ACE_SCOPE_THREAD);
          if (this->tasks_[i]->activate (flags, 1, 1, priority) == -1)
            ACE_ERROR ((LM_ERROR,
                        "EC (%P|%t) cannot activate queue %d", i));
        }
    }

  this->activated_ = 1;
  return 0;
}

Dispatcher_Task*
Default_Dispatcher_Impl::find_task_with_preemption_prio (Priority_t prio)
{
  int i;

  if (prio >=0)
  {
    for( i=0; i<ntasks_; ++i)
    {
      if ( tasks_[i]->preemption_priority () == prio)
        return  tasks_[i].get();
    }
  }

  return 0;
}

int
Default_Dispatcher_Impl::dispatch_i (const Dispatch_Command* cmd,
                  const QoSDescriptor& qos_info)
{
  //delegate to the appropriate task
  if (qos_info.preemption_priority_ < 0)
    return -1;

  Dispatcher_Task* task =
    find_task_with_preemption_prio (qos_info.preemption_priority_);

  if (task != 0)
    task->enqueue (cmd, qos_info);
  else
    tasks_[0]->enqueue (cmd, qos_info);

  return 0;
}

int
Default_Dispatcher_Impl::shutdown_i ()
{
  //post shutdown command to all tasks
  int i;

  for(i=0; i<ntasks_; ++i)
    {
      QoSDescriptor qos_info;
      Shutdown_Task_Command* shutdown_cmd = 0;
      ACE_NEW_RETURN (shutdown_cmd, Shutdown_Task_Command, -1);
      tasks_[i]->enqueue (shutdown_cmd, qos_info);
    }

  //wait for all tasks to exit
  for (i=0; i<ntasks_; ++i)
    {
      tasks_[i]->wait ();
    }

  return 0;
}

int
Shutdown_Task_Command::execute ()
{
  return -1;
}

}
