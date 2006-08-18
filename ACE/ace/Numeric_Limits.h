// -*- C++ -*-

//=============================================================================
/**
 * @file    Numeric_Limits.h
 *
 * $Id$
 *
 * Traits containing basic integer limits.  Useful for template-based
 * code on platforms that lack @c std::numeric_limits<>.
 *
 * @note These traits are not meant to be a replacement for
 *       @c std::numeric_limits<>.  Rather they are a crutch until all
 *       ACE-supported platforms also support
 *       @c std::numeric_limits<>.
 *
 * @internal   Only meant for internal use by ACE.
 * @deprecated This header will be removed once all platforms
 *             supported by ACE support @c std::numeric_limits<>.
 *
 * @author  Ossama Othman <ossama_othman at symantec dot com>
 */
//=============================================================================

#ifndef ACE_NUMERIC_LIMITS_H
#define ACE_NUMERIC_LIMITS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#ifdef ACE_LACKS_NUMERIC_LIMITS
# include "ace/Basic_Types.h"
#else
# ifdef __MINGW32__
// Windows defines min/max macros that interfere with the
// numeric_limits::min/max() traits.  Undefine those macros before
// including <limits>.
//
// Ideally, we could prevent those macros from being defined by
// defining the Windows-specific NOMINMAX symbol before any Windows
// headers are included, preferrably on the command line.  However,
// that would probably break some applications.
//
// @@ Why isn't this a problem with MSVC++ and Borland builds?
#  undef min
#  undef max
# endif  /* __MINGW32__ */
# include <limits>
#endif /* ACE_LACKS_NUMERIC_LIMITS */

// Address global namespace pollution potentially incurred by some
// platforms.
#undef min
#undef max

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#ifdef ACE_LACKS_NUMERIC_LIMITS

template <typename T> struct ACE_Numeric_Limits;


// ------------------------------------------
// Signed integers.

template<>
struct ACE_Export ACE_Numeric_Limits<signed char>
{
  static signed char min (void) { return SCHAR_MIN; }
  static signed char max (void) { return SCHAR_MAX; }
};

template<>
struct ACE_Export ACE_Numeric_Limits<signed short>
{
  static signed short min (void) { return SHRT_MIN; }
  static signed short max (void) { return SHRT_MAX; }
};

template<>
struct ACE_Export ACE_Numeric_Limits<signed int>
{
  static signed int min (void) { return INT_MIN; }
  static signed int max (void) { return INT_MAX; }
};

template<>
struct ACE_Export ACE_Numeric_Limits<signed long>
{
  static signed long min (void) { return LONG_MIN; }
  static signed long max (void) { return LONG_MAX; }
};

// #ifndef ACE_LACKS_LONGLONG_T
// template<>
// struct ACE_Export ACE_Numeric_Limits<signed long long>
// {
// #if defined (LLONG_MIN)
// #  define ACE_LLONG_MIN LLONG_MIN
// #elif defined (LONG_LONG_MIN)
// #  define ACE_LLONG_MIN LONG_LONG_MIN
// #elif defined (LONGLONG_MIN)
// #  define ACE_LLONG_MIN LONGLONG_MIN
// #else
// #  error Unable to determine minimum signed long long value.
// #endif  /* LLONG_MIN */

// #if defined (LLONG_MAX)
// #  define ACE_LLONG_MAX LLONG_MAX
// #elif defined (LONG_LONG_MAX)
// #  define ACE_LLONG_MAX LONG_LONG_MAX
// #elif defined (LONGLONG_MAX)
// #  define ACE_LLONG_MAX LONGLONG_MAX
// #else
// #  error Unable to determine maximum signed long long value.
// #endif  /* LLONG_MAX */

//   static signed long long min (void) { return ACE_LLONG_MIN; }
//   static signed long long max (void) { return ACE_LLONG_MAX; }
// };
// #endif  /* !ACE_LACKS_LONGLONG_T */

// ------------------------------------------
// Unsigned integers
template<>
struct ACE_Export ACE_Numeric_Limits<unsigned char>
{
  static unsigned char min (void) { return 0; }
  static unsigned char max (void) { return UCHAR_MAX; }
};

template<>
struct ACE_Export ACE_Numeric_Limits<unsigned short>
{
  static unsigned short min (void) { return 0; }
  static unsigned short max (void) { return USHRT_MAX; }
};

template<>
struct ACE_Export ACE_Numeric_Limits<unsigned int>
{
  static unsigned int min (void) { return 0; }
  static unsigned int max (void) { return UINT_MAX; }
};

template<>
struct ACE_Export ACE_Numeric_Limits<unsigned long>
{
  static unsigned long min (void) { return 0; }
  static unsigned long max (void) { return ULONG_MAX; }
};

// #ifndef ACE_LACKS_LONGLONG_T
// template<>
// struct ACE_Export ACE_Numeric_Limits<unsigned long long>
// {
//   static unsigned long long min (void) { return 0; }
//   static unsigned long long max (void)
//   {
// # if defined (ULLONG_MAX)
//     return ULLONG_MAX;
// # elif defined (ULONGLONG_MAX)
//     return ULONGLONG_MAX;
// # else
// #  error Unable to determine maximum unsigned long long value.
// # endif  /* ULLONG_MAX */
//   }
// };
// #endif  /* !ACE_LACKS_LONGLONG_T */

// ------------------------------------------
// Floating point types

template<>
struct ACE_Export ACE_Numeric_Limits<float>
{
  static float min (void) { return FLT_MIN; }
  static float max (void) { return FLT_MAX; }
};

template<>
struct ACE_Export ACE_Numeric_Limits<double>
{
  static double min (void) { return DBL_MIN; }
  static double max (void) { return DBL_MAX; }
};

template<>
struct ACE_Export ACE_Numeric_Limits<long double>
{
  static long double min (void) { return LDBL_MIN; }
  static long double max (void) { return LDBL_MAX; }
};

#else

// std::numeric_limits<> has all of the necessary specializations.
// Just wrap it.

template <typename T>
struct ACE_Numeric_Limits
{
  static T min (void) { return std::numeric_limits<T>::min (); }
  static T max (void) { return std::numeric_limits<T>::max (); }
};

#endif /* ACE_LACKS_NUMERIC_LIMITS */

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif  /* ACE_NUMERIC_LIMITS_H */
