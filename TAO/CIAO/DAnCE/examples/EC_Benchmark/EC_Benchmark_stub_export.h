
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl EC_BENCHMARK_STUB
// ------------------------------
#ifndef EC_BENCHMARK_STUB_EXPORT_H
#define EC_BENCHMARK_STUB_EXPORT_H

#include "ace/config-all.h"

#if !defined (EC_BENCHMARK_STUB_HAS_DLL)
#  define EC_BENCHMARK_STUB_HAS_DLL 1
#endif /* ! EC_BENCHMARK_STUB_HAS_DLL */

#if defined (EC_BENCHMARK_STUB_HAS_DLL) && (EC_BENCHMARK_STUB_HAS_DLL == 1)
#  if defined (EC_BENCHMARK_STUB_BUILD_DLL)
#    define EC_BENCHMARK_STUB_Export ACE_Proper_Export_Flag
#    define EC_BENCHMARK_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define EC_BENCHMARK_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* EC_BENCHMARK_STUB_BUILD_DLL */
#    define EC_BENCHMARK_STUB_Export ACE_Proper_Import_Flag
#    define EC_BENCHMARK_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define EC_BENCHMARK_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* EC_BENCHMARK_STUB_BUILD_DLL */
#else /* EC_BENCHMARK_STUB_HAS_DLL == 1 */
#  define EC_BENCHMARK_STUB_Export
#  define EC_BENCHMARK_STUB_SINGLETON_DECLARATION(T)
#  define EC_BENCHMARK_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* EC_BENCHMARK_STUB_HAS_DLL == 1 */

// Set EC_BENCHMARK_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (EC_BENCHMARK_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define EC_BENCHMARK_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define EC_BENCHMARK_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !EC_BENCHMARK_STUB_NTRACE */

#if (EC_BENCHMARK_STUB_NTRACE == 1)
#  define EC_BENCHMARK_STUB_TRACE(X)
#else /* (EC_BENCHMARK_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define EC_BENCHMARK_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (EC_BENCHMARK_STUB_NTRACE == 1) */

#endif /* EC_BENCHMARK_STUB_EXPORT_H */

// End of auto generated file.
