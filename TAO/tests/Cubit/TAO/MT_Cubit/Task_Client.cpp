// $Id$

#include "Task_Client.h"
#include "ace/Stats.h"

#include "cubit_i.h"

#if defined (NO_ACE_QUANTIFY)
#include "quantify.h"
#endif /* NO_ACE_QUANTIFY */

ACE_RCSID(MT_Cubit, Task_Client, "$Id$")

Task_State::Task_State (int argc, char **argv)
  : key_ ("Cubit"),
    loop_count_ (1000),
    thread_count_ (2),
    datatype_ (CB_OCTET),
    argc_ (argc),
    argv_ (argv),
    thread_per_rate_ (0),
    global_jitter_array_ (0),
    shutdown_ (0),
    oneway_ (0),
    use_name_service_ (1),
    one_to_n_test_ (0),
    context_switch_test_ (0),
    ior_file_ (0),
    granularity_ (1),
    use_utilization_test_ (0),
    high_priority_loop_count_ (0),
    use_multiple_priority_ (0),
    utilization_task_started_ (0),
    util_time_ (0),
    ready_ (0),
    ready_cnd_ (ready_mtx_),
    remote_invocations_ (1),
    util_test_time_ (0)
{
}

int
Task_State::parse_args (int argc,char **argv)
{
  ACE_Get_Opt opts (argc, argv, "U:mu:sn:t:d:rxof:g:1cl");
  int c;
  int datatype;

  while ((c = opts ()) != -1)
    switch (c) {
    case 'g':
      granularity_ = ACE_OS::atoi (opts.optarg);
      if (granularity_ < 1)
        granularity_ = 1;
      break;
    case 'l':
      remote_invocations_ = 0;
      break;
    case 'c':
      context_switch_test_ = 1;
      break;
    case '1':
      one_to_n_test_ = 1;
      break;
    case 'u':
      use_utilization_test_ = 1;
      loop_count_ = util_time_ = ACE_OS::atoi (opts.optarg);
      break;
    case 's':
      use_name_service_ = 0;
      break;
    case 'f':
      ior_file_ = ACE_OS::strdup (opts.optarg);
      break;
    case 'o':
      oneway_ = 1;
      break;
    case 'x':
      shutdown_ = 1;
      break;
    case 'r':
      thread_per_rate_ = 1;
      break;
    case 'd':
      datatype = ACE_OS::atoi (opts.optarg);
      switch (datatype)
        {
        case CB_OCTET:
          ACE_DEBUG ((LM_DEBUG, "Testing Octets\n"));
          datatype_ = CB_OCTET;
          break;
        case CB_LONG:
          ACE_DEBUG ((LM_DEBUG, "Testing Longs\n"));
          datatype_ = CB_LONG;
          break;
        case CB_STRUCT:
          ACE_DEBUG ((LM_DEBUG, "Testing Structs\n"));
          datatype_ = CB_STRUCT;
          break;
        case CB_SHORT:
        default:
          ACE_DEBUG ((LM_DEBUG, "Testing Shorts\n"));
          datatype_ = CB_SHORT;
          break;
        }
      continue;
    case 'n':                   // loop count
      loop_count_ = (u_int) ACE_OS::atoi (opts.optarg);
      ACE_DEBUG ((LM_DEBUG,"(%P|%t) Loop_count:%d\n",loop_count_));
      continue;
    case 't':
      thread_count_ = (u_int) ACE_OS::atoi (opts.optarg);
      continue;
    case '?':
    default:
      ACE_DEBUG ((LM_DEBUG, "usage:  %s"
                  "[-d datatype Octet=0, Short=1, Long=2, Struct=3]"
                  " [-n num_calls]"
                  " [-t num_threads]"
                  " [-f ior_file]"
                  " [-x] // makes a call to servant to shutdown"
                  " [-o] // makes client use oneway calls instead"
                  " [-s] // makes client *NOT* use the name service"
                  " [-g granularity_of_timing]"
                  "\n", this->argv_ [0]));
      return -1;
    }

  if (thread_per_rate_ == 1)
    thread_count_ = 4;

  if (use_utilization_test_ == 1)
    {
      thread_count_ = 1;
      shutdown_ = 1;
    }

  // allocate the array of character pointers.
  ACE_NEW_RETURN (iors_,
                  char *[thread_count_],
                  -1);

  if (ior_file_ != 0)
    {
      char buf[BUFSIZ];
      u_int i = 0;
      int j = 0;
      FILE *ior_file = ACE_OS::fopen (ior_file_, "r");

      if (ior_file == 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR, "Task_State::parse_args; "
                             "unable to open IOR file \"%s\"\n",
                             ior_file_), -1);
        }

      while (ACE_OS::fgets (buf, BUFSIZ, ior_file) != 0 && i < thread_count_)
        {
          ACE_DEBUG ((LM_DEBUG,buf));
          j = ACE_OS::strlen (buf);
          buf[j - 1] = 0;  // this is to delete the "\n" that was read from the file.
          iors_[i] = ACE_OS::strdup (buf);
          i++;
        }
      this->iors_count_ = i;
      ACE_OS::fclose (ior_file);
    }

  // thread_count_ + 2 because there is one utilization thread also
  // wanting to begin at the same time the clients begin && the main
  // thread wants to know when clients will start running to get
  // accurate context switch numbers.
  if (thread_per_rate_ == 0)
    {
      if (use_utilization_test_ == 1)
        // If we are to use the utilization test, include it in the
        // barrier count.  See description of this variable in header
        // file.
        {
          ACE_NEW_RETURN (barrier_,
			  ACE_Barrier (thread_count_ + 2),
			  -1);
        }
      else
        {
          ACE_NEW_RETURN (barrier_,
			  ACE_Barrier (thread_count_ + 1),
			  -1);
        }
    }
  else
    {
      ACE_NEW_RETURN (barrier_,
		      ACE_Barrier (thread_count_),
                      -1);
    }

  ACE_NEW_RETURN (semaphore_,
		  ACE_Thread_Semaphore (0),
                  -1);
  ACE_NEW_RETURN (latency_,
		  double [thread_count_],
                  -1);
  ACE_NEW_RETURN (global_jitter_array_,
		  double *[thread_count_],
		  -1);
  ACE_NEW_RETURN (count_,
		  u_int [thread_count_],
		  -1);
  return 0;
}


