// file      : ace/RMCast/Retransmit.cpp
// author    : Boris Kolpackov <boris@kolpackov.net>
// cvs-id    : $Id$

#include <ace/OS.h>

#include <ace/RMCast/Retransmit.h>

namespace ACE_RMCast
{
  ACE_Time_Value const tick (0, 50000);

  Retransmit::
  Retransmit ()
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
    tracker_mgr_.cancel_all (1);
    tracker_mgr_.wait ();

    Element::out_stop ();
  }

  void Retransmit::
  send (Message_ptr m)
  {
    if (Data const* data = static_cast<Data const*> (m->find (Data::id)))
    {
      u64 sn (static_cast<SN const*> (m->find (SN::id))->num ());

      Lock l (mutex_);

      queue_.bind (sn, Descr (new Data (*data)));
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


          Queue::ENTRY* pair;

          if (queue_.find (*psn, pair) == 0)
          {
            //cerr << 5 << "PRTM " << to << " " << pair->ext_id_ << endl;

            Message_ptr m (new Message);

            m->add (Profile_ptr (new SN (pair->ext_id_)));
            m->add (pair->int_id_.data ());

            pair->int_id_.reset ();

            out_->send (m);
          }
          else
          {
            //@@ TODO: message aging
            //
            //cerr << 4 << "message " << *psn << " not available" << endl;
          }
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
      {
        Lock l (mutex_);

        for (Queue::iterator i (queue_); !i.done ();)
        {
          if ((*i).int_id_.inc () >= 60)
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
      }

      ACE_OS::sleep (tick);
    }
  }
}
