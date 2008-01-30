#ifndef guard_bounded_basic_string_sequence_hpp
#define guard_bounded_basic_string_sequence_hpp
/**
 * @file
 *
 * @brief Implement bounded sequences for strings and wide-strings.
 *
 * $Id$
 *
 * @author Carlos O'Ryan
 */
#include "tao/Bounded_Reference_Allocation_Traits_T.h"
#include "tao/String_Traits_T.h"
#include "tao/Generic_Sequence_T.h"
#include "tao/String_Sequence_Element_T.h"
#include "tao/String_Const_Sequence_Element_T.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{

#if TAO_HAS_SEQUENCE_ITERATORS

// Forward declare the iterators
template<typename T>
class BBS_Sequence_Iterator;

template<typename T>
class Const_BBS_Sequence_Iterator;

template<typename T>
class BBS_Sequence_Reverse_Iterator;

template<typename T>
class Const_BBS_Sequence_Reverse_Iterator;
  
#endif /* TAO_HAS_SEQUENCE_ITERATORS */

template<typename charT, CORBA::ULong MAX>
class bounded_basic_string_sequence
{
public:
  typedef charT character_type;
  typedef charT * value_type;
  typedef charT const * const_value_type;

  typedef details::string_traits<charT,true> element_traits;
  typedef details::bounded_reference_allocation_traits<value_type,element_traits,MAX,true> allocation_traits;

  typedef details::string_sequence_element<element_traits> element_type;
  typedef details::string_const_sequence_element<element_traits> const_element_type;
  typedef element_type subscript_type;
  typedef const_value_type const_subscript_type;

  typedef details::generic_sequence<value_type, allocation_traits, element_traits> implementation_type;

  /// @copydoc details::generic_sequence::generic_sequence
  inline bounded_basic_string_sequence()
    : impl_()
  {}
  /// @copydoc details::generic_sequence::generic_sequence
  inline bounded_basic_string_sequence(
      CORBA::ULong length,
      value_type * data,
      CORBA::Boolean release)
    : impl_(MAX, length, data, release)
  {}
  /// @copydoc details::generic_sequence::maximum
  inline CORBA::ULong maximum() const {
    return impl_.maximum();
  }
  /// @copydoc details::generic_sequence::release
  inline CORBA::Boolean release() const {
    return impl_.release();
  }
  /// @copydoc details::generic_sequence::length
  inline CORBA::ULong length() const {
    return impl_.length();
  }

  /// @copydoc details::generic_sequence::length
  inline void length(CORBA::ULong length) {
    implementation_type::range::check_length(length, MAX);
    impl_.length(length);
  }
  /// @copydoc details::generic_sequence::operator[]
  inline const_element_type operator[](CORBA::ULong i) const {
    return const_element_type (impl_[i], release());
  }
  /// @copydoc details::generic_sequence::operator[]
  inline element_type operator[](CORBA::ULong i) {
    return element_type(impl_[i], release());
  }
  /// @copydoc details::generic_sequence::get_buffer
  inline const_value_type const * get_buffer() const {
    return impl_.get_buffer();
  }
  /// @copydoc details::generic_sequence::replace
  inline void replace(
      CORBA::ULong length,
      value_type * data,
      CORBA::Boolean release = false) {
    impl_.replace(MAX, length, data, release);
  }
  /// @copydoc TAO::details::generic_sequence::get_buffer(CORBA::Boolean)
  inline value_type * get_buffer(CORBA::Boolean orphan = false) {
    return impl_.get_buffer(orphan);
  }
  inline void swap(bounded_basic_string_sequence & rhs) throw() {
    impl_.swap(rhs.impl_);
  }

  static value_type * allocbuf(CORBA::ULong maximum)
  {
    return implementation_type::allocbuf(maximum);
  }
  static value_type * allocbuf() {
    return implementation_type::allocbuf(MAX);
  }
  static void freebuf(value_type * buffer)
  {
    implementation_type::freebuf(buffer);
  }

#if TAO_HAS_SEQUENCE_ITERATORS

  ///
  /// Additions to support iterator semantics for TAO unbounded basic
  /// string sequences.
  ///

