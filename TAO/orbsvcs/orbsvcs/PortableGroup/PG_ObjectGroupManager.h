// -*- C++ -*-

//=============================================================================
/**
 * @file PG_ObjectGroupManager.h
 *
 * $Id$
 *
 * @author Ossama Othman <ossama@uci.edu>
 */
//=============================================================================


#ifndef TAO_PG_OBJECT_GROUP_MANAGER_H
#define TAO_PG_OBJECT_GROUP_MANAGER_H

#include /**/ "ace/pre.h"

#include "orbsvcs/PortableGroupS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "PG_ObjectGroup_Map.h"
#include "PG_Location_Map.h"


#include "tao/PortableServer/Key_Adapters.h"
#include "tao/PortableServer/PortableServerC.h"
#include "tao/IORManipulation/IORManip_Loader.h"

/// Forward declarations
class TAO_PG_GenericFactory;


/**
 * @class TAO_PG_ObjectGroupManager
 *
 * @brief PortableGroup::ObjectGroupManager implementation.
 *
 * The ObjectGroupManager provides the interface necessary to
 * facilitate application-controlled object group membership.
 */
class TAO_PortableGroup_Export TAO_PG_ObjectGroupManager
  : public virtual POA_PortableGroup::ObjectGroupManager
{
public:

  /// Constructor.
  TAO_PG_ObjectGroupManager (void);

  /// Destructor.
  virtual ~TAO_PG_ObjectGroupManager (void);

  /**
   * @name PortableGroup::ObjectGroupManager methods
   *
   * Methods required by the PortableGroup::ObjectGroupManager
   * interface.
   */
  //@{

  /// Create a member and add it to the given object group.
  virtual PortableGroup::ObjectGroup_ptr create_member (
      PortableGroup::ObjectGroup_ptr object_group,
      const PortableGroup::Location & the_location,
      const char * type_id,
      const PortableGroup::Criteria & the_criteria
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound,
                     PortableGroup::MemberAlreadyPresent,
                     PortableGroup::NoFactory,
                     PortableGroup::ObjectNotCreated,
                     PortableGroup::InvalidCriteria,
                     PortableGroup::CannotMeetCriteria));

  /// Add an existing object to the ObjectGroup.
  virtual PortableGroup::ObjectGroup_ptr add_member (
      PortableGroup::ObjectGroup_ptr object_group,
      const PortableGroup::Location & the_location,
      CORBA::Object_ptr member
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound,
                     PortableGroup::MemberAlreadyPresent,
                     PortableGroup::ObjectNotAdded));

  /**
   * Remove an object at a specific location from the given
   * ObjectGroup.  Deletion of application created objects must be
   * deleted by the application.  Objects created by the
   * infrastructure (load balancer) will be deleted by the
   * infrastructure.
   */
  virtual PortableGroup::ObjectGroup_ptr remove_member (
      PortableGroup::ObjectGroup_ptr object_group,
      const PortableGroup::Location & the_location
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound,
                     PortableGroup::MemberNotFound));

  /// Return the locations of the members in the given ObjectGroup.
  virtual PortableGroup::Locations * locations_of_members (
      PortableGroup::ObjectGroup_ptr object_group
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound));

  /// Return the locations of the members in the given ObjectGroup.
  virtual PortableGroup::ObjectGroups * groups_at_location (
      const PortableGroup::Location & the_location
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the ObjectGroupId for the given ObjectGroup.
  /// @note Does this method make sense for load balanced objects?
  virtual PortableGroup::ObjectGroupId get_object_group_id (
      PortableGroup::ObjectGroup_ptr object_group
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound));

  /// @note Does this method make sense for load balanced objects?
  virtual PortableGroup::ObjectGroup_ptr get_object_group_ref (
      PortableGroup::ObjectGroup_ptr object_group
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound));

  /// Return the reference corresponding to the member of a given
  /// ObjectGroup at the given location.
  virtual CORBA::Object_ptr get_member_ref (
      PortableGroup::ObjectGroup_ptr object_group,
      const PortableGroup::Location & loc
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound,
                     PortableGroup::MemberNotFound));

  /**
   * TAO-specific extension.
   * Return the ObjectGroup reference for the given ObjectGroupId.
   */
   virtual PortableGroup::ObjectGroup_ptr get_object_group_ref_from_id (
        PortableGroup::ObjectGroupId group_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , PortableGroup::ObjectGroupNotFound
      ));

  //@}

  /// TAO-specific member addition method.
  /**
   * This method is meant to be invoked by TAO's GenericFactory
   * implementation.  It is designed to allow only certain exceptions
   * to be propagated to the caller, and to prevent redundant remote
   * RepositoryId checking.
   */
  PortableGroup::ObjectGroup_ptr _tao_add_member (
      PortableGroup::ObjectGroup_ptr object_group,
      const PortableGroup::Location & the_location,
      CORBA::Object_ptr member,
      const char * type_id,
      const CORBA::Boolean propagate_member_already_present
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::MemberAlreadyPresent,
                     PortableGroup::NoFactory));

  /// Create object an empty object.
  /**
   * @note This method is used mainly by the
   *       GenericFactory::create_object() method.
   */
  PortableGroup::ObjectGroup_ptr create_object_group (
    const char * type_id,
    const char * domain_id,
    const PortableGroup::Criteria & the_criteria,
    PortableGroup::ObjectGroupId & group_id
    ACE_ENV_ARG_DECL);

  /// Destroy the object group corresponding to the given ObjectGroupId.
  /**
   * @note This method is used mainly by the
   *       GenericFactory::delete_object() method.
   */
  void destroy_object_group (const PortableGroup::ObjectGroupId group_id
                             ACE_ENV_ARG_DECL);

  /// Return the properties set when the object group was created, and
  /// the dynamic properties that may have overridden them.
  PortableGroup::Properties * get_properties (
      PortableGroup::ObjectGroup_ptr object_group
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound));

  /// Return the dynamic properties for the given group.
  PortableGroup::Properties * get_dynamic_properties (
      PortableGroup::ObjectGroup_ptr object_group
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound));

  /// Return the type_id for the given object group.
  char * type_id (PortableGroup::ObjectGroup_ptr object_group
                  ACE_ENV_ARG_DECL);

  /// Return the object group associated with the given ObjectId.
  /**
   * @return Returns PortableGroup::ObjectGroup::_nil() if no object
   *         group corresponding to the given ObjectId exists.
   */
  PortableGroup::ObjectGroup_ptr object_group (
      const PortableGroup::ObjectGroupId ogid);

  /// Return the number of members in the given object group.
  CORBA::ULong member_count (PortableGroup::ObjectGroup_ptr group
                             ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound));

  /// Initializes the group manager.
  int init (CORBA::ORB_ptr orb, PortableServer::POA_ptr p);

  /// Set the pointer to the GenericFactory associated with this
  /// ObjectGroupManager.
  /**
   * The TAO_PG_GenericFactory will only be used when
   * ObjectGroupManager::remove_member() is explicitly called so that
   * the infrastructure may be given an opportunity to clean up any
   * object group members it may have created.
   */
  void generic_factory (TAO_PG_GenericFactory * generic_factory);

