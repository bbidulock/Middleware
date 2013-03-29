// -*- C++ -*-
// $Id$

#include "LiveCheck.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"
#include "ace/OS_NS_time.h"

LiveListener::LiveListener (const char *server)
  : server_(server)
{
}

const char *
LiveListener::server (void) const
{
  return this->server_;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

const int LiveEntry::reping_msec_[] = {0, 10, 100, 500, 1000, 1000,
                                             1000, 1000, 5000, 5000};
int LiveEntry::reping_limit_ = sizeof (LiveEntry::reping_msec_) / sizeof (int);

void
LiveEntry::set_reping_limit (int max)
{
  LiveEntry::reping_limit_ = max;
}

bool
LiveEntry::reping_available (void)
{
  return this->repings_ < LiveEntry::reping_limit_;
}

int
LiveEntry::next_reping (void)
{
  if ( this->repings_ < LiveEntry::reping_limit_)
    {
      return LiveEntry::reping_msec_[this->repings_++];
    }
  else
    return -1;
}

LiveEntry::LiveEntry (LiveCheck *owner,
                      const char *server,
                      ImplementationRepository::ServerObject_ptr ref)
  : owner_ (owner),
    server_ (server),
    ref_ (ImplementationRepository::ServerObject::_duplicate (ref)),
    liveliness_ (LS_UNKNOWN),
    next_check_ (ACE_OS::time()),
    retry_count_ (0),
    repings_ (0),
    listeners_ (),
    lock_ ()
{
}

LiveEntry::~LiveEntry (void)
{
}

void
LiveEntry::add_listener (LiveListener* ll)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, mon, this->lock_);
  this->listeners_.insert (ll);
  //  ACE_DEBUG ((LM_DEBUG, "LiveEntry(%s)::add_listener\n", this->server_.c_str()));
}

LiveStatus
LiveEntry::status (void) const
{
  if ( this->liveliness_ == LS_ALIVE &&
       this->owner_->ping_interval() != ACE_Time_Value::zero )
    {
      ACE_Time_Value now (ACE_OS::time());
      if (now >= this->next_check_)
        {
          return LS_UNKNOWN;
        }
    }
  return this->liveliness_;
}

void
LiveEntry::status (LiveStatus l)
{
  {
    ACE_GUARD (TAO_SYNCH_MUTEX, mon, this->lock_);
    this->liveliness_ = l;
  }
  if (l == LS_ALIVE)
    {
      this->retry_count_ = 0;
      ACE_Time_Value now (ACE_OS::time());
      this->next_check_ = now + owner_->ping_interval();
    }
  ACE_DEBUG ((LM_DEBUG, "LiveEntry(%s)::status updating listeners, size = %d\n",
              this->server_.c_str(), this->listeners_.size()));

  LiveStatus ls = this->liveliness_;
  if (ls == LS_TRANSIENT && ! this->reping_available())
    ls = LS_LAST_TRANSIENT;
  for (Listen_Set::ITERATOR i(this->listeners_);
       !i.done();
       i.advance ())
    {
      LiveListener **ll = 0;
      i.next (ll);
      if (*ll != 0)
        {
          if ((*ll)->status_changed (this->liveliness_))
            {
              ACE_GUARD (TAO_SYNCH_MUTEX, mon, this->lock_);
              this->listeners_.remove (*ll);
            }
        }
    }

  if (this->listeners_.size() > 0)
    {
      this->owner_->schedule_ping (this);
    }

  // ACE_DEBUG ((LM_DEBUG, "LiveEntry(%s)::status updating listeners done, size = %d\n",
  //             this->server_.c_str(), this->listeners_.size()));

}

const ACE_Time_Value &
LiveEntry::next_check (void) const
{
  return this->next_check_;
}

