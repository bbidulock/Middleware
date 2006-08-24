
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl OUTPUT_MANAGER_SVNT
// ------------------------------
#ifndef OUTPUT_MANAGER_SVNT_EXPORT_H
#define OUTPUT_MANAGER_SVNT_EXPORT_H

#include "ace/config-all.h"

#if !defined (OUTPUT_MANAGER_SVNT_HAS_DLL)
#  define OUTPUT_MANAGER_SVNT_HAS_DLL 1
#endif /* ! OUTPUT_MANAGER_SVNT_HAS_DLL */

#if defined (OUTPUT_MANAGER_SVNT_HAS_DLL) && (OUTPUT_MANAGER_SVNT_HAS_DLL == 1)
#  if defined (OUTPUT_MANAGER_SVNT_BUILD_DLL)
#    define OUTPUT_MANAGER_SVNT_Export ACE_Proper_Export_Flag
#    define OUTPUT_MANAGER_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define OUTPUT_MANAGER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* OUTPUT_MANAGER_SVNT_BUILD_DLL */
#    define OUTPUT_MANAGER_SVNT_Export ACE_Proper_Import_Flag
#    define OUTPUT_MANAGER_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define OUTPUT_MANAGER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* OUTPUT_MANAGER_SVNT_BUILD_DLL */
#else /* OUTPUT_MANAGER_SVNT_HAS_DLL == 1 */
#  define OUTPUT_MANAGER_SVNT_Export
#  define OUTPUT_MANAGER_SVNT_SINGLETON_DECLARATION(T)
#  define OUTPUT_MANAGER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* OUTPUT_MANAGER_SVNT_HAS_DLL == 1 */

// Set OUTPUT_MANAGER_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (OUTPUT_MANAGER_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define OUTPUT_MANAGER_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define OUTPUT_MANAGER_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !OUTPUT_MANAGER_SVNT_NTRACE */

#if (OUTPUT_MANAGER_SVNT_NTRACE == 1)
#  define OUTPUT_MANAGER_SVNT_TRACE(X)
#else /* (OUTPUT_MANAGER_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define OUTPUT_MANAGER_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (OUTPUT_MANAGER_SVNT_NTRACE == 1) */

#endif /* OUTPUT_MANAGER_SVNT_EXPORT_H */

// End of auto generated file.
