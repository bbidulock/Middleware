/* -*- C++ -*- */
// $Id$

#if defined (ACE_HAS_TOKENS_LIBRARY)

ACE_INLINE ACE_TOKEN_CONST::MUTEX &
ACE_Token_Manager::mutex (void)
{
  ACE_TRACE ("ACE_Token_Manager::mutex");
  return lock_;
}

ACE_INLINE void
ACE_Token_Manager::debug (int d)
{
  ACE_TRACE ("ACE_Token_Manager::debug");
  debug_ = d;
}

#endif /* ACE_HAS_TOKENS_LIBRARY */
