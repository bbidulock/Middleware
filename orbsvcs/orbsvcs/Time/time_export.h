// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by
// ${ACE_ROOT}/GenExportH.BAT
// ------------------------------
#if !defined (TAO_TIME_EXPORT_H)
#define TAO_TIME_EXPORT_H

#include "ace/OS.h"

#if !defined (TAO_TIME_HAS_DLL)
#define TAO_TIME_HAS_DLL 1
#endif /* ! TAO_TIME_HAS_DLL */

#if defined (TAO_TIME_HAS_DLL)
#  if (TAO_TIME_HAS_DLL == 1)
#    if defined (TAO_TIME_BUILD_DLL)
#      define TAO_Time_Export ACE_Proper_Export_Flag
#      define TAO_TIME_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    else
#      define TAO_Time_Export ACE_Proper_Import_Flag
#      define TAO_TIME_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    endif /* TAO_TIME_BUILD_DLL */
#  else
#    define TAO_Time_Export
#    define TAO_TIME_SINGLETON_DECLARATION(T)
#  endif   /* ! TAO_TIME_HAS_DLL == 1 */
#else
#  define TAO_Time_Export
#  define TAO_TIME_SINGLETON_DECLARATION(T)
#endif     /* TAO_TIME_HAS_DLL */

#endif     /* TAO_TIME_EXPORT_H */

// End of auto generated file.
