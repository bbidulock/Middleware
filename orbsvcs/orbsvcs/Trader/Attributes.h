/* -*- C++ -*- */

// ========================================================================
// $Id$
// 
// = LIBRARY
//    orbsvcs
// 
// = FILENAME
//    Attributes.h
//
// = AUTHOR
//    Marina Spivak <marina@cs.wustl.edu>
//    Seth Widoff <sbw1@cs.wustl.edu>
//    Irfan Pyarali <irfan@cs.wustl.edu>
// 
// ========================================================================

#ifndef TAO_ATTRIBUTES_H
#define TAO_ATTRIBUTES_H

#include "orbsvcs/CosTradingS.h"

#if defined(_MSC_VER)
#pragma warning (disable:4250)
#endif /* _MSC_VER */

class TAO_Lockable
// = DESCRIPTION
//   Class used to remove the circular dependencies between the
//   Attribute classes with the Trader class.  
{
public: 

  virtual ACE_Lock& lock (void) = 0;  
};

class TAO_ORBSVCS_Export TAO_Support_Attributes_Impl
  // = TITLE
  //     This class stores, allows access to and modification of 
  //     trader's support attributes.
  //
  // = DESCRIPTION
  //     Contains a reference to the trader from which it is
  //     used so it can use trader's lock.
{
public:
  // = Initialization and termination methods.
  TAO_Support_Attributes_Impl (TAO_Lockable &locker);
  ~TAO_Support_Attributes_Impl ();

  // = Accessor methods.
  CORBA::Boolean supports_modifiable_properties (void) const;
  void supports_modifiable_properties (CORBA::Boolean);

  CORBA::Boolean supports_dynamic_properties (void) const;
  void supports_dynamic_properties (CORBA::Boolean);

  CORBA::Boolean supports_proxy_offers (void) const;
  void supports_proxy_offers (CORBA::Boolean);

  CosTrading::TypeRepository_ptr type_repos (void) const;
  void type_repos (CosTrading::TypeRepository_ptr);

private:

  TAO_Lockable &locker_;
  // A reference to the trader (needed for obtaining the lock.)

  CORBA::Boolean supports_modifiable_properties_;
  // Indicator of whether the trader supports property modification.

  CORBA::Boolean supports_dynamic_properties_;
  // Indicator of whether the trader supports dynamic properties.

  CORBA::Boolean supports_proxy_offers_;
  // Indicator of whether the trader supports proxy offers.

  CORBA::Object_var type_repos_;
  // A reference to the TypeRepostitory used by the trader.
};

class TAO_ORBSVCS_Export TAO_Link_Attributes_Impl
  // = TITLE
  //     This class stores, allows access to and modification of 
  //     trader's link attributes.
  //
  // = DESCRIPTION
  //     Contains a reference to the trader from which it is
  //     used so it can use trader's lock.
{
public:
  // = Initialization and termination methods.

  TAO_Link_Attributes_Impl (TAO_Lockable &locker);
  ~TAO_Link_Attributes_Impl ();

  // = Accessor methods.
  
  CosTrading::FollowOption max_link_follow_policy (void) const;
  void  max_link_follow_policy (CosTrading::FollowOption);

private:

  TAO_Lockable &locker_;
  // A reference to the trader (needed for obtaining the lock.)

  CosTrading::FollowOption max_link_follow_policy_;
  // 
};

