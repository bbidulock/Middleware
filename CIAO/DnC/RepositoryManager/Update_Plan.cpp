// $Id$

#include "RepositoryManager_Impl.h"
#include "Update_Plan.h"
#include "DeploymentC.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/OS_NS_stdio.h"
#include "ace/streams.h"

void traverse_package (Deployment::PackageConfiguration* &pc,
                       Deployment::DeploymentPlan &plan,
                       REF_MAP &ref_map, REF_MAP &primary_ref_map)
{
  for (CORBA::ULong x = 0; x < pc->basePackage.length (); ++x)
    {
      for (CORBA::ULong y = 0; 
           y < pc->basePackage[x].implementation.length (); ++y)
        {
          Deployment::ComponentImplementationDescription cid =
            pc->basePackage[x].implementation[y].referencedImplementation;
          for (CORBA::ULong z = 0; z < cid.assemblyImpl.length (); ++z)
            {
              Deployment::ComponentAssemblyDescription assembly =
                cid.assemblyImpl[z];
              for (CORBA::ULong k = 0; 
                   k < assembly.instance.length (); ++k)
                {
                  Deployment::SubcomponentInstantiationDescription ins =
                    assembly.instance[k];
                  const char* in_name = ins.name;
                  for (CORBA::ULong l = 0; l < plan.instance.length (); ++l)
                    {
                      const char* plan_name = plan.instance[l].name;
                      if (strcmp (plan_name, in_name) == 0)
                        {
                          traverse_instance (ins, plan, l,
                                             ref_map, primary_ref_map);
                        }
                    }
                }
              for (CORBA::ULong m = 0; 
                   m < assembly.connection.length (); ++m)
                {
                  Deployment::AssemblyConnectionDescription
                     assembly_connection = assembly.connection[m];
                  traverse_connection (assembly,
                                       assembly_connection,
                                       plan);
                }
            }
        }
    }
}

void traverse_connection (Deployment::ComponentAssemblyDescription
                          &assembly,
                          Deployment::AssemblyConnectionDescription
                          &assembly_connection,
                          Deployment::DeploymentPlan &plan)
{
  CORBA::ULong con_length (plan.connection.length ());
  plan.connection.length (con_length + 1);
  for (CORBA::ULong n = 0;
       n < assembly_connection.internalEndpoint.length ();
       ++n)
    {
      CORBA::ULong iep_len (plan.connection[con_length].
                            internalEndpoint.length ());
      plan.connection[con_length].internalEndpoint
                   .length (iep_len + 1);
      plan.connection[con_length].internalEndpoint
          [iep_len].portName = assembly_connection.
                               internalEndpoint[n].portName;
      CORBA::ULong ins_ref = assembly_connection.internalEndpoint[n].
                             instanceRef;
      const char* ins_name = assembly.instance[ins_ref].name;
      for (CORBA::ULong w = 0; w < plan.instance.length (); 
           ++w)
        {
          const char* pl_name = plan.instance[w].name;
          if (strcmp (pl_name, ins_name) == 0)
            {
              plan.connection[con_length].internalEndpoint
                [iep_len].instanceRef = w;
              break;
            }
        }
      traverse_interface (assembly.instance[ins_ref],
                          plan.connection[con_length].
                          internalEndpoint[iep_len]);
    }
}

void traverse_interface (Deployment::SubcomponentInstantiationDescription
                         &instance,
                         Deployment::PlanSubcomponentPortEndpoint
                         &pspe)
{
  for (CORBA::ULong m = 0; m < instance.package.length (); ++m)
    {
      Deployment::ComponentPackageDescription
	package = instance.package[m];

      Deployment::ComponentInterfaceDescription
        cid = package.realizes;

      for (CORBA::ULong n = 0; n < cid.port.length (); ++n)
        {
          const char* main_port_name = cid.port[n].name;
          const char* port_name = pspe.portName;
          if (strcmp (main_port_name, port_name) == 0)
            {
              pspe.kind = cid.port[n].kind;
            }
        }
    }
}

