
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s CIAO_XML_HELPERS
// ------------------------------
#ifndef CIAO_XML_HELPERS_EXPORT_H
#define CIAO_XML_HELPERS_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CIAO_XML_HELPERS_HAS_DLL)
#  define CIAO_XML_HELPERS_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CIAO_XML_HELPERS_HAS_DLL */

#if !defined (CIAO_XML_HELPERS_HAS_DLL)
#  define CIAO_XML_HELPERS_HAS_DLL 1
#endif /* ! CIAO_XML_HELPERS_HAS_DLL */

#if defined (CIAO_XML_HELPERS_HAS_DLL) && (CIAO_XML_HELPERS_HAS_DLL == 1)
#  if defined (CIAO_XML_HELPERS_BUILD_DLL)
#    define CIAO_XML_HELPERS_Export ACE_Proper_Export_Flag
#    define CIAO_XML_HELPERS_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CIAO_XML_HELPERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CIAO_XML_HELPERS_BUILD_DLL */
#    define CIAO_XML_HELPERS_Export ACE_Proper_Import_Flag
#    define CIAO_XML_HELPERS_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CIAO_XML_HELPERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CIAO_XML_HELPERS_BUILD_DLL */
#else /* CIAO_XML_HELPERS_HAS_DLL == 1 */
#  define CIAO_XML_HELPERS_Export
#  define CIAO_XML_HELPERS_SINGLETON_DECLARATION(T)
#  define CIAO_XML_HELPERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CIAO_XML_HELPERS_HAS_DLL == 1 */

// Set CIAO_XML_HELPERS_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CIAO_XML_HELPERS_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CIAO_XML_HELPERS_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CIAO_XML_HELPERS_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CIAO_XML_HELPERS_NTRACE */

#if (CIAO_XML_HELPERS_NTRACE == 1)
#  define CIAO_XML_HELPERS_TRACE(X)
#else /* (CIAO_XML_HELPERS_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CIAO_XML_HELPERS_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CIAO_XML_HELPERS_NTRACE == 1) */

#endif /* CIAO_XML_HELPERS_EXPORT_H */

// End of auto generated file.
