// $Id$

#define ACE_WEBSVCS_BUILD_DLL
#include "URL_Addr.h"

#if !defined (__ACE_INLINE__)
#include "ace/URL_Addr.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, URL_Addr, "$Id$")

static ASYS_TCHAR http[] = ASYS_TEXT ("http:");
static size_t http_size = sizeof(http)/sizeof(http[0]) - 1;
static ASYS_TCHAR ftp[] = ASYS_TEXT ("ftp:");
static size_t ftp_size = sizeof(ftp)/sizeof(ftp[0]) - 1;
static ASYS_TCHAR mailto[] = ASYS_TEXT ("mailto:");
static size_t mailto_size = sizeof(mailto)/sizeof(mailto[0]) - 1;

ACE_URL_Addr::ACE_URL_Addr (void)
  : url_ (0)
{
}

ACE_URL_Addr::~ACE_URL_Addr ()
{
  ACE_OS::free (this->url_);
  this->url_ = 0;
}

int
ACE_URL_Addr::set (const ACE_URL_Addr& address)
{
  return this->ACE_URL_Addr::string_to_addr (address.url_);
}

int
ACE_URL_Addr::string_to_addr (LPCTSTR address)
{
  if (this->url_ != 0)
    ACE_OS::free (this->url_);
  ACE_ALLOCATOR_RETURN (this->url_, ACE_OS::strdup (address), -1);
  return 0;
}

int
ACE_URL_Addr::addr_to_string (LPTSTR s,
                              size_t size,
                              int ipaddr_format) const
{
  if (size < ACE_OS::strlen (this->url_))
    return -1;
  ACE_OS::strcpy (s, this->url_);
  return 0;
}

int
ACE_URL_Addr::accept (ACE_URL_Addr_Visitor* visitor)
{
  return visitor->visit (this);
}

// The factory method to create URL addresses.
ACE_URL_Addr*
ACE_URL_Addr::create_address (LPCTSTR url)
{
  ACE_URL_Addr* addr = 0;
  if (ACE_OS::strncmp (http, url, http_size) == 0)
    ACE_NEW_RETURN (addr, ACE_HTTP_Addr (), 0);
  else if (ACE_OS::strncmp (ftp, url, ftp_size) == 0)
    ACE_NEW_RETURN (addr, ACE_FTP_Addr (), 0);
  else if (ACE_OS::strncmp (mailto, url, mailto_size) == 0)
    ACE_NEW_RETURN (addr, ACE_Mailto_Addr (), 0);
  else
    ACE_NEW_RETURN (addr, ACE_URL_Addr (), 0);

  if (addr->string_to_addr (url) != 0)
    {
      delete addr;
      addr = 0;
    }
  return addr;
}

// ****************************************************************

ACE_URL_Addr_Visitor::~ACE_URL_Addr_Visitor (void)
{
}

int
ACE_URL_Addr_Visitor::visit (ACE_URL_Addr*)
{
  return 0;
}

int
ACE_URL_Addr_Visitor::visit (ACE_HTTP_Addr*)
{
  return 0;
}

int
ACE_URL_Addr_Visitor::visit (ACE_FTP_Addr*)
{
  return 0;
}

int
ACE_URL_Addr_Visitor::visit (ACE_Mailto_Addr*)
{
  return 0;
}

// ****************************************************************

ACE_HTTP_Addr::ACE_HTTP_Addr (void)
  :  hostname_ (0),
     port_number_ (0),
     path_ (0),
     query_ (0)
{
}

ACE_HTTP_Addr::ACE_HTTP_Addr (LPCTSTR host_name,
                              LPCTSTR path,
                              LPCTSTR query,
                              u_short port)
  :  hostname_ (0),
     port_number_ (0),
     path_ (0),
     query_ (0)
{
  this->set (host_name, path, query, port);
}

ACE_HTTP_Addr::ACE_HTTP_Addr (const ACE_HTTP_Addr &addr)
  :  hostname_ (0),
     port_number_ (0),
     path_ (0),
     query_ (0)
{
  this->set (addr);
}

ACE_HTTP_Addr::~ACE_HTTP_Addr (void)
{
  this->clear ();
  this->hostname_ = 0;
  this->path_ = 0;
  this->query_ = 0;
}

