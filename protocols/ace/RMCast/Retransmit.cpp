// file      : ace/RMCast/Retransmit.cpp
// author    : Boris Kolpackov <boris@kolpackov.net>
// cvs-id    : $Id$

#include "ace/Time_Value.h"     // ACE_Time_Value
#include "ace/OS_NS_sys_time.h" // gettimeofday

#include "Retransmit.h"

namespace ACE_RMCast
{
  ACE_Time_Value const tick (0, 50000);
  unsigned long const retention_time = 60; // How many ticks to retain.

  Retransmit::
  Retransmit ()
      : cond_ (mutex_),
        sn_ (1),
        stop_ (false)
  {
  }

  void Retransmit::
  out_start (Out_Element* out)
  {
    Element::out_start (out);

    tracker_mgr_.spawn (track_thunk, this);
  }

  void Retransmit::
  out_stop ()
  {
    {
      Lock l (mutex_);
      stop_ = true;
      cond_.signal ();
    }

    tracker_mgr_.wait ();

    Element::out_stop ();
  }

  void Retransmit::
  send (Message_ptr m)
  {
    if (m->find (Data::id) != 0)
    {
      m->add (Profile_ptr (new SN (sn_)));

      Lock l (mutex_);
      queue_.bind (sn_++, Descr (m->clone ()));
    }

    out_->send (m);
  }

  void Retransmit::
  recv (Message_ptr m)
  {
    if (NAK const* nak = static_cast<NAK const*> (m->find (NAK::id)))
    {
      Address to (static_cast<To const*> (m->find (To::id))->address ());

      if (nak->address () == to)
      {
        Lock l (mutex_);

        for (NAK::iterator j (const_cast<NAK*> (nak)->begin ());
             !j.done ();
             j.advance ())
        {
          u64* psn;
          j.next (psn);

          Message_ptr m;

          Queue::ENTRY* pair;

          if (queue_.find (*psn, pair) == 0)
          {
            //cerr << 5 << "PRTM " << to << " " << pair->ext_id_ << endl;

            m = pair->int_id_.message ();

            pair->int_id_.reset ();
          }
          else
          {
            //cerr << 4 << "message " << *psn << " not available" << endl;

            m = Message_ptr (new Message);
            m->add (Profile_ptr (new SN (*psn)));
            m->add (Profile_ptr (new NoData));
          }

          out_->send (m);
        }
      }
    }
    else
    {
      in_->recv (m);
    }
  }

  ACE_THR_FUNC_RETURN Retransmit::
  track_thunk (void* obj)
  {
    reinterpret_cast<Retransmit*> (obj)->track ();
    return 0;
  }

  void Retransmit::
  track ()
  {
    while (true)
    {
      Lock l (mutex_);

      for (Queue::iterator i (queue_); !i.done ();)
      {
        if ((*i).int_id_.inc () >= retention_time)
        {
          u64 sn ((*i).ext_id_);
          i.advance ();
          queue_.unbind (sn);
        }
        else
        {
          i.advance ();
        }
      }

      // Go to sleep but watch for "manual cancellation" request.
      //
      ACE_Time_Value time (ACE_OS::gettimeofday ());
      time += tick;

      while (!stop_)
      {
        if (cond_.wait (&time) == -1)
        {
          if (errno != ETIME)
            abort ();
          else
            break;
        }
      }

      if (stop_)
        break;
    }
  }
}
