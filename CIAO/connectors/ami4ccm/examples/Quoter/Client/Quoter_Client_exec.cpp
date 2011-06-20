// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.0
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

#include "Quoter_Client_exec.h"

#include "ace/OS_NS_unistd.h"

namespace CIAO_Quoter_Client_Impl
{

  //============================================================
  // Worker thread for asynchronous invocations
  //============================================================
  asynch_quoter_generator::asynch_quoter_generator (
     ::Quoter::CCM_Client_Context_ptr context)
   : context_(::Quoter::CCM_Client_Context::_duplicate (context))
  {
  }

  int asynch_quoter_generator::svc ()
  {
    ACE_OS::sleep (3);
    ::Quoter::AMI4CCM_StockManager_var my_quoter_ami_  =
       context_->get_connection_sendc_my_quoter();

    if (CORBA::is_nil (my_quoter_ami_))
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT("ERROR Client (ASYNCH) :")
                    ACE_TEXT("\tmy_quoter_ami_ is NIL !!!\n")));
        return 1;
      }
    ::Quoter::CCM_AMI4CCM_StockManagerReplyHandler_var cb =
         new AMI4CCM_StockManagerReplyHandler_my_quoter_i ();

    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT("Client (ASYNCH) :")
                ACE_TEXT("\tInvoke Asynchronous calls\n")));

    my_quoter_ami_->sendc_get_stock_exchange_name (cb.in ());

    my_quoter_ami_->sendc_add_stock (cb.in (), "Google", 10.46);

    my_quoter_ami_->sendc_edit_stock (cb.in (), "Google", 11.13);

    my_quoter_ami_->sendc_remove_stock (cb.in (), "Microsoft");

    my_quoter_ami_->sendc_find_closest_symbol (cb.in (), "Micro");

    my_quoter_ami_->sendc_get_quote (cb.in (), "Google");

    ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT("Client (ASYNCH) :\tInvoked Asynchronous calls\n")));

    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT("Client (ASYNCH) :\tInvoke Asynchronous call ")
                ACE_TEXT("to test except handling\n")));

    my_quoter_ami_->sendc_get_quote (cb.in (), "Microsoft");

    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT("Client (ASYNCH) :\tInvoked Asynchronous call.\n")));
    return 0;
  }

  /**
   * Component Executor Implementation Class: Client_exec_i
   */

  Client_exec_i::Client_exec_i (void){
  }

  Client_exec_i::~Client_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  // Operations from Components::SessionComponent.

  void
  Client_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Quoter::CCM_Client_Context::_narrow (ctx);
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Client_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Client_exec_i::ccm_activate (void)
  {
    this->asynch_quoter_gen_ =
      new asynch_quoter_generator (this->context_.in ());
    this->asynch_quoter_gen_->activate (THR_NEW_LWP | THR_JOINABLE, 1);
  }

  void
  Client_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Client_exec_i::ccm_remove (void)
  {
    delete this->asynch_quoter_gen_;
    this->asynch_quoter_gen_ = 0;
  }

  AMI4CCM_StockManagerReplyHandler_my_quoter_i::AMI4CCM_StockManagerReplyHandler_my_quoter_i (void)
  {
  }

  AMI4CCM_StockManagerReplyHandler_my_quoter_i::~AMI4CCM_StockManagerReplyHandler_my_quoter_i (void)
  {
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::get_stock_exchange_name (
    const char * stock_exchange_name)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("Client - StockManagerReplyHandler : get_stock_exchange_name = %C\n"),
                stock_exchange_name));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::get_stock_exchange_name_excep (
    ::CCM_AMI::ExceptionHolder_ptr /* excep_holder */)
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("ERROR Client - StockManagerReplyHandler : get_stock_exchange_name threw exception\n")));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::set_stock_exchange_name (void)
  {
    /* Your code here. */
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::set_stock_exchange_name_excep (
    ::CCM_AMI::ExceptionHolder_ptr /* excep_holder */)
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("ERROR Client - StockManagerReplyHandler : set_stock_exchange_name threw exception\n")));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::add_stock (
    ::CORBA::Boolean ami_return_val)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("Client - StockManagerReplyHandler : add_stock returned %C\n"),
                ami_return_val ? "true" : "false"));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::add_stock_excep (
    ::CCM_AMI::ExceptionHolder_ptr /* excep_holder */)
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("ERROR Client - StockManagerReplyHandler : add_stock threw exception\n")));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::edit_stock (void)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("Client - StockManagerReplyHandler : edit_stock returned successfully\n")));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::edit_stock_excep (
    ::CCM_AMI::ExceptionHolder_ptr /* excep_holder */)
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("ERROR Client - StockManagerReplyHandler : edit_stock threw exception\n")));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::remove_stock (
    ::CORBA::Double quote)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("Client - StockManagerReplyHandler : remove_stock returned %f\n"),
                quote));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::remove_stock_excep (
    ::CCM_AMI::ExceptionHolder_ptr /* excep_holder */)
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("ERROR Client - StockManagerReplyHandler : remove_stock threw exception\n")));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::find_closest_symbol (
    ::CORBA::Boolean ami_return_val,
    const char * symbol)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("Client - StockManagerReplyHandler : find_closest_symbol returned %C; ")
                ACE_TEXT ("symbol found = %C\n"),
                ami_return_val ? "true" : "false",
                ami_return_val ? symbol : "(none)"));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::find_closest_symbol_excep (
    ::CCM_AMI::ExceptionHolder_ptr /* excep_holder */)
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("ERROR Client - StockManagerReplyHandler : find_closest_symbol threw exception\n")));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::get_quote (
    ::CORBA::Double ami_return_val)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("Client - StockManagerReplyHandler : get_quote returned %f\n"),
                ami_return_val));
  }

  void
  AMI4CCM_StockManagerReplyHandler_my_quoter_i::get_quote_excep (
    ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    try
    {
      excep_holder->raise_exception ();
    }
    catch (const Quoter::InvalidStock& ex)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT("Client - StockManagerReplyHandler : get_quote threw correct exception type\n")));

      if (ACE_OS::strcmp (ex.sym.in (), "Microsoft") == 0)
      {
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT("Client - StockManagerReplyHandler : get_quote could not find quote for %C\n"),
                    ex.sym.in ()));
        return;
      }
    }
    catch (const CORBA::Exception& /*ex*/)
    {
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("ERROR Client - StockManagerReplyHandler : get_quote threw unexpected exception\n")));
    }
  }

  extern "C" QUOTER_CLIENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Client_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Client_exec_i);

    return retval;
  }
}
