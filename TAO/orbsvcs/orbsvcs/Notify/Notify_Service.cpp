// $Id$

#include "Notify_Service.h"

#include "ace/Sched_Params.h"
#include "ace/Arg_Shifter.h"
#include "tao/ORB_Core.h"
#include "Builder.h"
#include "Properties.h"
#include "Factory.h"

ACE_RCSID(RT_Notify, TAO_NS_Notify_Service, "$Id$")

TAO_NS_Notify_Service::TAO_NS_Notify_Service (void)
:factory_ (0), builder_ (0)
{
}

TAO_NS_Notify_Service::~TAO_NS_Notify_Service ()
{
  delete factory_;
  delete builder_;
}

int
TAO_NS_Notify_Service::init (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);

  const ACE_TCHAR *current_arg = 0;

  while (arg_shifter.is_anything_left ())
    {
      if (arg_shifter.cur_arg_strncasecmp ("-Updates") == 0) // -AsynchUpdates update_period_uS
        {
          arg_shifter.consume_arg ();

          current_arg = arg_shifter.get_current ();

          if (current_arg != 0)
            {
              ACE_Time_Value update_period (0, ACE_OS::atoi (current_arg));


              TAO_NS_PROPERTIES::instance()->updates (1);
              TAO_NS_PROPERTIES::instance()->update_period (update_period);
            }
        }
      else if (arg_shifter.cur_arg_strncasecmp ("-NoUpdates") == 0) // No Updates to begin with.
        {
          arg_shifter.consume_arg ();

          TAO_NS_PROPERTIES::instance()->updates (0);
        }
    }

  return 0;
}

int
TAO_NS_Notify_Service::fini (void)
{
  return 0;
}

void
TAO_NS_Notify_Service::init (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL)
{
  ACE_DEBUG ((LM_DEBUG, "Loading the Cos Notification Service...\n"));

  this->init_i (orb ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_NS_Notify_Service::init_i (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL)
{
  /// first, init the main thread.
  //this->init_main_thread (orb ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Obtain the Root POA
  CORBA::Object_var object  =
    orb->resolve_initial_references("RootPOA"
                                           ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (CORBA::is_nil (object.in ()))
    ACE_ERROR ((LM_ERROR,
                       " (%P|%t) Unable to resolve the RootPOA.\n"));

  PortableServer::POA_var default_poa = PortableServer::POA::_narrow (object.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  /// Set the properties
  TAO_NS_Properties* properties = TAO_NS_PROPERTIES::instance();

  properties->default_poa (default_poa.in ());
  properties->sched_policy (orb->orb_core ()->orb_params ()->sched_policy ());
  properties->scope_policy (orb->orb_core ()->orb_params ()->scope_policy ());


  // Init the factory and builder

  this->init_factory (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->init_builder (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_NS_Notify_Service::init_main_thread (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL)
{
  ACE_Sched_Params::Policy sched_policy;
  long thr_sched_policy = orb->orb_core ()->orb_params ()->sched_policy ();

  long thr_scope_policy = orb->orb_core ()->orb_params ()->scope_policy ();

  if (thr_sched_policy == THR_SCHED_FIFO)
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG, "Sched policy = THR_SCHED_FIFO\n"));

      sched_policy = ACE_SCHED_FIFO;
    }
  else if (thr_sched_policy == THR_SCHED_RR)
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG, "Sched policy = THR_SCHED_RR\n"));

      sched_policy = ACE_SCHED_RR;
    }
  else
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG, "Sched policy = THR_SCHED_OTHER\n"));

      sched_policy = ACE_SCHED_OTHER;
    }

  /// Check sched.
  int min_priority = ACE_Sched_Params::priority_min (sched_policy);
  int max_priority = ACE_Sched_Params::priority_max (sched_policy);

   if (TAO_debug_level > 0)
    {
      ACE_DEBUG ((LM_DEBUG, "max_priority = %d, min_priority = %d\n",
                  max_priority, min_priority));

      if (max_priority == min_priority)
        {
          ACE_DEBUG ((LM_DEBUG,"Detected max_priority == min_priority\n"));
        }
    }

  // Set the main thread to min priority...
    int priority = min_priority;

    if (ACE_OS::sched_params (ACE_Sched_Params (sched_policy ,
                                                priority,
                                                ACE_SCOPE_PROCESS)) != 0)
      {
        if (ACE_OS::last_error () == EPERM)
          {
            ACE_DEBUG ((LM_DEBUG,
                        "(%P|%t): user is not superuser, "
                        "test runs in time-shared class\n"));
          }
        else
          ACE_ERROR ((LM_ERROR,
                      "(%P|%t): sched_params failed\n"));
      }
}

void
TAO_NS_Notify_Service::init_factory (ACE_ENV_SINGLE_ARG_DECL)
{
  ACE_NEW_THROW_EX (this->factory_,
                    TAO_NS_Factory (),
                    CORBA::NO_MEMORY ());
  ACE_CHECK;

  TAO_NS_PROPERTIES::instance()->factory (this->factory_);
}

void
TAO_NS_Notify_Service::init_builder (ACE_ENV_SINGLE_ARG_DECL)
{
  ACE_NEW_THROW_EX (this->builder_,
                    TAO_NS_Builder (),
                    CORBA::NO_MEMORY ());
  ACE_CHECK;

  TAO_NS_PROPERTIES::instance()->builder (this->builder_);
}

CosNotifyChannelAdmin::EventChannelFactory_ptr
TAO_NS_Notify_Service::create (PortableServer::POA_ptr poa ACE_ENV_ARG_DECL)
{
  return this->builder_->build_event_channel_factory (poa ACE_ENV_ARG_PARAMETER);
}

ACE_FACTORY_DEFINE (TAO_Notify, TAO_NS_Notify_Service)
