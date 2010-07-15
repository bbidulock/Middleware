/**
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef QUERYCONDITION_T_H_
#define QUERYCONDITION_T_H_

#include "dds4ccm/idl/dds_rtf2_dcpsEC.h"

#include "dds4ccm/idl/dds_rtf2_dcpsC.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

#if (CIAO_DDS4CCM_NDDS==1)
#include "ndds/ndds_cpp.h"
#endif

#if (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::QueryCondition DDSQueryCondition;
#endif

namespace CIAO
{
  namespace DDS4CCM
  {
    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    class DataReader_T;

    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    class CCM_DDS_QueryCondition_T :
      public virtual ::DDS::CCM_QueryCondition,
      public virtual ::CORBA::LocalObject
    {
    typedef DataReader_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE> DataReader_type;

    public:
      /// Constructor
      CCM_DDS_QueryCondition_T (DDSQueryCondition * qc);

      /// Destructor
      virtual ~CCM_DDS_QueryCondition_T (void);

      virtual ::CORBA::Boolean get_trigger_value (void);

      virtual ::DDS::SampleStateMask get_sample_state_mask (void);

      virtual ::DDS::ViewStateMask get_view_state_mask (void);

      virtual ::DDS::InstanceStateMask get_instance_state_mask (void);

      virtual ::DDS::DataReader_ptr get_datareader (void);

      virtual char *get_query_expression (void);

      virtual ::DDS::ReturnCode_t
      get_query_parameters (::DDS::StringSeq & query_parameters);

      virtual ::DDS::ReturnCode_t
      set_query_parameters (const ::DDS::StringSeq & query_parameters);

      DDSQueryCondition * get_impl (void);

      void set_impl (DDSQueryCondition * qc);

    private:
      DDSQueryCondition * impl_;

      DDSQueryCondition * impl ();
    };
  }
}

#include "dds4ccm/impl/QueryCondition_T.cpp"

#endif /* QUERYCONDITION_T_H_ */
