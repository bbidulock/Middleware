// @(#)tcpoa.cpp	1.16 95/11/04
// Copyright 1994-1995 by Sun Microsystems Inc.
// All Rights Reserved
//
// IIOP:	Small "TCP OA", thinly layered atop IIOP.
//
// Like all OAs, this provides an object creation facility and a simple
// DSI-based operation dispatch facility.  However, it's so simple it
// doesn't do any more than that!  In particular, it maintains no per-object
// state either on disk or in memory.
//
// NOTE:  It's undesirable in firewall and threaded environments to continue
// with the current restriction of only one OA per process.
//

#include	<assert.h>
#include	<stdio.h>
#include	<string.h>

#if	unix
#include	<unistd.h>
#include	<netdb.h>

#else
#include	<winsock.h>

#endif

#include	<orb.hh>
#include	<toa.hh>

#include	"thread.hh"
#include	"cdr.hh"
#include	"debug.hh"

#include "connmgr.hh"
#include	"tcpoa.hh"
#include	"giop.hh"
#include	"svrrqst.hh"
#include "roa.hh"

#include	<initguid.h>

static TCP_OA		*the_oa;

#ifdef _POSIX_THREADS
static pthread_key_t	request_key;
static pthread_mutex_t	tcpoa_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t	tcpoa_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_attr_t	thread_attr;
#endif	// _POSIX_THREADS

//
// Dispatch routine that provides most of the IIOP glue ... constructs
// a dynamic ServerRequest and any reply message that's needed.
//
static void
tcp_oa_dispatcher (
    GIOP::RequestHeader		&req,
    CDR				&request_body,
    CDR				*reply,
    void			*context,
    CORBA_Environment		&env
)
{
  IIOP_ServerRequest svr_req (&request_body,
			      the_oa->orb (),
			      the_oa);

  //
  // ServerRequest is what does the unmarshaling, driven by typecodes
  // that the DSI user provides.  Create the ServerRequest, store away
  // information that'll be needed by some methods, and call the dispatch
  // routine that the user supplied.  Then release the reference so it
  // can be safely destroyed sometime later.
  //
  svr_req._opname = req.operation;

#ifdef	_POSIX_THREADS
  (void) pthread_setspecific (request_key, &req);
#else
  request_tsd = &req;
#endif	// _POSIX_THREADS

  TCP_OA::dispatch_context* helper;

  helper = (TCP_OA::dispatch_context*) context;
  helper->skeleton (req.object_key, svr_req, helper->context, env);

  svr_req.release ();

  //
  // If reply is null, this was a oneway request ... return!
  //
  if (reply == 0)
    return;

  //
  // Otherwise check for correct parameter handling, and reply as
  // appropriate.
  //
  // NOTE:  if "env" is set, it takes precedence over exceptions
  // reported using the mechanism of the ServerRequest.  Only system
  // exceptions are reported that way ...
  //
  // XXX  Exception reporting is ambiguous; it can be cleaner than
  // this.  With both language-mapped and dynamic/explicit reporting
  // mechanisms, one of must be tested "first" ... so an exception
  // reported using the other mechanism could be "lost".  Perhaps only
  // the language mapped one should be used for system exceptions.
  //
  CORBA_TypeCode_ptr		tc;
  const void			*value;

  if (!svr_req._params && env.exception () == 0) {
    dmsg ("DSI user error, didn't supply params");
    env.exception (new CORBA_BAD_INV_ORDER (COMPLETED_NO));
  }

  if (env.exception () != 0) {	// standard exceptions only
    CORBA_Environment	env2;
    CORBA_Exception		*x = env.exception ();
    CORBA_TypeCode_ptr	except_tc = x->type ();

    reply->put_ulong (GIOP::SYSTEM_EXCEPTION);
    (void) CDR::encoder (except_tc, x, 0, reply, env2);
	
  } else if (svr_req._exception) {	// any exception at all
    CORBA_Exception		*x;
    CORBA_TypeCode_ptr	except_tc;

    x = (CORBA_Exception *) svr_req._exception->value ();
    except_tc = svr_req._exception->type ();

    //
    // Finish the GIOP Reply header, then marshal the exception.
    //
    // XXX x->type() someday ...
    //
    if (svr_req._ex_type == SYSTEM_EXCEPTION)
      reply->put_ulong (GIOP::SYSTEM_EXCEPTION);
    else
      reply->put_ulong (GIOP::USER_EXCEPTION);

    (void) CDR::encoder (except_tc, x, 0, reply, env);

  } else {				// normal reply
    //
    // First finish the GIOP header ...
    //
    reply->put_ulong (GIOP::NO_EXCEPTION);

    //
    // ... then send any return value ...
    //
    if (svr_req._retval) {
      tc = svr_req._retval->type ();
      value = svr_req._retval->value ();
      (void) CDR::encoder (tc, value, 0, reply, env);
    }

    //
    // ... followed by "inout" and "out" parameters, left to right
    //
    unsigned			i;

    for (i = 0; i < svr_req._params->count (); i++) {
      CORBA_NamedValue_ptr	nv = svr_req._params->item (i);
      CORBA_Any_ptr		any;

      if (!(nv->flags () & (CORBA_ARG_INOUT|CORBA_ARG_OUT)))
	continue;

      any = nv->value ();
      tc = any->type ();
      value = any->value ();
      (void) CDR::encoder (tc, value, 0, reply, env);
    }
  }
}

