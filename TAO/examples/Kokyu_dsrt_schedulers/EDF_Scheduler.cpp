//$Id$

#include "EDF_Scheduler.h"
#include "Kokyu_qosC.h"
#include "utils.h"
#include "tao/RTScheduling/Request_Interceptor.h"
#include "tao/ORB_Constants.h"

EDF_Scheduling::SchedulingParameter
EDF_Sched_Param_Policy::value (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->value_;
}

void
EDF_Sched_Param_Policy::value (const EDF_Scheduling::SchedulingParameter& value ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->value_ = value;
}

EDF_Scheduler::EDF_Scheduler (CORBA::ORB_ptr orb,
                              Kokyu::DSRT_Dispatcher_Impl_t disp_impl_type,
                              int ace_sched_policy,
                              int ace_sched_scope)
  : orb_ (orb),
    disp_impl_type_ (disp_impl_type),
    ace_sched_policy_ (ace_sched_policy),
    ace_sched_scope_ (ace_sched_scope)
{
  ACE_DECLARE_NEW_ENV;

  Kokyu::DSRT_ConfigInfo config;

  config.impl_type_ = this->disp_impl_type_;
  config.sched_policy_ = ace_sched_policy_;
  config.sched_scope_ = ace_sched_scope_;

  Kokyu::DSRT_Dispatcher_Factory<EDF_Scheduler_Traits>::DSRT_Dispatcher_Auto_Ptr
    tmp( Kokyu::DSRT_Dispatcher_Factory<EDF_Scheduler_Traits>::
         create_DSRT_dispatcher (config) );
  kokyu_dispatcher_ = tmp;

  CORBA::Object_var object =
    orb->resolve_initial_references ("RTScheduler_Current"
                                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->current_ =
    RTScheduling::Current::_narrow (object.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  IOP::CodecFactory_var codec_factory;
  CORBA::Object_var obj = 
    orb->resolve_initial_references ("CodecFactory"
                                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (CORBA::is_nil(obj.in ()))
    {
      ACE_ERROR ((LM_ERROR, "Nil Codec factory\n"));
    }
  else
    {
      codec_factory = IOP::CodecFactory::_narrow (obj.in ());
    }

  IOP::Encoding encoding;
  encoding.format = IOP::ENCODING_CDR_ENCAPS;
  encoding.major_version = 1;
  encoding.minor_version = 2;

  codec_ = codec_factory->create_codec (encoding);
}

EDF_Scheduler::~EDF_Scheduler (void)
{
}

void
EDF_Scheduler::shutdown (void)
{
  kokyu_dispatcher_->shutdown ();
  ACE_DEBUG ((LM_DEBUG, "kokyu DSRT dispatcher shutdown\n"));
}

EDF_Scheduling::SchedulingParameterPolicy_ptr
EDF_Scheduler::create_scheduling_parameter (const EDF_Scheduling::SchedulingParameter & value ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  EDF_Scheduling::SchedulingParameterPolicy_ptr sched_param_policy;
  ACE_NEW_THROW_EX (sched_param_policy,
                    EDF_Sched_Param_Policy,
                    CORBA::NO_MEMORY (
                                      CORBA::SystemException::_tao_minor_code (
                                       TAO_DEFAULT_MINOR_CODE,
                                       ENOMEM),
                                      CORBA::COMPLETED_NO));

  sched_param_policy->value (value);

  return sched_param_policy;
}


void
EDF_Scheduler::begin_new_scheduling_segment (const RTScheduling::Current::IdType &guid,
                                             const char *,
                                             CORBA::Policy_ptr sched_policy,
                                             CORBA::Policy_ptr
                                             ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE))
{
#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG, 
              "(%t|%T):EDF_Scheduler::begin_new_scheduling_segment enter\n")); 
#endif

#ifdef KOKYU_DSRT_LOGGING
  int int_guid;
  ACE_OS::memcpy (&int_guid,
                  guid.get_buffer (),
                  guid.length ());
  ACE_DEBUG ((LM_DEBUG, "(%t|%T): guid is %d\n", int_guid));
#endif

  EDF_Scheduler_Traits::QoSDescriptor_t qos;
  EDF_Scheduling::SchedulingParameterPolicy_var sched_param_policy =
    EDF_Scheduling::SchedulingParameterPolicy::_narrow (sched_policy);

  EDF_Scheduling::SchedulingParameter_var sched_param = sched_param_policy->value ();

  qos.deadline_ = sched_param->deadline;
  qos.importance_ = sched_param->importance;

  kokyu_dispatcher_->schedule (guid, qos);

#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG, 
              "(%t|%T):EDF_Scheduler::begin_new_scheduling_segment exit\n")); 
