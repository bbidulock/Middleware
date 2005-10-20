// $Id$

#include "CSD_TP_Task.h"
#include "CSD_TP_Request.h"
#include "CSD_TP_Dispatchable_Visitor.h"
#include "CSD_TP_Cancel_Visitor.h"

ACE_RCSID (CSD_ThreadPool,
           TP_Task,
           "$Id$")

#if !defined (__ACE_INLINE__)
# include "CSD_TP_Task.inl"
#endif /* ! __ACE_INLINE__ */

TAO::CSD::TP_Task::~TP_Task()
{
}


bool
TAO::CSD::TP_Task::add_request(TP_Request* request)
{
  GuardType guard(this->lock_);

  if (!this->accepting_requests_)
    {
      ACE_DEBUG((LM_DEBUG,"(%P|%t) TP_Task::add_request() - "
                 "not accepting requests\n"));
      return false;
    }

  // We have made the decision that the request is going to be placed upon
  // the queue_.  Inform the request that it is about to be placed into
  // a request queue.  Some requests may not need to do anything in
  // preparation of being placed into a queue.  Others, however, may need
  // to perfom a "clone" operation on some underlying request data before
  // the request can be properly placed into a queue.
  request->prepare_for_queue();

  this->queue_.put(request);

  this->work_available_.signal();

  return true;
}


int
TAO::CSD::TP_Task::open(void* num_threads_ptr)
{
  unsigned num = 1;

  if (num_threads_ptr != 0)
    {
      unsigned* tmp = static_cast<unsigned*> (num_threads_ptr);

      if (tmp == 0)
        {
          ACE_ERROR_RETURN((LM_ERROR,
                            "(%P|%t) TP_Task failed to open.  "
                            "Invalid argument type passed to open().\n"),
                           -1);
        }

      num = *tmp;
    }

  // We can't activate 0 threads.  Make sure this isn't the case.
  if (num < 1)
    {
      ACE_ERROR_RETURN((LM_ERROR,
                        "(%P|%t) TP_Task failed to open.  "
                        "num_threads_ (%u) is less-than 1.\n",
                        num),
                       -1);
    }

  // Likewise, we can't activate too many.  Make sure this isn't the case.
  if (num > MAX_THREADPOOL_TASK_WORKER_THREADS)
    {
      ACE_ERROR_RETURN((LM_ERROR,
                        "(%P|%t) TP_Task failed to open.  "
                        "num_threads_ (%u) is too large.  Max is %d.\n",
                        num, MAX_THREADPOOL_TASK_WORKER_THREADS),
                        -1);
    }

  // We need the lock acquired from here on out.
  GuardType guard(this->lock_);

  // We can assume that we are in the proper state to handle this open()
  // call as long as we haven't been open()'ed before.
  if (this->opened_)
    {
      ACE_ERROR_RETURN((LM_ERROR,
                        "(%P|%t) TP_Task failed to open.  "
                        "Task has previously been open()'ed.\n"),
                       -1);
    }

  // Activate this task object with 'num' worker threads.
  if (this->activate(THR_NEW_LWP | THR_JOINABLE, num) != 0)
    {
      // Assumes that when activate returns non-zero return code that
      // no threads were activated.
      ACE_ERROR_RETURN((LM_ERROR,
                        "(%P|%t) TP_Task failed to activate "
                        "(%d) worker threads.\n",
                        num),
                       -1);
    }

  // Now we have past the point where we can say we've been open()'ed before.
  this->opened_ = true;

  // Now we wait until all of the threads have started.
  while (this->num_threads_ != num)
    {
      this->active_workers_.wait();
    }

  // We can now accept requests (via our add_request() method).
  this->accepting_requests_ = true;

  return 0;
}


