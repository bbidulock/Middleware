// $Id$

// ============================================================================
//
// = LIBRARY
//    performance-tests/UDP
//
// = FILENAME
//    udp_test.cpp
//
// = DESCRIPTION
//    Measures UDP round-trip performance.
//
// = AUTHORS
//    Fred Kuhns and David L. Levine
//
// ============================================================================

#include "ace/Reactor.h"
#include "ace/SOCK_Dgram.h"
#include "ace/INET_Addr.h"
#include "ace/ACE.h"
#include "ace/Get_Opt.h"
#include <math.h>

// Global variables (evil).
static const u_short DEFPORT = 5050;
static const int MAXPKTSZ = 65536;
static const int DEFPKTSZ = 64;
static const int DEFITERATIONS = 1000;
static const int DEFINTERVAL = 1000; // 1000 usecs.
static const int DEFWINDOWSZ = 10; // 10 microsecond.
static char SendBuf[MAXPKTSZ];
static char RxBuf[MAXPKTSZ];
static char **cmd;
static char *target;
static char targethost[MAXHOSTNAMELEN];
static char targetip[MAXHOSTNAMELEN];
static char datafile[MAXHOSTNAMELEN];

static ACE_UINT32 nsamples = DEFITERATIONS;
static int usdelay = DEFINTERVAL;
static int bufsz = DEFPKTSZ;
static int window = DEFWINDOWSZ;
static int VERBOSE = 0;
static int logfile = 0;
static int server = 0;
static int client = 0;
ACE_hrtime_t max_allow = 0;
ACE_hrtime_t total_ltime;
ACE_hrtime_t ltime;

static void
usage (void)
{
  ACE_ERROR ((LM_ERROR,
              "%s\n"
              "[-w window_size]\n"
              "  [-f datafile] (creates datafile.samp and datafile.dist)\n"
              "  [-v]          (Verbose)\n"
              "  [-b send_bufsz]\n"
              "  [-n nsamples]\n"
              "  [-I usdelay]\n"
              "  [-s so_bufsz] \n"
              "  [-p port]\n"
              "  [-t]\n"
              "  [-r]\n"
              "  [-x max_sample_allowed]\n"
              "  targethost \n",
              *cmd));
}

static ACE_hrtime_t *Samples;
static u_int *Dist;
static char sumfile[30];
static char distfile[30];
static char sampfile[30];

class Client : public ACE_Event_Handler
{
public:
  Client (const ACE_INET_Addr &addr,
          const ACE_INET_Addr &remote_addr);

  virtual ~Client (void);

  // = Override <ACE_Event_Handler> methods.
  virtual ACE_HANDLE get_handle (void) const;
  virtual int handle_input (ACE_HANDLE);
  virtual int handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask);

  int send (const char *buf, size_t len);
  // Send the <buf> to the server.

  int get_response (char *buf, size_t len);
  // Wait for the response.

  int run (void);
  // Send messages to server and record statistics.

  int shutdown (void);
  // Send shutdown message to server.

private:
  ACE_SOCK_Dgram endpoint_;
  // To send messages and receive responses.

  ACE_INET_Addr remote_addr_;
  // The address to send messages to.

  ACE_UNIMPLEMENTED_FUNC (Client (void))
  ACE_UNIMPLEMENTED_FUNC (Client (const Client &))
  ACE_UNIMPLEMENTED_FUNC (Client &operator= (const Client &))
};

Client::Client (const ACE_INET_Addr &addr,
                const ACE_INET_Addr &remote_addr)
  : endpoint_ (addr),
    remote_addr_ (remote_addr)
{
  if (ACE_Reactor::instance ()->register_handler
      (this, ACE_Event_Handler::READ_MASK) == -1)
    ACE_ERROR ((LM_ERROR,
                "ACE_Reactor::register_handler: Client\n"));
}

Client::~Client (void)
{
}

ACE_HANDLE
Client::get_handle (void) const
{
  return endpoint_.get_handle ();
}

int
Client::handle_input (ACE_HANDLE)
{
  char buf[BUFSIZ];
  ACE_INET_Addr from_addr;

  ssize_t n = endpoint_.recv (buf, sizeof buf, from_addr);

  if (n == -1)
    ACE_ERROR ((LM_ERROR,
                "%p\n",
                "handle_input"));
  else
    ACE_DEBUG ((LM_DEBUG,
                "(%P|%t) buf of size %d = %*s\n",
                n,
                n,
                buf));

  return 0;
}

int
Client::handle_close (ACE_HANDLE,
                      ACE_Reactor_Mask)
{
  this->endpoint_.close ();
  return 0;
}

int
Client::send (const char *buf, size_t len)
{
  return this->endpoint_.send (buf, len, remote_addr_);
}

int
Client::get_response (char *buf, size_t len)
{
  ACE_INET_Addr addr;
  return this->endpoint_.recv (buf, len, addr);
}