class TAO_ORBSVCS_Export TAO_Import_Attributes_Impl
  // = TITLE
  //     This class stores, allows access to and modification of 
  //     trader's import attributes.
  //
  // = DESCRIPTION
  //     Contains a reference to the trader from which it is
  //     used so it can use trader's lock.
{
public:
  // = Initialization and termination methods.

  TAO_Import_Attributes_Impl (TAO_Lockable &locker);

  ~TAO_Import_Attributes_Impl (void);

  // = Accessor methods.
  
  CORBA::ULong def_search_card (void) const;
  void def_search_card (CORBA::ULong);
	
  CORBA::ULong max_search_card (void) const;
  void max_search_card (CORBA::ULong);

  CORBA::ULong def_match_card (void) const;
  void def_match_card (CORBA::ULong);

  CORBA::ULong max_match_card (void) const;
  void max_match_card (CORBA::ULong);

  CORBA::ULong def_return_card (void) const;
  void def_return_card (CORBA::ULong);

  CORBA::ULong max_return_card (void) const;
  void max_return_card (CORBA::ULong);

  CORBA::ULong max_list (void) const;
  void max_list (CORBA::ULong);

  CORBA::ULong def_hop_count (void) const;
  void def_hop_count (CORBA::ULong);

  CORBA::ULong max_hop_count (void) const;
  void max_hop_count (CORBA::ULong);

  CosTrading::FollowOption def_follow_policy (void) const;
  void def_follow_policy (CosTrading::FollowOption);

  CosTrading::FollowOption max_follow_policy (void) const;
  void max_follow_policy (CosTrading::FollowOption);

private:

  TAO_Lockable &locker_;

  CORBA::ULong def_search_card_;
  // Upper bound of offers to be searched if <search_card>
  // is not specified.  

  CORBA::ULong max_search_card_;
  // Maximum upper bound of offers to be searched.

  CORBA::ULong def_match_card_;
  // Upper bound of matched offers to be ordered if 
  // <match_card> is not specified).  

  CORBA::ULong max_match_card_; 
  // Maximum upper bound of matched offers to be ordered.

  CORBA::ULong def_return_card_;
  // Upper bound of ordered offers to be returned if 
  // <returned_card> is not specified.

  CORBA::ULong max_return_card_; 
  // Maximum upper bound of ordered offers to be returned.

  CORBA::ULong max_list_;
  // Upper bound of depth
    
  CORBA::ULong def_hop_count_;
  // Upper bound of depth of links to be traversed if <hop_count> is
  // not specified.

  CORBA::ULong max_hop_count_;
  // Maximum upper bound of depth of links to be traversed.
    
  CosTrading::FollowOption def_follow_policy_;
  // Default link follow policy for a particular trader.

  CosTrading::FollowOption max_follow_policy_;
  // Limiting link follow policy for all links of the trader -
  // overrides both link and importer policies.
};

class TAO_ORBSVCS_Export TAO_Trading_Components_Impl
  //
  // = TITLE
  //     Set/get methods for references to various
  //     interfaces of the trader.
  //
  // = DESCRIPTION
  //     Note, this class is for use in local address space only and is NOT a
  //     direct implementation of IDL methods. (Implementation of 
  //     IDL methods in CosTrading::Trader_Components would need
  //     add a _duplicate call for each get method). 
{
public:

  // = Initialization and termination methods.
  TAO_Trading_Components_Impl (TAO_Lockable &locker);
  ~TAO_Trading_Components_Impl (void);

  // = CosTrading::TraderComponents methods. 

  CosTrading::Lookup_ptr lookup_if (void) const;
  // Returns an object reference to the Lookup interface of the trader.
  // Returns nil if the trader does not support Lookup interface.

  void lookup_if (CosTrading::Lookup_ptr);
  // Set the reference to the Lookup interface.
  
  CosTrading::Register_ptr register_if (void) const;
  // Returns object reference for the Register interface of the trader.
  // Returns nil if the trader does not support Register interface.

  void register_if (CosTrading::Register_ptr);
  // Set the reference to the Register interface of the trader.
  
  CosTrading::Link_ptr link_if (void) const;
  // Returns object reference for the Link interface of the trader.
  // Returns nil if the trader does not support Link interface.

  void link_if (CosTrading::Link_ptr);
  // Set the reference to the Link interface of the trader.

  CosTrading::Proxy_ptr proxy_if (void) const;
  // Returns object reference to the Proxy interface of the trader.
  // Returns nil if the trader does not support Proxy interface. 

  void proxy_if (CosTrading::Proxy_ptr);
  // Set the reference to the Proxy interface of the trader.
  
  CosTrading::Admin_ptr admin_if (void) const;
  // Returns object reference for the Admin interface of the trader.
  // Returns nil if the trader does not support Admin interface.

  void admin_if (CosTrading::Admin_ptr);
  // Set the reference to the Admin interface of the trader.

private:

  TAO_Lockable &locker_;

  CosTrading::Lookup_var lookup_;
  CosTrading::Register_var register_;
  CosTrading::Link_var link_;
  CosTrading::Proxy_var proxy_;
  CosTrading::Admin_var admin_;
};

#endif /* TAO_ATTRIBUTES_H */
