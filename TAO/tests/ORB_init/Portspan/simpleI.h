// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef SIMPLEI_H_
#define SIMPLEI_H_

#include "simpleS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

//Class simple_i
class  simple_i : public virtual POA_simple
{
public:
  //Constructor
  simple_i (void);

  //Destructor
  virtual ~simple_i (void);

virtual void test (
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

};


#endif /* SIMPLEI_H_  */
