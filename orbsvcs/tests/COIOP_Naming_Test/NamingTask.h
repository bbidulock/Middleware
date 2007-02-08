#ifndef NAMINGTASK_H
#define NAMINGTASK_H

#include <tao/corba.h>
#include <ace/Task.h>
#include "orbsvcs/CosNamingC.h"

class NamingTask : public ACE_Task<ACE_MT_SYNCH>
{
public:
  NamingTask (const char* orbname, int argc, char** argv);
  virtual int svc();
  void waitInit ();
  void end();

  CosNaming::NamingContext_ptr root (void) const;

private:
  CORBA::ORB_var orb_;
  bool initialized_;
  CosNaming::NamingContext_var root_;
};

#endif
