/* -*- c++ -*- */
// $Id$


#ifndef ACE_CACHE_OBJECT_H
#define ACE_CACHE_OBJECT_H

#include "ace/OS.h"
#include "ace/Synch.h"
#include "ace/Malloc.h"

// Cache bucket -- use Hash_Bucket to hold cacheable objects.

class ACE_Cache_Object
{
public:
  ACE_Cache_Object (const void *, size_t);
  virtual ~ACE_Cache_Object (void);

  void *internal (void) const;
  void internal (void *);

  const void *data (void) const;
  size_t size (void) const;
  unsigned int count (void) const;

  int acquire (void);
  int release (void);

  time_t last_access (void) const;
  time_t first_access (void) const;

  unsigned int priority (void) const;

  enum { ACE_CO_REFERENCED, ACE_CO_COUNTED };

  void *heap_item (void) const;
  void heap_item (void *item);

  virtual ACE_Lock & lock (void) = 0;

protected:

  virtual unsigned int count_i (void) const = 0;
  virtual int acquire_i (void) = 0;
  virtual int release_i (void) = 0;
  virtual unsigned int priority_i (void) const = 0;

private:

  void *internal_;
  const void *data_;
  size_t size_;

  time_t last_access_;
  time_t first_access_;
  time_t new_last_access_;

  void *heap_item_;

};

class ACE_Referenced_Cache_Object : public ACE_Cache_Object
{
public:
  ACE_Referenced_Cache_Object (const void *, size_t);
  virtual ~ACE_Referenced_Cache_Object (void);

  virtual ACE_Lock & lock (void);

protected:

  virtual unsigned int count_i (void) const;
  virtual int acquire_i (void);
  virtual int release_i (void);
  virtual unsigned int priority_i (void) const;

private:

  /* MUTABLE */ ACE_SYNCH_RW_MUTEX count_;
  /* MUTABLE */ ACE_Lock_Adapter<ACE_SYNCH_RW_MUTEX> lock_adapter_;
  
};

class ACE_Counted_Cache_Object : public ACE_Cache_Object
{
public:
  ACE_Counted_Cache_Object (const void *, size_t);
  virtual ~ACE_Counted_Cache_Object (void);

  virtual ACE_Lock & lock (void);

protected:

  virtual unsigned int count_i (void) const;
  virtual int acquire_i (void);
  virtual int release_i (void);
  virtual unsigned int priority_i (void) const;

private:

  unsigned int count_;
  unsigned int new_count_;
  /* MUTABLE */ ACE_SYNCH_MUTEX lock_;
  /* MUTABLE */ ACE_Lock_Adapter<ACE_SYNCH_MUTEX> lock_adapter_;

};

class ACE_Cache_Object_Factory
{
public:

  ACE_Cache_Object_Factory (ACE_Allocator *alloc = 0);
  virtual ~ACE_Cache_Object_Factory (void);

  int open (ACE_Allocator *alloc = 0);

  virtual ACE_Cache_Object * create (const void *, size_t) = 0;
  virtual void destroy (ACE_Cache_Object *) = 0;

protected:

  ACE_Allocator *allocator_;

};

class ACE_Referenced_Cache_Object_Factory : public ACE_Cache_Object_Factory
{
public:
  ACE_Referenced_Cache_Object_Factory (ACE_Allocator *alloc = 0);
  virtual ~ACE_Referenced_Cache_Object_Factory (void);

  virtual ACE_Cache_Object * create (const void *, size_t);
  virtual void destroy (ACE_Cache_Object *);

};

class ACE_Counted_Cache_Object_Factory : public ACE_Cache_Object_Factory
{
public:
  ACE_Counted_Cache_Object_Factory (ACE_Allocator *alloc = 0);
  virtual ~ACE_Counted_Cache_Object_Factory (void);

  virtual ACE_Cache_Object * create (const void *, size_t);
  virtual void destroy (ACE_Cache_Object *);

};

#endif /* UTL_CACHE_OBJECT_H */
