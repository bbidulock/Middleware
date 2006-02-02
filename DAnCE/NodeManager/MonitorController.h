// $Id$
//---------------------------------------------------------------------------------
/**
 *  @file MonitorController.h
 *
 *  @brief The Monitor Controller class.
 *
 *  This class is invoked by the Nodemanager object and it
 *  in turn loads the proper Monitor which is strategised.
 *
 *  @author Nilabja Roy
 */
//----------------------------------------------------------------------------------
#ifndef MONITOR_CONTROLLER_H
#define MONITOR_CONTROLLER_H

#include "TargetManager/TargetManagerC.h"
#include "ace/Task.h"
#include "ace/Auto_Ptr.h"

#include "ace/Synch_Traits.h"
#include "ace/Synch.h"



/**
 * @namespace CIAO
 *
 * @brief The top level CIAO namespace
 *
 */

namespace CIAO
{

  class MonitorBase;

  /**
   *  @class MonitorController
   *
   *  @brief The Controller class
   *
   *  Acts as a facade to the Monitor
   *  module
   *
   */
  class MonitorController : public ACE_Task_Base
    {
    public:
      /**
       * @function svc.
       * @brief The main function containing the
       * entire activity.
       *
       * This function runs in the context of the
       * thread
       * @return int The status of the function
       */
      int svc (void);
      /**
       * @function terminate.
       * @brief The terminate function
       *
       * This function is called to terminate the
       * thread
       */
      void terminate ();
      
      
      /// The Constructor.
      MonitorController (CORBA::ORB_ptr orb,
                         ::Deployment::Domain& domain,
                         ::Deployment::TargetManager_ptr target
                         );
      
      ~MonitorController ();
    protected:
      
      /**
       * @function terminating.
       * @brief returns the terminating flag
       * @return bool The terminting state of the thread
       */
      bool terminating ();
      
      /// The monitor object
      auto_ptr <MonitorBase>  monitor_;
      
      /// The TargetManagerImpl object
      CIAO::TargetManagerImpl_var target_impl_cmp_;
      
      /// The TargetManager Facet ....
      Deployment::TargetManager_var target_facet_i_;
      
      /// The terminate flag_
      bool terminate_flag_;
      
      //Thread Mutex for synchronizing call
      ACE_SYNCH_MUTEX lock_;
      
      // the ORB pointer ..
      CORBA::ORB_ptr orb_;
      
      /// The initial domain
      ::Deployment::Domain initial_domain_;
    };

} // CIAO
  
#endif
