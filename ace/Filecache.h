/* -*- c++ -*- */
// Hey, Emacs!  This is a C++ file!
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    Filecache.h
//
// = AUTHOR
//    James Hu
//
// ============================================================================

#ifndef ACE_FILECACHE_H
#define ACE_FILECACHE_H
#include "ace/pre.h"

#include "ace/Mem_Map.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Synch_T.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/SString.h"

enum ACE_Filecache_Flag
{
  ACE_NOMAP = 0,
  ACE_MAPIT = 1
};

class ACE_Filecache_Object;

class ACE_Export ACE_Filecache_Handle
{
  // = TITLE
  //     Abstraction over a real file.  This is meant to be the entry
  //     point into the Cached Virtual Filesystem.
  //
  // = DESCRIPTION
  // This is a cached filesystem implementation based loosely on the
  // implementation of JAWS_File.  The interfaces will be nearly the
  // same.  The under-the-hood implementation should hopefully be a
  // much faster thing.
  //
  // These will be given their own implementations later. For now, we
  // borrow the implementation provided by JAWS.
  //
  // On creation, the cache is checked, and reference count is
  // incremented.  On destruction, reference count is decremented.  If
  // the reference count is 0, the file is removed from the cache.
  //
  //     E.g. 1,
  //       {
  //         ACE_Filecache_Handle foo("foo.html");
  //         this->peer ().send (foo.address (), foo.size ());
  //       }
  //
  //     E.g. 2,
  //       {
  //         ACE_Filecache_Handle foo("foo.html");
  //         io->transmitfile (foo.handle (), this->peer ().handle ());
  //       }
  //
  //     E.g. 3,
  //       {
  //         ACE_Filecache_Handle foo("foo.html", content_length);
  //         this->peer ().recv (foo.address (), content_length);
  //       }
  //
  // TODO:

  // (1) Get rid of the useless copying of files when reading.  Although
  // it does make sure the file you send isn't being changed, it doesn't
  // make sure the file is in a sensible state before sending it.

  // Alternative: if the file get's trashed while it is being shipped, let
  // the client request the file again.  The cache should have an updated
  // copy by that point.

  // (2) Use hashing for locating files.  This means I need a hastable
  // implementation with buckets.

  // (3) Only lock when absolutely necessary.  JAWS_Virtual_Filesystem was
  // rather conservative, but for some reason it still ran into problems.
  // Since this design should be simpler, problems should be easier to spot.
  //
public:

  ACE_Filecache_Handle (const ACE_TCHAR *filename,
                        ACE_Filecache_Flag mapit = ACE_MAPIT);
  // Query cache for file, and acquire it.  Assumes the file is being
  // opened for reading.

  ACE_Filecache_Handle (const ACE_TCHAR *filename,
                        int size,
                        ACE_Filecache_Flag mapit = ACE_MAPIT);
  // Create new entry, and acquire it.  Presence of SIZE assumes the
  // file is being opened for writing.  If SIZE is zero, assumes the
  // file is to be removed from the cache.

  ~ACE_Filecache_Handle (void);
  // Closes any open handles, release acquired file.

  void *address (void) const;
  // Base address of memory mapped file.

  ACE_HANDLE handle (void) const;
  // A handle (e.g., UNIX file descriptor, or NT file handle).

  int error (void) const;
  // Any associated error in handle creation and acquisition.

  size_t size (void) const;
  // The size of the file.

protected:
  ACE_Filecache_Handle (void);
  // Default do nothing constructor.  Prevent it from being called.

  void init (void);
  // Common initializations for constructors.

public:
  // = These come from ACE_Filecache_Object, which is an internal class.
  enum
  {
    ACE_SUCCESS = 0,
    ACE_ACCESS_FAILED,
    ACE_OPEN_FAILED,
    ACE_COPY_FAILED,
    ACE_STAT_FAILED,
    ACE_MEMMAP_FAILED,
    ACE_WRITE_FAILED
  };

private:
  ACE_Filecache_Object *file_;
  // A reference to the low level instance.

  ACE_HANDLE handle_;
  // A <dup>'d version of the one from <file_>.

  int mapit_;
};

#if defined (ACE_HAS_TEMPLATE_SPECIALIZATION)
typedef ACE_Hash_Map_Entry<const ACE_TCHAR *, ACE_Filecache_Object *>
        ACE_Filecache_Hash_Entry;

typedef ACE_Hash_Map_Manager<const ACE_TCHAR *, ACE_Filecache_Object *, ACE_Null_Mutex>
        ACE_Filecache_Hash;
#else
typedef ACE_Hash_Map_Entry<ACE_TString, ACE_Filecache_Object *>
        ACE_Filecache_Hash_Entry;

typedef ACE_Hash_Map_Manager<ACE_TString, ACE_Filecache_Object *, ACE_Null_Mutex>
        ACE_Filecache_Hash;
#endif /* ACE_HAS_TEMPLATE_SPECIALIZATION */

class ACE_Export ACE_Filecache
{
  // = TITLE
  //     A hash table holding the information about entry point into
  //     the Cached Virtual Filesystem. On insertion, the reference
  //     count is incremented. On destruction, reference count is
  //     decremented.
public:
  static ACE_Filecache *instance (void);
  // Singleton pattern.

  ~ACE_Filecache (void);

  int find (const ACE_TCHAR *filename);
  // Returns 0 if the file associated with ``filename'' is in the cache,
  // or -1 if not.

