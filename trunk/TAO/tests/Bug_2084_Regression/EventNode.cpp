//
// $Id$
//
#include "EventNode.h"
#include "tao/ORB_Core.h"
#include "tao/ORB_Table.h"

ACE_RCSID(EventNode, EventNode, "$Id$")

EventNode::EventNode (CORBA::ORB_ptr orb,
                      ACE_thread_t thrid)
  : orb_ (CORBA::ORB::_duplicate (orb))
    , thr_id_ (thrid)
{
}

void EventNode::registerHello ( ::Test::Hello_ptr h )
{
  ACE_DEBUG ((LM_DEBUG,
              "(%P|%t) EventNode: registerHello will call get_string...\n"));

  if (ACE_Thread::self () == this->thr_id_)
    {
      if (this->orb_->orb_core ()->optimize_collocation_objects () &&
          this->orb_->orb_core ()->use_global_collocation ())
        {
          ACE_ERROR ((LM_ERROR,
                      "(%P|%t) ERROR: A remote call has been made "
                      " exiting ..\n"));
          ACE_OS::abort ();
        }
      else if (this->orb_->orb_core ()->optimize_collocation_objects () &&
               this->orb_->orb_core ()->use_global_collocation () == 0)
        {
          TAO::ORB_Table * const orb_table =
            TAO::ORB_Table::instance ();

          if (orb_table->find ("server_orb") == 0)
            {
              // We are running on a single ORB and this is an error.
              ACE_ERROR ((LM_ERROR,
                          "(%P|%t) ERROR: A remote call has been made "
                          " with a single ORB "
                          " exiting ..\n"));
              ACE_OS::abort ();
            }
        }
    }

  CORBA::String_var str =
    h->get_string (static_cast<CORBA::Long> ((size_t)ACE_Thread::self ()));
  ACE_DEBUG ((LM_DEBUG,
              "(%P|%t) - EventNode: string returned <%s>\n",
              str.in ()));
}

void
EventNode::shutdown (void)
{
  this->orb_->shutdown (0);
}
