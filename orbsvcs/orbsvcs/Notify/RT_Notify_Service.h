/* -*- C++ -*- */
/**
 *  @file RT_Notify_Service.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_RT_NOTIFY_SERVICE_H
#define TAO_Notify_RT_NOTIFY_SERVICE_H

#include /**/ "ace/pre.h"
#include "rt_notify_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "CosNotify_Service.h"

/**
 * @class TAO_RT_Notify_Service
 *
 * @brief Implementation of the TAO_Notify_Service interface for
 * RT Notification.
 *
 */
class TAO_RT_Notify_Export TAO_RT_Notify_Service : public TAO_CosNotify_Service
{
public:
  /// Constuctor
  TAO_RT_Notify_Service (void);

  /// Destructor
  ~TAO_RT_Notify_Service ();


  /// Init the service.
  virtual void init_service (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL);

protected:
  /// Init the data members
  virtual void init_i (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL);

  /// Create the Factory for RT Notify objects.
  virtual TAO_Notify_Factory* create_factory (ACE_ENV_SINGLE_ARG_DECL);

  /// Creates the Builder for RT Notify objects.
  virtual TAO_Notify_Builder* create_builder (ACE_ENV_SINGLE_ARG_DECL);
};

ACE_FACTORY_DECLARE (TAO_RT_Notify,TAO_RT_Notify_Service)

#include /**/ "ace/post.h"
#endif /* TAO_Notify_RT_NOTIFY_SERVICE_H */
