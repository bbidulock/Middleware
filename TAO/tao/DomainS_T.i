/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html


#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_CORBA::DomainManager_tie<T>::DomainManager_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::DomainManager_tie<T>::DomainManager_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::DomainManager_tie<T>::DomainManager_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::DomainManager_tie<T>::DomainManager_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::DomainManager_tie<T>::~DomainManager_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA::DomainManager_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA::DomainManager_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA::DomainManager_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA::DomainManager_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA::DomainManager_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA::DomainManager_tie<T>::_default_POA (CORBA::Environment &env)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());
  else
  {
    TAO_POA *poa = TAO_ORB_Core_instance ()->root_poa ();
    PortableServer::POA_var result = poa->_this (env);
    if (env.exception () != 0)
      return PortableServer::POA::_nil ();
    else
      return result._retn ();
  }
}

template <class T> ACE_INLINE
CORBA::Policy_ptr POA_CORBA::DomainManager_tie<T>::get_domain_policy  (
    CORBA::PolicyType policy_type,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->ptr_->get_domain_policy (
    policy_type,
    ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

#if ! defined (TAO_HAS_MINIMUM_CORBA)

#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_CORBA::ConstructionPolicy_tie<T>::ConstructionPolicy_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::ConstructionPolicy_tie<T>::ConstructionPolicy_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_CORBA::ConstructionPolicy_tie<T>::ConstructionPolicy_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::ConstructionPolicy_tie<T>::ConstructionPolicy_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_CORBA::ConstructionPolicy_tie<T>::~ConstructionPolicy_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_CORBA::ConstructionPolicy_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA::ConstructionPolicy_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA::ConstructionPolicy_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_CORBA::ConstructionPolicy_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_CORBA::ConstructionPolicy_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_CORBA::ConstructionPolicy_tie<T>::_default_POA (CORBA::Environment &env)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());
  else
  {
    TAO_POA *poa = TAO_ORB_Core_instance ()->root_poa ();
    PortableServer::POA_var result = poa->_this (env);
    if (env.exception () != 0)
      return PortableServer::POA::_nil ();
    else
      return result._retn ();
  }
}

template <class T> ACE_INLINE
void POA_CORBA::ConstructionPolicy_tie<T>::make_domain_manager  (
    CORBA::InterfaceDef_ptr object_type,
    CORBA::Boolean constr_policy,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  this->ptr_->make_domain_manager (
    object_type,
    constr_policy,
    ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

#endif /* ! defined (TAO_HAS_MINIMUM_CORBA)
