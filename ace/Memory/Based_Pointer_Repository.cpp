// $Id$

#include "ace/Utils/Templates/Map_Manager.h"
#include "ace/Memory/Based_Pointer_Repository.h"

class ACE_Based_Pointer_Repository_Rep
{
  // = TITLE
  //   Implementation for the <ACE_Based_Pointer_Repository>.
  //
  // = DESCRIPTION
  //   Every memory pool in ACE binds it's mapping base address and
  //   the mapped size to this repository every time it maps/remaps a
  //   new chunk of memory successfully.

public:
  // Useful typedefs.
  typedef ACE_Map_Manager <void *, size_t, ACE_Null_Mutex> MAP_MANAGER;
  typedef ACE_Map_Iterator < void *, size_t, ACE_Null_Mutex> MAP_ITERATOR;
  typedef ACE_Map_Entry <void *, size_t> MAP_ENTRY;

  MAP_MANAGER addr_map_;
  // Keeps track of the mapping between addresses and their associated
  // values.

  ACE_SYNCH_MUTEX lock_;
  // Synchronize concurrent access to the map.
};

ACE_Based_Pointer_Repository::ACE_Based_Pointer_Repository (void)
{
  ACE_TRACE ("ACE_Based_Pointer_Repository::ACE_Based_Pointer_Repository");
  ACE_NEW (this->rep_,
           ACE_Based_Pointer_Repository_Rep);
}

ACE_Based_Pointer_Repository::~ACE_Based_Pointer_Repository (void)
{
  ACE_TRACE ("ACE_Based_Pointer_Repository::~ACE_Based_Pointer_Repository");
  delete this->rep_;
}

// Search for appropriate base address in repository

int
ACE_Based_Pointer_Repository::find (void *addr,
                                    void *&base_addr)
{
  ACE_TRACE ("ACE_Based_Pointer_Repository::find");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->rep_->lock_, -1);
  ACE_Based_Pointer_Repository_Rep::MAP_ENTRY *ce = 0;

  for (ACE_Based_Pointer_Repository_Rep::MAP_ITERATOR iter (this->rep_->addr_map_);
       iter.next (ce) != 0;
       iter.advance ())
    // Check to see if <addr> is within any of the regions.
    if (addr >= ce->ext_id_
        && addr < ((char *) ce->ext_id_ + ce->int_id_))
      {
        // Assign the base address.
        base_addr = ce->ext_id_;
        return 1;
      }

  // Assume base address 0 (e.g., if new'ed).
  base_addr = 0;
  return 0;
}

// Bind a new entry to the repository or update the size of an
// existing entry.

int
ACE_Based_Pointer_Repository::bind (void *addr,
                                    size_t size)
{
  ACE_TRACE ("ACE_Based_Pointer_Repository::bind");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->rep_->lock_, -1);

  return this->rep_->addr_map_.rebind (addr, size);
}

// Unbind a base from the repository.

int
ACE_Based_Pointer_Repository::unbind (void *addr)
{
  ACE_TRACE ("ACE_Based_Pointer_Repository::unbind");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->rep_->lock_, -1);
  ACE_Based_Pointer_Repository_Rep::MAP_ENTRY *ce = 0;

  // Search for service handlers that requested notification.

  for (ACE_Based_Pointer_Repository_Rep::MAP_ITERATOR iter (this->rep_->addr_map_);
       iter.next (ce) != 0;
       iter.advance ())
    {
      // Check to see if <addr> is within any of the regions and if
      // so, unbind the key from the map.
      if (addr >= ce->ext_id_
          && addr < ((char *) ce->ext_id_ + ce->int_id_))
        // Unbind base address.
        return this->rep_->addr_map_.unbind (ce->ext_id_);
    }

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Singleton <ACE_Based_Pointer_Repository, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Entry<void *, size_t>;
template class ACE_Map_Manager<void *, size_t, ACE_Null_Mutex>;
template class ACE_Map_Iterator<void *, size_t, ACE_Null_Mutex>;
template class ACE_Map_Reverse_Iterator<void *, size_t, ACE_Null_Mutex>;
template class ACE_Map_Iterator_Base<void *, size_t, ACE_Null_Mutex>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Singleton <ACE_Based_Pointer_Repository, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Entry<void *, size_t>
#pragma instantiate ACE_Map_Manager<void *, size_t, ACE_Null_Mutex>
#pragma instantiate ACE_Map_Iterator<void *, size_t, ACE_Null_Mutex>
#pragma instantiate ACE_Map_Reverse_Iterator<void *, size_t, ACE_Null_Mutex>
#pragma instantiate ACE_Map_Iterator_Base<void *, size_t, ACE_Null_Mutex>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
