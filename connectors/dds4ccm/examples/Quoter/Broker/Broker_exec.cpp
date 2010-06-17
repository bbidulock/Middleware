// -*- C++ -*-
//
// $Id$

#include "Broker_exec.h"
#include "ace/Reactor.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_unistd.h"
#include "tao/ORB_Core.h"

namespace CIAO_Quoter_Broker_Impl
{
  void
  Broker_exec_i::read_one (void)
  {
    ACE_DEBUG ((LM_DEBUG, "read_one\n"));

    ::Quoter::Stock_Info  stock_info;
    stock_info.symbol= "IBM";
    ::CCM_DDS::ReadInfo readinfo;

    try
      {
        ::Quoter::Reader_var reader =
          this->context_->get_connection_info_out_data();

        reader->read_one_last (stock_info, readinfo, ::DDS::HANDLE_NIL);
        time_t const tim = readinfo.source_timestamp.sec;
        ACE_DEBUG ((LM_DEBUG, "Read_Info. -> date = %C\n", ACE_OS::ctime (&tim)));
        ACE_DEBUG ((LM_DEBUG, "Stock_Info_Read_One: received a stock_info for <%C> at %u:%u:%u\n",
            stock_info.symbol.in (),
            stock_info.low,
            stock_info.current,
            stock_info.high));
      }
    catch (const CCM_DDS::NonExistent& )
      {
        ACE_DEBUG ((LM_DEBUG, "Stock_Info_Read_One: no stock_info received\n"));
      }
  }

  void
  Broker_exec_i::read_all (void)
  {
    ACE_DEBUG ((LM_DEBUG, "read_all\n"));

    ::Quoter::Reader_var reader =
      this->context_->get_connection_info_out_data();

    ::Quoter::Stock_InfoSeq stock_infos;
    ::CCM_DDS::ReadInfoSeq readinfoseq;
    reader->read_all(stock_infos, readinfoseq);
    if(readinfoseq.length()!= 0)
      {
        for(CORBA::ULong i = 0; i < readinfoseq.length(); i ++)
          {
            time_t const tim = readinfoseq[i].source_timestamp.sec;
            ACE_DEBUG ((LM_DEBUG,
                        "Read_Info.source_timestamp -> date = %C\n",
                        ACE_OS::ctime (&tim)));
          }
      }
    if(stock_infos.length()!= 0)
      {
        for(CORBA::ULong i = 0; i < stock_infos.length(); i ++)
          {
            ACE_DEBUG ((LM_DEBUG,
                        "Stock_Info_Read_All: Number %d : received a stock_info for <%C> at %u:%u:%u\n",
                i,
                stock_infos[i].symbol.in (),
                stock_infos[i].low,
                stock_infos[i].current,
                stock_infos[i].high));
          }
      }
  }
  void
  Broker_exec_i::read_all_history (void)
  {
    ACE_DEBUG ((LM_DEBUG, "read_all_history\n"));

    ::Quoter::Reader_var reader =
      this->context_->get_connection_info_out_data();

    ::Quoter::Stock_InfoSeq stock_infos;
    ::CCM_DDS::ReadInfoSeq readinfoseq;
    reader->read_all(stock_infos, readinfoseq);
    if (readinfoseq.length()!= 0)
      {
        for (CORBA::ULong i = 0; i < readinfoseq.length(); i ++)
          {
            time_t const tim = readinfoseq[i].source_timestamp.sec;
            ACE_DEBUG ((LM_DEBUG,
                        "Read_Info.source_timestamp -> date = %C\n",
                        ACE_OS::ctime (&tim)));
          }
      }
    if (stock_infos.length() != 0)
      {
        for (CORBA::ULong i = 0; i < stock_infos.length(); i ++)
          {
            ACE_DEBUG ((LM_DEBUG, "Stock_Info_Read_All_History: Number %d : received a stock_info for <%C> at %u:%u:%u\n",
                i,
                stock_infos[i].symbol.in (),
                stock_infos[i].low,
                stock_infos[i].current,
                stock_infos[i].high));
          }
      }
  }
  // read all samples of an given instance
  void
  Broker_exec_i::read_one_history (void)
  {
    ACE_DEBUG ((LM_DEBUG, "read_one_history\n"));
    ::Quoter::Stock_Info  stock_info;
    stock_info.symbol= "IBM";  //key of instance to read

    ::Quoter::Stock_InfoSeq stock_infos;
    ::CCM_DDS::ReadInfoSeq readinfoseq;
    try
      {
        ::Quoter::Reader_var reader =
          this->context_->get_connection_info_out_data();

        reader->read_one_all(stock_info,stock_infos, readinfoseq, ::DDS::HANDLE_NIL);
        if (readinfoseq.length()!= 0)
          {
            for (CORBA::ULong i = 0; i < readinfoseq.length(); i ++)
              {
                time_t const tim = readinfoseq[i].source_timestamp.sec;
                ACE_DEBUG ((LM_DEBUG,
                            "Read_Info.source_timestamp -> date = %C\n",
                            ACE_OS::ctime (&tim)));
              }
          }
        if(stock_infos.length()!= 0)
          {
            for (CORBA::ULong i = 0; i < stock_infos.length(); i ++)
              {
                ACE_DEBUG ((LM_DEBUG,
                            "Stock_Info_Read_One_History: Number %d : received a stock_info for <%C> at %u:%u:%u\n",
                    i,
                    stock_infos[i].symbol.in (),
                    stock_infos[i].low,
                    stock_infos[i].current,
                    stock_infos[i].high));
              }
          }
      }
    catch (const CCM_DDS::NonExistent& )
      {
         ACE_DEBUG ((LM_DEBUG, "Stock_Info_Read_One_History: no stock_info's received\n"));
      }
  }
  //============================================================
  // Facet Executor Implementation Class: Stock_Info_Listener_exec_i
  //============================================================

