// $Id$

/*

COPYRIGHT

Copyright 1992, 1993, 1994 Sun Microsystems, Inc.  Printed in the United
States of America.  All Rights Reserved.

This product is protected by copyright and distributed under the following
license restricting its use.

The Interface Definition Language Compiler Front End (CFE) is made
available for your use provided that you include this license and copyright
notice on all media and documentation and the software program in which
this product is incorporated in whole or part. You may copy and extend
functionality (but may not remove functionality) of the Interface
Definition Language CFE without charge, but you are not authorized to
license or distribute it to anyone else except as part of a product or
program developed by you or with the express written consent of Sun
Microsystems, Inc. ("Sun").

The names of Sun Microsystems, Inc. and any of its subsidiaries or
affiliates may not be used in advertising or publicity pertaining to
distribution of Interface Definition Language CFE as permitted herein.

This license is effective until terminated by Sun for failure to comply
with this license.  Upon termination, you shall destroy or return all code
and documentation for the Interface Definition Language CFE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED AS IS WITH NO WARRANTIES OF
ANY KIND INCLUDING THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS
FOR A PARTICULAR PURPOSE, NONINFRINGEMENT, OR ARISING FROM A COURSE OF
DEALING, USAGE OR TRADE PRACTICE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED WITH NO SUPPORT AND WITHOUT
ANY OBLIGATION ON THE PART OF Sun OR ANY OF ITS SUBSIDIARIES OR AFFILIATES
TO ASSIST IN ITS USE, CORRECTION, MODIFICATION OR ENHANCEMENT.

SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES SHALL HAVE NO LIABILITY WITH
RESPECT TO THE INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY
INTERFACE DEFINITION LANGUAGE CFE OR ANY PART THEREOF.

IN NO EVENT WILL SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES BE LIABLE FOR
ANY LOST REVENUE OR PROFITS OR OTHER SPECIAL, INDIRECT AND CONSEQUENTIAL
DAMAGES, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

Use, duplication, or disclosure by the government is subject to
restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
Technical Data and Computer Software clause at DFARS 252.227-7013 and FAR
52.227-19.

Sun, Sun Microsystems and the Sun logo are trademarks or registered
trademarks of Sun Microsystems, Inc.

SunSoft, Inc.
2550 Garcia Avenue
Mountain View, California  94043

NOTE:

SunOS, SunSoft, Sun, Solaris, Sun Microsystems or the Sun logo are
trademarks or registered trademarks of Sun Microsystems, Inc.

*/

// AST_Structure nodes denote IDL struct declarations.
// AST_Structure is a subclass of AST_ConcreteType and of UTL_Scope (the
// structure's fields are managed in a scope).

#include "ast_union.h"
#include "ast_field.h"
#include "ast_enum.h"
#include "ast_enum_val.h"
#include "ast_visitor.h"
#include "utl_err.h"
#include "utl_indenter.h"

ACE_RCSID (ast, 
           ast_structure, 
           "$Id$")

AST_Structure::AST_Structure (void)
  : member_count_ (-1),
    local_struct_ (-1)
{
}

AST_Structure::AST_Structure (UTL_ScopedName *n,
                              idl_bool local,
                              idl_bool abstract)
 : AST_Decl (AST_Decl::NT_struct,
             n),
   UTL_Scope (AST_Decl::NT_struct),
   COMMON_Base (local,
                abstract),
   member_count_ (-1),
   local_struct_ (-1)
{
}

AST_Structure::AST_Structure (AST_Decl::NodeType nt,
                              UTL_ScopedName *n,
                              idl_bool local,
                              idl_bool abstract)
 : AST_Decl (nt,
             n),
   UTL_Scope (nt),
   COMMON_Base (local,
                abstract),
   member_count_ (-1),
   local_struct_ (-1)
{
}

AST_Structure::~AST_Structure (void)
{
}

