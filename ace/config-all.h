// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//   ace
//
// = FILENAME
//   config-all.h
//
// = AUTHOR
//   (Originally in OS.h)
//   Doug Schmidt <schmidt@cs.wustl.edu>, Jesper S. M|ller
//   <stophph@diku.dk>, and a cast of thousands...
//
// ============================================================================

#ifndef ACE_CONFIG_ALL_H
#define ACE_CONFIG_ALL_H
#include "ace/pre.h"

#include "ace/config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// ============================================================================
// RCSID Macros
// ============================================================================

// By default, DO include RCS Id strings in object code.
#if ! defined (ACE_USE_RCSID)
#  define ACE_USE_RCSID 1
#endif /* #if ! defined (ACE_USE_RCSID) */

#if (defined (ACE_USE_RCSID) && (ACE_USE_RCSID != 0))
#  if ! defined (ACE_RCSID)

   // This hack has the following purposes:
   // 1. To define the RCS id string variable as a static char*, so
   //    that there won't be any duplicate extern symbols at link
   //    time.
   // 2. To have a RCS id string variable with a unique name for each
   //    file.
   // 3. To avoid warnings of the type "variable declared and never
   //    used".

#    define ACE_RCSID(path, file, id) \
      inline const char* get_rcsid_ ## path ## _ ## file (const char*) \
      { \
        return id ; \
      } \
      static const char* rcsid_ ## path ## _ ## file = \
        get_rcsid_ ## path ## _ ## file ( rcsid_ ## path ## _ ## file ) ;

#  endif /* #if ! defined (ACE_RCSID) */
#else

   // RCS id strings are not wanted.
#  if defined (ACE_RCSID)
#    undef ACE_RCSID
#  endif /* #if defined (ACE_RCSID) */
#  define ACE_RCSID(path, file, id) /* noop */
#endif /* #if (defined (ACE_USE_RCSID) && (ACE_USE_RCSID != 0)) */

// ============================================================================
// INLINE macros
//
// These macros handle all the inlining of code via the .i or .inl files
// ============================================================================

#if defined (ACE_LACKS_INLINE_FUNCTIONS) && !defined (ACE_NO_INLINE)
#  define ACE_NO_INLINE
#endif /* defined (ACE_LACKS_INLINE_FUNCTIONS) && !defined (ACE_NO_INLINE) */

// ACE inlining has been explicitly disabled.  Implement
// internally within ACE by undefining __ACE_INLINE__.
#if defined (ACE_NO_INLINE)
#  undef __ACE_INLINE__
#endif /* ! ACE_NO_INLINE */

#if defined (__ACE_INLINE__)
#  define ACE_INLINE inline
#  if !defined (ACE_HAS_INLINED_OSCALLS)
#    define ACE_HAS_INLINED_OSCALLS
#  endif /* !ACE_HAS_INLINED_OSCALLS */
#else
#  define ACE_INLINE
#endif /* __ACE_INLINE__ */

# if defined (ACE_HAS_GNUC_BROKEN_TEMPLATE_INLINE_FUNCTIONS)
#   define ACE_INLINE_FOR_GNUC ACE_INLINE
# else
#   define ACE_INLINE_FOR_GNUC
# endif /* ACE_HAS_GNUC_BROKEN_TEMPLATE_INLINE_FUNCTIONS */

// Some ACE classes always use inline functions to maintain high
// performance, but some platforms have buggy inline function support.
// In this case, we don't use inline with them.
# if defined (ACE_LACKS_INLINE_FUNCTIONS)
#   if defined (ASYS_INLINE)
#     undef ASYS_INLINE
#   endif /* ASYS_INLINE */
#   define ASYS_INLINE
#   if defined (ACE_HAS_INLINED_OSCALLS)
#     undef ACE_HAS_INLINED_OSCALLS
#   endif /* ACE_HAS_INLINED_OSCALLS */
# else
#   define ASYS_INLINE inline
# endif /* ACE_LACKS_INLINE_FUNCTIONS */

