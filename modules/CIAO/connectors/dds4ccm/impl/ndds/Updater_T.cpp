// $Id$
#include "dds4ccm/impl/ndds/DataWriter.h"
#include "dds4ccm/impl/ndds/Utils.h"

#include "ciao/Logger/Log_Macros.h"

// Implementation skeleton constructor
template <typename NDDS_TYPE, typename BASE >
CIAO::DDS4CCM::RTI::Updater_T<NDDS_TYPE, BASE>::Updater_T (::DDS::DataWriter_ptr dw)
  : impl_ (0),
    is_lifecycle_checked_ (true)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Updater_T::Updater_T");

  RTI_DataWriter_i *rdu = dynamic_cast <RTI_DataWriter_i *> (dw);

  if (rdu == 0)
    {
      CIAO_ERROR ((LM_ERROR, CLINFO "CIAO::DDS4CCM::RTI::Updater_T::Updater - "
                   "Unable to cast provided DataUpdater to servant\n"));
      throw CORBA::INTERNAL ();
    }

  this->impl_ =  NDDS_TYPE::data_writer::narrow (rdu->get_datawriter ());

  if (!this->impl_)
    {
      CIAO_ERROR ((LM_ERROR, CLINFO "CIAO::DDS4CCM::RTI::Updater_T::Updater_T - "
                   "Unable to narrow the provided updater entity to the specific "
                   "type necessary to update messages\n"));
      throw CORBA::INTERNAL ();
    }
}

// Implementation skeleton destructor
template <typename NDDS_TYPE, typename BASE >
CIAO::DDS4CCM::RTI::Updater_T<NDDS_TYPE, BASE>::~Updater_T (void)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Updater_T::~Updater_T");
}

template <typename NDDS_TYPE, typename BASE >
bool
CIAO::DDS4CCM::RTI::Updater_T<NDDS_TYPE, BASE>::is_lifecycle_checked ()
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Updater_T::~is_lifecycle_checked");
  
  printf ("CIAO::DDS4CCM::RTI::Updater_T::is_lifecycle_checked\n");
  return this->is_lifecycle_checked_;
}

template <typename NDDS_TYPE, typename BASE >
void
CIAO::DDS4CCM::RTI::Updater_T<NDDS_TYPE, BASE>::create (const typename NDDS_TYPE::value_type & an_instance)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Updater_T::create");
  
  DDS_InstanceHandle_t hnd = this->impl_->lookup_instance (an_instance);
  if (this->is_lifecycle_checked_ && !DDS_InstanceHandle_equals (&hnd, & ::DDS_HANDLE_NIL))
    throw CCM_DDS::AlreadyCreated (0);
  hnd = this->impl_->register_instance (an_instance);
  printf ("############# REGISTERED INSTANCE <%d>\n", hnd);
}

template <typename NDDS_TYPE, typename BASE >
void
CIAO::DDS4CCM::RTI::Updater_T<NDDS_TYPE, BASE>::update (const typename NDDS_TYPE::value_type & an_instance)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Updater_T::update");
  
  DDS_InstanceHandle_t hnd = this->impl_->lookup_instance (an_instance);
  if (this->is_lifecycle_checked_ && DDS_InstanceHandle_equals (&hnd, &::DDS_HANDLE_NIL))
    throw CCM_DDS::NonExistent (0);
  ::DDS::ReturnCode_t const result  = this->impl_->write (an_instance, hnd);
  if (result != DDS_RETCODE_OK)
    {
      ACE_ERROR ((LM_ERROR, ACE_TEXT ("#@#@#@#@#@#@ Unable to update data, error %d.\n"), result));
      throw CCM_DDS::InternalError (result, 0);;
    }
}

template <typename NDDS_TYPE, typename BASE >
void
CIAO::DDS4CCM::RTI::Updater_T<NDDS_TYPE, BASE>::_cxx_delete (const typename NDDS_TYPE::value_type & an_instance)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Updater_T::_cxx_delete");
  
  DDS_InstanceHandle_t hnd = this->impl_->lookup_instance (an_instance);
  if (this->is_lifecycle_checked_ && DDS_InstanceHandle_equals (&hnd, & ::DDS_HANDLE_NIL))
    throw CCM_DDS::NonExistent (0);
  ::DDS::ReturnCode_t const result  = this->impl_->unregister_instance (an_instance, hnd);
  if (result != DDS_RETCODE_OK)
  {
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("#@#@#@#@#@#@ Unable to unregister instance, error %d.\n"), result));
    throw CCM_DDS::InternalError (result, 0);
  }
}
