// -*- C++ -*-

// ===================================================================
/**
 *  @file   Default_Protocols_Hooks.h
 *
 *  $Id$
 *
 *  @author Priyanka Gontla <pgontla@ece.uci.edu>
 */
// ===================================================================

#ifndef TAO_DEFAULT_PROTOCOLS_HOOKS_H
#define TAO_DEFAULT_PROTOCOLS_HOOKS_H
#include "ace/pre.h"

#include "Protocols_Hooks.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"

class TAO_Export TAO_Default_Protocols_Hooks : public TAO_Protocols_Hooks
{
 public:

  TAO_Default_Protocols_Hooks (void);

  /// Destructor
  virtual ~TAO_Default_Protocols_Hooks (void);

  virtual int
  call_client_protocols_hook (TAO_ORB_Core *orb_core,
                              int &send_buffer_size,
                              int &recv_buffer_size,
                              int &no_delay,
                              const char *protocol_type);

  virtual int
  call_server_protocols_hook (TAO_ORB_Core *orb_core,
                              int &send_buffer_size,
                              int &recv_buffer_size,
                              int &no_delay,
                              const char *protocol_type);

  virtual void call_policy_type_hook (CORBA::PolicyList *&policy_list,
                                      CORBA::ULong &policy_type);

  virtual void validate_policy_type (CORBA::ULong slot,
                                     CORBA::ULong &type_value,
                                     CORBA::Environment &ACE_TRY_ENV);

  virtual void add_rt_service_context_hook (
                  TAO_GIOP_Invocation *invocation,
                  CORBA::Policy *model_policy,
                  CORBA::Short &client_priority,
                  CORBA::Environment &ACE_TRY_ENV);

  virtual void get_selector_hook (CORBA::Policy *model_policy,
                                  CORBA::Boolean
                                  &is_client_propagated,
                                  CORBA::Short &server_priority);

  virtual void get_selector_bands_policy_hook (
                                  CORBA::Policy
                                  *bands_policy,
                                  CORBA::Short &min_priority,
                                  CORBA::Short &max_priority,
                                  CORBA::Short &p,
                                  int &in_range);


  /**
   * Hook to check and override the exposed policies if needed
   *
   */
  virtual CORBA::Policy *effective_priority_banded_connection_hook (CORBA::Policy *override,
                                                                    CORBA::Policy *exposed,
                                                                    CORBA::Environment &);

  virtual CORBA::Policy *effective_client_protocol_hook (CORBA::Policy *override,
                                                         CORBA::Policy *exposed,
                                                         CORBA::Environment &);

  /**
   * Accessor and modifier to the current thread priority, used to
   * implement the RTCORBA::Current interface, but it is faster for
   * some critical components.  If TAO_HAS_RT_CORBA == 0, the
   * operations are no-ops.
   */
  //@{
  virtual int get_thread_priority (TAO_ORB_Core *,
                                   CORBA::Short &,
                                   CORBA::Environment &);

  virtual int set_thread_priority (TAO_ORB_Core *,
                                   CORBA::Short,
                                   CORBA::Environment &);
  //@}

  virtual void set_priority_mapping (TAO_ORB_Core *,
                                     TAO_Resource_Factory *,
                                     CORBA::Environment &);

  virtual int set_default_policies (TAO_ORB_Core *orb_core);

};

#if defined (__ACE_INLINE__)
#include "tao/Default_Protocols_Hooks.i"
#endif /* __ACE_INLINE__ */

ACE_STATIC_SVC_DECLARE_EXPORT (TAO, TAO_Default_Protocols_Hooks)
ACE_FACTORY_DECLARE (TAO, TAO_Default_Protocols_Hooks)

#include "ace/post.h"
#endif /* TAO_DEFAULT_PROTOCOLS_HOOKS_H */
