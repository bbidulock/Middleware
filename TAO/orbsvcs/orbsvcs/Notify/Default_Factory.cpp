// $Id$

#include "Default_Factory.h"

#if ! defined (__ACE_INLINE__)
#include "Default_Factory.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Notify, TAO_NS_Default_Factory, "$Id$")

#include "orbsvcs/ESF/ESF_Proxy_List.h"
#include "orbsvcs/ESF/ESF_Copy_On_Write.h"

#include "EventChannelFactory.h"
#include "EventChannel.h"
#include "Admin.h"
#include "Proxy.h"
#include "SupplierAdmin.h"
#include "ConsumerAdmin.h"
#include "Structured/StructuredProxyPushConsumer.h"
#include "Structured/StructuredProxyPushSupplier.h"
#include "Any/ProxyPushConsumer.h"
#include "Any/ProxyPushSupplier.h"
#include "Any/CosEC_ProxyPushConsumer.h"
#include "Any/CosEC_ProxyPushSupplier.h"
#include "Sequence/SequenceProxyPushConsumer.h"
#include "Sequence/SequenceProxyPushSupplier.h"
#include "Supplier.h"

template <class PROXY>
class COW_Collection_Default_Factory
{
public:
  typedef ACE_TYPENAME TAO_ESF_Proxy_List<PROXY>::Iterator PROXY_ITER;
  typedef TAO_ESF_Copy_On_Write<PROXY, TAO_ESF_Proxy_List<PROXY>,PROXY_ITER, ACE_SYNCH> COLLECTION;
  typedef TAO_ESF_Proxy_Collection<PROXY> BASE_COLLECTION;

  void create (BASE_COLLECTION* &collection ACE_ENV_ARG_DECL)
  {
    ACE_NEW_THROW_EX (collection,
                      COLLECTION (),
                      CORBA::INTERNAL ());
  }
};

TAO_NS_Default_Factory::TAO_NS_Default_Factory (void)
{
}

TAO_NS_Default_Factory::~TAO_NS_Default_Factory ()
{
}

