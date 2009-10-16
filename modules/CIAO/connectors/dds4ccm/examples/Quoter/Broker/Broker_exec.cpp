// -*- C++ -*-
//
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.2
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
// be/be_codegen.cpp:1278

#include "Broker_exec.h"
#include "ciao/CIAO_common.h"
#include "ace/Reactor.h"
#include "ace/OS_NS_time.h"

namespace CIAO_Quoter_Broker_Impl
{

  read_action_Generator::read_action_Generator (Broker_exec_i &callback)
    : active_ (0),
      pulse_callback_ (callback)
  {
    // initialize the reactor
    this->reactor (ACE_Reactor::instance ());
  }

  read_action_Generator::~read_action_Generator ()
  {
  }

  int
  read_action_Generator::open_h ()
  {
    // convert the task into a active object that runs in separate thread
    return this->activate ();
  }

  int
  read_action_Generator::close_h ()
  {
    this->reactor ()->end_reactor_event_loop ();
    // wait for all threads in the task to exit before it returns
    return this->wait ();
  }

  int
  read_action_Generator::start (CORBA::ULong hertz)
  {
    // return if not valid
    if (hertz == 0 || this->active_ != 0)
    {
      return -1;
    }

    // calculate the interval time
    long usec = 1000 / hertz;

    std::cerr << "Starting read_action_generator with hertz of " << hertz << ", interval of "
              << usec << std::endl;

    if (this->reactor ()->schedule_timer (this,
                                          0,
                                          ACE_Time_Value(0),
                                          ACE_Time_Value(3)) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Unable to setup Timer\n"),
                          -1);

    }

