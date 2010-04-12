/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_LIVELINESSQOSPOLICY_H
#define DDS4CCM_LIVELINESSQOSPOLICY_H

#include "Duration_t.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

#if (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::LivelinessQosPolicy DDS_LivelinessQosPolicy;
#endif

#if (CIAO_DDS4CCM_NDDS==1)
inline void
operator<<= (::DDS::LivelinessQosPolicy &ddsqos, const ::DDS_LivelinessQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS::LivelinessQosPolicyKind> (qos.kind);
  ddsqos.lease_duration <<= qos.lease_duration;
}

inline void
operator<<= (::DDS_LivelinessQosPolicy &ddsqos, const ::DDS::LivelinessQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS_LivelinessQosPolicyKind> (qos.kind);
  ddsqos.lease_duration <<= qos.lease_duration;
}

#endif

#endif /* DDS4CCM_LIVELINESSQOSPOLICY_H */
