// $Id$

#include "CSD_TP_Request.h"

ACE_RCSID (CSD_ThreadPool,
           TP_Request,
           "$Id$")

#if !defined (__ACE_INLINE__)
# include "CSD_TP_Request.inl"
#endif /* ! __ACE_INLINE__ */


TAO::CSD::TP_Request::~TP_Request()
{
}


void
TAO::CSD::TP_Request::prepare_for_queue_i()
{
  // Default implementation is to do nothing.  Subclasses can provide
  // their own implementation if needed.
}
