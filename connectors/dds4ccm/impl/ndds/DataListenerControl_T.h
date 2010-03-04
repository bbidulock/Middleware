// -*- C++ -*-
// $Id$

#ifndef DDS4CCM_DATALISTENERCONTROLI_H_
#define DDS4CCM_DATALISTENERCONTROLI_H_

#include "dds4ccm/idl/dds4ccm_DataListenerControlEC.h"
#include "tao/LocalObject.h"
#include "ace/Copy_Disabled.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

template <typename BASE_TYPE>
class CCM_DDS_DataListenerControl_T
  : public virtual BASE_TYPE,
    public virtual ::CORBA::LocalObject,
    private ACE_Copy_Disabled
{
public:
  /// Constructor
  CCM_DDS_DataListenerControl_T (void);

  /// Destructor
  virtual ~CCM_DDS_DataListenerControl_T (void);

  /// Set the mode
  virtual ::CCM_DDS::ListenerMode mode (void);

  /// Get the mode
  virtual void mode (::CCM_DDS::ListenerMode mode);

  /// Set the max_delivered_data
  virtual ::CCM_DDS::DataNumber_t max_delivered_data (void);

  /// Get the max_delivered_data
  virtual void max_delivered_data (::CCM_DDS::DataNumber_t max_delivered_data);

protected:
  ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CCM_DDS::ListenerMode> mode_;
  ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CCM_DDS::DataNumber_t> max_delivered_data_;
};

#include "dds4ccm/impl/ndds/DataListenerControl_T.cpp"

#endif /* DDS4CCM_DATALISTENERCONTROLI_H_  */

