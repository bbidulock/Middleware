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

#ifndef CIAO_FTCLIENT_EXEC_H
#define CIAO_FTCLIENT_EXEC_H

#include /**/ "ace/pre.h"

#include "FTClientEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "FTClient_exec_export.h"
#include "tao/LocalObject.h"
#include "FTClient_Timer_Handler.h"
#include "WorkerC.h"

namespace CIDL_FTClient_Impl
{
  class FTCLIENT_EXEC_Export FTClient_exec_i
    : public virtual SimpleProvider_Exec,
      public virtual ::CORBA::LocalObject
  {
    public:
    FTClient_exec_i (void);
    virtual ~FTClient_exec_i (void);

    // Supported or inherited operations.

    virtual void start (void);

    // Attribute operations.
    virtual ::CORBA::Double
    period (void);

    virtual void
    period (::CORBA::Double period);

    virtual ::CORBA::Double
    execution_time (void);

    virtual void
    execution_time (::CORBA::Double execution_time);

    virtual ::CORBA::ULong
    iterations (void);

    virtual void
    iterations (::CORBA::ULong iterations);

    virtual char *
    server_ior (void);

    virtual void
    server_ior (const char * server_ior);

    virtual char *
    name (void);

    virtual void
    name (const char * name);

    virtual ::CORBA::Object_ptr
    COMPONENT_REFERENCE ();

    virtual void
    COMPONENT_REFERENCE (::CORBA::Object_ptr COMPONENT_REFERENCE);

    // returns the reference to the server
    DeCoRAM::Worker_ptr server (void);
    
    // Port operations.

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);

    virtual void ccm_passivate (void);

    virtual void ccm_remove (void);

    private:
    DeCoRAM::CCM_FTClient_Context_var context_;
    
    // members for attribute implementation
    CORBA::Double period_;

    CORBA::Double execution_time_;

    CORBA::ULong iterations_;

    CORBA::String_var server_ior_;

    std::string name_;

    bool started_;
    
    CORBA::ORB_var orb_;

    CORBA::Object_var myself_;

    // event handler that allows a repeated scheduling 
    // of calls to the server
    FTClient_Timer_Handler timeout_handler_;    
  };

  extern "C" FTCLIENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_DeCoRAM_FTClient_Impl (void);

  class FTCLIENT_EXEC_Export FTClientHome_exec_i
    : public virtual FTClientHome_Exec,
      public virtual ::CORBA::LocalObject
  {
    public:
    FTClientHome_exec_i (void);
    virtual ~FTClientHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };

  extern "C" FTCLIENT_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_DeCoRAM_FTClientHome_Impl (void);
};

#include /**/ "ace/post.h"

#endif /* CIAO_FTCLIENT_EXEC_H */
