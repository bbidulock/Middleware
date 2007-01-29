
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl INHERITANCE_STUB
// ------------------------------
#ifndef INHERITANCE_STUB_EXPORT_H
#define INHERITANCE_STUB_EXPORT_H

#include "ace/config-all.h"

#if !defined (INHERITANCE_STUB_HAS_DLL)
#  define INHERITANCE_STUB_HAS_DLL 1
#endif /* ! INHERITANCE_STUB_HAS_DLL */

#if defined (INHERITANCE_STUB_HAS_DLL) && (INHERITANCE_STUB_HAS_DLL == 1)
#  if defined (INHERITANCE_STUB_BUILD_DLL)
#    define INHERITANCE_STUB_Export ACE_Proper_Export_Flag
#    define INHERITANCE_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define INHERITANCE_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* INHERITANCE_STUB_BUILD_DLL */
#    define INHERITANCE_STUB_Export ACE_Proper_Import_Flag
#    define INHERITANCE_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define INHERITANCE_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* INHERITANCE_STUB_BUILD_DLL */
#else /* INHERITANCE_STUB_HAS_DLL == 1 */
#  define INHERITANCE_STUB_Export
#  define INHERITANCE_STUB_SINGLETON_DECLARATION(T)
#  define INHERITANCE_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* INHERITANCE_STUB_HAS_DLL == 1 */

// Set INHERITANCE_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (INHERITANCE_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define INHERITANCE_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define INHERITANCE_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !INHERITANCE_STUB_NTRACE */

#if (INHERITANCE_STUB_NTRACE == 1)
#  define INHERITANCE_STUB_TRACE(X)
#else /* (INHERITANCE_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define INHERITANCE_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (INHERITANCE_STUB_NTRACE == 1) */

#endif /* INHERITANCE_STUB_EXPORT_H */

// End of auto generated file.
