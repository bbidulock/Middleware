// -*- C++ -*-
//=============================================================================
/**
 *  @file    PG_Object_Group.h
 *
 *  $Id$
 *
 *  Manage all information related to an object group.
 *  @@ Note: the above description is optimistic.  The hope is to eventually
 *  @@ consolidate all information related to an object group into this object.
 *  @@ however at the moment GenericFactory, ObjectGroupManager, and FT_ReplicationManager
 *  @@ have parallel collections of object group information.
 *
 *  @author Dale Wilson <wilson_d@ociweb.com>
 */
//=============================================================================

#ifndef TAO_PG_OBJECT_GROUP_H_
#define TAO_PG_OBJECT_GROUP_H_
#include /**/ <ace/pre.h>
#include <ace/ACE.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "PG_Properties_Decoder.h"

//////////////////////////////////
// Classes declared in this header
namespace TAO
{
  class PG_Object_Group;
}

/////////////////////////////////
// Includes needed by this header
#include <orbsvcs/PortableGroupC.h>
#include <tao/PortableServer/PortableServer.h>
#include <ace/Hash_Map_Manager_T.h>
#include "PG_Location_Hash.h"
#include "PG_Location_Equal_To.h"
#include "PG_Object_Group_Manipulator.h"

/////////////////////
// Forward references

namespace TAO_IOP
{
  class TAO_IOR_Property;
}

////////////////
// Class declarations
namespace TAO
{
  /**
   */
  class TAO_PortableGroup_Export PG_Object_Group
  {
    // Information about an object group member
    struct MemberInfo
    {
      /// Reference to the member.
      CORBA::Object_var member_;

      /// The factory that was used to create this object
      /// nil if application created.
      PortableGroup::GenericFactory_var factory_;

      /// FactoryCreationId assigned to the member. Empty if application created
      PortableGroup::GenericFactory::FactoryCreationId factory_id_;

      /// Location where this member exists
      PortableGroup::Location location_;


      /// TRUE if this is primary member
      CORBA::Boolean is_primary_;


      ///////////////
      // Methods

      /// Construct an application-supplied member.
      MemberInfo (CORBA::Object_ptr member, const PortableGroup::Location & location);

      /// Construct a infrastructure-created member.
      MemberInfo (
        CORBA::Object_ptr member,
        const PortableGroup::Location & location,
        PortableGroup::GenericFactory_ptr factory,
        PortableGroup::GenericFactory::FactoryCreationId factory_id);

      /// Destructor
      ~MemberInfo();
    };

    typedef TAO_SYNCH_MUTEX MemberMapMutex;
    typedef ACE_Hash_Map_Manager_Ex <
      PortableGroup::Location,
      MemberInfo *,
      TAO_PG_Location_Hash,
      TAO_PG_Location_Equal_To,
      MemberMapMutex>  MemberMap;
    typedef ACE_Hash_Map_Entry <PortableGroup::Location, MemberInfo *> MemberMap_Entry;
    typedef ACE_Hash_Map_Iterator_Ex <
      PortableGroup::Location,
      MemberInfo *,
      TAO_PG_Location_Hash,
      TAO_PG_Location_Equal_To,
      MemberMapMutex> MemberMap_Iterator;

    /**
     * Private constructor -- use static create method.
     * NOTE: gcc complains about private constructor so
     * make it protected.  Now it really should complain
     * about non-virtual destructor, but it's not that smart.
     */
  protected:
    PG_Object_Group (
      CORBA::ORB_ptr orb,
      TAO::PG_Object_Group_Manipulator * manipulator,
      CORBA::Object_ptr empty_group,
      const PortableGroup::TagGroupTaggedComponent & tag_component,
      const char * type_id,
      const PortableGroup::Criteria & the_criteria,
      TAO_PG::Properties_Decoder * type_properties);

  public:

    /// Destructor
    ~PG_Object_Group ();

    /////////////////
    // public methods

  public:

    /// Set object group id
    void set_object_group_id (PortableGroup::ObjectGroupId oid);

    /// Set type ID
    void set_typeid (PortableGroup::TypeId type_id);

    /// return a duplicated reference to this group (IOGR)
    PortableGroup::ObjectGroup_ptr reference()const;

    void set_membership_style (PortableGroup::MembershipStyleValue style);
    PortableGroup::MembershipStyleValue get_membership_style () const;

    void set_initial_number_members (PortableGroup::InitialNumberMembersValue count);
    PortableGroup::InitialNumberMembersValue get_initial_number_members () const;

