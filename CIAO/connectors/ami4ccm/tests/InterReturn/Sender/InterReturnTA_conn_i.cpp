// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
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
// be/be_codegen.cpp:1661

#include "InterReturnTA_conn_i.h"

namespace CIAO_InterReturnT_Sender_Impl
{
  AMI4CCM_MyFooReplyHandler_i::AMI4CCM_MyFooReplyHandler_i (
      Atomic_UShort &nr_of_received)
  : nr_of_received_(nr_of_received)
  {
  }

  AMI4CCM_MyFooReplyHandler_i::~AMI4CCM_MyFooReplyHandler_i (void)
  {
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_void (const char * /* answer */,
  ::CORBA::Long l_cmd)
  {
    if (l_cmd != 1)
      {
        ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_void: "
                              "received the wrong long, expected 1,"
                              " received %lu\n",
                              l_cmd));
      }
    else
      {
        ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_void_excep (
          ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_long (::CORBA::Long  ami_return_val ,
  const char * /* answer */,
  ::CORBA::Long  l_cmd)
  {
    if ((l_cmd != 2) || (ami_return_val != 200))
          {
            ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_long: "
                                  "received the wrong longs, expected 2 and 200,"
                                  " received %lu and %lu\n",
                                  l_cmd, ami_return_val));
          }
        else
          {
            ++this->nr_of_received_;
          }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_long_excep (
        ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_double (::CORBA::Double  ami_return_val,
                                                 const char * /* answer */,
                                                 ::CORBA::Long l_cmd)
  {
    if ((l_cmd != 3) || (ami_return_val != 3.14))
      {
        ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_double: "
                              "received the wrong returns, expected 3 "
                              "and 3.14,received %u and %2.2f\n",
                              l_cmd, ami_return_val));
      }
    else
      {
        ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_double_excep (
                  ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_struct (
                       const ::InterReturnT::TestStruct &  ami_return_val,
                       const char * /* answer */,
                       ::CORBA::Long l_cmd)
  {
    if (l_cmd != 4)
        {
          ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_struct: "
                                "received the wrong long, expected 4,"
                                " received %u\n",
                                l_cmd));
        }
      else if ((ACE_OS::strcmp (ami_return_val.key.in(), "aaa") != 0) ||
               (ami_return_val.x != 10))
        {
          ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_struct: "
                                "received the struct return, expected 'aaa' "
                                "and 10, received %C and %u\n",
                                ami_return_val.key.in(), ami_return_val.x));
        }
      else
        {
          ++this->nr_of_received_;
        }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_struct_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_array (
                              const ::InterReturnT::TestArray ami_return_val,
                              const char * /* answer */,
                              ::CORBA::Long l_cmd)
  {
    if ((l_cmd != 5) || (ami_return_val[1].x_array[2] != 102))
       {
         ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_array: "
                               "received the wrong long or array, expected 5 "
                               "and 102,received %u and %u\n",
                               l_cmd, ami_return_val[1].x_array[2]));
       }
     else
       {
         ++this->nr_of_received_;
       }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_array_excep (
          ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_seq (
                               const ::InterReturnT::TestSeq & ami_return_val,
                               const char * /* answer */,
                               ::CORBA::Long l_cmd)
  {
    if (l_cmd != 6)
       {
         ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_seq: "
                               "received the wrong long, expected 6,"
                               " received %lu\n",
                               l_cmd));
       }
     else if ((ACE_OS::strcmp (ami_return_val[0].x_teststr, "ccc") != 0) ||
              (ami_return_val[1].x_test != 12))
       {
         ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_seq: "
                               "didn't receive the expected sequence,"
                               " received %C and %lu\n",
                               ami_return_val[0].x_teststr.in(),
                               ami_return_val[1].x_test));
       }
     else
       {
         ++this->nr_of_received_;
       }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_seq_excep (
          ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_union (
                            const ::InterReturnT::X_Union & ami_return_val,
                            const char * /* answer */,
                            ::CORBA::Long l_cmd )
  {
    if ((l_cmd != 7) || (ami_return_val.x_long() != 11))
       {
         ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_union: "
                               "received the wrong long or union, expected 7"
                               " and 11, received %u and %u\n",
                               l_cmd, ami_return_val.x_long()));
       }
     else
       {
         ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_union_excep (
           ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_enum (
                               ::InterReturnT::test_enum ami_return_val,
                               const char * /* answer */,
                               ::CORBA::Long l_cmd)
  {
    if ((l_cmd != 8) || (ami_return_val != InterReturnT::TWO))
        {
          ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::ret_enum: "
                                "received the wrong long or enum value, expected 8"
                                " and TWO, received %u and %u\n",
                                l_cmd, ami_return_val));
        }
      else
        {
          ++this->nr_of_received_;
        }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::ret_enum_excep (
               ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }
}
