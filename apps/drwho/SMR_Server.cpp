// $Id$
#include "Options.h"
#include "SMR_Server.h"

#ifndef __OPTIMIZE__
SMR_Server::SMR_Server (short port_number)
{
  if (CM_Server::open (port_number) < 0)
    perror (Options::program_name), exit (1);
}

SMR_Server::~SMR_Server (void)
{}
#endif /* __OPTIMIZE__ */
