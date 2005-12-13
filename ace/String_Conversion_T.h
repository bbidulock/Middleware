/* -*- C++ -*- */
// $Id$

#ifndef STRING_CONVERTER_T_H
#define STRING_CONVERTER_T_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ace_wchar.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace ACE
{

namespace String_Conversion
{
// The duplicate/copy(_new) suite of methods are used to provide seamless
// conversions between wchar_t and char.
// * The alloc/free suite of methods are used to advertise
//   how the String_Conversion services manage memory.
//   Alloc allocates len + 1 and sets first byte to zero.
// * The duplicate method allocates the output string.
// * The copy method is the worker that expects two existing buffers
//   of at least <len+1> size. It will always NULL terminate the dest string.

static const size_t calc_len = static_cast<size_t>(-1);

template < typename T >
class Allocator_cpp
{
public:
  T* alloc( size_t len ) const;

  void free( T* str ) const;
};

template < typename T >
class Allocator_malloc
{
public:
  T* alloc( size_t len ) const;

  void free( T* str ) const;
};

template < typename DestT, typename SrcT, typename Allocator > ACE_INLINE
DestT*
duplicate( const SrcT* src, size_t* dest_len = 0 );

template < typename DestT, typename SrcT > ACE_INLINE
size_t
copy( DestT* dest, const SrcT* src, size_t dest_len = calc_len );

// Length Note:
// The len parameters are content-length. The need to
// allocate more (len + 1 for null character) is an
// implementation detail.

// Constructor Note:
// The classes have overriden constructors. This
// obviates the need for the user to explicitely
// redeclare the type of the input. The classes
// will do the right/optimal thing depending
// on the type.

/**
 * @class Convert_Out
 *
 * @brief A lightweight classed used for
 *        output symmantics.
 *
 * This class will always allocate a new copy
 * of the source string.
 */
template < typename DestT, typename Allocator = Allocator_cpp<DestT> >
class Convert_Out
{
public:
  template < typename SrcT >
  explicit Convert_Out( const SrcT* src, size_t len = calc_len )
  : len_( len )
  , dest_( duplicate<DestT, SrcT, Allocator>( src, &len_ ) )
  {
  }

  // Make certain we provide a counter to the allocation
  static void free( DestT* ptr )
  {
    Allocator().free( ptr );
  }

  DestT* c_str() const;

#if !defined (ACE_LACKS_DEPRECATED_MACROS)
  DestT* char_rep() const
  {
    return c_str();
  }
#endif

  size_t length() const;

private:
  size_t len_;
  DestT* dest_;

  /// Not implemented.
  Convert_Out();
  Convert_Out( Convert_Out& );
  Convert_Out& operator= ( Convert_Out& );
};


/**
 * @class Convert_In
 *
 * @brief A lightweight classed used for
 *        input symmantics.
 *
 * This class will either pass the src string
 * along or make a temporary copy.
 * The c_str() is const and should not be modified.
 *
 * TODO: Remove <typename SrcT> from class template.
 *       It appears that some compilers do not support
 *       template method specialization within a template
 *       class.
 */
template < typename DestT, typename SrcT >
class Convert_In
{
public:
  //template < typename SrcT >
  explicit Convert_In( const SrcT* src )
  : str_(0)
  , ownstr_( duplicate<DestT, SrcT, Allocator_cpp<DestT> >( src, 0 ) )
  {
  }

  // This is an optimized specialization
  // where src and dest are the same type
  //template <>
  explicit Convert_In( const DestT* src )
  : str_(src)
  , ownstr_(0)
  {
  }

  ~Convert_In();

  const DestT* c_str() const;

#if !defined (ACE_LACKS_DEPRECATED_MACROS)
  const DestT* char_rep() const
  {
    return c_str();
  }
#endif

private:
  const DestT* str_;
  DestT* ownstr_;

  /// Not implemented.
  Convert_In();
  Convert_In( Convert_In& );
  Convert_In& operator= ( Convert_In& );
};


/**
 * @class Convert_InOut
 *
 * @brief A lightweight classed used for
 *        input/output symmantics.
 *
 * This class will either pass the src string
 * along or make a temporary copy.
 * The if a temp string is created, it is copied
 * back to the src on destruction.
 *
 * NOTE: Make certain src points to a NULL teminated string.
 *
 * NOTE: The size passed in at construction is buffer size,
 * including space for the NULL char.
 *
 * NOTE: encode_factor is used when we believe that the number
 * of characters required differs between the two representations.
 * To avoid data loss, we default to an oversized buffer of size*3.
 */
template < typename DestT, typename SrcT >
class Convert_InOut
{
public:
  //template < typename SrcT >
  explicit Convert_InOut( SrcT* src, size_t size, size_t encode_factor = 3 )
  : len_( size == calc_len ? calc_len : (size - 1) * encode_factor )
  , encode_factor_( size == calc_len ? 1 : encode_factor )
  , str_(0)
  , orig_(src)
  , ownstr_( duplicate<DestT, SrcT, Allocator_cpp<DestT> >(src, &len_))
  {
  }

  //template < typename SrcT >
  explicit Convert_InOut( SrcT* src )
  : len_(calc_len)
  , encode_factor_(1)
  , str_(0)
  , orig_(src)
  , ownstr_( duplicate<DestT, SrcT, Allocator_cpp<DestT> >(src, &len_))
  {
  }

  // This is an optimized specialization
  // where src and dest are the same type
  //template <>
  explicit Convert_InOut( DestT* src, size_t size = calc_len )
  : len_( size == calc_len ? calc_len : size - 1 )
  , encode_factor_(1)
  , str_(src)
  , orig_(0)
  , ownstr_(0)
  {
  }

  ~Convert_InOut();

  DestT* c_str();

  size_t size() const
  {
    return len_+1;
  }

#if !defined (ACE_LACKS_DEPRECATED_MACROS)
  DestT* char_rep()
  {
    return c_str();
  }
#endif

private:
  /// Internal pointer to the converted string.
  size_t  len_;
  size_t  encode_factor_;
  DestT*  str_;
  SrcT*   orig_;
  DestT*  ownstr_;

  /// Not implemented.
  Convert_InOut();
  Convert_InOut( Convert_InOut& );
  Convert_InOut& operator= ( Convert_InOut& );
};

} // String_Conversion

} // ACE

