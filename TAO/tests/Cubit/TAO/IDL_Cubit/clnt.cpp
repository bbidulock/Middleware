// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/IDL_Cubit
//
// = FILENAME
//    clnt.cpp
//
// = DESCRIPTION
//      This class implements a simple "cube" CORBA client for the Cubit
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//    Copyright 1994-1995 by Sun Microsystems Inc.
//    and
//    Aniruddha Gokhale, Sumedh Mungee, and Sergio Flores-Gaitan
//
// ============================================================================

#include "ace/Profile_Timer.h"
#include "clnt.h"

// Constructor.

Cubit_Client::Cubit_Client (void)
  : cubit_factory_key_ ("factory"),
    cubit_key_ ("key0"),
    hostname_ (ACE_DEFAULT_SERVER_HOST),
    portnum_ (TAO_DEFAULT_SERVER_PORT),
    loop_count_ (250),
    exit_later_ (0),
    factory_ (Cubit_Factory::_nil ()),
    objref_ (CORBA::Object::_nil ()),
    cubit_ (Cubit::_nil ()),
    orb_ptr_ (0),
    call_count_ (0),
    error_count_ (0)
{
}

// Simple function that returns the substraction of 117 from the
// parameter.

int
Cubit_Client::func (u_int i)
{
  return i - 117;
}

// Parses the command line arguments and returns an error status.

int
Cubit_Client::parse_args (void)
{
  ACE_Get_Opt get_opts (argc_, argv_, "dn:h:p:k:x");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag
        TAO_debug_level++;
        break;
      case 'n':			// loop count
        loop_count_ = (u_int) ACE_OS::atoi (get_opts.optarg);
        break;
      case 'h':
        hostname_ = ACE_OS::strdup (get_opts.optarg);
        break;
      case 'p':
        portnum_ = ACE_OS::atoi (get_opts.optarg);
        break;
      case 'k':			// stringified objref
        cubit_key_ = ACE_OS::strdup (get_opts.optarg);
        break;
      case 'x':
        this->exit_later_++;
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-d]"
                           " [-n loopcount]"
                           " [-k cubit-obj-ref-key]"
                           " [-h hostname]"
                           " [-p port]"
                           " [-x]"
                           "\n",
                           this->argv_ [0]),
                          -1);
      }

  // Indicates successful parsing of command line.
  return 0;
}

// Exercise the union.  Cube a union.

void
Cubit_Client::cube_union_stub (void)
{
  CORBA::Environment env;
  Cubit::oneof u, r;

  this->call_count_++;

  u.l (3); // use the long union branch

  // Cube a "union" ...
  r = this->cubit_->cube_union (u, this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("from cube_union");
      this->error_count_++;
    }
  else
    {
      dmsg ("cube union ...");
      u.l (u.l () * u.l () * u.l ()) ;

      if (u.l () != r.l ())
	{
	  ACE_DEBUG ((LM_DEBUG, "** cube_union ERROR\n"));
	  this->error_count_++;
	}

    }

  this->call_count_++;

  u._d (Cubit::e_3rd);
#if 0
  u.cm ().l = this->func (i);
  u.cm ().s = this->func (i);
  u.cm ().o = this->func (i);
#endif

  u.cm ().l = 7;
  u.cm ().s = 5;
  u.cm ().o = 3;

  // Cube another "union" which uses the default arm ... NOT tested yet
  r = this->cubit_->cube_union (u, this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("from cube_union");
      this->error_count_++;
    }
  else
    {
      dmsg ("cube union ...");
      u.cm ().l = u.cm ().l * u.cm ().l * u.cm ().l;
      u.cm ().s = u.cm ().s * u.cm ().s * u.cm ().s;
      u.cm ().o = u.cm ().o * u.cm ().o * u.cm ().o;

      if (u.cm ().l != r.cm ().l
	  || u.cm ().s != r.cm ().s
	  || u.cm ().o != r.cm ().o)
	{
	  ACE_DEBUG ((LM_DEBUG, "** cube_union ERROR\n"));
	  this->error_count_++;
	}
    }
}

// Exercise the union using dii.

