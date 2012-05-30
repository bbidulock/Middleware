// -*- C++ -*-
// $Id$

#include "dds4ccm/impl/DataReaderListener_T.h"
#include "dds4ccm/impl/DataListenerControl_T.h"
#include "dds4ccm/impl/logger/Log_Macros.h"


template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::DDS_Write_T (void)
{
}

template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::~DDS_Write_T (void)
{
}

template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
void
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::set_component (
  ::CORBA::Object_ptr component)
{
  this->dds_write_->_set_component (component);
  this->ccm_data_writer_->_set_component (component);
}

template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
void
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::configuration_complete (
  ::DDS::Topic_ptr topic,
  ::DDS::Publisher_ptr publisher,
#if (CIAO_DDS4CCM_NDDS==1)
  const char * qos_profile)
#else
  const char * qos_profile,
  DDS4CCM::QOS_XML_Loader& qos_xml)
#endif
{
  DDS4CCM_TRACE ("DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::configuration_complete");
  ::DDS::DataWriter_var dw = this->dds_write_->get_dds_writer ();
  if (::CORBA::is_nil (dw.in ()))
    {
      ::DDS::DataWriter_var dwv_tmp;
#if (CIAO_DDS4CCM_NDDS==1)
      if (qos_profile)
        {
          dwv_tmp = publisher->create_datawriter_with_profile (
              topic,
              qos_profile,
              ::DDS::DataWriterListener::_nil (),
              0);
        }
      else
#endif
        {
          ::DDS::DataWriterQos dwqos;
          DDS::ReturnCode_t const retcode =
            publisher->get_default_datawriter_qos (dwqos);

#if (CIAO_DDS4CCM_OPENDDS==1)
          CORBA::String_var name = topic->get_name ();
          qos_xml.get_datawriter_qos (dwqos,
                                      DDS4CCM::get_profile_name (qos_profile).c_str (),
                                      name.in ());
#endif

          if (retcode != DDS::RETCODE_OK)
            {
              DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                  "DDS_Write_T::configuration_complete - "
                  "Error: Unable to retrieve get_default_datawriter_qos: <%C>\n",
                  ::CIAO::DDS4CCM::translate_retcode (retcode)));
              throw ::CCM_DDS::InternalError (retcode, 0);
            }

#if defined GEN_OSTREAM_OPS
          if (DDS4CCM_debug_level >= DDS4CCM_LOG_LEVEL_DDS_STATUS)
            {
              std::stringstream output;
              output << dwqos;
              std::string message = output.str();
              DDS4CCM_DEBUG (DDS4CCM_LOG_LEVEL_DDS_STATUS, (LM_INFO, DDS4CCM_INFO
                            ACE_TEXT ("DDS_Update_T::configuration_complete - ")
                            ACE_TEXT ("Using datawriter QOS <%C>\n"), message.c_str()));
            }
#endif
          dwv_tmp = publisher->create_datawriter (
              topic,
              dwqos,
              ::DDS::DataWriterListener::_nil (),
              0);
        }
      if (::CORBA::is_nil (dwv_tmp.in ()))
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_DDS_NIL_RETURN, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Write_T::configuration_complete - "
                        "Error: Proxy returned a nil datawriter.\n"));
          throw ::CORBA::INTERNAL ();
        }
      ::DDS::ReturnCode_t retcode = dwv_tmp->enable ();
      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Write_T::configuration_complete - "
                        "Error: Unable to enable the datawriter: <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }

      this->dds_write_->set_dds_writer (dwv_tmp.in ());
      this->ccm_data_writer_->set_dds_entity (dwv_tmp.in ());
    }
}

template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
void
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::activate ()
{
  DDS4CCM_TRACE ("DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::activate");
}

template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
void
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::passivate ()
{
  DDS4CCM_TRACE ("DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::passivate");
}

template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
void
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::remove (
  ::DDS::Publisher_ptr publisher)
{
  DDS4CCM_TRACE ("DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::remove");

  ::DDS::DataWriter_var writer = this->dds_write_->get_dds_writer ();
  if (!::CORBA::is_nil (writer.in ()))
    {
      ::DDS::ReturnCode_t const retcode =
        publisher->delete_datawriter (writer.in ());

      if (retcode == ::DDS::RETCODE_OK)
        {
          this->dds_write_->set_dds_writer (::DDS::DataWriter::_nil ());
          this->ccm_data_writer_->set_dds_entity (::DDS::DataWriter::_nil ());
        }
      else
        {
          throw ::CORBA::INTERNAL ();
        }
    }
}

template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
typename CCM_TYPE::data_type::_ptr_type
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::get_data (void)
{
  DDS4CCM_TRACE ("DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::get_data");

  return CCM_TYPE::data_type::_duplicate (this->dds_write_);
}

template <typename CCM_TYPE, typename TYPED_WRITER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE>
typename CCM_TYPE::dds_entity_type::_ptr_type
DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::get_dds_entity (void)
{
  DDS4CCM_TRACE ("DDS_Write_T<CCM_TYPE, TYPED_WRITER, VALUE_TYPE, SEQ_VALUE_TYPE>::get_dds_entity");
  return ::DDS::CCM_DataWriter::_duplicate (this->ccm_data_writer_);
}

