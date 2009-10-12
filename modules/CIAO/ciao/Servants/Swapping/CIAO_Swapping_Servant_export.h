
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl CIAO_Swapping_Servant
// ------------------------------
#ifndef CIAO_SWAPPING_SERVANT_EXPORT_H
#define CIAO_SWAPPING_SERVANT_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CIAO_SWAPPING_SERVANT_HAS_DLL)
#  define CIAO_SWAPPING_SERVANT_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CIAO_SWAPPING_SERVANT_HAS_DLL */

#if !defined (CIAO_SWAPPING_SERVANT_HAS_DLL)
#  define CIAO_SWAPPING_SERVANT_HAS_DLL 1
#endif /* ! CIAO_SWAPPING_SERVANT_HAS_DLL */

#if defined (CIAO_SWAPPING_SERVANT_HAS_DLL) && (CIAO_SWAPPING_SERVANT_HAS_DLL == 1)
#  if defined (CIAO_SWAPPING_SERVANT_BUILD_DLL)
#    define CIAO_Swapping_Servant_Export ACE_Proper_Export_Flag
#    define CIAO_SWAPPING_SERVANT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CIAO_SWAPPING_SERVANT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CIAO_SWAPPING_SERVANT_BUILD_DLL */
#    define CIAO_Swapping_Servant_Export ACE_Proper_Import_Flag
#    define CIAO_SWAPPING_SERVANT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CIAO_SWAPPING_SERVANT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CIAO_SWAPPING_SERVANT_BUILD_DLL */
#else /* CIAO_SWAPPING_SERVANT_HAS_DLL == 1 */
#  define CIAO_Swapping_Servant_Export
#  define CIAO_SWAPPING_SERVANT_SINGLETON_DECLARATION(T)
#  define CIAO_SWAPPING_SERVANT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CIAO_SWAPPING_SERVANT_HAS_DLL == 1 */

// Set CIAO_SWAPPING_SERVANT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CIAO_SWAPPING_SERVANT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CIAO_SWAPPING_SERVANT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CIAO_SWAPPING_SERVANT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CIAO_SWAPPING_SERVANT_NTRACE */

#if (CIAO_SWAPPING_SERVANT_NTRACE == 1)
#  define CIAO_SWAPPING_SERVANT_TRACE(X)
#else /* (CIAO_SWAPPING_SERVANT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CIAO_SWAPPING_SERVANT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CIAO_SWAPPING_SERVANT_NTRACE == 1) */

#endif /* CIAO_SWAPPING_SERVANT_EXPORT_H */

// End of auto generated file.