void
Cubit_Client::cube_union_dii (void)
{
  // Create the request ...
  CORBA::Request_ptr req;

  this->call_count_++;

  req = this->cubit_->_request ((CORBA::String) "cube_union", this->env_);

  if (this->env_.exception () != 0)
    {
      this->error_count_++;

      this->env_.print_exception ("cube_union_dii request create");
      return;
    }

  // ... initialise the argument list and result ...
  Cubit::oneof	*u, r;

  u = new Cubit::oneof;
  u->_d (Cubit::e_3rd);

  u->cm ().l = 5;
  u->cm ().s = -7;
  u->cm ().o = 3;

  CORBA::Any tmp_arg (Cubit::_tc_oneof, u, CORBA::B_FALSE);

  req->arguments ()->add_value ("values", tmp_arg, CORBA::ARG_IN, this->env_);

  if (this->env_.exception () != 0)
    {
      this->error_count_++;
      this->env_.print_exception ("cube_union_dii request arg add");
      CORBA::release (req);
      return;
    }

  req->result ()->value ()->replace (Cubit::_tc_oneof, 0, CORBA::B_TRUE, this->env_);

  if (this->env_.exception () != 0)
    {
      this->error_count_++;
      this->env_.print_exception ("cube_union_dii result type");
      CORBA::release (req);
      return;
    }

  // Make the invocation, verify the result.

  req->invoke ();

  if (req->env ()->exception () != 0)
    {
      this->error_count_++;
      req->env ()->print_exception ("cube_union_dii invoke");
      CORBA::release (req);
      return;
    }

  r = *(Cubit::oneof *) req->result ()->value ()->value ();

  if (r.cm ().o != 27 || r.cm ().l != 125 || r.cm ().s != -343)
    {
      this->error_count_++;
      ACE_ERROR ((LM_ERROR, "cube_union_dii -- bad results\n"));
    }
  else
    dmsg ("cube_union_dii ... success!!");

  CORBA::release (req);
  delete u;
}

// Cube a short.

void
Cubit_Client::cube_short (int i)
{
  CORBA::Short arg_short = this->func (i);
  // Cube a short.
  CORBA::Short ret_short = cubit_->cube_short (arg_short, this->env_);

  this->call_count_++;

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("from cube_short");
      this->error_count_++;
    }
  else
    {
      dmsg2 ("cube short:  %d --> %d\n",
	     arg_short,
	     ret_short);
      arg_short = arg_short * arg_short * arg_short;

      if (arg_short != ret_short)
	{
	  ACE_ERROR ((LM_ERROR, "** cube_short (%d) ERROR (--> %d)\n",
		      (CORBA::Short) this->func (i),
		      ret_short));
	  this->error_count_++;
	}
    }
}

// Cube an octet

void
Cubit_Client::cube_octet (int i)
{
  CORBA::Octet arg_octet = this->func (i);

   // Cube an octet.
  CORBA::Octet ret_octet = this->cubit_->cube_octet (arg_octet, this->env_);

  this->call_count_++;

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("from cube_octet");
      this->error_count_++;
    }
  else
    {
      dmsg2 ("cube octet:  %d --> %d\n", arg_octet, ret_octet);
      arg_octet = arg_octet * arg_octet * arg_octet;
      if (arg_octet != ret_octet) {
	ACE_DEBUG ((LM_DEBUG,
		    "** cube_octet (%d) ERROR (--> %d)\n",
		    (CORBA::Octet) this->func (i),
		    ret_octet));
	this->error_count_++;
      }
    }
}

// calculate the cube from a long

void
Cubit_Client::cube_long (int i)
{
  CORBA::Long arg_long = this->func (i);

  // Cube a long.
  CORBA::Long ret_long = this->cubit_->cube_long (arg_long, this->env_);;

  this->call_count_++;

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("from cube_long");
      this->error_count_++;
    }
  else
    {
      dmsg2 ("cube long:  %d --> %d\n", arg_long, ret_long);
      arg_long = arg_long * arg_long * arg_long;
      if (arg_long != ret_long) {
	ACE_ERROR ((LM_ERROR,
		    "** cube_long (%ld) ERROR (--> %ld)\n",
		    (CORBA::Long) this->func (i),
		    ret_long));
	this->error_count_++;
      }
    }
}

// Cube the numbers in a struct

void
Cubit_Client::cube_struct (int i)
{
  Cubit::Many arg_struct;
  Cubit::Many ret_struct;

  this->call_count_++;

  arg_struct.l = this->func (i);
  arg_struct.s = this->func (i);
  arg_struct.o = this->func (i);

  // Cube a "struct" ...
  ret_struct = this->cubit_->cube_struct (arg_struct, this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("from cube_struct");
      this->error_count_++;
    }
  else
    {
      dmsg ("cube struct ...");
      arg_struct.l = arg_struct.l * arg_struct.l * arg_struct.l;
      arg_struct.s = arg_struct.s * arg_struct.s * arg_struct.s;
      arg_struct.o = arg_struct.o * arg_struct.o * arg_struct.o;

      if (arg_struct.l != ret_struct.l
	  || arg_struct.s != ret_struct.s
	  || arg_struct.o != ret_struct.o)
	{
	  ACE_ERROR ((LM_ERROR, "** cube_struct ERROR\n"));
	  this->error_count_++;
	}
    }
}

// Cube the numbers in a sequence

