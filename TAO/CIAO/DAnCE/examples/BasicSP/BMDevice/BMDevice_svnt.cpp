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
//    http://www.dre.vanderbilt.edu/CIAO

#include "BMDevice_svnt.h"
#include "Cookies.h"
#include "ciao/Servant_Activator.h"
#include "ciao/Port_Activator_T.h"

namespace BMDevice_Impl
{
  namespace CIAO_GLUE_BasicSP
  {
    template <typename T>
    ReadData_Servant_T<T>::ReadData_Servant_T (
    ::BasicSP::CCM_ReadData_ptr executor,
    ::Components::CCMContext_ptr c)
    : executor_ (::BasicSP::CCM_ReadData::_duplicate (executor)),
    ctx_ (::Components::CCMContext::_duplicate (c))
    {
    }

    template <typename T>
    ReadData_Servant_T<T>::~ReadData_Servant_T (void)
    {
    }

    template <typename T>
    char *
    ReadData_Servant_T<T>::get_data (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return this->executor_->get_data (
      ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    template <typename T>
    CORBA::Object_ptr
    ReadData_Servant_T<T>::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::Components::SessionContext_var sc =
      ::Components::SessionContext::_narrow (
      this->ctx_.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());

      if (! CORBA::is_nil (sc.in ()))
      {
        return sc->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ::Components::EntityContext_var ec =
      ::Components::EntityContext::_narrow (
      this->ctx_.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());

      if (! CORBA::is_nil (ec.in ()))
      {
        return ec->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (CORBA::INTERNAL (), 0);
    }
  }

  namespace CIAO_GLUE_BasicSP
  {
    BMDevice_Context::BMDevice_Context (
    ::Components::CCMHome_ptr home,
    ::CIAO::Session_Container *c,
    BMDevice_Servant *sv)
    : home_ (::Components::CCMHome::_duplicate (home)),
    container_ (c),
    servant_ (sv)
    {
    }

    BMDevice_Context::~BMDevice_Context (void)
    {
    }

    // Operations from ::Components::CCMContext.

    ::Components::Principal_ptr
    BMDevice_Context::get_caller_principal (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::Components::Principal::_nil ());
    }

    ::Components::CCMHome_ptr
    BMDevice_Context::get_CCM_home (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return ::Components::CCMHome::_duplicate (this->home_.in ());
    }

    CORBA::Boolean
    BMDevice_Context::get_rollback_only (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState))
    {
      ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Transaction::UserTransaction_ptr
    BMDevice_Context::get_user_transaction (
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
    BMDevice_Context::is_caller_in_role (
    const char * /* role */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
    }

    void
    BMDevice_Context::set_rollback_only (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState))
    {
      ACE_THROW (CORBA::NO_IMPLEMENT ());
    }

    // Operations from ::Components::SessionContextinterface.

    CORBA::Object_ptr
    BMDevice_Context::get_CCM_object (
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
        ::BasicSP::BMDevice::_narrow (
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

      return ::BasicSP::BMDevice::_duplicate (
      this->component_.in ());
    }

    // Operations for BMDevice receptacles and event sources,
    // defined in ::BasicSP::CCM_BMDevice_Context.

    void
    BMDevice_Context::push_data_available (
    ::BasicSP::DataAvailable *ev
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_CString my_uuid = this->servant_->component_UUID (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
      my_uuid += "_data_available_publisher";

      this->container_->push_event (ev,
                                    my_uuid.c_str ()
                                    ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
      /*
      ACE_Active_Map_Manager< 
      ::BasicSP::DataAvailableConsumer_var>::iterator end =
      this->ciao_publishes_data_available_map_.end ();

      for (ACE_Active_Map_Manager< 
      ::BasicSP::DataAvailableConsumer_var>::iterator iter =
      this->ciao_publishes_data_available_map_.begin ();
      iter != end;
      ++iter)
      {
        ACE_Active_Map_Manager< 
        ::BasicSP::DataAvailableConsumer_var>::ENTRY &entry = *iter;

        ::BasicSP::DataAvailableConsumer_var c =
        ::BasicSP::DataAvailableConsumer::_narrow (
        entry.int_id_.in ()
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;

        entry.int_id_->push_DataAvailable (
        ev
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }
      */
    }

    ::Components::Cookie *
    BMDevice_Context::subscribe_data_available (
    ::BasicSP::DataAvailableConsumer_ptr c
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::ExceededConnectionLimit))
    {
      if (CORBA::is_nil (c))
      {
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      }

      ::BasicSP::DataAvailableConsumer_var sub =
      ::BasicSP::DataAvailableConsumer::_duplicate (c);

      ACE_Active_Map_Manager_Key key;
      this->ciao_publishes_data_available_map_.bind (sub.in (), key);
      sub._retn ();

      ::Components::Cookie_var retv = new ::CIAO::Map_Key_Cookie (key);
      return retv._retn ();
    }

    ::BasicSP::DataAvailableConsumer_ptr
    BMDevice_Context::unsubscribe_data_available (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConnection))
    {
      ::BasicSP::DataAvailableConsumer_var retv;
      ACE_Active_Map_Manager_Key key;

      if (ck == 0 || ::CIAO::Map_Key_Cookie::extract (ck, key) == false)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BasicSP::DataAvailableConsumer::_nil ());
      }

      if (this->ciao_publishes_data_available_map_.unbind (key, retv) != 0)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BasicSP::DataAvailableConsumer::_nil ());
      }

