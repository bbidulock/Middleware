/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    ace_wchar.h
 *
 *  $Id$
 *
 *  @author Darrell Brunsch <brunsch@uci.edu>
 */
//=============================================================================

#ifndef ACE_WCHAR_H
#define ACE_WCHAR_H

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined(ACE_SIZEOF_WCHAR) || !defined (ACE_WCHAR_MAX)
  #error Must (Un)define ACE_SIZEOF_WCHAR, ACE_WCHAR_MAX, \
         and ACE_LACKS_BUILTIN_WCHAR_T in the config-<platform>.h
#endif

// Add includes and/or typedefs to get wchar_t, wint_t, and wctype_t.
# if defined (ACE_HAS_XPG4_MULTIBYTE_CHAR)
#    include /**/ <wchar.h>
# endif /* ACE_HAS_XPG4_MULTIBYPTE_CHAR */

# if defined (VXWORKS)
#   include /**/ <types/vxTypes.h>  /* For wchar_t */
    typedef wchar_t wint_t;
    typedef wchar_t wctype_t;

# elif defined (ACE_OPENVMS)
#   include /**/ <wchar.h>
#   include /**/ <wctype.h>

# elif defined (ACE_HAS_STANDARD_CPP_LIBRARY) && \
    (ACE_HAS_STANDARD_CPP_LIBRARY != 0)
#   include /**/ <cwchar>
#   include /**/ <cwctype>

# elif defined (ACE_HAS_WINCE)
#   include /**/ <wtypes.h>

# elif !defined (__BORLANDC__)
#   include /**/ <wchar.h>

# endif /* ACE_HAS_STANDARD_CPP_LIBRARY */

#if defined (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB) && \
            (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB != 0)
using std::size_t;
#endif /* ACE_USES_STD_NAMESPACE_FOR_STDC_LIB */

// Set the default behaviour for ACE_TEXT_WIDE to use the L-prefix
#if !defined (ACE_USES_L_PREFIX)
# define ACE_USES_L_PREFIX 1
#endif /* ACE_USES_L_PREFIX */

// Define the unicode/wchar related macros correctly

# if !defined (ACE_TEXT_WIDE)
#  if (ACE_USES_L_PREFIX == 1)
#    define ACE_TEXT_WIDE_I(STRING) L##STRING
#  else /* ACE_USES_L_PREFIX */
#    define ACE_TEXT_WIDE_I(STRING) STRING
#  endif /* ACE_USES_L_PREFIX */
#  define ACE_TEXT_WIDE(STRING) ACE_TEXT_WIDE_I (STRING)
# endif /* ACE_TEXT_WIDE */

#if defined (ACE_LEGACY_MODE)
# define ACE_TEXT TEXT
#else /* ACE_LEGACY_MODE */
# define ACE_TEXT ACE_LIB_TEXT
#endif /* ACE_LEGACY_MODE */

// The OS_String module defines some wide-char functions that are not
// universally available. In particular, they're not part of the
// XPG4 Worldwide Portability Interface wide-character string handling
// functions. So, if ACE_HAS_XPG4_MULTIBYTE_CHAR is defined, note that
// these functions are missing.
#if defined (ACE_HAS_XPG4_MULTIBYTE_CHAR)

#  if !defined (ACE_LACKS_ITOW)
#    define ACE_LACKS_ITOW
#  endif

#  if !defined (ACE_LACKS_WCSICMP)
#    define ACE_LACKS_WCSICMP
#  endif

#  if !defined (ACE_LACKS_WCSNICMP)
#    define ACE_LACKS_WCSNICMP
#  endif

#  if !defined (ACE_LACKS_WCSDUP)
#    define ACE_LACKS_WCSDUP
#  endif

#endif /* ACE_HAS_XPG4_MULTIBYTE_CHAR */

// ACE_TCHAR Macros
#if defined (ACE_USES_WCHAR)
  typedef wchar_t ACE_TCHAR;
  typedef char ACE_ANTI_TCHAR;
  # define ACE_LIB_TEXT(STRING) ACE_TEXT_WIDE( STRING )
#else /* ACE_USES_WCHAR */
  typedef char ACE_TCHAR;
  typedef wchar_t ACE_ANTI_TCHAR;
  # define ACE_LIB_TEXT(STRING) STRING
#endif /* ACE_USES_WCHAR */

// This package should only be included in the implementation files
// that use it.
#if defined (ACE_WIN32)
#include "ace/ace_wchar_win32_defs.h"
#endif

#endif /* ACE_WCHAR_H */
