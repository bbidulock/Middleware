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

#include "InterInOutT_Sender_exec.h"
#include "InterInOutTA_conn_i.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_InterInOutT_Sender_Impl
{
  CORBA::Short nr_of_excep_received = 0;
  CORBA::UShort update_val = InterInOutT::update_val;
  CORBA::UShort cmd_synch_ok = InterInOutT::cmd_synch_ok;
  CORBA::UShort cmd_synch_nok = InterInOutT::cmd_synch_nok;
  CORBA::UShort cmd_asynch_ok = InterInOutT::cmd_asynch_ok;
  CORBA::UShort cmd_asynch_nok = InterInOutT::cmd_asynch_nok;

  void HandleException (
       long id,
       long expect_id,
       const char* error_string,
       const char* func)
  {
     //expected exception
    if ( id == expect_id)
      {
        ACE_DEBUG ((LM_DEBUG, "Sender: Caught correct exception <%u,"
                               "%C> for %C\n",
                               id, error_string, func));
        ++nr_of_excep_received;
       }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR Sender: wrong exception received"
                               " for %C\n", func));
      }
  }
  //============================================================
  // Worker thread for asynchronous invocations for MyFoo
  //============================================================
  asynch_foo_generator::asynch_foo_generator (
       ::InterInOutT::CCM_Sender_Context_ptr context,
        Atomic_UShort  &nr_of_received)
     : context_(::InterInOutT::CCM_Sender_Context::_duplicate (context)),
       nr_of_received_(nr_of_received)
  {
  }
  int asynch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    ::InterInOutT::AMI4CCM_MyFoo_var my_foo_ami_  =
       context_->get_connection_sendc_run_my_foo();
    if (CORBA::is_nil (my_foo_ami_))
      {
        ACE_ERROR ((LM_ERROR, "ERROR Sender (ASYNCH) :\tfoo_ami is NIL !\n"));
       return 1;
      }
    else
      {
        ::InterInOutT::AMI4CCM_MyFooReplyHandler_var cb =
          new CIAO_InterInOutT_AMI4CCM_MyFoo_Connector_AMI4CCM_Connector_Impl::AMI4CCM_MyFooReplyHandler_i (
          this->nr_of_received_);

        CORBA::Long l_cmd = 3;
        CORBA::String_var answer = CORBA::string_dup("Hi from sender");
        //Invoke Asynchronous calls to test
        my_foo_ami_->sendc_foo ( cb.in (),
          "Do something synchronous", l_cmd, answer.inout());

        //this should invoke a exception
        l_cmd = 4;
        my_foo_ami_->sendc_foo (  cb.in (),
          "", l_cmd, answer.inout());
        my_foo_ami_->sendc_var_ins(  cb.in (),
                                   "Here a double for you.", 1.6);

        InterInOutT::TestTopic test_topic;
        test_topic.key = "aaa";
        test_topic.x = 10;
        InterInOutT::TopicString topic_str;
        topic_str.key = "bbb";
        topic_str.x_str = "ccc";
        InterInOutT::TestArray topic_arr;
        for ( CORBA::UShort i = 0; i < 5; i ++)
          {
            topic_arr[i].key = CORBA::string_dup("ddd");
            for (CORBA::UShort y = 0; y < 5; y ++)
              {
                topic_arr[i].x_array[y] = i * 100 + y ;
              }
          }
        my_foo_ami_->sendc_var_div_ins ( cb.in (),
                                        test_topic,topic_str,topic_arr, answer);

        InterInOutT::X_Union topic_union;
        topic_union.x_long(11);
        InterInOutT::test ttt;
        ttt.x_test = 12;
        ttt.x_teststr = "fff" ;
        InterInOutT::test_seq seq;
        seq.length(2);
        seq[0] = ttt;

        my_foo_ami_->sendc_var_div2_ins ( cb.in (),
                                         topic_union, seq);
        InterInOutT::test_enum in_test;
        in_test = ::InterInOutT::ONE;
        my_foo_ami_->sendc_enum_in( cb.in (),
                                          in_test);
      }
    return 0;
  }
  //============================================================
  // Worker thread for synchronous invocations for MyFoo
  //============================================================
  synch_foo_generator::synch_foo_generator (
   ::InterInOutT::CCM_Sender_Context_ptr context,
    Atomic_UShort  &nr_of_received)
  : context_(::InterInOutT::CCM_Sender_Context::_duplicate (context)),
    nr_of_received_(nr_of_received)
  {
  }
  int synch_foo_generator::svc ()
   {
     ACE_OS::sleep (3);

     //run some synch calls
     ::InterInOutT::MyFoo_var my_foo_ami_ =
          context_->get_connection_run_my_foo ();
     CORBA::String_var answer = CORBA::string_dup("Hi from sender");
     CORBA::Long l_cmd = 1;
     try
       {
         CORBA::Long result = my_foo_ami_->foo ("Do something synchronous",
                                                 l_cmd ,
                                                 answer.inout ());
         if ((result == (update_val + cmd_synch_ok)) &&
             (ACE_OS::strcmp (answer.in(), "Hi from receiver") == 0))
           {
             ++this->nr_of_received_;
           }
       }
     catch (const InterInOutT::InternalError&)
       {
         ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::foo: "
                               "Unexpected exception.\n"));
       }
     try
       {
         l_cmd = 2;
         answer = CORBA::string_dup("Hi from sender");
         my_foo_ami_->foo ("",l_cmd, answer.inout());
       }
     catch (const InterInOutT::InternalError& ex)
       {
           HandleException (ex.id, (update_val + cmd_synch_nok),
                            ex.error_string.in(),
                            "synch foo");
       }
     return 0;
   }

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void){
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
      ::InterInOutT::CCM_Sender_Context::_narrow (ctx);

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
                                 this->nr_of_received_);
     this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

     this->synch_foo_gen =
        new synch_foo_generator (this->ciao_context_.in(),
                                 this->nr_of_received_);
     this->synch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);   }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if (nr_of_excep_received != 2)
    {
      ACE_ERROR ((LM_ERROR, "ERROR: not received the expected number of"
                            " exceptions"
                            "Expected: 2, Received: %u.\n",
                            nr_of_excep_received));
    }
    if (this->nr_of_received_.value() != 6)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Sender not received the expected number"
                              " of callbacks and returns  for syn- and "
                              "asynchronous calls. Expected: 6,"
                              " Received: %u.\n",
                              this->nr_of_received_.value()));
      }
    if ((this->nr_of_received_.value() == 6) && (nr_of_excep_received == 2))
      {
        ACE_DEBUG ((LM_DEBUG, "OK: Sender received the expected number of"
                              " callbacks and exceptions for syn- and "
                              "asynchronous calls\n"));
      }
    delete this->asynch_foo_gen;
    this->asynch_foo_gen = 0;
    delete this->synch_foo_gen;
    this->synch_foo_gen = 0;
  }

  extern "C" INTERINOUT_T_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_InterInOutT_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
