// $Id$

// ===========================================================
//
//
// = LIBRARY
//    CIAO/examples/handcrafted/hello
//
// = FILENAME
//    hello_servants.h
//
// = DESCRIPTION
//    Generic Servant implementations for hello world example.
//    This file is currently handcrafted but it should really
//    be generated by the CCIDL compiler.
//
//    This example demonstrates how a servant implementation for a
//    session component should look like.
//
// @author Nanbor Wang <nanbor@cs.wustl.edu>
//
// ===========================================================

#include "helloS.h"
#include "helloEC.h"
#include "ciao/Container_Base.h"

class HELLO_SERVANT_Export CIAO_HelloWorld_Context :
  public virtual CCM_HelloWorld_Context
// @@ The following line is causing compiler to barf.
//  , public virtual ::Components::SessionContext
{
public:
  // Ctor.
  CIAO_HelloWorld_Context ();

  // Dtor.
  virtual ~CIAO_HelloWorld_Context ();

  // Operations for HellowWorld attributes, event source, and
  // receptable defined in CCM_HelloWorld_Context.

  // Operations for ::Components::CCMContext
  virtual ::Components::Principal_ptr get_caller_principal (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::Components::CCMHome_ptr get_CCM_home (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual CORBA::Boolean get_rollback_only (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::IllegalState));
  virtual ::Components::Transaction::UserTransaction_ptr get_user_transaction (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::IllegalState));
  virtual CORBA::Boolean is_caller_in_role (const char * role
                                            ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void set_rollback_only (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::IllegalState));


  // Operations for ::Components::SessionContext interface
  virtual CORBA::Object_ptr get_CCM_object (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::IllegalState));
};

class HELLO_SERVANT_Export CIAO_HelloWorld_Servant
  : public virtual POA_HelloWorld,
  // @@ Perhaps we could implement a common component servant class
  //    which provide common functionality for operations defined in
  //    Navigation/Events/Receptacles interfaces.
    public virtual PortableServer::RefCountServantBase
{
public:
  // Ctor.
  CIAO_HelloWorld_Servant (CCM_HelloWorld_ptr executor_);

  // Dtor.
  ~CIAO_HelloWorld_Servant (void);

  // Operations for supported interfaces.
  // Explicit opereations and attribute operations.
  virtual char * sayhello (const char * username
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  // Operations for provides interfaces.

  // Operations for receptacles interfaces.

  // Operations for emits interfaces.

  // Operations for consumers interfaces.

  // Operations for publishes interfaces.

  // Operations for Navigation interface
  virtual CORBA::Object_ptr provide_facet (const char * name
                                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException ,
                     Components::InvalidName)) ;
  virtual ::Components::FacetDescriptions * get_all_facets (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::Components::FacetDescriptions * get_named_facets (const Components::NameList & names
                                                              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException ,
                     Components::InvalidName));
  virtual CORBA::Boolean same_component (CORBA::Object_ptr object_ref
                                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  // Operations for Receptacles interface
  virtual ::Components::Cookie * connect (const char * name,
                                          CORBA::Object_ptr connection
                                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName,
                     Components::InvalidConnection,
                     Components::AlreadyConnected,
                     Components::ExceededConnectionLimit));
  virtual void disconnect (const char * name,
                           Components::Cookie * ck
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName,
                     Components::InvalidConnection,
                     Components::CookieRequired,
                     Components::NoConnection));
  virtual ::Components::ConnectionDescriptions * get_connections (const char * name
                                                                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName));

  virtual ::Components::ReceptacleDescriptions * get_all_receptacles (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::Components::ReceptacleDescriptions * get_named_receptacles (const Components::NameList & names
                                                                        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName));

  // Operations for Events interface
  virtual ::Components::EventConsumerBase_ptr get_consumer (const char * sink_name
                                                            ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName));
  virtual ::Components::Cookie * subscribe (const char * publisher_name,
                                            Components::EventConsumerBase_ptr subscriber
                                            ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName,
                     Components::AlreadyConnected,
                     Components::InvalidConnection));
  virtual void unsubscribe (const char * publisher_name,
                            Components::Cookie * ck
                            ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName,
                     Components::InvalidConnection));
  virtual void connect_consumer (const char * emitter_name,
                                 Components::EventConsumerBase_ptr consumer
                                 ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName,
                     Components::AlreadyConnected,
                     Components::InvalidConnection));
  virtual ::Components::EventConsumerBase_ptr disconnect_consumer (const char * source_name
                                                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName,
                     Components::NoConnection));
  virtual ::Components::ConsumerDescriptions * get_all_consumers (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::Components::ConsumerDescriptions * get_named_consumers (const Components::NameList & names
                                                                    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName));
  virtual ::Components::EmitterDescriptions * get_all_emitters (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::Components::EmitterDescriptions * get_named_emitters (const Components::NameList & names
                                                                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName));
  virtual ::Components::PublisherDescriptions * get_all_publishers (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::Components::PublisherDescriptions * get_named_publishers (const Components::NameList & names
                                                                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidName));

  // Operations for CCMObject interface
  virtual ::CORBA::IRObject_ptr get_component_def (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::Components::CCMHome_ptr get_ccm_home (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::Components::PrimaryKeyBase * get_primary_key (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::NoKeyAvailable));
  virtual void configuration_complete (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::InvalidConfiguration));
  virtual void remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::RemoveFailure));
  virtual ::Components::ComponentPortDescription * get_all_ports (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

protected:
  // My Executor.
  CCM_HelloWorld_var executor_;

  // My Run-time Context.
  CCM_HelloWorld_Context_var context_;
};


class HELLO_SERVANT_Export CIAO_HelloHome_Servant :
  public virtual POA_HelloHome,
  public virtual PortableServer::RefCountServantBase
{
public:
  // Ctor.
  CIAO_HelloHome_Servant (CCM_HelloHome_ptr exe,
                          CIAO::Session_Container *c);

  // Dtor.
  ~CIAO_HelloHome_Servant (void);

  // User defined and inherited operations
  // (Factories, Finders, and explicit operations.)

  // Operations for KeylessHome interface
  virtual ::Components::CCMObject_ptr create_component (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::CreateFailure));

  // Operations for Implicit Home interface
  virtual ::HelloWorld_ptr create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::CreateFailure));

  // Operations for CCMHome interface
  virtual ::CORBA::IRObject_ptr get_component_def (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual ::CORBA::IRObject_ptr get_home_def (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void remove_component (Components::CCMObject_ptr comp
                                 ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::RemoveFailure));

protected:
  // My Executor.
  CCM_HelloHome_var executor_;

  // My Container
  CIAO::Session_Container *container_;
};
