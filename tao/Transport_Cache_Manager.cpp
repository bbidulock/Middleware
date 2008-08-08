//$Id$
#include "tao/Transport_Cache_Manager.h"
#include "tao/Transport.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/Connection_Purging_Strategy.h"
#include "tao/Client_Strategy_Factory.h"
#include "tao/Condition.h"
#include "tao/Wait_Strategy.h"
#include "ace/ACE.h"
#include "ace/Reactor.h"

#if !defined (__ACE_INLINE__)
# include "tao/Transport_Cache_Manager.inl"
#endif /* __ACE_INLINE__ */


ACE_RCSID (tao,
           Transport_Cache_Manager,
           "$Id$")

// notes on debug level and LM_xxxx codes for transport cache
// TAO_debug_level > 0: recoverable error condition (LM_ERROR)
// TAO_debug_level > 4: normal transport cache operations (LM_INFO)
// TAO_debug_level > 6: detailed cache operations (LM_DEBUG)
// TAO_debug_level > 8: for debugging the cache itself (LM_DEBUG)


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  Transport_Cache_Manager::Transport_Cache_Manager (TAO_ORB_Core &orb_core)
    : percent_ (orb_core.resource_factory ()->purge_percentage ())
    , purging_strategy_ (orb_core.resource_factory ()->create_purging_strategy ())
    , cache_map_ (orb_core.resource_factory ()->cache_maximum ())
    , cache_lock_ (0)
  {
    if (orb_core.resource_factory ()->locked_transport_cache ())
      {
        ACE_NEW (this->cache_lock_,
                 ACE_Lock_Adapter <TAO_SYNCH_MUTEX> (this->cache_map_mutex_));
      }
    else
      {
        ACE_NEW (this->cache_lock_,
                 ACE_Lock_Adapter<ACE_SYNCH_NULL_MUTEX>);
      }

#if defined (TAO_HAS_MONITOR_POINTS) && (TAO_HAS_MONITOR_POINTS == 1)
    ACE_NEW (this->purge_monitor_,
             ACE::Monitor_Control::Size_Monitor);
    ACE_NEW (this->size_monitor_,
             ACE::Monitor_Control::Size_Monitor);

    ACE_CString purge_name ("Connection_Cache_Purge_");
    ACE_CString size_name ("Connection_Cache_Size_");

    purge_name += orb_core.orbid ();
    size_name += orb_core.orbid ();

    this->purge_monitor_->name (purge_name.c_str ());
    this->size_monitor_->name (size_name.c_str ());

    this->purge_monitor_->add_to_registry ();
    this->size_monitor_->add_to_registry ();
#endif /* TAO_HAS_MONITOR_POINTS==1 */
  }

  Transport_Cache_Manager::~Transport_Cache_Manager (void)
  {
    delete this->cache_lock_;
    this->cache_lock_ = 0;

    delete this->purging_strategy_;
    this->purging_strategy_ = 0;

#if defined (TAO_HAS_MONITOR_POINTS) && (TAO_HAS_MONITOR_POINTS == 1)
    this->purge_monitor_->remove_from_registry ();
    this->size_monitor_->remove_from_registry ();
    this->purge_monitor_->remove_ref ();
    this->size_monitor_->remove_ref ();
#endif /* TAO_HAS_MONITOR_POINTS==1 */
  }


  int
  Transport_Cache_Manager::bind_i (Cache_ExtId &ext_id,
                                   Cache_IntId &int_id)
  {
    if (TAO_debug_level > 4)
       {
         ACE_DEBUG ((LM_INFO,
            ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::bind_i: ")
            ACE_TEXT ("Transport[%d] @ hash:index{%d:%d}\n"),
            int_id.transport ()->id (),
            ext_id.hash (),
            ext_id.index ()
            ));
       }

    // Get the entry too
    HASH_MAP_ENTRY *entry = 0;

    // Update the purging strategy information while we
    // are holding our lock
    this->purging_strategy_->update_item (int_id.transport ());
    int retval = 0;
    bool more_to_do = true;
    while (more_to_do)
      {
        retval = this->cache_map_.bind (ext_id, int_id, entry);
        if (retval == 0)
          {
            // The entry has been added to cache succesfully
            // Add the cache_map_entry to the transport
            int_id.transport ()->cache_map_entry (entry);
            more_to_do = false;
          }
        else if (retval == 1)
          {
            if (entry->item ().transport () == int_id.transport ())
              {
                // update the cache status
                // we are already holding the lock, do not call set_entry_state
                entry->item ().recycle_state (int_id.recycle_state ());
                if (TAO_debug_level > 9 &&
                    entry->item ().is_connected_ != int_id.is_connected_)
                  ACE_DEBUG ((LM_DEBUG,
                              ACE_TEXT ("TAO (%P|%t) - Transport_Cache_")
                              ACE_TEXT ("Manager::bind_i: Updating existing ")
                              ACE_TEXT ("entry sets is_connected_ to %C\n"),
                              (int_id.is_connected_ ? "true" : "false")));

                entry->item ().is_connected_ = int_id.is_connected_;
                retval = 0;
                more_to_do = false;
              }
            else
            {
              ext_id.index (ext_id.index () + 1);
              if (TAO_debug_level > 8)
                {
                  ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::bind_i: ")
                    ACE_TEXT ("Unable to bind Transport[%d] @ hash:index{%d:%d}. ")
                    ACE_TEXT ("Trying with a new index \n"),
                    int_id.transport ()->id (),
                    ext_id.hash (),
                    ext_id.index ()));
                }
            }
          }
        else
          {
            if (TAO_debug_level > 0)
              {
                ACE_ERROR ((LM_ERROR,
                  "TAO (%P|%t) - Transport_Cache_Manager::bind_i, "
                  "ERROR: unable to bind transport\n"));
              }
            more_to_do = false;
          }
      }
    if (retval == 0)
      {
        if (TAO_debug_level > 4)
          {
            ACE_DEBUG ((LM_INFO,
              ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::bind_i: ")
              ACE_TEXT ("Success Transport[%d] @ hash:index{%d:%d}. ")
              ACE_TEXT ("Cache size is [%d]\n"),
              int_id.transport ()->id (),
              ext_id.hash (),
              ext_id.index (),
              this->current_size ()
              ));
          }
      }

