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
#ifndef CIAO_QCLS_TEST_RECEIVER_EXEC_GHBRF4_H_
#define CIAO_QCLS_TEST_RECEIVER_EXEC_GHBRF4_H_

#include /**/ "ace/pre.h"

#include "QCLS_Test_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_QCLS_Test_Receiver_Impl
{
  class Receiver_exec_i;

  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::Long> Atomic_Long;

  /**
   * Provider Executor Implementation Class: info_state_data_listener_exec_i
   */

  class info_state_data_listener_exec_i
    : public virtual ::QCLS_Test::QueryConditionListenStateTestConnector::CCM_StateListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_state_data_listener_exec_i (
      ::QCLS_Test::CCM_Receiver_Context_ptr ctx,
      ACE_Thread_ID &thread_id,
      Atomic_Long &samples_received);
    virtual ~info_state_data_listener_exec_i (void);

    //@{
    /** Operations and attributes from QCLS_Test::QueryConditionListenStateTestConnector::StateListener. */

    virtual
    void on_creation (const ::QueryConditionListenStateTest & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_one_update (const ::QueryConditionListenStateTest & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_updates (const ::QueryConditionListenStateTestSeq & data,
    const ::CCM_DDS::ReadInfoSeq & infos);

    virtual
    void on_deletion (const ::QueryConditionListenStateTest & datum,
    const ::CCM_DDS::ReadInfo & info);
    //@}

  private:
    ::QCLS_Test::CCM_Receiver_Context_var ciao_context_;
    ACE_Thread_ID &thread_id_;
    Atomic_Long &samples_received_;
  };

  /**
   * Provider Executor Implementation Class: info_state_status_exec_i
   */

  class info_state_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_state_status_exec_i (
      ::QCLS_Test::CCM_Receiver_Context_ptr ctx);
    virtual ~info_state_status_exec_i (void);

    //@{
    /** Operations and attributes from CCM_DDS::PortStatusListener. */

    virtual
    void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
    const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (::DDS::DataReader_ptr the_reader,
    const ::DDS::SampleLostStatus & status);
    //@}

  private:
    ::QCLS_Test::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  class Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::QCLS_Test::QueryConditionListenStateTestConnector::CCM_StateListener_ptr
    get_info_state_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_state_status (void);

    virtual ::CORBA::UShort keys (void);

    virtual void keys (::CORBA::UShort keys);

    virtual ::CORBA::UShort iterations (void);

    virtual void iterations (::CORBA::UShort iterations);
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
    ::QCLS_Test::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::QCLS_Test::QueryConditionListenStateTestConnector::CCM_StateListener_var ciao_info_state_data_listener_;
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_state_status_;

    ::CORBA::UShort keys_;

    ::CORBA::UShort iterations_;
    //@}

    //@{
    /** User defined members. */
    ACE_Thread_ID thread_id_listener_;

    CORBA::Long samples_expected_;
    Atomic_Long samples_received_;

    //@}

    //@{
    /** User defined private operations. */
    void start (void);
    //@}
  };

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_QCLS_Test_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
