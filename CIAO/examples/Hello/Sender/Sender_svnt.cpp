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

#include "Sender_svnt.h"
#include "Cookies.h"
#include "ciao/Servant_Activator.h"
#include "ciao/Port_Activator_T.h"
#include "ace/SString.h"

namespace CIAO_FACET_Hello
{
  template <typename T>
  ReadMessage_Servant_T<T>::ReadMessage_Servant_T (
    ::Hello::CCM_ReadMessage_ptr executor,
    ::Components::CCMContext_ptr c)
    : executor_ ( ::Hello::CCM_ReadMessage::_duplicate (executor)),
      ctx_ ( ::Components::CCMContext::_duplicate (c))
  {
  }

  template <typename T>
  ReadMessage_Servant_T<T>::~ReadMessage_Servant_T (void)
  {
  }

  template <typename T>
  char *
  ReadMessage_Servant_T<T>::get_message (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->get_message (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  template <typename T>
  ::CORBA::Object_ptr
  ReadMessage_Servant_T<T>::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::SessionContext_var sc =
      ::Components::SessionContext::_narrow (
        this->ctx_.in ()
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (sc.in ()))
    {
      return sc->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::EntityContext_var ec =
    ::Components::EntityContext::_narrow (
      this->ctx_.in ()
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (ec.in ()))
    {
      return ec->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN ( ::CORBA::INTERNAL (), 0);
  }
}

namespace CIDL_Sender_Impl
{
  Sender_Context::Sender_Context (
    ::Components::CCMHome_ptr h,
    ::CIAO::Session_Container *c,
    Sender_Servant *sv)
    : ::CIAO::Context_Impl_Base (h, c), 
      ::CIAO::Context_Impl<
          ::Hello::CCM_Sender_Context,
          Sender_Servant,
          ::Hello::Sender,
          ::Hello::Sender_var
        > (h, c, sv)
  {
  }

  Sender_Context::~Sender_Context (void)
  {
  }

  // Operations for Sender receptacles and event sources,
  // defined in ::Hello::CCM_Sender_Context.

  void
  Sender_Context::push_click_out (
    ::Hello::TimeOut *ev
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    for (ACE_Active_Map_Manager< 
           ::Hello::TimeOutConsumer_var>::iterator iter =
             this->ciao_publishes_click_out_map_.begin ();
         iter != this->ciao_publishes_click_out_map_.end ();
         ++iter)
    {
      (*iter).int_id_->push_TimeOut (
        ev
        ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }

    for (ACE_Active_Map_Manager< 
           ::Components::EventConsumerBase_var>::iterator giter =
             this->ciao_publishes_click_out_generic_map_.begin ();
         giter != this->ciao_publishes_click_out_generic_map_.end ();
         ++giter)
    {
      (*giter).int_id_->push_event (
        ev
        ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  }

  ::Components::Cookie *
  Sender_Context::subscribe_click_out (
    ::Hello::TimeOutConsumer_ptr c
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::ExceededConnectionLimit))
  {
    if ( ::CORBA::is_nil (c))
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (), 0);
    }

    ::Hello::TimeOutConsumer_var sub =
      ::Hello::TimeOutConsumer::_duplicate (c);

    ACE_Active_Map_Manager_Key key;
    this->ciao_publishes_click_out_map_.bind (sub.in (), key);
    sub._retn ();

    ::Components::Cookie * retv = 0;
    ACE_NEW_THROW_EX (retv,
                      ::CIAO::Map_Key_Cookie (key),
                      ::CORBA::NO_MEMORY ());

    return retv;
  }

  ::Components::Cookie *
  Sender_Context::subscribe_click_out_generic (
    ::Components::EventConsumerBase_ptr c
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::ExceededConnectionLimit))
  {
    if ( ::CORBA::is_nil (c))
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (), 0);
    }

    ::Components::EventConsumerBase_var sub =
      ::Components::EventConsumerBase::_duplicate (c);

    ACE_Active_Map_Manager_Key key;
    this->ciao_publishes_click_out_generic_map_.bind (sub.in (), key);
    sub._retn ();

    ::Components::Cookie * retv = 0;
    ACE_NEW_THROW_EX (retv,
                      ::CIAO::Map_Key_Cookie (key),
                      ::CORBA::NO_MEMORY ());

    return retv;
  }

