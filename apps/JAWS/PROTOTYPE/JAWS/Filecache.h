/* -*- c++ -*- */
// $Id$

#ifndef JAWS_FILECACHE_H
#define JAWS_FILECACHE_H

#include "ace/OS.h"
#include "ace/FILE_IO.h"

#include "JAWS/Cache_Manager.h"
#include "JAWS/Export.h"

class JAWS_Export JAWS_Referenced_Filecache_Factory
  : public JAWS_Referenced_Cache_Object_Factory
{
public:

  virtual void destroy (ACE_Cache_Object *);

};

class JAWS_Export JAWS_Counted_Filecache_Factory
  : public JAWS_Counted_Cache_Object_Factory
{
public:

  virtual void destroy (ACE_Cache_Object *);

};

typedef ACE_Cache_Manager<ACE_Strdup_String,
                          JAWS_Referenced_Filecache_Factory,
                          ACE_String_Hash_Functor,
                          ACE_String_Equal_Functor>
        JAWS_Referenced_Filecache_Manager;

typedef ACE_Cache_Manager<ACE_Strdup_String,
                          JAWS_Counted_Filecache_Factory,
                          ACE_String_Hash_Functor,
                          ACE_String_Equal_Functor>
        JAWS_Counted_Filecache_Manager;

typedef JAWS_Referenced_Filecache_Manager JAWS_Filecache_Manager;

typedef ACE_Cache_Proxy<const char *,
                        JAWS_FILE, JAWS_Filecache_Manager>
        JAWS_Filecache_Proxy;

class JAWS_Export JAWS_Cached_FILE : private JAWS_Filecache_Proxy
{
public:

  JAWS_Cached_FILE (const char *const &filename,
                    JAWS_Filecache_Proxy::Cache_Manager *cm = 0);
  JAWS_Cached_FILE (const char *const &filename,
                    JAWS_FILE *&file,
                    size_t size,
                    JAWS_Filecache_Proxy::Cache_Manager *cm = 0);

  ~JAWS_Cached_FILE (void);

  ACE_FILE_IO * file (void);
  ACE_Mem_Map * mmap (void);

private:

  ACE_FILE_IO file_;

};


#endif /* JAWS_FILECACHE_H */
