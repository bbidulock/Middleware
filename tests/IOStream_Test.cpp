// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    IOStream_Test.cpp
//
// = DESCRIPTION
//    This is a simple test of the IOStream class that illustrates
//    how to use iostream operations on almost arbitrary I/O classes.
//
// = AUTHOR
//    James CE Johnson <jcej@lads.com>
//
// ============================================================================

#include "ace/Thread.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Connector.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/INET_Addr.h"
#include "ace/IOStream.h"
#include "test_config.h"

typedef ACE_IOStream<ACE_SOCK_Stream> ACE_SOCK_IOStream;

static short PORT = ACE_DEFAULT_SERVER_PORT;

/* The biggest drawback to an iostream is that it generally
   eats up whitespace when performing a get (>>) operation.

   That may be good if you're reading non-textual data but
   if you're trying to read a stream of words with embedded
   whitespace, it isn't going to be pleasant.

   If you've been blessed with the GNU String class, I've
   already provided a derived class, QuotedString, that
   makes dealing with strings very easy.

   If you're stuck with an array of characters then you
   will probably need somthing like I have below.


   On the other hand, one of the biggest advantages to an
   iostream is that it eats up whitespace :-)

   If you put (<<) your non-textual data to the iostream
   with any number of whitespace between the data then
   you can easily get (>>) the data from the iostream
   without having to worry about delimeters and such.


   The main thing to keep in mind when using an iostream
   between peers is that you MUST keep the data "fields"
   in sync.  That is, if the "putter" puts an int followed
   by a float followed by a double, you must make sure
   that the "getter" will be attempting to get an int
   then a float then a double.
 */

// Since I can't rely on GNU's String class being everywhere (yet),
// here's a simple class that will work with quoted strings.  Use at
// your own risk!  It is very incomplete!

class qchar
{
public:
  qchar (void) { c_ = '\0'; }

  qchar (char c) : c_(c) { };

  operator char () const { return c_; }

  qchar operator= (char c) { return c_ = c; }

  int operator== (char c) { return c_ == c; }

  friend ACE_SOCK_IOStream &operator>> (ACE_SOCK_IOStream & stream, qchar * buf);
  friend ACE_SOCK_IOStream &operator<< (ACE_SOCK_IOStream & stream, qchar * buf);
  friend ostream &operator<< (ostream & stream, qchar * buf);

private:
  char c_;
};

// This is taken almost directly from the QuotedString object that has
// been derived from GNU's String class.  The advantage to using
// QuotedString is that it is MUCH more robust than qchar will every
// be.

ACE_SOCK_IOStream &
operator>> (ACE_SOCK_IOStream & stream, qchar *buf)
{
  char c;

  *buf = '\0';	// Initialize the string

  if (!(stream >> c)) // eat space up to the first char
    return stream;

  // if we don't have a quote, append until we see space
  if (c != '"')
    for (*buf++ = c; 
	 stream.get(c) && !isspace(c); 
	 *buf++ = c)
      continue;
  else
    for (; stream.get(c) && c != '"'; *buf++ = c)
      if (c == '\\')
	{
	  stream.get(c);
	  if (c != '"')
	    *buf++ = '\\';
	}

  *buf = '\0';
	
  return stream;
}

ACE_SOCK_IOStream &
operator<< (ACE_SOCK_IOStream &stream, qchar *buf)
{
  stream.put ('"');
  while (*buf)
    if (*buf == '"')
      stream.put ('\\');

  stream.put ((char) *buf++);
  stream.put ('"');

  return stream;
}

ostream &
operator<< (ostream &stream, qchar *buf)
{
  while (*buf)
    stream.put ((char) *buf++);

  return stream;
}

// Our client thread will initiate the test by sending some data to
// the server.

static void *
client (void *arg = 0)
{
  ACE_NEW_THREAD;
  ACE_UNUSED_ARG (arg);

#if defined (ACE_HAS_THREADS)
  ACE_Thread_Control thread_control (ACE_Service_Config::thr_mgr ());
#endif /* ACE_HAS_THREADS */

  ACE_SOCK_IOStream server;
  ACE_INET_Addr addr (PORT, ACE_DEFAULT_SERVER_HOST);
  ACE_SOCK_Connector connector;

  if (connector.connect (server, addr) == -1)
    {
      ACE_ERROR ((LM_ERROR, "(%t) %p\n", "Failed to connect to server thread"));
      return (void *) -1;
    }

  // Send a string to the server which it can interpret as a qchar[]
  char *str = "\"This is a test     string.\"";
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Client Sending:  (%s)\n", str));
  server << str << endl;

  // Allow the server to get the string and echo it to the user.  (The
  // iostream doesn't need this, but humans do :)
  ACE_OS::sleep (2);

  // Send another string but this time the server will read it as a
  // char[].  Notice how the server's output doesn't include all of
  // the spaces sent by the client.

  str = "\"THIS IS A     TEST STRING.\"";
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Client Sending:  (%s)\n", str));
  server << str << endl;

  // Again, give the server time to display the happenings to the
  // user.
  ACE_OS::sleep (2);

  // Read from the server an int, float, long, float double.  The
  // iostream will pull them out by using the whitespace provided by
  // the server.

  int i;
  float f1, f2;
  long l;
  double d;
  server >> i >> f1 >> l >> f2 >> d;

  ACE_DEBUG ((LM_DEBUG, 
	      "(%P|%t) Client Received: int %d float %f long %d float %f double %f\n", 
	      i, f1, (int) l, f2, d));

  // Check for proper received values.
  ACE_ASSERT (i == 1  && (f1 >= 0.123420 && f1 <= 0.123422)  
	      && l == 666555444  &&  (f2 >= 23.44 && f2 <= 23.46)  
	      && (d >= -47.1e+9 && d <= -45.9e+9));
  // Reset the precision to limit ourselves to two significant digits.
  server.precision (2);

  // Now, make a little change & send 'em back.
  i  *= -1; server << i  << " ";
  f1 *= -1; server << f1 << " ";
  l  *= -1; server << l  << " ";
  f2 *= -1; server << f2 << " ";
  d  *= -1; server << d  << " ";
  server << endl;

  // Shut down the test.
  server.close();

  return 0;
}

