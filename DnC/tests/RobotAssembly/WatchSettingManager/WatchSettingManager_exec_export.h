// $Id$
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl WATCHSETTINGMANAGER_EXEC
// ------------------------------
#ifndef WATCHSETTINGMANAGER_EXEC_EXPORT_H
#define WATCHSETTINGMANAGER_EXEC_EXPORT_H

#include "ace/config-all.h"

#if !defined (WATCHSETTINGMANAGER_EXEC_HAS_DLL)
#  define WATCHSETTINGMANAGER_EXEC_HAS_DLL 1
#endif /* ! WATCHSETTINGMANAGER_EXEC_HAS_DLL */

#if defined (WATCHSETTINGMANAGER_EXEC_HAS_DLL) && (WATCHSETTINGMANAGER_EXEC_HAS_DLL == 1)
#  if defined (WATCHSETTINGMANAGER_EXEC_BUILD_DLL)
#    define WATCHSETTINGMANAGER_EXEC_Export ACE_Proper_Export_Flag
#    define WATCHSETTINGMANAGER_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define WATCHSETTINGMANAGER_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* WATCHSETTINGMANAGER_EXEC_BUILD_DLL */
#    define WATCHSETTINGMANAGER_EXEC_Export ACE_Proper_Import_Flag
#    define WATCHSETTINGMANAGER_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define WATCHSETTINGMANAGER_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* WATCHSETTINGMANAGER_EXEC_BUILD_DLL */
#else /* WATCHSETTINGMANAGER_EXEC_HAS_DLL == 1 */
#  define WATCHSETTINGMANAGER_EXEC_Export
#  define WATCHSETTINGMANAGER_EXEC_SINGLETON_DECLARATION(T)
#  define WATCHSETTINGMANAGER_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* WATCHSETTINGMANAGER_EXEC_HAS_DLL == 1 */

// Set WATCHSETTINGMANAGER_EXEC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (WATCHSETTINGMANAGER_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define WATCHSETTINGMANAGER_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define WATCHSETTINGMANAGER_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !WATCHSETTINGMANAGER_EXEC_NTRACE */

#if (WATCHSETTINGMANAGER_EXEC_NTRACE == 1)
#  define WATCHSETTINGMANAGER_EXEC_TRACE(X)
#else /* (WATCHSETTINGMANAGER_EXEC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define WATCHSETTINGMANAGER_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (WATCHSETTINGMANAGER_EXEC_NTRACE == 1) */

#endif /* WATCHSETTINGMANAGER_EXEC_EXPORT_H */

// End of auto generated file.
