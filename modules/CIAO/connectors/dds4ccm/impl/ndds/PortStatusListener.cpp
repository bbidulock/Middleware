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
// be/be_codegen.cpp:1422

#include "PortStatusListener.h"

// Implementation skeleton constructor
CCM_DDS_PortStatusListener_i::CCM_DDS_PortStatusListener_i (void)
{
}

// Implementation skeleton destructor
CCM_DDS_PortStatusListener_i::~CCM_DDS_PortStatusListener_i (void)
{
}

void CCM_DDS_PortStatusListener_i::on_requested_deadline_missed (
  ::DDS::DataReader_ptr the_reader,
  const ::DDS::RequestedDeadlineMissedStatus & status)
{
  // Add your implementation here
}

void CCM_DDS_PortStatusListener_i::on_sample_lost (
  ::DDS::DataReader_ptr the_reader,
  const ::DDS::SampleLostStatus & status)
{
  // Add your implementation here
}


