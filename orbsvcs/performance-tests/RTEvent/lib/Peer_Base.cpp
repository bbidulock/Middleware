/**
 * @file Peer_Base.cpp
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

#include "Peer_Base.h"
#include "RTServer_Setup.h"
#include "RIR_Narrow.h"
#include "Servant_var.h"
#include "RTEC_Initializer.h"
#include "EC_Destroyer.h"
#include "Auto_Disconnect.h"
#include "Loopback.h"

#include "orbsvcs/Event/EC_Event_Channel.h"
#include "orbsvcs/Event/EC_Gateway_IIOP.h"

ACE_RCSID (TAO_RTEC_Perf,
           Peer_Base,
           "$Id$")

Peer_Base::Peer_Base (CORBA::ORB_ptr orb,
                      RTServer_Setup &rtserver_setup
                      ACE_ENV_ARG_DECL)
  : orb_ (CORBA::ORB::_duplicate (orb))
  , poa_ (rtserver_setup.poa ())
{
  Servant_var<TAO_EC_Event_Channel> ec_impl (
      RTEC_Initializer::create (this->poa_.in (),
                                this->poa_.in (),
                                rtserver_setup.rtcorba_setup ()
                                ACE_ENV_ARG_PARAMETER)
      );

  ec_impl->activate ();

  PortableServer::ObjectId_var ec_id =
    this->poa_->activate_object (ec_impl.in ()
                                 ACE_ENV_ARG_PARAMETER);
  CORBA::Object_var ec_object =
    this->poa_->id_to_reference (ec_id.in ()
                                 ACE_ENV_ARG_PARAMETER);

  this->event_channel_ =
    RtecEventChannelAdmin::EventChannel::_narrow (ec_object.in ()
                                                  ACE_ENV_ARG_PARAMETER);
}

Peer_Base::~Peer_Base (void)
{
}

void
Peer_Base::shutdown (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  {
    EC_Destroyer ec_destroyer (this->event_channel_.in ());
    this->event_channel_ =
      RtecEventChannelAdmin::EventChannel::_nil ();
  }

  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
}

CORBA::Object_ptr
Peer_Base::channel (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::Object::_duplicate (this->event_channel_.in ());
}

void
Peer_Base::connect (Federated_Test::Peer_ptr remote_peer
                    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Connecting....\n"));
  CORBA::Object_var remote_ec_object =
    remote_peer->channel ();

  RtecEventChannelAdmin::EventChannel_var remote_ec =
    RtecEventChannelAdmin::EventChannel::_narrow (remote_ec_object.in ()
                                                  ACE_ENV_ARG_PARAMETER);

  Servant_var<TAO_EC_Gateway_IIOP> gateway (new TAO_EC_Gateway_IIOP);
  gateway->init (remote_ec.in (),
                 this->event_channel_.in ()
                 ACE_ENV_ARG_PARAMETER);

  RtecEventChannelAdmin::Observer_var observer =
    gateway->_this ();

  RtecEventChannelAdmin::Observer_Handle h =
    this->event_channel_->append_observer (observer.in ()
                                           ACE_ENV_ARG_PARAMETER);

  gateway->observer_handle (h);
}

Federated_Test::Loopback_ptr
Peer_Base::setup_loopback (CORBA::Long experiment_id,
                           CORBA::Long base_event_type
                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Servant_var<Loopback> loopback (
      new Loopback (experiment_id,
                    base_event_type,
                    this->poa_.in (),
                    this->poa_.in (),
                    this->event_channel_.in ()
                    ACE_ENV_ARG_PARAMETER));

  Auto_Disconnect<Loopback> disconnect (loopback);

  Federated_Test::Loopback_var lb =
    loopback->_this ();

  disconnect.release ();

  return lb._retn ();
}

PortableServer::POA_ptr
Peer_Base::_default_POA (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return PortableServer::POA::_duplicate (this->poa_.in ());
}
