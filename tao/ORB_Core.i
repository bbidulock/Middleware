// -*- C++ -*-

// $Id$

ACE_INLINE CORBA::ULong
TAO_ORB_Core::_incr_refcnt (void)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->lock_, 0);
  return this->refcount_++;
}

ACE_INLINE CORBA::ULong
TAO_ORB_Core::_decr_refcnt (void)
{
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->lock_, 0);
    this->refcount_--;
    if (this->refcount_ != 0)
      return this->refcount_;
  }

  this->fini ();
  return 0;
}

ACE_INLINE int
TAO_ORB_Core::register_handle (ACE_HANDLE handle)
{
  if (handle == ACE_INVALID_HANDLE)
    {
      errno = EINVAL;
      return -1;
    }

  // Acquire a lock to ensure that modifications to the state within
  // the handle set are atomic.
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->lock_, -1));
  this->handle_set_.set_bit (handle);

  return 0;
}

ACE_INLINE int
TAO_ORB_Core::remove_handle (ACE_HANDLE handle)
{
  if (handle == ACE_INVALID_HANDLE)
    {
      errno = EINVAL;
      return -1;
    }

  // Acquire a lock to ensure that modifications to the state within
  // the handle set are atomic.
  ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->lock_, -1));
  this->handle_set_.clr_bit (handle);

  return 0;
}


ACE_INLINE CORBA::Boolean
TAO_ORB_Core::service_profile_selection (TAO_MProfile &mprofile,
                                         TAO_Profile  *&profile)
{
  CORBA::Boolean retval = 0;
  // @@ If different services have the same feature we may want to
  // prioritise them here. We need to decide here whose selection of
  // profile is more important.
  if (this->ft_service_callbacks_ != 0)
    {
      cout << "ORB_Core.i "<<endl;
      retval =
        this->ft_service_callbacks_->select_profile (&mprofile,
                                                     profile);
    }
  return retval;
}

ACE_INLINE CORBA::Boolean
TAO_ORB_Core::service_profile_reselection (TAO_Stub *stub,
                                           TAO_Profile *&profile)
{
  CORBA::Boolean retval = 0;
  // @@ If different services have the same feature we may want to
  // prioritise them here. We need to decide here whose selection of
  // profile is more important.
  if (this->ft_service_callbacks_ != 0)
    {
      retval =
        this->ft_service_callbacks_->reselect_profile (stub,
                                                       profile);
    }
  return retval;
}

ACE_INLINE void
TAO_ORB_Core::reset_service_profile_flags (void)
{
  // @@ If different services have the same feature we may want to
  // prioritise them here. We need to decide here whose selection of
  // profile is more important.

  if (this->ft_service_callbacks_ != 0)
    {
      this->ft_service_callbacks_->reset_profile_flags ();
    }
  return;
}


ACE_INLINE CORBA::Boolean
TAO_ORB_Core::object_is_nil (CORBA::Object_ptr obj)
{
  CORBA::Boolean retval = 0;
  if (this->ft_service_callbacks_ != 0)
    {
      retval =
        this->ft_service_callbacks_->object_is_nil (obj);
    }
  return retval;
}

ACE_INLINE ACE_Thread_Manager *
TAO_ORB_Core::thr_mgr (void)
{
  return &this->tm_;
}

ACE_INLINE CORBA::ORB_ptr
TAO_ORB_Core::orb (void)
{
  return this->orb_.in ();
}

ACE_INLINE TAO_Adapter_Registry *
TAO_ORB_Core::adapter_registry (void)
{
  return &this->adapter_registry_;
}

ACE_INLINE void
TAO_ORB_Core::optimize_collocation_objects (CORBA::Boolean opt)
{
  this->opt_for_collocation_ = opt;
}

ACE_INLINE CORBA::Boolean
TAO_ORB_Core::optimize_collocation_objects (void) const
{
  return this->opt_for_collocation_;
}

ACE_INLINE void
TAO_ORB_Core::use_global_collocation (CORBA::Boolean opt)
{
  this->use_global_collocation_ = opt;
}

ACE_INLINE CORBA::Boolean
TAO_ORB_Core::use_global_collocation (void) const
{
  return this->use_global_collocation_;
}

ACE_INLINE CORBA::ULong
TAO_ORB_Core::get_collocation_strategy (void) const
{
  return this->collocation_strategy_;
}

