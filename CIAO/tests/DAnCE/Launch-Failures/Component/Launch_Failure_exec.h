// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.1
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
#ifndef CIAO_LAUNCH_FAILURE_EXEC_SOQV6E_H_
#define CIAO_LAUNCH_FAILURE_EXEC_SOQV6E_H_

#include /**/ "ace/pre.h"

#include "Launch_FailureEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Launch_Failure_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Launch_Failure_Impl
{

  /**
   * Provider Executor Implementation Class: remote_out_exec_i
   */

  class remote_out_exec_i
    : public virtual ::CCM_Remote_Interface,
      public virtual ::CORBA::LocalObject
  {
  public:
    remote_out_exec_i (
      ::CCM_Launch_Failure_Context_ptr ctx);
    virtual ~remote_out_exec_i (void);

    /** @name Operations and attributes from Remote_Interface */
    //@{
    //@}

  private:
    ::CCM_Launch_Failure_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: local_out_exec_i
   */

  class local_out_exec_i
    : public virtual ::CCM_Local_Interface,
      public virtual ::CORBA::LocalObject
  {
  public:
    local_out_exec_i (
      ::CCM_Launch_Failure_Context_ptr ctx);
    virtual ~local_out_exec_i (void);

    /** @name Operations and attributes from Local_Interface */
    //@{
    //@}

  private:
    ::CCM_Launch_Failure_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: local_in_exec_i
   */

  class local_in_exec_i
    : public virtual ::CCM_Local_Interface,
      public virtual ::CORBA::LocalObject
  {
  public:
    local_in_exec_i (
      ::CCM_Launch_Failure_Context_ptr ctx);
    virtual ~local_in_exec_i (void);

    /** @name Operations and attributes from Local_Interface */
    //@{
    //@}

  private:
    ::CCM_Launch_Failure_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: Launch_Failure_exec_i
   */

  class Launch_Failure_exec_i
    : public virtual Launch_Failure_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Launch_Failure_exec_i (void);
    virtual ~Launch_Failure_exec_i (void);

    /** @name Supported operations and attributes. */
    //@{

    //@}

    /** @name Component attributes and port operations. */
    //@{

    virtual ::CCM_Remote_Interface_ptr
    get_remote_out (void);

    virtual ::CCM_Local_Interface_ptr
    get_local_out (void);

    virtual ::Failure_Reason failure_reason (void);

    virtual void failure_reason (::Failure_Reason failure_reason);
    //@}

    /** @name Operations from Components::SessionComponent. */
    //@{
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    /** @name User defined public operations. */
    //@{

    //@}

  private:
    ::CCM_Launch_Failure_Context_var ciao_context_;

    /** @name Component attributes. */
    //@{
    ::CCM_Remote_Interface_var ciao_remote_out_;
    ::CCM_Local_Interface_var ciao_local_out_;
    ::CCM_Local_Interface_var ciao_local_in_;

    ::Failure_Reason failure_reason_;
    //@}

    /** @name User defined members. */
    //@{

    //@}

    /** @name User defined private operations. */
    //@{

    //@}
  };

  extern "C" LAUNCH_FAILURE_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Launch_Failure_Impl (void);
}

namespace CIAO_Launch_Failure_Impl
{
  class LAUNCH_FAILURE_EXEC_Export Launch_Failure_Home_exec_i
    : public virtual Launch_Failure_Home_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Launch_Failure_Home_exec_i (void);

    virtual ~Launch_Failure_Home_exec_i (void);

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };

  extern "C" LAUNCH_FAILURE_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Launch_Failure_Home_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
