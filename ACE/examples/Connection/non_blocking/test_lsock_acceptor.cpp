// $Id$

// ACE_LSOCK Server.

#include "ace/LSOCK_Acceptor.h"
#include "ace/Log_Msg.h"
#include "ace/Service_Config.h"


#if defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)
int
ACE_TMAIN (int, ACE_TCHAR *argv[])
{
  ACE_ERROR_RETURN ((LM_INFO,
                     ACE_TEXT ("%s: not supported with ")
                     ACE_TEXT ("ACE_LACKS_UNIX_DOMAIN_SOCKETS\n"),
                     argv[0]),
                     -1);
}

#else  /* ! ACE_LACKS_UNIX_DOMAIN_SOCKETS */

#include "ace/UNIX_Addr.h"
#include "CPP-acceptor.h"

typedef Svc_Handler<ACE_LSOCK_STREAM> SVC_HANDLER;
typedef IPC_Server<SVC_HANDLER, ACE_LSOCK_ACCEPTOR> IPC_SERVER;

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  // Perform Service_Config initializations
  ACE_Service_Config daemon (argv[0]);

  IPC_SERVER peer_acceptor;

  if (peer_acceptor.init (argc, argv) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("init")),
                      -1);
  return peer_acceptor.svc ();
}

#endif /* ! ACE_LACKS_UNIX_DOMAIN_SOCKETS */
