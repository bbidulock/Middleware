//     $Id$

#if 0
#include "ace/OS.h"    // WARNING! This MUST come before objbase.h on WIN32!
#include <objbase.h>
#include <initguid.h>

#include "tao/orb.h"
#include "tao/roa.h"
#include "tao/boa.h"
#include "tao/cdr.h"
#include "tao/connect.h"
#include "tao/giop.h"
#include "tao/params.h"
#include "tao/orbobj.h"
#include "tao/nvlist.h"
#include "tao/debug.h"
#include "tao/Orb_Core.h"
#endif

#include "tao/corba.h"

// Forward declarations...
static void request_dispatcher (TAO_GIOP_RequestHeader &req,
				CDR &request_body,
				CDR *reply,
				TAO_Dispatch_Context *context,
				CORBA::Environment &env);

static TAO_GIOP_LocateStatusType request_forwarder (TAO_opaque &target_key,
                                                    CORBA::Object_ptr &forward_reference,
                                                    TAO_Dispatch_Context *ctx);

ROA_ptr
ROA::init (CORBA::ORB_ptr parent,
	   ACE_INET_Addr &,
	   CORBA::Environment &env)
{
  env.clear ();
  TAO_ORB_Core *p = TAO_ORB_CORE::instance();

  //    ACE_MT (ACE_GUARD (ACE_Thread_Mutex, roa_mon, lock_));

  if (p->root_poa ())
    {
      env.exception (new CORBA_INITIALIZE (CORBA::COMPLETED_NO));
      return 0;
    }

#if defined (ROA_NEEDS_REQ_KEY)
 (void) ACE_Thread::keycreate (&req_key_);
#endif /* ROA_NEEDS_REQ_KEY */
    
  ROA_ptr rp;
  ACE_NEW_RETURN (rp, ROA (parent, env), 0);
  p->root_poa (rp);

  return rp;
}

ROA::ROA (CORBA::ORB_ptr owning_orb,
	  CORBA::Environment &)
  : do_exit_ (CORBA::B_FALSE), 
    orb_ (owning_orb),
    call_count_ (0),
    skeleton_ (0)
{
  TAO_Server_Strategy_Factory *f = orb_->server_factory ();
  TAO_ORB_Core* p = TAO_ORB_CORE::instance ();
  
  this->objtable_ = f->create_object_table ();

  if (this->objtable_ != 0)
    p->root_poa (this);
}

ROA::~ROA (void)
{
}

// Generic routine to handle a message.

int
ROA::handle_message (TAO_Dispatch_Context &ctx,
		     CORBA::Environment &env)
{
  int result =
    TAO_GIOP::incoming_message (ctx.endpoint_,
                                TAO_GIOP_ForwardFunc (ctx.check_forward_ ? request_forwarder : 0),
                                TAO_GIOP_RequestHandler (request_dispatcher),
                                &ctx,
                                env);

  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, roa_mon, lock_, -1));

  call_count_--;

  return result;
}

// Create an objref

CORBA::Object_ptr
ROA::create (CORBA::OctetSeq &key,
             CORBA::String type_id,
             CORBA::Environment &env)
{
  CORBA::String id;
  IIOP_Object *data;

  if (type_id)
    id = CORBA::string_copy (type_id);
  else
    id = 0;

  IIOP::Version ver (IIOP::MY_MAJOR, IIOP::MY_MINOR);
  // Cast below de-warns on Sun's C++
  const ACE_INET_Addr& addr = orb_->params ()->addr ();
  CORBA::String h = (char*)addr.get_host_name ();

  data = new IIOP_Object (id, IIOP::ProfileBody (ver,
						 h,
						 addr.get_port_number (),
						 key));
  if (data != 0)
    env.clear ();
  else
    {
      env.exception (new CORBA_NO_MEMORY (CORBA::COMPLETED_NO));
      return 0;
    }

  // Return the CORBA::Object_ptr interface to this objref.
  CORBA::Object_ptr new_obj;

  if (data->QueryInterface (IID_CORBA_Object,
			    (void**)&new_obj) != NOERROR)
    env.exception (new CORBA::INTERNAL (CORBA::COMPLETED_NO));

  data->Release ();
  return new_obj;
}

