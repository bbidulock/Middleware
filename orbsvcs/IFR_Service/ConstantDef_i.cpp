/* -*- C++ -*- */
// $Id$

#include "ConstantDef_i.h"
#include "Repository_i.h"
#include "IDLType_i.h"
#include "Servant_Factory.h"
#include "ace/Auto_Ptr.h"

ACE_RCSID(IFR_Service, ConstantDef_i, "$Id$")

TAO_ConstantDef_i::TAO_ConstantDef_i (
    TAO_Repository_i *repo,
    ACE_Configuration_Section_Key section_key
  )
  : TAO_IRObject_i (repo, section_key),
    TAO_Contained_i (repo, section_key)
{
}

TAO_ConstantDef_i::~TAO_ConstantDef_i (void)
{
}

IR::DefinitionKind
TAO_ConstantDef_i::def_kind (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return IR::dk_Constant;
}

IR::Contained::Description *
TAO_ConstantDef_i::describe (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  IR::Contained::Description *desc_ptr = 0;
  ACE_NEW_THROW_EX (desc_ptr,
                    IR::Contained::Description,
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  IR::Contained::Description_var retval = desc_ptr;

  retval->kind = this->def_kind (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  IR::ConstantDescription cd;

  cd.name = this->name (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  cd.id = this->id (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  ACE_TString container_id;

  this->repo_->config ()->get_string_value (this->section_key_,
                                            "container_id",
                                            container_id);

  cd.defined_in = container_id.c_str ();

  cd.version = this->version (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  cd.type = this->type (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  CORBA::Any_var val = this->value (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  cd.value = val.in ();

  retval->value <<= cd;

  return retval._retn ();
}

CORBA::TypeCode_ptr 
TAO_ConstantDef_i::type (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_TString type_path;
  this->repo_->config ()->get_string_value (this->section_key_,
                                            "type_path",
                                            type_path);

  ACE_Configuration_Section_Key type_key;
  this->repo_->config ()->expand_path (this->repo_->root_key (),
                                       type_path,
                                       type_key,
                                       0);

  TAO_IDLType_i *impl =
    this->repo_->servant_factory ()->create_idltype (type_key,
                                                     ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::TypeCode::_nil ());

  auto_ptr<TAO_IDLType_i> safety (impl);

  return impl->type (ACE_TRY_ENV);
}

IR::IDLType_ptr 
TAO_ConstantDef_i::type_def (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_TString type_path;

  this->repo_->config ()->get_string_value (this->section_key_,
                                            "type_path",
                                            type_path);

  ACE_Configuration_Section_Key type_key;

  this->repo_->config ()->expand_path (this->repo_->root_key (),
                                       type_path,
                                       type_key,
                                       0);

  u_int kind = 0;

  this->repo_->config ()->get_integer_value (type_key,
                                             "def_kind",
                                             kind);

  IR::DefinitionKind def_kind =
    ACE_static_cast (IR::DefinitionKind, kind);

  CORBA::Object_var obj = 
    this->repo_->servant_factory ()->create_objref (def_kind,
                                                    type_path.c_str (),
                                                    ACE_TRY_ENV);
  ACE_CHECK_RETURN (IR::IDLType::_nil ());

  return IR::IDLType::_narrow (obj.in (),
                               ACE_TRY_ENV);
}

void 
TAO_ConstantDef_i::type_def (IR::IDLType_ptr type_def,
                             CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  PortableServer::ObjectId_var oid = 
    this->repo_->ir_poa ()->reference_to_id (type_def,
                                             ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::String_var type_path = 
    PortableServer::ObjectId_to_string (oid.in ());

  this->repo_->config ()->set_string_value (this->section_key_,
                                            "type_path",
                                            type_path.in ());
}

CORBA::Any *
TAO_ConstantDef_i::value (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::TypeCode_var tc = this->type (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  void *ref = 0;
  size_t length = 0;

  this->repo_->config ()->get_binary_value (
                              this->section_key_,
                              "value",
                              ref,
                              length
                            );

  char *data = ACE_static_cast (char *, ref);

  auto_ptr<char> safety (data);

  ACE_Message_Block mb (data, 
                        length);

  mb.length (length);

  CORBA::Any *retval = 0;
  ACE_NEW_THROW_EX (retval,
                    CORBA::Any (tc.in (),
                                0,
                                TAO_ENCAP_BYTE_ORDER,
                                &mb),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  return retval;
}

void 
TAO_ConstantDef_i::value (const CORBA::Any &value,
                          CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::TypeCode_var my_tc = this->type (ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::TypeCode_var val_tc = value.type ();

  if (!my_tc.in ()->equal (val_tc.in ()))
    return;

  ACE_Message_Block *mb = value._tao_get_cdr ();

  CORBA::TCKind kind = val_tc->kind (ACE_TRY_ENV);
  ACE_CHECK;

  switch (kind)
  {
    // The data for these types will be aligned to an 8-byte
    // boundary, while the rd_ptr may not.
    case CORBA::tk_double:
    case CORBA::tk_ulonglong:
    case CORBA::tk_longlong:
    case CORBA::tk_longdouble:
      mb->rd_ptr (ACE_ptr_align_binary (mb->rd_ptr (),
                                        ACE_CDR::MAX_ALIGNMENT));
      break;
    default:
      break;
  }

  mb->crunch ();

  this->repo_->config ()->set_binary_value (this->section_key_,
                                            "value",
                                            mb->base (),
                                            mb->length ());
}