// ============================================================================
// EXPLICIT macro
// ============================================================================

# if defined (ACE_HAS_EXPLICIT_KEYWORD)
#   define ACE_EXPLICIT explicit
# else  /* ! ACE_HAS_EXPLICIT_KEYWORD */
#   define ACE_EXPLICIT
# endif /* ! ACE_HAS_EXPLICIT_KEYWORD */

// ============================================================================
// MUTABLE macro
// ============================================================================

# if defined (ACE_HAS_MUTABLE_KEYWORD)
#   define ACE_MUTABLE mutable
# else  /* ! ACE_HAS_MUTABLE_KEYWORD */
#   define ACE_MUTABLE
# endif /* ! ACE_HAS_MUTABLE_KEYWORD */

// ============================================================================
// EXPORT macros
//
// Since Win32 DLL's do not export all symbols by default, they must be
// explicitly exported (which is done by *_Export macros).
// ============================================================================

// Win32 should have already defined the macros in config-win32-common.h
#if !defined (ACE_HAS_CUSTOM_EXPORT_MACROS)
#  define ACE_Proper_Export_Flag
#  define ACE_Proper_Import_Flag
#  define ACE_EXPORT_SINGLETON_DECLARATION(T)
#  define ACE_IMPORT_SINGLETON_DECLARATION(T)
#  define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ACE_HAS_CUSTOM_EXPORT_MACROS */

#include "ace/ACE_export.h"
#include "ace/svc_export.h"

// This is a whim of mine -- that instead of annotating a class with
// ACE_Export in its declaration, we make the declaration near the TOP
// of the file with ACE_DECLARE_EXPORT.
// TS = type specifier (e.g., class, struct, int, etc.)
// ID = identifier
// So, how do you use it?  Most of the time, just use ...
// ACE_DECLARE_EXPORT(class, someobject);
// If there are global functions to be exported, then use ...
// ACE_DECLARE_EXPORT(void, globalfunction) (int, ...);
// Someday, when template libraries are supported, we made need ...
// ACE_DECLARE_EXPORT(template class, sometemplate) <class TYPE, class LOCK>;
# define ACE_DECLARE_EXPORT(TS,ID) TS ACE_Export ID

// ============================================================================
// Cast macros
//
// These macros are used to choose between the old cast style and the new
// *_cast<> operators
// ============================================================================

# if defined (ACE_HAS_ANSI_CASTS)

#   define ACE_sap_any_cast(TYPE)                                      reinterpret_cast<TYPE> (const_cast<ACE_Addr &> (ACE_Addr::sap_any))

#   define ACE_static_cast(TYPE, EXPR)                                 static_cast<TYPE> (EXPR)
#   define ACE_static_cast_1_ptr(TYPE, T1, EXPR)                       static_cast<TYPE<T1> *> (EXPR)
#   define ACE_static_cast_2_ptr(TYPE, T1, T2, EXPR)                   static_cast<TYPE<T1, T2> *> (EXPR)
#   define ACE_static_cast_3_ptr(TYPE, T1, T2, T3, EXPR)               static_cast<TYPE<T1, T2, T3> *> (EXPR)
#   define ACE_static_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)           static_cast<TYPE<T1, T2, T3, T4> *> (EXPR)
#   define ACE_static_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)       static_cast<TYPE<T1, T2, T3, T4, T5> *> (EXPR)
#   define ACE_static_cast_1_ref(TYPE, T1, EXPR)                       static_cast<TYPE<T1> &> (EXPR)
#   define ACE_static_cast_2_ref(TYPE, T1, T2, EXPR)                   static_cast<TYPE<T1, T2> &> (EXPR)
#   define ACE_static_cast_3_ref(TYPE, T1, T2, T3, EXPR)               static_cast<TYPE<T1, T2, T3> &> (EXPR)
#   define ACE_static_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)           static_cast<TYPE<T1, T2, T3, T4> &> (EXPR)
#   define ACE_static_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)       static_cast<TYPE<T1, T2, T3, T4, T5> &> (EXPR)

