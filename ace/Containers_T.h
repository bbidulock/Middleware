/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Containers_T.h
 *
 *  $Id$
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_CONTAINERS_T_H
#define ACE_CONTAINERS_T_H
#include "ace/pre.h"

#include "ace/ACE.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Need by ACE_DLList_Node.
#include "ace/Containers.h"

class ACE_Allocator;

/**
 * @class ACE_Bounded_Stack
 *
 * @brief Implement a generic LIFO abstract data type.
 *
 * This implementation of a Stack uses a bounded array
 * that is allocated dynamically.
 */
template <class T>
class ACE_Bounded_Stack
{
public:
  // = Initialization, assignemnt, and termination methods.

  /// Initialize a new stack so that it is empty.
  /// The copy constructor (performs initialization).
  ACE_Bounded_Stack (size_t size);
  ACE_Bounded_Stack (const ACE_Bounded_Stack<T> &s);

  /// Assignment operator (performs assignment).
  void operator= (const ACE_Bounded_Stack<T> &s);

  /// Perform actions needed when stack goes out of scope.
  ~ACE_Bounded_Stack (void);

  // = Classic Stack operations.

  /**
   * Place a new item on top of the stack.  Returns -1 if the stack
   * is already full, 0 if the stack is not already full, and -1 if
   * failure occurs.
   */
  int push (const T &new_item);

  /**
   * Remove and return the top stack item.  Returns -1 if the stack is
   * already empty, 0 if the stack is not already empty, and -1 if
   * failure occurs.
   */
  int pop (T &item);

  /**
   * Return top stack item without removing it.  Returns -1 if the
   * stack is already empty, 0 if the stack is not already empty, and
   * -1 if failure occurs.
   */
  int top (T &item) const;

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is full, otherwise returns 0.
  int is_full (void) const;

  /// The number of items in the stack.
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Size of the dynamically allocated data.
  size_t size_;

  /// Keeps track of the current top of stack.
  size_t top_;

  /// Holds the stack's contents.
  T *stack_;
};

//----------------------------------------

/**
 * @class ACE_Fixed_Stack
 *
 * @brief Implement a generic LIFO abstract data type.
 *
 * This implementation of a Stack uses a fixed array
 * with the size fixed at instantiation time.
 */
template <class T, size_t ACE_SIZE>
class ACE_Fixed_Stack
{
public:
  // = Initialization, assignemnt, and termination methods.
  /// Initialize a new stack so that it is empty.
  ACE_Fixed_Stack (void);

  /// The copy constructor (performs initialization).
  ACE_Fixed_Stack (const ACE_Fixed_Stack<T, ACE_SIZE> &s);

  /// Assignment operator (performs assignment).
  void operator= (const ACE_Fixed_Stack<T, ACE_SIZE> &s);

  /// Perform actions needed when stack goes out of scope.
  ~ACE_Fixed_Stack (void);

  // = Classic Stack operations.

  /**
   * Place a new item on top of the stack.  Returns -1 if the stack
   * is already full, 0 if the stack is not already full, and -1 if
   * failure occurs.
   */
  int push (const T &new_item);

  /**
   * Remove and return the top stack item.  Returns -1 if the stack is
   * already empty, 0 if the stack is not already empty, and -1 if
   * failure occurs.
   */
  int pop (T &item);

  /**
   * Return top stack item without removing it.  Returns -1 if the
   * stack is already empty, 0 if the stack is not already empty, and
   * -1 if failure occurs.
   */
  int top (T &item) const;

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is full, otherwise returns 0.
  int is_full (void) const;

  /// The number of items in the stack.
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Size of the allocated data.
  size_t size_;

  /// Keeps track of the current top of stack.
  size_t top_;

  /// Holds the stack's contents.
  T stack_[ACE_SIZE];
};

//----------------------------------------

// Forward declarations.
template <class T> class ACE_Unbounded_Set;
template <class T> class ACE_Unbounded_Set_Iterator;
template <class T> class ACE_Unbounded_Queue;
template <class T> class ACE_Unbounded_Queue_Iterator;
template <class T> class ACE_Unbounded_Stack;
template <class T> class ACE_Unbounded_Stack_Iterator;
template <class T> class ACE_Ordered_MultiSet;
template <class T> class ACE_Ordered_MultiSet_Iterator;

/**
 * @class ACE_Node
 *
 * @brief Implementation element in a Queue, Set, and Stack.
 */
template<class T>
class ACE_Node
{
public:
  friend class ACE_Unbounded_Queue<T>;
  friend class ACE_Unbounded_Queue_Iterator<T>;
  friend class ACE_Unbounded_Set<T>;
  friend class ACE_Unbounded_Set_Iterator<T>;
  friend class ACE_Unbounded_Stack<T>;
  friend class ACE_Unbounded_Stack_Iterator<T>;

# if ! defined (ACE_HAS_BROKEN_NOOP_DTORS)
  /// This isn't necessary, but it keeps some compilers happy.
  ~ACE_Node (void);
# endif /* ! defined (ACE_HAS_BROKEN_NOOP_DTORS) */

private:
  // = Initialization methods
  ACE_Node (const T &i, ACE_Node<T> *n);
  ACE_Node (ACE_Node<T> *n = 0, int = 0);
  ACE_Node (const ACE_Node<T> &n);

  /// Pointer to next element in the list of <ACE_Node>s.
  ACE_Node<T> *next_;

  /// Current value of the item in this node.
  T item_;
};

/**
 * @class ACE_DNode
 *
 * @brief Implementation element in a bilinked list.
 */
template<class T>
class ACE_DNode
{
  friend class ACE_Ordered_MultiSet<T>;
  friend class ACE_Ordered_MultiSet_Iterator<T>;

public:

# if ! defined (ACE_HAS_BROKEN_NOOP_DTORS)
  /// This isn't necessary, but it keeps some compilers happy.
  ~ACE_DNode (void);
# endif /* ! defined (ACE_HAS_BROKEN_NOOP_DTORS) */

private:

  // = Initialization methods
  ACE_DNode (const T &i, ACE_DNode<T> *n = 0, ACE_DNode<T> *p = 0);

  /// Pointer to next element in the list of <ACE_DNode>s.
  ACE_DNode<T> *next_;

  /// Pointer to previous element in the list of <ACE_DNode>s.
  ACE_DNode<T> *prev_;

