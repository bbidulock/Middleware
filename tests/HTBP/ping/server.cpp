/**
 * server for a basic connection establishment test using HTBP
 *
 * $Id$
 */

#include "ace/Log_Msg.h"

#include "ace/HTBP/HTBP_Session.h"
#include "ace/HTBP/HTBP_Stream.h"
#include "ace/HTBP/HTBP_Addr.h"

#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_Stream.h"

int
main (int argc, char *argv[])
{
  ACE_UNUSED_ARG (argc);
  ACE_UNUSED_ARG (argv);

  char buffer[1000];
  ssize_t n = 0;

  ACE_OS::socket_init (ACE_WSOCK_VERSION);

  ACE_INET_Addr local(8088);
  ACE_SOCK_Stream sock[2];
  ACE_SOCK_Acceptor acc(local,1);
  ACE_DEBUG ((LM_DEBUG,"server is ready\n"));

  acc.accept(sock[0]);
  ACE::HTBP::Channel channel1(sock[0]);
  ACE_DEBUG ((LM_DEBUG,"Got sock[0], handle = %d\n",sock[0].get_handle()));
  acc.accept(sock[1]);
  ACE::HTBP::Channel channel2(sock[1]);
  ACE_DEBUG ((LM_DEBUG,"Got sock[1], handle = %d\n",sock[1].get_handle()));
  int res = 0;
  while ((res =channel1.pre_recv()) != 0)
    {
      ACE_DEBUG ((LM_DEBUG,"res = %d. waiting 1 sec. %p\n",res,
                  "stream.pre_recv()"));
      ACE_OS::sleep (1);
    }

  ACE_DEBUG ((LM_DEBUG,"Read from channel2\n"));
  while ((res = channel2.pre_recv()) != 0)
    {
      ACE_DEBUG ((LM_DEBUG,"res = %d, waiting 1 sec. %p\n",res,
                  "stream2.pre_recv()"));
      ACE_OS::sleep (1);
    }

  ACE::HTBP::Session *session = channel1.session();
  ACE::HTBP::Stream stream (session);

  ACE_DEBUG ((LM_DEBUG,"using streams %d, %d. Got sesssion = %x\n",
              sock[0].get_handle(),sock[1].get_handle(),session));

  for (int i = 0; i >= 0; i++)
    {
      int retrycount = 10;
      while ((n = stream.recv(buffer,1000)) == -1
             && (errno == EWOULDBLOCK || errno == ETIME)
             && retrycount > 0)
        {
          retrycount--;
          ACE_DEBUG ((LM_DEBUG,"waiting for inbound data, %d tries left\n",
                      retrycount));
          ACE_OS::sleep(1);
        }
      if (retrycount == 0 || n < 0)
        break;

      buffer[n] = 0;

      ACE_DEBUG ((LM_DEBUG,"Got: \"%s\"\n",buffer));

      if (ACE_OS::strstr (buffer,"goodbye") != 0)
        break;

      ACE_OS::sprintf (buffer,"I hear you %d",i);
      n = stream.send (buffer,ACE_OS::strlen(buffer)+1);
      if (n == -1)
        ACE_ERROR_RETURN ((LM_ERROR, "%p\n","stream.send"),-1);

      ACE_DEBUG ((LM_DEBUG,"Send returned %d\n",n));

      int got[2] = {-1,-1};
      while (got[0] == -1 || got[1] == -1)
        {
          if (got[0] == -1)
            {
              if ((got[0] = (res =channel1.pre_recv())) == -1)
                ACE_DEBUG ((LM_DEBUG,"res = %d, waiting 1 sec. %p\n",got[0],
                            "channel1.pre_recv()"));
            }
          if (got[1] == -1)
            {
              if ((got[1] = (res =channel2.pre_recv())) == -1)
                ACE_DEBUG ((LM_DEBUG,"res = %d, waiting 1 sec. %p\n",got[1],
                            "channel2.pre_recv()"));
            }
          if (got[0] == -1 || got[1] == -1)
            ACE_OS::sleep (1);
        }
    }
  return 0;
}
