// -*- c++ -*-
// $Id$
// ============================================================================
//
// = LIBRARY
//    TAO/tests/DynAny_Test
//
// = FILENAME
//    test_dynsequence.cpp
//
// = DESCRIPTION
//    Implementation of the simple DynSequence test
//
// = AUTHOR
//    Jeff Parsons <jp4@cs.wustl.edu>
//
// ============================================================================

#include "test_dynsequence.h"
#include "da_testsC.h"
#include "data.h"

Test_DynSequence::Test_DynSequence (CORBA::ORB_var orb)
  : test_name_ (CORBA::string_dup ("test_dynsequence")),
    orb_ (orb),
    error_count_ (0)
{
}

Test_DynSequence::~Test_DynSequence (void)
{
  CORBA::string_free (this->test_name_);
  this->test_name_ = 0;
}

const char*
Test_DynSequence::test_name (void) const
{ 
  return this->test_name_;
}

int
Test_DynSequence::run_test (void)
{
  Data data (this->orb_);

  DynAnyTests::test_seq ts (2);
  ts.length (2);

    TAO_TRY
    {
      ACE_DEBUG ((LM_DEBUG,
                 "\t*=*=*=*= %s =*=*=*=*\n",
                 data.labels[11]));

      ACE_DEBUG ((LM_DEBUG,
                 "testing: constructor(Any)/insert/get/seek/rewind/current_component\n"));

      ts[0] = data.m_string2;
      ts[1] = data.m_string2;
      CORBA_Any in_any1;
      in_any1 <<= ts;
      CORBA_DynAny_ptr dp1 = 
        this->orb_->create_dyn_any (in_any1,
                                    TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CORBA_DynSequence_ptr fa1 = CORBA_DynSequence::_narrow (dp1,
                                                              TAO_TRY_ENV);
      TAO_CHECK_ENV;
      fa1->seek (1,
                 TAO_TRY_ENV);
      TAO_CHECK_ENV;
      fa1->insert_string (data.m_string1,
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      fa1->rewind (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      fa1->seek (1,
                 TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CORBA::String out_str1 = fa1->get_string (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      if (!ACE_OS::strcmp (out_str1, data.m_string1))
        ACE_DEBUG ((LM_DEBUG,
                   "++ OK ++\n"));
      else 
        ++this->error_count_;

      // Created with NEW
      delete out_str1;

      ACE_DEBUG ((LM_DEBUG,
                 "testing: constructor(TypeCode)/from_any/to_any\n"));

      CORBA_DynSequence_ptr ftc1 =
        this->orb_->create_dyn_sequence (DynAnyTests::_tc_test_seq,
                                         TAO_TRY_ENV);
      TAO_CHECK_ENV;
      ts[0] = data.m_string1;
      CORBA_Any in_any2;
      in_any2 <<= ts;
      ftc1->from_any (in_any2,
                      TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CORBA::Any* out_any1 = ftc1->to_any (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      DynAnyTests::test_seq* ts_out;
      *out_any1 >>= ts_out;
      if (!ACE_OS::strcmp ((*ts_out)[0], data.m_string1))
        ACE_DEBUG ((LM_DEBUG,
                   "++ OK ++\n"));
      else 
        ++this->error_count_;

      // Created with NEW
      delete out_any1;


      ACE_DEBUG ((LM_DEBUG,
                 "testing: length/set_elements/get_elements\n"));

      if (ftc1->length (TAO_TRY_ENV) != 2)
        ++this->error_count_;
      TAO_CHECK_ENV;

      ftc1->length (3,
                    TAO_TRY_ENV);
      TAO_CHECK_ENV;
      AnySeq as_in (3);
      as_in.length (3);
      CORBA_Any in_any3;
      in_any3 <<= CORBA::Any::from_string (data.m_string2, 0);
      as_in[0] = in_any3;
      as_in[1] = in_any3;
      in_any3 <<= CORBA::Any::from_string (data.m_string1, 0);
      as_in[2] = in_any3;
      ftc1->set_elements (as_in,
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;
      AnySeq* as_out = ftc1->get_elements (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CORBA_Any out_any2 = (*as_out)[2];
      CORBA::String out_str2;
      out_any2 >>= CORBA::Any::to_string (out_str2, 0);
      if (ACE_OS::strcmp (out_str2, data.m_string1))
        ++this->error_count_;
      if (this->error_count_ == 0)
        ACE_DEBUG ((LM_DEBUG,
                   "++ OK ++\n"));

      // Created with NEW
      delete as_out;
      delete out_str2;

      fa1->destroy (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CORBA::release (fa1);
      CORBA::release (dp1);
      ftc1->destroy (TAO_TRY_ENV);
      TAO_CHECK_ENV;
      CORBA::release (ftc1);
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("test_dynsequence::run_test");
      return -1;
    }
  TAO_ENDTRY;

  ACE_DEBUG ((LM_DEBUG,
              "\n%d errors\n",
              this->error_count_));


  return 0;
}