  /// Current value of the item in this node.
  T item_;
};


/**
 * @class ACE_Unbounded_Stack
 *
 * @brief Implement a generic LIFO abstract data type.
 *
 * This implementation of an unbounded Stack uses a linked list.
 * If you use the <insert> or <remove> methods you should keep
 * in mind that duplicate entries aren't allowed.  In general,
 * therefore, you should avoid the use of these methods since
 * they aren't really part of the ADT stack.
 */
template <class T>
class ACE_Unbounded_Stack
{
public:
  friend class ACE_Unbounded_Stack_Iterator<T>;

  // Trait definition.
  typedef ACE_Unbounded_Stack_Iterator<T> ITERATOR;

  // = Initialization, assignemnt, and termination methods.
  /// Initialize a new stack so that it is empty.  Use user defined
  /// allocation strategy if specified.
  ACE_Unbounded_Stack (ACE_Allocator *alloc = 0);

  /// The copy constructor (performs initialization).
  ACE_Unbounded_Stack (const ACE_Unbounded_Stack<T> &s);

  /// Assignment operator (performs assignment).
  void operator= (const ACE_Unbounded_Stack<T> &s);

  /// Perform actions needed when stack goes out of scope.
  ~ACE_Unbounded_Stack (void);

  // = Classic Stack operations.

  /**
   * Place a new item on top of the stack.  Returns -1 if the stack
   * is already full, 0 if the stack is not already full, and -1 if
   * failure occurs.
   */
  int push (const T &new_item);

  /**
   * Remove and return the top stack item.  Returns -1 if the stack is
   * already empty, 0 if the stack is not already empty, and -1 if
   * failure occurs.
   */
  int pop (T &item);

  /**
   * Return top stack item without removing it.  Returns -1 if the
   * stack is already empty, 0 if the stack is not already empty, and
   * -1 if failure occurs.
   */
  int top (T &item) const;

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is full, otherwise returns 0.
  int is_full (void) const;

  // = Auxiliary methods (not strictly part of the Stack ADT).

  /**
   * Insert <new_item> into the Stack at the head (but doesn't allow
   * duplicates).  Returns -1 if failures occur, 1 if item is already
   * present (i.e., no duplicates are allowed), else 0.
   */
  int insert (const T &new_item);

  /// Remove <item> from the Stack.  Returns 0 if it removes the item,
  /// -1 if it can't find the item, and -1 if a failure occurs.
  int remove (const T &item);

  /// Finds if <item> occurs the set.  Returns 0 if finds, else -1.
  int find (const T &item) const;

  /// The number of items in the stack.
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Delete all the nodes in the stack.
  void delete_all_nodes (void);

  /// Copy all nodes from <s> to <this>.
  void copy_all_nodes (const ACE_Unbounded_Stack<T> &s);

  /// Head of the linked list of Nodes.
  ACE_Node<T> *head_;

  /// Current size of the stack.
  size_t cur_size_;

  /// Allocation strategy of the stack.
  ACE_Allocator *allocator_;
};

/**
 * @class ACE_Unbounded_Stack_Iterator
 *
 * @brief Implement an iterator over an unbounded Stack.
 */
template <class T>
class ACE_Unbounded_Stack_Iterator
{
public:
  // = Initialization method.
  /// Move to the first element in the <stack>.
  ACE_Unbounded_Stack_Iterator (ACE_Unbounded_Stack<T> &stack);

  // = Iteration methods.

  /// Pass back the <next_item> that hasn't been seen in the Stack.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the Stack.  Returns 0 when all the
  /// items in the Stack have been seen, else 1.
  int advance (void);

  /// Move to the first element in the Stack.  Returns 0 if the
  /// Stack is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the current node in the iteration.
  ACE_Node<T> *current_;

  /// Pointer to the Stack we're iterating over.
  ACE_Unbounded_Stack<T> &stack_;
};

template <class T>
class ACE_Unbounded_Queue;

/**
 * @class ACE_Unbounded_Queue_Iterator
 *
 * @brief Implement an iterator over an unbounded queue.
 */
template <class T>
class ACE_Unbounded_Queue_Iterator
{
public:
  // = Initialization method.
  ACE_Unbounded_Queue_Iterator (ACE_Unbounded_Queue<T> &q, int end = 0);

  // = Iteration methods.

  /// Pass back the <next_item> that hasn't been seen in the queue.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the queue have been seen, else 1.
  int advance (void);

  /// Move to the first element in the queue.  Returns 0 if the
  /// queue is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the current node in the iteration.
  ACE_Node<T> *current_;

  /// Pointer to the queue we're iterating over.
  ACE_Unbounded_Queue<T> &queue_;
};

/**
 * @class ACE_Unbounded_Queue
 *
 * @brief A Queue of "infinite" length.
 *
 * This implementation of an unbounded queue uses a circular
 * linked list with a dummy node.
 */
template <class T>
class ACE_Unbounded_Queue
{
public:
  friend class ACE_Unbounded_Queue_Iterator<T>;

  // Trait definition.
  typedef ACE_Unbounded_Queue_Iterator<T> ITERATOR;

  // = Initialization and termination methods.
  /// construction.  Use user specified allocation strategy
  /// if specified.
  ACE_Unbounded_Queue (ACE_Allocator *alloc = 0);

  /// Copy constructor.
  ACE_Unbounded_Queue (const ACE_Unbounded_Queue<T> &);

  /// Assignment operator.
  void operator= (const ACE_Unbounded_Queue<T> &);

  /// construction.
  ~ACE_Unbounded_Queue (void);

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is full, otherwise returns 0.
  int is_full (void) const;

  // = Classic queue operations.

  /// Adds <new_item> to the tail of the queue.  Returns 0 on success,
  /// -1 on failure.
  int enqueue_tail (const T &new_item);

  /// Adds <new_item> to the head of the queue.  Returns 0 on success,
  /// -1 on failure.
  int enqueue_head (const T &new_item);

  /// Removes and returns the first <item> on the queue.  Returns 0 on
  /// success, -1 if the queue was empty.
  int dequeue_head (T &item);

  // = Additional utility methods.

  /// Reset the <ACE_Unbounded_Queue> to be empty and release all its
  /// dynamically allocated resources.
  void reset (void);

  /// Get the <slot>th element in the set.  Returns -1 if the element
  /// isn't in the range {0..<size> - 1}, else 0.
  int get (T *&item, size_t slot = 0) const;

