// -*- C++ -*-
//=============================================================================
/**
 *  @file   OS_String.h
 *
 *  $Id$
 *
 *  @brief  Contains definition of class ACE_OS_String.
 *
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller <stophph@diku.dk>
 *  @author and a cast of thousands...
 */
//=============================================================================

#ifndef ACE_OS_STRING_H
#define ACE_OS_STRING_H
#include /**/ "ace/pre.h"

#include "ace/OS_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Types.h"
#include "ace/os_include/os_stddef.h"

#if defined (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB) && \
            (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB != 0)
using std::size_t;
using std::wint_t;
#endif /* ACE_USES_STD_NAMESPACE_FOR_STDC_LIB */

/**
 *  @namespace ACE_OS_String
 *
 *  @brief This class includes functions available in string.h and ctype.h.
 */
#define ACE_OS_String ACE_OS
namespace ACE_OS
{
  /** @name Functions from <cstring>
   *
   *  Included are the functions defined in <cstring> and their <cwchar>
   *  equivalents.
   *
   *  @todo To be complete, we should add strcoll, and strxfrm.
   */
  //@{

  /// Finds characters in a buffer (const void version).
  const void *memchr (const void *s, int c, size_t len);

  /// Finds characters in a buffer (void version).
  void *memchr (void *s, int c, size_t len);

  /// Compares two buffers.
  int memcmp (const void *t, const void *s, size_t len);

  /// Copies one buffer to another.
  void *memcpy (void *t, const void *s, size_t len);

  /// Moves one buffer to another.
  void *memmove (void *t, const void *s, size_t len);

  /// Fills a buffer with a character value.
  void *memset (void *s, int c, size_t len);

