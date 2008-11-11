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

#ifndef CIAO_SIMPLEFT_EXEC_H
#define CIAO_SIMPLEFT_EXEC_H

#include /**/ "ace/pre.h"

#include "SimpleFTEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "SimpleFT_exec_export.h"
#include "tao/LocalObject.h"
#include "StateSynchronizationAgentC.h"
#include "ace/Sample_History.h"
#include "ace/High_Res_Timer.h"

namespace CIDL_SimpleFT_Impl
{
  class SIMPLEFT_EXEC_Export SimpleFT_exec_i
    : public virtual SimpleProvider_Exec,
      public virtual ::CORBA::LocalObject
  {
    public:
    SimpleFT_exec_i (void);
    virtual ~SimpleFT_exec_i (void);

    // Supported or inherited operations.

    virtual void set_state (const CORBA::Any & state_value);
    
    virtual CORBA::Any * get_state ();

    virtual void method (CORBA::ULong start, CORBA::ULong end, CORBA::ULong work,
			 CORBA::ULong prime_number, CORBA::ULong kill);

    virtual void shutdown (void);

    virtual void dump (void);

    // Attribute operations.

    virtual char * object_id (void);
    
    virtual void object_id (const char * object_id);

    virtual CORBA::Double load ();
    
    virtual void load (CORBA::Double load);
    
    virtual CORBA::Short role ();
    
    virtual void role (CORBA::Short role);

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
    std::string get_hostname ();

    std::string get_process_id ();

    ::Simple::CCM_SimpleFT_Context_var context_;

    // members representing config properties
    
    std::string app_name_;

    CORBA::Double load_;

    bool primary_;

    // members needed for component functionality

    CORBA::ORB_var orb_;

    StateSynchronizationAgent_var agent_;

    ACE_Sample_History history_;

    ACE_hrtime_t start_;

    ACE_hrtime_t end_;

    long state_;
  };

  class SIMPLEFT_EXEC_Export SimpleFTHome_exec_i
    : public virtual SimpleFTHome_Exec,
      public virtual ::CORBA::LocalObject
  {
    public:
    SimpleFTHome_exec_i (void);
    virtual ~SimpleFTHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" SIMPLEFT_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Simple_SimpleFTHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_SIMPLEFT_EXEC_H */