  /**
   * Set the <slot>th element in the set.  Will pad out the set with
   * empty nodes if <slot> is beyond the range {0..<size> - 1}.
   * Returns -1 on failure, 0 if <slot> isn't initially in range, and
   * 0 otherwise.
   */
  int set (const T &item, size_t slot);

  /// The number of items in the queue.
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  // = STL-styled unidirectional iterator factory.
  ACE_Unbounded_Queue_Iterator<T> begin (void);
  ACE_Unbounded_Queue_Iterator<T> end (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Delete all the nodes in the queue.
  void delete_nodes (void);

  /// Copy nodes into this queue.
  void copy_nodes (const ACE_Unbounded_Queue<T> &);

  /// Pointer to the dummy node in the circular linked Queue.
  ACE_Node<T> *head_;

  /// Current size of the queue.
  size_t cur_size_;

  /// Allocation Strategy of the queue.
  ACE_Allocator *allocator_;
};

template <class T>
class ACE_Double_Linked_List;

/**
 * @class ACE_Double_Linked_List_Iterator_Base
 *
 * @brief Implements a common base class for iterators for a double
 * linked list ADT
 */
template <class T>
class ACE_Double_Linked_List_Iterator_Base
{
public:
  // = Iteration methods.

  /// Passes back the <entry> under the iterator. Returns 0 if the
  /// iteration has completed, otherwise 1
  int next (T *&) const;

  /**
   * Return the address of next (current) unvisited item in the list.
   * 0 if there is no more element available.
   * DEPRECATED
   */
  T *next (void) const;

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// STL-like iterator dereference operator: returns a reference
  /// to the node underneath the iterator.
  T & operator* (void) const ;

  /**
   * Retasks the iterator to iterate over a new
   * Double_Linked_List. This allows clients to reuse an iterator
   * without incurring the constructor overhead. If you do use this,
   * be aware that if there are more than one reference to this
   * iterator, the other "clients" may be very bothered when their
   * iterator changes.  @@ Here be dragons. Comments?
   */
  void reset (ACE_Double_Linked_List<T> &);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  // = Initialization methods.

  /// Constructor
  ACE_Double_Linked_List_Iterator_Base (ACE_Double_Linked_List<T> &);

  /// Copy constructor.
  ACE_Double_Linked_List_Iterator_Base (const
                                        ACE_Double_Linked_List_Iterator_Base<T>
                                        &iter);

  // = Iteration methods.
  /**
   * Move to the first element of the list. Returns 0 if the list is
   * empty, else 1. Note: the head of the ACE_DLList is actually a
   * null entry, so the first element is actually the 2n'd entry
   */
  int go_head (void);

  /// Move to the last element of the list. Returns 0 if the list is
  /// empty, else 1.
  int go_tail (void);

  /**
   * Check if we reach the end of the list.  Can also be used to get
   * the *current* element in the list.  Return the address of the
   * current item if there are still elements left , 0 if we run out
   * of element.
   */
  T *not_done (void) const ;

  /// Advance to the next element in the list.  Return the address of the
  /// next element if there are more, 0 otherwise.
  T *do_advance (void);

  /// Retreat to the previous element in the list.  Return the address
  /// of the previous element if there are more, 0 otherwise.
  T *do_retreat (void);

  /// Dump the state of an object.
  void dump_i (void) const;

  /// Remember where we are.
  T *current_;

  ACE_Double_Linked_List<T> *dllist_;
};

/**
 * @class ACE_Double_Linked_List_Iterator
 *
 * @brief Implements an iterator for a double linked list ADT
 *
 * Iterate thru the double-linked list.  This class provides
 * an interface that let users access the internal element
 * addresses directly. Notice <class T> must delcare
 * ACE_Double_Linked_List<T>,
 * ACE_Double_Linked_List_Iterator_Base <T> and
 * ACE_Double_Linked_List_Iterator as friend classes and class T
 * should also have data members T* next_ and T* prev_.
 */
template <class T>
class ACE_Double_Linked_List_Iterator : public ACE_Double_Linked_List_Iterator_Base <T>
{
public:
  // = Initialization method.
  ACE_Double_Linked_List_Iterator (ACE_Double_Linked_List<T> &);

  /**
   * Retasks the iterator to iterate over a new
   * Double_Linked_List. This allows clients to reuse an iterator
   * without incurring the constructor overhead. If you do use this,
   * be aware that if there are more than one reference to this
   * iterator, the other "clients" may be very bothered when their
   * iterator changes.
   * @@ Here be dragons. Comments?
   */
  void reset (ACE_Double_Linked_List<T> &);

  /// Move to the first element in the list.  Returns 0 if the
  /// list is empty, else 1.
  int first (void);

  /// Move forward by one element in the list.  Returns 0 when all the
  /// items in the list have been seen, else 1.
  int advance (void);

  /**
   * Advance the iterator while removing the original item from the
   * list.  Return a pointer points to the original (removed) item.
   * If <dont_remove> equals 0, this function behaves like <advance>
   * but return 0 (NULL) instead.
   */
  T* advance_and_remove (int dont_remove);

  // = STL-style iteration methods

  /// Prefix advance.
  ACE_Double_Linked_List_Iterator<T> & operator++ (void);

  /// Postfix advance.
  ACE_Double_Linked_List_Iterator<T> operator++ (int);

  /// Prefix reverse.
  ACE_Double_Linked_List_Iterator<T> & operator-- (void);

  /// Postfix reverse.
  ACE_Double_Linked_List_Iterator<T> operator-- (int);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Double_Linked_List_Reverse_Iterator
 *
 * @brief Implements a reverse iterator for a double linked list ADT
 *
 * Iterate backwards over the double-linked list.  This class
 * provide an interface that let users access the internal
 * element addresses directly, which seems to break the
 * encapsulation.  Notice <class T> must delcare
 * ACE_Double_Linked_List<T>,
 * ACE_Double_Linked_List_Iterator_Base <T> and
 * ACE_Double_Linked_List_Iterator as friend classes and class T
 * should also have data members T* next_ and T* prev_.
 */
template <class T>
class ACE_Double_Linked_List_Reverse_Iterator : public ACE_Double_Linked_List_Iterator_Base <T>
{
public:
  // = Initialization method.
  ACE_Double_Linked_List_Reverse_Iterator (ACE_Double_Linked_List<T> &);

