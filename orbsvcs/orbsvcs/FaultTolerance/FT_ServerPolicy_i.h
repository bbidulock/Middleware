/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   FT_ServerPolicy_i.h
 *
 *  $Id$
 *
 *  @author Balachandran Natarajan <bala@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_FT_SERVERPOLICY_I_H
#define TAO_FT_SERVERPOLICY_I_H
#include /**/ "ace/pre.h"

#include "orbsvcs/FT_CORBA_ORBC.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#include "tao/LocalObject.h"

/**
 * @class TAO_FT_Heart_Beat_Enabled_Policy
 *
 * @brief FT::HeartBeatEnabledPolicy
 *
 * If this  policy is set, it enables the server ORB to set
 * the TAG_FT_HEARTBEAT_ENABLED component in the IOP profile of
 * the IOR that it exposes
 */
class TAO_FT_Export TAO_FT_Heart_Beat_Enabled_Policy
  : public FT::HeartbeatEnabledPolicy,
    public TAO_Local_RefCounted_Object
{
public:

  /// Constructor.
  TAO_FT_Heart_Beat_Enabled_Policy (const CORBA::Boolean boolean);

  /// Copy constructor.
  TAO_FT_Heart_Beat_Enabled_Policy (
      const TAO_FT_Heart_Beat_Enabled_Policy &rhs);

  static CORBA::Policy_ptr create (const CORBA::Any& val
                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  // Helper method for the implementation of
  // CORBA::ORB::create_policy.

  /// Returns a copy of <this>.
  virtual TAO_FT_Heart_Beat_Enabled_Policy *clone (void) const;

  // = The FT::HeartBeatPolicy methods
  virtual CORBA::Boolean heartbeat_enabled_policy_value (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::PolicyType policy_type (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::Policy_ptr copy (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void destroy (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:

  /// indicates whether heartbeating is enabled or not.
  CORBA::Boolean heartbeat_enabled_value_;
};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__ACE_INLINE__)
#include "FT_ServerPolicy_i.inl"
#endif /* __ACE_INLINE__ */


#include /**/ "ace/post.h"
#endif /* TAO_FT_SERVERPOLICY_I_H */
