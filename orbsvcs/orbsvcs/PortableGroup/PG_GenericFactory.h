// -*- C++ -*-

//=============================================================================
/**
 * @file  PG_GenericFactory.h
 *
 * $Id$
 *
 * @author Ossama Othman <ossama@uci.edu>
 */
//=============================================================================


#ifndef TAO_PG_GENERIC_FACTORY_H
#define TAO_PG_GENERIC_FACTORY_H

#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "PG_Factory_Map.h"

#include "tao/PortableServer/PortableServerC.h"
#include "orbsvcs/PortableGroupC.h"


/// Forward declarations.
class TAO_PG_ObjectGroupManager;
class TAO_PG_PropertyManager;

struct TAO_PG_ObjectGroup_Map_Entry;


/**
 * @class TAO_PG_GenericFactory
 *
 * @brief PortableGroup::GenericFactory implementation used by the
 *        load balancer when creating object groups.
 *
 * This GenericFactory creates an object group reference for given set
 * of replicas.  Those replicas will be created by this GenericFactory
 * if the "infrastructure-controlled" membership style is configured.
 */
class TAO_PortableGroup_Export TAO_PG_GenericFactory
  : public virtual PortableGroup::GenericFactory
{
public:

  /// Constructor.
  TAO_PG_GenericFactory (TAO_PG_ObjectGroupManager & object_group_map,
                         TAO_PG_PropertyManager & property_manager);

  /// Destructor.
  ~TAO_PG_GenericFactory (void);

  /**
   * @name TAO_LoadBalancer::GenericFactory methods
   */
  //@{

  /**
   * Create an object of the specified type that adheres to the
   * restrictions defined by the provided Criteria.  The out
   * FactoryCreationId parameter may be passed to the delete_object()
   * method to delete the object.
   */
  virtual CORBA::Object_ptr create_object (
      const char * type_id,
      const PortableGroup::Criteria & the_criteria,
      PortableGroup::GenericFactory::FactoryCreationId_out
        factory_creation_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::NoFactory,
                     PortableGroup::ObjectNotCreated,
                     PortableGroup::InvalidCriteria,
                     PortableGroup::InvalidProperty,
                     PortableGroup::CannotMeetCriteria));

  /**
   * Delete the object corresponding to the provided
   * FactoryCreationId.  If the object is actually an ObjectGroup,
   * then all members within the ObjectGroup will be deleted.
   * Afterward, the ObjectGroup itself will be deleted.
   */
  virtual void delete_object (
      const PortableGroup::GenericFactory::FactoryCreationId &
        factory_creation_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableGroup::ObjectNotFound));

  //@}

  /// Set the POA to use when creating object references.
  void poa (PortableServer::POA_ptr p);

private:

  /// Call delete_object() on all factories use to create members in a
  /// given object group.
  /**
   * If ignore_exceptions is true, any exception returned from the
   * delete_object() call on the remote factory will be ignored in
   * order to allow other objects to be deleted via other registered
   * factories.
   */
  void delete_object_i (TAO_PG_Factory_Set & factory_set,
                        CORBA::Boolean ignore_exceptions
                        ACE_ENV_ARG_DECL);

  /// Populate the object group being created.  Called when the
  /// infrastructure-controlled membership style is used for the
  /// object group being created.
  void populate_object_group (
         CORBA::ULong fcid,
         PortableGroup::ObjectGroup_ptr object_group,
         const PortableServer::ObjectId & oid,
         const char * type_id,
         const PortableGroup::FactoryInfos &factory_infos,
         const PortableGroup::InitialNumberMembersValue initial_number_members
         ACE_ENV_ARG_DECL);

  /// Get a new ObjectId to be used when creating a new ObjectGroup.
  /**
   * An ObjectId created by this method will never be reused within
   * the scope of a given ReplicationManager.  A value suitable for
   * use in a map association <ext_id> is also returned.
   */
  void get_ObjectId (CORBA::ULong fcid,
                     PortableServer::ObjectId_out oid);

  /// Process criteria to be applied to the object group being
  /// created.
  /**
   * Only the MemberShipStyle, Factories, InitialNumberMembers and
   * MinimumNumberMembers criteria/properties are defined by the
   * PortableGroup IDL.  Other services that implement the
   * GenericFactory interface, such as load balancing and fault
   * tolerance, may choose to support more.
   * @par
   * The extracted criteria are object group-specific.  In particular,
   * they are the object group creation time criteria.
   */
  void process_criteria (
    const char * type_id,
    const PortableGroup::Criteria & criteria,
    PortableGroup::MembershipStyleValue & membership_style,
    PortableGroup::FactoriesValue *& factory_infos,
    PortableGroup::InitialNumberMembersValue & initial_number_members,
    PortableGroup::MinimumNumberMembersValue & minimum_number_members
    ACE_ENV_ARG_DECL);

private:

  /// Reference to the POA used to create object group references.
  PortableServer::POA_var poa_;

  /// Reference to the ObjectGroup map.
  TAO_PG_ObjectGroupManager & object_group_manager_;

  /// Reference to the PropertyManager.
  TAO_PG_PropertyManager & property_manager_;

  /// Table that maps FactoryCreationId to TAO_PG_Factory_Set.
  /**
   * The TAO_PG_Factory_Set corresponding to a given FactoryCreationId
   * contains the information necessary to clean up objects (members)
   * that were created by the infrastructure, i.e. this
   * GenericFactory.  For example, this GenericFactory will invoke
   * other application defined GenericFactorys when creating new
   * object group members.  The information returned from those
   * application defined GenericFactorys is stored in a
   * TAO_PG_Factory_Set, and thus this table.
   */
  TAO_PG_Factory_Map factory_map_;

  /// The FactoryCreationId that will be assigned to the next object
  /// group that is created.
  /**
   * Value that is used when assigning a FactoryCreationId to the
   * factory that was used to create a given ObjectGroup.  The
   * FactoryCreationId is typically comprised of this value in
   * addition to another value that makes it unique to a given Load
   * Balancer.
   */
  CORBA::ULong next_fcid_;

  /// Lock used to synchronize access to the factory creation id
  /// index (i.e. next_fcid_).
  TAO_SYNCH_MUTEX lock_;

};


#include "ace/post.h"

#endif  /* TAO_PG_GENERIC_FACTORY_H */
