#include "tao/Connection_Cache_Manager.h"
#include "tao/Connection_Handler.h"
#include "tao/debug.h"


#if !defined (__ACE_INLINE__)
# include "tao/Connection_Cache_Manager.inl"
#endif /* __ACE_INLINE__ */


ACE_RCSID(tao, Connection_Cache_Hash_Manager, "$Id$")


TAO_Connection_Cache_Manager::
    TAO_Connection_Cache_Manager (void)
      : cache_map_ ()
{
  ACE_NEW (this->cache_lock_,
           ACE_Lock_Adapter<ACE_SYNCH_MUTEX>);
}

TAO_Connection_Cache_Manager::~TAO_Connection_Cache_Manager (void)
{
  // Delete the lock that we have
  delete this->cache_lock_;
}



int
TAO_Connection_Cache_Manager::bind_i (TAO_Cache_ExtId &ext_id,
                                      TAO_Cache_IntId &int_id)
{
  // Get the entry too
  HASH_MAP_ENTRY *entry = 0;
  int retval = this->cache_map_.bind (ext_id,
                                      int_id,
                                      entry);
  if (retval == 0)
    {
      // The entry has been added to cache succesfully
      // Add the cache_map_entry to the handler
      int_id.handler () ->cache_map_entry (entry);
    }
  else if (retval == 1)
    {
      if (TAO_debug_level > 0 && retval != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("(%P|%t) TAO_Connection_Cache_Manager::bind_i")
                      ACE_TEXT (" unable to bind in the first attempt \n")
                      ACE_TEXT (" So trying with a new index \n")));
        }


      // There was an entry like this before, so let us do some
      // minor adjustments and rebind
      retval = this->get_last_index_bind (ext_id,
                                          int_id,
                                          entry);
      if (retval == 0)
        {
          int_id.handler ()->cache_map_entry (entry);
          int_id.recycle_state (ACE_RECYCLABLE_BUSY);
        }
    }

  if (TAO_debug_level > 0 && retval != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) TAO_Connection_Cache_Manager::bind_i")
                  ACE_TEXT (" unable to bind \n")));
    }

  return retval;
}


int
TAO_Connection_Cache_Manager::find_i (const TAO_Cache_ExtId &key,
                                      TAO_Cache_IntId &value)
{
  HASH_MAP_ENTRY *entry = 0;

  // Get the entry from the Hash Map
  int retval = 0;

  // Get the index of the <key>
  int index = key.index ();

  while (retval == 0)
    {
      // Make a temporary object. It does not do a copy.
      TAO_Cache_ExtId tmp_key (key.property ());

      // Look for an entry in the map
      retval = this->cache_map_.find (key,
                                      entry);

      // We have an entry in the map, check whether it is idle. If it
      // is idle it would be marked as busy.
      if (entry)
        {
          CORBA::Boolean idle =
            this->is_entry_idle (entry);

          if (idle)
            {
              // We have a succesful entry
              value = entry->int_id_;
              return 0;
            }
        }

      // Bump the index up
      tmp_key.index (++index);
    }

  // If we are here then it is an error
  if (TAO_debug_level > 0 && retval != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) TAO_Connection_Cache_Manager::find_i")
                  ACE_TEXT (" unable to locate a free connection \n")));
    }

  return retval;
}

int
TAO_Connection_Cache_Manager::rebind_i (const TAO_Cache_ExtId &key,
                                           const TAO_Cache_IntId &value)
{
  return this->cache_map_.rebind (key,
                                  value);
}

int
TAO_Connection_Cache_Manager::trybind_i (const TAO_Cache_ExtId &key,
                                         TAO_Cache_IntId &value)
{
  return this->cache_map_.trybind (key, value);
}

int
TAO_Connection_Cache_Manager::unbind_i (const TAO_Cache_ExtId &key)
{
  return this->cache_map_.unbind (key);
}

int
TAO_Connection_Cache_Manager::unbind_i (const TAO_Cache_ExtId &key,
                                        TAO_Cache_IntId &value)
{
  return this->cache_map_.unbind (key,
                          value);
}

int
TAO_Connection_Cache_Manager::make_idle_i (HASH_MAP_ENTRY *&entry)
{

  // First get the entry again (if at all things had changed in the
  // cache map in the mean time)
  HASH_MAP_ENTRY *new_entry = 0;
  int retval = this->cache_map_.find (entry->ext_id_,
                                      new_entry);
  if (retval == 0)
    {
      new_entry->int_id_.
        recycle_state (ACE_RECYCLABLE_IDLE_AND_PURGABLE);

      entry = new_entry;
    }
  else if (TAO_debug_level > 0 && retval != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) TAO_Connection_Cache_Manager::make_idle_i")
                  ACE_TEXT ("unable to locate the entry to make it idle \n")));
    }

  return retval;
}

