// $Id$

#include "ace/Get_Opt.h"
#include "tao/corba.h"
#include "tao/RTCORBA/RTCORBA.h"

ACE_RCSID(Destroy_Thread_Pools, Destroy_Thread_Pools, "$Id$")

static CORBA::ULong stacksize = 0;
static CORBA::ULong static_threads = 1;
static CORBA::ULong dynamic_threads = 0;
static RTCORBA::Priority default_priority =
  RTCORBA::Priority (ACE_DEFAULT_THREAD_PRIORITY);
static CORBA::Boolean allow_request_buffering = 0;
static CORBA::Boolean allow_borrowing = 0;
static CORBA::ULong max_buffered_requests = 0;
static CORBA::ULong max_request_buffer_size = 0;
static int iterations = 5;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "i:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'i':
        iterations = ACE_OS::atoi (get_opts.optarg);
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-i <iterations> "
                           "\n",
                           argv [0]),
                          -1);
      }

  return 0;
}

RTCORBA::ThreadpoolId
create_threadpool (RTCORBA::RTORB_ptr rt_orb,
                   CORBA_Environment &ACE_TRY_ENV)
{
  RTCORBA::ThreadpoolId id =
    rt_orb->create_threadpool (stacksize,
                               static_threads,
                               dynamic_threads,
                               default_priority,
                               allow_request_buffering,
                               max_buffered_requests,
                               max_request_buffer_size,
                               ACE_TRY_ENV);
  ACE_CHECK;

  return id;
}

RTCORBA::ThreadpoolId
create_threadpool_with_lanes (RTCORBA::RTORB_ptr rt_orb,
                              CORBA_Environment &ACE_TRY_ENV)
{
  RTCORBA::ThreadpoolLanes lanes (2);
  lanes.length (2);

  lanes[0].lane_priority = default_priority;
  lanes[0].static_threads = static_threads;
  lanes[0].dynamic_threads = dynamic_threads;

  lanes[1].lane_priority = default_priority;
  lanes[1].static_threads = static_threads;
  lanes[1].dynamic_threads = dynamic_threads;

  RTCORBA::ThreadpoolId id =
    rt_orb->create_threadpool_with_lanes (stacksize,
                                          lanes,
                                          allow_borrowing,
                                          allow_request_buffering,
                                          max_buffered_requests,
                                          max_request_buffer_size,
                                          ACE_TRY_ENV);
  ACE_CHECK;

  return id;
}

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc,
                         argv,
                         "",
                         ACE_TRY_ENV);
      ACE_TRY_CHECK;

      CORBA::Object_var object =
        orb->resolve_initial_references ("RTORB",
                                         ACE_TRY_ENV);
      ACE_TRY_CHECK;

      RTCORBA::RTORB_var rt_orb =
        RTCORBA::RTORB::_narrow (object.in (),
                                 ACE_TRY_ENV);
      ACE_TRY_CHECK;

      int result =
        parse_args (argc, argv);
      if (result != 0)
        return result;

      int i = 0;
      for (i = 0;
           i < iterations;
           ++i)
        {
          RTCORBA::ThreadpoolId id =
            create_threadpool (rt_orb.in (),
                               ACE_TRY_ENV);
          ACE_TRY_CHECK;

          rt_orb->destroy_threadpool (id,
                                      ACE_TRY_ENV);
          ACE_TRY_CHECK;

          id =
            create_threadpool_with_lanes (rt_orb.in (),
                                          ACE_TRY_ENV);
          ACE_TRY_CHECK;

          rt_orb->destroy_threadpool (id,
                                      ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }

      orb->destroy (ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception caught:");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}
