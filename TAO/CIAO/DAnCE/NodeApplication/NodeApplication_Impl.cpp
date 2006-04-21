//$Id$

#include "NodeApplication_Impl.h"
#include "ace/SString.h"
#include "Container_Impl.h"
#include "Deployment_EventsC.h"

#if !defined (__ACE_INLINE__)
# include "NodeApplication_Impl.inl"
#endif /* __ACE_INLINE__ */

CIAO::NodeApplication_Impl::~NodeApplication_Impl (void)
{
}

CORBA::Long
CIAO::NodeApplication_Impl::init (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  /// @todo initialize this NodeApplication properties
  return 0;
}

CORBA::Long
CIAO::NodeApplication_Impl::create_all_containers (
    const ::Deployment::ContainerImplementationInfos & container_infos
    ACE_ENV_ARG_DECL_NOT_USED
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Create all the containers here based on the input node_impl_info.
  const CORBA::ULong len = container_infos.length ();

  for (CORBA::ULong i = 0; i < len; ++i)
    {
      // The factory method <create_container> will intialize the container
      // servant with properties, so we don't need to call <init> on the
      // container object reference.
      // Also, the factory method will add the container object reference
      // to the set for us.
      ::Deployment::Container_var cref =
        this->create_container (container_infos[i].container_config);

      // Build the Component_Container_Map
      for (CORBA::ULong j = 0;
           j < container_infos[i].impl_infos.length ();
           ++j)
        {
          this->component_container_map_.bind (
            container_infos[i].impl_infos[j].component_instance_name.in (),
            ::Deployment::Container::_duplicate (cref.in ()));
        }
    }

  return 0;
}

void
CIAO::NodeApplication_Impl::finishLaunch (
    const Deployment::Connections & providedReference,
    CORBA::Boolean start,
    CORBA::Boolean add_connection
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StartError,
                   Deployment::InvalidConnection))
{
  ACE_UNUSED_ARG (start);

  // If parameter "add_connection" is true, then it means we want to "add"
  // new connections, other, we remove existing connections
  this->finishLaunch_i (providedReference, start, add_connection);
}

void
CIAO::NodeApplication_Impl::finishLaunch_i (
    const Deployment::Connections & connections,
    CORBA::Boolean start,
    CORBA::Boolean add_connection
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StartError,
                   Deployment::InvalidConnection))
{
  ACE_UNUSED_ARG (start);

  ACE_TRY
    {
      const CORBA::ULong length = connections.length ();

      // For every connection struct we finish the connection.
      for (CORBA::ULong i = 0; i < length; ++i)
        {
          ACE_CString name = connections[i].instanceName.in ();

          // For ES_to_Consumer connection, we simply call
          // handle_es_consumer_connection method.
          //if (connections[i].kind == Deployment::rtecEventConsumer)
          if (this->_is_es_consumer_conn (connections[i]))
            {
              this->handle_es_consumer_connection (
                      connections[i],
                      add_connection);
              continue;
            }

          // For other type of connections, we need to fetch the
          // objref of the source component
          Component_State_Info comp_state;

          if (this->component_state_map_.find (name, comp_state) != 0)
            {
              ACE_ERROR ((LM_ERROR,
                          "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                          "CIAO::NodeApplication_Impl::finishLaunch, "
                          "invalid port name [%s] in instance [%s] \n",
                          connections[i].portName.in (),
                          name.c_str ()));
              ACE_TRY_THROW (Deployment::InvalidConnection ());
            }

          Components::EventConsumerBase_var consumer;

          Components::CCMObject_var comp = comp_state.objref_;

          if (CORBA::is_nil (comp.in ()))
            {
              ACE_DEBUG ((LM_DEBUG, "comp is nil\n"));
              throw Deployment::InvalidConnection ();
            }

          switch (connections[i].kind)
            {
              case Deployment::SimplexReceptacle:
              case Deployment::MultiplexReceptacle:
                this->handle_facet_receptable_connection (
                        comp.in (),
                        connections[i],
                        add_connection);
                break;

              case Deployment::EventEmitter:
                this->handle_emitter_consumer_connection (
                        comp.in (),
                        connections[i],
                        add_connection);
                break;

              case Deployment::EventPublisher:
                if (this->_is_publisher_es_conn (connections[i]))
                  this->handle_publisher_es_connection (
                          comp.in (),
                          connections[i],
                          add_connection);
                else
                  this->handle_publisher_consumer_connection (
                          comp.in (),
                          connections[i],
                          add_connection);
                break;

              default:
                ACE_DEBUG ((LM_DEBUG,
                            "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                            "CIAO::NodeApplication_Impl::finishLaunch_i: "
                            "Unsupported event port type encounted\n"));
                ACE_TRY_THROW (CORBA::NO_IMPLEMENT ());
            }
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "NodeApplication_Impl::finishLaunch\t\n");
      ACE_RE_THROW;
    }

  ACE_ENDTRY;
}

