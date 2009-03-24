/**
 * @file
 *
 * @brief Unit test for bounded sequences of value types (integers,
 *        structures, etc.)
 *
 * $Id$
 *
 * @author Carlos O'Ryan
 */
#include "testing_allocation_traits.hpp"
#include "testing_range_checking.hpp"

#include "tao/Bounded_Value_Sequence_T.h"

#include "value_sequence_tester.hpp"

#include "test_macros.h"


using namespace TAO_VERSIONED_NAMESPACE_NAME::TAO;

CORBA::ULong const MAXIMUM = 32;

typedef bounded_value_sequence<int,MAXIMUM> tested_sequence;
typedef tested_sequence::element_traits tested_element_traits;
typedef tested_sequence::allocation_traits tested_allocation_traits;
typedef details::range_checking<int,true> range;

struct Tester
{
  typedef tested_sequence::value_type value_type;

  int test_set_length_less_than_maximum()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    {
      tested_sequence x;

      x.length(8);
      CHECK_EQUAL(CORBA::ULong(MAXIMUM), x.maximum());
      CHECK_EQUAL(CORBA::ULong(8), x.length());
      CHECK_EQUAL(true, x.release());
    }
    FAIL_RETURN_IF_NOT(a.expect(0), a);
    FAIL_RETURN_IF_NOT(f.expect(1), f);
    return 0;
  }

  int test_set_length_more_than_maximum()
  {
    tested_sequence x;

    CHECK_THROW(x.length(64), std::runtime_error);
    return 0;
  }

  value_type * alloc_and_init_buffer()
  {
    value_type * buf = tested_sequence::allocbuf();
    buf[0] = 1; buf[1] = 4; buf[2] = 9; buf[3] = 16;

    return buf;
  }

  int test_regression_2201 ()
  {
    value_type * buffer = alloc_and_init_buffer();

    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    {
      tested_sequence a(32, buffer);
      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(32), a.length());
      CHECK_EQUAL(buffer, a.get_buffer());
      CHECK_EQUAL(int( 1), a[0]);
      CHECK_EQUAL(int( 4), a[1]);
      CHECK_EQUAL(int( 9), a[2]);
      CHECK_EQUAL(int(16), a[3]);
      CHECK_EQUAL(false, a.release());
      a.length (3);
      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(3), a.length());
      a.length (4);
      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(4), a.length());
      CHECK_EQUAL(int( 0), a[3]);
    }
    FAIL_RETURN_IF_NOT(a.expect(0), a);
    FAIL_RETURN_IF_NOT(f.expect(0), f);
    tested_sequence::freebuf(buffer);
    return 0;
  }

  int test_buffer_constructor_default()
  {
    value_type * buffer = alloc_and_init_buffer();

    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    {
      tested_sequence a(4, buffer);
      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(4), a.length());
      CHECK_EQUAL(buffer, a.get_buffer());
      CHECK_EQUAL(int( 1), a[0]);
      CHECK_EQUAL(int( 4), a[1]);
      CHECK_EQUAL(int( 9), a[2]);
      CHECK_EQUAL(int(16), a[3]);
      CHECK_EQUAL(false, a.release());
    }
    FAIL_RETURN_IF_NOT(a.expect(0), a);
    FAIL_RETURN_IF_NOT(f.expect(0), f);
    tested_sequence::freebuf(buffer);
    return 0;
  }

  int test_buffer_constructor_false()
  {
    value_type * buffer = alloc_and_init_buffer();
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    {
      tested_sequence a(4, buffer, false);
      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(4), a.length());
      CHECK_EQUAL(buffer, a.get_buffer());
      CHECK_EQUAL(int( 1), a[0]);
      CHECK_EQUAL(int( 4), a[1]);
      CHECK_EQUAL(int( 9), a[2]);
      CHECK_EQUAL(int(16), a[3]);
      CHECK_EQUAL(false, a.release());
    }
    FAIL_RETURN_IF_NOT(a.expect(0), a);
    FAIL_RETURN_IF_NOT(f.expect(0), f);
    tested_sequence::freebuf(buffer);
    return 0;
  }

  int test_buffer_constructor_true()
  {
    value_type * buffer = alloc_and_init_buffer();
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    {
      tested_sequence a(4, buffer, true);
      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(4), a.length());
      CHECK_EQUAL(buffer, a.get_buffer());
      CHECK_EQUAL(int( 1), a[0]);
      CHECK_EQUAL(int( 4), a[1]);
      CHECK_EQUAL(int( 9), a[2]);
      CHECK_EQUAL(int(16), a[3]);
      CHECK_EQUAL(true, a.release());
    }
    FAIL_RETURN_IF_NOT(a.expect(0), a);
    FAIL_RETURN_IF_NOT(f.expect(1), f);
    return 0;
  }

  int test_replace_default()
  {
    value_type * buffer = alloc_and_init_buffer();

    expected_calls c(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    {
      tested_sequence a;
      a.replace(4, buffer);
      FAIL_RETURN_IF_NOT(c.expect(0), c);
      FAIL_RETURN_IF_NOT(f.expect(1), f);

      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(4), a.length());
      CHECK_EQUAL(buffer, a.get_buffer());
      CHECK_EQUAL(int( 1), a[0]);
      CHECK_EQUAL(int( 4), a[1]);
      CHECK_EQUAL(int( 9), a[2]);
      CHECK_EQUAL(int(16), a[3]);
      CHECK_EQUAL(false, a.release());
    }
    FAIL_RETURN_IF_NOT(c.expect(0), c);
    FAIL_RETURN_IF_NOT(f.expect(0), f);
    tested_sequence::freebuf(buffer);
    return 0;
  }

  int test_replace_false()
  {
    value_type * buffer = alloc_and_init_buffer();
    expected_calls c(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);

    {
      tested_sequence a;
      a.replace(4, buffer, false);
      FAIL_RETURN_IF_NOT(c.expect(0), c);
      FAIL_RETURN_IF_NOT(f.expect(1), f);

      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(4), a.length());
      CHECK_EQUAL(buffer, a.get_buffer());
      CHECK_EQUAL(int( 1), a[0]);
      CHECK_EQUAL(int( 4), a[1]);
      CHECK_EQUAL(int( 9), a[2]);
      CHECK_EQUAL(int(16), a[3]);
      CHECK_EQUAL(false, a.release());
    }
    FAIL_RETURN_IF_NOT(c.expect(0), c);
    FAIL_RETURN_IF_NOT(f.expect(0), f);
    tested_sequence::freebuf(buffer);
    return 0;
  }

  int test_replace_true()
  {
    value_type * buffer = alloc_and_init_buffer();
    expected_calls c(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);

    {
      tested_sequence a;
      a.replace(4, buffer, true);
      FAIL_RETURN_IF_NOT(c.expect(0), c);
      FAIL_RETURN_IF_NOT(f.expect(1), f);

      CHECK_EQUAL(CORBA::ULong(32), a.maximum());
      CHECK_EQUAL(CORBA::ULong(4), a.length());
      CHECK_EQUAL(buffer, a.get_buffer());
      CHECK_EQUAL(int( 1), a[0]);
      CHECK_EQUAL(int( 4), a[1]);
      CHECK_EQUAL(int( 9), a[2]);
      CHECK_EQUAL(int(16), a[3]);
      CHECK_EQUAL(true, a.release());
    }
    FAIL_RETURN_IF_NOT(c.expect(0), c);
    FAIL_RETURN_IF_NOT(f.expect(1), f);
    return 0;
  }

  int test_get_buffer_default()
  {
    value_type * buffer = alloc_and_init_buffer();
    tested_sequence a(4, buffer, true);
    CHECK_EQUAL(a.get_buffer(), buffer);
    return 0;
  }

  int test_get_buffer_false()
  {
    value_type * buffer = alloc_and_init_buffer();
    tested_sequence a(4, buffer, true);
    CHECK_EQUAL(a.get_buffer(), buffer);
    return 0;
  }

  int test_get_buffer_true_with_release_false()
  {
    value_type * buffer = alloc_and_init_buffer();
    tested_sequence a(4, buffer, false);
    CHECK(0 == a.get_buffer(true));
    tested_sequence::freebuf(buffer);
    return 0;
  }

  int test_get_buffer_true_with_release_true()
  {
    value_type * buffer = alloc_and_init_buffer();
    expected_calls c(tested_allocation_traits::default_buffer_allocation_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    {
      tested_sequence a(4, buffer, true);
      CHECK_EQUAL(buffer, a.get_buffer(true));

      tested_sequence const & b = a;
      CHECK_EQUAL(MAXIMUM, b.maximum());
      CHECK_EQUAL(0UL, b.length());
      CHECK(0 != b.get_buffer());
      CHECK_EQUAL(true, b.release());

      FAIL_RETURN_IF_NOT(c.expect(1), c);

      CHECK(buffer != b.get_buffer());
    }
    FAIL_RETURN_IF_NOT(c.expect(0), c);
    FAIL_RETURN_IF_NOT(f.expect(1), c);
    tested_sequence::freebuf(buffer);
    return 0;
  }

  int test_all()
  {
    int status = 0;
    status += this->test_set_length_less_than_maximum();
    status += this->test_set_length_more_than_maximum();
    status += this->test_regression_2201();
    status += this->test_buffer_constructor_default();
    status += this->test_buffer_constructor_false();
    status += this->test_buffer_constructor_true();
    status += this->test_replace_default();
    status += this->test_replace_false();
    status += this->test_replace_true();
    status += this->test_get_buffer_false();
    status += this->test_get_buffer_true_with_release_false();
    status += this->test_get_buffer_true_with_release_true();
    return status;
  }
  Tester() {}
};

int ACE_TMAIN(int,ACE_TCHAR*[])
{
  int status = 0;
  {
    Tester tester;
    status += tester.test_all ();
  }

  {
    typedef value_sequence_tester<tested_sequence,tested_allocation_traits> common;
    common tester(true);
    status += tester.test_all ();
  }

  return status;
}