ACE_INLINE TAO_ORB_Parameters *
TAO_ORB_Core::orb_params(void)
{
  return &(this->orb_params_);
}

#define TAO_OC_RETRIEVE(member) \
  ((this->member##_ == 0) ? (this->member##_ = this->resource_factory ()->get_##member ()) : (this->member##_) )

ACE_INLINE TAO_ProtocolFactorySet *
TAO_ORB_Core::protocol_factories (void)
{
  return TAO_OC_RETRIEVE (protocol_factories);
}

ACE_INLINE TAO_Connector_Registry *
TAO_ORB_Core::connector_registry (void)
{
  return TAO_OC_RETRIEVE (connector_registry);
}

ACE_INLINE TAO_Acceptor_Registry *
TAO_ORB_Core::acceptor_registry (void)
{
  return TAO_OC_RETRIEVE (acceptor_registry);
}

ACE_INLINE TAO_Parser_Registry *
TAO_ORB_Core::parser_registry (void)
{
  return &this->parser_registry_;
}

#undef TAO_OC_RETRIEVE

ACE_INLINE ACE_Char_Codeset_Translator *
TAO_ORB_Core::from_iso8859 (void) const
{
  return this->from_iso8859_;
}

ACE_INLINE ACE_Char_Codeset_Translator *
TAO_ORB_Core::to_iso8859 (void) const
{
  return this->to_iso8859_;
}

ACE_INLINE ACE_WChar_Codeset_Translator *
TAO_ORB_Core::from_unicode (void) const
{
  return this->from_unicode_;
}

ACE_INLINE ACE_WChar_Codeset_Translator *
TAO_ORB_Core::to_unicode (void) const
{
  return this->to_unicode_;
}

#if (TAO_HAS_CORBA_MESSAGING == 1)

ACE_INLINE TAO_Policy_Manager *
TAO_ORB_Core::policy_manager (void)
{
  return this->policy_manager_;
}

ACE_INLINE CORBA::Policy_ptr
TAO_ORB_Core::get_default_policy (
      CORBA::PolicyType policy,
      CORBA::Environment &ACE_TRY_ENV)
{
  return this->default_policies_->get_policy (policy, ACE_TRY_ENV);
}

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

#if (TAO_HAS_RELATIVE_ROUNDTRIP_TIMEOUT_POLICY == 1)

ACE_INLINE TAO_RelativeRoundtripTimeoutPolicy *
TAO_ORB_Core::default_relative_roundtrip_timeout (void) const
{
  return this->default_policies_->relative_roundtrip_timeout ();
}

#endif /* TAO_HAS_RELATIVE_ROUNDTRIP_TIMEOUT_POLICY == 1 */

#if (TAO_HAS_CLIENT_PRIORITY_POLICY == 1)

ACE_INLINE TAO_Client_Priority_Policy *
TAO_ORB_Core::default_client_priority (void) const
{
  return this->default_policies_->client_priority ();
}

#endif /* TAO_HAS_CLIENT_PRIORITY_POLICY == 1 */

#if (TAO_HAS_SYNC_SCOPE_POLICY == 1)

ACE_INLINE TAO_Sync_Scope_Policy *
TAO_ORB_Core::default_sync_scope (void) const
{
  return this->default_policies_->sync_scope ();
}

#endif /* TAO_HAS_SYNC_SCOPE_POLICY == 1 */

#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

ACE_INLINE TAO_Buffering_Constraint_Policy *
TAO_ORB_Core::default_buffering_constraint (void) const
{
  return this->default_policies_->buffering_constraint ();
}

#endif /* TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1 */

#if (TAO_HAS_RT_CORBA == 1)

ACE_INLINE TAO_ThreadpoolPolicy *
TAO_ORB_Core::default_threadpool (void) const
{
  return this->default_policies_->threadpool ();
}

ACE_INLINE TAO_PriorityModelPolicy *
TAO_ORB_Core::default_priority_model (void) const
{
  return this->default_policies_->priority_model ();
}

ACE_INLINE TAO_ServerProtocolPolicy *
TAO_ORB_Core::default_server_protocol (void) const
{
  return this->default_policies_->server_protocol ();
}

ACE_INLINE TAO_ClientProtocolPolicy *
TAO_ORB_Core::default_client_protocol (void) const
{
  return this->default_policies_->client_protocol ();
}

ACE_INLINE TAO_PrivateConnectionPolicy *
TAO_ORB_Core::default_private_connection (void) const
{
  return this->default_policies_->private_connection ();
}

ACE_INLINE TAO_PriorityBandedConnectionPolicy *
TAO_ORB_Core::default_priority_banded_connection (void) const
{
  return this->default_policies_->priority_banded_connection ();
}

#endif /* TAO_HAS_RT_CORBA == 1 */

ACE_INLINE TAO_ORB_Core_TSS_Resources*
TAO_ORB_Core::get_tss_resources (void)
{
  return ACE_TSS_GET (&this->tss_resources_,TAO_ORB_Core_TSS_Resources);
}

ACE_INLINE int
TAO_ORB_Core::has_shutdown (void)
{
  return this->has_shutdown_;
}

ACE_INLINE void
TAO_ORB_Core::check_shutdown (CORBA_Environment &ACE_TRY_ENV)
{
  if (this->has_shutdown ())
    {
      // As defined by the CORBA 2.3 specification, throw a
      // CORBA::BAD_INV_ORDER exception with minor code 4 if the ORB
      // has shutdown by the time an ORB function is called.

      ACE_THROW (CORBA::BAD_INV_ORDER (4, CORBA::COMPLETED_NO));
    }
}


ACE_INLINE int
TAO_ORB_Core::thread_per_connection_timeout (ACE_Time_Value &timeout) const
{
  timeout = this->thread_per_connection_timeout_;
  return this->thread_per_connection_use_timeout_;
}

ACE_INLINE const char *
TAO_ORB_Core::orbid (void) const
{
  return this->orbid_;
}

ACE_INLINE void
TAO_ORB_Core::implrepo_service (const CORBA::Object_ptr ir)
{
  this->implrepo_service_ = ir;
}

ACE_INLINE CORBA::Object_ptr
TAO_ORB_Core::resolve_typecodefactory (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->lock_,
                    CORBA::Object::_nil ());
  if (CORBA::is_nil (this->typecode_factory_))
    {
      this->resolve_typecodefactory_i (ACE_TRY_ENV);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());
    }
  return CORBA::Object::_duplicate (this->typecode_factory_);
}