void
CIAO::NodeApplication_Impl::ciao_preactivate (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StartError))
{
  Component_Iterator end = this->component_state_map_.end ();
  for (Component_Iterator iter (this->component_state_map_.begin ());
       iter != end;
       ++iter)
  {
    if (((*iter).int_id_).state_ == NEW_BORN)
      {
        ((*iter).int_id_).objref_->ciao_preactivate (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }

    ((*iter).int_id_).state_ = PRE_ACTIVE;
  }
}

void
CIAO::NodeApplication_Impl::start (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StartError))
{
  Component_Iterator end = this->component_state_map_.end ();
  for (Component_Iterator iter (this->component_state_map_.begin ());
       iter != end;
       ++iter)
  {
    if (((*iter).int_id_).state_ == PRE_ACTIVE)
      {
        ((*iter).int_id_).objref_->ciao_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }

    ((*iter).int_id_).state_ = ACTIVE;
  }
}

void
CIAO::NodeApplication_Impl::ciao_postactivate (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StartError))
{
  Component_Iterator end = this->component_state_map_.end ();
  for (Component_Iterator iter (this->component_state_map_.begin ());
       iter != end;
       ++iter)
  {
    if (((*iter).int_id_).state_ == ACTIVE)
      {
        ((*iter).int_id_).objref_->ciao_postactivate (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;

        ((*iter).int_id_).state_ = POST_ACTIVE;
      }
  }
}

void
CIAO::NodeApplication_Impl::ciao_passivate (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StopError))
{
  Component_Iterator end = this->component_state_map_.end ();
  for (Component_Iterator iter (this->component_state_map_.begin ());
       iter != end;
       ++iter)
  {
    ((*iter).int_id_).objref_->ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;

    ((*iter).int_id_).state_ = PASSIVE;
  }
  ACE_DEBUG ((LM_DEBUG, "exiting passivate\n"));
}

Deployment::ComponentInfos *
CIAO::NodeApplication_Impl::install (
    const ::Deployment::NodeImplementationInfo & node_impl_info
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::UnknownImplId,
                   Deployment::ImplEntryPointNotFound,
                   Deployment::InstallationFailure,
                   Components::InvalidConfiguration))
{
  Deployment::ComponentInfos_var retv;
  ACE_TRY
    {
      // Extract ORB resource def here.
      this->configurator_.init_resource_manager (node_impl_info.nodeapp_config);

      const ::Deployment::ContainerImplementationInfos container_infos =
        node_impl_info.impl_infos;

      ACE_NEW_THROW_EX (retv,
                        Deployment::ComponentInfos,
                        CORBA::NO_MEMORY ());
      ACE_TRY_CHECK;

      retv->length (0UL);

      // Call create_all_containers to create all the necessary containers..
      // @@(GD): The "create_all_containers" mechanism needs to be refined, so
      // we should always try to reuse existing containers as much as possible!
      // We need not only factory pattern, but also finder pattern here as well.
      if (CIAO::debug_level () > 15)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) NodeApplication_Impl.cpp -"
                      "CIAO::NodeApplication_Impl::install -"
                      "creating all the containers. \n"));
        }

      CORBA::ULong old_set_size = this->container_set_.size ();

      (void) this->create_all_containers (container_infos);
      if (CIAO::debug_level () > 9)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) NodeApplication_Impl.cpp -"
                      "CIAO::NodeApplication_Impl::install -"
                      "create_all_containers() called.\n"));
        }

      // For each container, invoke <install> operation, this will return
      // the ComponentInfo for components installed in each container.
      // Merge all the returned ComponentInfo, which will be used
      // as the return value of this method.
      const CORBA::ULong num_containers = container_infos.length ();
      for (CORBA::ULong i = 0; i < num_containers; ++i)
        {
          Deployment::ComponentInfos_var comp_infos =
            this->container_set_.at(i+old_set_size)->
                    install (container_infos[i]
                             ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          // Append the return sequence to the *big* return sequence
          CORBA::ULong curr_len = retv->length ();
          retv->length (curr_len + comp_infos->length ());

          for (CORBA::ULong j = curr_len; j < retv->length (); j++)
            retv[j] = comp_infos[j-curr_len];
        }

      // @@ Maybe we can optimize this. We can come up with a decision later.
      // Cache a copy of the component object references for all the components
      // installed on this NodeApplication. I know we can delegates these to the
      // undelying containers, but in that case, we should loop
      // all the containers to find the component object reference. - Gan
      const CORBA::ULong comp_len = retv->length ();
      for (CORBA::ULong len = 0;
          len < comp_len;
          ++len)
      {
        Component_State_Info tmp;

        tmp.state_ = NEW_BORN;
        tmp.objref_ =
          Components::CCMObject::_duplicate (retv[len].component_ref.in ());

        //Since we know the type ahead of time...narrow is omitted here.
        if (this->component_state_map_.rebind (
            retv[len].component_instance_name.in(), tmp))
          {
            ACE_DEBUG ((LM_DEBUG,
                        "CIAO (%P|%t) NodeApplication_Impl.cpp -"
                        "CIAO::NodeApplication_Impl::install -"
                        "error binding component instance [%s] "
                        "into the map. \n",
                        retv[len].component_instance_name.in ()));
            ACE_TRY_THROW (
               Deployment::InstallationFailure ("NodeApplication_Imp::install",
                                       "Duplicate component instance name"));
          }
      }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "CIAO_NodeApplication::install error\t\n");
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (0);

  return retv._retn ();
}

