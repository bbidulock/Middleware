// TS_Server_Handler.cpp
// $Id$

#define ACE_BUILD_SVC_DLL
#include "ace/SString.h"
#include "ace/Set.h"
#include "ace/Get_Opt.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_Stream.h"
#include "ace/Time_Request_Reply.h"
#include "TS_Server_Handler.h"

class ACE_Svc_Export ACE_TS_Server_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
  // = TITLE
  //    Product object created by <ACE_TS_Server_Acceptor>.
  //
  // = DESCRIPTION
{
  friend class ACE_Shutup_GPlusPlus;  // Turn off g++ warning
public:
  // = Initialization and termination.

  ACE_TS_Server_Handler (ACE_Thread_Manager * = 0);
  // Default constructor.

  virtual int open (void * = 0);
  // Activate this instance of the <ACE_TS_Server_Handler> (called by the
  // <ACE_Strategy_Acceptor>).

  ~ACE_TS_Server_Handler (void);
  // Must be allocated dynamically.

protected:
  // = Helper routines for the operations exported to clients.

  virtual int abandon (void);
  // Give up waiting (e.g., when a timeout occurs or a client shuts
  // down unexpectedly).

  // = Low level routines for framing requests, dispatching
  // operations, and returning replies.

  virtual int recv_request (void);
  // Receive, frame, and decode the client's request.
  
  virtual int dispatch (void);
  // Dispatch the appropriate operation to handle the client's
  // request.
  
  virtual int send_request (ACE_Time_Request &);
  // Special kind of reply

  // = Demultiplexing hooks.
  virtual ACE_HANDLE get_handle (void) const;
  // Return the underlying <ACE_HANDLE>.

  virtual int handle_input (ACE_HANDLE);
  // Callback method invoked by the <ACE_Reactor> when client events
  // arrive.

  // = Timer hook.
  virtual int handle_timeout (const ACE_Time_Value &tv, const void *arg);
  // Enable clients to limit the amount of time they wait.

private:
  ACE_Time_Request time_request_;
  // Cache request from the client.

  ACE_INET_Addr addr_;
  // Address of client we are connected with.
};

class ACE_TS_Server_Acceptor : public ACE_Strategy_Acceptor<ACE_TS_Server_Handler, ACE_SOCK_ACCEPTOR>
  // = TITLE
  //     This class contains the service-specific methods that can't
  //     easily be factored into the <ACE_Strategy_Acceptor>.
{
public:
  virtual int init (int argc, char *argv[]);
  // Dynamic linking hook.

  int parse_args (int argc, char *argv[]);
  // Parse svc.conf arguments.

private:
  ACE_Schedule_All_Reactive_Strategy<ACE_TS_Server_Handler> scheduling_strategy_;
  // The scheduling strategy is designed for Reactive services.
};

int
ACE_TS_Server_Acceptor::parse_args (int argc, char *argv[])
{
  ACE_TRACE ("ACE_TS_Server_Acceptor::parse_args");

  this->service_port_ = ACE_DEFAULT_SERVER_PORT;

  ACE_LOG_MSG->open ("Time Service");

  ACE_Get_Opt get_opt (argc, argv, "p:", 0);

  for (int c; (c = get_opt ()) != -1; )
    {
      switch (c)
	{
	case 'p':
	  this->service_port_ = ACE_OS::atoi (get_opt.optarg);
	  break;
	default:
	  ACE_ERROR_RETURN ((LM_ERROR, 
			    "%n:\n[-p server-port]\n%a", 1),
			   -1);
	  break;
	}
    }
  this->service_addr_.set (this->service_port_);
  return 0;
}

int
ACE_TS_Server_Acceptor::init (int argc, char *argv[])
{
  ACE_TRACE ("ACE_TS_Server_Acceptor::init");

  // Use the options hook to parse the command line arguments and set
  // options.
  this->parse_args (argc, argv);

  // Set the acceptor endpoint into listen mode (use the Singleton
  // global Reactor...).
  if (this->open (this->service_addr_, ACE_Service_Config::reactor (),
		  0, 0, 0, 
		  &this->scheduling_strategy_,
		  "Time Server", "ACE time service") == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%n: %p on port %d\n", 
		       "acceptor::open failed", 
		       this->service_addr_.get_port_number ()), -1);

  // Register ourselves to receive SIGINT so we can shutdown
  // gracefully.
  if (this->reactor ()->register_handler (SIGINT, this) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%n: %p\n", 
		      "register_handler (SIGINT)"), -1);

  // Ignore SIGPIPE so that each <SVC_HANDLER> can handle this on its
  // own.
  ACE_Sig_Action sig ((ACE_SignalHandler) SIG_IGN, SIGPIPE);
  ACE_UNUSED_ARG (sig);

  ACE_INET_Addr server_addr;

  // Figure out what port we're really bound to.
  if (this->acceptor ().get_local_addr (server_addr) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "get_local_addr"), -1);
    
  ACE_DEBUG ((LM_DEBUG, 
	      "starting up Time Server at port %d on handle %d\n", 
	     server_addr.get_port_number (),
	     this->acceptor ().get_handle ()));
  return 0;
}

// The following is a "Factory" used by the ACE_Service_Config and
// svc.conf file to dynamically initialize the state of the Time Server

ACE_SVC_FACTORY_DEFINE (ACE_TS_Server_Acceptor)

