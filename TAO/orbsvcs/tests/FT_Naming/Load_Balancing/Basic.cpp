// $Id$

#include "Basic.h"
#include "LB_server.h"

Basic::Basic (CORBA::Object_ptr object_group,
              FT::NamingManager_ptr lm,
              CORBA::ORB_ptr orb,
              const char *loc)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
  this->object_group_ = CORBA::Object::_duplicate (object_group);
  this->lm_ = FT::NamingManager::_duplicate (lm);
  this->location_ = CORBA::string_dup (loc);
}

char *
Basic::get_string (void)
{
  return CORBA::string_dup (this->location_.in ());
}

void
Basic::remove_member (void)
{
  try
    {
      PortableGroup::Location location (1);
      location.length (1);
      location[0].id = CORBA::string_dup (this->location_.in ());
      this->lm_->remove_member (this->object_group_.in (),
                                location);

      ACE_DEBUG ((LM_DEBUG, "(%P|%t) - Removed Member at Location <%s>\n",
                      this->location_.in ()));

    }
  catch (const PortableGroup::ObjectNotFound& ex)
    {
      ex._tao_print_exception ("Caught exception in remove_member");
      throw CORBA::INTERNAL ();
    }
  catch (const PortableGroup::MemberNotFound& ex)
    {
      ex._tao_print_exception ("Caught exception in remove_member");
      throw CORBA::INTERNAL ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught while destroying member\n");
    }

}

void
Basic::shutdown (void)
{
  this->orb_->shutdown (0);
}
