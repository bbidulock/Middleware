// $Id$

#ifndef TAO_ADVANCED_RESOURCE_H
#define TAO_ADVANCED_RESOURCE_H
#include "ace/pre.h"

#include "strategies_export.h"
#include "tao/default_resource.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"

class TAO_Strategies_Export TAO_Advanced_Resource_Factory : public TAO_Default_Resource_Factory
{
  // = TITLE
  //   TAO's default resource factory
  //
  // = DESCRIPTION
  //   Using a <{resource source specifier}> as a discriminator, the
  //   factory can return resource instances which are, e.g., global,
  //   stored in thread-specific storage, stored in shared memory,
  //   etc.
  //
public:
  // = Initialization and termination methods.
  TAO_Advanced_Resource_Factory (void);
  // Constructor.

  virtual ~TAO_Advanced_Resource_Factory (void);
  // Destructor.

  // = Service Configurator hooks.
  virtual int init (int argc, char* argv[]);
  // Dynamic linking hook

  // = Member Accessors
  enum
  {
    TAO_ALLOCATOR_NULL_LOCK,
    TAO_ALLOCATOR_THREAD_LOCK
  };

  // = Type of Reactor
  enum
  {
    TAO_REACTOR_SELECT_MT, // Use ACE_Token
    TAO_REACTOR_SELECT_ST, // Use ACE_Noop_Token
    TAO_REACTOR_FL,
    TAO_REACTOR_TK,
    TAO_REACTOR_WFMO,
    TAO_REACTOR_MSGWFMO,
    TAO_REACTOR_TP
  };

  // = Priority mapping types
  enum
  {
    TAO_PRIORITY_MAPPING_LINEAR,
    TAO_PRIORITY_MAPPING_DIRECT
  };

  // = Reactor mappings strategy
  enum
  {
    TAO_SINGLE_REACTOR,
    TAO_REACTOR_PER_PRIORITY
  };

  // = Resource Retrieval
  virtual TAO_Reactor_Registry *get_reactor_registry (void);
  virtual int init_protocol_factories (void);
  virtual ACE_Allocator* input_cdr_dblock_allocator (void);
  virtual ACE_Allocator* input_cdr_buffer_allocator (void);
  virtual TAO_ProtocolFactorySet *get_protocol_factories (void);

  virtual TAO_Priority_Mapping *get_priority_mapping (void);

protected:

  virtual ACE_Reactor_Impl *allocate_reactor_impl (void) const;
  // Obtain the reactor implementation

  TAO_ProtocolFactorySet protocol_factories_;
  // list of loaded protocol factories.

  int sched_policy_;
  // The scheduling policy used to initialize the priority mapping
  // strategy.

  int reactor_registry_type_;
  // The type of reactor registry.

  int reactor_type_;
  // Flag indicating which kind of reactor we should use.

  int priority_mapping_type_;
  // The type of priority mapping class created by this factory.

  int cdr_allocator_type_;
  // The type of CDR allocators.

  virtual int load_default_protocols (void);

};

#if defined (__ACE_INLINE__)
#include "advanced_resource.i"
#endif /* __ACE_INLINE__ */

ACE_STATIC_SVC_DECLARE (TAO_Advanced_Resource_Factory)
ACE_FACTORY_DECLARE (TAO_Strategies, TAO_Advanced_Resource_Factory)
ACE_STATIC_SVC_REQUIRE(TAO_Advanced_Resource_Factory)

#include "ace/post.h"
#endif /* TAO_ADVANCED_RESOURCE_H */