#endif
}


void
EDF_Scheduler::begin_nested_scheduling_segment (const RTScheduling::Current::IdType &guid,
                                                           const char *name,
                                                           CORBA::Policy_ptr sched_param,
                                                           CORBA::Policy_ptr implicit_sched_param
                                                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE))
{
  this->begin_new_scheduling_segment (guid,
                                      name,
                                      sched_param,
                                      implicit_sched_param
                                      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
EDF_Scheduler::update_scheduling_segment (const RTScheduling::Current::IdType& guid,
                                          const char* name,
                                          CORBA::Policy_ptr sched_policy,
                                          CORBA::Policy_ptr implicit_sched_param
                                          ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE))
{
  ACE_UNUSED_ARG ((name));
  ACE_UNUSED_ARG ((implicit_sched_param));

#ifdef KOKYU_DSRT_LOGGING
  int int_guid ;
  ACE_OS::memcpy (&int_guid,
                  guid.get_buffer (),
                  guid.length ());
  ACE_DEBUG ((LM_DEBUG, "(%t|%T): update_sched_seg::guid is %d\n", int_guid));
#endif

  EDF_Scheduling::SchedulingParameterPolicy_var sched_param_policy =
    EDF_Scheduling::SchedulingParameterPolicy::_narrow (sched_policy);

  EDF_Scheduling::SchedulingParameter_var sched_param = sched_param_policy->value ();
  EDF_Scheduler_Traits::QoSDescriptor_t qos;

  qos.deadline_ = sched_param->deadline;
  qos.importance_ = sched_param->importance;

  kokyu_dispatcher_->update_schedule (guid, qos);
}

void
EDF_Scheduler::end_scheduling_segment (const RTScheduling::Current::IdType &guid,
                                       const char *
                                       ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
#ifdef KOKYU_DSRT_LOGGING
  int int_guid;
  ACE_OS::memcpy (&int_guid,
                  guid.get_buffer (),
                  guid.length ());
  ACE_DEBUG ((LM_DEBUG, "(%t|%T) call to end_sched_segment for guid %d\n", int_guid));
#endif

  kokyu_dispatcher_->cancel_schedule (guid);
}

void
EDF_Scheduler::end_nested_scheduling_segment (const RTScheduling::Current::IdType &,
                                                         const char *,
                                                         CORBA::Policy_ptr
                                                         ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}


void
EDF_Scheduler::send_request (PortableInterceptor::ClientRequestInfo_ptr ri
                             ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  Kokyu::Svc_Ctxt_DSRT_QoS sc_qos;

  CORBA::String_var operation = ri->operation (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG,
              "(%t|%T): send_request "
              "from \"%s\"\n",
              operation.in ()));
#endif

  // Make the context to send the context to the target
  IOP::ServiceContext sc;
  sc.context_id = Client_Interceptor::SchedulingInfo;

  CORBA::Policy_ptr sched_policy =
    this->current_->scheduling_parameter(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  /*
  int guid;
  ACE_OS::memcpy (&guid,
                  this->current_->id ()->get_buffer (),
                  this->current_->id ()->length ());
  */

  CORBA::Long importance;
  TimeBase::TimeT deadline;

  if (CORBA::is_nil (sched_policy))
    {
      //24 hrs from now - infinity
      ACE_Time_Value deadline_tv = ACE_OS::gettimeofday () + ACE_Time_Value (24*60*60,0);
      deadline = deadline_tv.sec () * 1000000 + deadline_tv.usec () * 10; //100s of nanoseconds for TimeBase::TimeT
      importance = 0;
    }
  else
    {
      EDF_Scheduling::SchedulingParameterPolicy_var sched_param_policy =
        EDF_Scheduling::SchedulingParameterPolicy::_narrow (sched_policy);

      EDF_Scheduling::SchedulingParameter_var sched_param = sched_param_policy->value ();
      deadline = sched_param->deadline;
      importance = sched_param->importance;

#ifdef KOKYU_DSRT_LOGGING
      int int_guid;
      ACE_OS::memcpy (&int_guid,
                      this->current_->id ()->get_buffer (),
                      this->current_->id ()->length ());
      ACE_DEBUG ((LM_DEBUG,
                  "(%t|%T): send_request guid = %d\n",
                  int_guid));
#endif

      //Fill the guid in the SC Qos struct
      sc_qos.guid.length (this->current_->id ()->length ());
      guid_copy (sc_qos.guid, *(this->current_->id ()));
      sc_qos.deadline = deadline;
      sc_qos.importance = importance;
      CORBA::Any sc_qos_as_any;
      sc_qos_as_any <<= sc_qos;

      sc.context_data =
        ACE_reinterpret_cast(IOP::ServiceContext::
                             _tao_seq_CORBA_Octet_ &,
                             *codec_->encode (sc_qos_as_any));
      
#ifdef KOKYU_DSRT_LOGGING
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("(%t|%T): send_request : about to add sched SC\n")));
#endif

      // Add this context to the service context list.
      ri->add_request_service_context (sc, 0 ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }


#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG,
              ACE_LIB_TEXT ("(%t|%T): send_request : ")
              ACE_LIB_TEXT ("about to call scheduler to inform block\n")
              ));
