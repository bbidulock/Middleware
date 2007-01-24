/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = FILENAME
//   Supplier.h
//
// = AUTHOR
//   Pradeep Gore <pradeep@cs.wustl.edu>
//
// = DESCRIPTION
//   Defines a simple Push Supplier.
//
// ============================================================================

#ifndef COSECSUPPLIER_H_
#define COSECSUPPLIER_H_

#include "orbsvcs/CosEventCommC.h"
#include "orbsvcs/CosEventChannelAdminC.h"
#include "orbsvcs/CosEventCommS.h"
#include "orbsvcs/CosEventChannelAdminS.h"

class Supplier : public POA_CosEventComm::PushSupplier
{
  // = TITLE
  //   Supplier
  //
  // = DESCRIPTION
  //   The Supplier is a simple Push Supplier that connects to
  //   the CosEC and sends events to it.
public:
  void open (CosEventChannelAdmin::EventChannel_ptr event_channel
             ACE_ENV_ARG_DECL);
  // This method connects the supplier to the EC.

  void close (void);
  // Disconnect from the EC.

  void connect (void);

  void disconnect (void);
  // Disconnect from the EC, but do not forget about it or close it.

  void send_event (const CORBA::Any &data
                   ACE_ENV_ARG_DECL);
  // Send one event.

  virtual void disconnect_push_supplier (void)
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  // The POA_CosEventComm::PushSupplier method.

private:
  CosEventChannelAdmin::ProxyPushConsumer_var consumer_proxy_;
  // We talk to the EC using this proxy.

  CosEventChannelAdmin::SupplierAdmin_var supplier_admin_;
  // We talk to the EC using this proxy.
};

#endif /* COSECSUPPLIER_H_ */
