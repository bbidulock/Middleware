/*************************************************
 *
 * = PACKAGE
 *    JACE.Concurrency
 *
 * = FILENAME
 *    Semaphore.java
 *
 *@author Prashant Jain
 *
 *************************************************/
package JACE.Concurrency;

import java.util.*;
import JACE.ASX.*;

class TimedWaitSAdapter extends JACE.ASX.TimedWait
{
  TimedWaitSAdapter (Object obj)
  {
    super (obj);
  }

  // Check to see if there are any semaphores available.
  public boolean condition ()
  {
    return this.count_ > 0;
  }

  // Increment the count by one
  public void increment ()
  {
    this.count_++;
  }

  // Decrement the count by one
  public void decrement ()
  {
    this.count_--;
  }

  // Set the count
  public void count (int c)
  {
    this.count_ = c;
  }

  private int count_ = 0;
}

/**
 * <hr>
 * <h2>SYNOPSIS</h2>
 *     Implementation of Dijkstra's counting semaphore in java.
 */
public class Semaphore
{  
  /**
   * Create a Semaphore.
   *@param count semaphore count
   */
  public Semaphore (int c)
    {
      this.monitor_.count (c);
    }

  /**
   * Acquire the Semaphore. Note that this will block.
   *@exception InterruptedException exception during wait
   */
  public synchronized void acquire () throws InterruptedException
    {
      this.monitor_.timedWait ();
      this.monitor_.decrement ();
    }

  /**
   * Acquire the Semaphore.  Throws a TimeoutException if the semaphore
   * isn't acquired before the given absolute time.
   *@param tv time (TimeValue) to wait until before throwing a
   * TimeoutException (unless the semaphore is acquired before that)
   *@exception TimeoutException wait timed out exception
   *@exception InterruptedException exception during wait
   */
  public synchronized void acquire (TimeValue tv)
      throws JACE.ASX.TimeoutException, InterruptedException 
    {
      this.monitor_.timedWait (tv);
      this.monitor_.decrement ();
    }

  /**
   * Release the Semaphore.
   */
  public synchronized void release ()
    {
      this.monitor_.increment ();
      this.monitor_.signal ();
    }

  private TimedWaitSAdapter monitor_ = new TimedWaitSAdapter (this);
  // The monitor (adapter) to wait on
}
