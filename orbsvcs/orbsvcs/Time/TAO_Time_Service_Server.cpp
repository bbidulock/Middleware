// -*- C++ -*-
// $Id$

#include "TAO_UTO.h"
#include "TAO_TIO.h"
#include "TAO_Time_Service_Server.h"

// Constructor.
TAO_Time_Service_Server::TAO_Time_Service_Server (void)
{
}

// Destructor.
TAO_Time_Service_Server::~TAO_Time_Service_Server (void)
{
}

// This method returns the current system time and an estimate of
// inaccuracy in a UTO.

CosTime::UTO_ptr
TAO_Time_Service_Server::universal_time (CORBA::Environment &_env)
{
  TAO_UTO *uto = 0;

  // Return the local time of the system as a UTO.
  ACE_NEW_THROW_RETURN (uto,
			TAO_UTO (CORBA::ULongLong (ACE_OS::gettimeofday ().sec ()),
				 0,
				 0),
			CORBA::NO_MEMORY (CORBA::COMPLETED_NO),
			CosTime::UTO::_nil ());

  return uto->_this ();
}

// This method returns the current time in a UTO only if the time can
// be guaranteed to have been obtained securely.  This method is not
// implemented currently.

CosTime::UTO_ptr
TAO_Time_Service_Server::secure_universal_time (CORBA::Environment &env)
{
  TAO_TRY
    {
      TAO_TRY_ENV.exception (new CORBA::NO_IMPLEMENT (CORBA::COMPLETED_NO));
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Exception:");
    }
  TAO_ENDTRY;

  return 0;
}

// This creates a new UTO based on the given parameters.

CosTime::UTO_ptr
TAO_Time_Service_Server::new_universal_time (TimeBase::TimeT time,
					     TimeBase::InaccuracyT inaccuracy,
					     TimeBase::TdfT tdf,
					     CORBA::Environment &_env)
{
  TAO_UTO *uto = 0;

  ACE_NEW_THROW_RETURN (uto,
			TAO_UTO (time,
				 inaccuracy,
				 tdf),
			CORBA::NO_MEMORY (CORBA::COMPLETED_NO),
			CosTime::UTO::_nil ());

  return uto->_this ();

}

// This creates a new UTO given a time in the UtcT form.

CosTime::UTO_ptr
TAO_Time_Service_Server::uto_from_utc (const TimeBase::UtcT &utc,
				       CORBA::Environment &_env)
{
  TAO_UTO *uto = 0;

  ACE_NEW_THROW_RETURN (uto,
			TAO_UTO (utc.time,
				 utc.inacclo + utc.inacchi,
				 utc.tdf),
			CORBA::NO_MEMORY (CORBA::COMPLETED_NO),
			CosTime::UTO::_nil ());
  return uto->_this ();
}

// This creates a new TIO with the given parameters.

CosTime::TIO_ptr
TAO_Time_Service_Server::new_interval (TimeBase::TimeT lower,
				       TimeBase::TimeT upper,
				       CORBA::Environment &_env)
{
  TAO_TIO *tio = 0;

  ACE_NEW_THROW_RETURN (tio,
			TAO_TIO (lower,
				 upper),
			CORBA::NO_MEMORY (CORBA::COMPLETED_NO),
			CosTime::TIO::_nil ());
  return tio->_this ();
}
