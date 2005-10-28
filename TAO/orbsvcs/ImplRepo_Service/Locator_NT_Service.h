/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   Locator_NT_Service.h
 *
 *  $Id$
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 *  @author Jeff Parsons <parsons@cs.wustl.edu>
 *  @author John Tucker <jtucker@infoglide.com>
 *  @author Mike Vitalo <mvitalo@infoglide.com>
 */
//=============================================================================

#ifndef Locator_NT_Service_H
#define Locator_NT_Service_H

#include "ace/config-all.h"

#if defined (ACE_WIN32)

#include "ace/NT_Service.h"
#include "ace/Singleton.h"
#include "ace/Synch.h"
#include "tao/orbconf.h"

static const ACE_TCHAR * IMR_LOCATOR_SERVICE_NAME = ACE_TEXT("TAOImR");
static const ACE_TCHAR * IMR_LOCATOR_DISPLAY_NAME = ACE_TEXT("TAO Implementation Repository");
static const ACE_TCHAR * IMR_LOCATOR_DESCRIPTION = ACE_TEXT("Implementation Repository Locator service for TAO");

/**
 * @class Locator_NT_Service
 *
 * @brief Allows the Implementation Repository to act as a Windows NT Service.
 */
class Locator_NT_Service : public ACE_NT_Service
{
public:
  typedef TAO_SYNCH_RECURSIVE_MUTEX MUTEX;

  /// We override <handle_control> because it handles stop requests
  /// privately.
  virtual void handle_control (DWORD control_code);

  /// We override <handle_exception> so a 'stop' control code can wake
  /// the reactor off of its wait.
  virtual int handle_exception (ACE_HANDLE h);

  /// This is a virtual method inherited from ACE_NT_Service.
  virtual int svc (void);

private:
  friend class ACE_Singleton<Locator_NT_Service, MUTEX>;
};

typedef ACE_Singleton<Locator_NT_Service, ACE_Mutex> SERVICE;

#endif /* ACE_WIN32 */

#endif /* Locator_NT_Service_H */


