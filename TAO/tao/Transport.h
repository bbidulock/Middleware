// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file Transport.h
 *
 *  $Id$
 *
 *  Define the interface for the Transport component in TAO's
 *  pluggable protocol framework.
 *
 *  @author  Fred Kuhns <fredk@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_TRANSPORT_H
#define TAO_TRANSPORT_H
#include "ace/pre.h"

#include "corbafwd.h"
#include "Exception.h"
#include "Transport_Descriptor_Interface.h"
#include "Transport_Cache_Manager.h"
#include "ace/Strategies.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_ORB_Core;
class TAO_Target_Specification;
class TAO_Operation_Details;
class TAO_Transport_Mux_Strategy;
class TAO_Wait_Strategy;
class TAO_Connection_Handler;

class TAO_Queued_Message;

class TAO_Export TAO_Synch_Refcountable : private ACE_Refcountable
{
public:
  virtual ~TAO_Synch_Refcountable (void);

  int increment (void);
  int decrement (void);

  int refcount (void) const;

protected:
  TAO_Synch_Refcountable (int refcount);

  TAO_SYNCH_MUTEX mutex_;
};

/**
 * @class TAO_Transport
 *
 * @brief Generic definitions for the Transport class.
 *
 * The transport object is created in the Service handler
 * constructor and deleted in the Service Handler's destructor!!
 *
 * The main responsability of a Transport object is to encapsulate a
 * connection, and provide a transport independent way to send and
 * receive data.  Since TAO is heavily based on the Reactor for all if
 * not all its I/O the Transport class is usually implemented with a
 * helper Connection Handler that adapts the generic Transport
 * interface to the Reactor types.
 *
 * <H3>The outgoing data path:</H3>
 *
 * One of the responsabilities of the TAO_Transport class is to send
 * out GIOP messages as efficiently as possible.  In most cases
 * messages are put out in FIFO order, the transport object will put
 * out the message using a single system call and return control to
 * the application.  However, for oneways and AMI requests it may be
 * more efficient (or required if the SYNC_NONE policy is in effect)
 * to queue the messages until a large enough data set can be put out.
 * Also, large messages may not be sent out without blocking, and in
 * some applications blocking for I/O is unacceptable.
 *
 * Therefore, the Transport class may need to use a queue to
 * temporarily hold the messages, and, in some configurations, it may
 * need to use the Reactor to concurrently drain such queues.
 *
 * <H4>Out of order messages:</H4> TAO provides explicit policies to
 * send 'urgent' messages.  Such messages may put at the head of the
 * queue. However, they cannot be sent immediately because the
 * transport may already be sending another message in a reactive
 * fashion.
 *
 * Consequently, the Transport must also know if the head of the queue
 * has been partially sent.  In that case new messages can only follow
 * the head. Only once the head is completely sent we can start
 * sending new messages.
 *
 * <H4>Waiting threads:</H4> One or more threads can be blocked
 * waiting for the connection to completely send the message.
 * The thread should return as soon as its message has been sent, so a
 * per-thread condition is required.  This suggest that simply using a
 * ACE_Message_Queue would not be enough:  there is a significant
 * amount of ancillary information, to keep on each message that the
 * Message_Block class does not provide room for.
 *
 * Also some applications may choose, for performance reasons or to
 * avoid complex concurrency scenarios due to nested upcalls, to
 * using blocking I/O
 * block the
 *
 * <H4>Timeouts:</H4> Some or all messages could have a timeout period
 * attached to them.  The timeout source could either be some
 * high-level policy or maybe some strategy to prevent denial of
 * service attacks.  In any case the timeouts are per-message, and
 * later messages could have shorter timeouts.
 * In fact, some kind of scheduling (such as EDF) could be required in
 * a few applications.
 *
 * <H4>Conclusions:</H4> The outgoing data path consist in several
 * components:
 *
 * - A queue of pending messages
 * - A message currently being transmitted
 * - A per-transport 'send strategy' to choose between blocking on
 *   write, blocking on the reactor or blockin on leader/follower.
 * - A per-message 'waiting object'
 * - A per-meessage timeout
 *
 * The Transport object provides a single method to send messages
 * (send_message ()).
 *
 * <H3>The incoming data path:</H3>
 *
 * @todo Document the incoming data path design forces.
 *
 *
 * <B>See Also:</B>
 *
 * http://ace.cs.wustl.edu/cvsweb/ace-latest.cgi/ACE_wrappers/TAO/docs/pluggable_protocols/index.html
 *
 */
