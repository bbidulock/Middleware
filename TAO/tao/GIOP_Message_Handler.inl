// -*- C++ -*-
// $Id$

ACE_INLINE TAO_GIOP_Message_State &
TAO_GIOP_Message_Handler::message_state (void)
{
  return this->message_state_;
}

ACE_INLINE ACE_Message_Block *
TAO_GIOP_Message_Handler::message_block (void)
{
  // The read pointer should be after the  GIOP header
  return &this->current_buffer_;
}

ACE_INLINE void
TAO_GIOP_Message_Handler::reset (int /*reset_flag*/)
{
  // Reset the contents of the message state
  this->message_state_.reset (0);

  // Reset the current buffer
  this->current_buffer_.reset ();
}
