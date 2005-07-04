// -*- C++ -*-

//=============================================================================
/**
 *  @file LB_LoadMinimum.h
 *
 *  $Id$
 *
 *  @author Jaiganesh Balasubramanian <jai@dre.vanderbilt.edu>
 *          Ossama Othman <ossama@uci.edu>
 */
//=============================================================================


#ifndef LB_LOAD_MINIMUM_H
#define LB_LOAD_MINIMUM_H

#include /**/ "ace/pre.h"

#include "LB_LoadMap.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/CosLoadBalancingS.h"

#include "ace/Synch_Traits.h"
#include "ace/Thread_Mutex.h"

namespace TAO_LB
{
  /**
   * @name Default LoadMinimum strategy parameters.
   *
   * Defaults defined by the Load Balancing specification.
   */
  //@{
  const CORBA::Float LM_DEFAULT_TOLERANCE = 1;
  const CORBA::Float LM_DEFAULT_DAMPENING = 0;
  const CORBA::Float LM_DEFAULT_PER_BALANCE_LOAD = 0;
  //@}

  /**
   * @name TAO-specific LoadMinimum strategy parameters.
   *
   * Parameters internal to TAO's LoadMinimum strategy
   * implementation.
   */
  //@{
  /// Percentage difference between two load values that determines
  /// whether the loads are considered equivalent.
  /**
   * If the percent difference between two loads, i.e.:
   *   (Old Load - New Load) / New Load
   * is less than or equal to this value, the two loads will be
   * considered equivalent.  In such a case, an object group member
   * residing at the location corresponding to one of the two loads
   * will be selected at random.
   */
  const CORBA::Float LM_DEFAULT_LOAD_PERCENT_DIFF_CUTOFF = 0.05f;  // 1%
  const CORBA::Float LM_DEFAULT_DIFF_AVERAGE_CUTOFF = 0.4f;  // 80%
  //@}
}

/**
 * @class TAO_LB_LoadMinimum
 *
 * @brief "Least loaded" load balancing strategy
 *
 * This load balancing strategy is designed to select an object group
 * member residing at a location with the smallest load.
 */
class TAO_LB_LoadMinimum
  : public virtual POA_CosLoadBalancing::Strategy
{
public:

  /// Constructor.
  TAO_LB_LoadMinimum (PortableServer::POA_ptr poa);

  /**
   * @name CosLoadBalancing::Strategy methods
   *
   * Methods required by the CosLoadBalancing::Strategy interface.
   */
  //@{
  virtual char * name (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CosLoadBalancing::Properties * get_properties (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void push_loads (
      const PortableGroup::Location & the_location,
      const CosLoadBalancing::LoadList & loads
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CosLoadBalancing::LoadList * get_loads (
      CosLoadBalancing::LoadManager_ptr load_manager,
      const PortableGroup::Location & the_location
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     CosLoadBalancing::LocationNotFound));

  virtual CORBA::Object_ptr next_member (
      PortableGroup::ObjectGroup_ptr object_group,
      CosLoadBalancing::LoadManager_ptr load_manager
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound,
                     PortableGroup::MemberNotFound));

  virtual void analyze_loads (
      PortableGroup::ObjectGroup_ptr object_group,
      CosLoadBalancing::LoadManager_ptr load_manager
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  //@}

  /// Returns the default POA for this servant.
  virtual PortableServer::POA_ptr _default_POA (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    );

  /// Initialize the LoadMinimum instance with the given properties.
  void init (const PortableGroup::Properties & props
             ACE_ENV_ARG_DECL);

protected:

  /// Destructor.
  ~TAO_LB_LoadMinimum (void);

  /// Retrieve the least loaded location from the given list of
  /// locations.
  CORBA::Boolean get_location (CosLoadBalancing::LoadManager_ptr load_manager,
                               const PortableGroup::Locations & locations,
                               PortableGroup::Location & location
                               ACE_ENV_ARG_DECL);

  /// Return the effective load.
  CORBA::Float effective_load (CORBA::Float previous_load,
                               CORBA::Float new_load);

  /// Push the new load into this Strategy's load processor, and
  /// return the corresponding effective load.
  void push_loads (
      const PortableGroup::Location & the_location,
      const CosLoadBalancing::LoadList & loads,
      CosLoadBalancing::Load & effective_load
      ACE_ENV_ARG_DECL);

  /// Utility method to extract a CORBA::Float value from the given
  /// property.
  void extract_float_property (const PortableGroup::Property & property,
                               CORBA::Float & value
                               ACE_ENV_ARG_DECL);

private:

  /// This servant's default POA.
  PortableServer::POA_var poa_;

  /// Table that maps location to load list.
  TAO_LB_LoadMap * load_map_;

  /// Lock used to ensure atomic access to state retained by this
  /// class.
  TAO_SYNCH_MUTEX * lock_;

  /// Cached set of properties used when initializing this strategy.
  CosLoadBalancing::Properties properties_;

  /**
   * @name LoadMinimum Property Values
   *
   * Cached LoadMinimum load balancing strategy property values.
   */
  //@{

  ///
  CORBA::Float tolerance_;

  ///
  CORBA::Float dampening_;

  ///
  CORBA::Float per_balance_load_;

  //@}

};


#if defined (__ACE_INLINE__)
#include "LB_LoadMinimum.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif  /* LB_LOAD_MINIMUM_H */
