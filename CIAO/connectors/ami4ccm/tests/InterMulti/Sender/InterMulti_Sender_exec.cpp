// -*- C++ -*-
// $Id$

// test sendc methods with derived classes, multiple inheritance.
#include "InterMulti_Sender_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_InterMulti_Sender_Impl
{
  Atomic_UShort nr_of_received = 0;
  //============================================================
  // Facet Executor Implementation Class: One_callback_exec_i
  //============================================================
  One_callback_exec_i::One_callback_exec_i (void)
  {
  }

  One_callback_exec_i::~One_callback_exec_i (void)
  {
  }
  //============================================================
  // Operations from ::CCM_AMI::One_callback
  //============================================================
  // FOO methods
  void
  One_callback_exec_i::foo (
    ::CORBA::Long /*ami_return_val*/,
    const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from ONE::foo,"
                          " answer = <%C>\n",
                          answer));
    ++nr_of_received;
  }

  void
  One_callback_exec_i::foo_excep (
      ::CCM_AMI::ExceptionHolder * excep_holder)
  {
    excep_holder->raise_exception ();
  }
  //============================================================
  // Facet Executor Implementation Class: Two_callback_exec_i
  //============================================================
  Two_callback_exec_i::Two_callback_exec_i (void)
  {
  }

  Two_callback_exec_i::~Two_callback_exec_i (void)
  {
  }
  //============================================================
  // Operations from ::CCM_AMI::Two_callback
  //============================================================
  // FOO methods
  void
  Two_callback_exec_i::bar (const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from TWO::bar,"
                          " answer = <%C>\n",
                          answer));
    ++nr_of_received;
  }

  void
  Two_callback_exec_i::bar_excep (
      ::CCM_AMI::ExceptionHolder * excep_holder)
  {
    excep_holder->raise_exception ();
  }
   //============================================================
  // Facet Executor Implementation Class: Three_callback_exec_i
  //============================================================
  Three_callback_exec_i::Three_callback_exec_i (void)
  {
  }

  Three_callback_exec_i::~Three_callback_exec_i (void)
  {
  }

  //============================================================
  // Operations from ::CCM_AMI::Three_callback
  //============================================================
  // FOO methods
  void
  Three_callback_exec_i::plus (const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from THREE::plus,"
                          " answer = <%C>\n",
                          answer));
     ++nr_of_received;
  }

  void
  Three_callback_exec_i::plus_excep (
      ::CCM_AMI::ExceptionHolder * excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  Three_callback_exec_i::foo (
    ::CORBA::Long /*ami_return_val*/,
    const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from THREE::foo,"
                          " answer = <%C>\n",
                          answer));
    ++nr_of_received;
  }

  void
  Three_callback_exec_i::foo_excep (
      ::CCM_AMI::ExceptionHolder * excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  Three_callback_exec_i::bar (const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from THREE::bar,"
                          " answer = <%C>\n",
                          answer));
    ++nr_of_received;
  }

  void
  Three_callback_exec_i::bar_excep (
      ::CCM_AMI::ExceptionHolder * excep_holder)
  {
    excep_holder->raise_exception ();
  }
  //============================================================
  // Worker thread for asynchronous invocations for One
  //============================================================
  asynch_one_generator::asynch_one_generator (
    ::InterMulti::CCM_Sender_Context_ptr context)
  : context_(::InterMulti::CCM_Sender_Context::_duplicate (context))
  {
  }

  int asynch_one_generator::svc ()
  {
    ::InterMulti::AMI4CCM_One_var my_one_ami_  =
       context_->get_connection_sendc_run_my_one();

    //Invoke Asynchronous calls to test
    my_one_ami_->sendc_foo ( new One_callback_exec_i (),
      "Hi from asynch call ONE::foo", 1);
    return 0;
  }

