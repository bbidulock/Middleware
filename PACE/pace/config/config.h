/*
 * $Id$

 * ============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    config.h
 *
 * = AUTHOR
 *    Luther Baker
 *
 * ============================================================================ */


#ifndef PACE_CONFIG_CONFIG_H
#define PACE_CONFIG_CONFIG_H

# if defined __EXTENSIONS__
# define PACE_EXTENSIONS
# endif

# if defined _REENTRANT
# define PACE_HAS_REENTRANT
# endif

# if defined _POSIX_PTHREAD_SEMANTICS
# define PACE_HAS_POSIX_PTHREAD_SEMANTICS
# endif

/* OS/PACE_mqueue.h */
# define PACE_HAS_RT

#endif /* PACE_CONFIG_CONFIG_H */


