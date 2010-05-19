// $Id$
#include "dds4ccm/impl/dds/Utils.h"

#include "dds4ccm/impl/dds/DataReader.h"
#include "dds4ccm/impl/logger/Log_Macros.h"
#include "ace/Reactor.h"

template <typename DDS_TYPE, typename CCM_TYPE>
CIAO::DDS4CCM::DataReaderListener_T<DDS_TYPE, CCM_TYPE>::DataReaderListener_T (
  typename CCM_TYPE::listener_type::_ptr_type listener,
  ::CCM_DDS::PortStatusListener_ptr port_status_listener,
  ::CCM_DDS::DataListenerControl_ptr control,
  ACE_Reactor* reactor)
  : PortStatusListener_T <DDS_TYPE, CCM_TYPE> (port_status_listener, reactor) ,
    listener_ (CCM_TYPE::listener_type::_duplicate (listener)),
    control_ (::CCM_DDS::DataListenerControl::_duplicate (control))
{
  DDS4CCM_TRACE ("CIAO::DDS4CCM::DataReaderListener_T::DataReaderListener_T");
}

template <typename DDS_TYPE, typename CCM_TYPE>
CIAO::DDS4CCM::DataReaderListener_T<DDS_TYPE, CCM_TYPE>::~DataReaderListener_T (void)
{
  DDS4CCM_TRACE ("CIAO::DDS4CCM::DataReaderListener_T::~DataReaderListener_T");
}

template <typename DDS_TYPE, typename CCM_TYPE>
void
CIAO::DDS4CCM::DataReaderListener_T<DDS_TYPE, CCM_TYPE>::on_data_available (::DDS::DataReader_ptr rdr)
{
  DDS4CCM_TRACE ("CIAO::DDS4CCM::DataReaderListener_T::on_data_available");

  if (::CORBA::is_nil (this->control_.in ()) ||
      this->control_->mode () == ::CCM_DDS::NOT_ENABLED ||
      ::CORBA::is_nil (rdr))
    {
      return;
    }

  if (this->reactor_)
    {
      drh* rh = 0;
      ACE_NEW (rh, drh (this, rdr));

      ACE_Event_Handler_var safe_handler (rh);
      if (this->reactor_->notify (rh) != 0)
        {
          DDS4CCM_ERROR (1, (LM_ERROR, ACE_TEXT ("DataReaderListener_T::failed to use reactor.\n")));
        }
    }
  else
    {
      this->on_data_available_i (rdr);
    }
}

template <typename DDS_TYPE, typename CCM_TYPE>
void
CIAO::DDS4CCM::DataReaderListener_T<DDS_TYPE, CCM_TYPE>::on_data_available_i (::DDS::DataReader_ptr rdr)
{
  DDS4CCM_TRACE ("CIAO::DDS4CCM::DataReaderListener_T::on_data_available_i");

  if (::CORBA::is_nil (this->control_.in ()) ||
      this->control_->mode () == ::CCM_DDS::NOT_ENABLED ||
      ::CORBA::is_nil (rdr))
    {
      return;
    }

  ::CIAO::DDS4CCM::DataReader_T<DDS_TYPE, CCM_TYPE> * reader =
    reinterpret_cast < ::CIAO::DDS4CCM::DataReader_T<DDS_TYPE, CCM_TYPE> *> (rdr);

  if (!reader)
    {
      DDS4CCM_ERROR (1, (LM_ERROR,
                         ACE_TEXT ("DataReaderListener_T::on_data_available_i - ")
                         ACE_TEXT ("Failed to retrieve pointer to proxy from ")
                         ACE_TEXT ("DDSDataReader.\n")));
      return;
    }

  typename DDS_TYPE::dds_seq_type data;
  DDS_SampleInfoSeq sample_info;
  ::DDS::ReturnCode_t const result = reader->take (
              data,
              sample_info);

  if (result == DDS_RETCODE_NO_DATA)
    {
      return;
    }
  else if (result != DDS_RETCODE_OK)
    {
      DDS4CCM_ERROR (1, (LM_ERROR, ACE_TEXT ("Unable to take data from data reader, "
                                             "error %C.\n"),
                                             translate_retcode (result)));
      return;
    }

  if (this->control_->mode () == ::CCM_DDS::ONE_BY_ONE)
    {
      for (::DDS_Long i = 0; i < data.length (); ++i)
        {
          if (sample_info[i].valid_data)
            {
              ::CCM_DDS::ReadInfo info;
              info <<= sample_info[i];
              this->listener_->on_one_data (data[i], info);
            }
        }
    }
  else
    {
      CORBA::ULong nr_of_samples = 0;
      for (::DDS_Long i = 0 ; i < sample_info.length(); i++)
        {
          if (sample_info[i].valid_data)
            {
              ++nr_of_samples;
            }
        }

      if (nr_of_samples > 0)
        {
          typename CCM_TYPE::seq_type * inst_seq = 0;
          ACE_NEW (inst_seq,
                   typename CCM_TYPE::seq_type (nr_of_samples));

          ::CCM_DDS::ReadInfoSeq * infoseq = 0;
          ACE_NEW (infoseq,
                   ::CCM_DDS::ReadInfoSeq (nr_of_samples));

          infoseq->length (nr_of_samples);
          inst_seq->length (nr_of_samples);

          // Copy the valid samples
          CORBA::ULong ix = 0;
          for (::DDS_Long i = 0 ; i < sample_info.length(); i++)
            {
              if(sample_info[i].valid_data)
                {
                  (*infoseq)[ix] <<= sample_info[i];
                  (*inst_seq)[ix] = data[i];
                  ++ix;
                }
            }
          this->listener_->on_many_data (*inst_seq, *infoseq);
        }
    }

  // Return the loan
  DDS_ReturnCode_t const retval = reader->return_loan (data, sample_info);
  if (retval != DDS_RETCODE_OK)
    {
      DDS4CCM_ERROR (1, (LM_ERROR, CLINFO
        "CIAO::DDS4CCM::DataReaderListener_T::on_data_available_i - "
        "Error returning loan to DDS - <%C>\n",
        translate_retcode (retval)));
    }
}

template <typename DDS_TYPE, typename CCM_TYPE>
::DDS::StatusMask
CIAO::DDS4CCM::DataReaderListener_T<DDS_TYPE, CCM_TYPE>::get_mask (
  ::CCM_DDS::PortStatusListener_ptr listener)
{
  DDS4CCM_TRACE ("CIAO::DDS4CCM::DataReaderListener_T::get_mask");

  ::DDS::StatusMask mask = ::DDS::DATA_AVAILABLE_STATUS;
  if (! ::CORBA::is_nil (listener) ||
      CIAO_debug_level >= 10)
    {
      mask |= PortStatusListener::get_mask (listener);
      DDS4CCM_DEBUG (10, (LM_DEBUG, "DataReaderListener_T::get_mask - "
                                   "Mask becomes %d\n",
                                   mask));
    }
  return mask;
}
