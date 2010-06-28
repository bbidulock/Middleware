/**
 * @author Marcel Smit <msmit@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */
#ifndef DDS_LISTEN_T_H_
#define DDS_LISTEN_T_H_

#include "dds4ccm/impl/DDS_Subscriber_Base_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Reactor;
ACE_END_VERSIONED_NAMESPACE_DECL



template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED, DDS4CCM_Vendor VENDOR_TYPE>
class DDS_Listen_T
  : public DDS_Subscriber_Base_T<DDS_TYPE, CCM_TYPE, FIXED, VENDOR_TYPE>
{
public:
  DDS_Listen_T (void);
  ~DDS_Listen_T (void);

  /**
   * @name DDS_Listen
   * DDS_Listen operations
   */
  //@{
  ::CCM_DDS::CCM_DataListenerControl_ptr get_data_control (void);
  //@}

  bool configuration_complete (
    typename CCM_TYPE::base_type::_ptr_type component,
    ::DDS::Topic_ptr topic,
    ::DDS::Subscriber_ptr subscriber,
    const char* library_name,
    const char* profile_name);

  void activate (
    typename CCM_TYPE::listener_type::_ptr_type listener,
    ::CCM_DDS::PortStatusListener_ptr status,
    ACE_Reactor* reactor);

  void remove (::DDS::Subscriber_ptr subscriber);

private:
  /**
   * DDS_Listen
   */
  //@{
  ::CCM_DDS::CCM_DataListenerControl_var data_control_;
  //@}
  typedef ::CIAO::DDS4CCM::DataReaderListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>
    DataReaderListener;
  typedef CCM_DDS_DataListenerControl_T< ::CCM_DDS::CCM_DataListenerControl, CCM_TYPE>
    DataListenerControl;
};

#include "dds4ccm/impl/DDS_Listen_T.cpp"

#endif /* DDS_LISTEN_T_H_ */