    void set_minimum_number_members (PortableGroup::MinimumNumberMembersValue count);
    PortableGroup::MinimumNumberMembersValue get_minimum_number_members ()const;

    void set_group_specific_factories (const PortableGroup::FactoryInfos & infos);

    /**
     * Note the caller receives a copy of the factoryinfos in the result argument.
     * inefficient, but thread safe.
     */
    void get_group_specific_factories (PortableGroup::FactoryInfos & result) const;

    /**
     * get location of primary member
     */
    const PortableGroup::Location & primary_location() const;

    /**
     * returns a duplicate
     * caller must release
     */
    PortableGroup::TypeId get_type_id ()const;

    void set_properties_dynamically (
        const PortableGroup::Properties & overrides
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       PortableGroup::InvalidProperty,
                       PortableGroup::UnsupportedProperty));

    void get_properties (PortableGroup::Properties_var & result) const
      ACE_THROW_SPEC ((CORBA::SystemException));

    PortableGroup::ObjectGroupId  get_object_group_id () const;

    /**
     * Add a new member to the group.
     * @param the_location the location for the new member
     * @param member the member to be added
     */
    void add_member (
        const PortableGroup::Location & the_location,
        CORBA::Object_ptr member
        ACE_ENV_ARG_PARAMETER)
      ACE_THROW_SPEC ( (CORBA::SystemException,
                       PortableGroup::ObjectNotAdded));

    /**
     * set the replica at the given location to be primary.
     * Note: This should return void and throw FT::PrimaryNotSet
     * but to avoid dependancies between PortableGroup and FaultTolerance
     * it returns a boolean result.  A false return means caller should
     * throw FT::PrimaryNot_Set.
     */
    int set_primary_member (
      TAO_IOP::TAO_IOR_Property * prop,
      const PortableGroup::Location & the_location
      ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , PortableGroup::MemberNotFound
      ));

    void remove_member (
        const PortableGroup::Location & the_location
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ( (CORBA::SystemException,
                       PortableGroup::MemberNotFound));


    /////////////////////////
    // Implementation methods
  private:

    int increment_version ();
    void distribute_iogr (ACE_ENV_ARG_DECL);

    /////////////////////////
    // Forbidden methods
  private:
    PG_Object_Group ();
    PG_Object_Group (const PG_Object_Group & rhs);
    PG_Object_Group & operator = (const PG_Object_Group & rhs);


    /////////////////
    // Static Methods
  public:
    /**
     * Static creation method needed because exceptions can happen.
     */
    static PG_Object_Group * create (
      CORBA::ORB_ptr orb,
      PortableServer::POA_ptr poa,
      CORBA::Object_ptr empty_group, // empty group as created by ObjectManager
      const char * type_id,
      const PortableGroup::Criteria & the_criteria,
      TAO_PG::Properties_Decoder * type_properties
      ACE_ENV_ARG_DECL);

    ///////////////
    // Static Data
  private:

    ///////////////
    // Data Members
  private:

    /**
     * Protect internal state.
     */
    TAO_SYNCH_MUTEX internals_;
    typedef ACE_Guard<TAO_SYNCH_MUTEX> InternalGuard;

    CORBA::ORB_var orb_;

    // The object group manipulator
    TAO::PG_Object_Group_Manipulator * manipulator_;

    /// boolean true if empty group
    int empty_;

    ACE_CString role_;
    PortableGroup::TypeId type_id_;

    /**
     * the GroupTaggedComponent that defines this group
     * contains:
     *   GIOP::Version component_version;
     *   TAO_String_Manager group_domain_id;
     *   PortableGroup::ObjectGroupId object_group_id;
     *   PortableGroup::ObjectGroupRefVersion object_group_ref_version;
     */
    PortableGroup::TagGroupTaggedComponent tagged_component_;

    /**
     * the reference (IOGR) to this group
     */
    PortableGroup::ObjectGroup_var reference_;

    /**
     * The CORBA object id assigned to this object group
     */
    PortableServer::ObjectId_var object_id_;

    // group members
    MemberMap members_;

    PortableGroup::Location primary_location_;

    // Miscellaneous properties passed to create_object when this group
    // was initially created.  To be used to create new members.
    TAO_PG::Properties_Decoder properties_;

    // Cached property information

    PortableGroup::MembershipStyleValue membership_style_;
    PortableGroup::InitialNumberMembersValue initial_number_members_;
    PortableGroup::MinimumNumberMembersValue minimum_number_members_;
    PortableGroup::FactoryInfos group_specific_factories_;

  };
} // namespace TAO

#include /**/ <ace/post.h>

#endif // TAO_PG_OBJECT_GROUP_H_
