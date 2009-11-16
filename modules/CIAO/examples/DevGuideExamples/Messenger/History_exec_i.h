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

#ifndef CIAO_HISTORY_EXEC_H
#define CIAO_HISTORY_EXEC_H

#include /**/ "ace/pre.h"

#include "MessengerEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Messenger_exec_export.h"
#include "tao/LocalObject.h"

// MY CODE
#include <list>
#include "ace/Thread_Mutex.h"

namespace CIAO_Messenger_Impl
{
  class MESSENGER_EXEC_Export History_exec_i
  : public virtual ::CCM_History,
    public virtual ::CORBA::LocalObject
  {
  public:
    History_exec_i (void);
    virtual ~History_exec_i (void);

    // Operations from ::History

    virtual ::Messages *get_all ();

    virtual ::Message *get_latest ();

    // MY CODE

    void add( ::Message* message);

  private:
    TAO_SYNCH_MUTEX lock_;

    typedef std::list< ::Message_var> MessageList;
    MessageList messages_;
  };
}

#include /**/ "ace/post.h"

#endif /* CIAO_HISTORY_EXEC_H */

