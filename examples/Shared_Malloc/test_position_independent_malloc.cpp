// $Id$

// Test the capability of <ACE_Malloc> to handle a single malloc that
// can be rooted at different base addresses each time it's used.

#include "ace/Malloc.h"
#include "ace/Based_Pointer_T.h"
#include "ace/Get_Opt.h"
#include "ace/Synch.h"
#include "test_position_independent_malloc.h"

ACE_RCSID(Shared_Malloc, test_multiple_mallocs, "$Id$")

typedef ACE_Malloc <ACE_MMAP_MEMORY_POOL, ACE_Process_Mutex> MALLOC;

// Default address for memory-mapped files.
static void *base_addr = ACE_DEFAULT_BASE_ADDR;

static void
print (Test_Data *data)
{
  for (Test_Data *t = data; t != 0; t = t->next_)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "<<<<\ni1_ = %d, i2_ = %d, i3_ = %d\n",
                  t->i1_,
                  t->i2_,
                  t->i3_));
      ACE_DEBUG ((LM_DEBUG,
                  "*t->bpl_ = %d, t->long_test_->array_[0] = %d\n>>>>\n",
                  *t->long_test_->bpl_,
                  t->long_test_->array_[0]));
    }
}

static void *
initialize (MALLOC *allocator)
{
  void *ptr;
  ACE_ALLOCATOR_RETURN (ptr,
                        allocator->malloc (sizeof (Test_Data)),
                        0);
  Test_Data *data1 = new (ptr) Test_Data;

  data1->i1_ = 111;
  data1->i2_ = 222;
  data1->i3_ = 333;

  void *gap = 0;
  ACE_ALLOCATOR_RETURN (gap,
                        allocator->malloc (sizeof (256)),
                        0);

  allocator->free (gap);

  ACE_ALLOCATOR_RETURN (ptr,
                        allocator->malloc (sizeof (Test_Data)),
                        0);
  Test_Data *data2 = new (ptr) Test_Data;

  data1->next_ = 0;
  data1->i1_ = 111;
  data1->i2_ = 222;
  data1->i3_ = 333;
  data2->next_ = data1;
  data2->i1_ = -111;
  data2->i2_ = -222;
  data2->i3_ = -333;

  // Test in shared memory using long (array/pointer)
  ACE_ALLOCATOR_RETURN (ptr,
                        allocator->malloc (sizeof (Long_Test)),
                        0);
  Long_Test *lt = new (ptr) Long_Test;

  lt->array_[0] = 1000;
  lt->array_[1] = 1001;
  lt->array_[2] = 1002;
  lt->array_[3] = 1003;
  lt->array_[4] = 1004;
  lt->bpl_ = lt->array_;

  data1->long_test_= lt;

  long long_cont_1 = *lt->bpl_;
  long long_cont_2 = lt->bpl_[3];

  ACE_ASSERT (long_cont_1 == 1000);
  ACE_ASSERT (long_cont_2 == 1003);

  // Test in local memory using long (array/pointer).
  ACE_ALLOCATOR_RETURN (ptr,
                        allocator->malloc (sizeof (Long_Test)),
                        0);
  lt = new (ptr) Long_Test;

  lt->array_[0] = 2000;
  lt->array_[1] = 2001;
  lt->array_[2] = 2002;
  lt->array_[3] = 2003;
  lt->array_[4] = 2004;
  lt->bpl_ = lt->array_;

  data2->long_test_= lt;

  long long_cont_3 = *lt->bpl_;
  long long_cont_4 = lt->bpl_[4];

  ACE_ASSERT (long_cont_3 == 2000);
  ACE_ASSERT (long_cont_4 == 2004);

  return data2;
}

static void
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opt (argc, argv, "a:T");

  for (int c;
       (c = get_opt ()) != -1;
       )
    {
      switch (c)
        {
        case 'a':
          // Override the default base address.
          base_addr = (void *) ACE_OS::atoi (get_opt.optarg);
          break;
        case 'T':
          ACE_Trace::start_tracing ();
          break;
        }
    }
}

int
main (int argc, char *argv[])
{
  parse_args (argc, argv);

  ACE_MMAP_Memory_Pool_Options options (base_addr);

  // Create an allocator.
  MALLOC *allocator;
  ACE_NEW_RETURN (allocator,
                  MALLOC ("test_file",
                          "test_lock",
                          &options),
                  1);
  void *data = 0;

  // This is the first time in, so we allocate the memory and bind it
  // to the name "foo".
  if (allocator->find ("foo",
                       data) == -1)
    {
      data = initialize (allocator);

      if (allocator->bind ("foo",
                           data) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%p\n",
                           "bind"),
                          1);

      ACE_DEBUG ((LM_DEBUG,
                  "Run again to see results and release resources.\n"));
    }
  // If we find "foo" then we're running the "second" time, so we must
  // release the resources.
  else
    {
      print ((Test_Data *) data);
      allocator->free (data);
      allocator->remove ();
      ACE_DEBUG ((LM_DEBUG,
                  "all resources released\n"));
    }

  delete allocator;

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Based_Pointer<Test_Data>;
template class ACE_Based_Pointer_Basic<Test_Data>;
template class ACE_Based_Pointer_Basic<long>;
template class ACE_Based_Pointer_Basic<Long_Test>;
template class ACE_Based_Pointer<Long_Test>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Based_Pointer<Test_Data>
#pragma instantiate ACE_Based_Pointer_Basic<Test_Data>
#pragma instantiate ACE_Based_Pointer_Basic<long>
#pragma instantiate ACE_Based_Pointer_Basic<Long_Test>
#pragma instantiate ACE_Based_Pointer_Basic<Long>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
