// $Id$

#define  ACE_BUILD_SVC_DLL
#include "ace/Service_Repository.h"
#include "ace/Synch.h"
#include "ace/Get_Opt.h"
#include "ace/Thread_Manager.h"
#include "Baseline_Test.h"

#if !defined (__ACE_INLINE__)
#include "Baseline_Test.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Synch_Benchmarks, Baseline_Test, "$Id$")

Baseline_Test_Options baseline_options;
// Static Baseline Options holds the test configuration information
// and the test statistics.

Baseline_Test_Base::Baseline_Test_Base (void)
  : yield_method_ (Baseline_Test_Options::USE_SLEEP_ZERO),
    multiply_factor_ (100),
    iteration_ (10000),
    Benchmark_Base (Benchmark_Base::BASELINE)
{
}

int
Baseline_Test_Base::init (int argc, char *argv[])
{
  return this->parse_args (argc, argv);
}

int
Baseline_Test_Base::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt getopt (argc, argv, "m:i:y", 0);
  int c;

  while ((c = getopt ()) != -1)
    switch (c)
      {
      case 'm':
        {
          int tmp = ACE_OS::atoi (getopt.optarg);
          if (tmp <= 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "%d is not a valid value for multiply_factor\n",
                               tmp), -1);
          else
            this->multiply_factor_ = ACE_static_cast (size_t, tmp);
        }
        break;

      case 'i':
        {
          int tmp = ACE_OS::atoi (getopt.optarg);
          if (tmp <= 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "%d is not a valid value for iteration\n",
                               tmp), -1);
          else
            this->iteration_ = ACE_static_cast (size_t, tmp);
        }
        break;

      case 'y':                 // Use thr_yield.
        this->yield_method_ = Baseline_Test_Options::USE_THR_YIELD;
        break;

      default:
        ACE_ERROR ((LM_ERROR, "Invalid argument %c used\n", c));
        break;
      }
  return 0;
}

void
Baseline_Test_Base::yield (void)
{
  if (this->yield_method_ == Baseline_Test_Options::USE_SLEEP_ZERO)
    ACE_OS::sleep (0);
  else
    ACE_OS::thr_yield ();
}

Baseline_Test_Options::Baseline_Test_Options (void)
  : test_try_lock_ (0),
    verbose_ (0),
    current_yield_method_ (0),
    current_multiply_factor_ (10),
    current_iteration_ (0),
    total_iteration_ (10000)
{
}

int
Baseline_Test_Options::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt getopt (argc, argv, "tv", 0);
  int c;

  while ((c = getopt ()) != -1)
    switch (c)
      {
      case 't':
        this->test_try_lock_ = 1;
        break;

      case 'v':
        this->verbose_ = 1;
        break;

      default:
        ACE_ERROR ((LM_ERROR, "Invalid arguemnt %c used.\n", c));
        break;
      }
  return 0;
}

int
Baseline_Test_Options::reset_params (size_t multiply,
                                     size_t iteration,
                                     int yield)
{
  this->total_iteration_ = 0;
  this->real_ = 0;
  this->system_ = 0;
  this->user_ = 0;
  // Start a new test, reset statistic info.

  this->current_yield_method_ = yield;
  this->current_multiply_factor_ = multiply;
  this->total_iteration_ = iteration;
  return 0;
}

void
Baseline_Test_Options::print_result (void)
{
  ACE_DEBUG ((LM_DEBUG,
              "Real Time: %f\n System Time: %f\nUser Time: %f\n",
              this->real_,
              this->system_,
              this->user_));
}

Baseline_Test::Baseline_Test (void)
  : current_test_ (0),
    get_lock_ (2),
    let_go_lock_ (2)
{
}

// Initialize and run the benchmarks tests.

int
Baseline_Test::init (int argc, char **argv)
{
  return baseline_options.parse_args (argc, argv);
}

int
Baseline_Test::pre_run_test (Benchmark_Base *bb)
{
  this->current_test_ = (Baseline_Test_Base *) bb;
  baseline_options.reset_params (this->current_test_->multiply_factor (),
                                 this->current_test_->iteration (),
                                 this->current_test_->yield_method ());

  if (baseline_options.test_try_lock ())
    {
      ACE_Thread_Manager::instance ()->spawn
        (ACE_THR_FUNC (Baseline_Test::hold_lock),
         (void *) this);

      this->get_lock_.wait ();
      // Wait until the lock is held by the spawning thread.
    }

  return 0;
}

int
Baseline_Test::run_test (void)
{
  if (baseline_options.test_try_lock ())
    return this->current_test_->test_try_lock ();
  else
    return this->current_test_->test_acquire_release ();
}

int
Baseline_Test::post_run_test (void)
{
  if (baseline_options.test_try_lock ())
    {
      // Release the lock we hold.
      this->let_go_lock_.wait ();

      ACE_Thread_Manager::instance ()->wait ();
    }

  baseline_options.print_result ();

  return 0;
}

int
Baseline_Test::valid_test_object (Benchmark_Base *bb)
{
  return (bb->benchmark_type () == Benchmark_Base::BASELINE);
}

void *
Baseline_Test::hold_lock (void *arg)
{
  Baseline_Test *this_test = (Baseline_Test *) arg;
  this_test->current_test_->acquire ();
  this_test->get_lock_.wait ();

  this_test->let_go_lock_.wait ();
  return 0;
}

ACE_SVC_FACTORY_DEFINE (Baseline_Test)