  // = Traits and factory methods that create iterators.
  typedef BBS_Sequence_Iterator<bounded_basic_string_sequence<charT, MAX> > iterator;
  typedef Const_BBS_Sequence_Iterator<bounded_basic_string_sequence<charT, MAX> > const_iterator;
  typedef BBS_Sequence_Reverse_Iterator<bounded_basic_string_sequence<charT, MAX> > reverse_iterator;
  typedef Const_BBS_Sequence_Reverse_Iterator<bounded_basic_string_sequence<charT, MAX> > const_reverse_iterator;

  // Get an iterator that points to the beginning of the sequence.
  iterator begin (void)
  {
    return iterator (&this->impl_);
  }

  // Get a const iterator that points to the beginning of the sequence.
  const_iterator begin (void) const
  {
    return const_iterator (&this->impl_);
  }

  // Get an iterator that points to the end of the sequence.
  iterator end (void)
  {
    return iterator (&this->impl_,
                     this->impl_.length ());
  }

  // Get a const iterator that points to the end of the sequence.
  const_iterator end (void) const
  {
    return const_iterator (&this->impl_,
                           this->impl_.length ());
  }

  // Get a reverse iterator that points to the end of the sequence.
  reverse_iterator rbegin (void)
  {
    return reverse_iterator (&this->impl_,
                             this->impl_.length () - 1);
  }

  // Get a const reverse iterator that points to the end of the sequence.
  const_reverse_iterator rbegin (void) const
  {
    return const_reverse_iterator (&this->impl_,
                                   this->impl_.length () - 1);
  }

  // Get a reverse iterator that points to one before the beginning
  // of the sequence.
  reverse_iterator rend (void)
  {
    return reverse_iterator (&this->impl_,
                             -1);
  }

  // Get a const reverse iterator that points to one before the
  // beginning of the sequence.
  const_reverse_iterator rend (void) const
  {
    return const_reverse_iterator (&this->impl_,
                                   -1);
  }

#endif /* TAO_HAS_SEQUENCE_ITERATORS */

private:
  implementation_type impl_;
};


/**
 * @class BBS_Sequence_Iterator
 * @brief Implements a random access iterator for generic sequence type classes.
 */
template <typename SEQUENCE_T>
  class BBS_Sequence_Iterator
{
  friend class Const_BBS_Sequence_Iterator<SEQUENCE_T>;

public:
  // = Necessary traits
  typedef std::random_access_iterator_tag iterator_category;
  typedef typename SEQUENCE_T::value_type value_type;
  typedef typename SEQUENCE_T::value_type *pointer;
  typedef typename SEQUENCE_T::value_type &reference;
  typedef typename SEQUENCE_T::element_type element_type;
  typedef typename SEQUENCE_T::const_element_type const_element_type;
  typedef typename SEQUENCE_T::allocation_traits allocation_traits;
  typedef typename SEQUENCE_T::element_traits element_traits;
  typedef typename SEQUENCE_T::implementation_type implementation_type;
  typedef CORBA::Long difference_type;

  /// Construct a BBS_Sequence_Iterator at position pos.
  BBS_Sequence_Iterator (implementation_type *sequence, 
			 size_t pos = 0)
    : sequence_ (sequence),
    pos_ (pos)
      {
      }

  /// Copy constructor
  BBS_Sequence_Iterator (BBS_Sequence_Iterator<SEQUENCE_T> const & rhs)
    : sequence_ (rhs.sequence_),
    pos_ (rhs.pos_)
      {
      }
  
  /// Assignment operator
  BBS_Sequence_Iterator & operator= (BBS_Sequence_Iterator<SEQUENCE_T> const & rhs)
    {
      BBS_Sequence_Iterator tmp(rhs);
      swap (tmp);
      return * this;
    }

  /// swaps all members
  void swap(BBS_Sequence_Iterator<SEQUENCE_T> & rhs) 
    throw()
    {
      std::swap (sequence_, rhs.sequence_);
      std::swap (this->pos_, rhs.pos_);
    }

  /// typecast operator to Const_BBS_Sequence_Iterator
  operator Const_BBS_Sequence_Iterator<SEQUENCE_T> ()
  {
    return Const_BBS_Sequence_Iterator<SEQUENCE_T> (*this);
  }

  /// Dereference operator returns a reference to the item contained
  /// at the current position
  element_type operator* (void)
    {
      // Access the underlying element in the sequence.
      return element_type ((*(this->sequence_))[this->pos_],
                           this->sequence_->release ());
    }

  /// Returns a const reference to the item contained at the current position
  const_element_type operator* (void) const
    {
      // Access the underlying element in the sequence.
      return const_element_type ((*(this->sequence_))[this->pos_],
                                 this->sequence_->release ());
    }

