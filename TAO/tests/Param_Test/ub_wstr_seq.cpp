// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/Param_Test
//
// = FILENAME
//    ub_wstr_seq.cpp
//
// = DESCRIPTION
//    tests unbounded wide string sequences
//
// = AUTHORS
//      Jeff Parsons
//
// ============================================================================

#include "helper.h"
#include "ub_wstr_seq.h"

// ************************************************************************
//               Test_WString_Sequence
// ************************************************************************

Test_WString_Sequence::Test_WString_Sequence (void)
  : opname_ (CORBA::string_dup ("test_wstrseq")),
    in_ (new Param_Test::WStrSeq),
    inout_ (new Param_Test::WStrSeq),
    out_ (new Param_Test::WStrSeq),
    ret_ (new Param_Test::WStrSeq)
{
}

Test_WString_Sequence::~Test_WString_Sequence (void)
{
  CORBA::string_free (this->opname_);
  this->opname_ = 0;
}

const char *
Test_WString_Sequence::opname (void) const
{
  return this->opname_;
}

void
Test_WString_Sequence::dii_req_invoke (CORBA::Request *req,
                                       CORBA::Environment &ACE_TRY_ENV)
{
  req->invoke (ACE_TRY_ENV);
}

int
Test_WString_Sequence::init_parameters (Param_Test_ptr ,
                                        CORBA::Environment &)
{
  Generator *gen = GENERATOR::instance (); // value generator

  const CORBA::WChar *choiceList[3];
  CORBA::ULong i = 0;

  for (i = 0; i < 3; i++)
    {
      choiceList[i] = gen->gen_wstring ();
    }

  CORBA::ULong len = sizeof(choiceList)/sizeof(CORBA::WChar *) - 1;

  // set the length of the sequences
  this->in_->length (len);
  this->inout_->length (len);

  // now set each individual element
  for (i = 0; i < this->in_->length (); i++)
    {
      this->in_[i] = choiceList[i];
      this->inout_[i] = choiceList[i+1];
    }
  return 0;
}

int
Test_WString_Sequence::reset_parameters (void)
{
  this->inout_ = new Param_Test::WStrSeq; // delete the previous ones
  this->out_ = new Param_Test::WStrSeq;
  this->ret_ = new Param_Test::WStrSeq;
  return 0;
}

int
Test_WString_Sequence::run_sii_test (Param_Test_ptr objref,
                                     CORBA::Environment &ACE_TRY_ENV)
{
  ACE_TRY
    {
      Param_Test::WStrSeq_out out (this->out_.out ());

      this->ret_ = objref->test_wstrseq (this->in_.in (),
                                         this->inout_.inout (),
                                         out,
                                         ACE_TRY_ENV);
      ACE_TRY_CHECK;

      return 0;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Test_WString_Sequence::run_sii_test\n");

    }
  ACE_ENDTRY;
  return -1;
}

int
Test_WString_Sequence::add_args (CORBA::NVList_ptr param_list,
                                 CORBA::NVList_ptr retval,
                                 CORBA::Environment &ACE_TRY_ENV)
{
  ACE_TRY
    {
      CORBA::Any in_arg (Param_Test::_tc_WStrSeq,
                         (void *) &this->in_.in (),
                         0);

      CORBA::Any inout_arg (Param_Test::_tc_WStrSeq,
                            &this->inout_.inout (),
                            0);

      CORBA::Any out_arg (Param_Test::_tc_WStrSeq,
                          &this->out_.inout (), // .out () causes crash
                          0);

      // add parameters
      param_list->add_value ("ws1",
                             in_arg,
                             CORBA::ARG_IN,
                             ACE_TRY_ENV);
      ACE_TRY_CHECK;

      param_list->add_value ("ws2",
                             inout_arg,
                             CORBA::ARG_INOUT,
                             ACE_TRY_ENV);
      ACE_TRY_CHECK;

      param_list->add_value ("ws3",
                             out_arg,
                             CORBA::ARG_OUT,
                             ACE_TRY_ENV);
      ACE_TRY_CHECK;

      CORBA::NamedValue *item = retval->item (0,
                                              ACE_TRY_ENV);
      ACE_TRY_CHECK;

      item->value ()->replace (Param_Test::_tc_WStrSeq,
                               &this->ret_.inout (),
                               0, // does not own
                               ACE_TRY_ENV);
      ACE_TRY_CHECK;

      return 0;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Test_WString_Sequence::add_args\n");

    }
  ACE_ENDTRY;
  return -1;
}

CORBA::Boolean
Test_WString_Sequence::check_validity (void)
{
  CORBA::Boolean flag = 0;
  if ((this->in_->length () == this->inout_->length ()) &&
      (this->in_->length () == this->out_->length ()) &&
      (this->in_->length () == this->ret_->length ()))
    {
      flag = 1; // assume all are equal
      // lengths are same. Now compare the contents
      for (CORBA::ULong i=0; i < this->in_->length () && flag; i++)
        {
          if (ACE_OS::strcmp (this->in_[i], this->inout_[i]) ||
              ACE_OS::strcmp (this->in_[i], this->out_[i]) ||
              ACE_OS::strcmp (this->in_[i], this->ret_[i]))
            // not equal
            flag = 0;
        }
    }
  return flag;
}

CORBA::Boolean
Test_WString_Sequence::check_validity (CORBA::Request_ptr )
{
  return this->check_validity ();
}

void
Test_WString_Sequence::print_values (void)
{
}
