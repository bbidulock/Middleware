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
#ifndef CIAO_HELLOT_SENDER_EXEC_4QC1XJ_H_
#define CIAO_HELLOT_SENDER_EXEC_4QC1XJ_H_

#include /**/ "ace/pre.h"

#include "HelloT_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "HelloT_Sender_exec_export.h"
#include "tao/LocalObject.h"
#include "ace/Task.h"

namespace CIAO_HelloT_Sender_Impl
{

  /// Worker thread for asynchronous invocations
  class asynch_foo_generator : public virtual ACE_Task_Base
  {
  public:
    asynch_foo_generator (::HelloT::CCM_Sender_Context_ptr context);

    virtual int svc (void);

  private:
    ::HelloT::CCM_Sender_Context_var context_;
  };

  /// Worker thread for synchronous invocations
  class synch_foo_generator : public virtual ACE_Task_Base
  {
  public:
    synch_foo_generator (::HelloT::CCM_Sender_Context_ptr context);

    virtual int svc (void);

  private:
    ::HelloT::CCM_Sender_Context_var context_;
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
    ::HelloT::CCM_Sender_Context_var ciao_context_;
    asynch_foo_generator* asynch_foo_gen;
    synch_foo_generator* synch_foo_gen;

    //@{
    /** Component attributes. */
    //@}

    //@{
    /** User defined members. */

    //@}

    //@{
    /** User defined private operations. */

    //@}
  };


  class AMI4CCM_MyFooReplyHandler_run_my_foo_i
    : public ::HelloT::CCM_AMI4CCM_MyFooReplyHandler,
      public virtual ::CORBA::LocalObject
    {
    public:
      AMI4CCM_MyFooReplyHandler_run_my_foo_i (void);
      virtual ~AMI4CCM_MyFooReplyHandler_run_my_foo_i (void);

      virtual void
      hello (
        const char * answer);

      virtual void
      hello_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      get_rw_attrib (
        ::CORBA::Short rw_attrib);

      virtual void
      get_rw_attrib_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      set_rw_attrib (void);

      virtual void
      set_rw_attrib_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);

      virtual void
      get_ro_attrib (
        ::CORBA::Short ro_attrib);

      virtual void
      get_ro_attrib_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder);
    };

    extern "C" HELLO_T_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
    create_HelloT_Sender_Impl (void);
  }

#include /**/ "ace/post.h"

#endif /* ifndef */
