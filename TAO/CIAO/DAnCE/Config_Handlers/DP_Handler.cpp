#include "DP_Handler.h"
#include "ciao/Deployment_DataC.h"

#include "CCD_Handler.h"
#include "ADD_Handler.h"
#include "MDD_Handler.h"
#include "IDD_Handler.h"
#include "ID_Handler.h"
#include "Property_Handler.h"
#include "cdp.hpp"

#include "DP_PCD_Handler.h"

ACE_RCSID (Config_Handlers,
           DP_Handler,
           "$Id$")

namespace CIAO
{
  namespace Config_Handlers
  {
    DP_Handler::DP_Handler (DeploymentPlan &dp)
      :   xsc_dp_ (0)
        , idl_dp_ (0)
        , retval_ (false)
    {
      if (!this->resolve_plan (dp))
        throw;
    }
    
    DP_Handler::DP_Handler (const ::Deployment::DeploymentPlan &plan)
      : xsc_dp_ (new DeploymentPlan),
        idl_dp_ (0),
        retval_ (0)
    {
      if (!this->build_xsc (plan))
        throw;
    }
    
    DP_Handler::~DP_Handler (void)
      throw ()
    {
    }
    
    DeploymentPlan const *
    DP_Handler::xsc (void) const
      throw (DP_Handler::NoPlan)
    {
      if (this->retval_ && this->xsc_dp_.get () != 0)
        return this->xsc_dp_.get ();

      throw NoPlan ();
    }
    
    DeploymentPlan *
    DP_Handler::xsc (void)
      throw (DP_Handler::NoPlan)
    {
      if (this->retval_ && this->xsc_dp_.get () != 0)
        return this->xsc_dp_.release ();
      
      throw NoPlan ();
    }
    
    ::Deployment::DeploymentPlan const *
    DP_Handler::plan (void) const
      throw (DP_Handler::NoPlan)
    {
      if (this->retval_ && this->idl_dp_.get () != 0)
        return this->idl_dp_.get ();

      throw NoPlan ();
    }

    ::Deployment::DeploymentPlan *
    DP_Handler::plan (void)
      throw (DP_Handler::NoPlan)
    {
      if (this->retval_ && this->idl_dp_.get () != 0)
        return this->idl_dp_.release ();

      throw NoPlan ();
    }

    bool
    DP_Handler::resolve_plan (DeploymentPlan &xsc_dp)
    {
      ::Deployment::DeploymentPlan *tmp =
          new Deployment::DeploymentPlan;

      this->idl_dp_.reset (tmp);

      // Read in the label, if present, since minoccurs = 0
      if (xsc_dp.label_p ())
	      {
	        this->idl_dp_->label =
	          CORBA::string_dup (xsc_dp.label ().c_str ());
	      }

      // Read in the UUID, if present
      if (xsc_dp.UUID_p ())
	      {
	        this->idl_dp_->UUID =
	          CORBA::string_dup (xsc_dp.UUID ().c_str ());
	      }


      // Similar thing for dependsOn
      for (DeploymentPlan::dependsOn_const_iterator dstart = xsc_dp.begin_dependsOn ();
	   dstart != xsc_dp.end_dependsOn ();
	   ++dstart)
      {
	CORBA::ULong len = this->idl_dp_->dependsOn.length ();
	this->idl_dp_->dependsOn.length (len + 1);
	ID_Handler::get_ImplementationDependency (
				   this->idl_dp_->dependsOn [len],
                *dstart);

      }

      /* @@ Not needed at this time...

      // ... An the property stuff
      for (DeploymentPlan::infoProperty_const_iterator pstart = xsc_dp.begin_infoProperty ();
	   pstart != xsc_dp.end_infoProperty ();
	   ++pstart)
	{
	  CORBA::ULong len =
	    this-idl_dp_->infoProperty.length ();

	  this->idl_dp_->infoProperty.length (len + 1);

	  Property_Handler::get_property (
	    *pstart,
	    this->idl_dp_->infoProperty [len]);
	}
      */

      // Read in the realizes, if present
      if (xsc_dp.realizes_p ())
      {
        this->retval_ =
          CCD_Handler::component_interface_descr (
            xsc_dp.realizes (),
            this->idl_dp_->realizes);

        if (!this->retval_)
          {
            ACE_DEBUG ((LM_ERROR,
                        "(%P|%t) DP_Handler: "
                        "Error parsing Component Interface Descriptor."));
            return false;
          }
      }


      this->retval_ =
        ADD_Handler::artifact_deployment_descrs (
          xsc_dp,
          this->idl_dp_->artifact);

      if (!this->retval_)
        {
          ACE_DEBUG ((LM_ERROR,
                      "(%P|%t) DP_Handler: "
                      "Error parsing Artifact Deployment Descriptior."));
          return false;
        }

      this->retval_ =
        MDD_Handler::mono_deployment_descriptions (
          xsc_dp,
          this->idl_dp_->implementation);

      if (!this->retval_)
        {
          ACE_DEBUG ((LM_ERROR,
                      "(%P|%t) DP_Handler: "
                      "Error parsing Monolithic Deployment Decriptions."));
          return false;
        }

      this->retval_ =
        IDD_Handler::instance_deployment_descrs (
          xsc_dp,
          this->idl_dp_->instance);

      if (!this->retval_)
        {
          ACE_DEBUG ((LM_ERROR,
                      "(%P|%t) DP_Handler: "
                      "Error parsing Instance Deployment Decriptions."));
          return false;
        }

      DP_PCD_Handler::plan_connection_descrs (xsc_dp, this->idl_dp_->connection);
      return this->retval_;
    }
    
