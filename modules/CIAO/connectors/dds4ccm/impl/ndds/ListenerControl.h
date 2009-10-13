// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.9 ****
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
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from 
// be/be_codegen.cpp:1364

#ifndef DDS4CCM_LISTNERCONTROLI_H_
#define DDS4CCM_LISTNERCONTROLI_H_

#include "dds4ccm/impl/ndds/dds4ccm_ndds_impl_export.h"
#include "dds4ccm/idl/dds4ccm_ListenerControlEC.h"
#include "tao/LocalObject.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class DDS4CCM_NDDS_IMPL_Export CCM_DDS_ListenerControl_i
  : public virtual CCM_DDS::CCM_ListenerControl,
    public virtual ::CORBA::LocalObject
{
public:
  // Constructor 
  CCM_DDS_ListenerControl_i (ACE_Atomic_Op <TAO_SYNCH_MUTEX, bool> &flag);
  
  // Destructor 
  virtual ~CCM_DDS_ListenerControl_i (void);
  
  virtual ::CORBA::Boolean enabled (void);
  
  virtual void enabled (::CORBA::Boolean enabled);
  
private:
  ACE_Atomic_Op <TAO_SYNCH_MUTEX, bool> &flag_;
};


#endif /* DDS4CCM_LISTNERCONTROLI_H_  */

