divert(-1)

# file      : CCF/IDL2/SyntaxTree/BuiltIn.hpp.m4
# author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
# cvs-id    : $Id$

include(`BuiltIn.m4')

define(`built_in_type', `built_in_type_impl(`make_class_name(`$1')', `$1')')

define(`built_in_type_impl', `

      //
      //
      //
      class $1 : public virtual BuiltInTypeDecl
      {
      public:
        virtual
        ~$1 () throw () {}

        $1 (ScopePtr const& scope)
            : Declaration (SimpleName ("$2"), scope)
        {
          type_info (static_type_info ());
        }

      protected:
        $1 (SimpleName const& name, Order const& order, ScopePtr const& scope)
            : Declaration (name, order, scope)
        {
          type_info (static_type_info ());
        }

      public:
        virtual TypeDeclPtr
        clone_typedef_temporary (SimpleName const& name,
                                 Order const& order,
                                 ScopePtr const& scope)
        {
          return TypeDeclPtr (new $1 (name, order, scope));
        }

        // Runtime declaration type information.
        //
      public:
        virtual std::string
        declaration_class ()
        {
          return "built-in type $2";
        }

      public:
        static Utility::Introspection::TypeInfo const&
        static_type_info ();
      };

      typedef
      StrictPtr<$1>
      $1Ptr;')
divert(0)dnl
dnl
dnl
dnl
// file      : CCF/IDL2/SyntaxTree/BuiltIn.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

// Note, that this file is automatically generated!
//

#ifndef CCF_IDL2_SYNTAX_TREE_BUILT_IN_HPP
#define CCF_IDL2_SYNTAX_TREE_BUILT_IN_HPP

#include "CCF/IDL2/SyntaxTree/Elements.hpp"

namespace CCF
{
  namespace IDL2
  {
    namespace SyntaxTree
    {
      //
      //
      //
      class BuiltInTypeDecl : public virtual TypeDecl
      {
      protected:
        virtual
        ~BuiltInTypeDecl () throw () {}

        BuiltInTypeDecl ()
        {
          type_info (static_type_info ());
        }

      public:
        virtual bool
        complete () const
        {
          return true;
        }

      public:
        static Utility::Introspection::TypeInfo const&
        static_type_info ();
      };

      typedef
      StrictPtr<BuiltInTypeDecl>
      BuiltInTypeDeclPtr;
dnl
built_in_type(`Object')
built_in_type(`ValueBase')
built_in_type(`any')
built_in_type(`boolean')
built_in_type(`char')
built_in_type(`double')
built_in_type(`float')
built_in_type(`long')
built_in_type(`long double')
built_in_type(`long long')
built_in_type(`octet')
built_in_type(`short')
built_in_type(`string')
built_in_type(`unsigned long')
built_in_type(`unsigned long long')
built_in_type(`unsigned short')
built_in_type(`void')
built_in_type(`wchar')
built_in_type(`wstring')
dnl
    }
  }
}

#endif  // CCF_IDL2_SYNTAX_TREE_BUILT_IN_HPP