void
CIAO::NodeApplication_Impl::remove_component (const char * inst_name
                                              ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((::CORBA::SystemException,
                   ::Components::RemoveFailure))
{
  ACE_DEBUG ((LM_DEBUG, "NA_I: removing component %s\n",
        inst_name));

  // Fetch the container object reference from the componet_container_map
  ::Deployment::Container_var container_ref;
  if (this->component_container_map_.find (inst_name, container_ref) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::remove_component, "
                  "invalid instance [%s] in the component_container_map.\n",
                  inst_name));
      ACE_TRY_THROW (::Components::RemoveFailure ());
    }

  // Remove this component instance from the node application
  ACE_CString name (inst_name);
  this->component_container_map_.unbind (name);
  this->component_state_map_.unbind (name);
  container_ref->remove_component (inst_name);
}

void
CIAO::NodeApplication_Impl::passivate_component (const char * name
                                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((::CORBA::SystemException,
                   ::Components::RemoveFailure))
{
  Component_State_Info comp_state;

  if (this->component_state_map_.find (name, comp_state) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::passivate_component, "
                  "invalid instance [%s] \n",
                   name));
      ACE_TRY_THROW (Deployment::StartError ());
    }

  if (CORBA::is_nil (comp_state.objref_.in ()))
    {
      ACE_DEBUG ((LM_DEBUG, "comp is nil\n"));
      throw Deployment::StartError ();
    }

  comp_state.objref_->ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
CIAO::NodeApplication_Impl::activate_component (const char * name
                                                ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((::CORBA::SystemException,
                   ::Components::RemoveFailure))
{
  Component_State_Info comp_state;

  if (this->component_state_map_.find (name, comp_state) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::passivate_component, "
                  "invalid instance [%s] \n",
                   name));
      ACE_TRY_THROW (Deployment::StartError ());
    }

  if (CORBA::is_nil (comp_state.objref_.in ()))
    {
      ACE_DEBUG ((LM_DEBUG, "comp is nil\n"));
      throw Deployment::StartError ();
    }

  comp_state.objref_->ciao_preactivate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  comp_state.objref_->ciao_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  comp_state.objref_->ciao_postactivate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}


