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


// TAO_IDL - Generated from
// be/be_visitor_interface/tie_si.cpp:96

#if defined (ACE_HAS_USING_KEYWORD)

template <class T> ACE_INLINE
POA_A::AMI_Test_tie<T>::AMI_Test_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_A::AMI_Test_tie<T>::AMI_Test_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_A::AMI_Test_tie<T>::AMI_Test_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_A::AMI_Test_tie<T>::AMI_Test_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_A::AMI_Test_tie<T>::~AMI_Test_tie (void)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
}

template <class T> ACE_INLINE T *
POA_A::AMI_Test_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_A::AMI_Test_tie<T>::_tied_object (T &obj)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_A::AMI_Test_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_A::AMI_Test_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_A::AMI_Test_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_A::AMI_Test_tie<T>::_default_POA (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    {
      return PortableServer::POA::_duplicate (this->poa_.in ());
    }
  
  return this->AMI_Test::_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
CORBA::Long POA_A::AMI_Test_tie<T>::foo  (
    CORBA::Long_out out_l,
    CORBA::Long in_l,
    const char * in_str
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
    , A::DidTheRightThing
  ))
{
  return this->ptr_->foo (
    out_l,
    in_l,
    in_str
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
CORBA::Long POA_A::AMI_Test_tie<T>::yadda  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->ptr_->yadda (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_A::AMI_Test_tie<T>::yadda  (
    CORBA::Long yadda
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->yadda (
    yadda
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_A::AMI_Test_tie<T>::shutdown  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->shutdown (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

// TAO_IDL - Generated from
// be/be_visitor_interface/tie_si.cpp:96

#if defined (ACE_HAS_USING_KEYWORD)

template <class T> ACE_INLINE
POA_A::AMI_AMI_TestHandler_tie<T>::AMI_AMI_TestHandler_tie (T &t)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_A::AMI_AMI_TestHandler_tie<T>::AMI_AMI_TestHandler_tie (T &t, PortableServer::POA_ptr poa)
	: ptr_ (&t),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (0)
{}

template <class T> ACE_INLINE
POA_A::AMI_AMI_TestHandler_tie<T>::AMI_AMI_TestHandler_tie (T *tp, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_nil ()),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_A::AMI_AMI_TestHandler_tie<T>::AMI_AMI_TestHandler_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release)
	: ptr_ (tp),
	  poa_ (PortableServer::POA::_duplicate (poa)),
	  rel_ (release)
{}

template <class T> ACE_INLINE
POA_A::AMI_AMI_TestHandler_tie<T>::~AMI_AMI_TestHandler_tie (void)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
}

template <class T> ACE_INLINE T *
POA_A::AMI_AMI_TestHandler_tie<T>::_tied_object (void)
{
  return this->ptr_;
}

template <class T> ACE_INLINE void
POA_A::AMI_AMI_TestHandler_tie<T>::_tied_object (T &obj)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = &obj;
  this->rel_ = 0;
}

template <class T> ACE_INLINE void
POA_A::AMI_AMI_TestHandler_tie<T>::_tied_object (T *obj, CORBA::Boolean release)
{
  if (this->rel_)
    {
      delete this->ptr_;
    }
  
  this->ptr_ = obj;
  this->rel_ = release;
}

template <class T> ACE_INLINE CORBA::Boolean
POA_A::AMI_AMI_TestHandler_tie<T>::_is_owner (void)
{
  return this->rel_;
}

template <class T> ACE_INLINE void
POA_A::AMI_AMI_TestHandler_tie<T>::_is_owner (CORBA::Boolean b)
{
  this->rel_ = b;
}

template <class T> ACE_INLINE PortableServer::POA_ptr
POA_A::AMI_AMI_TestHandler_tie<T>::_default_POA (ACE_ENV_SINGLE_ARG_DECL)
{
  if (!CORBA::is_nil (this->poa_.in ()))
    {
      return PortableServer::POA::_duplicate (this->poa_.in ());
    }
  
  return this->AMI_AMI_TestHandler::_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_A::AMI_AMI_TestHandler_tie<T>::foo  (
    CORBA::Long ami_return_val,
    CORBA::Long out_l
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->foo (
    ami_return_val,
    out_l
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_A::AMI_AMI_TestHandler_tie<T>::foo_excep  (
    A::AMI_AMI_TestExceptionHolder * excep_holder
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->foo_excep (
    excep_holder
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_A::AMI_AMI_TestHandler_tie<T>::get_yadda  (
    CORBA::Long ami_return_val
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->get_yadda (
    ami_return_val
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_A::AMI_AMI_TestHandler_tie<T>::get_yadda_excep  (
    A::AMI_AMI_TestExceptionHolder * excep_holder
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->get_yadda_excep (
    excep_holder
    ACE_ENV_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_A::AMI_AMI_TestHandler_tie<T>::set_yadda  (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->set_yadda (
    ACE_ENV_SINGLE_ARG_PARAMETER
  );
}

// TAO_IDL - Generated from 
// be/be_visitor_operation/tie_si.cpp:68

template <class T> ACE_INLINE
void POA_A::AMI_AMI_TestHandler_tie<T>::set_yadda_excep  (
    A::AMI_AMI_TestExceptionHolder * excep_holder
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->ptr_->set_yadda_excep (
    excep_holder
    ACE_ENV_ARG_PARAMETER
  );
}

#endif /* ACE_HAS_USING_KEYWORD */

