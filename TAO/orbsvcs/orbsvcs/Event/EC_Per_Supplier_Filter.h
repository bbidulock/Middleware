/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = LIBRARY
//   ORBSVCS Real-time Event Channel
//
// = FILENAME
//   EC_Per_Supplier_Filter
//
// = AUTHOR
//   Carlos O'Ryan (coryan@cs.wustl.edu)
//
// = CREDITS
//   Based on previous work by Tim Harrison (harrison@cs.wustl.edu)
//   and other members of the DOC group.
//   More details can be found in:
//   http://www.cs.wustl.edu/~schmidt/oopsla.ps.gz
//   http://www.cs.wustl.edu/~schmidt/JSAC-98.ps.gz
//
//
// ============================================================================

#ifndef TAO_EC_PER_SUPPLIER_FILTER_H
#define TAO_EC_PER_SUPPLIER_FILTER_H

#include "EC_Supplier_Filter.h"
#include "EC_Supplier_Filter_Builder.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

template<class PROXY> class TAO_EC_Proxy_Collection;

class TAO_ORBSVCS_Export TAO_EC_Per_Supplier_Filter : public TAO_EC_Supplier_Filter
{
  // = TITLE
  //   Filter the events on each supplier.
  //
  // = DESCRIPTION
  //   This is a filtering strategy for the suppliers. In this
  //   particular case we keep a collection of the consumers that
  //   could potentially be interested in any event generated by a
  //   particular supplier.
  //   This minimizes the amount of consumers touched by the EC when
  //   dispatching an event.
  //
public:
  TAO_EC_Per_Supplier_Filter (TAO_EC_Event_Channel* ec);
  // Constructor

  virtual ~TAO_EC_Per_Supplier_Filter (void);
  // Destructor

  // = The TAO_EC_Supplier_Filter methods.
  virtual void bind (TAO_EC_ProxyPushConsumer* consumer);
  virtual void unbind (TAO_EC_ProxyPushConsumer* consumer);
  virtual void connected (TAO_EC_ProxyPushSupplier* supplier,
                          CORBA::Environment &env);
  virtual void reconnected (TAO_EC_ProxyPushSupplier* supplier,
                            CORBA::Environment &env);
  virtual void disconnected (TAO_EC_ProxyPushSupplier* supplier,
                             CORBA::Environment &env);
  virtual void shutdown (CORBA::Environment &env);
  virtual void push (const RtecEventComm::EventSet& event,
                     CORBA::Environment &);
  virtual CORBA::ULong _decr_refcnt (void);
  virtual CORBA::ULong _incr_refcnt (void);

private:
  TAO_EC_Event_Channel *event_channel_;
  // The event channel, used to locate the set of consumers.

  TAO_EC_ProxyPushConsumer* consumer_;
  // The proxy for the supplier we are bound to.

  TAO_EC_Proxy_Collection<TAO_EC_ProxyPushSupplier>* collection_;
  // Keep the collection of proxies for the consumers that may be
  // interested in our events.

  CORBA::ULong refcnt_;
  // Reference counting

  ACE_SYNCH_MUTEX lock_;
  // Locking
};

// ****************************************************************

class TAO_ORBSVCS_Export TAO_EC_Per_Supplier_Filter_Builder : public TAO_EC_Supplier_Filter_Builder
{
  // = TITLE
  //   Create Per_Supplier_Filter objects
  //
  // = DESCRIPTION
  //
public:
  TAO_EC_Per_Supplier_Filter_Builder (TAO_EC_Event_Channel* ec);
  // constructor....

  // = The TAO_EC_Supplier_Filter_Builder methods...
  virtual TAO_EC_Supplier_Filter*
      create (RtecEventChannelAdmin::SupplierQOS& qos);
  virtual void
      destroy (TAO_EC_Supplier_Filter *filter);

private:
  TAO_EC_Event_Channel* event_channel_;
  // The event channel
};

#if defined (__ACE_INLINE__)
#include "EC_Per_Supplier_Filter.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_EC_PER_SUPPLIER_FILTER_H */
