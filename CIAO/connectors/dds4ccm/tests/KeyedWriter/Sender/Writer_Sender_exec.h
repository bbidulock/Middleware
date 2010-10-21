// -*- C++ -*-
// $Id$

#ifndef CIAO_WRITER_SENDER_EXEC_AJ8QK5_H_
#define CIAO_WRITER_SENDER_EXEC_AJ8QK5_H_

#include /**/ "ace/pre.h"

#include "Writer_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Sender_exec_export.h"
#include "tao/LocalObject.h"

#include <map>

namespace CIAO_Writer_Sender_Impl
{
  class Sender_exec_i;

  enum WRITER_ASSIGNMENT {
    WRITE_NONE,
    WRITE_KEYED,
    WRITE_MULTI
  };

  //============================================================
  // pulse_Generator
  //============================================================
  class pulse_Generator :
    public ACE_Event_Handler
  {
  public:
    pulse_Generator (Sender_exec_i &callback);
    /// Handle the timeout.
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
  private:
    /// Maintains a handle that actually process the event
    Sender_exec_i &pulse_callback_;
  };

  class SENDER_EXEC_Export Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::CORBA::UShort
    rate (void);

    virtual void
    rate (
      ::CORBA::UShort rate);

    virtual ::CORBA::UShort
    iterations (void);

    virtual void
    iterations (
      ::CORBA::UShort iterations);

    virtual ::CORBA::UShort
    keys (void);

    virtual void
    keys (
      ::CORBA::UShort keys);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    void tick ();

  private:
    void start (void);
    void stop (void);

    pulse_Generator * ticker_;
    ::Writer::CCM_Sender_Context_var ciao_context_;

    ::CORBA::UShort rate_;

    ::CORBA::UShort iterations_;

    ::CORBA::UShort keys_;
    WRITER_ASSIGNMENT assignment_;
    CORBA::Long last_iteration_;

    void reset_iterations ();
    void register_handles ();
    void unregister_handles ();
    void start_new_assignment (
        WRITER_ASSIGNMENT assignment);
    void write_keyed ();
    void write_many ();

    TAO_SYNCH_MUTEX mutex_;
    typedef std::map<ACE_CString, WriterTest_var> Writer_Table;
    Writer_Table ktests_;

    typedef std::map<ACE_CString, ::DDS::InstanceHandle_t> Writer_Table_Handles;
    Writer_Table_Handles handles_;

    Writer_Table::iterator last_key_;

    ACE_Reactor* reactor (void);
  };

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Writer_Sender_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
