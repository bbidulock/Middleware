// $Id$

// ============================================================================
//
// = LIBRARY
//    apps/JAWS/clients/Caching
// 
// = FILENAME
//    http_handler.cpp
//
// = AUTHOR
//    James Hu
// 
// ============================================================================

#include "http_handler.h"
#include "ace/Filecache.h"

HTTP_Handler::HTTP_Handler (void)
{
}

HTTP_Handler::HTTP_Handler (const char * path)
{
  // How long is the request going to be?
  this->request_[0] = '\0';
  this->request_size_ = 
    ACE_OS::strlen ("GET ")
    + ACE_OS::strlen (path)
    + ACE_OS::strlen (" HTTP/1.0\r\nAccept: HTTP/1.0\r\n\r\n");

  // Make the request.
  if ((unsigned int) this->request_size_ < sizeof (this->request_))
    ACE_OS::sprintf(this->request_,
                    "GET %s HTTP/1.0\r\nAccept: HTTP/1.0\r\n\r\n",
                    path);

  // Find the filename.
  const char * last = ACE_OS::strrchr (path, '/');
  if (last == 0) last = path;
  else if (last[1] == '\0') last = "index.html";
  else last = last+1;

  ACE_OS::sprintf(this->filename_, "%s", last);
}

int
HTTP_Handler::open (void *)
{
  // If you want threads, use the activate stuff.
#if 0
  if (this->activate () != 0)
    {
      ACE_ERROR_RETURN((LM_ERROR, "HTTP_Handler::open, whups!\n"), -1);
    }
#else
  return this->svc ();
#endif /* 0 */

  return 0;
}

int
HTTP_Handler::svc (void)
{
  static char buf[BUFSIZ];
  int count = 0;

  // First check the cache.
  if (ACE_Filecache::instance ()->find (this->filename_))
    {
      ACE_OS::fprintf (stdout, "  ``%s'' is already cached.\n",
                       this->filename_);
      return 0;
    }

  ACE_DEBUG ((LM_DEBUG, "[%t] sending request --\n%s", this->request_));

  this->send_n (this->request_, this->request_size_);

  // Read in characters until encounter \r\n\r\n
  int done = 0;
  char * contentlength;
  do
    {
      while (((count += this->recv_n (buf+count, 1)) > 0)
             && ((unsigned int) count < sizeof (buf)))
        {
          buf[count] = '\0';
          if (count < 2) continue;
          done = (strcmp (buf+count-4, "\n\n") == 0);
          if (done) break;
          if (count < 4) continue;
          done = (strcmp (buf+count-4, "\r\n\r\n") == 0);
          if (done) break;
        }

      if (!done)
        {
          char * last = ACE_OS::strrchr (buf, '\n');
          last[0] = '\0';
          if ((contentlength = ACE_OS::strstr (buf, "\nContent-length:"))
              || (contentlength = ACE_OS::strstr (buf, "\nContent-Length:")))
            done = 1;
          else
            {
              last[0] = '\n';
              count = ACE_OS::strlen (last);
              ACE_OS::memmove (buf, last, count + 1);
            }
        }
      else
        {
          if (!(contentlength = ACE_OS::strstr (buf, "\nContent-length:")))
            contentlength = ACE_OS::strstr (buf, "\nContent-Length:");
        }
          
    }
  while (!done);

  // ASSERT (contentlength != 0)
  if (contentlength
      && (::sscanf (contentlength, "\nContent-%*[lL]ength: %d ",
                    &(this->response_size_)) == 1))
    {
      ACE_Filecache_Handle afh(this->filename_, this->response_size_);

      this->recv_n (afh.address (), this->response_size_);

      ACE_OS::fprintf (stdout, "  ``%s'' is now cached.\n",
                       this->filename_);
    }
  else
    {
      // Maybe we should do something more clever here, such as
      // extend ACE_Filecache_Handle to allow the creation of cache
      // objects whose size is unknown?

      // Another possibility is to write the contents out to a file,
      // and then cache it.

      // Perhaps make ACE_Filecache_Handle more savvy, and allow a
      // constructor which accepts a PEER as a parameter.
      ACE_DEBUG ((LM_DEBUG, "HTTP_Handler, no content-length header!\n"));
    }

  return 0;
}

int
HTTP_Handler::send_n (const void *buf, size_t n)
{
  int count = 0;
  const char *p = (const char *) buf;
  do
    {
      int result = this->peer ().send (p+count, n - count);
      if (result <= 0)
        {
          if (result < 0)
            ACE_DEBUG ((LM_DEBUG, "HTTP_Handler::send_n, error %p\n"));
          break;
        }
      count += result;
    }
  while ((unsigned int) count < n);

  return count;
}

int
HTTP_Handler::recv_n (void *buf, size_t n)
{
  int count = 0;
  char *p = (char *) buf;

  do
    {
      int result = this->peer ().recv (p+count, n - count);
      if (result <= 0)
        {
          if (result < 0)
            ACE_DEBUG ((LM_DEBUG, "HTTP_Handler::recv_n, error %p\n"));
          break;
        }
      count += result;
    }
  while ((unsigned int) count < n);

  return count;
}

int
HTTP_Connector::connect (const char * url)
{
  char host[BUFSIZ];
  unsigned short port;
  char path[BUFSIZ];

  if (this->parseurl (url, host, &port, path) == -1)
    {
      ACE_DEBUG ((LM_DEBUG, "HTTP_Connector, error parsing url: %s\n", url));
      return -1;
    }

  HTTP_Handler hh (path);
  HTTP_Handler *hhptr = &hh;
  return this->connector_.connect (hhptr, ACE_INET_Addr (port, host));
}

#define DEFAULT_SERVER_PORT 80

// extract the main components of a URL
int
HTTP_Connector::parseurl(const char *url,
                         char *host, unsigned short *port, char *path)
{
  int status = 0;

  // hackish, but useful
  if (3 != ::sscanf(url, "http://%[^:/]:%hu%s", host, port, path)) {
    if (2 != ::sscanf(url, "http://%[^:/]:%hu", host, port)) {
      if (2 != ::sscanf(url, "http://%[^:/]%s", host, path)) {
        if (1 != ::sscanf(url, "http://%[^:/]", host)) {
          status = -1;
        }
        else { *port = DEFAULT_SERVER_PORT; ACE_OS::strcpy(path, "/"); }
      }
      else *port = DEFAULT_SERVER_PORT;
    }
    else ACE_OS::strcpy(path, "/");
  }

  // 0 => success
  // -1 => error
  return status;
}

#if defined (ACE_TEMPLATES_REQUIRE_SPECIALIZATION)
template class ACE_Connector<HTTP_Handler,ACE_SOCK_CONNECTOR>;

template class ACE_Svc_Tuple<HTTP_Handler>;
template class ACE_Svc_Handler<ACE_SOCK_STREAM,ACE_NULL_SYNCH>;

template class ACE_Map_Entry<ACE_HANDLE,ACE_Svc_Tuple<HTTP_Handler>*>;
template class ACE_Map_Manager<ACE_HANDLE,ACE_Svc_Tuple<HTTP_Handler>*,ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Iterator<ACE_HANDLE,ACE_Svc_Tuple<HTTP_Handler>*,ACE_SYNCH_RW_MUTEX>;
#endif /* ACE_TEMPLATES_REQUIRE_SPECIALIZATION */
