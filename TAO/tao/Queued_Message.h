// -*- C++ -*-

//=============================================================================
/**
 *  @file Queued_Message.h
 *
 *  $Id$
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef TAO_QUEUED_MESSAGE_H
#define TAO_QUEUED_MESSAGE_H
#include "ace/pre.h"

#include "corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ACE_Message_Block;
class TAO_Message_Sent_Callback;

/**
 * @class TAO_Queued_Message
 *
 * @brief Implement an queued message for the outgoing path in the
 *        TAO_Transport class
 *
 * Please read the documentation in the TAO_Transport class to find
 * out more about the design of the outgoing data path.
 *
 * In some configurations TAO needs to maintain a per-connection queue
 * of outgoing messages.  This queue is drained by the pluggable
 * protocols framework, normally under control of the ACE_Reactor, but
 * other configurations are conceivable.  The elements in the queue
 * may may removed early, for example, because the application can
 * specify timeouts for each message, or because the underlying
 * connection is broken.
 *
 * In many cases the message corresponds to some application request,
 * the application may be blocked waiting for the request to be sent,
 * even more importantlyl, the ORB can be configured to use the
 * Leader/Followers strategy, in which case one of the waiting threads
 * can be required to wake up before its message completes
 * each message may contain a 'Sent_Notifier'
 *
 * <H4>NOTE:</H4> The contents of the ACE_Message_Block may have been
 * allocated from TSS storage, in that case we cannot steal them.
 * However, we do not need to perform a deep copy all the time, for
 * example, in a twoway request the sending thread blocks until the
 * data goes out.  The queued message can borrow the memory as it will
 * be deallocated by the sending thread when it finishes.
 * Oneways and asynchronous calls are another story.
 *
 * @todo: Change the ORB to allocate oneway and AMI buffer from global
 *        memory, to avoid the data copy in this path.  What happens
 *        if the there is no queueing?  Can we check that before
 *        allocating the memory?
 *
 */
class TAO_Export TAO_Queued_Message
{
public:
  /// Constructor
  /**
   * @param contents The message block chain that must be sent.
   *
   * @param own_contents If this flag is true then this object assumes
   * ownership of the contents.
   *
   * @param callback A callback interface to signal any waiting
   * threads about the status of the message.  It is null if there are
   * no waiting threads.
   */
  TAO_Queued_Message (ACE_Message_Block *contents,
                      int own_contents,
                      TAO_Message_Sent_Callback *callback = 0);

  /// Destructor
  virtual ~TAO_Queued_Message (void);

  /// Get the message block
  ACE_Message_Block *mb (void) const;

  /// The transport has successfully sent more data, adjust internal
  /// status
  void bytes_transferred (size_t byte_count);

  /// Return 0 if the message has not been completely sent
  int done (void) const;

  /// The underlying connection has been closed, release resources and
  /// signal waiting threads.
  void connection_closed (void);

  /// Reclaim resources
  void destroy (void);

  /** @name Intrusive list manipulation
   *
   * The messages are put in a doubled linked list (for easy insertion
   * and removal).  To minimize memory allocations the list is
   * intrusive, i.e. each element in the list contains the pointers
   * for the next and previous element.
   *
   * The following methods are used to manipulate this implicit list.
   *
   * @todo: We should implement this as a base template, something
   *        like:<BR>
   * template<class T> Intrusive_Node {<BR>
   * public:<BR><BR>
   *   void next (T *);<BR>
   *   T* next () const;<BR><BR>
   * private:<BR>
   *   T* next_;<BR>
   * };<BR>
   * and use it as follows:<BR>
   * class TAO_Queued_Message : public Intrusive_Node<TAO_Queued_Message><BR>
   * {<BR>
   * };<BR>
   *
   */
  //@{
  /// Set/get the next element in the list
  virtual TAO_Queued_Message *next (void) const;

  /// Set/get the previous element in the list
  virtual TAO_Queued_Message *prev (void) const;

  /// Remove this element from the list
  virtual void remove_from_list (TAO_Queued_Message *&head,
                                 TAO_Queued_Message *&tail);

  /// Insert the current element after position.
  /**
   * If position is null then we assume that we are inserting the
   * current element into an empty list.
   */
  virtual void push_back (TAO_Queued_Message *&head,
                          TAO_Queued_Message *&tail);
  //@}

private:
  /// The contents of the message.
  /**
   * The message is normally generated by a TAO_OutputCDR stream.  The
   * application marshals the payload, possibly generating a chain of
   * message block connected via the 'cont()' field.
   */
  ACE_Message_Block *contents_;

  /// If not zero the @c contents_ are owned by this object
  int own_contents_;

  /// If not null, this is the object that we signal to indicate that
  /// the message was sent.
  /**
   * The signaling mechanism used to wakeup the thread waiting for
   * this message to complete changes
   */
  TAO_Message_Sent_Callback *callback_;

  /// Implement an intrusive double-linked list for the message queue
  TAO_Queued_Message *next_;
  TAO_Queued_Message *prev_;
};

#if defined (__ACE_INLINE__)
# include "Queued_Message.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif  /* TAO_QUEUED_MESSAGE_H */
