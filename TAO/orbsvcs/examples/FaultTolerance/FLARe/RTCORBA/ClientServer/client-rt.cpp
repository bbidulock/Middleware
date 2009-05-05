// $Id$

#include <sstream>
#include <fstream>
#include "WorkerC.h"
#include "orbsvcs/orbsvcs/LWFT/LWFT_Client_Init.h"

#include "ace/Get_Opt.h"
#include "ace/High_Res_Timer.h"
#include "ace/Stats.h"
#include "ace/Sample_History.h"
#include "ace/Read_Buffer.h"
#include "ace/Array_Base.h"
#include "ace/Task.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Throughput_Stats.h"

#include "tao/ORB_Core.h"
#include "tao/debug.h"
#include "tao/RTCORBA/RTCORBA.h"
#include "tao/RTCORBA/Priority_Mapping_Manager.h"
#include "tests/RTCORBA/common_args.cpp"
#include "tests/RTCORBA/check_supported_priorities.cpp"
#include "ace/Event.h"

#include "ace/Barrier.h"
#include <vector>
#include <fstream>
#include <algorithm>

enum Priority_Setting
{
  AT_THREAD_CREATION = 0,
  AFTER_THREAD_CREATION = 1
};

static const char *ior = "file://test.ior";
static const char *rates_file = "rates";
static const char *invocation_priorities_file = "empty-file";
static int shutdown_server = 0;
static int do_dump_history = 0;
static const char *history_file_name;
static ACE_UINT32 gsf = 0;
static int done = 0;
static CORBA::ULong time_for_test = 10;
static CORBA::ULong work = 10;
static CORBA::ULong max_throughput_timeout = 5;
static CORBA::ULong continuous_worker_priority = 0;
static int set_priority = 1;
static Priority_Setting priority_setting = AFTER_THREAD_CREATION;
static int individual_continuous_worker_stats = 0;
static int print_missed_invocations = 0;
static ACE_hrtime_t test_start;
static CORBA::ULong prime_number = 9619;
static int count_missed_end_deadlines = 0;

const char *agent_ior_file = "agent.ior";
const char *rm_ior = "file://rm.ior";
std::vector <int> sample_vector (3100);
size_t count = 0;
const char *dummy_file_name = "temp1";
std::string server_id = "server";
std::string prefix = "";
bool logging = false;
bool kill_me = false;

int
check_for_nil (CORBA::Object_ptr obj, const char *msg)
{
  if (CORBA::is_nil (obj))
    ACE_ERROR_RETURN ((LM_ERROR,
                       "ERROR: Object reference <%C> is nil\n",
                       msg),
                      -1);
  else
    return 0;
}

struct Synchronizers
{
  Synchronizers (void)
    : worker_lock_ (),
      workers_ (1),
      workers_ready_ (0),
      number_of_workers_ (0)
  {
  }

