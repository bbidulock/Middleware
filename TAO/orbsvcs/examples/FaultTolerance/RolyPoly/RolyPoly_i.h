// file      : RolyPoly/RolyPoly_i.h
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef ROLY_POLY_I_H
#define ROLY_POLY_I_H

#include "RolyPolyS.h"
#include "StateUpdate.h"

class RolyPoly_i : public virtual POA_RolyPoly,
                   public virtual Checkpointable
{
public:
  RolyPoly_i (CORBA::ORB_ptr orb);

  ~RolyPoly_i (void);

  // Checkpointable
  //
  virtual CORBA::Any*
  get_state ();

  virtual void
  set_state (CORBA::Any const& state);


  // RolyPoly
  //
  virtual CORBA::Short
  number (char *&s ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void
  shutdown (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  CORBA::Short number_;

  CORBA::ORB_var orb_;
};

#endif  /* ROLY_POLY_I_H */
