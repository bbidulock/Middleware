// $Id$

#include "Memory_Pools.h"
#include "Event_Channel.h"

#if !defined (__ACE_INLINE__)
#include "Memory_Pools.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Event, Memory_Pools, "$Id$")

//ACE_TSS<ACE_ES_Dispatch_Request_Allocator> ACE_ES_Memory_Pools::Dispatch_Request_;

// ************************************************************

int
ACE_ES_Memory_Pools::thr_init (void)
{
  // Allocate the memory pool for this thread.
  //Dispatch_Request_.ts_object ();
  //Event_.ts_object ();
  return 0;
}

// ************************************************************

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Singleton<ACE_ES_Dispatch_Request_Allocator,ACE_SYNCH_MUTEX>;

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Singleton<ACE_ES_Dispatch_Request_Allocator,ACE_SYNCH_MUTEX>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