void
Cubit_Client::cube_sequence (int i)
{
  this->call_count_++;

  Cubit::vector input (i + 1);
  input.length (i+1);

  // Fill in the input sequence...
  for (int j = 0; j < i + 1; ++j)
    {
      input[j] = j;
    }

  Cubit::vector_var output;
  Cubit::vector_out vout (output);

  // Cube the sequence
  this->cubit_->cube_sequence (input, vout, this->env_);

  //  Cubit::vector& output = *vout.ptr ();
  //  output = vout;

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("from cube_struct");
      this->error_count_++;
    }
  else
    {
      if (output->length () != input.length ())
        {
          ACE_ERROR ((LM_ERROR, "** cube sequence, wrong length\n"));
          this->error_count_++;
        }

      u_int l = output->length ();
      if (input.length () < l)
        {
          l = input.length ();
        }
      for (u_int j = 0; j < l; ++j)
        {
          int x = input[j];
          if (x*x*x != output[j])
            {
              ACE_ERROR ((LM_ERROR, "** cube_sequence ERROR\n"));
              this->error_count_++;
            }
        }
    }
}



// Cube the numbers in a struct

void
Cubit_Client::cube_struct_dii (void)
{
  // Create the request ...
  CORBA::Request_ptr req =
    this->cubit_->_request ((CORBA::String) "cube_struct", this->env_);

  this->call_count_++;

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("DII request create");
      return;
    }

  // ... initialise the argument list and result ...
  Cubit::Many arg;
  Cubit::Many result;

  arg.o = 3;
  arg.l = 5;
  arg.s = -7;

  CORBA::Any tmp_arg (Cubit::_tc_Many, &arg, CORBA::B_FALSE);

  req->arguments ()->add_value ("values", tmp_arg, CORBA::ARG_IN, this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("DII request arg add");
      CORBA::release (req);
      return;
    }

  req->result ()->value ()->replace (Cubit::_tc_Many, 0, CORBA::B_TRUE, this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("DII request result type");
      CORBA::release (req);
      return;
    }

  // Make the invocation, verify the result

  req->invoke ();

  if (req->env ()->exception () != 0)
    {
      req->env ()->print_exception ("DII invoke sending struct");
      CORBA::release (req);
      return;
    }

  result = *(Cubit::Many *) req->result ()->value ()->value ();

  if (result.o != 27 || result.l != 125 || result.s != -343)
    ACE_ERROR ((LM_ERROR, "DII cube_struct -- bad results\n"));
  else
    dmsg ("DII cube_struct ... success!!");

  CORBA::release (req);
}

void
Cubit_Client::print_stats (const char *call_name, ACE_Profile_Timer::ACE_Elapsed_Time &elapsed_time)
{
  double tmp;

  ACE_DEBUG ((LM_DEBUG,
	      "%s:\n",
	      call_name));

  if (this->call_count_ > 0  &&  this->error_count_ == 0)
    {
      tmp = 1000 / elapsed_time.real_time;

      elapsed_time.real_time *= ACE_ONE_SECOND_IN_MSECS;
      elapsed_time.user_time *= ACE_ONE_SECOND_IN_MSECS;
      elapsed_time.system_time *= ACE_ONE_SECOND_IN_MSECS;

      elapsed_time.real_time /= this->call_count_;
      elapsed_time.user_time /= this->call_count_;
      elapsed_time.system_time /= this->call_count_;

      tmp = 1000 / elapsed_time.real_time;

      ACE_DEBUG ((LM_DEBUG,
		  "\treal_time\t= %0.06f ms, \n\t"
		  "user_time\t= %0.06f ms, \n\t"
		  "system_time\t= %0.06f ms\n"
		  "\t%0.00f calls/second\n",
		  elapsed_time.real_time < 0.0? 0.0:elapsed_time.real_time,
		  elapsed_time.user_time < 0.0? 0.0:elapsed_time.user_time,
		  elapsed_time.system_time < 0.0? 0.0:elapsed_time.system_time,
		  tmp < 0.0? 0.0 : tmp));
    }
  else
    {
      ACE_ERROR ((LM_ERROR, "\tNo time stats printed.  Call count zero or error ocurred.\n"));
    }

  ACE_DEBUG ((LM_DEBUG,
	      "\t%d calls, %d errors\n",
	      this->call_count_,
	      this->error_count_));
}

// Execute client example code.

