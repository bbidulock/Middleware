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

#include "ServantManagerC.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

#if (TAO_HAS_MINIMUM_POA == 0)

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_ServantManager[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  46,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f53), 
  ACE_NTOHL (0x65727661), 
  ACE_NTOHL (0x6e744d61), 
  ACE_NTOHL (0x6e616765), 
  ACE_NTOHL (0x723a322e), 
  ACE_NTOHL (0x33000000),  // repository ID = IDL:omg.org/PortableServer/ServantManager:2.3
    15,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x616e744d), 
  ACE_NTOHL (0x616e6167), 
  ACE_NTOHL (0x65720000),  // name = ServantManager
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_ServantManager (
    CORBA::tk_objref,
    sizeof (_oc_PortableServer_ServantManager),
    (char *) &_oc_PortableServer_ServantManager,
    0,
    sizeof (PortableServer::ServantManager)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_ServantManager =
    &_tc_TAO_tc_PortableServer_ServantManager;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_ForwardRequest[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  46,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f46), 
  ACE_NTOHL (0x6f727761), 
  ACE_NTOHL (0x72645265), 
  ACE_NTOHL (0x71756573), 
  ACE_NTOHL (0x743a322e), 
  ACE_NTOHL (0x33000000),  // repository ID = IDL:omg.org/PortableServer/ForwardRequest:2.3
    15,
  ACE_NTOHL (0x466f7277), 
  ACE_NTOHL (0x61726452), 
  ACE_NTOHL (0x65717565), 
  ACE_NTOHL (0x73740000),  // name = ForwardRequest
  1, // member count
    18,
  ACE_NTOHL (0x666f7277), 
  ACE_NTOHL (0x6172645f), 
  ACE_NTOHL (0x72656665), 
  ACE_NTOHL (0x72656e63), 
  ACE_NTOHL (0x65000000),  // name = forward_reference
    CORBA::tk_objref,
  52, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    29,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f4f62), 
    ACE_NTOHL (0x6a656374), 
    ACE_NTOHL (0x3a312e30), 
    ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/Object:1.0
        7,
    ACE_NTOHL (0x4f626a65), 
    ACE_NTOHL (0x63740000),  // name = Object
    
};

static CORBA::TypeCode _tc_TAO_tc_PortableServer_ForwardRequest (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_ForwardRequest),
    (char *) &_oc_PortableServer_ForwardRequest,
    0,
    sizeof (PortableServer::ForwardRequest)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_ForwardRequest =
    &_tc_TAO_tc_PortableServer_ForwardRequest;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantManager>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantManager>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantManager>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantManager_ptr _tao_elem
  )
{
  PortableServer::ServantManager_ptr _tao_objptr =
    PortableServer::ServantManager::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantManager_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::ServantManager>::insert (
      _tao_any,
      PortableServer::ServantManager::_tao_any_destructor,
      PortableServer::_tc_ServantManager,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::ServantManager_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::ServantManager>::extract (
        _tao_any,
        PortableServer::ServantManager::_tao_any_destructor,
        PortableServer::_tc_ServantManager,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::ForwardRequest>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if ((cdr >> id.out ()) == 0)
    {
      return 0;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return 0;
    }
  ACE_ENDTRY;
  
  return 1;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::ForwardRequest &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::ForwardRequest>::insert_copy (
      _tao_any,
      PortableServer::ForwardRequest::_tao_any_destructor,
      PortableServer::_tc_ForwardRequest,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ForwardRequest *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::ForwardRequest>::insert (
      _tao_any,
      PortableServer::ForwardRequest::_tao_any_destructor,
      PortableServer::_tc_ForwardRequest,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::ForwardRequest *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::ForwardRequest *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::ForwardRequest *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::ForwardRequest>::extract (
        _tao_any,
        PortableServer::ForwardRequest::_tao_any_destructor,
        PortableServer::_tc_ForwardRequest,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        PortableServer::ServantManager
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::ForwardRequest
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::ServantManager \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::ForwardRequest \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
