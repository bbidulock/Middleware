// $Id$
#include "dds4ccm/impl/ndds/DataReader.h"
#include "dds4ccm/impl/ndds/Utils.h"
#include "dds4ccm/impl/ndds/Duration_t.h"
#include "dds4ccm/impl/ndds/SampleInfo.h"

#include "ciao/Logger/Log_Macros.h"
// Implementation skeleton constructor
template <typename NDDS_TYPE, typename BASE >
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::Getter_T (::DDS::DataReader_ptr reader)
: impl_ (0),
  condition_(0),
  time_out_ ()
{
  printf("----in constructor getter -----\n");
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Getter_T::Getter_T");

  RTI_DataReader_i *rdr = dynamic_cast <RTI_DataReader_i *> (reader);

  if (rdr == 0)
    {
      CIAO_ERROR ((LM_ERROR, CLINFO "CIAO::DDS4CCM::RTI::Getter_T::Getter_T - "
                   "Unable to cast provided DataReader to servant\n"));
      throw CORBA::INTERNAL ();
    }

  this->impl_ =  NDDS_TYPE::data_reader::narrow (rdr->get_datareader ());
  
  if (!this->impl_)
    {
      CIAO_ERROR ((LM_ERROR, CLINFO "CIAO::DDS4CCM::RTI::Getter_T::Getter_T - "
                   "Unable to narrow the provided writer entity to the specific "
                   "type necessary to publish messages\n"));
      throw CORBA::INTERNAL ();
    }
  //now create the waitset conditions
  ws_ = new DDSWaitSet ();
  gd_ = new DDSGuardCondition ();
  rd_condition_ = this->impl_->create_readcondition (DDS_NOT_READ_SAMPLE_STATE,
                                                     DDS_ANY_VIEW_STATE,
                                                     DDS_ANY_INSTANCE_STATE);
  DDS_ReturnCode_t retcode = ws_->attach_condition (gd_);
  if (retcode != DDS_RETCODE_OK)
      throw CCM_DDS::InternalError (retcode, 0);
  retcode = ws_->attach_condition (rd_condition_);
  if (retcode != DDS_RETCODE_OK)
      throw CCM_DDS::InternalError (retcode, 1);
}

// Implementation skeleton destructor
template <typename NDDS_TYPE, typename BASE >
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::~Getter_T (void)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Getter_T::~Getter_T");
  delete ws_;
}

template <typename NDDS_TYPE, typename BASE >
bool
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::get_all (
          typename NDDS_TYPE::seq_type::_out_type instances,
          ::CCM_DDS::ReadInfoSeq_out infos)
{
  ACE_UNUSED_ARG (instances);
  ACE_UNUSED_ARG (infos);
  return true;
}

template <typename NDDS_TYPE, typename BASE >
bool
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::get_all_history (
          typename NDDS_TYPE::seq_type::_out_type instances,
          ::CCM_DDS::ReadInfoSeq_out infos)
{
  ACE_UNUSED_ARG (instances);
  ACE_UNUSED_ARG (infos);
  return true;
}

template <typename NDDS_TYPE, typename BASE >
bool
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::get_one (
          typename NDDS_TYPE::value_type& an_instance,
          ::CCM_DDS::ReadInfo_out info)
{
  DDSConditionSeq active_conditions;
  DDS_SampleInfoSeq sample_info;
  DDS_Duration_t timeout;
  timeout<<=this->time_out_;
  DDS_ReturnCode_t retcode = ws_->wait (active_conditions, timeout);
  if (retcode == DDS_RETCODE_TIMEOUT)
    {
      CIAO_DEBUG ((LM_DEBUG, ACE_TEXT ("Getter: No data available after timeout.\n")));
      return false;
    }
  typename NDDS_TYPE::dds_seq_type data;
  for (int i = 0; i < active_conditions.length(); i++)
    {
      if (active_conditions[i] == gd_)
        {
          printf("Got event status event for Guard Matched\n");
          //Must reset guard trigger
          gd_->set_trigger_value(false);
        }

      if (active_conditions[i] == rd_condition_)
        {
          // Check trigger
          if (active_conditions[i]->get_trigger_value() )
          {
            printf("wait condition trigger was set.\n");
          }

          // Take read condition
          printf("##### GETTER START READ\n");
          retcode = this->impl_->read (data,
                                    sample_info,
                                    DDS_LENGTH_UNLIMITED,
                                    DDS_READ_SAMPLE_STATE | DDS_NOT_READ_SAMPLE_STATE ,
                                    DDS_NEW_VIEW_STATE | DDS_NOT_NEW_VIEW_STATE,
                                    DDS_ALIVE_INSTANCE_STATE);

          if (retcode == DDS_RETCODE_NO_DATA) {
            throw CCM_DDS::InternalError (retcode, 1);
          } else if (retcode != DDS_RETCODE_OK) {
              CIAO_ERROR ((LM_ERROR, CLINFO "CIAO::DDS4CCM::RTI::Getter_T::Getter_T - "
                   "Unable to return the loan to DDS: <%d>\n", retcode));
            break;
          }
          info <<= sample_info;
          if (retcode == DDS_RETCODE_OK)
            {
              an_instance = data[0];
            }
          else
            throw CCM_DDS::InternalError (retcode, 1);

          retcode = this->impl_->return_loan(data,sample_info);
          if (retcode != DDS_RETCODE_OK) 
            {
              printf("return loan error %d\n", retcode);
            }
        }
    } // endif able to take w condition
  return true;
}

template <typename NDDS_TYPE, typename BASE >
bool
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::get_one_history (
          const typename NDDS_TYPE::value_type& an_instance,
          typename NDDS_TYPE::seq_type::_out_type instances,
          ::CCM_DDS::ReadInfoSeq_out infos)
{
  ACE_UNUSED_ARG (an_instance);
  ACE_UNUSED_ARG (instances);
  ACE_UNUSED_ARG (infos);
  return true;
}

template <typename NDDS_TYPE, typename BASE >
bool
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::get_next (
          typename NDDS_TYPE::value_type::_out_type  an_instance,
          ::CCM_DDS::ReadInfo_out info)
{
  ACE_UNUSED_ARG (an_instance);
  ACE_UNUSED_ARG (info);
  return true;
}

template <typename NDDS_TYPE, typename BASE >
 ::CCM_DDS::QueryFilter *
 CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::filter (void)
{
  return 0;
}

template <typename NDDS_TYPE, typename BASE >
void
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::filter (const ::CCM_DDS::QueryFilter & filter)
{
  ACE_UNUSED_ARG (filter);
}

template <typename NDDS_TYPE, typename BASE >
::DDS::Duration_t
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::time_out (void)
{
  return this->time_out_;
}

template <typename NDDS_TYPE, typename BASE >
void
CIAO::DDS4CCM::RTI::Getter_T<NDDS_TYPE, BASE>::time_out (const ::DDS::Duration_t & time_out)
{
  this->time_out_ = time_out;
}