void
TAO_NS_Default_Factory::create (TAO_NS_ProxySupplier_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_NS_ProxySupplier> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_NS_Default_Factory::create (TAO_NS_ProxyConsumer_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_NS_ProxyConsumer> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_NS_Default_Factory::create (TAO_NS_EventChannel_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_NS_EventChannel> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_NS_Default_Factory::create (TAO_NS_ConsumerAdmin_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_NS_ConsumerAdmin> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_NS_Default_Factory::create (TAO_NS_SupplierAdmin_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_NS_SupplierAdmin> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_NS_Default_Factory::create (TAO_NS_Proxy_Collection* &collection ACE_ENV_ARG_DECL)
{
  COW_Collection_Default_Factory<TAO_NS_Proxy> f;
  f.create (collection ACE_ENV_ARG_PARAMETER);
}

void
TAO_NS_Default_Factory::create (TAO_NS_EventChannelFactory*& factory ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (factory,
                    TAO_NS_EventChannelFactory (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_EventChannel*& channel ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (channel,
                    TAO_NS_EventChannel (),
                    CORBA::NO_MEMORY ());
}


void
TAO_NS_Default_Factory::create (TAO_NS_SupplierAdmin*& admin ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (admin,
                    TAO_NS_SupplierAdmin (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_ConsumerAdmin*& admin ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (admin,
                    TAO_NS_ConsumerAdmin (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_StructuredProxyPushConsumer*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_NS_StructuredProxyPushConsumer (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_StructuredProxyPushSupplier*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_NS_StructuredProxyPushSupplier (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_ProxyPushConsumer*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_NS_ProxyPushConsumer (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_ProxyPushSupplier*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_NS_ProxyPushSupplier (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_CosEC_ProxyPushConsumer*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_NS_CosEC_ProxyPushConsumer (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_CosEC_ProxyPushSupplier*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_NS_CosEC_ProxyPushSupplier (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_SequenceProxyPushConsumer*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_NS_SequenceProxyPushConsumer (),
                    CORBA::NO_MEMORY ());
}

void
TAO_NS_Default_Factory::create (TAO_NS_SequenceProxyPushSupplier*& proxy ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (proxy,
                    TAO_NS_SequenceProxyPushSupplier (),
                    CORBA::NO_MEMORY ());
}

ACE_FACTORY_DEFINE (TAO_Notify, TAO_NS_Default_Factory)

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO_NS_ProxySupplier_T <POA_Event_Forwarder::StructuredProxyPushSupplier>;
template class TAO_NS_Proxy_T <POA_Event_Forwarder::StructuredProxyPushSupplier>;
template class TAO_NS_ProxySupplier_T <POA_CosNotifyChannelAdmin::SequenceProxyPushSupplier>;
template class TAO_NS_Proxy_T <POA_CosNotifyChannelAdmin::SequenceProxyPushSupplier>;
template class TAO_NS_ProxySupplier_T <POA_Event_Forwarder::ProxyPushSupplier>;
template class TAO_NS_Proxy_T <POA_Event_Forwarder::ProxyPushSupplier>;
template class TAO_NS_ProxySupplier_T <POA_CosEventChannelAdmin::ProxyPushSupplier>;
template class TAO_NS_Proxy_T <POA_CosEventChannelAdmin::ProxyPushSupplier>;

template class TAO_NS_ProxyConsumer_T <POA_CosNotifyChannelAdmin::StructuredProxyPushConsumer>;
template class TAO_NS_Proxy_T <POA_CosNotifyChannelAdmin::StructuredProxyPushConsumer>;
template class TAO_NS_ProxyConsumer_T <POA_CosNotifyChannelAdmin::SequenceProxyPushConsumer>;
template class TAO_NS_Proxy_T <POA_CosNotifyChannelAdmin::SequenceProxyPushConsumer>;
template class TAO_NS_ProxyConsumer_T <POA_CosNotifyChannelAdmin::ProxyPushConsumer>;
template class TAO_NS_Proxy_T <POA_CosNotifyChannelAdmin::ProxyPushConsumer>;
template class TAO_NS_ProxyConsumer_T <POA_CosEventChannelAdmin::ProxyPushConsumer>;
template class TAO_NS_Proxy_T <POA_CosEventChannelAdmin::ProxyPushConsumer>;

template class TAO_ESF_Proxy_Collection<TAO_NS_ProxyConsumer>;
template class TAO_ESF_Proxy_Collection<TAO_NS_ProxySupplier>;
template class TAO_ESF_Proxy_Collection<TAO_NS_EventChannel>;
template class TAO_ESF_Proxy_Collection<TAO_NS_ConsumerAdmin>;
template class TAO_ESF_Proxy_Collection<TAO_NS_SupplierAdmin>;
template class TAO_ESF_Proxy_Collection<TAO_NS_Proxy>;
template class TAO_ESF_Proxy_Collection<TAO_NS_Consumer>;
template class TAO_ESF_Proxy_Collection<TAO_NS_Supplier>;
template class TAO_ESF_Proxy_Collection<TAO_NS_Peer>;

template class ACE_Unbounded_Set<int>;
//template class ACE_Unbounded_Set<TAO_NS_EventType>;
//template class ACE_Unbounded_Set<TAO_NS_ProxySupplier *>;

template class ACE_Unbounded_Set_Const_Iterator<int>;
template class ACE_Unbounded_Set_Iterator<TAO_NS_Proxy *>;

template class TAO_ESF_Copy_On_Write<TAO_NS_Proxy, TAO_ESF_Proxy_List<TAO_NS_Proxy>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write<TAO_NS_Peer, TAO_ESF_Proxy_List<TAO_NS_Peer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write<TAO_NS_Consumer, TAO_ESF_Proxy_List<TAO_NS_Consumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write<TAO_NS_Supplier, TAO_ESF_Proxy_List<TAO_NS_Supplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write<TAO_NS_EventChannel, TAO_ESF_Proxy_List<TAO_NS_EventChannel>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write<TAO_NS_ProxyConsumer, TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write<TAO_NS_ProxySupplier, TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write<TAO_NS_ConsumerAdmin, TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write<TAO_NS_SupplierAdmin, TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin *>, ACE_SYNCH>;

template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier*>,TAO_SYNCH_MUTEX>;
template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_EventChannel>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel*>,TAO_SYNCH_MUTEX>;
template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin*>,TAO_SYNCH_MUTEX>;
template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin*>,TAO_SYNCH_MUTEX>;
template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer*>,TAO_SYNCH_MUTEX>;
template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_Consumer>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer*>,TAO_SYNCH_MUTEX>;
template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_Supplier>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier*>,TAO_SYNCH_MUTEX>;
template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_Peer>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer*>,TAO_SYNCH_MUTEX>;
template class TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_Proxy>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy*>,TAO_SYNCH_MUTEX>;



template class TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>;
template class TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>;
template class TAO_ESF_Proxy_List<TAO_NS_Consumer>;
template class TAO_ESF_Proxy_List<TAO_NS_Supplier>;
template class TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>;
template class TAO_ESF_Proxy_List<TAO_NS_Proxy>;
template class TAO_ESF_Proxy_List<TAO_NS_EventChannel>;
template class TAO_ESF_Proxy_List<TAO_NS_Peer>;
template class TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>;

template class ACE_Unbounded_Set_Ex<TAO_NS_Peer *>;
template class ACE_Unbounded_Set_Ex<TAO_NS_Supplier *>;
template class ACE_Unbounded_Set_Ex<TAO_NS_Consumer *>;
template class ACE_Unbounded_Set_Ex<TAO_NS_ProxyConsumer *>;
template class ACE_Unbounded_Set_Ex<TAO_NS_ProxySupplier *>;
template class ACE_Unbounded_Set_Ex<TAO_NS_ConsumerAdmin *>;
template class ACE_Unbounded_Set_Ex<TAO_NS_SupplierAdmin *>;
template class ACE_Unbounded_Set_Ex<TAO_NS_EventChannel *>;
template class ACE_Unbounded_Set_Ex<TAO_NS_Proxy *>;
//template class ACE_Unbounded_Set<int>;

template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer *>;
template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier *>;
template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer *>;
template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer *>;
template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier *>;
template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin *>;
template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin *>;
template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel *>;
template class ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *>;
template class ACE_Unbounded_Set_Iterator<int>;

template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_Proxy>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_Peer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer *>, ACE_SYNCH>;

template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_Consumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_EventChannel>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier *>, ACE_SYNCH>;
template class TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_Supplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier *>, ACE_SYNCH>;

template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer *> >;
template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_Supplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier *> >;
template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin *> >;
template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin *> >;
template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_EventChannel>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel *> >;
template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_Consumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer *> >;
template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_Peer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer *> >;
template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier *> >;
template class TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_Proxy>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *> >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate TAO_NS_ProxySupplier_T <POA_Event_Forwarder::StructuredProxyPushSupplier>
#pragma instantiate TAO_NS_Proxy_T <POA_Event_Forwarder::StructuredProxyPushSupplier>
#pragma instantiate TAO_NS_ProxySupplier_T <POA_CosNotifyChannelAdmin::SequenceProxyPushSupplier>
#pragma instantiate TAO_NS_Proxy_T <POA_CosNotifyChannelAdmin::SequenceProxyPushSupplier>
#pragma instantiate TAO_NS_ProxySupplier_T <POA_Event_Forwarder::ProxyPushSupplier>
#pragma instantiate TAO_NS_Proxy_T <POA_Event_Forwarder::ProxyPushSupplier>
#pragma instantiate TAO_NS_ProxySupplier_T <POA_CosEventChannelAdmin::ProxyPushSupplier>
#pragma instantiate TAO_NS_Proxy_T <POA_CosEventChannelAdmin::ProxyPushSupplier>

#pragma instantiate TAO_NS_ProxyConsumer_T <POA_CosNotifyChannelAdmin::StructuredProxyPushConsumer>
#pragma instantiate TAO_NS_Proxy_T <POA_CosNotifyChannelAdmin::StructuredProxyPushConsumer>
#pragma instantiate TAO_NS_ProxyConsumer_T <POA_CosNotifyChannelAdmin::SequenceProxyPushConsumer>
#pragma instantiate TAO_NS_Proxy_T <POA_CosNotifyChannelAdmin::SequenceProxyPushConsumer>
#pragma instantiate TAO_NS_ProxyConsumer_T <POA_CosNotifyChannelAdmin::ProxyPushConsumer>
#pragma instantiate TAO_NS_Proxy_T <POA_CosNotifyChannelAdmin::ProxyPushConsumer>
#pragma instantiate TAO_NS_ProxyConsumer_T <POA_CosEventChannelAdmin::ProxyPushConsumer>
#pragma instantiate TAO_NS_Proxy_T <POA_CosEventChannelAdmin::ProxyPushConsumer>

#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_ProxyConsumer>
#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_ProxySupplier>
#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_EventChannel>
#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_ConsumerAdmin>
#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_SupplierAdmin>
#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_Proxy>
#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_Consumer>
#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_Supplier>
#pragma instantiate TAO_ESF_Proxy_Collection<TAO_NS_Peer>

#pragma instantiate ACE_Unbounded_Set<int>
#pragma instantiate ACE_Unbounded_Set<TAO_NS_EventType>
//#pragma instantiate ACE_Unbounded_Set<TAO_NS_ProxySupplier *>

#pragma instantiate ACE_Unbounded_Set_Const_Iterator<int>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *>

#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_Proxy, TAO_ESF_Proxy_List<TAO_NS_Proxy>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_Peer, TAO_ESF_Proxy_List<TAO_NS_Peer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_Consumer, TAO_ESF_Proxy_List<TAO_NS_Consumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_Supplier, TAO_ESF_Proxy_List<TAO_NS_Supplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_EventChannel, TAO_ESF_Proxy_List<TAO_NS_EventChannel>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_ProxyConsumer, TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_ProxySupplier, TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_ConsumerAdmin, TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write<TAO_NS_SupplierAdmin, TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin *>, ACE_SYNCH>

#pragma instantiate TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier*>,ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_EventChannel>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel*>,ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin*>,ACE_SYNCH>#pragma instantiate TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin*>,ACE_SYNCH>
#pragma instantitae TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer*>,ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_Consumer>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer*>,ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_Supplier>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier*>,ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_Peer>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer*>,ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Read_Guard<TAO_ESF_Proxy_List<TAO_NS_Proxy>,ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy*>,ACE_SYNCH>



#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>
#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>
#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_Consumer>
#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_Supplier>
#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>
#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_Proxy>
#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_EventChannel>
#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_Peer>
#pragma instantiate TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>

#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_Peer *>
#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_Supplier *>
#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_Consumer *>
#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_ProxyConsumer *>
#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_ProxySupplier *>
#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_ConsumerAdmin *>
#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_SupplierAdmin *>
#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_EventChannel *>
#pragma instantiate ACE_Unbounded_Set_Ex<TAO_NS_Proxy *>

#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer *>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier *>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer *>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer *>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier *>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin *>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin *>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel *>
#pragma instantiate ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *>
#pragma instantiate ACE_Unbounded_Set_Iterator<int>

#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_Proxy>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_Peer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_Consumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_EventChannel>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier *>, ACE_SYNCH>
#pragma instantiate TAO_ESF_Copy_On_Write_Write_Guard<TAO_ESF_Proxy_List<TAO_NS_Supplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier *>, ACE_SYNCH>

#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_ProxyConsumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxyConsumer *> >
#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_Supplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Supplier *> >
#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_ConsumerAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ConsumerAdmin *> >
#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_SupplierAdmin>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_SupplierAdmin *> >
#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_EventChannel>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_EventChannel *> >
#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_Consumer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Consumer *> >
#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_Peer>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Peer *> >
#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_ProxySupplier>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_ProxySupplier *> >
#pragma instantiate TAO_ESF_Copy_On_Write_Collection<TAO_ESF_Proxy_List<TAO_NS_Proxy>, ACE_Unbounded_Set_Ex_Iterator<TAO_NS_Proxy *> >

#endif /*ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
