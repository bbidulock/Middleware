
// $Id$

#include "ace/SOCK_Dgram.h"
#include "ace/INET_Addr.h"

static const u_short PORT = ACE_DEFAULT_SERVER_PORT;

int main(int argc,char *argv[] )
{
	ACE_INET_Addr  local((u_short)0);
	ACE_INET_Addr  remote(PORT, argc > 1 ? argv[1] : "localhost" );
	ACE_SOCK_Dgram dgram;
	
	if( dgram.open(local) == -1 )
	{
		cerr << "Cannot create client datagram" << endl;
		return(0);
	}

	char buf[512];

	sprintf(buf, argc > 2 ? argv[2] : "Hello World!");

	if( dgram.send(buf,strlen(buf)+1,remote) == -1 )
	{
		cerr << "Failed to send datagram" << endl;
		return(0);
	}

	if( argc > 2 )
	{
		ACE_Time_Value timeout(2,0);
		if( dgram.recv(buf,sizeof(buf),remote,0,&timeout) == -1 )
		{
			cerr << "Failed to receive server's response" << endl;
			return(0);
		}

		cerr << "Server responded with:  " << buf << endl;
	}

	return(0);
}
