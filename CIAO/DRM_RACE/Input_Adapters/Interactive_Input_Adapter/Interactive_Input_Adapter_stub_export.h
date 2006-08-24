
// -*- C++ -*-
// Interactive_Input_Adapter_stub_export.h,v 1.1 2005/09/06 19:57:22 wotte Exp
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl INTERACTIVE_INPUT_ADAPTER_STUB
// ------------------------------
#ifndef INTERACTIVE_INPUT_ADAPTER_STUB_EXPORT_H
#define INTERACTIVE_INPUT_ADAPTER_STUB_EXPORT_H

#include "ace/config-all.h"

#if !defined (INTERACTIVE_INPUT_ADAPTER_STUB_HAS_DLL)
#  define INTERACTIVE_INPUT_ADAPTER_STUB_HAS_DLL 1
#endif /* ! INTERACTIVE_INPUT_ADAPTER_STUB_HAS_DLL */

#if defined (INTERACTIVE_INPUT_ADAPTER_STUB_HAS_DLL) && (INTERACTIVE_INPUT_ADAPTER_STUB_HAS_DLL == 1)
#  if defined (INTERACTIVE_INPUT_ADAPTER_STUB_BUILD_DLL)
#    define INTERACTIVE_INPUT_ADAPTER_STUB_Export ACE_Proper_Export_Flag
#    define INTERACTIVE_INPUT_ADAPTER_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define INTERACTIVE_INPUT_ADAPTER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* INTERACTIVE_INPUT_ADAPTER_STUB_BUILD_DLL */
#    define INTERACTIVE_INPUT_ADAPTER_STUB_Export ACE_Proper_Import_Flag
#    define INTERACTIVE_INPUT_ADAPTER_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define INTERACTIVE_INPUT_ADAPTER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* INTERACTIVE_INPUT_ADAPTER_STUB_BUILD_DLL */
#else /* INTERACTIVE_INPUT_ADAPTER_STUB_HAS_DLL == 1 */
#  define INTERACTIVE_INPUT_ADAPTER_STUB_Export
#  define INTERACTIVE_INPUT_ADAPTER_STUB_SINGLETON_DECLARATION(T)
#  define INTERACTIVE_INPUT_ADAPTER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* INTERACTIVE_INPUT_ADAPTER_STUB_HAS_DLL == 1 */

// Set INTERACTIVE_INPUT_ADAPTER_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (INTERACTIVE_INPUT_ADAPTER_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define INTERACTIVE_INPUT_ADAPTER_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define INTERACTIVE_INPUT_ADAPTER_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !INTERACTIVE_INPUT_ADAPTER_STUB_NTRACE */

#if (INTERACTIVE_INPUT_ADAPTER_STUB_NTRACE == 1)
#  define INTERACTIVE_INPUT_ADAPTER_STUB_TRACE(X)
#else /* (INTERACTIVE_INPUT_ADAPTER_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define INTERACTIVE_INPUT_ADAPTER_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (INTERACTIVE_INPUT_ADAPTER_STUB_NTRACE == 1) */

#endif /* INTERACTIVE_INPUT_ADAPTER_STUB_EXPORT_H */

// End of auto generated file.
