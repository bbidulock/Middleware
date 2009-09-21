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

#ifndef ADMINISTRATOR_SVNT_EXPORT_H
#define ADMINISTRATOR_SVNT_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (ADMINISTRATOR_SVNT_HAS_DLL)
#  define ADMINISTRATOR_SVNT_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && ADMINISTRATOR_SVNT_HAS_DLL */

#if !defined (ADMINISTRATOR_SVNT_HAS_DLL)
#  define ADMINISTRATOR_SVNT_HAS_DLL 1
#endif /* ! ADMINISTRATOR_SVNT_HAS_DLL */

#if defined (ADMINISTRATOR_SVNT_HAS_DLL) && (ADMINISTRATOR_SVNT_HAS_DLL == 1)
#  if defined (ADMINISTRATOR_SVNT_BUILD_DLL)
#    define ADMINISTRATOR_SVNT_Export ACE_Proper_Export_Flag
#    define ADMINISTRATOR_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ADMINISTRATOR_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ADMINISTRATOR_SVNT_BUILD_DLL */
#    define ADMINISTRATOR_SVNT_Export ACE_Proper_Import_Flag
#    define ADMINISTRATOR_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ADMINISTRATOR_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ADMINISTRATOR_SVNT_BUILD_DLL */
#else /* ADMINISTRATOR_SVNT_HAS_DLL == 1 */
#  define ADMINISTRATOR_SVNT_Export
#  define ADMINISTRATOR_SVNT_SINGLETON_DECLARATION(T)
#  define ADMINISTRATOR_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ADMINISTRATOR_SVNT_HAS_DLL == 1 */

// Set ADMINISTRATOR_SVNT_NTRACE = 0 to turn on library-specific
// tracing even if tracing is turned off for ACE.
#if !defined (ADMINISTRATOR_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define ADMINISTRATOR_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define ADMINISTRATOR_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !ADMINISTRATOR_SVNT_NTRACE */

#if (ADMINISTRATOR_SVNT_NTRACE == 1)
#  define ADMINISTRATOR_SVNT_TRACE(X)
#else /* (ADMINISTRATOR_SVNT_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define ADMINISTRATOR_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (ADMINISTRATOR_SVNT_NTRACE == 1) */

#endif /* ADMINISTRATOR_SVNT_EXPORT_H */

