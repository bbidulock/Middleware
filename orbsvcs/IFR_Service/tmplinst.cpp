// $Id$

#include "concrete_classes.h"
#include "ace/Containers_T.h"
#include "ace/Auto_Ptr.h"

ACE_RCSID(IFR_Service, tmplinst, "$Id$")

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Unbounded_Queue<IR::DefinitionKind>;
template class ACE_Unbounded_Queue<ACE_TString>;
template class ACE_Unbounded_Queue<ACE_Configuration_Section_Key>;

template class POA_IR::Repository_tie<TAO_Repository_i>;
template class POA_IR::ComponentRepository_tie<TAO_ComponentRepository_i>;
template class POA_IR::PrimitiveDef_tie<TAO_PrimitiveDef_i>;
template class POA_IR::StringDef_tie<TAO_StringDef_i>;
template class POA_IR::WstringDef_tie<TAO_WstringDef_i>;
template class POA_IR::SequenceDef_tie<TAO_SequenceDef_i>;
template class POA_IR::ArrayDef_tie<TAO_ArrayDef_i>;
template class POA_IR::FixedDef_tie<TAO_FixedDef_i>;
template class POA_IR::EnumDef_tie<TAO_EnumDef_i>;
template class POA_IR::AliasDef_tie<TAO_AliasDef_i>;
template class POA_IR::NativeDef_tie<TAO_NativeDef_i>;
template class POA_IR::ValueBoxDef_tie<TAO_ValueBoxDef_i>;
template class POA_IR::UnionDef_tie<TAO_UnionDef_i>;
template class POA_IR::StructDef_tie<TAO_StructDef_i>;
template class POA_IR::ConsumesDef_tie<TAO_ConsumesDef_i>;
template class POA_IR::PublishesDef_tie<TAO_PublishesDef_i>;
template class POA_IR::EmitsDef_tie<TAO_EmitsDef_i>;
template class POA_IR::PrimaryKeyDef_tie<TAO_PrimaryKeyDef_i>;
template class POA_IR::ProvidesDef_tie<TAO_ProvidesDef_i>;
template class POA_IR::UsesDef_tie<TAO_UsesDef_i>;
template class POA_IR::ValueMemberDef_tie<TAO_ValueMemberDef_i>;
template class POA_IR::FactoryDef_tie<TAO_FactoryDef_i>;
template class POA_IR::FinderDef_tie<TAO_FinderDef_i>;
template class POA_IR::AttributeDef_tie<TAO_AttributeDef_i>;
template class POA_IR::ConstantDef_tie<TAO_ConstantDef_i>;
template class POA_IR::ComponentDef_tie<TAO_ComponentDef_i>;
template class POA_IR::HomeDef_tie<TAO_HomeDef_i>;
template class POA_IR::ValueDef_tie<TAO_ValueDef_i>;
template class POA_IR::ExceptionDef_tie<TAO_ExceptionDef_i>;
template class POA_IR::ModuleDef_tie<TAO_ModuleDef_i>;
template class POA_IR::OperationDef_tie<TAO_OperationDef_i>;
template class POA_IR::InterfaceDef_tie<TAO_InterfaceDef_i>;

template class auto_ptr<TAO_Repository_i>;
template class auto_ptr<TAO_ComponentRepository_i>;
template class auto_ptr<TAO_PrimitiveDef_i>;
template class auto_ptr<TAO_StringDef_i>;
template class auto_ptr<TAO_WstringDef_i>;
template class auto_ptr<TAO_SequenceDef_i>;
template class auto_ptr<TAO_ArrayDef_i>;
template class auto_ptr<TAO_FixedDef_i>;
template class auto_ptr<TAO_EnumDef_i>;
template class auto_ptr<TAO_AliasDef_i>;
template class auto_ptr<TAO_NativeDef_i>;
template class auto_ptr<TAO_ValueBoxDef_i>;
template class auto_ptr<TAO_UnionDef_i>;
template class auto_ptr<TAO_StructDef_i>;
template class auto_ptr<TAO_ConsumesDef_i>;
template class auto_ptr<TAO_PublishesDef_i>;
template class auto_ptr<TAO_EmitsDef_i>;
template class auto_ptr<TAO_PrimaryKeyDef_i>;
template class auto_ptr<TAO_ProvidesDef_i>;
template class auto_ptr<TAO_UsesDef_i>;
template class auto_ptr<TAO_ValueMemberDef_i>;
template class auto_ptr<TAO_FactoryDef_i>;
template class auto_ptr<TAO_FinderDef_i>;
template class auto_ptr<TAO_AttributeDef_i>;
template class auto_ptr<TAO_ConstantDef_i>;
template class auto_ptr<TAO_ComponentDef_i>;
template class auto_ptr<TAO_HomeDef_i>;
template class auto_ptr<TAO_ValueDef_i>;
template class auto_ptr<TAO_ExceptionDef_i>;
template class auto_ptr<TAO_ModuleDef_i>;
template class auto_ptr<TAO_OperationDef_i>;
template class auto_ptr<TAO_InterfaceDef_i>;
template class auto_ptr<TAO_Container_i>;
template class auto_ptr<TAO_Contained_i>;
template class auto_ptr<TAO_IDLType_i>;
template class auto_ptr<char>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Unbounded_Queue<IR::DefinitionKind>
#pragma instantiate ACE_Unbounded_Queue<ACE_TString>
#pragma instantiate ACE_Unbounded_Queue<ACE_Configuration_Section_Key>

