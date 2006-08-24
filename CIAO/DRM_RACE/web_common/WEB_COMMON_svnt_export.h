
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl WEB_COMMON_SVNT
// ------------------------------
#ifndef WEB_COMMON_SVNT_EXPORT_H
#define WEB_COMMON_SVNT_EXPORT_H

#include "ace/config-all.h"

#if !defined (WEB_COMMON_SVNT_HAS_DLL)
#  define WEB_COMMON_SVNT_HAS_DLL 1
#endif /* ! WEB_COMMON_SVNT_HAS_DLL */

#if defined (WEB_COMMON_SVNT_HAS_DLL) && (WEB_COMMON_SVNT_HAS_DLL == 1)
#  if defined (WEB_COMMON_SVNT_BUILD_DLL)
#    define WEB_COMMON_SVNT_Export ACE_Proper_Export_Flag
#    define WEB_COMMON_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define WEB_COMMON_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* WEB_COMMON_SVNT_BUILD_DLL */
#    define WEB_COMMON_SVNT_Export ACE_Proper_Import_Flag
#    define WEB_COMMON_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define WEB_COMMON_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* WEB_COMMON_SVNT_BUILD_DLL */
#else /* WEB_COMMON_SVNT_HAS_DLL == 1 */
#  define WEB_COMMON_SVNT_Export
#  define WEB_COMMON_SVNT_SINGLETON_DECLARATION(T)
#  define WEB_COMMON_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* WEB_COMMON_SVNT_HAS_DLL == 1 */

// Set WEB_COMMON_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (WEB_COMMON_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define WEB_COMMON_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define WEB_COMMON_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !WEB_COMMON_SVNT_NTRACE */

#if (WEB_COMMON_SVNT_NTRACE == 1)
#  define WEB_COMMON_SVNT_TRACE(X)
#else /* (WEB_COMMON_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define WEB_COMMON_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (WEB_COMMON_SVNT_NTRACE == 1) */

#endif /* WEB_COMMON_SVNT_EXPORT_H */

// End of auto generated file.