Task_State::~Task_State (void)
{
  int i;

  if (this->ior_file_ != 0)
    delete this->ior_file_;

  // Delete the strduped memory
  for (i=0;i<this->iors_count_; i++)
    ACE_OS::free (this->iors_ [i]);
  
  // Delete the barrier

  delete this->barrier_;
  delete this->semaphore_;
  delete [] this->latency_;
  delete [] this->global_jitter_array_;
  delete [] this->count_;
}

Client::Client (ACE_Thread_Manager *thread_manager, Task_State *ts, u_int id)
  : ACE_MT (ACE_Task<ACE_MT_SYNCH> (thread_manager)),
    ts_ (ts),
    id_ (id)
{
}

void
Client::put_latency (double *jitter,
                     double latency,
                     u_int thread_id,
                     u_int count)
{
  ACE_MT (ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, ts_->lock_));

  ts_->latency_[thread_id] = latency;
  ts_->global_jitter_array_[thread_id] = jitter;
  ts_->count_[thread_id] = count;

#if defined (ACE_LACKS_FLOATING_POINT)
  ACE_DEBUG ((LM_DEBUG,
              "(%t) My latency was %u msec\n",
              latency));
#else
  ACE_DEBUG ((LM_DEBUG,
              "(%t) My latency was %f msec\n",
              latency));
#endif /* ! ACE_LACKS_FLOATING_POINT */
}

double
Client::get_high_priority_latency (void)
{
  return (double) ts_->latency_ [0];
}

double
Client::get_low_priority_latency (void)
{
  if (ts_->thread_count_ == 1)
    return 0;

  double l = 0;

  for (u_int i = 1; i < ts_->thread_count_; i++)
    l += (double) ts_->latency_[i];

  return l / (double) (ts_->thread_count_ - 1);
}

double
Client::get_latency (u_int thread_id)
{
  return ACE_static_cast (double, ts_->latency_ [thread_id]);
}

double
Client::get_high_priority_jitter (void)
{
  double jitter = 0.0;
  double average = get_high_priority_latency ();
  double number_of_samples = ts_->high_priority_loop_count_ / ts_->granularity_;

  // Compute the standard deviation (i.e. jitter) from the values
  // stored in the global_jitter_array_.

  ACE_Stats stats;

  // We first compute the sum of the squares of the differences
  // each latency has from the average
  for (u_int i = 0; i < number_of_samples; i ++)
    {
      double difference =
        ts_->global_jitter_array_ [0][i] - average;
      jitter += difference * difference;
      stats.sample ((ACE_UINT32) (ts_->global_jitter_array_ [0][i] * 1000 + 0.5));
    }

  // Return the square root of the sum of the differences computed
  // above, i.e. jitter.

  ACE_OS::fprintf (stderr, "high priority jitter:\n");
  stats.print_summary (3, 1000, stderr);

  return sqrt (jitter / (number_of_samples - 1));
}

