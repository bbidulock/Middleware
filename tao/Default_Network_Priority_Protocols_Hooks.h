// -*- C++ -*-

// ===================================================================
/**
 *  @file   Default_Network_Priority_Protocols_Hooks.h
 *
 *  $Id$
 *
 *  @author Jaiganesh Balasubramanian <jai@dre.vanderbilt.edu>
 *          Johnny Willemsen <jwillemsen@remedy.nl>
 */
// ===================================================================

#ifndef TAO_DEFAULT_NETWORK_PRIORITY_PROTOCOLS_HOOKS_H
#define TAO_DEFAULT_NETWORK_PRIORITY_PROTOCOLS_HOOKS_H

#include /**/ "ace/pre.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Network_Priority_Protocols_Hooks.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_POA;

class TAO_Export TAO_Default_Network_Priority_Protocols_Hooks
      : public TAO_Network_Priority_Protocols_Hooks
{
public:

  /// destructor
  virtual ~TAO_Default_Network_Priority_Protocols_Hooks (void);

  void init_hooks (TAO_ORB_Core *orb_core);

  CORBA::Long get_dscp_codepoint (TAO_Stub *stub, CORBA::Object *object);

  CORBA::Long get_dscp_codepoint (TAO_Service_Context &service_context);

  void np_service_context (TAO_Stub *stub,
                           TAO_Service_Context &service_context,
                           CORBA::Boolean restart);

  void add_rep_np_service_context_hook (
    TAO_Service_Context &service_context,
    CORBA::Long &dscp_codepoint);
};

TAO_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DECLARE_EXPORT (TAO,
                               TAO_Default_Network_Priority_Protocols_Hooks)
ACE_FACTORY_DECLARE (TAO, TAO_Default_Network_Priority_Protocols_Hooks)

#include /**/ "ace/post.h"
#endif /* TAO_DEFAULT_NETWORK_PRIORITY_PROTOCOLS_HOOKS_H */
