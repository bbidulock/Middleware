// $Id$
 
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include "ace/Thread.h"

ACE_Reactor * g_reactor;

static sig_atomic_t finished = 0;

extern "C" void handler (int) { finished = 1; }
static void *thread_run(void *);
// ----------------------------------------

class Logging_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{

public:

  Logging_Handler (void)
  {
    thread_reactor = NULL;
  }

  ~Logging_Handler (void)
  {
    cout << "in destructor";
    delete thread_reactor;
  }

  virtual void destroy (void)
  { 
    cout << " in destroy";
    g_reactor->cancel_timer (this);
    this->peer ().close ();
    delete this;
  }

  static void *run_thread(Logging_Handler *this_)
  {
    cout << "run_thread in " << getpid() << endl;

    this_->thread_reactor = new ACE_Reactor;
	
    if (this_->thread_reactor->register_handler(this_, ACE_Event_Handler::READ_MASK) == -1)
      ACE_ERROR_RETURN ((LM_ERROR,"can'(%P|%t) t register with reactor\n"), -1);
    else if (this_->thread_reactor->schedule_timer (this_, (const void *)this_, ACE_Time_Value (2), ACE_Time_Value (2)) == -1)
      ACE_ERROR_RETURN ((LM_ERROR, "can'(%P|%t) t register with reactor\n"), -1);
    else
      ACE_DEBUG ((LM_DEBUG, "(%P|%t) connected with client \n"));
	
    while(!finished)
      this_->thread_reactor->handle_events();
	  	
  } 

  virtual int open (void *)
  {
    ACE_Thread::spawn(&Logging_Handler::run_thread,this);
    return 0;
  }

  virtual int close (u_long)
  {

    if (this->thread_reactor->remove_handler(this,ACE_Event_Handler::READ_MASK) == -1)
      ACE_ERROR_RETURN ((LM_ERROR, "can'(%P|%t) t remove service from reactor\n"), -1);
    this->destroy ();
    return 0;
  }

protected:

  virtual int handle_input (ACE_HANDLE)
  {
    char buf[128];
    memset(buf,0,sizeof(buf));
        
    cout << "handle_input in " << getpid() << endl;
    switch( this->peer().recv(buf,sizeof buf) )
      {
      case -1:
        ACE_ERROR_RETURN ((LM_ERROR, "(%P|%t) %p bad read\n", "client logger"), -1);
      case 0:
        ACE_ERROR_RETURN ((LM_ERROR, "(%P|%t) closing log daemon (fd = %d)\n", this->get_handle ()), -1);
      default:
        cout << "Data from client " << buf << endl;
        // ACE_DEBUG ((LM_DEBUG, "(%P|%t) from client: %s",buf));
      }
          
    return 0;
  }

  virtual int handle_timeout (const ACE_Time_Value &tv, const void *arg)
  {
    ACE_ASSERT (arg == this);
    // ACE_DEBUG ((LM_DEBUG, "(%P|%t) handling timeout from this = %u\n", this));
    cout << "Timout in " << getpid() << endl;
    return 0;
  }

private:
  ACE_Reactor *thread_reactor;
  char peer_name_[MAXHOSTNAMELEN + 1];
  
};


typedef ACE_Acceptor <Logging_Handler, ACE_SOCK_ACCEPTOR> Logging_Acceptor;


static const u_short PORT = ACE_DEFAULT_SERVER_PORT;

int main (int argc, char *argv[])
{
  g_reactor = new ACE_Reactor;

  cout << "main is " << getpid() << endl;

  // Acceptor factory.
  Logging_Acceptor peer_acceptor;

  if (peer_acceptor.open (ACE_INET_Addr (PORT)) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "open"), -1);

  else if (g_reactor->register_handler (&peer_acceptor, ACE_Event_Handler::READ_MASK) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "registering service with ACE_Reactor\n"), -1);

  ACE_Sig_Action sa ((ACE_SignalHandler) handler, SIGINT);

  // Run forever, performing logging service.

  ACE_DEBUG ((LM_DEBUG, "(%P|%t) starting up server logging daemon\n"));

  // Perform logging service until QUIT_HANDLER receives SIGINT.
  while ( !finished )
    g_reactor->handle_events ();

  ACE_DEBUG ((LM_DEBUG, "(%P|%t) shutting down server logging daemon\n"));

  return 0;
}
