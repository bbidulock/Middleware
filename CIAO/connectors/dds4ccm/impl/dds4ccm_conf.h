/**
 * @author Marcel Smit <msmit@remedy.nl>
 *
 * $Id$
 *
 * Configuration file for DDS4CCM.
 */

#ifndef DDS4CCM_CONF_H_
#define DDS4CCM_CONF_H_

/// Defines whether the Reader uses a QueryCondition.
/// If not, it uses a ContentFilteredTopic.
#define DDS4CCM_USES_QUERY_CONDITION  0

/// Defines whether DDS4CCM does a thread switch when
/// a DDS callback has been received. If this is not
/// defined, DDS4CCM uses the DDS thread to handle the
/// callbacks.
#define CIAO_DDS4CCM_CONTEXT_SWITCH   0

/// DDS Vendor settings
#define CIAO_DDS4CCM_NDDS     1
#define CIAO_DDS4CCM_OPENDDS  0
#define CIAO_DDS4CCM_SPLICE   0

#endif /* DDS4CCM_CONF_H_ */
