// -*- C++ -*-
//
// $Id$

// OS_NS_wchar.h is only needed to get the emulation methods.
// Perhaps they should be moved.  dhinton
#include "ace/OS_NS_wchar.h"
#include "ace/os_include/os_string.h"

ACE_INLINE const void *
ACE_OS::memchr (const void *s, int c, size_t len)
{
#if defined (ACE_HAS_MEMCHR)
  return ::memchr (s, c, len);
#else /* ACE_HAS_MEMCHR */
  return ACE_OS::memchr_emulation (s, c, len);
#endif /* ACE_HAS_MEMCHR */
}

ACE_INLINE void *
ACE_OS::memchr (void *s, int c, size_t len)
{
  return const_cast<void *> (ACE_OS::memchr (static_cast<const void *> (s),
                                             c,
                                             len));
}

ACE_INLINE int
ACE_OS::memcmp (const void *t, const void *s, size_t len)
{
  return ::memcmp (t, s, len);
}

ACE_INLINE void *
ACE_OS::memcpy (void *t, const void *s, size_t len)
{
#if defined (ACE_HAS_MEMCPY_LOOP_UNROLL)
  return fast_memcpy (t, s, len);
#else
  return ::memcpy (t, s, len);
#endif /* ACE_HAS_MEMCPY_LOOP_UNROLL */
}

ACE_INLINE void *
ACE_OS::memmove (void *t, const void *s, size_t len)
{
  return ::memmove (t, s, len);
}

ACE_INLINE void *
ACE_OS::memset (void *s, int c, size_t len)
{
  return ::memset (s, c, len);
}

ACE_INLINE char *
ACE_OS::strcat (char *s, const char *t)
{
  return ::strcat (s, t);
}

ACE_INLINE wchar_t *
ACE_OS::strcat (wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSCAT)
  return ACE_OS::wcscat_emulation (s, t);
#  else /* ACE_LACKS_WCSCAT */
  return ::wcscat (s, t);
#  endif /* ACE_LACKS_WCSCAT */
}

ACE_INLINE const char *
ACE_OS::strchr (const char *s, int c)
{
#if defined (ACE_LACKS_STRCHR)
  return ACE_OS::strchr_emulation (s, c);
#else  /* ! ACE_LACKS_STRCHR */
  return (const char *) ::strchr (s, c);
#endif /* ACE_LACKS_STRCHR */
}

ACE_INLINE const wchar_t *
ACE_OS::strchr (const wchar_t *s, wint_t c)
{
#  if defined (ACE_LACKS_WCSCHR)
  return ACE_OS::wcschr_emulation (s, c);
#  else /* ACE_LACKS_WCSCHR */
  return ::wcschr (s, c);
#  endif /* ACE_LACKS_WCSCHR */
}

ACE_INLINE char *
ACE_OS::strchr (char *s, int c)
{
  return ::strchr (s, c);
}

ACE_INLINE wchar_t *
ACE_OS::strchr (wchar_t *s, wint_t c)
{
  return
    const_cast<wchar_t *> (ACE_OS::strchr (static_cast<const wchar_t *> (s),
                                           c));
}

ACE_INLINE char *
ACE_OS::strcpy (char *s, const char *t)
{
  return ::strcpy (s, t);
}

ACE_INLINE wchar_t *
ACE_OS::strcpy (wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSCPY)
  return ACE_OS::wcscpy_emulation (s, t);
#  else /* ACE_LACKS_WCSCPY */
  return ::wcscpy (s, t);
#  endif /* ACE_LACKS_WCSCPY */
}

ACE_INLINE size_t
ACE_OS::strcspn (const char *s, const char *reject)
{
  return ::strcspn (s, reject);
}

ACE_INLINE size_t
ACE_OS::strcspn (const wchar_t *s, const wchar_t *reject)
{
#  if defined (ACE_LACKS_WCSCSPN)
  return ACE_OS::wcscspn_emulation (s, reject);
#  else /* ACE_LACKS_WCSCSPN */
  return ::wcscspn (s, reject);
#  endif /* ACE_LACKS_WCSCSPN */
}

ACE_INLINE char *
ACE_OS::strncat (char *s, const char *t, size_t len)
{
  return ::strncat (s, t, len);
}

ACE_INLINE wchar_t *
ACE_OS::strncat (wchar_t *s, const wchar_t *t, size_t len)
{
#  if defined (ACE_LACKS_WCSNCAT)
  return ACE_OS::wcsncat_emulation (s, t, len);
#  else /* ACE_LACKS_WCSNCAT */
  return ::wcsncat (s, t, len);
#  endif /* ACE_LACKS_WCSNCAT */
}