#endif

  kokyu_dispatcher_->update_schedule (*(this->current_->id ()),
                                        Kokyu::BLOCK);

#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG,
              ACE_LIB_TEXT ("(%t|%T): send_request interceptor done\n")));
#endif
}

void
EDF_Scheduler::receive_request (PortableInterceptor::ServerRequestInfo_ptr ri,
                                RTScheduling::Current::IdType_out guid_out,
                                CORBA::String_out /*name*/,
                                CORBA::Policy_out sched_param_out,
                                CORBA::Policy_out /*implicit_sched_param_out*/
                                ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  Kokyu::Svc_Ctxt_DSRT_QoS* sc_qos_ptr;

#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG, "(%t|%T):entered EDF_Scheduler::receive_request\n"));
#endif

  RTScheduling::Current::IdType guid;

  CORBA::String_var operation = ri->operation (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG,
              "(%t|%T): receive_request from "
              "\"%s\"\n",
              operation.in ()));
#endif

  // Ignore the "_is_a" operation since it may have been invoked
  // locally on the server side as a side effect of another call,
  // meaning that the client hasn't added the service context yet.
  if (ACE_OS::strcmp ("_is_a", operation.in ()) == 0)
    return;

  IOP::ServiceContext_var sc =
    ri->get_request_service_context (Server_Interceptor::SchedulingInfo
                                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Long importance;
  TimeBase::TimeT deadline;

  if (sc.ptr () == 0)
    {
      //24 hrs from now - infinity
      ACE_Time_Value deadline_tv = ACE_OS::gettimeofday () + ACE_Time_Value (24*60*60,0);
      deadline = deadline_tv.sec ()*1000000 + deadline_tv.usec ()*10; //100s of nanoseconds for TimeBase::TimeT
      importance = 0;
    }
  else
    {
      CORBA::OctetSeq oc_seq = CORBA::OctetSeq (sc->context_data.length (),
                                                 sc->context_data.length (),
                                                 sc->context_data.get_buffer (),
                                                 0);
      CORBA::Any sc_qos_as_any;
      sc_qos_as_any = *codec_->decode (oc_seq);
      //Don't store in a _var, since >>= returns a pointer to an
      //internal buffer and we are not supposed to free it.
      sc_qos_as_any >>= sc_qos_ptr;

      deadline  = sc_qos_ptr->deadline;
      importance = sc_qos_ptr->importance;

      guid.length (sc_qos_ptr->guid.length ());
      guid_copy (guid, sc_qos_ptr->guid);

      ACE_NEW (guid_out.ptr (),
	       RTScheduling::Current::IdType);
      guid_out.ptr ()->length (guid.length ());
      *(guid_out.ptr ()) = guid;

#ifdef KOKYU_DSRT_LOGGING
      int int_guid;
      ACE_OS::memcpy (&int_guid,
                      guid.get_buffer (),
                      guid.length ());
      ACE_DEBUG ((LM_DEBUG,
                  "(%t|%T): Importance = %d, guid = %d "
                  "in recvd service context\n",
                  importance,
                  int_guid));
#endif
      EDF_Scheduling::SchedulingParameter sched_param;
      sched_param.importance = importance;
      sched_param.deadline = deadline;
      sched_param_out = this->create_scheduling_parameter (sched_param);
    }

  EDF_Scheduler_Traits::QoSDescriptor_t qos;
  qos.importance_ = importance;
  qos.deadline_ = deadline;

  this->kokyu_dispatcher_->schedule (guid, qos);

#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG, "(%t|%T): receive_request interceptor done\n"));
#endif

}

