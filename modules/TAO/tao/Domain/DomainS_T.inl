// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be\be_visitor_interface/tie_si.cpp:96

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
  if (this->rel_)
    {
      delete this->ptr_;
    }
}

template <class T> ACE_INLINE T *
POA_CORBA::DomainManager_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA::DomainManager_tie<T>::_tied_object (T &obj)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA::DomainManager_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
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
POA_CORBA::DomainManager_tie<T>::_default_POA (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    {
      return PortableServer::POA::_duplicate (this->poa_.in ());
    }
  
  return this->DomainManager::_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// TAO_IDL - Generated from 
// be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
::CORBA::Policy_ptr POA_CORBA::DomainManager_tie<T>::get_domain_policy  (
    ::CORBA::PolicyType policy_type
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->get_domain_policy (
    policy_type
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/tie_si.cpp:96

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
  if (this->rel_)
    {
      delete this->ptr_;
    }
}

template <class T> ACE_INLINE T *
POA_CORBA::ConstructionPolicy_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_CORBA::ConstructionPolicy_tie<T>::_tied_object (T &obj)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_CORBA::ConstructionPolicy_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
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
POA_CORBA::ConstructionPolicy_tie<T>::_default_POA (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    {
      return PortableServer::POA::_duplicate (this->poa_.in ());
    }
  
  return this->ConstructionPolicy::_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// TAO_IDL - Generated from 
// be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
CORBA::PolicyType POA_CORBA::ConstructionPolicy_tie<T>::policy_type  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->policy_type (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
::CORBA::Policy_ptr POA_CORBA::ConstructionPolicy_tie<T>::copy  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->copy (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_CORBA::ConstructionPolicy_tie<T>::destroy  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be\be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_CORBA::ConstructionPolicy_tie<T>::make_domain_manager  (
    ::CORBA::InterfaceDef_ptr object_type,
    ::CORBA::Boolean constr_policy
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->make_domain_manager (
    object_type,
    constr_policy
    ACE_ENV_ARG_PARAMETER
  );
}


TAO_END_VERSIONED_NAMESPACE_DECL
