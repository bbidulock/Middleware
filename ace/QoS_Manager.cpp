// QoS_Manager.cpp
// $Id$

#define ACE_BUILD_DLL
#include "ace/QoS_Manager.h"

ACE_RCSID(ace, QoS_Manager, "$Id $")

ACE_ALLOC_HOOK_DEFINE(ACE_QOS_MANAGER)

ACE_QoS_Manager::ACE_QoS_Manager (void)
{}

ACE_QoS_Manager::~ACE_QoS_Manager (void)
{}

// Adds the given session to the list of session objects joined by
// this socket.

int 
ACE_QoS_Manager::join_qos_session (ACE_QoS_Session *qos_session)
{
  if (this->qos_session_set ().insert (qos_session) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error in adding a new session to the "
                       "socket session set\n"),
                      -1);
  return 0;
}

// Returns the QoS session set for this socket.

ACE_Unbounded_Set <ACE_QoS_Session *>
ACE_QoS_Manager::qos_session_set (void)
{
  return this->qos_session_set_;
}


