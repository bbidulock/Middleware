/* -*- c++ -*- */
// $Id$

#if !defined (JAWS_HTTP_10_H)
#define JAWS_HTTP_10_H

#include "ace/RB_Tree.h"

#include "JAWS/Pipeline_Tasks.h"

// Forward declaration
class JAWS_HTTP_10_Request;

// Reading the initial request

class JAWS_HTTP_10_Read_Task : public JAWS_Pipeline_Handler
{
public:
  JAWS_HTTP_10_Read_Task (void);
  virtual ~JAWS_HTTP_10_Read_Task (void);

  virtual int handle_put (JAWS_Data_Block *data, ACE_Time_Value *tv);

private:
};

// Parsing the request

class JAWS_HTTP_10_Parse_Task : public JAWS_Pipeline_Handler
{
public:
  JAWS_HTTP_10_Parse_Task (void);
  virtual ~JAWS_HTTP_10_Parse_Task (void);

  virtual int handle_put (JAWS_Data_Block *data, ACE_Time_Value *tv);

private:
  int parse_request (JAWS_HTTP_10_Request *info, JAWS_Data_Block *data);

  void parse_request_line (JAWS_HTTP_10_Request *info, char *line);
  void parse_header_line (JAWS_HTTP_10_Request *info, char *line);
};

// Write the response

class JAWS_HTTP_10_Write_Task : public JAWS_Pipeline_Handler
{
public:
  JAWS_HTTP_10_Write_Task (void);
  virtual ~JAWS_HTTP_10_Write_Task (void);

  virtual int handle_put (JAWS_Data_Block *data, ACE_Time_Value *tv);

private:
};

typedef RB_Tree<const char *, const char *> Symbol_Table;
typedef RB_Tree_Iterator<const char *, const char *> Symbol_Table_Iterator;

class JAWS_HTTP_10_Headers : public Symbol_Table
{
public:
  JAWS_HTTP_10_Headers (void);
  virtual ~JAWS_HTTP_10_Headers (void);

  virtual int lessthan (const char *const &k1, const char *const &k2);
  // virtual comparison hook in RB_Tree

  Symbol_Table_Iterator &iter (void);
  // returns an iterator to the headers container

private:
  Symbol_Table_Iterator iter_;
};

class JAWS_HTTP_10_Request
{
public:
  JAWS_HTTP_10_Request (void);
  ~JAWS_HTTP_10_Request (void);

  int reset (char *buffer, int buflen);

  void parse_request_line (char *request_line);
  void parse_header_line (char *header_line);

  int complete_header_line (char *line);
  int end_of_line (char *&line, int &offset) const;

  int got_request_line (void) const;
  int end_of_headers (void) const;
  int status (void) const;

  const char *method (void) const;
  const char *uri (void) const;
  const char *version (void) const;
  const char *path (void) const;

  void got_request_line (int flag);
  void end_of_headers (int flag);
  void status (int s);

  JAWS_HTTP_10_Headers *table (void);

  const char *method (const char *s);
  const char *uri (const char *s);
  const char *version (const char *s);
  const char *path (const char *s);


  int type (void);

  enum REQUEST_TYPE
  {
    NO_TYPE = -1,
    GET = 0,
    HEAD,
    POST,
    PUT,
    NUM_METHOD_STRINGS
  };

  enum STATUS_CODE
  {
    STATUS_OK = 200,
    STATUS_CREATED = 201,
    STATUS_ACCEPTED = 202,
    STATUS_NO_CONTENT = 204,
    STATUS_MOVED_PERMANENTLY = 301,
    STATUS_MOVED_TEMPORARILY = 302,
    STATUS_NOT_MODIFIED = 304,
    STATUS_BAD_REQUEST = 400,
    STATUS_UNAUTHORIZED = 401,
    STATUS_FORBIDDEN = 403,
    STATUS_NOT_FOUND = 404,
    STATUS_INTERNAL_SERVER_ERROR = 500,
    STATUS_NOT_IMPLEMENTED = 501,
    STATUS_BAD_GATEWAY = 502,
    STATUS_SERVICE_UNAVAILABLE = 503,
    STATUS_INSUFFICIENT_DATA = 399
  };

  enum
  {
    MAX_STATUS_CODE = 599
  };

private:
  int got_request_line_;
  int end_of_headers_;
  int status_;
  int type_;
  int content_length_;
  int datalen_;

  char *data_;
  char *method_;
  char *uri_;
  char *version_;
  char *path_;

  JAWS_HTTP_10_Headers table_;
};

class JAWS_HTTP_10_Helper
// Static functions to enhance the lives of HTTP programmers everywhere.
{
public:

  static char *HTTP_decode_string (char *path);
  // Decode '%' escape codes in a URI

};

#endif /* !defined (JAWS_HTTP_10_H) */
