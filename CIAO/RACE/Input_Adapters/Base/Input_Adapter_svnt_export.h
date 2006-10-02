
// -*- C++ -*-
// Input_Adapter_svnt_export.h,v 1.1 2005/09/06 19:57:22 wotte Exp
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl INPUT_ADAPTER_SVNT
// ------------------------------
#ifndef INPUT_ADAPTER_SVNT_EXPORT_H
#define INPUT_ADAPTER_SVNT_EXPORT_H

#include "ace/config-all.h"

#if !defined (INPUT_ADAPTER_SVNT_HAS_DLL)
#  define INPUT_ADAPTER_SVNT_HAS_DLL 1
#endif /* ! INPUT_ADAPTER_SVNT_HAS_DLL */

#if defined (INPUT_ADAPTER_SVNT_HAS_DLL) && (INPUT_ADAPTER_SVNT_HAS_DLL == 1)
#  if defined (INPUT_ADAPTER_SVNT_BUILD_DLL)
#    define INPUT_ADAPTER_SVNT_Export ACE_Proper_Export_Flag
#    define INPUT_ADAPTER_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define INPUT_ADAPTER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* INPUT_ADAPTER_SVNT_BUILD_DLL */
#    define INPUT_ADAPTER_SVNT_Export ACE_Proper_Import_Flag
#    define INPUT_ADAPTER_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define INPUT_ADAPTER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* INPUT_ADAPTER_SVNT_BUILD_DLL */
#else /* INPUT_ADAPTER_SVNT_HAS_DLL == 1 */
#  define INPUT_ADAPTER_SVNT_Export
#  define INPUT_ADAPTER_SVNT_SINGLETON_DECLARATION(T)
#  define INPUT_ADAPTER_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* INPUT_ADAPTER_SVNT_HAS_DLL == 1 */

// Set INPUT_ADAPTER_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (INPUT_ADAPTER_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define INPUT_ADAPTER_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define INPUT_ADAPTER_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !INPUT_ADAPTER_SVNT_NTRACE */

#if (INPUT_ADAPTER_SVNT_NTRACE == 1)
#  define INPUT_ADAPTER_SVNT_TRACE(X)
#else /* (INPUT_ADAPTER_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define INPUT_ADAPTER_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (INPUT_ADAPTER_SVNT_NTRACE == 1) */

#endif /* INPUT_ADAPTER_SVNT_EXPORT_H */

// End of auto generated file.