    this->active_ = 1;
    return 0;
  }

  int
  read_action_Generator::stop (void)
  {
    // return if not valid.
    if (this->active_ == 0)
    {
      return -1;
    }
    // cancle the timer
    this->reactor ()->cancel_timer (this);
    this->active_ = 0;
    return 0;
  }

  int
  read_action_Generator::active (void)
  {
    return this->active_;
  }

  int
  read_action_Generator::handle_close (ACE_HANDLE handle,
                                 ACE_Reactor_Mask close_mask)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("[%x] handle = %d, close_mask = %d\n"),
                this,
                handle,
                close_mask));
    return 0;
  }

  int
  read_action_Generator::handle_timeout (const ACE_Time_Value &,
                                   const void *)
  {
    // Notify the subscribers
    this->pulse_callback_.read ();
    return 0;
  }

  int
  read_action_Generator::svc (void)
  {
    // define the owner of the reactor thread
    this->reactor ()->owner (ACE_OS::thr_self ());

    // run event loop to wait for event, and then dispatch them to corresponding handlers
    this->reactor ()->run_reactor_event_loop ();

    return 0;
  }


   void
   Broker_exec_i::read (void)
   {
    std::cerr << "read" << std::endl;
	::Quoter::Stock_Info  stock_info;
    ::CCM_DDS::ReadInfo readinfo;
    printf("GO TO read ONE\n");    
	this->reader_->read_one (stock_info, readinfo );  

    printf ("Stock_Info_Read_One: received a stock_info for <%s> at %u:%u:%u\n",
            stock_info.symbol.in (),
            stock_info.low,
            stock_info.current,
            stock_info.high);
   
	printf("END OF READ_ONE\n");
}
	

  
  //============================================================
  // Facet Executor Implementation Class: Stock_Info_RawListener_exec_i
  //============================================================
  
  Stock_Info_RawListener_exec_i::Stock_Info_RawListener_exec_i (void)
  {
  }
  
  Stock_Info_RawListener_exec_i::~Stock_Info_RawListener_exec_i (void)
  {
  }
  
  // Operations from ::CCM_DDS::Stock_Info_RawListener
  
  void
  Stock_Info_RawListener_exec_i::on_data (
    const ::Quoter::Stock_Info & an_instance,
    const ::CCM_DDS::ReadInfo & /* info */)
  {
      /*
    printf ("Stock_Info_RawListener: received a stock_info for <%s> at %u:%u:%u\n",
            an_instance.symbol.in (),
            an_instance.low,
            an_instance.current,
            an_instance.high);
       */
  

  }  
  //============================================================
  // Facet Executor Implementation Class: PortStatusListener_exec_i
  //============================================================
  
  PortStatusListener_exec_i::PortStatusListener_exec_i (void)
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
    /* Your code here. */
  }
  
  void
  PortStatusListener_exec_i::on_sample_lost (
    ::DDS::DataReader_ptr /* the_reader */,
    const ::DDS::SampleLostStatus & /* status */)
  {
   
  }
  
  //============================================================
  // Component Executor Implementation Class: Broker_exec_i
  //============================================================
  
  Broker_exec_i::Broker_exec_i (void)
   {
    ACE_OS::srand (static_cast <u_int> (ACE_OS::time ()));
    this->ticker_ = new read_action_Generator (*this);
  }
  
  Broker_exec_i::~Broker_exec_i (void)
  {
    printf ("Broker_exec_i::~Broker_exec_i\n");
  }
  
  // Supported operations and attributes.
  
  // Component attributes.
  
  // Port operations.
  
  ::CCM_DDS::CCM_Stock_Info_RawListener_ptr
  Broker_exec_i::get_info_out_listener (void)
  {
    printf ("*************** out listener\n");
    return new Stock_Info_RawListener_exec_i ();
  }
  
  ::CCM_DDS::CCM_PortStatusListener_ptr
  Broker_exec_i::get_info_out_status (void)
  {
    /* Your code here. */
	 return ::CCM_DDS::CCM_PortStatusListener::_nil ();
  }
  
  // Operations from Components::SessionComponent.
  
  void
  Broker_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    ::Quoter::CCM_Broker_Context_var lctx = 
      ::Quoter::CCM_Broker_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (lctx.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
    
    this->context_ = lctx;
  }
  
  void
  Broker_exec_i::configuration_complete (void)
  {
    /* Your code here. */
    std::cerr << ">>> Broker_exec_i::configuration_complete" << endl;
    this->reader_ = this->context_->get_connection_info_out_data();
    this->ticker_->open_h ();
  }
      
 
  void
  Broker_exec_i::start (void)
  { 
	printf("start \n");
    std::cerr << ">>> Broker_exec_i::start" << endl;
    this->ticker_->start (500);
    printf("eind start \n");
  }
  void
  Broker_exec_i::stop (void)
  {
    std::cerr << ">>> Broker_exec_i::stop" << endl;
    this->ticker_->stop ();
  }
  void
  Broker_exec_i::ccm_activate (void)
  { 
    std::cerr << ">>> Broker_exec_i::ccm_activate" << endl;
    ::CCM_DDS::ListenerControl_var lc = 
    this->context_->get_connection_info_out_control ();
  
	if (CORBA::is_nil (lc.in ()))
    {
      printf ("Error:  Listener control receptacle is null!\n");
      throw CORBA::INTERNAL ();
    }
    //in case of testing RawListener set lc-> enabled true
    // lc->enabled (true);
   //in case of testing Reader set lc-> enabled false
    lc->enabled (false);
    this->start();



  }
  
  void
  Broker_exec_i::ccm_passivate (void)
  {
    std::cerr << ">>> Broker_exec_i::ccm_passivate" << endl;
    this->stop ();
  }

  void
  Broker_exec_i::ccm_remove (void)
  {
    std::cerr << ">>> Broker_exec_i::ccm_remove" << endl;
    this->ticker_->close_h ();
  }
  
  extern "C" BROKER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Broker_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    printf("in create Broker\n"); 
    ACE_NEW_NORETURN (
      retval,
      Broker_exec_i);
    
    return retval;
  }
}

