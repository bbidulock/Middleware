// $Id$

#include "tao/corba.h"
#include "reactor_i.h"

ACE_RCSID(Reactor, reactor_i, "$Id$")

// CTOR
Reactor_i::Reactor_i (void)
  :  quiet_ (0)
{
}

// DTOR
Reactor_i::~Reactor_i (void)
{
}

void
Reactor_i::be_quiet (int quiet)
{
  this->quiet_ = quiet;
}

// register...with nothing
CORBA::Long
Reactor_i::register_handler (EventHandler_ptr eh,
                             CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (!this->quiet_)
    ACE_DEBUG ((LM_DEBUG,
                "(%P|%t) BEGIN Reactor_i::register_handler ()\n"));

  CORBA::Long r = 0;

  TAO_TRY
    {
      r = eh->peer (TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("getting peer");
    }
  TAO_ENDTRY;

  if (!this->quiet_)
    ACE_DEBUG ((LM_DEBUG,
                "(%P|%t) got this value from peer: %d\n",
                r));

  if (!this->quiet_)
    ACE_DEBUG ((LM_DEBUG,
                "(%P|%t) END Reactor_i::register_handler ()\n"));

  return 0;
}

void
Reactor_i::set_value (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (!this->quiet_)
    ACE_DEBUG ((LM_DEBUG,
                "(%P|%t) doing Reactor_i::set_value()\n"));
}

CORBA::UShort
Reactor_i::decrement (EventHandler_ptr eh,
                      CORBA::UShort num,
                      CORBA::Environment &env)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (!this->quiet_)
    ACE_DEBUG ((LM_DEBUG, "%{%I(%P|%t) Reactor::decrement (%d)%$", num));

  CORBA::UShort ret;
  if (--num <= 0)
    ret = 0;
  else
    {
      if (!this->quiet_)
        ACE_DEBUG ((LM_DEBUG,
                    "(%P|%t) Reactor::decrement() "
                    "invoking EventHandler::decrement(%d)%$", num));

      Reactor_var me = _this (env);
      ret = eh->decrement (me.in (), num, env);
    }

  if (!this->quiet_)
    ACE_DEBUG ((LM_DEBUG,
                "%}(%P|%t) Reactor::decrement() "
                "returning %d\n", ret));

  return ret;
}

void
Reactor_i::stop (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ TODO Keep an ORB pointer around...
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) stopping.\n"));
  TAO_ORB_Core_instance ()->orb ()->shutdown ();
}
