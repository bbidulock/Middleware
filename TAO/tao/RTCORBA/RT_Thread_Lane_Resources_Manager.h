//=============================================================================
/**
 *  @file    RT_Thread_Lane_Resources_Manager.h
 *
 *  $Id$
 *
 *  @author  Irfan Pyarali
 */
// ===================================================================

#ifndef TAO_RT_THREAD_LANE_RESOURCES_MANAGER_H
#define TAO_RT_THREAD_LANE_RESOURCES_MANAGER_H

#include "ace/pre.h"
#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/RTCORBA/rtcorba_export.h"
#include "tao/Thread_Lane_Resources_Manager.h"
#include "ace/Service_Config.h"

class TAO_Thread_Pool_Manager;

/**
 * @class TAO_RT_Thread_Lane_Resources_Manager
 *
 * @brief Manager for thread lane resources.
 *
 * \nosubgrouping
 *
 **/
class TAO_RTCORBA_Export TAO_RT_Thread_Lane_Resources_Manager :
  public TAO_Thread_Lane_Resources_Manager
{
public:

  /// Constructor.
  TAO_RT_Thread_Lane_Resources_Manager (TAO_ORB_Core &orb_core);

  /// Destructor.
  ~TAO_RT_Thread_Lane_Resources_Manager (void);

  /// Finalize resources.
  void finalize (void);

  /// Open default resources.
  int open_default_resources (CORBA_Environment &ACE_TRY_ENV);

  /// Shutdown all reactors.
  int shutdown_all_reactors (CORBA_Environment &ACE_TRY_ENV);

  /// @name Accessors
  // @{

  TAO_Thread_Lane_Resources &lane_resources (void);

  TAO_Thread_Lane_Resources &default_lane_resources (void);

  TAO_Thread_Pool_Manager &tp_manager (void);

  // @}

protected:

  /// Shutdown reactors.
  int shutdown_reactors (TAO_Thread_Lane_Resources &lane_resources,
                         CORBA_Environment &ACE_TRY_ENV);

  /// Mutual exclusion for calling open.
  TAO_SYNCH_MUTEX open_lock_;

  /// Flag which denotes that the open method was called.
  int open_called_;

  /// Default lane resources.
  TAO_Thread_Lane_Resources *default_lane_resources_;

  /// Thread Pool Manager.
  TAO_Thread_Pool_Manager *tp_manager_;
};

/**
 * @class TAO_RT_Thread_Lane_Resources_Manager_Factory
 *
 * @brief This class is a factory for managers of thread resources.
 *
 * \nosubgrouping
 *
 **/
class TAO_RTCORBA_Export TAO_RT_Thread_Lane_Resources_Manager_Factory
  : public TAO_Thread_Lane_Resources_Manager_Factory
{
public:

  /// Factory method.
  TAO_Thread_Lane_Resources_Manager *create_thread_lane_resources_manager (TAO_ORB_Core &core);

};

ACE_STATIC_SVC_DECLARE_EXPORT (TAO_RTCORBA, TAO_RT_Thread_Lane_Resources_Manager_Factory)
ACE_FACTORY_DECLARE (TAO_RTCORBA, TAO_RT_Thread_Lane_Resources_Manager_Factory)

#if defined (__ACE_INLINE__)
# include "tao/RTCORBA/RT_Thread_Lane_Resources_Manager.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"

#endif /* TAO_RT_THREAD_LANE_RESOURCES_MANAGER_H */
