/*************************************************
 *
 * = PACKAGE
 *    JACE.Concurrency
 *
 * = FILENAME
 *    Condition.java
 *
 *@author Irfan Pyarali
 *
 *************************************************/
package JACE.Concurrency;

import JACE.ASX.TimeoutException;
import JACE.ASX.TimeValue;

/**
 * <hr>
 * <h2>TITLE</h2>
 *<blockquote>
 *     Abstraction for <em>traditional</em> 
 *     condition variable
 *</blockquote>
 *
 * <h2>DESCRIPTION</h2>
 *<blockquote>
 *     This condition variable allows the use of one 
 *     mutex between multiple conditions. 
 *     This implementation is based on the C++ version of ACE.
 *</blockquote>
 */
public class Condition
{
  /** 
   * Default constructor
   *@param Mutex for synchronization
   */
  public Condition (Mutex mutex)
  {
    mutex_ = mutex;
  }
  
  /**
   * Wait for condition to become signaled. 
   *@exception InterruptedException exception during wait
   */
  public void Wait () 
    throws InterruptedException
  {
    waiters_++;

    try
      {
	mutex_.release();
	semaphore_.acquire ();
	mutex_.acquire ();
      }
    finally 
      {
	waiters_--;
      }
  }
  
  /**
   * TimedWait for condition to become signaled.  Note that the
   * given TimeValue is an absolute time, not a relative time.
   *
   *@param tv Absolute time to wait until before timing out
   *@exception TimeoutException wait timed out exception
   *@exception InterruptedException exception during wait
   */
  public void Wait (TimeValue tv) 
      throws TimeoutException, InterruptedException
  {
    waiters_++;

    try
      {
	mutex_.release();

	semaphore_.acquire (tv);

	mutex_.acquire (tv);
      }
    finally 
      {
	waiters_--;
      }
  }
  
  /**
   * Signal condition. Wake one waiter (if any).
   */
  public void signal ()
  {
    if (waiters_ > 0)
      semaphore_.release ();
  }

  /**
   * Signal condition. Wake up all waiters (if any).
   */
  public void broadcast ()
  {
    for (int i = waiters_; i > 0; i--)
      semaphore_.release ();
  }

  /** 
   * Accessor to lock
   *@return Mutex
   */
  public Mutex mutex ()
  {
    return mutex_;
  }

  private int waiters_;  
  private Semaphore semaphore_ = new Semaphore (0);
  private Mutex mutex_;

}
