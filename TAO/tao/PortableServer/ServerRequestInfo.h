// -*- C++ -*-

//=============================================================================
/**
 * @file ServerRequestInfo.h
 *
 * $Id$
 *
 * This is the implementation of the
 * @c PortableInterceptor::ServerRequestInfo interface.
 *
 * @author Kirthika Parameswaran <kirthika@cs.wustl.edu>
 * @author Ossama Othman
 */
//=============================================================================

#ifndef TAO_SERVER_REQUEST_INFO_H
#define TAO_SERVER_REQUEST_INFO_H

#include /**/ "ace/pre.h"

#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_INTERCEPTORS == 1)

#include "tao/PortableInterceptorC.h"
#include "tao/LocalObject.h"
#include "tao/OctetSeqC.h"
#include "tao/TAO_Server_Request.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class TAO_ServerRequest;
class TAO_Service_Context;

namespace TAO
{
  namespace Portable_Server
  {
    class Servant_Upcall;
  }
}

namespace TAO
{
  /**
   * @class ServerRequestInfo
   *
   * @brief Implementation of the
   *        @c PortableInterceptor::ServerRequestInfo IDL interface.
   *
   * Implementation of the @c PortableInterceptor::ServerRequestInfo
   * IDL interface.
   *
   * @note This class is currently not meant to be reference counted
   *       since it is instantiated on the stack.
   */
  class ServerRequestInfo
    : public virtual PortableInterceptor::ServerRequestInfo,
      public virtual CORBA::LocalObject
  {
  public:

    /// Constructor.
    ServerRequestInfo (TAO_ServerRequest & server_request,
                       TAO::Argument * const * args,
                       size_t nargs,
                       void * servant_upcall,
                       CORBA::TypeCode_ptr const * exceptions,
                       size_t nexceptions);

    /// Return an ID unique to the current request.  This request ID may
    /// or may not be the same as the GIOP request ID.
    virtual CORBA::ULong request_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the operation name for the current request.
    virtual char * operation (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the list of arguments passed to the current operation.
    virtual Dynamic::ParameterList * arguments (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the list of exceptions the current operation is capable
    /// of throwing.
    virtual Dynamic::ExceptionList * exceptions (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual Dynamic::ContextList * contexts (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual Dynamic::RequestContext * operation_context (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the result of the current request.  If there is no
    /// return value then an @c Any with @c tk_void @c TypeCode is
    /// returned.  This method is not valid for oneway operations.
    virtual CORBA::Any * result (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Returns @c true for a two-way operation, and @c false otherwise.
    virtual CORBA::Boolean response_expected (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the @c sync_scope policy value for the current one-way
    /// operation.  If the operation is not a one-way, a
    /// @c CORBA::BAD_INV_ORDER exception is thrown.
    virtual Messaging::SyncScope sync_scope (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the reply status for the current request.
    /**
     * Statuses can be @c PortableInterceptor::SUCCESSFUL,
     * @c SYSTEM_EXCEPTION, @c USER_EXCEPTION, @c LOCATION_FORWARD,
     * @c LOCATION_FORWARD_PERMANENT, @c TRANSPORT_RETRY.
     */
    virtual PortableInterceptor::ReplyStatus reply_status (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// If the reply status is
    /// @c PortableInterceptor::LOCATION_FORWARD or
    /// @c PortableInterceptor::LOCATION_FORWARD_PERMANENT, return the
    /// object reference to which the request was forwarded.
    virtual CORBA::Object_ptr forward_reference (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException)) ;

    /// Retrieve data from the "request scope" @c PICurrent object.
    virtual CORBA::Any * get_slot (
                                   PortableInterceptor::SlotId id
                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       PortableInterceptor::InvalidSlot));

    /// Return the @c IOP::ServiceContext with the given
    /// @c IOP::ServiceId from the request service context list.
    virtual IOP::ServiceContext * get_request_service_context (
        IOP::ServiceId id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the @c IOP::ServiceContext with the given
    /// @c IOP::ServiceId from the reply service context list.
    virtual IOP::ServiceContext * get_reply_service_context (
        IOP::ServiceId id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return an @c Any containing the exception being sent, if any.
    /// Otherwise, throw a @c CORBA::BAD_INV_ORDER exception.
    /**
     * @note There is no trivial way to extract the exception from an
     *       @c Any.
     */
    virtual CORBA::Any * sending_exception (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the @c ObjectId for the target object.
    virtual PortableInterceptor::ObjectId * object_id (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the @c AdapterId for the POA handling the current
    /// request.
    virtual CORBA::OctetSeq * adapter_id (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the server_id of the server. The value is passed to
    /// the ORB via @c -ORBServerId parameter.
    virtual char * server_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the ORBId value that is passed to the @c ORB_init
    /// call.
    virtual char * orb_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the name of the object adapter that services requests
    /// for the invoked object.
    virtual PortableInterceptor::AdapterName * adapter_name (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the most derived interface of the target object.
    virtual char * target_most_derived_interface (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Return the policy of the given type in effect for the current
    /// request.
    virtual CORBA::Policy_ptr get_server_policy (
        CORBA::PolicyType type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Insert data into the "request scope" @c PICurrent object.
    virtual void set_slot (PortableInterceptor::SlotId id,
                           const CORBA::Any & data
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       PortableInterceptor::InvalidSlot));

    /// Returns true if the target's type corresponds to the given
    /// @c RepositoryId.
    virtual CORBA::Boolean target_is_a (const char * id
                                        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Add the @c IOP::ServiceContext to the reply (outgoing)
    /// @c IOP::ServiceContextList.
    virtual void add_reply_service_context (
        const IOP::ServiceContext & service_context,
        CORBA::Boolean replace
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

  public:

    /**
     * @name Helper methods specific to TAO.
     */
    //@{

    /// Change the exception status.
    void exception (CORBA::Exception *exception);

    /// Set the status of the received reply.
    void reply_status (PortableInterceptor::ReplyStatus s);

    /// Extract the forward object reference from the
    /// @c PortableInterceptor::ForwardRequest exception, and set the
    /// reply status flag accordingly.
    void forward_reference (PortableInterceptor::ForwardRequest &exc);

    /// Set the forward reference associated with the current
    /// LOCATION_FORWARD reply.
    /**
     * @note This method is only invoked when a
     * @c PortableServer::ForwardRequest exception is thrown by a
     * servant manager.
     */
    void forward_reference (CORBA::Object_ptr obj);

    //@}

    /// Return a reference to the underlying @c TAO_ServerRequest
    /// object.
    TAO_ServerRequest &server_request (void);

  protected:

    /// Helper method to get the request and response service
    /// contexts.
    IOP::ServiceContext * get_service_context_i (
        TAO_Service_Context & service_context_list,
        IOP::ServiceId id
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException));

  protected:

    /// Underlying request object that contains much of the
    /// information encapsulated by this @c ServerRequestInfo
    /// implementation.
    TAO_ServerRequest & server_request_;

    /// Operation argument list.
    TAO::Argument * const * const args_;

    /// Number of element in the operation argument list.
    size_t const nargs_;

    /// Pointer to the @c Servant_Upcall object that contains the
    /// object ID, among other things.
    TAO::Portable_Server::Servant_Upcall * const servant_upcall_;

    /// Array of @c TypeCodes for user exceptions the operation is
    /// capable of raising.
    CORBA::TypeCode_ptr const * const exceptions_;

    /// The number of elements in the @c exceptions_ array.
    size_t const nexceptions_;

    /// Pointer to the caught exception.
    CORBA::Exception * caught_exception_;

    /// Reply status for the current request.
    PortableInterceptor::ReplyStatus reply_status_;

  };

}  // End namespace TAO


# if defined (__ACE_INLINE__)
#  include "ServerRequestInfo.inl"
# endif  /* __ACE_INLINE__ */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_HAS_INTERCEPTORS == 1 */

#include /**/ "ace/post.h"

#endif /* TAO_SERVER_REQUEST_INFO_H */
