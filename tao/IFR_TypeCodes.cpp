// -*- C++ -*-
// $Id$

#include "tao/corbafwd.h"

ACE_RCSID(tao, IFR_TypeCodes, "$Id$")

// These Interface Repository typecodes and constants are in
// the CORBA namespace. The typecodes are set to 0 here. If the 
// IFR_Client library is built and linked, the library initializer 
// will set them to their correct values. The constants are set to
// the correct values in this file, since it doesn't take up any
// more space to do that.

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_RepositoryId, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Identifier, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ScopedName, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_VersionSpec, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Visibility, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (const CORBA::Visibility)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::Visibility, PRIVATE_MEMBER, 0)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::Visibility)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::Visibility, PUBLIC_MEMBER, 1)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ValueModifier, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (const CORBA::ValueModifier)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::ValueModifier, VM_NONE, 0)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::ValueModifier)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::ValueModifier, VM_CUSTOM, 1)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::ValueModifier)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::ValueModifier, VM_ABSTRACT, 2)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::ValueModifier)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::ValueModifier, VM_TRUNCATABLE, 3)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ContextIdentifier, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_IRObject, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_DefinitionKind, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Contained, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ContainedSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Repository, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Container, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ModuleDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ConstantDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_IDLType, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_StructDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_UnionDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_EnumDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_AliasDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_InterfaceDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_AbstractInterfaceDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_LocalInterfaceDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ExceptionDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_NativeDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_InterfaceDefSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_AbstractInterfaceDefSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_LocalInterfaceDefSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ValueDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ValueDefSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ValueBoxDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_StructMember, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_StructMemberSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Initializer, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_InitializerSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_UnionMember, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_UnionMemberSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_EnumMemberSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ModuleDescription, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ConstantDescription, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_TypedefDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_TypeDescription, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_PrimitiveDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_StringDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_WstringDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_FixedDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_SequenceDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ArrayDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ExceptionDescription, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ExceptionDefSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ExcDescriptionSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_AttributeMode, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_AttributeDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_AttributeDescription, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_PrimitiveKind, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ParameterMode, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ParameterDescription, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ParDescriptionSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ContextIdentifier, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ContextIdSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_OperationDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_OperationMode, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_OperationDescription, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_RepositoryIdSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_OpDescriptionSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_AttrDescriptionSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_InterfaceDescription, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ValueMember, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ValueMemberSeq, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ValueMemberDef, 0)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ValueDescription, 0)
TAO_NAMESPACE_END

