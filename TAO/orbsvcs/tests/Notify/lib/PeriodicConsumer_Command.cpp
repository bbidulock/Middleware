// $Id$

#include "PeriodicConsumer_Command.h"

#if ! defined (__ACE_INLINE__)
#include "PeriodicConsumer_Command.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(lib, TAO_PeriodicConsumer_Command, "$id$")

#include "LookupManager.h"
#include "Name.h"
#include "Periodic_Consumer.h"
#include "Activation_Manager.h"
#include "Options_Parser.h"

TAO_NS_PeriodicConsumer_Command::TAO_NS_PeriodicConsumer_Command (void)
  :command_ (DUMP_STATE), poa_ (TAO_NS_Name.root_poa), ifgop_ (CosNotifyChannelAdmin::OR_OP), id_ (0)
{
}

TAO_NS_PeriodicConsumer_Command::~TAO_NS_PeriodicConsumer_Command ()
{
}

const char*
TAO_NS_PeriodicConsumer_Command::get_name (void)
{
  return TAO_NS_PeriodicConsumer_Command::name ();
}

const char*
TAO_NS_PeriodicConsumer_Command::name (void)
{
  return TAO_NS_Name.periodic_consumer_command;
}

void
TAO_NS_PeriodicConsumer_Command::init (ACE_Arg_Shifter& arg_shifter)
{
  const ACE_TCHAR* current_arg = 0;

  if (arg_shifter.is_anything_left ())
    {
      /// -Create consumer_name admin_name -POA [POA_name] consumer_specific_options
      if (arg_shifter.cur_arg_strncasecmp ("-Create") == 0)
        {
          this->command_ = CREATE;

          arg_shifter.consume_arg ();

          this->name_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();

          this->admin_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();

          // Is a POA name specified?
         if (arg_shifter.cur_arg_strncasecmp ("-POA") == 0)
           {
             arg_shifter.consume_arg ();

             this->poa_ = arg_shifter.get_current ();
             arg_shifter.consume_arg ();
           }

         // create the consumer
         TAO_NS_Periodic_Consumer* consumer = new TAO_NS_Periodic_Consumer ();

         TAO_NS_Activation_Manager* act_mgr = 0;
         LOOKUP_MANAGER->resolve (act_mgr);

         act_mgr->_register (consumer, this->name_.c_str () ACE_ENV_ARG_PARAMETER);
         ACE_CHECK;

         consumer->init_state (arg_shifter);
         consumer->TAO_NS_StructuredPushConsumer::name (this->name_);

        } /* -Create */
      else if (arg_shifter.cur_arg_strncasecmp ("-Subscription") == 0) // -Subscription admin_name +added_type1 +-added_type2 ... -added_type3 -added_type4..
        {
          this->command_ = SUBSCRIPTION;

          arg_shifter.consume_arg ();

          this->name_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();

          TAO_NS_Options_Parser options_parser;
          options_parser.execute (this->added_, this->removed_, arg_shifter);
        } /* Subscription */
      else if (arg_shifter.cur_arg_strncasecmp ("-Disconnect") == 0) //
        {
          this->command_ = DISCONNECT;

          arg_shifter.consume_arg ();

          this->name_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();
        } /* disconnect */
      else if (arg_shifter.cur_arg_strncasecmp ("-Deactivate") == 0) //
        {
          this->command_ = DEACTIVATE;

          arg_shifter.consume_arg ();

          this->name_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();
        } /* deactivate */
      else if (arg_shifter.cur_arg_strncasecmp ("-Status") == 0) //
        {
          this->command_ = DUMP_STATE;

          arg_shifter.consume_arg ();

          this->name_ = arg_shifter.get_current ();
          arg_shifter.consume_arg ();
        } /* -Dump */
    }
}

TAO_NS_Periodic_Consumer*
TAO_NS_PeriodicConsumer_Command::consumer (void)
{
  TAO_NS_Activation_Manager* act_mgr = 0;
  LOOKUP_MANAGER->resolve (act_mgr);

  // Locate the consumer
  TAO_NS_Periodic_Consumer* consumer = 0;

  act_mgr->resolve (consumer, this->name_.c_str ());

  if (consumer == 0)
    ACE_DEBUG ((LM_DEBUG, "Consumer %s not found by Lookup Manager\n", this->name_.c_str ()));

  return consumer;
}