  /**
   * Retasks the iterator to iterate over a new
   * Double_Linked_List. This allows clients to reuse an iterator
   * without incurring the constructor overhead. If you do use this,
   * be aware that if there are more than one reference to this
   * iterator, the other "clients" may be very bothered when their
   * iterator changes.
   * @@ Here be dragons. Comments?
   */
  void reset (ACE_Double_Linked_List<T> &);

  /// Move to the first element in the list.  Returns 0 if the
  /// list is empty, else 1.
  int first (void);

  /// Move forward by one element in the list.  Returns 0 when all the
  /// items in the list have been seen, else 1.
  int advance (void);

  /**
   * Advance the iterator while removing the original item from the
   * list.  Return a pointer points to the original (removed) item.
   * If <dont_remove> equals 0, this function behaves like <advance>
   * but return 0 (NULL) instead.
   */
  T* advance_and_remove (int dont_remove);

  // = STL-style iteration methods

  /// Prefix advance.
  ACE_Double_Linked_List_Reverse_Iterator<T> & operator++ (void);

  /// Postfix advance.
  ACE_Double_Linked_List_Reverse_Iterator<T> operator++ (int);

  /// Prefix reverse.
  ACE_Double_Linked_List_Reverse_Iterator<T> & operator-- (void);

  /// Postfix reverse.
  ACE_Double_Linked_List_Reverse_Iterator<T> operator-- (int);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Double_Linked_List
 *
 * @brief A double-linked list implementation.
 *
 * This implementation of an unbounded double-linked list uses a
 * circular linked list with a dummy node.  It is pretty much
 * like the <ACE_Unbounded_Queue> except that it allows removing
 * of a specific element from a specific location.
 * Notice that this class is an implementation of a very simply
 * data structure.is *NOT* a container class.  You can use the
 * class to implement other contains classes but it is *NOT* a
 * general purpose container class.
 * The parameter class *MUST* has members T* prev and T* next
 * and users of this class are responsible to follow the general
 * rules of using double-linked lists to maintaining the list
 * integrities.
 * If you need a double linked container class, check out the
 * DLList class in this file.
 */
template <class T>
class ACE_Double_Linked_List
{
public:
  friend class ACE_Double_Linked_List_Iterator_Base<T>;
  friend class ACE_Double_Linked_List_Iterator<T>;
  friend class ACE_Double_Linked_List_Reverse_Iterator<T>;

  // Trait definition.
  typedef ACE_Double_Linked_List_Iterator<T> ITERATOR;
  typedef ACE_Double_Linked_List_Reverse_Iterator<T> REVERSE_ITERATOR;

  // = Initialization and termination methods.
  /// construction.  Use user specified allocation strategy
  /// if specified.
  ACE_Double_Linked_List (ACE_Allocator *alloc = 0);

  /// Copy constructor.
  ACE_Double_Linked_List (ACE_Double_Linked_List<T> &);

  /// Assignment operator.
  void operator= (ACE_Double_Linked_List<T> &);

  /// Destructor.
  ~ACE_Double_Linked_List (void);

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is full, otherwise returns 0.
  int is_full (void) const;

  // = Classic queue operations.

  /// Adds <new_item> to the tail of the list. Returns the new item
  /// that was inserted.
  T *insert_tail (T *new_item);

  /// Adds <new_item> to the head of the list.Returns the new item that
  /// was inserted.
  T *insert_head (T *new_item);

  /**
   * Removes and returns the first <item> in the list.  Returns
   * internal node's address on success, 0 if the queue was empty.
   * This method will *not* free the internal node.
   */
  T* delete_head (void);

  /**
   * Removes and returns the last <item> in the list.  Returns
   * internal nodes's address on success, 0 if the queue was
   * empty. This method will *not* free the internal node.
   */
  T *delete_tail (void);

  // = Additional utility methods.

  /**
   * Reset the <ACE_Double_Linked_List> to be empty.
   * Notice that since no one is interested in the items within,
   * This operation will delete all items.
   */
  void reset (void);

  /// Get the <slot>th element in the set.  Returns -1 if the element
  /// isn't in the range {0..<size> - 1}, else 0.
  int get (T *&item, size_t slot = 0);

  /// The number of items in the queue.
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Use DNode address directly.
  int remove (T *n);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Delete all the nodes in the list.
  void delete_nodes (void);

  /// Copy nodes into this list.
  void copy_nodes (ACE_Double_Linked_List<T> &);

  /// Setup header pointer.  Called after we create the head node in ctor.
  void init_head (void);

  /**
   * Insert a <new_element> into the list.  It will be added before
   * or after <old_item>.  Default is to insert the new item *after*
   * <head_>.  Return 0 if succeed, -1 if error occured.
   */
  int insert_element (T *new_item,
                      int before = 0,
                      T *old_item = 0);

  /**
   * Remove an <item> from the list.  Return 0 if succeed, -1 otherwise.
   * Notice that this function checks if item is <head_> and either its
   * <next_> or <prev_> is NULL.  The function resets item's <next_> and
   * <prev_> to 0 to prevent clobbering the double-linked list if a user
   * tries to remove the same node again.
   */
  int remove_element (T *item);

  /// Head of the circular double-linked list.
  T *head_;

  /// Size of this list.
  size_t size_;

  /// Allocation Strategy of the queue.
  ACE_Allocator *allocator_;
};


template <class T> class ACE_DLList;
template <class T> class ACE_DLList_Iterator;
template <class T> class ACE_DLList_Reverse_Iterator;

typedef ACE_Double_Linked_List<ACE_DLList_Node> ACE_DLList_Base;

//typedef ACE_Double_Linked_List_Iterator <ACE_DLList_Node>
//        ACE_DLList_Iterator_Base;
//typedef ACE_Double_Linked_List_Reverse_Iterator <ACE_DLList_Node>
//        ACE_DLList_Reverse_Iterator_Base;
//@@ These two typedefs (inherited from James Hu's original design)
// have been removed because Sun CC 4.2 had problems with it. I guess
// having the DLList_Iterators inheriting from a class which is
// actually a typedef leads to problems. #define'ing rather than
// typedef'ing worked, but as per Carlos's reccomendation, I'm just
// replacing all references to the base classes with their actual
// type.  Matt Braun (6/15/99)

/**
 * @class ACE_DLList
 *
 * @brief A double-linked list container class.
 *
 * This implementation uses ACE_Double_Linked_List to perform
 * the logic behind this container class.  It delegates all of its
 * calls to ACE_Double_Linked_List.
 */
template <class T>
class ACE_DLList : public ACE_DLList_Base
{

