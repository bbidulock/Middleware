
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl PRIMARY_GIZMO_SVNT
// ------------------------------
#ifndef PRIMARY_GIZMO_SVNT_EXPORT_H
#define PRIMARY_GIZMO_SVNT_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (PRIMARY_GIZMO_SVNT_HAS_DLL)
#  define PRIMARY_GIZMO_SVNT_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && PRIMARY_GIZMO_SVNT_HAS_DLL */

#if !defined (PRIMARY_GIZMO_SVNT_HAS_DLL)
#  define PRIMARY_GIZMO_SVNT_HAS_DLL 1
#endif /* ! PRIMARY_GIZMO_SVNT_HAS_DLL */

#if defined (PRIMARY_GIZMO_SVNT_HAS_DLL) && (PRIMARY_GIZMO_SVNT_HAS_DLL == 1)
#  if defined (PRIMARY_GIZMO_SVNT_BUILD_DLL)
#    define PRIMARY_GIZMO_SVNT_Export ACE_Proper_Export_Flag
#    define PRIMARY_GIZMO_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define PRIMARY_GIZMO_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* PRIMARY_GIZMO_SVNT_BUILD_DLL */
#    define PRIMARY_GIZMO_SVNT_Export ACE_Proper_Import_Flag
#    define PRIMARY_GIZMO_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define PRIMARY_GIZMO_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* PRIMARY_GIZMO_SVNT_BUILD_DLL */
#else /* PRIMARY_GIZMO_SVNT_HAS_DLL == 1 */
#  define PRIMARY_GIZMO_SVNT_Export
#  define PRIMARY_GIZMO_SVNT_SINGLETON_DECLARATION(T)
#  define PRIMARY_GIZMO_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* PRIMARY_GIZMO_SVNT_HAS_DLL == 1 */

// Set PRIMARY_GIZMO_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (PRIMARY_GIZMO_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define PRIMARY_GIZMO_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define PRIMARY_GIZMO_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !PRIMARY_GIZMO_SVNT_NTRACE */

#if (PRIMARY_GIZMO_SVNT_NTRACE == 1)
#  define PRIMARY_GIZMO_SVNT_TRACE(X)
#else /* (PRIMARY_GIZMO_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define PRIMARY_GIZMO_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (PRIMARY_GIZMO_SVNT_NTRACE == 1) */

#endif /* PRIMARY_GIZMO_SVNT_EXPORT_H */

// End of auto generated file.
