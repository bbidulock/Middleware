/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    FT_ReplicationManager_Main.cpp
 *
 *  $Id$
 *
 *  This file is part of Fault Tolerant CORBA.
 *  This file provides the main routine for a process that
 *  implements the FT_ReplicationManager interface.
 *
 *  @author Curt Hibbs <hibbs_c@ociweb.com>
 */
//=============================================================================

#include <tao/Utils/ServantMain.h>
#include "FT_ReplicationManager.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  TAO::Utils::ServantMain<TAO::FT_ReplicationManager> servantMain("ReplicationManager");
  return servantMain.Main(argc, argv);
}

///////////////////////////////////
// Template instantiation for
// inept compilers.

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template TAO::Utils::ServantMain<FT_FaultDetectorFactory_i>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Utils::ServantMain<FT_FaultDetectorFactory_i>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