#   define ACE_const_cast(TYPE, EXPR)                                  const_cast<TYPE> (EXPR)
#   define ACE_const_cast_1_ptr(TYPE, T1, EXPR)                        const_cast<TYPE<T1> *> (EXPR)
#   define ACE_const_cast_2_ptr(TYPE, T1, T2, EXPR)                    const_cast<TYPE<T1, T2> *> (EXPR)
#   define ACE_const_cast_3_ptr(TYPE, T1, T2, T3, EXPR)                const_cast<TYPE<T1, T2, T3> *> (EXPR)
#   define ACE_const_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)            const_cast<TYPE<T1, T2, T3, T4> *> (EXPR)
#   define ACE_const_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)        const_cast<TYPE<T1, T2, T3, T4, T5> *> (EXPR)
#   define ACE_const_cast_1_ref(TYPE, T1, EXPR)                        const_cast<TYPE<T1> &> (EXPR)
#   define ACE_const_cast_2_ref(TYPE, T1, T2, EXPR)                    const_cast<TYPE<T1, T2> &> (EXPR)
#   define ACE_const_cast_3_ref(TYPE, T1, T2, T3, EXPR)                const_cast<TYPE<T1, T2, T3> &> (EXPR)
#   define ACE_const_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)            const_cast<TYPE<T1, T2, T3, T4> &> (EXPR)
#   define ACE_const_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)        const_cast<TYPE<T1, T2, T3, T4, T5> &> (EXPR)

#   define ACE_reinterpret_cast(TYPE, EXPR)                            reinterpret_cast<TYPE> (EXPR)
#   define ACE_reinterpret_cast_1_ptr(TYPE, T1, EXPR)                  reinterpret_cast<TYPE<T1> *> (EXPR)
#   define ACE_reinterpret_cast_2_ptr(TYPE, T1, T2, EXPR)              reinterpret_cast<TYPE<T1, T2> *> (EXPR)
#   define ACE_reinterpret_cast_3_ptr(TYPE, T1, T2, T3, EXPR)          reinterpret_cast<TYPE<T1, T2, T3> *> (EXPR)
#   define ACE_reinterpret_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)      reinterpret_cast<TYPE<T1, T2, T3, T4> *> (EXPR)
#   define ACE_reinterpret_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)  reinterpret_cast<TYPE<T1, T2, T3, T4, T5> *> (EXPR)
#   define ACE_reinterpret_cast_1_ref(TYPE, T1, EXPR)                  reinterpret_cast<TYPE<T1> &> (EXPR)
#   define ACE_reinterpret_cast_2_ref(TYPE, T1, T2, EXPR)              reinterpret_cast<TYPE<T1, T2> &> (EXPR)
#   define ACE_reinterpret_cast_3_ref(TYPE, T1, T2, T3, EXPR)          reinterpret_cast<TYPE<T1, T2, T3> &> (EXPR)
#   define ACE_reinterpret_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)      reinterpret_cast<TYPE<T1, T2, T3, T4> &> (EXPR)
#   define ACE_reinterpret_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)  reinterpret_cast<TYPE<T1, T2, T3, T4, T5> &> (EXPR)

