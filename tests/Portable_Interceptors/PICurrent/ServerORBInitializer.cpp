// -*- C++ -*-

#include "ServerORBInitializer.h"
#include "ServerRequestInterceptor.h"

ACE_RCSID (PICurrent,
           ServerORBInitializer,
           "$Id$")

PortableInterceptor::SlotId slot_id = 2093843221;

void
ServerORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr /* info */
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
ServerORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr info
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Object_var obj =
    info->resolve_initial_references ("PICurrent"
                                      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  PortableInterceptor::Current_var pi_current =
    PortableInterceptor::Current::_narrow (obj.in ()
                                           ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (CORBA::is_nil (pi_current.in ()))
    {
      ACE_ERROR ((LM_ERROR,
                  "(%P|%t) ERROR: Could not resolve PICurrent object.\n"));

      ACE_THROW (CORBA::INTERNAL ());
    }

  ::slot_id = info->allocate_slot_id (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  PortableInterceptor::ServerRequestInterceptor_ptr tmp;
  ACE_NEW_THROW_EX (tmp,
                    ServerRequestInterceptor (::slot_id,
                                              pi_current.in ()),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK;

  PortableInterceptor::ServerRequestInterceptor_var interceptor = tmp;

  info->add_server_request_interceptor (interceptor.in ()
                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}
