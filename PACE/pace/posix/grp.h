/* $Id$

 * ============================================================================
 *
 * = LIBRARY
 *    pace (posix ace)
 *
 * = FILENAME
 *    pace/posix/grp.h
 *
 * = AUTHOR
 *    Luther Baker
 *
 * ============================================================================ */

#ifndef PACE_GRP_H
#define PACE_GRP_H

#include <grp.h>

# if defined (PACE_HAS_CPLUSPLUS)
extern "C" {
# endif /* PACE_HAS_CPLUSPLUS */

  PACE_INLINE struct group * pace_getgrgid (pace_gid_t gid);

  PACE_INLINE int pace_getgrgid_r (pace_gid_t gid,
                                   struct group * grp,
                                   char * buffer,
                                   size_t bufsize,
                                   struct group ** result);
  /* Requires PACE_HAS_POSIX_PTHREAD_SEMANTICS. */

  PACE_INLINE struct group * pace_getgrnam (const char * name);

  PACE_INLINE int pace_getgrnam_r (const char * name,
                                   struct group * grp,
                                   char * buffer,
                                   size_t bufsize,
                                   struct group ** result);
  /* Requires PACE_HAS_POSIX_PTHREAD_SEMANTICS. */

# if defined (PACE_HAS_CPLUSPLUS)
}
# endif /* PACE_HAS_CPLUSPLUS */

# if defined (PACE_HAS_INLINE)
# include "pace/posix/grp.inl"
# endif /* PACE_HAS_INLINE */

#endif /* PACE_GRP_H */
