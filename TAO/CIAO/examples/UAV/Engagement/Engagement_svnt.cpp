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

#include "Engagement_svnt.h"
#include "Cookies.h"

namespace Engagement_Impl
{
  namespace CIAO_GLUE_BBN_UAV
  {
    Engagement_Context::Engagement_Context (
    ::Components::CCMHome_ptr home,
    ::CIAO::Session_Container *c,
    Engagement_Servant *sv)
    : home_ (::Components::CCMHome::_duplicate (home)),
    container_ (c),
    servant_ (sv)
    {
    }

    Engagement_Context::~Engagement_Context (void)
    {
    }

    // Operations from ::Components::CCMContext.

    ::Components::Principal_ptr
    Engagement_Context::get_caller_principal (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::Components::Principal::_nil ());
    }

    ::Components::CCMHome_ptr
    Engagement_Context::get_CCM_home (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return ::Components::CCMHome::_duplicate (this->home_.in ());
    }

    CORBA::Boolean
    Engagement_Context::get_rollback_only (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState))
    {
      ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Transaction::UserTransaction_ptr
    Engagement_Context::get_user_transaction (
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
    Engagement_Context::is_caller_in_role (
    const char * /* role */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
    }

    void
    Engagement_Context::set_rollback_only (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState))
    {
      ACE_THROW (CORBA::NO_IMPLEMENT ());
    }

    // Operations from ::Components::SessionContext interface.

    CORBA::Object_ptr
    Engagement_Context::get_CCM_object (
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
        ::BBN_UAV::Engagement::_narrow (
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

      return ::BBN_UAV::Engagement::_duplicate (
      this->component_.in ());
    }

    // Operations for Engagement receptacles and event sources,
    // defined in ::BBN_UAV::CCM_Engagement_Context.

    void
    Engagement_Context::push_start_engage (
    ::BBN_UAV::StartEngage *ev
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {

      ACE_CString my_uuid = this->servant_->component_UUID (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
      my_uuid += "_start_engage_publisher";

      this->container_->push_event (ev,
                                    my_uuid.c_str ()
                                    ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      /*
      ACE_Active_Map_Manager<
      ::BBN_UAV::StartEngageConsumer_var>::iterator end =
      this->ciao_publishes_start_engage_map_.end ();

      for (ACE_Active_Map_Manager<
      ::BBN_UAV::StartEngageConsumer_var>::iterator iter =
      this->ciao_publishes_start_engage_map_.begin ();
      iter != end;
      ++iter)
      {
        ACE_Active_Map_Manager<
        ::BBN_UAV::StartEngageConsumer_var>::ENTRY &entry = *iter;

        ::BBN_UAV::StartEngageConsumer_var c =
        ::BBN_UAV::StartEngageConsumer::_narrow (
        entry.int_id_.in ()
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;

        entry.int_id_->push_StartEngage (
        ev
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }
      */
    }

    ::Components::Cookie *
    Engagement_Context::subscribe_start_engage (
    ::BBN_UAV::StartEngageConsumer_ptr c
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::ExceededConnectionLimit))
    {
      if (CORBA::is_nil (c))
      {
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      }

      ::BBN_UAV::StartEngageConsumer_var sub =
      ::BBN_UAV::StartEngageConsumer::_duplicate (c);

      ACE_Active_Map_Manager_Key key;
      this->ciao_publishes_start_engage_map_.bind (sub.in (), key);
      sub._retn ();

      ::Components::Cookie_var retv = new ::CIAO::Map_Key_Cookie (key);
      return retv._retn ();
    }

    ::BBN_UAV::StartEngageConsumer_ptr
    Engagement_Context::unsubscribe_start_engage (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConnection))
    {
      ::BBN_UAV::StartEngageConsumer_var retv;
      ACE_Active_Map_Manager_Key key;

      if (ck == 0 || ::CIAO::Map_Key_Cookie::extract (ck, key) == -1)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BBN_UAV::StartEngageConsumer::_nil ());
      }


      if (this->ciao_publishes_start_engage_map_.unbind (key, retv) != 0)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BBN_UAV::StartEngageConsumer::_nil ());
      }

      return retv._retn ();
    }

    void
    Engagement_Context::push_prepare_move (
    ::BBN_UAV::PrepareMove *ev
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {

      ACE_CString my_uuid = this->servant_->component_UUID (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
      my_uuid += "_prepare_move_publisher";

      this->container_->push_event (ev,
                                    my_uuid.c_str ()
                                    ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      /*
      ACE_Active_Map_Manager<
      ::BBN_UAV::PrepareMoveConsumer_var>::iterator end =
      this->ciao_publishes_prepare_move_map_.end ();

      for (ACE_Active_Map_Manager<
      ::BBN_UAV::PrepareMoveConsumer_var>::iterator iter =
      this->ciao_publishes_prepare_move_map_.begin ();
      iter != end;
      ++iter)
      {
        ACE_Active_Map_Manager<
        ::BBN_UAV::PrepareMoveConsumer_var>::ENTRY &entry = *iter;

        ::BBN_UAV::PrepareMoveConsumer_var c =
        ::BBN_UAV::PrepareMoveConsumer::_narrow (
        entry.int_id_.in ()
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;

        entry.int_id_->push_PrepareMove (
        ev
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }
      */
    }

    ::Components::Cookie *
    Engagement_Context::subscribe_prepare_move (
    ::BBN_UAV::PrepareMoveConsumer_ptr c
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::ExceededConnectionLimit))
    {
      if (CORBA::is_nil (c))
      {
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      }

      ::BBN_UAV::PrepareMoveConsumer_var sub =
      ::BBN_UAV::PrepareMoveConsumer::_duplicate (c);

      ACE_Active_Map_Manager_Key key;
      this->ciao_publishes_prepare_move_map_.bind (sub.in (), key);
      sub._retn ();

      ::Components::Cookie_var retv = new ::CIAO::Map_Key_Cookie (key);
      return retv._retn ();
    }

    ::BBN_UAV::PrepareMoveConsumer_ptr
    Engagement_Context::unsubscribe_prepare_move (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConnection))
    {
      ::BBN_UAV::PrepareMoveConsumer_var retv;
      ACE_Active_Map_Manager_Key key;

      if (ck == 0 || ::CIAO::Map_Key_Cookie::extract (ck, key) == -1)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BBN_UAV::PrepareMoveConsumer::_nil ());
      }


      if (this->ciao_publishes_prepare_move_map_.unbind (key, retv) != 0)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BBN_UAV::PrepareMoveConsumer::_nil ());
      }

      return retv._retn ();
    }

    // CIAO-specific.

    ::CIAO::Session_Container *
    Engagement_Context::_ciao_the_Container (void) const
    {
      return this->container_;
    }

    Engagement_Context *
    Engagement_Context::_narrow (
    ::Components::SessionContext_ptr p
    ACE_ENV_ARG_DECL_NOT_USED)
    {
      return dynamic_cast<Engagement_Context *> (p);
    }
  }

  namespace CIAO_GLUE_BBN_UAV
  {
    Engagement_Servant::Engagement_Servant (
    ::BBN_UAV::CCM_Engagement_ptr exe,
    ::Components::CCMHome_ptr h,
    ::CIAO::Session_Container *c)
    : executor_ (::BBN_UAV::CCM_Engagement::_duplicate (exe)),
    container_ (c)
    {
      this->context_ = new Engagement_Context (h, c, this);

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

    Engagement_Servant::~Engagement_Servant (void)
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
    Engagement_Servant::provide_facet (
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
    Engagement_Servant::get_all_facets (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::FacetDescriptions *
    Engagement_Servant::get_named_facets (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    CORBA::Boolean
    Engagement_Servant::same_component (
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
    Engagement_Servant::get_all_emitters (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::EmitterDescriptions *
    Engagement_Servant::get_named_emitters (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Cookie *
    Engagement_Servant::subscribe_start_engage (
    ::BBN_UAV::StartEngageConsumer_ptr c
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::ExceededConnectionLimit))
    {
      return this->context_->subscribe_start_engage (
      c
      ACE_ENV_ARG_PARAMETER);
    }

    ::BBN_UAV::StartEngageConsumer_ptr
    Engagement_Servant::unsubscribe_start_engage (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConnection))
    {
      return this->context_->unsubscribe_start_engage (
      ck
      ACE_ENV_ARG_PARAMETER);
    }

    ::Components::Cookie *
    Engagement_Servant::subscribe_prepare_move (
    ::BBN_UAV::PrepareMoveConsumer_ptr c
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::ExceededConnectionLimit))
    {
      return this->context_->subscribe_prepare_move (
      c
      ACE_ENV_ARG_PARAMETER);
    }

    ::BBN_UAV::PrepareMoveConsumer_ptr
    Engagement_Servant::unsubscribe_prepare_move (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConnection))
    {
      return this->context_->unsubscribe_prepare_move (
      ck
      ACE_ENV_ARG_PARAMETER);
    }

    Engagement_Servant::PrepareEngageConsumer_prepare_engage_Servant::PrepareEngageConsumer_prepare_engage_Servant (
    ::BBN_UAV::CCM_Engagement_ptr executor,
    ::BBN_UAV::CCM_Engagement_Context_ptr c)
    : executor_ (::BBN_UAV::CCM_Engagement::_duplicate (executor)),
    ctx_ (::BBN_UAV::CCM_Engagement_Context::_duplicate (c))
    {
    }

    Engagement_Servant::PrepareEngageConsumer_prepare_engage_Servant::~PrepareEngageConsumer_prepare_engage_Servant (void)
    {
    }

    CORBA::Object_ptr
    Engagement_Servant::PrepareEngageConsumer_prepare_engage_Servant::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return this->ctx_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    void
    Engagement_Servant::PrepareEngageConsumer_prepare_engage_Servant::push_PrepareEngage (
    ::BBN_UAV::PrepareEngage *evt
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      this->executor_->push_prepare_engage (
      evt
      ACE_ENV_ARG_PARAMETER);
    }

    // Inherited from ::Components::EventConsumerBase.
    void
    Engagement_Servant::PrepareEngageConsumer_prepare_engage_Servant::push_event (
    ::Components::EventBase *ev
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::BadEventType))
    {
      ::BBN_UAV::PrepareEngage_var ev_type =
      ::BBN_UAV::PrepareEngage::_downcast (ev);

      if (ev_type != 0)
      {
        this->push_PrepareEngage (
        ev_type.in ()
        ACE_ENV_ARG_PARAMETER);

        return;
      }

      ACE_THROW (::Components::BadEventType ());
    }

    ::BBN_UAV::PrepareEngageConsumer_ptr
    Engagement_Servant::get_consumer_prepare_engage (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      if (CORBA::is_nil (this->consumes_prepare_engage_.in ()))
      {
        Engagement_Servant::PrepareEngageConsumer_prepare_engage_Servant *svt =
        new Engagement_Servant::PrepareEngageConsumer_prepare_engage_Servant (
        this->executor_.in (),
        this->context_);
        PortableServer::ServantBase_var safe_servant (svt);

        CORBA::Object_var obj =
        this->container_->install_servant (
        svt
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (::BBN_UAV::PrepareEngageConsumer::_nil ());

        ::BBN_UAV::PrepareEngageConsumer_var eco =
        ::BBN_UAV::PrepareEngageConsumer::_narrow (
        obj.in ()
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (::BBN_UAV::PrepareEngageConsumer::_nil ());

        this->consumes_prepare_engage_ = eco;
      }

      return ::BBN_UAV::PrepareEngageConsumer::_duplicate (this->consumes_prepare_engage_.in ());
    }

    ::Components::Cookie *
    Engagement_Servant::connect (
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
    Engagement_Servant::disconnect (
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
    Engagement_Servant::get_connections (
    const char * /* name */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ReceptacleDescriptions *
    Engagement_Servant::get_all_receptacles (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ReceptacleDescriptions *
    Engagement_Servant::get_named_receptacles (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::EventConsumerBase_ptr
    Engagement_Servant::get_consumer (
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

      if (ACE_OS::strcmp (sink_name, "prepare_engage") == 0)
      {
        return this->get_consumer_prepare_engage (ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    void
    Engagement_Servant::connect_consumer (
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
    Engagement_Servant::disconnect_consumer (
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
    Engagement_Servant::get_all_consumers (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ConsumerDescriptions *
    Engagement_Servant::get_named_consumers (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Cookie *
    Engagement_Servant::subscribe (
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

      if (ACE_OS::strcmp (publisher_name, "start_engage") == 0)
      {
        ::BBN_UAV::StartEngageConsumer_var _ciao_consumer =
        ::BBN_UAV::StartEngageConsumer::_narrow (
        subscribe
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (::CORBA::is_nil (_ciao_consumer.in ()))
        {
          ACE_THROW_RETURN (::Components::InvalidConnection (), 0);
        }

        return this->subscribe_start_engage (
        _ciao_consumer.in ()
        ACE_ENV_ARG_PARAMETER);
      }

      if (ACE_OS::strcmp (publisher_name, "prepare_move") == 0)
      {
        ::BBN_UAV::PrepareMoveConsumer_var _ciao_consumer =
        ::BBN_UAV::PrepareMoveConsumer::_narrow (
        subscribe
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (::CORBA::is_nil (_ciao_consumer.in ()))
        {
          ACE_THROW_RETURN (::Components::InvalidConnection (), 0);
        }

        return this->subscribe_prepare_move (
        _ciao_consumer.in ()
        ACE_ENV_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (::Components::InvalidName (), 0);
    }

    ::Components::EventConsumerBase_ptr
    Engagement_Servant::unsubscribe (
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

      if (ACE_OS::strcmp (publisher_name, "start_engage") == 0)
      {
        return this->unsubscribe_start_engage (
        ck
        ACE_ENV_ARG_PARAMETER);
      }

      if (ACE_OS::strcmp (publisher_name, "prepare_move") == 0)
      {
        return this->unsubscribe_prepare_move (
        ck
        ACE_ENV_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    ::Components::PublisherDescriptions *
    Engagement_Servant::get_all_publishers (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::PublisherDescriptions *
    Engagement_Servant::get_named_publishers (
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
    Engagement_Servant::component_UUID (
    const char * new_component_UUID
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      this->component_UUID_ = new_component_UUID;
    }

    CIAO::CONNECTION_ID
    Engagement_Servant::component_UUID (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return CORBA::string_dup (this->component_UUID_.c_str ());
    }

    CORBA::IRObject_ptr
    Engagement_Servant::get_component_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    ::Components::CCMHome_ptr
    Engagement_Servant::get_ccm_home (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return this->context_->get_CCM_home (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::PrimaryKeyBase *
    Engagement_Servant::get_primary_key (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::NoKeyAvailable))
    {
      ACE_THROW_RETURN (::Components::NoKeyAvailable (), 0);
    }

    void
    Engagement_Servant::configuration_complete (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConfiguration))
    {
      // CIAO to-do
    }

    void
    Engagement_Servant::remove (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::RemoveFailure))
    {
      // CIAO to-do
    }

    ::Components::ComponentPortDescription *
    Engagement_Servant::get_all_ports (
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
    Engagement_Servant::_get_component (
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
    Engagement_Servant::_ciao_activate (
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
    Engagement_Servant::_ciao_passivate (
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
    EngagementHome_Servant::EngagementHome_Servant (
    ::BBN_UAV::CCM_EngagementHome_ptr exe,
    ::CIAO::Session_Container *c)
    : executor_ (::BBN_UAV::CCM_EngagementHome::_duplicate (exe)),
    container_ (c)
    {
    }

    EngagementHome_Servant::~EngagementHome_Servant (void)
    {
    }

    // Home factory and other operations.

    // Home attribute operations.

    // Operations for keyless home interface.

    ::Components::CCMObject_ptr
    EngagementHome_Servant::create_component (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::CreateFailure))
    {
      return this->create (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    // Operations for implicit home interface.

    ::BBN_UAV::Engagement_ptr
    EngagementHome_Servant::create (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::CreateFailure))
    {
      if (this->executor_.in () == 0)
      {
        ACE_THROW_RETURN (
        ::CORBA::INTERNAL (),
        ::BBN_UAV::Engagement::_nil ());
      }

      Components::EnterpriseComponent_var _ciao_ec =
      this->executor_->create (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::Engagement::_nil ());

      ::BBN_UAV::CCM_Engagement_var _ciao_comp =
      ::BBN_UAV::CCM_Engagement::_narrow (
      _ciao_ec.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::Engagement::_nil ());

      return this->_ciao_activate_component (
      _ciao_comp.in ()
      ACE_ENV_ARG_PARAMETER);
    }

    // Operations for CCMHome interface.

    ::CORBA::IRObject_ptr
    EngagementHome_Servant::get_component_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    ::CORBA::IRObject_ptr
    EngagementHome_Servant::get_home_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    void
    EngagementHome_Servant::remove_component (
    ::Components::CCMObject_ptr comp
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::RemoveFailure))
    {
      ::BBN_UAV::Engagement_var _ciao_comp =
      ::BBN_UAV::Engagement::_narrow (
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

    ::BBN_UAV::Engagement_ptr
    EngagementHome_Servant::_ciao_activate_component (
    ::BBN_UAV::CCM_Engagement_ptr exe
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::CORBA::Object_var hobj =
      this->container_->get_objref (
      this
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::Engagement::_nil ());

      ::Components::CCMHome_var home =
      ::Components::CCMHome::_narrow (
      hobj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::Engagement::_nil ());

      Engagement_Servant *svt =
      new Engagement_Servant (
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
      ACE_CHECK_RETURN (::BBN_UAV::Engagement::_nil ());

      svt->_ciao_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::Engagement::_nil ());

      ::BBN_UAV::Engagement_var ho =
      ::BBN_UAV::Engagement::_narrow (
      objref.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BBN_UAV::Engagement::_nil ());

      if (this->component_map_.bind (oid.in (), svt) == 0)
      {
        safe._retn ();
      }

      return ho._retn ();
    }

    void
    EngagementHome_Servant::_ciao_passivate_component (
    ::BBN_UAV::Engagement_ptr comp
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      PortableServer::ObjectId_var oid;

      this->container_->uninstall_component (
      comp,
      oid.out ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      Engagement_Servant *servant = 0;

      if (this->component_map_.unbind (oid.in (), servant) == 0)
      {
        PortableServer::ServantBase_var safe (servant);

        servant->_ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }
    }
  }

  extern "C" ENGAGEMENT_SVNT_Export ::PortableServer::Servant
  createEngagementHome_Servant (
  ::Components::HomeExecutorBase_ptr p,
  CIAO::Session_Container *c
  ACE_ENV_ARG_DECL)
  {
    if (p == 0)
    {
      return 0;
    }

    ::BBN_UAV::CCM_EngagementHome_var x =
    ::BBN_UAV::CCM_EngagementHome::_narrow (
    p
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    if (::CORBA::is_nil (x.in ()))
    {
      return 0;
    }

    return new
    CIAO_GLUE_BBN_UAV::EngagementHome_Servant (
    x.in (),
    c);
  }
}
