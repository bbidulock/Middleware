
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl BACKUP_GIZMO_LOW_SVNT
// ------------------------------
#ifndef BACKUP_GIZMO_LOW_SVNT_EXPORT_H
#define BACKUP_GIZMO_LOW_SVNT_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (BACKUP_GIZMO_LOW_SVNT_HAS_DLL)
#  define BACKUP_GIZMO_LOW_SVNT_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && BACKUP_GIZMO_LOW_SVNT_HAS_DLL */

#if !defined (BACKUP_GIZMO_LOW_SVNT_HAS_DLL)
#  define BACKUP_GIZMO_LOW_SVNT_HAS_DLL 1
#endif /* ! BACKUP_GIZMO_LOW_SVNT_HAS_DLL */

#if defined (BACKUP_GIZMO_LOW_SVNT_HAS_DLL) && (BACKUP_GIZMO_LOW_SVNT_HAS_DLL == 1)
#  if defined (BACKUP_GIZMO_LOW_SVNT_BUILD_DLL)
#    define BACKUP_GIZMO_LOW_SVNT_Export ACE_Proper_Export_Flag
#    define BACKUP_GIZMO_LOW_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define BACKUP_GIZMO_LOW_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* BACKUP_GIZMO_LOW_SVNT_BUILD_DLL */
#    define BACKUP_GIZMO_LOW_SVNT_Export ACE_Proper_Import_Flag
#    define BACKUP_GIZMO_LOW_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define BACKUP_GIZMO_LOW_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* BACKUP_GIZMO_LOW_SVNT_BUILD_DLL */
#else /* BACKUP_GIZMO_LOW_SVNT_HAS_DLL == 1 */
#  define BACKUP_GIZMO_LOW_SVNT_Export
#  define BACKUP_GIZMO_LOW_SVNT_SINGLETON_DECLARATION(T)
#  define BACKUP_GIZMO_LOW_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* BACKUP_GIZMO_LOW_SVNT_HAS_DLL == 1 */

// Set BACKUP_GIZMO_LOW_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (BACKUP_GIZMO_LOW_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define BACKUP_GIZMO_LOW_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define BACKUP_GIZMO_LOW_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !BACKUP_GIZMO_LOW_SVNT_NTRACE */

#if (BACKUP_GIZMO_LOW_SVNT_NTRACE == 1)
#  define BACKUP_GIZMO_LOW_SVNT_TRACE(X)
#else /* (BACKUP_GIZMO_LOW_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define BACKUP_GIZMO_LOW_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (BACKUP_GIZMO_LOW_SVNT_NTRACE == 1) */

#endif /* BACKUP_GIZMO_LOW_SVNT_EXPORT_H */

// End of auto generated file.
