// $Id$

#include "RT_ORB.h"

#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0

#include "RT_Policy_i.h"
#include "RT_Mutex.h"
#include "Priority_Mapping_Manager.h"
#include "tao/ORB_Core.h"
#include "tao/ORB.h"
#include "tao/RTCORBA/Thread_Pool.h"
#include "tao/RTCORBA/RT_Thread_Lane_Resources_Manager.h"
#include "ace/Sched_Params.h"

ACE_RCSID(RTCORBA,
          RT_ORB,
          "$Id$")

TAO_RT_ORB::TAO_RT_ORB (TAO_ORB_Core *orb_core)
  : orb_core_ (orb_core),
    mutex_mgr_ (),
    tp_manager_ (0)
{
  TAO_Thread_Lane_Resources_Manager *thread_lane_resources_manager =
    &this->orb_core_->thread_lane_resources_manager ();

  TAO_RT_Thread_Lane_Resources_Manager *rt_thread_lane_resources_manager =
    (TAO_RT_Thread_Lane_Resources_Manager *) thread_lane_resources_manager;

  this->tp_manager_ =
    &rt_thread_lane_resources_manager->tp_manager ();
}

TAO_RT_ORB::~TAO_RT_ORB (void)
{
}

RTCORBA::Mutex_ptr
TAO_RT_ORB::create_mutex (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->mutex_mgr_.create_mutex (ACE_ENV_SINGLE_ARG_PARAMETER);
}

void
TAO_RT_ORB::destroy_mutex (RTCORBA::Mutex_ptr mutex
                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->mutex_mgr_.destroy_mutex (mutex
                                  ACE_ENV_ARG_PARAMETER);
}


RTCORBA::Mutex_ptr
TAO_RT_ORB::create_named_mutex (const char *name,
                                CORBA::Boolean_out created_flag
                                ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->mutex_mgr_.create_named_mutex (name,
                                              created_flag
                                              ACE_ENV_ARG_PARAMETER);
}

RTCORBA::Mutex_ptr
TAO_RT_ORB::open_named_mutex (const char *name
                              ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   RTCORBA::RTORB::MutexNotFound))
{
  return this->mutex_mgr_.open_named_mutex (name
                                            ACE_ENV_ARG_PARAMETER);
}

////////////////////////////////////////////////////////////////////////////////

TAO_Named_RT_Mutex_Manager::TAO_Named_RT_Mutex_Manager (void)
{
}

TAO_Named_RT_Mutex_Manager::~TAO_Named_RT_Mutex_Manager (void)
{
}

RTCORBA::Mutex_ptr
TAO_Named_RT_Mutex_Manager::create_mutex (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_RT_Mutex *mutex = 0;
  ACE_NEW_THROW_EX (mutex,
                    TAO_RT_Mutex (),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO::VMCID,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::Mutex::_nil ());

  return mutex;
}

// If Named RT_Mutexes aren't enabled, this function is a nop
// as also indicated by the comment below.
#if (TAO_HAS_NAMED_RT_MUTEXES == 1)
void
TAO_Named_RT_Mutex_Manager::destroy_mutex (RTCORBA::Mutex_ptr mutex
                                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_RT_Mutex *tao_mutex =
    ACE_dynamic_cast (TAO_RT_Mutex *,
                      mutex);

  // If this mutex is named, then we need to remove it from our table.
  // Otherwise, we don't have to do anything.
  const char *name = tao_mutex->name ();
  if (name != 0)
    {
      // The following should be atomic.
      ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX,
                          monitor,
                          this->lock_,
                          CORBA::INTERNAL ());
      ACE_CHECK;

      int result =
        this->map_.unbind (name);

      if (result != 0)
        ACE_THROW (CORBA::INTERNAL ());
    }
}
#else /* TAO_HAS_NAMED_RT_MUTEXES == 1 */
void
TAO_Named_RT_Mutex_Manager::destroy_mutex (RTCORBA::Mutex_ptr
                                           ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}
#endif /* TAO_HAS_NAMED_RT_MUTEXES == 1 */

