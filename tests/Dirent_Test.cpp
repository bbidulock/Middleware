// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Dirent_Test.cpp
//
// = DESCRIPTION
//     This is a test of the opendir and readdir emulation provided by the
//     class ACE_OS_Dirent.  It is used to ensure that the emulation code
//     works properly on platforms that don't support this capability
//     natively.  As the emulation code is not compiled in other
//     platforms, this test also ensures that there is no impact to
//     platforms that natively support directory scanning operations.
//
// = AUTHOR
//    Phil Mesnier <mesnier_p@ociweb.com>,
//    Zvika Ashani <zvika@aspectusvi.com>,
//    Rich Newman <RNewman@directv.com>, and
//    Douglas C. Schmidt <d.schmidt@vanderbilt.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/Dirent.h"
#include "ace/Dirent_Selector.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_String.h"


ACE_RCSID (tests,
           Dirent_Test,
           "$Id Dirent_Test.cpp,v 4.10 2003/05/18 19:17:34 dhinton Exp$")


#if defined (VXWORKS) || defined(CHORUS)
#define TEST_DIR "log"
#define TEST_ENTRY ".."
#else
#define TEST_DIR "../tests"
#define TEST_ENTRY "run_test.lst"
#endif /* VXWORKS || CHORUS */

static const int RECURSION_INDENT = 3;

// Number of entries in the directory.
static int entrycount = 0;

static int
selector (const dirent *d)
{
  return ACE_OS_String::strcmp (d->d_name, ACE_TEXT (TEST_ENTRY)) == 0;
}

static int
comparator (const dirent **d1, const dirent **d2)
{
  return ACE_OS_String::strcmp ((*d1)->d_name, (*d2)->d_name);
}

static int
dirent_selector_test (void)
{
  int status;
  int n;

  ACE_Dirent_Selector sds;

  // Pass in functions that'll specify the selection criteria.
  status = sds.open (ACE_TEXT (TEST_DIR), selector, comparator);
  ACE_ASSERT (status != -1);

  // We should only have located ourselves!
  ACE_ASSERT (sds.length () == 1);

  for (n = 0; n < sds.length (); ++n)
    ACE_DEBUG ((LM_DEBUG,
                "Sorted: %d: %s\n",
                n,
                sds[n]->d_name));

  status = sds.close ();
  ACE_ASSERT (status != -1);

  ACE_Dirent_Selector ds;

  // Don't specify any selection criteria.
  status = ds.open (ACE_TEXT (TEST_DIR));
  ACE_ASSERT (status != -1);

  ACE_ASSERT (entrycount == ds.length ());

  for (n = 0; n < ds.length (); ++n)
    ACE_DEBUG ((LM_DEBUG,
                "Entry %d: %s\n",
                n,
                ds[n]->d_name));

  status = ds.close ();
  ACE_ASSERT (status != -1);

  return status;
}

static int
dirent_test (void)
{
  ACE_Dirent dir (ACE_TEXT (TEST_DIR));

  for (dirent *directory;
       (directory = dir.read ()) != 0;
       entrycount++)
    ACE_DEBUG ((LM_DEBUG,
                "Entry %d: %s\n",
                entrycount,
                directory->d_name));
  switch (entrycount)
    {
    case 0:
      ACE_ERROR_RETURN ((LM_ERROR,
                         "readdir failed to read anything\n"),
                        -1);
      /* NOTREACHED */
    case 1:
      ACE_ERROR_RETURN ((LM_ERROR,
                         "readdir failed, only matched directory name\n"),
                        -1);
      /* NOTREACHED */
    default:
      ACE_DEBUG ((LM_DEBUG,
                  "readdir succeeded, read %d entries\n",
                  entrycount));
    }
  return 0;
}

static int
dirent_count (const ACE_TCHAR *dir_path,
              int &dir_count,
              int &file_count,
              int recursion_level)
{
  if (ACE_OS::chdir (dir_path) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "chdir: %p\n",
                       dir_path),
                      -1);
  ACE_Dirent dir (ACE_TEXT ("."));

  int entry_count = 0;

  for (dirent *directory; (directory = dir.read ()) != 0;)
    {
      // Skip the ".." and "." files.
      if (ACE_OS_String::strcmp (directory->d_name, ACE_TEXT (".")) == 0
          || ACE_OS_String::strcmp (directory->d_name, ACE_TEXT ("..")) == 0)
        continue;
      entry_count++;

      int local_file_count = 0;
      int local_dir_count = 0;
      ACE_stat stat_buf;

      if (ACE_OS::lstat (directory->d_name, &stat_buf) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%p\n",
                           directory->d_name),
                          -1);

      switch (stat_buf.st_mode & S_IFMT)
        {
        case S_IFREG: // Either a regular file or an executable.
          file_count++;
          break;

        case S_IFLNK: // Either a file or directory link, so let's find out.
          if (ACE_OS::stat (directory->d_name, &stat_buf) == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "%p\n",
                               directory->d_name),
                              -1);

          if ((stat_buf.st_mode & S_IFMT) == S_IFDIR)
            // Don't recurse through symbolic directory links!
            dir_count++;
          else
            file_count++;
          break;

        default: // Must be a directory.
          ACE_DEBUG ((LM_DEBUG, "%*sentering subdirectory %s\n",
                      recursion_level * RECURSION_INDENT,
                      "",
                      directory->d_name));
          if (dirent_count (directory->d_name,
                            local_dir_count,
                            local_file_count,
                            recursion_level + 1) != -1)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "%*ssubdirectory %s has %d files and %d subdirectories.\n",
                          recursion_level * RECURSION_INDENT,
                          "",
                          directory->d_name,
                          local_file_count,
                          local_dir_count));
              dir_count++;

              // Move back up a level.
              if (ACE_OS::chdir (ACE_TEXT ("..")) == -1)
                ACE_ERROR_RETURN ((LM_ERROR,
                                   "chdir: %p\n",
                                   dir_path),
                                  -1);
            }
          break;
        }
    }

  return entry_count;
}

static int
dirent_recurse_test (void)
{
  int total_dirs = 0;
  int total_files = 0;

  ACE_DEBUG ((LM_DEBUG,
              "Starting directory recursion test for %s\n",
              ACE_TEXT (TEST_DIR)));

  if (dirent_count (ACE_TEXT (TEST_DIR),
                    total_dirs,
                    total_files,
                    1) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Directory recursion test failed for %s\n",
                       ACE_TEXT (TEST_DIR)),
                      -1);
  ACE_DEBUG ((LM_DEBUG,
              "Directory recursion test succeeded for %s, read %d files %d dirs\n",
              ACE_TEXT (TEST_DIR),
              total_files,
              total_dirs));
  return 0;
}

int
run_main (int, ACE_TCHAR *[])
{
  ACE_START_TEST (ACE_TEXT ("Dirent_Test"));

  int status = 0;

  status = dirent_test ();

  if (status != -1)
    status = dirent_selector_test ();

  if (status != -1)
    status = dirent_recurse_test ();

  ACE_END_TEST;
  return status;
}