//
// Helper routine that provides IIOP glue for forwarding requests
// to specific objects from one process to another.
//
static GIOP::LocateStatusType
tcp_oa_forwarder (
    opaque			&target_key,
    CORBA_Object_ptr		&forward_reference,
    void			*ctx
)
{
    TCP_OA::dispatch_context	*helper;
    CORBA_Environment		env;

    helper = (TCP_OA::dispatch_context *) ctx;
    assert (helper->check_forward != 0);
    helper->check_forward (target_key, forward_reference, helper->context, env);

    if (env.exception () != 0)
	return GIOP::UNKNOWN_OBJECT;
    else if (forward_reference == 0)
	return GIOP::OBJECT_HERE;
    else
	return GIOP::OBJECT_FORWARD;
}


TCP_OA::TCP_OA (CORBA_ORB_ptr owning_orb,
		ACE_INET_Addr& rendesvous,
		CORBA_Environment &env)
  : do_exit(CORBA_B_FALSE), 
    _orb(owning_orb), call_count(0), skeleton(0)
{
  assert (the_oa == 0); 

  //
  // Initialize the endpoint ... or try!
  //
  if (clientAcceptor_.open(rendesvous, ACE_ROA::reactor()) == -1)
    {
      // XXXCJC Need to return an error somehow!!
    }

  else if (ACE_ROA::reactor()->register_handler(&clientAcceptor_,
					    ACE_Event_Handler::ACCEPT_MASK) == -1)
    {
      // XXXCJC Need to return an error somehow!!
    }
  
  clientAcceptor_.acceptor().get_local_addr(addr);

  if (env.exception () != 0)  {
    dmsg2 ("TCP OA:  '%s', port %u", namebuf, port);
    the_oa = this;
  }
}

TCP_OA::~TCP_OA ()
{
}


//
// Public initialisation routine for this OA.
// XXX This should really be scoped as CORBA_TCP_OA_init()!!!!!  -cjc

//
TCP_OA_ptr
TCP_OA::init (CORBA_ORB_ptr parent,
	      ACE_INET_Addr& rendesvous,
	      CORBA_Environment& env)
{
    env.clear ();

#ifdef	_POSIX_THREADS
    Critical		region (&tcpoa_mutex);
#endif	// _POSIX_THREADS

    if (the_oa) {
	env.exception (new CORBA_INITIALIZE (COMPLETED_NO));
	return 0;
    }

#ifdef	_POSIX_THREADS

    //
    // Initialize POSIX thread stuff:  TSD key for request data, and
    // attributes for threads that can be dynamically created.
    //
    // XXX this stuff should be guarded by "pthread_once", it's not
    // at all OA-specific.
    //
    (void) pthread_key_create (&request_key, 0);

    (void) pthread_attr_init (&thread_attr);
    (void) pthread_attr_setdetachstate (&thread_attr, PTHREAD_CREATE_DETACHED);

#ifdef	_POSIX_THREAD_PRIORITY_SCHEDULING
    (void) pthread_attr_setscope (&thread_attr, PTHREAD_SCOPE_PROCESS);
#endif	// _POSIX_THREAD_PRIORITY_SCHEDULING

#endif	// _POSIX_THREADS

    the_oa = new TCP_OA (parent, rendesvous, env);

    return the_oa;
}


