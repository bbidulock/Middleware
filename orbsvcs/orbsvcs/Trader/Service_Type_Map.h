/* -*- C++ -*- */

// ========================================================================
// $Id$
//
// = LIBRARY
//    orbsvcs
// 
// = FILENAME
//    Service_Type_Map.h
//
// = AUTHOR
//    Seth Widoff <sbw1@cs.wustl.edu>
// 
// ========================================================================

#ifndef TAO_SERVICE_TYPE_MAP_H
#define TAO_SERVICE_TYPE_MAP_H

#include "Trader.h"
#include "ace/Map_Manager.h"

class TAO_Offer_Id_Iterator;

template <class LOCK_TYPE> class TAO_Service_Offer_Iterator;

template <class LOCK_TYPE>
class TAO_Service_Type_Map
// = DESCRIPTION
//   The TAO_Service_Type_Map encapsulates the mapping of service
//   types to those offers exported with that service types. The
//   underlying structure is a map of maps. The first maps maps the
//   service type name to a map of exported offers. The second map
//   maps the identifying index for that offer within the service
//   types. So a service type name and an index uniquely identifies an 
//   exported offer. In fact, when the register export interface
//   returns a CosTrading::OfferId, it's returning no more than a
//   simple string concatenation of these two values. In addition to
//   all these wonderful things, the TAO_Service_Type_Map has built-in 
//   locking, one reader/writer-style lock for modifying the top-level 
//   map and a reader/writer-style for each of the offer
//   maps. Needless to say the locks are acquired when the
//   TAO_Service_Type_Map performs operations on the structures they
//   guard.
//
//   NOTE: TAO_Service_Type_Map needs to be parameterized by a
//   READER/WRITER LOCK, a RECURSIVE MUTEX, or a NULL MUTEX, not a
//   simple binary mutex! Mutexes will cause deadlock when you try to
//   contruct an iterator (which acquires a read lock on the map under
//   an existing read lock). Just don't do it, ok?
{
  friend TAO_Service_Offer_Iterator<LOCK_TYPE>;
public:

  // Traits
  typedef TAO_Service_Offer_Iterator<LOCK_TYPE> offer_iterator;
    
  TAO_Service_Type_Map (void);
  // No arg constructor.

  ~TAO_Service_Type_Map (void);
  
  CosTrading::OfferId insert_offer (const char* type,
				    const CosTrading::Offer& offer);
  // Add an offer of type <type> and generate a CosTrading::OfferId
  // for it. Returns 0 on failure.
  
  int remove_offer (const CosTrading::OfferId offer_id,
		    CORBA::Environment& _env)
    TAO_THROW_SPEC ((CosTrading::IllegalOfferId,
		    CosTrading::UnknownOfferId));
  
  CosTrading::Offer* lookup_offer (const CosTrading::OfferId offer_id,
				   CORBA::Environment& _env)
    TAO_THROW_SPEC ((CosTrading::IllegalOfferId,
		    CosTrading::UnknownOfferId));
  // Lookup an offer whose offer_id is <offer_id>, and return
  // it. Otherwise, throw the appropriate exception.

  CosTrading::Offer* lookup_offer (const CosTrading::OfferId offer_id,
				   char*& type_name,
				   CORBA::Environment& _env)
    TAO_THROW_SPEC ((CosTrading::IllegalOfferId,
		    CosTrading::UnknownOfferId));
  // Lookup an offer whose OfferId is <offer_id> and return in
  // <type_name> the type name of the object. Type name is just a
  // pointer to a location in offer_id, so DON'T DELETE IT.

  TAO_Offer_Id_Iterator* retrieve_all_offer_ids (void);
  // Return an iterator that will traverse and return all the offer
  // ids in the service type map.

  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const TAO_Service_Type_Map<LOCK_TYPE> &))
  ACE_UNIMPLEMENTED_FUNC (TAO_Service_Type_Map (const TAO_Service_Type_Map<LOCK_TYPE> &))
  
