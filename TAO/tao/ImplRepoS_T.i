/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html


#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::ServerObject_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::ServerObject_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::ServerObject_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::ServerObject_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerObject_tie<T>::~ServerObject_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_ImplementationRepository::ServerObject_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerObject_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerObject_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_ImplementationRepository::ServerObject_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerObject_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_ImplementationRepository::ServerObject_tie<T>::_default_POA (CORBA::Environment &env)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->ServerObject::_default_POA (env);
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::ServerObject_tie<T>::ping  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->ping (
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::ServerObject_tie<T>::shutdown  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->shutdown (
    ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::Administration_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::Administration_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::Administration_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::Administration_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::Administration_tie<T>::~Administration_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_ImplementationRepository::Administration_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::Administration_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::Administration_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_ImplementationRepository::Administration_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::Administration_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_ImplementationRepository::Administration_tie<T>::_default_POA (CORBA::Environment &env)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->Administration::_default_POA (env);
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::activate_server  (
    const char * server,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    ImplementationRepository::Administration::NotFound,
    ImplementationRepository::Administration::CannotActivate
  ))
{
  this->ptr_->activate_server (
    server,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::register_server  (
    const char * server,
    const ImplementationRepository::StartupOptions & options,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    ImplementationRepository::Administration::AlreadyRegistered
  ))
{
  this->ptr_->register_server (
    server,
    options,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::reregister_server  (
    const char * server,
    const ImplementationRepository::StartupOptions & options,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->reregister_server (
    server,
    options,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::remove_server  (
    const char * server,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    ImplementationRepository::Administration::NotFound
  ))
{
  this->ptr_->remove_server (
    server,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::shutdown_server  (
    const char * server,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    ImplementationRepository::Administration::NotFound
  ))
{
  this->ptr_->shutdown_server (
    server,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
char * POA_ImplementationRepository::Administration_tie<T>::server_is_running  (
    const char * server,
    const char * addr,
    ImplementationRepository::ServerObject_ptr server_object,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    ImplementationRepository::Administration::NotFound
  ))
{
  return this->ptr_->server_is_running (
    server,
    addr,
    server_object,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::server_is_shutting_down  (
    const char * server,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    ImplementationRepository::Administration::NotFound
  ))
{
  this->ptr_->server_is_shutting_down (
    server,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::find  (
    const char * server,
    ImplementationRepository::ServerInformation_out info,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    ImplementationRepository::Administration::NotFound
  ))
{
  this->ptr_->find (
    server,
    info,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::Administration_tie<T>::list  (
    CORBA::ULong how_many,
    ImplementationRepository::ServerInformationList_out server_list,
    ImplementationRepository::ServerInformationIterator_out server_iterator,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->list (
    how_many,
    server_list,
    server_iterator,
    ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

#if defined (ACE_HAS_USING_KEYWORD)
template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::ServerInformationIterator_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::ServerInformationIterator_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::ServerInformationIterator_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::ServerInformationIterator_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_ImplementationRepository::ServerInformationIterator_tie<T>::~ServerInformationIterator_tie (void)
{
  if (this->rel_) delete this->ptr_;
}

template <class T> ACE_INLINE T *
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_tied_object (T &obj)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_) delete this->ptr_;
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_ImplementationRepository::ServerInformationIterator_tie<T>::_default_POA (CORBA::Environment &env)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    return PortableServer::POA::_duplicate (this->poa_.in ());

  return this->ServerInformationIterator::_default_POA (env);
}

template <class T> ACE_INLINE
CORBA::Boolean POA_ImplementationRepository::ServerInformationIterator_tie<T>::next_n  (
    CORBA::ULong how_many,
    ImplementationRepository::ServerInformationList_out server_list,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->next_n (
    how_many,
    server_list,
    ACE_TRY_ENV
  );
}

template <class T> ACE_INLINE
void POA_ImplementationRepository::ServerInformationIterator_tie<T>::destroy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->destroy (
    ACE_TRY_ENV
  );
}

#endif /* ACE_HAS_USING_KEYWORD */