bool
LiveEntry::do_ping (PortableServer::POA_ptr poa)
{
  ACE_Time_Value now (ACE_OS::time());
  if (this->liveliness_ == LS_PING_AWAY)
    {
      ACE_DEBUG ((LM_DEBUG, "LiveEntry(%s)::do_ping, ping_away_ is true\n",
                  this->server_.c_str()));
      return false;
    }

  if (this->next_check_ > now || this->liveliness_ == LS_DEAD)
    {
      ACE_Time_Value diff = next_check_ - now;
      ACE_DEBUG ((LM_DEBUG, "LiveEntry(%s)::do_ping, too soon = %d, come back in %d ms, status = %d\n",
                  this->server_.c_str(), (this->next_check_ > now), diff.sec() * 1000 + (diff.usec() / 1000), liveliness_));
      return true;
    }

  switch (this->liveliness_)
    {
    case LS_UNKNOWN:
      this->next_check_ = now;
      break;
    case LS_ALIVE:
    case LS_TIMEDOUT:
      this->next_check_ = now + owner_->ping_interval();
      break;
    case LS_TRANSIENT:
      {
        int ms = this->next_reping ();
        if (ms != -1)
          {
            ACE_Time_Value next (ms / 1000, (ms % 1000) * 1000);
            this->next_check_ = now + next;
          }
        else
          {
            ACE_DEBUG ((LM_DEBUG, "LiveEntry(%s)::do_ping, transient, but no next\n",
                        this->server_.c_str()));
            return false;
          }
      }
      break;
    default:;
    }

  {
    ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, mon, this->lock_, false);
    this->liveliness_ = LS_PING_AWAY;
    this->retry_count_++;
  }
  ACE_DEBUG ((LM_DEBUG, "LiveEntry(%s)::do_ping, sending ping, retry count = %d\n",
              this->server_.c_str(), retry_count_));
  PortableServer::ServantBase_var callback = new PingReceiver (this, poa);
  PortableServer::ObjectId_var oid = poa->activate_object (callback.in());
  CORBA::Object_var obj = poa->id_to_reference (oid.in());
  ImplementationRepository::AMI_ServerObjectHandler_var cb =
    ImplementationRepository::AMI_ServerObjectHandler::_narrow (obj.in());
  this->ref_->sendc_ping (cb.in());
  return false;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

PingReceiver::PingReceiver (LiveEntry *entry, PortableServer::POA_ptr poa)
  :poa_ (PortableServer::POA::_duplicate(poa)),
   entry_ (entry)
{
}

PingReceiver::~PingReceiver (void)
{
}

void
PingReceiver::ping (void)
{
  ACE_DEBUG ((LM_DEBUG, "PingReceiver::ping\n"));
  this->entry_->status (LS_ALIVE);
  PortableServer::ObjectId_var oid = this->poa_->servant_to_id (this);
  poa_->deactivate_object (oid.in());
}