//============================================================
  // Worker thread for asynchronous invocations for Two
  //============================================================
  asynch_two_generator::asynch_two_generator (
    ::InterMulti::CCM_Sender_Context_ptr context)
  : context_(::InterMulti::CCM_Sender_Context::_duplicate (context))
  {
  }

  int asynch_two_generator::svc ()
  {
    ::InterMulti::AMI4CCM_Two_var my_two_ami_  =
       context_->get_connection_sendc_run_my_two();

    if (CORBA::is_nil (my_two_ami_.in ()))
      {
        ACE_ERROR ((LM_ERROR,
                   "ERROR Sender (ASYNCH) :my_two_ami_ is NIL !\n"));
        return 1;
      }
    else
      {
        //Invoke Asynchronous calls to test
        my_two_ami_->sendc_bar ( new Two_callback_exec_i (), 2);
      }
    return 0;
  }

  //============================================================
  // Worker thread for asynchronous invocations for Three
  //============================================================
  asynch_three_generator::asynch_three_generator (
   ::InterMulti::CCM_Sender_Context_ptr context)
  : context_(::InterMulti::CCM_Sender_Context::_duplicate (context))
  {
  }

  int asynch_three_generator::svc ()
  {
    ::InterMulti::AMI4CCM_Three_var my_three_ami_  =
       context_->get_connection_sendc_run_my_three();

    if (CORBA::is_nil (my_three_ami_))
      {
        ACE_ERROR ((LM_ERROR,
                    "ERROR Sender (ASYNCH) :my_three_ami_ is NIL !\n"));
        return 1;
      }
    else
      {
        //Invoke Asynchronous calls to test
        my_three_ami_->sendc_plus( new Three_callback_exec_i (), 3);
        // derived from CLASS ONE
        my_three_ami_->sendc_foo ( new Three_callback_exec_i (),"hoi", 3);
        // derived fron CLASS TWO
        my_three_ami_->sendc_bar ( new Three_callback_exec_i (), 3);
      }
    return 0;
  }
  //============================================================
  // Worker thread for synchronous invocations for One
  //============================================================
  synch_one_generator::synch_one_generator (
   ::InterMulti::CCM_Sender_Context_ptr context)
  : context_(::InterMulti::CCM_Sender_Context::_duplicate (context))
  {
  }

  int synch_one_generator::svc ()
  {
    ::InterMulti::One_var my_one_ami_ =
         context_->get_connection_run_my_one ();

    CORBA::String_var answer;
    CORBA::Long result = my_one_ami_->foo (
                            "Synchronous call foo from class One",
                            1,
                            answer.out ());
    if (result != 1)
      {
        ACE_ERROR ((LM_ERROR,
                    "ERROR Sender (SYNCH) : CLASS One foo !\n"));
      }
    return 0;
  }
 //============================================================
  // Worker thread for synchronous invocations for One
  //============================================================
  synch_three_generator::synch_three_generator (
   ::InterMulti::CCM_Sender_Context_ptr context)
  : context_(::InterMulti::CCM_Sender_Context::_duplicate (context))
  {
  }

  int synch_three_generator::svc ()
  {
    ::InterMulti::Three_var my_three_ami_ =
         context_->get_connection_run_my_three ();

    ::CORBA::String_var answer;
    CORBA::Long result = my_three_ami_->foo (
                        "Synchronous call foo from class Three, "
                        " derived from class ONE",
                        3 ,
                        answer.out ());
    if (result != 3)
      {
        ACE_ERROR ((LM_ERROR,
                    "ERROR Sender (SYNCH) : CLASS Three foo !\n"));
      }
    return 0;
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
  // Operations from Components::SessionComponent.
  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::InterMulti::CCM_Sender_Context::_narrow (ctx);
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::configuration_complete (void)
  {
  }

  void
  Sender_exec_i::ccm_activate (void)
  {
    asynch_one_generator* asynch_one_gen =
      new asynch_one_generator (this->context_.in ());
    asynch_one_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    asynch_two_generator* asynch_two_gen =
      new asynch_two_generator (this->context_.in ());
    asynch_two_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    asynch_three_generator* asynch_three_gen =
      new asynch_three_generator (this->context_.in ());
    asynch_three_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);


    synch_one_generator* synch_one_gen =
       new synch_one_generator (this->context_.in());
    synch_one_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    synch_three_generator* synch_three_gen =
       new synch_three_generator (this->context_.in());
    synch_three_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

  }
  void
  Sender_exec_i::ccm_passivate (void)
  {
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if (nr_of_received.value() != 5)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Did not get all callbacks for"
                              "derived classes."
                              " Received = %u of 5\n",
                              nr_of_received.value()));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG,
                    "OK: All messages received back by Sender\n"));
      }
  }

  extern "C"  ::Components::EnterpriseComponent_ptr
  create_InterMulti_AMI_Sender_Impl (void)
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
