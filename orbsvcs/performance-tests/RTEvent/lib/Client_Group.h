/**
 * @file Client_Group.h
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

#ifndef TAO_PERF_RTEC_CLIENT_GROUP_H
#define TAO_PERF_RTEC_CLIENT_GROUP_H

#include "Servant_var.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Consumer.h"
#include "Supplier.h"
#include "Loopback_Supplier.h"
#include "Loopback_Consumer.h"

/**
 * @class Client_Group
 *
 * @brief Simplify the initialization of a Supplier/Consumer pair
 *        connected through a Loopback.
 */
class Client_Group
{
public:
  /// Constructor
  /**
   * We need a default constructor because this class is often used in
   * arrays.
   */
  Client_Group (void);

  /**
   * @param experiment_id For tests that run multiple experiments
   *        this number is changed on each iteration, guaranteeing
   *        better isolation.
   * @param base_event_type The event type generated by the supplier.
   *        The Loopback_Consumer consumes the same event, the
   *        Loopback_Supplier generates (base_event_type + 1), and the
   *        consumer subscribes for that type too.
   * @param iterations The number of iterations expected on the test.
   * @param workload_in_usecs The consumer workload, in microseconds.
   * @param gsf The high resolution timer global scale factor.
   *
   */
  void init (CORBA::Long experiment_id,
             CORBA::Long base_event_type,
             CORBA::ULong iterations,
             CORBA::Long workload_in_usecs,
             ACE_UINT32 gsf);

  /// Connect to the event channel
  void connect (RtecEventChannelAdmin::EventChannel_ptr ec
                ACE_ENV_ARG_DECL);

  /// Disconnect from the event channel
  void disconnect (ACE_ENV_SINGLE_ARG_DECL);

  //@{
  /** @name Accessors
   */
  Supplier *supplier (void) const;

  Consumer *consumer (void) const;

  Loopback_Supplier *loopback_supplier (void) const;

  Loopback_Consumer *loopback_consumer (void) const;
  //@}

private:
  Servant_var<Supplier> supplier_;
  Servant_var<Consumer> consumer_;
  Servant_var<Loopback_Supplier> loopback_supplier_;
  Servant_var<Loopback_Consumer> loopback_consumer_;
};

#if defined(__ACE_INLINE__)
#include "Client_Group.inl"
#endif /* __ACE_INLINE__ */

#endif /* TAO_PERF_RTEC_CLIENT_GROUP_H */
