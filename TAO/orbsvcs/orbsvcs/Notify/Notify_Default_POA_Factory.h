/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   Notify_Default_POA_Factory.h
 *
 *  $Id$
 *
 * Default factory for POA objects.
 *
 *
 *  @author Pradeep Gore <pradeep@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_NOTIFY_DEFAULT_POA_FACTORY_H
#define TAO_NOTIFY_DEFAULT_POA_FACTORY_H

#include "ace/pre.h"
#include "Notify_POA_Factory.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class TAO_Notify_Default_POA_Factory
 *
 * @brief Default factory for POA objects.
 */
class TAO_Notify_Export TAO_Notify_Default_POA_Factory : public TAO_Notify_POA_Factory
{
public:
  TAO_Notify_Default_POA_Factory (void);
  ~TAO_Notify_Default_POA_Factory ();

  /// Helper function to register the default factory into the service
  /// configurator.
  static int init_svc (void);

  // = The Service_Object entry points
  virtual int init (int argc, ACE_TCHAR* argv[]);
  virtual int fini (void);

  /// Create the POA to activate Event Channels in.
  PortableServer::POA_ptr create_event_channel_POA (PortableServer::POA_ptr parent_poa ACE_ENV_ARG_DECL);

  /// Create the POA to activate SA's in.
  PortableServer::POA_ptr create_supplier_admin_POA (PortableServer::POA_ptr parent_poa, CORBA::Long new_poa_id ACE_ENV_ARG_DECL);

  /// Create the POA to activate CA's in.
  PortableServer::POA_ptr create_consumer_admin_POA (PortableServer::POA_ptr parent_poa, CORBA::Long new_poa_id ACE_ENV_ARG_DECL);

  /// Create the POA to activate proxy push consumers in.
  PortableServer::POA_ptr create_proxy_pushconsumer_POA (PortableServer::POA_ptr parent_poa, CORBA::Long new_poa_id ACE_ENV_ARG_DECL);

  /// Create the POA to activate proxy push suppliers in.
  PortableServer::POA_ptr create_proxy_pushsupplier_POA (PortableServer::POA_ptr parent_poa, CORBA::Long new_poa_id ACE_ENV_ARG_DECL);

  // = Object activation and POA methods
  /// Converts <id> to an ObjectId and registers with the POA <poa>.
  CORBA::Object_ptr activate_object_with_id (CORBA::Long id, PortableServer::POA_ptr poa,PortableServer::Servant servant ACE_ENV_ARG_DECL);

  /// Registers with the POA <poa>.
  CORBA::Object_ptr activate_object (PortableServer::POA_ptr poa,PortableServer::Servant servant ACE_ENV_ARG_DECL);

  /// Registers with the POA <poa>.
  CORBA::Object_ptr servant_to_reference (PortableServer::POA_ptr poa,PortableServer::Servant servant ACE_ENV_ARG_DECL);

  /// Look for the Object with id <id> in <poa>.
  CORBA::Object_ptr id_to_reference (CORBA::Long id, PortableServer::POA_ptr poa ACE_ENV_ARG_DECL);

  /// Destroy the <poa>
  void destroy_POA (PortableServer::POA_ptr poa ACE_ENV_ARG_DECL);

  /// Deactivate the object.
  void deactivate_object (CORBA::Object_ptr obj, PortableServer::POA_ptr poa ACE_ENV_ARG_DECL);

  /// Deactivate the object.
  void deactivate_object (PortableServer::Servant servant, PortableServer::POA_ptr ACE_ENV_ARG_DECL);

protected:
  // = Helper methods

  /// Converts a CORBA::Long to an ObjectId
  PortableServer::ObjectId* long_to_ObjectId (const CORBA::Long id);

  /// Create the POA with the most generic policies required of our POA's.
  PortableServer::POA_ptr create_generic_childPOA_i (const char* child_poa_name, PortableServer::POA_ptr parent_poa ACE_ENV_ARG_DECL);

};

ACE_STATIC_SVC_DECLARE (TAO_Notify_Default_POA_Factory)
ACE_FACTORY_DECLARE (TAO_Notify,TAO_Notify_Default_POA_Factory)

#include "ace/post.h"
#endif /* TAO_NOTIFY_DEFAULT_POA_FACTORY_H */
