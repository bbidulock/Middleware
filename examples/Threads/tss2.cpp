// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
// 
// = FILENAME
//    TSS_Test.cpp
//
// = DESCRIPTION
//     This program tests various features of ACE_Thread and thread
//     specific storage of data. 
//
// = AUTHOR
//    Prashant Jain and Doug Schmidt
// 
// ============================================================================

#include "ace/Task.h"
#include "ace/Token.h"

#if defined (ACE_HAS_THREADS)

const int MAX_TASKS = 4;
const int MAX_ITERATIONS = 10;

class TSS_Obj
  // = TITLE
  //     This object is stored in thread-specific storage.
{
public:
  TSS_Obj (void);
  ~TSS_Obj (void);

private:
  static ACE_Atomic_Op<ACE_Thread_Mutex, int> count_;
};

ACE_Atomic_Op<ACE_Thread_Mutex, int> TSS_Obj::count_ = 0;

TSS_Obj::TSS_Obj (void)
{
  TSS_Obj::count_++;
  ACE_DEBUG ((LM_DEBUG, "(%t) TSS_Obj+: %d\n", (int) TSS_Obj::count_));
}

TSS_Obj::~TSS_Obj (void)
{
  TSS_Obj::count_--;
  ACE_DEBUG ((LM_DEBUG, "(%t) TSS_Obj-: %d\n", (int) TSS_Obj::count_));
}

class Test_Task
{
public:

  Test_Task (void);
  ~Test_Task (void);

  int open (void *arg);

  static void *svc (void *arg);

  static ACE_Atomic_Op<ACE_Token, int> wait_count_;
  static ACE_Atomic_Op<ACE_Token, int> max_count_;

private:
  static ACE_Atomic_Op<ACE_Token, int> count_;
};

ACE_Atomic_Op<ACE_Token, int> Test_Task::count_ (0);
ACE_Atomic_Op<ACE_Token, int> Test_Task::wait_count_ (0);
ACE_Atomic_Op<ACE_Token, int> Test_Task::max_count_ (0);
int num_tasks = 0;

// ACE synchronization object.
static ACE_Token token;

Test_Task::Test_Task (void)
{
  Test_Task::count_++;
  ACE_DEBUG ((LM_DEBUG, 
	      "(%t) Test_Task+: %d\n", (int) Test_Task::count_));
}

Test_Task::~Test_Task (void)
{
  Test_Task::count_--;

  ACE_DEBUG ((LM_DEBUG, 
	      "(%t) Test_Task-: %d\n", (int) Test_Task::count_));
  Test_Task::wait_count_--;
}

void *
Test_Task::svc (void *arg)
{
  // When the thread exits this thread-specific object will be deleted
  // automatically.
  ACE_TSS<TSS_Obj> tss (new TSS_Obj);

  Test_Task::wait_count_++;
  Test_Task::max_count_++;

  ACE_DEBUG ((LM_DEBUG, "(%t) svc: waiting\n"));

  while (1)
    {   
      if (Test_Task::max_count_ >= num_tasks)
	break;
      else
	ACE_Thread::yield ();
    }

  ACE_DEBUG ((LM_DEBUG, "(%t) svc: waiting finished\n"));

  delete (Test_Task *) arg;

  return 0;
}

int 
Test_Task::open (void *arg)
{
  if (ACE_Thread::spawn (Test_Task::svc, arg) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "ACE_Thread::spawn"), 0);

  return 0;
}

int 
main (int argc, char *argv[])
{
  num_tasks = argc > 1 ? atoi (argv[1]) : MAX_TASKS;

  Test_Task **task_arr;
  
  ACE_NEW_RETURN (task_arr, Test_Task *[num_tasks], -1);

  for (int i = 0; i < MAX_ITERATIONS; i++)
    {
      ACE_DEBUG ((LM_DEBUG, 
		  "(%t) ********* iteration %d **********\n"
		  "Test_Task::max_count_ %d\n",
		  i,
		  (int) Test_Task::max_count_));
      Test_Task::max_count_ = 0;

      for (int j = 0; j < num_tasks; j++)
	{
          ACE_NEW_RETURN (task_arr[j], Test_Task, -1);
	  task_arr[j]->open (task_arr[j]);
	}

      ACE_DEBUG ((LM_DEBUG, "(%t) waiting for first thread started\n"));

      for (;;)
	{
	  ACE_Thread::yield ();

	  if (Test_Task::max_count_ != 0 )
	    break;
	}

      ACE_DEBUG ((LM_DEBUG, "(%t) First thread started\n"
		  "Waiting for all threads finished\n"));

      for (;;)
	{
	  if (!(Test_Task::max_count_ == num_tasks 
		&& Test_Task::wait_count_ == 0))
	    {
	      ACE_Thread::yield ();
	      continue;
	    }
	  ACE_DEBUG ((LM_DEBUG, 
		      "(%t) Test_Task::max_count_ = %d,"
		      " Test_Task::wait_count_ = %d",
		      (int) Test_Task::max_count_,
		      (int) Test_Task::wait_count_)); 
	  break;
	}

      ACE_DEBUG ((LM_DEBUG, "(%t) all threads finished\n"));
    }

  return 0;
}

#else
int 
main (int, char *[])
{
  ACE_ERROR ((LM_ERROR, "threads not supported on this platform\n"));
  return 0;
}
#endif /* ACE_HAS_THREADS */

#if defined (ACE_TEMPLATES_REQUIRE_SPECIALIZATION)
template class ACE_Atomic_Op<ACE_Token, int>;
#endif /* ACE_TEMPLATES_REQUIRE_SPECIALIZATION */
