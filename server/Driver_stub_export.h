
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl DRIVER_STUB
// ------------------------------
#ifndef DRIVER_STUB_EXPORT_H
#define DRIVER_STUB_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (DRIVER_STUB_HAS_DLL)
#  define DRIVER_STUB_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && DRIVER_STUB_HAS_DLL */

#if !defined (DRIVER_STUB_HAS_DLL)
#  define DRIVER_STUB_HAS_DLL 1
#endif /* ! DRIVER_STUB_HAS_DLL */

#if defined (DRIVER_STUB_HAS_DLL) && (DRIVER_STUB_HAS_DLL == 1)
#  if defined (DRIVER_STUB_BUILD_DLL)
#    define DRIVER_STUB_Export ACE_Proper_Export_Flag
#    define DRIVER_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define DRIVER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* DRIVER_STUB_BUILD_DLL */
#    define DRIVER_STUB_Export ACE_Proper_Import_Flag
#    define DRIVER_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define DRIVER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* DRIVER_STUB_BUILD_DLL */
#else /* DRIVER_STUB_HAS_DLL == 1 */
#  define DRIVER_STUB_Export
#  define DRIVER_STUB_SINGLETON_DECLARATION(T)
#  define DRIVER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* DRIVER_STUB_HAS_DLL == 1 */

// Set DRIVER_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (DRIVER_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define DRIVER_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define DRIVER_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !DRIVER_STUB_NTRACE */

#if (DRIVER_STUB_NTRACE == 1)
#  define DRIVER_STUB_TRACE(X)
#else /* (DRIVER_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define DRIVER_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (DRIVER_STUB_NTRACE == 1) */

#endif /* DRIVER_STUB_EXPORT_H */

// End of auto generated file.