  ACE_SYNCH_MUTEX worker_lock_;
  ACE_Event workers_;
  CORBA::ULong workers_ready_;
  CORBA::ULong number_of_workers_;
};

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv,
                        ACE_TEXT ("e:g:hk:m:p:q:r:t:v:w:x:y:z:a:") 
                        );
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'e':
        count_missed_end_deadlines =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'g':
        do_dump_history =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'k':
        ior =
          get_opts.opt_arg ();
        break;

      case 'm':
        print_missed_invocations =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'p':
        invocation_priorities_file =
          get_opts.opt_arg ();
        break;

      case 'q':
        prime_number =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'r':
        rates_file =
          get_opts.opt_arg ();
        break;

      case 't':
        time_for_test =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'v':
        priority_setting =
          Priority_Setting (ACE_OS::atoi (get_opts.opt_arg ()));
        break;

      case 'w':
        work =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'x':
        shutdown_server =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'y':
        set_priority =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'z':
        max_throughput_timeout =
          ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'a':
        history_file_name = get_opts.opt_arg();
        break;

      case 'h':
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s\n"
                           "\t-c <number of continuous workers> (defaults to %d)\n"
                           "\t-e <count missed end deadlines> (defaults to %d)\n"
                           "\t-g <show history> (defaults to %d)\n"
                           "\t-h <help: shows options menu>\n"
                           "\t-i <print stats of individual continuous workers> (defaults to %d)\n"
                           "\t-k <ior> (defaults to %s)\n"
                           "\t-m <print missed invocations for paced workers> (defaults to %d)\n"
                           "\t-p <invocation priorities file> (defaults to %s)\n"
                           "\t-q <prime number> (defaults to %d)\n"
                           "\t-r <rates file> (defaults to %s)\n"
                           "\t-t <time for test> (defaults to %d)\n"
                           "\t-v <priority setting: AT_THREAD_CREATION = 0, AFTER_THREAD_CREATION = 1> (defaults to %s)\n"
                           "\t-w <work> (defaults to %d)\n"
                           "\t-x <shutdown server> (defaults to %d)\n"
                           "\t-y <set invocation priorities> (defaults to %d)\n"
                           "\t-z <timeout for max throughput measurement> (defaults to %d)\n"
                           "\n",
                           argv [0],
                           count_missed_end_deadlines,
                           do_dump_history,
                           individual_continuous_worker_stats,
                           ior,
                           print_missed_invocations,
                           invocation_priorities_file,
                           prime_number,
                           rates_file,
                           time_for_test,
                           continuous_worker_priority,
                           priority_setting == 0 ? "AT_THREAD_CREATION" : "AFTER_THREAD_CREATION",
                           work,
                           shutdown_server,
                           set_priority,
                           max_throughput_timeout),
                          -1);
      }

  return 0;
}

double
to_seconds (ACE_UINT64 hrtime,
            ACE_UINT32 sf)
{
  double seconds =
#if defined ACE_LACKS_LONGLONG_T
    hrtime / sf;
#else  /* ! ACE_LACKS_LONGLONG_T */
  static_cast<double> (ACE_UINT64_DBLCAST_ADAPTER (hrtime / sf));
#endif /* ! ACE_LACKS_LONGLONG_T */
  seconds /= ACE_HR_SCALE_CONVERSION;

  return seconds;
}

ACE_UINT64
to_hrtime (double seconds,
           ACE_UINT32 sf)
{
  return ACE_UINT64 (seconds * sf * ACE_HR_SCALE_CONVERSION);
}

int
start_synchronization (DeCoRAM::Worker_ptr test,
                       Synchronizers &synchronizers)
{
  CORBA::ULong synchronization_iterations = 1;
  try
    {
      for (CORBA::ULong i = 0;
           i < synchronization_iterations;
           ++i)
        {
          test->run_task (2, true);
        }
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return -1;
    }

  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX,
                      mon,
                      synchronizers.worker_lock_,
                      -1);

    if (synchronizers.workers_ready_ == 0)
      {
        if (TAO_debug_level > 0)
          ACE_DEBUG ((LM_DEBUG,
                      "\n"));
      }

    ++synchronizers.workers_ready_;

    if (TAO_debug_level > 0)
      ACE_DEBUG ((LM_DEBUG,
                  "%d worker ready\n",
                  synchronizers.workers_ready_));

    if (synchronizers.workers_ready_ ==
        synchronizers.number_of_workers_)
      {
        if (TAO_debug_level > 0)
          ACE_DEBUG ((LM_DEBUG,
                      "\n"));

        test_start =
          ACE_OS::gethrtime ();

        synchronizers.workers_.signal ();

        return 0;
      }
  }

  synchronizers.workers_.wait ();

  return 0;
}

int
end_synchronization (Synchronizers &synchronizers)
{
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX,
                      mon,
                      synchronizers.worker_lock_,
                      -1);

    if (synchronizers.workers_ready_ ==
        synchronizers.number_of_workers_)
      {
        if (TAO_debug_level > 0)
          ACE_DEBUG ((LM_DEBUG,
                      "\n"));

        synchronizers.workers_.reset ();
      }

    if (TAO_debug_level > 0)
      ACE_DEBUG ((LM_DEBUG,
                  "%d worker completed\n",
                  synchronizers.workers_ready_));

    --synchronizers.workers_ready_;

    if (synchronizers.workers_ready_ == 0)
      {
        if (TAO_debug_level > 0)
          ACE_DEBUG ((LM_DEBUG,
                      "\n"));

        synchronizers.workers_.signal ();

        return 0;
      }
  }

  synchronizers.workers_.wait ();

  return 0;
}