private:

  class Hashable_ULong
  {
  public:

    Hashable_ULong (void)
      : number_ (0) {}
    
    Hashable_ULong (CORBA::ULong number)
      : number_ (number) {}

    u_long hash (void) const { return number_; }

    Hashable_ULong& operator= (const Hashable_ULong& number)
      { this->number_ = number.number_; }
    
    operator CORBA::ULong (void) const { return number_; }

    friend int operator== (const Hashable_ULong& left,
		    const Hashable_ULong& right)
      { return left.number_ == right.number_; }
    
  private:

    CORBA::ULong number_;   
  };
  
  typedef ACE_Hash_Map_Manager
    <
    //    CORBA::ULong,
    Hashable_ULong,
    CosTrading::Offer,
    ACE_Null_Mutex
    >
    Offer_Map;

  struct Offer_Map_Entry 
  {
    Offer_Map* offer_map_;
    CORBA::ULong counter_;
    LOCK_TYPE lock_;
  };
  
  typedef ACE_Hash_Map_Manager 
    <
    TAO_String_Hash_Key,
    Offer_Map_Entry,
    ACE_Null_Mutex
    >
    Offer_Database;

  CosTrading::Offer* lookup_offer (const char* type,
				   CORBA::ULong id);
  // Lookup an offer whose type is <type> and id, <id>. Return 0 on
  // failure. 

  int remove_offer (const char* type,  CORBA::ULong id);
  // Remove an offers whose id is <offer_id>. Returns 0 on success, -1 
  // on failure, and throws a CosTrading::IllegalOfferId if it can't 
  // parse the CosTrading::OfferId.

  static CosTrading::OfferId generate_offer_id (const char *type_name,
						CORBA::ULong id);
  // Take in a service type name for the offer the current value of
  // of the counter and generate an offer id.
  
  static void parse_offer_id (const CosTrading::OfferId offer_id,
			      char* &service_type,
			      CORBA::ULong& id,
			      CORBA::Environment& _env)
    TAO_THROW_SPEC ((CosTrading::IllegalOfferId));
  // Take in a previously generated offer id and return the type
  // and id that were used to generate the offer id.  

  LOCK_TYPE db_lock_;
  
  Offer_Database offer_db_;
  // The protected data structure.
};

template <class LOCK_TYPE>
class TAO_Service_Offer_Iterator
// = TITLE
//   Local_Offer_Iterator iterates over the set of exported
//   offers for a given type. Handily, it takes care of all the
//   necessary locking, acquiring them in the constructor, and
//   releasing them in the destructor. Since Local_Offer_Iterator
//   is dynamically allocated by TAO_Offer_Id_Iterator, make sure
//   to EXPLICITLY CALL DELETE when you're done with it.
{
 public:

  typedef TAO_Service_Type_Map<LOCK_TYPE> Service_Type_Map;
  
  TAO_Service_Offer_Iterator (const char* type,
			      TAO_Service_Type_Map<LOCK_TYPE>& offer_database);
  
  ~TAO_Service_Offer_Iterator (void);
  // Release all the locks acquired.
  
  int has_more_offers (void);
  // Returns 1 if there are more offers, 0 otherwise.
  
  CosTrading::OfferId get_id (void);
  // Get the id for the current offer.
    
  CosTrading::Offer* get_offer (void);
  // Returns the next offer in the series.
  
  void next_offer (void);
  // Advances the iterator 1.
  
 private:
  // Protected constructor.

  TAO_Service_Type_Map<LOCK_TYPE>& stm_;

  TAO_Service_Type_Map<LOCK_TYPE>::Offer_Map_Entry* entry_;

  TAO_Service_Type_Map<LOCK_TYPE>::Offer_Map::iterator* offer_iter_;
  
  const char* type_;
};


#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "Service_Type_Map.cpp"
#endif  /* ACE_TEMPLATES_REQUIRE_SOURCE */

#endif /* TAO_SERVICE_TYPE_MAP_H */