int
Cubit_Client::run (void)
{
  u_int i;

  ACE_Profile_Timer timer;
  ACE_Profile_Timer::ACE_Elapsed_Time elapsed_time;

  //  ACE_Time_Value before;

  // We start an ACE_Profile_Timer here...
  timer.start ();

  // Make the calls in a loop.
  for (i = 0; i < this->loop_count_; i++)
    {
      this->cube_short (i);
      this->cube_octet (i);
      this->cube_long (i);
      this->cube_struct (i);
      this->cube_sequence (i);
    }

  // stop the timer.
  timer.stop ();

  timer.elapsed_time (elapsed_time);
  // compute call average call time.
  this->print_stats ("cube average call", elapsed_time);

  // Simple test for DII: call "cube_struct". (It's not timed since
  // the copious mallocation of DII would bias numbers against typical
  // stub-based calls).

  timer.start ();

  this->call_count_ = 0;
  this->error_count_ = 0;
  // Make the calls in a loop.
  for (i = 0; i < this->loop_count_; i++)
    {
      this->cube_struct_dii ();
    }
  timer.stop ();

  timer.elapsed_time (elapsed_time);
  // compute call average call time.
  this->print_stats ("cube_struct_dii call", elapsed_time);

  // ------------------>
  // Two more tests, using the "cube_union" function

  // unions using stubs
  timer.start ();

  this->call_count_ = 0;
  this->error_count_ = 0;
  // Make the calls in a loop.
  for (i = 0; i < this->loop_count_; i++)
    {
      this->cube_union_stub ();
    }

  timer.stop ();

  timer.elapsed_time (elapsed_time);
  // compute call average call time.
  this->print_stats ("cube_union_stub call", elapsed_time);

  // union DII
  timer.start ();

  this->call_count_ = 0;
  this->error_count_ = 0;
  // Make the calls in a loop.
  for (i = 0; i < this->loop_count_; i++)
    {
      this->cube_union_dii ();
    }

  timer.stop ();

  timer.elapsed_time (elapsed_time);
  // compute call average call time.
  this->print_stats ("cube_union_dii call", elapsed_time);

  // Sequences
  timer.start ();
  this->call_count_ = 0;
  this->error_count_ = 0;
  // Make the calls in a loop.
  for (i = 0; i < this->loop_count_; i++)
    {
      this->cube_sequence (this->loop_count_);
    }

  timer.stop ();

  timer.elapsed_time (elapsed_time);
  // compute call average call time.
  this->print_stats ("cube_sequence", elapsed_time);



  if (this->exit_later_)
    {
      this->cubit_->please_exit (this->env_);
      dexc (this->env_, "server, please ACE_OS::exit");
    }

  return this->error_count_ == 0 ? 0 : 1;
}

Cubit_Client::~Cubit_Client (void)
{
  // Free resources
  CORBA::release (this->orb_ptr_);
  CORBA::release (this->objref_);
  CORBA::release (this->factory_);
  CORBA::release (this->cubit_);
}

int
Cubit_Client::init (int argc, char **argv)
{
  this->argc_ = argc;
  this->argv_ = argv;

  // Retrieve the ORB.
  this->orb_ptr_ = CORBA::ORB_init (this->argc_,
                                    this->argv_,
                                    "internet",
                                    this->env_);

  // Parse command line and verify parameters.
  if (this->parse_args () == -1)
    return -1;

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("ORB initialization");
      return -1;
    }

  if (this->cubit_key_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
               "%s: must specify an object reference using -k <key>\n",
		       this->argv_[0]),
		      -1);

  // Retrieve a factory objref.
  this->objref_ = Cubit_Factory::_bind (this->hostname_,
                                        this->portnum_,
                                        this->cubit_factory_key_,
                                        this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("Cubit_Factory::_bind");
      return -1;
    }

  if (CORBA::is_nil (this->objref_) == CORBA::B_TRUE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       " _bind returned null object for key (%s), host (%s), port (%d)\n",
                       this->cubit_factory_key_,
                       this->hostname_,
                       this->portnum_),
                      -1);

  // Narrow the CORBA::Object reference to the stub object, checking
  // the type along the way using _is_a.  There is really no need to
  // narrow <objref> because <_bind> will return us the
  // <Cubit_Factory> pointer.  However, we do it so that we can
  // explicitly test the _narrow function.
  this->factory_ = Cubit_Factory::_narrow (this->objref_, this->env_);
  //CORBA::release (this->objref_);
  this->objref_->Release ();

  if (this->factory_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
		       " (%P|%t) Unable to narrow object reference to a Cubit_Factory_ptr.\n"),
		      -1);

  // Now retrieve the Cubit obj ref corresponding to the key.
  this->cubit_ =
    this->factory_->make_cubit (this->cubit_key_, this->env_);

  if (this->env_.exception () != 0)
    {
      this->env_.print_exception ("string2object");
      return -1;
    }

  if (CORBA::is_nil (this->cubit_))
    ACE_ERROR_RETURN ((LM_ERROR,
                       "null cubit objref returned by factory\n"),
                      -1);

  return 0;
}

// This function runs the test.

int
main (int argc, char **argv)
{
  Cubit_Client cubit_client;

  if (cubit_client.init (argc, argv) == -1)
    return 1;
  else
    return cubit_client.run ();
}
