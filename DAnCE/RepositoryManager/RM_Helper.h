
/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    RM_Helper.h
 *
 *  $Id$
 *
 *  This class aggregates a number of helper functions used by the
 *  CIAO RepositoryManager
 *
 *
 *  @author Stoyan Paunov
 */
//=============================================================================

#ifndef RM_HELPER_H_
#define RM_HELPER_H_


#include "ciao/Packaging_DataC.h"    //for the PackageConfiguration declaration
#include "tao/CDR.h"                 //for TAO CDR classes
#include "ace/Message_Block.h"      //for ACE_Message_Block

//int operator<< (ACE_OutputCDR& cdr, const Deployment::PackageConfiguration& pc);
//int operator>> (ACE_InputCDR& cdr, Deployment::PackageConfiguration& pc);
//Similar operators are generated by the IDL compiler
//
//Do search for "Deployment::PackageConfiguration &" in Packaging_DataC.cpp
//
//::CORBA::Boolean operator<< (
//    TAO_OutputCDR &strm,
//    const Deployment::PackageConfiguration &_tao_aggregate
//
//::CORBA::Boolean operator>> (
//    TAO_InputCDR &strm,
//    Deployment::PackageConfiguration &_tao_aggregate
//  )


class RM_Helper
{
public:

  static void pc_to_cdr (const Deployment::PackageConfiguration& pc, TAO_OutputCDR& cdr);

  static void cdr_to_pc (Deployment::PackageConfiguration& pc, TAO_InputCDR& cdr);

  static bool externalize (const Deployment::PackageConfiguration& pc, const char* path);

  static bool reincarnate (Deployment::PackageConfiguration& pc, const char* path);

  ///function that writes out a file to a specified location on the hard disk
  ///returns 1 on success
  ///       0 on error

  static bool write_to_disk (const char* full_path,
                   const CORBA::Octet* buffer,
                 size_t length
                 );


  ///function that writes out a file to a specified location on the hand disk
  ///returns 1 on success
  ///       0 on already exists and replace == false
  ///       0 on error

  static bool write_to_disk (const char* full_path,
                 ACE_Message_Block& mb,
                 bool replace = true
                 );

  ///function that writes out a file to a specified location on the hand disk
  ///returns 1 on success
  ///       0 on already exists and replace == false
  ///       0 on error
  ///
  ///NOTE: This function is relevant for PackageConfigurations ONLY

  static bool write_pc_to_disk (const char* full_path,
                  ACE_Message_Block& mb,
                  bool replace = true
                 );

  ///function to read the contents of a file from disk into a CORBA::OctetSeq
  ///returns a pointer to a CORBA::Octet buffer and updates the lenght on success
  ///     0 on failure

  static CORBA::Octet* read_from_disk (const char* full_path, size_t &length);

  ///function to read the contents of a file from disk into an ACE_Message_Block
  ///returns a pointer to an ACE_Message_Block and updates the lenght on success
  ///     0 on failure


  static ACE_Message_Block* read_pc_from_disk (const char* full_path, size_t &length);

};

#endif
