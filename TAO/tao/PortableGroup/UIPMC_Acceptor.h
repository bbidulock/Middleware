// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file    UIPMC_Acceptor.h
 *
 *  $Id$
 *
 *  DIOP specific acceptor processing
 *
 *
 *  @author Fred Kuhns <fredk@cs.wustl.edu>
 *  @author Ossama Othman <ossama@uci.edu>
 */
//=============================================================================


#ifndef TAO_UIPMC_ACCEPTOR_H
#define TAO_UIPMC_ACCEPTOR_H
#include "ace/pre.h"

#include "tao/Pluggable.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "UIPMC_Connection_Handler.h"
#include "tao/Acceptor_Impl.h"

#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "tao/GIOP_Message_State.h"
#include "portablegroup_export.h"

// TAO UIPMC_Acceptor concrete call defination

/**
 * @class TAO_UIPMC_Acceptor
 *
 * @brief TAO_UIPMC_Acceptor
 *
 * The UIPMC-specific bridge class for the concrete acceptor.
 */
class TAO_PortableGroup_Export TAO_UIPMC_Acceptor : public TAO_Acceptor
{
public:
  /// Constructor.
  TAO_UIPMC_Acceptor (CORBA::Boolean flag = 0);

  /// Destructor.
  ~TAO_UIPMC_Acceptor (void);

  /// @@ Helper method for the implementation repository, should go
  ///    away
  const ACE_INET_Addr& address (void) const;

  /// Returns the array of endpoints in this acceptor
  const ACE_INET_Addr *endpoints (void);

  /**
   * The TAO_Acceptor methods, check the documentation in
   * Pluggable.h for details.
   */
  virtual int open (TAO_ORB_Core *orb_core,
                    int version_major,
                    int version_minor,
                    const char *address,
                    const char *options = 0);
  virtual int open_default (TAO_ORB_Core *orb_core,
                            int version_major,
                            int version_minor,
                            const char *options = 0);
  virtual int close (void);
  virtual int create_mprofile (const TAO_ObjectKey &object_key,
                               TAO_MProfile &mprofile);
  virtual int is_collocated (const TAO_Endpoint *endpoint);
  virtual CORBA::ULong endpoint_count (void);

  virtual int object_key (IOP::TaggedProfile &profile,
                          TAO_ObjectKey &key);

  /**
   * Set the host name for the given addr.
   * A hostname may be forced by using specified_hostname.  This
   * is useful if the given address corresponds to more than one
   * hostname and the desired one cannot be determined in any
   * other way.
   */
  int hostname (TAO_ORB_Core *orb_core,
                ACE_INET_Addr &addr,
                char *&host,
                const char *specified_hostname = 0);

  /**
   * Set the host name for the given address using the dotted decimal
   * format.
   */
  int dotted_decimal_address (ACE_INET_Addr &addr,
                              char *&host);

protected:

  /**
   * Implement the common part of the open*() methods.  This method is
   * virtual to allow a derived class implementation to be invoked
   * instead.
   */
  virtual int open_i (const ACE_INET_Addr &addr);

  /**
   * Probe the system for available network interfaces, and initialize
   * the <addrs_> array with an ACE_INET_Addr for each network
   * interface.  The port for each initialized ACE_INET_Addr will be
   * set in the open_i() method.  This method only gets invoked when
   * no explicit hostname is provided in the specified endpoint.
   */
  int probe_interfaces (TAO_ORB_Core *orb_core);

  /// Parse protocol specific options.
  virtual int parse_options (const char *options);

  /// Obtain uipmc properties that must be used by this acceptor, i.e.,
  /// initialize <uipmc_properties_>.
  int init_uipmc_properties (void);

protected:

  /// Array of ACE_INET_Addr instances, each one corresponding to a
  /// given network interface.
  ACE_INET_Addr *addrs_;

  /**
   * Cache the information about the endpoints serviced by this
   * acceptor.
   * There may in fact be multiple hostnames for this endpoint. For
   * example, if the IP address is INADDR_ANY (0.0.0.0) then there
   * will be possibly a different hostname for each interface.
   */
  char **hosts_;

  /// The number of host names cached in the hosts_ array (equivalent
  /// to the number of endpoints opened by this Acceptor).
  size_t endpoint_count_;

  /**
   * The GIOP version for this endpoint
   * @@ Theoretically they shouldn't be here!! We need to look at a
   * way to move this out
   */
  TAO_GIOP_Version version_;

  /// ORB Core.
  TAO_ORB_Core *orb_core_;

  /// UIPMC configuration properties to be used for all
  /// connections opened by this acceptor.
  TAO_UIPMC_Properties uipmc_properties_;

private:
  // @@ Frank: From UIPMC_Acceptor.h
  TAO_UIPMC_Connection_Handler *connection_handler_;

};

#if defined(__ACE_INLINE__)
#include "UIPMC_Acceptor.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif  /* TAO_UIPMC_ACCEPTOR_H */