class TAO_Export TAO_Transport : private TAO_Synch_Refcountable
{
public:
  /// default creator, requres the tag value be supplied.
  TAO_Transport (CORBA::ULong tag,
                 TAO_ORB_Core *orb_core);

  /// destructor
  virtual ~TAO_Transport (void);

  /// Return the protocol tag.
  /**
   * The OMG assigns unique tags (a 32-bit unsigned number) to each
   * protocol. New protocol tags can be obtained free of charge from
   * the OMG, check the documents in corbafwd.h for more details.
   */
  CORBA::ULong tag (void) const;

  /// Access the ORB that owns this connection.
  TAO_ORB_Core *orb_core (void) const;

  /// Get the TAO_Tranport_Mux_Strategy used by this object.
  /**
   * The role of the TAO_Transport_Mux_Strategy is described in more
   * detail in that class' documentation.  Enough is to say that the
   * class is used to control how many threads can have pending
   * requests over the same connection. Multiplexing multiple threads
   * over the same connection conserves resources and is almost
   * required for AMI, but having only one pending request per
   * connection is more efficient and reduces the possibilities of
   * priority inversions.
   */
  TAO_Transport_Mux_Strategy *tms (void) const;

  /// Return the TAO_Wait_Strategy used by this object.
  /**
   * The role of the TAO_Wait_Strategy is described in more detail in
   * that class' documentation. Enough is to say that the ORB can wait
   * for a reply blocking on read(), using the Reactor to wait for
   * multiple events concurrently or using the Leader/Followers
   * protocol.
   */
  TAO_Wait_Strategy *wait_strategy (void) const;

  /// Callback method to reactively drain the outgoing data queue
  int handle_output (void);

  /**
   * Return the TSS leader follower condition variable used in the
   * Wait Strategy. Muxed Leader Follower implementation returns a
   * valid condition variable, others return 0.
   */
  virtual TAO_SYNCH_CONDITION *leader_follower_condition_variable (void);

  /**
   * Initialising the messaging object. This would be used by the
   * connector side. On the acceptor side the connection handler
   * would take care of the messaging objects.
   */
  virtual int messaging_init (CORBA::Octet major,
                              CORBA::Octet minor) = 0;

  /// Get/Set the bidirectional flag
  virtual int bidirectional_flag (void) const;
  virtual void bidirectional_flag (int flag);

  /// Fill in a handle_set with any associated handler's reactor handle.
  /**
   * Called by the cache when the cache is closing in order to fill
   * in a handle_set in a lock-safe manner.
   * @param handle_set the ACE_Handle_Set into which the transport
   *        should place any handle registered with the reactor 
   */
  void provide_handle (ACE_Handle_Set &handle_set);

  /// @@ Bala: you must document this function!!
  /// @@ Bala: from the implementation in IIOP_Transport it looks more
  //         like it process the list of listening endpoints, or it is
  //         parsing it, but 'tearing'???
  virtual int tear_listen_point_list (TAO_InputCDR &cdr);

  /// Remove all messages from the outgoing queue.
  /**
   * @todo: shouldn't this be automated?
   */
  void dequeue_all (void);

  /// Check if there are messages pending in the queue
  /**
   * @return 1 if the queue is empty
   */
  int queue_is_empty (void);

  /// Register the handler with the reactor.
  /**
   * This method is used by the Wait_On_Reactor strategy. The
   * transport must register its event handler with the ORB's Reactor.
   *
   * @todo: I think this method is pretty much useless, the
   * connections are *always* registered with the Reactor, except in
   * thread-per-connection mode.  In that case putting the connection
   * in the Reactor would produce unpredictable results anyway.
   */
  // @@ lockme
  int register_handler (void);

  /**
   * @name Control connection lifecycle
   *
   * These methods are routed through the TMS object. The TMS
   * strategies implement them correctly.
   */
  //@{

  /// Request has been just sent, but the reply is not received. Idle
  /// the transport now.
  virtual int idle_after_send (void);

  /// Request is sent and the reply is received. Idle the transport
  /// now.
  virtual int idle_after_reply (void);

  /// Call the corresponding connection handler's <close>
  /// method.
  virtual void close_connection (void);

