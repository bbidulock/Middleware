/**
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_INSTANCEHANDLE_T_H_
#define DDS4CCM_INSTANCEHANDLE_T_H_

#include "dds4ccm/impl/dds4ccm_conf.h"
#include "ndds/ndds_cpp.h"

inline void
operator<<= (::DDS::InstanceHandle_t &ddsinstancehandle, const ::DDS_InstanceHandle_t & instancehandle)
{
  ACE_OS::memcpy (ddsinstancehandle.value, instancehandle.keyHash.value, sizeof (instancehandle.keyHash.value));
  ddsinstancehandle.length = instancehandle.keyHash.length;
  ddsinstancehandle.isValid = instancehandle.isValid;
}

inline void
operator<<= (::DDS_InstanceHandle_t &ddsinstancehandle, const ::DDS::InstanceHandle_t & instancehandle)
{
  ACE_OS::memcpy (ddsinstancehandle.keyHash.value, instancehandle.value, sizeof (instancehandle.value));
  ddsinstancehandle.keyHash.length = instancehandle.length;
  ddsinstancehandle.isValid = instancehandle.isValid;
}

inline bool
operator== (const DDS_InstanceHandle_t & dds_instancehandle, const ::DDS::InstanceHandle_t & ccm_instancehandle)
{
  return dds_instancehandle.keyHash.length  == ccm_instancehandle.length  &&
         static_cast<CORBA::ULong>(dds_instancehandle.isValid) == ccm_instancehandle.isValid &&
         ACE_OS::memcmp (dds_instancehandle.keyHash.value, ccm_instancehandle.value, sizeof (dds_instancehandle.keyHash.value)) == 0;
}

inline bool
operator== (const ::DDS::InstanceHandle_t & ccm_instancehandle, const DDS_InstanceHandle_t & dds_instancehandle)
{
  return ccm_instancehandle.length  == dds_instancehandle.keyHash.length  &&
         ccm_instancehandle.isValid == static_cast<CORBA::ULong>(dds_instancehandle.isValid) &&
         ACE_OS::memcmp (ccm_instancehandle.value, dds_instancehandle.keyHash.value, sizeof (ccm_instancehandle.value)) == 0;
}

inline bool
operator!= (const DDS_InstanceHandle_t & dds_instancehandle, const ::DDS::InstanceHandle_t & ccm_instancehandle)
{
  return dds_instancehandle.keyHash.length != ccm_instancehandle.length  ||
         static_cast<CORBA::ULong>(dds_instancehandle.isValid) != ccm_instancehandle.isValid ||
         ACE_OS::memcmp (dds_instancehandle.keyHash.value, ccm_instancehandle.value, sizeof (dds_instancehandle.keyHash.value)) != 0;
}

inline bool
operator!= (const ::DDS::InstanceHandle_t & ccm_instancehandle, const DDS_InstanceHandle_t & dds_instancehandle)
{
  return ccm_instancehandle.length  != dds_instancehandle.keyHash.length  ||
         ccm_instancehandle.isValid != static_cast<CORBA::ULong>(dds_instancehandle.isValid) ||
         ACE_OS::memcmp (ccm_instancehandle.value, dds_instancehandle.keyHash.value, sizeof (ccm_instancehandle.value)) != 0;
}
#endif /* DDS4CCM_INSTANCEHANDLE_T_H_ */
