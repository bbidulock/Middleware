// -*- C++ -*-

#include "Current_Test_Impl.h"

#include "orbsvcs/Transport_Current/TC_IIOPC.h"
#include "orbsvcs/Transport_Current/TCC.h"

ACE_RCSID (Transport_Current,
           Current_Test_Impl,
           "$Id:$")


Current_Test_Impl::Current_Test_Impl (CORBA::ORB_ptr orb,
                                      PortableServer::POA_ptr poa,
                                      int do_collocated_calls)
    : orb_ (CORBA::ORB::_duplicate (orb))
    , poa_ (PortableServer::POA::_duplicate (poa))
    , do_collocated_calls_ (do_collocated_calls)
{
}

Current_Test_Impl::~Current_Test_Impl (void)
{
}

::CORBA::Long
Current_Test_Impl::self_test (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((::CORBA::SystemException))
{
  return 0;
}

void
Current_Test_Impl::test_transport_current (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (TAO_debug_level > 2) {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) server - Testing access to IIOP Transport Current ...\n")));
  }

  CORBA::Object_var tcobject =
    this->orb_->resolve_initial_references ("TAO::Transport::IIOP::Current"
                                            ACE_ENV_ARG_PARAMETER);
  ACE_TRY_CHECK;

  TAO::Transport::IIOP::Current_var tc =
    TAO::Transport::IIOP::Current::_narrow (tcobject.in ()
                                            ACE_ENV_SINGLE_ARG_DECL);
  ACE_TRY_CHECK;

  if (CORBA::is_nil (tc.in()))
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("Unable to narrow down to TAO::Transport::IIOP::Current\n")));
      ACE_THROW (CORBA::INTERNAL ());
    }

  CORBA::String_var rhost (tc->remote_host ());
  CORBA::String_var lhost (tc->local_host ());
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%P|%t) server - [%s:%d] -> [%s:%d]\n"),
              rhost.in (), tc->remote_port (),
              lhost.in (), tc->local_port ()));

  if (TAO_debug_level > 2) {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) server - Successfully accessed IIOP Transport Current\n")));
  }
}



void
Current_Test_Impl::invoked_by_client (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (TAO_debug_level >= 1) {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) server - Test method invoked by client.\n")));
  }

  this->test_transport_current (ACE_ENV_SINGLE_ARG_DECL);
  ACE_TRY_CHECK;

  if (this->do_collocated_calls_)
    {
      CORBA::Object_var selfobject =
        poa_->servant_to_reference (this
                                    ACE_ENV_SINGLE_ARG_DECL);
      ACE_TRY_CHECK;

      TAO::Transport::CurrentTest_var self =
        TAO::Transport::CurrentTest::_narrow (selfobject.in ()
                                               ACE_ENV_SINGLE_ARG_DECL);
      ACE_TRY_CHECK;

      if (TAO_debug_level >= 1) {
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("(%P|%t) server - Making a collocated invocation to invoked_during_upcall().\n")));
      }
      self->invoked_during_upcall (ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  else
    {
      if (TAO_debug_level >= 1)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("(%P|%t) server - skipping collocated calls\n")));
        }

    }

}

void
Current_Test_Impl::invoked_during_upcall (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (TAO_debug_level > 2) {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) server - Test method invoked ")
                ACE_TEXT ("by the server during upcall.\n")));
  }
}

void
Current_Test_Impl::shutdown (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (TAO_debug_level > 2) {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) server - shutting down.\n")));
  }

  this->orb_->shutdown (0
                        ACE_ENV_ARG_PARAMETER);
}
