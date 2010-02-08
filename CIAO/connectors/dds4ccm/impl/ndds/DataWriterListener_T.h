/**
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */
#ifndef DDS_DATAWRITERLISTENER_T
#define DDS_DATAWRITERLISTENER_T

#include "dds4ccm/idl/dds_rtf2_dcpsC.h"
#include "ace/Copy_Disabled.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    template <typename DDS_TYPE, typename CCM_TYPE>
    class DataWriterListener_T :
      public ::DDS::DataWriterListener,
      private ACE_Copy_Disabled
    {
    public:
      /// Constructor
      DataWriterListener_T (void);

      /// Destructor
      virtual ~DataWriterListener_T (void);

      virtual void
      on_offered_deadline_missed (
        ::DDS::DataWriter_ptr ,
        const ::DDS::OfferedDeadlineMissedStatus & );

      virtual void
      on_offered_incompatible_qos (
        ::DDS::DataWriter_ptr ,
        const ::DDS::OfferedIncompatibleQosStatus & );

      virtual void
      on_liveliness_lost (
        ::DDS::DataWriter_ptr ,
        const ::DDS::LivelinessLostStatus & );

      virtual void
      on_publication_matched (
        ::DDS::DataWriter_ptr ,
        const ::DDS::PublicationMatchedStatus & );

      virtual void
      on_reliable_reader_activity_changed (
        ::DDS::DataWriter_ptr ,
        const ::DDS::ReliableReaderActivityChangedStatus & );

      static ::DDS::StatusMask get_mask (void);
    };
  }
}

#include "dds4ccm/impl/ndds/DataWriterListener_T.cpp"

#endif /* DDS_DATAWRITERLISTENER_T */