RTCORBA::Mutex_ptr
TAO_Named_RT_Mutex_Manager::create_named_mutex (const char *name,
                                                CORBA::Boolean_out created_flag
                                                ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
#if (TAO_HAS_NAMED_RT_MUTEXES == 1)
  // The following should be atomic.
  ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX,
                      monitor,
                      this->lock_,
                      CORBA::INTERNAL ());
  ACE_CHECK_RETURN (RTCORBA::Mutex::_nil ());

  // Optimistic that we'll find it.
  created_flag = 0;

  // If we find the mutex, simply return it.
  RTCORBA::Mutex_var mutex;
  if (this->map_.find (name,
                       mutex) != 0)
    {
      // Oops, we didn't find it.
      created_flag = 1;

      RTCORBA::Mutex_ptr tmp_mutex;

      // Create a new one.
      ACE_NEW_THROW_EX (tmp_mutex,
                        TAO_Named_RT_Mutex (name),
                        CORBA::NO_MEMORY (
                          CORBA::SystemException::_tao_minor_code (
                            TAO::VMCID,
                            ENOMEM),
                          CORBA::COMPLETED_NO));
      ACE_CHECK_RETURN (RTCORBA::Mutex::_nil ());

      mutex = tmp_mutex;

      // Add it to the map.
      int result =
        this->map_.bind (name,
                         mutex);

      if (result != 0)
        ACE_THROW_RETURN (CORBA::INTERNAL (),
                          RTCORBA::Mutex::_nil ());
    }

  // Return the one we found or created.
  return mutex._retn ();
#else /* TAO_HAS_NAMED_RT_MUTEXES */
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (created_flag);
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (),
                    RTCORBA::Mutex::_nil ());
#endif /* TAO_HAS_NAMED_RT_MUTEXES */
}

RTCORBA::Mutex_ptr
TAO_Named_RT_Mutex_Manager::open_named_mutex (const char *name
                                              ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   RTCORBA::RTORB::MutexNotFound))
{
#if (TAO_HAS_NAMED_RT_MUTEXES == 1)
  // The following should be atomic.
  ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX,
                      monitor,
                      this->lock_,
                      CORBA::INTERNAL ());
  ACE_CHECK_RETURN (RTCORBA::Mutex::_nil ());

  // If we find the mutex, simply return it.
  RTCORBA::Mutex_var mutex;
  if (this->map_.find (name,
                       mutex) != 0)
    ACE_THROW_RETURN (RTCORBA::RTORB::MutexNotFound (),
                      RTCORBA::Mutex::_nil ());

  // Return the one we found.
  return mutex._retn ();
#else /* TAO_HAS_NAMED_RT_MUTEXES */
  ACE_UNUSED_ARG (name);
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (),
                    RTCORBA::Mutex::_nil ());
#endif /* TAO_HAS_NAMED_RT_MUTEXES */
}

///////////////////////////////////////////////////////////////////////////////

RTCORBA::TCPProtocolProperties_ptr
TAO_RT_ORB::create_tcp_protocol_properties (CORBA::Long send_buffer_size,
                                            CORBA::Long recv_buffer_size,
                                            CORBA::Boolean keep_alive,
                                            CORBA::Boolean dont_route,
                                            CORBA::Boolean no_delay,
                                            CORBA::Boolean enable_network_priority
                                            ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException ))
{
  TAO_TCP_Protocol_Properties *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_TCP_Protocol_Properties (send_buffer_size,
                                        recv_buffer_size,
                                        keep_alive,
                                        dont_route,
                                        no_delay,
                                        enable_network_priority),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::TCPProtocolProperties::_nil ());

  return tmp;
}

RTCORBA::UnixDomainProtocolProperties_ptr
TAO_RT_ORB::create_unix_domain_protocol_properties (
                                                    CORBA::Long send_buffer_size,
                                                    CORBA::Long recv_buffer_size
                                                    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_UnixDomain_Protocol_Properties *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_UnixDomain_Protocol_Properties (
                                               send_buffer_size,
                                               recv_buffer_size),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::UnixDomainProtocolProperties::_nil ());

  return tmp;
}

RTCORBA::SharedMemoryProtocolProperties_ptr
TAO_RT_ORB::create_shared_memory_protocol_properties (
                                                      CORBA::Long send_buffer_size,
                                                      CORBA::Long recv_buffer_size,
                                                      CORBA::Boolean keep_alive,
                                                      CORBA::Boolean dont_route,
                                                      CORBA::Boolean no_delay,
                                                      CORBA::Long preallocate_buffer_size,
                                                      const char *mmap_filename,
                                                      const char *mmap_lockname
                                                      ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_SharedMemory_Protocol_Properties *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_SharedMemory_Protocol_Properties (send_buffer_size,
                                                          recv_buffer_size,
                                                          keep_alive,
                                                          dont_route,
                                                          no_delay,
                                                          preallocate_buffer_size,
                                                          mmap_filename,
                                                          mmap_lockname),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::SharedMemoryProtocolProperties::_nil ());

  return tmp;
}

