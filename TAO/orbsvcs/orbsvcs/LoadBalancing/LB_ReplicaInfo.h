// -*- C++ -*-

//=======================================================================
/**
 *  @file    LB_ReplicaInfo.h
 *
 *  $Id$
 *
 *  @author  Ossama Othman <ossama@uci.edu>
 */
//=======================================================================


#ifndef TAO_LB_REPLICA_INFO_H
#define TAO_LB_REPLICA_INFO_H

#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "orbsvcs/LoadBalancingC.h"

#include "LB_Replica_Set.h"

class TAO_LB_ReplicaInfo;
typedef ACE_Unbounded_Set<TAO_LB_ReplicaInfo *> TAO_LB_ReplicaInfoSet;
typedef ACE_Unbounded_Set_Iterator<TAO_LB_ReplicaInfo *> TAO_LB_ReplicaInfoSetIterator;


/**
 * @class TAO_LB_ReplicaInfo
 *
 * @brief Class that contains all replica-specific information.
 */
class TAO_LB_ReplicaInfo
{
public:

  /// Reference to the replica.
  CORBA::Object_var replica;

  /// FactoryInfo used when creating the replica.
  LoadBalancing::FactoryInfo factory_info;

  /// FactoryCreationId assigned to this replica.  This
  /// FactoryCreationId_var will contain a zero pointer if the replica
  /// was not created using a GenericFactory.
  LoadBalancing::GenericFactory::FactoryCreationId_var factory_creation_id;

};

#include "ace/post.h"

#endif  /* TAO_LB_REPLICA_INFO_H */
