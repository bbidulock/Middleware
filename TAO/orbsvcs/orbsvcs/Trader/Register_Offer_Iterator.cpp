/* -*- C++ -*- */

// ============================================================================
// $Id$
// 
// = LIBRARY
//    orbsvcs
// 
// = FILENAME
//    Register_Offer_Iterator.cpp
//
// = AUTHOR
//    Marina Spivak <marina@cs.wustl.edu>
//    Seth Widoff <sbw1@cs.wustl.edu>
//    Irfan Pyarali <irfan@cs.wustl.edu>
// ============================================================================

#if !defined (TAO_REGISTER_OFFER_ITERATOR_C)
#define  TAO_REGISTER_OFFER_ITERATOR_C

#include "Register_Offer_Iterator.h"
#include <iostream.h>

#ifndef min
#define        min(a, b)               ((a) > (b) ? (b) : (a))
#endif

template <class TRADER>
TAO_Register_Offer_Iterator<TRADER>::
TAO_Register_Offer_Iterator (TRADER &trader,
			     const TAO_Property_Filter& pfilter)
  : TAO_Offer_Iterator (pfilter),
    trader_ (trader)
{
}

template <class TRADER>
TAO_Register_Offer_Iterator<TRADER>::~TAO_Register_Offer_Iterator (void)
{
}

template <class TRADER> void
TAO_Register_Offer_Iterator<TRADER>::add_offer (CosTrading::OfferId id,
						CosTrading::Offer* offer)
{
  this->offer_ids_.push_back (id);
}

template <class TRADER> CORBA::ULong 
TAO_Register_Offer_Iterator<TRADER>::max_left (CORBA::Environment& _env) 
  TAO_THROW_SPEC ((CORBA::SystemException, 
		  CosTrading::UnknownMaxLeft))
{
  return this->offer_ids_.size ();
}

template <class TRADER> CORBA::Boolean 
TAO_Register_Offer_Iterator<TRADER>::next_n (CORBA::ULong n, 
                                             CosTrading::OfferSeq_out offers,
					      CORBA::Environment& _env) 
  TAO_THROW_SPEC (CORBA::SystemException)
{
  offers = new CosTrading::OfferSeq;

  CORBA::ULong ret_offers = 0;
  
  // Get service type map (monitor object).
  TRADER::SERVICE_TYPE_MAP &service_type_map = 
    this->trader_.service_type_map ();

  CORBA::ULong max_possible_offers_in_sequence =
    min(n, this->offer_ids_.size ());
  offers->length (max_possible_offers_in_sequence);  
  
  // While there are entries left and we haven't filled <offers>
  // with requested number.
  while (! this->offer_ids_.empty () 
	 && n > ret_offers)
    {
      // If offer is found, put it into the sequence.	  
      // remove this id irrespective of whether the offer is found
      // or not.      
      CosTrading::OfferId_var id = this->offer_ids_.front ();
      
      TAO_TRY
	{
	  CosTrading::Offer* offer =
	    service_type_map.lookup_offer (id, TAO_TRY_ENV);
	  TAO_CHECK_ENV;
	  
	  if (offer != 0)
	    {
	      CosTrading::Offer& destination = (*offers)[ret_offers++];
	      this->pfilter_.filter_offer (*offer, destination);
	    }
	}
      TAO_CATCHANY {}
      TAO_ENDTRY;
      
      this->offer_ids_.pop_front ();
    }
  
  // Reset the length to the correct value
  offers->length (ret_offers);

  return (CORBA::Boolean)(ret_offers != 0);
}

#endif /* TAO_REGISTER_OFFER_ITERATOR_C */