      return retv._retn ();
    }

    // CIAO-specific.

    ::CIAO::Session_Container *
    BMDevice_Context::_ciao_the_Container (void) const
    {
      return this->container_;
    }

    BMDevice_Context *
    BMDevice_Context::_narrow (
    ::Components::SessionContext_ptr p
    ACE_ENV_ARG_DECL_NOT_USED)
    {
      return dynamic_cast<BMDevice_Context *> (p);
    }
  }

  namespace CIAO_GLUE_BasicSP
  {
    BMDevice_Servant::BMDevice_Servant (
    ::BasicSP::CCM_BMDevice_ptr exe,
    ::Components::CCMHome_ptr h,
    ::CIAO::Session_Container *c)
      : our_base (exe, c)
    {
      this->context_ = new BMDevice_Context (h, c, this);

      CIAO_REGISTER_OBV_FACTORY (
      ::BasicSP::TimeOut_init,
      ::BasicSP::TimeOut);

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
          ACE_TRY_CHECK;
        }

        this->populate_port_tables (
        ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }

      ACE_CATCHANY
      {
      }

      ACE_ENDTRY;
    }

    BMDevice_Servant::~BMDevice_Servant (void)
    {
    }

    void
    BMDevice_Servant::set_attributes (
    const ::Components::ConfigValues &descr
    ACE_ENV_ARG_DECL_NOT_USED)
    {
      for (CORBA::ULong i = 0;
       i < descr.length ();
       ++i)
      {
        const char *descr_name = descr[i]->name ();
        ::CORBA::Any &descr_value = descr[i]->value ();

        ACE_UNUSED_ARG (descr_name);
        ACE_UNUSED_ARG (descr_value);
      }
    }

    ::BasicSP::ReadData_ptr
    BMDevice_Servant::provide_data_read (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      if (! ::CORBA::is_nil (this->provide_data_read_.in ()))
      {
        return ::BasicSP::ReadData::_duplicate (this->provide_data_read_.in ());
      }

      ::CORBA::Object_var obj =
      this->provide_data_read_i (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::ReadData::_nil ());

      ::BasicSP::ReadData_var fo =
      ::BasicSP::ReadData::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::ReadData::_nil ());

      this->provide_data_read_ = fo;
      return ::BasicSP::ReadData::_duplicate (this->provide_data_read_.in ());
    }

    ::CORBA::Object_ptr
    BMDevice_Servant::provide_data_read_i (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::CORBA::Object_ptr ret =
      this->lookup_facet ("data_read");

      if (! ::CORBA::is_nil (ret))
      {
        return ret;
      }

      CIAO::Port_Activator_T< CIAO_GLUE_BasicSP::ReadData_Servant,
      ::BasicSP::CCM_ReadData,
       ::Components::CCMContext,
      BMDevice_Servant > *tmp = 0;

      typedef  CIAO::Port_Activator_T<
      CIAO_GLUE_BasicSP::ReadData_Servant,
      ::BasicSP::CCM_ReadData,
       ::Components::CCMContext,
      BMDevice_Servant >
       MACRO_MADNESS_TYPEDEF;


      ACE_NEW_THROW_EX ( 
        tmp,
        MACRO_MADNESS_TYPEDEF (
      "BasicSP_BMDevice_data_read",
      "data_read",
      CIAO::Port_Activator::Facet,
      0,
      this->context_,
      this),
      CORBA::NO_MEMORY ());


      CIAO::Servant_Activator *sa = 
      this->container_->ports_servant_activator ();

      if (!sa->register_port_activator (tmp))
      return 0;

      ::CORBA::Object_var obj =
      this->container_->generate_reference (
      "BasicSP_BMDevice_data_read",
      "IDL:BasicSP/ReadData:1.0",
      CIAO::Container::Facet_Consumer
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::ReadData::_nil ());

      this->add_facet (
      "data_read",
      obj.in ());

      return obj._retn ();
    }

    // Operations for Navigation interface.

    CORBA::Object_ptr
    BMDevice_Servant::provide_facet (
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

      if (ACE_OS::strcmp (name, "data_read") == 0)
      {
        return this->provide_data_read (ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::CORBA::Object::_nil ());
    }

    ::Components::FacetDescriptions *
    BMDevice_Servant::get_named_facets (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::EmitterDescriptions *
    BMDevice_Servant::get_all_emitters (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::EmitterDescriptions *
    BMDevice_Servant::get_named_emitters (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Cookie *
    BMDevice_Servant::subscribe_data_available (
    ::BasicSP::DataAvailableConsumer_ptr c
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::ExceededConnectionLimit))
    {
      return this->context_->subscribe_data_available (
      c
      ACE_ENV_ARG_PARAMETER);
    }

    ::BasicSP::DataAvailableConsumer_ptr
    BMDevice_Servant::unsubscribe_data_available (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConnection))
    {
      return this->context_->unsubscribe_data_available (
      ck
      ACE_ENV_ARG_PARAMETER);
    }

    BMDevice_Servant::TimeOutConsumer_timeout_Servant::TimeOutConsumer_timeout_Servant (
    ::BasicSP::CCM_BMDevice_ptr executor,
    ::BasicSP::CCM_BMDevice_Context_ptr c)
    : executor_ (::BasicSP::CCM_BMDevice::_duplicate (executor)),
    ctx_ (::BasicSP::CCM_BMDevice_Context::_duplicate (c))
    {
    }

    BMDevice_Servant::TimeOutConsumer_timeout_Servant::~TimeOutConsumer_timeout_Servant (void)
    {
    }

    CORBA::Object_ptr
    BMDevice_Servant::TimeOutConsumer_timeout_Servant::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return this->ctx_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    void
    BMDevice_Servant::TimeOutConsumer_timeout_Servant::push_TimeOut (
    ::BasicSP::TimeOut *evt
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      this->executor_->push_timeout (
      evt
      ACE_ENV_ARG_PARAMETER);
    }

    // Inherited from ::Components::EventConsumerBase.
    void
    BMDevice_Servant::TimeOutConsumer_timeout_Servant::push_event (
    ::Components::EventBase *ev
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::BadEventType))
    {
      ::BasicSP::TimeOut_var ev_type =
      ::BasicSP::TimeOut::_downcast (ev);

      if (ev_type != 0)
      {
        this->push_TimeOut (
        ev_type.in ()
        ACE_ENV_ARG_PARAMETER);

        return;
      }

      ACE_THROW (::Components::BadEventType ());
    }

    ::BasicSP::TimeOutConsumer_ptr
    BMDevice_Servant::get_consumer_timeout (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      if (! ::CORBA::is_nil (this->consumes_timeout_.in ()))
      {
        return ::BasicSP::TimeOutConsumer::_duplicate (this->consumes_timeout_.in ());
      }

      ::Components::EventConsumerBase_var obj =
      this->get_consumer_timeout_i (
      ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::TimeOutConsumer::_nil ());

      ::BasicSP::TimeOutConsumer_var eco =
      ::BasicSP::TimeOutConsumer::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::TimeOutConsumer::_nil ());

      this->consumes_timeout_ = eco;
      return ::BasicSP::TimeOutConsumer::_duplicate (this->consumes_timeout_.in ());
    }

    ::Components::EventConsumerBase_ptr
    BMDevice_Servant::get_consumer_timeout_i (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::Components::EventConsumerBase_ptr ret =
      this->lookup_consumer ("timeout");

      if (! ::CORBA::is_nil (ret))
      {
        return ret;
      }

      CIAO::Port_Activator_T<
      BMDevice_Servant::TimeOutConsumer_timeout_Servant,
      ::BasicSP::CCM_BMDevice,
      ::BasicSP::CCM_BMDevice_Context,
      BMDevice_Servant > *tmp = 0;

      typedef  CIAO::Port_Activator_T<
      BMDevice_Servant::TimeOutConsumer_timeout_Servant,
      ::BasicSP::CCM_BMDevice,
      ::BasicSP::CCM_BMDevice_Context, 
      BMDevice_Servant > 
       MACRO_MADNESS_TYPEDEF;


      ACE_NEW_THROW_EX ( 
        tmp,
        MACRO_MADNESS_TYPEDEF (
      "BasicSP_BMDevice_timeout",
      "timeout",
      CIAO::Port_Activator::Sink,
      this->executor_.in (),
      this->context_,
      this),
      CORBA::NO_MEMORY ());


      CIAO::Servant_Activator *sa = 
      this->container_->ports_servant_activator ();

      if (!sa->register_port_activator (tmp))
      return 0;

      ::CORBA::Object_var obj =
      this->container_->generate_reference (
      "BasicSP_BMDevice_timeout",
      "IDL:BasicSP/TimeOutConsumer:1.0",
      CIAO::Container::Facet_Consumer
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::TimeOutConsumer::_nil ());

      ::Components::EventConsumerBase_var ecb =
      ::Components::EventConsumerBase::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::TimeOutConsumer::_nil ());

      this->add_consumer (
      "timeout",
      ecb.in ());

      return ecb._retn ();
    }

    ::Components::Cookie *
    BMDevice_Servant::connect (
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
    BMDevice_Servant::disconnect (
    const char *name,
    ::Components::Cookie * ck
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

      ACE_UNUSED_ARG (ck);
    }

    ::Components::ConnectionDescriptions *
    BMDevice_Servant::get_connections (
    const char * /* name */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ReceptacleDescriptions *
    BMDevice_Servant::get_all_receptacles (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::ReceptacleDescriptions *
    BMDevice_Servant::get_named_receptacles (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::EventConsumerBase_ptr
    BMDevice_Servant::get_consumer (
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

      if (ACE_OS::strcmp (sink_name, "timeout") == 0)
      {
        return this->get_consumer_timeout (ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    void
    BMDevice_Servant::connect_consumer (
    const char * emitter_name,
    ::Components::EventConsumerBase_ptr consumer
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::AlreadyConnected,
    ::Components::InvalidConnection))
    {
      if (emitter_name == 0)
      {
        ACE_THROW (::CORBA::BAD_PARAM ());
      }

      ACE_UNUSED_ARG (consumer);
      ACE_THROW (::Components::InvalidName ());
    }

    ::Components::EventConsumerBase_ptr
    BMDevice_Servant::disconnect_consumer (
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
    BMDevice_Servant::get_named_consumers (
    const ::Components::NameList & /* names */
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::Cookie *
    BMDevice_Servant::subscribe (
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

      if (ACE_OS::strcmp (publisher_name, "data_available") == 0)
      {
        ::BasicSP::DataAvailableConsumer_var _ciao_consumer =
        ::BasicSP::DataAvailableConsumer::_narrow (
        subscribe
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (::CORBA::is_nil (_ciao_consumer.in ()))
        {
          ACE_THROW_RETURN (::Components::InvalidConnection (), 0);
        }

        return this->subscribe_data_available (
        _ciao_consumer.in ()
        ACE_ENV_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (::Components::InvalidName (), 0);
    }

    ::Components::EventConsumerBase_ptr
    BMDevice_Servant::unsubscribe (
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

      if (ACE_OS::strcmp (publisher_name, "data_available") == 0)
      {
        return this->unsubscribe_data_available (
        ck
        ACE_ENV_ARG_PARAMETER);
      }

      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    ::Components::PublisherDescriptions *
    BMDevice_Servant::get_all_publishers (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
    }

    ::Components::PublisherDescriptions *
    BMDevice_Servant::get_named_publishers (
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
    BMDevice_Servant::component_UUID (
    const char * new_component_UUID
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      this->component_UUID_ = new_component_UUID;
    }

    CIAO::CONNECTION_ID
    BMDevice_Servant::component_UUID (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return CORBA::string_dup (this->component_UUID_.c_str ());
    }

    CORBA::IRObject_ptr
    BMDevice_Servant::get_component_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    void
    BMDevice_Servant::configuration_complete (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConfiguration))
    {
      // CIAO to-do
    }

    void
    BMDevice_Servant::remove (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::RemoveFailure))
    {
      // CIAO to-do
    }

    CORBA::Object_ptr
    BMDevice_Servant::get_facet_executor (const char *name
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException))
    {
      if (name == 0)
      {
        ACE_THROW_RETURN (
        ::CORBA::BAD_PARAM (),
        ::CORBA::Object::_nil ());
      }

      if (ACE_OS::strcmp (name, "data_read") == 0)
      {
        return this->executor_->get_data_read (ACE_ENV_SINGLE_ARG_PARAMETER);
      }

       return CORBA::Object::_nil ();
    }

    // Supported operations.

    // Component attribute operations.

    // Private method to populate the port tables.
    void
    BMDevice_Servant::populate_port_tables (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::CORBA::Object_var obj_var;
      ::Components::EventConsumerBase_var ecb_var;

      obj_var =
      this->provide_data_read_i (
      ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      ecb_var =
      this->get_consumer_timeout_i (
      ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }
  }

  namespace CIAO_GLUE_BasicSP
  {
    BMDeviceHome_Servant::BMDeviceHome_Servant (
    ::BasicSP::CCM_BMDeviceHome_ptr exe,
    ::CIAO::Session_Container *c)
    : executor_ (::BasicSP::CCM_BMDeviceHome::_duplicate (exe)),
    container_ (c)
    {
    }

    BMDeviceHome_Servant::~BMDeviceHome_Servant (void)
    {
    }

    // Home operations.

    // Home supported interface operations.

    // Home factory and finder operations.

    // Home attribute operations.

    // Operations for keyless home interface.

    ::Components::CCMObject_ptr
    BMDeviceHome_Servant::create_component (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::CreateFailure))
    {
      return this->create (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    // Operations for implicit home interface.

    ::BasicSP::BMDevice_ptr
    BMDeviceHome_Servant::create (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::CreateFailure))
    {
      if (this->executor_.in () == 0)
      {
        ACE_THROW_RETURN (
        ::CORBA::INTERNAL (),
        ::BasicSP::BMDevice::_nil ());
      }

      ::Components::EnterpriseComponent_var _ciao_ec =
      this->executor_->create (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::BMDevice::_nil ());

      ::BasicSP::CCM_BMDevice_var _ciao_comp =
      ::BasicSP::CCM_BMDevice::_narrow (
      _ciao_ec.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::BMDevice::_nil ());

      return this->_ciao_activate_component (
      _ciao_comp.in ()
      ACE_ENV_ARG_PARAMETER);
    }

    // Operations for CCMHome interface.

    ::CORBA::IRObject_ptr
    BMDeviceHome_Servant::get_component_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    ::CORBA::IRObject_ptr
    BMDeviceHome_Servant::get_home_def (
    ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_THROW_RETURN (
      ::CORBA::NO_IMPLEMENT (),
      ::CORBA::IRObject::_nil ());
    }

    void
    BMDeviceHome_Servant::remove_component (
    ::Components::CCMObject_ptr comp
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::RemoveFailure))
    {
      ::BasicSP::BMDevice_var _ciao_comp =
      ::BasicSP::BMDevice::_narrow (
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

    ::BasicSP::BMDevice_ptr
    BMDeviceHome_Servant::_ciao_activate_component (
    ::BasicSP::CCM_BMDevice_ptr exe
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ::CORBA::Object_var hobj =
      this->container_->get_objref (
      this
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::BMDevice::_nil ());

      ::Components::CCMHome_var home =
      ::Components::CCMHome::_narrow (
      hobj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::BMDevice::_nil ());

      BMDevice_Servant *svt =
      new BMDevice_Servant (
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
      ACE_CHECK_RETURN (::BasicSP::BMDevice::_nil ());

      ::BasicSP::BMDevice_var ho =
      ::BasicSP::BMDevice::_narrow (
      objref.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::BMDevice::_nil ());

      if (this->component_map_.bind (oid.in (), svt) == 0)
      {
        safe._retn ();
      }

      return ho._retn ();
    }

    void
    BMDeviceHome_Servant::_ciao_passivate_component (
    ::BasicSP::BMDevice_ptr comp
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      PortableServer::ObjectId_var oid;

      this->container_->uninstall_component (
      comp,
      oid.out ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      BMDevice_Servant *servant = 0;

      if (this->component_map_.unbind (oid.in (), servant) == 0)
      {
        PortableServer::ServantBase_var safe (servant);

        servant->_ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }
    }
  }

  extern "C" BMDEVICE_SVNT_Export ::PortableServer::Servant
  createBMDeviceHome_Servant (
  ::Components::HomeExecutorBase_ptr p,
  CIAO::Session_Container *c
  ACE_ENV_ARG_DECL)
  {
    if (p == 0)
    {
      return 0;
    }

    ::BasicSP::CCM_BMDeviceHome_var x =
    ::BasicSP::CCM_BMDeviceHome::_narrow (
    p
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    if (::CORBA::is_nil (x.in ()))
    {
      return 0;
    }

    return new
    CIAO_GLUE_BasicSP::BMDeviceHome_Servant (
    x.in (),
    c);
  }
}

