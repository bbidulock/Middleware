// -*- C++ -*-
// HTTP_Server.h

#if !defined (HTTP_SERVER_H)
#define HTTP_SERVER_H

class ACE_Proactor;

#include "ace/Service_Object.h"
#include "ace/Thread_Manager.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Task.h"
#include "ace/Asynch_IO.h"

#include "JAWS/server/HTTP_Handler.h"

// Specialize ACE_SOCK_Acceptor to lock around accept();
template <class LOCK>
class LOCK_SOCK_Acceptor : public ACE_SOCK_Acceptor
{
public:
  int accept (ACE_SOCK_Stream &new_stream,
	      ACE_Addr *remote_addr = 0,
	      ACE_Time_Value *timeout = 0,
	      int restart = 1) const;
  
private:
  LOCK lock_;
};

#if defined (ACE_HAS_TEMPLATE_TYPEDEFS)
#define ONESHOT_SOCK_ACCEPTOR HTTP_SOCK_Acceptor
#else /* TEMPLATES are broken */
#define ONESHOT_SOCK_ACCEPTOR HTTP_SOCK_Acceptor, HTTP_SOCK_Acceptor::PEER_ADDR
#endif /* ACE_HAS_TEMPLATE_TYPEDEFS */

#if defined (ACE_WIN32)
typedef LOCK_SOCK_Acceptor<ACE_Null_Mutex> HTTP_SOCK_Acceptor;
#else
typedef LOCK_SOCK_Acceptor<ACE_Thread_Mutex> HTTP_SOCK_Acceptor;
#endif /* ACE_WIN32 */

//typedef ACE_Oneshot_Acceptor <HTTP_Handler, ONESHOT_SOCK_ACCEPTOR> HTTP_Acceptor;
typedef HTTP_SOCK_Acceptor HTTP_Acceptor;

class HTTP_Server : public ACE_Service_Object
  //     
  // = TITLE
  //
  //     This server is used to create HTTP Handlers for the Web
  //     server
  // 
  // = DESCRIPTION
  //     
  //     
{
public:
  virtual int init (int argc, char *argv[]);
  // Initialization

  virtual int fini (void);
  // Exit hooks

protected:
  virtual int thread_per_request ();
  // Thread Per Request implementation

  virtual int asynch_thread_pool ();
  // Asynch Thread Pool implementation
  
  virtual int synch_thread_pool ();
  // Synch Thread Pool implementation
  
  void setup_signal_handler (void);

private:
  void parse_args (int argc, char **argv);
  int port_;
  int threads_;
  int strategy_;
  ACE_Thread_Manager tm_;
  HTTP_Acceptor acceptor_;
};

class Synch_Thread_Pool_Task : public ACE_Task<ACE_NULL_SYNCH>
  //     
  // = TITLE
  //
  //     Used to implement Synch Thread Pool
  // 
  // = DESCRIPTION
  //     
  //     
{
public:
  Synch_Thread_Pool_Task (HTTP_Acceptor &acceptor, ACE_Thread_Manager &tm);
  virtual int open (void *args = 0);
  virtual int svc (void);

private:
  HTTP_Acceptor &acceptor_;
};

class Thread_Per_Request_Task : public ACE_Task<ACE_NULL_SYNCH>
  //     
  // = TITLE
  //
  //     Used to implement Thread Per Request
  // 
  // = DESCRIPTION
  //     
  //     
{
public:
  Thread_Per_Request_Task (ACE_HANDLE handle, ACE_Thread_Manager &tm);
  virtual int open (void *args = 0);
  virtual int close (u_long);
  virtual int svc (void);

private:
  ACE_HANDLE handle_;
};

// This only works on Win32
#if defined (ACE_WIN32)
class Asynch_Thread_Pool_Task : public ACE_Task<ACE_NULL_SYNCH>
  //     
  // = TITLE
  //
  //     Used to implement Asynch Thread Pool
  // 
  // = DESCRIPTION
  //     
  //     
{
public:
  Asynch_Thread_Pool_Task (ACE_Proactor &proactor, ACE_Thread_Manager &tm);
  virtual int open (void *args = 0);
  virtual int svc (void);

private:
  ACE_Proactor &proactor_;
};
#endif /* ACE_WIN32 */

ACE_STATIC_SVC_DECLARE (HTTP_Server)

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "JAWS/server/HTTP_Server.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("HTTP_Server.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* HTTP_SERVER_H */

