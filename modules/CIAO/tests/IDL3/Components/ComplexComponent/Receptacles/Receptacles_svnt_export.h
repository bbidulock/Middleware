
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl RECEPTACLES_SVNT
// ------------------------------
#ifndef RECEPTACLES_SVNT_EXPORT_H
#define RECEPTACLES_SVNT_EXPORT_H

#include "ace/config-all.h"

#if !defined (RECEPTACLES_SVNT_HAS_DLL)
#  define RECEPTACLES_SVNT_HAS_DLL 1
#endif /* ! RECEPTACLES_SVNT_HAS_DLL */

#if defined (RECEPTACLES_SVNT_HAS_DLL) && (RECEPTACLES_SVNT_HAS_DLL == 1)
#  if defined (RECEPTACLES_SVNT_BUILD_DLL)
#    define RECEPTACLES_SVNT_Export ACE_Proper_Export_Flag
#    define RECEPTACLES_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define RECEPTACLES_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* RECEPTACLES_SVNT_BUILD_DLL */
#    define RECEPTACLES_SVNT_Export ACE_Proper_Import_Flag
#    define RECEPTACLES_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define RECEPTACLES_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* RECEPTACLES_SVNT_BUILD_DLL */
#else /* RECEPTACLES_SVNT_HAS_DLL == 1 */
#  define RECEPTACLES_SVNT_Export
#  define RECEPTACLES_SVNT_SINGLETON_DECLARATION(T)
#  define RECEPTACLES_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* RECEPTACLES_SVNT_HAS_DLL == 1 */

// Set RECEPTACLES_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (RECEPTACLES_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define RECEPTACLES_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define RECEPTACLES_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !RECEPTACLES_SVNT_NTRACE */

#if (RECEPTACLES_SVNT_NTRACE == 1)
#  define RECEPTACLES_SVNT_TRACE(X)
#else /* (RECEPTACLES_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define RECEPTACLES_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (RECEPTACLES_SVNT_NTRACE == 1) */

#endif /* RECEPTACLES_SVNT_EXPORT_H */

// End of auto generated file.