#pragma instantiate POA_IR::Repository_tie<TAO_Repository_i>
#pragma instantiate POA_IR::ComponentRepository_tie<TAO_ComponentRepository_i>
#pragma instantiate POA_IR::PrimitiveDef_tie<TAO_PrimitiveDef_i>
#pragma instantiate POA_IR::StringDef_tie<TAO_StringDef_i>
#pragma instantiate POA_IR::WstringDef_tie<TAO_WstringDef_i>
#pragma instantiate POA_IR::SequenceDef_tie<TAO_SequenceDef_i>
#pragma instantiate POA_IR::ArrayDef_tie<TAO_ArrayDef_i>
#pragma instantiate POA_IR::FixedDef_tie<TAO_FixedDef_i>
#pragma instantiate POA_IR::EnumDef_tie<TAO_EnumDef_i>
#pragma instantiate POA_IR::AliasDef_tie<TAO_AliasDef_i>
#pragma instantiate POA_IR::NativeDef_tie<TAO_NativeDef_i>
#pragma instantiate POA_IR::ValueBoxDef_tie<TAO_ValueBoxDef_i>
#pragma instantiate POA_IR::UnionDef_tie<TAO_UnionDef_i>
#pragma instantiate POA_IR::StructDef_tie<TAO_StructDef_i>
#pragma instantiate POA_IR::ConsumesDef_tie<TAO_ConsumesDef_i>
#pragma instantiate POA_IR::PublishesDef_tie<TAO_PublishesDef_i>
#pragma instantiate POA_IR::EmitsDef_tie<TAO_EmitsDef_i>
#pragma instantiate POA_IR::PrimaryKeyDef_tie<TAO_PrimaryKeyDef_i>
#pragma instantiate POA_IR::ProvidesDef_tie<TAO_ProvidesDef_i>
#pragma instantiate POA_IR::UsesDef_tie<TAO_UsesDef_i>
#pragma instantiate POA_IR::ValueMemberDef_tie<TAO_ValueMemberDef_i>
#pragma instantiate POA_IR::FactoryDef_tie<TAO_FactoryDef_i>
#pragma instantiate POA_IR::FinderDef_tie<TAO_FinderDef_i>
#pragma instantiate POA_IR::AttributeDef_tie<TAO_AttributeDef_i>
#pragma instantiate POA_IR::ConstantDef_tie<TAO_ConstantDef_i>
#pragma instantiate POA_IR::ComponentDef_tie<TAO_ComponentDef_i>
#pragma instantiate POA_IR::HomeDef_tie<TAO_HomeDef_i>
#pragma instantiate POA_IR::ValueDef_tie<TAO_ValueDef_i>
#pragma instantiate POA_IR::ExceptionDef_tie<TAO_ExceptionDef_i>
#pragma instantiate POA_IR::ModuleDef_tie<TAO_ModuleDef_i>
#pragma instantiate POA_IR::OperationDef_tie<TAO_OperationDef_i>
#pragma instantiate POA_IR::InterfaceDef_tie<TAO_>

#pragma instantiate auto_ptr<TAO_Repository_i>
#pragma instantiate auto_ptr<TAO_ComponentRepository_i>
#pragma instantiate auto_ptr<TAO_PrimitiveDef_i>
#pragma instantiate auto_ptr<TAO_StringDef_i>
#pragma instantiate auto_ptr<TAO_WstringDef_i>
#pragma instantiate auto_ptr<TAO_SequenceDef_i>
#pragma instantiate auto_ptr<TAO_ArrayDef_i>
#pragma instantiate auto_ptr<TAO_FixedDef_i>
#pragma instantiate auto_ptr<TAO_EnumDef_i>
#pragma instantiate auto_ptr<TAO_AliasDef_i>
#pragma instantiate auto_ptr<TAO_NativeDef_i>
#pragma instantiate auto_ptr<TAO_ValueBoxDef_i>
#pragma instantiate auto_ptr<TAO_UnionDef_i>
#pragma instantiate auto_ptr<TAO_StructDef_i>
#pragma instantiate auto_ptr<TAO_ConsumesDef_i>
#pragma instantiate auto_ptr<TAO_PublishesDef_i>
#pragma instantiate auto_ptr<TAO_EmitsDef_i>
#pragma instantiate auto_ptr<TAO_PrimaryKeyDef_i>
#pragma instantiate auto_ptr<TAO_ProvidesDef_i>
#pragma instantiate auto_ptr<TAO_UsesDef_i>
#pragma instantiate auto_ptr<TAO_ValueMemberDef_i>
#pragma instantiate auto_ptr<TAO_FactoryDef_i>
#pragma instantiate auto_ptr<TAO_FinderDef_i>
#pragma instantiate auto_ptr<TAO_AttributeDef_i>
#pragma instantiate auto_ptr<TAO_ConstantDef_i>
#pragma instantiate auto_ptr<TAO_ComponentDef_i>
#pragma instantiate auto_ptr<TAO_HomeDef_i>
#pragma instantiate auto_ptr<TAO_ValueDef_i>
#pragma instantiate auto_ptr<TAO_ExceptionDef_i>
#pragma instantiate auto_ptr<TAO_ModuleDef_i>
#pragma instantiate auto_ptr<TAO_OperationDef_i>
#pragma instantiate auto_ptr<TAO_InterfaceDef_i>
#pragma instantiate auto_ptr<TAO_Container_i>
#pragma instantiate auto_ptr<TAO_Contained_i>
#pragma instantiate auto_ptr<TAO_IDLType_i>
#pragma instantiate auto_ptr<char>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
