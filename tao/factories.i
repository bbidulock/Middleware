ACE_INLINE
TAO_Client_Connection_Handler::TAO_Client_Connection_Handler (ACE_Thread_Manager *)
  : in_use_ (0)
{
}

ACE_INLINE CORBA::Boolean
TAO_Client_Connection_Handler::in_use (void)
{
  return in_use_;
}

ACE_INLINE void
TAO_Client_Connection_Handler::in_use (CORBA::Boolean flag)
{
  in_use_ = flag;
}

ACE_INLINE TAO_Server_Factory::CREATION_STRATEGY *
TAO_Server_Factory::creation_strategy (void)
{
  return 0;
}

ACE_INLINE TAO_Server_Factory::ACCEPT_STRATEGY *
TAO_Server_Factory::accept_strategy (void)
{
  return 0;
}

ACE_INLINE TAO_Server_Factory::SCHEDULING_STRATEGY *
TAO_Server_Factory::scheduling_strategy (void)
{
  return 0;
}

#if defined (TAO_HAS_CLIENT_CONCURRENCY)
ACE_INLINE TAO_Client_Factory::CONCURRENCY_STRATEGY *
TAO_Client_Factory::concurrency_strategy (void)
{
  return 0;
}
#endif /* TAO_HAS_CLIENT_CONCURRENCY */

ACE_INLINE
TAO_Server_Factory::TAO_Server_Factory (void)
  : concurrency_strategy_ (0)
{
}

ACE_INLINE TAO_Client_Factory::CONNECTOR*
TAO_Client_Factory::connector(void)
{
  return &connector_;
}