//
// Create an objref
//
CORBA_Object_ptr
__stdcall
TCP_OA::create (
    CORBA_OctetSeq	_FAR &key,
    CORBA_String	_FAR type_id,
    CORBA_Environment	_FAR &env
)
{
    CORBA_String	id;
    IIOP_Object		*data;

    if (type_id)
	id = CORBA_string_copy (type_id);
    else
	id = 0;
    data = new IIOP_Object (id);

    if (data != 0)
	env.clear ();
    else {
	env.exception (new CORBA_NO_MEMORY (COMPLETED_NO));
	return 0;
    }

    data->profile.iiop_version.major = IIOP::MY_MAJOR;
    data->profile.iiop_version.minor = IIOP::MY_MINOR;
    data->profile.host = ACE_OS::strdup(addr.get_host_name());
    data->profile.port = addr.get_port_number();
    data->profile.object_key.length =  key.length;
    data->profile.object_key.maximum = key.length;
    data->profile.object_key.buffer = new CORBA_Octet [(size_t) key.length];

    //
    // Verify the memory allocations we just did ...
    //
    if (data->profile.host == 0 || data->profile.object_key.buffer == 0) {
	env.exception (new CORBA_NO_MEMORY (COMPLETED_NO));
	data->Release ();
	return 0;
    }

    ACE_OS::memcpy (data->profile.object_key.buffer, key.buffer, (size_t) key.length);

    //
    // Return the CORBA_Object_ptr interface to this objref.
    //
    CORBA_Object_ptr		new_obj;

    if (data->QueryInterface (IID_CORBA_Object, (void **)&new_obj)
	    != NOERROR) {
	env.exception (new CORBA_INTERNAL (COMPLETED_NO));
    }
    data->Release ();
    return new_obj;
}


//
// Return the key fed into an object at creation time.
//
CORBA_OctetSeq *
__stdcall
TCP_OA::get_key (
    CORBA_Object_ptr	,
    CORBA_Environment	&env
)
{
    // XXX implement me ! ... must have been created by this OA.
    env.exception (new CORBA_IMP_LIMIT (COMPLETED_NO));
    return 0;
}


#ifdef	_POSIX_THREADS
//
// Use the TSD key set up as part of OA initialization to get the
// thread-specific data describing this invocation
//
#define	request_tsd \
	((GIOP::RequestHeader *) pthread_getspecific (request_key))

#else

//
// This emulates "thread specific data" to hold data about the request
// that the thread is processing.  It needs to be accessed for a variety
// of purposes in the course of request processing.
//
static GIOP::RequestHeader	*request_tsd;
#endif	// _POSIX_THREADS


//
// Return the objref which is target of the call.  This must be freed
// by whoever calls the routine.
//
// XXX should be consistent with other explicit/implicit request data
// and have the ORB free it when the call returns; that'll let the cost
// of the four mallocs (yeech!) be amortized over more work.
//
// XXX there's no way to report exceptions here ...
//
CORBA_Object_ptr
__stdcall
_this ()
{
    IIOP_Object			*data;
    opaque			*key = &request_tsd->object_key;

    //
    // NOTE:  The "TCP_OA" can't return the type ID of this object
    // since it has no persistent storage.  The expectation is that
    // code layered on top of this OA, providing whatever storage is
    // needed and defining their own policies for object keys, will be
    // built on top of this interface; their implementations of the
    // "_this()" routine will return a full objref (and also be able
    // to answer questions like whether it _is_a given type).
    //
    if ((data = new IIOP_Object (0)) == 0) {	// null type ID
	return 0;
    }

    data->profile.iiop_version.major = IIOP::MY_MAJOR;
    data->profile.iiop_version.minor = IIOP::MY_MINOR;
    data->profile.object_key.length =  key->length;
    data->profile.object_key.maximum = key->length;
    data->profile.object_key.buffer = new CORBA_Octet [(size_t) key->length];
    ACE_OS::memcpy (data->profile.object_key.buffer, key->buffer, (size_t) key->length);

    if (data->profile.host == 0 || data->profile.object_key.buffer == 0) {
	data->Release ();
	return 0;
    }

    //
    // Return the CORBA_Object_ptr interface to this objref.
    //
    CORBA_Object_ptr		new_obj;

    (void) data->QueryInterface (IID_CORBA_Object, (void **)&new_obj);
    data->Release ();
    return new_obj;
}


//
// return the target's key
//
// NOTE:  as with all "in" parameters to a call, this memory is freed
// by the ORB not by the object implementation.
//
CORBA_OctetSeq *
__stdcall
TCP_OA::get_target_key (
    CORBA_Environment		&env
)
{
    env.clear ();

    return &request_tsd->object_key;
}


