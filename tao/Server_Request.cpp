// $Id$

// Implementation of the Dynamic Server Skeleton Interface

#include "tao/corba.h"

// Timeprobes class
#include "tao/Timeprobe.h"

#if !defined (__ACE_INLINE__)
# include "tao/Server_Request.i"
#endif /* ! __ACE_INLINE__ */

const char *TAO_Server_Request_Timeprobe_Description[] = 
{ 
  "Server_Request::Server_Request - start",
  "Server_Request::Server_Request - end",
};

enum 
{
  TAO_SERVER_REQUEST_START = 400,
  TAO_SERVER_REQUEST_END,
};

// {77420086-F276-11ce-9598-0000C07CA898}
DEFINE_GUID (IID_IIOP_ServerRequest,
0x77420086, 0xf276, 0x11ce, 0x95, 0x98, 0x0, 0x0, 0xc0, 0x7c, 0xa8, 0x98);

// {4B48D881-F7F0-11ce-9598-0000C07CA898}
DEFINE_GUID (IID_CORBA_ServerRequest,
0x4b48d881, 0xf7f0, 0x11ce, 0x95, 0x98, 0x0, 0x0, 0xc0, 0x7c, 0xa8, 0x98);

CORBA_ServerRequest *
CORBA_ServerRequest::_duplicate (CORBA_ServerRequest *req)
{
  if (req)
    {
      req->AddRef ();
      return req;
    }
  return (CORBA_ServerRequest *) 0;
}

CORBA_ServerRequest *
CORBA_ServerRequest::_nil (void)
{
  return (CORBA_ServerRequest *) 0;
}

IIOP_ServerRequest::IIOP_ServerRequest (TAO_InputCDR &input,
                                        TAO_OutputCDR &output,
                                        CORBA::ORB_ptr the_orb,
                                        TAO_POA *the_poa,
                                        CORBA::Environment &env)
  : operation_ (),
    incoming_ (&input),
    outgoing_ (&output),
    response_expected_ (CORBA::B_FALSE),
    params_ (0),
    retval_ (0),
    exception_ (0),
    exception_type_ (TAO_GIOP_NO_EXCEPTION),
    refcount_ (1),
    orb_ (the_orb),
    poa_ (the_poa),
    service_info_ (),
    request_id_ (0),
    object_key_ (),
    requesting_principal_ (0)
{
  ACE_FUNCTION_TIMEPROBE (TAO_SERVER_REQUEST_START);

  CORBA::Boolean hdr_status;

  // Tear out the service context ... we currently ignore it, but it
  // should probably be passed to each ORB service as appropriate
  // (e.g. transactions, security).
  //
  // NOTE: As security support kicks in, this is a good place to
  // verify a digital signature, if that is required in this security
  // environment.  It may be required even when using IPSEC security
  // infrastructure.

  hdr_status = input.decode (TC_ServiceContextList,
                             &this->service_info_,
                             0,
                             env);

  // Get the rest of the request header ...

  hdr_status = hdr_status && input.read_ulong (this->request_id_);
  hdr_status = hdr_status && input.read_boolean (this->response_expected_);
  hdr_status = hdr_status && input.decode (TC_opaque,
                                           &this->object_key_,
                                           0,
                                           env);
  hdr_status = hdr_status && input.decode (CORBA::_tc_string,
                                           &this->operation_,
                                           0,
                                           env);
  hdr_status = hdr_status && input.decode (CORBA::_tc_Principal,
                                           &this->requesting_principal_,
                                           0,
                                           env);

  if (!hdr_status)
    env.exception (new CORBA::COMM_FAILURE (CORBA::COMPLETED_NO));
}

IIOP_ServerRequest::~IIOP_ServerRequest (void)
{
  if (this->params_)
    CORBA::release (this->params_);
  if (this->retval_)
    delete this->retval_;
  if (this->exception_)
    delete this->exception_;
}

ULONG
IIOP_ServerRequest::AddRef (void)
{
  ACE_ASSERT (this->refcount_ > 0);
  return this->refcount_++;
}

ULONG
IIOP_ServerRequest::Release (void)
{
  ACE_ASSERT (this != 0);

  if (--this->refcount_ != 0)
    return this->refcount_;

  delete this;
  return 0;
}

