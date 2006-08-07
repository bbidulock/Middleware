// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO/examples/POA/Loader
//
// = FILENAME
//     Servant_Locator.cpp
//
// = DESCRIPTION
//     Implementation of ServantLocator class, used with a POA
//     having a NON_RETAIN policy.
//
// = AUTHOR
//     Kirthika Parameswaran <kirthika@cs.wustl.edu>
//
// ============================================================================

#include "Servant_Locator.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (Loader, 
           Servant_Locator, 
           "$Id$")

// Initialization.The dllname is used by the Loactor to load it into
// memory. The factory function is the point of entry into the dll and
// is used for obtaining the servant. The garbage_collection_function
// is used to kill the servant.

ServantLocator::ServantLocator (CORBA::ORB_ptr orb,
                                const char *dllname,
                                const char *factory_function,
                                const char *garbage_collection_function)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
  // The dll is opened using the dllname passed.
  if (this->dll_.open (dllname) == -1)
    ACE_ERROR ((LM_ERROR,
                "%p",
                this->dll_.error ()));

  // Obtain the symbol for the function that will get the servant
  // object.

  //
  // Cannot go from void* to function pointer directly. Cast the void*
  // to long first.
  //
  void *symbol = this->dll_.symbol (factory_function);
  long function = reinterpret_cast<long> (symbol);

  servant_supplier_ =
    reinterpret_cast<SERVANT_FACTORY> (function);

  // Obtain the symbol for the function which will destroy the
  // servant.
  symbol = this->dll_.symbol (garbage_collection_function);
  function = reinterpret_cast<long> (symbol);

  servant_garbage_collector_ =
    reinterpret_cast<SERVANT_GARBAGE_COLLECTOR> (function);
}

// This method associates an servant with the ObjectID.

PortableServer::Servant
ServantLocator::preinvoke (const PortableServer::ObjectId &oid,
                           PortableServer::POA_ptr poa,
                           const char * /* operation */,
                           PortableServer::ServantLocator::Cookie &cookie
                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableServer::ForwardRequest))
{
  PortableServer::Servant servant =
    (*servant_supplier_) (oid,
                          poa,
                          this->orb_.in ());
  if (servant != 0)
    {
      // Return the servant as the cookie , used as a check when
      // postinvoke is called on this ServantLocator.

      cookie = servant;
      return servant;
    }
  else
    ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                      0);
}

// Since the servant gets invoked per operation, the servant has to be
// destroyed per operation too.  This is accomplished in the
// postinvoke method.

void
ServantLocator::postinvoke (const PortableServer::ObjectId &oid,
                            PortableServer::POA_ptr poa ,
                            const char * /* operation */,
                            PortableServer::ServantLocator::Cookie cookie,
                            PortableServer::Servant servant
                            ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Check the passed servant with the cookie.
  PortableServer::Servant my_servant =
    reinterpret_cast<PortableServer::Servant> (cookie);

  ACE_ASSERT (servant == my_servant);

  // Invoke the garbage_collection_function.
  (*servant_garbage_collector_) (oid,
                                 poa,
                                 servant);

  // To avoid warning about unused variable with ACE_NDEBUG.
  ACE_UNUSED_ARG (my_servant);
}
