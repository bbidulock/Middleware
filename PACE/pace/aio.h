/* $Id$

 * ============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    pace/aio.h
 *
 * = AUTHOR
 *    Luther Baker
 *
 * ============================================================================ */

#ifndef PACE_AIO_H
#define PACE_AIO_H

#include "pace/config/defines.h"

#if (PACE_HAS_POSIX)
# include "pace/posix/aio.h"
#elif (PACE_VXWORKS)
# include "pace/vxworks/aio.h"
#elif (PACE_WIN32)
# include "pace/win32/aio.h"
#endif

#if defined (PACE_HAS_CPLUSPLUS)
extern "C" {
#endif /* PACE_HAS_CPLUSPLUS */

  /**
     PACE's implementation of the POSIX function aio_cancel.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), section 6.7.7.
   */
  PACE_INLINE int pace_aio_cancel (int fildes, pace_aiocb * aiocb);

  /**
     PACE's implementation of the POSIX function aio_error.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), section 6.7.5.
   */
  PACE_INLINE int pace_aio_error (const pace_aiocb * aiocbp);

  /**
     PACE's implementation of the POSIX function aio_fsync.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), section 6.7.9.
   */
  PACE_INLINE int pace_aio_fsync (int op, pace_aiocb * aiocbp);

  /**
     PACE's implementation of the POSIX function aio_read.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), section 6.7.2.
   */
  PACE_INLINE int pace_aio_read (pace_aiocb * aiocbp);

  /**
     PACE's implementation of the POSIX function aio_return.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), section 6.7.6.
   */
  PACE_INLINE int pace_aio_return (pace_aiocb * aiocbp);

  /**
     PACE's implementation of the POSIX function aio_suspend.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), section 6.7.8.
   */
  PACE_INLINE int pace_aio_suspend (const pace_aiocb * const list[],
                                    int nent,
                                    const pace_timespec * timeout);

  /**
     PACE's implementation of the POSIX function aio_write.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), section 6.7.3.
   */
  PACE_INLINE int pace_aio_write (pace_aiocb * aiocbp);

  /**
     PACE's implementation of the POSIX function lio_listio.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), section 6.7.4.
   */
  PACE_INLINE int pace_lio_listio (int mode,
                                   pace_aiocb * const list[],
                                   int nent,
                                   pace_sigevent * sig);

#if defined (PACE_HAS_INLINE)
#  if (PACE_HAS_POSIX)
#    include "pace/posix/aio.inl"
#  elif (PACE_VXWORKS)
#    include "pace/vxworks/aio.inl"
#  elif (PACE_WIN32)
#    include "pace/win32/aio.inl"
#  endif
#endif /* PACE_HAS_INLINE */

#if defined (PACE_HAS_CPLUSPLUS)
}
#endif /* PACE_HAS_CPLUSPLUS */

#endif /* PACE_AIO_H */