/*ACE_INLINE void
TAO_ORB_Core::typecode_factory (const CORBA::Object_ptr tf)
{
  this->typecode_factory_ = tf;
}
*/

ACE_INLINE CORBA::Object_ptr
TAO_ORB_Core::resolve_dynanyfactory (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->lock_,
                    CORBA::Object::_nil ());
  if (CORBA::is_nil (this->dynany_factory_))
    {
      this->resolve_dynanyfactory_i (ACE_TRY_ENV);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());
    }
  return CORBA::Object::_duplicate (this->dynany_factory_);
}

ACE_INLINE CORBA::Object_ptr
TAO_ORB_Core::resolve_ior_manipulation (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->lock_,
                    CORBA::Object::_nil ());
  if (CORBA::is_nil (this->ior_manip_factory_))
    {
      this->resolve_iormanipulation_i (ACE_TRY_ENV);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());
    }
  return CORBA::Object::_duplicate (this->ior_manip_factory_);
}

ACE_INLINE CORBA::Object_ptr
TAO_ORB_Core::resolve_ior_table (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->lock_,
                    CORBA::Object::_nil ());
  if (CORBA::is_nil (this->ior_table_))
    {
      this->resolve_ior_table_i (ACE_TRY_ENV);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());
    }
  return CORBA::Object::_duplicate (this->ior_table_);
}

// ****************************************************************

#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

ACE_INLINE TAO_Eager_Buffering_Sync_Strategy &
TAO_ORB_Core::eager_buffering_sync_strategy (void)
{
  return *this->eager_buffering_sync_strategy_;
}

ACE_INLINE TAO_Delayed_Buffering_Sync_Strategy &
TAO_ORB_Core::delayed_buffering_sync_strategy (void)
{
  return *this->delayed_buffering_sync_strategy_;
}

#endif /* TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1 */

ACE_INLINE TAO_Transport_Sync_Strategy &
TAO_ORB_Core::transport_sync_strategy (void)
{
  return *this->transport_sync_strategy_;
}

#if (TAO_HAS_CORBA_MESSAGING == 1)

ACE_INLINE TAO_Policy_Current &
TAO_ORB_Core::policy_current (void)
{
  return *this->policy_current_;
}

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

