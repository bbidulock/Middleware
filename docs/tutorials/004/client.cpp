
// $Id$

#include "ace/SOCK_Connector.h"
#include "ace/SString.h"

class Client : public ACE_SOCK_Stream
{

public:
        Client(void);
        Client( const char * server, u_short port );

        int open( const char * server, u_short port );

        inline int initialized(void) { return mInitialized; }
        inline int error(void)       { return mError; }

        Client & operator<<( ACE_SString & str );
        Client & operator<<( char * str );
        Client & operator<<( int  n );

protected:

private:
  unsigned char mInitialized;
  unsigned char mError;

};

Client::Client(void)
{
  mInitialized = 0;
  mError = 0;
}

Client::Client( const char * server, u_short port )
{
  mInitialized = 0;
  mError = 0;
  (void)open(server,port);
}

int Client::open( const char * server, u_short port )
{
  ACE_SOCK_Connector connector;
  ACE_INET_Addr addr (port, server);

  if (connector.connect (*this, addr) == -1)
  {
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "open"), -1);
  }

  mInitialized = 1;

  return(0);
}

Client & Client::operator<<( ACE_SString & str )
{
        if( initialized() && ! error() )
        {
                char * cp = str.rep();

                mError = 0;

                if( this->send_n(cp,strlen(cp)) == -1 )
                {
                        mError = 1;
                }
        }
        else
        {
                mError = 1;
        }

        return *this ;
}

Client & Client::operator<< ( char * str )
{
        ACE_SString newStr(str);

        *this << newStr;

        return *this ;
}

Client & Client::operator<< ( int n )
{
        // ACE_SString newStr;
        // newStr = n;

        char buf[1024];
        sprintf(buf,"(%d)\n",n);
        ACE_SString newStr(buf);

        *this << newStr;

        return *this;
}

int main (int argc, char *argv[])
{
  const char *server_host = argc > 1 ? argv[1]                : ACE_DEFAULT_SERVER_HOST;
  u_short server_port     = argc > 2 ? ACE_OS::atoi (argv[2]) : ACE_DEFAULT_SERVER_PORT;
  int max_iterations      = argc > 3 ? ACE_OS::atoi (argv[3]) : 4;

  Client server(server_host,server_port);

  if( ! server.initialized() )
  {
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "intialization"), -1);
  }

  
  for (int i = 0; i < max_iterations; i++)
    {
      server << "message = " << i+1;

      if ( server.error() )
      {
        ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "send"), -1);
      }
      else
      {
        ACE_OS::sleep (1);
      }
    }

  if (server.close () == -1)
  {
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "close"), -1);
  }

  return 0;
}
