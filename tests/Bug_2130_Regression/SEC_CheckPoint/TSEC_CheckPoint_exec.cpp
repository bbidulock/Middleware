//$Id$

//-------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------

#include "ace/Timer_Queue.h"
#include "ace/Reactor.h"

#include "tao/LocalObject.h"
#include <orbsvcs/CosNamingC.h>

#include "ciao/CIAO_common.h"
#include "ciao/Version.h"

#include "TSEC_CheckPoint_exec.h"
#include "TSEC_CheckPoint_svnt.h"


//-------------------------------------------------------------------
// Defines
//-------------------------------------------------------------------

#define SEPARATION_LINE "----------------------------------------" \
                        "----------------------------------------\n"


//-------------------------------------------------------------------
// Statics
//-------------------------------------------------------------------

static char* argv[] =
{
  "TSEC_CheckPoint"
};


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_SessionEntry::TSEC_SessionEntry()
: _p_sessionImpl( 0 )
{
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_SessionEntry::TSEC_SessionEntry
(
  TSEC_Session_impl* pSessionImpl,
  ENW::TSession_ptr  Session
)
: _p_sessionImpl( pSessionImpl )
{
  if( !CORBA::is_nil( Session ) )
  {
    _session = ENW::TSession::_duplicate( Session );
  }
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_Session_impl::TSEC_Session_impl
(
  TSEC_CheckPoint_exec_i& Parent,
  CORBA::Long             Ident
)
  : _isInUse(0),_ident( Ident ),_parent( Parent )
{
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_Session_impl::~TSEC_Session_impl()
{
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

CORBA::ULong
Impl::TSEC_Session_impl::hash
(
  CORBA::ULong Maximum
  ACE_ENV_ARG_DECL_NOT_USED
)
{
  CORBA::ULong hash =
       ACE_static_cast( CORBA::ULong, ACE_reinterpret_cast( ptrdiff_t, this ) );

  return hash % Maximum;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

CORBA::Long
Impl::TSEC_Session_impl::getIdent
(
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  //ACE_GUARD_RETURN( TMutex, guard, _parent.getMutex(), -1 );

  return _ident;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

CORBA::Boolean
Impl::TSEC_Session_impl::isInUse
(
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  //ACE_GUARD_RETURN( TMutex, guard, _parent.getMutex(), FALSE );
  return _isInUse;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_CheckPoint_exec_i::TSEC_CheckPoint_exec_i()
: _p_sessionContainer( 0 ),
  _isActivated( false )
{
  ACE_DEBUG( ( LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::"
                         "TSEC_CheckPoint_exec_i\n" ) );

  this->init();
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_CheckPoint_exec_i::TSEC_CheckPoint_exec_i
(
  const char* /*Version*/
)
: _p_sessionContainer( 0 ),
  _isActivated( false )
{
  ACE_DEBUG( ( LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::"
                         "TSEC_CheckPoint_exec_i\n" ) );
  this->init();
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_CheckPoint_exec_i::~TSEC_CheckPoint_exec_i()
{
  ACE_DEBUG( ( LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::"
                         "~TSEC_CheckPoint_exec_i\n" ) );
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

CORBA::Object_ptr
Impl::TSEC_CheckPoint_exec_i::getObjRef
(
  PortableServer::Servant Servant
  ACE_ENV_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( (CORBA::SystemException ) )
{
  return this->_p_sessionContainer->get_objref( Servant ACE_ENV_ARG_PARAMETER );
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

int
Impl::TSEC_CheckPoint_exec_i::init
(
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  ACE_DEBUG ((LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::init\n"));

  int argc = sizeof( argv ) / sizeof( argv[0] );

  CORBA::ORB_var orb = CORBA::ORB_init( argc, argv ACE_ENV_ARG_PARAMETER );
  _orb               = CORBA::ORB::_duplicate( orb.in () );

  return 0;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

CORBA::Object_ptr
Impl::TSEC_CheckPoint_exec_i::installServant
(
  PortableServer::Servant Servant
  ACE_ENV_ARG_DECL
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  assert( this->_p_sessionContainer );

  return this->_p_sessionContainer->install_servant( Servant,
                             CIAO::Container::Component ACE_ENV_ARG_PARAMETER );
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

void
Impl::TSEC_CheckPoint_exec_i::uninstallServant
(
  CORBA::Object_ptr ObjRef
  ACE_ENV_ARG_DECL
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  assert( this->_p_sessionContainer );

  this->_p_sessionContainer->uninstall( ObjRef, CIAO::Container::Component );
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

ENW::TSession_ptr
Impl::TSEC_CheckPoint_exec_i::createSession
(
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  static long cnt = 0L;

  ENW::TSession_var session = ENW::TSession::_nil();

  ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::createSession...\n" ) );

  TSEC_Session_impl* p_sessionImpl = new TSEC_Session_impl( *this, ++cnt );
  PortableServer::ServantBase_var safe_servant( p_sessionImpl );
  CORBA::Object_var obj = this->installServant( p_sessionImpl
                                                ACE_ENV_ARG_PARAMETER );
  session = ENW::TSession::_narrow ( obj.in () ACE_ENV_ARG_PARAMETER );

  ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::createSession...[DONE]\n" ) );

  return session._retn();
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

::CORBA::Boolean
Impl::TSEC_CheckPoint_exec_i::destroySession
(
  ENW::TSession_ptr Session
  ACE_ENV_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::destroySession...\n" ) );

  if( CORBA::is_nil( Session ) )
  {
    ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::destroySession...[ERROR]\n" ) );
    return 0;
  }

  this->uninstallServant( Session );

  return 1;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

ENW::TSession_ptr
Impl::TSEC_CheckPoint_exec_i::acquireSession
(
  CORBA::Long Ident
  ACE_ENV_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    ENW::EUnknownIdent ) )
{
  ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::acquireSession...\n" ) );

  if( Ident <= 0  ||  Ident > TSEC_SESSION_MAX_IDENT )
  {
    if( Ident != -1 )
    {
      ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::releaseSession...[ERROR]\n" ) );
      throw ENW::EUnknownIdent();
    }
  }

  ENW::TSession_var  session = ENW::TSession::_nil();
  TSEC_Session_impl* p_sessionImpl = 0;

  ACE_TRY_NEW_ENV
  {
    {
      //ACE_GUARD_RETURN( TMutex, guard, _mutex, ENW::TSession::_nil() );
      p_sessionImpl = sessionVector[Ident-1]._p_sessionImpl;
    }

    p_sessionImpl->isInUse( 1 );
    //CORBA::Object_var obj = this->getObjRef( p_sessionImpl) ;
    //session = ENW::TSession::_narrow ( obj.in () ACE_ENV_ARG_PARAMETER );
    session = sessionVector[Ident-1]._session;
  }
  ACE_CATCHANY
  {
    ACE_PRINT_EXCEPTION( ACE_ANY_EXCEPTION, "Reason\n" );
    ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::releaseSession...[ERROR]\n" ) );

    return session._retn();
  }
  ACE_ENDTRY;

  ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::releaseSession...[DONE]\n" ) );

  return session._retn();
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

::CORBA::Boolean
Impl::TSEC_CheckPoint_exec_i::releaseSession
(
  CORBA::Long Ident,
  ENW::TSession_ptr Session
  ACE_ENV_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    ENW::EUnknownSession ) )
{
  ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::releaseSession...\n" ) );

  if( CORBA::is_nil( Session ) )
  {
    ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::releaseSession...[ERROR]\n" ) );
    throw ENW::EUnknownSession();
  }

  //CORBA::Long ident = Session->getIdent();
  CORBA::Long ident = Ident;

  if( ident <= 0  ||  ident > TSEC_SESSION_MAX_IDENT )
  {
    ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::releaseSession...[ERROR]\n" ) );
    return 0;;
  }

  TSEC_Session_impl* p_sessionImpl = 0;

  {
    //ACE_GUARD_RETURN( TMutex, guard, _mutex, FALSE );

    p_sessionImpl = sessionVector[ident-1]._p_sessionImpl;
  }

  assert( p_sessionImpl );


  if( !p_sessionImpl->isInUse() )
  {
    ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::releaseSession...[ERROR]\n" ) );
    return 0;
  }

  p_sessionImpl->isInUse( 0);

  ACE_DEBUG( ( LM_DEBUG, "(%P|%t@%T) TSEC_CheckPoint_exec_i::releaseSession...[DONE]\n" ) );

  return 1;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

ENW::CCM_ISessionService_ptr
Impl::TSEC_CheckPoint_exec_i::get_sessionService
(
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  return ENW::CCM_ISessionService::_duplicate( this );
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

void
Impl::TSEC_CheckPoint_exec_i::set_session_context
(
  Components::SessionContext_ptr Ctx
  ACE_ENV_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    Components::CCMException ) )
{
  ACE_DEBUG( ( LM_DEBUG,
               "Impl::TSEC_CheckPoint_exec_i::set_session_context\n" ) );

  this->_context =
    ENW::CCM_TSEC_CheckPoint_Context::_narrow( Ctx
                                               ACE_ENV_ARG_PARAMETER );
  ACE_CHECK;

  if( CORBA::is_nil( this->_context.in() ) )
  {
    ACE_THROW( CORBA::INTERNAL() );
  }

  CIDL_TSEC_CheckPoint_Impl::TSEC_CheckPoint_Context* p_checkPoint_Context =
             CIDL_TSEC_CheckPoint_Impl::TSEC_CheckPoint_Context::_narrow( Ctx );

  if( !p_checkPoint_Context )
  {
    ACE_THROW( CORBA::INTERNAL() );
  }

  this->_p_sessionContainer = p_checkPoint_Context->_ciao_the_Container();

  if( !_p_sessionContainer )
  {
    ACE_THROW( CORBA::INTERNAL() );
  }
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

void
Impl::TSEC_CheckPoint_exec_i::push_lifeTokenIn
(
  ENW::ET_LifeToken* /* Event */
  ACE_ENV_ARG_DECL_WITH_DEFAULTS
) ACE_THROW_SPEC( ( CORBA::SystemException ) )
{
  _awaitingLifeToken = false;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

void
Impl::TSEC_CheckPoint_exec_i::ciao_preactivate
(
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    Components::CCMException ) )
{
  ACE_DEBUG( ( LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::ciao_preactivate\n" ) );
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

void
Impl::TSEC_CheckPoint_exec_i::ccm_activate
(
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    Components::CCMException ) )
{
  ACE_DEBUG( ( LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::ccm_activate\n" ) );

  TSEC_Session_impl* p_sessionImpl = 0;

  for( CORBA::Long i = 0; i < TSEC_SESSION_MAX_IDENT; ++i )
  {
    p_sessionImpl = new TSEC_Session_impl( *this, i + 1 );
    PortableServer::ServantBase_var safe_servant( p_sessionImpl );
    CORBA::Object_var obj = this->installServant( p_sessionImpl
                                                  ACE_ENV_ARG_PARAMETER );
    ENW::TSession_var session =
                     ENW::TSession::_narrow ( obj.in () ACE_ENV_ARG_PARAMETER );
    sessionVector[i] = TSEC_SessionEntry( p_sessionImpl, session.in () );
  }

  _isActivated = true;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

void
Impl::TSEC_CheckPoint_exec_i::ciao_postactivate
(
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    Components::CCMException ) )
{
  ACE_DEBUG( ( LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::ciao_postactivate\n" ) );
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

void
Impl::TSEC_CheckPoint_exec_i::ccm_passivate
(
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    Components::CCMException ) )
{
  ACE_DEBUG( ( LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::ccm_passivate\n" ) );
  _isActivated = false;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

void
Impl::TSEC_CheckPoint_exec_i::ccm_remove
(
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    Components::CCMException ) )
{
  ACE_DEBUG( ( LM_DEBUG, "Impl::TSEC_CheckPoint_exec_i::ccm_remove\n" ) );
  _isActivated = false;
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_CheckPointHome_exec_i::TSEC_CheckPointHome_exec_i()
{
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

Impl::TSEC_CheckPointHome_exec_i::~TSEC_CheckPointHome_exec_i()
{
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

::Components::EnterpriseComponent_ptr
Impl::TSEC_CheckPointHome_exec_i::new_TSEC_CheckPoint
(
  const char* Version
  ACE_ENV_ARG_DECL_WITH_DEFAULTS
  ) ACE_THROW_SPEC( ( CORBA::SystemException ))
{
  return new Impl::TSEC_CheckPoint_exec_i( Version );
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

::Components::EnterpriseComponent_ptr
Impl::TSEC_CheckPointHome_exec_i::create
(
  ACE_ENV_SINGLE_ARG_DECL
) ACE_THROW_SPEC( ( CORBA::SystemException,
                    Components::CCMException ) )
{

  return new Impl::TSEC_CheckPoint_exec_i();
}


//-------------------------------------------------------------------
// Operation
//-------------------------------------------------------------------

extern "C" TSEC_CHECKPOINT_EXEC_Export ::Components::HomeExecutorBase_ptr
createTSEC_CheckPointHome_Impl()
{
  return new Impl::TSEC_CheckPointHome_exec_i();
}