TAO_HRESULT
IIOP_ServerRequest::QueryInterface (REFIID riid,
                                    void **ppv)
{
  ACE_ASSERT (this->refcount_ > 0);
  *ppv = 0;

  if (IID_IIOP_ServerRequest == riid
      || IID_CORBA_ServerRequest == riid
      || IID_TAO_IUnknown == riid)
    *ppv = this;

  if (*ppv == 0)
    return TAO_ResultFromScode (TAO_E_NOINTERFACE);

 (void) this->AddRef ();
  return TAO_NOERROR;
}

// Unmarshal in/inout params, and set up to marshal the appropriate
// inout/out/return values later on.

void
IIOP_ServerRequest::arguments (CORBA::NVList_ptr &list,
                               CORBA::Environment &env)
{
  env.clear ();

  // Save params for later use when marshaling the reply.
  this->params_ = list;

  // Then unmarshal each "in" and "inout" parameter.
  for (u_int i = 0; i < list->count (); i++)
    {
      CORBA::NamedValue_ptr nv = list->item (i, env);

      // check if it is an in or inout parameter
      if (ACE_BIT_DISABLED (nv->flags (), CORBA::ARG_IN | CORBA::ARG_INOUT))
        continue;

      // First, make sure the memory into which we'll be unmarshaling
      // exists, and is the right size.
      //
      // NOTE: desirable to have a way to let the dynamic
      // implementation routine preallocate this data, for
      // environments where DSI is just being used in lieu of a
      // language mapped server-side API and the size is really
      // knowable in advance.
      //
      // This is exactly what the TAO IDL compiler generated skeletons do.

      CORBA::Any_ptr any = nv->value ();
      CORBA::TypeCode_ptr tc = any->type ();

      tc->AddRef ();

      void *value;
      if (!any->value ())
        { // not preallocated
          ACE_NEW (value, char [tc->size (env)]);

	  if (env.exception () != 0)
	    return;

          any->replace (tc, value, CORBA::B_TRUE, env);
	  if (env.exception () != 0)
	    return;

          // Decrement the refcount of "tc".
          //
          // The earlier AddRef is needed since Any::replace () releases
          // the typecode inside the Any.  Without the dup, the reference
          // count can go to zero, and the typecode would then be deleted.
          //
          // This Release ensures that the reference count is correct so
          // the typecode can be deleted some other time.

          tc->Release ();
        }
      else
        value = (void *)any->value (); // memory was already preallocated

      // Then just unmarshal the value.
      (void) incoming_->decode (tc, value, 0, env);
      if (env.exception () != 0)
	{
	  const char* param_name = nv->name ();
	  if (param_name == 0)
	    param_name = "(no name given)";
	  ACE_ERROR ((LM_ERROR,
		      "IIOP_ServerRequest::arguments - problem while"
		      " decoding parameter %d <%s>\n", i, param_name));
	  return;
	}
    }

  // If any data is left over, it'd be context values ... else error.
  // We don't support context values, so it's always an error.

  // @@ (TAO) support for Contexts??
  if (incoming_->length () != 0)
    {
      ACE_ERROR ((LM_ERROR,
		  "IIOP_ServerRequest::arguments - "
		  "%d bytes left in buffer\n", incoming_->length ()));
      env.exception (new CORBA::BAD_PARAM (CORBA::COMPLETED_NO));
    }
}

// Store the result value.  There's either an exception, or a result,
// but not both of them.  Results (and exceptions) can be reported
// only after the parameter list has been provided (maybe empty).

void
IIOP_ServerRequest::set_result (const CORBA::Any &value,
                                CORBA::Environment &env)
{
  env.clear ();

  // setting a result when another result already exists or if an exception
  // exists is an error
  if (this->retval_ || this->exception_)
    env.exception (new CORBA::BAD_INV_ORDER (CORBA::COMPLETED_NO));
  else
    {
      this->retval_ = new CORBA::Any;
      this->retval_->replace (value.type (), value.value (), 1, env);
    }
}

// Store the exception value.

