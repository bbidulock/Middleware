// $Id$

#include "orbsvcs/CosLifeCycleC.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/CosPropertyServiceC.h"
#include "orbsvcs/RtecEventCommC.h"
#include "orbsvcs/RtecEventChannelAdminC.h"
#include "orbsvcs/RtecSchedulerC.h"

ACE_RCSID(orbsvcs, tmplinst_orbsvcs, "$Id$")

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class TAO_Object_Manager<CORBA_Object>;
template class TAO_Object_Manager<CORBA_TypeCode>;
template class TAO_Unbounded_Object_Sequence<CORBA_Object>;
template class TAO_Unbounded_Object_Sequence<CORBA_TypeCode>;
template class TAO_Unbounded_Sequence<CosLifeCycle::NVP>;
template class TAO_Unbounded_Sequence<CosNaming::NameComponent>;
template class TAO_Unbounded_Sequence<CosNaming::Binding>;
template class TAO_Unbounded_Sequence<CosPropertyService::Property>;
template class TAO_Unbounded_Sequence<CosPropertyService::PropertyDef>;
template class TAO_Unbounded_Sequence<CosPropertyService::PropertyException>;
template class TAO_Unbounded_Sequence<CosPropertyService::PropertyMode>;
template class TAO_Unbounded_Sequence<RtecEventComm::Event>;
template class TAO_Unbounded_Sequence<RtecEventChannelAdmin::Dependency>;
template class TAO_Unbounded_Sequence<RtecEventChannelAdmin::Publication>;
template class TAO_Unbounded_Sequence<RtecScheduler::Dependency_Info>;
template class TAO_Unbounded_Sequence<RtecScheduler::RT_Info>;
#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate TAO_Object_Manager<CORBA_Object>
#pragma instantiate TAO_Object_Manager<CORBA_TypeCode>
#pragma instantiate TAO_Unbounded_Object_Sequence<CORBA_Object>
#pragma instantiate TAO_Unbounded_Object_Sequence<CORBA_TypeCode>
#pragma instantiate TAO_Unbounded_Sequence<CosLifeCycle::NVP>
#pragma instantiate TAO_Unbounded_Sequence<CosNaming::NameComponent>
#pragma instantiate TAO_Unbounded_Sequence<CosNaming::Binding>
#pragma instantiate TAO_Unbounded_Sequence<CosPropertyService::Property>
#pragma instantiate TAO_Unbounded_Sequence<CosPropertyService::PropertyDef>
#pragma instantiate TAO_Unbounded_Sequence<CosPropertyService::PropertyException>
#pragma instantiate TAO_Unbounded_Sequence<CosPropertyService::PropertyMode>
#pragma instantiate TAO_Unbounded_Sequence<RtecEventComm::Event>
#pragma instantiate TAO_Unbounded_Sequence<RtecEventChannelAdmin::Dependency>
#pragma instantiate TAO_Unbounded_Sequence<RtecEventChannelAdmin::Publication>
#pragma instantiate TAO_Unbounded_Sequence<RtecScheduler::Dependency_Info>
#pragma instantiate TAO_Unbounded_Sequence<RtecScheduler::RT_Info>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