int
ACE_HTTP_Addr::set (LPCTSTR host_name,
                    LPCTSTR path,
                    LPCTSTR query,
                    u_short port)
{
  this->clear ();
  ACE_ALLOCATOR_RETURN (this->hostname_, ACE_OS::strdup (host_name), -1);
  ACE_ALLOCATOR_RETURN (this->path_, ACE_OS::strdup (path), -1);
  ACE_ALLOCATOR_RETURN (this->query_, ACE_OS::strdup (query), -1);

  size_t size = this->url_size (1);

  LPTSTR buffer;
  ACE_ALLOCATOR_RETURN (buffer,
                        ACE_reinterpret_cast(LPTSTR,
                                             ACE_OS::malloc (size)),
                        -1);
  if (this->addr_to_string (buffer, size, 1) == -1)
    return -1;
  this->set_url (buffer);
  return 0;
}

int
ACE_HTTP_Addr::set (const ACE_HTTP_Addr &addr)
{
  if (this->ACE_URL_Addr::set (addr) != 0)
    return -1;
  this->clear ();
  ACE_ALLOCATOR_RETURN (this->hostname_, ACE_OS::strdup (addr.hostname_), -1);
  ACE_ALLOCATOR_RETURN (this->path_, ACE_OS::strdup (addr.path_), -1);
  ACE_ALLOCATOR_RETURN (this->query_, ACE_OS::strdup (addr.query_), -1);
  return 0;
}

void 
ACE_HTTP_Addr::clear (void)
{
  if (this->hostname_ != 0)
    ACE_OS::free (this->hostname_);
  if (this->path_ != 0)
    ACE_OS::free (this->path_);
  if (this->query_ != 0)
    ACE_OS::free (this->query_);
}

size_t
ACE_HTTP_Addr::url_size (int flags) const
{
  // Notice that we cannot hard-code the value because the size in
  // wchar's may be different.
  size_t size = 
    + sizeof (ASYS_TEXT ("http://"))
    + sizeof (ASYS_TEXT ("/:?")); // separators

  size_t chars =
    + (this->path_?ACE_OS::strlen (this->path_):0)
    + (this->query_?ACE_OS::strlen (this->query_):0);


  if (flags == 0)
    {
      size += sizeof (ASYS_TEXT("255.255.255.255"));
    }
  else
    {
      chars += ACE_OS::strlen (this->hostname_);
    }

  if (this->port_number_ != ACE_DEFAULT_HTTP_PORT)
    {
      size += sizeof (ASYS_TEXT(":65335"));
    }

  size += chars * sizeof(ASYS_TCHAR);

  return size;
}

int
ACE_HTTP_Addr::string_to_addr (LPCTSTR address)
{
  if (ACE_OS::strncmp (http, address, http_size) != 0)
    return -1;

  this->clear ();
  this->hostname_ = 0;
  this->path_ = 0;
  this->query_ = 0;

  // Save the original URL....
  if (this->ACE_URL_Addr::string_to_addr (address) != 0)
    return -1;

  LPCTSTR string = address;
  string += http_size;
  ASYS_TCHAR separator[] = ASYS_TEXT("//");
  string += sizeof(separator)/sizeof(separator[0]) - 1;

  // Make a copy of the string to manipulate it.
  ASYS_TCHAR *t;
  ACE_ALLOCATOR_RETURN (t, ACE_OS::strdup (string), -1);

  ASYS_TCHAR *path_start = ACE_OS::strchr (t, '/');
  if (path_start != 0)
    {
      // terminate the host:port substring
      path_start[0] = '\0';
      path_start++;
      ASYS_TCHAR *query_start = ACE_OS::strchr (path_start, '?');
      if (query_start != 0)
        {
          query_start[0] = '\0';
          query_start++;
          ACE_ALLOCATOR_RETURN (this->query_,
                                ACE_OS::strdup (query_start),
                                -1);
        }
      ACE_ALLOCATOR_RETURN (this->path_, ACE_OS::strdup (path_start), -1);
    }
  
  // By now t is null terminated at the start of the path, find the
  // port (if present).
  ASYS_TCHAR *port_start = ACE_OS::strchr(t, ':');
  this->port_number_ = ACE_DEFAULT_HTTP_PORT;
  if (port_start != 0)
    {
      // terminate the ipaddr.
      port_start[0] = '\0';
      port_start++;
      this->port_number_ = ACE_OS::atoi (port_start);
    }
  this->hostname_ = t;

  return 0;
}

