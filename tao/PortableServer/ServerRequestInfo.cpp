// -*- C++ -*-
//
// $Id$

#include "ServerRequestInfo.h"

#include "tao/TAO_Server_Request.h"

ACE_RCSID (PortableServer, ServerRequestInfo, "$Id$")

#if (TAO_HAS_INTERCEPTORS == 1)

# if !defined (__ACE_INLINE__)
#   include "ServerRequestInfo.inl"
# endif /* !__ACE_INLINE__ */

TAO_ServerRequestInfo::TAO_ServerRequestInfo (
  TAO_ServerRequest &server_request)
  : server_request_ (server_request),
    caught_exception_ (0),
    reply_status_ (-1)
{
}

CORBA::ULong
TAO_ServerRequestInfo::request_id (CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->server_request_.request_id ();
}

char *
TAO_ServerRequestInfo::operation (CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::string_dup (this->server_request_.operation ());
}

Dynamic::ParameterList *
TAO_ServerRequestInfo::arguments (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Need the minor code once it becomes available.
  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (), 0);
}

Dynamic::ExceptionList *
TAO_ServerRequestInfo::exceptions (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Need the minor code once it becomes available.
  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (), 0);
}

Dynamic::ContextList *
TAO_ServerRequestInfo::contexts (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Need the minor code once it becomes available.
  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (), 0);
}

Dynamic::RequestContext *
TAO_ServerRequestInfo::operation_context (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Need the minor code once it becomes available.
  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (), 0);
}

CORBA::Any *
TAO_ServerRequestInfo::result (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Need the minor code once it becomes available.
  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (), 0);
}

CORBA::Boolean
TAO_ServerRequestInfo::response_expected (CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->server_request_.response_expected ();
}

# if TAO_HAS_CORBA_MESSAGING == 1
Messaging::SyncScope
TAO_ServerRequestInfo::sync_scope (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (this->server_request_.sync_with_server ())
    return Messaging::SYNC_WITH_SERVER;

  // @@ Need the minor once it becomes available.
  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (), -1);
}
#endif  /* TAO_HAS_CORBA_MESSAGING */

PortableInterceptor::ReplyStatus
TAO_ServerRequestInfo::reply_status (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (this->reply_status_ == -1)
    // A reply hasn't been received yet.
    ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (), -1);

  return this->reply_status_;
}

CORBA::Object_ptr
TAO_ServerRequestInfo::forward_reference (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (this->reply_status_ != PortableInterceptor::LOCATION_FORWARD
      && this->reply_status_ !=
           PortableInterceptor::LOCATION_FORWARD_PERMANENT)
    ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (),
                      CORBA::Object::_nil ());

  // We don't get the forward reference from the TAO_Server_Request
  // object since it may not have been set there.  For example, this
  // is the case when a Servant Manager throws a
  // PortableServer::ForwardRequest exception.  As such, we only
  // return the one stored in this object since it is explicitly set
  // by the responsible request forwarding code.
  return CORBA::Object::_duplicate (this->forward_reference_);
}

CORBA::Any *
TAO_ServerRequestInfo::get_slot (PortableInterceptor::SlotId,
                                 CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::InvalidSlot))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOTSUP),
                      CORBA::COMPLETED_NO),
                    0);
}

IOP::ServiceContext *
TAO_ServerRequestInfo::get_request_service_context (
    IOP::ServiceId id,
    CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  IOP::ServiceContextList &service_context_list =
    this->server_request_.service_context ().service_info ();

  CORBA::ULong len = service_context_list.length ();

  for (CORBA::ULong i = 0; i < len; ++i)
    if (service_context_list[i].context_id == id)
      {
        IOP::ServiceContext *service_context = 0;
        ACE_NEW_THROW_EX (service_context,
                          IOP::ServiceContext,
                          CORBA::NO_MEMORY (
                            CORBA::SystemException::_tao_minor_code (
                              TAO_DEFAULT_MINOR_CODE,
                              ENOMEM),
                            CORBA::COMPLETED_NO));
        ACE_CHECK_RETURN (0);

        IOP::ServiceContext_var safe_service_context = service_context;

        (*service_context) = service_context_list[i];

        return safe_service_context._retn ();
      }

  ACE_THROW_RETURN (CORBA::BAD_PARAM (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        EINVAL), // @@ Need minor code from PI spec!
                      CORBA::COMPLETED_NO),
                    0);
}

