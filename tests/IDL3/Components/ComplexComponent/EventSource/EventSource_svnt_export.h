
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl EVENTSOURCE_SVNT
// ------------------------------
#ifndef EVENTSOURCE_SVNT_EXPORT_H
#define EVENTSOURCE_SVNT_EXPORT_H

#include "ace/config-all.h"

#if !defined (EVENTSOURCE_SVNT_HAS_DLL)
#  define EVENTSOURCE_SVNT_HAS_DLL 1
#endif /* ! EVENTSOURCE_SVNT_HAS_DLL */

#if defined (EVENTSOURCE_SVNT_HAS_DLL) && (EVENTSOURCE_SVNT_HAS_DLL == 1)
#  if defined (EVENTSOURCE_SVNT_BUILD_DLL)
#    define EVENTSOURCE_SVNT_Export ACE_Proper_Export_Flag
#    define EVENTSOURCE_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define EVENTSOURCE_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* EVENTSOURCE_SVNT_BUILD_DLL */
#    define EVENTSOURCE_SVNT_Export ACE_Proper_Import_Flag
#    define EVENTSOURCE_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define EVENTSOURCE_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* EVENTSOURCE_SVNT_BUILD_DLL */
#else /* EVENTSOURCE_SVNT_HAS_DLL == 1 */
#  define EVENTSOURCE_SVNT_Export
#  define EVENTSOURCE_SVNT_SINGLETON_DECLARATION(T)
#  define EVENTSOURCE_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* EVENTSOURCE_SVNT_HAS_DLL == 1 */

// Set EVENTSOURCE_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (EVENTSOURCE_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define EVENTSOURCE_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define EVENTSOURCE_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !EVENTSOURCE_SVNT_NTRACE */

#if (EVENTSOURCE_SVNT_NTRACE == 1)
#  define EVENTSOURCE_SVNT_TRACE(X)
#else /* (EVENTSOURCE_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define EVENTSOURCE_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (EVENTSOURCE_SVNT_NTRACE == 1) */

#endif /* EVENTSOURCE_SVNT_EXPORT_H */

// End of auto generated file.
