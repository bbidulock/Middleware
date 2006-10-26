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


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



ACE_INLINE
void
POA_CORBA::Contained::_get_def_kind_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IRObject * const impl = static_cast<POA_CORBA::Contained *> (servant);
  POA_CORBA::IRObject::_get_def_kind_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

// TAO_IDL - Generated from
// be\be_interface.cpp:1955

ACE_INLINE
void
POA_CORBA::Contained::destroy_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IRObject * const impl = static_cast<POA_CORBA::Contained *> (servant);
  POA_CORBA::IRObject::destroy_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::Container::_get_def_kind_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IRObject * const impl = static_cast<POA_CORBA::Container *> (servant);
  POA_CORBA::IRObject::_get_def_kind_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

// TAO_IDL - Generated from
// be\be_interface.cpp:1955

ACE_INLINE
void
POA_CORBA::Container::destroy_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IRObject * const impl = static_cast<POA_CORBA::Container *> (servant);
  POA_CORBA::IRObject::destroy_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::IDLType::_get_def_kind_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IRObject * const impl = static_cast<POA_CORBA::IDLType *> (servant);
  POA_CORBA::IRObject::_get_def_kind_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

// TAO_IDL - Generated from
// be\be_interface.cpp:1955

ACE_INLINE
void
POA_CORBA::IDLType::destroy_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IRObject * const impl = static_cast<POA_CORBA::IDLType *> (servant);
  POA_CORBA::IRObject::destroy_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_get_def_kind_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IRObject * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::IRObject::_get_def_kind_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

// TAO_IDL - Generated from
// be\be_interface.cpp:1955

ACE_INLINE
void
POA_CORBA::TypedefDef::destroy_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IRObject * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::IRObject::destroy_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_get_id_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_get_id_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_set_id_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_set_id_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_get_name_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_get_name_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_set_name_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_set_name_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_get_version_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_get_version_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_set_version_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_set_version_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_get_defined_in_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_get_defined_in_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_get_absolute_name_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_get_absolute_name_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_get_containing_repository_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::_get_containing_repository_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

// TAO_IDL - Generated from
// be\be_interface.cpp:1955

ACE_INLINE
void
POA_CORBA::TypedefDef::describe_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::describe_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

// TAO_IDL - Generated from
// be\be_interface.cpp:1955

ACE_INLINE
void
POA_CORBA::TypedefDef::move_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Contained * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::Contained::move_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}

ACE_INLINE
void
POA_CORBA::TypedefDef::_get_type_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::IDLType * const impl = static_cast<POA_CORBA::TypedefDef *> (servant);
  POA_CORBA::IDLType::_get_type_skel (
      server_request,
      servant_upcall,
      impl
      ACE_ENV_ARG_PARAMETER
    );
}


TAO_END_VERSIONED_NAMESPACE_DECL


