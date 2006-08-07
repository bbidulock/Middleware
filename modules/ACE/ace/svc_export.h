// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.

// This file was generated by generate_export_file.pl
// but needed to be altered to support ACE_BUILD_SVC_DLL
// instead of ACE_SVC_BUILD_DLL which was already being
// used.

// ------------------------------
#if !defined (ACE_SVC_EXPORT_H)
#define ACE_SVC_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (ACE_SVC_HAS_DLL)
#  define ACE_SVC_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && ACE_SVC_HAS_DLL */

#if !defined (ACE_SVC_HAS_DLL)
#define ACE_SVC_HAS_DLL 1
#endif /* ! ACE_SVC_HAS_DLL */

#if defined (ACE_SVC_HAS_DLL)
#  if (ACE_SVC_HAS_DLL == 1)
#    if defined (ACE_BUILD_SVC_DLL) || defined (ACE_SVC_BUILD_DLL)
#      define ACE_Svc_Export ACE_Proper_Export_Flag
#      define ACE_SVC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    else
#      define ACE_Svc_Export ACE_Proper_Import_Flag
#      define ACE_SVC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    endif /* ACE_BUILD_SVC_DLL */
#  else
#    define ACE_Svc_Export
#    define ACE_SVC_SINGLETON_DECLARATION(T)
#  endif   /* ! ACE_SVC_HAS_DLL == 1 */
#else
#  define ACE_Svc_Export
#  define ACE_SVC_SINGLETON_DECLARATION(T)
#endif     /* ACE_SVC_HAS_DLL */

#endif     /* ACE_SVC_EXPORT_H */

// End of auto generated file.