// Conversion Macros
# define ACE_TEXT_TO_CHAR_OUT(STRING) ACE::String_Conversion::Convert_Out< char >( STRING ).c_str()
# define ACE_TEXT_TO_WCHAR_OUT(STRING) ACE::String_Conversion::Convert_Out< wchar_t >( STRING ).c_str()
# define ACE_TEXT_TO_TCHAR_OUT(STRING) ACE::String_Conversion::Convert_Out< ACE_TCHAR >( STRING ).c_str()

# define ACE_TEXT_TO_MALLOC_CHAR_OUT(STRING) ACE::String_Conversion::Convert_Out< char, ACE::String_Conversion::Allocator_malloc<char> >( STRING ).c_str()
# define ACE_TEXT_TO_MALLOC_WCHAR_OUT(STRING) ACE::String_Conversion::Convert_Out< wchar_t, ACE::String_Conversion::Allocator_malloc<wchar_t> >( STRING ).c_str()
# define ACE_TEXT_TO_MALLOC_TCHAR_OUT(STRING) ACE::String_Conversion::Convert_Out< ACE_TCHAR, ACE::String_Conversion::Allocator_malloc<ACE_TCHAR> >( STRING ).c_str()

# define ACE_TEXT_TO_CHAR_IN(STRING) ACE::String_Conversion::Convert_In< char, wchar_t  >( STRING ).c_str()
# define ACE_TEXT_TO_WCHAR_IN(STRING) ACE::String_Conversion::Convert_In< wchar_t, char >( STRING ).c_str()
# define ACE_TEXT_TO_TCHAR_IN(STRING) ACE::String_Conversion::Convert_In< ACE_TCHAR, ACE_ANTI_TCHAR >( STRING ).c_str()