#   if defined (ACE_LACKS_RTTI)
#     define ACE_dynamic_cast(TYPE, EXPR)                              static_cast<TYPE> (EXPR)
#     define ACE_dynamic_cast_1_ptr(TYPE, T1, EXPR)                    static_cast<TYPE<T1> *> (EXPR)
#     define ACE_dynamic_cast_2_ptr(TYPE, T1, T2, EXPR)                static_cast<TYPE<T1, T2> *> (EXPR)
#     define ACE_dynamic_cast_3_ptr(TYPE, T1, T2, T3, EXPR)            static_cast<TYPE<T1, T2, T3> *> (EXPR)
#     define ACE_dynamic_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)        static_cast<TYPE<T1, T2, T3, T4> *> (EXPR)
#     define ACE_dynamic_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)    static_cast<TYPE<T1, T2, T3, T4, T5> *> (EXPR)
#     define ACE_dynamic_cast_1_ref(TYPE, T1, EXPR)                    static_cast<TYPE<T1> &> (EXPR)
#     define ACE_dynamic_cast_2_ref(TYPE, T1, T2, EXPR)                static_cast<TYPE<T1, T2> &> (EXPR)
#     define ACE_dynamic_cast_3_ref(TYPE, T1, T2, T3, EXPR)            static_cast<TYPE<T1, T2, T3> &> (EXPR)
#     define ACE_dynamic_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)        static_cast<TYPE<T1, T2, T3, T4> &> (EXPR)
#     define ACE_dynamic_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)    static_cast<TYPE<T1, T2, T3, T4, T5> &> (EXPR)
#   else  /* ! ACE_LACKS_RTTI */
#     define ACE_dynamic_cast(TYPE, EXPR)                              dynamic_cast<TYPE> (EXPR)
#     define ACE_dynamic_cast_1_ptr(TYPE, T1, EXPR)                    dynamic_cast<TYPE<T1> *> (EXPR)
#     define ACE_dynamic_cast_2_ptr(TYPE, T1, T2, EXPR)                dynamic_cast<TYPE<T1, T2> *> (EXPR)
#     define ACE_dynamic_cast_3_ptr(TYPE, T1, T2, T3, EXPR)            dynamic_cast<TYPE<T1, T2, T3> *> (EXPR)
#     define ACE_dynamic_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)        dynamic_cast<TYPE<T1, T2, T3, T4> *> (EXPR)
#     define ACE_dynamic_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)    dynamic_cast<TYPE<T1, T2, T3, T4, T5> *> (EXPR)
#     define ACE_dynamic_cast_1_ref(TYPE, T1, EXPR)                    dynamic_cast<TYPE<T1> &> (EXPR)
#     define ACE_dynamic_cast_2_ref(TYPE, T1, T2, EXPR)                dynamic_cast<TYPE<T1, T2> &> (EXPR)
#     define ACE_dynamic_cast_3_ref(TYPE, T1, T2, T3, EXPR)            dynamic_cast<TYPE<T1, T2, T3> &> (EXPR)
#     define ACE_dynamic_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)        dynamic_cast<TYPE<T1, T2, T3, T4> &> (EXPR)
#     define ACE_dynamic_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)    dynamic_cast<TYPE<T1, T2, T3, T4, T5> &> (EXPR)
#   endif /* ! ACE_LACKS_RTTI */

# else

#   define ACE_sap_any_cast(TYPE)                                      ((TYPE) (ACE_Addr::sap_any))

#   define ACE_static_cast(TYPE, EXPR)                                 ((TYPE) (EXPR))
#   define ACE_static_cast_1_ptr(TYPE, T1, EXPR)                       ((TYPE<T1> *) (EXPR))
#   define ACE_static_cast_2_ptr(TYPE, T1, T2, EXPR)                   ((TYPE<T1, T2> *) (EXPR))
#   define ACE_static_cast_3_ptr(TYPE, T1, T2, T3, EXPR)               ((TYPE<T1, T2, T3> *) (EXPR))
#   define ACE_static_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)           ((TYPE<T1, T2, T3, T4> *) (EXPR))
#   define ACE_static_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)       ((TYPE<T1, T2, T3, T4, T5> *) (EXPR))
#   define ACE_static_cast_1_ref(TYPE, T1, EXPR)                       ((TYPE<T1> &) (EXPR))
#   define ACE_static_cast_2_ref(TYPE, T1, T2, EXPR)                   ((TYPE<T1, T2> &) (EXPR))
#   define ACE_static_cast_3_ref(TYPE, T1, T2, T3, EXPR)               ((TYPE<T1, T2, T3> &) (EXPR))
#   define ACE_static_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)           ((TYPE<T1, T2, T3, T4> &) (EXPR))
#   define ACE_static_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)       ((TYPE<T1, T2, T3, T4, T5> &) (EXPR))

