// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/examples/Simple/grid
//
// = FILENAME
//    Grid_i.h
//
// = DESCRIPTION
//    This class implements the Grid IDL interface.
//
// = AUTHOR
//
// ============================================================================

#ifndef GRID_I_H
#define GRID_I_H

#include "GridS.h"
#include "ace/OS.h"
#include "ace/Memory_Pool.h"
#include "ace/Null_Mutex.h"
#include "ace/Malloc_T.h"

typedef ACE_Malloc<ACE_MMAP_MEMORY_POOL, ACE_Null_Mutex> pool_t;
// Memory pool for the persistent stuff

//class Grid_Factory_i;
class Grid_Factory_i : public POA_Grid_Factory
{
  // =TITLE
  //   Create a <Grid>.
public:
  // = Initialization and termination methods.
  Grid_Factory_i (void);
  // Constructor.

  ~Grid_Factory_i (void);
  // Destructor.

  virtual Grid_ptr make_grid (CORBA::Short,
                              CORBA::Short)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // This function creates and returns a <Grid>.

  virtual void shutdown (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Shutdown the server.

  virtual void cleanup ( )
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Do a clean up of the memory map

  void orb (CORBA::ORB_ptr o);
  // Set the ORB pointer.

  void pool_name (const char *name);
  // Set the pool pointer

private:
  CORBA::ORB_var orb_;
  // ORB pointer.

  char *pool_name_;
  // Name of the pool

  pool_t *pool_t_;
  // Hold the pool of name pool_name_

  ACE_UNIMPLEMENTED_FUNC (void operator= (const Grid_Factory_i &))
  // Keeping g++2.7.2
};


class Grid_i: public POA_Grid
{
  // = TITLE
  //    Grid object implementation.
  //
  // = DESCRIPTION
  //    Grid object implementation
public:
  // = Initialization and termination methods.

  Grid_i (void);
  // Constructor

  Grid_i (CORBA::Short,
          CORBA::Short,
          pool_t *);

  // Constructor.

  ~Grid_i (void);
  // Destructor

  virtual CORBA::Short width (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Returns the width of the grid

  virtual CORBA::Short height (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Returns the height of the grid

  virtual void width (CORBA::Short)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Sets the width of the grid.

  virtual void height (CORBA::Short)
     ACE_THROW_SPEC ((CORBA::SystemException));
  // Sets the height of the grid.

  virtual void set (CORBA::Short,
                    CORBA::Short,
                    CORBA::Long)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Grid::RANGE_ERROR));
  // Sets the grid value.

  virtual CORBA::Long get (CORBA::Short,
                           CORBA::Short)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Grid::RANGE_ERROR));
  // Gets the grid value.

  virtual void destroy (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Destroy the grid.

  void set_pool (pool_t *);
  // Set a pointer to the pool

private:
  CORBA::Short width_;
  // Width of the grid.

  CORBA::Short height_;
  // Height of the grid.

  CORBA::Long **array_;
  // Pointer to the matrix.  This is organized as an "array of arrays."

  pool_t *pool_t_;
  //Pointer to the memory pool..
};


#endif /* GRID_I_H */