int
TAO_Connection_Cache_Manager::mark_closed_i (HASH_MAP_ENTRY *&entry)
{
  // First get the entry again (if at all things had changed in the
  // cache map in the mean time)
  HASH_MAP_ENTRY *new_entry = 0;

  int retval = this->cache_map_.find (entry->ext_id_,
                                      new_entry);
  if (retval == 0)
    {
      new_entry->int_id_.
        recycle_state (ACE_RECYCLABLE_CLOSED);

      entry = new_entry;
    }
    else if (TAO_debug_level > 0 && retval != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) TAO_Connection_Cache_Manager::make_idle_i")
                  ACE_TEXT ("unable to locate the entry to mark it as closed \n")));
    }

  return retval;
}

int
TAO_Connection_Cache_Manager::close_i (ACE_Handle_Set &handle_set)
{


  for (HASH_MAP_ITER iter = this->cache_map_.begin ();
       iter != this->cache_map_.end ();
       iter ++)
    {

      // Should I look for IDLE & PURGABLE ones to remove? That would
      // sound odd as we would be called at ORB destruction time. So,
      // we should just go ahead and remove the entries from the map

      // As a first step, check whether the handler has been
      // registered with the reactor. If registered, then get the
      // handle and set that in the <handle_set> so that the ORB_Core
      // would deregister them from the reactor before shutdown.
      if ((*iter).int_id_.handler ()->is_registered ())
        {
          handle_set.set_bit ((*iter).int_id_.handler ()->fetch_handle ());
        }

      // Then decrement the reference count on the handler
      (*iter).int_id_.handler ()->decr_ref_count ();

      // Then remove the entry from the map
      // @@ When I get the purging ready, I should call purge () from
      // here.
      HASH_MAP_ENTRY &entry = (*iter);

      this->cache_map_.unbind (&entry);
    }

  return 0;
}

int
TAO_Connection_Cache_Manager::
    get_last_index_bind (TAO_Cache_ExtId &key,
                         TAO_Cache_IntId &val,
                         HASH_MAP_ENTRY *&entry)
{
  CORBA::ULong ctr = entry->ext_id_.index ();

  int retval = 0;

  while (retval == 0)
    {
      // Set the index
      key.index (++ctr);

      // Check to see if an element exists in the Map. If it exists we
      // loop, else we drop out of the loop
      retval =
        this->cache_map_.find (key);
    }

  // Now do a bind again with the new index
  return  this->cache_map_.bind (key,
                                 val,
                                 entry);
}


int
TAO_Connection_Cache_Manager::
    is_entry_idle (HASH_MAP_ENTRY *&entry)
{
  if (entry->int_id_.recycle_state () == ACE_RECYCLABLE_IDLE_AND_PURGABLE ||
      entry->int_id_.recycle_state () == ACE_RECYCLABLE_IDLE_BUT_NOT_PURGABLE)
    {
      // Save that in the handler
      entry->int_id_.handler ()->cache_map_entry (entry);

      // Mark the connection as busy
      entry->int_id_.recycle_state (ACE_RECYCLABLE_BUSY);

      return 0;
    }

  return -1;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  // Instantiations for the Hash Map
template class ACE_Equal_To<TAO_Cache_ExtId>;
template class ACE_Hash<TAO_Cache_ExtId>;
template class ACE_Hash_Map_Entry<TAO_Cache_ExtId, TAO_Cache_IntId>;
template class ACE_Hash_Map_Manager<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>;
template class ACE_Hash_Map_Manager_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Base_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

  // Instantiations for the Hash Map
#pragma instantiate ACE_Equal_To<TAO_Cache_ExtId>
#pragma instantiate ACE_Hash<TAO_Cache_ExtId>
#pragma instantiate ACE_Hash_Map_Entry<TAO_Cache_ExtId, TAO_Cache_IntId>
#pragma instantiate ACE_Hash_Map_Manager<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Manager_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<TAO_Cache_ExtId, TAO_Cache_IntId, ACE_Hash<TAO_Cache_ExtId>, ACE_Equal_To<TAO_Cache_ExtId>, ACE_Null_Mutex>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