  ACE_Filecache_Object *fetch (const ACE_TCHAR *filename, int mapit = 1);
  // Return the file associated with ``filename'' if it is in the cache,
  // or create if not.

  ACE_Filecache_Object *remove (const ACE_TCHAR *filename);
  // Remove the file associated with ``filename'' from the cache.

  ACE_Filecache_Object *create (const ACE_TCHAR *filename, int size);
  // Create a new Filecache_Object, returns it.

  ACE_Filecache_Object *finish (ACE_Filecache_Object *&new_file);
  // Release an acquired Filecache_Object, returns it again or NULL if it
  // was deleted.

protected:
  ACE_Filecache_Object *insert_i (const ACE_TCHAR *filename,
                                  ACE_SYNCH_RW_MUTEX &filelock,
                                  int mapit);
  ACE_Filecache_Object *remove_i (const ACE_TCHAR *filename);
  ACE_Filecache_Object *update_i (const ACE_TCHAR *filename,
                                  ACE_SYNCH_RW_MUTEX &filelock,
                                  int mapit);

public:

  enum
  {
    ACE_DEFAULT_VIRTUAL_FILESYSTEM_TABLE_SIZE = 512,
    // For this stupid implementation, use an array.  Someday, use a
    // balanced search tree, or real hash table.

    ACE_DEFAULT_VIRTUAL_FILESYSTEM_CACHE_SIZE = 20
    // This determines the highwater mark in megabytes for the cache.
    // This will be ignored for now.
  };

protected:
  ACE_Filecache (void);
  // Prevent it from being called.

private:
  int size_;

  ACE_Filecache_Hash hash_;
  // The hash table

  static ACE_Filecache *cvf_;
  // The reference to the instance

  // = Synchronization variables.
  ACE_SYNCH_RW_MUTEX hash_lock_[ACE_DEFAULT_VIRTUAL_FILESYSTEM_TABLE_SIZE];
  ACE_SYNCH_RW_MUTEX file_lock_[ACE_DEFAULT_VIRTUAL_FILESYSTEM_TABLE_SIZE];
};

class ACE_Export ACE_Filecache_Object
{
  // = TITLE
  //     Abstraction over a real file.  This is what the Virtual
  //     Filesystem contains.  This class is not intended for general
  //     consumption.  Please consult a physician before attempting to
  //     use this class.
public:
  friend class ACE_Filecache;

  ACE_Filecache_Object (const ACE_TCHAR *filename,
                        ACE_SYNCH_RW_MUTEX &lock,
                        LPSECURITY_ATTRIBUTES sa = 0,
                        int mapit = 1);
  // Creates a file for reading.

  ACE_Filecache_Object (const ACE_TCHAR *filename,
                        int size,
                        ACE_SYNCH_RW_MUTEX &lock,
                        LPSECURITY_ATTRIBUTES sa = 0);
  // Creates a file for writing.

  ~ACE_Filecache_Object (void);
  // Only if reference count is zero should this be called.

  int acquire (void);
  // Increment the reference_count_.

  int release (void);
  // Decrement the reference_count_.

  // = error_ accessors
  int error (void) const;
  int error (int error_value,
             const ACE_TCHAR *s = ACE_TEXT ("ACE_Filecache_Object"));

  const ACE_TCHAR *filename (void) const;
  // filename_ accessor

  ACE_HANDLE handle (void) const;
  // handle_ accessor.

  void *address (void) const;
  // Base memory address for memory mapped file.

  size_t size (void) const;
  // size_ accessor.

  int update (void) const;
  // True if file on disk is newer than cached file.

protected:
  ACE_Filecache_Object (void);
  // Prevent from being called.

  void init (void);
  // Common initialization code,

private:
  int error_i (int error_value,
               const ACE_TCHAR *s = ACE_TEXT ("ACE_Filecache_Object"));
  // Internal error logging method, no locking.

public:

  enum Creation_States
  {
    ACE_READING = 1,
    ACE_WRITING = 2
  };

  enum Error_Conditions
  {
    ACE_SUCCESS = 0,
    ACE_ACCESS_FAILED,
    ACE_OPEN_FAILED,
    ACE_COPY_FAILED,
    ACE_STAT_FAILED,
    ACE_MEMMAP_FAILED,
    ACE_WRITE_FAILED
  };

private:
  ACE_TCHAR *tempname_;
  ACE_TCHAR filename_[MAXPATHLEN + 1];
  // The temporary file name and the real file name.  The real file is
  // copied into the temporary file for safety reasons.

  ACE_Mem_Map mmap_;
  ACE_HANDLE handle_;
  // mmap_ holds the memory mapped version of the temporary file.
  // handle_ is the descriptor to the temporary file.

  struct stat stat_;
  size_t size_;
  // Used to compare against the real file to test if an update is needed.

  int action_;
  int error_;
  // Status indicators.

  int stale_;
  // If set to 1, means the object is flagged for removal.

  LPSECURITY_ATTRIBUTES sa_;
  // Security attribute object.

  ACE_SYNCH_RW_MUTEX junklock_;
  ACE_SYNCH_RW_MUTEX &lock_;
  // lock_ provides a bookkeeping mechanism for users of this object.
  // junklock_ is the default initializer
};


#include "ace/post.h"
#endif /* ACE_FILECACHE_H */