int
Client::run (void)
{
  int ndist = 0;
  int i;
  int j; 
  int n;
  int maxindx = 0;
  int minindx = 0;
  char *sbuf = SendBuf;
  char *rbuf = RxBuf;

  ACE_hrtime_t start;
  ACE_hrtime_t end;
  ACE_hrtime_t sample;

#if defined (ACE_LACKS_FLOATING_POINT)
  ACE_hrtime_t sample_mean;
#else  /* ! ACE_LACKS_FLOATING_POINT */
  int d;
  double std_dev;
  double std_err;
  double sample_mean;
#endif /* ! ACE_LACKS_FLOATING_POINT */

  ACE_hrtime_t last_over = 0;
  ACE_hrtime_t psum = 0;
  ACE_hrtime_t sum = 0;
  ACE_hrtime_t max = 0;
  ACE_hrtime_t min = (ACE_hrtime_t) (u_int) -1;
  FILE *sumfp = 0;
  FILE *distfp = 0;
  FILE *sampfp = 0;
  pid_t *pid = (pid_t *) sbuf;
  int *seq = (int *) (sbuf + sizeof (int));

  ACE_OS::memset (sbuf, 0, bufsz);
  ACE_OS::memset (rbuf, 0, bufsz);

  *pid = ACE_OS::getpid ();
  *seq = 0;

  ACE_DEBUG ((LM_DEBUG,
              "PID = %d, Starting SEQ = %d\n",
              *pid,
              *seq));

  // Allocate memory to hold samples.
  Samples = (ACE_hrtime_t *) ACE_OS::calloc (nsamples,
                                             sizeof (ACE_hrtime_t));

  for (i = -1, *seq = 0, j = 0; 
       i < (ACE_INT32) nsamples;
       (*seq)++, i++, j++)
    {
      start = ACE_OS::gethrtime ();
      if (send (sbuf, bufsz) <= 0)
        ACE_ERROR_RETURN ((LM_ERROR, "(%P) %p\n", "send"), -1);

      if ((n = get_response (rbuf, bufsz)) <= 0)
        ACE_ERROR_RETURN ((LM_ERROR, "(%P) %p\n", "get_response"), -1);

      end = ACE_OS::gethrtime ();

      if (n <= 0)
        ACE_ERROR_RETURN ((LM_ERROR, 
                           "\nTrouble receiving from socket!\n\n"),
                          -1);

      sample = end - start; // in nanoseconds.

      if (i < 0 )
        {
          ACE_DEBUG ((LM_DEBUG,
                      "Ignoring first sample of %lld usecs\n",
                      sample / 1000));
          continue;
        }
      else if (max_allow > 0  &&  sample > max_allow)
        {
          ACE_DEBUG ((LM_DEBUG, "Sample # %i = "
                      "%lld msec is over the limit (%lld)!\n",
                      i,
                      sample / 1000000,
                      max_allow / 1000000));

          if (last_over > 0)
            ACE_DEBUG ((LM_DEBUG,
                        "\tTime since last over = %lld msec!\n",
                        (end - last_over) / 1000000));
          last_over = end;
          i--;
          continue;
        }

      Samples[i] = sample;
      sum += sample;

      if (min == (ACE_hrtime_t) (u_int) -1)
        {
          min = sample;
          minindx = i;
        }
      if (sample > max)
        {
          max = sample;
          maxindx = i;
        }
      if (sample < min)
        {
          min = sample;
          minindx = i;
        }

      if (VERBOSE)
        {
          psum += sample;
          if (j == 500)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "(%i) Partial (running) mean %lld usecs\n",
                          i + 1, 
                          psum / (1000 * 500)));
              j = 0;
              psum = 0;
            }
        }
    }

#if defined (ACE_LACKS_FLOATING_POINT)
  sample_mean = sum / nsamples;
#else  /* ! ACE_LACKS_FLOATING_POINT */
  sample_mean = ((double)sum)/((double)nsamples);
#endif /* ! ACE_LACKS_FLOATING_POINT */

  if (logfile)
    {
      ACE_OS::sprintf (sumfile, "%s.sum", datafile);
      ACE_OS::sprintf (distfile, "%s.dist", datafile);
      ACE_OS::sprintf (sampfile, "%s.samp", datafile);

      distfp = ACE_OS::fopen(distfile, "w");

      if (distfp == NULL)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "Unable to open dist file!\n\n"));
          logfile = 0;
        }
      if (logfile && (sampfp = ACE_OS::fopen (sampfile, "w")) == NULL)
        {
          ACE_OS::fclose (distfp);
          ACE_DEBUG ((LM_DEBUG,
                      "Unable to open sample file!\n\n"));
          logfile = 0;
        }
      if (logfile && (sumfp = ACE_OS::fopen (sumfile, "w")) == NULL)
        {
          ACE_OS::fclose (distfp);
          ACE_OS::fclose (sampfp);
          ACE_DEBUG ((LM_DEBUG,
                      "Unable to open sample file!\n\n"));
          logfile = 0;
        }
    }

  if (window)
    {
      window = window * 1000; // convert to nsec.
      ndist = (int)((max-min) / window) + 1;
      Dist = (u_int *) ACE_OS::calloc (ndist,
                                       sizeof (u_int));
    }