int
max_throughput (DeCoRAM::Worker_ptr test,
                RTCORBA::Current_ptr current,
                RTCORBA::PriorityMapping &priority_mapping,
                CORBA::ULong &max_rate)
{
  CORBA::ULong calls_made = 0;
  CORBA::Short CORBA_priority = 0;
  CORBA::Short native_priority = 0;

  try
    {
      CORBA_priority =
        current->the_priority ();

      CORBA::Boolean result =
        priority_mapping.to_native (CORBA_priority,
                                    native_priority);
      if (!result)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Error in converting CORBA priority %d to native priority\n",
                           CORBA_priority),
                          -1);

      ACE_hrtime_t start =
        ACE_OS::gethrtime ();

      ACE_hrtime_t end =
        start +
        to_hrtime (max_throughput_timeout, gsf);

      for (;;)
        {
          ACE_hrtime_t now =
            ACE_OS::gethrtime ();

          if (now > end)
            break;

          test->run_task (2, true);

          ++calls_made;
        }
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return -1;
    }

  max_rate =
    calls_made / max_throughput_timeout;

  ACE_DEBUG ((LM_DEBUG,
              "\nPriority = %d/%d; Max rate calculations => %d calls in %d seconds; Max rate = %.2f\n",
              CORBA_priority,
              native_priority,
              calls_made,
              max_throughput_timeout,
              calls_made / (double) max_throughput_timeout));

  return 0;
}

class Paced_Worker :
  public ACE_Task_Base
{
public:
  Paced_Worker (ACE_Thread_Manager &thread_manager,
                DeCoRAM::Worker_ptr test,
                CORBA::Short rate,
                CORBA::ULong iterations,
                CORBA::Short priority,
                RTCORBA::Current_ptr current,
                RTCORBA::PriorityMapping &priority_mapping,
                Synchronizers &synchronizers);

  int svc (void);
  ACE_hrtime_t deadline_for_current_call (CORBA::ULong i);
  void reset_priority (void);
  void print_stats (ACE_hrtime_t test_end);
  int setup (void);
  void missed_start_deadline (CORBA::ULong invocation);
  void missed_end_deadline (CORBA::ULong invocation);

  DeCoRAM::Worker_var test_;
  int rate_;
  ACE_Sample_History history_;
  CORBA::Short priority_;
  RTCORBA::Current_var current_;
  RTCORBA::PriorityMapping &priority_mapping_;
  Synchronizers &synchronizers_;
  CORBA::Short CORBA_priority_;
  CORBA::Short native_priority_;
  ACE_hrtime_t interval_between_calls_;
  CORBA::ULong missed_start_deadlines_;
  CORBA::ULong missed_end_deadlines_;

  typedef ACE_Array_Base<CORBA::ULong> Missed_Invocations;
  Missed_Invocations missed_start_invocations_;
  Missed_Invocations missed_end_invocations_;
};

Paced_Worker::Paced_Worker (ACE_Thread_Manager &thread_manager,
                            DeCoRAM::Worker_ptr test,
                            CORBA::Short rate,
                            CORBA::ULong iterations,
                            CORBA::Short priority,
                            RTCORBA::Current_ptr current,
                            RTCORBA::PriorityMapping &priority_mapping,
                            Synchronizers &synchronizers)
  : ACE_Task_Base (&thread_manager),
    test_ (DeCoRAM::Worker::_duplicate (test)),
    rate_ (rate),
    history_ (iterations),
    priority_ (priority),
    current_ (RTCORBA::Current::_duplicate (current)),
    priority_mapping_ (priority_mapping),
    synchronizers_ (synchronizers),
    CORBA_priority_ (0),
    native_priority_ (0),
    interval_between_calls_ (),
    missed_start_deadlines_ (0),
    missed_end_deadlines_ (0),
    missed_start_invocations_ (iterations),
    missed_end_invocations_ (iterations)
{
  this->interval_between_calls_ =
    to_hrtime (1 / double (this->rate_), gsf);
}

