// $Id$

#include "tao/default_client.h"
#include "tao/ORB_Core.h"
#include "tao/Wait_Strategy.h"
#include "tao/Transport_Mux_Strategy.h"

#if !defined (__ACE_INLINE__)
# include "tao/default_client.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(tao, default_client, "$Id$")

TAO_Default_Client_Strategy_Factory::TAO_Default_Client_Strategy_Factory (void)
  : profile_lock_type_ (TAO_THREAD_LOCK),
    cached_connector_lock_type_ (TAO_THREAD_LOCK)
{
  // Use single thread client connection handler
#if defined (TAO_USE_ST_CLIENT_CONNECTION_HANDLER)
  this->wait_strategy_ = TAO_WAIT_ON_REACTOR;
#else
  this->wait_strategy_ = TAO_WAIT_ON_LEADER_FOLLOWER;
#endif /* TAO_USE_ST_CLIENT_CONNECTION_HANDLER */

#if defined (TAO_USE_MUXED_TRANSPORT_MUX_STRATEGY)
  this->transport_mux_strategy_ = TAO_MUXED_TMS;
#else
  this->transport_mux_strategy_ = TAO_EXCLUSIVE_TMS;
#endif /* TAO_USE_MUXED_TRANSPORT_MUX_STRATEGY */

// #if defined (TAO_USE_WAIT_ON_READ)
//   this->wait_strategy_ = TAO_WAIT_ON_LEADER_FOLLOWER;
// #elif defined (TAO_USE_WAIT_ON_REACTOR)
//   this->wait_strategy_ = TAO_WAIT_ON_REACTOR;
// #else
//   this->wait_strategy_ = TAO_WAIT_ON_READ;
// #endif /* TAO_USE_WAIT_ON_LEADER_FOLLOWER */
}

TAO_Default_Client_Strategy_Factory::~TAO_Default_Client_Strategy_Factory (void)
{
}

int
TAO_Default_Client_Strategy_Factory::init (int argc, char *argv[])
{
  return this->parse_args (argc, argv);
}

int
TAO_Default_Client_Strategy_Factory::parse_args (int argc, char ** argv)
{
  ACE_TRACE ("TAO_Default_Client_Strategy_Factory::parse_args");

  int curarg;

  for (curarg = 0; curarg < argc && argv[curarg]; curarg++)
    {
      if (ACE_OS::strcasecmp (argv[curarg],
                              "-ORBProfileLock") == 0)
        {
        curarg++;
        if (curarg < argc)
          {
            char *name = argv[curarg];

            if (ACE_OS::strcasecmp (name,
                                    "thread") == 0)
              this->profile_lock_type_ = TAO_THREAD_LOCK;
            else if (ACE_OS::strcasecmp (name,
                                         "null") == 0)
              this->profile_lock_type_ = TAO_NULL_LOCK;
          }
        }

      else if (ACE_OS::strcasecmp (argv[curarg],
                                   "-ORBIIOPProfileLock") == 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "WARNING: The -ORBIIOPProfileLock option"
                      " is deprecated and will be removed.\n"
                      "         Please use -ORBProfileLock instead\n"));
          curarg++;
          if (curarg < argc)
            {
              char *name = argv[curarg];

              if (ACE_OS::strcasecmp (name,
                                      "thread") == 0)
                this->profile_lock_type_ = TAO_THREAD_LOCK;
              else if (ACE_OS::strcasecmp (name,
                                           "null") == 0)
                this->profile_lock_type_ = TAO_NULL_LOCK;
            }
        }

      else if (ACE_OS::strcasecmp (argv[curarg],
                                   "-ORBClientConnectionHandler") == 0)
        {
          curarg++;
          if (curarg < argc)
            {
              char *name = argv[curarg];

              if (ACE_OS::strcasecmp (name,
                                      "MT") == 0)
                this->wait_strategy_ = TAO_WAIT_ON_LEADER_FOLLOWER;
              else if (ACE_OS::strcasecmp (name,
                                           "ST") == 0)
                this->wait_strategy_ = TAO_WAIT_ON_REACTOR;
              else if (ACE_OS::strcasecmp (name,
                                           "RW") == 0)
                this->wait_strategy_ = TAO_WAIT_ON_READ;
            }
        }
      else if (ACE_OS::strcmp (argv[curarg],
                               "-ORBTransportMuxStrategy") == 0)
        {
          curarg++;
          if (curarg < argc)
            {
              char *name = argv[curarg];

              if (ACE_OS::strcasecmp (name,
                                      "MUXED") == 0)
                this->transport_mux_strategy_ = TAO_MUXED_TMS;
              else if (ACE_OS::strcasecmp (name,
                                           "EXCLUSIVE") == 0)
                this->transport_mux_strategy_ = TAO_EXCLUSIVE_TMS;
            }
        }

      else if (ACE_OS::strcasecmp (argv[curarg],
                                   "-ORBConnectorLock") == 0)
        {
          curarg++;
          if (curarg < argc)
            {
              char *name = argv[curarg];
              
              if (ACE_OS::strcasecmp (name,
                                      "thread") == 0)
                this->cached_connector_lock_type_ = TAO_THREAD_LOCK;
              else if (ACE_OS::strcasecmp (name,
                                           "null") == 0)
                this->cached_connector_lock_type_ = TAO_NULL_LOCK;
            }
        }
    }
  return 0;
}