double
Client::get_low_priority_jitter (void)
{
  if (ts_->thread_count_ == 1)
    return 0;

  double jitter = 0.0;
  double average = get_low_priority_latency ();
  double number_of_samples = 0;
  //(ts_->thread_count_ - 1) * (ts_->loop_count_ / ts_->granularity_);

  // Compute the standard deviation (i.e. jitter) from the values
  // stored in the global_jitter_array_.

  ACE_Stats stats;

  // We first compute the sum of the squares of the differences each
  // latency has from the average.
  for (u_int j = 1; j < ts_->thread_count_; j ++)
    {
      number_of_samples += ts_->count_[j];
      for (u_int i = 0; i < ts_->count_[j] / ts_->granularity_; i ++)
        {
          double difference =
            ts_->global_jitter_array_[j][i] - average;
          jitter += difference * difference;
          stats.sample ((ACE_UINT32) (ts_->global_jitter_array_ [j][i] * 1000 + 0.5));
        }
    }

  ACE_OS::fprintf (stderr, "low priority jitter:\n");
  stats.print_summary (3, 1000, stderr);

  // Return the square root of the sum of the differences computed
  // above, i.e. jitter.
  return sqrt (jitter / (number_of_samples - 1));
}

double
Client::get_jitter (u_int id)
{
  double jitter = 0.0;
  double average = get_latency (id);
  double number_of_samples = ts_->count_[id]  / ts_->granularity_;

  // Compute the standard deviation (i.e. jitter) from the values
  // stored in the global_jitter_array_.

  ACE_Stats stats;

  // We first compute the sum of the squares of the differences each
  // latency has from the average.
  for (u_int i = 0; i < ts_->count_[id] / ts_->granularity_; i ++)
    {
      double difference =
        ts_->global_jitter_array_[id][i] - average;
      jitter += difference * difference;
      stats.sample ((ACE_UINT32) (ts_->global_jitter_array_ [id][i] * 1000 + 0.5));
    }

  ACE_OS::fprintf (stderr, "jitter for thread id %d:\n", id);
  stats.print_summary (3, 1000, stderr);

  // Return the square root of the sum of the differences computed
  // above, i.e. jitter.
  return sqrt (jitter / (number_of_samples - 1));
}

