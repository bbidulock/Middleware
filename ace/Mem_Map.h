/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    Mem_Map.h
//
// = AUTHOR
//    Doug Schmidt
//
// ============================================================================

#ifndef ACE_MEM_MAP_H
#define ACE_MEM_MAP_H

#include "ace/ACE.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ACE_Export ACE_Mem_Map
{
  // = TITLE
  //     C++ interface OS memory mapping system call.
  //
  // = DESCRIPTION
  //     This class works with both the mmap(2) UNIX system and the
  //     Win32 family of memory mapping system calls.
public:
  // = Initialization and termination methods.

  ACE_Mem_Map (void);
  // Default constructor.

  ACE_Mem_Map (ACE_HANDLE handle,
               int length = -1,
               int prot = PROT_RDWR,
               int share = ACE_MAP_PRIVATE,
               void *addr = 0,
               off_t offset = 0,
               LPSECURITY_ATTRIBUTES sa = 0);
  // Map a file from an open file descriptor <handle>.  This function
  // will lookup the length of the file if it is not given.

  ACE_Mem_Map (LPCTSTR filename,
               int len = -1,
               int flags = O_RDWR | O_CREAT,
               int mode = ACE_DEFAULT_FILE_PERMS,
               int prot = PROT_RDWR,
               int share = ACE_MAP_PRIVATE,
               void *addr = 0,
               off_t offset = 0,
               LPSECURITY_ATTRIBUTES sa = 0);
  // Map a file specified by <file_name>.

  int map (ACE_HANDLE handle,
           int length = -1,
           int prot = PROT_RDWR,
           int share = ACE_MAP_PRIVATE,
           void *addr = 0,
           off_t offset = 0,
           LPSECURITY_ATTRIBUTES sa = 0);
  // Map a file from an open file descriptor <handle>.  This function
  // will lookup the length of the file if it is not given.

  int map (int length = -1,
           int prot = PROT_RDWR,
           int share = ACE_MAP_PRIVATE,
           void *addr = 0,
           off_t offset = 0,
           LPSECURITY_ATTRIBUTES sa = 0);
  // Remap the file associated with <handle_>.

  int map (LPCTSTR filename,
           int len = -1,
           int flags = O_RDWR | O_CREAT,
           int mode = ACE_DEFAULT_FILE_PERMS,
           int prot = PROT_RDWR,
           int share = ACE_MAP_PRIVATE,
           void *addr = 0,
           off_t offset = 0,
           LPSECURITY_ATTRIBUTES sa = 0);
  // Map a file specified by <filename>.

  ~ACE_Mem_Map (void);
  // Destructor.

  int open (LPCTSTR filename,
            int flags = O_RDWR | O_CREAT,
            int mode = ACE_DEFAULT_FILE_PERMS,
            LPSECURITY_ATTRIBUTES sa = 0);
  // Open the file without mapping it.

  int close (void);
  // Close down the <handle_> if necessary and unmap the mapping.

  int close_handle (void);
  // Close down the <handle_> if necessary.

  int close_filemapping_handle (void);
  // Close down the internal <file_mapping_> if necessary.  This is
  // mostly necessary on Win32, that has a different handle for
  // file-mapping kernel object.

  int operator () (void *&addr);
  // This operator passes back the starting address of the mapped
  // file.

  void *addr (void) const;
  // Return the base address.

  size_t size (void) const;
  // This function returns the number of bytes currently mapped in the
  // file.

  int unmap (int len = -1);
  // Unmap the region starting at <base_addr_>.

  int unmap (void *addr, int len);
  // Unmap the region starting at <addr_>.

  int sync (ssize_t len = -1, int flags = MS_SYNC);
  // Sync <len> bytes of the memory region to the backing store
  // starting at <base_addr_>.  If <len> == -1 then sync the whole
  // region.

  int sync (void *addr, size_t len, int flags = MS_SYNC);
  // Sync <len> bytes of the memory region to the backing store
  // starting at <addr_>.

  int protect (ssize_t len = -1, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <base_addr_> up to <len> bytes.  If <len> == -1 then
  // change protection of all pages in the mapped region.

  int protect (void *addr, size_t len, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <addr> up to <len> bytes.

  int remove (void);
  // Close down and remove the file from the file system.

  int advise (int behavior, int len = -1);
  // Hook into the underlying VM system.

  ACE_HANDLE handle (void) const;
  // Return the underlying <handle_>.

  const TCHAR *filename (void) const;
  // Return the name of file that is mapped (if any).

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  void *base_addr_;
  // Base address of the memory-mapped file.

  TCHAR filename_[MAXPATHLEN + 1];
  // Name of the file that is mapped.

  size_t length_;
  // Length of the mapping.

  ACE_HANDLE handle_;
  // HANDLE for the open file.

  ACE_HANDLE file_mapping_;
  // HANDLE for the open mapping.

#if defined (__Lynx__)
  int write_enabled_;
  // Flag to indicate that PROT_WRITE has been enabled.
#endif /* __Lynx__ */

  int close_handle_;
  // Keeps track of whether we need to close the handle.  This is set
  // if we opened the file.

  int map_it (ACE_HANDLE handle,
              int len = -1,
              int prot = PROT_RDWR,
              int share = MAP_SHARED,
              void *addr = 0,
              off_t offset = 0,
              LPSECURITY_ATTRIBUTES sa = 0);
  // This method does the dirty work of actually calling ::mmap to map
  // the file into memory.

  // = Disallow copying and assignment.
  ACE_Mem_Map (const ACE_Mem_Map &);
  void operator = (const ACE_Mem_Map &);
};

#if defined (__ACE_INLINE__)
#include "ace/Mem_Map.i"
#endif /* __ACE_INLINE__ */

#endif /* ACE_MEM_MAP_H */