void
Paced_Worker::reset_priority (void)
{
  if (set_priority)
    {
      this->current_->the_priority (this->priority_);
    }
  else
    {
      this->current_->the_priority (continuous_worker_priority);
    }
}

ACE_hrtime_t
Paced_Worker::deadline_for_current_call (CORBA::ULong i)
{
  ACE_hrtime_t deadline_for_current_call =
    this->interval_between_calls_;

  deadline_for_current_call *= i;

  deadline_for_current_call += test_start;

  return deadline_for_current_call;
}

void
Paced_Worker::print_stats (ACE_hrtime_t test_end)
{
  ACE_GUARD (ACE_SYNCH_MUTEX,
             mon,
             this->synchronizers_.worker_lock_);

  CORBA::ULong missed_total_deadlines =
    this->missed_start_deadlines_ + this->missed_end_deadlines_;

  CORBA::ULong made_total_deadlines =
    this->history_.max_samples () - missed_total_deadlines;

  ACE_DEBUG ((LM_DEBUG,
              "\n************ Statistics for thread %t ************\n\n"));

  ACE_DEBUG ((LM_DEBUG,
              "Priority = %d/%d; Rate = %d/sec; Iterations = %d; ",
              this->CORBA_priority_,
              this->native_priority_,
              this->rate_,
              this->history_.max_samples ()));

  if (count_missed_end_deadlines)
    ACE_DEBUG ((LM_DEBUG,
                "Deadlines made/missed[start,end]/%% = %d/%d[%d,%d]/%.2f%%; Effective Rate = %.2f\n",
                made_total_deadlines,
                missed_total_deadlines,
                this->missed_start_deadlines_,
                this->missed_end_deadlines_,
                made_total_deadlines * 100 / (double) this->history_.max_samples (),
                made_total_deadlines / to_seconds (test_end - test_start, gsf)));
  else
    ACE_DEBUG ((LM_DEBUG,
                "Deadlines made/missed/%% = %d/%d/%.2f%%; Effective Rate = %.2f\n",
                made_total_deadlines,
                missed_total_deadlines,
                made_total_deadlines * 100 / (double) this->history_.max_samples (),
                made_total_deadlines / to_seconds (test_end - test_start, gsf)));


  if (do_dump_history)
    {
      //this->history_.dump_samples (history_file_name, gsf);
      std::ofstream output_file (history_file_name);
      std::copy (sample_vector.begin(), sample_vector.end(), 
                 std::ostream_iterator <int> (output_file, "\n"));
    }

  ACE_Basic_Stats stats;
  this->history_.collect_basic_stats (stats);
  stats.dump_results ("Total", gsf);

  ACE_Throughput_Stats::dump_throughput ("Total", gsf,
                                         test_end - test_start,
                                         stats.samples_count ());

  if (print_missed_invocations)
    {
      ACE_DEBUG ((LM_DEBUG, "\nMissed start invocations are: "));

      for (CORBA::ULong j = 0;
           j != this->missed_start_deadlines_;
           ++j)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "%d ",
                      this->missed_start_invocations_[j]));
        }

      ACE_DEBUG ((LM_DEBUG, "\n"));

      if (count_missed_end_deadlines)
        {
          ACE_DEBUG ((LM_DEBUG, "\nMissed end invocations are: "));

          for (CORBA::ULong j = 0;
               j != this->missed_end_deadlines_;
               ++j)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "%d ",
                          this->missed_end_invocations_[j]));
            }

          ACE_DEBUG ((LM_DEBUG, "\n"));
        }
    }
}

int
Paced_Worker::setup (void)
{
  if (priority_setting == AFTER_THREAD_CREATION)
    {
      this->reset_priority ();
    }

  this->CORBA_priority_ =
    this->current_->the_priority ();

  CORBA::Boolean result =
    this->priority_mapping_.to_native (this->CORBA_priority_,
                                       this->native_priority_);
  if (!result)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error in converting CORBA priority %d to native priority\n",
                       this->CORBA_priority_),
                      -1);

  return
    start_synchronization (this->test_.in (),
                           this->synchronizers_);
}