IOP::ServiceContext *
TAO_ServerRequestInfo::get_reply_service_context (
    IOP::ServiceId id,
    CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  IOP::ServiceContextList &service_context_list =
    this->server_request_.service_context ().service_info ();

  CORBA::ULong len = service_context_list.length ();

  for (CORBA::ULong i = 0; i < len; ++i)
    if (service_context_list[i].context_id == id)
      {
        IOP::ServiceContext *service_context = 0;
        ACE_NEW_THROW_EX (service_context,
                          IOP::ServiceContext,
                          CORBA::NO_MEMORY (
                            CORBA::SystemException::_tao_minor_code (
                              TAO_DEFAULT_MINOR_CODE,
                              ENOMEM),
                            CORBA::COMPLETED_NO));
        ACE_CHECK_RETURN (0);

        IOP::ServiceContext_var safe_service_context = service_context;

        (*service_context) = service_context_list[i];

        return safe_service_context._retn ();
      }

  ACE_THROW_RETURN (CORBA::BAD_PARAM (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        EINVAL), // @@ Need minor code from PI spec!
                      CORBA::COMPLETED_NO),
                    0);
}


// Use at own risk. There is no way currently of extracting an
// exception from an Any. This method is in place just to be compliant
// with the spec.
CORBA::Any *
TAO_ServerRequestInfo::sending_exception (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (this->reply_status_ != PortableInterceptor::SYSTEM_EXCEPTION
      && this->reply_status_ != PortableInterceptor::USER_EXCEPTION)
    {
      // @@ Need the minor code once it is available.
      ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (), 0);
    }

  // The spec says that if it is a user exception which cant be inserted
  // then the UNKNOWN exception needs to be thrown with minor code TBD_U.

  CORBA::Any * temp = 0;

  ACE_NEW_THROW_EX (temp,
                    CORBA::Any,
                    CORBA::NO_MEMORY (
                      CORBA_SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (0);

  CORBA::Any_var caught_exception = temp;

  if (this->caught_exception_ != 0)
    (*temp) <<= *(this->caught_exception_);

  return caught_exception._retn ();
}

// = TAO specific method done since there currently is no simple way
// to extract exceptions from an Any
CORBA::Exception *
TAO_ServerRequestInfo::_sending_exception (CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->caught_exception_;
}

CORBA::OctetSeq *
TAO_ServerRequestInfo::object_id (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
//   if (this->object_id_.in () == 0)
//     {
//       // @@ Need the minor code once it is available.
//       ACE_THROW_RETURN (CORBA::NO_RESOURCES (), 0);
//     }

  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOTSUP),
                      CORBA::COMPLETED_NO),
                    0);
}

CORBA::OctetSeq *
TAO_ServerRequestInfo::adapter_id (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
//   if (this->adapter_id_.in () == 0)
//     {
//       // @@ Need the minor code once it is available.
//       ACE_THROW_RETURN (CORBA::NO_RESOURCES (), 0);
//     }

  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOTSUP),
                      CORBA::COMPLETED_NO),
                    0);
}

char *
TAO_ServerRequestInfo::target_most_derived_interface (
    CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Need the minor code once it is available.
  ACE_THROW_RETURN (CORBA::NO_RESOURCES (), 0);
}

CORBA::Policy_ptr
TAO_ServerRequestInfo::get_server_policy (CORBA::PolicyType,
                                          CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return 0;
}

void
TAO_ServerRequestInfo::set_slot (PortableInterceptor::SlotId,
                                 const CORBA::Any &,
                                 CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::InvalidSlot))
{
  ACE_THROW (CORBA::NO_IMPLEMENT (
               CORBA::SystemException::_tao_minor_code (
                 TAO_DEFAULT_MINOR_CODE,
                 ENOTSUP),
               CORBA::COMPLETED_NO));
}

CORBA::Boolean
TAO_ServerRequestInfo::target_is_a (const char * /* id */,
                                    CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ Need the minor code once it is available.
  ACE_THROW_RETURN (CORBA::NO_RESOURCES (), 0);
}

void
TAO_ServerRequestInfo::add_reply_service_context (
    const IOP::ServiceContext & service_context,
    CORBA::Boolean replace,
    CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Copy the service context into the list.
  IOP::ServiceContextList &service_context_list =
    this->server_request_.service_context ().service_info ();

  CORBA::ULong len = service_context_list.length ();

  // First check if a service context with the same ID exists.
  for (CORBA::ULong i = 0; i < len; ++i)
    {
      if (service_context_list[i].context_id ==
          service_context.context_id)
        {
          if (replace)
            {
              service_context_list[i] = service_context;
              return;
            }
          else
            // @@ Need the minor code once it becomes available.
            ACE_THROW (CORBA::BAD_INV_ORDER ());
        }
    }

  // No service context with the given ID exists so add one.
  service_context_list.length (len + 1);

  service_context_list[len] = service_context;
}

#endif  /* TAO_HAS_INTERCEPTORS == 1 */
