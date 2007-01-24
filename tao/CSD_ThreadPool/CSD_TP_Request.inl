// -*- C++ -*-
//
// $Id$

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
TAO::CSD::TP_Request::TP_Request(PortableServer::Servant servant,
                                 TP_Servant_State*       servant_state)
  : prev_(0),
    next_(0),
    servant_ (servant),
    servant_state_(servant_state, false)
{
  // This try-catch block is not really necessary for current implementation
  // since the _add_ref does not throw exception, but we have to add it to
  // satisfy the non-exception builds. If _add_ref really throws an exception
  // then this constructor needs deal with the exception.
  try
  {
    this->servant_->_add_ref ();
  }
  catch (...)
  {
  }
}


ACE_INLINE
void
TAO::CSD::TP_Request::prepare_for_queue()
{
  this->prepare_for_queue_i();
}


ACE_INLINE
PortableServer::Servant
TAO::CSD::TP_Request::servant()
{
  // Used for chaining so we do not return a new "copy".
  return this->servant_.in();
}


ACE_INLINE
bool
TAO::CSD::TP_Request::is_ready() const
{
  if (this->servant_state_.is_nil())
    {
      // This means that the serialization of servants is off.
      // We always answer true here to indicate that the servant is
      // never busy.
      return true;
    }

  return !this->servant_state_->busy_flag();
}


ACE_INLINE
void
TAO::CSD::TP_Request::mark_as_busy()
{
  if (!this->servant_state_.is_nil())
    {
      this->servant_state_->busy_flag(true);
    }
}


ACE_INLINE
void
TAO::CSD::TP_Request::mark_as_ready()
{
  if (!this->servant_state_.is_nil())
    {
      this->servant_state_->busy_flag(false);
    }
}


ACE_INLINE
bool
TAO::CSD::TP_Request::is_target(PortableServer::Servant servant)
{
  // Compare pointers.  Return true only if these are the exact same object.
  return (servant == this->servant_.in());
}


ACE_INLINE
void
TAO::CSD::TP_Request::dispatch()
{
  this->dispatch_i();

}


ACE_INLINE
void
TAO::CSD::TP_Request::cancel()
{
  this->cancel_i();
}

TAO_END_VERSIONED_NAMESPACE_DECL