// Return the key fed into an object at creation time.

CORBA::OctetSeq *
ROA::get_key (CORBA::Object_ptr,
	      CORBA::Environment &env)
{
  // XXX implement me ! ... must have been created by this OA.
  env.exception (new CORBA_IMP_LIMIT (CORBA::COMPLETED_NO));
  return 0;
}

#if defined (ROA_NEEDS_REQ_KEY)
// return the target's key
//
// NOTE: as with all "in" parameters to a call, this memory is freed
// by the ORB not by the object implementation.

CORBA::OctetSeq *
TCP_OA::get_target_key (CORBA::Environment &env)
{
  env.clear ();

  return &request_tsd->object_key;
}

// return the caller's principal
//
// NOTE: as with all "in" parameters to a call, this memory is freed
// by the ORB not by the object implementation.

CORBA::Principal_ptr
ROA::get_client_principal (CORBA::Environment &env)
{
  env.clear ();

  return request_tsd->requesting_principal;
}
#endif /* ROA_NEEd_REQ_KEY */

// Used by method code to ask the OA to shut down.
void
ROA::please_shutdown (CORBA::Environment &env)
{
  ACE_MT (ACE_GUARD (ACE_Thread_Mutex, roa_mon, lock_));

  env.clear ();
  do_exit_ = CORBA::B_TRUE;
}

// Used by non-method code to tell the OA to shut down.
void
ROA::clean_shutdown (CORBA::Environment &env)
{
  ACE_MT (ACE_GUARD (ACE_Thread_Mutex, roa_mon, lock_));

  env.clear ();

  if (call_count_ != 0)
    {
      dmsg ("called clean_shutdown with requests outstanding");
      env.exception (new CORBA::BAD_INV_ORDER (CORBA::COMPLETED_NO));
      return;
    }

  // Here we need to tell all the endpoints to shut down...
}

// For BOA -- BOA operations for which we provide the vtable entry

void
ROA::register_dir (CORBA::BOA::dsi_handler handler,
		   void *ctx, CORBA::Environment &env)
{
  if (handler == 0)
    {
      env.exception (new CORBA::BAD_PARAM (CORBA::COMPLETED_NO));
      return;
    }

  skeleton_ = handler;
  context_ = ctx;

  env.clear ();
}


// For COM -- IUnknown operations, we provide the vtable entry

// {A201E4C4-F258-11ce-9598-0000C07CA898}
DEFINE_GUID (IID_ROA,
0xa201e4c4, 0xf258, 0x11ce, 0x95, 0x98, 0x0, 0x0, 0xc0, 0x7c, 0xa8, 0x98);

ULONG __stdcall
ROA::AddRef (void)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, roa_mon, com_lock_, 0));
  return ++refcount_;
}

ULONG __stdcall
ROA::Release (void)
{
  {
    ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, roa_mon, com_lock_, 0));

    if (--refcount_ != 0)
      return refcount_;
  }

  delete this;
  return 0;
}

HRESULT __stdcall
ROA::QueryInterface (REFIID riid,
		     void **ppv)
{
  *ppv = 0;

  if (IID_ROA == riid
      || IID_BOA == riid
      || IID_IUnknown == riid)
    *ppv = this;

  if (*ppv == 0)
    return ResultFromScode (E_NOINTERFACE);

 (void) AddRef ();
  return NOERROR;
}

// Dispatch routine that provides most of the IIOP glue ... constructs
// a dynamic ServerRequest and any reply message that's needed.
// 
// Based on what this does, would it be make sense to move much of
// this functionality into a method on the OA that gets called by
// ROA_Handler::handle_input ()?

