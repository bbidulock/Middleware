// $Id$

#include "CSD_TP_Custom_Asynch_Request.h"

ACE_RCSID (CSD_ThreadPool,
           TP_Custom_Asynch_Request,
           "$Id$")

#if !defined (__ACE_INLINE__)
# include "CSD_TP_Custom_Asynch_Request.inl"
#endif /* ! __ACE_INLINE__ */


TAO::CSD::TP_Custom_Asynch_Request::~TP_Custom_Asynch_Request()
{
}


void
TAO::CSD::TP_Custom_Asynch_Request::dispatch_i()
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      this->execute_op();
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      // Eat these.  We probably should log these, but since we have already
      // unblocked the requesting thread there is no point in saving it or
      // doing anything with it.
    }
#if defined (TAO_HAS_EXCEPTIONS)
  ACE_CATCHALL
    {
      // Eat these.  We probably should log these, but since we have already
      // unblocked the requesting thread there is no point in saving it or
      // doing anything with it.
    }
#endif
  ACE_ENDTRY;
}


void
TAO::CSD::TP_Custom_Asynch_Request::cancel_i()
{
  this->cancel_op();
}
