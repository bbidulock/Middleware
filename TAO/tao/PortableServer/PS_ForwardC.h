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
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_PS_FORWARDC_H_
#define _TAO_IDL_ORIG_PS_FORWARDC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "portableserver_export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/OctetSeqC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_PortableServer_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

class TAO_ServantBase;
class TAO_ServantBase_var;
class TAO_RefCountServantBase;
class TAO_Local_ServantBase;
class TAO_POA;
class TAO_DynamicImplementation;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace PortableServer
{
   typedef TAO_ServantBase ServantBase;
   typedef TAO_ServantBase_var ServantBase_var;
   typedef TAO_RefCountServantBase RefCountServantBase;
   typedef ServantBase *Servant;

   typedef TAO_Local_ServantBase LocalServantBase;
   typedef TAO_DynamicImplementation DynamicImplementation;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:435
  
  typedef CORBA::OctetSeq ObjectId;
  typedef CORBA::OctetSeq_var ObjectId_var;
  typedef CORBA::OctetSeq_out ObjectId_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectId;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:603

#if !defined (_PORTABLESERVER_POA__VAR_OUT_CH_)
#define _PORTABLESERVER_POA__VAR_OUT_CH_
  
  class POA;
  typedef POA *POA_ptr;
  
  typedef
    TAO_Objref_Var_T<
        POA
      >
    POA_var;
  
  typedef
    TAO_Objref_Out_T<
        POA
      >
    POA_out;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_interface_fwd/any_op_ch.cpp:65

TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::POA_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::POA_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableServer::POA *&);

// TAO_IDL - Generated from
// be\be_visitor_interface_fwd/cdr_op_ch.cpp:66

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableServer::POA_ptr );
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableServer::POA_ptr &);


// TAO_IDL - Generated from
// be\be_codegen.cpp:958

#if defined (__ACE_INLINE__)
#include "PS_ForwardC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


