/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_DESTINATIONORDERQOSPOLICY_H
#define DDS4CCM_DESTINATIONORDERQOSPOLICY_H

#include "Duration_t.h"

#if defined (CIAO_DDS4CCM_OPENDDS) && (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::DestinationOrderQosPolicy DDS_DestinationOrderQosPolicy;
#endif

#if defined (CIAO_DDS4CCM_NDDS) && (CIAO_DDS4CCM_NDDS==1)
inline void
operator<<= (::DDS::DestinationOrderQosPolicy &ddsqos, const ::DDS_DestinationOrderQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS::DestinationOrderQosPolicyKind> (qos.kind);
}

inline void
operator<<= (::DDS_DestinationOrderQosPolicy &ddsqos, const ::DDS::DestinationOrderQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS_DestinationOrderQosPolicyKind> (qos.kind);
}

#endif

#endif /* DDS4CCM_DESTINATIONORDERQOSPOLICY_H */