// Test the server's ability to receive data from the client and then
// begin a two-way conversation.

static void *
server (void * = 0)
{
  ACE_NEW_THREAD;

#if defined (ACE_HAS_THREADS)
  ACE_Thread_Control thread_control (ACE_Service_Config::thr_mgr ());
#endif /* ACE_HAS_THREADS */

  ACE_INET_Addr addr (PORT);
  ACE_SOCK_Acceptor acceptor (addr);
  ACE_SOCK_IOStream client_handler;

  if (ACE_Service_Config::thr_mgr ()->spawn (ACE_THR_FUNC (client), 
					     0,
					     THR_NEW_LWP | THR_DETACHED) == -1)
    {
      ACE_ERROR ((LM_ERROR, "(%t) %p\n", "spawing client thread"));
      return (void *) -1;
    }

  if (acceptor.accept (client_handler) == -1)
    ACE_DEBUG ((LM_ERROR, "(%P|%t) Failed to accept new client_handler"));

  // Read a qbuf[] from the client.  Notice that all of the client's
  // whitespace is preserved.
  qchar qbuf[1024];
  ACE_OS::memset (qbuf, 0, sizeof qbuf);
  client_handler >> qbuf;
  ACE_DEBUG ((LM_DEBUG, 
	      "(%P|%t) Server Received: (\"%s\")\n", 
	      qbuf));

  // Give the client time to announce the next test to the user.
  ACE_OS::sleep (2);

  // Now we try to use a char[] to get a string from the client.
  // Compared to the method above, this is quite messy.  Notice also
  // that whitespace is lost.

  char buf[1024];
  ACE_OS::memset (buf, 0, sizeof buf);
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Server Received: ("));

  while (ACE_OS::strlen (buf) == 0  ||  buf[ACE_OS::strlen (buf) - 1] != '"')
    {
      client_handler >> buf;
      ACE_DEBUG ((LM_DEBUG, "%s ", buf));
    }

  ACE_DEBUG ((LM_DEBUG, ")\n"));

  // Send some non-textual data to the client.  We use a single
  // character to separate the fields but we could have used any valid
  // whitespace.  The data will be sent if the iostream's buffer gets
  // filled or when we flush it with an explicit client.sync() command
  // or the implicit <<endl.

  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Server Sending:  1 .12342134 666555444 23.45 -46.5e9 \n"));
  client_handler << 1 << " ";
  client_handler << .12342134 << " ";
  client_handler << 666555444 << " ";
  client_handler << 23.45 << " ";
  client_handler << -46.5e9 << " ";
  client_handler << endl;

  // The client will have changed the sign of each data field and sent
  // 'em all back to us.  At the same time, the client used the
  // precision() function to change the significant digits for
  // non-integer values.
  int i;
  float f1, f2;
  long l;
  double d;
  client_handler >> i >> f1 >> l >> f2 >> d;

  ACE_DEBUG ((LM_DEBUG, 
	      "(%P|%t) Server Received: int %d float %g long %d float %g double %g\n", 
	      i, f1, (int) l, f2, d));

  // check for proper received values
  ACE_ASSERT (i == -1  && (f1 >= -0.13 && f1 <= -0.11)
	      && l == -666555444  &&  (f2 >= -24.0 && f2 <= -22.0)  
	      && (d >= -45e+9 && d <= 47e+9));
  return 0;
}

static void
spawn (void)
{
#if defined (ACE_HAS_THREADS)
  if (ACE_Service_Config::thr_mgr ()->spawn (ACE_THR_FUNC (server),
					     0,
					     THR_NEW_LWP | THR_DETACHED) == -1)
    {
      ACE_ERROR ((LM_ERROR, "%p\n","spawning server thread"));
      return;
    }

  // Wait for the client and server thread to exit.
  ACE_Service_Config::thr_mgr ()->wait ();

#elif !defined (ACE_LACKS_EXEC)
  server ();

  switch (ACE_OS::fork ("child"))
    {
    case -1:
      ACE_ERROR ((LM_ERROR, "%p\n%a", "fork failed"));
      ACE_OS::_exit (-1);
    case 0: // In child
      {
	client ();
	break;
      }
    default: // In parent
      {
	// Allow the client to exit, then remove the Process_Mutex.
	ACE_OS::wait ();
	break;
      }
    }
#else
  ACE_ERROR ((LM_ERROR, 
	      "threads *and* processes not supported on this platform\n%"));
#endif /* ACE_HAS_THREADS */	
}

int
main (int argc, char *argv[])
{
  ACE_START_TEST ("IOStream_Test");

  if (argc > 1)
    PORT = ACE_OS::atoi (argv[1]);

  spawn ();

  ACE_END_TEST;
  return 0;
}

#if defined (ACE_TEMPLATES_REQUIRE_SPECIALIZATION)
template class ACE_IOStream<ACE_SOCK_Stream>;
template class ACE_Streambuf<ACE_SOCK_Stream>;
#endif /* ACE_TEMPLATES_REQUIRE_SPECIALIZATION */
