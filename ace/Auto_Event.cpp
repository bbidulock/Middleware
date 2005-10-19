// $Id$

#include "ace/Auto_Event.h"

#if !defined (__ACE_INLINE__)
#include "ace/Auto_Event.inl"
#endif /* __ACE_INLINE__ */


ACE_RCSID(ace, Auto_Event, "$Id$")

ACE_Auto_Event::ACE_Auto_Event (int initial_state,
                                int type,
                                const char *name,
                                void *arg)
  : ACE_Event (0,
               initial_state,
               type,
               ACE_TEXT_TO_TCHAR_IN (name),
               arg)
{
}

ACE_Auto_Event::ACE_Auto_Event (int initial_state,
                                int type,
                                const wchar_t *name,
                                void *arg)
  : ACE_Event (0,
               initial_state,
               type,
               ACE_TEXT_TO_TCHAR_IN (name),
               arg)
{
}

void
ACE_Auto_Event::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_Event::dump ();
#endif /* ACE_HAS_DUMP */
}