  /// Preincrement operator
  BBS_Sequence_Iterator<SEQUENCE_T> &operator++ (void)
    {
      // Increment the position.
      // We also need to check if we're now past the end.
      ++this->pos_;
      return *this;
    }

  /// Postincrement operator
  BBS_Sequence_Iterator<SEQUENCE_T> operator++ (int)
    {
      // Create a temporary to return so that it's not modified.
      BBS_Sequence_Iterator<SEQUENCE_T> temp_iter (this->sequence_, this->pos_);
      // Increment the position.
      // We also need to check if we're now past the end.
      ++this->pos_;
      return temp_iter;
    }

  /// Predecrement operator
  BBS_Sequence_Iterator<SEQUENCE_T> &operator-- (void)
    {
      --this->pos_;
      return *this;
    }

  /// Postdecrement operator
  BBS_Sequence_Iterator<SEQUENCE_T> operator-- (int)
    {
      // Create a temporary to return so that it's not modified.
      BBS_Sequence_Iterator<SEQUENCE_T> temp_iter (this->sequence_, this->pos_);
      --this->pos_;
      return temp_iter;
    }

  /// Iterator addition
  BBS_Sequence_Iterator<SEQUENCE_T> &operator+= (difference_type n)
    {
      // Move ahead n elements.
      this->pos_ += n;
      return *this;
    }

  /// Iterator addition
  BBS_Sequence_Iterator<SEQUENCE_T> operator+ (difference_type n)
    {
      // Create a temporary to return and move it ahead n elements.
      return BBS_Sequence_Iterator<SEQUENCE_T> (this->sequence_, this->pos_ + n);
    }

  /// Iterator subtraction
  BBS_Sequence_Iterator<SEQUENCE_T> &operator-= (difference_type n)
    {
      // Move back n elements.
      this->pos_ -= n;
      return *this;
    }

  /// Iterator subtraction
  BBS_Sequence_Iterator<SEQUENCE_T> operator- (difference_type n)
    {
      // Create a temporary to return and move it back n elements.
      return BBS_Sequence_Iterator<SEQUENCE_T> (this->sequence_, this->pos_ - n);
    }

  /// Difference
  difference_type operator- (const BBS_Sequence_Iterator<SEQUENCE_T> & rhs)
    {
      // I think order is important here (i.e., this before rhs).
      return this->pos_ - rhs.pos_;
    }

  /// Difference
  difference_type operator- (const Const_BBS_Sequence_Iterator<SEQUENCE_T> & rhs)
    {
      // I think order is important here (i.e., this before rhs).
      return this->pos_ - rhs.pos_;
    }

  /// Element operator/assignment
  element_type operator[] (difference_type n)
    {
      // Return the element at position pos_ + n
      return element_type ((*(this->sequence_))[this->pos_ + n],
                           this->sequence_->release ());
    }

  /// Element operator/assignment
  const_element_type operator[] (difference_type n) const
    {
      // Return the element at position pos_ + n
      return const_element_type ((*(this->sequence_))[this->pos_ + n],
                                 this->sequence_->release ());
    }

  /// Less than
  bool operator< (const BBS_Sequence_Iterator<SEQUENCE_T> & rhs)
    {
      // Return if this iterator is less than the passed in iterator.
      return this->pos_ < rhs.pos_;
    }

  /// Less than
  bool operator< (const Const_BBS_Sequence_Iterator<SEQUENCE_T> & rhs)
    {
      // Return if this iterator is less than the passed in iterator.
      return this->pos_ < rhs.pos_;
    }


  /// Equality operator
  bool operator== (const BBS_Sequence_Iterator<SEQUENCE_T> &rhs) const
  {
    // Compare all the data members for equality.
    return this->sequence_ == rhs.sequence_
        && this->pos_ == rhs.pos_;
  }

  /// Nonequality operator
  bool operator!= (const BBS_Sequence_Iterator<SEQUENCE_T> &rhs) const
  {
    return !(*this == rhs);
  }

private:
  /// the sequence with which we are dealing
  implementation_type *sequence_;

  /// Our current position in the sequence.
  mutable difference_type pos_;
};


/// Iterator addition with the difference_type being the first argument.
template<typename SEQUENCE_T>
 BBS_Sequence_Iterator<SEQUENCE_T>
  operator+ (typename BBS_Sequence_Iterator<SEQUENCE_T>::difference_type n,
             const BBS_Sequence_Iterator<SEQUENCE_T> & iter)
   {
     // Create an iter and move it ahead n elements.
     return BBS_Sequence_Iterator<SEQUENCE_T> (iter.sequence_, iter.pos_ + n);
   }

/// Iterator subtraction with the difference_type being the first argument.
template<typename SEQUENCE_T>
 BBS_Sequence_Iterator<SEQUENCE_T> operator-
   (typename BBS_Sequence_Iterator<SEQUENCE_T>::difference_type n,
    BBS_Sequence_Iterator<SEQUENCE_T> iter)
   {
     // Create an iter and move it back n elements.
     return BBS_Sequence_Iterator<SEQUENCE_T> (iter.sequence_, iter.pos_ - n);
   }


/**
 * @class Const_BBS_Sequence_Iterator
 * @brief Implements a random access iterator for generic sequence type classes.
 *
 * Note:  Having a const Iterator does not guarantee that the current
 * *position* that it points to will not change, it only guarantees that
 * you cannot change the underlying array!
 */
template <typename SEQUENCE_T>
class Const_BBS_Sequence_Iterator 
{
  friend class BBS_Sequence_Iterator<SEQUENCE_T>;

public:
  // = Necessary traits
  typedef std::random_access_iterator_tag iterator_category;
  typedef typename SEQUENCE_T::value_type value_type;
  typedef typename SEQUENCE_T::value_type *pointer;
  typedef typename SEQUENCE_T::value_type &reference;
  typedef typename SEQUENCE_T::const_element_type const_element_type;
  typedef typename SEQUENCE_T::allocation_traits allocation_traits;
  typedef typename SEQUENCE_T::element_traits element_traits;
  typedef typename SEQUENCE_T::implementation_type implementation_type;
  typedef int difference_type;

  /// Construct a Const_BBS_Sequence_Iterator at position pos from
  /// a const sequence.
  Const_BBS_Sequence_Iterator (const implementation_type *sequence,
                               size_t pos = 0)
    : sequence_ (sequence),
    pos_ (pos)
      {
      }

  virtual ~Const_BBS_Sequence_Iterator ()
    {
    }

  /// Copy constructor
  Const_BBS_Sequence_Iterator (
		Const_BBS_Sequence_Iterator<SEQUENCE_T> const & rhs)
    : sequence_ (rhs.sequence_),
    pos_ (rhs.pos_)
      {
      }

  /// Copy constructor initializing by a BBS_Sequence_Iterator
  Const_BBS_Sequence_Iterator (
		BBS_Sequence_Iterator<SEQUENCE_T> const & rhs)
    : sequence_ (rhs.sequence_),
    pos_ (rhs.pos_)
      {
      }
  
  /// Assignment operator
  Const_BBS_Sequence_Iterator & operator= (
                Const_BBS_Sequence_Iterator<SEQUENCE_T> const & rhs)
    {
      Const_BBS_Sequence_Iterator tmp(rhs);
      swap (tmp);
      return * this;
    }

  /// swaps all members  
  void swap(Const_BBS_Sequence_Iterator<SEQUENCE_T> & rhs) 
    throw()
    {
      std::swap (sequence_, rhs.sequence_);
      std::swap (this->pos_, rhs.pos_);
    }

  /// Dereference operator returns a reference to the item contained
  /// at the current position
  const_element_type operator* (void) const
    {
      // Access the underlying element in the sequence.
      return const_element_type ((*(this->sequence_))[this->pos_],
                                 this->sequence_->release ());
    }

  /// Preincrement operator
  const Const_BBS_Sequence_Iterator<SEQUENCE_T> &operator++ (void) const
    {
      // Increment the position.
      ++this->pos_;
      return * this;
    }

  /// Postincrement operator
  Const_BBS_Sequence_Iterator<SEQUENCE_T> operator++ (int) const
    {
      // Create a temporary to return so that it's not modified.
      Const_BBS_Sequence_Iterator<SEQUENCE_T> temp_iter (this->sequence_, this->pos_);
      // Increment the position.
      // We also need to check if we're now past the end.
      ++this->pos_;
      return temp_iter;
    }

  /// Predecrement operator
  const Const_BBS_Sequence_Iterator<SEQUENCE_T> &operator-- (void) const
    {
      --this->pos_;
      return * this;
    }

