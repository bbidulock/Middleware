// $Id$

#include "Adapter_Activator.h"

ACE_RCSID (PortableServer,
           Adapter_Activator,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

#include "AdapterActivatorC.h"
#include "POAManagerC.h"

  // @@Johnny, why can't you simply include PortableServer.h. This
  // looks like a mega hack..
#define TAO_PORTABLESERVER_SAFE_INCLUDE
#include "PortableServerC.h"
#undef TAO_PORTABLESERVER_SAFE_INCLUDE

namespace TAO
{
  namespace Portable_Server
  {
    Adapter_Activator::Adapter_Activator (
      PortableServer::POAManager_ptr pm)
      : poa_manager_ (PortableServer::POAManager::_duplicate (pm))
    {
    }

    CORBA::Boolean
    Adapter_Activator::unknown_adapter (PortableServer::POA_ptr parent,
                                        const char *name
                                        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      // Default policies
      CORBA::PolicyList default_policies;

      // This assumes that the lock on the parent is recursive
      PortableServer::POA_var child =
        parent->create_POA (name,
                            this->poa_manager_.in (),
                            default_policies
                            ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      ACE_TRY
        {
          child->the_activator (this ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      ACE_CATCHANY
        {
          (void) child->destroy (1,
                                 1
                                 ACE_ENV_ARG_PARAMETER);

          // Delete the child
          delete child;
          child = 0;

          return false;
        }
      ACE_ENDTRY;
      ACE_CHECK_RETURN (0);

      // Finally everything is fine
      return true;
    }
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */
