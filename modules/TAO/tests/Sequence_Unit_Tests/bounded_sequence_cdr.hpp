#ifndef guard_bounded_sequence_cdr
#define guard_bounded_sequence_cdr
/**
 * @file
 *
 * @brief Extract the sequence
 *
 * $Id$
 *
 * @author Carlos O'Ryan
 * @author Johnny Willemsen
 */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO {
  namespace details {
    template <typename stream, typename sequence>
    bool extract_bounded_sequence(stream & strm, sequence & target) {
      ::CORBA::ULong new_length;
      if (!(strm >> new_length)) {
        return false;
      }
      if (new_length > strm.length()) {
         return false;
      }
      if (new_length > target.maximum ()) {
         return false;
      }
      sequence tmp;
      tmp.length(new_length);
      typename sequence::value_type * buffer = tmp.get_buffer();
      for(CORBA::ULong i = 0; i < new_length; ++i) {
        if (!(strm >> buffer[i])) {
          return false;
        }
      }
      tmp.swap(target);
      return true;
    }

    template <typename stream, typename sequence>
    bool insert_bounded_sequence(stream & strm, const sequence & source) {
      const ::CORBA::ULong length = source.length ();
      if (!(strm << length)) {
        return false;
      }
      for(CORBA::ULong i = 0; i < length; ++i) {
        if (!(strm << source[i])) {
          return false;
        }
      }
      return true;
    }
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL
#endif /* guard_bounded_sequence_cdr */