RTCORBA::UserDatagramProtocolProperties_ptr
TAO_RT_ORB::create_user_datagram_protocol_properties (
                                                      CORBA::Boolean enable_network_priority
                                                      ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_UserDatagram_Protocol_Properties *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_UserDatagram_Protocol_Properties (
                                                 enable_network_priority),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::UserDatagramProtocolProperties::_nil ());

  return tmp;
}

RTCORBA::StreamControlProtocolProperties_ptr
TAO_RT_ORB::create_stream_control_protocol_properties (
                                                       CORBA::Long send_buffer_size,
                                                       CORBA::Long recv_buffer_size,
                                                       CORBA::Boolean keep_alive,
                                                       CORBA::Boolean dont_route,
                                                       CORBA::Boolean no_delay,
                                                       CORBA::Boolean enable_network_priority
                                                       ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_StreamControl_Protocol_Properties *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_StreamControl_Protocol_Properties (
                                                  send_buffer_size,
                                                  recv_buffer_size,
                                                  keep_alive,
                                                  dont_route,
                                                  no_delay,
                                                  enable_network_priority),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::StreamControlProtocolProperties::_nil ());

  return tmp;
}

RTCORBA::ThreadpoolId
TAO_RT_ORB::create_threadpool (CORBA::ULong stacksize,
                               CORBA::ULong static_threads,
                               CORBA::ULong dynamic_threads,
                               RTCORBA::Priority default_priority,
                               CORBA::Boolean allow_request_buffering,
                               CORBA::ULong max_buffered_requests,
                               CORBA::ULong max_request_buffer_size
                               ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->tp_manager_->create_threadpool (stacksize,
                                               static_threads,
                                               dynamic_threads,
                                               default_priority,
                                               allow_request_buffering,
                                               max_buffered_requests,
                                               max_request_buffer_size
                                               ACE_ENV_ARG_PARAMETER);
}

RTCORBA::ThreadpoolId
TAO_RT_ORB::create_threadpool_with_lanes (CORBA::ULong stacksize,
                                          const RTCORBA::ThreadpoolLanes &lanes,
                                          CORBA::Boolean allow_borrowing,
                                          CORBA::Boolean allow_request_buffering,
                                          CORBA::ULong max_buffered_requests,
                                          CORBA::ULong max_request_buffer_size
                                          ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->tp_manager_->create_threadpool_with_lanes (stacksize,
                                                          lanes,
                                                          allow_borrowing,
                                                          allow_request_buffering,
                                                          max_buffered_requests,
                                                          max_request_buffer_size
                                                          ACE_ENV_ARG_PARAMETER);
}

void
TAO_RT_ORB::destroy_threadpool (RTCORBA::ThreadpoolId threadpool
                                ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   RTCORBA::RTORB::InvalidThreadpool))
{
  this->tp_manager_->destroy_threadpool (threadpool
                                         ACE_ENV_ARG_PARAMETER);
}

RTCORBA::PriorityModelPolicy_ptr
TAO_RT_ORB::create_priority_model_policy (RTCORBA::PriorityModel priority_model,
                                          RTCORBA::Priority server_priority
                                          ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_PriorityModelPolicy *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_PriorityModelPolicy (priority_model, server_priority),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::PriorityModelPolicy::_nil ());

  return tmp;
}

RTCORBA::ThreadpoolPolicy_ptr
TAO_RT_ORB::create_threadpool_policy (RTCORBA::ThreadpoolId threadpool
                                      ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_ThreadpoolPolicy *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_ThreadpoolPolicy (threadpool),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::ThreadpoolPolicy::_nil ());

  return tmp;
}

RTCORBA::PriorityBandedConnectionPolicy_ptr
TAO_RT_ORB::create_priority_banded_connection_policy (const
                                                      RTCORBA::PriorityBands & priority_bands
                                                      ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_PriorityBandedConnectionPolicy *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_PriorityBandedConnectionPolicy (priority_bands),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::PriorityBandedConnectionPolicy::_nil ());

  return tmp;
}