#   define ACE_const_cast(TYPE, EXPR)                                  ((TYPE) (EXPR))
#   define ACE_const_cast_1_ptr(TYPE, T1, EXPR)                        ((TYPE<T1> *) (EXPR))
#   define ACE_const_cast_2_ptr(TYPE, T1, T2, EXPR)                    ((TYPE<T1, T2> *) (EXPR))
#   define ACE_const_cast_3_ptr(TYPE, T1, T2, T3, EXPR)                ((TYPE<T1, T2, T3> *) (EXPR))
#   define ACE_const_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)            ((TYPE<T1, T2, T3, T4> *) (EXPR))
#   define ACE_const_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)        ((TYPE<T1, T2, T3, T4, T5> *) (EXPR))
#   define ACE_const_cast_1_ref(TYPE, T1, EXPR)                        ((TYPE<T1> &) (EXPR))
#   define ACE_const_cast_2_ref(TYPE, T1, T2, EXPR)                    ((TYPE<T1, T2> &) (EXPR))
#   define ACE_const_cast_3_ref(TYPE, T1, T2, T3, EXPR)                ((TYPE<T1, T2, T3> &) (EXPR))
#   define ACE_const_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)            ((TYPE<T1, T2, T3, T4> &) (EXPR))
#   define ACE_const_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)        ((TYPE<T1, T2, T3, T4, T5> &) (EXPR))

#   define ACE_reinterpret_cast(TYPE, EXPR)                            ((TYPE) (EXPR))
#   define ACE_reinterpret_cast_1_ptr(TYPE, T1, EXPR)                  ((TYPE<T1> *) (EXPR))
#   define ACE_reinterpret_cast_2_ptr(TYPE, T1, T2, EXPR)              ((TYPE<T1, T2> *) (EXPR))
#   define ACE_reinterpret_cast_3_ptr(TYPE, T1, T2, T3, EXPR)          ((TYPE<T1, T2, T3> *) (EXPR))
#   define ACE_reinterpret_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)      ((TYPE<T1, T2, T3, T4> *) (EXPR))
#   define ACE_reinterpret_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)  ((TYPE<T1, T2, T3, T4, T5> *) (EXPR))
#   define ACE_reinterpret_cast_1_ref(TYPE, T1, EXPR)                  ((TYPE<T1> &) (EXPR))
#   define ACE_reinterpret_cast_2_ref(TYPE, T1, T2, EXPR)              ((TYPE<T1, T2> &) (EXPR))
#   define ACE_reinterpret_cast_3_ref(TYPE, T1, T2, T3, EXPR)          ((TYPE<T1, T2, T3> &) (EXPR))
#   define ACE_reinterpret_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)      ((TYPE<T1, T2, T3, T4> &) (EXPR))
#   define ACE_reinterpret_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)  ((TYPE<T1, T2, T3, T4, T5> &) (EXPR))

#   define ACE_dynamic_cast(TYPE, EXPR)                                ((TYPE) (EXPR))
#   define ACE_dynamic_cast_1_ptr(TYPE, T1, EXPR)                      ((TYPE<T1> *) (EXPR))
#   define ACE_dynamic_cast_2_ptr(TYPE, T1, T2, EXPR)                  ((TYPE<T1, T2> *) (EXPR))
#   define ACE_dynamic_cast_3_ptr(TYPE, T1, T2, T3, EXPR)              ((TYPE<T1, T2, T3> *) (EXPR))
#   define ACE_dynamic_cast_4_ptr(TYPE, T1, T2, T3, T4, EXPR)          ((TYPE<T1, T2, T3, T4> *) (EXPR))
#   define ACE_dynamic_cast_5_ptr(TYPE, T1, T2, T3, T4, T5, EXPR)      ((TYPE<T1, T2, T3, T4, T5> *) (EXPR))
#   define ACE_dynamic_cast_1_ref(TYPE, T1, EXPR)                      ((TYPE<T1> &) (EXPR))
#   define ACE_dynamic_cast_2_ref(TYPE, T1, T2, EXPR)                  ((TYPE<T1, T2> &) (EXPR))
#   define ACE_dynamic_cast_3_ref(TYPE, T1, T2, T3, EXPR)              ((TYPE<T1, T2, T3> &) (EXPR))
#   define ACE_dynamic_cast_4_ref(TYPE, T1, T2, T3, T4, EXPR)          ((TYPE<T1, T2, T3, T4> &) (EXPR))
#   define ACE_dynamic_cast_5_ref(TYPE, T1, T2, T3, T4, T5, EXPR)      ((TYPE<T1, T2, T3, T4, T5> &) (EXPR))
# endif /* ACE_HAS_ANSI_CASTS */

