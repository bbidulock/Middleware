/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_MESSAGINGS_T_CPP_
#define _TAO_IDL_MESSAGINGS_T_CPP_

#include "MessagingS_T.h"
#include "tao/POA.h"
#include "tao/ORB_Core.h"

#if !defined (__ACE_INLINE__)
#include "tao/MessagingS_T.i"
#endif /* !defined INLINE */

template <class T> PortableServer::POA_ptr
POA_Messaging::RebindPolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->RebindPolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::SyncScopePolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->SyncScopePolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::RequestPriorityPolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->RequestPriorityPolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::ReplyPriorityPolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->ReplyPriorityPolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::RequestStartTimePolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->RequestStartTimePolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::RequestEndTimePolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->RequestEndTimePolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::ReplyStartTimePolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->ReplyStartTimePolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::ReplyEndTimePolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->ReplyEndTimePolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::RelativeRequestTimeoutPolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->RelativeRequestTimeoutPolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::RelativeRoundtripTimeoutPolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->RelativeRoundtripTimeoutPolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::RoutingPolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->RoutingPolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::MaxHopsPolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->MaxHopsPolicy::_default_POA (ACE_TRY_ENV);
}

template <class T> PortableServer::POA_ptr
POA_Messaging::QueueOrderPolicy_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->QueueOrderPolicy::_default_POA (ACE_TRY_ENV);
}

#if (TAO_HAS_AMI_CALLBACK == 1)

template <class T> PortableServer::POA_ptr
POA_Messaging::ReplyHandler_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->ReplyHandler::_default_POA (ACE_TRY_ENV);
}

#endif /* TAO_HAS_AMI_CALLBACK == 1 */

#if (TAO_HAS_AMI_POLLER == 1)

template <class T> PortableServer::POA_ptr
POA_Messaging::Poller_tie<T>::_default_POA (CORBA::Environment &ACE_TRY_ENV)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->Poller::_default_POA (ACE_TRY_ENV);
}
#endif /* TAO_HAS_AMI_POLLER == 1 */

#endif /* ifndef */
