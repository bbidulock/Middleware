/* -*- C++ -*- */
// $Id$

ACE_INLINE
CIAO::ComponentServer_Impl::ComponentServer_Impl (CORBA::ORB_ptr o,
                                                  PortableServer::POA_ptr p)
  : orb_ (CORBA::ORB::_duplicate (o)),
    poa_ (PortableServer::POA::_duplicate (p))
{
}

ACE_INLINE void
CIAO::ComponentServer_Impl::set_objref (Components::Deployment::ServerActivator_ptr act,
                                        Components::Deployment::ComponentServer_ptr cs
                                        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (!CORBA::is_nil (this->activator_.in ()) || !CORBA::is_nil (this->objref_.in ()))
    ACE_THROW (CORBA::BAD_INV_ORDER ());

  this->activator_ = Components::Deployment::ServerActivator::_duplicate (act);
  this->objref_ = Components::Deployment::ComponentServer::_duplicate (cs);
}

ACE_INLINE Components::Deployment::ComponentServer_ptr
CIAO::ComponentServer_Impl::get_objref (ACE_ENV_SINGLE_ARG_DECL)
{
  if (CORBA::is_nil (this->objref_.in ()))
    {
      this->objref_ = this->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);
    }

  return this->objref_.in ();
}
