/* $Id$

 * ============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    pace/stdlib.h
 *
 * = AUTHOR
 *    Luther Baker
 *
 * ============================================================================ */

#ifndef PACE_STDLIB_H_INDIRECT
#define PACE_STDLIB_H_INDIRECT

#include "pace/config/defines.h"

#if defined (PACE_HAS_POSIX)
# include "pace/posix/stdlib.h"
#elif defined (PACE_VXWORKS)
# include "pace/vxworks/stdlib.h"
#elif defined (PACE_WIN32)
# include "pace/win32/stdlib.h"
#endif

#endif /* PACE_STDLIB_H_INDIRECT */