  friend class ACE_DLList_Node;
  friend class ACE_Double_Linked_List_Iterator<T>;
  friend class ACE_DLList_Iterator<T>;
  friend class ACE_DLList_Reverse_Iterator<T>;

public:

  /// Delegates to ACE_Double_Linked_List.
  void operator= (ACE_DLList<T> &l);

  // = Classic queue operations.

  /// Delegates to ACE_Double_Linked_List.
  T *insert_tail (T *new_item);

  /// Delegates to ACE_Double_Linked_List.
  T *insert_head (T *new_item);

  /// Delegates to ACE_Double_Linked_List.
  T *delete_head (void);

  /// Delegates to ACE_Double_Linked_List.
  T *delete_tail (void);

  // = Additional utility methods.

  /**
   * Delegates to <ACE_Double_Linked_List>, but where
   * <ACE_Double_Linked_List> returns the node as the item, this get
   * returns the contents of the node in item.
   */
  int get (T *&item, size_t slot = 0);

  /// Delegates to ACE_Double_Linked_List.
  void dump (void) const;

  /// Delegates to ACE_Double_Linked_List.
  int remove (ACE_DLList_Node *n);


  // = Initialization and termination methods.

  /// Delegates to ACE_Double_Linked_List.
  ACE_DLList (ACE_Allocator *alloc = 0);

  /// Delegates to ACE_Double_Linked_List.
  ACE_DLList (ACE_DLList<T> &l);

  /// Deletes the list starting from the head.
  ~ACE_DLList (void);
};

/**
 * @class ACE_DLList_Iterator
 *
 * @brief A double-linked list container class iterator.
 *
 * This implementation uses ACE_Double_Linked_List_Iterator to
 * perform the logic behind this container class.  It delegates
 * all of its calls to ACE_Double_Linked_List_Iterator.
 */
template <class T>
class ACE_DLList_Iterator : public ACE_Double_Linked_List_Iterator <ACE_DLList_Node>
{

  friend class ACE_DLList<T>;
  friend class ACE_DLList_Node;

public:

  // = Initialization method.
  ACE_DLList_Iterator (ACE_DLList<T> &l);

  /**
   * Retasks the iterator to iterate over a new
   * Double_Linked_List. This allows clients to reuse an iterator
   * without incurring the constructor overhead. If you do use this,
   * be aware that if there are more than one reference to this
   * iterator, the other "clients" may be very bothered when their
   * iterator changes.
   * @@ Here be dragons. Comments?
   */
  void reset (ACE_DLList<T> &l);

  // = Iteration methods.
  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Pass back the <next_item> that hasn't been seen in the Stack.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&);

  /**
   * Delegates to ACE_Double_Linked_List_Iterator, except that whereas
   * the Double_Linked_List version of next returns the node, this next
   * returns the contents of the node
   * DEPRECATED
   */
  T *next (void) const;

  /// Removes the current item (i.e., <next>) from the list.
  int remove (void);

  /// Delegates to ACE_Double_Linked_List_Iterator.
  void dump (void) const;

private:
  ACE_DLList<T> *list_;
};

/**
 * @class ACE_DLList_Reverse_Iterator
 *
 * @brief A double-linked list container class iterator.
 *
 * This implementation uses ACE_Double_Linked_List_Iterator to
 * perform the logic behind this container class.  It delegates
 * all of its calls to ACE_Double_Linked_List_Iterator.
 */
template <class T>
class ACE_DLList_Reverse_Iterator : public ACE_Double_Linked_List_Reverse_Iterator <ACE_DLList_Node>
{

  friend class ACE_DLList<T>;
  friend class ACE_DLList_Node;

public:

  // = Initialization method.
  ACE_DLList_Reverse_Iterator (ACE_DLList<T> &l);

  /**
   * Retasks the iterator to iterate over a new
   * Double_Linked_List. This allows clients to reuse an iterator
   * without incurring the constructor overhead. If you do use this,
   * be aware that if there are more than one reference to this
   * iterator, the other "clients" may be very bothered when their
   * iterator changes.
   * @@ Here be dragons. Comments?
   */
  void reset (ACE_DLList<T> &l);

  // = Iteration methods.
  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Pass back the <next_item> that hasn't been seen in the Stack.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&);

  /// Delegates to ACE_Double_Linked_List_Iterator.
  /// DEPRECATED
  T *next (void) const;

  /// Removes the current item (i.e., <next>) from the list.
  int remove (void);

  /// Delegates to ACE_Double_Linked_List_Iterator.
  void dump (void) const;

private:
  ACE_DLList<T> *list_;
};

/**
 * @class ACE_Unbounded_Set_Iterator
 *
 * @brief Implement an iterator over an unbounded set.
 */
template <class T>
class ACE_Unbounded_Set_Iterator
{
public:
  // = Initialization method.
  ACE_Unbounded_Set_Iterator (ACE_Unbounded_Set<T> &s, int end = 0);

  // = Iteration methods.

  /// Pass back the <next_item> that hasn't been seen in the Set.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Move to the first element in the set.  Returns 0 if the
  /// set is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Postfix advance.
  ACE_Unbounded_Set_Iterator<T> operator++ (int);

  /// Prefix advance.
  ACE_Unbounded_Set_Iterator<T>& operator++ (void);

  /// Returns a reference to the internal element <this> is pointing to.
  T& operator* (void);

  /// Check if two iterators point to the same position
  int operator== (const ACE_Unbounded_Set_Iterator<T> &) const;
  int operator!= (const ACE_Unbounded_Set_Iterator<T> &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  /// Pointer to the current node in the iteration.
  ACE_Node<T> *current_;

  /// Pointer to the set we're iterating over.
  ACE_Unbounded_Set<T> *set_;
};

/**
 * @class ACE_Unbounded_Set
 *
 * @brief Implement a simple unordered set of <T> of unbounded size.
 *
 * This implementation of an unordered set uses a circular
 * linked list with a dummy node.  This implementation does not
 * allow duplicates, but it maintains FIFO ordering of insertions.
 */
template <class T>
class ACE_Unbounded_Set
{
public:
  friend class ACE_Unbounded_Set_Iterator<T>;