int
Client::svc (void)
{
  Cubit_ptr cb = 0;
  CORBA::ORB_var orb;
  CORBA::Object_var objref (0);
  CORBA::Object_var naming_obj (0);
  CORBA::Environment env;

  double frequency = 0.0;

  ACE_DEBUG ((LM_DEBUG,"I'm thread %t\n"));
  /// Add "-ORBobjrefstyle url" argument to the argv vector for the
  //orb to / use a URL style to represent the ior.

  // Convert the argv vector into a string.
  ACE_ARGV tmp_args (ts_->argv_);
  char tmp_buf[BUFSIZ];

  ACE_OS::strcpy (tmp_buf,
                  tmp_args.buf ());

  // Add the argument.
  ACE_OS::strcat (tmp_buf,
                  " -ORBobjrefstyle url "
                  " -ORBrcvsock 32768 "
                  " -ORBsndsock 32768 ");

  ACE_DEBUG ((LM_DEBUG,tmp_buf));
  // Convert back to argv vector style.
  ACE_ARGV tmp_args2 (tmp_buf);
  int argc = tmp_args2.argc ();

  char **argv = tmp_args2.argv ();

  u_int naming_success = CORBA::B_FALSE;

  orb = CORBA::ORB_init (argc,
                         argv,
                         "internet",
                         env);

  if (env.exception () != 0)
    {
      env.print_exception ("ORB_init()\n");
      return -1;
    }
ACE_DEBUG ((LM_DEBUG, "in svc() ts_->one_ior_ = \"%s\"\n", ts_->one_ior_));

  if (this->id_ == 0)
    {
      ACE_DEBUG ((LM_DEBUG,"parsing the arguments\n"));
      int result;
      result = this->ts_->parse_args (argc,argv);
ACE_DEBUG ((LM_DEBUG, "in svc(), AFTER parse_args()  ts_->one_ior_ = \"%s\"\n", ts_->one_ior_));
      if (result < 0)
        return -1;
      ACE_DEBUG ((LM_DEBUG,"(%t)Arguments parsed successfully\n"));
      ACE_MT (ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ready_mon, this->ts_->ready_mtx_, 1));
      this->ts_->ready_ = 1;
      this->ts_->ready_cnd_.broadcast ();
      ready_mon.release ();
    }

  ACE_DEBUG ((LM_DEBUG,"(%t) ORB_init success\n"));
  if (ts_->use_name_service_ != 0)
    {
      // Initialize the naming services
      if (my_name_client_.init (orb.in (), argc, argv) != 0)
	ACE_ERROR_RETURN ((LM_ERROR,
			   " (%P|%t) Unable to initialize "
			   "the TAO_Naming_Client. \n"),
			  -1);
    }
  {
    //    ACE_DEBUG ((LM_DEBUG,"(%t) Not using Naming service\n"));

    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, ts_->lock_, -1));

    ACE_DEBUG ((LM_DEBUG,"(%P|%t) Out of ACE_MT\n"));
    if (ts_->thread_per_rate_ == 0)
      {
        if (this->id_ == 0)
          {
            ACE_DEBUG ((LM_DEBUG,
                        "(%t) I'm the high priority client, my id is %d.\n",
                        this->id_));
            frequency = CB_HIGH_PRIORITY_RATE;
          }
        else
          {
            ACE_DEBUG ((LM_DEBUG,
                        "(%t) I'm a low priority client, my id is %d.\n",
                        this->id_));
            frequency = CB_LOW_PRIORITY_RATE;
          }
      }
    else
      switch (this->id_)
        {
        case CB_20HZ_CONSUMER:
          frequency = CB_20HZ_CONSUMER_RATE;
          ACE_DEBUG ((LM_DEBUG,
                      "(%t) I'm a %u Hz frequency client, "
                      "my id is %u.\n",
                      CB_20HZ_CONSUMER_RATE,
                      this->id_));
          break;
        case CB_10HZ_CONSUMER:
          frequency = CB_10HZ_CONSUMER_RATE;
          ACE_DEBUG ((LM_DEBUG,
                      "(%t) I'm a %u Hz frequency client, "
                      "my id is %u.\n",
                      CB_10HZ_CONSUMER_RATE,
                      this->id_));
          break;
        case CB_5HZ_CONSUMER:
          frequency = CB_5HZ_CONSUMER_RATE;
          ACE_DEBUG ((LM_DEBUG,
                      "(%t) I'm a %u Hz frequency client, "
                      "my id is %u.\n",
                      CB_5HZ_CONSUMER_RATE,
                      this->id_));
          break;
        case CB_1HZ_CONSUMER:
          frequency = CB_1HZ_CONSUMER_RATE;
          ACE_DEBUG ((LM_DEBUG,
                      "(%t) I'm a %u Hz frequency client, "
                      "my id is %u.\n",
                      CB_1HZ_CONSUMER_RATE,
                      this->id_));
          break;
        default:
          ACE_DEBUG ((LM_DEBUG, "(%t) Invalid Thread ID!!!!\n", this->id_));
        }

    TAO_TRY
      {
        // if the naming service was resolved successsfully ...
        if (!CORBA::is_nil (this->my_name_client_.get_context ()))
          {
            ACE_DEBUG ((LM_DEBUG,
                        " (%t) ----- Using the NameService resolve() method"
                        " to get cubit objects -----\n"));

            // Construct the key for the name service lookup.
            CosNaming::Name mt_cubit_context_name (1);
            mt_cubit_context_name.length (1);
            mt_cubit_context_name[0].id = CORBA::string_dup ("MT_Cubit");

            objref =
              this->my_name_client_->resolve (mt_cubit_context_name,
                                              TAO_TRY_ENV);
            TAO_CHECK_ENV;

            this->mt_cubit_context_ =
              CosNaming::NamingContext::_narrow (objref.in (),
                                                 TAO_TRY_ENV);
            TAO_CHECK_ENV;

            char *buffer;
            int l = ACE_OS::strlen (ts_->key_) + 3;
            ACE_NEW_RETURN (buffer,
                            char[l],
                            -1);

            ACE_OS::sprintf (buffer,
                             "%s%02d",
                             (char *) ts_->key_,
                             this->id_);

            // Construct the key for the name service lookup.
            CosNaming::Name cubit_name (1);
            cubit_name.length (1);
            cubit_name[0].id = CORBA::string_dup (buffer);

            objref = this->mt_cubit_context_->resolve (cubit_name,
                                                       TAO_TRY_ENV);

            if (TAO_TRY_ENV.exception () != 0
                || CORBA::is_nil (objref.in ()))
              {
                ACE_DEBUG ((LM_DEBUG,
                            " (%t) resolve() returned nil\n"));
                TAO_TRY_ENV.print_exception ("Attempt to resolve() a cubit object"
                                             "using the name service Failed!\n");
              }
            else
              {
                naming_success = CORBA::B_TRUE;
                ACE_DEBUG ((LM_DEBUG,
                            " (%t) Cubit object resolved to the name \"%s\".\n",
                            buffer));
              }
          }

ACE_DEBUG ((LM_DEBUG, "ts_->one_ior_=%s, this->id_=%d \t naming_success=%d\n", ts_->one_ior_, this->id_, naming_success));

        if (naming_success == CORBA::B_FALSE)
          {
            char *my_ior = ts_->use_utilization_test_ == 1? ts_->one_ior_ : ts_->iors_[this->id_];

            // if we are running the "1 to n" test make sure all low
            // priority clients use only 1 low priority servant.
            if (this->id_ > 0 && ts_->one_to_n_test_ == 1)
              my_ior = ts_->iors_[1];

            if (my_ior == 0)
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Must specify valid factory ior key with -k option,"
                                 " naming service, or ior filename\n"),
                                -1);

            ACE_DEBUG ((LM_DEBUG,"(%P|%t) my ior is:%s\n",my_ior));
            // if we are running the "1 to n" test make sure all low
            // priority clients use only 1 low priority servant.
            if (this->id_ > 0 && ts_->one_to_n_test_ == 1)
              my_ior = ts_->iors_[1];

            if (my_ior == 0)
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Must specify valid factory ior key with -k option,"
                                 " naming service, or ior filename\n"),
                                -1);

            objref = orb->string_to_object (my_ior,
                                            TAO_TRY_ENV);
            ACE_DEBUG ((LM_DEBUG,"(%P|%t)  String_to_object success\n"));
            TAO_CHECK_ENV;
          }

        if (CORBA::is_nil (objref.in ()))
          ACE_ERROR_RETURN ((LM_ERROR,
                             " (%t) string_to_object or NameService->resolve() Failed!\n"),
                            -1);

        // Narrow the CORBA::Object reference to the stub object,
        // checking the type along the way using _is_a.
        cb = Cubit::_narrow (objref.in (),
                             TAO_TRY_ENV);
        TAO_CHECK_ENV;

        ACE_DEBUG ((LM_DEBUG,"(%t) _narrow done\n"));

        if (CORBA::is_nil (cb))
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Create cubit failed\n"),
                            1);

        ACE_DEBUG ((LM_DEBUG,
                    "(%t) Binding succeeded\n"));

        CORBA::String_var str =
          orb->object_to_string (cb, TAO_TRY_ENV);
        TAO_CHECK_ENV;

        ACE_DEBUG ((LM_DEBUG,
                    "(%t) CUBIT OBJECT connected <%s>\n",
                    str.in ()));

        ACE_DEBUG ((LM_DEBUG,
                    "(%t) Waiting for other threads to "
                    "finish binding..\n"));
      }
    TAO_CATCHANY
      {
        TAO_TRY_ENV.print_exception ("get_object");
        return 1;
      }
    TAO_ENDTRY;
  }

  // Wait for all the client threads to be initialized before going
  // any further.
  ts_->barrier_->wait ();
  ACE_DEBUG ((LM_DEBUG,
              "(%t) Everyone's done, here I go!!\n"));

  if (ts_->oneway_ == 1)
    ACE_DEBUG ((LM_DEBUG,
                "(%t) **** USING ONEWAY CALLS ****\n"));

  // Perform the tests.
  int result = this->run_tests (cb,
                                ts_->loop_count_,
                                this->id_,
                                ts_->datatype_,
                                frequency);

  if (ts_->thread_per_rate_ == 1 && this->id_ == (ts_->thread_count_ - 1) )
    ts_->semaphore_->release (ts_->thread_count_ - 1);
  else
    ts_->semaphore_->release ();

  if (result == -1)
    return -1;

  if (ts_->shutdown_)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "(%t) CALLING SHUTDOWN() ON THE SERVANT\n"));
      cb->shutdown (env);
      if (env.exception () != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "Shutdown of the server failed!\n"));
          env.print_exception ("shutdown() call failed.\n");
        }
    }

  // Delete dynamic memory
  
  CORBA::release (cb);

  return 0;
}

