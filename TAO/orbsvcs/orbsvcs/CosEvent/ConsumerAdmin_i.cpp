// $Id$

#include "ConsumerAdmin_i.h"

TAO_CosEC_ConsumerAdmin_i::TAO_CosEC_ConsumerAdmin_i (void)
  : qos_ (),
    rtec_consumeradmin_ (RtecEventChannelAdmin::ConsumerAdmin::_nil ())
{
  // No-Op.
}

TAO_CosEC_ConsumerAdmin_i::~TAO_CosEC_ConsumerAdmin_i (void)
{
  // No-Op.
}

int
TAO_CosEC_ConsumerAdmin_i::init (const RtecEventChannelAdmin::ConsumerQOS &consumerqos,
                                 RtecEventChannelAdmin::ConsumerAdmin_ptr rtec_consumeradmin)
{
  this->qos_ = consumerqos;
  this->rtec_consumeradmin_ =
    RtecEventChannelAdmin::ConsumerAdmin::_duplicate (rtec_consumeradmin);
  return 0;
}

CosEventChannelAdmin::ProxyPushSupplier_ptr
TAO_CosEC_ConsumerAdmin_i::obtain_push_supplier (CORBA::Environment &TAO_TRY_ENV)
{
  RtecEventChannelAdmin::ProxyPushSupplier_var rtecproxypushsupplier =
    this->rtec_consumeradmin_->obtain_push_supplier (TAO_TRY_ENV);
  TAO_CHECK_ENV_RETURN (TAO_TRY_ENV, 0);

  TAO_CosEC_ProxyPushSupplier_i *pps;

  ACE_NEW_RETURN (pps,
                  TAO_CosEC_ProxyPushSupplier_i (this->qos_,
                                       rtecproxypushsupplier.in ()),
                  CosEventChannelAdmin::ProxyPushSupplier::_nil ());

  return pps->_this (TAO_TRY_ENV);
}

CosEventChannelAdmin::ProxyPullSupplier_ptr
TAO_CosEC_ConsumerAdmin_i::obtain_pull_supplier (CORBA::Environment &TAO_TRY_ENV)
{
  // TODO: implement this.
  return CosEventChannelAdmin::ProxyPullSupplier::_nil ();
}
