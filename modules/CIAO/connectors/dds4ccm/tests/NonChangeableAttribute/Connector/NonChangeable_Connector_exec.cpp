// -*- C++ -*-
// $Id$

#include "NonChangeable_Connector_exec.h"

namespace CIAO_NonChangeable_NonChangeable_Connector_Impl
{
  NonChangeable_Connector_exec_i::NonChangeable_Connector_exec_i (void)
    : DDS_Event_Connector_T<NonChangeableTest_DDS_Traits, NonChangeableTest_Connector_Traits> ()
  {
  }

  NonChangeable_Connector_exec_i::~NonChangeable_Connector_exec_i (void)
  {
  }

  void
  NonChangeable_Connector_exec_i::test_domain_id ()
  {
    bool nonchangeable_caught = false;
    try
      {
        DDS::DomainId_t id = 0;
        this->domain_id (id);
      }
    catch (const CCM_DDS::NonChangeable)
      {
        ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("test_domain_id : Expected exception caught\n")));
        nonchangeable_caught = true;
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("Exception caught:");
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_domain_id : Exception caught\n")));
      }
    catch (...)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_domain_id : Unknown exception caught\n")));
      }
    if (!nonchangeable_caught)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_domain_id : No NonChangeable exception caught\n")));
      }
  }

  void
  NonChangeable_Connector_exec_i::test_qos_profile ()
  {
    bool nonchangeable_caught = false;
    try
      {
        this->qos_profile ("test");
      }
    catch (const CCM_DDS::NonChangeable)
      {
        ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("test_qos_profile : Expected exception caught\n")));
        nonchangeable_caught = true;
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("Exception caught:");
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_qos_profile : Exception caught\n")));
      }
    catch (...)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_qos_profile : Unknown exception caught\n")));
      }
    if (!nonchangeable_caught)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_qos_profile : No NonChangeable exception caught\n")));
      }
  }

  void
  NonChangeable_Connector_exec_i::test_topic_name ()
  {
    bool nonchangeable_caught = false;
    try
      {
        this->topic_name ("test");
      }
    catch (const CCM_DDS::NonChangeable)
      {
        ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("test_topic_name : Expected exception caught\n")));
        nonchangeable_caught = true;
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("Exception caught:");
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_topic_name : Exception caught\n")));
      }
    catch (...)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_topic_name : Unknown exception caught\n")));
      }
    if (!nonchangeable_caught)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_topic_name : No NonChangeable exception caught\n")));
      }
  }

  void
  NonChangeable_Connector_exec_i::test_key_fields ()
  {
    bool nonchangeable_caught = false;
    try
      {
        DDS::StringSeq key_fields;
        this->key_fields (key_fields);
      }
    catch (const CCM_DDS::NonChangeable)
      {
        ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("test_key_fields : Expected exception caught\n")));
        nonchangeable_caught = true;
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("Exception caught:");
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_key_fields : Exception caught\n")));
      }
    catch (...)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_key_fields : Unknown exception caught\n")));
      }
    if (!nonchangeable_caught)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: test_key_fields : No NonChangeable exception caught\n")));
      }
  }


  void
  NonChangeable_Connector_exec_i::ccm_activate ()
  {
    test_domain_id ();
    test_qos_profile ();
    test_topic_name ();
    test_key_fields ();
  }

  extern "C" NONCHANGEABLE_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_NonChangeable_NonChangeable_Connector_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      NonChangeable_Connector_exec_i ());

    return retval;
  }
}

