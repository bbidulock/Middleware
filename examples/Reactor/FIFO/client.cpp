// $Id$

#include "ace/FIFO_Send_Msg.h"

int 
main (int, char *[])
{
  char buf[] = "hello world";
  ACE_Str_Buf msg (buf, sizeof buf);

  ACE_FIFO_Send_Msg fifo_sender (ACE_DEFAULT_RENDEZVOUS, 
				 O_WRONLY | O_CREAT, 
				 ACE_DEFAULT_FILE_PERMS);

  if (fifo_sender.send (msg) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "send error for fifo"), -1);
  else
    return 0;
}