void
PingReceiver::ping_excep (Messaging::ExceptionHolder * excep_holder)
{
  try
    {
      ACE_DEBUG ((LM_DEBUG, "PingReceiver::ping_excep\n"));
      excep_holder->raise_exception ();
    }
  catch (CORBA::TRANSIENT &ex)
    {
      const CORBA::ULong BITS_5_THRU_12_MASK = 0x00000f80;
      switch (ex.minor () & BITS_5_THRU_12_MASK)
        {
        case TAO_POA_DISCARDING:
        case TAO_POA_HOLDING:
          {
            this->entry_->status (LS_TRANSIENT);
            break;
          }
        default: //case TAO_INVOCATION_SEND_REQUEST_MINOR_CODE:
          {
            this->entry_->status (LS_DEAD);
          }
        }
    }
  catch (CORBA::TIMEOUT &)
    {
      this->entry_->status (LS_TIMEDOUT);
    }
  catch (CORBA::Exception &)
    {
      this->entry_->status (LS_DEAD);
    }

  PortableServer::ObjectId_var oid = this->poa_->servant_to_id (this);
  poa_->deactivate_object (oid.in());
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

LiveCheck::LiveCheck ()
  :ping_interval_()
{
}

LiveCheck::~LiveCheck (void)
{
  while (this->entry_map_.current_size() > 0)
    {
      LiveEntryMap::iterator i (this->entry_map_);
      LiveEntryMap::value_type *pair = 0;
      i.next (pair);
      this->entry_map_.unbind(pair);
      delete pair->item();
    }
}

void
LiveCheck::init (CORBA::ORB_ptr orb,
                 const ACE_Time_Value &pi )
{
  this->ping_interval_ = pi;
  ACE_Reactor *r = orb->orb_core()->reactor();
  this->reactor (r);
  CORBA::Object_var obj = orb->resolve_initial_references ("RootPOA");
  this->poa_ = PortableServer::POA::_narrow (obj.in());
}

const ACE_Time_Value &
LiveCheck::ping_interval (void) const
{
  return this->ping_interval_;
}

int
LiveCheck::handle_timeout (const ACE_Time_Value &,
                           const void *)
{
  ACE_DEBUG ((LM_DEBUG, "LiveCheck::handle_timeout\n"));
  bool want_reping = false;
  ACE_Time_Value next;
  for (LiveEntryMap::iterator le (this->entry_map_);
       !le.done ();
       le.advance ())
    {
      LiveEntryMap::value_type *pair = 0;
      le.next(pair);
      if (pair->item()->do_ping (poa_.in ()))
        {
          LiveStatus status = pair->item ()->status ();
          if (status != LS_DEAD)
            {
              if (!want_reping || pair->item ()->next_check() < next)
                {
                  want_reping = true;
                  next = pair->item ()->next_check();
                }
            }
        }
    }
  for (PerClientStack::ITERATOR pe (this->per_client_);
       !pe.done ();
       pe.advance ())
    {
      LiveEntry **entry = 0;
      pe.next(entry);
      if (*entry != 0)
        {
          bool result = (*entry)->do_ping (poa_.in ());
          LiveStatus status = (*entry)->status ();
          if (result)
            {
              if (status != LS_DEAD)
                {
                  if (!want_reping || (*entry)->next_check() < next)
                    {
                      want_reping = true;
                      next = (*entry)->next_check();
                    }
                }
            }
          else
            {
              if (status != LS_PING_AWAY && status != LS_TRANSIENT)
                {
                  this->per_client_.remove (*entry);
                }
            }
        }
    }

  if (want_reping)
    {
      ACE_Time_Value now (ACE_OS::time());
      ACE_Time_Value delay = next - now;
      ACE_DEBUG ((LM_DEBUG, "LiveCheck::handle_timeout schdeuling next - in %d ms \n",
                  delay.sec() * 1000 + (delay.usec()/1000)));
      this->reactor()->schedule_timer (this, 0, delay);
    }

  return 0;
}

void
LiveCheck::add_server (const char *server,
                       ImplementationRepository::ServerObject_ptr ref)
{
  ACE_CString s (server);
  LiveEntry *entry = 0;
  ACE_NEW (entry, LiveEntry (this, server, ref));
  int result = entry_map_.bind (s, entry);
  if (result != 0)
    {
      LiveEntry *old = 0;
      result = entry_map_.rebind (s, entry, old);
      delete old;
    }
}

void
LiveCheck::remove_server (const char *server)
{
  ACE_CString s(server);
  LiveEntry *entry = 0;
  int result = entry_map_.unbind (s, entry);
  if (result == 0)
    delete entry;
}

void
LiveCheck::remove_per_client_entry (LiveEntry *e)
{
  this->per_client_.remove (e);
}

bool
LiveCheck::add_per_client_listener (LiveListener *l,
                                    ImplementationRepository::ServerObject_ptr ref)
{
  LiveEntry *entry = 0;
  ACE_NEW_RETURN (entry, LiveEntry (this, 0, ref), false);
  if (this->per_client_.push(entry) == 0)
    {
      entry->add_listener (l);
      this->reactor()->schedule_timer (this,0,ACE_Time_Value::zero);
      return true;
    }
  return false;
}

bool
LiveCheck::add_listener (LiveListener *l)
{
  LiveEntry *entry = 0;
  ACE_CString key (l->server());
  int result = entry_map_.find (key, entry);
  if (result == -1 || entry == 0)
    {
      return false;
    }

  entry->add_listener (l);
  this->schedule_ping (entry);
  return true;
}

void
LiveCheck::schedule_ping (LiveEntry *entry)
{
  ACE_Time_Value now (ACE_OS::time());
  ACE_Time_Value next = entry->next_check ();

  if (next <= now)
    {
      ACE_DEBUG ((LM_DEBUG, "LiveCheck::schedule_ping - immediate \n"));
      this->reactor()->schedule_timer (this,0,ACE_Time_Value::zero);
    }
  else
    {
      ACE_Time_Value delay = next - now;
      ACE_DEBUG ((LM_DEBUG, "LiveCheck::schedule_ping - in %dms \n",
                  delay.sec() * 1000 + (delay.usec()/1000)));
      this->reactor()->schedule_timer (this, 0, delay);
    }
}

LiveStatus
LiveCheck::is_alive (const char *server)
{
  if (this->ping_interval_ == ACE_Time_Value::zero)
    {
      return LS_ALIVE;
    }

  ACE_CString s(server);
  LiveEntry *entry = 0;
  int result = entry_map_.find (s, entry);
  if (result == 0 && entry != 0)
    {
      return entry->status ();
    }
  return LS_DEAD;
}
