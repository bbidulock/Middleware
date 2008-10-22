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

#ifndef CIAO_RUNNABLE_EXEC_H
#define CIAO_RUNNABLE_EXEC_H

#include /**/ "ace/pre.h"

#include "Messenger_svnt.h"
#include "Messenger_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

// MY CODE
#include "ace/Synch.h"

namespace CIDL_Messenger_Impl
{
  class MESSENGER_EXEC_Export Runnable_exec_i
  : public virtual ::CCM_Runnable,
  public virtual TAO_Local_RefCounted_Object
  {
  public:
    Runnable_exec_i ();
    virtual ~Runnable_exec_i (void);

    // Operations from ::Runnable

    virtual void
    start ();

    virtual void
    stop ();

    // MY CODE

    ACE_Mutex& get_run_lock();

  private:
    ACE_Mutex run_lock_;
  };
}

#include /**/ "ace/post.h"

#endif /* CIAO_RUNNABLE_EXEC_H */

