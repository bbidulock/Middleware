// $Id$

#include "ace/MC_Generic_Registry.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    MC_Generic_Registry::MapError::MapError (ErrorReason why)
      : why_ (why)
    {}

    MC_Generic_Registry::MC_Generic_Registry (void)
    {}

    MC_Generic_Registry::~MC_Generic_Registry (void)
    {}

    bool
    MC_Generic_Registry::add (MC_Generic* type)
    {
      if (type == 0)
        {
          throw MapError (MapError::MAP_ERROR_INVALID_VALUE);
        }

      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, false);

      int const status = this->map_.bind (type->name (), type);

      if (status == -1)
        {
          throw MapError (MapError::MAP_ERROR_BIND_FAILURE);
        }

      return (status == 0);
    }

    MC_Generic*
    MC_Generic_Registry::getobj (const ACE_CString& name) const
    {
      ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->mutex_, 0);
      Map::data_type type = 0;
      this->map_.find (name, type);
      return type;
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

