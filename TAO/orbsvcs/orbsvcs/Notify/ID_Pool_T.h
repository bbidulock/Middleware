/* -*- C++ -*- */
// $Id$
// ==========================================================================
//
// = LIBRARY
//   orbsvcs
//
// = FILENAME
//   ID_Pool_T.h
//
// = DESCRIPTION
//   A class to generate ID's and recycle them.
//
// = AUTHOR
//    Pradeep Gore <pradeep@cs.wustl.edu>
//
// ==========================================================================

#ifndef ID_POOL_T_H
#define ID_POOL_T_H

template <class ID_TYPE>
class ID_Pool
{
  // = TITLE
  //   ID_Pool
  // = DESCRIPTION
  //   This class is used by factories that need to associate id's with the
  //   objects that they create.When the objects are destroyed, these id's
  //   can be reused, hence the need to recycle.
  //

 public:
  ID_TYPE get (void);
  // Returns a new or recycled ID

  void put (ID_TYPE id);
  // Put an ID back so that it might be recycled.
 private:
  ID_TYPE id_;
};

#endif /* ID_POOL_T_H */