  //@}

  /// Write the complete Message_Block chain to the connection.
  /**
   * This method serializes on handler_lock_, guaranteeing that only
   * thread can execute it on the same instance concurrently.
   *
   * Often the implementation simply forwards the arguments to the
   * underlying ACE_Svc_Handler class. Using the code factored out
   * into ACE.
   *
   * Be careful with protocols that perform non-trivial
   * transformations of the data, such as SSLIOP or protocols that
   * compress the stream.
   *
   * @param mblk contains the data that must be sent.  For each
   * message block in the cont() chain all the data between rd_ptr()
   * and wr_ptr() should be delivered to the remote peer.
   *
   * @param timeout is the maximum time that the application is
   * willing to wait for the data to be sent, useful in platforms that
   * implement timed writes.
   * The timeout value is obtained from the policies set by the
   * application.
   *
   * @param bytes_transferred should return the total number of bytes
   * successfully transferred before the connection blocked.  This is
   * required because in some platforms and/or protocols multiple
   * system calls may be required to send the chain of message
   * blocks.  The first few calls can work successfully, but the final
   * one can fail or signal a flow control situation (via EAGAIN).
   * In this case the ORB expects the function to return -1, errno to
   * be appropriately set and this argument to return the number of
   * bytes already on the OS I/O subsystem.
   *
   * This call can also fail if the transport instance is no longer
   * associated with a connection (e.g., the connection handler closed
   * down).  In that case, it returns -1 and sets errno to
   * <code>ENOENT</code>.
   */
  ssize_t send (iovec *iov, int iovcnt,
                size_t &bytes_transferred,
                const ACE_Time_Value *timeout = 0);

  /// Read len bytes from into buf.
  /**
   * This method serializes on handler_lock_, guaranteeing that only
   * thread can execute it on the same instance concurrently.
   *
   * @param buffer ORB allocated buffer where the data should be
   * @@ The ACE_Time_Value *s is just a place holder for now.  It is
   * not clear this this is the best place to specify this.  The actual
   * timeout values will be kept in the Policies.
   */
  ssize_t recv (char *buffer,
                size_t len,
                const ACE_Time_Value *timeout = 0);


  /// Return the identifier for this transport instance.
  /**
   * If not set, this will return an integer representation of
   * the <code>this</code> pointer for the instance on which
   * it's called.
   */
  int id (void) const;
  /// Set the identifier for this transport instance.
  void id (int id);

protected:
  /** @name Template methods
   *
   * The Transport class uses the Template Method Pattern to implement
   * the protocol specific functionality.
   * Implementors of a pluggable protocol should override the
   * following methods with the semantics documented below.
   */
  //@{

  /// Return the event handler used to receive notifications from the
  /// Reactor.
  /**
   * Normally a concrete TAO_Transport object has-a ACE_Event_Handler
   * member that function as an adapter between the ACE_Reactor
   * framework and the TAO pluggable protocol framework.
   * In all the protocols implemented so far this role is fullfilled
   * by an instance of ACE_Svc_Handler.
   *
   * @todo Since we only use a limited functionality of
   * ACE_Svc_Handler we could probably implement a generic
   * adapter class (TAO_Transport_Event_Handler or something), this
   * will reduce footprint and simplify the process of implementing a
   * pluggable protocol.
   */
  // @@ this is broken once we add the lock b/c it returns the thing
  // we're trying to lock down! (CJC)
  virtual ACE_Event_Handler *event_handler_i (void) = 0;

  /// Write the complete Message_Block chain to the connection.
  /**
   * Often the implementation simply forwards the arguments to the
   * underlying ACE_Svc_Handler class. Using the code factored out
   * into ACE.
   *
   * Be careful with protocols that perform non-trivial
   * transformations of the data, such as SSLIOP or protocols that
   * compress the stream.
   *
   * @param mblk contains the data that must be sent.  For each
   * message block in the cont() chain all the data between rd_ptr()
   * and wr_ptr() should be delivered to the remote peer.
   *
   * @param timeout is the maximum time that the application is
   * willing to wait for the data to be sent, useful in platforms that
   * implement timed writes.
   * The timeout value is obtained from the policies set by the
   * application.
   *
   * @param bytes_transferred should return the total number of bytes
   * successfully transferred before the connection blocked.  This is
   * required because in some platforms and/or protocols multiple
   * system calls may be required to send the chain of message
   * blocks.  The first few calls can work successfully, but the final
   * one can fail or signal a flow control situation (via EAGAIN).
   * In this case the ORB expects the function to return -1, errno to
   * be appropriately set and this argument to return the number of
   * bytes already on the OS I/O subsystem.
   *
   */
  virtual ssize_t send_i (iovec *iov, int iovcnt,
                          size_t &bytes_transferred,
                          const ACE_Time_Value *timeout = 0) = 0;

