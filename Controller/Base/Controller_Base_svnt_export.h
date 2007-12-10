
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl CONTROLLER_BASE_SVNT
// ------------------------------
#ifndef CONTROLLER_BASE_SVNT_EXPORT_H
#define CONTROLLER_BASE_SVNT_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CONTROLLER_BASE_SVNT_HAS_DLL)
#  define CONTROLLER_BASE_SVNT_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CONTROLLER_BASE_SVNT_HAS_DLL */

#if !defined (CONTROLLER_BASE_SVNT_HAS_DLL)
#  define CONTROLLER_BASE_SVNT_HAS_DLL 1
#endif /* ! CONTROLLER_BASE_SVNT_HAS_DLL */

#if defined (CONTROLLER_BASE_SVNT_HAS_DLL) && (CONTROLLER_BASE_SVNT_HAS_DLL == 1)
#  if defined (CONTROLLER_BASE_SVNT_BUILD_DLL)
#    define CONTROLLER_BASE_SVNT_Export ACE_Proper_Export_Flag
#    define CONTROLLER_BASE_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CONTROLLER_BASE_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CONTROLLER_BASE_SVNT_BUILD_DLL */
#    define CONTROLLER_BASE_SVNT_Export ACE_Proper_Import_Flag
#    define CONTROLLER_BASE_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CONTROLLER_BASE_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CONTROLLER_BASE_SVNT_BUILD_DLL */
#else /* CONTROLLER_BASE_SVNT_HAS_DLL == 1 */
#  define CONTROLLER_BASE_SVNT_Export
#  define CONTROLLER_BASE_SVNT_SINGLETON_DECLARATION(T)
#  define CONTROLLER_BASE_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CONTROLLER_BASE_SVNT_HAS_DLL == 1 */

// Set CONTROLLER_BASE_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CONTROLLER_BASE_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CONTROLLER_BASE_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CONTROLLER_BASE_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CONTROLLER_BASE_SVNT_NTRACE */

#if (CONTROLLER_BASE_SVNT_NTRACE == 1)
#  define CONTROLLER_BASE_SVNT_TRACE(X)
#else /* (CONTROLLER_BASE_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CONTROLLER_BASE_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CONTROLLER_BASE_SVNT_NTRACE == 1) */

#endif /* CONTROLLER_BASE_SVNT_EXPORT_H */

// End of auto generated file.