ACE_INLINE char *
ACE_OS::strnchr (char *s, int c, size_t len)
{
#if defined ACE_PSOS_DIAB_PPC  /* Compiler problem Diab 4.2b */
  const char *const_char_s = s;
  return const_cast<char *> (ACE_OS::strnchr (const_char_s, c, len));
#else
  return const_cast<char *> (ACE_OS::strnchr (static_cast<const char *> (s),
                                              c,
                                              len));
#endif
}

ACE_INLINE wchar_t *
ACE_OS::strnchr (wchar_t *s, wint_t c, size_t len)
{
  return
    const_cast<wchar_t *> (ACE_OS::strnchr (
                                 static_cast<const wchar_t *> (s),
                                 c,
                                 len));
}

ACE_INLINE int
ACE_OS::strncmp (const char *s, const char *t, size_t len)
{
  return ::strncmp (s, t, len);
}

ACE_INLINE int
ACE_OS::strncmp (const wchar_t *s, const wchar_t *t, size_t len)
{
#  if defined (ACE_LACKS_WCSNCMP)
  return ACE_OS::wcsncmp_emulation (s, t, len);
#  else /* ACE_LACKS_WCSNCMP */
  return ::wcsncmp (s, t, len);
#  endif /* ACE_LACKS_WCSNCMP */
}

ACE_INLINE size_t
ACE_OS::strnlen (const char *s, size_t maxlen)
{
#if defined (ACE_HAS_STRNLEN)
  return ::strnlen (s, maxlen);
#else /* ACE_HAS_STRNLEN */
  size_t i;
  for (i = 0; i < maxlen; ++i)
    if (s[i] == '\0')
      break;
  return i;
#endif /* ACE_HAS_STRNLEN */
}

ACE_INLINE size_t
ACE_OS::strnlen (const wchar_t *s, size_t maxlen)
{
#if defined (ACE_HAS_WCSNLEN)
  return wcsnlen (s, maxlen);
#else /* ACE_HAS_WCSNLEN */
  size_t i;
  for (i = 0; i < maxlen; ++i)
    if (s[i] == '\0')
      break;
  return i;
#endif /* ACE_HAS_WCSNLEN */
}

ACE_INLINE char *
ACE_OS::strnstr (char *s, const char *t, size_t len)
{
#if defined ACE_PSOS_DIAB_PPC  /* Compiler problem Diab 4.2b */
  const char *const_char_s=s;
  return (char *) ACE_OS::strnstr (const_char_s, t, len);
#else
  return (char *) ACE_OS::strnstr ((const char *) s, t, len);
#endif
}

ACE_INLINE wchar_t *
ACE_OS::strnstr (wchar_t *s, const wchar_t *t, size_t len)
{
  return
    const_cast<wchar_t *> (ACE_OS::strnstr (
                                 static_cast<const wchar_t *> (s),
                                 t,
                                 len));
}

ACE_INLINE const char *
ACE_OS::strpbrk (const char *s1, const char *s2)
{
#if defined (ACE_LACKS_STRPBRK)
  return ACE_OS::strpbrk_emulation (s1, s2);
#else  /* ACE_LACKS_STRPBRK */
  return (const char *) ::strpbrk (s1, s2);
#endif /* ACE_LACKS_STRPBRK */
}

ACE_INLINE const wchar_t *
ACE_OS::strpbrk (const wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSPBRK)
  return ACE_OS::wcspbrk_emulation (s, t);
#  else /* ACE_LACKS_WCSPBRK */
  return ::wcspbrk (s, t);
#  endif /* ACE_LACKS_WCSPBRK */
}

ACE_INLINE char *
ACE_OS::strpbrk (char *s1, const char *s2)
{
#if defined (ACE_LACKS_STRPBRK)
  return ACE_OS::strpbrk_emulation (s1, s2);
#else /* ACE_LACKS_STRPBRK */
  return ::strpbrk (s1, s2);
#endif /* ACE_LACKS_STRPBRK */
}

ACE_INLINE wchar_t *
ACE_OS::strpbrk (wchar_t *s, const wchar_t *t)
{
  return const_cast<wchar_t *> (ACE_OS::strpbrk (
                                  static_cast<const wchar_t *> (s), t));
}

ACE_INLINE const char *
ACE_OS::strrchr (const char *s, int c)
{
#if defined (ACE_LACKS_STRRCHR)
  return ACE_OS::strrchr_emulation (s, c);
#else  /* ! ACE_LACKS_STRRCHR */
  return (const char *) ::strrchr (s, c);
#endif /* ! ACE_LACKS_STRRCHR */
}

