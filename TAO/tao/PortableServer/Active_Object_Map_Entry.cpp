// $Id$

#include "Active_Object_Map_Entry.h"

ACE_RCSID(tao, Active_Object_Map_Entry, "$Id$")

TAO_Active_Object_Map_Entry::TAO_Active_Object_Map_Entry (void)
  : user_id_ (),
    system_id_ (),
    servant_ (0),
    reference_count_ (1),
    deactivated_ (0),
    priority_ (-1)
{
}