void
Paced_Worker::missed_start_deadline (CORBA::ULong invocation)
{
  this->missed_start_invocations_[this->missed_start_deadlines_++] =
    invocation;
}

void
Paced_Worker::missed_end_deadline (CORBA::ULong invocation)
{
  if (count_missed_end_deadlines)
    this->missed_end_invocations_[this->missed_end_deadlines_++] =
      invocation;
}

int
Paced_Worker::svc (void)
{
  try
    {
      ACE_UINT32 gsf = ACE_High_Res_Timer::global_scale_factor (); 
      size_t terminate_count =  this->history_.max_samples () / 2;
      int result =
        this->setup ();

      if (result != 0)
        return result;

      CORBA::ULong testing_start = 0;
      CORBA::ULong testing_end = 0;
      CORBA::ULong end_iteration = this->history_.max_samples () - 1;

      for (CORBA::ULong i = 0;
           i != this->history_.max_samples ();
           ++i)
        {
          ACE_hrtime_t deadline_for_current_call =
            this->deadline_for_current_call (i);

          ACE_hrtime_t time_before_call =
            ACE_OS::gethrtime ();

          if (time_before_call > deadline_for_current_call)
            {
              this->missed_start_deadline (i + 1);
              continue;
            }

          if (i == 0)
            {
              testing_start = 1;
            }
          else if (i == end_iteration)
            {
              testing_end = 1;
            }

          if (i == terminate_count)
          {
            // sample_vector[count++] = 0;
            this->test_->method (prime_number, 1);
          }
          else
          {
            this->test_->method (prime_number, 0);
          }

          ACE_hrtime_t time_after_call =
            ACE_OS::gethrtime ();
          this->history_.sample (time_after_call - time_before_call);
          // sample_vector[count++] = ((time_after_call - time_before_call) / gsf);

          if (time_after_call > deadline_for_current_call)
            {
              this->missed_end_deadline (i + 1);
              continue;
            }

          ACE_hrtime_t sleep_time =
            deadline_for_current_call - time_after_call;

          ACE_OS::sleep (ACE_Time_Value (0,
                                         long (to_seconds (sleep_time, gsf) *
                                               ACE_ONE_SECOND_IN_USECS)));
        }

      ACE_hrtime_t test_end = ACE_OS::gethrtime ();

      done = 1;

      end_synchronization (this->synchronizers_);

      this->print_stats (test_end);

      ACE_DEBUG ((LM_DEBUG, "******************************\n"));

      //      this->test_->dump ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return -1;
    }

  return 0;
}

class Task : public ACE_Task_Base
{
public:

  Task (ACE_Thread_Manager &thread_manager,
        CORBA::ORB_ptr orb);

  int svc (void);

  CORBA::ORB_var orb_;

};

Task::Task (ACE_Thread_Manager &thread_manager,
            CORBA::ORB_ptr orb)
  : ACE_Task_Base (&thread_manager),
    orb_ (CORBA::ORB::_duplicate (orb))
{
}