int
ACE_HTTP_Addr::addr_to_string (LPTSTR buffer,
                               size_t size,
                               int flags) const
{
  if (size < this->url_size (flags))
    return -1;
  
  if (this->hostname_ == 0)
    return -1;

  size_t n = ACE_OS::sprintf (buffer,
                              ASYS_TEXT ("http://"));
  if (flags == 0)
    {
      ACE_INET_Addr inet = this->get_inet_address ();
      n += ACE_OS::sprintf (buffer + n, "%s", inet.get_host_addr ());
    }
  else
    {
     n += ACE_OS::sprintf (buffer + n, "%s", this->hostname_);
    }
  
  if (this->port_number_ != ACE_DEFAULT_HTTP_PORT)
    {
      n += ACE_OS::sprintf (buffer + n, ":%d", this->port_number_);
    }
  if (this->path_ != 0)
    {
      n += ACE_OS::sprintf (buffer + n, "/%s", this->path_);
    }
  if (this->query_ != 0)
    {
      n += ACE_OS::sprintf (buffer + n, "?%s", this->query_);
    }
  return 0;
}

int
ACE_HTTP_Addr::accept (ACE_URL_Addr_Visitor *visitor)
{
  return visitor->visit (this);
}

// ****************************************************************

ACE_FTP_Addr::ACE_FTP_Addr (void)
  :  user_ (0),
     passwd_ (0),
     hostname_ (0),
     path_ (0)
{
}

ACE_FTP_Addr::ACE_FTP_Addr (LPCTSTR host_name,
                            LPCTSTR path,
                            LPCTSTR user,
                            LPCTSTR passwd)
  :  user_ (0),
     passwd_ (0),
     hostname_ (0),
     path_ (0)
{
  this->set (host_name, path, user, passwd);
}

ACE_FTP_Addr::ACE_FTP_Addr (const ACE_FTP_Addr& addr)
  :  user_ (0),
     passwd_ (0),
     hostname_ (0),
     path_ (0)
{
  this->set (addr);
}

ACE_FTP_Addr::~ACE_FTP_Addr (void)
{
  this->clear ();
}

int
ACE_FTP_Addr::set (LPCTSTR host_name,
                   LPCTSTR path,
                   LPCTSTR user,
                   LPCTSTR passwd)
{
  this->clear ();
  ACE_ALLOCATOR_RETURN (this->hostname_, ACE_OS::strdup (host_name), -1);
  ACE_ALLOCATOR_RETURN (this->path_, ACE_OS::strdup (path), -1);
  ACE_ALLOCATOR_RETURN (this->user_, ACE_OS::strdup (user), -1);
  ACE_ALLOCATOR_RETURN (this->passwd_, ACE_OS::strdup (passwd), -1);

  size_t size = this->url_size (1);

  LPTSTR buffer;
  ACE_ALLOCATOR_RETURN (buffer,
                        ACE_reinterpret_cast(LPTSTR,
                                             ACE_OS::malloc (size)),
                        -1);
  if (this->addr_to_string (buffer, size, 1) == -1)
    return -1;
  this->set_url (buffer);
  return 0;
}

int
ACE_FTP_Addr::set (const ACE_FTP_Addr& addr)
{
  if (this->ACE_URL_Addr::set (addr) != 0)
    return -1;
  this->clear ();
  ACE_ALLOCATOR_RETURN (this->hostname_, ACE_OS::strdup (addr.hostname_), -1);
  ACE_ALLOCATOR_RETURN (this->path_, ACE_OS::strdup (addr.path_), -1);
  ACE_ALLOCATOR_RETURN (this->user_, ACE_OS::strdup (addr.user_), -1);
  ACE_ALLOCATOR_RETURN (this->passwd_, ACE_OS::strdup (addr.passwd_), -1);
  return 0;
}

void
ACE_FTP_Addr::clear (void)
{
  if (this->hostname_ != 0)
    ACE_OS::free (this->hostname_);
  if (this->path_ != 0)
    ACE_OS::free (this->path_);
  if (this->user_ != 0)
    ACE_OS::free (this->user_);
  if (this->passwd_ != 0)
    ACE_OS::free (this->passwd_);
}

