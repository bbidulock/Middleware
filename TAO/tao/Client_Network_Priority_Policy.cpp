// $Id$

#include "tao/Client_Network_Priority_Policy.h"
#include "tao/TAO_Network_Priority_PolicyC.h"
#include "tao/SystemException.h"

ACE_RCSID (tao,
           Client_Network_Priority_Policy,
           "$Id$")

#if ! defined (__ACE_INLINE__)
#include "tao/Client_Network_Priority_Policy.i"
#endif /* __ACE_INLINE__ */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Client_Network_Priority_Policy::TAO_Client_Network_Priority_Policy (void)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , TAO::NetworkPriorityPolicy ()
  , TAO_Local_RefCounted_Object ()
  , request_diffserv_codepoint_ (0)
  , reply_diffserv_codepoint_ (0)
  , network_priority_model_ (TAO::NO_NETWORK_PRIORITY)
{
}

TAO_Client_Network_Priority_Policy::TAO_Client_Network_Priority_Policy (
  const TAO::DiffservCodepoint &request_diffserv_codepoint,
  const TAO::DiffservCodepoint &reply_diffserv_codepoint,
  TAO::NetworkPriorityModel &network_priority_model)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , TAO::NetworkPriorityPolicy ()
  , TAO_Local_RefCounted_Object ()
  , request_diffserv_codepoint_ (request_diffserv_codepoint)
  , reply_diffserv_codepoint_ (reply_diffserv_codepoint)
  , network_priority_model_ (network_priority_model)
{
}

TAO_Client_Network_Priority_Policy::TAO_Client_Network_Priority_Policy (
   const TAO_Client_Network_Priority_Policy &rhs)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , TAO::NetworkPriorityPolicy ()
  , TAO_Local_RefCounted_Object ()
  , request_diffserv_codepoint_ (rhs.request_diffserv_codepoint_)
  , reply_diffserv_codepoint_ (rhs.reply_diffserv_codepoint_)
  , network_priority_model_ (rhs.network_priority_model_)
{
}

CORBA::PolicyType
TAO_Client_Network_Priority_Policy::policy_type (
   ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return TAO::CLIENT_NETWORK_PRIORITY_TYPE;
}

TAO_Client_Network_Priority_Policy *
TAO_Client_Network_Priority_Policy::clone (void) const
{
  TAO_Client_Network_Priority_Policy *copy = 0;
  ACE_NEW_RETURN (copy,
                  TAO_Client_Network_Priority_Policy (*this),
                  0);
  return copy;
}

TAO::DiffservCodepoint
TAO_Client_Network_Priority_Policy::request_diffserv_codepoint (
   ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->request_diffserv_codepoint_;
}

TAO::DiffservCodepoint
TAO_Client_Network_Priority_Policy::reply_diffserv_codepoint (
   ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->reply_diffserv_codepoint_;
}

TAO::NetworkPriorityModel
TAO_Client_Network_Priority_Policy::network_priority_model (
   ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->network_priority_model_;
}

void
TAO_Client_Network_Priority_Policy::set_request_diffserv_codepoint (
  TAO::DiffservCodepoint ds
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->request_diffserv_codepoint_ = ds;
}

void
TAO_Client_Network_Priority_Policy::set_reply_diffserv_codepoint (
  TAO::DiffservCodepoint ds
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->reply_diffserv_codepoint_ = ds;
}

void
TAO_Client_Network_Priority_Policy::set_network_priority_model (
  TAO::NetworkPriorityModel npm
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->network_priority_model_ = npm;
}

TAO::DiffservCodepoint
TAO_Client_Network_Priority_Policy::get_request_diffserv_codepoint (
   ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
   ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->request_diffserv_codepoint_;
}

TAO::DiffservCodepoint
TAO_Client_Network_Priority_Policy::get_reply_diffserv_codepoint (
   ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
   ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->reply_diffserv_codepoint_;
}

TAO::NetworkPriorityModel
TAO_Client_Network_Priority_Policy::priority_model (
   ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->network_priority_model_;
}

CORBA::Policy_ptr
TAO_Client_Network_Priority_Policy::copy (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_Client_Network_Priority_Policy* servant = 0;
  ACE_NEW_THROW_EX (servant,
                    TAO_Client_Network_Priority_Policy (*this),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return servant;
}

void
TAO_Client_Network_Priority_Policy::destroy (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

TAO_Cached_Policy_Type
TAO_Client_Network_Priority_Policy::_tao_cached_type (void) const
{
  return TAO_CACHED_POLICY_CLIENT_NETWORK_PRIORITY;
}

TAO_Policy_Scope
TAO_Client_Network_Priority_Policy::_tao_scope (void) const
{
  return static_cast<TAO_Policy_Scope> (TAO_POLICY_DEFAULT_SCOPE |
                                        TAO_POLICY_CLIENT_EXPOSED);
}


TAO_END_VERSIONED_NAMESPACE_DECL
