// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.cs.wustl.edu/~nanbor/projects/CIAO-src/docs/index.html

#include "UAV_svnt.h"
#include "Cookies.h"

namespace UAV_Impl
{
  namespace CIAO_GLUE_BBN_UAV
  {
    UAV_Context::UAV_Context (
    ::Components::CCMHome_ptr home,
    ::CIAO::Session_Container *c,
    UAV_Servant *sv)
    : home_ (::Components::CCMHome::_duplicate (home)),
    container_ (c),
    servant_ (sv)
    {
    }

    UAV_Context::~UAV_Context (void)
    {
    }

    // Operations from ::Components::CCMContext.

    ::Components::Principal_ptr
    UAV_Context::get_caller_principal (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::Components::Principal::_nil ());
    }

    ::Components::CCMHome_ptr
    UAV_Context::get_CCM_home (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return ::Components::CCMHome::_duplicate (this->home_.in ());
    }

    CORBA::Boolean
    UAV_Context::get_rollback_only (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState))
    {
      ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Transaction::UserTransaction_ptr
    UAV_Context::get_user_transaction (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::Components::Transaction::UserTransaction::_nil ());
    }

    CORBA::Boolean
    UAV_Context::is_caller_in_role (
    const char * /* role */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
    }

    void
    UAV_Context::set_rollback_only (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState))
    {
      ACE_THROW (CORBA::NO_IMPLEMENT ());
    }

    // Operations from ::Components::SessionContext interface.

    CORBA::Object_ptr
    UAV_Context::get_CCM_object (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState))
    {
      if (CORBA::is_nil (this->component_.in ()))
      {
        CORBA::Object_var obj =
        this->container_->get_objref (
        this->servant_
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (CORBA::Object::_nil ());

        this->component_ =
        ::BBN_UAV::UAV::_narrow (
        obj.in ()
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (CORBA::Object::_nil ());

        if (CORBA::is_nil (this->component_.in ()))
        {
          ACE_THROW_RETURN (
          ::CORBA::INTERNAL (),
          ::CORBA::Object::_nil ());
        }
      }

      return ::BBN_UAV::UAV::_duplicate (
      this->component_.in ());
    }

    // Operations for UAV receptacles and event sources,
    // defined in ::BBN_UAV::CCM_UAV_Context.

    void
    UAV_Context::push_uav_ready (
    ::BBN_UAV::UAVReady *ev
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {

      ACE_CString my_uuid = this->servant_->component_UUID (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
      my_uuid += "_uav_ready_publisher";

      this->container_->push_event (ev,
                                    my_uuid.c_str ()
                                    ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      /*
      ACE_Active_Map_Manager<
      ::BBN_UAV::TargetLocatedConsumer_var>::iterator end =
      this->ciao_publishes_target_located_map_.end ();

      for (ACE_Active_Map_Manager<
      ::BBN_UAV::TargetLocatedConsumer_var>::iterator iter =
      this->ciao_publishes_target_located_map_.begin ();
      iter != end;
      ++iter)
      {
        ACE_Active_Map_Manager<
        ::BBN_UAV::TargetLocatedConsumer_var>::ENTRY &entry = *iter;

        ::BBN_UAV::TargetLocatedConsumer_var c =
        ::BBN_UAV::TargetLocatedConsumer::_narrow (
        entry.int_id_.in ()
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;

        entry.int_id_->push_TargetLocated (
        ev
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }
      */
    }

    ::Components::Cookie *
    UAV_Context::subscribe_uav_ready (
    ::BBN_UAV::UAVReadyConsumer_ptr c
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::ExceededConnectionLimit))
    {
      if (CORBA::is_nil (c))
      {
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      }

      ::BBN_UAV::UAVReadyConsumer_var sub =
      ::BBN_UAV::UAVReadyConsumer::_duplicate (c);

      ACE_Active_Map_Manager_Key key;
      this->ciao_publishes_uav_ready_map_.bind (sub.in (), key);
      sub._retn ();

      ::Components::Cookie_var retv = new ::CIAO::Map_Key_Cookie (key);
      return retv._retn ();
    }

    ::BBN_UAV::UAVReadyConsumer_ptr
    UAV_Context::unsubscribe_uav_ready (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConnection))
    {
      ::BBN_UAV::UAVReadyConsumer_var retv;
      ACE_Active_Map_Manager_Key key;

      if (ck == 0 || ::CIAO::Map_Key_Cookie::extract (ck, key) == -1)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BBN_UAV::UAVReadyConsumer::_nil ());
      }


      if (this->ciao_publishes_uav_ready_map_.unbind (key, retv) != 0)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BBN_UAV::UAVReadyConsumer::_nil ());
      }

      return retv._retn ();
    }

    // CIAO-specific.

    ::CIAO::Session_Container *
    UAV_Context::_ciao_the_Container (void) const
    {
      return this->container_;
    }

    UAV_Context *
    UAV_Context::_narrow (
    ::Components::SessionContext_ptr p
    ACE_ENV_ARG_DECL_NOT_USED)
    {
      return dynamic_cast<UAV_Context *> (p);
    }
  }

  namespace CIAO_GLUE_BBN_UAV
  {
    UAV_Servant::UAV_Servant (
    ::BBN_UAV::CCM_UAV_ptr exe,
    ::Components::CCMHome_ptr h,
    ::CIAO::Session_Container *c)
    : executor_ (::BBN_UAV::CCM_UAV::_duplicate (exe)),
    container_ (c)
    {
      this->context_ = new UAV_Context (h, c, this);

      ACE_TRY_NEW_ENV
      {
        ::Components::SessionComponent_var scom =
        ::Components::SessionComponent::_narrow (
        exe
        ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;

        if (! ::CORBA::is_nil (scom.in ()))
        {
          scom->set_session_context (
          this->context_
          ACE_ENV_ARG_PARAMETER);
        }
      }
      ACE_CATCHANY
      {
      }
      ACE_ENDTRY;
    }

    UAV_Servant::~UAV_Servant (void)
    {
      ACE_TRY_NEW_ENV
      {
        ::Components::SessionComponent_var scom =
        ::Components::SessionComponent::_narrow (
        this->executor_.in ()
        ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;

        if (! ::CORBA::is_nil (scom.in ()))
        {
          scom->ccm_remove (ACE_ENV_SINGLE_ARG_PARAMETER);
        }
      }
      ACE_CATCHANY
      {
      }
      ACE_ENDTRY;

      this->context_->_remove_ref ();
    }

    // Operations for Navigation interface.

    CORBA::Object_ptr
    UAV_Servant::provide_facet (
    const char *name
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      if (name == 0)
      {
        ACE_THROW_RETURN (
        ::CORBA::BAD_PARAM (),
        ::CORBA::Object::_nil ());
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::CORBA::Object::_nil ());
    }

    ::Components::FacetDescriptions *
    UAV_Servant::get_all_facets (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::FacetDescriptions *
    UAV_Servant::get_named_facets (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    CORBA::Boolean
    UAV_Servant::same_component (
    CORBA::Object_ptr object_ref
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      if (::CORBA::is_nil (object_ref))
      {
        ACE_THROW_RETURN (::CORBA::BAD_PARAM (), 0);
      }

      ::CORBA::Object_var the_other =
      object_ref->_get_component (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      ::CORBA::Object_var me =
      this->context_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return me->_is_equivalent (
      the_other.in ()
      ACE_ENV_ARG_PARAMETER);
    }

    ::Components::EmitterDescriptions *
    UAV_Servant::get_all_emitters (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::EmitterDescriptions *
    UAV_Servant::get_named_emitters (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Cookie *
    UAV_Servant::subscribe_uav_ready (
    ::BBN_UAV::UAVReadyConsumer_ptr c
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::ExceededConnectionLimit))
    {
      return this->context_->subscribe_uav_ready (
      c
      ACE_ENV_ARG_PARAMETER);
    }

    ::BBN_UAV::UAVReadyConsumer_ptr
    UAV_Servant::unsubscribe_uav_ready (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConnection))
    {
      return this->context_->unsubscribe_uav_ready (
      ck
      ACE_ENV_ARG_PARAMETER);
    }

    UAV_Servant::StartCaptureConsumer_start_capture_Servant::StartCaptureConsumer_start_capture_Servant (
    ::BBN_UAV::CCM_UAV_ptr executor,
    ::BBN_UAV::CCM_UAV_Context_ptr c)
    : executor_ (::BBN_UAV::CCM_UAV::_duplicate (executor)),
    ctx_ (::BBN_UAV::CCM_UAV_Context::_duplicate (c))
    {
    }

    UAV_Servant::StartCaptureConsumer_start_capture_Servant::~StartCaptureConsumer_start_capture_Servant (void)
    {
    }

    CORBA::Object_ptr
    UAV_Servant::StartCaptureConsumer_start_capture_Servant::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return this->ctx_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    void
    UAV_Servant::StartCaptureConsumer_start_capture_Servant::push_StartCapture (
    ::BBN_UAV::StartCapture *evt
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      this->executor_->push_start_capture (
      evt
      ACE_ENV_ARG_PARAMETER);
    }

    // Inherited from ::Components::EventConsumerBase.
    void
    UAV_Servant::StartCaptureConsumer_start_capture_Servant::push_event (
    ::Components::EventBase *ev
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::BadEventType))
    {
      ::BBN_UAV::StartCapture_var ev_type =
      ::BBN_UAV::StartCapture::_downcast (ev);

      if (ev_type != 0)
      {
        this->push_StartCapture (
        ev_type.in ()
        ACE_ENV_ARG_PARAMETER);

        return;
      }

      ACE_THROW (::Components::BadEventType ());
    }

    ::BBN_UAV::StartCaptureConsumer_ptr
    UAV_Servant::get_consumer_start_capture (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      if (CORBA::is_nil (this->consumes_start_capture_.in ()))
      {
        UAV_Servant::StartCaptureConsumer_start_capture_Servant *svt =
        new UAV_Servant::StartCaptureConsumer_start_capture_Servant (
        this->executor_.in (),
        this->context_);
        PortableServer::ServantBase_var safe_servant (svt);

        CORBA::Object_var obj =
        this->container_->install_servant (
        svt
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (::BBN_UAV::StartCaptureConsumer::_nil ());

        ::BBN_UAV::StartCaptureConsumer_var eco =
        ::BBN_UAV::StartCaptureConsumer::_narrow (
        obj.in ()
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (::BBN_UAV::StartCaptureConsumer::_nil ());

        this->consumes_start_capture_ = eco;
      }

      return ::BBN_UAV::StartCaptureConsumer::_duplicate (this->consumes_start_capture_.in ());
    }

    ::Components::Cookie *
    UAV_Servant::connect (
    const char *name,
    ::CORBA::Object_ptr connection
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::InvalidConnection,
    ::Components::AlreadyConnected,
    ::Components::ExceededConnectionLimit))
    {
      // If the component has no receptacles, this will be unused.
      ACE_UNUSED_ARG (connection);

      if (name == 0)
      {
        ACE_THROW_RETURN (::Components::InvalidName (), 0);
      }

      ACE_THROW_RETURN (::Components::InvalidName (), 0);
    }

    CORBA::Object_ptr
    UAV_Servant::disconnect (
    const char *name,
    ::Components::Cookie * /* ck */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::InvalidConnection,
    ::Components::CookieRequired,
    ::Components::NoConnection))
    {
      if (name == 0)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidName (),
        ::CORBA::Object::_nil ());
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::CORBA::Object::_nil ());
    }

    ::Components::ConnectionDescriptions *
    UAV_Servant::get_connections (
    const char * /* name */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ReceptacleDescriptions *
    UAV_Servant::get_all_receptacles (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ReceptacleDescriptions *
    UAV_Servant::get_named_receptacles (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::EventConsumerBase_ptr
    UAV_Servant::get_consumer (
    const char *sink_name
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      if (sink_name == 0)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidName (),
        ::Components::EventConsumerBase::_nil ());
      }

      if (ACE_OS::strcmp (sink_name, "start_capture") == 0)
      {
        return this->get_consumer_start_capture (ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    void
    UAV_Servant::connect_consumer (
    const char * /* emitter_name */,
    ::Components::EventConsumerBase_ptr /*consumer*/
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::AlreadyConnected,
    ::Components::InvalidConnection))
    {
      ACE_THROW (::CORBA::NO_IMPLEMENT ());
    }

    ::Components::EventConsumerBase_ptr
    UAV_Servant::disconnect_consumer (
    const char * /* source_name */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::NoConnection))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ConsumerDescriptions *
    UAV_Servant::get_all_consumers (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ConsumerDescriptions *
    UAV_Servant::get_named_consumers (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Cookie *
    UAV_Servant::subscribe (
    const char *publisher_name,
    ::Components::EventConsumerBase_ptr subscribe
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::InvalidConnection,
    ::Components::ExceededConnectionLimit))
    {
      // Just in case there are no if blocks
      ACE_UNUSED_ARG (subscribe);

      if (publisher_name == 0)
      {
        ACE_THROW_RETURN (::Components::InvalidName (), 0);
      }

      if (ACE_OS::strcmp (publisher_name, "uav_ready") == 0)
      {
        ::BBN_UAV::UAVReadyConsumer_var _ciao_consumer =
        ::BBN_UAV::UAVReadyConsumer::_narrow (
        subscribe
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (::CORBA::is_nil (_ciao_consumer.in ()))
        {
          ACE_THROW_RETURN (::Components::InvalidConnection (), 0);
        }

        return this->subscribe_uav_ready (
        _ciao_consumer.in ()
        ACE_ENV_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (::Components::InvalidName (), 0);
    }

    ::Components::EventConsumerBase_ptr
    UAV_Servant::unsubscribe (
    const char *publisher_name,
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::InvalidConnection))
    {
      // Just in case there are no if blocks
      ACE_UNUSED_ARG (ck);

      if (publisher_name == 0)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidName (),
        ::Components::EventConsumerBase::_nil ());
      }

      if (ACE_OS::strcmp (publisher_name, "uav_ready") == 0)
      {
        return this->unsubscribe_uav_ready (
        ck
        ACE_ENV_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    ::Components::PublisherDescriptions *
    UAV_Servant::get_all_publishers (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::PublisherDescriptions *
    UAV_Servant::get_named_publishers (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    // Operations for CCMObject interface.

    void
    UAV_Servant::component_UUID (
    const char * new_component_UUID
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      this->component_UUID_ = new_component_UUID;
    }

    CIAO::CONNECTION_ID
    UAV_Servant::component_UUID (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return CORBA::string_dup (this->component_UUID_.c_str ());
    }

    CORBA::IRObject_ptr
    UAV_Servant::get_component_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    ::Components::CCMHome_ptr
    UAV_Servant::get_ccm_home (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return this->context_->get_CCM_home (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::PrimaryKeyBase *
    UAV_Servant::get_primary_key (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::NoKeyAvailable))
    {
      ACE_THROW_RETURN (::Components::NoKeyAvailable (), 0);
    }

    void
    UAV_Servant::configuration_complete (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConfiguration))
    {
      // CIAO to-do
    }

    void
    UAV_Servant::remove (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::RemoveFailure))
    {
      // CIAO to-do
    }

    ::Components::ComponentPortDescription *
    UAV_Servant::get_all_ports (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::Components::ComponentPortDescription_var retv =
      new OBV_Components::ComponentPortDescription;

      ::Components::FacetDescriptions_var facets_desc =
      this->get_all_facets (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      ::Components::ReceptacleDescriptions_var receptacle_desc =
      this->get_all_receptacles (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      ::Components::ConsumerDescriptions_var consumer_desc =
      this->get_all_consumers (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      ::Components::EmitterDescriptions_var emitter_desc =
      this->get_all_emitters (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      ::Components::PublisherDescriptions_var publisher_desc =
      this->get_all_publishers (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      retv->facets (facets_desc.in ());
      retv->receptacles (receptacle_desc.in ());
      retv->consumers (consumer_desc.in ());
      retv->emitters (emitter_desc.in ());
      retv->publishers (publisher_desc.in ());

      return retv._retn ();
    }

    CORBA::Object_ptr
    UAV_Servant::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::Components::SessionContext_var sc =
      ::Components::SessionContext::_narrow (
      this->context_
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::CORBA::Object::_nil ());

      if (! ::CORBA::is_nil (sc.in ()))
      {
        return sc->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ::Components::EntityContext_var ec =
      ::Components::EntityContext::_narrow (
      this->context_
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::CORBA::Object::_nil ());

      if (! ::CORBA::is_nil (ec.in ()))
      {
        return ec->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (
      ::CORBA::INTERNAL (),
      ::CORBA::Object::_nil ());
    }

    // CIAO-specific operations.

    void
    UAV_Servant::_ciao_activate (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::Components::SessionComponent_var temp =
      ::Components::SessionComponent::_narrow (
      this->executor_.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      if (! ::CORBA::is_nil (temp.in ()))
      {
        temp->ccm_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      }
    }

    void
    UAV_Servant::_ciao_passivate (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::Components::SessionComponent_var temp =
      ::Components::SessionComponent::_narrow (
      this->executor_.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      if (! ::CORBA::is_nil (temp.in ()))
      {
        temp->ccm_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
      }
    }

    // Supported operations.

    // Component attribute operations.
  }

  namespace CIAO_GLUE_BBN_UAV
  {
    UAVHome_Servant::UAVHome_Servant (
    ::BBN_UAV::CCM_UAVHome_ptr exe,
    ::CIAO::Session_Container *c)
    : executor_ (::BBN_UAV::CCM_UAVHome::_duplicate (exe)),
    container_ (c)
    {
    }

    UAVHome_Servant::~UAVHome_Servant (void)
    {
    }

    // Home factory and other operations.

    // Home attribute operations.

    // Operations for keyless home interface.

    ::Components::CCMObject_ptr
    UAVHome_Servant::create_component (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::CreateFailure))
    {
      return this->create (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    // Operations for implicit home interface.

    ::BBN_UAV::UAV_ptr
    UAVHome_Servant::create (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::CreateFailure))
    {
      if (this->executor_.in () == 0)
      {
        ACE_THROW_RETURN (
        ::CORBA::INTERNAL (),
        ::BBN_UAV::UAV::_nil ());
      }

      Components::EnterpriseComponent_var _ciao_ec =
      this->executor_->create (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::UAV::_nil ());

      ::BBN_UAV::CCM_UAV_var _ciao_comp =
      ::BBN_UAV::CCM_UAV::_narrow (
      _ciao_ec.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::UAV::_nil ());

      return this->_ciao_activate_component (
      _ciao_comp.in ()
      ACE_ENV_ARG_PARAMETER);
    }

    // Operations for CCMHome interface.

    ::CORBA::IRObject_ptr
    UAVHome_Servant::get_component_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    ::CORBA::IRObject_ptr
    UAVHome_Servant::get_home_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    void
    UAVHome_Servant::remove_component (
    ::Components::CCMObject_ptr comp
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::RemoveFailure))
    {
      ::BBN_UAV::UAV_var _ciao_comp =
      ::BBN_UAV::UAV::_narrow (
      comp
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      if (CORBA::is_nil (_ciao_comp.in ()))
      {
        ACE_THROW (CORBA::INTERNAL ());
      }

      _ciao_comp->remove (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      this->_ciao_passivate_component (
      _ciao_comp.in ()
      ACE_ENV_ARG_PARAMETER);
    }

    // CIAO-specific operations.

    ::BBN_UAV::UAV_ptr
    UAVHome_Servant::_ciao_activate_component (
    ::BBN_UAV::CCM_UAV_ptr exe
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::CORBA::Object_var hobj =
      this->container_->get_objref (
      this
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::UAV::_nil ());

      ::Components::CCMHome_var home =
      ::Components::CCMHome::_narrow (
      hobj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::UAV::_nil ());

      UAV_Servant *svt =
      new UAV_Servant (
      exe,
      home.in (),
      this->container_);

      PortableServer::ServantBase_var safe (svt);
      PortableServer::ObjectId_var oid;

      CORBA::Object_var objref =
      this->container_->install_component (
      svt,
      oid.out ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::UAV::_nil ());

      svt->_ciao_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::UAV::_nil ());

      ::BBN_UAV::UAV_var ho =
      ::BBN_UAV::UAV::_narrow (
      objref.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::UAV::_nil ());

      if (this->component_map_.bind (oid.in (), svt) == 0)
      {
        safe._retn ();
      }

      return ho._retn ();
    }

    void
    UAVHome_Servant::_ciao_passivate_component (
    ::BBN_UAV::UAV_ptr comp
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      PortableServer::ObjectId_var oid;

      this->container_->uninstall_component (
      comp,
      oid.out ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      UAV_Servant *servant = 0;

      if (this->component_map_.unbind (oid.in (), servant) == 0)
      {
        PortableServer::ServantBase_var safe (servant);

        servant->_ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }
    }
  }

  extern "C" UAV_SVNT_Export ::PortableServer::Servant
  createUAVHome_Servant (
  ::Components::HomeExecutorBase_ptr p,
  CIAO::Session_Container *c
  ACE_ENV_ARG_DECL)
  {
    if (p == 0)
    {
      return 0;
    }

    ::BBN_UAV::CCM_UAVHome_var x =
    ::BBN_UAV::CCM_UAVHome::_narrow (
    p
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    if (::CORBA::is_nil (x.in ()))
    {
      return 0;
    }

    return new
    CIAO_GLUE_BBN_UAV::UAVHome_Servant (
    x.in (),
    c);
  }
}
