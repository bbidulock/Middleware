// $Id$

#include "Local_Servant_Base.h"
#include "tao/SystemException.h"

ACE_RCSID (PortableServer,
           Local_Servant_Base,
           "$Id$")

#if !defined (__ACE_INLINE__)
# include "Local_Servant_Base.inl"
#endif /* ! __ACE_INLINE__ */

void
TAO_Local_ServantBase::_dispatch (TAO_ServerRequest &,
                                  void *
                                  ACE_ENV_ARG_DECL)
{
  ACE_THROW (CORBA::BAD_OPERATION ());
}
