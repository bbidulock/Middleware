// $Id$

#include "orbsvcs/Notify/Any/CosEC_ProxyPushConsumer.h"

ACE_RCSID (Notify, TAO_Notify_CosEC_ProxyPushConsumer, "$Id$")

#include "tao/debug.h"
#include "orbsvcs/Notify/AdminProperties.h"
#include "orbsvcs/Notify/Method_Request_Lookup.h"
#include "orbsvcs/Notify/Worker_Task.h"
#include "orbsvcs/Notify/Any/AnyEvent.h"
#include "orbsvcs/Notify/Any/PushSupplier.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Notify_CosEC_ProxyPushConsumer::TAO_Notify_CosEC_ProxyPushConsumer (void)
{
}

TAO_Notify_CosEC_ProxyPushConsumer::~TAO_Notify_CosEC_ProxyPushConsumer ()
{
}

void
TAO_Notify_CosEC_ProxyPushConsumer::release (void)
{
  delete this;
  //@@ inform factory
}

void
TAO_Notify_CosEC_ProxyPushConsumer::push (const CORBA::Any& any)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosEventComm::Disconnected
                   ))
{
  // Check if we should proceed at all.
  if (this->admin_properties().reject_new_events () == 1
      && this->admin_properties().queue_full ())
    throw CORBA::IMP_LIMIT ();

  if (this->is_connected () == 0)
    {
      throw CosEventComm::Disconnected ();
    }

  TAO_Notify_AnyEvent_No_Copy event (any);

  TAO_Notify_Method_Request_Lookup_No_Copy request (&event, this);

  this->execute_task (request);
}

void
TAO_Notify_CosEC_ProxyPushConsumer::connect_push_supplier (CosEventComm::PushSupplier_ptr push_supplier)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   , CosEventChannelAdmin::AlreadyConnected
                   ))
{
  // Convert Supplier to Base Type
  TAO_Notify_PushSupplier *supplier;
  ACE_NEW_THROW_EX (supplier,
                    TAO_Notify_PushSupplier (this),
                    CORBA::NO_MEMORY ());

  supplier->init (push_supplier);

  this->connect (supplier);
}

void
TAO_Notify_CosEC_ProxyPushConsumer::disconnect_push_consumer (void)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  TAO_Notify_CosEC_ProxyPushConsumer::Ptr guard( this );
  this->destroy ();
}

const char *
TAO_Notify_CosEC_ProxyPushConsumer::get_proxy_type_name (void) const
{
  return "ec_proxy_push_consumer";
}

TAO_END_VERSIONED_NAMESPACE_DECL
