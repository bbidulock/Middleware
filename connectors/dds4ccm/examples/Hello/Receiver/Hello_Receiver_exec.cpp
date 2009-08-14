// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.9 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:1278

#include "Hello_Receiver_exec.h"
#include "ciao/CIAO_common.h"

#include "ace/Atomic_Op.h"

namespace CIAO_Hello_DDS_Receiver_Impl
{
  //============================================================
  // Facet Executor Implementation Class: string_RawListener_exec_i
  //============================================================

  string_RawListener_exec_i::string_RawListener_exec_i (Atomic_ULong &received,
                                                        const ACE_CString &name)
    : received_ (received),
      name_ (name)
  {
  }

  string_RawListener_exec_i::~string_RawListener_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::string_RawListener

  void
  string_RawListener_exec_i::on_data (
    const char * an_instance,
    const ::CCM_DDS::ReadInfo & /* info */)
  {
    ++received_;
    printf ("<%s> string_RawListener::on_data received <%s>\n", this->name_.c_str (), an_instance);
  }
  //============================================================
  // Facet Executor Implementation Class: PortStatusListener_exec_i
  //============================================================

  PortStatusListener_exec_i::PortStatusListener_exec_i (Atomic_ULong &lost)
    : lost_ (lost)
  {
  }

  PortStatusListener_exec_i::~PortStatusListener_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  PortStatusListener_exec_i::on_requested_deadline_missed (
    ::DDS::DataReader_ptr /* the_reader */,
    const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    printf ("port status listener::on_requested_deadline_missed\n");
  }

  void
  PortStatusListener_exec_i::on_sample_lost (
    ::DDS::DataReader_ptr /* the_reader */,
    const ::DDS::SampleLostStatus & /* status */)
  {
    ++lost_;
    printf ("port status listener::on_sample_lost\n");
  }

  //============================================================
  // Component Executor Implementation Class: Receiver_exec_i
  //============================================================

  Receiver_exec_i::Receiver_exec_i (void)
    : context_ (0),
      expected_ (10),
      received_ (0),
      lost_ (0)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes.

  ::CORBA::ULong
  Receiver_exec_i::expected_samples (void)
  {
    return this->expected_;
  }

  void
  Receiver_exec_i::expected_samples (::CORBA::ULong expected_samples)
  {
    this->expected_ = expected_samples;
  }

  char *
  Receiver_exec_i::name (void)
  {
    return CORBA::string_dup (this->name_.c_str ());
  }

  void
  Receiver_exec_i::name (const char *name)
  {
    this->name_ = name;
  }

  // Port operations.

  ::CCM_DDS::CCM_string_RawListener_ptr
  Receiver_exec_i::get_read_message_listener (void)
  {
    return new string_RawListener_exec_i (this->received_, this->name_);
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_read_message_status (void)
  {
    return new PortStatusListener_exec_i (this->lost_);
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_DDS::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
  /* Code to use the reader 
    ::CCM_DDS::string_Reader_var reader = this->context_->get_connection_read_message_data ();
    ::CCM_DDS::ReadInfo_var readinfo;
    ::CORBA::String_var string;
    reader->read_one (string.out (), readinfo.out ());
  /*

  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    CIAO_DEBUG ((LM_INFO, "Receiver_exec_i received %u messages and lost %u messages\n",
                 this->received_.value (),
                 this->lost_.value ()));

    if (this->received_ != this->expected_)
      {
        CIAO_ERROR ((LM_EMERGENCY, "Receiver_exec_i: Warning: Expected to receive %u messages, actually got %u\n",
                     this->expected_, this->received_.value ()));
      }
  }

  extern "C" HELLO_RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_DDS_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}

namespace CIAO_Hello_DDS_Receiver_Impl
{
  //============================================================
  // Home Executor Implementation Class: ReceiverHome_exec_i
  //============================================================

  ReceiverHome_exec_i::ReceiverHome_exec_i (void)
  {
  }

  ReceiverHome_exec_i::~ReceiverHome_exec_i (void)
  {
  }

  // All operations and attributes.

  // Factory operations.

  // Finder operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  ReceiverHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      Receiver_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C" HELLO_RECEIVER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_DDS_ReceiverHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      ReceiverHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());
    
    return retval;
  }
}

