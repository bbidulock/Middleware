// $Id$

/**
 * @file GPS_exec.h
 *
 * Header file for the actual GPS and GPSHome component
 * implementations.
 *
 * @author Nanbor Wang <nanbor@cse.wustl.edu>
 */

#ifndef GPS_EXEC_H
#define GPS_EXEC_H

#include "GPSEIC.h"
#include "tao/LocalObject.h"

namespace MyImpl
{
  /**
   * @class GPS_exec_impl
   *
   * RateGen executor implementation class.
   */
  class GPS_EXEC_Export GPS_exec_impl :
    public virtual HUDisplay::GPS_Exec,
    public virtual TAO_Local_RefCounted_Object
  {
  public:
    /// Default constructor.
    GPS_exec_impl ();

    /// Default destructor.
    ~GPS_exec_impl ();

    // Operations from HUDisplay::GPS

    virtual HUDisplay::CCM_position_ptr
    get_MyLocation (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void
    push_Refresh (HUDisplay::tick_ptr ev
                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Operations from HUDisplay::position

    virtual CORBA::Long
    posx (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual CORBA::Long
    posy (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (Components::SessionContext_ptr ctx
                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    virtual void
    ccm_activate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    virtual void
    ccm_passivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    virtual void
    ccm_remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));
  protected:
    CORBA::Long positionx_;
    CORBA::Long positiony_;

    /// Copmponent specific context
    HUDisplay::CCM_GPS_Context_var context_;
  };

  /**
   * @class GPSHome_exec_impl
   *
   * GPS home executor implementation class.
   */
  class GPS_EXEC_Export GPSHome_exec_impl :
    public virtual HUDisplay::CCM_GPSHome,
    public virtual TAO_Local_RefCounted_Object
  {
  public:
    /// Default ctor.
    GPSHome_exec_impl ();

    /// Default dtor.
    ~GPSHome_exec_impl ();

    // Explicit home operations.

    // Implicit home operations.

    virtual ::Components::EnterpriseComponent_ptr
    create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CreateFailure));
  };

}

extern "C" GPS_EXEC_Export ::Components::HomeExecutorBase_ptr
createGPSHome_Impl (void);

#endif /* GPS_EXEC_H */
