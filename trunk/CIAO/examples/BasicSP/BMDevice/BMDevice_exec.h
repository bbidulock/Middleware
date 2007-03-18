// $Id$

// ================================================================
/**
 * @file BMDevice_exec.h
 *
 * Header file for the actual BMDevice and BMDeviceHome component
 * implementations.  These classes are the implementations of local
 * interfaces defined in BMDeviceEI.idl.
 *
 * @author Balachandran Natarajan <bala@dre.vanderbilt.edu>
 */
// ================================================================

#ifndef CIAO_BMDEVICE_EXEC_H
#define CIAO_BMDEVICE_EXEC_H

#include "BMDeviceEIC.h"
#include "tao/LocalObject.h"

namespace MyImpl
{
  /**
   * @class BMDEVICE_exec_i
   *
   * An example RateGen executor implementation class.
   */
  class BMDEVICE_EXEC_Export BMDevice_exec_i :
    public virtual BasicSP::BMDevice_Exec,
    public virtual TAO_Local_RefCounted_Object
  {
  public:
    /// Default constructor.
    BMDevice_exec_i ();

    /// Default destructor.
    ~BMDevice_exec_i ();

    // Operations from BasicSP::BMDevice

    virtual BasicSP::CCM_ReadData_ptr
    get_data_read ();

    virtual void
    push_timeout (BasicSP::TimeOut *ev);

    // Operations from BasicSP::position

    virtual char *
    data_read ();

    virtual char *
    get_data ();

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (Components::SessionContext_ptr ctx);

    virtual void
    ciao_preactivate ();

    virtual void
    ccm_activate ();
    virtual void
    ciao_postactivate ();


    virtual void
    ccm_passivate ();

    virtual void
    ccm_remove ();
  protected:
    const char *str_;

   /// Copmponent specific context
    BasicSP::CCM_BMDevice_Context_var context_;
  };

  /**
   * @class BMDeviceHome_exec_i
   *
   * BMDevice home executor implementation class.
   */
  class BMDEVICE_EXEC_Export BMDeviceHome_exec_i :
    public virtual BasicSP::CCM_BMDeviceHome,
    public virtual TAO_Local_RefCounted_Object
  {
  public:
    /// Default ctor.
    BMDeviceHome_exec_i ();

    /// Default dtor.
    ~BMDeviceHome_exec_i ();

    // Explicit home operations.

    // Implicit home operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

}

// Executor DLL entry point.  CIAO's deployment and assembly framework
// invokes this function on the resulting DLL to get the home executor.
extern "C" BMDEVICE_EXEC_Export ::Components::HomeExecutorBase_ptr
createBMDeviceHome_Impl (void);

#endif /* CIAO_BMDEVICE_EXEC_H*/