#if ! defined (ACE_LACKS_FLOATING_POINT)
  std_dev = std_err = 0;

  for (i = 0; i < (ACE_INT32) nsamples; i++)
    {
      std_dev += ((double)Samples[i] - sample_mean) *
        ((double) Samples[i] - sample_mean);
      d = (int)((Samples[i] - min)/window);

      if (d < 0 || d > ndist)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "\nError indexing into dist array %d (%d)\n\n",
                      d, 
                      ndist));
          ACE_OS::exit (1);
        }
      Dist[d] += 1;
      if (logfile)
        ACE_OS::fprintf (sampfp,
                         "%lld\n", 
                         Samples[i]);
    }
#endif /* ACE_LACKS_FLOATING_POINT */

  if (logfile)
    {
      ACE_hrtime_t tmp;
      tmp = min + (window / 2);

      for (i = 0; i < ndist; i++)
        {
          ACE_OS::fprintf (distfp,
                           "%lld %d\n",
                           tmp / 1000,
                           Dist[i]);
          tmp += window;
        }
    }

#if defined (ACE_LACKS_FLOATING_POINT)
  ACE_DEBUG ((LM_DEBUG, 
              "\nResults for %i samples (usec):\n"
              "\tSample Mean = %u,\n"
              "\tSample Max = %u, Max index = %u,\n"
              "\tSample Min = %u, Min index = %u,\n",
              nsamples,
              sample_mean / (ACE_UINT32) 1000,
              max / (ACE_UINT32) 1000,
              maxindx,
              min / (ACE_UINT32) 1000,
              minindx);
#else  /* ! ACE_LACKS_FLOATING_POINT */
  std_dev = (double) sqrt (std_dev / (double) (nsamples - 1.0));
  std_err = (double) std_dev / sqrt ((double) nsamples);

  ACE_DEBUG ((LM_DEBUG,
              "\nResults for %i samples (usec):\n"
              "\tSample Mean = %f,\n"
              "\tSample Max = %lld, Max index = %d,\n"
              "\tSample Min = %lld, Min index = %d,\n"
              "\tStandard Deviation = %f,\n"
              "\tStandard Error = %f\n",
              nsamples,
              sample_mean / 1000,
              max / 1000,
              maxindx,
              min / 1000,
              minindx,
              std_dev / 1000, 
              std_err / 1000));

  if (logfile)
    {
      ACE_OS::fprintf (sumfp,
                       "Command executed: \n");
      for (; *cmd; cmd++)
        ACE_OS::fprintf (sumfp, 
                         "%s ",
                         *cmd);
      ACE_OS::fprintf (sumfp,
                       "\n");

      ACE_OS::fprintf (sumfp,
                       "\nResults for %i samples (usec):"
                       "\tSample Mean = %f,\n"
                       "\tSample Max = %lld, Max index = %d,\n"
                       "\tSample Min = %lld, Min index = %d,\n"
                       "\tStandard Deviation = %f,\n"
                       "\tStandard Error = %f\n",
                       nsamples,
                       sample_mean / 1000,
                       max / 1000,
                       maxindx,
                       min / 1000,
                       minindx,
                       std_dev / 1000,
                       std_err / 1000);
    }
#endif /* ! ACE_LACKS_FLOATING_POINT */

  return 0;
}

int
Client::shutdown (void)
{
  const char buf = 'S';
  const int n = endpoint_.send (&buf, 1u, remote_addr_);

  if (ACE_Reactor::instance ()->remove_handler
      (this, ACE_Event_Handler::READ_MASK) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "ACE_Reactor::remove_handler: Client\n"),
                      -1);
  return n;
}

class Server : public ACE_Event_Handler
{
public:
  Server (const ACE_INET_Addr &addr);

  virtual ~Server (void);

  // = Override <ACE_Event_Handler> methods.
  virtual ACE_HANDLE get_handle (void) const;
  virtual int handle_input (ACE_HANDLE);
  virtual int handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask);

private:
  ACE_SOCK_Dgram endpoint_;
  // Receives datagrams.

  ACE_UNIMPLEMENTED_FUNC (Server (void))
  ACE_UNIMPLEMENTED_FUNC (Server (const Server &))
  ACE_UNIMPLEMENTED_FUNC (Server &operator= (const Server &))
};