  Stock_Info_Listener_exec_i::Stock_Info_Listener_exec_i (void)
  {
  }

  Stock_Info_Listener_exec_i::~Stock_Info_Listener_exec_i (void)
  {
  }

  void
  Stock_Info_Listener_exec_i::on_many_data (
    const ::Quoter::Stock_InfoSeq & /* an_instance */,
    const ::CCM_DDS::ReadInfoSeq & /* info */)
  {
  }

  void
  Stock_Info_Listener_exec_i::on_one_data (
    const ::Quoter::Stock_Info & an_instance,
    const ::CCM_DDS::ReadInfo & /* info */)
  {
    ACE_DEBUG ((LM_DEBUG, "Stock_Info_Listener: received a stock_info for <%C> at %u:%u:%u\n",
            an_instance.symbol.in (),
            an_instance.low,
            an_instance.current,
            an_instance.high));
  }
  //============================================================
  // Facet Executor Implementation Class: PortStatusListener_exec_i
  //============================================================

  PortStatusListener_exec_i::PortStatusListener_exec_i (void)
  {
    ACE_DEBUG ((LM_DEBUG, "####### construct PortStatusListener ######\n"));
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
    ACE_DEBUG ((LM_DEBUG, "####### deadline missed ######\n"));
  }

  void
  PortStatusListener_exec_i::on_sample_lost (
    ::DDS::DataReader_ptr  /*the_reader*/ ,
    const ::DDS::SampleLostStatus &  status )
  {
    ACE_DEBUG ((LM_DEBUG, "####### sample lost ######\n"));
    ACE_DEBUG ((LM_DEBUG, " status.total_count = %d\n", status.total_count));
    ACE_DEBUG ((LM_DEBUG, " status.total_count_change = %d\n", status.total_count_change));
  }

  //============================================================
  // Component Executor Implementation Class: Broker_exec_i
  //============================================================

  Broker_exec_i::Broker_exec_i (void)
  {
    ACE_OS::srand (static_cast <u_int> (ACE_OS::time ()));
  }

  Broker_exec_i::~Broker_exec_i (void)
  {
    ACE_DEBUG ((LM_DEBUG, "Broker_exec_i::~Broker_exec_i\n"));
  }

  // Supported operations and attributes.

  // Component attributes.

  // Port operations.

  ::Quoter::CCM_Listener_ptr
  Broker_exec_i::get_info_out_data_listener (void)
  {
    ACE_DEBUG ((LM_DEBUG, "*************** out listener\n"));
    return new Stock_Info_Listener_exec_i ();
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Broker_exec_i::get_info_out_status (void)
  {
    ACE_DEBUG ((LM_DEBUG, "*************** out status************************\n"));
    return new PortStatusListener_exec_i ();
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
    ACE_DEBUG ((LM_DEBUG, ">>> Broker_exec_i::configuration_complete\n"));
  }

  void
  Broker_exec_i::start (void)
  {
    ACE_DEBUG ((LM_DEBUG, ">>> Broker_exec_i::start\n"));
  }

  void
  Broker_exec_i::stop (void)
  {
    ACE_DEBUG ((LM_DEBUG, ">>> Broker_exec_i::stop\n"));
  }

  void
  Broker_exec_i::ccm_activate (void)
  {
    ACE_DEBUG ((LM_DEBUG, ">>> Broker_exec_i::ccm_activate\n"));
    ::CCM_DDS::DataListenerControl_var lc =
    this->context_->get_connection_info_out_data_control ();

    if (::CORBA::is_nil (lc.in ()))
      {
        ACE_DEBUG ((LM_DEBUG, "Error:  Listener control receptacle is null!\n"));
        throw CORBA::INTERNAL ();
      }
    //in case of testing Listener set lc-> enabled true
    lc->mode ( ::CCM_DDS::ONE_BY_ONE);
    //in case of testing Reader set lc-> enabled false, so the Listener doesn't consume all the messages
    //lc->enabled (false);
    this->start();
  }

  void
  Broker_exec_i::ccm_passivate (void)
  {
    ACE_DEBUG ((LM_DEBUG, ">>> Broker_exec_i::ccm_passivate\n"));
    this->stop ();
  }

  void
  Broker_exec_i::ccm_remove (void)
  {
    ACE_DEBUG ((LM_DEBUG, ">>> Broker_exec_i::ccm_remove\n"));
  }

  extern "C" BROKER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Broker_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    ACE_DEBUG ((LM_DEBUG, "in create Broker\n"));
    ACE_NEW_NORETURN (
      retval,
      Broker_exec_i);

    return retval;
  }
}
