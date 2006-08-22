// -*- C++ -*-

//=============================================================================
/**
 *  @file    NIOP_Connector.h
 *
 *  $Id$
 *
 *  NIOP specific connector processing
 *
 *  @author  Johnny Willemsen <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_NIOP_CONNECTOR_H
#define TAO_NIOP_CONNECTOR_H

#include /**/ "ace/pre.h"

#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (TAO_HAS_NIOP) && (TAO_HAS_NIOP != 0)

#include "tao/Strategies/NIOP_Connection_Handler.h"
#include "tao/Transport_Connector.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_Endpoint;
class TAO_NIOP_Endpoint;

// ****************************************************************

/**
 * @class TAO_NIOP_Connector
 *
 * @brief NIOP-specific Connector bridge for pluggable protocols.
 *
 * Concrete instance of the TAO_Connector class.  Responsible
 * for establishing a connection with a server and is called from the
 * Connector_Registory.
 */
class TAO_Strategies_Export TAO_NIOP_Connector : public TAO_Connector
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  TAO_NIOP_Connector (CORBA::Boolean flag = false);

  /// Destructor.
  ~TAO_NIOP_Connector (void);

  /**
   * @name The TAO_Connector Methods
   *
   * Please check the documentation in Transport_Connector.h for details.
   */
  //@{
  int open (TAO_ORB_Core *orb_core);
  int close (void);

  TAO_Profile *create_profile (TAO_InputCDR& cdr);

  virtual int check_prefix (const char *endpoint);

  virtual char object_key_delimiter (void) const;
  //@}

protected:

  /**
   * @name More TAO_Connector Methods
   *
   * Please check the documentation in Transport_Connector.h for details.
   */
  //@{
  int set_validate_endpoint (TAO_Endpoint *ep);

  TAO_Transport *make_connection (TAO::Profile_Transport_Resolver *r,
                                  TAO_Transport_Descriptor_Interface &desc,
                                  ACE_Time_Value *timeout = 0);

  virtual TAO_Profile * make_profile (ACE_ENV_SINGLE_ARG_DECL);
  //@}

  /// Cancel the passed cvs handler from the connector
  int cancel_svc_handler (TAO_Connection_Handler * svc_handler);

protected:

  /// Do we need to use a GIOP_Lite for sending messages?
  CORBA::Boolean lite_flag_;

private:

  /// Return the remote endpoint, a helper function
  TAO_NIOP_Endpoint *remote_endpoint (TAO_Endpoint *ep);
};

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_HAS_NIOP && TAO_HAS_NIOP != 0 */

#include /**/ "ace/post.h"

#endif  /* TAO_NIOP_CONNECTOR_H */
