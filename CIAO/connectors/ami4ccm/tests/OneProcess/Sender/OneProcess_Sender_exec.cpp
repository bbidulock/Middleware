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

#include "OneProcess_Sender_exec.h"
#include "ace/OS_NS_unistd.h"


namespace CIAO_OneProcess_Sender_Impl
{
  Atomic_UShort nr_of_sent = 0;

  //============================================================
  // Worker thread for asynchronous invocations for MyFoo
  //============================================================
  asynch_foo_generator::asynch_foo_generator (
      ::OneProcess::CCM_Sender_Context_ptr context,
       Atomic_Boolean &asynch)
     : context_(::OneProcess::CCM_Sender_Context::_duplicate (context)),
       asynch_(asynch)

  {
  }

  int asynch_foo_generator::svc ()
  {
    ACE_OS::sleep(3);
    ::OneProcess::AMI4CCM_MyFoo_var my_foo_ami_  =
       this->context_->get_connection_sendc_run_my_foo();

    ::OneProcess::AMI4CCM_MyFooReplyHandler_var cb0 =
        new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
            this->asynch_);
    ::OneProcess::AMI4CCM_MyFooReplyHandler_var cb1 =
        new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
            this->asynch_);
    ::OneProcess::AMI4CCM_MyFooReplyHandler_var cb2 =
        new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
            this->asynch_);
    ::OneProcess::AMI4CCM_MyFooReplyHandler_var cb3 =
        new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
            this->asynch_);
    ::OneProcess::AMI4CCM_MyFooReplyHandler_var cb4 =
        new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
            this->asynch_);

    for (int i = 0; i < 5; ++i)
      {
        if (CORBA::is_nil (my_foo_ami_))
          {
             ACE_ERROR ((LM_ERROR, "ERROR Sender (ASYNCH) :"
                                   "\tfoo_ami is NIL !\n"));
             return 1;
          }
        // sender, receiver and connector in one node: asynchronous callbacks
        // should become received synchronous.
        if (this->asynch_.value() == true)
          {
            //expect to have receive an answer before you come here again.
            //if asynch == true, error because no answer received in
            //MyFoo_callback_exec_i::foo
            ACE_ERROR ((LM_ERROR, "ERROR: not received synchronous answer "
                                   "for asynchronous call\n"));
          }
        else
          {
            ++nr_of_sent;
            //Invoke Asynchronous calls to test
            if (i == 0)
              {
                this->asynch_ = true;
                my_foo_ami_->sendc_foo ( cb0.in(),"Hi 1", 1);
              }
            else if (i == 1)
              {
                this->asynch_ = true;
                my_foo_ami_->sendc_foo ( cb1.in(),"Hi 2", 1);
              }
            else if (i == 2)
              {
                this->asynch_ = true;
                my_foo_ami_->sendc_foo ( cb2.in(),"Hi 3", 1);
              }
            else if (i == 3)
              {
                this->asynch_ = true;
                my_foo_ami_->sendc_foo ( cb3.in(),"Hi 4", 1);
              }
            else if (i == 4)
              {
                this->asynch_ = true;
                my_foo_ami_->sendc_foo ( cb4.in(),"Hi 5", 1);
              }
          }
      }
    return 0;
  }

  //============================================================
  // Worker thread for synchronous invocations for MyFoo
  //============================================================
  synch_foo_generator::synch_foo_generator (
      ::OneProcess::CCM_Sender_Context_ptr context)
     : context_(::OneProcess::CCM_Sender_Context::_duplicate (context))
  {
  }

  int synch_foo_generator::svc ()
  {
    ACE_OS::sleep(3);
   ::OneProcess::MyFoo_var my_foo_ami_ =
       this->context_->get_connection_run_my_foo ();

    CORBA::Boolean wait = false;
    for (int i = 0; i < 3; ++i)
      {
        //run some synch calls
        try
          {
            CORBA::String_var answer;
            if( wait==true)
              {
                ACE_ERROR ((LM_ERROR,
                            "ERROR: NOT RECEIVED SYNCHRONOUS answer.\n"));
              }
            wait = true;
            CORBA::Long result = my_foo_ami_->foo ("Do something synchronous",
                                                    2 ,
                                                    answer.out ());
            if ( result == 2)
              {
                ACE_DEBUG ((LM_DEBUG, "OK: RECEIVED SYNCHRONOUS answer <%C>\n",
                                       answer.in ()));
                wait = false;
              }
          }
        catch (const OneProcess::InternalError&)
          {
            ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::foo: "
                                    "Unexpected exception.\n"));
          }
        ACE_OS::sleep(1);
      }
    return 0;
  }

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void) :
    asynch_foo_gen(0),
    synch_foo_gen(0),
    asynch_(false)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::OneProcess::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
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
    this->asynch_foo_gen =
      new asynch_foo_generator (this->ciao_context_.in (),
                                 this->asynch_);
    this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    this->synch_foo_gen =
      new synch_foo_generator (this->ciao_context_.in());
    this->synch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if ((this->asynch_.value() == true) || (nr_of_sent.value() != 5))
      {
        ACE_ERROR ((LM_ERROR,
                   "ERROR: All in one proces worked asynchronous, "
                   "this was not expected!\n"));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG,
                   "OK: All in one proces worked synchronous as expected\n"));
      }
    delete this->asynch_foo_gen;
    this->asynch_foo_gen = 0;
    delete this->synch_foo_gen;
    this->synch_foo_gen = 0;
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::AMI4CCM_MyFooReplyHandler_run_my_foo_i (
      Atomic_Boolean &asynch)
   : asynch_(asynch)
  {
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::~AMI4CCM_MyFooReplyHandler_run_my_foo_i (void)
  {
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::foo (
     ::CORBA::Long ami_return_val,
     const char * /* answer */)
  {
    if (ami_return_val == 1)
      {
        ACE_DEBUG ((LM_DEBUG, "OK: GET ASYNCHRONOUS CALLBACK, \n"));
        this->asynch_ = false;
      }
    if (ami_return_val == 2)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: GET ASYNCHRONOUS CALLBACK "
                             "FROM SYNCHRONOUS SENT MESSAGE\n"));
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::foo_excep (
    ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  extern "C" ONEPROCESS_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_OneProcess_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