  // Trait definition.
  typedef ACE_Unbounded_Set_Iterator<T> ITERATOR;
  typedef ACE_Unbounded_Set_Iterator<T> iterator;

  // = Initialization and termination methods.
  /// Constructor.  Use user specified allocation strategy
  /// if specified.
  ACE_Unbounded_Set (ACE_Allocator *alloc = 0);

  /// Copy constructor.
  ACE_Unbounded_Set (const ACE_Unbounded_Set<T> &);

  /// Assignment operator.
  void operator= (const ACE_Unbounded_Set<T> &);

  /// Destructor.
  ~ACE_Unbounded_Set (void);

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is full, otherwise returns 0.
  int is_full (void) const;

  // = Classic unordered set operations.

  /**
   * Insert <new_item> into the set (doesn't allow duplicates).
   * Returns -1 if failures occur, 1 if item is already present, else
   * 0.
   */
  int insert (const T &new_item);

  /**
   * Remove first occurrence of <item> from the set.  Returns 0 if
   * it removes the item, -1 if it can't find the item, and -1 if a
   * failure occurs.
   */
  int remove (const T &item);

  /// Finds if <item> occurs in the set.  Returns 0 if find succeeds,
  /// else -1.
  int find (const T &item) const;

  /// Size of the set.
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Reset the <ACE_Unbounded_Set> to be empty.
  void reset (void);

