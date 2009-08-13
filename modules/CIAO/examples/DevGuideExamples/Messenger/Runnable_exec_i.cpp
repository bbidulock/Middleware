// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#include "Runnable_exec_i.h"
#include "ciao/CIAO_common.h"

namespace CIAO_Messenger_Impl
{
  //==================================================================
  // Facet Executor Implementation Class:   Runnable_exec_i
  //==================================================================

  Runnable_exec_i::Runnable_exec_i ()
  {
    // initially in "stopped" state
    this->stop();
  }

  Runnable_exec_i::~Runnable_exec_i (void)
  {
    // don't own anything
  }

  // Operations from ::Runnable

  void
  Runnable_exec_i::start ()
  {
    this->run_lock_.release();
  }

  void
  Runnable_exec_i::stop ()
  {
    this->run_lock_.acquire();
  }

  TAO_SYNCH_MUTEX&
  Runnable_exec_i::get_run_lock ()
  {
    return this->run_lock_;
  }
}