Server::Server (const ACE_INET_Addr &addr)
  :  endpoint_ (addr)
{
  if (ACE_Reactor::instance ()->register_handler
      (this,
       ACE_Event_Handler::READ_MASK) == -1)
    ACE_ERROR ((LM_ERROR,
                "ACE_Reactor::register_handler: Server\n"));
}

Server::~Server (void)
{
}

ACE_HANDLE
Server::get_handle (void) const
{
  return endpoint_.get_handle ();
}

int
Server::handle_input (ACE_HANDLE)
{
  char buf[BUFSIZ];
  ACE_INET_Addr from_addr;

  ssize_t n = endpoint_.recv (buf, sizeof buf, from_addr);

  if (n == -1)
    ACE_DEBUG ((LM_ERROR,
                "%p\n",
                "handle_input: recv"));

  // Send the message back as the response.
  if (endpoint_.send (buf, n, from_addr) == n)
    {
      if (n == 1 && buf[0] == 'S')
        {
          if (ACE_Reactor::instance ()->remove_handler
              (this, ACE_Event_Handler::READ_MASK) == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "ACE_Reactor::remove_handler: server\n"),
                              -1);

          ACE_Reactor::end_event_loop ();
        }

      return 0;
    }
  else
    {
      ACE_DEBUG ((LM_ERROR,
                  "%p\n",
                  "handle_input: send"));
      return -1;
    }
}

int
Server::handle_close (ACE_HANDLE,
                      ACE_Reactor_Mask)
{
  endpoint_.close ();

  return 0;
}

int
main (int argc, char *argv[])
{
  int c, dstport = DEFPORT;
  int so_bufsz = 0;

  cmd = argv;

  ACE_Get_Opt getopt (argc, argv, "x:w:f:vs:I:p:rtn:b:");

  while ((c = getopt ()) != -1)
    {
      switch ((char) c)
        {
        case 'x':
          max_allow = ACE_OS::atoi (getopt.optarg);
          break;
        case 'w':
          window = ACE_OS::atoi (getopt.optarg);
          if (window < 0)
            ACE_ERROR_RETURN ((LM_ERROR, 
                               "Invalid window!\n\n"),
                              1);
          break;
        case 'f':
          ACE_OS::strcpy (datafile, optarg);
          logfile = 1;
          break;
        case 'v':
          VERBOSE = 1;
          break;
        case 'b':
          bufsz = ACE_OS::atoi (getopt.optarg);

          if (bufsz <= 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "\nBuffer size must be greater than 0!\n\n"),
                              1);
                          
        case 'n':
          nsamples = ACE_OS::atoi (getopt.optarg);
          if (nsamples <= 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "\nIterations must be greater than 0!\n\n"),
                              1);
          break;
        case 's':
          so_bufsz = ACE_OS::atoi (getopt.optarg);

          if (so_bufsz <= 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "\nInvalid socket buffer size!\n\n"),
                              1);
          break;
        case 'I':
          usdelay = ACE_OS::atoi (getopt.optarg);

          if (usdelay == 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "%s: bad usdelay: %s\n",
                               argv[0],
                               getopt.optarg),
                              1);
          break;
        case 'p':
          dstport = ACE_OS::atoi (getopt.optarg);
          if (dstport <= 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "\nInvalid port number!\n\n"),
                              1);
          break;
        case 't':
          server = 0;
          client = 1;
          break;
        case 'r':
          client = 0;
          server = 1;
          break;
        default:
          usage ();
          return 1;
        }
    }

  if (getopt.optind >= argc && client || argc == 1)
    {
      usage ();
      return 1;
    }

  ACE_INET_Addr addr (server ? dstport : dstport + 1);

  if (server)
    {
      Server server (addr);

      ACE_Reactor::run_event_loop ();
    }
  else
    {
      if ((u_int) bufsz < sizeof (ACE_hrtime_t))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "\nbufsz must be >= %d\n",
                           sizeof (ACE_hrtime_t)),
                          1);
      ACE_INET_Addr remote_addr;

      if (isdigit(argv[getopt.optind][0]))
        {
          if (remote_addr.set (dstport,
                               (ACE_UINT32) ACE_OS::inet_addr (argv[getopt.optind])) == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "invalid IP address: %s\n",
                               argv[getopt.optind]),
                              1);
        }
      else
        {
          if (remote_addr.set (dstport, argv[getopt.optind]) == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "invalid IP address: %s\n",
                               argv[getopt.optind]),
                              1);
        }
      getopt.optind++;

      Client client (addr, remote_addr);

      ACE_DEBUG ((LM_DEBUG,
                  "\nSending %d byte packets to %s:%d "
                  "with so_bufsz = %d\n\n",
                  bufsz,
                  addr.get_host_name (),
                  dstport,
                  so_bufsz));

      client.run ();
      client.shutdown ();
    }

  return 0;
}
