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
#ifndef CIAO_COHERENTWRITE_TEST_RECEIVER_EXEC_Q0HRJG_H_
#define CIAO_COHERENTWRITE_TEST_RECEIVER_EXEC_Q0HRJG_H_

#include /**/ "ace/pre.h"

#include "CoherentWrite_Test_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_CoherentWrite_Test_Receiver_Impl
{
  class Receiver_exec_i;

  /**
   * Read action Generator
   */
  class read_action_Generator
    : public ACE_Event_Handler
  {
  public:
    read_action_Generator (Receiver_exec_i &callback,
                           int run);

    ~read_action_Generator ();

    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
  private:
    Receiver_exec_i &callback_;
    int run_;
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
      ::CoherentWrite_Test::CCM_Receiver_Context_ptr ctx);
    virtual ~info_out_status_exec_i (void);

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
    ::CoherentWrite_Test::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: reader_start_exec_i
   */

  class reader_start_exec_i
    : public virtual ::CCM_CoherentWriteStarter,
      public virtual ::CORBA::LocalObject
  {
  public:
    reader_start_exec_i (
      ::CoherentWrite_Test::CCM_Receiver_Context_ptr ctx,
      Receiver_exec_i &callback);

    virtual ~reader_start_exec_i (void);

    //@{
    /** Operations and attributes from CoherentWriteStarter. */

    virtual
    void set_reader_properties (::CORBA::UShort nr_iterations);

    virtual
    void start_read (::CORBA::UShort run);
    //@}

  private:
    ::CoherentWrite_Test::CCM_Receiver_Context_var ciao_context_;
    Receiver_exec_i &callback_;
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

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);

    virtual ::CCM_CoherentWriteStarter_ptr
    get_reader_start (void);

    virtual ::CORBA::UShort nr_runs (void);

    virtual void nr_runs (::CORBA::UShort nr_runs);
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
    bool check_last (void);
    void start_read (CORBA::UShort run);
    void run (CORBA::UShort run);

    ::CORBA::UShort iterations (void);
    void iterations (::CORBA::UShort iterations);
    //@}

  private:
    ::CoherentWrite_Test::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_out_status_;
    ::CCM_CoherentWriteStarter_var ciao_reader_start_;

    ::CORBA::UShort nr_runs_;
    //@}

    //@{
    /** User defined members. */
    CORBA::UShort   iterations_;
    CORBA::UShort   run_;
    CORBA::Long     last_iter_;

    read_action_Generator *ticker_;

    void check_iters (const char * test,
                      const CoherentWriteTestSeq& coherentwrite_info_seq);

    void get_all (void);
    void read_all (void);

    //@}

    //@{
    /** User defined private operations. */

    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CoherentWrite_Test_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