void
CIAO::NodeApplication_Impl::remove (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // If we still have components installed, then do nothing

  if (this->component_state_map_.current_size () != 0)
    return;

  // For each container, invoke <remove> operation to remove home and components.
  const CORBA::ULong set_size = this->container_set_.size ();
  for (CORBA::ULong i = 0; i < set_size; ++i)
    {
      ACE_DEBUG ((LM_DEBUG, "NA: calling remove on container %i\n"));
      this->container_set_.at(i)->remove (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }

  // Remove all containers
  // Maybe we should also deactivate container object reference.
  ACE_DEBUG ((LM_DEBUG, "NA: remove all\n"));
  this->container_set_.remove_all ();

  if (CIAO::debug_level () > 1)
    ACE_DEBUG ((LM_DEBUG, "Removed all containers from this NodeApplication!\n"));

  //For static deployment, ORB will be shutdown in the Static_NodeManager
  if (this->static_entrypts_maps_ == 0)
    {
      this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
      ACE_DEBUG ((LM_DEBUG, "NA: shutdown\n"));
    }
}


// Create a container interface, which will be hosted in this NodeApplication.
::Deployment::Container_ptr
CIAO::NodeApplication_Impl::create_container (
    const ::Deployment::Properties &properties
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                  ::Components::CreateFailure,
                  ::Components::InvalidConfiguration))
{
  //if (CIAO::debug_level () > 1)
  //  ACE_DEBUG ((LM_DEBUG, "ENTERING: NodeApplication_Impl::create_container()\n"));

  CORBA::PolicyList_var policies
    = this->configurator_.find_container_policies (properties);

  CIAO::Container_Impl *container_servant = 0;

  ACE_NEW_THROW_EX (container_servant,
                    CIAO::Container_Impl (this->orb_.in (),
                                          this->poa_.in (),
                                          this->get_objref (),
                                          this->static_entrypts_maps_),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  PortableServer::ServantBase_var safe_servant (container_servant);

  // @TODO: Need to decide a "component_installation" equivalent data
  // structure  to pass to the container, which will be used to
  // suggest how to install the components.  Each such data stucture
  // should be correspond to one <process_collocation> tag  in the XML
  // file to describe the deployment plan.
  container_servant->init (policies.ptr ()
                           ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  PortableServer::ObjectId_var oid
    = this->poa_->activate_object (container_servant
                                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Object_var obj
    = this->poa_->id_to_reference (oid.in ()
                                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  ::Deployment::Container_var ci
    = ::Deployment::Container::_narrow (obj.in ()
                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  // Cached the objref in its servant.
  container_servant->set_objref (ci.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  {
    ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, ace_mon, this->lock_, 0);

    this->container_set_.add (ci.in ());
  }

  //if (CIAO::debug_level () > 1)
  //  ACE_DEBUG ((LM_DEBUG,
  //              "LEAVING: NodeApplication_Impl::create_container()\n"));
  return ci._retn ();
}

// Remove a container interface.
void
CIAO::NodeApplication_Impl::remove_container (::Deployment::Container_ptr cref
                                              ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                  ::Components::RemoveFailure))
{
  ACE_DEBUG ((LM_DEBUG, "ENTERING: NodeApplication_Impl::remove_container()\n"));
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);

  if (this->container_set_.object_in_set (cref) == 0)
    {
      ACE_THROW (Components::RemoveFailure());
    }

  cref->remove (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // @@ Deactivate object.
  PortableServer::ObjectId_var oid
    = this->poa_->reference_to_id (cref
                                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->poa_->deactivate_object (oid.in ()
                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Should we remove the server still, even if the previous call failed.

  if (this->container_set_.remove (cref) == -1)
    {
      ACE_THROW (::Components::RemoveFailure ());
    }

  ACE_DEBUG ((LM_DEBUG, "LEAVING: NodeApplication_Impl::remove_container()\n"));
}

// Get containers
::Deployment::Containers *
CIAO::NodeApplication_Impl::get_containers (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return 0;
}

::Deployment::CIAO_Event_Services *
CIAO::NodeApplication_Impl::
install_es (const ::Deployment::ESInstallationInfos & es_infos
            ACE_ENV_ARG_DECL)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Deployment::InstallationFailure))
{
  Deployment::CIAO_Event_Services_var retv;
  ACE_NEW_RETURN (retv,
                  Deployment::CIAO_Event_Services,
                  0);

  CORBA::ULong total_lenth = es_infos.length ();

  for (CORBA::ULong i = 0; i < total_lenth; ++i)
    {
      CIAO_Event_Service_var temp =
        es_factory_.create (es_infos[i].type);

      CORBA::ULong curr_len = retv->length ();
      retv->length (curr_len + 1);

      retv[curr_len] =
        CIAO::CIAO_Event_Service::_duplicate (temp.in ());
    }
  return retv._retn ();
}


ACE_CString *
CIAO::NodeApplication_Impl::
create_connection_key (const Deployment::Connection & connection)
{
  ACE_CString * retv;
  ACE_NEW_RETURN (retv, ACE_CString, 0);

  (*retv) += connection.instanceName.in ();
  (*retv) += connection.portName.in ();
  (*retv) += connection.endpointInstanceName.in ();
  (*retv) += connection.endpointPortName.in ();

  if (CIAO::debug_level () > 3)
    ACE_DEBUG ((LM_ERROR, "The key is: %s\n", (*retv).c_str ()));

  return retv;
}


void
CIAO::NodeApplication_Impl::
handle_facet_receptable_connection (
    Components::CCMObject_ptr comp,
    const Deployment::Connection & connection,
    CORBA::Boolean add_connection)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::InvalidConnection))
{
  if (CIAO::debug_level () > 11)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::finishLaunch, "
                  "working on port name [%s] in instance [%s] \n",
                  connection.portName.in (),
                  connection.instanceName.in ()));
    }

  if (add_connection)
    {
      ::Components::Cookie_var cookie =
        comp->connect (connection.portName.in (),
                        connection.endpoint.in ()
                        ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_CString key = (*create_connection_key (connection));
      if (CIAO::debug_level () > 10)
        {
          ACE_DEBUG ((LM_ERROR, "[BINDING KEY]: %s\n", key.c_str ()));
        }
      this->cookie_map_.rebind (key, cookie);

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::finishLaunch\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] connected.\n",
                      connection.instanceName.in (),
                      connection.portName.in (),
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in ()));
        }
    }
  else
    {
      ACE_CString key = (*create_connection_key (connection));
      ::Components::Cookie_var cookie;
      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_ERROR, "[FINDING KEY]: %s\n", key.c_str ()));
        }
      if (this->cookie_map_.find (key, cookie) != 0)
        {
          ACE_DEBUG ((LM_ERROR, "Error: Cookie Not Found!\n"));
          ACE_TRY_THROW (Deployment::InvalidConnection ());
        }

      comp->disconnect (connection.portName.in (),
                        cookie.in ());
      this->cookie_map_.unbind (key);
      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::finishLaunch\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] disconnected.\n",
                      connection.instanceName.in (),
                      connection.portName.in (),
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in ()));
        }
    }
}


