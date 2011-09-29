// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.2
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
#ifndef CIAO_TYPEREGISTRATION_TEST_COMPONENT_EXEC_0FYVIW_H_
#define CIAO_TYPEREGISTRATION_TEST_COMPONENT_EXEC_0FYVIW_H_

#include /**/ "ace/pre.h"

#include "TypeRegistration_Test_ComponentEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Component_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_MLD_TypeRegistration_Test_CFTTestComponent_Impl
{
  class CFTTestComponent_exec_i;

  /**
   * WriteTicker
   */
  class WriteTicker :
    public ACE_Event_Handler
  {
  public:
    WriteTicker (CFTTestComponent_exec_i &callback);
    int handle_timeout (const ACE_Time_Value &, const void *);
  private:
    /// Maintains a handle that actually process the event
    CFTTestComponent_exec_i &callback_;
  };

  /**
   * Provider Executor Implementation Class: listener_data_listener_exec_i
   */

  class listener_data_listener_exec_i
    : public virtual ::MLDTypeRegistrationTestConn::CCM_Listener,
      public virtual ::CORBA::LocalObject
  {
  public:
    listener_data_listener_exec_i (
      ::MLD_TypeRegistration_Test::CCM_CFTTestComponent_Context_ptr ctx);
    virtual ~listener_data_listener_exec_i (void);

    /** @name Operations and attributes from MLDTypeRegistrationTestConn::Listener */
    //@{

    virtual
    void on_one_data (const ::MLDTypeRegistrationTest & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_data (const ::MLDTypeRegistrationTestSeq & data,
    const ::CCM_DDS::ReadInfoSeq & infos);
    //@}

  private:
    ::MLD_TypeRegistration_Test::CCM_CFTTestComponent_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: listener_status_exec_i
   */

  class listener_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    listener_status_exec_i (
      ::MLD_TypeRegistration_Test::CCM_CFTTestComponent_Context_ptr ctx);
    virtual ~listener_status_exec_i (void);

    /** @name Operations and attributes from CCM_DDS::PortStatusListener */
    //@{

    virtual
    void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
    const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (::DDS::DataReader_ptr the_reader,
    const ::DDS::SampleLostStatus & status);
    //@}

  private:
    ::MLD_TypeRegistration_Test::CCM_CFTTestComponent_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: CFTTestComponent_exec_i
   */

  class CFTTestComponent_exec_i
    : public virtual CFTTestComponent_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    CFTTestComponent_exec_i (void);
    virtual ~CFTTestComponent_exec_i (void);

    /** @name Supported operations and attributes. */
    //@{

    //@}

    /** @name Component attributes and port operations. */
    //@{

    virtual ::MLDTypeRegistrationTestConn::CCM_Listener_ptr
    get_listener_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_listener_status (void);
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
    void write_one (void);
    //@}

  private:
    ::MLD_TypeRegistration_Test::CCM_CFTTestComponent_Context_var ciao_context_;

    /** @name Component attributes. */
    //@{
    ::MLDTypeRegistrationTestConn::CCM_Listener_var ciao_listener_data_listener_;
    ::CCM_DDS::CCM_PortStatusListener_var ciao_listener_status_;
    //@}

    /** @name User defined members. */
    //@{
    WriteTicker     *ticker_;
    ::CORBA::ULong  iterator;
    //@}

    /** @name User defined private operations. */
    //@{

    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_MLD_TypeRegistration_Test_CFTTestComponent_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
