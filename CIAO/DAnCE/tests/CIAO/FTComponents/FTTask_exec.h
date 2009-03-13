// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#ifndef CIAO_FTTASK_EXEC_H
#define CIAO_FTTASK_EXEC_H

#include /**/ "ace/pre.h"

#include "FTTaskEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "FTTask_exec_export.h"
#include "tao/LocalObject.h"
#include "CPU/CPU_Worker.h"
#include "Failure_Task.h"

namespace CIDL_FTTask_Impl
{
  class FTTASK_EXEC_Export FTTask_exec_i
    : public virtual DeCoRAMProvider_Exec,
      public virtual ::CORBA::LocalObject
        {
    public:
    FTTask_exec_i (void);
    virtual ~FTTask_exec_i (void);

    // Supported or inherited operations.

    virtual void
    run_task (
      ::CORBA::Double execution_time);

    virtual void stop (void);

    virtual void
    set_state (
      const ::CORBA::Any & state_value);

    virtual ::CORBA::Any *
    get_state ();

    virtual ::StateSynchronizationAgent_ptr
    agent ();

    virtual void
    agent (::StateSynchronizationAgent_ptr agent);

    virtual char *
    object_id ();

    virtual void
    object_id (const char * object_id);

    // Attribute operations.

    virtual ::CORBA::Object_ptr
    COMPONENT_REFERENCE ();

    virtual void
    COMPONENT_REFERENCE (::CORBA::Object_ptr COMPONENT_REFERENCE);

    virtual CORBA::Double 
    load ();
    
    virtual void 
    load (CORBA::Double load);

    virtual ::CORBA::Short
    role ();

    virtual void
    role (::CORBA::Short role);

    virtual CORBA::Long 
    failure_count (void);
    
    virtual void 
    failure_count (CORBA::Long failure_count);

    // Port operations.

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete ();

    virtual void ccm_activate ();

    virtual void ccm_passivate ();

    virtual void ccm_remove ();

    private:
    /// helper function to find out about the hostname
    std::string get_hostname ();

    /// helper function to find out about the process id of the
    /// application
    std::string get_process_id ();

    // member variables

    CORBA::ORB_var orb_;

    StateSynchronizationAgent_var agent_;

    DeCoRAM::CCM_FTTask_Context_var context_;

    CORBA::Object_var myself_;

    CUTS_CPU_Worker cpu_;

    std::string object_id_;

    CORBA::Double load_;

    bool primary_;

    long state_;

    long suicidal_count_;

    Failure_Task task_;
  };

  extern "C" FTTASK_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_DeCoRAM_FTTask_Impl (void);

  class FTTASK_EXEC_Export FTTaskHome_exec_i
    : public virtual FTTaskHome_Exec,
      public virtual ::CORBA::LocalObject
  {
    public:
    FTTaskHome_exec_i (void);
    virtual ~FTTaskHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" FTTASK_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_DeCoRAM_FTTaskHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_FTTASK_EXEC_H */

