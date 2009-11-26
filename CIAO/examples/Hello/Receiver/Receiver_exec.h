// $Id$

#ifndef CIAO_RECEIVER_EXEC_H
#define CIAO_RECEIVER_EXEC_H

#include /**/ "ace/pre.h"

#include "ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Hello_Receiver_Impl
{
  /**
   * @class Receiver_exec_i
   *
   * Receiver executor implementation class.
   */
  class RECEIVER_EXEC_Export Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {

  public:
    /// Default constructor.
    Receiver_exec_i ();

    /// Default destructor.
    ~Receiver_exec_i ();

    /// Operation to set the value of the attribute "iterations"
    virtual void iterations (CORBA::Short iterations);

    /// Operation to get the value of the attribute "iterations"
    virtual CORBA::Short iterations ();

    // Operation which will be called upon receiving the timeout event.
    virtual void
    push_click_in (::Hello::TimeOut *ev);

    // Operations from Components::SessionComponent
    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete ();

    virtual void ccm_activate ();
    virtual void ccm_passivate ();
    virtual void ccm_remove ();

  protected:
    /// Copmponent specific context
    ::Hello::CCM_Receiver_Context_var context_;

  private:
    CORBA::String_var message_;
    CORBA::Short iterations_;
  };

  /**
   * @class ReceiverHome_exec_i
   *
   * Receiver home executor implementation class.
   */
  class RECEIVER_EXEC_Export ReceiverHome_exec_i
    : public virtual ReceiverHome_Exec,
      public virtual ::CORBA::LocalObject
  {
    public:
    ReceiverHome_exec_i (void);
    virtual ~ReceiverHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" RECEIVER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_ReceiverHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_RECEIVER_EXEC_H */
