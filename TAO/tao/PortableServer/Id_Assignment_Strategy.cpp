// $Id$

#include "Id_Assignment_Strategy.h"

ACE_RCSID (PortableServer,
           Id_Assignment_Strategy,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    Id_Assignment_Strategy::~Id_Assignment_Strategy (void)
    {
    }

    void
    Id_Assignment_Strategy::strategy_init (TAO_POA *)
    {
      // dependent on type create the correct strategy.
    }

    char
    Id_Assignment_Strategy::key_type_length (void) const
    {
      return sizeof (char);
    }

    void
    Id_Assignment_Strategy::create_key (
      CORBA::Octet *buffer,
      CORBA::ULong& starting_at)
    {
      // Copy the system id byte.
      buffer[starting_at] = (CORBA::Octet) this->id_assignment_key_type ();
      starting_at += this->key_type_length ();
    }

    //============================================================

    User_Id_Assignment_Strategy::~User_Id_Assignment_Strategy()
    {
    }

    char
    User_Id_Assignment_Strategy::id_assignment_key_type (void) const
    {
      return 'U';
    }

    //============================================================

    System_Id_Assignment_Strategy::~System_Id_Assignment_Strategy()
    {
    }

    char
    System_Id_Assignment_Strategy::id_assignment_key_type (void) const
    {
      return 'S';
    }

  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */
