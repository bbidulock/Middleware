
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s Config_Handlers
// ------------------------------
#ifndef CONFIG_HANDLERS_EXPORT_H
#define CONFIG_HANDLERS_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CONFIG_HANDLERS_HAS_DLL)
#  define CONFIG_HANDLERS_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CONFIG_HANDLERS_HAS_DLL */

#if !defined (CONFIG_HANDLERS_HAS_DLL)
#  define CONFIG_HANDLERS_HAS_DLL 1
#endif /* ! CONFIG_HANDLERS_HAS_DLL */

#if defined (CONFIG_HANDLERS_HAS_DLL) && (CONFIG_HANDLERS_HAS_DLL == 1)
#  if defined (CONFIG_HANDLERS_BUILD_DLL)
#    define Config_Handlers_Export ACE_Proper_Export_Flag
#    define CONFIG_HANDLERS_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CONFIG_HANDLERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CONFIG_HANDLERS_BUILD_DLL */
#    define Config_Handlers_Export ACE_Proper_Import_Flag
#    define CONFIG_HANDLERS_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CONFIG_HANDLERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CONFIG_HANDLERS_BUILD_DLL */
#else /* CONFIG_HANDLERS_HAS_DLL == 1 */
#  define Config_Handlers_Export
#  define CONFIG_HANDLERS_SINGLETON_DECLARATION(T)
#  define CONFIG_HANDLERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CONFIG_HANDLERS_HAS_DLL == 1 */

// Set CONFIG_HANDLERS_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CONFIG_HANDLERS_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CONFIG_HANDLERS_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CONFIG_HANDLERS_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CONFIG_HANDLERS_NTRACE */

#if (CONFIG_HANDLERS_NTRACE == 1)
#  define CONFIG_HANDLERS_TRACE(X)
#else /* (CONFIG_HANDLERS_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CONFIG_HANDLERS_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CONFIG_HANDLERS_NTRACE == 1) */

#endif /* CONFIG_HANDLERS_EXPORT_H */

// End of auto generated file.