void
IIOP_ServerRequest::set_exception (const CORBA::Any &value,
                                   CORBA::Environment &env)
{
  if (this->retval_ || this->exception_)
    env.exception (new CORBA::BAD_INV_ORDER (CORBA::COMPLETED_NO));
  else
    {
      this->exception_ = new CORBA::Any;
      this->exception_->replace (value.type (), value.value (), 1, env);

      // @@ This cast is not safe, but we haven't implemented the >>=
      // and <<= operators for base exceptions (yet).
      CORBA_Exception* x = (CORBA_Exception*)value.value ();
      if (CORBA_UserException::_narrow (x) != 0)
	this->exception_type_ = TAO_GIOP_USER_EXCEPTION;
      else
	this->exception_type_ = TAO_GIOP_SYSTEM_EXCEPTION;
    }
}

// Extension
void
IIOP_ServerRequest::demarshal (CORBA::Environment &orb_env,
                               // ORB related exception reporting
                               const TAO_Call_Data_Skel *info,
                               // call description
                               ...)
{
  // initialize a container object to hold the parameters
  CORBA::NVList_ptr nvlist;

  // Create an NVList
  this->orb ()->create_list (0, nvlist);

  // Now, put all "in" and "inout" parameters into the NVList.
  CORBA::ULong i;

  // Setup the variable argument list.
  const TAO_Param_Data_Skel *pdp;
  va_list param_vector;
  va_start (param_vector, info);

  for (i = 0, pdp = info->params;
       i < info->param_count;
       i++, pdp++)
    {
      void *ptr = va_arg (param_vector, void *);

      if ((pdp->mode == CORBA::ARG_IN)
          || (pdp->mode == CORBA::ARG_INOUT))
        // Populate the NVList.
        (void) nvlist->add_item (0, pdp->mode, orb_env)->value ()
          ->replace (pdp->tc, ptr, pdp->own, orb_env);
      else if (pdp->mode == CORBA::ARG_OUT)
        // Don't add any value.
        (void) nvlist->add_item (0, pdp->mode, orb_env);

    }

  va_end (param_vector);

  // Now demarshal the parameters using a call to params.
  this->arguments (nvlist, orb_env); // nvlist is now owned by us
}

// Extension

void
IIOP_ServerRequest::marshal (CORBA::Environment &orb_env,
                             // ORB related exception reporting
                             CORBA::Environment &skel_env,
                             // skeleton related exception reporting
                             const TAO_Call_Data_Skel *info,
                             // call description
                             ...)
{
  // what is "orb_env" and "skel_env"?
  // "skel_env" holds the exception that got raised inside the operation
  // implementation (upcall)
  //
  // "orb_env" is the exception that may have been raised due to things going
  // wrong in the entire dispatch process. These are always system exceptions.

  // check if we are inside with an exception. This may have happened
  // since the upcall could have set some exception
  if (skel_env.exception ())
    {
      // don't own it because ultimately it will be owned by the Server_Request
      // via a call to "set_exception"
      CORBA::Any any (skel_env.exception ()->_type (), skel_env.exception ());
      this->set_exception (any, orb_env);
    }

  // Setup a Reply message so that we can marshal all the outgoing parameters
  // into it. If an exception was set, then that gets marshaled into the reply
  // message and we don't do anything after that
  this->init_reply (orb_env);

  // exception? nothing to do after this
  if (orb_env.exception () || skel_env.exception ())
    return;

  // Now, put all "in" and "inout" parameters into the NVList.
  CORBA::ULong i;
  CORBA::ULong j;

  // Setup the variable argument list.
  const TAO_Param_Data_Skel *pdp;
  va_list param_vector;
  va_start (param_vector, info);

  j = 0;

  for (i = 0, pdp = info->params;
       i < info->param_count;
       i++, pdp++)
    {
      void *ptr = va_arg (param_vector, void *);

      if (pdp->mode == 0)
        {
          // check if the return type is not void
          if (pdp->tc->kind (orb_env) != CORBA::tk_void)
            {
              this->retval_ = new CORBA::Any (pdp->tc, ptr, pdp->own);
            }
          continue;
        }

      if (pdp->mode == CORBA::ARG_OUT)
        // don't add any value. The skeletons generated by the TAO IDL compiler
        // make sure that the Any does not own the data
        (void) this->params_->item (j, orb_env)->value ()->replace (pdp->tc, ptr, pdp->own, orb_env);

      j++;
    }
  va_end (param_vector);

  // in the following we are guaranteed that the any->value () returns a void*
  // and not an ACE_Message_Block since the generated skeletons make sure that
  // these Anys don't own the data.

  // Normal reply.
  if (!orb_env.exception ())
    {
      // ... then send any return value ...
      if (this->retval_)
        {
          CORBA::TypeCode_ptr tc = this->retval_->type ();
          const void *value = this->retval_->value ();

          if (value)
            (void) this->outgoing_->encode (tc, value, 0, orb_env);
        }

      // ... Followed by "inout" and "out" parameters, left to right
      for (i = 0;
           i < this->params_->count ();
           i++)
        {
          CORBA::NamedValue_ptr nv = this->params_->item (i, orb_env);
          CORBA::Any_ptr any;

          if (!(nv->flags () & (CORBA::ARG_INOUT|CORBA::ARG_OUT)))
            continue;

          any = nv->value ();
          CORBA::TypeCode_ptr tc = any->type ();
          const void *value = any->value ();
          (void) this->outgoing_->encode (tc, value, 0, orb_env);
        }
    }
}