int
TAO::CSD::TP_Task::svc()
{
  // Account for this current worker thread having started the
  // execution of this svc() method.
  {
    GuardType guard(this->lock_);
    // Put the thread id into a collection which is used to check whether  
    // the orb shutdown is called by one of the threads in the pool.
    ACE_thread_t thr_id = ACE_OS::thr_self ();
    if (this->activated_threads_.set(thr_id, this->num_threads_) == -1)
      {
        ACE_ERROR_RETURN((LM_ERROR,
          ACE_TEXT("(%P|%t)TP_Task::svc: number of threads is out of range \n")),
          0); 
      }
    ++this->num_threads_;
    this->active_workers_.signal();
  }

  // This visitor object will be re-used over and over again as part of
  // the "GetWork" logic below.
  TP_Dispatchable_Visitor dispatchable_visitor;

  // Start the "GetWork-And-PerformWork" loop for the current worker thread.
  while (1)
    {
      TP_Request_Handle request;

      // Do the "GetWork" step.
      {
        // Acquire the lock until just before we decide to "PerformWork".
        GuardType guard(this->lock_);

        // Start the "GetWork" loop.
        while (request.is_nil())
        {
          if (this->shutdown_initiated_)
            {
              // This breaks us out of all loops with one fell swoop.
              return 0;
            }

          // There is no need to visit the queue if it is empty.
          if (!this->queue_.is_empty())
            {
              // Reset the visitor since we use it over and over.  This
              // will cause the visitor to drop any reference to
              // a request that it may still be holding from a prior
              // call to accept_visitor().
              dispatchable_visitor.reset();

              // Visit the requests in the queue in hopes of
              // locating the first "dispatchable" (ie, not busy) request.
              // If a dispatchable request is located, it is extracted
              // from the queue and saved in a handle data member in the
              // visitor object.
              this->queue_.accept_visitor(dispatchable_visitor);

              // If a dispatchable request is located, it is extracted
              // from the queue and saved in a handle data member in the
              // visitor object.  Let's get a "copy" (or a NULL pointer
              // if the visitor didn't locate/extract one).
              request = dispatchable_visitor.request();
            }

          // Either the queue is empty or we couldn't find any dispatchable
          // requests in the queue at this time.
          if (request.is_nil())
            {
              // Let's wait until we hear about the possibility of
              // work before we go look again.
              this->work_available_.wait();
            }
        }

        // We have dropped out of the "while (request.is_nil())" loop.
        // We only get here is we located/extracted a dispatchable request
        // from the queue.  Note that the visitor will have already
        // marked the target servant as now being busy (because of us).
        // We can now safely release the lock.
      }

      // Do the "PerformWork" step.  We don't need the lock_ to do this.
      request->dispatch();

      // Now that the request has been dispatched, we need to mark the target
      // servant as no longer being busy, and we need to signal any wait()'ing
      // worker threads that there may be some dispatchable requests in the
      // queue now for this not-busy servant.  We need the lock_ to do this.
      {
        GuardType guard(this->lock_);
        request->mark_as_ready();
        this->work_available_.signal();
      }

      // Note that the request will be "released" here when the request
      // handle falls out of scope and its destructor performs the
      // _remove_ref() call on the underlying TP_Request object.
    }

  // This will never get executed.
  return 0;
}


int
TAO::CSD::TP_Task::close(u_long flag)
{
  GuardType guard(this->lock_);

  if (flag == 0)
    {
      // Worker thread is closing.
      --this->num_threads_;
      this->active_workers_.signal();
    }
  else
    {
      // Strategy object is shutting down the task.

      // Do nothing if this task has never been open()'ed.
      if (!this->opened_)
        {
          return 0;
        }

      // Set the shutdown flag to true.
      this->shutdown_initiated_ = true;

      // Stop accepting requests.
      this->accepting_requests_ = false;

      // Signal all worker threads waiting on the work_available_ condition.
      this->work_available_.broadcast();

      size_t num_waiting_threads = 0;

      ACE_thread_t my_thr_id = ACE_OS::thr_self ();

      // Check whether the calling thread(calling orb shutdown) is one of the 
      // threads in the pool. If it is then it should not wait itself.
      size_t size = this->activated_threads_.size ();
      
      for (size_t i = 0; i < size; i ++)
        {
          ACE_thread_t thr_id = 0;
          if (activated_threads_.get (thr_id, i) == 0 && thr_id == my_thr_id)
            {
              num_waiting_threads = 1;
              break;
            }
        }

      // Wait until all worker threads have shutdown.
      while (this->num_threads_ != num_waiting_threads)
        {
          this->active_workers_.wait();
        }

      // Cancel all requests.
      TP_Cancel_Visitor cancel_visitor;
      this->queue_.accept_visitor(cancel_visitor);
    }

  return 0;
}



void
TAO::CSD::TP_Task::cancel_servant (PortableServer::Servant servant
                                   ACE_ENV_ARG_DECL)
{
  GuardType guard(this->lock_);

  // Cancel the requests targeted for the provided servant.
  TP_Cancel_Visitor cancel_visitor(servant);
  this->queue_.accept_visitor(cancel_visitor);
}