# if !defined (ACE_CAST_CONST)
    // Sun CC 4.2, for example, requires const in reinterpret casts of
    // data members in const member functions.  But, other compilers
    // complain about the useless const.  This keeps everyone happy.
#   if defined (__SUNPRO_CC)
#     define ACE_CAST_CONST const
#   else  /* ! __SUNPRO_CC */
#     define ACE_CAST_CONST
#   endif /* ! __SUNPRO_CC */
# endif /* ! ACE_CAST_CONST */

// ============================================================================
// UNICODE macros (to be added later)
// ============================================================================

// Get the unicode (i.e. ACE_TCHAR) defines
# include "ace/ace_wchar.h"


// ============================================================================
// Compiler Silencing macros
//
// Some compilers complain about parameters that are not used.  This macro
// should keep them quiet.
// ============================================================================

#if defined (ghs) || defined (__GNUC__) || defined (__hpux) || defined (__sgi) || defined (__DECCXX) || defined (__KCC) || defined (__rational__) || (__USLC__)
// Some compilers complain about "statement with no effect" with (a).
// This eliminates the warnings, and no code is generated for the null
// conditional statement.  NOTE: that may only be true if -O is enabled,
// such as with GreenHills (ghs) 1.8.8.
# define ACE_UNUSED_ARG(a) {if (&a) /* null */ ;}
#else /* ghs || __GNUC__ || ..... */
# define ACE_UNUSED_ARG(a) (a)
#endif /* ghs || __GNUC__ || ..... */

#if defined (__sgi) || defined (ghs) || defined (__DECCXX) || defined(__BORLANDC__) || defined (__KCC)
# define ACE_NOTREACHED(a)
#else  /* __sgi || ghs || ..... */
# define ACE_NOTREACHED(a) a
#endif /* __sgi || ghs || ..... */

// ============================================================================
// errno stuff
// ============================================================================

#if defined (ACE_HAS_H_ERRNO)
void herror (const char *str);
#endif /* ACE_HAS_H_ERRNO */

#if !defined (ACE_HAS_WINCE)
# include /**/ <errno.h>
#endif /* ACE_HAS_WINCE */

#if !defined (ACE_WIN32) && !defined (ACE_PSOS) && defined (ACE_LACKS_T_ERRNO)
extern int t_errno;
#endif /* ACE_WIN32 && !ACE_PSOS && ACE_LACKS_T_ERRNO */

// ============================================================================
// ACE_NEW macros
//
// A useful abstraction for expressions involving operator new since
// we can change memory allocation error handling policies (e.g.,
// depending on whether ANSI/ISO exception handling semantics are
// being used).
// ============================================================================

#if defined (ACE_NEW_THROWS_EXCEPTIONS)
# if (__SUNPRO_CC)
#   if (__SUNPRO_CC < 0x500) || ((__SUNPRO_CC == 0x500 && __SUNPRO_CC_COMPAT == 4))
#        include /**/ <exception.h>
         // Note: we catch ::xalloc rather than just xalloc because of
         // a name clash with unsafe_ios::xalloc()
