
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl Plan_Launcher_Base_Impl
// ------------------------------
#ifndef PLAN_LAUNCHER_BASE_IMPL_EXPORT_H
#define PLAN_LAUNCHER_BASE_IMPL_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (PLAN_LAUNCHER_BASE_IMPL_HAS_DLL)
#  define PLAN_LAUNCHER_BASE_IMPL_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && PLAN_LAUNCHER_BASE_IMPL_HAS_DLL */

#if !defined (PLAN_LAUNCHER_BASE_IMPL_HAS_DLL)
#  define PLAN_LAUNCHER_BASE_IMPL_HAS_DLL 1
#endif /* ! PLAN_LAUNCHER_BASE_IMPL_HAS_DLL */

#if defined (PLAN_LAUNCHER_BASE_IMPL_HAS_DLL) && (PLAN_LAUNCHER_BASE_IMPL_HAS_DLL == 1)
#  if defined (PLAN_LAUNCHER_BASE_IMPL_BUILD_DLL)
#    define Plan_Launcher_Base_Impl_Export ACE_Proper_Export_Flag
#    define PLAN_LAUNCHER_BASE_IMPL_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define PLAN_LAUNCHER_BASE_IMPL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* PLAN_LAUNCHER_BASE_IMPL_BUILD_DLL */
#    define Plan_Launcher_Base_Impl_Export ACE_Proper_Import_Flag
#    define PLAN_LAUNCHER_BASE_IMPL_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define PLAN_LAUNCHER_BASE_IMPL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* PLAN_LAUNCHER_BASE_IMPL_BUILD_DLL */
#else /* PLAN_LAUNCHER_BASE_IMPL_HAS_DLL == 1 */
#  define Plan_Launcher_Base_Impl_Export
#  define PLAN_LAUNCHER_BASE_IMPL_SINGLETON_DECLARATION(T)
#  define PLAN_LAUNCHER_BASE_IMPL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* PLAN_LAUNCHER_BASE_IMPL_HAS_DLL == 1 */

// Set PLAN_LAUNCHER_BASE_IMPL_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (PLAN_LAUNCHER_BASE_IMPL_NTRACE)
#  if (ACE_NTRACE == 1)
#    define PLAN_LAUNCHER_BASE_IMPL_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define PLAN_LAUNCHER_BASE_IMPL_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !PLAN_LAUNCHER_BASE_IMPL_NTRACE */

#if (PLAN_LAUNCHER_BASE_IMPL_NTRACE == 1)
#  define PLAN_LAUNCHER_BASE_IMPL_TRACE(X)
#else /* (PLAN_LAUNCHER_BASE_IMPL_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define PLAN_LAUNCHER_BASE_IMPL_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (PLAN_LAUNCHER_BASE_IMPL_NTRACE == 1) */

#endif /* PLAN_LAUNCHER_BASE_IMPL_EXPORT_H */

// End of auto generated file.