ACE_Lock *
TAO_Default_Client_Strategy_Factory::create_profile_lock (void)
{
  ACE_Lock *the_lock = 0;

  if (this->profile_lock_type_ == TAO_NULL_LOCK)
    ACE_NEW_RETURN (the_lock,
                    ACE_Lock_Adapter<ACE_SYNCH_NULL_MUTEX> (),
                    0);
  else
    ACE_NEW_RETURN (the_lock,
                    ACE_Lock_Adapter<ACE_SYNCH_MUTEX> (),
                    0);

  return the_lock;
}

// @@ Alex: implement the WS and TMS methods here, similar to the
//    create_profile_lock above...
// @@ Alex: remember your idea of using the
//    -ORBclientconnectionhandler option to implement the WS factory,
//    but you need new options for the TMS...

// Create the correct client transport muxing strategy.
TAO_Transport_Mux_Strategy *
TAO_Default_Client_Strategy_Factory::create_transport_mux_strategy (TAO_Transport *transport)
{
  TAO_Transport_Mux_Strategy *tms = 0;

  if (this->transport_mux_strategy_ == TAO_MUXED_TMS)
    ACE_NEW_RETURN (tms,
                    TAO_Muxed_TMS (transport),
                    0);
  else
    ACE_NEW_RETURN (tms,
                    TAO_Exclusive_TMS (transport),
                    0);

  return tms;
}

TAO_Wait_Strategy *
TAO_Default_Client_Strategy_Factory::create_wait_strategy (TAO_Transport *transport)
{
  TAO_Wait_Strategy *ws = 0;

  if (this->wait_strategy_ == TAO_WAIT_ON_READ)
    ACE_NEW_RETURN (ws,
                    TAO_Wait_On_Read (transport),
                    0);
  else if (this->wait_strategy_ == TAO_WAIT_ON_REACTOR)
    ACE_NEW_RETURN (ws,
                    TAO_Wait_On_Reactor (transport),
                    0);
  else
    {
      // = Leader follower model.
      
      if (this->transport_mux_strategy_ == TAO_EXCLUSIVE_TMS)
        ACE_NEW_RETURN (ws,
                        TAO_Exclusive_Wait_On_Leader_Follower (transport),
                        0);
      else
        ACE_NEW_RETURN (ws,
                        TAO_Muxed_Wait_On_Leader_Follower (transport),
                        0);
    }
      
  return ws;
}

ACE_Lock *
TAO_Default_Client_Strategy_Factory::create_cached_connector_lock (void)
{
  ACE_Lock *the_lock = 0;

  if (this->cached_connector_lock_type_ == TAO_NULL_LOCK)
    ACE_NEW_RETURN (the_lock,
                    ACE_Lock_Adapter<ACE_SYNCH_NULL_MUTEX>,
                    0);
  else
    ACE_NEW_RETURN (the_lock,
                    ACE_Lock_Adapter<ACE_SYNCH_MUTEX>,
                    0);

  return the_lock;
}

// ****************************************************************

ACE_STATIC_SVC_DEFINE (TAO_Default_Client_Strategy_Factory,
                       ASYS_TEXT ("Client_Strategy_Factory"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_Default_Client_Strategy_Factory),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO, TAO_Default_Client_Strategy_Factory)