  /// Appends a string to another string (char version).
  char *strcat (char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Appends a string to another string (wchar_t version).
  wchar_t *strcat (wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a character in a string (const char
  /// version).
  const char *strchr (const char *s, int c);

#if defined (ACE_HAS_WCHAR)
  /// Finds the first occurance of a character in a string (const wchar_t
  /// version).
  const wchar_t *strchr (const wchar_t *s, wint_t c);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a character in a string (char version).
  char *strchr (char *s, int c);

#if defined (ACE_HAS_WCHAR)
  /// Finds the first occurance of a character in a string (wchar_t version).
  wchar_t *strchr (wchar_t *s, wint_t c);
#endif /* ACE_HAS_WCHAR */

  /// Compares two strings (char version).
  int strcmp (const char *s, const char *t);

  /// Compares two strings (wchar_t version).
  int strcmp (const ACE_WCHAR_T *s, const ACE_WCHAR_T *t);

  /// Copies a string (char version).
  char *strcpy (char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Copies a string (wchar_t version).
  wchar_t *strcpy (wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Searches for the first substring without any of the specified
  /// characters and returns the size of the substring (char version).
  size_t strcspn (const char *s, const char *reject);

#if defined (ACE_HAS_WCHAR)
  /// Searches for the first substring without any of the specified
  /// characters and returns the size of the substring (wchar_t version).
  size_t strcspn (const wchar_t *s, const wchar_t *reject);
#endif /* ACE_HAS_WCHAR */

  /// Returns a system error message.
  char *strerror (int errnum);

  /// Finds the length of a string (char version).
  size_t strlen (const char *s);

  /// Finds the length of a string (ACE_WCHAR_T version).
  size_t strlen (const ACE_WCHAR_T *s);

  /// Finds the length of a limited-length string (char version).
  /**
   * @param s       The character string to find the length of.
   * @param maxlen  The maximum number of characters that will be
   *                scanned for the terminating nul character.
   *
   * @return The length of @arg s, if the terminating nul character
   *         is located, else @arg maxlen.
   */
  size_t strnlen (const char *s, size_t maxlen);

  /// Finds the length of a limited-length string (ACE_WCHAR_T version).
  /**
   * @param s       The character string to find the length of.
   * @param maxlen  The maximum number of characters that will be
   *                scanned for the terminating nul character.
   *
   * @return The length of @arg s, if the terminating nul character
   *         is located, else @arg maxlen.
   */
  size_t strnlen (const ACE_WCHAR_T *s, size_t maxlen);

  /// Appends part of a string to another string (char version).
  char *strncat (char *s, const char *t, size_t len);

  /// Appends part of a string to another string (wchar_t version).
  ACE_WCHAR_T *strncat (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len);

  /// Compares two arrays (char version).
  int strncmp (const char *s, const char *t, size_t len);

  /// Compares two arrays (wchar_t version).
  int strncmp (const ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len);

  /// Copies an array (char version)
  char *strncpy (char *s, const char *t, size_t len);

  /// Copies an array (ACE_WCHAR_T version)
  ACE_WCHAR_T *strncpy (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len);

  /// Searches for characters in a string (const char version).
  const char *strpbrk (const char *s1, const char *s2);

#if defined (ACE_HAS_WCHAR)
  /// Searches for characters in a string (const wchar_t version).
  const wchar_t *strpbrk (const wchar_t *s1, const wchar_t *s2);
#endif /* ACE_HAS_WCHAR */

  /// Searches for characters in a string (char version).
  char *strpbrk (char *s1, const char *s2);

#if defined (ACE_HAS_WCHAR)
  /// Searches for characters in a string (wchar_t version).
  wchar_t *strpbrk (wchar_t *s1, const wchar_t *s2);
#endif /* ACE_HAS_WCHAR */

  /// Finds the last occurance of a character in a string (const char
  /// version).
  const char *strrchr (const char *s, int c);

#if defined (ACE_HAS_WCHAR)
  /// Finds the last occurance of a character in a string (const wchar_t
  /// version).
  const wchar_t *strrchr (const wchar_t *s, wint_t c);
#endif /* ACE_HAS_WCHAR */

  /// Finds the last occurance of a character in a string (char version).
  char *strrchr (char *s, int c);

#if defined (ACE_HAS_WCHAR)
  /// Finds the last occurance of a character in a string (wchar_t version).
  wchar_t *strrchr (wchar_t *s, wint_t c);
#endif /* ACE_HAS_WCHAR */

  /// Searches for the first substring containing only the specified
  /// characters and returns the size of the substring (char version).
  size_t strspn (const char *s1, const char *s2);

#if defined (ACE_HAS_WCHAR)
  /// Searches for the first substring containing only the specified
  /// characters and returns the size of the substring (wchar_t version).
  size_t strspn (const wchar_t *s1, const wchar_t *s2);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a substring in a string (const char
  /// version).
  const char *strstr (const char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Finds the first occurance of a substring in a string (const wchar_t
  /// version).
  const wchar_t *strstr (const wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a substring in a string (char version).
  char *strstr (char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Finds the first occurance of a substring in a string (wchar_t version).
  wchar_t *strstr (wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Finds the next token in a string (char version).
  char *strtok (char *s, const char *tokens);

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOK)
  /// Finds the next token in a string (wchar_t version).
  wchar_t *strtok (wchar_t *s, const wchar_t *tokens);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOK */

  //@}

  /** @name Functions from <cctype>
   *
   *  Included are the functions defined in <cctype> and their <cwctype>
   *  equivalents.
   *
   *  Since they are often implemented as macros, we don't use the same name
   *  here.  Instead, we change by prepending "ace_" (with the exception of
   *  to_lower).
   *
   *  @todo To be complete, we should add: isalnum, isalpha, iscntrl
   *  isdigit, isgraph, islower, ispunct, isupper, isxdigit, and toupper.
   */
  //@{

  /// Returns true if the character is a printable character.
  int ace_isprint (const ACE_TCHAR c);

  /// Returns true if the character is a space character.
  int ace_isspace (const ACE_TCHAR c);

  /// Converts a character to lower case (char version).
  int to_lower (int c);

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_TOWLOWER)
  /// Converts a character to lower case (wchar_t version).
  wint_t to_lower (wint_t c);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_TOWLOWER */

  //@}

  /** @name Non-standard functions
   *
   *  These functions aren't in the standard.
   *
   */
  //@{

  /// Converts an integer to a string.
  char *itoa (int value, char *string, int radix);

#if defined (ACE_HAS_WCHAR)
  /// Converts an integer to a string.
  wchar_t *itoa (int value, wchar_t *string, int radix);
#endif /* ACE_HAS_WCHAR */

  /// Compares two strings (case insensitive const char version).
  int strcasecmp (const char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Compares two strings (case insensitive const wchar_t version).
  int strcasecmp (const wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a character in an array (const char
  /// version).
  const char *strnchr (const char *s, int c, size_t len);

  /// Finds the first occurance of a character in an array (const ACE_WCHAR_T
  /// version).
  const ACE_WCHAR_T *strnchr (const ACE_WCHAR_T *s, ACE_WINT_T c, size_t len);

  /// Finds the first occurance of a character in an array (char version).
  char *strnchr (char *s, int c, size_t len);

  /// Finds the first occurance of a character in an array (ACE_WCHAR_T version).
  ACE_WCHAR_T *strnchr (ACE_WCHAR_T *s, ACE_WINT_T c, size_t len);

  /// Compares two arrays (case insensitive const char version).
  int strncasecmp (const char *s, const char *t, size_t len);

#if defined (ACE_HAS_WCHAR)
  /// Compares two arrays (case insensitive const wchar_t version).
  int strncasecmp (const wchar_t *s, const wchar_t *t, size_t len);
#endif /* ACE_HAS_WCHAR */

  /// Copies a string, but returns a pointer to the end of the
  /// copied region (char version).
  char *strecpy (char *des, const char *src);

#if defined (ACE_HAS_WCHAR)
  /// Copies a string, but returns a pointer to the end of the
  /// copied region (wchar_t version).
  wchar_t *strecpy (wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// This is a "safe" c string copy function (char version).
  /**
   * Unlike strncpy() this function will always add a terminating '\0'
   * char if maxlen > 0.  So the user doesn't has to provide an extra
   * '\0' if the user wants a '\0' terminated dst.  The function
   * doesn't check for a 0 <dst>, because this will give problems
   * anyway.  When <src> is 0 an empty string is made.  We do not
   * "touch" *<dst> if maxlen is 0.  Returns <dst>.  Care should be
   * taken when replacing strncpy() calls, because in some cases a
   * strncpy() user is using the "not '\0' terminating" feature from
   * strncpy().  This happens most when the call to strncpy() was
   * optimized by using a maxlen which is 1 smaller than the size
   * because there's always written a '\0' inside this last position.
   * Very seldom it's possible that the '\0' padding feature from
   * strncpy() is needed.
   */
  char *strsncpy (char *dst,
                         const char *src,
                         size_t maxlen);

  /// This is a "safe" c string copy function (wchar_t version).
  /**
   * Unlike strncpy() this function will always add a terminating '\0'
   * char if maxlen > 0.  So the user doesn't has to provide an extra
   * '\0' if the user wants a '\0' terminated dst.  The function
   * doesn't check for a 0 <dst>, because this will give problems
   * anyway.  When <src> is 0 an empty string is made.  We do not
   * "touch" *<dst> if maxlen is 0.  Returns <dst>.  Care should be
   * taken when replacing strncpy() calls, because in some cases a
   * strncpy() user is using the "not '\0' terminating" feature from
   * strncpy().  This happens most when the call to strncpy() was
   * optimized by using a maxlen which is 1 smaller than the size
   * because there's always written a '\0' inside this last position.
   * Very seldom it's possible that the '\0' padding feature from
   * strncpy() is needed.
   */
  ACE_WCHAR_T *strsncpy (ACE_WCHAR_T *dst,
                                const ACE_WCHAR_T *src,
                                size_t maxlen);

  /// Finds the first occurance of a substring in an array (const char
  /// version).
  const char *strnstr (const char *s, const char *t, size_t len);

  /// Finds the first occurance of a substring in an array (const wchar_t
  /// version).
  const ACE_WCHAR_T *strnstr (const ACE_WCHAR_T *s,
                                     const ACE_WCHAR_T *t,
                                     size_t len);

  /// Finds the first occurance of a substring in an array (char version).
  char *strnstr (char *s, const char *t, size_t len);

  /// Finds the first occurance of a substring in an array (wchar_t version).
  ACE_WCHAR_T *strnstr (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len);

  /// Returns a malloced duplicated string (char version).
  char *strdup (const char *s);

#if defined (ACE_HAS_WCHAR)
  /// Returns a malloced duplicated string (wchar_t version).
  wchar_t *strdup (const wchar_t *s);
#endif /* ACE_HAS_WCHAR */

  /// Finds the next token in a string (safe char version).
  char *strtok_r (char *s, const char *tokens, char **lasts);

#if defined (ACE_HAS_WCHAR)
  /// Finds the next token in a string (wchar_t version).
  wchar_t *strtok_r (ACE_WCHAR_T *s, const ACE_WCHAR_T *tokens, ACE_WCHAR_T **lasts);
#endif  // ACE_HAS_WCHAR

#if !defined (ACE_LACKS_STRTOD)
  /// Converts a string to a double value (char version).
  double strtod (const char *s, char **endptr);
#endif /* !ACE_LACKS_STRTOD */

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOD)
  /// Converts a string to a double value (wchar_t version).
  double strtod (const wchar_t *s, wchar_t **endptr);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOD */

  /// Converts a string to a long value (char version).
  long strtol (const char *s, char **ptr, int base);

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOL)
  /// Converts a string to a long value (wchar_t version).
  long strtol (const wchar_t *s, wchar_t **ptr, int base);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOL */

  /// Converts a string to an unsigned long value (char version).
  unsigned long strtoul (const char *s, char **ptr, int base);

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOUL)
  /// Converts a string to an unsigned long value (wchar_t version).
  unsigned long strtoul (const wchar_t *s, wchar_t **ptr, int base);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOUL */

  //@}

  /** @name Emulation
   *
   *  These methods are provided for platforms that do not have a native
   *  implementation.
   */
  //@{

#if !defined (ACE_HAS_ITOA)
  /// Emulated itoa - Converts an integer to a string.
  char *itoa_emulation (int value, char *string, int radix);
#endif /* !ACE_HAS_ITOA */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_ITOW)
  /// Emulated itow - Converts an integer to a string.
  wchar_t *itow_emulation (int value, wchar_t *string, int radix);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_ITOW */

#if !defined (ACE_HAS_MEMCHR)
  /// Emulated memchr - Finds a character in a buffer.
  const void *memchr_emulation (const void *s, int c, size_t len);
#endif /* ACE_HAS_MEMCHR */

#if defined (ACE_LACKS_STRCASECMP)
  /// Emulated strcasecmp - Performs a case insensitive comparison of strings.
  int strcasecmp_emulation (const char *s, const char *t);

  /// Emulated strncasecmp - Performs a case insensitvie comparison of arrays.
  int strncasecmp_emulation (const char *s, const char *t, size_t len);
#endif /* ACE_LACKS_STRCASECMP */

#if defined (ACE_LACKS_STRCSPN)
  /// Emulated strcspn - Finds a substring in a string.
  size_t strcspn_emulation (const char *s, const char *reject);
#endif /* ACE_LACKS_STRCSPN */

#if defined (ACE_LACKS_STRCHR)
  /// Emulated strchr (char version) - Finds the first occurance of a
  /// character in a string.
  char *strchr_emulation (char *s, int c);

  /// Emulated strchr (const char version) - Finds the first occurance of a
  /// character in a string.
  const char *strchr_emulation (const char *s, int c);
#endif /* ACE_LACKS_STRCHR */

#if defined (ACE_LACKS_STRERROR)
  /// Emulated strerror - Returns a system error message.
  char *strerror_emulation (int errnum);
#endif /* ACE_LACKS_STRERROR */

#if defined (ACE_LACKS_STRPBRK)
  /// Emulated strpbrk - Searches for characters in a string.
  char *strpbrk_emulation (const char *string,
                                  const char *charset);
#endif /* ACE_LACKS_STRPBRK */

#if defined (ACE_LACKS_STRRCHR)
  /// Emulated strrchr (char version) - Finds the last occurance of a
  /// character in a string.
  char *strrchr_emulation (char *s, int c);

  /// Emulated strrchr (const char version) - Finds the last occurance of a
  /// character in a string.
  const char *strrchr_emulation (const char *s, int c);
#endif /* ACE_LACKS_STRRCHR */

#if !defined (ACE_HAS_REENTRANT_FUNCTIONS)
  /// Emulated strtok_r.
  char *strtok_r_emulation (char *s, const char *tokens, char **lasts);

# if defined (ACE_HAS_WCHAR)
  /// Emulated strtok_r (wchar_t version).
  wchar_t *strtok_r_emulation (ACE_WCHAR_T *s, const ACE_WCHAR_T *tokens, ACE_WCHAR_T **lasts);
# endif  // ACE_HAS_WCHAR
#endif /* !ACE_HAS_REENTRANT_FUNCTIONS */

#if defined (ACE_LACKS_STRSPN)
  /// Emulated wcsspn.
  size_t strspn_emulation (const char *string,
                                  const char *charset);
#endif /* ACE_LACKS_STRSPN */

#if defined (ACE_LACKS_STRTOL)
  long strtol_emulation (const char *nptr, char **endptr, int base);
#endif /* ACE_LACKS_STRTOL */

#if defined (ACE_LACKS_STRTOUL)
  unsigned long strtoul_emulation (const char *nptr,
                                          char **endptr,
                                          int base);
#endif /* ACE_LACKS_STRTOUL */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSCAT)
  /// Emulated wcscat - Appends a string.
  wchar_t *wcscat_emulation (wchar_t *destination,
                                    const wchar_t *source);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSCAT */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSCHR)
  /// Emulated wcschr - Finds a character in a string.
  wchar_t *wcschr_emulation (const wchar_t *string, wint_t c);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSCHR */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSCMP)
  /// Emulated wcscmp - Compares strings.
  int wcscmp_emulation (const ACE_WCHAR_T *string1, const ACE_WCHAR_T *string2);
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSCMP */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSCPY)
  /// Emulated wcscpy - Copies a string.
  wchar_t *wcscpy_emulation (wchar_t *destination,
                                    const wchar_t *source);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSCPY */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSICMP)
  /// Emulated wcsicmp - Performs a case insensitive comparison of strings.
  int wcsicmp_emulation (const wchar_t *string1,
                                const wchar_t *string2);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSICMP */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSLEN)
  /// Emulated wcslen - Returns the length of a string.
  size_t wcslen_emulation (const ACE_WCHAR_T *string);
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSLEN */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCAT)
  /// Emulated wcscat - Appends a string.
  ACE_WCHAR_T *wcsncat_emulation (ACE_WCHAR_T *destination,
                                         const ACE_WCHAR_T *source,
                                         size_t count);
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSCAT */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCMP)
  /// Emulated wcsncmp - Compares two arrays.
  int wcsncmp_emulation (const ACE_WCHAR_T *string1,
                                const ACE_WCHAR_T *string2,
                                size_t len);
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCMP */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCPY)
  /// Emulated wcsncpy - Copies an array.
  ACE_WCHAR_T *wcsncpy_emulation (ACE_WCHAR_T *destination,
                                         const ACE_WCHAR_T *source,
                                         size_t len);
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCPY */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSNICMP)
  /// Emulated wcsnicmp - Performs a case insensitive comparison of two
  /// arrays
  int wcsnicmp_emulation (const wchar_t *string1,
                                 const wchar_t *string2,
                                 size_t len);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSNICMP */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSPBRK)
  /// Emulated wcspbrk - Searches for characters in a string.
  wchar_t *wcspbrk_emulation (const wchar_t *string,
                                     const wchar_t *charset);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSPBRK */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSRCHR)
  /// Emulated wcsrchr (wchar_t version) - Finds the last occurance of a
  /// character in a string.
  wchar_t *wcsrchr_emulation (wchar_t *string, wint_t c);

  /// Emulated wcsrchr (const wchar_t version) - Finds the last occurance of a
  /// character in a string.
  const wchar_t *wcsrchr_emulation (const wchar_t *string, wint_t c);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSRCHR */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSCSPN)
  /// Emulated wcscspn.
  size_t wcscspn_emulation (const wchar_t *string,
                                   const wchar_t *reject);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSCSPN */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSSPN)
  /// Emulated wcsspn.
  size_t wcsspn_emulation (const wchar_t *string,
                                  const wchar_t *charset);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSSPN */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSSTR)
  /// Emulated wcsstr - Performs a case insensitive comparison of two strings.
  wchar_t *wcsstr_emulation (const wchar_t *string,
                                    const wchar_t *charset);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSSTR */

  //@}
}; /* namespace ACE_OS */

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_String.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

#include /**/ "ace/post.h"
#endif /* ACE_OS_STRING_H */
