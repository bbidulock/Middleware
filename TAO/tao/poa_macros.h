// $Id$

#if !defined (POA_MACROS_H)
#define POA_MACROS_H

#include "tao/try_macros.h"

// Convenient macro for testing for deadlock, as well as for detecting
// when mutexes fail.
#define TAO_POA_WRITE_GUARD(MUTEX,OBJ,LOCK,ENV) \
  TAO_WRITE_GUARD_THROW(MUTEX,OBJ,LOCK,ENV,CORBA::OBJ_ADAPTER (CORBA::COMPLETED_NO))

#define TAO_POA_READ_GUARD(MUTEX,OBJ,LOCK,ENV) \
  TAO_READ_GUARD_THROW(MUTEX,OBJ,LOCK,ENV,CORBA::OBJ_ADAPTER (CORBA::COMPLETED_NO))

#define TAO_POA_WRITE_GUARD_RETURN(MUTEX,OBJ,LOCK,RETURN,ENV) \
  TAO_WRITE_GUARD_THROW_RETURN(MUTEX,OBJ,LOCK,RETURN,ENV,CORBA::OBJ_ADAPTER (CORBA::COMPLETED_NO))
#define TAO_POA_READ_GUARD_RETURN(MUTEX,OBJ,LOCK,RETURN,ENV) \
  TAO_READ_GUARD_THROW_RETURN(MUTEX,OBJ,LOCK,RETURN,ENV,CORBA::OBJ_ADAPTER (CORBA::COMPLETED_NO))

#endif /* POA_MACROS_H */
