/* -*- C++ -*- */
// $Id$

// Return flags currently associated with handle.

#include "ace/OS.h"

ASYS_INLINE int
ACE_Flag_Manip::get_flags (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Flag_Manip::get_flags");

#if defined (ACE_LACKS_FCNTL)
  // ACE_OS::fcntl is not supported, e.g., on VxWorks.  It
  // would be better to store ACE's notion of the flags
  // associated with the handle, but this works for now.
  ACE_UNUSED_ARG (handle);
  return 0;
#else
  return ACE_OS::fcntl (handle, F_GETFL, 0);
#endif /* ACE_LACKS_FCNTL */
}