#if defined (TAO_HAS_MONITOR_POINTS) && (TAO_HAS_MONITOR_POINTS == 1)
    this->size_monitor_->receive (this->current_size ());
#endif /* TAO_HAS_MONITOR_POINTS==1 */

    return retval;
  }

  Transport_Cache_Manager::Find_Result
  Transport_Cache_Manager::find_transport (
    TAO_Transport_Descriptor_Interface *prop,
    TAO_Transport *&transport,
    size_t &busy_count)
  {
    if (prop == 0)
      {
        transport = 0;
        return CACHE_FOUND_NONE;
      }

    Transport_Cache_Manager::Find_Result find_result = this->find (
      prop, transport, busy_count);
    if (find_result != CACHE_FOUND_NONE)
      {
        if (find_result == CACHE_FOUND_AVAILABLE)
          {
            if (transport->wait_strategy ()->non_blocking () == 0 &&
                transport->orb_core ()->client_factory ()->use_cleanup_options ())
              {
                ACE_Event_Handler * const eh =
                  transport->event_handler_i ();

                ACE_Reactor * const r =
                  transport->orb_core ()->reactor ();

                if (eh &&
                    r->remove_handler (eh,
                                       ACE_Event_Handler::READ_MASK |
                                       ACE_Event_Handler::DONT_CALL) == -1)
                  {
                    if (TAO_debug_level > 0)
                      ACE_ERROR ((LM_ERROR,
                                  ACE_TEXT ("TAO (%P|%t) - TAO_Transport_Cache_Manager[%d]")
                                  ACE_TEXT ("::find_transport, remove_handler failed \n"),
                                  transport->id ()));
                  }
                else
                  {
                    transport->wait_strategy ()->is_registered (false);
                  }
              }
          }
      }
    return find_result;
  }

  Transport_Cache_Manager::Find_Result
  Transport_Cache_Manager::find_i (
    TAO_Transport_Descriptor_Interface *prop,
    TAO_Transport *&transport,
    size_t &busy_count)
  {
    // Get the entry from the Hash Map
    Transport_Cache_Manager::Find_Result found = CACHE_FOUND_NONE;

    // Make a temporary object. It does not do a copy.
    Cache_ExtId key (prop);
    HASH_MAP_ENTRY *entry = 0;
    busy_count = 0;
    int cache_status = 0;
    HASH_MAP_ENTRY *found_entry = 0;

    // loop until we find a usable transport, or until we've checked
    // all cached entries for this endpoint
    while (found != CACHE_FOUND_AVAILABLE && cache_status == 0)
      {
        entry = 0;
        cache_status = this->cache_map_.find (key, entry);
        if (cache_status == 0 && entry)
          {
            if (this->is_entry_available (*entry))
              {
                // Successfully found a TAO_Transport.

                found = CACHE_FOUND_AVAILABLE;
                found_entry = entry;
                entry->item ().recycle_state (ENTRY_BUSY);

                if (TAO_debug_level > 6)
                  {
                    ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::find_i: ")
                      ACE_TEXT ("Found available Transport[%d] @hash:index {%d:%d}\n"),
                      entry->item ().transport ()->id (),
                      entry->ext_id_.hash (),
                      entry->ext_id_.index ()
                      ));
                  }
              }
            else if (this->is_entry_connecting (*entry))
              {
                if (TAO_debug_level > 6)
                  {
                    ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::find_i: ")
                      ACE_TEXT ("Found connecting Transport[%d] @hash:index {%d:%d}\n"),
                      entry->item ().transport ()->id (),
                      entry->ext_id_.hash (),
                      entry->ext_id_.index ()
                      ));
                  }
                // if this is the first interesting entry
                if (found != CACHE_FOUND_CONNECTING)
                  {
                    found_entry = entry;
                    found = CACHE_FOUND_CONNECTING;
                  }
              }
            else
              {
                // if this is the first busy entry
                if (found == CACHE_FOUND_NONE && busy_count == 0)
                  {
                    found_entry = entry;
                    found = CACHE_FOUND_BUSY;
                  }
                busy_count += 1;
                if (TAO_debug_level > 6)
                  {
                    ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::find_i: ")
                      ACE_TEXT ("Found busy Transport[%d] @hash:index {%d:%d}\n"),
                      entry->item ().transport ()->id (),
                      entry->ext_id_.hash (),
                      entry->ext_id_.index ()
                      ));
                  }
              }
          }

        // Bump the index up
        key.incr_index ();
      }
    if (found_entry != 0)
    {
      transport = found_entry->item ().transport ();
      transport->add_reference ();
      if (found == CACHE_FOUND_AVAILABLE)
        {
          // Update the purging strategy information while we
          // are holding our lock
          this->purging_strategy_->update_item (transport);
        }
    }
    return found;
  }

  int
  Transport_Cache_Manager::make_idle_i (HASH_MAP_ENTRY *entry)
  {
    if (entry == 0)
      return -1;

    entry->item ().recycle_state (ENTRY_IDLE_AND_PURGABLE);

    return 0;
  }

  int
  Transport_Cache_Manager::update_entry (HASH_MAP_ENTRY *&entry)
  {
    if(entry == 0)
      return -1;

    ACE_MT (ACE_GUARD_RETURN (ACE_Lock,
                              guard,
                              *this->cache_lock_, -1));

    if (entry == 0)
      return -1;

    TAO_Connection_Purging_Strategy *st = this->purging_strategy_;
    (void) st->update_item (entry->item ().transport ());

    return 0;
  }

  int
  Transport_Cache_Manager::close_i (Connection_Handler_Set &handlers)
  {
    HASH_MAP_ITER end_iter = this->cache_map_.end ();

    for (HASH_MAP_ITER iter = this->cache_map_.begin ();
         iter != end_iter;
         ++iter)
      {
        // Get the transport to fill its associated connection's handler.
        (*iter).int_id_.transport ()->provide_handler (handlers);

        // Inform the transport that has a reference to the entry in the
        // map that we are *gone* now. So, the transport should not use
        // the reference to the entry that he has, to access us *at any
        // time*.
        (*iter).int_id_.transport ()->cache_map_entry (0);
      }

    // Unbind all the entries in the map
    this->cache_map_.unbind_all ();

    return 0;
  }

  bool
  Transport_Cache_Manager::blockable_client_transports_i (
    Connection_Handler_Set &h)
  {
    HASH_MAP_ITER end_iter = this->cache_map_.end ();

    for (HASH_MAP_ITER iter = this->cache_map_.begin ();
         iter != end_iter;
         ++iter)
      {
        // Get the transport to fill its associated connection's
        // handler.
        bool const retval =
          (*iter).int_id_.transport ()->provide_blockable_handler (h);

        // Do not mark the entry as closed if we don't have a
        // blockable handler added
        if (retval)
          (*iter).int_id_.recycle_state (ENTRY_CLOSED);
      }

    return true;
  }

  int
  Transport_Cache_Manager::purge_entry_i (HASH_MAP_ENTRY *&entry)
  {
    if (entry == 0)
      {
        return 0;
      }

    // Remove the entry from the Map
    int const retval = this->cache_map_.unbind (entry);

    // Set the entry pointer to zero
    entry = 0;

#if defined (TAO_HAS_MONITOR_POINTS) && (TAO_HAS_MONITOR_POINTS == 1)
    this->size_monitor_->receive (this->current_size ());
#endif /* TAO_HAS_MONITOR_POINTS==1 */

    return retval;
  }

  void
  Transport_Cache_Manager::mark_invalid_i (HASH_MAP_ENTRY *entry)
  {
    if (entry != 0)
      {
        // Mark the entry as not usable
        entry->item ().recycle_state (ENTRY_PURGABLE_BUT_NOT_IDLE);
      }
  }

  bool
  Transport_Cache_Manager::is_entry_available (const HASH_MAP_ENTRY &entry)
  {
    Cache_Entries_State entry_state = entry.int_id_.recycle_state ();
    bool result = (entry_state == ENTRY_IDLE_AND_PURGABLE ||
                   entry_state == ENTRY_IDLE_BUT_NOT_PURGABLE);

    if (result && entry.int_id_.transport () != 0)
    {
      // if it's not connected, it's not available
      result = entry.int_id_.is_connected_;
    }

    if (TAO_debug_level > 8)
      {
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::")
                    ACE_TEXT ("is_entry_available: %C state is %C\n"),
                    (result ? "true" : "false"),
                    Cache_IntId::state_name (entry_state)));
      }

    return result;
  }

  bool
  Transport_Cache_Manager::is_entry_connecting (const HASH_MAP_ENTRY &entry)
  {
    Cache_Entries_State entry_state = entry.int_id_.recycle_state ();
    bool result = (entry_state == ENTRY_CONNECTING);

    if (!result && entry.int_id_.transport () != 0)
      {
        // if we're not connected, that counts, too.
        // Can this happen?  Not sure <wilsond@ociweb.com>
        result = !entry.int_id_.is_connected_;
      }

    if (TAO_debug_level > 8)
      {
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::")
                    ACE_TEXT ("is_entry_connecting: %C, state is %C\n"),
                    (result ? "true" : "false"),
                    Cache_IntId::state_name (entry_state)));
      }

    return result;
  }