    bool
    DP_Handler::build_xsc (const ::Deployment::DeploymentPlan &plan)
    {
      size_t len; //Used for checking the length of struct data members
      
      // Read in the label, if present, since minoccurs = 0
      if (plan.label != 0)
      {
	  XMLSchema::string< char > i((plan.label));
	  this->xsc_dp_->label(i);
      }

      // Read in the UUID, if present
      if (plan.UUID != 0)
      {
	  XMLSchema::string< char > j((plan.UUID));
	  this->xsc_dp_->UUID(j);
      }

      // Similar thing for dependsOn
      len = plan.dependsOn.length();
      for (size_t j = 0;
	   j < len;
	   ++j)
      {
	  this->xsc_dp_->add_dependsOn(
	      ID_Handler::impl_dependency(
		  plan.dependsOn[j]));	
      }
      

      /* @@ Not needed at this time for the forward handler, so I assume not for the reverse handlers either...
      // This should be functional if we want to activate it at a later point	 
      // ... And the property stuff
      len = plan.infoProperty.length();
      for (size_t q = 0;
	   q < len;
	   q++)
      {
	  this->xsc_dp_->add_infoProperty (
	      Property_Handler::get_property (
	          plan.infoProperty[q]));
      }
      */

      // We are assuming there is a realizes for the moment
      // @@ We may want to change this at a later date by creating a sequence of
      // @@ ComponentInterfaceDescriptions in the DeploymentPlan in ../ciao/Deployment_Data.idl
      // @@ so we can check for length
      this->xsc_dp_->realizes(CCD_Handler::component_interface_descr(plan.realizes));
      if (!this->xsc_dp_->realizes_p())
      {
	  ACE_DEBUG ((LM_ERROR,
		      "(%P|%t) DP_Handler: "
		      "Error parsing Component Interface Descriptor."));
	  return false;
      }

      //Take care of the artifact(s) if they exist
      len = plan.artifact.length();
      for(size_t k = 0;
	  k < len;
	  k++)
      {
	  this->xsc_dp_->add_artifact (
	      ADD_Handler::artifact_deployment_descr (
		  plan.artifact[k]));
      }
      
      //Take care of the implementation(s) if they exist
      len = plan.implementation.length();
      for(size_t l = 0;
	  l < len;
	  l++)
      {
	  this->xsc_dp_->add_implementation (
	      MDD_Handler::mono_deployment_description (
		  plan.implementation[l]));
      }
    
      //Ditto for the instance(s)
      len = plan.instance.length();
      for(size_t m = 0;
	  m < len;
	  m++)
      {
	  this->xsc_dp_->add_instance (
	      IDD_Handler::instance_deployment_descr (
		  plan.instance[m]));
      }

      //Finally, take care of the Connection Planning
      len = plan.connection.length();
      for(size_t n = 0; n < len; n++)
      {
	  this->xsc_dp_->add_connection (
	      DP_PCD_Handler::plan_connection_descr (
		  plan.connection[n]));
      }
      
      retval_ = true;
      return true;
    }
  }
}