void
CIAO::NodeApplication_Impl::
handle_emitter_consumer_connection (
    Components::CCMObject_ptr comp,
    const Deployment::Connection & connection,
    CORBA::Boolean add_connection)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::InvalidConnection))
{
  Components::EventConsumerBase_var consumer =
      Components::EventConsumerBase::_narrow (connection.endpoint.in ()
                                              ACE_ENV_ARG_PARAMETER);
  ACE_TRY_CHECK;

  if (CORBA::is_nil (consumer.in ()))
    {
      ACE_ERROR ((LM_ERROR,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::handle_emitter_consumer_connection, "
                  "for port name [%s] in instance [%s] ,"
                  "there is an invalid endPoint. \n",
                  connection.portName.in (),
                  connection.instanceName.in ()));
      ACE_TRY_THROW (Deployment::InvalidConnection ());
    }

  if (CIAO::debug_level () > 11)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::handle_emitter_consumer_connection, "
                  "working on port name [%s] in instance [%s] \n",
                  connection.portName.in (),
                  connection.instanceName.in ()));
    }

  if (add_connection)
    {
      comp->connect_consumer (connection.portName.in (),
                              consumer.in ()
                              ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::handle_emitter_consumer_connection\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] connected.\n",
                      connection.instanceName.in (),
                      connection.portName.in (),
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in ()));
        }
    }
  else
    {
// Operation not implemented by the CIDLC.
//                  comp->disconnect_consumer (connection.portName.in (),
//                                             0
//                                             ACE_ENV_ARG_PARAMETER);
//                  ACE_TRY_CHECK;

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::handle_emitter_consumer_connection\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] disconnected.\n",
                      connection.instanceName.in (),
                      connection.portName.in (),
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in ()));
        }
    }
}


void
CIAO::NodeApplication_Impl::
handle_publisher_consumer_connection (
    Components::CCMObject_ptr comp,
    const Deployment::Connection & connection,
    CORBA::Boolean add_connection)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::InvalidConnection))
{
  Components::EventConsumerBase_var consumer =
      Components::EventConsumerBase::_narrow (connection.endpoint.in ()
                                              ACE_ENV_ARG_PARAMETER);
  ACE_TRY_CHECK;

  if (CORBA::is_nil (consumer.in ()))
    {
      ACE_ERROR ((LM_ERROR,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::handle_publisher_consumer_connection, "
                  "for port name [%s] in instance [%s] ,"
                  "there is an invalid endPoint. \n",
                  connection.portName.in (),
                  connection.instanceName.in ()));
      ACE_TRY_THROW (Deployment::InvalidConnection ());
    }

  if (CIAO::debug_level () > 11)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::handle_publisher_consumer_connection, "
                  "working on port name [%s] in instance [%s] \n",
                  connection.portName.in (),
                  connection.instanceName.in ()));
    }

  if (add_connection)
    {
      ::Components::Cookie_var cookie =
        comp->subscribe (connection.portName.in (),
                         consumer.in ()
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      ACE_CString key = (*create_connection_key (connection));
      this->cookie_map_.rebind (key, cookie);
      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::handle_publisher_consumer_connection\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] connected.\n",
                      connection.instanceName.in (),
                      connection.portName.in (),
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in ()));
        }
    }
  else // remove the connection
    {
      ACE_CString key = (*create_connection_key (connection));
      ::Components::Cookie_var cookie;

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_ERROR, "[FINDING KEY]: %s\n", key.c_str ()));
        }
      if (this->cookie_map_.find (key, cookie) != 0)
        {
          ACE_DEBUG ((LM_ERROR, "Error: Cookie Not Found!\n"));
          ACE_TRY_THROW (Deployment::InvalidConnection ());
        }

      comp->unsubscribe (connection.portName.in (),
                         cookie.in ()
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      this->cookie_map_.unbind (key);

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::handle_publisher_consumer_connection\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] disconnected.\n",
                      connection.instanceName.in (),
                      connection.portName.in (),
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in ()));
        }
    }
}