static void
request_dispatcher (TAO_GIOP_RequestHeader &req,
		    CDR &request_body,
		    CDR *reply,
		    TAO_Dispatch_Context *helper,
		    CORBA::Environment &env)
{
  TAO_ORB_Core *p = TAO_ORB_CORE::instance();
  IIOP_ServerRequest svr_req (&request_body,
			      p->orb (),
			      p->root_poa ());

  // ServerRequest is what does the unmarshaling, driven by typecodes
  // that the DSI user provides.  Create the ServerRequest, store away
  // information that'll be needed by some methods, and call the
  // dispatch routine that the user supplied.  Then release the
  // reference so it can be safely destroyed sometime later.
  //
  svr_req._opname = req.operation;

#if defined (ROA_NEEDS_REQ_KEY)
 (void) ACE_Thread::setspecific (p->root_poa ().req_key_, &req);
#endif /* ROA_NEEDS_REQ_KEY */

  CORBA::BOA_ptr oa = p->root_poa ();
  CORBA::BOA::dsi_handler ptmf = helper->skeleton_;
 (oa->*ptmf) (req.object_key, svr_req, helper->context_, env);
  // is this the correct way to do it? skeleton is a member function

  svr_req.release ();

  // If reply is null, this was a oneway request ... return!
  if (reply == 0)
    return;

  // Otherwise check for correct parameter handling, and reply as
  // appropriate.
  //
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

  if (!svr_req._params && env.exception () == 0) 
    {
      dmsg ("DSI user error, didn't supply params");
      env.exception (new CORBA::BAD_INV_ORDER (CORBA::COMPLETED_NO));
    }

  if (env.exception () != 0) 
    {	// standard exceptions only
      CORBA::Environment	env2;
      CORBA::Exception *x = env.exception ();
      CORBA::TypeCode_ptr except_tc = x->type ();

      reply->put_ulong (TAO_GIOP_SYSTEM_EXCEPTION);
      (void) reply->encode (except_tc, x, 0, env2);
    }
  else if (svr_req._exception)
    {	// any exception at all
      CORBA::Exception *x;
      CORBA::TypeCode_ptr except_tc;

      x = (CORBA::Exception *) svr_req._exception->value ();
      except_tc = svr_req._exception->type ();

      // Finish the GIOP Reply header, then marshal the exception.
      //
      // XXX x->type () someday ...
      if (svr_req._ex_type == CORBA::SYSTEM_EXCEPTION)
	reply->put_ulong (TAO_GIOP_SYSTEM_EXCEPTION);
      else
	reply->put_ulong (TAO_GIOP_USER_EXCEPTION);

      (void) reply->encode (except_tc, x, 0, env);
    }
  else
    {				// normal reply
      // First finish the GIOP header ...
      reply->put_ulong (TAO_GIOP_NO_EXCEPTION);

      // ... then send any return value ...
      if (svr_req._retval)
	{
	  tc = svr_req._retval->type ();
	  value = svr_req._retval->value ();
	  (void) reply->encode (tc, value, 0, env);
	}

      // ... followed by "inout" and "out" parameters, left to right
      for (u_int i = 0; i < svr_req._params->count (); i++)
	{
	  CORBA::NamedValue_ptr	nv = svr_req._params->item (i);
	  CORBA::Any_ptr any;

	  if (!(nv->flags () & (CORBA::ARG_INOUT|CORBA::ARG_OUT)))
	    continue;

	  any = nv->value ();
	  tc = any->type ();
	  value = any->value ();
	  (void) reply->encode (tc, value, 0, env);
	}
    }
}

// Helper routine that provides IIOP glue for forwarding requests to
// specific objects from one process to another.

static TAO_GIOP_LocateStatusType
request_forwarder (TAO_opaque &target_key,
		   CORBA::Object_ptr &forward_reference,
		   TAO_Dispatch_Context *helper)
{
  CORBA::Environment env;

  assert (helper->check_forward_ != 0);
  helper->check_forward_ (target_key, forward_reference, helper->context_, env);

  if (env.exception () != 0)
    return TAO_GIOP_UNKNOWN_OBJECT;
  else if (forward_reference == 0)
    return TAO_GIOP_OBJECT_HERE;
  else
    return TAO_GIOP_OBJECT_FORWARD;
}

#if !defined (__ACE_INLINE__)
#  include "roa.i"
#endif /* __ACE_INLINE__ */
