// $Id$

// Timer_Hash.cpp

#if !defined (ACE_TIMER_HASH_C)
#define ACE_TIMER_HASH_C

#define ACE_BUILD_DLL

#include "ace/config.h"
#include "ace/Timer_Hash.h"

#if defined (ACE_TEMPLATES_REQUIRE_SPECIALIZATION)
template class ACE_Free_List<ACE_Timer_Node_T<ACE_Event_Handler *> >;
template class ACE_Locked_Free_List<ACE_Timer_Node_T<ACE_Event_Handler *>,
                                    ACE_Null_Mutex>;
template class ACE_Timer_Hash_Upcall <ACE_Event_Handler *, 
                                      ACE_Event_Handler_Handle_Timeout_Upcall<ACE_SYNCH_RECURSIVE_MUTEX>,
                                      ACE_SYNCH_RECURSIVE_MUTEX>;

template class ACE_Timer_Queue_T <ACE_Event_Handler *,
                                  ACE_Hash_Upcall,
                                  ACE_Null_Mutex>;

template class ACE_Timer_Queue_Iterator_T <ACE_Event_Handler *,
                                           ACE_Hash_Upcall,
                                           ACE_Null_Mutex>;

template class ACE_Timer_List_T <ACE_Event_Handler *, 
                                 ACE_Hash_Upcall,
                                 ACE_Null_Mutex>;

template class ACE_Timer_List_Iterator_T <ACE_Event_Handler *,
                                          ACE_Hash_Upcall,
                                          ACE_Null_Mutex>;

template class ACE_Timer_Heap_T <ACE_Event_Handler *, 
                                 ACE_Hash_Upcall,
                                 ACE_Null_Mutex>;

template class ACE_Timer_Heap_Iterator_T <ACE_Event_Handler *,
                                          ACE_Hash_Upcall,
                                          ACE_Null_Mutex>;

template class ACE_Timer_Hash_T<ACE_Event_Handler *, 
                        ACE_Event_Handler_Handle_Timeout_Upcall<ACE_SYNCH_RECURSIVE_MUTEX>, 
                        ACE_SYNCH_RECURSIVE_MUTEX,
                        ACE_Hash_Timer_List>;

template class ACE_Timer_Hash_Iterator_T<ACE_Event_Handler *, 
                                  ACE_Event_Handler_Handle_Timeout_Upcall<ACE_SYNCH_RECURSIVE_MUTEX>, 
                                  ACE_SYNCH_RECURSIVE_MUTEX,
                                  ACE_Hash_Timer_List>;

template class ACE_Timer_Hash_T<ACE_Event_Handler *, 
                        ACE_Event_Handler_Handle_Timeout_Upcall<ACE_SYNCH_RECURSIVE_MUTEX>, 
                        ACE_SYNCH_RECURSIVE_MUTEX,
                        ACE_Hash_Timer_Heap>;

template class ACE_Timer_Hash_Iterator_T<ACE_Event_Handler *, 
                                  ACE_Event_Handler_Handle_Timeout_Upcall<ACE_SYNCH_RECURSIVE_MUTEX>, 
                                  ACE_SYNCH_RECURSIVE_MUTEX,
                                  ACE_Hash_Timer_Heap>;

#endif /* ACE_TEMPLATES_REQUIRE_SPECIALIZATION */

#endif /* ACE_TIMER_HASH_C */
