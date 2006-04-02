// -*- C++ -*-

//=============================================================================
/**
 *  @file    ORB.h
 *
 *  $Id$
 *
 *  Header file for CORBA's ORB type.
 *
 *  @author DOC Center - Washington University at St. Louis
 *  @author DOC Group - Vanderbilt University
 *  @author DOC Laboratory - University of California at Irvine
 */
//=============================================================================

#ifndef TAO_ORB_H
#define TAO_ORB_H

#include /**/ "ace/pre.h"

#include "UserException.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orb_typesC.h"
#include "objectid.h"
#include "CORBA_methods.h"
#include "VarOut_T.h"
#include "Seq_Var_T.h"
#include "Seq_Out_T.h"
#include "Sequence_T.h"
#include "Policy_ForwardC.h"

#include "ace/Thread_Mutex.h"
#include "ace/Guard_T.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

typedef enum
{
  TAO_SERVICEID_NAMESERVICE,
  TAO_SERVICEID_TRADINGSERVICE,
  TAO_SERVICEID_IMPLREPOSERVICE,
  TAO_SERVICEID_INTERFACEREPOSERVICE,
  TAO_SERVICEID_MCASTSERVER
} TAO_Service_ID;

/// Forward declarations.
class TAO_MProfile;
class TAO_Client_Strategy_Factory;
class TAO_Server_Strategy_Factory;
class TAO_InputCDR;
class TAO_OutputCDR;
class TAO_Stub;
class TAO_Valuetype_Adapter;
class TAO_Acceptor_Filter;

// ****************************************************************

namespace CORBA
{
  class EnumMemberSeq;
  class StructMemberSeq;
  class UnionMemberSeq;
  class ValueMemberSeq;
  class ORB_ObjectIdList;

  class ExceptionList;
  typedef ExceptionList * ExceptionList_ptr;

  class ContextList;
  typedef ContextList * ContextList_ptr;

  class Context;
  typedef Context * Context_ptr;

  class NVList;
  typedef NVList *NVList_ptr;

  class NamedValue;
  typedef NamedValue *NamedValue_ptr;

  class Policy;
  typedef Policy *Policy_ptr;

  typedef CORBA::ULong PolicyType;

  // TODO - implement OMG's 'ORBid CORBA::ORB::id (void)'.

  typedef
    TAO_VarSeq_Var_T<
        ORB_ObjectIdList
      >
    ORB_ObjectIdList_var;

  typedef
    TAO_Seq_Out_T<
        ORB_ObjectIdList
      >
    ORB_ObjectIdList_out;

  struct ServiceInformation;

  typedef
    TAO_Var_Var_T<
        ServiceInformation
      >
    ServiceInformation_var;

  typedef
    TAO_Out_T<
        ServiceInformation,
        ServiceInformation_var
      >
    ServiceInformation_out;

  class ValueFactoryBase;
  typedef ValueFactoryBase *ValueFactory;

  typedef UShort ServiceType;

  class Request;
  typedef Request * Request_ptr;
  typedef TAO_Pseudo_Var_T<Request> Request_var;
  typedef TAO_Pseudo_Out_T<Request, Request_var> Request_out;

  class ORB;
  typedef ORB * ORB_ptr;
  typedef TAO_Pseudo_Var_T<ORB> ORB_var;
  typedef TAO_Pseudo_Out_T<ORB, ORB_var> ORB_out;

  typedef CORBA::Short ValueModifier;

  /**
   * @class ORB
   *
   * @brief ORB pseudo-object.
   *
   * The "ORB" pseudo-object is used in bootstrapping, such as to
   * create object references from strings.  This class is intended
   * to be inherited by others, which will provide some more of the
   * CORBA support.  Implementations of this "CORBA::ORB" class must
   * know how to create stringify/destringify their objrefs, as well
   * as how to marshal and unmarshal them.
   */
  class TAO_Export ORB
  {
  public:

    class TAO_Export InvalidName : public CORBA::UserException
    {
    public:
      InvalidName (void);
      InvalidName (const InvalidName &);
      ~InvalidName (void);

      InvalidName &operator= (const InvalidName &);

      static InvalidName *_downcast (CORBA::Exception *);
      static CORBA::Exception *_alloc (void);

      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (TAO_OutputCDR &
                                ACE_ENV_ARG_DECL) const;

      virtual void _tao_decode (TAO_InputCDR &
                                ACE_ENV_ARG_DECL);
    };

    typedef char *ObjectId;
    typedef CORBA::String_var ObjectId_var;
    typedef CORBA::String_out ObjectId_out;
    static CORBA::TypeCode_ptr const _tc_ObjectId;