  /// Postdecrement operator
  Const_BBS_Sequence_Iterator<SEQUENCE_T> operator-- (int) const
    {
      // Create a temporary to return so that it's not modified.
      Const_BBS_Sequence_Iterator<SEQUENCE_T> temp_iter (this->sequence_, this->pos_);
      --this->pos_;
      return temp_iter;
    }

  /// Iterator addition
  const Const_BBS_Sequence_Iterator<SEQUENCE_T> &operator+= (difference_type n) const
    {
      // Move ahead n elements.
      this->pos_ += n;
      return * this;
    }

  /// Iterator addition
  Const_BBS_Sequence_Iterator<SEQUENCE_T> operator+ (difference_type n) const
    {
      // Create a temporary to return and move it ahead n elements.
      return Const_BBS_Sequence_Iterator<SEQUENCE_T> (this->sequence_, this->pos_ + n);
    }

  /// Iterator subtraction
  const Const_BBS_Sequence_Iterator<SEQUENCE_T> &operator-= (difference_type n) const
    {
      // Move back n elements.
      this->pos_ -= n;
      return * this;
    }

  /// Iterator subtraction
  Const_BBS_Sequence_Iterator<SEQUENCE_T> operator- (difference_type n) const
    {
      // Create a temporary to return and move it back n elements.
      return Const_BBS_Sequence_Iterator<SEQUENCE_T> (this->sequence_, this->pos_ - n);
    }

  /// Difference
  difference_type operator- (const Const_BBS_Sequence_Iterator<SEQUENCE_T> & rhs) const
    {
      // I think the order is important here (i.e., this before rhs).
      return this->pos_ - rhs.pos_;
    }

  /// Element operator
  const_element_type operator[] (difference_type n) const
    {
      // Return the element at position pos_ + n
      return const_element_type ((*(this->sequence_))[this->pos_ + n],
                                 this->sequence_->release ());
    }

  /// Less than
  virtual bool operator< (const Const_BBS_Sequence_Iterator<SEQUENCE_T> & rhs) const
    {
      // Return if this iterator is less than the passed in iterator.
      return this->pos_ < rhs.pos_;
    }

  /// Equality operator
  bool operator== (const Const_BBS_Sequence_Iterator<SEQUENCE_T> &rhs) const
  {
    // Compare all the data members for equality.
    return this->sequence_ == rhs.sequence_
        && this->pos_ == rhs.pos_;
  }

  /// Nonequality operator
  bool operator!= (const Const_BBS_Sequence_Iterator<SEQUENCE_T> &rhs) const
  {
    return !(*this == rhs);
  }

private:
  /// the sequence with which we are dealing
  const implementation_type *sequence_;

  /// Our current position in the sequence.
  mutable difference_type pos_;
};

/// Iterator addition with the difference_type being the first argument.
template<typename SEQUENCE_T>
 Const_BBS_Sequence_Iterator<SEQUENCE_T> operator+
   (typename BBS_Sequence_Iterator<SEQUENCE_T>::difference_type n,
    Const_BBS_Sequence_Iterator<SEQUENCE_T> iter)
   {
     // Create an iter and move it ahead n elements.
     return Const_BBS_Sequence_Iterator<SEQUENCE_T> (iter.sequence_, iter.pos_ + n);
   }

/// Iterator subtraction with the difference_type being the first argument.
template<typename SEQUENCE_T>
 Const_BBS_Sequence_Iterator<SEQUENCE_T> operator-
   (typename BBS_Sequence_Iterator<SEQUENCE_T>::difference_type n,
    Const_BBS_Sequence_Iterator<SEQUENCE_T> iter)
   {
     // Create an iter and move it back n elements.
     return Const_BBS_Sequence_Iterator<SEQUENCE_T> (iter.sequence_, iter.pos_ - n);
   }


/**
 * @class BBS_Sequence_Reverse_Iterator
 * @brief Implements a random access iterator for generic sequence type classes.
 */
template <typename SEQUENCE_T>
class BBS_Sequence_Reverse_Iterator 
{
  friend class Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T>;

public:
  // = Necessary traits
  typedef std::random_access_iterator_tag iterator_category;
  typedef typename SEQUENCE_T::value_type value_type;
  typedef typename SEQUENCE_T::value_type *pointer;
  typedef typename SEQUENCE_T::value_type &reference;
  typedef typename SEQUENCE_T::element_type element_type;
  typedef typename SEQUENCE_T::const_element_type const_element_type;
  typedef typename SEQUENCE_T::allocation_traits allocation_traits;
  typedef typename SEQUENCE_T::element_traits element_traits;
  typedef typename SEQUENCE_T::implementation_type implementation_type;
  typedef int difference_type;

