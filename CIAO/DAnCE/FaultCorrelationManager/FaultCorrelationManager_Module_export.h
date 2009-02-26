
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl FaultCorrelationManager_Module
// ------------------------------
#ifndef FAULTCORRELATIONMANAGER_MODULE_EXPORT_H
#define FAULTCORRELATIONMANAGER_MODULE_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (FAULTCORRELATIONMANAGER_MODULE_HAS_DLL)
#  define FAULTCORRELATIONMANAGER_MODULE_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && FAULTCORRELATIONMANAGER_MODULE_HAS_DLL */

#if !defined (FAULTCORRELATIONMANAGER_MODULE_HAS_DLL)
#  define FAULTCORRELATIONMANAGER_MODULE_HAS_DLL 1
#endif /* ! FAULTCORRELATIONMANAGER_MODULE_HAS_DLL */

#if defined (FAULTCORRELATIONMANAGER_MODULE_HAS_DLL) && (FAULTCORRELATIONMANAGER_MODULE_HAS_DLL == 1)
#  if defined (FAULTCORRELATIONMANAGER_MODULE_BUILD_DLL)
#    define FaultCorrelationManager_Module_Export ACE_Proper_Export_Flag
#    define FAULTCORRELATIONMANAGER_MODULE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define FAULTCORRELATIONMANAGER_MODULE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* FAULTCORRELATIONMANAGER_MODULE_BUILD_DLL */
#    define FaultCorrelationManager_Module_Export ACE_Proper_Import_Flag
#    define FAULTCORRELATIONMANAGER_MODULE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define FAULTCORRELATIONMANAGER_MODULE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* FAULTCORRELATIONMANAGER_MODULE_BUILD_DLL */
#else /* FAULTCORRELATIONMANAGER_MODULE_HAS_DLL == 1 */
#  define FaultCorrelationManager_Module_Export
#  define FAULTCORRELATIONMANAGER_MODULE_SINGLETON_DECLARATION(T)
#  define FAULTCORRELATIONMANAGER_MODULE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* FAULTCORRELATIONMANAGER_MODULE_HAS_DLL == 1 */

// Set FAULTCORRELATIONMANAGER_MODULE_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (FAULTCORRELATIONMANAGER_MODULE_NTRACE)
#  if (ACE_NTRACE == 1)
#    define FAULTCORRELATIONMANAGER_MODULE_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define FAULTCORRELATIONMANAGER_MODULE_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !FAULTCORRELATIONMANAGER_MODULE_NTRACE */

#if (FAULTCORRELATIONMANAGER_MODULE_NTRACE == 1)
#  define FAULTCORRELATIONMANAGER_MODULE_TRACE(X)
#else /* (FAULTCORRELATIONMANAGER_MODULE_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define FAULTCORRELATIONMANAGER_MODULE_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (FAULTCORRELATIONMANAGER_MODULE_NTRACE == 1) */

#endif /* FAULTCORRELATIONMANAGER_MODULE_EXPORT_H */

// End of auto generated file.
