// $Id$

#include "JAWS/JAWS.h"
#include "JAWS/IO.h"
#include "JAWS/IO_Handler.h"
#include "JAWS/Policy.h"

#include "HTTP_10.h"

ACE_RCSID(PROTOTYPE, HTTP_10_Write, "$Id$")

// --------------- WRITE TASK ----------------------

JAWS_HTTP_10_Write_Task::JAWS_HTTP_10_Write_Task (void)
{
}

JAWS_HTTP_10_Write_Task::~JAWS_HTTP_10_Write_Task (void)
{
}

int
JAWS_HTTP_10_Write_Task::handle_put (JAWS_Data_Block *data, ACE_Time_Value *)
{
  JAWS_TRACE ("JAWS_HTTP_10_Write_Task::handle_put");

  JAWS_IO_Handler *handler = data->io_handler ();
  JAWS_Dispatch_Policy *policy = this->policy ();
  if (policy == 0) policy = data->policy ();

  JAWS_IO *io = policy->io ();

  JAWS_HTTP_10_Request *info = ACE_static_cast (JAWS_HTTP_10_Request *,
                                                data->payload ());

  ACE_DEBUG ((LM_DEBUG, " (%t) request %s::%s::%s parsed\n",
              (info->method () ? info->method () : "-"),
              (info->uri () ? info->uri () : "="),
              (info->version () ? info->version () : "HTTP/0.9")));

#if 0
  JAWS_HTTP_10_Headers *table = info->table ();
  Symbol_Table_Iterator &iter = table->iter ();
  for (iter.first (); ! iter.is_done (); iter.next ())
    {
      ACE_DEBUG ((LM_DEBUG, " (%t) header %s::%s\n",
                  *(iter.key ()),
                  *(iter.item ())));
    }

  char message[] = "<html><h1>This is a test</h1></html>\n";

  io->send_error_message (handler, message, sizeof (message));
  if (handler->status () == JAWS_IO_Handler::WRITE_OK)
    {
      return 0;
    }

  return -1;
#else

  if (info->type () != JAWS_HTTP_10_Request::GET)
    info->status (JAWS_HTTP_10_Request::STATUS_NOT_IMPLEMENTED);

  if (info->type () == JAWS_HTTP_10_Request::QUIT)
    info->status (JAWS_HTTP_10_Request::STATUS_QUIT);

  if (info->status () != JAWS_HTTP_10_Request::STATUS_OK)
    {
      char *msg =
        "<html><head><title>HTTP/1.0 500 Internal Server Error</title>"
        "<body><h1>Server Error</h1>HTTP/1.0 500 Internal Server Error"
        "</body></html>";

      io->send_error_message (handler, msg, sizeof (msg));
      if (handler->status () == JAWS_IO_Handler::WRITE_OK)
        {
          JAWS_HTTP_10_Headers *table = info->table ();
          Symbol_Table_Iterator &iter = table->iter ();
          for (iter.first (); ! iter.is_done (); iter.next ())
            {
              table->remove (*(iter.key ()));
              ACE_OS::free ((void *) *(iter.key ()));
              ACE_OS::free ((void *) *(iter.item ()));
            }
          int result = (info->status () == JAWS_HTTP_10_Request::STATUS_QUIT);
          delete info;
          return -result;
        }
    }
  else
    {
      io->transmit_file (handler,
                         info->path (),
                         "",
                         0,
                         "",
                         0);

      JAWS_HTTP_10_Headers *table = info->table ();
      Symbol_Table_Iterator &iter = table->iter ();
      for (iter.first (); ! iter.is_done (); iter.next ())
        {
          table->remove (*(iter.key ()));
          ACE_OS::free ((void *) *(iter.key ()));
          ACE_OS::free ((void *) *(iter.item ()));
        }

      switch (handler->status ())
        {
        case JAWS_IO_Handler::TRANSMIT_OK:
          delete info;
          return 0;
        case JAWS_IO_Handler::TRANSMIT_ERROR:
          delete info;
          return -1;
        default:
          delete info;
          return 1;
        }
    }

  delete info;
  return -1;
#endif
}
