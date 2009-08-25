// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.1 ****
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

#include "Hello_Sender_exec.h"
#include "ciao/CIAO_common.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_Hello_AMI_Sender_Impl
{

  //============================================================
  // Worker thread for asynchronous invocations
  //============================================================
  asynch_generator::asynch_generator (::CCM_AMI::AMI_ami_foo_ptr foo_ami)
            : foo_ami_ (::CCM_AMI::AMI_ami_foo::_duplicate (foo_ami))
  {
  }

  int asynch_generator::svc ()
  {
      ACE_OS::sleep (2);
      long cookie;
      for (int i = 0; i < 5; ++i)
        {
          if (CORBA::is_nil (foo_ami_))
            printf ("Sender :\tfoo_receiver is NIL !!!\n");
          else
            {
              cookie = foo_ami_->sendc_foo ("Do something asynchronous");
        printf ("Sender :\tInvoked Asynchronous call. cookie <%ld>\n", cookie);
            }
        }

    printf ("Sender :\tInvoke Asynchronous call to test EXCEPTION HANDLING\n");
    cookie = foo_ami_->sendc_foo ("");
        printf ("Sender :\tInvoked Asynchronous call. cookie <%ld>\n", cookie);
    return 0;
  }

  //============================================================
  // Worker thread for synchronous invocations
  //============================================================
  synch_generator::synch_generator (::CCM_AMI::AMI_foo_ptr foo_ami)
            : foo_ami_ (::CCM_AMI::AMI_foo::_duplicate (foo_ami))
  {
  }

  int synch_generator::svc ()
  {
    ACE_OS::sleep (2);
    //run synch calls
    char * out_str;
    for (int i = 0; i < 5; ++i)
      {
        CORBA::Long result = foo_ami_->foo ("Do something synchronous", out_str);
        printf ("Sender :\tInvoked synchronous call result <%d> answer <%s>\n", result, out_str);
      }
    try
      {
        CORBA::Long result = foo_ami_->foo ("", out_str);
        printf ("Sender :\tInvoked synchronous call result <%d> answer <%s>\n", result, out_str);
      }
    catch (CCM_AMI::InternalError& ex)
      {
        printf ("Expected Exception caught : <%d> <%s>\n", ex.ex.id, ex.ex.error_string.in ());
      }
    return 0;
  }

  //============================================================
  // Facet Executor Implementation Class: AMI_foo_callback_exec_i
  //============================================================
  
  AMI_foo_callback_exec_i::AMI_foo_callback_exec_i (void)
  {
  }
  
  AMI_foo_callback_exec_i::~AMI_foo_callback_exec_i (void)
  {
  }
  
  // Operations from ::CCM_AMI::AMI_foo_callback
  
  void
  AMI_foo_callback_exec_i::foo_callback_handler (
    ::CCM_AMI::Cookie ck,
    ::CORBA::Long result,
    const char * answer)
  {
    printf ("Sender :\tCallback from AMI : cookie <%d> result <%d> answer <%s>\n", ck, result, answer);
  }
  
  void
  AMI_foo_callback_exec_i::foo_callback_excep (
    ::CCM_AMI::Cookie ck,
      const ::CCM_AMI::InternalException & exception_holder)
  {
    //printf ("Sender :\tCallback EXCEPTION from AMI : cookie <%d> error <%s>\n", ck, exception_holder.error_string);
    printf ("Sender :\tCallback EXCEPTION from AMI : cookie <%d> exception id : <%d> exception error : <%s>\n",
      ck, exception_holder.id, exception_holder.error_string.in ());
  }
  
  //============================================================
  // Component Executor Implementation Class: Sender_exec_i
  //============================================================
  
  Sender_exec_i::Sender_exec_i (void)
  {
  }
  
  Sender_exec_i::~Sender_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes.
  
  // Port operations.
  
  ::CCM_AMI::CCM_AMI_foo_callback_ptr
  Sender_exec_i::get_the_foo_callback ()
  {
    return new AMI_foo_callback_exec_i ();
  }
  
  // Operations from Components::SessionComponent.
  
  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_AMI::CCM_Sender_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  Sender_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  Sender_exec_i::ccm_activate (void)
  {
    ::CCM_AMI::AMI_ami_foo_var asynch_foo =
      this->context_->get_connection_run_asynch_foo ();
    ::CCM_AMI::AMI_foo_var synch_foo =
      this->context_->get_connection_run_foo ();

    asynch_generator* asynch = new asynch_generator (asynch_foo);
    asynch->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    synch_generator* synch = new synch_generator (synch_foo);
    synch->activate (THR_NEW_LWP | THR_JOINABLE, 1);
  }
  
  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Sender_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_AMI_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      Sender_exec_i,
      ::Components::EnterpriseComponent::_nil ());
    
    return retval;
  }
}

namespace CIAO_Hello_AMI_Sender_Impl
{
  //============================================================
  // Home Executor Implementation Class: SenderHome_exec_i
  //============================================================
  
  SenderHome_exec_i::SenderHome_exec_i (void)
  {
  }
  
  SenderHome_exec_i::~SenderHome_exec_i (void)
  {
  }
  
  // All operations and attributes.
  
  // Factory operations.
  
  // Finder operations.
  
  // Implicit operations.
  
  ::Components::EnterpriseComponent_ptr
  SenderHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      Sender_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C"  ::Components::HomeExecutorBase_ptr
  create_Hello_AMI_SenderHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      SenderHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());
    
    return retval;
  }
}

