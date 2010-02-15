// $Id$


#include "ace/streams.h"
#include "DAnCE/Deployment/DAnCE_PropertiesC.h"
#include "DAnCE/Logger/Log_Macros.h"

#include "NodeApplicationManager_Impl.h"
#include "NodeApplication/NodeApplication_Impl.h"
#include "NodeManager/NodeManager_Impl.h"

using namespace DAnCE;

NodeApplicationManager_Impl::NodeApplicationManager_Impl (CORBA::ORB_ptr orb,
                                                          PortableServer::POA_ptr poa,
                                                          const Deployment::DeploymentPlan& plan,
                                                          const ACE_CString& node_name,
                                                          const PROPERTY_MAP &properties)
    : plan_ (plan),
      orb_ (CORBA::ORB::_duplicate (orb)),
      poa_ (PortableServer::POA::_duplicate (poa)),
      application_ (0),
      node_name_ (node_name),
      properties_ ()
{
  DANCE_TRACE ("NodeApplicationManager_Impl::NodeApplicationManager_Impl");

  DANCE_DEBUG (6, (LM_DEBUG, DLINFO
               ACE_TEXT(" NodeApplicationManager_Impl::NodeApplicationManager_Impl - ")
               ACE_TEXT("Initializing for node '%C' and plan '%C' starting...\n"),
               node_name.c_str(),
               plan_.UUID.in()));

  PROPERTY_MAP::const_iterator i = properties.begin ();
  while (!i.done ())
    {
      DANCE_DEBUG (6, (LM_DEBUG, DLINFO
                    ACE_TEXT("NodeApplicationManager_Impl::NodeApplicationManager_Impl - ")
                    ACE_TEXT("Binding value for property %C\n"), i->key ().c_str ()));
      this->properties_.bind (i->key (), i->item ());
      i.advance ();
    }
}

NodeApplicationManager_Impl::~NodeApplicationManager_Impl()
{
  DANCE_TRACE ("NodeApplicationManager_Impl::~NodeApplicationManager_Impl");

  try
    {
      if (this->application_ != 0)
        {
          CORBA::Object_var app =
            this->poa_->servant_to_reference (this->application_);
          PortableServer::ObjectId_var id = this->poa_->reference_to_id (app);
          this->poa_->deactivate_object (id);

          delete this->application_;
          this->application_ = 0;
        }
    }
  catch (...)
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO
                    ACE_TEXT("NodeApplicationManager_Impl::~NodeApplicationManager_Impl - ")
                    ACE_TEXT("Caught exception in NodeApplicationManager destructor\n")));
    }
}

Deployment::Application_ptr
NodeApplicationManager_Impl::startLaunch (const Deployment::Properties &,
                                          Deployment::Connections_out providedReference)
{
  DANCE_TRACE ("NodeApplicationManager_Impl::startLaunch");

  // Creating NodeApplication object
  DANCE_DEBUG (9, (LM_TRACE, DLINFO ACE_TEXT("NodeApplicationManager_impl::startLaunch - ")
               ACE_TEXT("Initializing NodeApplication\n")));
  ACE_NEW_THROW_EX (this->application_,
                    NodeApplication_Impl (this->orb_.in(),
                                          this->poa_.in(),
                                          this->plan_,
                                          this->node_name_,
                                          this->properties_),
                    CORBA::NO_MEMORY ());

  DANCE_DEBUG (9, (LM_TRACE, DLINFO
                ACE_TEXT("NodeApplicationManager_impl::startLaunch - ")
               ACE_TEXT("Instructing NodeApplication to initialize components.\n")));

  this->application_->init_components();

  DANCE_DEBUG (9, (LM_TRACE, DLINFO
               ACE_TEXT("NodeApplicationManager_impl::startLaunch - ")
               ACE_TEXT("Collecting connection references\n")));

  providedReference = this->application_->getAllConnections();

  DANCE_DEBUG (6, (LM_DEBUG, DLINFO
               ACE_TEXT("NodeApplicationManager_impl::startLaunch - ")
               ACE_TEXT("Activating NodeApplication servant\n")));

  PortableServer::ObjectId_var as_id =
    this->poa_->activate_object (this->application_);

  CORBA::Object_var as_obj = this->poa_->id_to_reference (as_id.in ());
  Deployment::Application_var app = Deployment::Application::_narrow (as_obj.in ());

  return app._retn ();
}

void
NodeApplicationManager_Impl::destroyApplication (Deployment::Application_ptr application)
{
  DANCE_TRACE ("NodeApplicationManager_Impl::destroyApplication");

  try
  {
    if (!application->_is_equivalent (this->poa_->servant_to_reference (this->application_)))
      {
        DANCE_ERROR (1, (LM_ERROR, DLINFO
                     ACE_TEXT("NodeApplicationManager_Impl::destroyApplication - ")
                     ACE_TEXT("application is equivalent to current application\n")));
        throw ::Deployment::StopError();
      }

    CORBA::Any val;

    if (this->properties_.find (DAnCE::STANDALONE_NM, val) == 0)
      {
        DANCE_DEBUG (9, (LM_TRACE, DLINFO ACE_TEXT("NodeApplicationManager_Impl::destroyApplication - ")
                      ACE_TEXT("Found STANDALONE_NM property\n")));

        CORBA::Boolean standalone = false;

        val >>= CORBA::Any::to_boolean (standalone);

        this->application_->passivate_components ();
        this->application_->remove_components ();
      }

    PortableServer::ObjectId_var id = this->poa_->reference_to_id (application);
    this->poa_->deactivate_object (id);

    delete this->application_;
    this->application_ = 0;
  }
  catch (const CORBA::SystemException &)
  {
    throw;
  }
  catch (const Deployment::StopError &)
  {
    throw;
  }
  catch (const CORBA::UserException &e)
  {
    DANCE_ERROR (1, (LM_ERROR, DLINFO
                 ACE_TEXT("NodeApplicationManager_Impl::destroyApplication failed with UserException %C(%C) \"%C\"\n"),
                 e._name(), e._rep_id(), e._info().c_str()));
    throw Deployment::StopError(e._name(), e._info().c_str());
  }
  catch (...)
  {
    DANCE_ERROR (1, (LM_ERROR, DLINFO
                ACE_TEXT("NodeApplicationManager_Impl::destroyApplication failed with unknown exception.\n")));
    throw Deployment::StopError();
  }
}

