/**
 * @author Marcel Smit <msmit@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef GETTER_T_H
#define GETTER_T_H

#include "dds4ccm/idl/dds_rtf2_dcpsC.h"
#include "ace/Copy_Disabled.h"

#if defined (CIAO_DDS4CCM_OPENDDS) && (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::GuardCondition DDSGuardCondition;
typedef ::DDS::WaitSet DDSWaitSet;
typedef ::DDS::ReadCondition DDSReadCondition;
typedef ::DDS::ConditionSeq DDSConditionSeq;
#endif

namespace CIAO
{
  namespace DDS4CCM
  {
    namespace RTI
    {
      /**
      * @class template <typename DDS_TYPE, typename CCM_TYPE> class Getter_Base_T
      *
      * @brief Base class for the Getter port.
      *        Spec:  Get operations are performed with the following parameters
      *                · SampleStateMask: NO_READ,
      *                · ViewStateMask: NEW or NOT_NEW,
      *                · InstanceStateMask: ALIVE or NOT_ALIVE,
      *                · Through the query (if any) of the Reader associated to the port,
      *                · Within the time limit specified in time_out.
      *
      *               All methods return a boolean as result indicating whether actual data
      *               are provided (TRUE) or if the time-out occurred (FALSE).
      */
      template <typename DDS_TYPE, typename CCM_TYPE>
      class Getter_Base_T :
         public virtual CCM_TYPE::getter_type,
         public virtual ::CORBA::LocalObject,
         private virtual ACE_Copy_Disabled
      {
      public:
        /// Constructor
        Getter_Base_T (void);

        /// Destructor
        virtual ~Getter_Base_T (void);

        /**
        * @name get_one
        *
        * @brief  get_one implementation for fixed sized datatypes.
        *         Spec : get_many returns all the available samples
        *                in the limits set by the attribute max_delivered_data.
        *                In case there are more available samples, the first
        *                max_delivered_data are returned. The default value for
        *                that attribute is UNLIMITED (0)
        */
        /// get_many
        virtual bool get_many (
          typename CCM_TYPE::seq_type::_out_type instances,
          ::CCM_DDS::ReadInfoSeq_out infos);
        /// time_out getter
        virtual ::DDS::Duration_t time_out (void);
        /// time_out setter
        virtual void time_out (const ::DDS::Duration_t & time_out);

        /// max_delivered_data getter
        virtual ::CCM_DDS::DataNumber_t max_delivered_data (void);
        /// max_delivered_data setter
        virtual void max_delivered_data (
          ::CCM_DDS::DataNumber_t max_delivered_data);

        /**
        * @name set_impl
        *
        * @brief  set pointer to the DDS datareader.
        */
        void set_impl (::DDS::DataReader_ptr reader);

        /// passivate
        void passivate (void);

      protected:
        /**
        * Protected
        */
        //@{
        typename DDS_TYPE::data_reader *impl_;

        DDSQueryCondition* condition_;
        ::DDS::Duration_t time_out_;
        ::CCM_DDS::DataNumber_t max_delivered_data_;
        DDSWaitSet* ws_;
        DDSReadCondition* rd_condition_;

        bool wait (DDSConditionSeq& active_conditions);

        typename DDS_TYPE::data_reader * impl (void);
        //@}
      };

      template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
      class Getter_T;

      /**
      * @class template <typename DDS_TYPE, typename CCM_TYPE> class Getter_T <DDS_TYPE, CCM_TYPE, false>
      *
      * @brief Implementation of the Getter port for variable sized data types.
      */
      template <typename DDS_TYPE, typename CCM_TYPE>
      class Getter_T <DDS_TYPE, CCM_TYPE, false> :
        public Getter_Base_T <DDS_TYPE, CCM_TYPE>
      {
      public:
        /**
        * @name get_one
        *
        * @brief  get_one implementation for variable sized datatypes.
        *         Spec : get_one returns the next sample to be gotten.
        */
        virtual bool get_one (
          typename DDS_TYPE::value_type::_out_type an_instance,
          ::CCM_DDS::ReadInfo_out info);
      };

      /**
      * @class template <typename DDS_TYPE, typename CCM_TYPE> class Getter_T <DDS_TYPE, CCM_TYPE, true>
      *
      * @brief Implementation of the Getter port for fixed sized data types.
      */
      template <typename DDS_TYPE, typename CCM_TYPE>
      class Getter_T <DDS_TYPE, CCM_TYPE, true> :
        public Getter_Base_T <DDS_TYPE, CCM_TYPE>
      {
      public:
        /**
        * @name get_one
        *
        * @brief  get_one implementation for fixed sized datatypes.
        *         Spec : get_one returns the next sample to be gotten.
        */
        virtual bool get_one (
          typename DDS_TYPE::value_type::_out_type an_instance,
          ::CCM_DDS::ReadInfo_out info);
      };
    }
  }
}

#include "dds4ccm/impl/ndds/Getter_T.cpp"

#endif /* GETTER_T_H */