  // Read len bytes from into buf.
  /**
   * @param buffer ORB allocated buffer where the data should be
   * @@ The ACE_Time_Value *s is just a place holder for now.  It is
   * not clear this this is the best place to specify this.  The actual
   * timeout values will be kept in the Policies.
   */
  virtual ssize_t recv_i (char *buffer,
                          size_t len,
                          const ACE_Time_Value *timeout = 0) = 0;

public:
  /// Fill into <output> the right headers to make a request.
  /**
   * @todo Bala: in the good old days it was decided that the
   * pluggable protocol framework would not raise exceptions.
   */
  // @nolock
  virtual void start_request (TAO_ORB_Core *orb_core,
                              TAO_Target_Specification &spec,
                              TAO_OutputCDR &output,
                              CORBA::Environment &ACE_TRY_ENV =
                              TAO_default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  /// Fill into <output> the right headers to make a locate request.
  /**
   * @todo Bala: in the good old days it was decided that the
   * pluggable protocol framework would not raise exceptions.
   */
  // @@nolock
  virtual void start_locate (TAO_ORB_Core *orb_core,
                             TAO_Target_Specification &spec,
                             TAO_Operation_Details &opdetails,
                             TAO_OutputCDR &output,
                             CORBA::Environment &ACE_TRY_ENV =
                             TAO_default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  /// Prepare the waiting and demuxing strategy to receive a reply for
  /// a new request.
  /**
   * Preparing the ORB to receive the reply only once the request is
   * completely sent opens the system to some subtle race conditions:
   * suppose the ORB is running in a multi-threaded configuration,
   * thread A makes a request while thread B is using the Reactor to
   * process all incoming requests.
   * Thread A could be implemented as follows:
   * 1) send the request
   * 2) setup the ORB to receive the reply
   * 3) wait for the request
   *
   * but in this case thread B may receive the reply between step (1)
   * and (2), and drop it as an invalid or unexpected message.
   * Consequently the correct implementation is:
   * 1) setup the ORB to receive the reply
   * 2) send the request
   * 3) wait for the reply
   *
   * The following method encapsulates this idiom.
   *
   * @todo This is generic code, it should be factored out into the
   * Transport class.
   */
  // @nolock b/c this calls send_or_buffer
  virtual int send_request (TAO_Stub *stub,
                            TAO_ORB_Core *orb_core,
                            TAO_OutputCDR &stream,
                            int is_synchronous,
                            ACE_Time_Value *max_time_wait) = 0;

  /// This is a request for the transport object to write a request
  /// header before it sends out a request
  /**
   * @todo: Bala shouldn't this be <write_request_header> or maybe
   *   <init_request_header>, or <prepare_request_header>? Nothing is
   *   really sent at this point, right?
   *
   * @todo: This looks like generic code too.
   */
  virtual CORBA::Boolean send_request_header (TAO_Operation_Details &opd,
                                              TAO_Target_Specification &spec,
                                              TAO_OutputCDR &msg) = 0;

  /// This method formats the stream and then sends the message on the
  /// transport.
  /**
   * Once the ORB is prepared to receive a reply (see send_request()
   * above), and all the arguments have been marshaled the CDR stream
   * must be 'formatted', i.e. the message_size field in the GIOP
   * header can finally be set to the proper value.
   *
   * @todo Another generic method, move to TAO_Transport.
   */
  // @@ lockme
  virtual int send_message (TAO_OutputCDR &stream,
                            TAO_Stub *stub = 0,
                            int is_synchronous = 1,
                            ACE_Time_Value *max_time_wait = 0) = 0;

  /// Callback to read incoming data
  /**
   * The ACE_Event_Handler adapter invokes this method as part of its
   * handle_input() operation.
   *
   * @todo: the method name is confusing! Calling it handle_input()
   * would probably make things easier to understand and follow!
   *
   * Once a complete message is read the Transport class delegates on
   * the Messaging layer to invoke the right upcall (on the server) or
   * the TAO_Reply_Dispatcher (on the client side).
   *
   * @param max_wait_time In some cases the I/O is synchronous, e.g. a
   * thread-per-connection server or when Wait_On_Read is enabled.  In
   * those cases a maximum read time can be specified.
   *
   * @param block Is deprecated and ignored.
   *
   */
  // @@ lockme
  virtual int read_process_message (ACE_Time_Value *max_wait_time = 0,
                                    int block = 0) = 0;

protected:
  /// Register the handler with the reactor.
  /**
   * This method is used by the Wait_On_Reactor strategy. The
   * transport must register its event handler with the ORB's Reactor.
   *
   * @todo: I think this method is pretty much useless, the
   * connections are *always* registered with the Reactor, except in
   * thread-per-connection mode.  In that case putting the connection
   * in the Reactor would produce unpredictable results anyway.
   */
  // @@ lockme
  virtual int register_handler_i (void) = 0;

  /// Called by <code>connection_handler_closing()</code> to signal
  /// that the protocol-specific transport should dissociate itself
  /// with the protocol-specific connection handler.
  /**
   * Typically, this just sets the pointer to the associated connection
   * handler to zero, although it could also clear out any additional
   * resources associated with the handler association.
   */
  virtual void transition_handler_state_i (void) = 0;

public:
  /// Indicates whether the reactor is used by the protocol for
  /// signalling.
  /**
   * @todo: This method needs to go. This is part of the hack for
   * making SHMIOP work at the last minute for TAO 1.1.13
   */
  virtual int reactor_signalling (void);

  /// Method for the connection handler to signify that it
  /// is being closed and destroyed.
  virtual void connection_handler_closing (void);

  /// Register the associated connection handler with the reactor
  /// for a timer.
  /**
   * At this point, only
   * <code>TAO_Eager_Buffering_Sync_Strategy::timer_check()</code>
   * uses this, and it's unclear whether it needs to stay around.
   * But, it's here because it uses the associated protocol-specific
   * connection handler, and accesses to that must be serialized on
   * the internal lock.
   *
   * @param arg argument passed to the handle_timeout() method of the
   *        event handler
   * @param delay  time interval after which the timer will expire
   * @param interval  time interval after which the timer will be
   *        automatically rescheduled
   * @return -1 on failure, a Reactor timer_id value on success
   *
   * @see ACE_Reactor::schedule_timer()
   * @see TAO_Eager_Buffering_Sync_Strategy::timer_check()
   */
  long register_for_timer_event (const void* arg,
                                 const ACE_Time_Value &delay,
                                 const ACE_Time_Value &interval = ACE_Time_Value::zero);

  // Maintain reference counting with these
  static TAO_Transport* _duplicate (TAO_Transport* transport);
  static void release (TAO_Transport* transport);

  /// recache ourselves in the cache
  int recache_transport (TAO_Transport_Descriptor_Interface* desc);

  /// Set/Get the Cache Map entry
  void cache_map_entry (TAO_Transport_Cache_Manager::HASH_MAP_ENTRY *entry);
  TAO_Transport_Cache_Manager::HASH_MAP_ENTRY *cache_map_entry (void);

  /// Send a message block chain,
  int send_message_block_chain (const ACE_Message_Block *message_block,
                                size_t &bytes_transferred,
                                ACE_Time_Value *max_wait_time = 0);

  /// Sent the contents of <message_block>
  /**
   * @todo This method name sucks, but send_message() was already
   *       taken by other silly methods!
   *
   * @param stub The object reference used for this operation, useful
   *             to obtain the current policies.
   * @param is_synchronous If set this method will block until the
   *             operation is completely written on the wire
   * @param message_block The CDR encapsulation of the GIOP message
   *             that must be sent.  The message may consist of
   *             multiple Message Blocks chained through the cont()
   *             field.
   * @param max_wait_time The maximum time that the operation can
   *             block, used in the implementation of timeouts.
   *
   */
  /// the twoway flag or by the current policies in the stub.
  int send_message_i (TAO_Stub *stub,
                      int is_synchronous,
                      const ACE_Message_Block *message_block,
                      ACE_Time_Value *max_wait_time);

  /// Cache management
  void mark_invalid (void);

  /// Cache management
  int make_idle (void);

  /// Schedule handle_output() callbacks
  int schedule_output (void);

  /// Cancel handle_output() callbacks
  int cancel_output (void);

private:
  /// Send some of the data in the queue.
  /**
   * As the outgoing data is drained this method is invoked to send as
   * much of the current message as possible.
   *
   * Returns 0 if there is more data to send, -1 if there was an error
   * and 1 if the message was completely sent.
   */
  int drain_queue (void);

  /// Implement drain_queue() assuming the lock is held
  int drain_queue_i (void);

  /// Cleanup the queue.
  /**
   * Exactly <byte_count> bytes have been sent, the queue must be
   * cleaned up as potentially several messages have been completely
   * sent out.
   * It leaves on head_ the next message to send out.
   */
  void cleanup_queue (size_t byte_count);

  /// Copy the contents of a message block into a Queued_Message
  /// TAO_Queued_Message *copy_message_block (const ACE_Message_Block *mb);

  /// Check if the buffering constraints have been reached
  int check_buffering_constraints_i (TAO_Stub *stub, int &must_flush);

  /// Send a synchronous message, i.e. block until the message is on
  /// the wire
  int send_synchronous_message_i (TAO_Stub *stub,
                                  const ACE_Message_Block *message_block,
                                  ACE_Time_Value *max_wait_time);

  /// Prohibited
  ACE_UNIMPLEMENTED_FUNC (TAO_Transport (const TAO_Transport&))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const TAO_Transport&))

protected:
  /// IOP protocol tag.
  CORBA::ULong tag_;

