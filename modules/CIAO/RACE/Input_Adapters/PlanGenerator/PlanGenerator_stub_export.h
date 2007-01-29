
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl PLANGENERATOR_STUB
// ------------------------------
#ifndef PLANGENERATOR_STUB_EXPORT_H
#define PLANGENERATOR_STUB_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (PLANGENERATOR_STUB_HAS_DLL)
#  define PLANGENERATOR_STUB_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && PLANGENERATOR_STUB_HAS_DLL */

#if !defined (PLANGENERATOR_STUB_HAS_DLL)
#  define PLANGENERATOR_STUB_HAS_DLL 1
#endif /* ! PLANGENERATOR_STUB_HAS_DLL */

#if defined (PLANGENERATOR_STUB_HAS_DLL) && (PLANGENERATOR_STUB_HAS_DLL == 1)
#  if defined (PLANGENERATOR_STUB_BUILD_DLL)
#    define PLANGENERATOR_STUB_Export ACE_Proper_Export_Flag
#    define PLANGENERATOR_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define PLANGENERATOR_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* PLANGENERATOR_STUB_BUILD_DLL */
#    define PLANGENERATOR_STUB_Export ACE_Proper_Import_Flag
#    define PLANGENERATOR_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define PLANGENERATOR_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* PLANGENERATOR_STUB_BUILD_DLL */
#else /* PLANGENERATOR_STUB_HAS_DLL == 1 */
#  define PLANGENERATOR_STUB_Export
#  define PLANGENERATOR_STUB_SINGLETON_DECLARATION(T)
#  define PLANGENERATOR_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* PLANGENERATOR_STUB_HAS_DLL == 1 */

// Set PLANGENERATOR_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (PLANGENERATOR_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define PLANGENERATOR_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define PLANGENERATOR_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !PLANGENERATOR_STUB_NTRACE */

#if (PLANGENERATOR_STUB_NTRACE == 1)
#  define PLANGENERATOR_STUB_TRACE(X)
#else /* (PLANGENERATOR_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define PLANGENERATOR_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (PLANGENERATOR_STUB_NTRACE == 1) */

#endif /* PLANGENERATOR_STUB_EXPORT_H */

// End of auto generated file.
