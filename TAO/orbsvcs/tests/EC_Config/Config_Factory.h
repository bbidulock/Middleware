/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = FILENAME
//   Config_Factory
//
// = AUTHOR
//   Bryan Thrall (thrall@cse.wustl.edu)
//
// ============================================================================

#ifndef CONFIGFACTORY_H
#define CONFIGFACTORY_H

#include "TestConfig.h"
#include "ace/Service_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace ConfigFactory {

/**
 * @class Config_Factory
 *
 * @brief Abstract base factory for Test Configurators.
 *
 * Defines the Config_Factory interface.
 *
 * <H2>Memory Management</H2>
 * The objects it creates are owned by this class, the client must
 * invoke the corresponding destroy() method to release them.
 */
class Config_Factory : ACE_Service_Object
{
public:
  ///Constructor
  Config_Factory (void) {}

  ///Destructor
  virtual ~Config_Factory (void);

  /// Create and destroy the TestConfig module.
  virtual TestConfig::Test_Config* create_testconfig ()       = 0;
  virtual void destroy_testconfig (TestConfig::Test_Config *) = 0;

};

/** Enumerates the different scheduling strategies certain
 *  Test_Configs generated by Config_Factories can use.
 */
enum Sched_Type {
  RMS,
  MUF,
  EDF,
  RMSMLF,
  MIF
};

/**
 * @class Default_Config_Factory
 *
 * @brief A generic factory for TestConfigs.
 *
 * This class allows the user to experiment with different TestConfig
 * implementations.  Using a command-line like interface the user
 * can specify which strategies will this factory generate.
 * Since the class can be dynamically loaded the strategies can be
 * set in the service configurator file.
 */
class Default_Config_Factory : public Config_Factory
{
public:
  /// Constructor
  Default_Config_Factory (void);

  /// Destructor...
  virtual ~Default_Config_Factory (void);

  /// Helper function to register the default factory into the service
  /// configurator.
  static int init_svcs (void);

  // = The Service_Object entry points
  virtual int init (int argc, ACE_TCHAR* argv[]);
  virtual int fini (void);

  virtual TestConfig::Test_Config* create_testconfig ();

  virtual void destroy_testconfig (TestConfig::Test_Config *);
protected:
  int test_config_;
  Sched_Type sched_type_;
};

} /* namespace ConfigFactory */

//ACE_STATIC_SVC_DECLARE (Default_Config_Factory)
//ACE_FACTORY_DECLARE (TestConfig, Default_Config_Factory)

#endif /* CONFIGFACTORY_H */