  /// Construct a BBS_Sequence_Reverse_Iterator at position pos
  BBS_Sequence_Reverse_Iterator (implementation_type *sequence, 
                                 size_t pos)
    : sequence_ (sequence),
    pos_ (pos)
      {
      }

  /// Copy constructor
  BBS_Sequence_Reverse_Iterator (
	BBS_Sequence_Reverse_Iterator<SEQUENCE_T> const & rhs)
    : sequence_ (rhs.sequence_),
    pos_ (rhs.pos_)
      {
      }
  
  /// Assignment operator
  BBS_Sequence_Reverse_Iterator & operator= (
	BBS_Sequence_Reverse_Iterator<SEQUENCE_T> const & rhs)
    {
      BBS_Sequence_Reverse_Iterator tmp(rhs);
      swap (tmp);
      return * this;
    }

  /// swaps all members
  void swap(BBS_Sequence_Reverse_Iterator<SEQUENCE_T> & rhs) 
    throw()
    {
      std::swap (sequence_, rhs.sequence_);
      std::swap (this->pos_, rhs.pos_);
    }

  /// Dereference operator returns a reference to the item contained
  /// at the current position
  element_type operator* (void)
    {
      // Access the underlying element in the sequence.
      return element_type ((*(this->sequence_))[this->pos_],
                           this->sequence_->release ());
    }

  /// Returns a const reference to the item contained at the current position
  const_element_type operator* (void) const
    {
      // Access the underlying element in the sequence.
      return const_element_type ((*(this->sequence_))[this->pos_],
                                 this->sequence_->release ());
    }

  /// Preincrement operator
  BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &operator++ (void)
    {
      // Decrement the position for reverse iterators.
      // We also need to check if we're now before the start.
      --this->pos_;
      return *this;
    }

  /// Postincrement operator
  BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator++ (int)
    {
      // Create a temporary to return so that it's not modified.
      BBS_Sequence_Reverse_Iterator<SEQUENCE_T> temp_iter (this->sequence_, this->pos_);
      // Decrement the position for reverse iterators.
      // We also need to check if we're now past the end.
      --this->pos_;
      return temp_iter;
    }

  /// Predecrement operator
  BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &operator-- (void)
    {
      // Increment the position for reverse iterators.
      ++this->pos_;
      return *this;
    }

  /// Postdecrement operator
  BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator-- (int)
    {
      // Create a temporary to return so that it's not modified.
      BBS_Sequence_Reverse_Iterator<SEQUENCE_T> temp_iter (this->sequence_, this->pos_);
      // Increment the position for reverse iterators.
      ++this->pos_;
      return temp_iter;
    }

  /// Iterator addition
  BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &operator+= (difference_type n)
    {
      // Move back n elements for reverse iterators.
      this->pos_ -= n;
      return *this;
    }

  /// Iterator addition
  BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator+ (difference_type n)
    {
      // Create a temporary to return and move it back n elements for
      // reverse iterators.
      return BBS_Sequence_Reverse_Iterator<SEQUENCE_T> (this->sequence_, this->pos_ - n);
    }

  /// Iterator subtraction
  BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &operator-= (difference_type n)
    {
      // Move ahead n elements for reverse iterators.
      this->pos_ += n;
      return *this;
    }

  /// Iterator subtraction
  BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator- (difference_type n)
    {
      // Create a temporary to return and move it ahead n elements for
      // reverse iterators.
      return BBS_Sequence_Reverse_Iterator<SEQUENCE_T> (this->sequence_, this->pos_ + n);
    }

  /// Difference
  difference_type operator- (const BBS_Sequence_Reverse_Iterator<SEQUENCE_T> & rhs)
    {
      // I think order is important here (i.e., rhs before this).
      return rhs.pos_ - this->pos_;
    }

  /// Difference
  difference_type operator- (const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> & rhs)
    {
      // I think order is important here (i.e., rhs before this).
      return rhs.pos_ - this->pos_;
    }

  /// Element operator/assignment
  element_type operator[] (difference_type n)
    {
      // Return the element at position pos_ + n
      return element_type ((*(this->sequence_))[this->pos_ + n],
                           this->sequence_->release ());
    }

