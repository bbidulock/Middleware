// $Id$

ACE_INLINE ACE_Lock &
TAO_POA_Manager::lock (void)
{
  return *this->lock_;
}

ACE_INLINE void
TAO_POA_Manager::activate (CORBA_Environment &ACE_TRY_ENV)
{
  // Lock access to the POAManager for the duration of this transaction
  TAO_POA_WRITE_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->activate_i (ACE_TRY_ENV);
}

#if !defined (TAO_HAS_MINIMUM_CORBA)

ACE_INLINE void
TAO_POA_Manager::hold_requests (CORBA::Boolean wait_for_completion,
                                CORBA_Environment &ACE_TRY_ENV)
{
  // Lock access to the POAManager for the duration of this transaction
  TAO_POA_WRITE_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->hold_requests_i (wait_for_completion, ACE_TRY_ENV);
}

ACE_INLINE void
TAO_POA_Manager::discard_requests (CORBA::Boolean wait_for_completion,
                                   CORBA_Environment &ACE_TRY_ENV)
{
  // Lock access to the POAManager for the duration of this transaction
  TAO_POA_WRITE_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->discard_requests_i (wait_for_completion, ACE_TRY_ENV);
}

ACE_INLINE void
TAO_POA_Manager::deactivate (CORBA::Boolean etherealize_objects,
                             CORBA::Boolean wait_for_completion,
                             CORBA_Environment &ACE_TRY_ENV)
{
  // Lock access to the POAManager for the duration of this transaction
  TAO_POA_WRITE_GUARD (ACE_Lock, monitor, this->lock (), ACE_TRY_ENV);

  this->deactivate_i (etherealize_objects,
                      wait_for_completion,
                      ACE_TRY_ENV);
}

#endif /* TAO_HAS_MINIMUM_CORBA */

ACE_INLINE TAO_POA_Manager *
TAO_POA_Manager::clone (void)
{
  return new TAO_POA_Manager;
}

ACE_INLINE void
TAO_POA_Manager::destroy (void)
{
  delete this;
}