ACE_INLINE CORBA::Object_ptr
TAO_ORB_Core::poa_current (void)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->lock_, 0);
  return CORBA::Object::_duplicate (this->poa_current_.in ());
}

ACE_INLINE void
TAO_ORB_Core::poa_current (CORBA::Object_ptr current)
{
  ACE_GUARD (ACE_SYNCH_MUTEX, mon, this->lock_);
  this->poa_current_ =
    CORBA::Object::_duplicate (current);
}

ACE_INLINE CORBA_Environment *
TAO_ORB_Core::default_environment (void) const
{
  return TAO_TSS_RESOURCES::instance ()->default_environment_;
}

ACE_INLINE void
TAO_ORB_Core::default_environment (CORBA_Environment *env)
{
  TAO_TSS_RESOURCES::instance ()->default_environment_ = env;
}


#if (TAO_HAS_RT_CORBA == 1)

ACE_INLINE TAO_Priority_Mapping_Manager *
TAO_ORB_Core::priority_mapping_manager (void)
{
  return this->priority_mapping_manager_;
}

ACE_INLINE TAO_RT_ORB *
TAO_ORB_Core::rt_orb (void)
{
  return this->rt_orb_;
}

ACE_INLINE TAO_RT_Current *
TAO_ORB_Core::rt_current (void)
{
  return this->rt_current_;
}

#endif /* TAO_HAS_RT_CORBA == 1 */

// ****************************************************************

ACE_INLINE
TAO_ORB_Core_Auto_Ptr::TAO_ORB_Core_Auto_Ptr (TAO_ORB_Core *p)
  : p_ (p)
{
  ACE_TRACE ("TAO_ORB_Core_Auto_Ptr::TAO_ORB_Core_Auto_Ptr");
}

ACE_INLINE TAO_ORB_Core *
TAO_ORB_Core_Auto_Ptr::get (void) const
{
  ACE_TRACE ("TAO_ORB_Core_Auto_Ptr::get");
  return this->p_;
}

ACE_INLINE TAO_ORB_Core *
TAO_ORB_Core_Auto_Ptr::release (void)
{
  ACE_TRACE ("TAO_ORB_Core_Auto_Ptr::release");
  TAO_ORB_Core *old = this->p_;
  this->p_ = 0;
  return old;
}

ACE_INLINE void
TAO_ORB_Core_Auto_Ptr::reset (TAO_ORB_Core *p)
{
  ACE_TRACE ("TAO_ORB_Core_Auto_Ptr::reset");
  if (this->get () != p && this->get () != 0)
    this->get ()->_decr_refcnt ();
  this->p_ = p;
}

ACE_INLINE TAO_ORB_Core *
TAO_ORB_Core_Auto_Ptr::operator-> () const
{
  ACE_TRACE ("auto_ptr::operator->");
  return this->get ();
}

ACE_INLINE
TAO_ORB_Core_Auto_Ptr::TAO_ORB_Core_Auto_Ptr (TAO_ORB_Core_Auto_Ptr &rhs)
  : p_ (rhs.release ())
{
  ACE_TRACE ("TAO_ORB_Core_Auto_Ptr::TAO_ORB_Core_Auto_Ptr");
}

ACE_INLINE TAO_ORB_Core_Auto_Ptr &
TAO_ORB_Core_Auto_Ptr::operator= (TAO_ORB_Core_Auto_Ptr &rhs)
{
  ACE_TRACE ("TAO_ORB_Core_Auto_Ptr::operator=");
  if (this != &rhs)
    {
      this->reset (rhs.release ());
    }
  return *this;
}

ACE_INLINE
TAO_ORB_Core_Auto_Ptr::~TAO_ORB_Core_Auto_Ptr (void)
{
  ACE_TRACE ("TAO_ORB_Core_Auto_Ptr::~TAO_ORB_Core_Auto_Ptr");
  if (this->get() != 0)
    this->get ()->_decr_refcnt ();
}

// Accessor methods to the underlying ORB_Core Object

ACE_INLINE TAO_ORB_Core &
TAO_ORB_Core_Auto_Ptr::operator *() const
{
  ACE_TRACE ("TAO_ORB_Core_Auto_Ptr::operator *()");
  // @@ Potential problem if this->p_ is zero!
  return *this->get ();
}