void
EDF_Scheduler::send_poll (PortableInterceptor::ClientRequestInfo_ptr
			  ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
		   PortableInterceptor::ForwardRequest))
{
}

void
EDF_Scheduler::send_reply (PortableInterceptor::ServerRequestInfo_ptr ri
                           ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{

  Kokyu::Svc_Ctxt_DSRT_QoS sc_qos;

  CORBA::String_var operation = ri->operation (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG,
              "(%t|%T): send_reply from \"%s\"\n",
              ri->operation ()));
#endif

  // Make the context to send the context to the target
  IOP::ServiceContext sc;
  sc.context_id = Server_Interceptor::SchedulingInfo;


  CORBA::Long importance;
  TimeBase::TimeT deadline;

  CORBA::Policy_ptr sched_policy =
    this->current_->scheduling_parameter(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  if (CORBA::is_nil (sched_policy))
  {
#ifdef KOKYU_DSRT_LOGGING
    ACE_DEBUG ((LM_DEBUG, 
                "(%t|%T): sched_policy nil.\n "));
#endif
    //24 hrs from now - infinity
    ACE_Time_Value deadline_tv = ACE_OS::gettimeofday () + ACE_Time_Value (24*60*60,0);
    deadline = deadline_tv.sec ()*1000000 + deadline_tv.usec ()*10; //100s of nanoseconds for TimeBase::TimeT
    importance = 0;
  }
  else
    {
#ifdef KOKYU_DSRT_LOGGING
      ACE_DEBUG ((LM_DEBUG, 
                  "(%t|%T):sched_policy not nil. ",
                  "sched params set\n"));
#endif
      EDF_Scheduling::SchedulingParameterPolicy_var sched_param_policy =
        EDF_Scheduling::SchedulingParameterPolicy::_narrow (sched_policy);
      EDF_Scheduling::SchedulingParameter_var sched_param = sched_param_policy->value ();


      sc_qos.guid.length (this->current_->id ()->length ());
      guid_copy (sc_qos.guid, *(this->current_->id ()));

      deadline = sched_param->deadline;
      importance = sched_param->importance;
      sc_qos.deadline = deadline;
      sc_qos.importance = importance;

      CORBA::Any sc_qos_as_any;
      sc_qos_as_any <<= sc_qos;

      sc.context_data = ACE_reinterpret_cast(
                                             IOP::ServiceContext::
                                             _tao_seq_CORBA_Octet_ &,
                                             *codec_->encode (sc_qos_as_any));

      // Add this context to the service context list.
      ri->add_reply_service_context (sc, 1 ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

#ifdef KOKYU_DSRT_LOGGING
      ACE_DEBUG ((LM_DEBUG, "(%t|%T):reply sc added\n"));
#endif
    }

  kokyu_dispatcher_->update_schedule (*(this->current_->id ()), 
                                      Kokyu::BLOCK);

#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG, "(%t|%T): send_reply interceptor done\n"));
#endif
}

void
EDF_Scheduler::send_exception (PortableInterceptor::ServerRequestInfo_ptr ri
                               ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  send_reply (ri ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
EDF_Scheduler::send_other (PortableInterceptor::ServerRequestInfo_ptr ri
                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  send_reply (ri ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
EDF_Scheduler::receive_reply (PortableInterceptor::ClientRequestInfo_ptr ri
                              ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  RTScheduling::Current::IdType guid;

  CORBA::String_var operation = ri->operation (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Object_var target = ri->target (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  ACE_CString opname = operation.in ();
#ifdef KOKYU_DSRT_LOGGING
  ACE_DEBUG ((LM_DEBUG,
              "(%t|%T):receive_reply from "
              "\"%s\"\n",
              opname.c_str ()));
#endif

  // Check that the reply service context was received as
  // expected.
  IOP::ServiceContext_var sc =
    ri->get_reply_service_context (Client_Interceptor::SchedulingInfo 
                                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Long importance;
  TimeBase::TimeT deadline;

  if (sc.ptr () == 0)
    {
      ACE_DEBUG ((LM_DEBUG, "service context was not filled\n"));
      //24 hrs from now - infinity
      ACE_Time_Value deadline_tv = ACE_OS::gettimeofday () + ACE_Time_Value (24*60*60,0);
      deadline = deadline_tv.sec ()*1000000 + deadline_tv.usec ()*10; //100s of nanoseconds for TimeBase::TimeT
      importance = 0;
    }
  else
    {
      CORBA::OctetSeq oc_seq = CORBA::OctetSeq (sc->context_data.length (),
                                                sc->context_data.length (),
                                                sc->context_data.get_buffer (),
                                                0);

      //Don't store in a _var, since >>= returns a pointer to an internal buffer
      //and we are not supposed to free it.
      Kokyu::Svc_Ctxt_DSRT_QoS* sc_qos_ptr;
      CORBA::Any sc_qos_as_any;
      sc_qos_as_any = *codec_->decode (oc_seq);
      sc_qos_as_any >>= sc_qos_ptr;

      deadline  = sc_qos_ptr->deadline;
      importance = sc_qos_ptr->importance;

      guid.length (sc_qos_ptr->guid.length ());
      guid_copy (guid, sc_qos_ptr->guid);

      ACE_DEBUG ((LM_DEBUG,
                  "(%t|%T):Importance = %d in recvd service context\n",
                  importance));
    }

  EDF_Scheduler_Traits::QoSDescriptor_t qos;
  qos.deadline_ =   qos.importance_ = importance;
  qos.deadline_ = deadline;
  this->kokyu_dispatcher_->schedule (guid, qos);
}

void
EDF_Scheduler::receive_exception (PortableInterceptor::ClientRequestInfo_ptr ri
                                  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  receive_reply (ri ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
EDF_Scheduler::receive_other (PortableInterceptor::ClientRequestInfo_ptr ri
                              ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  receive_reply (ri ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
EDF_Scheduler::cancel (const RTScheduling::Current::IdType &
                       ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

CORBA::PolicyList*
EDF_Scheduler::scheduling_policies (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

void
EDF_Scheduler::scheduling_policies (const CORBA::PolicyList &
                                    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

CORBA::PolicyList*
EDF_Scheduler::poa_policies (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

char *
EDF_Scheduler::scheduling_discipline_name (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

RTScheduling::ResourceManager_ptr
EDF_Scheduler::create_resource_manager (const char *,
                                        CORBA::Policy_ptr
                                        ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

void
EDF_Scheduler::set_scheduling_parameter (PortableServer::Servant &,
                                         const char *,
                                         CORBA::Policy_ptr
                                         ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class Kokyu::DSRT_Dispatcher_Factory<EDF_Scheduler_Traits>;
template class Kokyu::DSRT_Dispatcher<EDF_Scheduler_Traits>;
template class Kokyu::DSRT_Dispatcher_Impl<EDF_Scheduler_Traits>;
template class Kokyu::DSRT_Direct_Dispatcher_Impl<EDF_Scheduler_Traits>;
template class Kokyu::DSRT_CV_Dispatcher_Impl<EDF_Scheduler_Traits>;
template class Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>;
template class Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>;
template class Kokyu::Sched_Ready_Queue<EDF_Scheduler_Traits, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>;

template class ACE_Hash_Map_Manager_Ex<EDF_Scheduler_Traits::Guid_t, ACE_RB_Tree_Node<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits> > *, Kokyu::Sched_Ready_Queue<EDF_Scheduler_Traits, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>::Guid_Hash, ACE_Equal_To<EDF_Scheduler_Traits::Guid_t>, ACE_Null_Mutex>;

template class ACE_RB_Tree<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>;

template class ACE_RB_Tree_Iterator<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>;

template class ACE_Hash_Map_Entry<EDF_Scheduler_Traits::Guid_t, ACE_RB_Tree_Node<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits> > *>;

template class ACE_RB_Tree_Node<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits> >;

template class Kokyu::EDF_Comparator<EDF_Scheduler_Traits::QoSDescriptor_t>;

template class ACE_Hash_Map_Iterator_Base_Ex<EDF_Scheduler_Traits::Guid_t, ACE_RB_Tree_Node<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits> > *, Kokyu::Sched_Ready_Queue<EDF_Scheduler_Traits, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>::Guid_Hash, ACE_Equal_To<EDF_Scheduler_Traits::Guid_t>, ACE_Null_Mutex>;

template class ACE_RB_Tree_Reverse_Iterator<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>;

template class ACE_RB_Tree_Iterator_Base<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>;

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate Kokyu::DSRT_Dispatcher_Factory<EDF_Scheduler_Traits>
#pragma instantiate Kokyu::DSRT_Dispatcher<EDF_Scheduler_Traits>
#pragma instantiate Kokyu::DSRT_Dispatcher_Impl<EDF_Scheduler_Traits>
#pragma instantiate Kokyu::DSRT_Direct_Dispatcher_Impl<EDF_Scheduler_Traits>
#pragma instantiate Kokyu::DSRT_CV_Dispatcher_Impl<EDF_Scheduler_Traits>
#pragma instantiate Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>
#pragma instantiate Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>

#pragma instantiate Kokyu::Sched_Ready_Queue<EDF_Scheduler_Traits, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>


#pragma instantiate ACE_Hash_Map_Manager_Ex<EDF_Scheduler_Traits::Guid_t, ACE_RB_Tree_Node<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits> > *, Kokyu::Sched_Ready_Queue<EDF_Scheduler_Traits, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>::Guid_Hash, ACE_Equal_To<EDF_Scheduler_Traits::Guid_t>, ACE_Null_Mutex>

#pragma instantiate ACE_RB_Tree<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>

#pragma instantiate ACE_RB_Tree_Iterator<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>

ACE_Hash_Map_Entry<EDF_Scheduler_Traits::Guid_t, ACE_RB_Tree_Node<Koky\
u::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<\
EDF_Scheduler_Traits> >

#pragma instantiate ACE_Hash_Map_Entry<EDF_Scheduler_Traits::Guid_t, ACE_RB_Tree_Node<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits> > *>

#pragma instantiate ACE_RB_Tree_Node<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits> >

#pragma instantiate Kokyu::EDF_Comparator<EDF_Scheduler_Traits::QoSDescriptor_t>

#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<EDF_Scheduler_Traits::Guid_t, ACE_RB_Tree_Node<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits> > *, Kokyu::Sched_Ready_Queue<EDF_Scheduler_Traits, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>::Guid_Hash, ACE_Equal_To<EDF_Scheduler_Traits::Guid_t>, ACE_Null_Mutex>

#pragma instantiate ACE_RB_Tree_Reverse_Iterator<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>

#pragma instantiate ACE_RB_Tree_Iterator_Base<Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::DSRT_Dispatch_Item_var<EDF_Scheduler_Traits>, Kokyu::Comparator_Adapter_Generator<EDF_Scheduler_Traits>::MoreEligible, ACE_Null_Mutex>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