void
TAO_NS_PeriodicConsumer_Command::handle_create (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_NS_Periodic_Consumer* consumer = this->consumer ();
  if (consumer == 0)
    return;

  // Get the POA
  PortableServer::POA_var poa;
  LOOKUP_MANAGER->resolve (poa, this->poa_.c_str () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // set the POA
  consumer->TAO_NS_StructuredPushConsumer::init (poa.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Resolve the consumer admin
  CosNotifyChannelAdmin::ConsumerAdmin_var consumer_admin;

  LOOKUP_MANAGER->resolve (consumer_admin, this->admin_.c_str () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // create the proxy supplier
  CosNotifyChannelAdmin::ProxySupplier_var proxy_supplier =
    consumer_admin->obtain_notification_push_supplier (CosNotifyChannelAdmin::STRUCTURED_EVENT, this->id_ ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (proxy_supplier.in ()));

  CosNotifyChannelAdmin::StructuredProxyPushSupplier_var s_proxy_supplier =
    CosNotifyChannelAdmin::StructuredProxyPushSupplier::_narrow (proxy_supplier.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (s_proxy_supplier.in ()));

  // connect consumer to proxy, also activates the consumer as CORBA object in the POA specified.
  consumer->connect (s_proxy_supplier.in (),this->id_ ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Register the proxy supplier.
  LOOKUP_MANAGER->_register (s_proxy_supplier.in (), consumer->proxy_name () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_DEBUG ((LM_DEBUG, "Consumer %s is connected\n", this->name_.c_str ()));
}

void
TAO_NS_PeriodicConsumer_Command::handle_subscriptions (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_NS_Periodic_Consumer* consumer= this->consumer ();
  if (consumer == 0)
    return;

  consumer->subscription_change (this->added_, this->removed_ ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_NS_PeriodicConsumer_Command::handle_disconnect (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_NS_Periodic_Consumer* consumer= this->consumer ();
  if (consumer == 0)
    return;

  consumer->disconnect (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_NS_PeriodicConsumer_Command::handle_deactivate (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_NS_Periodic_Consumer* consumer = this->consumer ();
  if (consumer == 0)
    return;

  consumer->deactivate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_NS_PeriodicConsumer_Command::handle_status (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_NS_Periodic_Consumer* consumer = this->consumer ();

  if (consumer == 0)
    return;

  ACE_TRY
    {
      CORBA::Boolean not_exist = consumer->get_proxy_supplier ()->_non_existent (ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (not_exist == 1)
        {
          ACE_DEBUG ((LM_DEBUG, "Consumer %s, Proxy does not exist\n",this->name_.c_str ()));
        }
      else
        {
          ACE_DEBUG ((LM_DEBUG, "Consumer %s, Proxy exists\n",this->name_.c_str ()));
        }
    }
  ACE_CATCH(CORBA::TRANSIENT, ex)
    {
      ACE_PRINT_EXCEPTION (ex, "");
      ACE_DEBUG ((LM_DEBUG, "Consumer %s is_equivanent transient exception.", this->name_.c_str ()));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "");
      ACE_DEBUG ((LM_DEBUG, "Consumeris_equivanent other exception.", this->name_.c_str ()));
    }
  ACE_ENDTRY;
}

void
TAO_NS_PeriodicConsumer_Command::execute_i (ACE_ENV_SINGLE_ARG_DECL)
{
  if (this->command_ == CREATE)
    {
      this->handle_create (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
  else if (this->command_ == SUBSCRIPTION)
    {
      this->handle_subscriptions (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
  else if (this->command_ == DISCONNECT)
    {
      this->handle_disconnect (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
  else if (this->command_ == DEACTIVATE)
    {
      this->handle_deactivate (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
  else  if (this->command_ == DUMP_STATE)
    {
      this->handle_status (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
}
