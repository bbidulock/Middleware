// -*- C++ -*-

//=============================================================================
/**
 *  @file    TAO_Time_Service_Server.h
 *
 *  $Id$
 *
 *  This class implements the CosTime::TimeService IDL interface.
 *
 *
 *  @author Vishal Kachroo  <vishal@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_TIME_SERVICE_SERVER_H
#define TAO_TIME_SERVICE_SERVER_H
#include /**/ "ace/pre.h"

#include "orbsvcs/TimeServiceS.h"
#include "time_export.h"

/**
 * @class TAO_Time_Service_Server
 *
 * @brief TimeService Object Implementation.
 *
 * The Object implementation implements methods to retrieve
 * current time as well as secure current time. The times are
 * retrieved as UTOs. The object also allows creation of a TIO
 * for a given time interval.  In general, the TimeService
 * manages the UTOs and the TIOs. The notion of time returned
 * here is the local time of the system.
 */
class TAO_Time_Export TAO_Time_Service_Server : public POA_CosTime::TimeService
{

public:
  // = Initialization and termination methods.
  /// Constructor.
  TAO_Time_Service_Server (void);

  /// Destructor.
  ~TAO_Time_Service_Server (void);

  /// This operation returns the current system time and an estimate of
  /// inaccuracy in a UTO.
  virtual CosTime::UTO_ptr universal_time (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     CosTime::TimeUnavailable));

  /**
   * This operation returns the current time in a UTO only if the time
   * can be guaranteed to have been obtained securely. Currently this operation
   * is not implemented and throws a CORBA::NO_IMPLEMENT exception, if called.
   */
  virtual CosTime::UTO_ptr secure_universal_time (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     CosTime::TimeUnavailable));

  /// This creates a new UTO based on the given parameters.
  virtual CosTime::UTO_ptr new_universal_time (TimeBase::TimeT time,
                                               TimeBase::InaccuracyT inaccuracy,
                                               TimeBase::TdfT tdf
                                               ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// This creates a new UTO given a time in the UtcT form.
  virtual CosTime::UTO_ptr uto_from_utc (const TimeBase::UtcT &utc
                                         ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// This creates a new TIO with the given parameters.
  virtual CosTime::TIO_ptr new_interval (TimeBase::TimeT lower,
                                         TimeBase::TimeT upper
                                         ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

};

#include /**/ "ace/post.h"
#endif /* TAO_TIME_SERVICE_SERVER_H */
