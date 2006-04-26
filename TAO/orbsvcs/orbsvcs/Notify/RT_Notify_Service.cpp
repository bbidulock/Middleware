// $Id$

#include "orbsvcs/Notify/RT_Notify_Service.h"

ACE_RCSID(RT_Notify, TAO_Notify_RT_Notify_Service, "$Id$")

#include "ace/Dynamic_Service.h"
#include "orbsvcs/Notify/Properties.h"
#include "orbsvcs/Notify/RT_Properties.h"
#include "orbsvcs/Notify/RT_Factory.h"
#include "orbsvcs/Notify/RT_Builder.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_RT_Notify_Service::TAO_RT_Notify_Service (void)
{
}

TAO_RT_Notify_Service::~TAO_RT_Notify_Service ()
{
}

void
TAO_RT_Notify_Service::init_service (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL)
{
  ACE_DEBUG ((LM_DEBUG, "Loading the Real-Time Notification Service...\n"));

  this->init_i (orb ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_RT_Notify_Service::init_i (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL)
{
  //Init the base class.
  TAO_CosNotify_Service::init_i (orb ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  TAO_Notify_RT_Properties* properties = TAO_Notify_RT_PROPERTIES::instance();

  // Resolve RTORB
  CORBA::Object_var object =
    orb->resolve_initial_references ("RTORB"
                                      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  RTCORBA::RTORB_var rt_orb =
    RTCORBA::RTORB::_narrow (object.in ()
                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Resolve RTCurrent
  object =
    orb->resolve_initial_references ("RTCurrent"
                                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  RTCORBA::Current_var current =
    RTCORBA::Current::_narrow (object.in ()
                               ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

 /// Set the properties
  properties->rt_orb (rt_orb.in ());
  properties->current (current.in ());
}

TAO_Notify_Factory*
TAO_RT_Notify_Service::create_factory (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Notify_Factory* factory =
    ACE_Dynamic_Service<TAO_Notify_Factory>::instance ("TAO_Notify_Factory");

  if (factory == 0)
    {
      ACE_NEW_THROW_EX (factory,
                        TAO_Notify_RT_Factory (),
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN(0);
    }
  return factory;
}

TAO_Notify_Builder*
TAO_RT_Notify_Service::create_builder (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Notify_Builder* builder = 0;
  ACE_NEW_THROW_EX (builder,
                    TAO_Notify_RT_Builder (),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN(0);

  return builder;
}

TAO_END_VERSIONED_NAMESPACE_DECL

ACE_FACTORY_DEFINE (TAO_RT_Notify,TAO_RT_Notify_Service)
