// -*- C++ -*-
// $Id$

#include "dds4ccm/impl/dds/DataReaderStateListener_T.h"
#include "dds4ccm/impl/dds/Reader_T.h"
#include "dds4ccm/impl/dds/DataReader_T.h"
#include "dds4ccm/impl/dds/StateListenerControl_T.h"
#include "dds4ccm/impl/dds/PortStatusListener_T.h"

#include "dds4ccm/impl/logger/Log_Macros.h"

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::DDS_StateListen_T (void) :
  data_control_ (new CCM_DDS_StateListenerControl_T
    < ::CCM_DDS::CCM_StateListenerControl> ())
{
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::~DDS_StateListen_T (void)
{
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
void
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::configuration_complete (
  ::DDS::Topic_ptr topic,
  ::DDS::Subscriber_ptr subscriber,
  const char* library_name,
  const char* profile_name)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::configuration_complete");

  try
    {
      if (!this->data_reader_.get_impl ())
        {
          this->data_reader_.create_datareader (topic,
                                                subscriber,
                                                library_name,
                                                profile_name);
          this->dds_read_.set_impl (&this->data_reader_);
        }
    }
  catch (...)
    {
      DDS4CCM_ERROR (1, (LM_EMERGENCY, "DDS_StateListen_T::configuration_complete: Caught unexpected exception.\n"));
      throw CORBA::INTERNAL ();
    }
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
void
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::activate (
  typename CCM_TYPE::statelistener_type::_ptr_type listener,
  ::CCM_DDS::PortStatusListener_ptr status,
  ACE_Reactor* reactor)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::activate");

  try
    {
      if (::CORBA::is_nil (this->data_listener_.in ()))
        {
          ACE_NEW_THROW_EX (this->data_listener_,
                            DataReaderStateListener (
                              listener,
                              status,
                              this->data_control_.in (),
                              reactor),
                            CORBA::NO_MEMORY ());
        }
      this->data_reader_.set_listener (
        this->data_listener_.in (),
        DataReaderStateListener::get_mask (listener));
    }
  catch (...)
    {
      DDS4CCM_ERROR (1, (LM_EMERGENCY, "DDS_StateListen_T::activate: Caught unexpected exception.\n"));
      throw CORBA::INTERNAL ();
    }
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
void
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::passivate (void)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::passivate");
  try
    {
      this->data_reader_.passivate ();
      this->data_listener_= ::DDS::DataReaderListener::_nil ();
    }
  catch (...)
    {
      DDS4CCM_ERROR (1, (LM_EMERGENCY, "DDS_StateListen_T::passivate: Caught unexpected exception.\n"));
      throw CORBA::INTERNAL ();
    }
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
void
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::remove (
  ::DDS::Subscriber_ptr subscriber)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::remove");
  try
    {
      this->data_reader_.delete_datareader (subscriber);
    }
  catch (...)
    {
      DDS4CCM_ERROR (1, (LM_EMERGENCY, "DDS_StateListen_T::remove: Caught unexpected exception.\n"));
      throw CORBA::INTERNAL ();
    }
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
typename CCM_TYPE::reader_type::_ptr_type
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::get_data (void)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::get_data");

  return &this->dds_read_;
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::DDS::CCM_DataReader_ptr
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::get_dds_entity (void)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::get_dds_entity");

  return &this->data_reader_;
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::CCM_DDS::CCM_StateListenerControl_ptr
DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::get_data_control (void)
{
  DDS4CCM_TRACE ("DDS_StateListen_T<DDS_TYPE, CCM_TYPE, FIXED>::get_data_control");

  return ::CCM_DDS::CCM_StateListenerControl::_duplicate (
    this->data_control_.in ());
}

