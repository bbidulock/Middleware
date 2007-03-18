
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl ATTRIBUTES_STUB
// ------------------------------
#ifndef ATTRIBUTES_STUB_EXPORT_H
#define ATTRIBUTES_STUB_EXPORT_H

#include "ace/config-all.h"

#if !defined (ATTRIBUTES_STUB_HAS_DLL)
#  define ATTRIBUTES_STUB_HAS_DLL 1
#endif /* ! ATTRIBUTES_STUB_HAS_DLL */

#if defined (ATTRIBUTES_STUB_HAS_DLL) && (ATTRIBUTES_STUB_HAS_DLL == 1)
#  if defined (ATTRIBUTES_STUB_BUILD_DLL)
#    define ATTRIBUTES_STUB_Export ACE_Proper_Export_Flag
#    define ATTRIBUTES_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ATTRIBUTES_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ATTRIBUTES_STUB_BUILD_DLL */
#    define ATTRIBUTES_STUB_Export ACE_Proper_Import_Flag
#    define ATTRIBUTES_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ATTRIBUTES_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ATTRIBUTES_STUB_BUILD_DLL */
#else /* ATTRIBUTES_STUB_HAS_DLL == 1 */
#  define ATTRIBUTES_STUB_Export
#  define ATTRIBUTES_STUB_SINGLETON_DECLARATION(T)
#  define ATTRIBUTES_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ATTRIBUTES_STUB_HAS_DLL == 1 */

// Set ATTRIBUTES_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (ATTRIBUTES_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define ATTRIBUTES_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define ATTRIBUTES_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !ATTRIBUTES_STUB_NTRACE */

#if (ATTRIBUTES_STUB_NTRACE == 1)
#  define ATTRIBUTES_STUB_TRACE(X)
#else /* (ATTRIBUTES_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define ATTRIBUTES_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (ATTRIBUTES_STUB_NTRACE == 1) */

#endif /* ATTRIBUTES_STUB_EXPORT_H */

// End of auto generated file.