int
Task::svc (void)
{
  Synchronizers synchronizers;

  gsf = ACE_High_Res_Timer::global_scale_factor ();

  try
    {
      CORBA::Object_var object =
        this->orb_->string_to_object (ior);

      DeCoRAM::Worker_var server1 = DeCoRAM::Worker::_narrow (object.in ());

      if (check_for_nil (server1.in (), "server1") == -1)
        return -1;

      object =
        this->orb_->resolve_initial_references ("RTCurrent");

      RTCORBA::Current_var current =
        RTCORBA::Current::_narrow (object.in ());

      object =
        this->orb_->resolve_initial_references ("PriorityMappingManager");

      RTCORBA::PriorityMappingManager_var mapping_manager =
        RTCORBA::PriorityMappingManager::_narrow (object.in ());

      RTCORBA::PriorityMapping &priority_mapping =
        *mapping_manager->mapping ();

      ULong_Array rates;
      int result =
        get_values ("client",
                    rates_file,
                    "rates",
                    rates,
                    1);
      if (result != 0)
        return result;

      ULong_Array invocation_priorities;
      result =
        get_values ("client",
                    invocation_priorities_file,
                    "invocation priorities",
                    invocation_priorities,
                    1);
      if (result != 0)
        return result;

      if (invocation_priorities.size () != 0 &&
          invocation_priorities.size () != rates.size ())
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Number of invocation priorities (%d) != Number of rates (%d)\n",
                           invocation_priorities.size (),
                           rates.size ()),
                          -1);

      synchronizers.number_of_workers_ =
        rates.size ();

      CORBA::ULong max_rate = 0;
      result =
        max_throughput (server1.in (),
                        current.in (),
                        priority_mapping,
                        max_rate);
      if (result != 0)
        return result;

      CORBA::Short priority_range =
        RTCORBA::maxPriority - RTCORBA::minPriority;

      ACE_Thread_Manager paced_workers_manager;

      CORBA::ULong i = 0;
      Paced_Worker **paced_workers =
        new Paced_Worker *[rates.size ()];

      for (i = 0;
           i < rates.size ();
           ++i)
        {
          CORBA::Short priority = 0;

          if (invocation_priorities.size () == 0)
            priority =
              CORBA::Short ((priority_range /
                             double (rates.size ())) *
                            (i + 1));
          else
            priority =
              invocation_priorities[i];

          paced_workers[i] =
            new Paced_Worker (paced_workers_manager,
                              server1.in (),
                              rates[i],
                              time_for_test * rates[i],
                              priority,
                              current.in (),
                              priority_mapping,
                              synchronizers);
        }

      CORBA::Short CORBA_priority;
      CORBA::Short native_priority;
      CORBA::Boolean convert_result;
      int force_active = 0;
      
      long flags =
        THR_NEW_LWP |
        THR_JOINABLE |
        this->orb_->orb_core ()->orb_params ()->thread_creation_flags ();

      for (i = 0;
           i < rates.size ();
           ++i)
        {
          if (priority_setting == AT_THREAD_CREATION)
            {
              if (set_priority)
                {
                  CORBA_priority =
                    paced_workers[i]->priority_;

                  convert_result =
                    priority_mapping.to_native (CORBA_priority,
                                                native_priority);
                  if (!convert_result)
                    ACE_ERROR_RETURN ((LM_ERROR,
                                       "Error in converting CORBA priority %d to native priority\n",
                                       CORBA_priority),
                                      -1);
                }

              result =
                paced_workers[i]->activate (flags,
                                            1,
                                            force_active,
                                            native_priority);
              if (result != 0)
                ACE_ERROR_RETURN ((LM_ERROR,
                                   "Paced_Worker::activate failed\n"),
                                  result);
            }
          else
            {
              
              result =
                paced_workers[i]->activate (flags);
              if (result != 0)
                ACE_ERROR_RETURN ((LM_ERROR,
                                   "Paced_Worker::activate failed\n"),
                                  result);
            }
        }

      if (rates.size () != 0)
        {
          paced_workers_manager.wait ();
        }

      for (i = 0;
           i < rates.size ();
           ++i)
        {
          delete paced_workers[i];
        }
      delete[] paced_workers;

      if (shutdown_server)
        {
          server1->stop ();
        }
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return -1;
    }

  return 0;
}

int
main (int argc, char *argv[])
{
  try
    {
      LWFT_Client_Init ci;
      CORBA::ORB_var orb = ci.init (argc, argv);

      int result =
        parse_args (argc, argv);
      if (result != 0)
        return result;

      // Make sure we can support multiple priorities that are required
      // for this test.
      check_supported_priorities (orb.in ());

      // Thread Manager for managing task.
      ACE_Thread_Manager thread_manager;

      ACE_Barrier thread_barrier (2);

      // Create task.
      Task task (thread_manager,
                 orb.in ());

      // Task activation flags.
      long flags =
        THR_NEW_LWP |
        THR_JOINABLE |
        orb->orb_core ()->orb_params ()->thread_creation_flags ();
      
      // Activate task.
      result =
        task.activate (flags);
      ACE_ASSERT (result != -1);
      ACE_UNUSED_ARG (result);

      // Wait for task to exit.
      result =
        thread_manager.wait ();
      ACE_ASSERT (result != -1);
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return -1;
    }

  return 0;
}