size_t
ACE_FTP_Addr::url_size (int flags) const
{
  // Notice that we cannot hard-code the value because the size in
  // wchar's may be different.
  size_t size = 
    + sizeof (ASYS_TEXT ("ftp://"))
    + sizeof (ASYS_TEXT ("@:/")); // separators

  size_t chars =
    + (this->user_?ACE_OS::strlen (this->path_):0)
    + (this->passwd_?ACE_OS::strlen (this->passwd_):0)
    + (this->path_?ACE_OS::strlen (this->path_):0);

  if (flags == 0)
    {
      size += sizeof (ASYS_TEXT("255.255.255.255"));
    }
  else
    {
      chars += ACE_OS::strlen (this->hostname_);
    }

  size += chars * sizeof(ASYS_TCHAR);
  return size;
}

int
ACE_FTP_Addr::addr_to_string (LPTSTR buffer,
                              size_t size,
                              int flags) const
{
  if (size < this->url_size (flags))
    return -1;

  size_t n = ACE_OS::sprintf (buffer,
                              ASYS_TEXT ("ftp://"));

  if (this->user_ != 0)
    {
      n += ACE_OS::sprintf (buffer + n, "%s", this->user_);
    }
  if (this->passwd_ != 0)
    {
      n += ACE_OS::sprintf (buffer + n, ":%s", this->passwd_);
    }

  if (this->user_ != 0)
    {
      n += ACE_OS::sprintf (buffer + n, "@");
    }

  if (flags == 0)
    {
      ACE_INET_Addr inet = this->get_inet_address ();
      n += ACE_OS::sprintf (buffer + n, "%s", inet.get_host_addr ());
    }
  else
    {
      n += ACE_OS::sprintf (buffer + n, "%s", this->hostname_);
    }
  if (this->path_ != 0)
    {
      n += ACE_OS::sprintf (buffer + n, "/%s", this->path_);
    }
  return 0;
}

int
ACE_FTP_Addr::string_to_addr (LPCTSTR address)
{
  if (ACE_OS::strncmp (ftp, address, ftp_size) != 0)
    return -1;

  this->clear ();
  this->hostname_ = 0;
  this->user_ = 0;
  this->passwd_ = 0;
  this->path_ = 0;

  // Save the original URL....
  this->ACE_URL_Addr::string_to_addr (address);

  LPCTSTR string = address;
  string += ftp_size;
  ASYS_TCHAR separator[] = ASYS_TEXT("//");
  string += sizeof(separator)/sizeof(separator[0]) - 1;

  // Make a copy of the string to manipulate it.
  ASYS_TCHAR *t;
  ACE_ALLOCATOR_RETURN (t, ACE_OS::strdup (string), -1);

  ASYS_TCHAR *path_start = ACE_OS::strchr (t, '/');
  if (path_start != 0)
    {
      // terminate the host:port substring
      path_start[0] = '\0';
      path_start++;
      ACE_ALLOCATOR_RETURN (this->path_, ACE_OS::strdup (path_start), -1);
    }

  ASYS_TCHAR *host_start = ACE_OS::strchr (t, '@');
  if (host_start != 0)
    {
      host_start[0] = '\0';
      host_start++;
      ACE_ALLOCATOR_RETURN (this->hostname_,
                            ACE_OS::strdup (host_start),
                            -1);
      ASYS_TCHAR *pass_start = ACE_OS::strchr (t, ':');
      if (pass_start != 0)
        {
          pass_start[0] = '\0';
          pass_start++;
          ACE_ALLOCATOR_RETURN (this->passwd_,
                                ACE_OS::strdup (pass_start),
                                -1);
        }
      this->user_ = t;
    }
  else
    {
      this->hostname_ = t;
    }

  return 0;
}

int
ACE_FTP_Addr::accept (ACE_URL_Addr_Visitor* visitor)
{
  return visitor->visit (this);
}

// ****************************************************************

ACE_Mailto_Addr::ACE_Mailto_Addr (void)
  :  user_ (0),
     hostname_ (0),
     headers_ (0)
{
}

ACE_Mailto_Addr::ACE_Mailto_Addr (LPCTSTR user,
                                  LPCTSTR hostname,
                                  LPCTSTR headers)
  :  user_ (0),
     hostname_ (0),
     headers_ (0)
{
  this->set (user, hostname, headers);
}

ACE_Mailto_Addr::ACE_Mailto_Addr (const ACE_Mailto_Addr &addr)
  :  ACE_URL_Addr (addr),
     user_ (0),
     hostname_ (0),
     headers_ (0)
{
  this->set (addr);
}

ACE_Mailto_Addr::~ACE_Mailto_Addr (void)
{
}

