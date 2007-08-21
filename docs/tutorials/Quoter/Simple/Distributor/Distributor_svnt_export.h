
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl DISTRIBUTOR_SVNT
// ------------------------------
#ifndef DISTRIBUTOR_SVNT_EXPORT_H
#define DISTRIBUTOR_SVNT_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (DISTRIBUTOR_SVNT_HAS_DLL)
#  define DISTRIBUTOR_SVNT_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && DISTRIBUTOR_SVNT_HAS_DLL */

#if !defined (DISTRIBUTOR_SVNT_HAS_DLL)
#  define DISTRIBUTOR_SVNT_HAS_DLL 1
#endif /* ! DISTRIBUTOR_SVNT_HAS_DLL */

#if defined (DISTRIBUTOR_SVNT_HAS_DLL) && (DISTRIBUTOR_SVNT_HAS_DLL == 1)
#  if defined (DISTRIBUTOR_SVNT_BUILD_DLL)
#    define DISTRIBUTOR_SVNT_Export ACE_Proper_Export_Flag
#    define DISTRIBUTOR_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define DISTRIBUTOR_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* DISTRIBUTOR_SVNT_BUILD_DLL */
#    define DISTRIBUTOR_SVNT_Export ACE_Proper_Import_Flag
#    define DISTRIBUTOR_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define DISTRIBUTOR_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* DISTRIBUTOR_SVNT_BUILD_DLL */
#else /* DISTRIBUTOR_SVNT_HAS_DLL == 1 */
#  define DISTRIBUTOR_SVNT_Export
#  define DISTRIBUTOR_SVNT_SINGLETON_DECLARATION(T)
#  define DISTRIBUTOR_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* DISTRIBUTOR_SVNT_HAS_DLL == 1 */

// Set DISTRIBUTOR_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (DISTRIBUTOR_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define DISTRIBUTOR_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define DISTRIBUTOR_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !DISTRIBUTOR_SVNT_NTRACE */

#if (DISTRIBUTOR_SVNT_NTRACE == 1)
#  define DISTRIBUTOR_SVNT_TRACE(X)
#else /* (DISTRIBUTOR_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define DISTRIBUTOR_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (DISTRIBUTOR_SVNT_NTRACE == 1) */

#endif /* DISTRIBUTOR_SVNT_EXPORT_H */

// End of auto generated file.
