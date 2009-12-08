// -*- C++ -*-
// $Id$

#ifndef CIAO_RECEIVER_EXEC_H_
#define CIAO_RECEIVER_EXEC_H_

#include "Getter_Test_ReceiverEC.h"

#include /**/ "Receiver_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"
#include "ace/Reactor.h"
#include "ace/Task.h"

#include <map>

namespace CIAO_Getter_Test_Receiver_Impl
{
  class Receiver_exec_i;

  //============================================================
  // ConnectorStatusListener_exec_i
  //============================================================
  class RECEIVER_EXEC_Export ConnectorStatusListener_exec_i
    : public virtual ::CCM_DDS::CCM_ConnectorStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    ConnectorStatusListener_exec_i (Receiver_exec_i &);
    virtual ~ConnectorStatusListener_exec_i (void);

    virtual
    void on_inconsistent_topic( ::DDS::Topic_ptr ,
                              const DDS::InconsistentTopicStatus & );
    virtual
    void on_requested_incompatible_qos( ::DDS::DataReader_ptr ,
                              const DDS::RequestedIncompatibleQosStatus & );
    virtual
    void on_sample_rejected( ::DDS::DataReader_ptr ,
                              const DDS::SampleRejectedStatus & );
    virtual
    void on_offered_deadline_missed( ::DDS::DataWriter_ptr ,
                              const DDS::OfferedDeadlineMissedStatus & );
    virtual
    void on_offered_incompatible_qos( ::DDS::DataWriter_ptr ,
                              const DDS::OfferedIncompatibleQosStatus & );
    virtual
    void on_unexpected_status( ::DDS::Entity_ptr ,
                              ::DDS::StatusKind );
  private:
    /// Maintains a handle that actually process the event
    Receiver_exec_i &callback_;
    bool has_run_;
  };

  //============================================================
  // GetOneHandler
  //============================================================
  class GetOneHandler
    : public ACE_Event_Handler
  {
  public:
    GetOneHandler (Receiver_exec_i &,
                   const char * key,
                   CORBA::Long iteration);
    virtual ~GetOneHandler ();

    virtual int handle_exception (ACE_HANDLE fc = ACE_INVALID_HANDLE);

  private:
    Receiver_exec_i &callback_;
    const char * key_;
    CORBA::Long iteration_;
  };

  //============================================================
  // GetManyHandler
  //============================================================
  class GetManyHandler
    : public ACE_Event_Handler
  {
  public:
    GetManyHandler (Receiver_exec_i &,
                   CORBA::UShort keys,
                   CORBA::Long iterations);
    virtual ~GetManyHandler ();

    virtual int handle_exception (ACE_HANDLE fc = ACE_INVALID_HANDLE);

  private:
    Receiver_exec_i &callback_;
    CORBA::UShort keys_;
    CORBA::Long   iterations_;
  };

  //============================================================
  // Invoker_exec_i
  //============================================================
  class Invoker_exec_i
    : public virtual ::CCM_GetInvoker,
      public virtual ::CORBA::LocalObject
  {
  public:
    Invoker_exec_i (Receiver_exec_i & callback);
    virtual ~Invoker_exec_i (void);

    virtual void get_no_data ();

    virtual void start_get_one (const char * key,
                                     ::CORBA::Long iteration);
    virtual void start_get_many (::CORBA::Short keys , ::CORBA::Long iterations);

  private:
    Receiver_exec_i &callback_;
  };

  //============================================================
  // Receiver_exec_i
  //============================================================
  class RECEIVER_EXEC_Export Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    // Supported operations and attributes.
    // Component attributes.

    // Port operations.
    virtual ::CCM_DDS::GetterTest::CCM_Listener_ptr
    get_info_out_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_get_status (void);

    virtual ::CCM_GetInvoker_ptr
    get_getter_invoke ();

    virtual ::CCM_DDS::CCM_ConnectorStatusListener_ptr
    get_info_out_connector_status (void);

    void get_no_data ();
    void start_get_one (const char * key,
                        CORBA::Long iteration);
    void get_one (const char * key,
                  CORBA::Long iteration);

    void start_get_many (CORBA::Short keys,
                         CORBA::Long iterations);
    void get_many (CORBA::Short keys,
                         CORBA::Long iterations);

    // Operations from Components::SessionComponent.
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);

  private:
    ::Getter_Test::CCM_Receiver_Context_var context_;
    ::CCM_DDS::GetterTest::Getter_var       getter_;

    typedef std::map<ACE_CString, DDS::InstanceHandle_t> Handle_Table;
    Handle_Table handles_;
  };

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Getter_Test_Receiver_Impl (void);
}

#endif /* ifndef */

