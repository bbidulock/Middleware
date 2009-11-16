/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef CIAO_RTI_HISTORYQOSPOLICY_H
#define CIAO_RTI_HISTORYQOSPOLICY_H

inline void
operator<<= (::DDS::HistoryQosPolicy &ddsqos, const ::DDS_HistoryQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS::HistoryQosPolicyKind> (qos.kind);
  ddsqos.depth = qos.depth;
}

inline void
operator<<= (::DDS_HistoryQosPolicy &ddsqos, const ::DDS::HistoryQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS_HistoryQosPolicyKind> (qos.kind);
  ddsqos.depth = qos.depth;
}

inline void
operator>>= (const ::DDS_HistoryQosPolicy &qos, ::DDS::HistoryQosPolicy & ddsqos)
{
  ddsqos.kind = static_cast < ::DDS::HistoryQosPolicyKind> (qos.kind);
  ddsqos.depth = qos.depth;
}

inline void
operator>>= (const ::DDS::HistoryQosPolicy &qos, ::DDS_HistoryQosPolicy & ddsqos)
{
  ddsqos.kind = static_cast < ::DDS_HistoryQosPolicyKind> (qos.kind);
  ddsqos.depth = qos.depth;
}

#endif /* CIAO_RTI_HISTORYQOSPOLICY_H */
