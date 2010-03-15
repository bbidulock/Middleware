/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_PARTITIONQOSPOLICY_H
#define DDS4CCM_PARTITIONQOSPOLICY_H

#include "StringSeq.h"

#include "dds4ccm/impl/dds4ccm_conf.h"

#if (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::PartitionQosPolicy DDS_PartitionQosPolicy;
#endif

#if (CIAO_DDS4CCM_NDDS==1)
inline void
operator<<= (::DDS::PartitionQosPolicy &ddsqos, const ::DDS_PartitionQosPolicy & qos)
{
  ddsqos.name <<= qos.name;
}

inline void
operator<<= (::DDS_PartitionQosPolicy &ddsqos, const ::DDS::PartitionQosPolicy & qos)
{
  ddsqos.name <<= qos.name;
}

#endif

#endif /* DDS4CCM_PARTITIONQOSPOLICY_H */
