// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/Param_Test
//
// = FILENAME
//    big_union.cpp
//
// = DESCRIPTION
//    tests Big_Unions
//
// = AUTHORS
//      Aniruddha Gokhale
//
// ============================================================================

#include "helper.h"
#include "big_union.h"

ACE_RCSID(Param_Test, big_union, "$Id$")

// ************************************************************************
//               Test_Big_Union
// ************************************************************************

size_t Test_Big_Union::counter = 0;

Test_Big_Union::Test_Big_Union (void)
  : opname_ (CORBA::string_dup ("test_big_union"))
{
}

Test_Big_Union::~Test_Big_Union (void)
{
  CORBA::string_free (this->opname_);
  this->opname_ = 0;
}

const char *
Test_Big_Union::opname (void) const
{
  return this->opname_;
}

void
Test_Big_Union::dii_req_invoke (CORBA::Request *req)
{
  req->invoke ();
}

int
Test_Big_Union::init_parameters (Param_Test_ptr objref,
                           CORBA::Environment &env)
{
  TAO_TRY
    {
      // get access to a Coffee Object
      this->cobj_ = objref->make_coffee (TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCH (CORBA::SystemException, sysex)
    {
      ACE_UNUSED_ARG (sysex);
      TAO_TRY_ENV.print_exception ("System Exception doing make_coffee");
      return -1;
    }
  TAO_ENDTRY;

  this->reset_parameters ();
  return 0;
}

int
Test_Big_Union::reset_parameters (void)
{
  Generator *gen = GENERATOR::instance (); // value generator
  CORBA::ULong index = (counter++ % Test_Big_Union::BIG_UNION_N_BRANCHES);

  switch (index)
    {
    case 0:
      {
        Param_Test::Fixed_Array x;
        for (int i = 0; i < Param_Test::DIM1; ++i)
          {
            x[i] = gen->gen_long ();
          }
        this->in_.the_array (x);
        this->inout_.the_array (x);
      }
      break;
    case 1:
      {
        this->in_.the_interface (this->cobj_.in ());
        this->inout_.the_interface (this->cobj_.in ());
      }
      break;
    case 2:
      {
        CORBA::Long x = gen->gen_long ();
        this->in_.the_long (x);
        this->inout_.the_long (x);
      }
      break;
    case 3:
      {
        Param_Test::Big_Union::_another_array x;
        for (int i = 0; i < 32; ++i)
          {
            x[i] = gen->gen_short ();
          }
        this->in_.another_array (x);
        this->inout_.another_array (x);
      }
      break;
    case 4:
      {
        CORBA::String_var str = gen->gen_string ();
        this->in_.the_string (str);
        this->inout_.the_string (str);
      }
      break;
    case 5:
      {
        Param_Test::Short_Seq seq;
        seq.length (gen->gen_short () % 50);
        for (size_t i = 0; i < seq.length (); i++)
          seq[i] = gen->gen_short ();
        this->in_.the_sequence (seq);
        this->inout_.the_sequence (seq);
      }
      break;
    case 6:
      {
        CORBA::Any any;
        any <<= CORBA::Short (25);
        this->in_.the_any (any);
        this->inout_.the_any (any);
      }
      break;
    case 7:
      {
        CORBA::Octet octet = gen->gen_short () % 255;
        this->in_.the_octet (octet);
        this->inout_.the_octet (octet);
      }
      break;
    case 8:
      {
        CORBA::Char x = '@';
        this->in_.the_char (x);
        this->inout_.the_char (x);
      }
      break;
    case 9:
      {
        CORBA::Boolean x = gen->gen_short () % 2;
        this->in_.the_boolean (x);
        this->inout_.the_boolean (x);
      }
      break;
    case 10:
      {
        Param_Test::Var_Struct var_struct;
        var_struct.dummy1 = gen->gen_string ();
        var_struct.dummy2 = gen->gen_string ();
        CORBA::ULong len = gen->gen_long () % 10 + 1;
        var_struct.seq.length (len);
        for (CORBA::ULong i = 0; i != len; ++i)
          {
            var_struct.seq[i] = gen->gen_string ();
          }
        this->in_.the_var_struct (var_struct);
        this->inout_.the_var_struct (var_struct);
      }
      break;
    case 11:
      {
        Param_Test::Fixed_Struct fixed_struct;
        fixed_struct.l = gen->gen_long ();
        fixed_struct.c = gen->gen_long () % 255;
        fixed_struct.s = gen->gen_long () % 32768;
        fixed_struct.o = gen->gen_long () % 255;
        fixed_struct.f = gen->gen_short () / 255.0;
        fixed_struct.b = gen->gen_long () % 2;
        fixed_struct.d = gen->gen_short () / 255.0;
        this->in_.the_fixed_struct (fixed_struct);
        this->inout_.the_fixed_struct (fixed_struct);
      }
      break;
    }
  return 0;
}

int
Test_Big_Union::run_sii_test (Param_Test_ptr objref,
                              CORBA::Environment &env)
{
  this->ret_ = objref->test_big_union (this->in_,
                                       this->inout_,
                                       this->out_,
                                       env);
  return (env.exception () ? -1:0);
}

int
Test_Big_Union::add_args (CORBA::NVList_ptr param_list,
                          CORBA::NVList_ptr retval,
                          CORBA::Environment &env)
{
  CORBA::Any in_arg (Param_Test::_tc_Big_Union,
                     &this->in_,
                     0);

  CORBA::Any inout_arg (Param_Test::_tc_Big_Union,
                        &this->inout_,
                        0);

  CORBA::Any out_arg (Param_Test::_tc_Big_Union,
                      &this->out_,
                      0);

  // add parameters
  param_list->add_value ("u1",
                         in_arg,
                         CORBA::ARG_IN,
                         env);

  param_list->add_value ("u2",
                         inout_arg,
                         CORBA::ARG_INOUT,
                         env);

  param_list->add_value ("u3",
                         out_arg,
                         CORBA::ARG_OUT,
                         env);

  // add return value
  retval->item (0, env)->value ()->replace (Param_Test::_tc_Big_Union,
                                            &this->ret_,
                                            0,
                                            env);
  return 0;
}

CORBA::Boolean
Test_Big_Union::check_validity (void)
{
  if (this->in_._d () != this->inout_._d ()
      || this->in_._d () != this->out_->_d ()
      || this->in_._d () != this->ret_->_d ())
    {
      ACE_DEBUG ((LM_DEBUG, "mismatch of discriminators\n"));
      return 0;
    }


  switch (this->in_._d ())
    {
    case 0:
      {
        Param_Test::Fixed_Array_slice* in_array    = this->in_.the_array ();
        Param_Test::Fixed_Array_slice* inout_array = this->inout_.the_array ();
        Param_Test::Fixed_Array_slice* out_array   = this->out_->the_array ();
        Param_Test::Fixed_Array_slice* ret_array   = this->ret_->the_array ();
        for (int i = 0; i < Param_Test::DIM1; ++i)
          {
            if (in_array[i] != inout_array[i]
                || in_array[i] != out_array[i]
                || in_array[i] != ret_array[i])
              return 0;
          }
      }
      break;
    case 1:
      {
        Coffee_ptr in    = this->in_.the_interface ();
        Coffee_ptr inout = this->inout_.the_interface ();
        Coffee_ptr out   = this->out_->the_interface ();
        Coffee_ptr ret   = this->ret_->the_interface ();

      }
      break;
    case 2:
      {
        CORBA::Long in    = this->in_.the_long ();
        CORBA::Long inout = this->inout_.the_long ();
        CORBA::Long out   = this->out_->the_long ();
        CORBA::Long ret   = this->ret_->the_long ();
        if (in != out || in != inout || in != ret)
          return 0;
      }
      break;

    case 3:
      {
        Param_Test::Big_Union::_another_array_slice* in_array    =
          this->in_.another_array ();
        Param_Test::Big_Union::_another_array_slice* inout_array =
          this->inout_.another_array ();
        Param_Test::Big_Union::_another_array_slice* out_array   =
          this->out_->another_array ();
        Param_Test::Big_Union::_another_array_slice* ret_array   =
          this->ret_->another_array ();
        for (int i = 0; i != 32; ++i)
          {
            if (in_array[i] != inout_array[i]
                || in_array[i] != out_array[i]
                || in_array[i] != ret_array[i])
              return 0;
          }
      }
      break;

    case 4:
      {
        const char* in    = this->in_.the_string ();
        const char* inout = this->inout_.the_string ();
        const char* out   = this->out_->the_string ();
        const char* ret   = this->ret_->the_string ();
        if (ACE_OS::strcmp (in,out)
            || ACE_OS::strcmp (in,inout)
            || ACE_OS::strcmp (in,ret))
          return 0;
      }
      break;

    case 5:
      {
        const Param_Test::Short_Seq& in = 
          this->in_.the_sequence ();
        const Param_Test::Short_Seq& inout = 
          this->inout_.the_sequence ();
        const Param_Test::Short_Seq& out = 
          this->out_->the_sequence ();
        const Param_Test::Short_Seq& ret = 
          this->ret_->the_sequence ();

        if (in.length () != out.length ()
            || in.length () != inout.length ()
            || in.length () != ret.length ())
          return 0;

        for (CORBA::ULong i = 0; i != in.length (); ++i)
          {
            if (in[i] != out[i]
                || in[i] != inout[i]
                || in[i] != ret[i])
              return 0;
          }
      }
      break;
#if 0
    case 6:
      {
        CORBA::Any any;
        any <<= CORBA::Short (25);
        this->in_.the_any (any);
        this->inout_.the_any (any);
      }
      break;
#endif

    case 7:
      {
        CORBA::Octet in    = this->in_.the_octet ();
        CORBA::Octet inout = this->inout_.the_octet ();
        CORBA::Octet out   = this->out_->the_octet ();
        CORBA::Octet ret   = this->ret_->the_octet ();
        if (in != out || in != inout || in != ret)
          return 0;
      }
      break;

    case 8:
      {
        CORBA::Char in    = this->in_.the_char ();
        CORBA::Char inout = this->inout_.the_char ();
        CORBA::Char out   = this->out_->the_char ();
        CORBA::Char ret   = this->ret_->the_char ();
        if (in != out || in != inout || in != ret)
          return 0;
      }
      break;

    case 9:
      {
        CORBA::Boolean in    = this->in_.the_boolean ();
        CORBA::Boolean inout = this->inout_.the_boolean ();
        CORBA::Boolean out   = this->out_->the_boolean ();
        CORBA::Boolean ret   = this->ret_->the_boolean ();
        if (in != out || in != inout || in != ret)
          return 0;
      }
      break;

#if 0
    case 10:
      {
        Param_Test::Var_Struct var_struct;
        var_struct.dummy1 = gen->gen_string ();
        var_struct.dummy2 = gen->gen_string ();
        CORBA::ULong len = gen->gen_long () % 10 + 1;
        var_struct.seq.length (len);
        for (CORBA::ULong i = 0; i != len; ++i)
          {
            var_struct.seq[i] = gen->gen_string ();
          }
        this->in_.the_var_struct (x);
        this->inout_.the_var_struct (x);
      }
      break;
    case 11:
      {
        Param_Test::Fixed_Struct fixed_struct;
        fixed_struct.l = gen->gen_long ();
        fixed_struct.c = gen->gen_long () % 255;
        fixed_struct.s = gen->gen_long () % 32768;
        fixed_struct.o = gen->gen_long () % 255;
        fixed_struct.f = gen->gen_short () / 255.0;
        fixed_struct.b = gen->gen_long () % 2; 
        fixed_struct.d = gen->gen_short () / 255.0;
        this->in_.the_fixed_struct (x);
        this->inout_.the_fixed_struct (x);
      }
      break;
#endif /* 0 */
    }

  return 1;
}

CORBA::Boolean
Test_Big_Union::check_validity (CORBA::Request_ptr req)
{
  ACE_UNUSED_ARG (req);
  return this->check_validity ();
}

void
Test_Big_Union::print_values (void)
{
}