protected:

  /// Underlying and non-locking implementation of the add_member()
  /// and _tao_add_member() methods in this class.
  PortableGroup::ObjectGroup_ptr add_member_i (
    PortableGroup::ObjectGroup_ptr object_group,
    const PortableGroup::Location & the_location,
    CORBA::Object_ptr member,
    const CORBA::Boolean check_type_id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableGroup::ObjectGroupNotFound,
                   PortableGroup::MemberAlreadyPresent,
                   PortableGroup::ObjectNotAdded));

  /// Obtain the ObjectGroup hash map entry corresponding to the given
  /// ObjectGroup reference.
  TAO_PG_ObjectGroup_Map_Entry * get_group_entry (
      PortableGroup::ObjectGroup_ptr object_group
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectGroupNotFound));


  /// Check if a member resides at the location to which the group
  /// array belongs to.
  /**
   * A member is actually represented by the object group to which it
   * belongs.  In this implementation, a pointer to a object group
   * hash map entry is associated with a given a location.
   */
  CORBA::Boolean member_already_present (
    const TAO_PG_ObjectGroup_Array & groups,
    TAO_PG_ObjectGroup_Map_Entry * group_entry);

  /// Verify that the member type_id matches the object group type_id.
  /**
   * @todo Strategize this -- e.g. strict type checking.
   */
  CORBA::Boolean valid_type_id (
    PortableGroup::ObjectGroup_ptr object_group,
    TAO_PG_ObjectGroup_Map_Entry * group_entry,
    CORBA::Object_ptr member
    ACE_ENV_ARG_DECL);

  /**
   * Allocate an ogid for a new object group
   */
  void allocate_ogid (PortableGroup::ObjectGroupId & ogid);

  /**
   * convert numeric OGID to Sequence<Octet> oid
   */
  PortableServer::ObjectId * convert_ogid_to_oid (PortableGroup::ObjectGroupId ogid);

private:

  /// The orb
  CORBA::ORB_var orb_;

  /// Reference to the POA that created the object group references.
  PortableServer::POA_var poa_;

  /// The ORBs IORManipulation object
  TAO_IOP::TAO_IOR_Manipulation_var iorm_;

  /// The underlying table that contains all object group
  /// information.
  TAO_PG_ObjectGroup_Map object_group_map_;

  /// Map that contains list of all members at a given location, in
  /// addition to the load monitor at that location.
  TAO_PG_Location_Map location_map_;

  /// Pointer to the TAO_PG_GenericFactory class responsible for
  /// object group creation/destruction.
  TAO_PG_GenericFactory * generic_factory_;

  /// Lock used to synchronize access to the underlying tables.
  TAO_SYNCH_MUTEX lock_;

  /// Lock used to synchronize access to next_ogid_.
  TAO_SYNCH_MUTEX lock_ogid_;

  /// Next ogid to be allocated.
  PortableGroup::ObjectGroupId next_ogid_;

};


#include /**/ "ace/post.h"

#endif  /* TAO_PG_OBJECT_GROUP_MANAGER_H */
