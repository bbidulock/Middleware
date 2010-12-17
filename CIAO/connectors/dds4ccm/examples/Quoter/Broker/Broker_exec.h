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
#ifndef CIAO_BROKER_EXEC_ULWEAH_H_
#define CIAO_BROKER_EXEC_ULWEAH_H_

#include /**/ "ace/pre.h"

#include "BrokerEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Broker_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Quoter_Broker_Impl
{

  /**
   * Provider Executor Implementation Class: info_out_data_listener_exec_i
   */

  class info_out_data_listener_exec_i
    : public virtual ::Quoter::CCM_Listener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_data_listener_exec_i (
      ::Quoter::CCM_Broker_Context_ptr ctx);
    virtual ~info_out_data_listener_exec_i (void);

    //@{
    /** Operations and attributes from ::Quoter::Listener. */

    virtual
    void on_one_data (const ::Quoter::Stock_Info & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_data (const ::Quoter::Stock_InfoSeq & data,
    const ::CCM_DDS::ReadInfoSeq & infos);
    //@}

  private:
    ::Quoter::CCM_Broker_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: info_out_status_exec_i
   */

  class info_out_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_status_exec_i (
      ::Quoter::CCM_Broker_Context_ptr ctx);
    virtual ~info_out_status_exec_i (void);

    //@{
    /** Operations and attributes from ::CCM_DDS::PortStatusListener. */

    virtual
    void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
    const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (::DDS::DataReader_ptr the_reader,
    const ::DDS::SampleLostStatus & status);
    //@}

  private:
    ::Quoter::CCM_Broker_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: Broker_exec_i
   */

  class Broker_exec_i
    : public virtual Broker_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Broker_exec_i (void);
    virtual ~Broker_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::Quoter::CCM_Listener_ptr
    get_info_out_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);
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
    ::Quoter::CCM_Broker_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::Quoter::CCM_Listener_var ciao_info_out_data_listener_;
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_out_status_;
    //@}

    //@{
    /** User defined members. */

    //@}

    //@{
    /** User defined private operations. */

    //@}
  };

  extern "C" BROKER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Broker_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
