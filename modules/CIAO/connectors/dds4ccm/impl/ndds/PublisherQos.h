/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef CIAO_RTI_PUBLISHERQOS_H
#define CIAO_RTI_PUBLISHERQOS_H

#include "PresentationQosPolicy.h"
#include "PartitionQosPolicy.h"
#include "GroupDataQosPolicy.h"
#include "EntityFactoryQosPolicy.h"

inline void
operator<<= (::DDS::PublisherQos &ddsqos, const ::DDS_PublisherQos & qos)
{
  ddsqos.presentation <<= qos.presentation;
  ddsqos.partition <<= qos.partition;
  ddsqos.group_data <<= qos.group_data;
  ddsqos.entity_factory <<= qos.entity_factory;
}

inline void
operator<<= (::DDS_PublisherQos &ddsqos, const ::DDS::PublisherQos & qos)
{
  ddsqos.presentation <<= qos.presentation;
  ddsqos.partition <<= qos.partition;
  ddsqos.group_data <<= qos.group_data;
  ddsqos.entity_factory <<= qos.entity_factory;
}

inline void
operator>>= (const ::DDS_PublisherQos &qos, ::DDS::PublisherQos & ddsqos)
{
  ddsqos.presentation <<= qos.presentation;
  ddsqos.partition <<= qos.partition;
  ddsqos.group_data <<= qos.group_data;
  ddsqos.entity_factory <<= qos.entity_factory;
}

inline void
operator>>= (const ::DDS::PublisherQos &qos, ::DDS_PublisherQos & ddsqos)
{
  ddsqos.presentation <<= qos.presentation;
  ddsqos.partition <<= qos.partition;
  ddsqos.group_data <<= qos.group_data;
  ddsqos.entity_factory <<= qos.entity_factory;
}

#endif /* CIAO_RTI_PUBLISHERQOS_H */