#        define ACE_bad_alloc ::xalloc
#        define ACE_throw_bad_alloc throw ACE_bad_alloc ("no more memory")
#   else
#        include /**/ <new>
#        define ACE_bad_alloc std::bad_alloc
#        define ACE_throw_bad_alloc throw ACE_bad_alloc ()
#   endif /* __SUNPRO_CC < 0x500 */
# else
    // I know this works for HP aC++... if <stdexcept> is used, it
    // introduces other stuff that breaks things, like <memory>, which
    // screws up auto_ptr.
#   include /**/ <new>
#   if (defined (__HP_aCC) && !defined (RWSTD_NO_NAMESPACE)) \
       || defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#     define ACE_bad_alloc std::bad_alloc
#   else
#     define ACE_bad_alloc bad_alloc
#   endif /* RWSTD_NO_NAMESPACE */
#   define ACE_throw_bad_alloc throw ACE_bad_alloc ()
# endif /* __SUNPRO_CC */

# define ACE_NEW_RETURN(POINTER,CONSTRUCTOR,RET_VAL) \
   do { try { POINTER = new CONSTRUCTOR; } \
        catch (ACE_bad_alloc) { errno = ENOMEM; return RET_VAL; } \
   } while (0)

# define ACE_NEW(POINTER,CONSTRUCTOR) \
   do { try { POINTER = new CONSTRUCTOR; } \
        catch (ACE_bad_alloc) { errno = ENOMEM; return; } \
   } while (0)

#else /* ACE_NEW_THROWS_EXCEPTIONS */

# define ACE_NEW_RETURN(POINTER,CONSTRUCTOR,RET_VAL) \
   do { POINTER = new CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; return RET_VAL; } \
   } while (0)
# define ACE_NEW(POINTER,CONSTRUCTOR) \
   do { POINTER = new CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; return; } \
   } while (0)

# define ACE_throw_bad_alloc \
  void* gcc_will_complain_if_literal_0_is_returned = 0; \
  return gcc_will_complain_if_literal_0_is_returned

#endif /* ACE_NEW_THROWS_EXCEPTIONS */

// ============================================================================
// ACE_OSCALL_* macros
//
// The following two macros ensure that system calls are properly
// restarted (if necessary) when interrupts occur.
// ============================================================================

#if defined (ACE_HAS_SIGNAL_SAFE_OS_CALLS)
#   define ACE_OSCALL(OP,TYPE,FAILVALUE,RESULT) \
  do \
    RESULT = (TYPE) OP; \
  while (RESULT == FAILVALUE && errno == EINTR)
#   define ACE_OSCALL_RETURN(OP,TYPE,FAILVALUE) \
  do { \
    TYPE ace_result_; \
    do \
      ace_result_ = (TYPE) OP; \
    while (ace_result_ == FAILVALUE && errno == EINTR); \
    return ace_result_; \
  } while (0)
# elif defined (ACE_WIN32)
#   define ACE_OSCALL_RETURN(X,TYPE,FAILVALUE) \
  do \
    return (TYPE) X; \
  while (0)
#   define ACE_OSCALL(X,TYPE,FAILVALUE,RESULT) \
  do \
    RESULT = (TYPE) X; \
  while (0)
#   if defined (__BORLANDC__) && (__BORLANDC__ <= 0x550)
#   define ACE_WIN32CALL_RETURN(X,TYPE,FAILVALUE) \
  do { \
    TYPE ace_result_; \
    TYPE ace_local_result_ = (TYPE) X; \
    ace_result_ = ace_local_result_; \
    if (ace_result_ == FAILVALUE) \
      ACE_OS::set_errno_to_last_error (); \
    return ace_result_; \
  } while (0)
#   else
#     define ACE_WIN32CALL_RETURN(X,TYPE,FAILVALUE) \
  do { \
    TYPE ace_result_; \
    ace_result_ = (TYPE) X; \
    if (ace_result_ == FAILVALUE) \
      ACE_OS::set_errno_to_last_error (); \
    return ace_result_; \
  } while (0)
