// -*- C++ -*-
// $Id$

#ifndef CIAO_SENDER_EXEC_H_
#define CIAO_SENDER_EXEC_H_


#include "Shapes_SenderEC.h"

#include /**/ "Sender_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"
#include "ace/Task.h"
#include "ace/Reactor.h"

#include <map>

namespace CIAO_Shapes_Sender_Impl
{
  class Sender_exec_i;
  
  class pulse_Generator : 
    public ACE_Event_Handler
  {
  public:
    pulse_Generator (Sender_exec_i &callback);

    ~pulse_Generator ();

    /// Handle the timeout.
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
  private:
    /// Maintains a handle that actually process the event
    Sender_exec_i &pulse_callback_;
  };
  
  class Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);
    
    // Supported operations and attributes.
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    void start (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    void stop (void);
    
    void tick ();
    
    // Component attributes.
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::ULong
    rate (void);
    
    virtual void
    rate (
      ::CORBA::ULong rate);
    
    virtual ::CORBA::UShort
    max_x (void);
    
    virtual void
    max_x (
      ::CORBA::UShort max_x);
    
    virtual ::CORBA::UShort
    max_y (void);
    
    virtual void
    max_y (
      ::CORBA::UShort max_y);

    virtual ::CORBA::UShort
    max_size (void);
    
    virtual void
    max_size (
      ::CORBA::UShort max_size);
    
    virtual void
    resize_shape (
      ::CORBA::Boolean resize);

    virtual ::CORBA::Boolean
    resize_shape (void);

    // Port operations.
    
    // Operations from Components::SessionComponent.
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
  
  private:
    CCM_DDS::ShapeType_Updater_var updater_;

    pulse_Generator * ticker_;
    ::Shapes::CCM_Sender_Context_var context_;
    CORBA::ULong rate_;
    CORBA::UShort max_x_;
    CORBA::UShort max_y_;
    CORBA::UShort max_size_;
    CORBA::Boolean resize_;
    
    bool x_increasing_;
    bool y_increasing_;
    bool size_increasing_;
    
    ShapeType* square_;
  };
  
  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shape_Sender_Impl (void);
}

#endif /* ifndef */

