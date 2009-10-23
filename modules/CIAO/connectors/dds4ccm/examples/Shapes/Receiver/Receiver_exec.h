// -*- C++ -*-
//
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.3
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
 *       http://doc.ece.uci.edu/
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

// TAO_IDL - Generated from
// be/be_codegen.cpp:1217

#ifndef CIAO_RECEIVER_EXEC_H_
#define CIAO_RECEIVER_EXEC_H_


#include "ReceiverEC.h"

#include /**/ "Receiver_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"
#include "ace/Task.h"
#include "ace/Reactor.h"

namespace CIAO_Shape_Receiver_Impl
{
  class Receiver_exec_i;
  /**
  * @class reader activity generator
  *
  * @brief an active object used by Receiver to perform a periodical read action
  *
  */
  class read_action_Generator : public ACE_Task_Base
  {
  public:
    read_action_Generator (Receiver_exec_i &callback);

    ~read_action_Generator ();

    /// Hook method that performs application-defined initialization activities
    int open_h (void);

    /// Hook method that performs application-defined destruction activites
    int close_h (void);

    /// appliation-defined method for starting the pulse-generation service
    int start (CORBA::ULong hertz);

    /// application-defined method for stopping the pulse-generation service
    int stop (void);

    /// Indicate whether the current object is active
    int active (void);

    /// Handle the timeout.
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);

    /// Called when timer handler is removed.
    virtual int handle_close (ACE_HANDLE handle,
                              ACE_Reactor_Mask close_mask);

    /// Hook methods implemnting the task's service processing,
    /// invoked by all threads activated by activate () method
    virtual int svc (void);

  private:
    /// Tracking whether we are actively generating pulse or not.
    int active_;

    /// Maintains a handle that actually process the event
    Receiver_exec_i &pulse_callback_;

  };
  
  class RECEIVER_EXEC_Export Shape_Info_RawListener_exec_i
    : public virtual ::CCM_DDS::CCM_Shape_Info_RawListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    Shape_Info_RawListener_exec_i (void);
    virtual ~Shape_Info_RawListener_exec_i (void);
    
    // Operations and attributes from ::CCM_DDS::Shape_Info_RawListener
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    on_data (
      const ::Shapes::Shape_Info & an_instance,
      const ::CCM_DDS::ReadInfo & info);
  };
  
  class RECEIVER_EXEC_Export Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);
    
    // Supported operations and attributes.
    void read_one (void);
    void read_all (void);
    void get_one (void);
    void get_all (void);
    
    // Component attributes.
    virtual ::CORBA::ULong
    rate (void);
    
    virtual void
    rate (
      ::CORBA::ULong rate);
    
    virtual ::CORBA::Boolean
    get_data (void);
    
    virtual void
    get_data (
      ::CORBA::Boolean get_data);
    
    virtual ::CORBA::Boolean
    read_data (void);
    
    virtual void
    read_data (
      ::CORBA::Boolean read_data);
    // Port operations.
    
    virtual ::CCM_DDS::CCM_Shape_Info_RawListener_ptr
    get_info_out_listener (void);
    
    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);
    
    // Operations from Components::SessionComponent.
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
  
  private:
    ::Shape::CCM_Receiver_Context_var context_;
    ::CCM_DDS::Shape_Info_Reader_var reader_;
    ::CCM_DDS::Shape_Info_Getter_var getter_;
    
    read_action_Generator * ticker_;
    CORBA::ULong rate_;
    CORBA::Boolean get_data_, read_data_;
  };
  
  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shape_Receiver_Impl (void);
}

#endif /* ifndef */

