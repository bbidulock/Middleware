//$Id$

#include "Sender_exec_2.h"

char*
Sender_Impl::Message_Impl_2::get_message (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG, "Sender sending out message. \n"));
  return CORBA::string_dup (component_.message_.in ());
}

Sender_Impl::Sender_exec_2_i::~Sender_exec_2_i ()
{
}

void
Sender_Impl::Sender_exec_2_i::local_message (const char * local_message
                                           ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  message_ = CORBA::string_dup (local_message);
}

char *
Sender_Impl::Sender_exec_2_i::local_message (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::string_dup(message_);
}

Hello::CCM_ReadMessage_ptr
Sender_Impl::Sender_exec_2_i::get_push_message (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG, 
              "Sender_Impl::Sender_exec.i::get_push_message called\n "));
  return ( new Message_Impl_2 (*this) );
}

void
Sender_Impl::Sender_exec_2_i::start (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Hello::TimeOut_var event = new OBV_Hello::TimeOut;
  ACE_DEBUG ((LM_DEBUG, "Sender initiates the process.\n"));
  this->context_->push_click_out (event ACE_ENV_ARG_PARAMETER);
}

void
Sender_Impl::Sender_exec_2_i::set_session_context 
   (Components::SessionContext_ptr ctx
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  ACE_DEBUG ((LM_DEBUG, "Sender_Impl::Sender_exec_2_i::set_session_context\n"));

  this->context_ =
        Sender_Impl::Sender_Exec_Context::_narrow (ctx
                                                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (CORBA::is_nil (this->context_.in ()))
       ACE_THROW (CORBA::INTERNAL ());
}

void
Sender_Impl::Sender_exec_2_i::ciao_preactivate (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  ACE_DEBUG ((LM_DEBUG,
              "Sender_Impl::Sender_exec_2_i::ciao_preactivate\n"));
}

void
Sender_Impl::Sender_exec_2_i::ccm_activate (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  ACE_DEBUG ((LM_DEBUG,
              "Sender_Impl::Sender_exec_2_i::ccm_activate\n"));
}

void
Sender_Impl::Sender_exec_2_i::ciao_postactivate (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  ACE_DEBUG ((LM_DEBUG,
              "Sender_Impl::Sender_exec_2_i::ciao_postactivate\n"));
}

void
Sender_Impl::Sender_exec_2_i::ccm_passivate (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  ACE_DEBUG ((LM_DEBUG, "Sender_Impl::Sender_exec_2_i::ccm_passivate\n"));
  ACE_DEBUG ((LM_DEBUG, "2 being removed\n"));
}

void
Sender_Impl::Sender_exec_2_i::ccm_remove (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  ACE_DEBUG ((LM_DEBUG, "Sender_Impl::Sender_exec_2_i::ccm_remove\n"));
}

extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
createSenderExec_Impl (void)
{
  return new Sender_Impl::Sender_exec_2_i ();
}
