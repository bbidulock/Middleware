/* -*- C++ -*- */
// $Id$

ACE_INLINE
CIAO::AssemblyFactory_Impl::AssemblyFactory_Impl (CORBA::ORB_ptr o,
                                                  PortableServer::POA_ptr p)
  : orb_ (CORBA::ORB::_duplicate (o)),
    poa_ (PortableServer::POA::_duplicate (p))
{
}

ACE_INLINE
CIAO::Assembly_Impl::Assembly_Impl (CORBA::ORB_ptr o,
                                    PortableServer::POA_ptr p)
  : orb_ (CORBA::ORB::_duplicate (o)),
    poa_ (PortableServer::POA::_duplicate (p)),
    state_ (::Components::Deployment::INACTIVE),
    serial_number_ (++CIAO::Assembly_Impl::assembly_count_)
{
  ACE_DEBUG ((LM_DEBUG,
              "CIAO::Assembly_Impl::Assembly_Impl %d\n",
              this->serial_number_));
}
