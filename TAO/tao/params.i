ACE_INLINE
TAO_OA_Parameters::TAO_OA_Parameters (void)
  : using_threads_ (0),
    thread_flags_ (THR_NEW_LWP),
    context_p_ (0),
    upcall_ (0),
    forwarder_ (0),
    oa_ (0)
{
}

ACE_INLINE int
TAO_OA_Parameters::using_threads (void)
{
  return using_threads_;
}

ACE_INLINE void
TAO_OA_Parameters::using_threads (int i)
{
  using_threads_ = i;
}

ACE_INLINE void *
TAO_OA_Parameters::context (void)
{
  return context_p_;
}

ACE_INLINE void
TAO_OA_Parameters::context (void* p)
{
  context_p_ = p;
}

ACE_INLINE TAO_OA_Parameters::UpcallFunc
TAO_OA_Parameters::upcall (void)
{
  return upcall_;
}

ACE_INLINE void
TAO_OA_Parameters::upcall (TAO_OA_Parameters::UpcallFunc f)
{
  upcall_ = f;
}

ACE_INLINE TAO_OA_Parameters::ForwardFunc
TAO_OA_Parameters::forwarder (void)
{
  return forwarder_;
}

ACE_INLINE void
TAO_OA_Parameters::forwarder (TAO_OA_Parameters::ForwardFunc f)
{
  forwarder_ = f;
}

ACE_INLINE CORBA_BOA_ptr
TAO_OA_Parameters::oa (void)
{
  return oa_;
}

ACE_INLINE void
TAO_OA_Parameters::oa (CORBA_BOA_ptr anOA)
{
  oa_ = anOA;
}

ACE_INLINE u_int
TAO_OA_Parameters::thread_flags (void)
{
  return thread_flags_;
}

ACE_INLINE void
TAO_OA_Parameters::thread_flags (u_int f)
{
  thread_flags_ = f;
}

ACE_INLINE void
TAO_OA_Parameters::addr (ACE_INET_Addr &addr)
{
  this->addr_ = addr;
}

ACE_INLINE ACE_INET_Addr
TAO_OA_Parameters::addr (void)
{
  return this->addr_;
}

ACE_INLINE void
TAO_OA_Parameters::demux_strategy (DEMUX_STRATEGY strategy)
{
  this->demux_ = strategy;      // Trust that the value is valid!
}

ACE_INLINE void 
TAO_OA_Parameters::demux_strategy (const char* strategy)
{
  // Determine the demux strategy based on the given name
  if (!ACE_OS::strcmp (strategy, "linear"))
    {
      this->demux_ = TAO_LINEAR;
    }
  else if (!ACE_OS::strcmp (strategy, "dynamic_hash"))
    {
      this->demux_ = TAO_DYNAMIC_HASH;
    }
  else if (!ACE_OS::strcmp (strategy, "user_def"))
    {
      this->demux_ = TAO_USER_DEFINED;
    }
  else if (!ACE_OS::strcmp (strategy, "active_demux"))
    {
      this->demux_ = TAO_ACTIVE_DEMUX;
    }
  else
    {
      // Provide fallback!
      this->demux_ = TAO_LINEAR;
    }
}

ACE_INLINE TAO_OA_Parameters::DEMUX_STRATEGY
TAO_OA_Parameters::demux_strategy (void)
{
  return this->demux_;
}

ACE_INLINE void
TAO_OA_Parameters::tablesize (CORBA_ULong tblsize)
{
  this->tablesize_ = tblsize;
}

ACE_INLINE CORBA_ULong
TAO_OA_Parameters::tablesize (void)
{
  return this->tablesize_;
}

ACE_INLINE TAO_OA_Parameters *&
TAO_OA_Parameters::instance_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++...
  static TAO_OA_Parameters *instance_ = 0;

  return instance_;
#else
  return TAO_OA_Parameters::instance_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

ACE_INLINE ACE_SYNCH_MUTEX &
TAO_OA_Parameters::singleton_lock_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // ACE_SYNCH_MUTEX the creation of the singleton.  This works around a
  // "feature" of G++... ;-)
  static ACE_SYNCH_MUTEX ace_singleton_lock_;

  return ace_singleton_lock_;
#else
  return TAO_OA_Parameters::ace_singleton_lock_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

ACE_INLINE TAO_OA_Parameters *
TAO_OA_Parameters::instance (void)
{
  ACE_TRACE ("TAO_OA_Parameters::instance");

  TAO_OA_Parameters *&singleton = TAO_OA_Parameters::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, (TAO_OA_Parameters::singleton_lock_i ()), 0);

      if (singleton == 0)
	ACE_NEW_RETURN (singleton, TAO_OA_Parameters, 0);
    }

  return singleton;
}

ACE_INLINE TAO_OA_Parameters *
TAO_OA_Parameters::instance (TAO_OA_Parameters *new_instance)
{
  ACE_TRACE ("TAO_OA_Parameters::set_instance");

  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, (TAO_OA_Parameters::singleton_lock_i ()), 0);

  TAO_OA_Parameters *&singleton = TAO_OA_Parameters::instance_i ();
  TAO_OA_Parameters *old_instance = singleton;
  singleton = new_instance;

  return old_instance;
}


#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
// Pointer to the Singleton instance.
TAO_OA_Parameters *TAO_OA_Parameters::instance_ = 0;

// Lock the creation of the singleton.  
ACE_SYNCH_MUTEX TAO_OA_Parameters::ace_singleton_lock_;
#endif /* !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES) */