  /// Element operator/assignment
  const_element_type operator[] (difference_type n) const
    {
      // Return the element at position pos_ + n
      return const_element_type ((*(this->sequence_))[this->pos_ + n],
                                 this->sequence_->release ());
    }

  /// Less than
  bool operator< (const BBS_Sequence_Reverse_Iterator<SEQUENCE_T> & rhs)
    {
      // Return if this iterator is less than the passed in iterator.
      // For reverse iterators reverse the logic.
      return this->pos_ > rhs.pos_;
    }

  /// Less than
  bool operator< (const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> & rhs)
    {
      // Return if this iterator is less than the passed in iterator.
      // For reverse iterators reverse the logic.
      return this->pos_ > rhs.pos_;
    }


  /// Equality operator
  bool operator== (const BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &rhs) const
  {
    // Compare all the data members for equality.
    return this->sequence_ == rhs.sequence_
           && this->pos_ == rhs.pos_;
  }

  /// Equality operator
  bool operator== (const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &rhs) const
  {
    // Compare all the data members for equality.
    return this->sequence_ == rhs.sequence_
           && this->pos_ == rhs.pos_;
  }

  /// Nonequality operator
  bool operator!= (const BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &rhs) const
  {
    return !(*this == rhs);
  }

  /// Nonequality operator
  bool operator!= (const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &rhs) const
  {
    return !(*this == rhs);
  }

private:
  /// The sequence with which we are dealing
  implementation_type *sequence_;

  /// Our current position in the sequence.
  mutable difference_type pos_;
};

/// Iterator addition with the difference_type being the first argument.
template<typename SEQUENCE_T>
 BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator+
   (typename BBS_Sequence_Reverse_Iterator<SEQUENCE_T>::difference_type n,
    BBS_Sequence_Reverse_Iterator<SEQUENCE_T> iter)
   {
     // Create an iter and move it back n elements for reverse iterators.
     return BBS_Sequence_Reverse_Iterator<SEQUENCE_T> (iter.sequence_, iter.pos_ - n);
   }

/// Iterator subtraction with the difference_type being the first argument.
template<typename SEQUENCE_T>
 BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator-
   (typename BBS_Sequence_Reverse_Iterator<SEQUENCE_T>::difference_type n,
    BBS_Sequence_Reverse_Iterator<SEQUENCE_T> iter)
   {
     // Create an iter and move it ahead n elements for reverse iterators.
     return BBS_Sequence_Reverse_Iterator<SEQUENCE_T> (iter.sequence_, iter.pos_ + n);
   }


/**
 * @class Const_BBS_Sequence_Reverse_Iterator
 * @brief Implements a random access iterator for generic sequence type classes.
 *
 * Note:  Having a const Iterator does not guarantee that the current
 * *position* that it points to will not change, it only guarantees that
 * you cannot change the underlying array!
 */
template <typename SEQUENCE_T>
class Const_BBS_Sequence_Reverse_Iterator 
{
  friend class BBS_Sequence_Reverse_Iterator<SEQUENCE_T>;

public:
  // = Necessary traits
  typedef std::random_access_iterator_tag iterator_category;
  typedef typename SEQUENCE_T::value_type value_type;
  typedef typename SEQUENCE_T::value_type *pointer;
  typedef typename SEQUENCE_T::value_type &reference;
  typedef typename SEQUENCE_T::const_element_type const_element_type;
  typedef typename SEQUENCE_T::allocation_traits allocation_traits;
  typedef typename SEQUENCE_T::element_traits element_traits;
  typedef typename SEQUENCE_T::implementation_type implementation_type;
  typedef int difference_type;

  /// Construct a Const_BBS_Sequence_Reverse_Iterator at position pos
  /// using a const sequence.
  Const_BBS_Sequence_Reverse_Iterator (const implementation_type *sequence, 
                                       size_t pos)
    : sequence_ (sequence),
    pos_ (pos)
      {
      }

  /// Copy constructor
  Const_BBS_Sequence_Reverse_Iterator (
	Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> const & rhs)
    : sequence_ (rhs.sequence_),
    pos_ (rhs.pos_)
      {
      }

  /// Copy constructor
  Const_BBS_Sequence_Reverse_Iterator (
	BBS_Sequence_Reverse_Iterator<SEQUENCE_T> const & rhs)
    : sequence_ (rhs.sequence_),
    pos_ (rhs.pos_)
      {
      }
  
