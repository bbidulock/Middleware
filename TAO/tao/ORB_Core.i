// $Id$

#include "ace/Dynamic_Service.h"

#define TAO_TRF (this->resource_factory ())
#define TAO_OC_RETRIEVE(member) \
  ((this->member##_ == 0) ? (this->member##_ = this->resource_factory ()->get_##member ()) : (this->member##_) )

ACE_INLINE ACE_Reactor *
TAO_ORB_Core::reactor (ACE_Reactor *r)
{
  ACE_Reactor *old_reactor = this->reactor_;
  this->reactor_ = r;
  return old_reactor;
}

ACE_INLINE ACE_Reactor*
TAO_ORB_Core::reactor (void)
{
  return TAO_OC_RETRIEVE (reactor);
}

ACE_INLINE ACE_Thread_Manager *
TAO_ORB_Core::thr_mgr (ACE_Thread_Manager *tm)
{
  ACE_Thread_Manager *old_thr_mgr = this->thr_mgr_;
  this->thr_mgr_ = tm;
  return old_thr_mgr;
}

ACE_INLINE ACE_Thread_Manager*
TAO_ORB_Core::thr_mgr (void)
{
  return TAO_OC_RETRIEVE (thr_mgr);
}

ACE_INLINE CORBA::ORB_ptr
TAO_ORB_Core::orb (void)
{
  return TAO_OC_RETRIEVE (orb);
}

ACE_INLINE TAO_POA *
TAO_ORB_Core::root_poa (const char *adapter_name,
                        TAO_POA_Manager *poa_manager,
                        const TAO_POA_Policies *policies)
{
  if (TAO_OC_RETRIEVE (root_poa) == 0)
    this->create_and_set_root_poa (adapter_name,
                                   poa_manager,
                                   policies);

  return this->root_poa_;
}

ACE_INLINE PortableServer::POA_ptr
TAO_ORB_Core::root_poa_reference (CORBA::Environment &TAO_IN_ENV,
                                  const char *adapter_name,
                                  TAO_POA_Manager *poa_manager,
                                  const TAO_POA_Policies *policies)
{
  if (CORBA::is_nil (this->root_poa_reference_.in ()))
    {
      TAO_POA *poa = this->root_poa (adapter_name,
                                     poa_manager,
                                     policies);

      this->root_poa_reference_ = poa->_this (TAO_IN_ENV);
      TAO_CHECK_RETURN (PortableServer::POA::_nil ());
    }

  return PortableServer::POA::_duplicate (this->root_poa_reference_.in ());
}

ACE_INLINE TAO_OA_Parameters *
TAO_ORB_Core::oa_params (void)
{
  return TAO_OC_RETRIEVE (oa_params);
}

ACE_INLINE
TAO_ORB_Parameters *
TAO_ORB_Core::orb_params(void)
{
  return TAO_OC_RETRIEVE (orb_params);
}

ACE_INLINE TAO_Connector_Registry *
TAO_ORB_Core::connector_registry (TAO_Connector_Registry *cr)
{
  TAO_Connector_Registry *old_cr = this->connector_registry_;
  this->connector_registry_ = cr;
  return old_cr;
}

ACE_INLINE TAO_Connector_Registry *
TAO_ORB_Core::connector_registry (void)
{
  return TAO_OC_RETRIEVE (connector_registry);
}

ACE_INLINE TAO_Acceptor *
TAO_ORB_Core::acceptor (TAO_Acceptor *a)
{
  TAO_Acceptor *old_acceptor = this->acceptor_;
  this->acceptor_ = a;
  return old_acceptor;
}

ACE_INLINE TAO_Acceptor *
TAO_ORB_Core::acceptor (void)
{
  return TAO_OC_RETRIEVE (acceptor);
}

#undef TAO_OC_RETRIEVE
#undef TAO_TRF

ACE_INLINE TAO_POA_Current *
TAO_ORB_Core::poa_current (void)
{
  return poa_current_;
}

ACE_INLINE TAO_POA_Current *
TAO_ORB_Core::poa_current (TAO_POA_Current *new_current)
{
  TAO_POA_Current *old = poa_current_;
  poa_current_ = new_current;
  return old;
}

ACE_INLINE CORBA::Boolean
TAO_ORB_Core::using_collocation (void)
{
  return this->opt_for_collocation_;
}

ACE_INLINE CORBA::Boolean
TAO_ORB_Core::using_collocation (CORBA::Boolean use_col)
{
  CORBA::Boolean retv = this->opt_for_collocation_;
  this->opt_for_collocation_ = use_col;
  return retv;
}

ACE_INLINE CORBA_Environment*
TAO_ORB_Core::default_environment (void) const
{
  return this->default_environment_;
}

ACE_INLINE void
TAO_ORB_Core::default_environment (CORBA_Environment* env)
{
  this->default_environment_ = env;
}

ACE_INLINE ACE_Data_Block*
TAO_ORB_Core::create_input_cdr_data_block (size_t size)
{
  return this->resource_factory ()->create_input_cdr_data_block (size);
}

// ****************************************************************

ACE_INLINE void
TAO_Resource_Factory::resource_source (int which_source)
{
  resource_source_ = which_source;
}

ACE_INLINE int
TAO_Resource_Factory::resource_source (void)
{
  return resource_source_;
}

ACE_INLINE void
TAO_Resource_Factory::poa_source (int which_source)
{
  poa_source_ = which_source;
}

ACE_INLINE int
TAO_Resource_Factory::poa_source (void)
{
  return poa_source_;
}

ACE_INLINE int
TAO_Resource_Factory::reactor_lock (void)
{
  return reactor_lock_;
}

ACE_INLINE int
TAO_Resource_Factory::init (int argc, char *argv[])
{
  return this->parse_args (argc, argv);
}

// ****************************************************************