#if !defined (ACE_LACKS_QSORT)
  int
  Transport_Cache_Manager::cpscmp(const void* a, const void* b)
  {
    const HASH_MAP_ENTRY** left  = (const HASH_MAP_ENTRY**)a;
    const HASH_MAP_ENTRY** right = (const HASH_MAP_ENTRY**)b;

    if ((*left)->int_id_.transport ()->purging_order () <
        (*right)->int_id_.transport ()->purging_order ())
      return -1;

    if ((*left)->int_id_.transport ()->purging_order () >
        (*right)->int_id_.transport ()->purging_order ())
      return 1;

    return 0;
  }
#endif /* ACE_LACKS_QSORT */

  int
  Transport_Cache_Manager::purge (void)
  {
    ACE_Unbounded_Stack<TAO_Transport*> transports_to_be_closed;

    {
      ACE_MT (ACE_GUARD_RETURN (ACE_Lock, ace_mon, *this->cache_lock_, 0));

      DESCRIPTOR_SET sorted_set = 0;
      int sorted_size = this->fill_set_i (sorted_set);

      // Only call close_entries () if sorted_set != 0.  It takes
      // control of sorted_set and cleans up any allocated memory.  If
      // sorted_set == 0, then there is nothing to de-allocate.
      if (sorted_set != 0)
        {
          // BEGIN FORMER close_entries
          // Calculate the number of entries to purge
          int const amount = (sorted_size * this->percent_) / 100;

          if (TAO_debug_level > 4)
            {
              ACE_DEBUG ((LM_INFO,
                ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::purge: ")
                ACE_TEXT ("Purging %d of %d cache entries\n"),
                amount,
                sorted_size));
            }

          int count = 0;

          for (int i = 0; count < amount && i < sorted_size; ++i)
            {
              if (this->is_entry_available (*sorted_set[i]))
                {
                  sorted_set[i]->int_id_.recycle_state (ENTRY_BUSY);

                  TAO_Transport* transport =
                    sorted_set[i]->int_id_.transport ();
                  transport->add_reference ();

                  if (TAO_debug_level > 4)
                    {
                      ACE_DEBUG ((LM_INFO,
                        ACE_TEXT ("TAO (%P|%t) Transport_Cache_Manager::purge ")
                        ACE_TEXT ("Purgable Transport[%d] found in ")
                        ACE_TEXT ("cache\n"),
                        transport->id ()));
                    }

                  if (transports_to_be_closed.push (transport) != 0)
                    {
                      if (TAO_debug_level > 0)
                        {
                          ACE_DEBUG ((LM_ERROR,
                            ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::purge: ")
                            ACE_TEXT ("Unable to push transport[%u] ")
                            ACE_TEXT ("on the to-be-closed stack, so ")
                            ACE_TEXT ("it will leak\n"),
                            transport->id ()));
                        }
                    }

                  // Count this as a successful purged entry
                  ++count;
                }
            }

          delete [] sorted_set;
          sorted_set = 0;
          // END FORMER close_entries
        }
    }

    // Now, without the lock held, lets go through and close all the transports.
    TAO_Transport *transport = 0;

    while (! transports_to_be_closed.is_empty ())
      {
        if (transports_to_be_closed.pop (transport) == 0)
          {
            if (transport)
              {
                transport->close_connection ();
                transport->remove_reference ();
              }
          }
      }
    if (TAO_debug_level > 4)
          {
            ACE_DEBUG ((LM_INFO,
              ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::purge: ")
              ACE_TEXT ("Cache size after purging is [%d]\n"),
              this->current_size ()
              ));
          }

#if defined (TAO_HAS_MONITOR_POINTS) && (TAO_HAS_MONITOR_POINTS == 1)
    /// The value doesn't matter, all we need is the timestamp,
    /// which is added automatically.
    this->purge_monitor_->receive (static_cast<size_t> (0UL));
    /// And update the size monitor as well.
    this->size_monitor_->receive (this->current_size ());
#endif /* TAO_HAS_MONITOR_POINTS==1 */

    return 0;
  }


  void
  Transport_Cache_Manager::sort_set (DESCRIPTOR_SET& entries,
                                     int current_size)
  {
#if defined (ACE_LACKS_QSORT)
    // Use insertion sort if we don't have qsort
    for(int i = 1; i < current_size; ++i)
      {
        if (entries[i]->int_id_.transport ()->purging_order () <
            entries[i - 1]->int_id_.transport ()->purging_order ())
          {
            HASH_MAP_ENTRY* entry = entries[i];

            for(int j = i; j > 0 &&
                  entries[j - 1]->int_id_.transport ()->purging_order () >
                  entry->item ().transport ()->purging_order (); --j)
              {
                HASH_MAP_ENTRY* holder = entries[j];
                entries[j] = entries[j - 1];
                entries[j - 1] = holder;
              }
          }
      }
#else
    ACE_OS::qsort (entries, current_size,
                   sizeof (HASH_MAP_ENTRY*), (ACE_COMPARE_FUNC)cpscmp);
#endif /* ACE_LACKS_QSORT */
  }


  int
  Transport_Cache_Manager::fill_set_i (DESCRIPTOR_SET& sorted_set)
  {
    int current_size = 0;
    int const cache_maximum = this->purging_strategy_->cache_maximum ();

    // set sorted_set to 0.  This signifies nothing to purge.
    sorted_set = 0;

    // Do we need to worry about cache purging?
    if (cache_maximum >= 0)
      {
        current_size = static_cast<int> (this->current_size ());

        if (TAO_debug_level > 6)
          {
            ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("TAO (%P|%t) - Transport_Cache_Manager::fill_set_i: ")
              ACE_TEXT ("current_size = %d, cache_maximum = %d\n"),
              current_size, cache_maximum));
          }

        if (current_size >= cache_maximum)
          {
            ACE_NEW_RETURN (sorted_set, HASH_MAP_ENTRY*[current_size], 0);

            HASH_MAP_ITER iter = this->cache_map_.begin ();

            for (int i = 0; i < current_size; ++i)
              {
                sorted_set[i] = &(*iter);
                iter++;
              }

            this->sort_set (sorted_set, current_size);
          }
      }

    return current_size;
  }

}

TAO_END_VERSIONED_NAMESPACE_DECL
