
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl RTEVENTSERVICE_EXEC
// ------------------------------
#ifndef RTEVENTSERVICE_EXEC_EXPORT_H
#define RTEVENTSERVICE_EXEC_EXPORT_H

#include "ace/config-all.h"

#if !defined (RTEVENTSERVICE_EXEC_HAS_DLL)
#  define RTEVENTSERVICE_EXEC_HAS_DLL 1
#endif /* ! RTEVENTSERVICE_EXEC_HAS_DLL */

#if defined (RTEVENTSERVICE_EXEC_HAS_DLL) && (RTEVENTSERVICE_EXEC_HAS_DLL == 1)
#  if defined (RTEVENTSERVICE_EXEC_BUILD_DLL)
#    define RTEVENTSERVICE_EXEC_Export ACE_Proper_Export_Flag
#    define RTEVENTSERVICE_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define RTEVENTSERVICE_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* RTEVENTSERVICE_EXEC_BUILD_DLL */
#    define RTEVENTSERVICE_EXEC_Export ACE_Proper_Import_Flag
#    define RTEVENTSERVICE_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define RTEVENTSERVICE_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* RTEVENTSERVICE_EXEC_BUILD_DLL */
#else /* RTEVENTSERVICE_EXEC_HAS_DLL == 1 */
#  define RTEVENTSERVICE_EXEC_Export
#  define RTEVENTSERVICE_EXEC_SINGLETON_DECLARATION(T)
#  define RTEVENTSERVICE_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* RTEVENTSERVICE_EXEC_HAS_DLL == 1 */

// Set RTEVENTSERVICE_EXEC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (RTEVENTSERVICE_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define RTEVENTSERVICE_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define RTEVENTSERVICE_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !RTEVENTSERVICE_EXEC_NTRACE */

#if (RTEVENTSERVICE_EXEC_NTRACE == 1)
#  define RTEVENTSERVICE_EXEC_TRACE(X)
#else /* (RTEVENTSERVICE_EXEC_NTRACE == 1) */
#  define RTEVENTSERVICE_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#endif /* (RTEVENTSERVICE_EXEC_NTRACE == 1) */

#endif /* RTEVENTSERVICE_EXEC_EXPORT_H */

// End of auto generated file.
