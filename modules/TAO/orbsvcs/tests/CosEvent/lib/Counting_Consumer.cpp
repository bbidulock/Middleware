// $Id$

#include "Counting_Consumer.h"
#include "ace/OS_NS_unistd.h"

ACE_RCSID(CEC_Tests, CEC_Count_Consumer, "$Id$")

CEC_Counting_Consumer::CEC_Counting_Consumer (const char* name)
  : event_count (0),
    disconnect_count (0),
    name_ (name)
{
}

void
CEC_Counting_Consumer::connect (CosEventChannelAdmin::ConsumerAdmin_ptr consumer_admin
                   ACE_ENV_ARG_DECL)
{
  // The canonical protocol to connect to the EC

  CosEventComm::PushConsumer_var consumer =
    this->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  if (CORBA::is_nil (this->supplier_proxy_.in ()))
    {
      this->supplier_proxy_ =
        consumer_admin->obtain_push_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }

  this->supplier_proxy_->connect_push_consumer (consumer.in ()
                                                ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
CEC_Counting_Consumer::disconnect (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->supplier_proxy_.in ()))
    {
      this->supplier_proxy_->disconnect_push_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }

  PortableServer::POA_var consumer_poa =
    this->_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  PortableServer::ObjectId_var consumer_id =
    consumer_poa->servant_to_id (this ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  consumer_poa->deactivate_object (consumer_id.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->supplier_proxy_ =
    CosEventChannelAdmin::ProxyPushSupplier::_nil ();
}

void
CEC_Counting_Consumer::dump_results (int expected_count, int tolerance)
{
  int diff = this->event_count - expected_count;
  if (diff > tolerance || diff < -tolerance)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "ERROR - %s unexpected number of events  <%d>\n",
                  this->name_,
                  this->event_count));
    }
  else
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s - number of events <%d> within margins\n",
                  this->name_,
                  this->event_count));
    }
}

void
CEC_Counting_Consumer::push (const CORBA::Any&
                             ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->event_count ++;
#if 0
  if (this->event_count % 10 == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s (%P|%t): %d events received\n",
                  this->name_,
                  this->event_count));
    }
#endif /* 0 */
}

void
CEC_Counting_Consumer::disconnect_push_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->disconnect_count++;
  this->supplier_proxy_ =
    CosEventChannelAdmin::ProxyPushSupplier::_nil ();
}

// ****************************************************************

CEC_Pull_Counting_Consumer::CEC_Pull_Counting_Consumer (const char* name)
  : event_count (0),
    disconnect_count (0),
    name_ (name)
{
}

void
CEC_Pull_Counting_Consumer::connect (CosEventChannelAdmin::ConsumerAdmin_ptr consumer_admin
                                     ACE_ENV_ARG_DECL)
{
  // The canonical protocol to connect to the EC

  CosEventComm::PullConsumer_var consumer =
    this->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  if (CORBA::is_nil (this->supplier_proxy_.in ()))
    {
      this->supplier_proxy_ =
        consumer_admin->obtain_pull_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }

  this->supplier_proxy_->connect_pull_consumer (consumer.in ()
                                                ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
CEC_Pull_Counting_Consumer::disconnect (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->supplier_proxy_.in ()))
    {
      this->supplier_proxy_->disconnect_pull_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }

  PortableServer::POA_var consumer_poa =
    this->_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  PortableServer::ObjectId_var consumer_id =
    consumer_poa->servant_to_id (this ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  consumer_poa->deactivate_object (consumer_id.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->supplier_proxy_ =
    CosEventChannelAdmin::ProxyPullSupplier::_nil ();
}

CORBA::Any*
CEC_Pull_Counting_Consumer::pull (ACE_ENV_SINGLE_ARG_DECL)
{
  if (CORBA::is_nil (this->supplier_proxy_.in ()))
    {
      return 0;
    }
  this->event_count++;
  return this->supplier_proxy_->pull (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::Any*
CEC_Pull_Counting_Consumer::try_pull (CORBA::Boolean_out has_event
                                      ACE_ENV_ARG_DECL)
{
  if (CORBA::is_nil (this->supplier_proxy_.in ()))
    {
      has_event = 0;
      return 0;
    }

  CORBA::Any_var event =
    this->supplier_proxy_->try_pull (has_event ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (has_event)
    this->event_count++;

  return event._retn ();
}

void
CEC_Pull_Counting_Consumer::dump_results (int expected_count, int tolerance)
{
  int diff = this->event_count - expected_count;
  if (diff > tolerance || diff < -tolerance)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "ERROR - %s unexpected number of events  <%d>\n",
                  this->name_,
                  this->event_count));
    }
  else
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s - number of events <%d> within margins\n",
                  this->name_,
                  this->event_count));
    }
}

void
CEC_Pull_Counting_Consumer::disconnect_pull_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->disconnect_count++;
  this->supplier_proxy_ =
    CosEventChannelAdmin::ProxyPullSupplier::_nil ();
}

// ****************************************************************

CEC_Counting_Consumer_Task::
    CEC_Counting_Consumer_Task (CEC_Pull_Counting_Consumer *s,
                                int milliseconds)
  :  consumer_ (s),
     stop_flag_ (0),
     pull_count_ (0),
     milliseconds_ (milliseconds)
{
}

int
CEC_Counting_Consumer_Task::svc ()
{
  ACE_TRY_NEW_ENV
    {
      this->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return -1;
    }
  ACE_ENDTRY;
  return 0;
}

void
CEC_Counting_Consumer_Task::stop (void)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);
  this->stop_flag_ = 1;
}

CORBA::ULong
CEC_Counting_Consumer_Task::pull_count (void)
{
  return this->pull_count_;
}

void
CEC_Counting_Consumer_Task::run (ACE_ENV_SINGLE_ARG_DECL)
{
  CORBA::Any event;
  event <<= CORBA::Long(0);

  int stop = 0;
  do {
    CORBA::Boolean has_event;
    CORBA::Any_var event =
      this->consumer_->try_pull (has_event
                                 ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    if (this->milliseconds_ != 0)
      {
        ACE_Time_Value tv (0, 1000 * this->milliseconds_);
        ACE_OS::sleep (tv);
      }
    else
      {
        // Sleep for a short time to avoid spinning... kind of klugy
        ACE_OS::sleep (0);
      }

    if (has_event)
      {
        ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);
        this->pull_count_++;
      }

    stop = this->stop_flag_;
  } while (stop == 0);
}