  ::Hello::TimeOutConsumer_ptr
  Sender_Context::unsubscribe_click_out (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidConnection))
  {
    ACE_Active_Map_Manager_Key key;

    if (ck == 0 || ::CIAO::Map_Key_Cookie::extract (ck, key) == false)
    {
      ACE_THROW_RETURN ( ::Components::InvalidConnection (),
                        ::Hello::TimeOutConsumer::_nil ());
    }

    ::Hello::TimeOutConsumer_var retv;
    if (this->ciao_publishes_click_out_map_.unbind (key, retv) == 0)
    {
      return retv._retn ();
    }

    ::Components::EventConsumerBase_var ecb;

    if (this->ciao_publishes_click_out_generic_map_.unbind (key, ecb) != 0)
    {
      ACE_THROW_RETURN ( ::Components::InvalidConnection (),
                        ::Hello::TimeOutConsumer::_nil ());
    }

    return ::Hello::TimeOutConsumer::_nil ();
  }

  // CIAO-specific.

  Sender_Context *
  Sender_Context::_narrow (
    ::Components::SessionContext_ptr p
    ACE_ENV_ARG_DECL_NOT_USED)
  {
    return dynamic_cast<Sender_Context *> (p);
  }

  Sender_Servant::Sender_Servant (
    ::Hello::CCM_Sender_ptr exe,
    ::Components::CCMHome_ptr h,
    const char *ins_name,
    ::CIAO::Home_Servant_Impl_Base *hs,
    ::CIAO::Session_Container *c,
    ::CIAO::REC_POL_MAP &rec_pol_map)
    : ::CIAO::Servant_Impl_Base (h, hs, c, rec_pol_map),
      ::CIAO::Servant_Impl<
          ::POA_Hello::Sender,
          ::Hello::CCM_Sender,
          Sender_Context
        > (exe, h, hs, c, rec_pol_map),
      ins_name_ (ins_name)
  {
    ACE_NEW (this->context_,
             Sender_Context (h, c, this));

    // Set the instance id of the component on the context

    this->context_->_ciao_instance_id (this->ins_name_);

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

  Sender_Servant::~Sender_Servant (void)
  {
  }

  void
  Sender_Servant::set_attributes (
    const ::Components::ConfigValues &descr
    ACE_ENV_ARG_DECL)
  {
    ACE_ENV_EMIT_CODE (ACE_UNUSED_ARG (ACE_TRY_ENV));

    for ( ::CORBA::ULong i = 0; i < descr.length (); ++i)
    {
      const char *descr_name = descr[i]->name ();
      ::CORBA::Any &descr_value = descr[i]->value ();

      if (ACE_OS::strcmp (descr_name, "local_message") == 0)
      {
        const char * _ciao_extract_val = 0;
        descr_value >>= _ciao_extract_val;
        this->local_message (_ciao_extract_val);
        continue;
      }

      if (ACE_OS::strcmp (descr_name, "hertz") == 0)
      {
        ::CORBA::Long _ciao_extract_val = 0;
        descr_value >>= _ciao_extract_val;
        this->hertz (_ciao_extract_val);
        continue;
      }

      if (ACE_OS::strcmp (descr_name, "color") == 0)
      {
        ::Hello::COLOR_SELECTION _ciao_extract_val;
        descr_value >>= _ciao_extract_val;
        this->color (_ciao_extract_val);
        continue;
      }

      ACE_UNUSED_ARG (descr_name);
      ACE_UNUSED_ARG (descr_value);
    }
  }

  ::Hello::ReadMessage_ptr
  Sender_Servant::provide_push_message (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    if (! ::CORBA::is_nil (this->provide_push_message_.in ()))
    {
      return ::Hello::ReadMessage::_duplicate (this->provide_push_message_.in ());
    }

    ::CORBA::Object_var obj =
      this->provide_push_message_i (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::Hello::ReadMessage::_nil ());

    ::Hello::ReadMessage_var fo =
      ::Hello::ReadMessage::_narrow (obj.in ()
                                     ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::Hello::ReadMessage::_nil ());

    this->provide_push_message_ = fo;
    return ::Hello::ReadMessage::_duplicate (this->provide_push_message_.in ());
  }

  ::CORBA::Object_ptr
  Sender_Servant::provide_push_message_i (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::CORBA::Object_ptr ret =
      this->lookup_facet ("push_message");

    if (! ::CORBA::is_nil (ret))
    {
      return ret;
    }

    ::CIAO::Port_Activator_T<
        ::CIAO_FACET_Hello::ReadMessage_Servant,
        ::Hello::CCM_ReadMessage,
        ::Components::CCMContext,
        Sender_Servant
      > *tmp = 0;

    typedef ::CIAO::Port_Activator_T<
        ::CIAO_FACET_Hello::ReadMessage_Servant,
        ::Hello::CCM_ReadMessage,
        ::Components::CCMContext,
        Sender_Servant
      >
    MACRO_MADNESS_TYPEDEF;

    ACE_CString obj_id (this->ins_name_);
    obj_id += "_push_message";

    ACE_NEW_THROW_EX (tmp,
                      MACRO_MADNESS_TYPEDEF (
                        obj_id.c_str (),
                        "push_message",
                        ::CIAO::Port_Activator::Facet,
                        0,
                        this->context_,
                        this),
                      ::CORBA::NO_MEMORY ());

    ::CIAO::Servant_Activator *sa = 
    this->container_->ports_servant_activator ();

    if (!sa->register_port_activator (tmp))
    {
      return ::Hello::ReadMessage::_nil ();
    }

    ::CORBA::Object_var obj =
      this->container_->generate_reference (
        obj_id.c_str (),
        "IDL:Hello/ReadMessage:1.0",
        ::CIAO::Container::Facet_Consumer
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::Hello::ReadMessage::_nil ());

    this->add_facet ("push_message",
                     obj.in ()
                     ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::Hello::ReadMessage::_nil ());

    return obj._retn ();
  }

  ::Components::Cookie *
  Sender_Servant::subscribe_click_out (
    ::Hello::TimeOutConsumer_ptr c
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::ExceededConnectionLimit))
  {
    return this->context_->subscribe_click_out (
      c
      ACE_ENV_ARG_PARAMETER);
  }

  ::Components::Cookie *
  Sender_Servant::subscribe_click_out_generic (
    ::Components::EventConsumerBase_ptr c
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::ExceededConnectionLimit))
  {
    return this->context_->subscribe_click_out_generic (
      c
      ACE_ENV_ARG_PARAMETER);
  }

  ::Hello::TimeOutConsumer_ptr
  Sender_Servant::unsubscribe_click_out (
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidConnection))
  {
    return this->context_->unsubscribe_click_out (
      ck
      ACE_ENV_ARG_PARAMETER);
  }

  ::Components::Cookie *
  Sender_Servant::connect (
    const char *name,
    ::CORBA::Object_ptr connection
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::InvalidConnection,
                   ::Components::AlreadyConnected,
                   ::Components::ExceededConnectionLimit))
  {
    // If the component has no receptacles, this will be unused.
    ACE_UNUSED_ARG (connection);

    if (name == 0)
    {
      ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
  }

  ::CORBA::Object_ptr
  Sender_Servant::disconnect (
    const char *name,
    ::Components::Cookie * ck
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::InvalidConnection,
                   ::Components::CookieRequired,
                   ::Components::NoConnection))
  {
    ACE_UNUSED_ARG (ck);

    if (name == 0)
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                        ::CORBA::Object::_nil ());
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (),
                      ::CORBA::Object::_nil ());
  }

  ::Components::ReceptacleDescriptions *
  Sender_Servant::get_all_receptacles (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::ReceptacleDescriptions *retval = 0;
    ACE_NEW_RETURN (retval,
                    ::Components::ReceptacleDescriptions,
                    0);
    ::Components::ReceptacleDescriptions_var safe_retval = retval;
    safe_retval->length (0UL);

    return safe_retval._retn ();
  }

  void
  Sender_Servant::connect_consumer (
    const char * emitter_name,
    ::Components::EventConsumerBase_ptr consumer
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::AlreadyConnected,
                   ::Components::InvalidConnection))
  {
    if (emitter_name == 0)
    {
      ACE_THROW ( ::CORBA::BAD_PARAM ());
    }

    ACE_UNUSED_ARG (consumer);
    ACE_THROW ( ::Components::InvalidName ());
  }

  ::Components::EventConsumerBase_ptr
  Sender_Servant::disconnect_consumer (
    const char *source_name
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::NoConnection))
  {
    if (source_name == 0)
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                        ::Components::EventConsumerBase::_nil ());
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (),
                      ::Components::EventConsumerBase::_nil ());
  }

  ::Components::PublisherDescriptions *
  Sender_Servant::get_all_publishers (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::PublisherDescriptions *retval = 0;
    ACE_NEW_RETURN (retval,
                    ::Components::PublisherDescriptions,
                    0);
    ::Components::PublisherDescriptions_var safe_retval = retval;
    safe_retval->length (1UL);

    ::CIAO::Servant_Impl_Base::describe_pub_event_source<
        ::Hello::TimeOutConsumer_var
      > ("click_out",
         "IDL:Hello/TimeOut:1.0",
         this->context_->ciao_publishes_click_out_map_,
         safe_retval,
         0UL);

    return safe_retval._retn ();
  }

  ::Components::EmitterDescriptions *
  Sender_Servant::get_all_emitters (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::EmitterDescriptions *retval = 0;
    ACE_NEW_RETURN (retval,
                    ::Components::EmitterDescriptions,
                    0);
    ::Components::EmitterDescriptions_var safe_retval = retval;
    safe_retval->length (0UL);

    return safe_retval._retn ();
  }

  ::Components::Cookie *
  Sender_Servant::subscribe (
    const char *publisher_name,
    ::Components::EventConsumerBase_ptr subscribe
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::InvalidConnection,
                   ::Components::ExceededConnectionLimit))
  {
    // Just in case there are no if blocks
    ACE_UNUSED_ARG (subscribe);

    if (publisher_name == 0)
    {
      ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
    }

    if (ACE_OS::strcmp (publisher_name, "click_out") == 0)
    {
      CORBA::PolicyList policy_list;
      policy_list = this->get_receptacle_policy (publisher_name);

      ::Hello::TimeOutConsumer_var sub =
        ::Hello::TimeOutConsumer::_narrow (
        subscribe
        ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (policy_list.length () != 0)
        {
          CORBA::Object_var over_ridden_object =
            sub->_set_policy_overrides (policy_list,
                                        CORBA::SET_OVERRIDE
                                        ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

         sub = ::Hello::TimeOutConsumer::_narrow (
                over_ridden_object
                ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);
        }

      if ( ::CORBA::is_nil (sub.in ()))
      {
        ::CORBA::Boolean substitutable =
          subscribe->ciao_is_substitutable (
            ::Hello::TimeOut::_tao_obv_static_repository_id ()
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (substitutable)
        {
          return this->subscribe_click_out_generic (
            subscribe
            ACE_ENV_ARG_PARAMETER);
        }

        else
        {
          ACE_THROW_RETURN ( ::Components::InvalidConnection (), 0);
        }
      }

      else
      {
        return this->subscribe_click_out (
          sub.in ()
          ACE_ENV_ARG_PARAMETER);
      }
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
  }

  ::Components::EventConsumerBase_ptr
  Sender_Servant::unsubscribe (
    const char *publisher_name,
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::InvalidConnection))
  {
    // Just in case there are no if blocks
    ACE_UNUSED_ARG (ck);

    if (publisher_name == 0)
    {
      ACE_THROW_RETURN ( ::Components::InvalidName (),
                        ::Components::EventConsumerBase::_nil ());
    }

    if (ACE_OS::strcmp (publisher_name, "click_out") == 0)
    {
      return this->unsubscribe_click_out (
        ck
        ACE_ENV_ARG_PARAMETER);
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (),
                      ::Components::EventConsumerBase::_nil ());
  }

  ::CORBA::Object_ptr
  Sender_Servant::get_facet_executor (
    const char *name
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                        ::CORBA::Object::_nil ());
    }

    if (ACE_OS::strcmp (name, "push_message") == 0)
    {
      return this->executor_->get_push_message (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    return ::CORBA::Object::_nil ();
  }

  // Supported operations.

  void
  Sender_Servant::start (
    ::CORBA::Long payload,
    ::CORBA::Long iterations
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    this->executor_->start (
      payload,
      iterations
      ACE_ENV_ARG_PARAMETER);
  }

  // Component attribute operations.

  char *
  Sender_Servant::local_message (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->local_message (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  void
  Sender_Servant::local_message (
    const char * local_message
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    this->executor_->local_message (
      local_message
      ACE_ENV_ARG_PARAMETER);
  }

  ::CORBA::Long
  Sender_Servant::hertz (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->hertz (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  void
  Sender_Servant::hertz (
    ::CORBA::Long hertz
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    this->executor_->hertz (
      hertz
      ACE_ENV_ARG_PARAMETER);
  }

  ::Hello::COLOR_SELECTION
  Sender_Servant::color (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->color (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  void
  Sender_Servant::color (
    ::Hello::COLOR_SELECTION color
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    this->executor_->color (
      color
      ACE_ENV_ARG_PARAMETER);
  }

  // Private method to populate the port tables.
  void
  Sender_Servant::populate_port_tables (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ACE_ENV_ARG_NOT_USED;
    ::CORBA::Object_var obj_var;
    ::Components::EventConsumerBase_var ecb_var;

    obj_var =
      this->provide_push_message_i (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
  }

  SenderHome_Servant::SenderHome_Servant (
    ::Hello::CCM_SenderHome_ptr exe,
    const char *ins_name,
    ::CIAO::Session_Container *c,
    ::CIAO::REC_POL_MAP &rec_pol_map)
    : ::CIAO::Home_Servant_Impl_Base (c),
      ::CIAO::Home_Servant_Impl<
            ::POA_Hello::SenderHome,
            ::Hello::CCM_SenderHome,
            Sender_Servant
          > (exe, c, ins_name, rec_pol_map)
  {
  }

  SenderHome_Servant::~SenderHome_Servant (void)
  {
  }

  // Home operations.

  // Home supported interface operations.

  // Home factory and finder operations.

  // Home attribute operations.

  extern "C" SENDER_SVNT_Export ::PortableServer::Servant
  create_Hello_SenderHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    ::CIAO::Session_Container *c,
    const char *ins_name,
    ::CIAO::REC_POL_MAP &rec_pol_map
    ACE_ENV_ARG_DECL)
  {
    if (p == 0)
    {
      return 0;
    }

    ::Hello::CCM_SenderHome_var x =
    ::Hello::CCM_SenderHome::_narrow (
      p
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    if (::CORBA::is_nil (x.in ()))
    {
      return 0;
    }

    return new
    SenderHome_Servant (
      x.in (),
      ins_name,
      c, rec_pol_map);
  }
}