//
// return the caller's principal
//
// NOTE:  as with all "in" parameters to a call, this memory is freed
// by the ORB not by the object implementation.
//
CORBA_Principal_ptr
__stdcall
TCP_OA::get_client_principal (
    CORBA_Environment		&env
)
{
    env.clear ();

    return request_tsd->requesting_principal;
}

//
// Generic routine to handle a message.
//
void
TCP_OA::handle_message (dispatch_context& ctx, CORBA_Environment& env)
{
  GIOP::incoming_message (ctx.endpoint,
			  ctx.check_forward ? tcp_oa_forwarder : 0,
			  tcp_oa_dispatcher, &ctx, env);

#ifdef	_POSIX_THREADS
  Critical region (&tcpoa_mutex);
#endif	// _POSIX_THREADS

  call_count--;
}


#ifdef	_POSIX_THREADS
//
// For cases where the OA creates new threads to handle messages (which
// are typically, but not always, GIOP::Request messages) we need to have
// a routine for that new thread to execute.  This is that routine:  its
// role is only to set up to call the common "handle_message" routine,
// knowing that it's not the thread which was initially handed the message.
//
// In "aggressive" threading mode, it continues reading from the connection
// until the connection goes away (e.g. client goes away, or server does
// its shutdown work).  This is a big win.
//
// XXX this needs to set up so it goes away with pthread_cancel().  We
// lack any kind of "timed read" primitive so the best we could otherwise
// do is to select (with timeout) before issuing the read, possibly with
// a switch to another thread in between.
//
void *
TCP_OA::worker (void *arg)
{
    CORBA_Environment		env;
    dispatch_context		*context = (dispatch_context *)arg;

    do {
	dmsg1 ("worker starting on FD %d", context->endpoint->fd);
	context->oa->handle_message (*context, env);

	if (env.exception () != 0) {
	    dexc (env, "TCP_OA, worker");
	    env.clear ();
	}
    } while (context->aggressive && context->endpoint != -1);

    delete context;
    return 0;
}
#endif	// _POSIX_THREADS


