
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl NAVDISPLAYGUI_EXEC_EXEC
// ------------------------------
#ifndef NAVDISPLAYGUI_EXEC_EXEC_EXPORT_H
#define NAVDISPLAYGUI_EXEC_EXEC_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL)
#  define NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL */

#if !defined (NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL)
#  define NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL 1
#endif /* ! NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL */

#if defined (NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL) && (NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL == 1)
#  if defined (NAVDISPLAYGUI_EXEC_EXEC_BUILD_DLL)
#    define NAVDISPLAYGUI_EXEC_EXEC_Export ACE_Proper_Export_Flag
#    define NAVDISPLAYGUI_EXEC_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define NAVDISPLAYGUI_EXEC_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* NAVDISPLAYGUI_EXEC_EXEC_BUILD_DLL */
#    define NAVDISPLAYGUI_EXEC_EXEC_Export ACE_Proper_Import_Flag
#    define NAVDISPLAYGUI_EXEC_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define NAVDISPLAYGUI_EXEC_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* NAVDISPLAYGUI_EXEC_EXEC_BUILD_DLL */
#else /* NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL == 1 */
#  define NAVDISPLAYGUI_EXEC_EXEC_Export
#  define NAVDISPLAYGUI_EXEC_EXEC_SINGLETON_DECLARATION(T)
#  define NAVDISPLAYGUI_EXEC_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* NAVDISPLAYGUI_EXEC_EXEC_HAS_DLL == 1 */

// Set NAVDISPLAYGUI_EXEC_EXEC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (NAVDISPLAYGUI_EXEC_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define NAVDISPLAYGUI_EXEC_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define NAVDISPLAYGUI_EXEC_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !NAVDISPLAYGUI_EXEC_EXEC_NTRACE */

#if (NAVDISPLAYGUI_EXEC_EXEC_NTRACE == 1)
#  define NAVDISPLAYGUI_EXEC_EXEC_TRACE(X)
#else /* (NAVDISPLAYGUI_EXEC_EXEC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define NAVDISPLAYGUI_EXEC_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (NAVDISPLAYGUI_EXEC_EXEC_NTRACE == 1) */

#endif /* NAVDISPLAYGUI_EXEC_EXEC_EXPORT_H */

// End of auto generated file.
