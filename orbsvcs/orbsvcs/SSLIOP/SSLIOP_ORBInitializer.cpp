// -*- C++ -*-
//
// $Id$

#include "SSLIOP_ORBInitializer.h"

ACE_RCSID (TAO_SSLIOP, SSLIOP_ORBInitializer, "$Id$")

#include "SSLIOP_Current.h"
#include "SSLIOP_Invocation_Interceptor.h"
#include "orbsvcs/SSLIOPC.h"
#include "tao/Exception.h"
#include "tao/ORBInitInfo.h"

TAO_SSLIOP_ORBInitializer::TAO_SSLIOP_ORBInitializer (int no_protection)
  : no_protection_ (no_protection)
{
}

void
TAO_SSLIOP_ORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr
    TAO_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
TAO_SSLIOP_ORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr info
    TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_ENV_ARG_DEFN;

  // Narrow to a TAO_ORBInitInfo object to get accss to the
  // allocate_tss_slot_id() TAO extension.
  TAO_ORBInitInfo *tao_info = TAO_ORBInitInfo::_narrow (info,
                                                        ACE_TRY_ENV);
  ACE_CHECK;

  if (tao_info == 0)
    {
      if (TAO_debug_level > 0)
        ACE_ERROR ((LM_ERROR,
                    "(%P|%t) SSLIOP_ORBInitializer::post_init:\n"
                    "(%P|%t)    Unable to narrow "
                    "\"PortableInterceptor::ORBInitInfo_ptr\" to\n"
                    "(%P|%t)   \"TAO_ORBInitInfo *.\"\n"));

      ACE_THROW (CORBA::INTERNAL ());
    }

  // Reserve a TSS slot in the ORB core internal TSS resources for the
  // thread-specific portion of SSLIOP::Current.
  size_t tss_slot = tao_info->allocate_tss_slot_id (0,
                                                    ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::String_var orb_id = info->orb_id (ACE_TRY_ENV);
  ACE_CHECK;

  // Create the SSLIOP::Current object.
  SSLIOP::Current_ptr current = SSLIOP::Current::_nil ();
  ACE_NEW_THROW_EX (current,
                    TAO_SSLIOP_Current (tss_slot, orb_id.in ()),
                    CORBA::NO_MEMORY (
                      CORBA_SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK;

  SSLIOP::Current_var ssliop_current = current;

  // Register the SSLIOP::Current object reference with the ORB.
  info->register_initial_reference ("SSLIOPCurrent",
                                    ssliop_current.in (),
                                    ACE_TRY_ENV);
  ACE_CHECK;

  // Create the SSLIOP secure invocation server request interceptor.
  PortableInterceptor::ServerRequestInterceptor_ptr si =
    PortableInterceptor::ServerRequestInterceptor::_nil ();
  ACE_NEW_THROW_EX (si,
                    TAO_SSLIOP_Server_Invocation_Interceptor (
                      ssliop_current.in (),
                      this->no_protection_),
                    CORBA::NO_MEMORY (
                      CORBA_SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK;

  PortableInterceptor::ServerRequestInterceptor_var si_interceptor =
    si;

  // Register the SSLIOP secure invocation server request interceptor
  // with the ORB.
  info->add_server_request_interceptor (si_interceptor.in (),
                                        ACE_TRY_ENV);
  ACE_CHECK;
}
