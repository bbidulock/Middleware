// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_exception.cpp
//
// = DESCRIPTION
//    Extension of class AST_Exception that provides additional means for C++
//    mapping of an interface.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================


#include        "idl.h"
#include        "idl_extern.h"
#include        "be.h"

ACE_RCSID(be, be_exception, "$Id$")

/*
 * BE_Exception
 */
be_exception::be_exception (void)
{
  this->size_type (be_decl::VARIABLE); // always the case
}

be_exception::be_exception (UTL_ScopedName *n,
                            UTL_StrList *p,
                            idl_bool local,
                            idl_bool abstract)
  : AST_Decl (AST_Decl::NT_except, n, p),
    AST_Structure (AST_Decl::NT_except, n, p, local, abstract),
    UTL_Scope (AST_Decl::NT_except),
    COMMON_Base (local, abstract)
{
  this->size_type (be_decl::VARIABLE); // always the case
}

// Are we or the parameter node involved in any recursion
idl_bool
be_exception::in_recursion (be_type *node)
{
  if (!node)
    {
      // we are determining the recursive status for ourselves
      node = this;
    }

  // proceed if the number of members in our scope is greater than 0
  if (this->nmembers () > 0)
    {
      // initialize an iterator to iterate thru our scope
      UTL_ScopeActiveIterator *si;
      ACE_NEW_RETURN (si,
                      UTL_ScopeActiveIterator (this,
                                               UTL_Scope::IK_decls),
                      -1);
      // continue until each element is visited
      while (!si->is_done ())
        {
          be_field *field = be_field::narrow_from_decl (si->item ());
          if (!field)
            {
              delete si;
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_TEXT ("(%N:%l) be_exception::")
                                 ACE_TEXT ("in_recursion - ")
                                 ACE_TEXT ("bad field node\n")),
                                0);
            }
          be_type *type = be_type::narrow_from_decl (field->field_type ());
          if (!type)
            {
              delete si;
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ACE_TEXT ("(%N:%l) be_exception::")
                                 ACE_TEXT ("in_recursion - ")
                                 ACE_TEXT ("bad field type\n")),
                                0);
            }
          if (type->in_recursion (node))
            {
              delete si;
              return 1;
            }
          si->next ();
        } // end of while loop
      delete si;
    } // end of if

  // not in recursion
  return 0;
}

int
be_exception::gen_iostream_op_hdr (TAO_OutStream *os)
{
  *os << "# if !defined (ACE_LACKS_IOSTREAM_TOTALLY)" << be_nl << be_nl;
  *os << idl_global->stub_export_macro ();
  *os << " ostream& operator<< (ostream &, const "
      << this->full_name () << " &);" << be_nl << be_nl;
  *os << "# endif /* ACE_LACKS_IOSTREAM_TOTALLY */" << be_nl;

  return 0;
}

int
be_exception::gen_iostream_op_impl (TAO_OutStream *os)
{
  *os << "#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)" << be_nl << be_nl;
  *os << "ACE_INLINE" << be_nl;
  *os << "ostream & operator<< (ostream &os, const "
      << this->full_name ()<< " &_tao_aggregate)" << be_nl;
  *os << "{" << be_idt_nl;
  *os << "CORBA::TypeCode_ptr tc = _tao_aggregate._type ();" << be_nl;
  *os << "if (tc)" << be_idt_nl;
  *os << "{" << be_idt_nl;
  *os << "os << tc->name () << \" (\";" << be_uidt_nl;
  *os << "}" << be_uidt_nl;
  *os << "os << _tao_aggregate._id ();" << be_nl;
  *os << "if (tc)" << be_idt_nl;
  *os << "{" << be_idt_nl;
  *os << "os << \")\";" << be_uidt_nl;
  *os << "}" << be_uidt_nl;
  *os << "return os;" << be_uidt_nl;
  *os << "}" << be_nl << be_nl;
  *os << "#endif /* ACE_LACKS_IOSTREAM_TOTALLY */" << be_nl << be_nl;

  return 0;
}

int
be_exception::accept (be_visitor *visitor)
{
  return visitor->visit_exception (this);
}

// Narrowing
IMPL_NARROW_METHODS3 (be_exception, AST_Exception, be_scope, be_type)
IMPL_NARROW_FROM_DECL (be_exception)
IMPL_NARROW_FROM_SCOPE (be_exception)