void
CIAO::NodeApplication_Impl::
handle_publisher_es_connection (
    Components::CCMObject_ptr comp,
    const Deployment::Connection & connection,
    CORBA::Boolean add_connection)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::InvalidConnection))
{
  if (! this->_is_publisher_es_conn (connection))
    {
      ACE_DEBUG ((LM_DEBUG,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::handle_publisher_es_connection: "
                  "Unsupported event connection type\n"));
      ACE_THROW (CORBA::NO_IMPLEMENT ());
    }

  const CIAO::CIAO_Event_Service_ptr event_service =
    connection.event_service;

  if (CORBA::is_nil (event_service))
    {
      ACE_DEBUG ((LM_DEBUG, "Nil event_service\n"));
      ACE_THROW (Deployment::InvalidConnection ());
    }

  // supplier ID
  ACE_CString sid (connection.instanceName.in ());
  sid += "_";
  sid += connection.portName.in ();
  sid += "_publisher";

  if (add_connection)
    {
      // Create a supplier_config and register it to ES
      CIAO::Supplier_Config_var supplier_config =
        event_service->create_supplier_config ();

      supplier_config->supplier_id (sid.c_str ());
      event_service->connect_event_supplier (supplier_config.in ());

      ::Components::Cookie_var cookie =
        comp->subscribe (connection.portName.in (),
                        supplier_config._retn ());

      ACE_CString key = (*create_connection_key (connection));
      this->cookie_map_.rebind (key, cookie);

      //supplier_config->destroy ();

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::handle_publisher_es_connection\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] connected.\n",
                      connection.instanceName.in (),
                      connection.portName.in (),
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in ()));
        }
    }
  else // remove the connection
    {
      ACE_CString key = (*create_connection_key (connection));
      ::Components::Cookie_var cookie;

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_ERROR, "[FINDING KEY]: %s\n", key.c_str ()));
        }
      if (this->cookie_map_.find (key, cookie) != 0)
        {
          ACE_DEBUG ((LM_ERROR, "Error: Cookie Not Found!\n"));
          ACE_TRY_THROW (Deployment::InvalidConnection ());
        }

     ACE_DEBUG ((LM_DEBUG, "about to unsubscribe event supplier\n"));

      comp->unsubscribe (connection.portName.in (),
                         cookie.in ());
      this->cookie_map_.unbind (key);

      ACE_DEBUG ((LM_DEBUG, "unsubscribe returned\n"));

  if (CORBA::is_nil (event_service))
    {
      ACE_DEBUG ((LM_DEBUG, "Nil event_service\n"));
      ACE_THROW (Deployment::InvalidConnection ());
    }

      event_service->disconnect_event_supplier (sid.c_str ());

      ACE_DEBUG ((LM_DEBUG, "disconnection event supplier returned\n"));

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::handle_publisher_es_connection\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] disconnected.\n",
                      connection.instanceName.in (),
                      connection.portName.in (),
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in ()));
        }
    }
}


