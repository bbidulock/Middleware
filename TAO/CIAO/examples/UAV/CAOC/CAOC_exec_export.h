
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl CAOC_EXEC
// ------------------------------
#ifndef CAOC_EXEC_EXPORT_H
#define CAOC_EXEC_EXPORT_H

#include "ace/config-all.h"

#if !defined (CAOC_EXEC_HAS_DLL)
#  define CAOC_EXEC_HAS_DLL 1
#endif /* ! CAOC_EXEC_HAS_DLL */

#if defined (CAOC_EXEC_HAS_DLL) && (CAOC_EXEC_HAS_DLL == 1)
#  if defined (CAOC_EXEC_BUILD_DLL)
#    define CAOC_EXEC_Export ACE_Proper_Export_Flag
#    define CAOC_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CAOC_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CAOC_EXEC_BUILD_DLL */
#    define CAOC_EXEC_Export ACE_Proper_Import_Flag
#    define CAOC_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CAOC_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CAOC_EXEC_BUILD_DLL */
#else /* CAOC_EXEC_HAS_DLL == 1 */
#  define CAOC_EXEC_Export
#  define CAOC_EXEC_SINGLETON_DECLARATION(T)
#  define CAOC_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CAOC_EXEC_HAS_DLL == 1 */

// Set CAOC_EXEC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CAOC_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CAOC_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CAOC_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CAOC_EXEC_NTRACE */

#if (CAOC_EXEC_NTRACE == 1)
#  define CAOC_EXEC_TRACE(X)
#else /* (CAOC_EXEC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CAOC_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CAOC_EXEC_NTRACE == 1) */

#endif /* CAOC_EXEC_EXPORT_H */

// End of auto generated file.
