// $Id$

#include "UpdateableHandler.h"
#include "Update_Manager.h"
#include "AMI_Primary_Replication_Strategy.h"
#include "../Utils/resolve_init.h"
#include "../Utils/Log.h"

ACE_RCSID (EventChannel,
           UpdateableHandler,
           "$Id$")


UpdateableHandler::UpdateableHandler(AMI_Primary_Replication_Strategy* strategy)
: strategy_(strategy)
{
}

UpdateableHandler::~UpdateableHandler()
{
}

FTRT::AMI_UpdateableHandler_ptr UpdateableHandler::activate(
  Update_Manager* mgr, int id,
  PortableServer::ObjectId& object_id
  ACE_ENV_ARG_DECL)
{
  object_id.length(sizeof(mgr) + sizeof(id));
  memcpy(object_id.get_buffer(), &mgr, sizeof(mgr));
  memcpy(object_id.get_buffer() + sizeof(mgr), &id, sizeof(id));
  strategy_->poa()->activate_object_with_id(object_id,
                                            this
                                            ACE_ENV_ARG_PARAMETER);
  CORBA::Object_var object = strategy_->poa()->id_to_reference(
    object_id
    ACE_ENV_ARG_PARAMETER);

  return FTRT::AMI_UpdateableHandler::_narrow(object.in() ACE_ENV_ARG_PARAMETER);
}



void UpdateableHandler::dispatch(UpdateableHandler::Handler handler ACE_ENV_ARG_DECL)
{
  PortableServer::Current_var current =
    resolve_init<PortableServer::Current>(strategy_->orb(),
    "POACurrent"
    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  PortableServer::ObjectId_var object_id =
    current->get_object_id(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  Update_Manager* mgr;
  int id;

  memcpy(&mgr, object_id->get_buffer(), sizeof(mgr));
  memcpy(&id, object_id->get_buffer()+sizeof(mgr), sizeof(id));

  TAO_FTRTEC::Log(3, "%d\n", id);

  (mgr->*handler)(id);

  strategy_->poa()->deactivate_object(object_id.in());
}

void UpdateableHandler::set_update (
                                    ACE_ENV_SINGLE_ARG_DECL
                                    )
                                    ACE_THROW_SPEC ((
                                    CORBA::SystemException
                                    ))
{
  TAO_FTRTEC::Log(3,"Received reply from ");
  dispatch(&Update_Manager::handle_reply ACE_ENV_ARG_PARAMETER);
}
void UpdateableHandler::set_update_excep (
  FTRT::AMI_UpdateableExceptionHolder * excep_holder
  ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
  CORBA::SystemException
  ))
{
  TAO_FTRTEC::Log(3, "Received Exception from");
  ACE_TRY {
    excep_holder->raise_set_update();
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {
    ACE_PRINT_EXCEPTION(ACE_ANY_EXCEPTION, "A corba exception\n");
  }
  ACE_ENDTRY;

  dispatch(&Update_Manager::handle_exception ACE_ENV_ARG_PARAMETER);
}
