// -*- C++ -*-

//=============================================================================
/**
 *  @file LoadBalancing_Strategy.h
 *
 *  $Id$
 *
 *  @author Ossama Othman <ossama@uci.edu>
 */
//=============================================================================


#ifndef TAO_LB_BALANCING_STRATEGY_H
#define TAO_LB_BALANCING_STRATEGY_H

#include "ace/pre.h"

#include "orbsvcs/LoadBalancingS.h"
#include "LoadBalancing_export.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_LB_ReplicaProxy;


/**
 * @class TAO_LB_Balancing_Strategy
 *
 * @brief Load balancing strategy abstract base class.
 *
 * This abstract base class defines the interface load balancing
 * strategies should implement.
 */
class TAO_LoadBalancing_Export TAO_LB_Balancing_Strategy
{
public:

  /// Destructor
  virtual ~TAO_LB_Balancing_Strategy (void);

  // @@ The name of the method should be more meaningful, what about:
  //    select_replica(), select_unloaded_replica() or something like
  //    that?
  /// Return the object reference to the Replica to which requests should
  /// be redirected.
  virtual CORBA::Object_ptr replica (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  /// Insert ReplicaProxy servant into the set of replica proxies upon
  /// which the load balancing algorithm is performed.
  virtual int insert (TAO_LB_ReplicaProxy *) = 0;

  /// Remove ReplicaProxy servant from the set of replica proxies.
  virtual int remove (TAO_LB_ReplicaProxy *) = 0;

  /**
   * The load on one proxy has changed.
   * @@ Ossama: see my comments on LoadBalancing_i about changing the
   * signature of this method.
   */
  virtual void load_changed (TAO_LB_ReplicaProxy *proxy,
                             CORBA::Environment &ACE_TRY_ENV);
};

#if !defined (__ACE_INLINE__)
#include "LoadBalancing_Strategy.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"

#endif  /* TAO_LB_BALANCING_STRATEGY_H */
