// -*- C++ -*-
//
// $Id$

#include "ace/config-all.h"
#include "ace/OS_NS_errno.h"

template <class ACE_LOCKING_MECHANISM> ACE_INLINE
ACE_Reverse_Lock<ACE_LOCKING_MECHANISM>::ACE_Reverse_Lock (
  ACE_LOCKING_MECHANISM &lock,
  ACE_Acquire_Method::METHOD_TYPE acquire_method)
  : lock_ (lock),
    acquire_method_ (acquire_method)
{
}
