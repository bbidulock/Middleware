// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_enum.cpp
//
// = DESCRIPTION
//    Extension of class AST_Enum that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#include "be_enum.h"
#include "be_visitor.h"
#include "be_helper.h"

#include "global_extern.h"

ACE_RCSID (be,
           be_enum,
           "$Id$")

be_enum::be_enum (void)
  : COMMON_Base (),
    AST_Decl (),
    AST_Type (),
    AST_ConcreteType (),
    UTL_Scope (),
    AST_Enum (),
    be_scope (),
    be_decl (),
    be_type ()
{
}

be_enum::be_enum (UTL_ScopedName *n,
                  bool local,
                  bool abstract)
  : COMMON_Base (local,
                 abstract),
    AST_Decl (AST_Decl::NT_enum,
              n),
    AST_Type (AST_Decl::NT_enum,
              n),
    AST_ConcreteType (AST_Decl::NT_enum,
                      n),
    UTL_Scope (AST_Decl::NT_enum),
    AST_Enum (n,
              local,
              abstract),
    be_scope (AST_Decl::NT_enum),
    be_decl (AST_Decl::NT_enum,
             n),
    be_type (AST_Decl::NT_enum,
             n)
{
  if (!this->imported ())
    {
      idl_global->enum_seen_ = true;
    }
}

void
be_enum::gen_ostream_operator (TAO_OutStream *os)
{
  static ACE_CString const tao_enumerators ("_tao_enumerators_");
  ACE_CString const enumerators_name (tao_enumerators
                                      + this->flat_name ());
  *os << be_nl
      << "std::ostream& operator<< (std::ostream &strm, const "
      << this->name () << " _tao_enumerator)" << be_nl
      << "{" << be_idt_nl
      << "if( 0 <= _tao_enumerator && " << this->member_count () << " > _tao_enumerator )" << be_idt_nl
      << "{" << be_idt_nl
      << "return strm << " << enumerators_name.c_str () << "[_tao_enumerator];" << be_uidt_nl
      << "}" << be_uidt_nl
      << "else" << be_idt_nl
      << "{" << be_idt_nl
      << "return strm;" << be_uidt_nl
      << "}" << be_uidt << be_uidt_nl
      << "}" << be_nl;
}

void
be_enum::destroy (void)
{
  // Call the destroy methods of our base classes.
  // No need to call be_scope::destroy(). It has no
  // allocated members, and AST_Enum::destroy() will
  // call UTL_Scope::destroy().
  this->be_type::destroy ();
  this->be_scope::destroy ();
  this->AST_Enum::destroy ();
}

int
be_enum::accept (be_visitor *visitor)
{
  return visitor->visit_enum (this);
}



IMPL_NARROW_FROM_DECL (be_enum)
IMPL_NARROW_FROM_SCOPE (be_enum)
