// $Id$

#include "hello_servants.h"

// @@: Denote stuff that need to be fixed later.
// @@@: Denote stuff that need to be fixed now.

CIAO_HelloWorld_Context::CIAO_HelloWorld_Context ()
{

}

CIAO_HelloWorld_Context::~CIAO_HelloWorld_Context ()
{

}

// Operations for HellowWorld attributes, event source, and
// receptable defined in CCM_HelloWorld_Context.

// Operations for ::Components::CCMContext
::Components::Principal_ptr
CIAO_HelloWorld_Context::get_caller_principal (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ We don't support Security in CIAO yet.
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

::Components::CCMHome_ptr
CIAO_HelloWorld_Context::get_CCM_home (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@@ Where to get a home reference?
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

CORBA::Boolean
CIAO_HelloWorld_Context::get_rollback_only (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::IllegalState))
{
  // @@ We don't support Transaction in CIAO yet.
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

::Components::Transaction::UserTransaction_ptr
CIAO_HelloWorld_Context::get_user_transaction (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::IllegalState))
{
  // @@ We don't support Transaction in CIAO yet.
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

CORBA::Boolean
CIAO_HelloWorld_Context::is_caller_in_role (const char * role
                                            ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_UNUSED_ARG (role);

  // @@ We don't support Transaction in CIAO yet.
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

void
CIAO_HelloWorld_Context::set_rollback_only (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::IllegalState))
{
  // @@ We don't support Transaction in CIAO yet.
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}


// Operations for ::Components::SessionContext interface
CORBA::Object_ptr
CIAO_HelloWorld_Context::get_CCM_object (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::IllegalState))
{
  // @@@ Where do we get the CCM Object reference?  From the container?
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

////////////////////////////////////////////////////////////////
/////////////////// CIAO_HelloWorld_Servant ////////////////////

CIAO_HelloWorld_Servant::CIAO_HelloWorld_Servant (CCM_HelloWorld_ptr exe)
  : executor_ (CCM_HelloWorld::_duplicate (exe))
{
  this->context_ = new CIAO_HelloWorld_Context ();
}

CIAO_HelloWorld_Servant::~CIAO_HelloWorld_Servant (void)
{
}

// Operations for supported interfaces.
// Explicit opereations and attribute operations.
char *
CIAO_HelloWorld_Servant::sayhello (const char * username
                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (this->executor_.in () == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), 0);

  return this->executor_->sayhello (username ACE_ENV_ARG_DECL);
}

// Operations for provides interfaces.

// Operations for receptacles interfaces.

// Operations for emits interfaces.

// Operations for consumers interfaces.

// Operations for publishes interfaces.

// Operations for Navigation interface
CORBA::Object_ptr
CIAO_HelloWorld_Servant::provide_facet (const char * name
                                        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException ,
                   Components::InvalidName))
{
  ACE_UNUSED_ARG (name);

  // @@ We should probably provide a more generic contruct
  // (Hash_Map?) to manage the navigation/receptacles/events
  // interface.

  // This component doesn't provide any facets so whatever name you
  // pass in is not a valid facet name.
  ACE_THROW_RETURN (Components::InvalidName (), 0);
}

::Components::FacetDescriptions *
CIAO_HelloWorld_Servant::get_all_facets (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // No facet for this component.
  return new ::Components::FacetDescriptions;
}

::Components::FacetDescriptions *
CIAO_HelloWorld_Servant::get_named_facets (const Components::NameList & names
                                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException ,
                   Components::InvalidName))
{
  // No facet for this component.
  if (names.length () != 0)
    ACE_THROW_RETURN (Components::InvalidName (), 0);

  // Or return an empty description sequence if you are not asking
  // for anyhing in particular.
  return new ::Components::FacetDescriptions;
}

CORBA::Boolean
CIAO_HelloWorld_Servant::same_component (CORBA::Object_ptr object_ref
                                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_UNUSED_ARG (object_ref);

  // @@@ Need to contact the POA, get the object reference, and invoke
  // _is_equivalent on the object reference.

  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

// Operations for Receptacles interface
::Components::Cookie *
CIAO_HelloWorld_Servant::connect (const char * name,
                                  CORBA::Object_ptr connection
                                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName,
                   Components::InvalidConnection,
                   Components::AlreadyConnected,
                   Components::ExceededConnectionLimit))
{
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (connection);
  // @@ We need to come up with a generic interface to manage
  // these connections.

  ACE_THROW_RETURN (::Components::InvalidName (), 0);
}

void
CIAO_HelloWorld_Servant::disconnect (const char * name,
                                     Components::Cookie * ck
                                     ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName,
                   Components::InvalidConnection,
                   Components::CookieRequired,
                   Components::NoConnection))
{
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (ck);

  ACE_THROW (::Components::InvalidName ());
}

::Components::ConnectionDescriptions *
CIAO_HelloWorld_Servant::get_connections (const char * name
                                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName))
{
  ACE_UNUSED_ARG (name);

  ACE_THROW_RETURN (::Components::InvalidName (), 0);
}

::Components::ReceptacleDescriptions *
CIAO_HelloWorld_Servant::get_all_receptacles (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // No receptacles.  Return an empty sequence.
  return new ::Components::ReceptacleDescriptions;
}

::Components::ReceptacleDescriptions *
CIAO_HelloWorld_Servant::get_named_receptacles (const Components::NameList & names
                                                ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName))
{
  // No facet for this component.
  if (names.length () != 0)
    ACE_THROW_RETURN (Components::InvalidName (), 0);

  // Or return an empty description sequence if you are not asking
  // for anyhing in particular.
  return new ::Components::ReceptacleDescriptions;
}

