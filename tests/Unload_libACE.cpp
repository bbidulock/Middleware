// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Unload_libACE.cpp
//
// = DESCRIPTION
//      This is a simple test of library unloading that uses
//      an application which has _not_ been linked with libACE
//      but uses dlopen() to dynamically load libACE
//      and then uses dlclose() to unload it.
//
// = AUTHORS
//    David Smith <dts@prismtech.com> and Don Sharp <Donald.Sharp@prismtech.com>
//
// ============================================================================

#include <stdio.h>

#if defined (__GNUC__) || defined (__hpux) || defined (__SUNPRO_CC)

#include <errno.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TIME_STAMP_FIELD_WIDTH  32

static char *
time_stamp ( char date_and_time[], int date_and_timelen, int format )
{
   static char const *const month_name[] =
   {
      "Jan",
      "Feb",
      "Mar",
      "Apr",
      "May",
      "Jun",
      "Jul",
      "Aug",
      "Sep",
      "Oct",
      "Nov",
      "Dec"
   };

   static char const *const day_of_week_name[] =
   {
      "Sun",
      "Mon",
      "Tue",
      "Wed",
      "Thu",
      "Fri",
      "Sat"
   };

   char *ts = NULL;

   if ( date_and_timelen >= TIME_STAMP_FIELD_WIDTH )
   {
      time_t timeval;
      struct tm *now;

      time ( &timeval );
      now = localtime ( &timeval );     /* Get current local time. */

      if ( format == 'Y' )
      {
         sprintf ( date_and_time,
                   "%3s %3s %2d %04d %02d:%02d:%02d.%06d",
                   day_of_week_name[now->tm_wday],
                   month_name[now->tm_mon],
                   ( int ) now->tm_mday,
                   ( int ) now->tm_year + 1900,
                   ( int ) now->tm_hour,
                   ( int ) now->tm_min, ( int ) now->tm_sec, ( int ) 0 );
      }
      else                      /* 'T' */
      {
         sprintf ( date_and_time,
                   "%3s %2d %02d:%02d:%02d.%03d %04d",
                   month_name[now->tm_mon],
                   ( int ) now->tm_mday,
                   ( int ) now->tm_hour,
                   ( int ) now->tm_min,
                   ( int ) now->tm_sec, ( int ) 0,
                   ( int ) now->tm_year + 1900 );
      }

      ts = date_and_time;
   }
   return ts;
}

int
run_main ( int, char ** )
{
   char const *const program = "UnloadLibACE";

   int status = 0;
   void *handle = NULL;
   char *ace_root = NULL;
   char tbuf[BUFSIZ];
   char ybuf[BUFSIZ];
   FILE *logfp = NULL;

   if (( logfp = fopen ( "log/UnloadLibACE.log", "w" )) != NULL )
   {
      setvbuf ( logfp, NULL, _IONBF, 0 );
      // reassign stdout/stderr to log file
      int fdno = fileno ( logfp );

      dup2 ( fdno, fileno ( stdout ));
      dup2 ( fdno, fileno ( stderr ));
      setvbuf ( stdout, NULL, _IONBF, 0 );
      setvbuf ( stderr, NULL, _IONBF, 0 );
      fflush ( stdout );
      fflush ( stderr );

      printf ( "%s@LM_DEBUG@ Starting %s test at %s\n",
               time_stamp ( tbuf, BUFSIZ, 'T' ),
               program, time_stamp ( ybuf, BUFSIZ, 'Y' ));

      if (( ace_root = getenv ( "ACE_ROOT" )) != NULL )
      {
         char buf[BUFSIZ];

         strcpy ( buf, ace_root );
#if defined (__hpux)
         strcat ( buf, "/lib/libACE.sl" );
#else
         strcat ( buf, "/lib/libACE.so" );
#endif /* (__hpux) */

         handle = dlopen ( buf, RTLD_LAZY );
         if ( handle == NULL )
         {
            fprintf ( stderr,
                      "%s@LM_ERROR@ dlopen() returned NULL\n",
                      time_stamp ( tbuf, BUFSIZ, 'T' ));
            fprintf ( stderr,
                      "%s@LM_ERROR@ dlerror() says: %s\n",
                      time_stamp ( tbuf, BUFSIZ, 'T' ), dlerror ());
            status = 1;
         }
         else if ( dlclose ( handle ) != 0 )
         {
            fprintf ( stderr,
                      "%s@LM_ERROR@ dlclose() failed : %s\n",
                      time_stamp ( tbuf, BUFSIZ, 'T' ), strerror ( errno ));
            status = 1;
         }
      }
      else
      {
         fprintf ( stderr,
                   "%s@LM_ERROR@ ACE_ROOT environment variable not set\n",
                   time_stamp ( tbuf, BUFSIZ, 'T' ));
         status = 1;
      }
      fflush ( stdout );
      fflush ( stderr );
   }
   else
   {
      // Couldn't go into the log file !!!
      printf ( "%s@LM_DEBUG@ Starting %s test at %s\n",
               time_stamp ( tbuf, BUFSIZ, 'T' ),
               program, time_stamp ( ybuf, BUFSIZ, 'Y' ));

      fprintf ( stderr,
                "%s@LM_ERROR@ Could not open log/UnloadLibACE.log : %s\n",
                time_stamp ( tbuf, BUFSIZ, 'T' ), strerror ( errno ));
      status = 1;
   }

   printf ( "%s@LM_DEBUG@ Ending %s test at %s\n",
            time_stamp ( tbuf, BUFSIZ, 'T' ),
            program, time_stamp ( ybuf, BUFSIZ, 'Y' ));

   fflush ( stderr );
   fflush ( stdout );
   fflush ( logfp );

   fclose ( logfp );
   fclose ( stdout );
   fclose ( stderr );

   exit ( status );
   return 0;
}
#else
int
run_main ( int, char ** )
{
   char const *const program = "UnloadLibACE";

   FILE *logfp = NULL;

   if (( logfp = fopen ( "log/UnloadLibACE.log", "w" )) != NULL )
   {
      fprintf ( logfp, "@LM_DEBUG@ Starting %s test\n", program);
      fprintf ( logfp, "@LM_DEBUG@ %s test not implemented for this platform\n",
                program);
      fprintf ( logfp, "@LM_DEBUG@ Ending %s test\n", program);

      fflush ( logfp );
      fclose ( logfp );
   }
   return 0;
}
#endif /* (__GNUC__) || (__hpux) || (__SUNPRO_CC) */