int
Client::run_tests (Cubit_ptr cb,
                   u_int loop_count,
                   u_int thread_id,
                   Cubit_Datatypes datatype,
                   double frequency)
{
  Cubit_i cb_impl;
  CORBA::Environment env;
  u_int i = 0;
  u_int call_count = 0;
  u_int error_count = 0;
  u_int low_priority_client_count = ts_->thread_count_ - 1;
  double *my_jitter_array;

  if (id_ == 0 && ts_->thread_count_ > 1)
    ACE_NEW_RETURN (my_jitter_array,
                    double [(loop_count/ts_->granularity_)*30], // magic number, for now.
                    -1);
  else
    ACE_NEW_RETURN (my_jitter_array,
                    double [loop_count/ts_->granularity_*15],
                    -1);

#if defined (CHORUS)
  long latency = 0;
  long sleep_time = (1 / frequency) * ACE_ONE_SECOND_IN_USECS * ts_->granularity_; // usec
  long delta = 0;
#else
  double latency = 0;
  double sleep_time = (1 / frequency) * ACE_ONE_SECOND_IN_USECS * ts_->granularity_; // usec
  double delta = 0;
#endif

  // time to wait for utilization tests to know when to stop.
  ACE_Time_Value max_wait_time (ts_->util_time_, 0);
  ACE_Countdown_Time countdown (&max_wait_time);

#if defined (CHORUS)
  int pstartTime = 0;
  int pstopTime = 0;
  long real_time = 0;
#else /* CHORUS */
  double real_time = 0.0;
#endif

  ACE_High_Res_Timer timer_;

  // Elapsed time will be in microseconds.
  ACE_Time_Value delta_t;

  if (ts_->use_utilization_test_ == 1)
    timer_.start ();

  // Make the calls in a loop.

  ACE_DEBUG((LM_DEBUG,"(%P|%t)loop_count:%d",loop_count));
  for (i = 0;
       // keep running for loop count, OR
       i < loop_count ||
         // keep running if we are the highest priority thread and at
         // least another lower client thread is running, OR
         (id_ == 0 && ts_->thread_count_ > 1) ||
         // keep running if test is thread_per_rate and we're not the
         // lowest frequency thread.
         (ts_->thread_per_rate_ == 1 && id_ < (ts_->thread_count_ - 1));
       i++)
    {
      // start timing a call
      if ( (i % ts_->granularity_) == 0 &&
           (ts_->use_utilization_test_ == 0) 
           )
        {
          // delay a sufficient amount of time to be able to enforce
          // the calling frequency (i.e., 20Hz, 10Hz, 5Hz, 1Hz).
          ACE_Time_Value tv (0,
                             (u_long) ((sleep_time - delta) < 0
                                       ? 0
                                       : (sleep_time - delta)));
          ACE_OS::sleep (tv);
#if defined (CHORUS)
          pstartTime = pccTime1Get();
#else /* CHORUS */
          timer_.start ();
#endif /* !CHORUS */
        }

      if (ts_->oneway_ == 0)
        {
          switch (datatype)
            {
            case CB_OCTET:
              {
                //            ACE_DEBUG ((LM_DEBUG,"(%P|%t) Cubing Octet\n"));
                // Cube an octet.
                CORBA::Octet arg_octet = func (i), ret_octet = 0;

#if defined (NO_ACE_QUANTIFY)
                /* start recording quantify data from here */
                quantify_start_recording_data ();
#endif /* NO_ACE_QUANTIFY */
		if (ts_->remote_invocations_ == 1)
		  ret_octet = cb->cube_octet (arg_octet, env);
		else
		  ret_octet = cb_impl.cube_octet (arg_octet, env);

#if defined (NO_ACE_QUANTIFY)
                quantify_stop_recording_data();
#endif /* NO_ACE_QUANTIFY */

                if (env.exception () != 0)
                  {
                    env.print_exception ("call to cube_octet()\n");
                    ACE_ERROR_RETURN ((LM_ERROR,
                                       "%s:Call failed\n",
                                       env.exception ()),
                                      2);
                  }
                //                ACE_DEBUG ((LM_DEBUG,"(%P|%t) Cube_Octed  call success\n"));

                arg_octet = arg_octet * arg_octet * arg_octet;

                if (arg_octet != ret_octet)
                  {
                    ACE_ERROR ((LM_ERROR,
                                "** cube_octet(%d)  (--> %d)\n",
                                arg_octet,
                                ret_octet));
                    error_count++;
                  }
                call_count++;
                break;
              }
            case CB_SHORT:
              // Cube a short.
              {
                call_count++;

                CORBA::Short arg_short = func (i), ret_short;

#if defined (NO_ACE_QUANTIFY)
                // start recording quantify data from here.
                quantify_start_recording_data ();
#endif /* NO_ACE_QUANTIFY */

                ret_short = cb->cube_short (arg_short, env);

#if defined (NO_ACE_QUANTIFY)
                quantify_stop_recording_data();
#endif /* NO_ACE_QUANTIFY */

                if (env.exception () != 0)
                  {
                    env.print_exception ("call to cube_short()\n");
                    ACE_ERROR_RETURN ((LM_ERROR,
                                       "%s:Call failed\n",
                                       env.exception ()),
                                      2);
                  }

                arg_short = arg_short * arg_short * arg_short;

                if (arg_short != ret_short)
                  {
                    ACE_ERROR ((LM_ERROR,
                                "** cube_short(%d)  (--> %d)\n",
                                arg_short ,
                                ret_short));
                    error_count++;
                  }
                break;
              }
	      // Cube a long.

            case CB_LONG:
              {
                call_count++;

                CORBA::Long arg_long = func (i);
                CORBA::Long ret_long;

#if defined (NO_ACE_QUANTIFY)
                /* start recording quantify data from here */
                quantify_start_recording_data ();
#endif /* NO_ACE_QUANTIFY */

                ret_long = cb->cube_long (arg_long, env);

#if defined (NO_ACE_QUANTIFY)
                quantify_stop_recording_data();
#endif /* NO_ACE_QUANTIFY */

                if (env.exception () != 0)
                  {
                    env.print_exception ("call to cube_long()\n");
                    ACE_ERROR_RETURN ((LM_ERROR,
                                       "%s:Call failed\n",
                                       env.exception ()),
                                      2);
                  }

                arg_long = arg_long * arg_long * arg_long;

                if (arg_long != ret_long)
                  {
                    ACE_ERROR ((LM_ERROR,
                                "** cube_long(%d)  (--> %d)\n",
                                arg_long,
                                ret_long));
                    error_count++;
                  }
                break;
              }

            case CB_STRUCT:
              // Cube a "struct" ...
              {
                Cubit::Many arg_struct, ret_struct;

                call_count++;

                arg_struct.l = func (i);
                arg_struct.s = func (i);
                arg_struct.o = func (i);

#if defined (NO_ACE_QUANTIFY)
                // start recording quantify data from here.
                quantify_start_recording_data ();
#endif /* NO_ACE_QUANTIFY */

                ret_struct = cb->cube_struct (arg_struct, env);

#if defined (NO_ACE_QUANTIFY)
                quantify_stop_recording_data();
#endif /* NO_ACE_QUANTIFY */

                if (env.exception () != 0)
                  {
                    env.print_exception ("call to cube_struct()\n");
                    ACE_ERROR_RETURN ((LM_ERROR,"%s:Call failed\n", env.exception ()), 2);
                  }

                arg_struct.l = arg_struct.l  * arg_struct.l  * arg_struct.l ;
                arg_struct.s = arg_struct.s  * arg_struct.s  * arg_struct.s ;
                arg_struct.o = arg_struct.o  * arg_struct.o  * arg_struct.o ;

                if (arg_struct.l  != ret_struct.l
                    || arg_struct.s  != ret_struct.s
                    || arg_struct.o  != ret_struct.o )
                  {
                    ACE_ERROR ((LM_ERROR, "**cube_struct error!\n"));
                    error_count++;
                  }

                break;
              }
            default:
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "(%P|%t); %s:%d; unexpected datatype: %d\n",
                                 datatype), -1);
            }
        }
      else
        {
          call_count++;
#if defined (NO_ACE_QUANTIFY)
          // start recording quantify data from here.
          quantify_start_recording_data ();
#endif /* NO_ACE_QUANTIFY */
          cb->noop (env);
#if defined (NO_ACE_QUANTIFY)
          quantify_stop_recording_data();
#endif /* NO_ACE_QUANTIFY */
          if (env.exception () != 0)
            {
              env.print_exception ("oneway call noop()\n");
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "(%t) noop() call failed\n"),
                                2);
            }
        }

      // stop the timer
      if ( (i % ts_->granularity_) == (ts_->granularity_ - 1) &&
           (ts_->use_utilization_test_ == 0) 
           )
        {
#if defined (CHORUS)
          pstopTime = pccTime1Get();
#else /* CHORUS */
          // if CHORUS is not defined just use plain timer_.stop ().
          timer_.stop ();
          timer_.elapsed_time (delta_t);
#endif /* !CHORUS */

          // Calculate time elapsed
#if defined (ACE_LACKS_FLOATING_POINT)
#   if defined (CHORUS)
          real_time = (pstopTime - pstartTime) / ts_->granularity_;
#   else /* CHORUS */
          // Store the time in usecs.
          real_time = (delta_t.sec () * ACE_ONE_SECOND_IN_USECS  +
		       delta_t.usec ()) / ts_->granularity_;
#   endif /* !CHORUS */
          delta = ((40 * fabs (real_time) / 100) + (60 * delta / 100)); // pow(10,6)
          latency += real_time * ts_->granularity_;
          my_jitter_array [i/ts_->granularity_] = real_time; // in units of microseconds.
          // update the latency array, correcting the index using the granularity
#else /* !ACE_LACKS_FLOATING_POINT */

          // Store the time in secs.

#if defined (VXWORKS)
          // @@ David, these comments are to temporarily fix what
          // seems a bug in the ACE_Long_Long class that is used to
          // calc the elapsed time.  It seems that subtraction of two
          // ACE_Long_Long are not done correctly when the least
          // significant value has wrapped around.  For example to
          // subtract these values: 00ff1001:00000001 minus
          // 00ff1000:ffffffff would give a huge number, instead of
          // giving 2.

          // This is only occuring in VxWorks.
          // I'll leave these here to debug it later.
          double tmp = (double)delta_t.sec ();
          double tmp2 = (double)delta_t.usec ();
          if (tmp > 100000)
            {
              tmp = 0.0;
              tmp2 = 2000.0;
              ACE_OS::fprintf (stderr, "tmp > 100000!, delta_t.usec ()=%ld\n",
                               delta_t.usec ());
            }

          real_time = tmp + tmp2 / (double)ACE_ONE_SECOND_IN_USECS;
#else
          real_time = ((double) delta_t.sec () +
                       (double) delta_t.usec () / (double) ACE_ONE_SECOND_IN_USECS);
#endif /* VXWORKS */

          real_time /= ts_->granularity_;

          delta = ((0.4 * fabs (real_time * ACE_ONE_SECOND_IN_USECS)) + (0.6 * delta)); // pow(10,6)
          latency += (real_time * ts_->granularity_);
          my_jitter_array [i/ts_->granularity_] = real_time * ACE_ONE_SECOND_IN_MSECS;
#endif /* !ACE_LACKS_FLOATING_POINT */
        } // END OF IF   :
      //       if ( (i % ts_->granularity_) == (ts_->granularity_ - 1) &&
      //       (ts_->use_utilization_test_ == 0) &&
      //       (ts_->run_server_utilization_test_ == 0)
      //       )

      if ( ts_->thread_per_rate_ == 1 && id_ < (ts_->thread_count_ - 1) )
        {
          if (ts_->semaphore_->tryacquire () != -1)
	    break;
        }
      else
        // if We are the high priority client.
        // if tryacquire() succeeded then a client must have done a
        // release () on it, thus we decrement the client counter.
        if (id_ == 0 && ts_->thread_count_ > 1)
          {
            if (ts_->semaphore_->tryacquire () != -1)
              {
                low_priority_client_count --;
                // if all clients are done then break out of loop.
                if (low_priority_client_count <= 0)
                  break;
              }
          }

    } /* end of for () */

  if (id_ == 0)
    ts_->high_priority_loop_count_ = call_count;

  if (ts_->use_utilization_test_ == 1)
    {
      timer_.stop ();
      timer_.elapsed_time (delta_t);
      ts_->util_test_time_ = ((double) delta_t.sec () +
			      (double) delta_t.usec () / (double) ACE_ONE_SECOND_IN_USECS);
    }

  // perform latency stats onlt if we are not running the utilization
  // tests.
  if (call_count > 0 &&
      (ts_->use_utilization_test_ == 0) 
      )
    {
      if (error_count == 0)
        {
#if defined (ACE_LACKS_FLOATING_POINT)
          long calls_per_second = (call_count * ACE_ONE_SECOND_IN_USECS) / latency;
          latency = latency/call_count;//calc average latency
#else
          latency /= call_count; // calc average latency
#endif /* ACE_LACKS_FLOATING_POINT */

          if (latency > 0)
            {
#if defined (ACE_LACKS_FLOATING_POINT)
              ACE_DEBUG ((LM_DEBUG,
                          "(%P|%t) cube average call ACE_OS::time\t= %u usec, \t"
                          "%u calls/second\n",
                          latency,
                          calls_per_second));

              this->put_latency (my_jitter_array,
                                 latency,
                                 thread_id,
                                 call_count);
#else
              ACE_DEBUG ((LM_DEBUG,
                          "(%P|%t) cube average call ACE_OS::time\t= %f msec, \t"
                          "%f calls/second\n",
                          latency * 1000,
                          1 / latency));

              this->put_latency (my_jitter_array,
                                 latency * ACE_ONE_SECOND_IN_MSECS,
                                 thread_id,
                                 call_count);
#endif /* ! ACE_LACKS_FLOATING_POINT */
            }
          else
            {
              // still we have to call this function to store a valid array pointer.
              this->put_latency (my_jitter_array,
                                 0,
                                 thread_id,
                                 call_count);

              ACE_DEBUG ((LM_DEBUG,
                          "*** Warning: Latency, %f, is less than or equal to zero."
                          "  Precision may have been lost.\n, latency"));
            }
        }
      ACE_DEBUG ((LM_DEBUG,
                  "%d calls, %d errors\n",
                  call_count,
                  error_count));
    }

  // Delete the dynamically allocated memory
  delete [] my_jitter_array;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Condition<ACE_SYNCH_MUTEX>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate ACE_Condition<ACE_SYNCH_MUTEX>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