// Default constructor.
ACE_TS_Server_Handler::ACE_TS_Server_Handler (ACE_Thread_Manager *tm)
  : ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> (tm)
{
  ACE_TRACE ("ACE_TS_Server_Handler::ACE_TS_Server_Handler");
}

// Activate this instance of the ACE_TS_Server_Handler (called by the
// ACE_TS_Server_Acceptor).

/* VIRTUAL */ int 
ACE_TS_Server_Handler::open (void *)
{
  ACE_TRACE ("ACE_TS_Server_Handler::open");

  ACE_INET_Addr client_addr;

  // Determine the address of the client and display it.
  if (this->peer ().get_remote_addr (client_addr) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "get_remote_addr"), -1);

  ACE_DEBUG ((LM_DEBUG, "(%t) accepted connection from host %s on fd %d\n",
	      client_addr.get_host_name (), this->peer ().get_handle ()));

  // Call down to our parent to register ourselves with the Reactor.
  if (ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>::open (0) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "open"), -1);
  return 0;
}

/* VIRTUAL */ int
ACE_TS_Server_Handler::send_request (ACE_Time_Request &request)
{
  ACE_TRACE ("ACE_TS_Server_Handler::send_request");
  void    *buffer;
  ssize_t length = request.encode (buffer);
 
  if (length == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "encode failed"), -1);
 
  // Transmit request via a blocking send.
 
  if (this->peer ().send_n (buffer, length) != length)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "send_n failed"), -1);

  return 0;
}

// Give up waiting (e.g., when a timeout occurs or a client shuts down
// unexpectedly).
 
/* VIRTUAL */ int
ACE_TS_Server_Handler::abandon (void)
{
  ACE_TRACE ("ACE_TS_Server_Handler::abandon");

  // Note we are using the time field to report the errno in case of
  // failure. 
  ACE_Time_Request rq (ACE_Time_Request::FAILURE, errno);
  return this->send_request (rq);
}

// Enable clients to limit the amount of time they'll wait
/* VIRTUAL */ int
ACE_TS_Server_Handler::handle_timeout (const ACE_Time_Value &, const void *)
{
  ACE_TRACE ("ACE_TS_Server_Handler::handle_timeout");
  return this->abandon ();
}

// Return the underlying ACE_HANDLE.

/* VIRTUAL */ ACE_HANDLE 
ACE_TS_Server_Handler::get_handle (void) const
{
  ACE_TRACE ("ACE_TS_Server_Handler::get_handle");
  return this->peer ().get_handle ();
}

// Dispatch the appropriate operation to handle the client request.

/* VIRTUAL */ int 
ACE_TS_Server_Handler::dispatch (void)
{
  ACE_TRACE ("ACE_TS_Server_Handler::dispatch");
  // Get the system time and then create an ACE_Time_Request
  time_t t = ACE_OS::time (0);
  ACE_Time_Request rq (ACE_Time_Request::TIME_UPDATE, t);
  return this->send_request (rq);
}
  
// Receive, frame, and decode the client's request.  Note, this method
// should use non-blocking I/O.

/* VIRTUAL */ int 
ACE_TS_Server_Handler::recv_request (void)
{
  ACE_TRACE ("ACE_TS_Server_Handler::recv_request");
  ssize_t bytes_expected = this->time_request_.size ();

  // Since Time_Request messages are fixed size, read the entire
  // message in one go.
  ssize_t n = this->peer ().recv ((void *) &this->time_request_, bytes_expected);
  if (n != bytes_expected)
    {
      switch (n)
	{
	case -1:
	  /* FALLTHROUGH */
	  ACE_DEBUG ((LM_DEBUG, "****************** recv_request returned -1\n"));
	default:
	  ACE_ERROR ((LM_ERROR, "%p got %d bytes, expected %d bytes\n", 
		      "recv failed", n, bytes_expected));
	  /* FALLTHROUGH */
	case 0:
	  // We've shutdown unexpectedly, let's abandon the connection.
	  this->abandon ();
	  return -1;
	  /* NOTREACHED */
	}
    }
  else
    {
      // Decode the request into host byte order.
      if (this->time_request_.decode () == -1)
	{
	  ACE_ERROR ((LM_ERROR, "%p\n", "decode failed"));
	  return this->abandon ();
	}
    }
  return 0;
}

// Callback method invoked by the ACE_Reactor when events arrive from
// the client.

/* VIRTUAL */ int 
ACE_TS_Server_Handler::handle_input (ACE_HANDLE)
{
  ACE_TRACE ("ACE_TS_Server_Handler::handle_input");

  if (this->recv_request () == -1)
    return -1;
  else
    return this->dispatch ();
}

ACE_TS_Server_Handler::~ACE_TS_Server_Handler (void)
{
  ACE_TRACE ("ACE_TS_Server_Handler::~ACE_TS_Server_Handler");
  ACE_DEBUG ((LM_DEBUG, "closing down Handle  %d\n",
	      this->get_handle ()));
}

#if defined (ACE_TEMPLATES_REQUIRE_SPECIALIZATION)
template class ACE_Strategy_Acceptor<ACE_TS_Server_Handler, ACE_SOCK_ACCEPTOR>;
template class ACE_Schedule_All_Reactive_Strategy<ACE_TS_Server_Handler>;
template class ACE_Svc_Handler<ACE_SOCK_Stream, ACE_INET_Addr, ACE_Null_Mutex, ACE_Null_Condition_Mutex>;
#endif /* ACE_TEMPLATES_REQUIRE_SPECIALIZATION */
