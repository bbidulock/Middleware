//$Id$
#ifndef ACE_UUID_H
#define ACE_UUID_H

#include "ace/pre.h"
#include "ace/OS.h"
#include "ace/SString.h"
#include "ace/Singleton.h"

//typedef unsigned char Octet;
class ACE_Lock;

/**
 *  @class ACE_UUID
 *
 *	ACE_UUID represebt a Universally Unique IDentifier (UUID)
 * 	as described in (the expired) INTERNET-DRAFT
 *	specification entitled UUIDs and GUIDs. All instances of
 *	UUID are of the time-based variety. That is, the version
 *	number part of the timeHiAndVersion field is 1.
 *
 *	The default constructor creates a nil UUID.
 *
 *	UUIDs have value semantics. In addition, they may be
 *	compared for ordering and equality.
 *
 *	Note: the statement of UUID uniqueness is less stringent
 *	than the requirement for UUID in general. There is no
 *	guarantee that a UUID generated by by this class is
 *	universally unique with respect to another arbitrary
 *	UUID. 
 */
class ACE_Export ACE_UUID 
{
 public:
  
  /**
   * Type to hold a MAC address
   */
  struct UUID_node_t 
  {
    typedef enum {NODE_ID_SIZE = 6};
    typedef u_char NodeID[NODE_ID_SIZE];
    bool operator == (const UUID_node_t& right) const;
    bool operator != (const UUID_node_t& right) const;
    bool operator <  (const UUID_node_t& right) const;
    NodeID nodeID;
  };

  struct UUID_t 
  {
    // Data Members for Class Attributes
    ACE_UINT32  timeLow;
    ACE_UINT16  timeMid;    
    ACE_UINT16  timeHiAndVersion;    
    u_char      clockSeqHiAndReserved;    
    u_char      clockSeqLow;    
    ACE_CString* thr_id;
    ACE_CString* pid;
    UUID_node_t node; 
  };

  ACE_UUID(void);

  /**
   * Copy constructor
   */
  ACE_UUID(const ACE_UUID &right);

  /** 
   * Construct a UUID based on a UUID_t
   */
  ACE_UUID (const UUID_t& newUUID);

  /**	
   * Constructs a UUID from a string representation.
   */
  ACE_UUID (const ACE_SString& uuidString);

  ~ACE_UUID(void);

  /**
   * Assignment Operation
   */
  ACE_UUID & operator=(const ACE_UUID &right);

  /** 
   * Equality Operations 
   */
  bool operator==(const ACE_UUID &right) const;
  bool operator!=(const ACE_UUID &right) const;

  /**
   * Relational Operations 
   */
  bool operator< (const ACE_UUID &right) const;
  bool operator> (const ACE_UUID &right) const;
  bool operator<=(const ACE_UUID &right) const;
  bool operator>=(const ACE_UUID &right) const;

  /**
   * Returns a string representation of the UUID. Internally,
   * the string representation, which is contained in as
   * String, is only computed if this operation is called.
   * Once the representation is computed it can never change.
   */
  const ACE_SString* to_string (void);
    
  static ACE_UUID NIL_UUID;
    
 private:
  /**
   * The string representation of the UUID. This is created
   * and updated only on demand.
   */
  //mutable ACE_SString asString; 
  ACE_SString *as_string_; 
    
  // This ACE_UUID_Impl's representation of the UUID
  UUID_t uuid_;
};

/**
 * @class ACE_UUID_Generator
 * Singleton class that generates UUIDs.
 */
class ACE_Export ACE_UUID_Generator
{
 public:

  enum { ACE_UUID_CLOCK_SEQ_MASK = 0x3FFF };
  
  // Format timestamp, clockseq, and nodeID into a VI UUID.
  void generateV1(ACE_UUID::UUID_t&);

  // Format timestamp, clockseq, and nodeID into a VI UUID.
  ACE_UUID generateUUID (void);

  /**
   * Type to represent UTC as a count of 100 nanosecond intervals since
   * 00:00:00.00, 15 October 1582.
   */
  typedef ACE_UINT64 UUID_time_t;

  ACE_UUID_Generator(void);
  ACE_UUID_Generator(ACE_Lock* lock);
  ~ACE_UUID_Generator();

  
  /**
   * The locking strategy prevents multiple generators
   * from accessing the UUID_state at the same time.
   * Get the locking strategy.
   */
  ACE_Lock *lock (void);

  /**
   * Set a new locking strategy and return the hold one.
   */
  ACE_Lock *lock (ACE_Lock *lock);


 private:

  /**
   * The maximum number of uuids that can be generated per tick of the
   * system clock. This number should be the number of 100ns ticks of the
   * actual resolution of the system's clock.
   */
  enum { UUIDS_PER_TICK = 1000 };

  /**
   * The number of uuids generated in this process since the last clock
   * tick. Value never exceeds uuidsPerTick - 1.
   */
  ACE_UINT32 uuidsThisTick;

  /**
   * The system time when that last uuid was generated.
   */
  UUID_time_t timeLast;

  /**
   * Type to map to contain the UUID generator persistent state. This
   * will be kept in memory mapped shared memory
   */
  struct UUID_state
  {
    UUID_time_t timestamp;
    ACE_UUID::UUID_node_t node;
    ACE_UINT16 clockSequence;
  };

  /**
   * Obtain a UUID timestamp. Compensate for the fact that the time
   * obtained from getSystem time has a resolution less than 100ns.
   */
  void getTimestamp( UUID_time_t& timestamp);

  /**
   * Obtain the system time in UTC as a count of 100 nanosecond intervals
   * since 00:00:00.00, 15 October 1582 (the date of Gregorian reform to
   * the Christian calendar).
   */
  void get_system_time( UUID_time_t& timeNow);

  
  /**
   * The system time when that last uuid was generated.
   */
  UUID_time_t time_last_;
 
  /**
   * The UUID generator persistent state.
   */
  UUID_state uuid_state_;

  ACE_Lock* lock_;
  
  // No value semantics
  //ACE_UNIMPLEMENTED_FUNC (ACE_UUID_Generator( const ACE_UUID_Generator&))
  // ACE_UNIMPLEMENTED_FUNC (ACE_UUID_Generator& operator=( const ACE_UUID_Generator&))
};

typedef ACE_Singleton <ACE_UUID_Generator, ACE_SYNCH_MUTEX> ACE_UUID_GENERATOR;

#if defined (__ACE_INLINE__)
#include "ace/UUID.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif // ACE_UUID_H

