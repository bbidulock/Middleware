//=============================================================================
/**
 *  @file    Thread_Lane_Resources.h
 *
 *  $Id$
 *
 *  @author  Irfan Pyarali
 */
// ===================================================================

#ifndef TAO_THREAD_LANE_RESOURCES_H
#define TAO_THREAD_LANE_RESOURCES_H

#include "ace/pre.h"
#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/corbafwd.h"

class TAO_ORB_Core;
class TAO_Acceptor_Registry;
class TAO_Transport_Cache_Manager;
class TAO_Leader_Follower;

/**
 * @class TAO_Thread_Lane_Resources
 *
 * @brief Class representing a thread lane's resources.
 *
 * \nosubgrouping
 *
 **/
class TAO_Export TAO_Thread_Lane_Resources
{
public:
  /// Constructor.
  TAO_Thread_Lane_Resources (TAO_ORB_Core &orb_core);

  /// Destructor.
  ~TAO_Thread_Lane_Resources (void);

  /// Checks if the acceptor registry has been created.
  int has_acceptor_registry_been_created (void) const;

  /// Open the acceptor registry.
  int open_acceptor_registry (int ignore_address,
                              CORBA::Environment &ACE_TRY_ENV);

  /// Finalize resources.
  void finalize (void);

  /// Shutdown the reactor.
  void shutdown_reactor (void);

  /// @name Accessors
  // @{

  TAO_Acceptor_Registry &acceptor_registry (void);

  TAO_Transport_Cache_Manager &transport_cache (void);

  TAO_Leader_Follower &leader_follower (void);

  // @}

private:
  /// ORB_Core related to this thread lane.
  TAO_ORB_Core &orb_core_;

  /// The registry which maintains a list of acceptor factories for
  /// each loaded protocol.
  TAO_Acceptor_Registry *acceptor_registry_;

  /// Transport cache.
  TAO_Transport_Cache_Manager *transport_cache_;

  /// The leader/followers management class for this lane.
  TAO_Leader_Follower *leader_follower_;

  /// Synchronization.
  TAO_SYNCH_MUTEX lock_;
};

#if defined (__ACE_INLINE__)
# include "tao/Thread_Lane_Resources.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"

#endif /* TAO_THREAD_LANE_RESOURCES_H */
