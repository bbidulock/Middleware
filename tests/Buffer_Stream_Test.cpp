// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Buffer_Stream_Test.cpp
//
// = DESCRIPTION
//     This program illustrates an implementation of the classic
//     "bounded buffer" program using an ASX STREAM containing two
//     Modules.  Each ACE_Module contains two Tasks.  Each ACE_Task
//     contains a ACE_Message_Queue and a pointer to a
//     ACE_Thread_Manager.  Note how the use of these reusable
//     components reduces the reliance on global variables.
//
// = AUTHOR
//    Prashant Jain and Doug Schmidt
//
// ============================================================================

#include "test_config.h"
#include "ace/Synch.h"
#include "ace/Stream.h"
#include "ace/Module.h"
#include "ace/Task.h"

#if defined (ACE_HAS_THREADS)

typedef ACE_Stream<ACE_MT_SYNCH> MT_Stream;
typedef ACE_Module<ACE_MT_SYNCH> MT_Module;
typedef ACE_Task<ACE_MT_SYNCH> MT_Task;

class Common_Task : public MT_Task
  // = TITLE
  //   Methods that are common to the Supplier and consumer.
{
public:
  Common_Task (void) {}

  // = ACE_Task hooks.
  virtual int open (void * = 0);
  virtual int close (u_long = 0);
};

class Supplier : public Common_Task
// = TITLE
// Define the Supplier interface.
{
public:
  Supplier (void) {}

  virtual int svc (void);
  // Read data from stdin and pass to consumer.
};

class Consumer : public Common_Task
  // = TITLE
  //    Define the Consumer interface.
{
public:
  Consumer (void) {}

  virtual int put (ACE_Message_Block *mb, ACE_Time_Value *tv = 0);
  // Enqueue the message on the ACE_Message_Queue for subsequent
  // handling in the svc() method.

  virtual int svc (void);
  // Receive message from Supplier and print to stdout.
private:

  ACE_Time_Value timeout_;
  // Amount of time to wait for a timeout.
};

// Spawn off a new thread.

int
Common_Task::open (void *)
{
  if (this->activate (THR_NEW_LWP | THR_DETACHED) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "spawn"), -1);
  return 0;
}

int
Common_Task::close (u_long exit_status)
{
  ACE_DEBUG ((LM_DEBUG,
	      "(%t) thread is exiting with status %d in module %s\n",
	     exit_status,
	      this->name ()));

  // Can do anything here that is required when a thread exits, e.g.,
  // storing thread-specific information in some other storage
  // location, etc.
  return 0;
}

// The Supplier reads data from the stdin stream, creates a message,
// and then queues the message in the message list, where it is
// removed by the consumer thread.  A 0-sized message is enqueued when
// there is no more data to read.  The consumer uses this as a flag to
// know when to exit.

int
Supplier::svc (void)
{
  ACE_Message_Block *mb;

  // Send one message for each letter of the alphabet, then send an empty
  // message to mark the end.
  for (char *c = ACE_ALPHABET; *c != '\0'; c++)
    {
      // Allocate a new message.
      char d[2];
      d[0] = *c;
      d[1] = '\0';

      ACE_NEW_RETURN (mb, ACE_Message_Block (2), -1);
      ACE_OS::strcpy (mb->rd_ptr (), d);

      mb->wr_ptr (2);

      if (this->put_next (mb) == -1)
	ACE_ERROR ((LM_ERROR, "(%t) %p\n", "put_next"));
    }

  ACE_NEW_RETURN(mb, ACE_Message_Block, -1);
  if (this->put_next (mb) == -1)
    ACE_ERROR ((LM_ERROR, "(%t) %p\n", "put_next"));

  return 0;
}

int
Consumer::put (ACE_Message_Block *mb, ACE_Time_Value *tv)
{
  // Simply enqueue the Message_Block into the end of the queue.
  return this->putq (mb, tv);
}

// The consumer dequeues a message from the ACE_Message_Queue, writes
// the message to the stderr stream, and deletes the message.  The
// Consumer sends a 0-sized message to inform the consumer to stop
// reading and exit.

int
Consumer::svc (void)
{
  ACE_Message_Block *mb = 0;
  int result = 0;
  char *c = ACE_ALPHABET;
  char *output;

  // Keep looping, reading a message out of the queue, until we
  // timeout or get a message with a length == 0, which signals us to
  // quit.

  for (;;)
    {
      this->timeout_.sec (ACE_OS::time (0) + 4); // Wait for upto 4 seconds

      result = this->getq (mb, &this->timeout_);

      if (result == -1)
	break;

      int length = mb->length ();

      if (length > 0)
	{
	  output = mb->rd_ptr ();
	  ACE_ASSERT (*c == output[0]);
	  c++;
	}
      mb->release ();

      if (length == 0)
	break;
    }

  ACE_ASSERT (result == 0 || errno == EWOULDBLOCK);
  return 0;
}

#endif /* ACE_HAS_THREADS */

// Main driver function.

int
main (int, char *[])
{
  ACE_START_TEST ("Buffer_Stream_Test");

#if defined (ACE_HAS_THREADS)
  // Control hierachically-related active objects.
  MT_Stream stream;
  MT_Module *cm;
  MT_Module *sm;

  // Allocate the Consumer and Supplier modules.
  ACE_NEW_RETURN (cm, MT_Module ("Consumer", new Consumer), -1);
  ACE_NEW_RETURN (sm, MT_Module ("Supplier", new Supplier), -1);

  // Create Supplier and Consumer Modules and push them onto the
  // Stream.  All processing is performed in the Stream.

  if (stream.push (cm) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "push"), 1);
  else if (stream.push (sm) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "push"), 1);

  // Barrier synchronization: wait for the threads to exit, then exit
  // ourselves.
  ACE_Thread_Manager::instance ()->wait ();
#else
  ACE_ERROR ((LM_ERROR, "threads not supported on this platform\n"));
#endif /* ACE_HAS_THREADS */
  ACE_END_TEST;
  return 0;
}