    typedef CORBA::ORB_ObjectIdList ObjectIdList;
    typedef CORBA::ORB_ObjectIdList_var ObjectIdList_var;
    typedef CORBA::ORB_ObjectIdList_out ObjectIdList_out;
    typedef CORBA::ORB_ObjectIdList *ObjectIdList_ptr;
    static CORBA::TypeCode_ptr const _tc_ObjectIdList;

    /// Return a duplicate of @c orb.
    /**
     * When work with this duplicate is complete, it should be freed
     * up using CORBA::release().
     */
    static CORBA::ORB_ptr _duplicate (CORBA::ORB_ptr orb);

    /// Returns a pointer to a nil ORB, i.e., an non-existent ORB.  This
    /// can be used for initialization or in comparisons.
    static CORBA::ORB_ptr _nil (void);

    /// Return this ORB's ORBid.
    char * id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    /**
     * Turn a string-ified object reference back into an object
     * pointer.  Typically these strings are created using
     * object_to_string(), but not necessarily locally.
     */
    CORBA::Object_ptr string_to_object (const char *str
                                        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /**
     * Turn an object reference into a string.  Each type of ORB,
     * e.g. an IIOP ORB, must implement this.  This can be used by
     * servers to publish their whereabouts to clients.  The output of
     * this is typically eventually given to @c string_to_object() as
     * an argument.
     */
    char * object_to_string (CORBA::Object_ptr obj
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    // Value factory operations  (CORBA 2.3 ptc/98-10-05 Ch. 4.2 p.4-7)
    CORBA::ValueFactory register_value_factory (
        const char *repository_id,
        CORBA::ValueFactory factory
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    void unregister_value_factory (const char * repository_id
                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    CORBA::ValueFactory lookup_value_factory (
        const char *repository_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

#if (TAO_HAS_MINIMUM_CORBA == 0)

    // Typedefs for CORBA::ORB::RequestSeq, which is an argument of
    // send_multiple_requests_*().

    typedef
      TAO::unbounded_object_reference_sequence<
          CORBA::Request, CORBA::Request_var
        >
      RequestSeq;

    typedef
      TAO_VarSeq_Var_T<
          RequestSeq
        >
      RequestSeq_var;

    typedef
      TAO_Seq_Out_T<
          RequestSeq
        >
      RequestSeq_out;

    void create_list (CORBA::Long count,
                      CORBA::NVList_ptr &new_list
                      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void create_operation_list(CORBA::OperationDef_ptr opDef,
                               CORBA::NVList_ptr& result
                               ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void create_named_value (CORBA::NamedValue_ptr &nmval
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void create_exception_list (CORBA::ExceptionList_ptr &exclist
                                ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void create_environment (CORBA::Environment_ptr &new_env
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    // The following are not implemented and just throw
    // CORBA::NO_IMPLEMENT.

    void create_context_list (CORBA::ContextList_ptr &ctxtlist
                              ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void get_default_context (CORBA::Context_ptr &ctx
                              ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::Boolean get_service_information (
      CORBA::ServiceType service_type,
      CORBA::ServiceInformation_out service_information
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void send_multiple_requests_oneway (const CORBA::ORB::RequestSeq &req
                                        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void send_multiple_requests_deferred (const CORBA::ORB::RequestSeq &req
                                          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    void get_next_response (CORBA::Request_ptr &req
                            ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::Boolean poll_next_response (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    /// The ORB TypeCode creation functions.

    CORBA::TypeCode_ptr create_struct_tc (
        const char *id,
        const char *name,
        const CORBA::StructMemberSeq &members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_union_tc (
        const char *id,
        const char *name,
        CORBA::TypeCode_ptr discriminator_type,
        const CORBA::UnionMemberSeq &members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_enum_tc (
        const char *id,
        const char *name,
        const CORBA::EnumMemberSeq &members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_alias_tc (
        const char *id,
        const char *name,
        CORBA::TypeCode_ptr original_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_exception_tc (
        const char *id,
        const char *name,
        const CORBA::StructMemberSeq &members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_interface_tc (
        const char *id,
        const char *name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_string_tc (
        CORBA::ULong bound
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_wstring_tc (
        CORBA::ULong bound
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_fixed_tc (
        CORBA::UShort digits,
        CORBA::UShort scale
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_sequence_tc (
        CORBA::ULong bound,
        CORBA::TypeCode_ptr element_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_array_tc (
        CORBA::ULong length,
        CORBA::TypeCode_ptr element_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_value_tc (
        const char *id,
        const char *name,
        CORBA::ValueModifier type_modifier,
        CORBA::TypeCode_ptr concrete_base,
        const CORBA::ValueMemberSeq &members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_value_box_tc (
        const char *id,
        const char *name,
        CORBA::TypeCode_ptr boxed_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_native_tc (
        const char *id,
        const char *name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_recursive_tc (
        const char *id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_abstract_interface_tc (
        const char *id,
        const char *name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_local_interface_tc (
        const char *id,
        const char *name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_component_tc (
        const char *id,
        const char *name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    CORBA::TypeCode_ptr create_home_tc (
        const char *id,
        const char *name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
        );

    CORBA::TypeCode_ptr create_event_tc (
        const char *id,
        const char *name,
        CORBA::ValueModifier type_modifier,
        CORBA::TypeCode_ptr concrete_base,
        const CORBA::ValueMemberSeq &members
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

#endif /* TAO_HAS_MINIMUM_CORBA */

    // = ORB event loop methods.

    /**
     * Instructs the ORB to initialize itself and run its event loop in
     * the current thread, not returning until the ORB has shut down.
     * If an error occurs during initialization or at runtime, a CORBA
     * system exception will be thrown.
     */
    void run (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    /**
     * Instructs the ORB to initialize itself and run its event loop in
     * the current thread, not returning until the ORB has shut down or
     * the time value specified through @a tv has expired.  If an
     * error occurs during initialization or at runtime, a CORBA
     * system exception will be thrown.  @a tv is reduced by the
     * amount of time spent in this call.
     *
     * If this function is called with a @ tv value, client threads
     * making invocations will continue their operations. When the
     * operation timesout and returns, any invocations showing up on
     * the server will be buffered by TCP.
     **/
    void run (ACE_Time_Value &tv
              ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /**
     * Instructs the ORB to initialize itself and run its event loop in
     * the current thread, not returning until the ORB has shut down or
     * the time value specified through @a tv has expired.  If an error
     * occurs during initialization or at runtime, a CORBA system
     * exception will be thrown.  @a tv is reduced by the amount of time
     * spent in this call.  If @a tv is 0, it means that the timeout
     * is infinite.  If @a tv is @c ACE_Time_Value::zero, it specifies
     * to poll and does not block.
     *
     * If this function is called with @a tv value, client threads
     * making invocations will continue their operations. When the
     * operation timesout and returns, any invocations showing up on
     * the server will be buffered by TCP.
     **/
    void run (ACE_Time_Value *tv
              ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /// Returns an indication of whether the ORB needs to perform some
    /// work.
    CORBA::Boolean work_pending (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    /// Returns an indication of whether the ORB needs to perform some
    /// work but will look for work pending for no more than the
    /// specified time.
    /**
     * @note This is useful for implementing an event loop with an
     *       idle timeout.
     */
    CORBA::Boolean work_pending (ACE_Time_Value &tv
                                 ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /**
     * This operation performs an implementation-defined unit of work.
     * Note that the default behavior is to block if the unit of work
     * is not present; this behavior can be modified by passing an
     * appropriate @c ACE_Time_Value as described in run().
     **/
    void perform_work (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);
    void perform_work (ACE_Time_Value &tv
                       ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    void perform_work (ACE_Time_Value *tv
                       ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /**
     * This operation instructs the ORB to shut down. Shutting down the
     * ORB causes all Object Adapters to be shut down. If
     * @c wait_for_completion parameter is TRUE, this operation blocks
     * until all ORB processing (including request processing and object
     * deactivation or other operations associated with object adapters)
     * has completed.
     */
    void shutdown (CORBA::Boolean wait_for_completion = 0
                   ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /**
     * Explicitly destroy the ORB, releasing any resources.  Note that
     * TAO *cannot* implicitly release the resources even if you have
     * destroyed all the references to a particular ORB since
     * CORBA::ORB_init() is required to return the same pointer if
     * called with the same ORBid, only after ORB::destroy() is called
     * it may return a new one.
     *
     * The results of multi-threaded applications, trying to destroy ()
     * the ORB in one thread and trying to service a request in another
     * thread are not well defined. TAO does not support such cases.
     */
    void destroy (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    CORBA::Object_ptr resolve_initial_references (
        const char *name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    /**
     * This method acts as a mini-bootstrapping Naming Service, which is
     * provided by the ORB for certain well-known object references.  TAO
     * supports the "NameService", "TradingService", "RootPOA",
     * "ImplRepo", and "POACurrent" via this method.  The @c timeout
     * value bounds the amount of time the ORB blocks waiting to
     * resolve the service.  This is most useful for bootstrapping
     * remote services, such as the "NameService" or "TradingService",
     * that are commonly resolved via multicast.  By default, the
     * value is 0, which means "use the @c
     * TAO_DEFAULT_SERVICE_RESOLUTION_TIMEOUT timeout period".
     *
     * @note By using a default value for the @c timeout parameter,
     *       TAO will remains compliant with the CORBA
     *       resolve_initial_references() specification.
     */
    CORBA::Object_ptr resolve_initial_references (
      const char *name,
      ACE_Time_Value *timeout
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /// Register an object reference with the ORB.
    void register_initial_reference (const char * id,
                                     CORBA::Object_ptr obj
                                     ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /// Returns a sequence of ObjectIds that lists which objects have
    /// references available via the initial references mechanism.
    CORBA::ORB::ObjectIdList_ptr list_initial_services (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

    CORBA::Policy_ptr create_policy (CORBA::PolicyType type,
                                     const CORBA::Any& val
                                     ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    // ----------------------------------------------------------------
    // = TAO-specific extensions to the CORBA specification.
    // ----------------------------------------------------------------

    /// Create an empty policy, usually to be filled in later by
    /// demarshaling.
    CORBA::Policy_ptr _create_policy (CORBA::PolicyType type
                                      ACE_ENV_ARG_DECL);

    // Reference counting...
    CORBA::ULong _incr_refcnt (void);
    CORBA::ULong _decr_refcnt (void);

    /// Set the IOR flag.
    void _use_omg_ior_format (CORBA::Boolean ior);

    /// Get the IOR flag.
    CORBA::Boolean _use_omg_ior_format (void);

    /// Get the ORB core.
    TAO_ORB_Core *orb_core (void) const;

    /**
     * TAO specific extension to get and set the client ID. The client
     * id can be set by the application which would be used by the FT
     * service. As there are no specific interfaces defined in the
     * spec, we have this proprietary extension.
     */
    const ACE_CString &_tao_ft_client_id (void);
    void _tao_ft_client_id (const char *id);

    /// Factory method that creates an ORB.
    static CORBA::ORB_ptr _tao_make_ORB (TAO_ORB_Core * orb_core);

    // Useful for template programming.
    typedef ORB_ptr _ptr_type;
    typedef ORB_var _var_type;

    /// Get the Timeout value
    ACE_Time_Value *get_timeout (void);

  protected:

    // We must be created via the @c CORBA::ORB_init() function.
    ORB (TAO_ORB_Core *orb_core);

    /// Destructor
    /**
     * Protected destructor to enforce proper memory management
     * through the reference counting mechanism.
     */
    ~ORB (void);

    /// Resolve the Policy Manager for this ORB.
    CORBA::Object_ptr resolve_policy_manager (void);

    /// Resolve the Policy Current for this thread.
    CORBA::Object_ptr resolve_policy_current (void);

  private:

    /// Resolve the given service based on the service ID.
    /**
     * "@c resolve_service" is a legacy name.  This method now simply
     * sets up a default initial reference that will be subsequently
     * used in resolve_initial_references().
     */
    void resolve_service (TAO::MCAST_SERVICEID service_id);

    /// Convert an OMG IOR into an object reference.
    CORBA::Object_ptr ior_string_to_object (const char* ior
                                            ACE_ENV_ARG_DECL);

    /// Convert an URL style IOR into an object reference.
    CORBA::Object_ptr url_ior_string_to_object (const char* ior
                                                ACE_ENV_ARG_DECL);

    /// Check if ORB has shutdown.  If it has, throw the appropriate
    /// exception.
    void check_shutdown (ACE_ENV_SINGLE_ARG_DECL);

    /// Set the timeout value
    void set_timeout (ACE_Time_Value * timeout);

  private:

    /// Lock required for mutual exclusion between multiple threads.
    TAO_SYNCH_MUTEX lock_;

    /// Maintains a reference count of number of instantiations of the
    /// ORB.
    CORBA::ULong refcount_;

    /// The ORB_Core that created us....
    TAO_ORB_Core *orb_core_;

    /// Decides whether to use the URL notation or to use IOR notation.
    CORBA::Boolean use_omg_ior_format_;

    // Prevent copying and assignment.
    ORB (const ORB &);
    ORB &operator= (const ORB &);

    /// Timeout value
    ACE_Time_Value * timeout_;

  };
}  // End namespace CORBA

namespace TAO
{
  namespace ORB
  {
    /// Initialize the ORB globals correctly, i.e., only when they
    /// haven't been initialized yet.
    void init_orb_globals (ACE_ENV_SINGLE_ARG_DECL);
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
# include "tao/ORB.i"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_ORB_H */