void
CIAO::NodeApplication_Impl::
handle_es_consumer_connection (
    const Deployment::Connection & connection,
    CORBA::Boolean add_connection)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::InvalidConnection))
{
  if (! this->_is_es_consumer_conn (connection))
    {
      ACE_DEBUG ((LM_DEBUG,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::handle_es_consumer_connection: "
                  "Unsupported event connection type\n"));
      ACE_THROW (CORBA::NO_IMPLEMENT ());
    }

  // Get ES object
  const CIAO::CIAO_Event_Service_ptr event_service =
    connection.event_service;

  if (CORBA::is_nil (event_service))
    {
      ACE_DEBUG ((LM_ERROR,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::handle_es_consumer_connection: "
                  "NIL event_service\n"));
      ACE_THROW (Deployment::InvalidConnection ());
    }

  // Get consumer object
  Components::EventConsumerBase_var consumer =
    Components::EventConsumerBase::_narrow (connection.endpoint.in ());

  if (CORBA::is_nil (consumer.in ()))
    {
      ACE_DEBUG ((LM_ERROR,
                  "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                  "CIAO::NodeApplication_Impl::handle_es_consumer_connection: "
                  "Nil consumer port object reference\n"));
      ACE_THROW (Deployment::InvalidConnection ());
    }

  // supplier ID
  ACE_CString sid (connection.instanceName.in ());
  sid += "_";
  sid += connection.portName.in ();
  sid += "_publisher";

  // consumer ID
  ACE_CString cid (connection.endpointInstanceName.in ());
  cid += "_";
  cid += connection.endpointPortName.in ();
  cid += "_consumer";

  if (add_connection)
    {
      CIAO::Consumer_Config_var consumer_config =
        event_service->create_consumer_config ();

      //consumer_config->supplier_id ("Hello-Sender-idd_click_out_publisher");
      //consumer_config->supplier_id (sid.c_str ());
      consumer_config->consumer_id (cid.c_str ());
      consumer_config->consumer (consumer.in ());

      // Need to setup a filter, if it's specified in the descriptor
      // @TODO: This below code needs to be refactored into the consumer_config
      // servant implementation to make the code cleaner.
      for (CORBA::ULong i = 0; i < connection.config.length (); ++i)
        {
          if (ACE_OS::strcmp (connection.config[i].name.in (),
                              "EventFilter") != 0)
            continue;

          // Extract the filter information
          CIAO::DAnCE::EventFilter *filter = 0;
          connection.config[i].value >>=  filter;

          CORBA::ULong size = (*filter).sources.length ();

          switch ((*filter).type)
          {
          case CIAO::DAnCE::CONJUNCTION:
            ACE_DEBUG ((LM_DEBUG,
                        "DAnCE (%P|%t): Creating a conjunction group of size [%d]\n",
                        size));
            consumer_config->start_conjunction_group (size);
            break;
          case CIAO::DAnCE::DISJUNCTION:
            ACE_DEBUG ((LM_DEBUG,
                        "DAnCE (%P|%t): Creating a disjunction group of size [%d]\n",
                        size));
            consumer_config->start_disjunction_group (size);
            break;
          default:
            ACE_DEBUG ((LM_DEBUG, "Unknown event filter type.\n"));
            ACE_THROW (CORBA::NO_IMPLEMENT ());
          }

          for (CORBA::ULong j = 0; j < size; ++j)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "DAnCE (%P|%t): Insert source id [%s]\n",
                          (*filter).sources[j].in ()));
              consumer_config->insert_source ((*filter).sources[j].in ());
            }
        }

      event_service->connect_event_consumer (consumer_config.in ());
      consumer_config->destroy ();

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::handle_es_consumer_connection\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] connected.\n",
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in (),
                      connection.instanceName.in (),
                      connection.portName.in ()));
        }
    }
  else // remove the connection
    {
      event_service->disconnect_event_consumer (cid.c_str ());

      if (CIAO::debug_level () > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "CIAO (%P|%t) - NodeApplication_Impl.cpp, "
                      "CIAO::NodeApplication_Impl::handle_es_consumer_connection\n"
                      "[INSTANCE:PORT] : [%s:%s] --> [%s:%s] disconnected.\n",
                      connection.endpointInstanceName.in (),
                      connection.endpointPortName.in (),
                      connection.instanceName.in (),
                      connection.portName.in ()));
        }
    }
}

