#include "Regular_POA.h"

ACE_RCSID (PortableServer,
           POA,
           "$Id$")

//
#if !defined (__ACE_INLINE__)
# include "Regular_POA.inl"
#endif /* ! __ACE_INLINE__ */

TAO_Regular_POA::TAO_Regular_POA (const TAO_Root_POA::String &name,
                  TAO_POA_Manager &poa_manager,
                  const TAO_POA_Policy_Set &policies,
                  TAO_Root_POA *parent,
                  ACE_Lock &lock,
                  TAO_SYNCH_MUTEX &thread_lock,
                  TAO_ORB_Core &orb_core,
                  TAO_Object_Adapter *object_adapter
                  ACE_ENV_ARG_DECL)
  : TAO_Root_POA (name,
                  poa_manager,
                  policies,
                  parent,
                  lock,
                  thread_lock,
                  orb_core,
                  object_adapter
                  ACE_ENV_ARG_PARAMETER),
     parent_ (parent)
{
}

TAO_Regular_POA::~TAO_Regular_POA (void)
{
}

void
TAO_Regular_POA::remove_from_parent_i (ACE_ENV_SINGLE_ARG_DECL)
{
  // Remove POA from the parent
  if (this->parent_ != 0)
    {
      int result = this->parent_->delete_child (this->name_);
      if (result != 0)
        {
          ACE_THROW (CORBA::OBJ_ADAPTER ());
        }
    }
}

CORBA::Boolean
TAO_Regular_POA::root (void) const
{
  return (parent_ == 0);
}

char
TAO_Regular_POA::root_key_type (void)
{
  if (this->parent_ != 0)
    {
      return TAO_Root_POA::non_root_key_char ();
    }
  else
    {
      return TAO_Root_POA::root_key_type ();
    }
}
