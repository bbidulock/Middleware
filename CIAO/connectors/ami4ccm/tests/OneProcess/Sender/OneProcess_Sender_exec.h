// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/
#ifndef CIAO_ONEPROCESS_SENDER_EXEC_MFMTWV_H_
#define CIAO_ONEPROCESS_SENDER_EXEC_MFMTWV_H_

#include /**/ "ace/pre.h"

#include "OneProcess_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "OneProcess_Sender_exec_export.h"
#include "tao/LocalObject.h"
#include "ace/Task.h"

namespace CIAO_OneProcess_Sender_Impl
{
  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::UShort > Atomic_UShort;
  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::Boolean > Atomic_Boolean;

  /// Worker thread for asynchronous invocations
  class asynch_foo_generator : public virtual ACE_Task_Base
  {
  public:
    asynch_foo_generator (::OneProcess::CCM_Sender_Context_ptr context,
                          Atomic_Boolean &asynch);

    virtual int svc (void);

  private:
    ::OneProcess::CCM_Sender_Context_var context_;
    Atomic_Boolean &asynch_;
  };

  /// Worker thread for synchronous invocations
  class synch_foo_generator : public virtual ACE_Task_Base
  {
  public:
    synch_foo_generator (::OneProcess::CCM_Sender_Context_ptr context);
    virtual int svc (void);

  private:
    ::OneProcess::CCM_Sender_Context_var context_;
  };

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  class Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    //@{
    /** Supported operations and attributes. */
    //@}

    //@{
    /** Component attributes and port operations. */
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */
    //@}

  private:
    ::OneProcess::CCM_Sender_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    //@}

    //@{
    /** User defined members. */
    asynch_foo_generator* asynch_foo_gen;
    synch_foo_generator* synch_foo_gen;
    Atomic_Boolean asynch_;
    //@}

    //@{
    /** User defined private operations. */
    //@}
  };
  class AMI4CCM_MyFooReplyHandler_run_my_foo_i
    : public ::OneProcess::CCM_AMI4CCM_MyFooReplyHandler,
      public virtual ::CORBA::LocalObject
    {
    public:
      AMI4CCM_MyFooReplyHandler_run_my_foo_i (Atomic_Boolean &asynch);
      virtual ~AMI4CCM_MyFooReplyHandler_run_my_foo_i (void);

      virtual void
      foo (
        ::CORBA::Long ami_return_val,
        const char * answer);

      virtual void
      foo_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);
    private:
      Atomic_Boolean &asynch_;

    };

    extern "C" ONEPROCESS_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
    create_OneProcess_Sender_Impl (void);
  }

#include /**/ "ace/post.h"

#endif /* ifndef */
