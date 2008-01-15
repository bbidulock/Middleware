
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl CALLBACK_STUB
// ------------------------------
#ifndef CALLBACK_STUB_EXPORT_H
#define CALLBACK_STUB_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CALLBACK_STUB_HAS_DLL)
#  define CALLBACK_STUB_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CALLBACK_STUB_HAS_DLL */

#if !defined (CALLBACK_STUB_HAS_DLL)
#  define CALLBACK_STUB_HAS_DLL 1
#endif /* ! CALLBACK_STUB_HAS_DLL */

#if defined (CALLBACK_STUB_HAS_DLL) && (CALLBACK_STUB_HAS_DLL == 1)
#  if defined (CALLBACK_STUB_BUILD_DLL)
#    define CALLBACK_STUB_Export ACE_Proper_Export_Flag
#    define CALLBACK_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CALLBACK_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CALLBACK_STUB_BUILD_DLL */
#    define CALLBACK_STUB_Export ACE_Proper_Import_Flag
#    define CALLBACK_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CALLBACK_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CALLBACK_STUB_BUILD_DLL */
#else /* CALLBACK_STUB_HAS_DLL == 1 */
#  define CALLBACK_STUB_Export
#  define CALLBACK_STUB_SINGLETON_DECLARATION(T)
#  define CALLBACK_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CALLBACK_STUB_HAS_DLL == 1 */

// Set CALLBACK_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CALLBACK_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CALLBACK_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CALLBACK_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CALLBACK_STUB_NTRACE */

#if (CALLBACK_STUB_NTRACE == 1)
#  define CALLBACK_STUB_TRACE(X)
#else /* (CALLBACK_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CALLBACK_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CALLBACK_STUB_NTRACE == 1) */

#endif /* CALLBACK_STUB_EXPORT_H */

// End of auto generated file.
