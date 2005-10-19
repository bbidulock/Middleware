// $Id$

#include "CSD_TP_Custom_Synch_Request.h"

ACE_RCSID (CSD_ThreadPool,
           TP_Custom_Synch_Request,
           "$Id$")

#if !defined (__ACE_INLINE__)
# include "CSD_TP_Custom_Synch_Request.inl"
#endif /* ! __ACE_INLINE__ */


TAO::CSD::TP_Custom_Synch_Request::~TP_Custom_Synch_Request()
{
}


void
TAO::CSD::TP_Custom_Synch_Request::dispatch_i()
{
  this->execute_op();
  this->synch_helper_.dispatched();
}


void
TAO::CSD::TP_Custom_Synch_Request::cancel_i()
{
  this->cancel_op();
  this->synch_helper_.cancelled();
}