  /// Assignment operator
  Const_BBS_Sequence_Reverse_Iterator & operator= (
	Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> const & rhs)
    {
      Const_BBS_Sequence_Reverse_Iterator tmp(rhs);
      swap (tmp);
      return * this;
    }

  /// swaps all members
  void swap(Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> & rhs) 
    throw()
    {
      std::swap (sequence_, rhs.sequence_);
      std::swap (this->pos_, rhs.pos_);
    }

  /// typecast operator to BBS_Sequence_Reverse_Iterator

  /// Dereference operator returns a reference to the item contained
  /// at the current position
  const_element_type operator* (void) const
    {
      // Access the underlying element in the sequence.
      return const_element_type ((*(this->sequence_))[this->pos_],
                                 this->sequence_->release ());
    }

  /// Preincrement operator
  const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &operator++ (void) const
    {
      // Decrement the position for reveres iterators.
      // We also need to check if we're now before the start.
      --this->pos_;
      return *this;
    }

  /// Postincrement operator
  Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator++ (int) const
    {
      // Create a temporary to return so that it's not modified.
      Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> temp_iter (this->sequence_, this->pos_);
      // Decrement the position for reverse iterators.
      // We also need to check if we're now before the start.
      --this->pos_;
      return temp_iter;
    }

  /// Predecrement operator
  const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &operator-- (void) const
    {
      // Increment the position for reverse iterators.
      ++this->pos_;
      return *this;
    }

  /// Postdecrement operator
  Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator-- (int) const
    {
      // Create a temporary to return so that it's not modified.
      Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> temp_iter (this->sequence_, this->pos_);
      // Increment the position for reverse iterators.
      ++this->pos_;
      return temp_iter;
    }

  /// Iterator addition
  const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &operator+= (difference_type n) const
    {
      // Move back n elements for reverse iterators.
      this->pos_ -= n;
      return *this;
    }

  /// Iterator addition
  Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator+ (difference_type n) const
    {
      // Create a temporary to return and move it back n elements for
      // reverse iterators.
      return Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> (this->sequence_, this->pos_ - n);
    }

  /// Iterator subtraction
  const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &operator-= (difference_type n) const
    {
      // Move ahead n elements for reverse iterators.
      this->pos_ += n;
      return *this;
    }

  /// Iterator subtraction
  Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator- (difference_type n) const
    {
      // Create a temporary to return and move it ahead n elements for
      // reverse iterators.
      return Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> (this->sequence_, this->pos_ + n);
    }

  /// Difference
  difference_type operator- (const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> & rhs) const
    {
      // I think order is important here (i.e., rhs before this).
      return rhs.pos_ - this->pos_;
    }

  /// Element operator/assignment
  const_element_type operator[] (difference_type n) const
    {
      // Return the element at position pos_ + n
      return const_element_type ((*(this->sequence_))[this->pos_ + n],
                                 this->sequence_->release ());
    }

  /// Less than
  bool operator< (const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> & rhs) const
    {
      // Return if this iterator is less than the passed in iterator.
      // For reverse iterators reverse the logic.
      return this->pos_ > rhs.pos_;
    }

  /// Equality operator
  bool operator== (const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &rhs) const
  {
    // Compare all the data members for equality.
    return this->sequence_ == rhs.sequence_
        && this->pos_ == rhs.pos_;
  }

  /// Nonequality operator
  bool operator!= (const Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> &rhs) const
  {
    return !(*this == rhs);
  }

private:
  /// the sequence with which we are dealing
  const implementation_type *sequence_;

  /// Our current position in the sequence.
  mutable difference_type pos_;
};

/// Iterator addition with the difference_type being the first argument.
template<typename SEQUENCE_T>
 Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator+
   (typename Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T>::difference_type n,
    Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> iter)
   {
     // Create an iter and move it back n elements for reverse iterators.
     return Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> (iter.sequence_, iter.pos_ - n);
   }

/// Iterator subtraction with the difference_type being the first argument.
template<typename SEQUENCE_T>
 Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> operator-
   (typename Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T>::difference_type n,
    Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> iter)
   {
     // Create an iter and move it ahead n elements for reverse iterators.
     return Const_BBS_Sequence_Reverse_Iterator<SEQUENCE_T> (iter.sequence_, iter.pos_ + n);
   }

} // namespace TAO

TAO_END_VERSIONED_NAMESPACE_DECL

#endif // guard_bounded_basic_string_sequence_hpp
