// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.9 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef TARGETMANAGER_EXEC_EXPORT_H
#define TARGETMANAGER_EXEC_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (TARGETMANAGER_EXEC_HAS_DLL)
#  define TARGETMANAGER_EXEC_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && TARGETMANAGER_EXEC_HAS_DLL */

#if !defined (TARGETMANAGER_EXEC_HAS_DLL)
#  define TARGETMANAGER_EXEC_HAS_DLL 1
#endif /* ! TARGETMANAGER_EXEC_HAS_DLL */

#if defined (TARGETMANAGER_EXEC_HAS_DLL) && (TARGETMANAGER_EXEC_HAS_DLL == 1)
#  if defined (TARGETMANAGER_EXEC_BUILD_DLL)
#    define TARGETMANAGER_EXEC_Export ACE_Proper_Export_Flag
#    define TARGETMANAGER_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define TARGETMANAGER_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* TARGETMANAGER_EXEC_BUILD_DLL */
#    define TARGETMANAGER_EXEC_Export ACE_Proper_Import_Flag
#    define TARGETMANAGER_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define TARGETMANAGER_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* TARGETMANAGER_EXEC_BUILD_DLL */
#else /* TARGETMANAGER_EXEC_HAS_DLL == 1 */
#  define TARGETMANAGER_EXEC_Export
#  define TARGETMANAGER_EXEC_SINGLETON_DECLARATION(T)
#  define TARGETMANAGER_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* TARGETMANAGER_EXEC_HAS_DLL == 1 */

// Set TARGETMANAGER_EXEC_NTRACE = 0 to turn on library-specific
// tracing even if tracing is turned off for ACE.
#if !defined (TARGETMANAGER_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define TARGETMANAGER_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define TARGETMANAGER_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !TARGETMANAGER_EXEC_NTRACE */

#if (TARGETMANAGER_EXEC_NTRACE == 1)
#  define TARGETMANAGER_EXEC_TRACE(X)
#else /* (TARGETMANAGER_EXEC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define TARGETMANAGER_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (TARGETMANAGER_EXEC_NTRACE == 1) */

#endif /* TARGETMANAGER_EXEC_EXPORT_H */

