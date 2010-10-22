// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1584

#ifndef CIAO__________TUTORIAL_CODE_GENERATEDEXEC_HELLO_MYFOO_OBJA_CONN_I_MQE6RN_H_
#define CIAO__________TUTORIAL_CODE_GENERATEDEXEC_HELLO_MYFOO_OBJA_CONN_I_MQE6RN_H_

#include /**/ "ace/pre.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Hello_MyFoo_objAC.h"

namespace CIAO_Hello_AMI4CCM_MyFoo_obj_Connector_AMI4CCM_Connector_Impl
{
  class  AMI4CCM_MyFoo_objReplyHandler_i
    : public ::Hello::AMI4CCM_MyFoo_objReplyHandler
  {
  public:
    AMI4CCM_MyFoo_objReplyHandler_i (void);
    virtual ~AMI4CCM_MyFoo_objReplyHandler_i (void);

    virtual
    void foo (::CORBA::Long ami_return_val,
    const char * answer);

    virtual
    void foo_excep (::CCM_AMI::ExceptionHolder_ptr excep_holder);

    virtual
    void hello (::CORBA::Long answer);

    virtual
    void hello_excep (::CCM_AMI::ExceptionHolder_ptr excep_holder);

    virtual
    void get_rw_attrib (::CORBA::Short rw_attrib);

    virtual
    void get_rw_attrib_excep (::CCM_AMI::ExceptionHolder_ptr excep_holder);

    virtual
    void set_rw_attrib (void);

    virtual
    void set_rw_attrib_excep (::CCM_AMI::ExceptionHolder_ptr excep_holder);

    virtual
    void get_ro_attrib (::CORBA::Short ro_attrib);

    virtual
    void get_ro_attrib_excep (::CCM_AMI::ExceptionHolder_ptr excep_holder);
  };
}

// TAO_IDL - Generated from
// be/be_codegen.cpp:2151


#include /**/ "ace/post.h"

#endif /* ifndef */
