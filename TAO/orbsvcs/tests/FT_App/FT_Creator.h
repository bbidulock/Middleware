/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    FT_Creator.h
 *
 *  $Id$
 *
 *  This file is part of Fault Tolerant CORBA.
 *  Main wrapped around TAO_Object_Group_Creator
 *
 *  @author Dale Wilson <wilson_d@ociweb.com>
 */
//=============================================================================

#ifndef FT_CREATOR_H
#define FT_CREATOR_H
#include <ace/ACE.h>
#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "TAO_Object_Group_Creator.h"

namespace FTAPP
{
  class FT_Creator
  {
    typedef ACE_Vector<ACE_CString> StringVec;
   public:
    ///////////////////////////
    // construction/destruction
    FT_Creator ();

    ~FT_Creator ();

    /////////////////
    // initialization
    int parse_args (int argc, char *argv[]);

    int init (CORBA::ORB_ptr orb ACE_ENV_ARG_DECL);

    ////////////
    // execution
    int run (ACE_ENV_SINGLE_ARG_DECL);

    ////////////
    // shut down
    int fini ();

    /////////////////
    // implementation
  private:
    void usage (ostream & out)const;

    ////////////////////
    // forbidden methods
   private:
      FT_Creator (const FT_Creator & rhs);
      FT_Creator & operator = (const FT_Creator & rhs);

    ////////////////
    // Data members
   private:

    TAO::Object_Group_Creator creator_;
    CORBA::ORB_var orb_;
    const char * registry_ior_;
    StringVec create_roles_;
    StringVec unregister_roles_;


    CosNaming::NamingContext_var naming_context_;

    ::FT::ReplicationManager_var replication_manager_;
    /**
     * bool: true if we have a real replication manager
     */
    int have_replication_manager_;

    /**
     * bool:  true if we should write individual IOR files
     */
    int write_iors_;

    /**
     * bool:  true if we should write IOGR to a file
     */
    int write_iogr_;

    /**
     * bool:  true if we should write IOGR to a Name Service
     */
    int ns_register_;

    /**
     * sequence number applied to created IOGRs
     */
    unsigned long iogr_seq_;

    /**
     * prefix for names
     */
    const char * prefix_;


  };

} // namespace TAO

#include /**/ "ace/post.h"

#endif // FT_CREATOR_H
