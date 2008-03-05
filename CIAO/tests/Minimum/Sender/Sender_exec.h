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

#ifndef CIAO_SENDER_EXEC_H
#define CIAO_SENDER_EXEC_H

#include /**/ "ace/pre.h"

#include "SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Sender_exec_export.h"
#include "tao/LocalObject.h"

namespace CIDL_Sender_Impl
{
  class SENDER_EXEC_Export Sender_exec_i
    : public virtual Sender_Exec,
      public virtual TAO_Local_RefCounted_Object
  {
    public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    // Supported or inherited operations.

    virtual void
    bar ();

    // Attribute operations.

    // Port operations.

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void ciao_preactivate ();

    virtual void ciao_postactivate ();

    virtual void ccm_activate ();

    virtual void ccm_passivate ();

    virtual void ccm_remove ();

    private:
    ::Minimum::CCM_Sender_Context_var context_;
  };

  class SENDER_EXEC_Export SenderHome_exec_i
    : public virtual SenderHome_Exec,
      public virtual TAO_Local_RefCounted_Object
  {
    public:
    SenderHome_exec_i (void);
    virtual ~SenderHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" SENDER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Minimum_SenderHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_SENDER_EXEC_H */

