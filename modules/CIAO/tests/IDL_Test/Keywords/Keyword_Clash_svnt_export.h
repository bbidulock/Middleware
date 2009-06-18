
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl KEYWORD_CLASH_SVNT
// ------------------------------
#ifndef KEYWORD_CLASH_SVNT_EXPORT_H
#define KEYWORD_CLASH_SVNT_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (KEYWORD_CLASH_SVNT_HAS_DLL)
#  define KEYWORD_CLASH_SVNT_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && KEYWORD_CLASH_SVNT_HAS_DLL */

#if !defined (KEYWORD_CLASH_SVNT_HAS_DLL)
#  define KEYWORD_CLASH_SVNT_HAS_DLL 1
#endif /* ! KEYWORD_CLASH_SVNT_HAS_DLL */

#if defined (KEYWORD_CLASH_SVNT_HAS_DLL) && (KEYWORD_CLASH_SVNT_HAS_DLL == 1)
#  if defined (KEYWORD_CLASH_SVNT_BUILD_DLL)
#    define KEYWORD_CLASH_SVNT_Export ACE_Proper_Export_Flag
#    define KEYWORD_CLASH_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define KEYWORD_CLASH_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* KEYWORD_CLASH_SVNT_BUILD_DLL */
#    define KEYWORD_CLASH_SVNT_Export ACE_Proper_Import_Flag
#    define KEYWORD_CLASH_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define KEYWORD_CLASH_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* KEYWORD_CLASH_SVNT_BUILD_DLL */
#else /* KEYWORD_CLASH_SVNT_HAS_DLL == 1 */
#  define KEYWORD_CLASH_SVNT_Export
#  define KEYWORD_CLASH_SVNT_SINGLETON_DECLARATION(T)
#  define KEYWORD_CLASH_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* KEYWORD_CLASH_SVNT_HAS_DLL == 1 */

// Set KEYWORD_CLASH_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (KEYWORD_CLASH_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define KEYWORD_CLASH_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define KEYWORD_CLASH_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !KEYWORD_CLASH_SVNT_NTRACE */

#if (KEYWORD_CLASH_SVNT_NTRACE == 1)
#  define KEYWORD_CLASH_SVNT_TRACE(X)
#else /* (KEYWORD_CLASH_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define KEYWORD_CLASH_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (KEYWORD_CLASH_SVNT_NTRACE == 1) */

#endif /* KEYWORD_CLASH_SVNT_EXPORT_H */

// End of auto generated file.
