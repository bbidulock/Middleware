// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/Param_Test
//
// = FILENAME
//    recursive_union.cpp
//
// = DESCRIPTION
//    test union that contains a sequence of itself
//
// = AUTHORS
//    Jeff Parsons <parsons@cs.wustl.edu>
//
// ============================================================================

#include "recursive_union.h"

ACE_RCSID(Param_Test, recursive_union, "$Id$")

const CORBA::ULong MAX_DEPTH = 3;
const CORBA::ULong MAX_SEQ_LENGTH = 2;

// ************************************************************************
//               Test_Recursive_Union
// ************************************************************************

Test_Recursive_Union::Test_Recursive_Union (void)
  : opname_ (CORBA::string_dup ("test_recursive_union"))
{
}

Test_Recursive_Union::~Test_Recursive_Union (void)
{
  CORBA::string_free (this->opname_);
  this->opname_ = 0;
  // the other data members will be freed as they are "_var"s and objects
  // (rather than pointers to objects)
}

const char *
Test_Recursive_Union::opname (void) const
{
  return this->opname_;
}

void
Test_Recursive_Union::dii_req_invoke (CORBA::Request *req,
                                      CORBA::Environment &ACE_TRY_ENV)
{
  req->invoke (ACE_TRY_ENV);
}

int
Test_Recursive_Union::init_parameters (Param_Test_ptr ,
                                       CORBA::Environment &)
{
  // The client calls init_parameters() before the first
  // call and reset_parameters() after each call. For this
  // test, we want the same thing to happen each time.
  return this->reset_parameters ();
}

int
Test_Recursive_Union::reset_parameters (void)
{
  // Since these are _vars, we do this the first call and
  // every call thereafter (if any).
  this->inout_ = new Param_Test::Recursive_Union;
  this->out_ = new Param_Test::Recursive_Union;
  this->ret_ = new Param_Test::Recursive_Union;

   // value generator
  Generator *gen = GENERATOR::instance ();

  // Set the depth of recursion.
  CORBA::ULong depth = 
    (CORBA::ULong) (gen->gen_long () % MAX_DEPTH) + 1;

  // Create a nested union to put in inout_.
  Param_Test::nested_rec_union nru;

  nru.value (0);

  this->inout_->nested_member (nru);

  // Call the recursive helper function. to initialize in_.
  this->deep_init (this->in_,
                   gen,
                   depth);

  return 0;
}

int
Test_Recursive_Union::run_sii_test (Param_Test_ptr objref,
                                    CORBA::Environment &ACE_TRY_ENV)
{
  ACE_TRY
    {
      Param_Test::Recursive_Union_out out (this->out_.out ());

      this->ret_ = objref->test_recursive_union (this->in_,
                                                 this->inout_.inout (),
                                                 out,
                                                 ACE_TRY_ENV);
      ACE_TRY_CHECK;

      return 0;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Test_Recursive_Union::run_sii_test\n");

    }
  ACE_ENDTRY;
  return -1;
}

int
Test_Recursive_Union::add_args (CORBA::NVList_ptr param_list,
			                          CORBA::NVList_ptr retval,
			                          CORBA::Environment &ACE_TRY_ENV)
{
  ACE_TRY
    {
      CORBA::Any in_arg (Param_Test::_tc_Recursive_Union,
                         &this->in_,
                         0);

      CORBA::Any inout_arg (Param_Test::_tc_Recursive_Union,
                            &this->inout_.inout (), // .out () causes crash
                            0);

      CORBA::Any out_arg (Param_Test::_tc_Recursive_Union,
                          &this->out_.inout (),
                          0);

      // add parameters
      param_list->add_value ("ru1",
                             in_arg,
                             CORBA::ARG_IN,
                             ACE_TRY_ENV);
      ACE_TRY_CHECK;

      param_list->add_value ("ru2",
                             inout_arg,
                             CORBA::ARG_INOUT,
                             ACE_TRY_ENV);
      ACE_TRY_CHECK;

      param_list->add_value ("ru3",
                             out_arg,
                             CORBA::ARG_OUT,
                             ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // add return value
      CORBA::NamedValue *item = retval->item (0,
                                              ACE_TRY_ENV);
      ACE_TRY_CHECK;

      item->value ()->replace (Param_Test::_tc_Recursive_Union,
                               &this->ret_.inout (), // see above
                               0, // does not own
                               ACE_TRY_ENV);
      ACE_TRY_CHECK;

      return 0;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Test_Recursive_Union::add_args\n");

    }
  ACE_ENDTRY;
  return -1;
}


CORBA::Boolean
Test_Recursive_Union::check_validity (void)
{
  // Pair in_ with each of the returned values and call the
  // helper function with that pair.

  if (this->deep_check (this->in_, this->inout_.in ()) == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "mismatch of inout arg\n"));

      return 0;
    }

  if (this->deep_check (this->in_, this->out_.in ()) == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "mismatch of out arg\n"));

      return 0;
    }

  if (this->deep_check (this->in_, this->ret_.in ()) == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "mismatch of ret value\n"));

      return 0;
    }

  // If we get this far, all is correct.
  return 1;
}

CORBA::Boolean
Test_Recursive_Union::check_validity (CORBA::Request_ptr)
{
  return this->check_validity ();
}

