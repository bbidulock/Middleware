// -*- C++ -*-
// $Id$

//=============================================================================
/**
 * @file  TaskMapFileIn.cpp
 *
 * This file contains the TaskMapFileIn class implementation for the input adapter
 * that initializes a TaskMap object using an XML TaskMap file.
 *
 * @author  John S. Kinnebrew <john.s.kinnebrew@vanderbilt.edu>
 */
//=============================================================================

#include "SA_POP_Types.h"
#include "TaskMapFileIn.h"
#include "Builder.h"
#include "SA_POP_XML_Typedefs.h"
#include "XML_TaskMap.hpp"

using namespace SA_POP;

// Constructor.
TaskMapFileIn::TaskMapFileIn (void)
{
  // Nothing to do.
};

// Destructor.
TaskMapFileIn::~TaskMapFileIn (void)
{
  // Nothing to do.
};

using SA_POP::XML::XML_Helper;

// Build task map from XML file.
void TaskMapFileIn::build_task_map (std::string filename, Builder *builder)
{
  if (!XML_Helper::XML_HELPER.is_initialized ())
    throw "SA_POP::TaskMapFileIn::build_task_map (): Could not initialize XML_Helper";

  // Parse file with Xerces.
  XERCES_CPP_NAMESPACE::DOMDocument *dom =
//*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****TEMP*****
// No longer need different call to XML Helper with/without CIAO... I think...
//#if defined (SA_POP_HAS_CIAO)
    XML_Helper::XML_HELPER.create_dom (filename.c_str ());
//#else
//  XML_Helper::XML_HELPER.create_dom (filename.c_str (), "");
//#endif  /* SA_POP_HAS_CIAO */
  if (!dom)
    throw "SA_POP::TaskMapFileIn::build_task_map (): Could not create Xerces DOMDocument from file";

  SA_POP::XML::TaskMap xml_tm = SA_POP::XML::reader::taskMap (dom);

  // Get task implementations.
  for (SA_POP::XML::TaskMap::taskImpl_iterator impl_iter =
    xml_tm.begin_taskImpl ();
    impl_iter != xml_tm.end_taskImpl (); impl_iter++)
  {
    // Get implementation ID.
    char implID[SA_POP::TaskMapFileIn::STR_BUF_SIZE];
    wcstombs (implID, (*impl_iter).implID ().c_str (),
      SA_POP::TaskMapFileIn::STR_BUF_SIZE);

    // Get implementation parameters.
    ImplParamSet params;
    params.clear ();
    for (SA_POP::XML::TaskImpl::param_iterator param_iter =
      (*impl_iter).begin_param ();
      param_iter != (*impl_iter).end_param (); param_iter++)
    {
      // Get parameter ID.
      char paramID[SA_POP::TaskMapFileIn::STR_BUF_SIZE];
      wcstombs (paramID, (*param_iter).paramID ().c_str (),
        SA_POP::TaskMapFileIn::STR_BUF_SIZE);

      // Get parameter kind.
      char kind[SA_POP::TaskMapFileIn::STR_BUF_SIZE];
      wcstombs (kind, (*param_iter).kind ().c_str (),
        SA_POP::TaskMapFileIn::STR_BUF_SIZE);

      // Get parameter value.
      char value[SA_POP::TaskMapFileIn::STR_BUF_SIZE];
      wcstombs (value, (*param_iter).value ().c_str (),
        SA_POP::TaskMapFileIn::STR_BUF_SIZE);

      // Add parameter to implementation parameter set.
      ImplParam param;
      param.id = paramID;
      param.kind = kind;
      param.value = value;
      params.insert (param);
    }

    // Add task implementation.
    TaskImpl *impl = new TaskImpl (implID, params);
    builder->add_task_impl (impl);
  }

 // ImplParamSet init_params;
 // ImplParam init_param;
 // init_param.id = "test_param1";
 // init_param.kind = "test_kind1";
 // init_param.value = "test_param_value1";
 // init_params.insert (init_param);

 // TaskImpl* initimpl = new TaskImpl ("initact_impl", init_params);
 // builder->add_task_impl (initimpl);

  // Get resources.
  for (SA_POP::XML::TaskMap::resource_iterator res_iter =
    xml_tm.begin_resource ();
    res_iter != xml_tm.end_resource (); res_iter++)
  {
    // Get resource ID.
    char resourceID[SA_POP::TaskMapFileIn::STR_BUF_SIZE];
    wcstombs (resourceID, (*res_iter).resourceID ().c_str (),
      SA_POP::TaskMapFileIn::STR_BUF_SIZE);

    // Get resource kind.
    SA_POP::ResourceKind kind;
    if ((*res_iter).kind () == SA_POP::XML::ResourceKind::DISCRETE)
      kind = SA_POP::DISCRETE;
    else if ((*res_iter).kind () == SA_POP::XML::ResourceKind::RESERVOIR)
      kind = SA_POP::RESERVOIR;
    else if ((*res_iter).kind () == SA_POP::XML::ResourceKind::UNARY)
      kind = SA_POP::UNARY;
    else
      kind = SA_POP::DISCRETE;

    // Get resource capacity.
    ResourceValue capacity = (*res_iter).capacity ();

    // Add resource.
    Resource resource;
    resource.id = resourceID;
    resource.kind = kind;
    resource.capacity = capacity;

    builder->add_resource (resource);

//	builder->assoc_impl_with_resource ("initact_impl", resourceID, 1);
  }

  // Get task to implementation associations.
  for (SA_POP::XML::TaskMap::taskToImpl_iterator tassoci_iter =
    xml_tm.begin_taskToImpl ();
    tassoci_iter != xml_tm.end_taskToImpl (); tassoci_iter++)
  {
    // Get task ID.
    TaskID taskID = (*tassoci_iter).taskID ();

    // Get impl ID.
    char implID[SA_POP::TaskMapFileIn::STR_BUF_SIZE];
    wcstombs (implID, (*tassoci_iter).implID ().c_str (),
      SA_POP::TaskMapFileIn::STR_BUF_SIZE);

    // Get duration.
    TimeValue duration = (*tassoci_iter).duration ();

    // Add association.
    builder->assoc_task_with_impl (taskID, implID, duration);
  }

 // builder->assoc_task_with_impl (INIT_TASK_ID, "initact_impl", 1);

  // Get task implementation to resource associations.
  for (SA_POP::XML::TaskMap::implToResource_iterator iassocr_iter =
    xml_tm.begin_implToResource ();
    iassocr_iter != xml_tm.end_implToResource (); iassocr_iter++)
  {
    // Get impl ID.
    char implID[SA_POP::TaskMapFileIn::STR_BUF_SIZE];
    wcstombs (implID, (*iassocr_iter).implID ().c_str (),
      SA_POP::TaskMapFileIn::STR_BUF_SIZE);

    // Get resource ID.
    char resourceID[SA_POP::TaskMapFileIn::STR_BUF_SIZE];
    wcstombs (resourceID, (*iassocr_iter).resourceID ().c_str (),
      SA_POP::TaskMapFileIn::STR_BUF_SIZE);

    // Get duration.
    ResourceValue utilization = (*iassocr_iter).utilization ();

    // Add association.
    builder->assoc_impl_with_resource (implID, resourceID, utilization);
  }
};
