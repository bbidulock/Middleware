/* -*- C++ -*- */
// $Id$

#include "Repository_i.h"
#include "HomeDef_i.h"
#include "FactoryDef_i.h"
#include "FinderDef_i.h"
#include "ValueDef_i.h"
#include "ExceptionDef_i.h"
#include "AttributeDef_i.h"
#include "IFR_Service_Utils_T.h"

ACE_RCSID (IFRService, 
           HomeDef_i, 
           "$Id$")

TAO_HomeDef_i::TAO_HomeDef_i (TAO_Repository_i *repo)
  : TAO_IRObject_i (repo),
    TAO_Container_i (repo),
    TAO_Contained_i (repo),
    TAO_IDLType_i (repo),
    TAO_InterfaceDef_i (repo),
    TAO_InterfaceAttrExtension_i (repo),
    TAO_ExtInterfaceDef_i (repo)
{
}

TAO_HomeDef_i::~TAO_HomeDef_i (void)
{
}

CORBA::DefinitionKind
TAO_HomeDef_i::def_kind (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::dk_Home;
}

void
TAO_HomeDef_i::destroy (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->destroy_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

void
TAO_HomeDef_i::destroy_i (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Destroy our special subsections first, then call destroy_i
  // on our base class.

  TAO_IFR_Generic_Utils<TAO_FactoryDef_i>::destroy_special (
      "factories",
      this->repo_,
      this->section_key_
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;

  TAO_IFR_Generic_Utils<TAO_FinderDef_i>::destroy_special (
      "finders",
      this->repo_,
      this->section_key_
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;

  this->TAO_ExtInterfaceDef_i::destroy_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::Contained::Description *
TAO_HomeDef_i::describe (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return this->describe_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::Contained::Description *
TAO_HomeDef_i::describe_i (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::ComponentIR::HomeDescription home_desc;

  TAO_IFR_Desc_Utils<CORBA::ComponentIR::HomeDescription,
                     TAO_HomeDef_i>::fill_desc_begin (home_desc,
                                                      this->repo_,
                                                      this->section_key_
                                                      ACE_ENV_ARG_PARAMETER);
  ACE_TString holder;
  int status =
    this->repo_->config ()->get_string_value (this->section_key_,
                                              "base_home",
                                              holder);

  ACE_Configuration_Section_Key tmp_key;

  if (status == 0)
    {
      this->repo_->config ()->expand_path (this->repo_->root_key (),
                                           holder,
                                           tmp_key,
                                           0);
      this->repo_->config ()->get_string_value (tmp_key,
                                                "id",
                                                holder);
      home_desc.base_home = holder.fast_rep ();
    }

  // No need to check the status - this one is required.
  this->repo_->config ()->get_string_value (this->section_key_,
                                            "managed",
                                            holder);
  home_desc.managed_component = holder.fast_rep ();
  status =
    this->repo_->config ()->get_string_value (this->section_key_,
                                              "primary_key",
                                              holder);

  if (status == 0)
    {
      this->repo_->config ()->expand_path (this->repo_->root_key (),
                                           holder,
                                           tmp_key,
                                           0);
      TAO_ValueDef_i impl (this->repo_);
      impl.section_key (tmp_key);
      impl.fill_value_description (home_desc.primary_key
                                   ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);
    }

  this->fill_op_desc_seq (this->section_key_,
                          home_desc.factories,
                          "factories"
                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  this->fill_op_desc_seq (this->section_key_,
                          home_desc.finders,
                          "finders"
                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  this->fill_op_desc_seq (this->section_key_,
                          home_desc.operations,
                          "ops"
                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  home_desc.type = this->type_i (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Contained::Description *retval = 0;
  ACE_NEW_RETURN (retval,
                  CORBA::Contained::Description,
                  0);

  retval->kind = CORBA::dk_Home;
  retval->value <<= home_desc;
  return retval;
}

CORBA::TypeCode_ptr
TAO_HomeDef_i::type (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (CORBA::TypeCode::_nil ());

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::TypeCode::_nil ());

  return this->type_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::TypeCode_ptr
TAO_HomeDef_i::type_i (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_TString id;
  this->repo_->config ()->get_string_value (this->section_key_,
                                            "id",
                                            id);

  ACE_TString name;
  this->repo_->config ()->get_string_value (this->section_key_,
                                            "name",
                                            name);

  return this->repo_->tc_factory ()->create_home_tc (id.fast_rep (),
                                                     name.fast_rep ()
                                                     ACE_ENV_ARG_PARAMETER);
}

CORBA::ComponentIR::HomeDef_ptr
TAO_HomeDef_i::base_home (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (CORBA::ComponentIR::HomeDef::_nil ());

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ComponentIR::HomeDef::_nil ());

  return this->base_home_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::ComponentIR::HomeDef_ptr
TAO_HomeDef_i::base_home_i (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_TString path;
  int status =
    this->repo_->config ()->get_string_value (this->section_key_,
                                              "base_home",
                                              path);

  if (status != 0)
    {
      return CORBA::ComponentIR::HomeDef::_nil ();
    }

  CORBA::Object_var obj = 
    TAO_IFR_Service_Utils::path_to_ir_object (path,
                                              this->repo_
                                              ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ComponentIR::HomeDef::_nil ());

  return CORBA::ComponentIR::HomeDef::_narrow (obj.in ()
                                               ACE_ENV_ARG_PARAMETER);
}

void
TAO_HomeDef_i::base_home (
    CORBA::ComponentIR::HomeDef_ptr base_home
    ACE_ENV_ARG_DECL
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->base_home_i (base_home
                     ACE_ENV_ARG_PARAMETER);
}

void
TAO_HomeDef_i::base_home_i (
    CORBA::ComponentIR::HomeDef_ptr base_home
    ACE_ENV_ARG_DECL_NOT_USED
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  char *path = TAO_IFR_Service_Utils::reference_to_path (base_home);
  this->repo_->config ()->set_string_value (this->section_key_,
                                            "base_home",
                                            path);
}

CORBA::InterfaceDefSeq *
TAO_HomeDef_i::supported_interfaces (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return this->supported_interfaces_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}
    
CORBA::InterfaceDefSeq *
TAO_HomeDef_i::supported_interfaces_i (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::InterfaceDefSeq *retval = 0;
  ACE_NEW_RETURN (retval,
                  CORBA::InterfaceDefSeq,
                  0);
  CORBA::InterfaceDefSeq_var safe_retval = retval;
  retval->length (0);
  ACE_Configuration_Section_Key supported_key;
  int status =
    this->repo_->config ()->open_section (this->section_key_,
                                          "supported",
                                          0,
                                          supported_key);

  if (status != 0)
    {
      return retval;
    }

  CORBA::ULong count = 0;
  this->repo_->config ()->get_integer_value (supported_key,
                                             "count",
                                             count);
  retval->length (count);
  char *stringified = 0;
  ACE_TString holder;
  CORBA::Object_var obj;

  for (CORBA::ULong i = 0; i < count; ++i)
    {
      stringified = TAO_IFR_Service_Utils::int_to_string (i);
      this->repo_->config ()->get_string_value (supported_key,
                                                stringified,
                                                holder);
      obj = TAO_IFR_Service_Utils::path_to_ir_object (holder,
                                                      this->repo_
                                                      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      safe_retval[i] = CORBA::InterfaceDef::_narrow (obj.in ()
                                                     ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);
    }

  return safe_retval._retn ();
}   

void 
TAO_HomeDef_i::supported_interfaces (
    const CORBA::InterfaceDefSeq &supported_interfaces
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->supported_interfaces_i (supported_interfaces
                                ACE_ENV_ARG_PARAMETER);
} 
   
void 
TAO_HomeDef_i::supported_interfaces_i (
    const CORBA::InterfaceDefSeq &supported_interfaces
    ACE_ENV_ARG_DECL_NOT_USED
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->repo_->config ()->remove_section (this->section_key_,
                                          "supported",
                                          1);
  CORBA::ULong length = supported_interfaces.length ();

  if (length == 0)
    {
      return;
    }

  ACE_Configuration_Section_Key supported_key;
  this->repo_->config ()->open_section (this->section_key_,
                                        "supported",
                                        1,
                                        supported_key);
  char *stringified = 0;
  char *path = 0;

  for (CORBA::ULong i = 0; i < length; ++i)
    {
      stringified = TAO_IFR_Service_Utils::int_to_string (i);
      path = 
        TAO_IFR_Service_Utils::reference_to_path (
            supported_interfaces[i].in ()
          );
      this->repo_->config ()->set_string_value (supported_key,
                                                stringified,
                                                path);
    }
}
      
CORBA::ComponentIR::ComponentDef_ptr
TAO_HomeDef_i::managed_component (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (CORBA::ComponentIR::ComponentDef::_nil ());

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ComponentIR::ComponentDef::_nil ());

  return this->managed_component_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::ComponentIR::ComponentDef_ptr
TAO_HomeDef_i::managed_component_i (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_TString path;
  this->repo_->config ()->get_string_value (this->section_key_,
                                            "managed",
                                            path);
  CORBA::Object_var obj = 
    TAO_IFR_Service_Utils::path_to_ir_object (path,
                                              this->repo_
                                              ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ComponentIR::ComponentDef::_nil ());

  return CORBA::ComponentIR::ComponentDef::_narrow (obj.in ()
                                                    ACE_ENV_ARG_PARAMETER);
}

void
TAO_HomeDef_i::managed_component (
    CORBA::ComponentIR::ComponentDef_ptr managed_component
    ACE_ENV_ARG_DECL
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->managed_component_i (managed_component
                             ACE_ENV_ARG_PARAMETER);
}

void
TAO_HomeDef_i::managed_component_i (
    CORBA::ComponentIR::ComponentDef_ptr managed_component
    ACE_ENV_ARG_DECL_NOT_USED
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  char *path = TAO_IFR_Service_Utils::reference_to_path (managed_component);
  this->repo_->config ()->set_string_value (this->section_key_,
                                            "managed",
                                            path);
}

CORBA::ValueDef_ptr
TAO_HomeDef_i::primary_key (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (CORBA::ValueDef::_nil ());

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ValueDef::_nil ());

  return this->primary_key_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

CORBA::ValueDef_ptr
TAO_HomeDef_i::primary_key_i (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_TString path;
  int status =
    this->repo_->config ()->get_string_value (this->section_key_,
                                              "primary_key",
                                              path);

  if (status != 0)
    {
      return CORBA::ValueDef::_nil ();
    }

  CORBA::Object_var obj =
    TAO_IFR_Service_Utils::path_to_ir_object (path,
                                              this->repo_
                                              ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ValueDef::_nil ());

  return CORBA::ValueDef::_narrow (obj.in ()
                                   ACE_ENV_ARG_PARAMETER);
}

void 
TAO_HomeDef_i::primary_key (
    CORBA::ValueDef_ptr primary_key
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->primary_key_i (primary_key
                       ACE_ENV_ARG_PARAMETER);
} 
   
void 
TAO_HomeDef_i::primary_key_i (
    CORBA::ValueDef_ptr primary_key
    ACE_ENV_ARG_DECL_NOT_USED
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (CORBA::is_nil (primary_key))
    {
      this->repo_->config ()->remove_value (this->section_key_,
                                            "primary_key");
      return;
    }

  char *path = TAO_IFR_Service_Utils::reference_to_path (primary_key);
  this->repo_->config ()->set_string_value (this->section_key_,
                                            "primary_key",
                                            path);
}
      
CORBA::ComponentIR::FactoryDef_ptr
TAO_HomeDef_i::create_factory (const char *id,
                               const char *name,
                               const char *version,
                               const CORBA::ParDescriptionSeq &params,
                               const CORBA::ExceptionDefSeq &exceptions
                               ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD_RETURN (CORBA::ComponentIR::FactoryDef::_nil ());

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ComponentIR::FactoryDef::_nil ());

  return this->create_factory_i (id,
                                 name,
                                 version,
                                 params,
                                 exceptions
                                 ACE_ENV_ARG_PARAMETER);
}

CORBA::ComponentIR::FactoryDef_ptr
TAO_HomeDef_i::create_factory_i (
    const char *id,
    const char *name,
    const char *version,
    const CORBA::ParDescriptionSeq &params,
    const CORBA::ExceptionDefSeq &exceptions
    ACE_ENV_ARG_DECL
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Object_var obj = this->create_common (CORBA::dk_Factory,
                                               id,
                                               name,
                                               version,
                                               "factories",
                                               params,
                                               exceptions
                                               ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ComponentIR::FactoryDef::_nil ());

  return CORBA::ComponentIR::FactoryDef::_narrow (obj.in ()
                                                  ACE_ENV_ARG_PARAMETER);
}

CORBA::ComponentIR::FinderDef_ptr
TAO_HomeDef_i::create_finder (const char *id,
                              const char *name,
                              const char *version,
                              const CORBA::ParDescriptionSeq &params,
                              const CORBA::ExceptionDefSeq &exceptions
                              ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD_RETURN (CORBA::ComponentIR::FinderDef::_nil ());

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ComponentIR::FinderDef::_nil ());

  return this->create_finder_i (id,
                                name,
                                version,
                                params,
                                exceptions
                                ACE_ENV_ARG_PARAMETER);
}

CORBA::ComponentIR::FinderDef_ptr
TAO_HomeDef_i::create_finder_i (
    const char *id,
    const char *name,
    const char *version,
    const CORBA::ParDescriptionSeq &params,
    const CORBA::ExceptionDefSeq &exceptions
    ACE_ENV_ARG_DECL
  )
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Object_var obj = this->create_common (CORBA::dk_Finder,
                                               id,
                                               name,
                                               version,
                                               "finders",
                                               params,
                                               exceptions
                                               ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::ComponentIR::FinderDef::_nil ());

  return CORBA::ComponentIR::FinderDef::_narrow (obj.in ()
                                                 ACE_ENV_ARG_PARAMETER);
}

CORBA::Object_ptr 
TAO_HomeDef_i::create_common (CORBA::DefinitionKind created_kind,
                              const char *id,
                              const char *name,
                              const char *version,
                              const char *sub_section,
                              const CORBA::ParDescriptionSeq &params,
                              const CORBA::ExceptionDefSeq &exceptions
                              ACE_ENV_ARG_DECL)
{
  TAO_Container_i::tmp_name_holder_ = name;
  ACE_Configuration_Section_Key new_key;

  // Common to all IR objects created in CORBA::Container.
  ACE_TString result_path = 
    TAO_IFR_Service_Utils::create_common (CORBA::dk_Home,
                                          created_kind,
                                          this->section_key_,
                                          new_key,
                                          this->repo_,
                                          id,
                                          name,
                                          &TAO_Container_i::same_as_tmp_name,
                                          version,
                                          sub_section
                                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::Object::_nil ());

  // Set the 'result' field with the path of our managed component.
  ACE_TString managed_path;
  this->repo_->config ()->get_string_value (this->section_key_,
                                            "managed",
                                            managed_path);
  this->repo_->config ()->set_string_value (new_key,
                                            "result",
                                            managed_path);

  // Always OP_NORMAL for factories.
  this->repo_->config ()->set_integer_value (new_key,
                                             "mode",
                                             CORBA::OP_NORMAL);

  CORBA::ULong i = 0;

  // Store the operation's parameter info.
  CORBA::ULong length = params.length ();

  if (length > 0)
    {
      ACE_Configuration_Section_Key params_key;
      this->repo_->config ()->open_section (new_key,
                                            "params",
                                            1,
                                            params_key);

      this->repo_->config ()->set_integer_value (params_key,
                                                 "count",
                                                 length);
      char *type_path = 0;
      char *stringified = 0;
      ACE_Configuration_Section_Key param_key;

      for (i = 0; i < length; ++i)
        {
          stringified = TAO_IFR_Service_Utils::int_to_string (i);
          this->repo_->config ()->open_section (params_key,
                                                stringified,
                                                1,
                                                param_key);

          this->repo_->config ()->set_string_value (param_key,
                                                    "name",
                                                    params[i].name.in ());
          type_path =
            TAO_IFR_Service_Utils::reference_to_path (
                params[i].type_def.in ()
              );

          this->repo_->config ()->set_string_value (param_key,
                                                    "type_path",
                                                    type_path);

          if (params[i].mode != CORBA::PARAM_IN)
            {
              // @@@ (JP) No OMG-defined exception for this, but maybe there
              // will be.
            }

          this->repo_->config ()->set_integer_value (param_key,
                                                     "mode",
                                                     CORBA::PARAM_IN);
       }
    }

  // Store the operation's exception info.
  length = exceptions.length ();

  if (length > 0)
    {
      ACE_Configuration_Section_Key excepts_key;
      this->repo_->config ()->open_section (new_key,
                                            "excepts",
                                            1,
                                            excepts_key);

      this->repo_->config ()->set_integer_value (excepts_key,
                                                 "count",
                                                 length);
      char *type_path = 0;

      for (i = 0; i < length; ++i)
        {
          type_path = 
            TAO_IFR_Service_Utils::reference_to_path (exceptions[i].in ());

          char *stringified = TAO_IFR_Service_Utils::int_to_string (i);
          this->repo_->config ()->set_string_value (excepts_key,
                                                    stringified,
                                                    type_path);
        }
    }

  // Create the object reference.
  return
    TAO_IFR_Service_Utils::create_objref (created_kind,
                                          result_path.c_str (),
                                          this->repo_
                                          ACE_ENV_ARG_PARAMETER);
}

void 
TAO_HomeDef_i::fill_op_desc_seq (ACE_Configuration_Section_Key &key,
                                 CORBA::OpDescriptionSeq &ods,
                                 const char *sub_section
                                 ACE_ENV_ARG_DECL)
{
  ods.length (0);
  ACE_Configuration_Section_Key sub_key;
  int status =
    this->repo_->config ()->open_section (key,
                                          sub_section,
                                          0,
                                          sub_key);

  if (status != 0)
    {
      return;
    }

  CORBA::ULong count = 0;
  this->repo_->config ()->get_integer_value (sub_key,
                                             "count",
                                             count);
  ods.length (count);
  char *stringified = 0;

  for (CORBA::ULong i = 0; i < count; ++i)
    {
      stringified = TAO_IFR_Service_Utils::int_to_string (i);
      this->fill_op_desc (sub_key,
                          ods[i],
                          stringified
                          ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
}

void 
TAO_HomeDef_i::fill_op_desc (ACE_Configuration_Section_Key &key,
                             CORBA::OperationDescription &od,
                             const char *sub_section
                             ACE_ENV_ARG_DECL)
{
  ACE_Configuration_Section_Key op_key;
  this->repo_->config ()->open_section (key,
                                        sub_section,
                                        0,
                                        op_key);
  TAO_IFR_Desc_Utils<CORBA::OperationDescription,
                     TAO_OperationDef_i>::fill_desc_begin (
      od,
      this->repo_,
      op_key
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;

  ACE_TString result_path;
  this->repo_->config ()->get_string_value (key,
                                            "result",
                                            result_path);
  TAO_IDLType_i *result = 
    TAO_IFR_Service_Utils::path_to_idltype (result_path,
                                            this->repo_);
  od.result = result->type_i (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  TAO_OperationDef_i impl (this->repo_);
  impl.section_key (op_key);
  od.mode = impl.mode_i (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  TAO_IFR_Strseq_Utils<CORBA::ContextIdSeq>::fill_string_seq (
      "contexts",
      this->repo_->config (),
      op_key,
      od.contexts
    );

  this->fill_param_desc_seq (op_key,
                             od.parameters,
                             "params"
                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->fill_exc_desc_seq (op_key,
                           od.exceptions,
                           "excepts"
                           ACE_ENV_ARG_PARAMETER);
}

void 
TAO_HomeDef_i::fill_param_desc_seq (ACE_Configuration_Section_Key &key,
                                    CORBA::ParDescriptionSeq &pds,
                                    const char *sub_section
                                    ACE_ENV_ARG_DECL)
{
  pds.length (0);
  ACE_Configuration_Section_Key params_key;
  int status =
    this->repo_->config ()->open_section (key,
                                          sub_section,
                                          0,
                                          params_key);

  if (status != 0)
    {
      return;
    }

  CORBA::ULong count = 0;
  this->repo_->config ()->get_integer_value (params_key,
                                             "count",
                                             count);
  pds.length (count);
  char *stringified = 0;

  for (CORBA::ULong i = 0; i < count; ++i)
    {
      stringified = TAO_IFR_Service_Utils::int_to_string (i);
      this->fill_param_desc (params_key,
                             pds[i],
                             stringified
                             ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
}

void 
TAO_HomeDef_i::fill_param_desc (ACE_Configuration_Section_Key &key,
                                CORBA::ParameterDescription &pd,
                                const char *sub_section
                                ACE_ENV_ARG_DECL)
{
  ACE_Configuration_Section_Key param_key;
  this->repo_->config ()->open_section (key,
                                        sub_section,
                                        0,
                                        param_key);
  ACE_TString holder;
  this->repo_->config ()->get_string_value (param_key,
                                            "name",
                                            holder);
  pd.name = holder.fast_rep ();
  this->repo_->config ()->get_string_value (param_key,
                                            "type_path",
                                            holder);
  TAO_IDLType_i *impl = TAO_IFR_Service_Utils::path_to_idltype (holder,
                                                                this->repo_);
  pd.type = impl->type_i (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Object_var obj = 
    TAO_IFR_Service_Utils::path_to_ir_object (holder,
                                              this->repo_
                                              ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  pd.type_def = CORBA::IDLType::_narrow (obj.in ()
                                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::ULong val;
  this->repo_->config ()->get_integer_value (param_key,
                                             "mode",
                                             val);
  pd.mode = static_cast<CORBA::ParameterMode> (val);
}

void 
TAO_HomeDef_i::fill_exc_desc_seq (ACE_Configuration_Section_Key &key,
                                  CORBA::ExcDescriptionSeq &eds,
                                  const char *sub_section
                                  ACE_ENV_ARG_DECL)
{
  eds.length (0);
  ACE_Configuration_Section_Key excepts_key;
  int status =
    this->repo_->config ()->open_section (key,
                                          sub_section,
                                          0,
                                          excepts_key);

  if (status != 0)
    {
      return;
    }

  CORBA::ULong count = 0;
  this->repo_->config ()->get_integer_value (excepts_key,
                                             "count",
                                             count);
  eds.length (count);
  char *stringified = 0;

  for (CORBA::ULong i = 0; i < count; ++i)
    {
      stringified = TAO_IFR_Service_Utils::int_to_string (i);
      this->fill_exc_desc (excepts_key,
                           eds[i],
                           stringified
                           ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
}

void 
TAO_HomeDef_i::fill_exc_desc (ACE_Configuration_Section_Key &key,
                              CORBA::ExceptionDescription &ed,
                              const char *sub_section
                              ACE_ENV_ARG_DECL)
{
  ACE_TString path;
  this->repo_->config ()->get_string_value (key,
                                            sub_section,
                                            path);

  // Description information for exceptions refers to the definition, not
  // the reference, so we need the extra step to get
  // the key of the exception's definition.
  ACE_Configuration_Section_Key except_def_key;
  this->repo_->config ()->expand_path (this->repo_->root_key (),
                                       path,
                                       except_def_key,
                                       0);
  TAO_IFR_Desc_Utils<CORBA::ExceptionDescription,
                     TAO_ExceptionDef_i>::fill_desc_begin (
                                              ed,
                                              this->repo_,
                                              except_def_key
                                              ACE_ENV_ARG_PARAMETER
                                            );

  TAO_ExceptionDef_i impl (this->repo_);
  impl.section_key (except_def_key);
  ed.type = impl.type_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

void 
TAO_HomeDef_i::fill_attr_desc_seq (ACE_Configuration_Section_Key &key,
                                   CORBA::ExtAttrDescriptionSeq &eads,
                                   const char *sub_section
                                   ACE_ENV_ARG_DECL)
{
  eads.length (0);
  ACE_Configuration_Section_Key attrs_key;
  int status =
    this->repo_->config ()->open_section (key,
                                          sub_section,
                                          0,
                                          attrs_key);

  if (status != 0)
    {
      return;
    }

  CORBA::ULong count = 0;
  this->repo_->config ()->get_integer_value (attrs_key,
                                             "count",
                                             count);
  eads.length (count);
  char *stringified = 0;

  for (CORBA::ULong i = 0; i < count; ++i)
    {
      stringified = TAO_IFR_Service_Utils::int_to_string (i);
      this->fill_attr_desc (attrs_key,
                            eads[i],
                            stringified
                            ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
}

void 
TAO_HomeDef_i::fill_attr_desc (ACE_Configuration_Section_Key &key,
                               CORBA::ExtAttributeDescription &ead,
                               const char *sub_section
                               ACE_ENV_ARG_DECL)
{
  ACE_Configuration_Section_Key attr_key;
  this->repo_->config ()->open_section (key,
                                        sub_section,
                                        0,
                                        attr_key);
  TAO_IFR_Desc_Utils<CORBA::ExtAttributeDescription,
                     TAO_AttributeDef_i>::fill_desc_begin (
                                              ead,
                                              this->repo_,
                                              attr_key
                                              ACE_ENV_ARG_PARAMETER
                                            );
  ACE_CHECK;

  TAO_AttributeDef_i impl (this->repo_);
  impl.section_key (attr_key);
  ead.type = impl.type_i (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  ead.mode = impl.mode_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}