RTCORBA::PrivateConnectionPolicy_ptr
TAO_RT_ORB::create_private_connection_policy (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_PrivateConnectionPolicy *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_PrivateConnectionPolicy (),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::PrivateConnectionPolicy::_nil ());

  return tmp;
}

RTCORBA::ServerProtocolPolicy_ptr
TAO_RT_ORB::create_server_protocol_policy (const RTCORBA::ProtocolList & protocols
                                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_ServerProtocolPolicy *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_ServerProtocolPolicy (protocols),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::ServerProtocolPolicy::_nil ());

  return tmp;
}

RTCORBA::ClientProtocolPolicy_ptr
TAO_RT_ORB::create_client_protocol_policy (const RTCORBA::ProtocolList & protocols
                                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_ClientProtocolPolicy *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_ClientProtocolPolicy (protocols),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (RTCORBA::ClientProtocolPolicy::_nil ());

  return tmp;
}

TAO_Thread_Pool_Manager &
TAO_RT_ORB::tp_manager (void) const
{
  return *this->tp_manager_;
}

TAO_ORB_Core *
TAO_RT_ORB::orb_core (void) const
{
  return this->orb_core_;
}

/* static */
int
TAO_RT_ORB::modify_thread_scheduling_policy (CORBA::ORB_ptr orb)
{
  //
  // This method changes the scheduling policy of the calling thread
  // to match the scheduling policy specified in the svc.conf file.
  // The priority of the calling thread will be set to the minimum
  // priority supported by that scheduling policy.
  //
  // This method make sense on those platform (e.g., Linux) where
  // PTHREAD_SCOPE_SYSTEM is the only scheduling scope supported.  On
  // other platforms, this method is a no-op since the only way to get
  // the real-time threading behavior is to setup the
  // PTHREAD_SCOPE_SYSTEM scheduling scope when a thread is being
  // created.  On such platforms, one can set the correct scheduling
  // scope and policy when creating the thread, thus not needing to
  // use this method.
  //

#if defined (linux)

  int sched_policy =
    orb->orb_core ()->orb_params ()->ace_sched_policy ();

  int minimum_priority =
    ACE_Sched_Params::priority_min (sched_policy);

  ACE_hthread_t thread_id;
  ACE_Thread::self (thread_id);

  return ACE_Thread::setprio (thread_id,
                              minimum_priority,
                              sched_policy);

#else /* linux */

  ACE_UNUSED_ARG (orb);
  ACE_NOTSUP_RETURN (-1);

#endif /* linux */

}

////////////////////////////////////////////////////////////////////////////////

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if (TAO_HAS_NAMED_RT_MUTEXES == 1)
template class ACE_Hash_Map_Manager_Ex<ACE_CString, RTCORBA::Mutex_var, ACE_Hash<ACE_CString>, ACE_Equal_To<ACE_CString>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Base_Ex<ACE_CString, RTCORBA::Mutex_var, ACE_Hash<ACE_CString>, ACE_Equal_To<ACE_CString>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Ex<ACE_CString, RTCORBA::Mutex_var, ACE_Hash<ACE_CString>, ACE_Equal_To<ACE_CString>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<ACE_CString, RTCORBA::Mutex_var, ACE_Hash<ACE_CString>, ACE_Equal_To<ACE_CString>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Entry<ACE_CString, RTCORBA::Mutex_var>;
#endif /* TAO_HAS_NAMED_RT_MUTEXES == 1 */

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if (TAO_HAS_NAMED_RT_MUTEXES == 1)
#pragma instantiate ACE_Hash_Map_Manager_Ex<ACE_CString, RTCORBA::Mutex_var, ACE_Hash<ACE_CString>, ACE_Equal_To<ACE_CString>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<ACE_CString, RTCORBA::Mutex_var, ACE_Hash<ACE_CString>, ACE_Equal_To<ACE_CString>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<ACE_CString, RTCORBA::Mutex_var, ACE_Hash<ACE_CString>, ACE_Equal_To<ACE_CString>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<ACE_CString, RTCORBA::Mutex_var, ACE_Hash<ACE_CString>, ACE_Equal_To<ACE_CString>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Entry<ACE_CString, RTCORBA::Mutex_var>
#endif /* TAO_HAS_NAMED_RT_MUTEXES == 1 */

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_HAS_CORBA_MESSAGING != 0 */