# define ACE_TEXT_TO_CHAR_INOUT(STRING) ACE::String_Conversion::Convert_InOut< char, wchar_t >( STRING ).c_str()
# define ACE_TEXT_TO_WCHAR_INOUT(STRING) ACE::String_Conversion::Convert_InOut< wchar_t, char >( STRING ).c_str()
# define ACE_TEXT_TO_TCHAR_INOUT(STRING) ACE::String_Conversion::Convert_InOut< ACE_TCHAR, ACE_ANTI_TCHAR >( STRING ).c_str()

#if !defined (ACE_LACKS_DEPRECATED_MACROS)

// Global Namespace Types
typedef ACE::String_Conversion::Convert_In< char, wchar_t > ACE_Wide_To_Ascii;
typedef ACE::String_Conversion::Convert_In< wchar_t, char > ACE_Ascii_To_Wide;
typedef ACE::String_Conversion::Convert_In< ACE_TCHAR, ACE_ANTI_TCHAR > ACE_AntiChar_To_TChar;
typedef ACE::String_Conversion::Convert_In< ACE_ANTI_TCHAR, ACE_TCHAR > ACE_TChar_To_AntiChar;

#if defined (ACE_LEGACY_MODE)

typedef ACE_Ascii_To_Wide ACE_OS_CString;
typedef ACE_Wide_To_Ascii ACE_OS_WString;

# define ASYS_ONLY_MULTIBYTE_STRING ACE_TEXT_TO_CHAR_IN
# define ASYS_MULTIBYTE_STRING ACE_TEXT_TO_TCHAR_IN
# define ASYS_WIDE_STRING ACE_TEXT_TO_TCHAR_IN
# define ACE_WIDE_STRING ACE_TEXT_TO_TCHAR_IN

# if defined (ACE_USES_WCHAR)
#   define ASYS_ONLY_WIDE_STRING(STRING) STRING
# else /* ACE_USES_WCHAR */
#   define ASYS_ONLY_WIDE_STRING(STRING) \
           ACE_Ascii_To_Wide (STRING).char_rep ()
# endif /* ACE_USES_WCHAR */

#endif /* ACE_LEGACY_MODE */

// Legacy Macros
// These macros have been deprecated in favor of those stated above
// or expicitely declaring the converter instance.
// These macros will no longer work where the destination requires
// a non-const string.
#define ACE_TEXT_ALWAYS_CHAR(STRING) ACE_TEXT_TO_CHAR_IN( STRING )
#define ACE_TEXT_ALWAYS_WCHAR(STRING) ACE_TEXT_TO_WCHAR_IN( STRING )
#define ACE_TEXT_CHAR_TO_TCHAR(STRING) ACE_TEXT_TO_TCHAR_IN( STRING )
#define ACE_TEXT_WCHAR_TO_TCHAR(STRING) ACE_TEXT_TO_TCHAR_IN( STRING )
#define ACE_TEXT_ANTI_TO_TCHAR(STRING) ACE_TEXT_TO_TCHAR_IN (STRING)

// These macros have been deprecated and should be replaced by their
// ACE_TEXT_* equivalents.  These macros are just hacks and may not
// completely provide the old functionality.
#if defined (ACE_LEGACY_MODE)
// These are defined to get older stuff to compile
// FUZZ: disable check_for_tchar
# define ASYS_TCHAR ACE_TCHAR
# define ASYS_TEXT ACE_LIB_TEXT
# define ACE_TEXT_STRING ACE_TString
#endif /* ACE_LEGACY_MODE */

#endif /* !ACE_LACKS_DEPRECATED_MACROS */

#if defined (__ACE_INLINE__)
#include "ace/String_Conversion_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/String_Conversion_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("String_Conversion_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* STRING_CONVERTER_T_H */
