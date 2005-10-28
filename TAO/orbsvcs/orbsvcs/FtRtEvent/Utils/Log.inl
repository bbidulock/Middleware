// $Id$

namespace TAO_FTRTEC {
#ifndef NDEBUG
  ACE_INLINE
  void Log::level(unsigned int log_level)
  {
    log_level_ = log_level;
  }

  ACE_INLINE
  unsigned int Log::level()
  {
    return log_level_;
  }

  ACE_INLINE
  void Log::hexdump(unsigned int level, const char* buf, size_t len, const char* msg)
  {
    if (Log::log_level_ >= level)
      ACE_HEX_DUMP((LM_DEBUG, buf, len, ACE_TEXT_TO_TCHAR_IN(msg)));
  }
#else // NDEBUG
  ACE_INLINE
  Log::Log (unsigned int, const ACE_TCHAR*, ...)
  {
  }

  ACE_INLINE
  void Log::level(unsigned int )
  {
  }

  ACE_INLINE
  unsigned int Log::level()
  {
    return 0;
  }

  ACE_INLINE
  void Log::hexdump(unsigned int, const char*, size_t, const char*)
  {
  }
#endif
}