// Operations for Events interface
::Components::EventConsumerBase_ptr
CIAO_HelloWorld_Servant::get_consumer (const char * sink_name
                                       ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName))
{
  ACE_UNUSED_ARG (sink_name);

  ACE_THROW_RETURN (::Components::InvalidName (), 0);
}

::Components::Cookie *
CIAO_HelloWorld_Servant::subscribe (const char * publisher_name,
                                    Components::EventConsumerBase_ptr subscriber
                                    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName,
                   Components::AlreadyConnected,
                   Components::InvalidConnection))
{
  ACE_UNUSED_ARG (publisher_name);
  ACE_UNUSED_ARG (subscriber);

  ACE_THROW_RETURN (::Components::InvalidName (), 0);
}

void
CIAO_HelloWorld_Servant::unsubscribe (const char * publisher_name,
                                      Components::Cookie * ck
                                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName,
                   Components::InvalidConnection))
{
  ACE_UNUSED_ARG (publisher_name);
  ACE_UNUSED_ARG (ck);

  ACE_THROW (::Components::InvalidName ());
}

void
CIAO_HelloWorld_Servant::connect_consumer (const char * emitter_name,
                                           Components::EventConsumerBase_ptr consumer
                                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName,
                   Components::AlreadyConnected,
                   Components::InvalidConnection))
{
  ACE_UNUSED_ARG (emitter_name);
  ACE_UNUSED_ARG (consumer);

  ACE_THROW (::Components::InvalidName ());
}

::Components::EventConsumerBase_ptr
CIAO_HelloWorld_Servant::disconnect_consumer (const char * source_name
                                              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName,
                   Components::NoConnection))
{
  ACE_UNUSED_ARG (source_name);

  ACE_THROW_RETURN (::Components::InvalidName (), 0);
}

::Components::ConsumerDescriptions *
CIAO_HelloWorld_Servant::get_all_consumers (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return new ::Components::ConsumerDescriptions;
}

::Components::ConsumerDescriptions *
CIAO_HelloWorld_Servant::get_named_consumers (const Components::NameList & names
                                              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName))
{
  // No facet for this component.
  if (names.length () != 0)
    ACE_THROW_RETURN (Components::InvalidName (), 0);

  // Or return an empty description sequence if you are not asking
  // for anyhing in particular.
  return new ::Components::ConsumerDescriptions;
}

::Components::EmitterDescriptions *
CIAO_HelloWorld_Servant::get_all_emitters (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return new ::Components::EmitterDescriptions;
}

::Components::EmitterDescriptions *
CIAO_HelloWorld_Servant::get_named_emitters (const Components::NameList & names
                                             ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName))
{
  // No facet for this component.
  if (names.length () != 0)
    ACE_THROW_RETURN (Components::InvalidName (), 0);

  // Or return an empty description sequence if you are not asking
  // for anyhing in particular.
  return new ::Components::EmitterDescriptions;
}

::Components::PublisherDescriptions *
CIAO_HelloWorld_Servant::get_all_publishers (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return new ::Components::PublisherDescriptions;
}

::Components::PublisherDescriptions *
CIAO_HelloWorld_Servant::get_named_publishers (const Components::NameList & names
                                               ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidName))
{
  // No facet for this component.
  if (names.length () != 0)
    ACE_THROW_RETURN (Components::InvalidName (), 0);

  // Or return an empty description sequence if you are not asking
  // for anyhing in particular.
  return new ::Components::PublisherDescriptions;
}

// Operations for CCMObject interface
::CORBA::IRObject_ptr
CIAO_HelloWorld_Servant::get_component_def (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

::Components::CCMHome_ptr
CIAO_HelloWorld_Servant::get_ccm_home (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@@ How?  Should we cache the home reference here?
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

::Components::PrimaryKeyBase *
CIAO_HelloWorld_Servant::get_primary_key (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::NoKeyAvailable))
{
  // This is a keyless component.
  ACE_THROW_RETURN (::Components::NoKeyAvailable (), 0);
}

void
CIAO_HelloWorld_Servant::configuration_complete (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::InvalidConfiguration))
{
  // @@
  return;
}

void
CIAO_HelloWorld_Servant::remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::RemoveFailure))
{
  // @@ Tear down connections and stuff?

  return;
}

::Components::ComponentPortDescription *
CIAO_HelloWorld_Servant::get_all_ports (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // No port, no nothing.
  return new OBV_Components::ComponentPortDescription;
}


////////////////////////////////////////////////////////////////
//////////////////// CIAO_HelloHome_Servant ////////////////////

CIAO_HelloHome_Servant::CIAO_HelloHome_Servant (CCM_HelloHome_ptr exe)
  : executor_ (CCM_HelloHome::_duplicate (exe))
{
}

CIAO_HelloHome_Servant::~CIAO_HelloHome_Servant (void)
{
}

// User defined and inherited operations
// (Factories, Finders, and explicit operations.)

// Operations for KeylessHome interface
::Components::CCMObject_ptr
CIAO_HelloHome_Servant::create_component (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CreateFailure))
{
  return this->create (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// Operations for Implicit Home interface
::HelloWorld_ptr
CIAO_HelloHome_Servant::create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CreateFailure))
{
  if (this->executor_.in () == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), 0);

  // @@@ Must implement this one.
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

// Operations for CCMHome interface
::CORBA::IRObject_ptr
CIAO_HelloHome_Servant::get_component_def (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Not implemented yet.
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

::CORBA::IRObject_ptr
CIAO_HelloHome_Servant::get_home_def (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Not implemented yet.
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

void
CIAO_HelloHome_Servant::remove_component (Components::CCMObject_ptr comp
                                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::RemoveFailure))
{
  // Removing the object reference?  get the servant from the POA with
  // the objref, and call remove() on the component, deactivate the
  // component, and then remove-ref the servant?
}
