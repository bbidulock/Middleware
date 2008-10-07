
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl SIMPLEPROVIDER_STUB
// ------------------------------
#ifndef SIMPLEPROVIDER_STUB_EXPORT_H
#define SIMPLEPROVIDER_STUB_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (SIMPLEPROVIDER_STUB_HAS_DLL)
#  define SIMPLEPROVIDER_STUB_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && SIMPLEPROVIDER_STUB_HAS_DLL */

#if !defined (SIMPLEPROVIDER_STUB_HAS_DLL)
#  define SIMPLEPROVIDER_STUB_HAS_DLL 1
#endif /* ! SIMPLEPROVIDER_STUB_HAS_DLL */

#if defined (SIMPLEPROVIDER_STUB_HAS_DLL) && (SIMPLEPROVIDER_STUB_HAS_DLL == 1)
#  if defined (SIMPLEPROVIDER_STUB_BUILD_DLL)
#    define SIMPLEPROVIDER_STUB_Export ACE_Proper_Export_Flag
#    define SIMPLEPROVIDER_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define SIMPLEPROVIDER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* SIMPLEPROVIDER_STUB_BUILD_DLL */
#    define SIMPLEPROVIDER_STUB_Export ACE_Proper_Import_Flag
#    define SIMPLEPROVIDER_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define SIMPLEPROVIDER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* SIMPLEPROVIDER_STUB_BUILD_DLL */
#else /* SIMPLEPROVIDER_STUB_HAS_DLL == 1 */
#  define SIMPLEPROVIDER_STUB_Export
#  define SIMPLEPROVIDER_STUB_SINGLETON_DECLARATION(T)
#  define SIMPLEPROVIDER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* SIMPLEPROVIDER_STUB_HAS_DLL == 1 */

// Set SIMPLEPROVIDER_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (SIMPLEPROVIDER_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define SIMPLEPROVIDER_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define SIMPLEPROVIDER_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !SIMPLEPROVIDER_STUB_NTRACE */

#if (SIMPLEPROVIDER_STUB_NTRACE == 1)
#  define SIMPLEPROVIDER_STUB_TRACE(X)
#else /* (SIMPLEPROVIDER_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define SIMPLEPROVIDER_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (SIMPLEPROVIDER_STUB_NTRACE == 1) */

#endif /* SIMPLEPROVIDER_STUB_EXPORT_H */

// End of auto generated file.