void
IIOP_ServerRequest::init_reply (CORBA::Environment &env)
{
  // Construct a REPLY header.
  TAO_GIOP::start_message (TAO_GIOP::Reply, *this->outgoing_);
  TAO_GIOP_ServiceContextList resp_ctx;
  resp_ctx.length (0);
  this->outgoing_->encode (TC_ServiceContextList,
                           &resp_ctx,
                           0,
                           env);
  this->outgoing_->write_ulong (this->request_id_);

  // Standard exceptions only.
  if (env.exception () != 0)
    {
      CORBA::Environment env2;
      CORBA::Exception *x = env.exception ();
      CORBA::TypeCode_ptr except_tc = x->_type ();

      this->outgoing_->write_ulong (TAO_GIOP_SYSTEM_EXCEPTION);
      (void) this->outgoing_->encode (except_tc, x, 0, env2);
    }

  // Any exception at all.
  else if (this->exception_)
    {
      CORBA::TypeCode_ptr except_tc;

      except_tc = this->exception_->type ();

      // Finish the GIOP Reply header, then marshal the exception.
      // XXX x->type () someday ...

      this->outgoing_->write_ulong (this->exception_type_);

      // we know that the value () will return the ACE_Message_Block
      TAO_InputCDR cdr ((ACE_Message_Block*)this->exception_->value ());
      (void) this->outgoing_->append (except_tc, &cdr, env);
    }
  else // Normal reply
    // First finish the GIOP header ...
    this->outgoing_->write_ulong (TAO_GIOP_NO_EXCEPTION);
}

// this method will be utilized by the DSI servant to marshal outgoing
// parameters

void
IIOP_ServerRequest::dsi_marshal (CORBA::Environment &env)
{
  // NOTE: if "env" is set, it takes precedence over exceptions
  // reported using the mechanism of the ServerRequest.  Only system
  // exceptions are reported that way ...
  //
  // XXX Exception reporting is ambiguous; it can be cleaner than
  // this.  With both language-mapped and dynamic/explicit reporting
  // mechanisms, one of must be tested "first" ... so an exception
  // reported using the other mechanism could be "lost".  Perhaps only
  // the language mapped one should be used for system exceptions.


  CORBA::TypeCode_ptr tc;
  const void *value;

  // only if there wasn't any exception, we proceed
  if (this->exception_type_ == TAO_GIOP_NO_EXCEPTION)
    {
      // ... then send any return value ...
      if (this->retval_)
        {
          tc = this->retval_->type ();
          value = this->retval_->value ();
          if (this->retval_->any_owns_data ())
            {
              TAO_InputCDR cdr ((ACE_Message_Block *)value);
              (void) this->outgoing_->append (tc, &cdr, env);
            }
          else
            (void) this->outgoing_->encode (tc, value, 0, env);
        }

      // ... Followed by "inout" and "out" parameters, left to right
      for (u_int i = 0;
           i < this->params_->count ();
           i++)
        {
          CORBA::NamedValue_ptr nv = this->params_->item (i, env);
          CORBA::Any_ptr any;

          if (!(nv->flags () & (CORBA::ARG_INOUT|CORBA::ARG_OUT)))
            continue;

          any = nv->value ();
          tc = any->type ();
          value = any->value ();
          if (any->any_owns_data ())
            {
              TAO_InputCDR cdr ((ACE_Message_Block *)value);
              (void) this->outgoing_->append (tc, &cdr, env);
            }
          else
            (void) this->outgoing_->encode (tc, value, 0, env);
        }
    }
}
