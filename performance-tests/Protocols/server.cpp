// $Id$

#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/Sample_History.h"
#include "ace/High_Res_Timer.h"
#include "ace/Stats.h"
#include "tao/debug.h"
#include "testS.h"

static const char *ior_file = "ior";
static int do_dump_history = 0;
static int print_missed_invocations = 0;
static ACE_UINT32 gsf = 0;

static int
parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "d:f:m:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':
        do_dump_history = ACE_OS::atoi (get_opts.opt_arg ());
        break;

      case 'f':
        ior_file = get_opts.opt_arg ();
        break;

      case 'm':
        print_missed_invocations = ACE_OS::atoi (get_opts.opt_arg ());
        break;

      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage: %s\n"
                           "\t-d <show history> (defaults to %d)\n"
                           "\t-f <ior_file> (defaults to %s)\n"
                           "\t-m <print missed invocations for paced workers> (defaults to %d)\n"
                           "\n",
                           argv[0],
                           do_dump_history,
                           ior_file,
                           print_missed_invocations),
                          -1);
      }

  return 0;
}

class test_i :
  public POA_test,
  public PortableServer::RefCountServantBase
{
public:
  test_i (CORBA::ORB_ptr orb,
          PortableServer::POA_ptr poa);

  ~test_i (void);

  void start_test (CORBA::ULong iterations
                   ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void end_test (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void method (CORBA::ULong iteration,
               const ::test::octets &payload
               ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  PortableServer::POA_ptr _default_POA (ACE_ENV_SINGLE_ARG_DECL);

private:
  CORBA::ORB_var orb_;
  PortableServer::POA_var poa_;
  typedef ACE_Array_Base<CORBA::Boolean> Invocations;
  Invocations invocations_received_;
  ACE_hrtime_t time_of_last_call_;
  ACE_hrtime_t test_start_;
  ACE_hrtime_t test_end_;
  CORBA::Boolean first_invocation_;
  ACE_Sample_History *inter_arrival_times_;
  CORBA::ULong iterations_;
  CORBA::ULong number_of_invocations_received_;
};

test_i::test_i (CORBA::ORB_ptr orb,
                PortableServer::POA_ptr poa)
  : orb_ (CORBA::ORB::_duplicate (orb)),
    poa_ (PortableServer::POA::_duplicate (poa)),
    inter_arrival_times_ (0),
    iterations_ (0)
{
}

test_i::~test_i (void)
{
}

void
test_i::start_test (CORBA::ULong iterations
                    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->iterations_ = iterations;
  this->number_of_invocations_received_ = 0;

  this->inter_arrival_times_ =
    new ACE_Sample_History (iterations);

  this->first_invocation_ = 1;

  this->invocations_received_.size (iterations);
  for (CORBA::ULong i = 0;
       i < iterations;
       ++i)
    this->invocations_received_[i] = 0;

  this->test_start_ =
    ACE_OS::gethrtime ();
}

void
test_i::end_test (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->test_end_ =
    ACE_OS::gethrtime ();

  ACE_DEBUG ((LM_DEBUG,
              "\nTotal invocations expected / received / missed = %d / %d / %d\n",
              this->iterations_,
              this->number_of_invocations_received_,
              this->iterations_ - this->number_of_invocations_received_));

  if (print_missed_invocations)
    {
      ACE_DEBUG ((LM_DEBUG, "\nFollowing invocations were never received:\n"));

      for (CORBA::ULong i = 0;
           i < this->iterations_;
           ++i)
        {
          if (this->invocations_received_[i] == 0)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "%d ",
                          i));
            }
        }

      ACE_DEBUG ((LM_DEBUG, "\n"));
    }

  if (do_dump_history)
    {
      this->inter_arrival_times_->dump_samples ("Inter-arrival times", gsf);
    }

  ACE_Basic_Stats stats;
  this->inter_arrival_times_->collect_basic_stats (stats);
  stats.dump_results ("Inter-arrival times", gsf);

  ACE_Throughput_Stats::dump_throughput ("Inter-arrival times", gsf,
                                         this->test_end_ - this->test_start_,
                                         stats.samples_count ());
  delete this->inter_arrival_times_;
}

void
test_i::method (CORBA::ULong iteration,
                const ::test::octets &payload
                ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (TAO_debug_level > 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "test_i::method -> iteration = %d payload size = %d\n",
                  iteration,
                  payload.length ()));
    }

  this->invocations_received_[iteration] = 1;
  ++this->number_of_invocations_received_;

  ACE_hrtime_t time_of_current_call =
    ACE_OS::gethrtime ();

  if (this->first_invocation_)
    this->first_invocation_ = 0;
  else
    this->inter_arrival_times_->sample (time_of_current_call - this->time_of_last_call_);

  this->time_of_last_call_ = time_of_current_call;
}

PortableServer::POA_ptr
test_i::_default_POA (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  return PortableServer::POA::_duplicate (this->poa_.in ());
}

void
test_i::shutdown (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG,
              "test_i::shutdown\n"));

  this->orb_->shutdown (0
                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

int
main (int argc, char **argv)
{
  gsf = ACE_High_Res_Timer::global_scale_factor ();

  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc,
                         argv,
                         0
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      int parse_args_result =
        parse_args (argc, argv);
      if (parse_args_result != 0)
        return parse_args_result;

      CORBA::Object_var object =
        orb->resolve_initial_references ("RootPOA"
                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (object.in ()
                                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      test_i servant (orb.in (),
                      root_poa.in ());

      test_var test =
        servant._this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      CORBA::String_var ior =
        orb->object_to_string (test.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      FILE *output_file =
        ACE_OS::fopen (ior_file, "w");
      ACE_ASSERT (output_file != 0);

      u_int result =
        ACE_OS::fprintf (output_file,
                         "%s",
                         ior.in ());
      ACE_ASSERT (result == ACE_OS::strlen (ior));
      ACE_UNUSED_ARG (result);

      ACE_OS::fclose (output_file);

      poa_manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      orb->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Exception caught");
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}