ACE_INLINE const wchar_t *
ACE_OS::strrchr (const wchar_t *s, wint_t c)
{
#if defined (ACE_LACKS_WCSRCHR)
  return ACE_OS::wcsrchr_emulation (s, c);
#else /* ! ACE_LACKS_WCSRCHR */
  return (const wchar_t *) ::wcsrchr (s, c);
#endif /* ! ACE_LACKS_WCSRCHR */
}

ACE_INLINE char *
ACE_OS::strrchr (char *s, int c)
{
#if defined (ACE_LACKS_STRRCHR)
  return ACE_OS::strrchr_emulation (s, c);
#else  /* ! ACE_LACKS_STRRCHR */
  return ::strrchr (s, c);
#endif /* ! ACE_LACKS_STRRCHR */
}

ACE_INLINE wchar_t *
ACE_OS::strrchr (wchar_t *s, wint_t c)
{
  return const_cast<wchar_t *> (ACE_OS::strrchr (
                     static_cast<const wchar_t *> (s), c));
}

ACE_INLINE size_t
ACE_OS::strspn (const char *s, const char *t)
{
#if defined (ACE_LACKS_STRSPN)
  return ACE_OS::strspn_emulation (s, t);
#else /* ACE_LACKS_STRSPN */
  return ::strspn (s, t);
#endif /* ACE_LACKS_STRSPN */
}

ACE_INLINE size_t
ACE_OS::strspn (const wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSSPN)
  return ACE_OS::wcsspn_emulation (s, t);
#  else /* ACE_LACKS_WCSSPN */
  return ::wcsspn (s, t);
#  endif /* ACE_LACKS_WCSSPN */
}

ACE_INLINE const char *
ACE_OS::strstr (const char *s, const char *t)
{
  return (const char *) ::strstr (s, t);
}

ACE_INLINE const wchar_t *
ACE_OS::strstr (const wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSSTR)
  return ACE_OS::wcsstr_emulation (s, t);
#  elif defined (HPUX)
  return (const wchar_t *) ::wcswcs (s, t);
#  else /* ACE_LACKS_WCSSTR */
  return (const wchar_t *) ::wcsstr (s, t);
#  endif /* ACE_LACKS_WCSSTR */
}

ACE_INLINE char *
ACE_OS::strstr (char *s, const char *t)
{
  return ::strstr (s, t);
}

ACE_INLINE wchar_t *
ACE_OS::strstr (wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSSTR)
  return ACE_OS::wcsstr_emulation (s, t);
#  elif defined (HPUX)
  return ::wcswcs (s, t);
#  else /* ACE_LACKS_WCSSTR */
  return ::wcsstr (s, t);
#  endif /* ACE_LACKS_WCSSTR */
}

ACE_INLINE char *
ACE_OS::strtok (char *s, const char *tokens)
{
  return ::strtok (s, tokens);
}

ACE_INLINE wchar_t *
ACE_OS::strtok (wchar_t *s, const wchar_t *tokens)
{
#if defined (ACE_HAS_3_PARAM_WCSTOK)
  static wchar_t *lasts;
  return ::wcstok (s, tokens, &lasts);
#elif !defined (ACE_LACKS_WCSTOK)
  return ::wcstok (s, tokens);
#else
    ACE_UNUSED_ARG( s );
    ACE_UNUSED_ARG( ptr );
    ACE_UNUSED_ARG( base );
    ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_3_PARAM_WCSTOK */
}

ACE_INLINE char *
ACE_OS::strtok_r (char *s, const char *tokens, char **lasts)
{
#if defined (ACE_HAS_REENTRANT_FUNCTIONS)
  return ::strtok_r (s, tokens, lasts);
#else
  return ACE_OS::strtok_r_emulation (s, tokens, lasts);
#endif /* (ACE_HAS_REENTRANT_FUNCTIONS) */
}

ACE_INLINE wchar_t*
ACE_OS::strtok_r (wchar_t *s, const wchar_t *tokens, wchar_t **lasts)
{
#if defined (ACE_LACKS_WCSTOK)
    return ACE_OS::strtok_r_emulation (s, tokens, lasts);
#else
#  if defined (ACE_HAS_3_PARAM_WCSTOK)
    return ::wcstok (s, tokens, lasts);
#  else /* ACE_HAS_3_PARAM_WCSTOK */
    *lasts = ::wcstok (s, tokens);
    return *lasts;
#  endif /* ACE_HAS_3_PARAM_WCSTOK */
#endif  /* ACE_LACKS_WCSTOK */
}
