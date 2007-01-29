// $Id$

#include "ace/Stats.h"
#include "ace/Sample_History.h"
#include "ace/High_Res_Timer.h"
#include "CIAO_common.h"
#include "ace/Env_Value_T.h"

#include "RoundTripClient_exec.h"

const int niterations = 100000; //Default no of iterations
//=================================================================

MyImpl::RoundTripClient_exec_i::RoundTripClient_exec_i ()
{

}

MyImpl::RoundTripClient_exec_i::~RoundTripClient_exec_i ()
{
}

// Operations from Components::SessionComponent
void
MyImpl::RoundTripClient_exec_i::set_session_context (
    Components::SessionContext_ptr ctx)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG,
                "MyImpl::RoundTripClient_exec_i::set_session_context\n"));

  //Since this is in collocated mode; The server-component will change the
  //scheduling strategy to real-time scheduling

  this->context_ =
    Benchmark::CCM_RoundTripClient_Context::_narrow (ctx);

  if (CORBA::is_nil (this->context_.in ()))
    throw CORBA::INTERNAL ();

  // Urm, we actually discard exceptions thrown from this operation.
}

//Start the collocated test here
void
MyImpl::RoundTripClient_exec_i::ciao_preactivate ()
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
}

void
MyImpl::RoundTripClient_exec_i::ccm_activate ()
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG, "MyImpl::RoundTripClient_exec_i::ccm_activate\n"));
}

void
MyImpl::RoundTripClient_exec_i::ciao_postactivate ()
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
}

void
MyImpl::RoundTripClient_exec_i::start ()
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ///////////// Start test /////////////////////////////////////////

  // Let's try to start tests from here...
  Benchmark::LatencyTest_var lt =
    context_->get_connection_latency ();

  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG,
                "MyImpl::RoundTripClient_exec::start obtain obj ref\n"));

  CORBA::Long test_data = 0L;

  //Warm up the system
  int i = 0;
  for (i=0; i < 100; i++)
    lt->makeCall (test_data);

  ACE_DEBUG ((LM_DEBUG, "MyImpl::start: warmed up the system\n"));

  ACE_Sample_History history (niterations);

  ACE_hrtime_t test_start = ACE_OS::gethrtime ();
  for (i = 0; i < niterations; ++i)
    {
      ACE_hrtime_t start = ACE_OS::gethrtime ();

      //Test value to be sent to the server
      long test = 0;

      (void) lt->makeCall (test);

      ACE_hrtime_t now = ACE_OS::gethrtime ();
      history.sample (now - start);
    }

  ACE_hrtime_t test_end = ACE_OS::gethrtime ();

  ACE_DEBUG ((LM_DEBUG, "test finished\n"));

  ACE_DEBUG ((LM_DEBUG, "High resolution timer calibration...."));
  ACE_UINT32 gsf = ACE_High_Res_Timer::global_scale_factor ();
  ACE_DEBUG ((LM_DEBUG, "done\n"));

  ACE_Env_Value<int> envar ("CIAO_DUMP_SAMPLE_HISTORY", 0);
  if (envar != 0)
    {
      history.dump_samples ("HISTORY", gsf);
    }

  ACE_Basic_Stats stats;
  history.collect_basic_stats (stats);
  stats.dump_results ("Total", gsf);

  ACE_Throughput_Stats::dump_throughput ("Total", gsf,
					 test_end - test_start,
					 stats.samples_count ());

}

::Benchmark::CCM_Controller_ptr
MyImpl::RoundTripClient_exec_i::get_controller ()
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return ::Benchmark::CCM_Controller::_duplicate (this);
}


void
MyImpl::RoundTripClient_exec_i::ccm_passivate ()
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG, "MyImpl::RoundTripClient_exec_i::ccm_passivate\n"));
}

void
MyImpl::RoundTripClient_exec_i::ccm_remove ()
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG, "MyImpl::RoundTripClient_exec_i::ccm_remove\n"));
}


MyImpl::RoundTripClientHome_exec_i::RoundTripClientHome_exec_i ()
{
}

MyImpl::RoundTripClientHome_exec_i::~RoundTripClientHome_exec_i ()
{
}

::Components::EnterpriseComponent_ptr
MyImpl::RoundTripClientHome_exec_i::create ()
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  return new MyImpl::RoundTripClient_exec_i;
}


extern "C" ROUNDTRIPCLIENT_EXEC_Export ::Components::HomeExecutorBase_ptr
createRoundTripClientHome_Impl (void)
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG, "Creating RoundTrip_client impl \n"));
  return new MyImpl::RoundTripClientHome_exec_i ();
}