void traverse_instance (Deployment::SubcomponentInstantiationDescription
                        &instance,
			Deployment::DeploymentPlan &plan, int l,
                        REF_MAP &ref_map, REF_MAP &primary_ref_map)
{
  ART_REF_MAP art_ref_map;

  for (CORBA::ULong m = 0; m < instance.package.length (); ++m)
    {
      Deployment::ComponentPackageDescription
	package = instance.package[m];

      for (CORBA::ULong n = 0; n < package.implementation.length (); ++n)
	{
	  Deployment::PackagedComponentImplementation
	    impl = instance.package[m].implementation[n];
	  CORBA::ULong impl_length (plan.implementation.length ());
	  plan.implementation.length (impl_length + 1);
	  plan.implementation[impl_length].name = plan.instance[l].name;
	  plan.instance[l].implementationRef = impl_length;

	  for (CORBA::ULong p = 0;
               p < impl.referencedImplementation.monolithicImpl.length (); ++p)
	    {
	      Deployment::MonolithicImplementationDescription
		mid = impl.referencedImplementation.monolithicImpl[p];

	      for (CORBA::ULong q = 0; q < mid.primaryArtifact.length (); ++q)
		{
		  Deployment::ImplementationArtifactDescription
		    pack_iad = mid.primaryArtifact[q].referencedArtifact;

		  CORBA::ULong art_length (plan.artifact.length ());
		  plan.artifact.length (art_length + 1);
		  plan.artifact[art_length].name =
                       mid.primaryArtifact[q].name;
		  plan.artifact[art_length].node = plan.instance[l].node;
                  ACE_TString artifact_name =
                     (const char*)plan.artifact[art_length].name;
                  ref_map.bind (artifact_name, art_length);
                  primary_ref_map.bind (artifact_name,
                                        art_length);
		  CORBA::ULong
		    art_ref_len (plan.implementation[impl_length].
                                 artifactRef.length ());
		  plan.implementation[impl_length].artifactRef.length
                        (art_ref_len + 1);
		  plan.implementation[impl_length].artifactRef[art_ref_len]
		    = art_length;
		  for (CORBA::ULong e = 0; e < pack_iad.location.length (); ++e)
		    {
		      CORBA::ULong
			art_loc_len
                          (plan.artifact[art_length].location.length ());
		      plan.artifact[art_length].location.length
                        (art_loc_len + 1);
		      plan.artifact[art_length].location[art_loc_len]
			= pack_iad.location[e];
		    }
		  for (CORBA::ULong f = 0;
                       f < pack_iad.execParameter.length (); ++f)
		    {
		      CORBA::ULong
			art_pro_len
                         (plan.artifact[art_length].execParameter.length ());
		      plan.artifact[art_length].execParameter.length
			(art_pro_len + 1);
		      plan.artifact[art_length].execParameter[art_pro_len]
			= pack_iad.execParameter[f];
		    }
		  for (CORBA::ULong g = 0;
                       g < pack_iad.dependsOn.length (); ++g)
		    {
                      ACE_TString dep_name =
                         (const char*)pack_iad.dependsOn[g].name;
                      int arti_len;

                      if (ref_map.find (dep_name, arti_len) == 0)
                        {
                          if (primary_ref_map.find (dep_name, arti_len) != 0)
                            {
                              if (art_ref_map.find (arti_len, arti_len) != 0)
                                {
		                  CORBA::ULong
		                    new_art_ref_len
                                      (plan.implementation[impl_length].
                                             artifactRef.length ());
		                  plan.implementation[impl_length].
                                     artifactRef.length
                                       (new_art_ref_len + 1);
		                  plan.implementation[impl_length].
                                     artifactRef[new_art_ref_len] =
                                       arti_len;
                                  art_ref_map.bind (arti_len, arti_len);
                                }
                            }
                        }
                      else
                        {
                          Deployment::ImplementationArtifactDescription
                             depends_iad = pack_iad.dependsOn[g].
                                  referencedArtifact;
		          CORBA::ULong new_art_length (plan.artifact.length ());
		          plan.artifact.length (new_art_length + 1);
                          plan.artifact[new_art_length].name =
                            pack_iad.dependsOn[g].name;
		          plan.artifact[new_art_length].node =
                             plan.instance[l].node;
		          for (CORBA::ULong h = 0;
                               h < depends_iad.location.length (); ++h)
		            {
		              CORBA::ULong
			        new_art_loc_len
                                  (plan.artifact[new_art_length].
                                      location.length ());
		              plan.artifact[new_art_length].location.length
                                (new_art_loc_len + 1);
		              plan.artifact[new_art_length].
                                 location[new_art_loc_len]
			           = depends_iad.location[h];
		            }
                          ref_map.bind (
                             (const char*)plan.artifact[new_art_length].name,
                              new_art_length);
		          CORBA::ULong
		            new_art_ref_len (plan.implementation[impl_length].
                                         artifactRef.length ());
		          plan.implementation[impl_length].artifactRef.length
                                (new_art_ref_len + 1);
		          plan.implementation[impl_length].
                                artifactRef[new_art_ref_len] = new_art_length;
                          art_ref_map.bind (new_art_length, new_art_length);
                        }
                    }
		}
	    }
	  for (CORBA::ULong x = 0;
               x < impl.referencedImplementation.configProperty.length (); ++x)
	    {
	      CORBA::ULong
                impl_pro_len
                  (plan.implementation[impl_length].execParameter.length ());
              plan.implementation[impl_length].execParameter.length
			(impl_pro_len + 1);
              plan.implementation[impl_length].execParameter[impl_pro_len]
			= impl.referencedImplementation.configProperty[x];

	      CORBA::ULong
                ins_pro_len
                  (plan.instance[l].configProperty.length ());
              plan.instance[l].configProperty.length
			(ins_pro_len + 1);
              plan.instance[l].configProperty[ins_pro_len]
			= impl.referencedImplementation.configProperty[x];
            }
	}
    }
}
