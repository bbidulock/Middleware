// FIFO.cpp
// $Id$

#include "ace/FIFO.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/FIFO.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, FIFO, "$Id$")

ACE_ALLOC_HOOK_DEFINE(ACE_FIFO)

void
ACE_FIFO::dump (void) const
{
  ACE_TRACE ("ACE_FIFO::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_LIB_TEXT ("rendezvous_ = %s"), this->rendezvous_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

int
ACE_FIFO::open (const ACE_TCHAR *r, int flags, int perms,
                LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_FIFO::open");
  ACE_OS::strsncpy (this->rendezvous_, r, MAXPATHLEN);

#if defined (ACE_PSOS_DIAB_MIPS)
  if ( ACE_OS::mkfifo (this->rendezvous_, perms) == -1
      && !(errno == EEXIST))
    return -1;
#else
  if ((flags & O_CREAT) != 0
      && ACE_OS::mkfifo (this->rendezvous_, perms) == -1
      && !(errno == EEXIST))
    return -1;
#endif

  this->set_handle (ACE_OS::open (this->rendezvous_, flags, 0, sa));
  return this->get_handle () == ACE_INVALID_HANDLE ? -1 : 0;
}

ACE_FIFO::ACE_FIFO (const ACE_TCHAR *fifo_name,
		    int flags,
		    int perms,
                    LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_FIFO::ACE_FIFO");
  if (this->open (fifo_name, flags, perms, sa) == -1)
    ACE_ERROR ((LM_ERROR,  ACE_LIB_TEXT ("%p\n"),  ACE_LIB_TEXT ("ACE_FIFO")));
}

ACE_FIFO::ACE_FIFO (void)
{
//  ACE_TRACE ("ACE_FIFO::ACE_FIFO");
}

int
ACE_FIFO::close (void)
{
  ACE_TRACE ("ACE_FIFO::close");
  int result = 0;

  if (this->get_handle () != ACE_INVALID_HANDLE)
    {
      result = ACE_OS::close (this->get_handle ());
      this->set_handle (ACE_INVALID_HANDLE);
    }
 return result;
}