  /// Global orbcore resource.
  TAO_ORB_Core *orb_core_;

  /// Our entry in the cache. We dont own this. It is here for our
  /// convinience. We cannot just change things around.
  TAO_Transport_Cache_Manager::HASH_MAP_ENTRY *cache_map_entry_;

  /// Strategy to decide whether multiple requests can be sent over the
  /// same connection or the connection is exclusive for a request.
  TAO_Transport_Mux_Strategy *tms_;

  /// Strategy for waiting for the reply after sending the request.
  TAO_Wait_Strategy *ws_;

#if 0
  /// Queue for buffering transport messages.
  TAO_Transport_Buffering_Queue *buffering_queue_;

  /// Buffering timer id.
  long buffering_timer_id_;

  /// Buffering timeout value.
  ACE_Time_Value buffering_timeout_value_;
#endif /* 0 */

  /// Use to check if bidirectional info has been synchronized with
  /// the peer.
  /**
   * Have we sent any info on bidirectional information or have we
   * received any info regarding making the connection served by this
   * transport bidirectional.
   * The flag is used as follows:
   * + We dont want to send the bidirectional context info more than
   *   once on the connection. Why? Waste of marshalling and
   *   demarshalling time on the client.
   * + On the server side -- once a client that has established the
   *   connection asks the server to use the connection both ways, we
   *   *dont* want the server to go pack service info to the
   *   client. That would be *bad*..
   *   @@ Bala: what would this be *bad*? Exactly what breaks? The
   *          protocol? Some GIOP rules?  Performance?
   *
   * The value of this flag will be 0 if the client sends info and 1
   * if the server receives the info.
   */
  int bidirectional_flag_;

  /// Synchronize access to the outgoing data queue
  TAO_SYNCH_MUTEX queue_mutex_;

  /// Implement the outgoing data queue
  TAO_Queued_Message *head_;
  TAO_Queued_Message *tail_;

  /// Lock that insures that activities that *might* use handler-related
  /// resources (such as a connection handler) get serialized.
  /**
   * This is an <code>ACE_Lock</code> that gets initialized from
   * <code>TAO_ORB_Core::resource_factory()->create_cached_connection_lock ()</code>.
   * This way, one can use a lock appropriate for the type of system, i.e.,
   * a null lock for single-threaded systems, and a real lock for
   * multi-threaded systems.
   */
  ACE_Lock *handler_lock_;

  /// A unique identifier for the transport.
  /**
   * This never *never*
   * changes over the lifespan, so we don't have to worry
   * about locking it.
   *
   * HINT: Protocol-specific transports that use connection handler
   * might choose to set this to the handle for their connection.
   */
  int id_;
};

#if defined (__ACE_INLINE__)
# include "Transport.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_TRANSPORT_H */
