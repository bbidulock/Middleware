// $Id$

#include "Notify_Worker_Task.h"
#include "Notify_Command.h"
#include "Notify_AdminProperties.h"
#include "Notify_QoSAdmin_i.h"

ACE_RCSID(Notify, Notify_Worker_Task, "$Id$")

TAO_Notify_Worker_Task::TAO_Notify_Worker_Task (void)
{
}

TAO_Notify_Worker_Task::~TAO_Notify_Worker_Task ()
{
}

int
TAO_Notify_Worker_Task::init_task (TAO_Notify_AdminProperties* const,
                                   TAO_Notify_QoSAdmin_i* const)
{
  return 0;
}

void
TAO_Notify_Worker_Task::shutdown (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
}

int
TAO_Notify_Worker_Task::process_event (TAO_Notify_Command *mb ACE_ENV_ARG_DECL, ACE_Time_Value * /*tv*/)
{
  int result = mb->execute (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  ACE_Message_Block::release (mb);
  return result;
}

void
TAO_Notify_Worker_Task::update_admin (TAO_Notify_AdminProperties& /*admin*/)
{
}

void
TAO_Notify_Worker_Task::update_qos (TAO_Notify_QoSAdmin_i& /*qos_admin*/)
{
}

