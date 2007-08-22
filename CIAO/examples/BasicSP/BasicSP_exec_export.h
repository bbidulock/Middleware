
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s BASICSP_EXEC
// ------------------------------
#ifndef BASICSP_EXEC_EXPORT_H
#define BASICSP_EXEC_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (BASICSP_EXEC_HAS_DLL)
#  define BASICSP_EXEC_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && BASICSP_EXEC_HAS_DLL */

#if !defined (BASICSP_EXEC_HAS_DLL)
#  define BASICSP_EXEC_HAS_DLL 1
#endif /* ! BASICSP_EXEC_HAS_DLL */

#if defined (BASICSP_EXEC_HAS_DLL) && (BASICSP_EXEC_HAS_DLL == 1)
#  if defined (BASICSP_EXEC_BUILD_DLL)
#    define BASICSP_EXEC_Export ACE_Proper_Export_Flag
#    define BASICSP_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define BASICSP_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* BASICSP_EXEC_BUILD_DLL */
#    define BASICSP_EXEC_Export ACE_Proper_Import_Flag
#    define BASICSP_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define BASICSP_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* BASICSP_EXEC_BUILD_DLL */
#else /* BASICSP_EXEC_HAS_DLL == 1 */
#  define BASICSP_EXEC_Export
#  define BASICSP_EXEC_SINGLETON_DECLARATION(T)
#  define BASICSP_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* BASICSP_EXEC_HAS_DLL == 1 */

// Set BASICSP_EXEC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (BASICSP_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define BASICSP_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define BASICSP_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !BASICSP_EXEC_NTRACE */

#if (BASICSP_EXEC_NTRACE == 1)
#  define BASICSP_EXEC_TRACE(X)
#else /* (BASICSP_EXEC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define BASICSP_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (BASICSP_EXEC_NTRACE == 1) */

#endif /* BASICSP_EXEC_EXPORT_H */

// End of auto generated file.
