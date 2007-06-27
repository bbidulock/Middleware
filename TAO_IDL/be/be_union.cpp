// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_union.cpp
//
// = DESCRIPTION
//    Extension of class AST_Union that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#include "be_union.h"
#include "be_union_branch.h"
#include "be_union_label.h"
#include "be_visitor.h"
#include "be_codegen.h"
#include "be_helper.h"
#include "be_extern.h"

#include "ast_union_branch.h"
#include "ast_enum.h"
#include "utl_identifier.h"
#include "idl_defines.h"
#include "global_extern.h"

ACE_RCSID (be,
           be_union,
           "$Id$")


be_union::be_union (void)
  : COMMON_Base (),
    AST_Decl (),
    AST_Type (),
    AST_ConcreteType (),
    UTL_Scope (),
    AST_Structure (),
    AST_Union (),
    be_scope (),
    be_decl (),
    be_type ()
{
  // Always the case.
  this->has_constructor (true);
}

be_union::be_union (AST_ConcreteType *dt,
                    UTL_ScopedName *n,
                    bool local,
                    bool abstract)
  : COMMON_Base (local,
                 abstract),
    AST_Decl (AST_Decl::NT_union,
              n),
    AST_Type (AST_Decl::NT_union,
              n),
    AST_ConcreteType (AST_Decl::NT_union,
                      n),
    UTL_Scope (AST_Decl::NT_union),
    AST_Structure (AST_Decl::NT_union,
                   n,
                   local,
                   abstract),
    AST_Union (dt,
               n,
               local,
               abstract),
    be_scope (AST_Decl::NT_union),
    be_decl (AST_Decl::NT_union,
             n),
    be_type (AST_Decl::NT_union,
             n)
{
  // Always the case.
  this->has_constructor (true);

  if (!this->imported ())
    {
      idl_global->aggregate_seen_ = true;

      idl_global->union_seen_ = true;
    }
}

void
be_union::redefine (AST_Structure *from)
{
  be_union *bu = be_union::narrow_from_decl (from);
  this->common_varout_gen_ = bu->common_varout_gen_;
  AST_Union::redefine (from);
}

bool
be_union::has_duplicate_case_labels (void)
{
  for (UTL_ScopeActiveIterator si (this, UTL_Scope::IK_decls);
       !si.is_done ();
       si.next ())
    {
      AST_Decl *d = si.item ();
      AST_UnionBranch *ub =
        AST_UnionBranch::narrow_from_decl (d);

      if (ub->label_list_length () > 1)
        {
          return true;
        }
    }

  return false;
}

void
be_union::gen_ostream_operator (TAO_OutStream *os)
{
  *os << be_nl
      << "std::ostream& operator<< (" << be_idt << be_idt_nl
      << "std::ostream &strm," << be_nl
      << "const " << this->name () << " &_tao_union" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "strm << \"" << this->name () << "(\";" << be_nl << be_nl
      << "switch (_tao_union._d ())" << be_nl
      << "{" << be_idt;
      
  for (long i = 0; i < this->pd_decls_used; ++i)
    {
      be_union_branch *ub =
        be_union_branch::narrow_from_decl (this->pd_decls[i]);
      
      // We don't want any decls, just members.
      if (ub == 0)
        {
          continue;
        }
        
      *os << be_nl;
        
      unsigned long ll_len = ub->label_list_length ();

      for (unsigned long j = 0; j < ll_len; ++j)
        {
          // Check if we are printing the default case.
          if (ub->label (j)->label_kind () == AST_UnionLabel::UL_default)
            {
              *os << "default:";
            }
          else
            {
              *os << "case ";

              ub->gen_label_value (os, j);

              *os << ":";
            }

          if (j == ll_len - 1)
            {
              *os << be_idt_nl;
            }
          else
            {
              *os << be_nl;
            }
        }

      ACE_CString instance_name ("_tao_union.");
      instance_name += ub->local_name ()->get_string ();
      
      *os << "strm << ";
      
      ub->gen_member_ostream_operator (os, instance_name.c_str (), true);
      
      *os << ";" << be_nl
          << "break;" << be_uidt;
    }
    
  *os << be_uidt_nl
      << "}" << be_nl << be_nl
      << "return strm << \")\";" << be_uidt_nl
      << "}" << be_nl;
}

void
be_union::destroy (void)
{
  // Call the destroy methods of our base classes.
  this->be_scope::destroy ();
  this->be_type::destroy ();
  this->AST_Union::destroy ();

}

// Visitor method.
int
be_union::accept (be_visitor *visitor)
{
  return visitor->visit_union (this);
}

bool
be_union::gen_empty_default_label (void)
{
  // A non-empty explicit default label will be generated.
  if (this->default_index () != -1)
    {
      return false;
    }

  AST_ConcreteType *disc = this->disc_type ();
  AST_Decl::NodeType nt = disc->node_type ();
  unsigned long n_labels = this->nlabels ();

  if (nt == AST_Decl::NT_enum)
    {
      AST_Enum *e = AST_Enum::narrow_from_decl (disc);
      
      if (e == 0)
        {
          return true;
        }

      // If we have an enum and the number of labels if as big as the enum
      // has members we don't have to generate a default label
      if (n_labels == static_cast<unsigned long> (e->member_count ()))
        {
           return false;
        }
      else
        {
          return true;
        }
    }

  AST_PredefinedType *pdt = AST_PredefinedType::narrow_from_decl (disc);

  if (pdt == 0)
    {
      return true;
    }

  if (pdt->pt () == AST_PredefinedType::PT_boolean && n_labels == 2)
    {
      return false;
    }

  return true;
}

unsigned long
be_union::nlabels (void)
{
  unsigned long retval = 0;

  for (UTL_ScopeActiveIterator si (this, UTL_Scope::IK_decls);
       !si.is_done ();
       si.next ())
    {
      AST_Decl *d = si.item ();
      AST_UnionBranch *ub =
        AST_UnionBranch::narrow_from_decl (d);

      if (ub != 0)
        {
          retval += ub->label_list_length ();
        }
    }

  return retval;
}

// Narrowing.
IMPL_NARROW_METHODS3 (be_union, AST_Union, be_scope, be_type)
IMPL_NARROW_FROM_DECL (be_union)
IMPL_NARROW_FROM_SCOPE (be_union)