//
// Block till some request comes in, and call "skeleton" when it does.
// Uses helper routines above to do most of the work.
//
// THREADING NOTE:  Only one thread may call this at a time, due to some
// underlying issues with select().  If you want a model wherein a finite
// pool of threads handles your requests, this doesn't do that.  (This is
// probably a good thing:  it's all but impossible to accurately bound the
// number of concurrent requests any given server will need to handle.)
//
void
__stdcall
TCP_OA::get_request (
    TOA::dsi_handler	handler,
    void		check_forward (
	CORBA_OctetSeq	&key,
	CORBA_Object_ptr	&fwd_ref,
	void			*ctx,
	CORBA_Environment	&env
    ),
    CORBA_Boolean	do_thr_create,
    void		*app_state,
    timeval		*timeout,
    CORBA_Environment	&env
)
{
    server_endpoint	*fd;

    env.clear ();

    //
    // Two bits of OA-private state need to be guarded by a critical
    // region:  the "do_exit" flag, and the "call_count" flag.  These
    // are used in clean shutdown, and can be modified here.
    //
    {
#ifdef	_POSIX_THREADS
    	Critical		region (&tcpoa_mutex);
#endif	// _POSIX_THREADS

	//
	// Applications sometimes make mistakes:  here, it'd be
	// polling for a new request after initiating shutdown.
	//
	if (do_exit) {
	    dmsg ("called get_request during OA shutdown");
	    env.exception (new CORBA_BAD_INV_ORDER (COMPLETED_NO));
	    return;
	}

#ifndef	_POSIX_THREADS
	//
	// Here, some unthreaded app asked for thread support.  Ooops!
	//
	if (do_thr_create) {
	    env.exception (new CORBA_IMP_LIMIT (COMPLETED_NO));
	    dexc (env, "TCP_OA, unthreaded: can't create worker threads");
	    return;
	}
#endif	// _POSIX_THREADS

	//
	// Get a request/message ... if no file descriptor is returned,
	// the application-specified timeout was reached, leading to a
	// clean shutdown.  Otherwise we flag an incoming message (so
	// shutdown will know it can't start yet), and leave the critical
	// section.  Some other thread could now get a request on some
	// other connection, if one's ready.
	//
	// THREADING NOTE:  what block_for_connection() returns will not
	// be read or written by any other thread until it's released ...
	// that is, until "fd" goes out of scope.  At least, in the
	// current implementation, which doesn't let threads share a
	// connection.
	//
	// Also, note that the underlying constraint of only allowing a
	// single thread to block_for_connection() call bubbles up here too.
	//
#ifdef	_POSIX_THREADS
	static int		blocking;	// = 0

	if (blocking) {
	    dmsg ("concurrent TCP_OA::get_request() calls");
	    env.exception (new CORBA_IMP_LIMIT (COMPLETED_NO));
	    return;
	} else
	    blocking = 1;

	region.leave ();
#endif	// _POSIX_THREADS

	//
	// Get a connection and hand it to method code.
	//
	// There are four "threading modes" currently possible with
	// this software, though only two are exposed in the OA API.
	//
	//	- Single-Threaded ... where either no threads are
	//	  used, or method code only sees one thread.
	//
	//	- Simple MT ... like single threaded, except that
	//	  (a) method code can see multiple threads, (b) a thread
	//	  context switch happens before incoming methods get
	//	  processed, and (c) there's expensive handshaking re
	//	  connections when they're released.
	//
	//	- "Eager" MT ... like simple MT, except that the context
	//	  switch (b) is gone, and incoming data is handled right
	//	  away by a thread that's always blocked in a read.  The
	//	  initial request latency is lower than "Simple MT".
	//
	//	- "Aggressive" MT ... like "eager" MT except that the
	//	  costly handshaking (c) is removed along with thread
	//	  creation costs.  Throughput is higher than with any
	//	  of the other models, since it's not just initial
	//	  requests which benefit from reduced latency and
	//	  since overall MT-related costs are minimized.
	//
	// To the application, only "single threaded" and "MT" policies
	// are exposed ... the rest is implementation details, all they
	// really care about is whether method code seems multiple threads
	// and the quality of the implementation (size, speed, etc).
	//
	// XXX Right now we equate "MT" to "Aggressive", despite problems.
	// If clients behave well, they're not an issue; in real systems,
	// we know clients don't always behave.
	//
	// One forward-looking way is to use pthread_cancel to kill idle
	// workers ... that looks forward to a later implementation which
	// always has a read outstanding on a connection, and so can also
	// handle GIOP::CancelRequest messages.
	//

#if 0
	fd = endpoint->block_for_connection (do_thr_create, timeout, env);
#endif

#ifdef	_POSIX_THREADS
	region.enter ();
	blocking = 0;
#endif	// _POSIX_THREADS

	if (env.exception () != 0) {
	    dexc (env, "TCP_OA, block for connection");
	    return;
	}
	if (fd == 0) {
	    do_exit = CORBA_B_TRUE;
	    return;
	}

	//
	// THREADING NOTE:  This is the last of the need to have the OA
	// locked ... next, let other threads in to access its state.
	//
	call_count++;
    }

    //
    // OK, now we've got a connection with a "live" IIOP message ready.
    //
    // If we're "eager", there's not actually any data on that connection
    // yet ... but we still hand it to some other thread as if it were
    // all there.  This gets all the setup out of the critical path so that
    // when data does arrive, its latency is minimal:  straight into the
    // IIOP data buffer, in the best (zero copy) case, with no lingering in
    // kernel read queues.
    //
    if (do_thr_create) {
#ifdef	_POSIX_THREADS
	//
	// Want to handle it in another thread.  That means handing off a
	// bunch of information to that thread and then having it do the
	// work ... the simplest alternative is to heap-allocate the data
	// and hand it over.  That involves no handshaking with the thread
	// we're about to create.  Note that we're also handing off the
	// connection resource too -- when this dispatch context gets
	// destroyed, only then is the connection released.
	//
	dispatch_context		*ctx;

	ctx = new dispatch_context;
	ctx->skeleton = handler;
	ctx->check_forward = check_forward;
	ctx->context = app_state;
	ctx->oa = this;
#if 0 // g++ didn't complain about this, but Sun C++ does
	ctx->endpoint = fd;
#endif
	ctx->aggressive = do_thr_create;

	//
	// Actually create the thread.
	//
	int				errcode;
	pthread_t			tid;

	// XXX Devpro bug at "-O3"
	void *(*func)(void *)		= worker;

	errcode = pthread_create (&tid, &thread_attr, func, ctx);

	if (errcode == 0)
	    return;

	//
	// Can't create a thread as requested.  Rather than handling it
	// in another thread, we must then handle it ourselves.  It's bad
	// news to drop requests, as would happen if we were to just
	// report an exception.
	//
	// XXX this should be logged as some kind of system fault;
	// an administrator would need to deal with these failures
	// if they happen repatedly.
	//
	dmsg2 ("pthread_create error: %d (%s)", errcode,
		strerror (errcode));
	delete context;

#endif	// _POSIX_THREADS
    }

    //
    // Handle it in this thread.  We can do it without any need
    // to dynamically allocate memory.
    //
    dispatch_context		ctx;

    ctx.skeleton = handler;
    ctx.check_forward = check_forward;
    ctx.context = app_state;
    ctx.oa = this;
#if 0 // g++ didn't complain about this assignment, but Sun C++ does
    ctx.endpoint = fd;
#endif

#ifdef	_POSIX_THREADS
    ctx.aggressive = CORBA_B_FALSE;
#endif

    handle_message (ctx, env);

    //
    // Don't report any errors from the application/skeleton back to the
    // top level ... the application already has a variety of means to
    // pass whatever data needs passing, and we don't need to confuse
    // things by mixing ORB and application errors here.
    //
    if (env.exception () != 0) {
	dexc (env, "TCP_OA, handle incoming message");
	env.clear ();
    }
}


