// -*- C++ -*-
// $Id$

// Ossama Othman <ossama@uci.edu>

#include "Content_Iterator_i.h"
#include "Iterator_Factory_i.h"

ACE_RCSID(ECE255, Iterator_Factory_i, "$Id$")

void
Iterator_Factory_i::get_iterator (const char * pathname,
                                  Web_Server::Content_Iterator_out contents,
                                  Web_Server::Metadata_Type_out metadata,
                                  CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException, Web_Server::Error_Result))
{
  // Based on code available in H&V.

  ACE_DEBUG ((LM_DEBUG,
              "Received request for file: <%s> ",
              pathname));

  ACE_HANDLE handle = ACE_OS::open (pathname, O_RDONLY);

  if (handle == ACE_INVALID_HANDLE)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "...FAILED\n"));

      ACE_THROW (Web_Server::Error_Result (404));
      // HTTP 1.1 "Not Found"
    }

  struct stat file_status;
  if (ACE_OS::fstat (handle, &file_status) == -1)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "...FAILED\n"));

      ACE_OS::close (handle);

      ACE_THROW (Web_Server::Error_Result (500));
      // HTTP 1.1 "Internal Server Error"
    }

  Content_Iterator_i * iterator_servant =
    new Content_Iterator_i (handle, file_status.st_size);

  // Activate the Content_Iterator object.
  Web_Server::Content_Iterator_var iterator =
    iterator_servant->_this (ACE_TRY_ENV);
  ACE_CHECK;

  metadata = new Web_Server::Metadata_Type;

  if (this->modification_date (&file_status,
                               metadata) != 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "...FAILED\n"));
 
      ACE_OS::close (handle);

      ACE_THROW (Web_Server::Error_Result (500));
      // HTTP 1.1 "Internal Server Error
    }

  if (this->content_type (pathname,
                          metadata) != 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "...FAILED\n"));

      ACE_OS::close (handle);

      ACE_THROW (Web_Server::Error_Result (500));
      // HTTP 1.1 "Internal Server Error
    }

  ACE_DEBUG ((LM_DEBUG,
              "...STARTED\n"));

  contents = iterator._retn (); // Make a copy
}

int
Iterator_Factory_i::modification_date (struct stat * file_status,
                                       Web_Server::Metadata_Type_out metadata)
{
  // Get the modification time from the file status structure/
  struct tm *t_gmt = gmtime (&(file_status->st_mtime));

  // A time string is probably never going to exceed 256 bytes.
  const size_t buflen = 256;
  char buf[buflen];

  // Format the time to conform to RFC 1123.
  if (ACE_OS::strftime (buf,
                        buflen,
                        "%a, %d %b %Y %H:%M:%S GMT",
                        t_gmt) == 0)
    return -1;
  else
    metadata->modification_date = CORBA::string_dup (buf);

  return 0;
}

int
Iterator_Factory_i::content_type (const char * filename,
                                  Web_Server::Metadata_Type_out metadata)
{
  if (filename == 0)
    return -1;

  // @@ There are a bunch of const_casts in this method.  It's ugly.
  //    I know.
  //        -Ossama

  size_t len = ACE_OS::strlen (filename);

  // Search for extension
  // Handle the case where multiple periods exists in the filename,
  // e.g.:  foo.bar.ps
  char * extension = 0;
  for (char * tmp = ACE_const_cast (char *, filename);
       tmp != 0 && tmp != tmp + len;
       )
    {
      tmp = ACE_const_cast (char *,
                            ACE_OS::strchr (tmp, '.'));

      if (tmp != 0)
        extension = ++tmp;  // Skip over the '.'
    }

  if (extension == 0)
    extension = ACE_const_cast (char *, filename);  // No extension!

  if (ACE_OS::strcasecmp (extension, "htm") == 0
      || ACE_OS::strcasecmp (extension, "html") == 0)
    {
      metadata->content_type = CORBA::string_dup ("text/html");
    }
  else if (ACE_OS::strcasecmp (extension,
                               "txt") == 0)
    {
      metadata->content_type = CORBA::string_dup ("text/plain");
    }
  else if (ACE_OS::strcasecmp (extension,
                               "ps") == 0)
    {
      metadata->content_type =
        CORBA::string_dup ("application/postscript");
    }
  else if (ACE_OS::strcasecmp (extension,
                               "pdf") == 0)
    {
      metadata->content_type = CORBA::string_dup ("application/pdf");
    }
  else if (ACE_OS::strcasecmp (extension,
                               "jpeg") == 0
           || ACE_OS::strcasecmp (extension,
                                  "jpg") == 0)
    {
      metadata->content_type = CORBA::string_dup ("image/jpeg");
    }
  else if (ACE_OS::strcasecmp (extension,
                               "tiff") == 0)
    {
      metadata->content_type = CORBA::string_dup ("image/tiff");
    }
  else if (ACE_OS::strcasecmp (extension,
                               "gif") == 0)
    {
      metadata->content_type = CORBA::string_dup ("image/gif");
    }
  else if (ACE_OS::strcasecmp (extension,
                               "png") == 0)
    {
      metadata->content_type = CORBA::string_dup ("image/png");
    }
  else
    {
      metadata->content_type = CORBA::string_dup ("text/html");
      ACE_ERROR ((LM_WARNING,
                  "\n  "
                  "Unknown file type.  "
                  "Using \"text/html\" content type.\n"));
    }

  return 0;
}
