// $Id$
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl ROBOTMANAGER_STUB
// ------------------------------
#ifndef ROBOTMANAGER_STUB_EXPORT_H
#define ROBOTMANAGER_STUB_EXPORT_H

#include "ace/config-all.h"

#if !defined (ROBOTMANAGER_STUB_HAS_DLL)
#  define ROBOTMANAGER_STUB_HAS_DLL 1
#endif /* ! ROBOTMANAGER_STUB_HAS_DLL */

#if defined (ROBOTMANAGER_STUB_HAS_DLL) && (ROBOTMANAGER_STUB_HAS_DLL == 1)
#  if defined (ROBOTMANAGER_STUB_BUILD_DLL)
#    define ROBOTMANAGER_STUB_Export ACE_Proper_Export_Flag
#    define ROBOTMANAGER_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ROBOTMANAGER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ROBOTMANAGER_STUB_BUILD_DLL */
#    define ROBOTMANAGER_STUB_Export ACE_Proper_Import_Flag
#    define ROBOTMANAGER_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ROBOTMANAGER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ROBOTMANAGER_STUB_BUILD_DLL */
#else /* ROBOTMANAGER_STUB_HAS_DLL == 1 */
#  define ROBOTMANAGER_STUB_Export
#  define ROBOTMANAGER_STUB_SINGLETON_DECLARATION(T)
#  define ROBOTMANAGER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ROBOTMANAGER_STUB_HAS_DLL == 1 */

// Set ROBOTMANAGER_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (ROBOTMANAGER_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define ROBOTMANAGER_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define ROBOTMANAGER_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !ROBOTMANAGER_STUB_NTRACE */

#if (ROBOTMANAGER_STUB_NTRACE == 1)
#  define ROBOTMANAGER_STUB_TRACE(X)
#else /* (ROBOTMANAGER_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define ROBOTMANAGER_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (ROBOTMANAGER_STUB_NTRACE == 1) */

#endif /* ROBOTMANAGER_STUB_EXPORT_H */

// End of auto generated file.