// Are we or the parameter node involved in any recursion?
idl_bool
AST_Structure::in_recursion (AST_Type *node)
{
  if (node == 0)
    {
      // We are determining the recursive status for ourselves.
      node = this;
    }

  // Proceed if the number of members in our scope is greater than 0.
  if (this->nmembers () > 0)
    {
      // Initialize an iterator to iterate over our scope.
      // Continue until each element is visited.
      for (UTL_ScopeActiveIterator si (this, UTL_Scope::IK_decls); 
           !si.is_done (); 
           si.next ())
        {
          AST_Field *field = AST_Field::narrow_from_decl (si.item ());

          if (field == 0)
            // This will be an enum value or other legitimate non-field
            // member - in any case, no recursion.
            {
              continue;
            }

          AST_Type *type = field->field_type ();

          if (type == 0)
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_TEXT ("(%N:%l) AST_Structure::")
                                 ACE_TEXT ("in_recursion - ")
                                 ACE_TEXT ("bad field type\n")),
                                0);
            }

          if (type->in_recursion (node))
            {
              return 1;
            }
        }
    }

  // Not in recursion.
  return 0;
}

// Return the member count.
int
AST_Structure::member_count (void)
{
  if (this->member_count_ == -1)
    {
      this->compute_member_count ();
    }

  return this->member_count_;
}

size_t
AST_Structure::nfields (void) const
{
  return this->fields_.size ();
}

int
AST_Structure::field (AST_Field **&result,
                      size_t slot) const
{
  return this->fields_.get (result,
                            slot);
}

idl_bool
AST_Structure::is_local (void)
{
  if (this->local_struct_ == -1)
    {
      if (this->is_local_)
        {
          this->local_struct_ = this->is_local_;
        }
      else
        {
          this->local_struct_ = 0;

          if (this->nmembers () > 0)
            {
              // Instantiate a scope iterator.
              for (UTL_ScopeActiveIterator si (this, UTL_Scope::IK_decls);
                   !si.is_done ();
                   si.next ())
                {
                  if (si.item ()->is_local ())
                    {
                      this->local_struct_ = I_TRUE;
                      break;
                    }
                }
            }
        }
    }

  return this->local_struct_;
}

int
AST_Structure::contains_wstring (void)
{
  if (this->contains_wstring_ == -1)
    {
      for (UTL_ScopeActiveIterator si (this, UTL_Scope::IK_decls);
           !si.is_done ();
           si.next ())
        {
          if (si.item ()->contains_wstring () == 1)
            {
              this->contains_wstring_ = 1;
              return this->contains_wstring_;
            }
        }

      this->contains_wstring_ = 0;
    }

  return this->contains_wstring_;
}

// Private operations.

// Add this AST_Field node (a field declaration) to this scope.
AST_Field *
AST_Structure::fe_add_field (AST_Field *t)
{
  AST_Decl *d = 0;

  // Already defined and cannot be redefined? Or already used?
  if ((d = this->lookup_for_add (t, I_FALSE)) != 0)
    {
      if (!can_be_redefined (d))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_REDEF,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (this->referenced (d, t->local_name ()))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_DEF_USE,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (t->has_ancestor (d))
        {
          idl_global->err ()->redefinition_in_scope (t,
                                                     d);
          return 0;
        }
    }

  // Add it to scope.
  this->add_to_scope (t);

  // Add it to set of locally referenced symbols.
  this->add_to_referenced (t,
                           I_FALSE,
                           t->local_name ());

  AST_Type *ft = t->field_type ();
  UTL_ScopedName *mru = ft->last_referenced_as ();

  if (mru != 0)
    {
      this->add_to_referenced (ft,
                               I_FALSE,
                               mru->first_component ());
    }

  this->fields_.enqueue_tail (t);

  return t;
}

// Add an AST_Structure node (a manifest struct type) to this scope.
AST_Structure *
AST_Structure::fe_add_structure (AST_Structure *t)
{
  AST_Decl *d = 0;

  // Already defined and cannot be redefined? Or already used?
  if ((d = this->lookup_for_add (t, I_FALSE)) != 0)
    {
      if (!can_be_redefined (d))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_REDEF,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (this->referenced (d, t->local_name ()))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_DEF_USE,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (t->has_ancestor (d))
        {
          idl_global->err ()->redefinition_in_scope (t,
                                                     d);
          return 0;
        }
    }

  // Add it to local types.
  this->add_to_local_types (t);

  // Add it to set of locally referenced symbols.
  this->add_to_referenced (t,
                           I_FALSE,
                           t->local_name ());

  return t;
}

// Add an AST_Union node (a manifest union type) to this scope.
AST_Union *
AST_Structure::fe_add_union (AST_Union *t)
{
  AST_Decl *d = 0;

  // Already defined and cannot be redefined? Or already used?
  if ((d = this->lookup_for_add (t, I_FALSE)) != 0)
    {
      if (!can_be_redefined (d))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_REDEF,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (this->referenced (d, t->local_name ()))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_DEF_USE,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (t->has_ancestor (d))
        {
          idl_global->err ()->redefinition_in_scope (t,
                                                     d);
          return 0;
        }
    }

  // Add it to local types.
  this->add_to_local_types (t);

  // Add it to set of locally referenced symbols.
  this->add_to_referenced (t,
                           I_FALSE,
                           t->local_name ());

  return t;
}