  // = STL-styled unidirectional iterator factory.
  ACE_Unbounded_Set_Iterator<T> begin (void);
  ACE_Unbounded_Set_Iterator<T> end (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Insert <item> at the tail of the set (doesn't check for
  /// duplicates).
  int insert_tail (const T &item);

  /// Delete all the nodes in the Set.
  void delete_nodes (void);

  /// Copy nodes into this set.
  void copy_nodes (const ACE_Unbounded_Set<T> &);

  /// Head of the linked list of Nodes.
  ACE_Node<T> *head_;

  /// Current size of the set.
  size_t cur_size_;

  /// Allocation strategy of the set.
  ACE_Allocator *allocator_;
};

// Forward declaration.
template <class T, size_t ACE_SIZE>
class ACE_Fixed_Set;

/**
 * @class ACE_Fixed_Set_Iterator
 *
 * @brief Interates through an unordered set.
 *
 * This implementation of an unordered set uses a fixed array.
 * Allows deletions while iteration is occurring.
 */
template <class T, size_t ACE_SIZE>
class ACE_Fixed_Set_Iterator
{
public:
  // = Initialization method.
  ACE_Fixed_Set_Iterator (ACE_Fixed_Set<T, ACE_SIZE> &s);

  // = Iteration methods.

  /// Pass back the <next_item> that hasn't been seen in the Set.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Move to the first element in the set.  Returns 0 if the
  /// set is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Set we are iterating over.
  ACE_Fixed_Set<T, ACE_SIZE> &s_;

  /// How far we've advanced over the set.
  ssize_t next_;
};

/**
 * @class ACE_Fixed_Set
 *
 * @brief Implement a simple unordered set of <T> with maximum <ACE_SIZE>.
 *
 * This implementation of an unordered set uses a fixed array.
 * This implementation does not allow duplicates...
 */
template <class T, size_t ACE_SIZE>
class ACE_Fixed_Set
{
public:
  friend class ACE_Fixed_Set_Iterator<T, ACE_SIZE>;

  // Trait definition.
  typedef ACE_Fixed_Set_Iterator<T, ACE_SIZE> ITERATOR;

  // = Initialization and termination methods.
  /// Constructor.
  ACE_Fixed_Set (void);

  /// Copy constructor.
  ACE_Fixed_Set (const ACE_Fixed_Set<T, ACE_SIZE> &);

  /// Assignment operator.
  void operator= (const ACE_Fixed_Set<T, ACE_SIZE> &);

  /// Destructor.
  ~ACE_Fixed_Set (void);

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is full, otherwise returns 0.
  int is_full (void) const;

  // = Classic unordered set operations.

  /**
   * Insert <new_item> into the set (doesn't allow duplicates).
   * Returns -1 if failures occur, 1 if item is already present, else
   * 0.
   */
  int insert (const T &new_item);

  /**
   * Remove first occurrence of <item> from the set.  Returns 0 if
   * it removes the item, -1 if it can't find the item, and -1 if a
   * failure occurs.
   */
  int remove (const T &item);

  /// Finds if <item> occurs in the set.  Returns 0 if finds, else -1.
  int find (const T &item) const;

  /// Size of the set.
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  struct
  {
    T item_;
    // Item in the set.

    int is_free_;
    // Keeps track of whether this item is in use or not.
  } search_structure_[ACE_SIZE];
  // Holds the contents of the set.

  /// Current size of the set.
  size_t cur_size_;

  /// Maximum size of the set.
  size_t max_size_;
};

// Forward declaration.
template <class T>
class ACE_Bounded_Set;

/**
 * @class ACE_Bounded_Set_Iterator
 *
 * @brief Interates through an unordered set.
 *
 * This implementation of an unordered set uses a Bounded array.
 * Allows deletions while iteration is occurring.
 */
template <class T>
class ACE_Bounded_Set_Iterator
{
public:
  // = Initialization method.
  ACE_Bounded_Set_Iterator (ACE_Bounded_Set<T> &s);

  // = Iteration methods.

  /// Pass back the <next_item> that hasn't been seen in the Set.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Move to the first element in the set.  Returns 0 if the
  /// set is empty, else 1.
  int first (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Set we are iterating over.
  ACE_Bounded_Set<T> &s_;

  /// How far we've advanced over the set.
  ssize_t next_;
};

/**
 * @class ACE_Bounded_Set
 *
 * @brief Implement a simple unordered set of <T> with maximum
 * set at creation time.
 *
 * This implementation of an unordered set uses a Bounded array.
 * This implementation does not allow duplicates...
 */
template <class T>
class ACE_Bounded_Set
{
public:
  friend class ACE_Bounded_Set_Iterator<T>;

  // Trait definition.
  typedef ACE_Bounded_Set_Iterator<T> ITERATOR;

  enum
  {
    DEFAULT_SIZE = 10
  };

  // = Initialization and termination methods.
  /// Constructor.
  ACE_Bounded_Set (void);

  /// Constructor.
  ACE_Bounded_Set (size_t size);

  /// Copy constructor.
  ACE_Bounded_Set (const ACE_Bounded_Set<T> &);

  /// Assignment operator.
  void operator= (const ACE_Bounded_Set<T> &);

  /// Destructor
  ~ACE_Bounded_Set (void);

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Returns 1 if the container is full, otherwise returns 0.
  int is_full (void) const;

  // = Classic unordered set operations.

  /**
   * Insert <new_item> into the set (doesn't allow duplicates).
   * Returns -1 if failures occur, 1 if item is already present, else
   * 0.
   */
  int insert (const T &new_item);

  /**
   * Remove first occurrence of <item> from the set.  Returns 0 if it
   * removes the item, -1 if it can't find the item, and -1 if a
   * failure occurs.
   */
  int remove (const T &item);

  /// Finds if <item> occurs in the set.  Returns 0 if finds, else -1.
  int find (const T &item) const;

  /// Size of the set.
  size_t size (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  struct Search_Structure
  {
    T item_;
    // Item in the set.

    int is_free_;
    // Keeps track of whether this item is in use or not.
  };

  /// Holds the contents of the set.
  Search_Structure *search_structure_;

  /// Current size of the set.
  size_t cur_size_;

  /// Maximum size of the set.
  size_t max_size_;
};

/**
 * @class ACE_Ordered_MultiSet_Iterator
 *
 * @brief Implement a bidirectional iterator over an ordered multiset.
 * This class template requires that < operator semantics be
 * defined for the parameterized type <T>, but does not impose
 * any restriction on how that ordering operator is implemented.
 */
template <class T>
class ACE_Ordered_MultiSet_Iterator
{
public:
  friend class ACE_Ordered_MultiSet<T>;

  // = Initialization method.
  ACE_Ordered_MultiSet_Iterator (ACE_Ordered_MultiSet<T> &s);

  // = Iteration methods.

  /// Pass back the <next_item> that hasn't been seen in the ordered multiset.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item) const;

  /// Repositions the iterator at the first item in the ordered multiset
  /// Returns 0 if the list is empty else 1.
  int first (void);

  /// Repositions the iterator at the last item in the ordered multiset
  /// Returns 0 if the list is empty else 1.
  int last (void);

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Move backward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int retreat (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Returns a reference to the internal element <this> is pointing to.
  T& operator* (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  /// Pointer to the current node in the iteration.
  ACE_DNode<T> *current_;

  /// Pointer to the set we're iterating over.
  ACE_Ordered_MultiSet<T> &set_;
};

/**
 * @class ACE_Ordered_MultiSet
 *
 * @brief Implement a simple ordered multiset of <T> of unbounded size
 * that allows duplicates.  This class template requires that <
 * operator semantics be defined for the parameterized type <T>, but
 * does not impose any restriction on how that ordering operator is
 * implemented.
 */
template <class T>
class ACE_Ordered_MultiSet
{
public:
  friend class ACE_Ordered_MultiSet_Iterator<T>;

  // Trait definition.
  typedef ACE_Ordered_MultiSet_Iterator<T> ITERATOR;

  // = Initialization and termination methods.
  /// Constructor.  Use user specified allocation strategy
  /// if specified.
  ACE_Ordered_MultiSet (ACE_Allocator *alloc = 0);

  /// Copy constructor.
  ACE_Ordered_MultiSet (const ACE_Ordered_MultiSet<T> &);

  /// Destructor.
  ~ACE_Ordered_MultiSet (void);

  /// Assignment operator.
  void operator= (const ACE_Ordered_MultiSet<T> &);

  // = Check boundary conditions.

  /// Returns 1 if the container is empty, otherwise returns 0.
  int is_empty (void) const;

  /// Size of the set.
  size_t size (void) const;

  // = Classic unordered set operations.

  /// Insert <new_item> into the ordered multiset.
  /// Returns -1 if failures occur, else 0.
  int insert (const T &new_item);

  /**
   * Insert <new_item> into the ordered multiset, starting its search at
   * the node pointed to by the iterator, and if insetion was successful,
   * updates the iterator to point to the newly inserted node.
   * Returns -1 if failures occur, else 0.
   */
  int insert (const T &new_item, ITERATOR &iter);

  /// Remove first occurrence of <item> from the set.  Returns 0 if
  /// it removes the item, -1 if it can't find the item.
  int remove (const T &item);

  /**
   * Finds first occurrance of <item> in the multiset, using the iterator's
   * current position as a hint to improve performance. If find succeeds,
   * it positions the iterator at that node and returns 0, or if it cannot
   * locate the node, it leaves the iterator alone and just returns -1.
   */
  int find (const T &item, ITERATOR &iter) const;

  /// Reset the <ACE_Ordered_MultiSet> to be empty.
  void reset (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  /**
   * Insert <item>, starting its search at the position given,
   * and if successful updates the passed pointer to point to
   * the newly inserted item's node.
   */
  int insert_from (const T &item, ACE_DNode<T> *start_position,
                   ACE_DNode<T> **new_position);

  /**
   * looks for first occurance of <item> in the ordered set, using the
   * passed starting position as a hint: if there is such an instance, it
   * updates the new_position pointer to point to this node and returns 0;
   * if there is no such node, then if there is a node before where the
   * item would have been, it updates the new_position pointer to point
   * to this node and returns -1; if there is no such node, then if there
   * is a node after where the item would have been, it updates the
   * new_position pointer to point to this node (or 0 if there is no such
   * node) and returns 1;
   */
  int locate (const T &item, ACE_DNode<T> *start_position,
              ACE_DNode<T> *&new_position) const;

  /// Delete all the nodes in the Set.
  void delete_nodes (void);

  /// Copy nodes into this set.
  void copy_nodes (const ACE_Ordered_MultiSet<T> &);

  /// Head of the bilinked list of Nodes.
  ACE_DNode<T> *head_;

  /// Head of the bilinked list of Nodes.
  ACE_DNode<T> *tail_;

  /// Current size of the set.
  size_t cur_size_;

  /// Allocation strategy of the set.
  ACE_Allocator *allocator_;
};

// ****************************************************************

// Forward declaration.
template <class T> class ACE_Array_Iterator;

/**
 * @class ACE_Array_Base
 *
 * @brief Implement a simple dynamic array
 *
 * This parametric class implements a simple dynamic array;
 * resizing must be controlled by the user. No comparison or find
 * operations are implemented.
 */
template<class T>
class ACE_Array_Base
{
public:

  // Define a "trait"
  typedef T TYPE;
  typedef ACE_Array_Iterator<T> ITERATOR;

  // = Initialization and termination methods.

  /// Dynamically create an uninitialized array.
  ACE_Array_Base (size_t size = 0,
                  ACE_Allocator *alloc = 0);

  /// Dynamically initialize the entire array to the <default_value>.
  ACE_Array_Base (size_t size,
                  const T &default_value,
                  ACE_Allocator *alloc = 0);

  /**
   * The copy constructor performs initialization by making an exact
   * copy of the contents of parameter <s>, i.e., *this == s will
   * return true.
   */
  ACE_Array_Base (const ACE_Array_Base<T> &s);

  /**
   * Assignment operator performs an assignment by making an exact
   * copy of the contents of parameter <s>, i.e., *this == s will
   * return true.  Note that if the <max_size_> of <array_> is >= than
   * <s.max_size_> we can copy it without reallocating.  However, if
   * <max_size_> is < <s.max_size_> we must delete the <array_>,
   * reallocate a new <array_>, and then copy the contents of <s>.
   */
  void operator= (const ACE_Array_Base<T> &s);

  /// Clean up the array (e.g., delete dynamically allocated memory).
  ~ACE_Array_Base (void);

  // = Set/get methods.

  /// Set item in the array at location <slot>.  Doesn't
  /// perform range checking.
  T &operator [] (size_t slot);

  /// Get item in the array at location <slot>.  Doesn't
  /// perform range checking.
  const T &operator [] (size_t slot) const;

  /// Set an item in the array at location <slot>.  Returns
  /// -1 if <slot> is not in range, else returns 0.
  int set (const T &new_item, size_t slot);

  /**
   * Get an item in the array at location <slot>.  Returns -1 if
   * <slot> is not in range, else returns 0.  Note that this function
   * copies the item.  If you want to avoid the copy, you can use
   * the const operator [], but then you'll be responsible for range checking.
   */
  int get (T &item, size_t slot) const;

  /// Returns the <cur_size_> of the array.
  size_t size (void) const;

  /**
   * Changes the size of the array to match <new_size>.
   * It copies the old contents into the new array.
   * Return -1 on failure.
   */
  int size (size_t new_size);

  /// Returns the <max_size_> of the array.
  size_t max_size (void) const;

  /**
   * Changes the size of the array to match <new_size>.
   * It copies the old contents into the new array.
   * Return -1 on failure.
   * It does not affect new_size
   */
  int max_size (size_t new_size);

private:
  /// Returns 1 if <slot> is within range, i.e., 0 >= <slot> <
  /// <cur_size_>, else returns 0.
  int in_range (size_t slot) const;

  /// Maximum size of the array, i.e., the total number of <T> elements
  /// in <array_>.
  size_t max_size_;

  /**
   * Current size of the array.  This starts out being == to
   * <max_size_>.  However, if we are assigned a smaller array, then
   * <cur_size_> will become less than <max_size_>.  The purpose of
   * keeping track of both sizes is to avoid reallocating memory if we
   * don't have to.
   */
  size_t cur_size_;

  /// Pointer to the array's storage buffer.
  T *array_;

  /// Allocation strategy of the ACE_Array_Base.
  ACE_Allocator *allocator_;

  friend class ACE_Array_Iterator<T>;
};

// ****************************************************************

/**
 * @class ACE_Array
 *
 * @brief Implement a dynamic array class.
 *
 * This class extends ACE_Array_Base, it provides comparison
 * operators.
 */
template <class T>
class ACE_Array : public ACE_Array_Base<T>
{
public:
  // Define a "trait"
  typedef T TYPE;

  typedef ACE_Array_Iterator<T> ITERATOR;

  // = Exceptions.

  // = Initialization and termination methods.

  /// Dynamically create an uninitialized array.
  ACE_Array (size_t size = 0,
             ACE_Allocator* alloc = 0);

  /// Dynamically initialize the entire array to the <default_value>.
  ACE_Array (size_t size,
             const T &default_value,
             ACE_Allocator* alloc = 0);

  /**
   * The copy constructor performs initialization by making an exact
   * copy of the contents of parameter <s>, i.e., *this == s will
   * return true.
   */
  ACE_Array (const ACE_Array<T> &s);

  /**
   * Assignment operator performs an assignment by making an exact
   * copy of the contents of parameter <s>, i.e., *this == s will
   * return true.  Note that if the <max_size_> of <array_> is >= than
   * <s.max_size_> we can copy it without reallocating.  However, if
   * <max_size_> is < <s.max_size_> we must delete the <array_>,
   * reallocate a new <array_>, and then copy the contents of <s>.
   */
  void operator= (const ACE_Array<T> &s);

  // = Compare operators

  /**
   * Compare this array with <s> for equality.  Two arrays are equal
   * if their <size>'s are equal and all the elements from 0 .. <size>
   * are equal.
   */
  int operator== (const ACE_Array<T> &s) const;

  /**
   * Compare this array with <s> for inequality such that <*this> !=
   * <s> is always the complement of the boolean return value of
   * <*this> == <s>.
   */
  int operator!= (const ACE_Array<T> &s) const;
};

/**
 * @class ACE_Array_Iterator
 *
 * @brief Implement an iterator over an ACE_Array.
 *
 * This iterator is safe in the face of array element deletions.
 * But it is NOT safe if the array is resized (via the ACE_Array
 * assignment operator) during iteration.  That would be very
 * odd, and dangerous.
 */
template <class T>
class ACE_Array_Iterator
{
public:
  // = Initialization method.
  ACE_Array_Iterator (ACE_Array_Base<T> &);

  // = Iteration methods.

  /// Pass back the <next_item> that hasn't been seen in the Array.
  /// Returns 0 when all items have been seen, else 1.
  int next (T *&next_item);

  /// Move forward by one element in the Array.  Returns 0 when all the
  /// items in the Array have been seen, else 1.
  int advance (void);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Pointer to the current item in the iteration.
  u_int current_;

  /// Pointer to the Array we're iterating over.
  ACE_Array_Base<T> &array_;
};

#if defined (__ACE_INLINE__)
#include "ace/Containers_T.i"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Containers_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Containers_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include "ace/post.h"
#endif /* ACE_CONTAINERS_T_H */