void
Test_Recursive_Union::print_values (void)
{
}

// Private helper function to recursively initialize the union.
void
Test_Recursive_Union::deep_init (Param_Test::Recursive_Union &ru,
                                 Generator *gen,
                                 CORBA::ULong level)
{
  if (level == 1) 
  // No more recursion, just insert a nested_rec_union.
    {
      CORBA::ULong nested_depth = 
        (CORBA::ULong) (gen->gen_long () % MAX_DEPTH) + 1;

      Param_Test::nested_rec_union nru;

      this->deep_init_nested (nru,
                              gen,
                              nested_depth);

      ru.nested_member (nru);

      Param_Test::Recursive_Union::_rec_member_seq tmp (MAX_SEQ_LENGTH);

      ru.rec_member (tmp);

      return;
    }
  else
    {
      // Generate a member sequence.
      CORBA::ULong len = 
        (CORBA::ULong) (gen->gen_long () % MAX_SEQ_LENGTH) + 1;

      Param_Test::Recursive_Union::_rec_member_seq tmp (MAX_SEQ_LENGTH);

      tmp.length (len);

      ru.rec_member (tmp);

      // We recurse for each element of the member sequence.
      for (CORBA::ULong i = 0; i < len; i++)
        {
          this->deep_init (ru.rec_member ()[i],
                           gen,
                           level - 1);
        }
    }
}

// Private helper function to recursively initialize the nested union.
void
Test_Recursive_Union::deep_init_nested (Param_Test::nested_rec_union &nu,
                                        Generator *gen,
                                        CORBA::ULong level)
{
  if (level == 1)
  // No more recursion
    {
      nu.value (gen->gen_long ());

      return;
    }
  else
    {
      // Generate a sequence length.
      CORBA::ULong len =
        (CORBA::ULong) (gen->gen_long () % MAX_SEQ_LENGTH) + 1;

      Param_Test::nested_rec_union::_nested_rec_member_seq tmp (MAX_SEQ_LENGTH);

      tmp.length (len);

      nu.nested_rec_member (tmp);

      // We recurse for each element of the member sequence.
      for (CORBA::ULong i = 0; i < len; i++)
        {
          this->deep_init_nested (nu.nested_rec_member ()[i],
                                  gen,
                                  level - 1);
        }
    }
}

// Private helper function for check_validity (so we can recurse).
CORBA::Boolean
Test_Recursive_Union::deep_check (const Param_Test::Recursive_Union &in_union,
                                  const Param_Test::Recursive_Union &test_union)
{
  // Do the discriminators match? 
  if (in_union._d () != test_union._d ())
    {
      ACE_DEBUG ((LM_DEBUG,
                  "mismatch of Recursive_Union discriminators\n"));

      return 0;
    }

  switch (in_union._d ())
    {
      // Active member is the Recursive_Union sequence.
      case 0:
        {
          // Do the sequence lengths match?
          if (in_union.rec_member ().length () != 
                test_union.rec_member ().length ())
            {
              ACE_DEBUG ((LM_DEBUG,
                          "mismatch of Recursive_Union member sequence lengths\n"));

              return 0;
            }

          for (CORBA::ULong i = 0; i < in_union.rec_member ().length (); i++)
            {
              if (!this->deep_check (in_union.rec_member ()[i], 
                                     test_union.rec_member ()[i]))
                {
                  ACE_DEBUG ((LM_DEBUG,
                              "mismatch of contained Recursive_Unions\n"));

                  return 0;
                }
            }

          break;
        }

      // Active member is the nested union.
      case 1:
        return this->deep_check_nested (in_union.nested_member (),
                                        test_union.nested_member ());

      default:
        ACE_DEBUG ((LM_DEBUG,
                    "bad discriminator value\n"));

        break;
    }

  return 1;
}

CORBA::Boolean
Test_Recursive_Union::deep_check_nested (const Param_Test::nested_rec_union &in,
                                         const Param_Test::nested_rec_union &test)
{
  if (in._d () != test._d ())
    {
      ACE_DEBUG ((LM_DEBUG,
                  "mismatch of nested union discriminators\n"));

      return 0;
    }

  switch (in._d ())
    {
      // Active member is the long integer.
      case 0:        
        // Do the nested_rec_union member values match?
        if (in.value () != test.value ())
          {
            ACE_DEBUG ((LM_DEBUG,
                        "mismatch of nested_rec_union member values\n"));

            return 0;
          }

        break;

      // Active member is the recursive sequence.
      case 1:
        {
          // Do the sequence lengths match?
          if (in.nested_rec_member ().length () !=
                test.nested_rec_member ().length ())
            {
              ACE_DEBUG ((LM_DEBUG,
                          "mismatch of nested_rec_union member sequence lengths\n"));

              return 0;
            }

          for (CORBA::ULong i = 0; i < in.nested_rec_member ().length (); i++)
            {
              if (!this->deep_check_nested (in.nested_rec_member ()[i], 
                                            test.nested_rec_member ()[i]))
                {
                  ACE_DEBUG ((LM_DEBUG,
                              "mismatch of contained nested_rec_unions\n"));

                  return 0;
                }
            }
        }
    }

  return 1;
}
