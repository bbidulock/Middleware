ACE_INLINE CORBA::Boolean
ROA::shutting_down (void)
{
  return do_exit_;
}

ACE_INLINE CORBA::ORB_ptr
ROA::orb (void) const
{
  return orb_;
}

ACE_INLINE ACE_INET_Addr
ROA::get_addr (void) const
{
  return addr_;
}
