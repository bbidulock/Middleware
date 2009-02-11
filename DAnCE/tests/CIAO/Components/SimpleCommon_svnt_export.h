
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl SIMPLECOMMON_SVNT
// ------------------------------
#ifndef SIMPLECOMMON_SVNT_EXPORT_H
#define SIMPLECOMMON_SVNT_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (SIMPLECOMMON_SVNT_HAS_DLL)
#  define SIMPLECOMMON_SVNT_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && SIMPLECOMMON_SVNT_HAS_DLL */

#if !defined (SIMPLECOMMON_SVNT_HAS_DLL)
#  define SIMPLECOMMON_SVNT_HAS_DLL 1
#endif /* ! SIMPLECOMMON_SVNT_HAS_DLL */

#if defined (SIMPLECOMMON_SVNT_HAS_DLL) && (SIMPLECOMMON_SVNT_HAS_DLL == 1)
#  if defined (SIMPLECOMMON_SVNT_BUILD_DLL)
#    define SIMPLECOMMON_SVNT_Export ACE_Proper_Export_Flag
#    define SIMPLECOMMON_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define SIMPLECOMMON_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* SIMPLECOMMON_SVNT_BUILD_DLL */
#    define SIMPLECOMMON_SVNT_Export ACE_Proper_Import_Flag
#    define SIMPLECOMMON_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define SIMPLECOMMON_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* SIMPLECOMMON_SVNT_BUILD_DLL */
#else /* SIMPLECOMMON_SVNT_HAS_DLL == 1 */
#  define SIMPLECOMMON_SVNT_Export
#  define SIMPLECOMMON_SVNT_SINGLETON_DECLARATION(T)
#  define SIMPLECOMMON_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* SIMPLECOMMON_SVNT_HAS_DLL == 1 */

// Set SIMPLECOMMON_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (SIMPLECOMMON_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define SIMPLECOMMON_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define SIMPLECOMMON_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !SIMPLECOMMON_SVNT_NTRACE */

#if (SIMPLECOMMON_SVNT_NTRACE == 1)
#  define SIMPLECOMMON_SVNT_TRACE(X)
#else /* (SIMPLECOMMON_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define SIMPLECOMMON_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (SIMPLECOMMON_SVNT_NTRACE == 1) */

#endif /* SIMPLECOMMON_SVNT_EXPORT_H */

// End of auto generated file.