//
// Used by method code to ask the OA to shut down.
//
void
__stdcall
TCP_OA::please_shutdown (
    CORBA_Environment	&env
)
{
#ifdef	_POSIX_THREADS
    Critical		region (&tcpoa_mutex);
#endif	// _POSIX_THREADS

    env.clear ();
    do_exit = CORBA_B_TRUE;
}

//
// Used by non-method code to tell the OA to shut down.
//
void
__stdcall
TCP_OA::clean_shutdown (
    CORBA_Environment	&env
)
{
#ifdef	_POSIX_THREADS
    Critical		region (&tcpoa_mutex);
#endif	// _POSIX_THREADS

    env.clear ();

    if (call_count != 0) {
	dmsg ("called clean_shutdown with requests outstanding");
	env.exception (new CORBA_BAD_INV_ORDER (COMPLETED_NO));
	return;
    }

#if 0
    endpoint->shutdown_connections (GIOP::close_connection, 0);
    endpoint = 0;
#endif
}


//
// For TOA -- TOA operations for which we provide the vtable entry
//

void
__stdcall
TCP_OA::register_dir (
    TOA::dsi_handler	handler,
    void		*ctx,
    CORBA_Environment	&env
)
{
    if (handler == 0) {
	env.exception (new CORBA_BAD_PARAM (COMPLETED_NO));
	return;
    }

    skeleton = handler;
    context = ctx;

    env.clear ();
}

void
__stdcall
TCP_OA::get_request  (
    CORBA_Boolean	use_threads,
    struct timeval	*tvp,
    CORBA_Environment	&env
)
{
    //
    // API spec calls for the DIR to be registered and for this to
    // report an invocation order problem if this is called after
    // shutdown was started (app can always avoid the latter).
    //
    if (skeleton == 0) {
	env.exception (new CORBA_INITIALIZE (COMPLETED_NO));
	return;
    }

    //
    // Just call the IIOP level dispatch code without allowing it to
    // ever forward requests to another TCP_OA.
    //
    get_request (skeleton, 0, use_threads, context, tvp, env);
}


//
// For COM -- IUnknown operations, we provide the vtable entry
//

// {A201E4C4-F258-11ce-9598-0000C07CA898}
DEFINE_GUID (IID_TCP_OA,
0xa201e4c4, 0xf258, 0x11ce, 0x95, 0x98, 0x0, 0x0, 0xc0, 0x7c, 0xa8, 0x98);


ULONG
__stdcall
TCP_OA::AddRef ()
{
#ifdef	_POSIX_THREADS
    Critical		region (&tcpoa_lock);
#endif

    return ++refcount;
}

ULONG
__stdcall
TCP_OA::Release ()
{
#ifdef	_POSIX_THREADS
    Critical		region (&tcpoa_lock);
#endif

    if (--refcount != 0)
	return refcount;

#ifdef	_POSIX_THREADS
    region.leave ();
#endif

    delete this;
    return 0;
}

HRESULT
__stdcall
TCP_OA::QueryInterface (
    REFIID	riid,
    void	**ppv
)
{
    *ppv = 0;

    if (IID_TCP_OA == riid
	    || IID_TOA == riid
	    || IID_IUnknown == riid)
	*ppv = this;

    if (*ppv == 0)
	return ResultFromScode (E_NOINTERFACE);

    (void) AddRef ();
    return NOERROR;
}