// Add this AST_Enum node (a manifest enum declaration) to this scope.
AST_Enum *
AST_Structure::fe_add_enum (AST_Enum *t)
{
  AST_Decl *d = 0;

  // Already defined and cannot be redefined? Or already used?
  if ((d = this->lookup_for_add (t, I_FALSE)) != 0)
    {
      if (!can_be_redefined (d))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_REDEF,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (this->referenced (d, t->local_name ()))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_DEF_USE,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (t->has_ancestor (d))
        {
          idl_global->err ()->redefinition_in_scope (t,
                                                     d);
          return 0;
        }
    }

  // Add it to local types.
  this->add_to_local_types (t);

  // Add it to set of locally referenced symbols.
  this->add_to_referenced (t,
                           I_FALSE,
                           t->local_name ());

  return t;
}

// Add this AST_EnumVal node (an enumerator declaration) to this scope.
// This is done to conform to the C++ scoping rules which declare
// enumerators in the enclosing scope (in addition to declaring them
// in the enum itself).
AST_EnumVal *
AST_Structure::fe_add_enum_val (AST_EnumVal *t)
{
  AST_Decl *d = 0;

  // Already defined and cannot be redefined? Or already used?
  if ((d = this->lookup_for_add (t, I_FALSE)) != 0)
    {
      if (!can_be_redefined (d))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_REDEF,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (this->referenced (d, t->local_name ()))
        {
          idl_global->err ()->error3 (UTL_Error::EIDL_DEF_USE,
                                      t,
                                      this,
                                      d);
          return 0;
        }

      if (t->has_ancestor (d))
        {
          idl_global->err ()->redefinition_in_scope (t,
                                                     d);
          return 0;
        }
    }

  // Add it to scope.
  this->add_to_scope (t);

  // Add it to set of locally referenced symbols.
  this->add_to_referenced (t,
                           I_FALSE,
                           t->local_name ());

  return t;
}

// Compute total number of members.
int
AST_Structure::compute_member_count (void)
{
  this->member_count_ = 0;

  // If there are elements in this scope.
  if (this->nmembers () > 0)
    {
      // Instantiate a scope iterator.
      for (UTL_ScopeActiveIterator si (this, UTL_Scope::IK_decls);
           !si.is_done ();
           si.next ())
        {
          ++this->member_count_;
        }
    }

  return 0;
}

// Dump this AST_Structure node to the ostream o.
void
AST_Structure::dump (ACE_OSTREAM_TYPE &o)
{
  if (this->is_local ())
    {
      o << "(local) ";
    }

  o << "struct ";
  AST_Decl::dump (o);
  o << " {\n";
  UTL_Scope::dump (o);
  idl_global->indent ()->skip_to (o);
  o << "}";
}

// Compute the size type of the node in question.
int
AST_Structure::compute_size_type (void)
{
  for (UTL_ScopeActiveIterator si (this, UTL_Scope::IK_decls);
       !si.is_done ();
       si.next ())
    {
      // Get the next AST decl node.
      AST_Decl *d = si.item ();

      if (d->node_type () == AST_Decl::NT_enum_val)
        {
          continue;
        }

      AST_Field *f = AST_Field::narrow_from_decl (d);
      AST_Type *t = f->field_type ();

      if (t != 0)
        {
          this->size_type (t->size_type ());

          // While we're iterating, we might as well do this one too.
          this->has_constructor (t->has_constructor ());
        }
      else
        {
          ACE_DEBUG ((LM_DEBUG,
                      "WARNING (%N:%l) be_structure::compute_size_type - "
                      "narrow_from_decl returned 0\n"));
        }
    }

  return 0;
}

int
AST_Structure::ast_accept (ast_visitor *visitor)
{
  return visitor->visit_structure (this);
}

void
AST_Structure::destroy (void)
{
}

// Narrowing.
IMPL_NARROW_METHODS2(AST_Structure, AST_ConcreteType, UTL_Scope)
IMPL_NARROW_FROM_DECL(AST_Structure)
IMPL_NARROW_FROM_SCOPE(AST_Structure)

