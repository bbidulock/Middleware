/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef CIAO_RTI_DESTINATIONORDERQOSPOLICY_H
#define CIAO_RTI_DESTINATIONORDERQOSPOLICY_H

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

inline void
operator>>= (const ::DDS_DestinationOrderQosPolicy &qos, ::DDS::DestinationOrderQosPolicy & ddsqos)
{
  ddsqos.kind = static_cast < ::DDS::DestinationOrderQosPolicyKind> (qos.kind);
}

inline void
operator>>= (const ::DDS::DestinationOrderQosPolicy &qos, ::DDS_DestinationOrderQosPolicy & ddsqos)
{
  ddsqos.kind = static_cast < ::DDS_DestinationOrderQosPolicyKind> (qos.kind);
}
#endif

#endif /* CIAO_RTI_DESTINATIONORDERQOSPOLICY_H */