#   endif /* defined (__BORLANDC__) && (__BORLANDC__ <= 0x550) */
#   define ACE_WIN32CALL(X,TYPE,FAILVALUE,RESULT) \
  do { \
    RESULT = (TYPE) X; \
    if (RESULT == FAILVALUE) \
      ACE_OS::set_errno_to_last_error (); \
  } while (0)
#else /* ACE_HAS_SIGNAL_SAFE_OS_CALLS */
#   define ACE_OSCALL_RETURN(OP,TYPE,FAILVALUE) do { TYPE ace_result_ = FAILVALUE; ace_result_ = ace_result_; return OP; } while (0)
#   define ACE_OSCALL(OP,TYPE,FAILVALUE,RESULT) do { RESULT = (TYPE) OP; } while (0)
#endif /* ACE_HAS_SIGNAL_SAFE_OS_CALLS */

// ============================================================================
// at_exit declarations
// ============================================================================

// Marker for cleanup, used by ACE_Exit_Info.
extern int ace_exit_hook_marker;

// For use by <ACE_OS::exit>.
extern "C"
{
  typedef void (*ACE_EXIT_HOOK) (void);
}

// ============================================================================
// log_msg declarations
// ============================================================================

# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
typedef int (*ACE_SEH_EXCEPT_HANDLER)(void *);
// Prototype of win32 structured exception handler functions.
// They are used to get the exception handling expression or
// as exception handlers.
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

class ACE_OS_Thread_Descriptor;
typedef void (*ACE_INIT_LOG_MSG_HOOK) (void*&
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
                                       , ACE_SEH_EXCEPT_HANDLER selector
                                       , ACE_SEH_EXCEPT_HANDLER handler
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
                                       );
typedef void (*ACE_INHERIT_LOG_MSG_HOOK) (ACE_OS_Thread_Descriptor*, void*&);

// ============================================================================
// Fundamental types
// ============================================================================

#if defined (ACE_WIN32)

typedef HANDLE ACE_HANDLE;
typedef SOCKET ACE_SOCKET;
# define ACE_INVALID_HANDLE INVALID_HANDLE_VALUE

#else /* ! ACE_WIN32 */

typedef int ACE_HANDLE;
typedef ACE_HANDLE ACE_SOCKET;
# define ACE_INVALID_HANDLE -1

#endif /* ACE_WIN32 */

// ============================================================================
// Miscellaneous macros
// ============================================================================

# if !defined (ENOSYS)
#   define ENOSYS EFAULT /* Operation not supported or unknown error. */
# endif /* !ENOSYS */

#if !defined (ENOTSUP)
# define ENOTSUP ENOSYS  /* Operation not supported. */
#endif /* !ENOTSUP */

// This is used to indicate that a platform doesn't support a
// particular feature.
#if defined ACE_HAS_VERBOSE_NOTSUP
  // Print a console message with the file and line number of the
  // unsupported function.
# if defined (ACE_HAS_STANDARD_CPP_LIBRARY) && (ACE_HAS_STANDARD_CPP_LIBRARY != 0)
#   include /**/ <cstdio>
# else
#   include /**/ <stdio.h>
# endif
# define ACE_NOTSUP_RETURN(FAILVALUE) do { errno = ENOTSUP; fprintf (stderr, ACE_TEXT ("ACE_NOTSUP: %s, line %d\n"), __FILE__, __LINE__); return FAILVALUE; } while (0)
# define ACE_NOTSUP do { errno = ENOTSUP; fprintf (stderr, ACE_TEXT ("ACE_NOTSUP: %s, line %d\n"), __FILE__, __LINE__); return; } while (0)
#else /* ! ACE_HAS_VERBOSE_NOTSUP */
# define ACE_NOTSUP_RETURN(FAILVALUE) do { errno = ENOTSUP ; return FAILVALUE; } while (0)
# define ACE_NOTSUP do { errno = ENOTSUP; return; } while (0)
#endif /* ! ACE_HAS_VERBOSE_NOTSUP */

#include "ace/post.h"
#endif /* ACE_CONFIG_ALL_H */