int
ACE_Mailto_Addr::set (LPCTSTR user,
                      LPCTSTR hostname,
                      LPCTSTR headers)
{
  this->clear ();
  ACE_ALLOCATOR_RETURN (this->user_, ACE_OS::strdup (user), -1);
  ACE_ALLOCATOR_RETURN (this->hostname_, ACE_OS::strdup (hostname), -1);
  ACE_ALLOCATOR_RETURN (this->headers_, ACE_OS::strdup (headers), -1);
  size_t size = this->url_size (1);
  LPTSTR buffer;
  ACE_ALLOCATOR_RETURN (buffer,
                        ACE_reinterpret_cast(LPTSTR,
                                             ACE_OS::malloc (size)),
                        -1);
  if (this->addr_to_string (buffer, size, 1) == -1)
    return -1;
  this->set_url (buffer);
  return 0;
}

int
ACE_Mailto_Addr::set (const ACE_Mailto_Addr &addr)
{
  if (this->ACE_URL_Addr::set (addr) != 0)
    return -1;
  this->clear ();
  ACE_ALLOCATOR_RETURN (this->user_, ACE_OS::strdup (addr.user_), -1);
  ACE_ALLOCATOR_RETURN (this->hostname_, ACE_OS::strdup (addr.hostname_), -1);
  ACE_ALLOCATOR_RETURN (this->headers_, ACE_OS::strdup (addr.headers_), -1);
  return 0;
}

void 
ACE_Mailto_Addr::clear (void)
{
  if (this->user_ != 0)
    ACE_OS::free (this->user_);
  if (this->hostname_ != 0)
    ACE_OS::free (this->hostname_);
  if (this->headers_ != 0)
    ACE_OS::free (this->headers_);
}

size_t
ACE_Mailto_Addr::url_size (int flags) const
{
  // Notice that we cannot hard-code the value because the size in
  // wchar's may be different.
  size_t size = sizeof (ASYS_TEXT ("mailto:"))
    + sizeof (ASYS_TEXT ("@?")); // separators

  size_t chars =
    + (this->user_?ACE_OS::strlen (this->user_):0)
    + (this->hostname_?ACE_OS::strlen (this->hostname_):0)
    + (this->headers_?ACE_OS::strlen (this->headers_):0);
  size += chars * sizeof (ASYS_TCHAR);

  return size;
}

int
ACE_Mailto_Addr::addr_to_string (LPTSTR buffer,
                                 size_t size,
                                 int flags) const
{
  if (size < this->url_size (flags))
    return -1;
  if (this->user_ == 0 || this->hostname_ == 0)
    return -1;

  size_t n = ACE_OS::sprintf (buffer, ASYS_TEXT ("mailto:%s@%s"),
                              this->user_, this->hostname_);
  if (this->headers_ != 0)
    {
      n += ACE_OS::sprintf (buffer + n, ASYS_TEXT ("?%s"),
                            this->headers_);
    }
  
  return 0;
}

int
ACE_Mailto_Addr::string_to_addr (LPCTSTR address)
{
  if (ACE_OS::strncmp (mailto, address, mailto_size) != 0)
    return -1;

  this->clear ();
  this->user_ = 0;
  this->hostname_ = 0;
  this->headers_ = 0;

  // Save the original URL....
  if (this->ACE_URL_Addr::string_to_addr (address) != 0)
    return -1;

  LPCTSTR string = address;
  string += mailto_size;

  // Make a copy of the string to manipulate it.
  ASYS_TCHAR *t;
  ACE_ALLOCATOR_RETURN (t, ACE_OS::strdup (string), -1);

  ASYS_TCHAR *host_start = ACE_OS::strchr (t, '@');
  if (host_start != 0)
    {
      // terminate the host:port substring
      host_start[0] = '\0';
      host_start++;
      ASYS_TCHAR *headers_start = ACE_OS::strchr (host_start, '?');
      if (headers_start != 0)
        {
          headers_start[0] = '\0';
          headers_start++;
          ACE_ALLOCATOR_RETURN (this->headers_,
                                ACE_OS::strdup (headers_start),
                                -1);
        }
      ACE_ALLOCATOR_RETURN (this->hostname_, ACE_OS::strdup (host_start), -1);
    }
  else
    {
      return -1;
    }
  this->user_ = t;

  return 0;
}

int
ACE_Mailto_Addr::accept (ACE_URL_Addr_Visitor* visitor)
{
  return visitor->visit (this);
}

