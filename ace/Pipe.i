/* -*- C++ -*- */
// $Id$

// Pipe.i

ASYS_INLINE ACE_HANDLE 
ACE_Pipe::read_handle (void) const
{
  ACE_TRACE ("ACE_Pipe::read_handle");
  return this->handles_[0];
}
  
ASYS_INLINE ACE_HANDLE 
ACE_Pipe::write_handle (void) const
{
  ACE_TRACE ("ACE_Pipe::write_handle");
  return this->handles_[1];
}