// Below code is not used at this time.
void
CIAO::NodeApplication_Impl::build_event_connection (
    const Deployment::Connection & connection,
    bool add_or_remove
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((Deployment::InvalidConnection,
                   CORBA::SystemException))
{
    ACE_DEBUG ((LM_DEBUG, "CIAO::NodeApplication_Impl::build_connection ()!!!\n"));

    ACE_DEBUG ((LM_DEBUG, "instanceName: %s\n", connection.instanceName.in ()));
    ACE_DEBUG ((LM_DEBUG, "portName: %s\n", connection.portName.in ()));

    ACE_DEBUG ((LM_DEBUG, "consumer Component Name: %s\n", connection.endpointInstanceName.in ()));
    ACE_DEBUG ((LM_DEBUG, "consumer Port Name: %s\n", connection.endpointPortName.in ()));

    ACE_DEBUG ((LM_DEBUG, "portkind: "));
    switch (connection.kind) {
      case Deployment::Facet: ACE_DEBUG ((LM_DEBUG, "Facet\n")); break;
      case Deployment::SimplexReceptacle: ACE_DEBUG ((LM_DEBUG, "SimplexReceptacle\n")); break;
      case Deployment::MultiplexReceptacle: ACE_DEBUG ((LM_DEBUG, "MultiplexReceptacle\n")); break;
      case Deployment::EventEmitter: ACE_DEBUG ((LM_DEBUG, "EventEmitter\n")); break;
      case Deployment::EventPublisher: ACE_DEBUG ((LM_DEBUG, "EventPublisher\n")); break;
      case Deployment::EventConsumer: ACE_DEBUG ((LM_DEBUG, "EventConsumer\n")); break;
    default:
      ACE_DEBUG ((LM_DEBUG, "Unknow\n")); break;
    }

    const CIAO::CIAO_Event_Service_ptr event_service =
      connection.event_service;


    // Get the consumer port object reference and put it into "consumer"
    Components::EventConsumerBase_var consumer =
      Components::EventConsumerBase::_narrow (connection.endpoint.in ()
                                              ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    if (CORBA::is_nil (consumer.in ()))
      {
        ACE_DEBUG ((LM_DEBUG, "Nil consumer port object reference\n"));
        ACE_THROW (Deployment::InvalidConnection ());
      }

    // Get the supplier component object reference.
    ACE_CString supplier_comp_name = connection.instanceName.in ();

    ACE_DEBUG ((LM_DEBUG, "source component name is: %s\n", supplier_comp_name.c_str ()));
    Component_State_Info comp_state;
    if (this->component_state_map_.find (supplier_comp_name, comp_state) != 0)
      {
        ACE_DEBUG ((LM_DEBUG, "Nil source component object reference\n"));
        ACE_THROW (Deployment::InvalidConnection ());
      }

    // Get the consumer component object reference.
    ACE_CString consumer_comp_name = connection.endpointInstanceName.in ();

    ACE_DEBUG ((LM_DEBUG, "consumer component name is: %s\n", consumer_comp_name.c_str ()));

    if (CORBA::is_nil (event_service))
      {
        ACE_DEBUG ((LM_DEBUG, "Nil event_service\n"));
        ACE_THROW (Deployment::InvalidConnection ());
      }

    // supplier ID
    ACE_CString sid (connection.instanceName.in ());
    sid += "_";
    sid += connection.portName.in ();
    sid += "_publisher";

    // consumer ID
    ACE_CString cid (connection.endpointInstanceName.in ());
    cid += "_";
    cid += connection.endpointPortName.in ();
    cid += "_consumer";

    //ACE_DEBUG ((LM_DEBUG, "Publisher: %s\n", sid.c_str ()));
    ACE_DEBUG ((LM_DEBUG, "Subscriber: %s\n", cid.c_str ()));


    if (add_or_remove == true)
      {
        CIAO::Supplier_Config_var supplier_config =
          event_service->create_supplier_config ();

        //supplier_config->supplier_id (sid.c_str ());
        event_service->connect_event_supplier (supplier_config.in ());
        supplier_config->destroy ();

        CIAO::Consumer_Config_var consumer_config =
          event_service->create_consumer_config ();

        //@@@
        //consumer_config->supplier_id ("dummy");
        consumer_config->consumer_id (cid.c_str ());
        consumer_config->consumer (consumer.in ());

        event_service->connect_event_consumer (consumer_config.in ());

        consumer_config->destroy ();
      }
    else
      {
        event_service->disconnect_event_supplier (sid.c_str ());
        event_service->disconnect_event_consumer (cid.c_str ());
      }

    ACE_DEBUG ((LM_DEBUG, "CIAO::NodeApplication_Impl::build_connection () completed!!!!\n"));
}

bool
CIAO::NodeApplication_Impl::
_is_es_consumer_conn (Deployment::Connection conn)
{
  if (conn.kind == Deployment::EventConsumer &&
    ACE_OS::strcmp (conn.endpointPortName, "CIAO_ES") == 0)
    return true;
  else
    return false;
}

bool
CIAO::NodeApplication_Impl::
_is_publisher_es_conn (Deployment::Connection conn)
{
  if (conn.kind == Deployment::EventPublisher &&
    ACE_OS::strcmp (conn.endpointPortName, "CIAO_ES") == 0)
    return true;
  else
    return false;
}
